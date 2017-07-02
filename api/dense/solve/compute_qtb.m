function bs = compute_qtb(Q, bs, ncols) 
%#codegen -args {coder.typeof(0, [inf, inf], [1,1]), coder.typeof(0, [inf,inf], [1,1]), int32(0)}
nrow = int32(size(Q,1));
for k=1:ncols
    % Optimized version for
    % bs(k:nrow,:) = bs(k:nrow,:) - 2*v*(v'*bs(k:nrow,:)),
    % where v is Q(k:npngs)
    for jj=1:int32(size(bs,2))
        t2 = 0; 
        for ii=k:nrow; t2 = t2+Q(ii,k)*bs(ii,jj); end; 
        t2 = t2+t2;
        for ii=k:nrow; bs(ii,jj) = bs(ii,jj) - t2 * Q(ii,k); end
    end
end
