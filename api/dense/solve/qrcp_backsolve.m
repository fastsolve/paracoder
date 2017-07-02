function bs = qrcp_backsolve(R, bs, cend, tol) %#codegen
% Perform backward substitution R\bs.
%     xs = qrcp_backsolve(R, bs)
%     xs = qrcp_backsolve(R, bs, cend, tol)
%  Compute xs = (triu(R(1:cend,1:cend))\bs), where bs is the right-hand
%  side and can have multiple columns, and cend is
%  min(int32(size(R,1)),int32(size(R,2))) by default.
%  tol is a relative dropoff tolerance of diagonal entries of R with
%  respect R(1,1). The default value of tol is 1.e-12*R(1,1).
%
%  Note: If xs and bs are the same variable when calling the function,
%   then the function updates bs in-place for better memory efficiency.
%
%  See also qrcp, qrcp_forwardsolve_trans, qr_qmulti, qr_qtmulti.

if nargin<3; cend = min(int32(size(R,1)),int32(size(R,2))); end
if nargin<4; tol = 1.e-16 * abs(R(1,1));
else tol = tol * abs(R(1,1)); end

n = min(int32(size(bs,1)),size(R,2));

for k=1:int32(size(bs,2))
    % Skip zeros in bs.
    cend1 = int32(0);
    for j=cend:-1:1
        if (bs(j,k)~=0); cend1 = j; break; end
    end
    
    for i=cend1:-1:1
        if abs(R(i,i)) > tol
            for j=cend1:-1:i+1
                bs(i,k) = bs(i,k) - R(i,j) * bs(j,k);
            end
            
            bs(i,k) = bs(i,k) / R(i,i);
        else
            cend = i-1;
        end
    end
    for i=cend+1:n; bs(i,k) = 0; end
end

if size(bs,1)<size(R,2)
    bs = [bs; zeros(size(R,2)-size(bs,1), size(bs,2))];
end

function test  %#ok<DEFNU>
%!test
%! for k=1:100
%!     R = triu(rand(10,10)); bs = rand(10,2);
%!     if condest(R)<1.e5
%!         us = qrcp_backsolve(R, bs);
%!         assert(norm(R*us-bs)<=1.e-12);
%!     end
%! end
