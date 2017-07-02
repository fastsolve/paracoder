function [V,lambdas] = eig3_sorted(A) %#codegen
%EIG3_SORTED Perform eigenvalue-decomposition of 3x3 matrix A
% [V,lambdas] = eig3_sorted(A) computes eigenvalues and eigenvectors of a 
% 3x3 symmetric matrix A and stores them into 3x1 vector lambdas and 3x3 
% matrix V, respectively. The eigenvalues are sorted from large to small.
%
% The function accesses only the diagonal and upper triangular parts of A.
% The access is read-only.
%
% See also eig, eig2, eig3

[V,D] = eig3(A);
lambdas = [D(1,1);D(2,2);D(3,3)];
if lambdas(1)<lambdas(2)
    lambdas([1,2])=lambdas([2,1]);
    V(:,[1,2]) = V(:,[2,1]);
end
if lambdas(1)<lambdas(3)
    lambdas([1,3])=lambdas([3,1]);
    V(:,[1,3]) = V(:,[3,1]);
end   
if lambdas(2)<lambdas(3)
    lambdas([2,3])=lambdas([3,2]);
    V(:,[2,3]) = V(:,[3,2]);
end
