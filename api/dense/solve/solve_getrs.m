function b = solve_getrs(A, b)
% solve_getrs  Solves a linear system with A in the format returned by
%              LAPACK routine DGETRF
%     b = solve_getrs(A, b)

%#codegen -args {coder.typeof(0,[inf,inf]), coder.typeof(0, [inf,inf])}

n = int32(size(b,1));

% Compute forward on unit lower triangular part
k = int32(1);
for j = 1:n
    k = k + j;
    for i = j+1 : n
        b(i) = b(i) - A(k) * b(j);
        k = k + 1;
    end
end

% Compute backsolve on upper triangular part
k = n * n;
for j = n:-1:1
    b(j) = b(j) / A(k);
    
    for i = j-1:-1:1
        k = k - 1;
        b(i) = b(i) - A(k) * b(j);
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
