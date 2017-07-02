function [bs,det,A,P] = solve2x2(A, bs) %#codegen
% Solves a 2-by-2 linear system with multiple right-hand side
% using Gaussian elimination with partial pivoting.
%     xs=solve2x2(A,bs)
%     [xs,det]=solve2x2(A,bs)
%     [xs,det,A,P]=solve2x2(A,bs)
% A is a 2-by-2 matrix of coefficients, and bs is 2-by-k.
% If xs and bs use the same variable, then bs is passed by reference.
% If det is specified for output, it also returns the determinant of the matrix.
% If A is specified for output, then A is passed by reference, and it
% stores the L and U factors at output, with P storing the permutation vector.
%
% See also SOLVE3X3

coder.extrinsic('warning');
coder.inline('always');

if nargout>3; P=int32(1:3); end

if isempty(coder.target) && isa(A, 'sym') && A(1,1)~=0 || ...
        (~isempty(coder.target) || ~isa(A, 'sym')) && abs(A(1,1)) >= abs(A(2,1))
    pivot = A(1,1);
    det = pivot;
    if (det==0); warning('Matrix is singular to working precision.'); end
else
    pivot = A(2,1);
    det = -pivot;
    T = A(2,:); A(2,:)=A(1,:); A(1,:)=T;
    T = bs(2,:); bs(2,:)=bs(1,:); bs(1,:)=T;
    if nargout>3; P(1)=2; P(2)=1; end
end

A(2,1) = A(2,1)/pivot;
A(2,2) = A(2,2) - A(2,1)*A(1,2);
bs(2,:) = bs(2,:) - A(2,1)*bs(1,:);

if (A(2,2)==0); warning('Matrix is singular to working precision.'); end
det = det*A(2,2);
bs(2,:) = bs(2,:) / A(2,2);
bs(1,:) = (bs(1,:) - A(1,2)*bs(2,:)) / A(1,1);

function test %#ok<DEFNU>
%!test
%! for k=1:1000
%!     A = rand(2,2); bs = rand(2,1);
%!     if condest(A)<1.e5
%!         [u1,d] = solve2x2(A, bs);
%!         assert(norm(A*u1-bs)<=1.e-12 && abs(d-det(A))<=1.e-12);
%!     end
%! end
