function [R,err] = chol2(A) %#codegen
% CHOL2 Perform cholesky factorization of a 2x2 SPD matrix.
%   R=CHOL2(A).
%   A is a 2-by-2 SPD matrix. Only its upper triangular part is accessed.
%
% See also CHOL3.

R = zeros(2,2);

if A(1,1)<=0; err = -1; return; end
R(1,1) = sqrt(A(1,1));
R(1,2) = A(1,2) / R(1,1);
R(2,2) = A(2,2) - R(1,2)*R(1,2);

if R(2,2)<=0; err = -1; return; end
R(2,2) = sqrt(R(2,2));

err = 0;
