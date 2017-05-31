function [b, Atx] = crs_prodAAtx(A, x, b, Atx, nthreads, varargin)
%crs_prodAAtx Compute A*A;*x for a sparse matrix A in CRS format.
%
%      b = crs_prodAAtx(A, x [, b]) or [b, Atx] = crs_prodAAtx(A, x, b, Atx)
% computes in serial. Atx is a buffer for storing the intermediate
% result Atx. If passed as input, b and Atx are assumed to have
% been preallocated.
%
%      [b, Atx] = crs_prodAAtx(A, x, b, Atx, nthreads)
% Computes using nthreads OpenMP threads, where nthreads is an int32.
% Note that size(Atx,1) should be >= A.ncols*nthreads to facilitate concurrency.
% Otherwise, computation of A'*x will use up to size(Atx,1)/A.ncols threads.
%
%      [b, Atx] = crs_prodAAtx(A, x, b, Atx, [])
% computes locally within each OpenMP thread, assuming the parallel
% region has already been initialized. In this mode, Atx must be a
% buffer shared by all threads in the team, and it must be both
% input and output arguments (i.e., passed by reference). The computation
% will use up to size(Atx,1)/A.ncols threads.
%
%      [b, Atx] = crs_prodAAtx(A, x, b, Atx, nthreads, comm)
% assumes that A is partitioned rowwise, and x is dupliplicate on all
% processes. It performs a reduction on b within the MPI communicator.
%
%      [b, Atx] = crs_prodAAtx(A, x, b, Atx, nthreads, comm, pgmsg [, pgsz])
% specifies an additiona message that should be summed during
% allreduce and strored in Atx. This is to piggy-back on allreduce
% to help aggregate small messages to optimize MPI communication.
%
% In multithread or multiprocess mode, this is a collective function,
% and there is an implicit barrier at the end of this function.
%
% The compiled version reqiures A and x to be double precision.
% The M-file works for both single and double precision.

%#codegen -args {crs_matrix, coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf]),
%#codegen coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0])}
%#codegen crs_prodAAtx_ser -args {crs_matrix, coder.typeof(0, [inf,inf])}
%#codegen crs_prodAAtx_ser1 -args {crs_matrix, coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf])}
% %#codegen crs_prodAAtx_mpi -args {crs_matrix, coder.typeof(0, [inf,inf]),
% %#codegen coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0]), MPI_Comm}
% %#codegen crs_prodAAtx_mpip -args {crs_matrix, coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf]),
% %#codegen coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0]), MPI_Comm, coder.typeof(0, [inf,1])}
% %#codegen crs_prodAAtx_mpip1 -args {crs_matrix, coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf]),
% %#codegen coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0]), MPI_Comm, coder.typeof(0, [inf,1]), int32(0)}

coder.inline('never');

assert(nargin<=8);

if nargin<3
    b = zeros(A.nrows,size(x,2)); 
elseif size(b,1)<A.nrows || size(b,2)~=size(x,2)
    OMP_begin_master
    m2c_error('crs_prodAAtx:IncorrectBuffer', 'Buffer b has incorrect size.');
    OMP_end_master
end
if nargin<4
    Atx = zeros(A.ncols,size(x,2));
elseif size(Atx,1)<A.ncols || size(Atx,2)~=size(x,2)
    OMP_begin_master
    m2c_error('prodAAtx:IncorrectBuffer', 'Buffer Atx has incorrect size.');
    OMP_end_master
end

ismt = nargin>=5 && ompGetNumThreads>1;

%% Declare parallel region
if nargin>=5 && ~isempty(nthreads)
    if ~ompGetNested && ismt && nthreads(1)>1
        OMP_begin_master
        m2c_warn('crs_prodAAtx:NestedParallel', ...
            'You are trying to use nested parallel regions, but nested parallelism is not enabled.');
        OMP_end_master
    end
    
    OMP_begin_parallel(nthreads(1));
    
    % Computes Atx=A'*x
    Atx = crs_prodAtx(A, x, Atx, [], varargin{:});
    if isempty(varargin); OMP_barrier; end
    
    % Computes b=A*Atx
    b = crs_prodAx(A, Atx, b, []);
    
    OMP_end_parallel(Atx);
elseif ismt
    if nargout<2
        OMP_begin_master
        m2c_warn('crs_prodAAtx:MissingBuffer', ...
            'crs_prodAAtx is called within a parallel region but Atx is not an in+out argument.');
        OMP_end_master
    end
    
    % Computes Atx=A'*x
    Atx = crs_prodAtx(A, x, Atx, [], varargin{:});
    if isempty(varargin); OMP_barrier; end
    
    % Computes b=A*Atx
    b = crs_prodAx(A, Atx, b, []);
else
    % Computes Atx=A'*x
    Atx = crs_prodAtx(A, x, Atx);
    
    % Computes b=A*Atx
    b = crs_prodAx(A, Atx, b);
end

function test %#ok<DEFNU>
%!test
%! if ~exist(['crs_prodAAtx.' mexext], 'file')
%!    m=100; n = 20;
%! else
%!    m=10000; n = 2000;
%! end
%! tic; sp = sprand(m,n,0.5); x=rand(size(sp,1),2);
%! [is,js,vs] = find(sp);
%! fprintf(1, '\n\tGenerated random matrix in %g seconds\n', toc);
%! tic; b0 = sp*(sp'*x);
%! fprintf(1, '\tComputed reference solution in %g seconds\n', toc);
%! tic; A = crs_matrix(int32(is), int32(js), vs, int32(size(sp,1)), int32(size(sp,2)));
%! fprintf(1, '\tConverted into crs_matrix in %g seconds\n', toc);

%! fprintf(1, '\tTesting serial: ');
%! tic; b1 = crs_prodAAtx(A, x);
%! fprintf(1, 'Done in %g seconds\n ', toc);
%! assert(norm(b0-b1)<=1.e-10);

%! b2 = zeros(size(sp,1),2);
%! for nthreads=int32([1 2 4 8])
%!     if nthreads>ompGetMaxThreads; break; end
%!     fprintf(1, '\tTesting %d thread(s): ', nthreads);
%!     Atx = zeros(size(sp,2)*nthreads,2);
%!     tic; [b2, Atx] = crs_prodAAtx(A, x, b2, Atx, nthreads);
%!     fprintf(1, 'Done in %g seconds\n ', toc);
%!     assert(norm(b0-b2)/norm(b0)<=1.e-10);
%! end

% %! nprocs = double(comm_size(MPI_COMM_WORLD));
% %! fprintf(1, '\tTesting 2 threads with MPI call: ');
% %! Atx = zeros(size(sp,2)*nthreads,2);
% %! b2 = zeros(size(sp,1),2);
% %! tic; [b2, Atx] = crs_prodAAtx(A, x, b2, Atx, int32(2), MPI_COMM_WORLD);
% %! fprintf(1, 'Done in %g seconds\n ', toc);
% %! assert(norm(b0-b2)/norm(b0)<=1.e-10);
% 
% %! b3 = zeros(size(sp,1),1); Atx = zeros(size(sp,2)*2,1);
% %! fprintf(1, '\tTesting 2 threads with piggy-back: ');
% %! tic; [b3, Atx] = crs_prodAAtx(A, x(:,1), b3, Atx, int32(2), MPI_COMM_WORLD, 1, int32(1));
% %! fprintf(1, 'Done in %g seconds\n ', toc);
% %! assert(nprocs>1 || norm(b0(:,1)-b3)/norm(b0)<=1.e-10);
% %! assert(Atx(size(sp,2)+1)==nprocs);
