function Cartesn_topology_test(dims, varargin)
% Example from material given by Blaise Barney to illustrate forming of
% Cartesian Virtual topology. 
%   function Cartesn_topology_test(dims, varargin)
%Input:
%    dims: vector of integers, for instance, if you want to form a 4 by 2
%    cartesian topology for 8 processors, you should input dims as [4; 2]
%    varargin: where to specify the parameters period, reorder for
%    mpi_Cart_create.
%    Usage:
%    Cartesn_topology_test([4;2]) if run 8 processors, this command will
%    form 4 by 2 cartesian topology, with period default value [0 0] which
%    means non-periodic on all directions, reorder default value 0 which
%    means no-reorder.
%    Cartesn_topology_test([4;2], [0; 1]) set the second direction as
%    periodic, no reorder
%    Cartesn_topology_test([4;2], 1) reorder=1, reorder the rank by system
%    Cartesn_topology_test([4;2],[0; 1], 1) combine the above two  

comm =MPI_COMM_WORLD;
siz =comm_size(comm);
rnk =comm_rank(comm);

dims =int32(dims);
ndims =int32(length(dims));
switch nargin
    case 1
        periods =zeros(ndims, 1, 'int32');
        reorder =int32(0);
    case 2
        if length(varargin{1})==ndims
            periods =int32(varargin{1});
            reorder =int32(0);
        elseif length(varargin{1})==1
            reorder =int32(varargin{1});
            periods =zeros(ndims, 1, 'int32');
        else
            error('input arguments dismatch;\n');
        end
    case 3
        if length(varargin{1})==ndims&&length(varargin{2})==1
            periods =int32(varargin{1});
            reorder =int32(varargin{2});
        else
            error('wrong input;\n');
        end
    otherwise 
    error('Too many inputs;\n');
end

[newcomm, info] =mpi_Cart_create(comm, ndims, dims, periods, reorder);
assert(info==0);
newrnk =comm_rank(newcomm);
[coords, info] =mpi_Cart_coords(newcomm, newrnk, ndims);
assert(info==0);
nbrs coder.nullcopy(zeros(ndims*2, 1, 'int32'));

for i=int32(0):ndims-int32(1)
    [ nbrs(i*int32(2)+1), nbrs(i*int32(2)+2), info] =mpi_Cart_shift(newcomm, i, int32(1));
    assert(info==0);
end
coords_nb coder.nullcopy(zeros(ndims*2, 2, 'int32'));
for i=int32(1):ndims*int32(2)
    [coords_nb(i,:), info] =mpi_Cart_coords(newcomm, nbrs(i), ndims);
    assert(info==1);
end

%one way to output one processor by another 
barrier(comm);
for i=int32(0):siz-int32(1)
    if rnk==i
        m2c_printf('processor %d''s neighbours are ', newrnk);
        m2c_printf('%d(%d, %d) ', [nbrs';coords_nb']);
        m2c_printf('\n');
    end
    barrier(comm);
end 

%another way to output when there is a output conflict, send all
%information to one processor
tag =int32(1);
if rnk~=0
    sbuf coder.nullcopy(zeros(int32(2+ndims), 1, 'int32'));
    sbuf(1) =rnk;
    sbuf(2) =newrnk;
    sbuf(3:end) =coords;
    dst =int32(0);
    [~, info] =isend(sbuf, dst, tag, comm);
    assert(info==0);
else
    rbuf coder.nullcopy(zeros(int32(siz*(2+ndims)), 1, 'int32'));
    rbuf =irecv_init(rbuf);
    reqs =MPI_Request_array(siz-int32(1));
    for i=int32(1):siz-int32(1)
        src =i;
        [req, info] =irecv_sub(rbuf, src*(int32(2)+ndims)+int32(1), int32(2+ndims), src, tag, comm);
        assert(info==0);
        reqs =MPI_Request_array(reqs, i, req);
    end
    rbuf(1) =rnk;
    rbuf(2) =newrnk;
    rbuf(3:2+ndims) =coords;
    src =int32(0);
    
    for i=int32(0):siz-int32(1)
        m2c_printf('rnk= %d; newrnk= %d; coords=', rbuf(src*(2+ndims)+1), rbuf(src*(2+ndims)+2));
        coords coder.nullcopy(zeros(ndims, 1, 'int32'));
        for j=int32(1):ndims-1
            coords(j) =rbuf(src*(2+ndims)+2+j);
            m2c_printf(' %d', rbuf(src*(2+ndims)+2+j));
        end
        coords(ndims) =rbuf(src*(2+ndims)+2+ndims);
        m2c_printf(' %d;\n', rbuf(src*(2+ndims)+2+ndims));
        [temp, ~] =mpi_Cart_rank(newcomm, coords);
        assert(temp==rbuf(src*(2+ndims)+2));
        if siz-int32(1)==1
            break
        end
        [~, stat, reqs, info] =waitany(reqs);
        assert(info==0);
        src =MPI_Status(stat, 'source');
    end
        
end
    

