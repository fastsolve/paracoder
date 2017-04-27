function nonblck_test
%illustrate usage of non-blocking send and receive in MMPI
%Every processor send its own rank to two "neighbouring" processors, whose
%ranks are next to this rank.

comm =MPI_COMM_WORLD;
siz =comm_size(comm);
rnk =comm_rank(comm);

if rnk==0
    m2c_printf('using %d prcs;\n', siz);
end

dst_pre =int32(mod(rnk-int32(1),siz));
dst_nxt =int32(mod(rnk+int32(1),siz));

if dst_pre==rnk||rnk==dst_nxt
    m2c_printf('prc %d has no neighbour;\n', rnk);
    return
end
reqs =MPI_Request_array(2);
[req, info] =isend(rnk, dst_pre, int32(1), comm);
assert(info==0);
reqs =MPI_Request_array(reqs, 1, req);
[req, info] =isend(rnk, dst_nxt, int32(2), comm);
assert(info==0);
reqs =MPI_Request_array(reqs, 2, req);

src_pre =int32(mod(rnk-int32(1),siz));
src_nxt =int32(mod(rnk+int32(1),siz));

rnk_nb =zeros(2,1,'int32');
reqr =MPI_Request_array(2);
rnk_nb =irecv_init(rnk_nb);%Before using irecv_sub, irecv_init is needed!
[req, info] =irecv_sub(rnk_nb, int32(1), int32(1), [], src_pre, int32(2), comm);
assert(info==0);
reqr =MPI_Request_array(reqr, int32(1), req);
[req, info] =irecv_sub(rnk_nb, int32(2), int32(1), [], src_nxt, int32(1), comm);
assert(info==0);
reqr =MPI_Request_array(reqr, int32(2), req);

for i=1:2

    [idx, stats, reqr, info] =waitany( reqr);
    assert(info==0);
    src = MPI_Status(stats, 'get', 'source');
    m2c_printf('prc %d: idx= %d, MPI_Source=%d for recv;\n', rnk, idx, src);
    tagg = MPI_Status(stats, 'get', 'tag');
    if tagg==1
        rnk_nxt =rnk_nb(2);
        assert(rnk_nxt==dst_nxt);
    elseif tagg==2
        rnk_pre =rnk_nb(1);
        assert(rnk_pre==dst_pre);
    else
        error('communication failed');
    end
    
    [idx, stats, reqs, info] =waitany( reqs);
    assert(info==0);
    m2c_printf('prc %d: idx= %d, MPI_Source=%d for send;\n', rnk, ...
               idx, MPI_Status(stats, 'get', 'source'));
end


assert(isequal([rnk_pre rnk_nxt],[dst_pre, dst_nxt])==1);

m2c_printf('I am prc %d, my preguy is %d, nxtguy is %d;\n', rnk, rnk_pre, rnk_nxt);


function test  %#ok<DEFNU> 
%!test
%! if ~mpi_Initialized; mpi_Init;end
%!
%! comm =MPI_COMM_WORLD;
%! siz =comm_size( comm);
%! rnk =comm_rank( comm);
%! m2c_printf('using %d prcs;\n', siz);
%! if rnk==0
%!    m2c_printf('I am prc %d;\n', rnk);
%!    return
%! end
%! m2c_printf('I am prc %d;\n', rnk);


