function d = det2(a1, a2) %#codegen 
%DET2 Compute determinant of 2x2 matrix.
% DET2(A) computes determinant of 2x2 matrix A.
% DET2(A1,A2) computes determinant of 2x2 matrix [A1,A2], where A1 and
% A2 are 2-dimensional column vectors.

if nargin==1
    assert(size(a1,1)==2 && size(a1,2)==2);
    d = a1(1,1)*a1(2,2)-a1(1,2)*a1(2,1);
else
    assert(nargin==2);
    d = a1(1)*a2(2)-a1(2)*a2(1);
end
