function b = crs_prodAtx(A, x, b, nthreads, varargin)
%crs_prodAtx Compute b=A'*x for a sparse matrix A in CRS format,
% assuming that number of columns of A is equal to size(x,1).
%
%      b = crs_prodAtx(A, x [, b])
% Computes b=A'*x in serial.
%
%      b = crs_prodAtx(A, x, b, nthreads)
% Computes b=A'*x using nthreads OpenMP threads, where nthreads is an int32.
% In this mode, there are implicit barriers in the function.
% It will use min(nthreads, size(b,1)/A.ncols, ompGetMaxThreads) threads.
%
%      b = crs_prodAtx(A, x, b, [])
% Computes b=A'*x locally within each OpenMP thread, assuming the parallel
% region has already been initialized. The argument b has been preallocated.
% It will use min(size(b,1)/A.ncols, ompGetNumThreads)
% threads forcomputations. In this mode, there is no implicit barrier.
%
%      b = crs_prodAtx(A, x, b, nthreads, comm)
% also performs communication within the MPI communicator.
% It assumes that A is partitioned rowwise, and hence A'*x is
% a partial sum on each process. An allreduce is performed on b
% within the communicator.
%
% If A is partitioned columnwise, then b must be duplicated on all 
% processes, and crs_prodAtx should be called without the communicator.
%
%      b = crs_prodAtx(A, x, b, nthreads, comm, pgmsg [, pgsz])
% specifies an additiona message that should be summed during
% allreduce and strored in b. This is to piggy-back on allreduce
% to help aggregate small messages to optimize MPI communication.
%
% The compiled version reqiures A and x to be double precision.
% The M file works for both single and double precision.

% See http://www.netlib.org/linalg/html_templates/node98.html

%#codegen -args {crs_matrix, coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf]), 
%#codegen coder.typeof(int32(1), [1,1], [1,0])}
%#codegen crs_prodAtx_ser -args {crs_matrix, coder.typeof(0, [inf,inf])}
%#codegen crs_prodAtx_ser1 -args {crs_matrix, coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf])}
% %#codegen crs_prodAtx_mpi -args {crs_matrix, coder.typeof(0, [inf,inf]),
% %#codegen coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0]), opaque_obj}
% %#codegen crs_prodAtx_mpip -args {crs_matrix, coder.typeof(0, [inf,inf]),
% %#codegen coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0]), opaque_obj, coder.typeof(0, [inf,1])}
% %#codegen crs_prodAtx_mpip1 -args {crs_matrix, coder.typeof(0, [inf,inf]),
% %#codegen coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0]), opaque_obj,coder.typeof(0, [inf,1]), int32(0)}

coder.inline('never');

if nargin==2;
    b = coder.nullcopy(zeros(A.ncols,size(x,2)));
else
    if size(b,1)<A.ncols || size(b,2)<size(x,2)
        m2c_error('crs_prodAtx:BufferTooSmal', 'Buffer space for output b is too small.');
    end
end
ismt = nargin>3 && ompGetNumThreads>1;

if nargin>3 && ~isempty(nthreads)
    %% Declare parallel region
    if ~ompGetNested && ismt && nthreads(1)>1
        OMP_begin_master
        m2c_warn('crs_prodAtx:NestedParallel', ...
            'You are trying to use nested parallel regions. Solution may be incorrect.');
        OMP_end_master
    end
    
    OMP_begin_parallel(nthreads(1));

    %% Compute b=A'*x
    b = crs_prodAtx_kernel(A.row_ptr, A.col_ind, A.val, x, int32(size(x,1)), ...
        b, int32(size(b,1)), A.nrows, A.ncols, int32(size(x,2)), ompGetNumThreads>1);
    
    OMP_end_parallel
else
    %% Compute b=A'*x
    b = crs_prodAtx_kernel(A.row_ptr, A.col_ind, A.val, x, int32(size(x,1)), ...
        b, int32(size(b,1)), A.nrows, A.ncols, int32(size(x,2)), ismt);

    if ~isempty(varargin) && ismt; OMP_barrier; end
end

if ~isempty(varargin)
    % Perform MPI allreduce
    OMP_begin_single
    s = int32(A.ncols*size(x,2));
    b = allreduce(b, s, MPI_SUM, varargin{:});
    OMP_end_single
