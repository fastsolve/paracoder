function OMP_clause_lastprivate(var1, var2, var3, var4, var5, ...
    var6, var7, var8, var9, var10) %#codegen
%OMP_clause_lastprivate  Declares lastprivate variables.
%   OMP_clause_lastprivate(var1, var2, ...)
%
% This clause combines the behavior of the PRIVATE clause with a copy from
% the last loop iteration or section to the original variable object.
% It can be used after OMP_begin_section.
%
% Example:
%    OMP_begin_section
%    OMP_clause_schedule('static', n)
%    OMP_clause_lastprivate(a, b)
%    
%    % a for loop here ...
%
%    OMP_begin_section


if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

switch nargin
    case 0
        coder.ceval('#++ lastprivate');
    case 1
        coder.ceval('#++ lastprivate', coder.rref(var1));
    case 2
        coder.ceval('#++ lastprivate', coder.rref(var1), coder.rref(var2));
    case 3
        coder.ceval('#++ lastprivate', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3));
    case 4
        coder.ceval('#++ lastprivate', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4));
    case 5
        coder.ceval('#++ lastprivate', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5));
    case 6
        coder.ceval('#++ lastprivate', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6));
    case 7
        coder.ceval('#++ lastprivate', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7));
    case 8
        coder.ceval('#++ lastprivate', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8));
    case 9
        coder.ceval('#++ lastprivate', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8), coder.rref(var9));
    case 10
        coder.ceval('#++ lastprivate', coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8), coder.rref(var9), coder.rref(var10));
    otherwise
        m2cerror('OMP_clause_lastprivate:TooManyArguments', ...
            'There are too many input arguments.');
end

