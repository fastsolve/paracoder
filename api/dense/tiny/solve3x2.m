function us = solve3x2(A, b) %#codegen
% This function solves the system Au=b, where A is 3-by-2, b is 3-by-k.
%    us = solve3x2(a, b)
% It solves using Gram-Schimdt QR factorization of A.

[Q,R] = qr3x2(A);
us = Q'*b;

us(2,:) = us(2,:)/R(2,2);
us(1,:) = (us(1,:) - R(1,2)*us(2,:))/R(1,1);

function test %#ok<DEFNU>
%!test
%! for k=1:1000
%!     A = rand(3,2);
%!     if A(:,1)'*A(:,2)>1.e-5
%!     b = A*rand(2,3);
%!         u1 = solve3x2(A, b);
%!         assert(norm(A*u1-b)<=1.e-12);
%!     end
%! end
