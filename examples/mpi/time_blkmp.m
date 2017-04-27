function time_blkmp(n)
%Timing to measure the time used for send and recv;
%Reminder: It seems that there is some maximum size of array you could
%send, and if you excedes this limit, it still works but gives you wrong
%value: the recv doesn't change the recv buffer.
comm =MPI_COMM_WORLD;
siz =comm_size(comm);
rnk =comm_rank(comm);
if siz~=2
    error('must use 2 processors');
end

tag =int32(1);
n=int32(n);
outmsg =ones(n,n);
inmsg =zeros(n,n);
if rnk==0
    m2c_printf('sending %dx%d matrix\n', n, n);
end
info=barrier( comm);assert(info==0);
t=wtime;
if rnk==0
    dst =int32(1);
    T=wtime;
    info =send(outmsg, dst, tag, comm); assert(info==0);
    m2c_printf('prc %d takes %f s to send\n', rnk, wtime-T);
elseif rnk==1
    src =int32(0);
    T=wtime;
    [inmsg, stats, info] =recv(inmsg, src, tag, comm); assert(info==0);
    m2c_printf('prc %d takes %f s to receive msg\n', rnk, wtime-T);
end
barrier( comm);
t = wtime-t;
if rnk==1
    assert(isequal(outmsg, inmsg)==1);
end
if rnk==0
    m2c_printf('using %d processors takes %fs\n', siz, t);
end
    