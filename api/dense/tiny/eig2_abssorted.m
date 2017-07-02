function [V,lambdas] = eig2_abssorted(A) %#codegen
%EIG2_ABSSORTED Perform eigenvalue-decomposition of 2x2 matrix A.
% [V,LAMBDAS] = eig2_abssorted(A) computes eigenvalues and eigenvectors of a 
% 2x2 symmetric matrix A and stores them into 2x1 vector LAMBDAS and 2x2 
% matrix V, respectively. The eigenvalues are sorted from large to small
% in their absolte values.
%
% The function accesses only the diagonal and upper triangular parts of A.
% The access is read-only.
%
% See also eig, eig2, eig3

[V,D] = eig2(A);
lambdas = [D(1,1);D(2,2)];
if abs(lambdas(1))<abs(lambdas(2))
    lambdas([1,2])=lambdas([2,1]);
    V(:,[1,2]) = V(:,[2,1]);
end
