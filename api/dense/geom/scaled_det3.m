function d = scaled_det3(A1, A2, A3) %#codegen
%SCALED_DET3 Compute scaled determinant of 3x3 matrix.
% SCALED_DET3(A) computes scaled determinant of 3x3 matrix A.
%
% SCALED_DET3(A1,A2,A3) computes scaled determinant of 3x3 matrix
% [A1,A2,A3], where A1, A2, and A3 are 3-dimensional column vectors.
%
% See also DET3

if nargin==1
    assert(size(A1,1)==3 && size(A2,1)==3);
    
    s = (A1(:,1)*A1(:,1)') * (A1(:,2)*A1(:,2)') * (A1(:,3)*A1(:,3)');
    d = cross_row(A1(:,1),A1(:,2))*A1(:,3) / sqrt(s);
else
    assert(nargin==3 && size(A1,1)==3&&size(A1,2)==1 && ...
        size(A2,1)==3&&size(A2,2)==1 && size(A3,1)==3&&size(A3,2)==1);

    s = (A1'*A1) * (A2'*A2) * (A3'*A3);
    d = cross_row(A1,A2)*A3 / sqrt(s);
end
