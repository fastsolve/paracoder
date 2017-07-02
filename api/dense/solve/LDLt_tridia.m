function [D, L x] = LDLt_tridia(D, L, x) %#codegen 
% LDLt_tirdia  Perform LDL' decomposition of matrix and optional solve
%              linear system.
%
%  [D, L] = LDLt_tirdia(B, C) performs LDL' decomposition for a given
%      symmetric positive definite matrix.
%
%    At input, tridiagonal matrix is
%
%                   /  b1  c1   0   0   0   ...   0  \
%                   |  c1  b2  c2   0   0   ...   0  |
%               A=  |   0  c2  b3  c3   0   ...   0  |
%                   |   :   :   :   :   :    :    :  |
%                   |   0   0   0   0 cn-2 bn-1 cn-1 |
%                   \   0   0   0   0   0  cn-1  bn /
%
%    where bi are stored in vector B, and ci is stored in vector C.
%
%    At output, D is a diagonal matrix and L is
%          /  1   0   0   0   0   ...   0  \
%         |  m1   1   0   0   0   ...   0  |
%     L=  |   0  m2   1   0   0   ...   0  |
%         |   :   :   :   :   :    :    :  |
%         |   0   0   0   0 mn-2   1    0  |
%         \   0   0   0   0   0  mn-1   1  /
%
%    We store the matrix D as a vector D, and store matrix L as a vector.
%
%  [D, L, x] = LDLt_tirdia(B, C, r) solves linear system Ax=r besides 
%      performing the LDL' decomposing.
%
% See also: LDLt_tirdia

assert(length(D)==length(L)+1);

for i=uint32(2):length(D)
    ci = L(i-1);
    
    L(i-1) = L(i-1) / D(i-1);
    D(i) = D(i) - L(i-1) * ci;
end

% Perform solve if nargin>2
if nargin>2
    % Perform forward solve
    for i=uint32(2):length(D)
        x(i) = x(i) - x(i-1)*L(i-1);
    end
       
    % Divide by diagonal entries
    x(:) = x(:) ./ D(:);
        
    % Perform back solve
    for i=length(D)-1:-1:1
        x(i) = x(i) - x(i+1)*L(i);
    end
end