end

function b = crs_prodAtx_kernel(row_ptr, col_ind, val, x, x_m, ...
    b, b_m, nrows, ncols, nrhs, ismt)

coder.inline('never');

if ismt
    nthreads = min(ompGetNumThreads, ...
        int32(floor(double(b_m)/double(ncols))));
    boffset = ompGetThreadNum*ncols;
    [istart, iend] = OMP_local_chunk(nrows, nthreads);
else
    nthreads = int32(1); boffset = int32(0);
    istart = int32(1); iend = int32(nrows);
end

if istart<=iend
    xoffset = int32(0);
    for k=1:nrhs
        for j=boffset+1:boffset+ncols; b(j) = 0; end
        
        for i=istart:iend
            alpha = x(i+xoffset);
            
            for j = row_ptr(i) : row_ptr(i+1) - 1
                r = boffset+col_ind(j);
                b(r) = b(r) + alpha * val(j);
            end
        end
        
        xoffset = xoffset + x_m; boffset = boffset + b_m;
    end
end

%% Perfom summation of partial sums in b
if nthreads>1
    OMP_barrier;
    [istart, iend] = OMP_local_chunk(ncols);
    
    offset = ncols;
    for j=2:nthreads
        boffset = int32(0);
        for k=1:nrhs
            for i=boffset+istart:boffset+iend
                b(i) = b(i) + b(offset+i);
            end
            boffset = boffset + b_m;
        end
        offset = offset + ncols;
    end
end

function test %#ok<DEFNU>
%!test
%! if ~exist(['crs_prodAtx.' mexext], 'file')
%!    m=100; n = 20;
%! else
%!    m=10000; n = 2000;
%! end
%! tic; sp = sprand(m,n,0.5); x=rand(size(sp,1),2);
%! [is,js,vs] = find(sp);
%! fprintf(1, '\n\tGenerated random matrix in %g seconds\n', toc);
%! tic; b0 = sp'*x;
%! fprintf(1, '\tComputed reference solution in %g seconds\n', toc);
%! tic; A = crs_matrix(int32(is), int32(js), vs, int32(size(sp,1)), int32(size(sp,2)));
%! fprintf(1, '\tConverted into crs_matrix in %g seconds\n', toc);
%! fprintf(1, '\tTesting serial: ');
%! tic; b1 = crs_prodAtx(A, x);
%! fprintf(1, 'Done in %g seconds\n ', toc);
%! assert(norm(b0-b1)/norm(b0)<=1.e-10);

%! for nthreads=int32([1 2 4 8])
%!     if nthreads>ompGetMaxThreads; break; end
%!     fprintf(1, '\tTesting %d thread(s): ', nthreads);
%!     tic; b2 = zeros(size(sp,2)*nthreads,2);
%!     b2 = crs_prodAtx(A, x, b2, nthreads);
%!     fprintf(1, 'Done in %g seconds\n ', toc);
%!     assert(norm(b0-b2(1:size(sp,2),:))/norm(b0)<=1.e-10);
%! end

% %! nprocs = double(comm_size(MPI_COMM_WORLD));
% %! fprintf(1, '\tTesting 2 threads with MPI call: ');
% %! b2 = zeros(size(sp,2)*2,2);
% %! tic; b2 = crs_prodAtx(A, x, b2, int32(2), MPI_COMM_WORLD);
% %! fprintf(1, 'Done in %g seconds\n ', toc);
% %! assert(norm(b0-b2(1:size(sp,2),:))/norm(b0)<=1.e-10);
% 
% %! b3 = zeros(2*size(sp,2)+1,1);
% %! fprintf(1, '\tTesting 2 threads with piggy-back: ');
% %! tic; b3 = crs_prodAtx(A, x(:,1), b3, int32(2), MPI_COMM_WORLD, 1, int32(1));
% %! fprintf(1, 'Done in %g seconds\n ', toc);
% %! assert(nprocs>1 || norm(b0(:,1)-b3(1:size(sp,2)))/norm(b0)<=1.e-10);
% %! assert(b3(size(sp,2)+1)==nprocs);
