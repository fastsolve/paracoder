function OMP_clause_private(var1, var2, var3, var4, var5, ...
    var6, var7, var8, var9, var10) %#codegen
%OMP_clause_private  declares variables in its list to be private to each thread.
%   OMP_clause_private(var1, var2, ...)
%
% Example: OMP_clause_private(var1, var2, ...)
%
% Note: It is advisable to declare all the local scalar variables private,
%       since codegen might reuse some of the variables during computaiton.

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

switch nargin
    case 0
        coder.ceval('#++ private');
    case 1
        coder.ceval('#++ private', coder.rref(var1));
    case 2
        coder.ceval('#++ private', coder.rref(var1), coder.rref(var2));
    case 3
        coder.ceval('#++ private', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3));
    case 4
        coder.ceval('#++ private', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4));
    case 5
        coder.ceval('#++ private', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5));
    case 6
        coder.ceval('#++ private', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6));
    case 7
        coder.ceval('#++ private', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7));
    case 8
        coder.ceval('#++ private', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8));
    case 9
        coder.ceval('#++ private', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8), coder.rref(var9));
    case 10
        coder.ceval('#++ private', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8), coder.rref(var9), coder.rref(var10));
    otherwise
        m2cerror('OMP_clause_private:TooManyArguments', ...
            'There are too many input arguments.');
end
