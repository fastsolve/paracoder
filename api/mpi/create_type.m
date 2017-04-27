function [newtype, info] = create_type(oldtype, count, varargin) %#codegen
%CREATE_TYPE  Creates and commits a congiguous, vector, or indexed datatype
%
% [newtype, info] = create_type(oldtype, count)
%  creates a contiguous datatype.
%
% [newtype, info] = create_type(oldtype, count, blocklen, stride)
%  creates a strided vector datatype, where blocklen and stride are scalars
%
% [newtype, info] = create_type(oldtype, count, blocklens, indices)
%  creates an indexed datatype, where blocklens and indices are vectors of
%  lengths equal to count. blocklens specifies the numbers of elements in
%  each block, and indices specifies the displacement (0-based)
%  of each block in multiples of oldtype.
%
%Input arguments:
%  oldtype   old datatype (MPI_Datatype)
%  count     number of blocks (int32)
%  blocklen  number of elements in each block (int32)
%  stride    number of elements between start of each block (int32)
%
%Output arguments:
%  newtype   new datatype (MPI_Datatype)
%  info      return code (int32)
%
%See also free_type, isend_sub, irecv_sub, send_sub, recv_sub,

coder.inline('always');

if nargin==2
    [newtype, info] = mpi_Type_contiguous(int32(count), MPI_Datatype(oldtype));
else
    assert(nargin==4);
    if isscalar(varargin{1}) && isscalar(varargin{1})
        [newtype, info] = mpi_Type_vector(int32(count), int32(varargin{1}), ...
            int32(varargin{2}), MPI_Datatype(oldtype));
    else
        assert(numel(varargin{1})==count && numel(varargin{2})==count);
        [newtype, info] = mpi_Type_indexed(int32(count), int32(varargin{1}(:)), ...
            int32(varargin{2}(:)), MPI_Datatype(oldtype));
    end
end

if info==0
    [newtype, info] = mpi_Type_commit(newtype);
end

%!test
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! var2 = zeros(10,10);

%! newtype = create_type(MPI_DOUBLE, 10);

%! var2 = irecv_init(var2);
%! [req,info] = irecv_sub(var2, 1, 10, newtype, 0, 1, comm);
%! assert(info==0);
%! info = send_sub(var1, 1, 10, newtype, 0, 1, comm);

%! free_request(req);
%! free_type(newtype);
%! assert(isequal(var1, var2));


%!test
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! var2 = zeros(10,10);

%! newtype = create_type(MPI_DOUBLE, 1, 10, 10);

%! var2 = irecv_init(var2);
%! [req,info] = irecv_sub(var2, 1, 10, newtype, 0, 1, comm);
%! assert(info==0);
%! info = send_sub(var1, 1, 10, newtype, 0, 1, comm);

%! free_request(req);
%! free_type(newtype);
%! assert(isequal(var1, var2));


%!test
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! var2 = zeros(10,10);

%! newtype = create_type(MPI_DOUBLE, 2, [5, 5], [0, 5]);

%! var2 = irecv_init(var2);
%! [req,info] = irecv_sub(var2, 1, 10, newtype, 0, 1, comm);
%! assert(info==0);
%! info = send_sub(var1, 1, 10, newtype, 0, 1, comm);

%! free_request(req);
%! free_type(newtype);
%! assert(isequal(var1, var2));
