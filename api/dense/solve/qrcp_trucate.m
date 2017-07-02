function [ R, rnk, kappa, buf ] = qrcp_trucate(R, rnk, rtol, buf ) %#codegen
%qrcp_trucate Estimate infinity-norm condition number of R.
%
%      [ R, rnk, kappa ] = qrcp_trucate(R, rnk, rtol )
% 
% R is upper-triangular matrix.
% rnk specifies the initial rank estimation of R.
% rtol is receiprocal of the upperbound of the condition number.
%
%   To avoid memory allocation, use 
%
%      [ R, rnk, kappa, buf ] = qrcp_trucate(R, rnk, rtol, buf )
%
%   where buf should be a struct with fields x and z, 
%       each being a rnk-by-1 array or larger.

if nargin<2; rnk=min(int32(size(R,1)), int32(size(R,2))); end
if nargin<3 || rtol<=0; rtol=1.e-16; end
if nargin<4; 
    buf.x = zeros(rnk,1); buf.z = zeros(rnk,1);
else
    assert(isfield(buf, 'x') && size(buf.x,1)>=rnk && size(buf.x,2)==1);
    assert(isfield(buf, 'z') && size(buf.z,1)>=rnk && size(buf.z,2)==1);
end

nrows = rnk; ncols = rnk;

% Determine how to truncate R if the estimated condition number is large.
tol = 1/rtol;
while true
    [kappa, buf] = condest_triu(R, rnk, int32(2), buf);
    
    if kappa>tol
        for i=rnk:nrows; for j=rnk:ncols; R(i,j)=0; end; end
        rnk = rnk-1;
    else
        break;
    end
end
