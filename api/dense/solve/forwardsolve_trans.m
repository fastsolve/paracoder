function bs = forwardsolve_trans(R, bs, cend, ws) %#codegen
% Perform forward substitution R'\bs.
%     bs = forwardsolve_trans(R, bs)
%     bs = forwardsolve_trans(R, bs, cend)
%     bs = forwardsolve_trans(R, bs, cend, ws)
%  Compute bs = (triu(R(1:cend,1:cend))'\bs) ./ ws;
%  The right-hand side vector bs can have multiple columns.
%  By default, cend is size(R,2), and ws is ones.

if nargin<3; cend = int32(size(R,2)); end

for kk=1:int32(size(bs,2))
    % Skip zeros in bs
    cstart = cend+1;
    for ii=1:cend
        if (bs(ii)~=0)
            cstart = ii;
            break;
        end
    end
    
    for jj=cstart:1:cend
        for ii=cstart:jj-1
            bs(jj,kk) = bs(jj,kk) - R(ii,jj) * bs(ii,kk);
        end
        
        assert(R(jj,jj)~=0);
        bs(jj,kk) = bs(jj,kk) / R(jj,jj);
    end
end

if nargin>3
    % Scale bs back if ts is given.
    for kk=1:int32(size(bs,2))
        for jj = cstart:cend
            bs(jj,kk) = bs(jj,kk) / ws(jj);
        end
    end
end

function test  %#ok<DEFNU>
%!test
%! for k=1:100
%!     R = triu(rand(10,10)); bs = rand(10,2);
%!     if condest(R)<1.e5
%!         us = forwardsolve_trans(R, bs);
%!         assert(norm(R'*us-bs)<=1.e-12);
%!     end
%! end
