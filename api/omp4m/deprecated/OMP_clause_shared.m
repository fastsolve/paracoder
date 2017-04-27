function OMP_clause_shared(var1, var2, var3, var4, ...
    var5, var6, var7, var8, var9, var10) %#codegen
%OMP_clause_shared  declares variables in its list to be shared by the team.
%   OMP_clause_shared(var1, var2, ...)
%
% See also OMP_clause_default

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

switch nargin
    case 1
        coder.ceval('#++ shared', coder.rref(var1));
    case 2
        coder.ceval('#++ shared', coder.rref(var1), coder.rref(var2));
    case 3
        coder.ceval('#++ shared', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3));
    case 4
        coder.ceval('#++ shared', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4));
    case 5
        coder.ceval('#++ shared', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5));
    case 6
        coder.ceval('#++ shared', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6));
    case 7
        coder.ceval('#++ shared', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7));
    case 8
        coder.ceval('#++ shared', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8));
    case 9
        coder.ceval('#++ shared', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8), coder.rref(var9));
    case 10
        coder.ceval('#++ shared', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8), coder.rref(var9), coder.rref(var10));
    otherwise
        m2cerror('OMP_clause_shared:TooManyArguments', ...
            'There are too many input arguments.');
end
