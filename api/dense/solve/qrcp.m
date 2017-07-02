function [A, varargout] = qrcp(A, rtol, ncols, varargin) %#codegen
% Perform QR factorization with column pivoting using Householder QR.
%     [X, P, rnk, kappa] = qrcp(A)
%     [X, P, rnk, kappa] = qrcp(A, rtol)
%     [X, P, rnk, kappa] = qrcp(A, rtol, ncols)
%     [X, P, rnk, kappa] = qrcp(A, rtol, ncols, fixcol1)
%     [X, P, rnk, kappa] = qrcp(A, rtol, ncols, coldeps)
%     [X, cpivot, rnk, kappa]  = qrcp(A, rtol, ncols, cpivot)
% It solves A(:,P) = Q*R, where P is a permutation vector. The diagonal
% entries of R are sorted in descending order of their magnitudes 
% (subject to some constraints specified by cpivot.coldep).
% At output, the R matrix is stored in the upper triangular part of X.
% The Householder reflector vectors are saved into the strictly lower
% triangular part of X, except for the first entry of each reflector,
% which is not stored as it is equal to sqrt(1- v(2:end)'*v(2:end))
% and can be recovered from the other entries.
%
% The function truncates R if the estimated 1-norm of the condition
% number of R is greater than 1/rtol. rnk is the estimated rank.
%
% If fixcol1 is present (a logical variable) and is true, 
%    then the first column would not be permuted.
%
% If coldeps is present (an uint8 array), then permutation will 
%    preserve the order specified by coldeps.
%
% In the most general case, cpivot should specify a structure as 
%    defined in qrcp_init_cpivot.
%
% The function is more memory efficient if A and X are the same variable
% for the caller, as X will overwrite A.
%
% See also: qr_qmulti, qr_qtmulti, qrcp_forwardsolve_trans, qrcp_init_cpivot

% References:
% 1. P.A.  Businger  and  G.H.  Golub,  Linear  least  squares  solutions
% by  Householder  transformation,  Namer.  Math. 7,  269-276,  (1965).
% 2. http://www.netlib.org/lapack/lug/node42.html

nrows = int32(size(A,1));
if nargin<3; ncols = int32(size(A,2)); end

if nargout>1 || (nargin>=4 && isstruct(varargin{1}))
    if nargin>=4 && isstruct(varargin{1})
        cpivot = varargin{1};
    else
        cpivot = qrcp_init_cpivot(nrows, ncols);
    end
    
    % Initialize permutation vector
    for i=1:ncols; cpivot.new2old(i) = i; cpivot.old2new(i) = i; end    

    if nargin<4 || islogical(varargin{1}) && ~varargin{1}
        nfronts = ncols; cpivot.fronts(:) = 1:ncols;
    elseif islogical(varargin{1})
        nfronts = int32(1); cpivot.fronts(1) = 1; 
    else
        cpivot.deps(:) = 0;
        nfronts = int32(0);
        for i=1:ncols
            if cpivot.deps(i)==0
                nfronts = nfronts+1;
                cpivot.fronts(nfronts) = i;
            end

            for j=1:int32(size(cpivot.coldep,2))
                if i<=size(cpivot.coldep,1) && cpivot.coldep(i,j)~=0
                    j2=i+int32(cpivot.coldep(i,j));
                    if j2<=ncols; cpivot.deps(j2) = cpivot.deps(j2)+1; end
                end
            end
        end
    end
else
    % Initilize Householder vector
    cpivot.hv = coder.nullcopy(zeros(nrows,1));
end

if nargin<2; rtol=1.e-16; end

if nargout>1
    % Compute squared norm of columns
    for jj=1:ncols
        s = 0; for ii=1:nrows; s = s+A(ii,jj)*A(ii,jj); end
        cpivot.cnorms(jj) = s;
    end

    tol_diag=cpivot.cnorms(1)*rtol*rtol;
end
rnk=min(ncols,nrows);

for k=1:rnk
    nv = nrows-k+1;
    
    % Perform column pivoting
    if nargout>1 && nfronts>0
        % Update squared norm of columns
        if k>1
            for jj=k:ncols
                s = A(k-1,jj)*A(k-1,jj); cpivot.cnorms(jj) = cpivot.cnorms(jj)- s;
            end
        end

        sqnorm_v = -realmax; maxfrnt = int32(0); maxcol=int32(0);        
        for i=1:nfronts
            jj=cpivot.old2new(cpivot.fronts(i));
            if cpivot.cnorms(jj)>sqnorm_v; 
                sqnorm_v = cpivot.cnorms(jj); maxcol = jj; maxfrnt=i;              
            end
        end
        
        % Recompute sqnorm_v to avoid effect of rounding errors
        sqnorm_v = 0;
        for ii=1:nv;
            sqnorm_v = sqnorm_v+A(ii+k-1,maxcol)*A(ii+k-1,maxcol);
        end
        
        if sqnorm_v==0
            rnk=k-1;
            break;
        elseif sqnorm_v<tol_diag
            % Truncate all the remaining columns
            for i=k:nrows; for j=k:ncols; A(i,j)=0; end; end
            rnk=k-1;
            break;
        elseif maxcol~=k
            % Permute entries in cpivot.new2old, cpivot.old2new and columns in A
            i = cpivot.new2old(k); 
            cpivot.old2new(cpivot.new2old(maxcol)) = k; cpivot.old2new(i) = maxcol;
            cpivot.new2old(k) = cpivot.new2old(maxcol); cpivot.new2old(maxcol) = i;
            for ii=1:nrows
                t = A(ii,k); A(ii,k) = A(ii,maxcol); A(ii,maxcol) = t;
            end
            t = cpivot.cnorms(k); cpivot.cnorms(k)=cpivot.cnorms(maxcol); cpivot.cnorms(maxcol) = t;
        end
        
        % Update cpivot.fronts and cpivot.deps
        nfronts = nfronts-1;
        if maxfrnt<=nfronts
            cpivot.fronts(maxfrnt)=cpivot.fronts(nfronts+1);
        end

        i = cpivot.new2old(k);
        for j=1:int32(size(cpivot.coldep,2))
            if i<=size(cpivot.coldep,1) && cpivot.coldep(i,j)~=0
                j2=i+int32(cpivot.coldep(i,j));
                if j2<=ncols
                    cpivot.deps(j2) = cpivot.deps(j2)-1;
                
                    if cpivot.deps(j2)==0
                        nfronts = nfronts+1;
                        cpivot.fronts(nfronts) = j2;
                    end
                end
            end
        end

        if nfronts==0 && k==1
            % Update for the case where only first column is fixed
            nfronts = ncols-1;
            cpivot.fronts(1:nfronts) = 2:ncols;
        end
    else
        sqnorm_v = 0;
        for ii=1:nv; sqnorm_v = sqnorm_v+A(ii+k-1,k)*A(ii+k-1,k); end
    end
    
    for jj=1:nv; cpivot.hv(jj) = A(jj+k-1,k); end
    t = sqrt(sqnorm_v);
    
    if cpivot.hv(1)>=0
        vnrm2 = sqrt(2*(sqnorm_v + cpivot.hv(1)*t));
        cpivot.hv(1) = cpivot.hv(1) + t;
        if vnrm2>0;
            for jj=1:nv; cpivot.hv(jj) = cpivot.hv(jj) / vnrm2; end;
        end
    else
        vnrm2 = sqrt(2*(sqnorm_v - cpivot.hv(1)*t));
        cpivot.hv(1) = cpivot.hv(1) - t;
        % Flip the sign to make sure cpivot.hv(1) is nonnegative.
        if vnrm2>0
            for jj=1:nv; cpivot.hv(jj) = -cpivot.hv(jj) / vnrm2; end;
        else
            cpivot.hv(1) = -cpivot.hv(1);
        end
    end
    
    % Optimized version for
    % A(k:npnts,k:ncols) = A(k:npnts,k:ncols) - 2*cpivot.hv*(cpivot.hv'*A(k:npnts,k:ncols));
    for jj=k:ncols
        t = 0; for ii=1:nv; t = t+cpivot.hv(ii)*A(ii+k-1,jj); end
        t = t+t;
        for ii=1:nv; A(ii+k-1,jj) = A(ii+k-1,jj) - t * cpivot.hv(ii); end
    end
    
    for i=2:nv; A(i+k-1,k) = cpivot.hv(i); end
end

% Truncate R if estimated condition number is large.
if nargout>3
    [ A, rnk, kappa, cpivot] = qrcp_trucate(A, rnk, rtol, cpivot);
    
    varargout{3} = kappa;
end

if nargout>2
    varargout{2} = rnk;
end

if nargout>1
    if nargin<4 || ~isstruct(varargin{1})
        varargout{1} = cpivot.new2old;
    else
        varargout{1} = cpivot;
    end
end

function test %#ok<DEFNU>
%!test
%! m = 20; n = 10;
%! for i=1:10000
%!   A = rand(m,n); bs = rand(m,2);
%!   xs1 = A\bs;
%!   [A, new2old, rnk] = qrcp(A);
%!   for j=1:9; assert(abs(A(j,j))>=abs(A(j+1,j+1))); end
%!   bs = qr_qtmulti(A, bs, n);
%!   xs2 = backsolve(A, bs(1:n,:));
%!   xs2(new2old,:) = xs2;
%!   assert(norm(xs1-xs2)<=1.e-10);
%! end

%!test
%! m = 20; n = 10;
%! for i=1:10000
%!   A = rand(m,n); bs = rand(m,2);
%!   xs1 = A\bs;
%!   [A, new2old, rnk] = qrcp(A, 1.e-16, n, true);
%!   for j=2:9; assert(abs(A(j,j))>=abs(A(j+1,j+1))); end
%!   bs = qr_qtmulti(A, bs, n);
%!   xs2 = backsolve(A, bs(1:n,:));
%!   xs2(new2old,:) = xs2;
%!   assert(norm(xs1-xs2)<=1.e-10);
%! end

%!test
%! m = 20; n = 10;
%! for i=1:10000
%!   A = rand(m,n); bs = rand(m,2);
%!   coldep = ones(n,1,'uint8');
%!   xs1 = A\bs;
%!   [A, new2old, rnk] = qrcp(A, 1.e-16, n, coldep);
%!   bs = qr_qtmulti(A, bs, n);
%!   xs2 = backsolve(A, bs(1:n,:));
%!   xs2(new2old,:) = xs2;
%!   assert(norm(xs1-xs2)<=1.e-10);
%! end

%!test
%! m = 20; n = 10;
%! cpivot = qrcp_init_cpivot(m, n);

%! for i=1:10000
%!   m = 20; n = 10;
%!   A = rand(m,n); bs = rand(m,2);
%!   xs1 = A\bs;
%!   [A, cpivot, rnk] = qrcp(A, 1.e-16, n, cpivot);
%!   bs = qr_qtmulti(A, bs, n);
%!   xs2 = backsolve(A, bs(1:n,:));
%!   xs2(cpivot.new2old,:) = xs2;
%!   assert(norm(xs1-xs2)<=1.e-10);
%! end
