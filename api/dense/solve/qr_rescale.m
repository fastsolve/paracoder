function [A, rnk, V] = qr_rescale(A, ncols, tol)
% Compute Householder QR factorization.
%     [A, rnk, V] = qr_rescaled(A, ncols, tol)
% It rescales the column vectors of A to be unit vectors, so that
% nearly singular matrices can be identified. With a given tolerance,
% it estimates a "rank", which ensures that for the first columns
% up to "rank", the angles between a column from the subspace of
% its preceding columns hyperplanes of are bounded above asin(tol).
%
% At output, it stores the R matrix into the upper triangular part of A.
% The Householder reflector vectors are saved into the lower triangular
% part of A, except for the first entry of each reflector vector, which
% is equal to sqrt(1- v(2:end)'*v(2:end)) so can be recovered from the other
% entries. Alternatively, the first entries can be returned if V is given
% as an output argument.
%
% See also qr_qtmulti, qr_qmulti

%#codegen -args {coder.typeof(0,[inf,inf]), int32(0), 0}

if nargin<2; ncols = int32(size(A,2)); end
if nargin<3; tol=1.e-6; end

if nargout>2; V = coder.nullcopy(zeros(ncols,1)); end

% Scale columns of A to reduce condition number and allow
% estimation of angles between columns.
[A, ts] = rescale_matrix(A, ncols);

rnk = ncols;
nrows = int32(size(A,1));
v = coder.nullcopy(zeros(nrows,1));

for k=1:ncols
    nv = nrows-k+1;
    for jj=1:nv; v(jj) = A(jj+k-1,k); end
    
    % We don't need to worry about overflow, since A has been rescaled.
    t2 = 0; for jj=1:nv; t2 = t2+v(jj)*v(jj); end
    t = sqrt(t2);
    
    if v(1)>=0
        vnrm2 = sqrt(2*(t2 + v(1)*t));
        v(1) = v(1) + t;
    else
        vnrm2 = sqrt(2*(t2 - v(1)*t));
        v(1) = v(1) - t;
        for jj=1:nv; v(jj) = -v(jj); end
    end
    
    if vnrm2>0; for jj=1:nv; v(jj) = v(jj) / vnrm2; end; end
    
    % Optimized version for
    % A(k:npnts,k:ncols) = A(k:npnts,k:ncols) - 2*v*(v'*A(k:npnts,k:ncols));
    for jj=k:ncols
        t2 = 0; for ii=1:nv; t2 = t2+v(ii)*A(ii+k-1,jj); end
        t2 = t2+t2;
        for ii=1:nv; A(ii+k-1,jj) = A(ii+k-1,jj) - t2 * v(ii); end
    end
    
    % Conserative estimation of the "rank" of the rescaled matrix
    if abs(A(k,k))<tol && rnk == ncols
        rnk = k-1;
    end
    
    for i=2:nv; A(i+k-1,k) = v(i); end
    if nargout>2; V(k) = v(1); end
end

% Rescale the R part back.
for k=1:ncols
    for j=1:k
        A(j,k) = A(j,k)*ts(k);
    end
end

function [A, ts] = rescale_matrix(A, ncols)
% Rescale the columns of matrix to reduce condition number and to
% allow better detection of singularities.

ts = coder.nullcopy(zeros(ncols,1));

for ii=1:ncols
    v = A(:,ii);
    ts(ii) = vec_norm2(v);
    
    if abs(ts(ii)) == 0
        ts(ii)=0;
    else
        for kk=1:int32(size(A,1))
            A(kk,ii) = A(kk,ii) / ts(ii);
        end
    end
end
