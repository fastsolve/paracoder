function d = det3(a1, a2, a3) %#codegen 
%DET3 Compute determinant of 3x3 matrix.
% DET3(A) computes determinant of 3x3 matrix A.
% DET3(A1,A2,A3) computes determinant of 3x3 matrix [A1,A2,A3], where A1,
% A2 and A3 are 3-dimensional column vectors.
%
% See also CROSS_ROW

if nargin==1
    assert(size(a1,1)==3 && size(a1,2)==3);
    d = cross_row(a1(:,1),a1(:,2))*a1(:,3);
else
    assert(nargin==3);
    d = cross_row(a1,a2)*a3;
end
