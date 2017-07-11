function [V, ts] = rescale_matrix(V, ncols, ts)
%% Rescale the columns of a matrix to reduce condition number
%#codegen -args {coder.typeof(0, [inf,inf], [1,1]), int32(0), coder.typeof(0, [inf,1], [1,0])}
if nargin < 2
    ncols=int32(size(V,2));
end
if nargin < 3
    ts = coder.nullcopy(zeros(ncols,1));
else
    assert(length(ts)>=ncols);
end

for ii=1:ncols
    v = V(:,ii);
    ts(ii) = vec_norm2(v);

    if abs(ts(ii)) == 0
        ts(ii)=1;
    else
        for kk=1:int32(size(V,1))
            V(kk,ii) = V(kk,ii) / ts(ii);
        end
    end
end
