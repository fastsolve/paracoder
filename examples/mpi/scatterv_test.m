function scatterv_test( max)
%illustrate usage of scatterv, if you specify max=number of processors,
%processor 0 will get 1 2 3 ... max, processor 1 will get max+1, ..., 2*max
%and so on.
%For scatterv, the datatype of scatterv is specified by the local sendbuf,
%so you need to be careful although the value of local sendbuf (except the
%one on source processor) doesn't matter.
max =int32(max);

comm =MPI_COMM_WORLD;
siz =comm_size( comm);
rnk =comm_rank( comm);

if rnk==0
sendbuf =reshape(1:max*max, max, max)';
else
    sendbuf = int32(zeros(0, max));
end

[istrt, iend] =get_local_chunk(max, comm);
ml =iend-istrt+1;
[recvbuf,info] =scatterv(sendbuf, ml, max, comm);
assert( info==0);
for i=int32(0):siz-int32(1)
    if rnk==i
    m2c_printf('prc %d''s recvbuf =', rnk);
    m2c_printf('%d ', recvbuf);
    m2c_printf('\n');
    end
    barrier(comm);
end
