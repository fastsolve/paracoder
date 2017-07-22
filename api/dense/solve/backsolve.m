function bs = backsolve(R, bs, cend, ws) 
% Perform backward substitution.
%     bs = backsolve(R, bs)
%     bs = backsolve(R, bs, cend)
%     bs = backsolve(R, bs, cend, ws)
%  Compute bs = (triu(R(1:cend,1:cend))\bs) ./ ws;
%  The right-hand side vector bs can have multiple columns.
%  By default, cend is size(R,2), and ws is ones.

%#codegen -args {coder.typeof(0,[inf,inf],[1,0]), coder.typeof(0, [inf,inf],[1,0]), int32(0),...
%#codegen coder.typeof(0, [inf,inf],[1,0])}

if nargin<3; cend = int32(size(R,2)); end

for kk=1:int32(size(bs,2))
    for jj=cend:-1:1
        for ii=jj+1:cend
            bs(jj,kk) = bs(jj,kk) - R(jj,ii) * bs(ii,kk);
        end

        assert(R(jj,jj)~=0);
        bs(jj,kk) = bs(jj,kk) / R(jj,jj);
    end
end

if nargin>3
    % Scale bs back if ts is given.
    for kk=1:int32(size(bs,2))
        for jj = 1:cend
            bs(jj,kk) = bs(jj,kk) / ws(jj);
        end
    end
end

function test  %#ok<DEFNU>
%!test 
%! for k=1:100
%!     R = triu(rand(10,10)); bs = rand(10,2);
%!     if condest(R)<1.e5
%!         us = backsolve(R, bs);
%!         assert(norm(R*us-bs)<=1.e-12);
%!     end
%! end
