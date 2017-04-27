%Illustrate an unsafe usage of blocking send and receive;
%Be careful, the code here is not portable: if the system doesn't provide
%send buffer for send_sub, then this script won't work!
%Usually, if this script is run on more than 1 processors, it will be OK
%since in this case system will provide buffer generally but if you run it 
%in one processor, then it will stuck at send_sub!
comm =MPI_COMM_WORLD;
siz =comm_size( comm);
rnk =comm_rank( comm);

% if siz~=int32(2)
%     error('test case for blocking send&recv between only 2 processors;\');
% end
num =siz;
sbuf =rand(num, 2);

dst =int32(mod(rnk+1, siz));
info =send_sub(sbuf, int32(1), int32(num), [], dst, int32(1), comm);
assert(info==0);
src =int32(mod(rnk-1, siz));
info =send_sub(sbuf, int32(num+1), int32(num), [], src, int32(2), comm);
assert(info==0);

rbuf =zeros(num,2);
[rbuf, stat, info] =recv_sub(rbuf, int32(1), int32(num), [], src, int32(1), comm);assert(info==0);
assert(MPI_Status(stat, 'get', 'source')==src && ...
       MPI_Status(stat, 'get', 'tag')==int32(1));
[rbuf, stat, info] =recv_sub(rbuf, int32(num+1), int32(num), [], dst, int32(2), comm);assert(info==0);
assert(MPI_Status(stat, 'get', 'source')==dst && ...
       MPI_Status(stat, 'get', 'tag')==int32(2));
assert(isequal(sbuf, rbuf));