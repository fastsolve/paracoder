function [b, Ax] = crs_prodAtAx(A, x, b, Ax, nthreads, varargin)
%crs_prodAtAx Compute A'*A*x for a sparse matrix A in CRS format.
%
%      b = crs_prodAtAx(A, x [, b]) or [b, Ax] = crs_prodAtAx(A, x, b, Ax)
% computes in serial. Ax is a buffer for storing the
% intermediate result Ax. If passed as input, b and Ax are assumed
% to have been preallocated.
%
%      [b, Ax] = crs_prodAtAx(A, x, b, Ax, nthreads)
% Computes using nthreads OpenMP threads, where nthreads is an int32.
% Note that size(b,1) should be >= A.ncols*nthreads to facilitate concurrency.
% Otherwise, computation of At*Ax will use up to size(b,1)/A.ncols threads.
%
%      [b, Ax] = crs_prodAtAx(A, x, b, Ax, [])
% computes locally within each OpenMP thread, assuming the
% parallel region has already been initialized. In this mode, Ax must
% be a buffer shared by all threads in the team, and it must be both
% input and output arguments (i.e., passed by reference). Vector
% b must be preallocated, the computation of At*Ax will use up to
% size(b,1)/A.ncols threads.
%
%      [b, Ax] = crs_prodAtAx(A, x, b, Ax, nthreads, comm)
% assumes that A is partitioned rowwise, and x is dupliplicate on all
% processes. It performs a reduction on b within the MPI communicator.
%
%      [b, Ax] = crs_prodAtAx(A, x, b, Ax, nthreads, comm, pgmsg [, pgsz])
% specifies an additiona message that should be summed during
% allreduce and strored in b. This is to piggy-back on allreduce
% to help aggregate small messages to optimize MPI communication.
%
% In multithread or multiprocess mode, this is a collective function,
% and there is an implicit barrier at the end of this function.
%
% The compiled version reqiures A and x to be double precision.
% The M file works for both single and double precision.

%#codegen -args {crs_matrix, coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf]), 
%#codegen coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0])}
%#codegen crs_prodAtAx_ser -args {crs_matrix, coder.typeof(0, [inf,inf])}
%#codegen crs_prodAtAx_ser1 -args {crs_matrix, coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf])}
% %#codegen crs_prodAtAx_mpi -args {crs_matrix, coder.typeof(0, [inf,inf]),
% %#codegen coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0]), MPI_Comm}
% %#codegen crs_prodAtAx_mpip -args {crs_matrix, coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf]),
% %#codegen coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0]), MPI_Comm, coder.typeof(0, [inf,1])}
% %#codegen crs_prodAtAx_mpip1 -args {crs_matrix, coder.typeof(0, [inf,inf]), coder.typeof(0, [inf,inf]),
% %#codegen coder.typeof(0, [inf,inf]), coder.typeof(int32(1), [1,1], [1,0]), MPI_Comm, coder.typeof(0, [inf,1]), int32(0)}

coder.inline('never');

assert(nargin<=8);

if nargin<3
    b = zeros(A.ncols,size(x,2)); 
elseif size(b,1)<A.ncols || size(b,2)~=size(x,2)
    OMP_begin_master
    m2c_error('crs_prodAAtx:IncorrectBuffer', 'Buffer b has incorrect size.');
    OMP_end_master
end
if nargin<4
    Ax = zeros(A.nrows,size(x,2));
elseif size(Ax,1)<A.nrows || size(Ax,2)~=size(x,2)
    OMP_begin_master
    m2c_error('prodAAtx:IncorrectBuffer', 'Buffer Ax has incorrect size.');
    OMP_end_master
end

%% Declare parallel region
if nargin>=5 && ~isempty(nthreads)
    if ~ompGetNested && ompGetNumThreads>1 && nthreads(1)>1
        OMP_begin_master
        m2c_warn('crs_prodAtAx:NestedParallel', ...
            'You are trying to use nested parallel regions, but nested parallelism is not enabled.');
        OMP_end_master
    end
    
    OMP_begin_parallel(nthreads(1));
    
    % Computes Ax=A*x
    Ax = crs_prodAx(A, x, Ax, []);
    OMP_barrier;
    
    % Computes b=A'*Ax
    b = crs_prodAtx(A, Ax, b, [], varargin{:});
    
    OMP_end_parallel(Ax);
elseif nargin>=5 && ompGetNumThreads>1
    if nargout<2
        OMP_begin_master
        m2c_warn('crs_prodAtAx:MissingBuffer', ...
            'crs_prodAtAx is called within a parallel region but Ax is not an in+out argument.');
        OMP_end_master
    end
    
    % Computes Ax=A*x
    Ax = crs_prodAx(A, x, Ax, []);
    OMP_barrier;
    
    % Computes b=A'*Ax
    b = crs_prodAtx(A, Ax, b, [], varargin{:});
else
    % Computes Ax=A*x
    Ax = crs_prodAx(A, x, Ax);
    % Computes b=A'*Ax
    b = crs_prodAtx(A, Ax, b);
end

function test %#ok<DEFNU>
%!test
%! if ~exist(['crs_prodAtAx.' mexext], 'file')
%!    m=100; n = 20;
%! else
%!    m=10000; n = 2000;
%! end
%! tic; sp = sprand(m,n,0.5); x=rand(size(sp,2),2);
%! fprintf(1, '\n\tGenerated random matrix in %g seconds\n', toc);
%! tic; b0 = sp'*(sp*x);
%! fprintf(1, '\tComputed reference solution in %g seconds\n', toc);
%! tic; A = crs_matrix(sp);
%! fprintf(1, '\tConverted into crs_matrix in %g seconds\n', toc);

%! fprintf(1, '\tTesting serial: ');
%! tic; b1 = crs_prodAtAx(A, x);
%! fprintf(1, 'Done in %g seconds\n ', toc);
%! assert(norm(b0-b1)<=1.e-10);

%! Ax = zeros(size(sp,1),2);
%! for nthreads=int32([1 2 4 8])
%!     if nthreads>ompGetMaxThreads; break; end
%!     fprintf(1, '\tTesting %d thread(s): ', nthreads);
%!     b2 = zeros(size(sp,2)*nthreads,2);
%!     tic; [b2, Ax] = crs_prodAtAx(A, x, b2, Ax, nthreads);
%!     fprintf(1, 'Done in %g seconds\n ', toc);
%!     assert(norm(b0-b2(1:size(sp,2),:))/norm(b0)<=1.e-10);
%! end

% %! nprocs = double(comm_size(MPI_COMM_WORLD));
% %! fprintf(1, '\tTesting 2 threads with MPI call: ');
% %! b2 = zeros(size(sp,2)*2,2);
% %! tic; [b2, Ax] = crs_prodAtAx(A, x, b2, Ax, int32(2), MPI_COMM_WORLD);
% %! fprintf(1, 'Done in %g seconds\n ', toc);
% %! assert(norm(b0-b2(1:size(sp,2),:))/norm(b0)<=1.e-10);
% 
% %! b3 = zeros(2*size(sp,2)+1,1); Ax = zeros(size(sp,1),1);
% %! fprintf(1, '\tTesting 2 threads with piggy-back: ');
% %! tic; [b3, Ax] = crs_prodAtAx(A, x(:,1), b3, Ax, int32(2), MPI_COMM_WORLD, 1, int32(1));
% %! fprintf(1, 'Done in %g seconds\n ', toc);
% %! assert(nprocs>1 || norm(b0(:,1)-b3(1:size(sp,2)))/norm(b0)<=1.e-10);
% %! assert(b3(size(sp,2)+1)==nprocs);
