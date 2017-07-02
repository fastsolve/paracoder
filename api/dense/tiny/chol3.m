function [R,err] = chol3(A) %#codegen
% CHOL3 Perform cholesky factorization of a 3x3 SPD matrix.
%   R=CHOL3(A).
%   A is a 3-by-3 SPD matrix. Only its upper triangular part is accessed.
%
% See also CHOL2.

R = zeros(3,3);

if A(1,1)<=0; err = -1; return; end
R(1,1) = sqrt(A(1,1));
R(1,2) = A(1,2) / R(1,1);
R(1,3) = A(1,3) / R(1,1);

R(2,2) = A(2,2) - R(1,2)*R(1,2);
R(2,3) = A(2,3) - R(1,3)*R(1,2);
R(3,3) = A(3,3) - R(1,3)*R(1,3);

if R(2,2)<=0; err = -1; return; end

R(2,2) = sqrt(R(2,2));
R(2,3) = R(2,3) / R(2,2);

R(3,3) = R(3,3) - R(2,3)*R(2,3);

if R(3,3)<=0; err = -1; return; end

R(3,3) = sqrt(R(3,3));

err = 0;
