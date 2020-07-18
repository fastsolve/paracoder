function [kappa,buf] = condest_triu(R, m, maxiter, buf)
% Estimate the condition number in 1-norm of an upper triangular matrix.
%       K = condest_triu(R, m, maxiter) computes a lower bound K for
%   the 1-norm condition number of an upper triangular matrix R.
%   m specifies the number of columns (default is min(size(R))).
%   maxiter specifies a positive integer parameter equal to the maximum
%   number of iterations during the process. The default value of maxiter is 2.
%
%   To avoid memory allocation, use
%       [K, buf] = condest_triu(R, m, maxiter, buf),
%   where buf should be a struct with fields x and z,
%       each being a m-by-1 array or larger.
%
% See also normest, qrcp_trucate

%#codegen -args {coder.typeof(0,[inf,inf]), int32(0), int32(0),
%#    coder.cstructname(struct('x', coder.typeof(0, [inf,1]), 'z',
%#    coder.typeof(0, [inf,1])), 'CondestBuf')} condest_triu_3args -args
%#    {coder.typeof(0,[inf,inf]), int32(0), int32(0)}

%   Reference:
%   William W. Hager, Condition estimates, SIAM J. Sci. Stat. Comput.
%        vol 5, 311-316, 1984.
%

if nargin<2 || m==0; m = min(int32(size(R,1)),int32(size(R,2))); end
if nargin<3; maxiter = int32(2); end
if nargin<4
    buf.x = zeros(m,1); buf.z = zeros(m,1);
else
    assert(isfield(buf, 'x') && size(buf.x,1)>=m && size(buf.x,2)==1);
    assert(isfield(buf, 'z') && size(buf.z,1)>=m && size(buf.z,2)==1);
end

%% First, compute 1-norm of R
nrm1 = 0;
for j=1:m
    if R(j,j)==0; kappa=1/R(j,j); return; end
    t = 0; for i=1:j; t = t + abs(R(i,j)); end
    if t>nrm1; nrm1=t; end
end

%% Second, estimate 1-norm of R, starting with e_m.
buf.x(m)=1; j=int32(m);

k=int32(1);
while true
    % Estimate nrm1_inv as norm1(R\buf.x)
    buf.x = backsolve(R, buf.x, m);
    if k>=maxiter; break; else k=k+1; end

    % Compute xi and buf.z=R'\xi (use buf.z to store xi and buf.z)
    for i=1:m; buf.z(i)=2*double(buf.x(i)>=0)-1; end
    buf.z = forwardsolve_trans(R,buf.z,m);

    % t = max(abs(buf.z));
    t = abs(buf.z(j)); j=int32(0);
    for i=1:m
        a = abs(buf.z(i)); if a>t; t = a; j=i; end
    end

    if j==0; break;
    else buf.x(:) = 0; buf.x(j)=1; end
end

% return condition number
nrm1_inv = 0;
for i=1:m; nrm1_inv = nrm1_inv + abs(buf.x(i)); end
kappa = nrm1_inv*nrm1;


function test  %#ok<DEFNU>
%!test
%! for i=1:10000
%!     R = triu(rand(30,30));
%!     kappa = condest_triu(R,int32(2));
%!     condref = condest(R);
%!     assert((condref-kappa)/condref<1.1);
%! end
