function [bs,det,A,P,flag] = solve3x3(A, bs) %#codegen
% Solves a 3x3 linear system with multiple right-hand side vectors
% using Gaussian elimination with partial pivoting.
%     xs=solve3x3(A,bs)
%     [xs,det]=solve3x3(A,bs)
%     [xs,det,A,P]=solve3x3(A,bs)
% A is a 3-by-3 matrix of coefficients, and B is 3-by-k.
% If xs and bs use the same variable, then bs is passed by reference.
% If det is specified for output, it also returns the determinant of the matrix.
% If A is specified for output, then A is passed by reference, and it
% stores the L and U factors at output, with P storing the permutation vector.
%
% See also solve2x2

coder.extrinsic('warning');
if nargout>3; P=int32(1:3); end
flag = int32(0);

S = abs(A(1:3,1));
if S(1)>=S(2) && S(1)>=S(3)
    pivot = A(1,1);
    det = pivot;
    if (pivot==0);
        warning('Matrix is singular to working precision.'); flag = int32(1);
    end
elseif S(2)>=S(3)
    pivot = A(2,1);
    det = -pivot;
    T = A(2,:); A(2,:)=A(1,:); A(1,:)=T;
    T = bs(2,:); bs(2,:)=bs(1,:); bs(1,:)=T;
    if nargout>3; P(1)=2; P(2)=1; end
else
    if nargout>3; P(1)=2; end
    pivot = A(3,1);
    det = -pivot;
    T = A(3,:); A(3,:)=A(1,:); A(1,:)=T;
    T = bs(3,:); bs(3,:)=bs(1,:); bs(1,:)=T;
    if nargout>3; P(1)=3; P(3)=1; end
end

A(2,1) = A(2,1)/pivot;
A(2,2:end) = A(2,2:end) - A(2,1)*A(1,2:end);
bs(2,:) = bs(2,:) - A(2,1)*bs(1,:);

A(3,1) = A(3,1)/pivot;
A(3,2:end) = A(3,2:end) - A(3,1)*A(1,2:end);
bs(3,:) = bs(3,:) - A(3,1)*bs(1,:);

S = abs(A(2:3,2));
if S(1) >= S(2)
    pivot = A(2,2);
    det = det*pivot;
    if (pivot==0);
        warning('Matrix is singular to working precision.'); flag = int32(2);
    end
else
    pivot = A(3,2);
    det = -det*pivot;
    T = A(3,:); A(3,:)=A(2,:); A(2,:)=T;
    T = bs(3,:); bs(3,:)=bs(2,:); bs(2,:)=T;
    if nargout>3; i=P(3); P(3)=P(2); P(2)=i; end
end

A(3,2) = A(3,2)/pivot;
A(3,3) = A(3,3) - A(3,2)*A(2,3);
bs(3,:) = bs(3,:) - A(3,2)*bs(2,:);
if (A(3,3)== 0);
    warning('Matrix is singular to working precision.'); flag = int32(3);
end
det = det*A(3,3);

bs(3,:) = bs(3,:) / A(3,3);
bs(2,:) = (bs(2,:) - A(2,3)*bs(3,:)) / A(2,2);
bs(1,:) = (bs(1,:) - A(1,3)*bs(3,:) - A(1,2)*bs(2,:)) / A(1,1);

function test %#ok<DEFNU>
%!test
%! for k=1:1000
%!     A = rand(3,3); bs = rand(3,2);
%!     if condest(A)<1.e5
%!         [u1,d] = solve3x3(A, bs);
%!         assert(norm(A*u1-bs)<=1.e-12 && abs(d-det(A))<1.e-12);
%!     end
%! end
