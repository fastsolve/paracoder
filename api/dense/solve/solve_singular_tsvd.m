function x = solve_singular_tsvd(A, b, rnk)
% Solve a singular system (or rank-deficient least squares problem) 
% using truncated SVD.
%     x = solve_singular_tsvd(A, b, rnk)
% b is m-by-k, where k is th enumber of columns of the right-hand side.
% rnk specifies the rank of A (if specified). If not specified, 
%    then rnk is estimated based on the singular values.

if issparse(A)
    [U,S,V] = svds(A,min(size(A,1),size(A,2)));
else
    [U,S,V] = svd(A,min(size(A,1),size(A,2)));
end
x = zeros(size(A,1),size(b,2));

if nargin<3
    tol = 1.e-10;
    rnk = size(A,1);
    for k=size(S,1):-1:1
        if abs(S(k,k)) < abs(S(1,1))*tol
            rnk = rnk - 1;
        else
            break;
        end
    end
end

for i=1:rnk
     x = x + (U(:,i)'*b)/S(i,i)*V(:,i);
end
