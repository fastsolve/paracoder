function rbuf = irecv_init(rbuf) %#codegen
%IRECV_INIT  Prepare a receive buffer for non-blocking receives.
%   [rbuf] = irecv_init(rbuf)
%
% This function should be called before the first call on irecv_sub.
%
%See also irecv_sub

coder.inline('always');
rbuf = m2c_unalias(rbuf);

function test  %#ok<DEFNU>
%!test
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! count = int32(numel(var1));
%! var2 = zeros(10,10);
%!
%! var2 = irecv_init(var2);
%! [req1, info] = irecv_sub(var2, 1, 50, [], 0, 1, comm);
%! [req2, info] = irecv_sub(var2, 51, 50, MPI_DOUBLE, 0, 1, comm);
%!
%! assert(info==0);

%! [req3, info] = isend_sub(var1, 1, 50, [], 0, 1, comm);
%! [req4, info] = isend_sub(var1, 51, 50, MPI_DOUBLE, 0, 1, comm);

%! reqs = MPI_Request_array(4);
%! reqs.data = [req1.data; req2.data; req3.data; req4.data];

%! for i=1:4; [idx, stat, reqs, info] = waitany(reqs); end
%! assert(isequal(var1, var2));
