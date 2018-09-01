function [A,R] = qr3x3(A) %#codegen 
% Computes QR factorization of a 3x3 matrix using modified Gram-Schimdt orthogonalization.
% [Q,R] = qr3x3(A)
%
% When called with [A,R] = qr3x3(A), then the code overwrites A.

coder.inline('always');

R = coder.nullcopy(zeros(3,3));
R(1,1) = sqrt(vec_sqnorm2(A(:,1)));
A(:,1) = A(:,1)/R(1,1);
R(1,2) = A(:,1)'*A(:,2);

A(:,2) = A(:,2) - R(1,2)*A(:,1);
R(2,2) = sqrt(vec_sqnorm2(A(:,2)));
A(:,2) = A(:,2)/R(2,2);

R(1,3) = A(:,1)'*A(:,3);
A(:,3) = A(:,3) - R(1,3)*A(:,1);
R(2,3) = A(:,2)'*A(:,3);

A(:,3) = A(:,3) - R(2,3)*A(:,2);
R(3,3) = sqrt(vec_sqnorm2(A(:,3)));
A(:,3) = A(:,3)/R(3,3);

function test %#ok<DEFNU>
%!test
%! for k=1:1000
%!     A = rand(3,3);
%!     [Q,R] = qr3x3(A);
%!     assert(norm(eye(3)-Q'*Q)<=1.e-12 && norm(Q*R-A)<=1.e-12);
%! end
