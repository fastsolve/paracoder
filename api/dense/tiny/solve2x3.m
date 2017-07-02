function us = solve2x3(A, bs) %#codegen
% Solve the system Au=bs, where A is 2-by-3, bs is 2-by-k.
%    us = solve2x3(A, bs)
% It solves as us=pinv(A)*bs;

[Q,R] = qr3x2(A');

% Sovle us = Q*R'\bs
us = coder.nullcopy(zeros(3,size(bs,2)));
us(1,:) = bs(1,:) / R(1,1);
us(2,:) = (bs(2,:) - R(1,2)*us(1,:))/R(2,2);

us = Q*us(1:2,:);

function test %#ok<DEFNU>
%!test
%! for k=1:1000
%!     A = rand(2,3);
%!     if A(1,:)*A(2,:)'>1.e-5
%!         bs = A*rand(3,2);
%!         us = solve2x3(A, bs);
%!         assert(norm(A*us-bs)<=1.e-12);
%!     end
%! end
