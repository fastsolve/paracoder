function [A,R] = qr2x2(A) %#codegen
% Computes QR factorization of a 2x2 matrix using Gram-Schimdt orthogonalization.
% [Q,R] = qr2x2(A)
%
% When called with [A,R] = qr3x2(A), then the code overwrites A.

coder.inline('always');

R = coder.nullcopy(zeros(2,2));
R(1,1) = sqrt(A(1,1)*A(1,1)+A(2,1)*A(2,1));
A(:,1) = A(:,1)/R(1,1);
R(1,2) = A(:,1)'*A(:,2);

A(:,2) = A(:,2) - R(1,2)*A(:,1);
R(2,2) = sqrt(A(1,2)*A(1,2)+A(2,2)*A(2,2));
A(:,2) = A(:,2)/R(2,2);

function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     A = rand(2,2);
%!     [Q,R] = qr2x2(A);
%!     assert(norm(eye(2)-Q'*Q)<=1.e-12 && norm(Q*R-A)<=1.e-12);
%! end
