function b = solve_getrs(A, b, varargin)
% solve_getrs  Solves a linear system with A storing the LU factorization
%     b = solve_getrs(A, b) performs back and forward solve on A, where
%     A stores the LU factors in the format returned by LAPACK's DGETRF.
%
%     b = solve_getrs(A, b, n) uses n instead of size(b,1) as n.
%
%     b = solve_getrs(A, b, n, offset) uses vector b(1+offset:n+offset)
%     instead of b.

%#codegen -args {m2c_mat, m2c_vec}
%#codegen solve_getrs_3args -args {m2c_mat, m2c_vec, int32(0)}
%#codegen solve_getrs_4args -args {m2c_mat, m2c_vec, int32(0), int32(0)}

if nargin < 3
    n = int32(size(b,1));
else
    n = int32(varargin{1});
end

if nargin < 4
    offset = int32(0);
else
    offset = int32(varargin{2});
end

% Compute forward on unit lower triangular part
k = int32(1);
for j = 1:n
    k = k + j;
    for i = j+1 : n
        b(i+offset) = b(i+offset) - A(k) * b(j+offset);
        k = k + 1;
    end
end

% Compute backsolve on upper triangular part
k = n * n;
for j = n:-1:1
    b(j+offset) = b(j+offset) / A(k);
    
    for i = j-1:-1:1
        k = k - 1;
        b(i+offset) = b(i+offset) - A(k) * b(j+offset);
    end
    k = k - (n - j) - 2;
end

function test  %#ok<DEFNU>
%!test
%! for k=1:100
%!     A = rand(10,10); b = A * ones(10, 1);
%!
%!     if condest(A)<1.e5
%!         [L, U, p] = lu(A, 'vector');
%!         B = tril(L, -1) + U;
%!     
%!         x = solve_getrs(B, b(p));
%!         assert(norm(A*x - b, inf) <= 1.e-12);
%!     end
%! end
