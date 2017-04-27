function OMP_clause_reduction(op, var1, var2, var3, var4, ...
    var5, var6, var7, var8, var9, var10) %#codegen
%OMP_clause_reduction  performs a reduction on the variables that appear in its list.
%   OMP_clause_reduction(op, var1, var2, ...)
%
% A private copy for each list variable is created for each thread. At the
% end of the reduction, the reduction variable is applied to all private
% copies of the shared variable, and the final result is written to the
% global shared variable. The variables in the list must be named scalar
% variables. They can not be array or structure type variables.
% The operations is one of +, *, -, /, &, ^, |, &&, ||.
%
% Example: OMP_clause_reduction('+', var1, var2)
%
% See also OMP_clause_shared, OMP_clause_private

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

switch nargin
    case 1
        coder.ceval(['#++ reduction' op ':']);
    case 2
        coder.ceval(['#++ reduction' op ':'], coder.rref(var1));
    case 3
        coder.ceval(['#++ reduction' op ':'], coder.rref(var1), coder.rref(var2));
    case 4
        coder.ceval(['#++ reduction' op ':'], coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3));
    case 5
        coder.ceval(['#++ reduction' op ':'], coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4));
    case 6
        coder.ceval(['#++ reduction' op ':'], coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5));
    case 7
        coder.ceval(['#++ reduction' op ':'], coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6));
    case 8
        coder.ceval(['#++ reduction' op ':'], coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7));
    case 9
        coder.ceval(['#++ reduction' op ':'], coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8));
    case 10
        coder.ceval(['#++ reduction' op ':'], coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8), coder.rref(var9));
    case 11
        coder.ceval(['#++ reduction' op ':'], coder.rref(var1), coder.rref(var2), ...
            coder.rref(var3), coder.rref(var4), coder.rref(var5), coder.rref(var6), ...
            coder.rref(var7), coder.rref(var8), coder.rref(var9), coder.rref(var10));
    otherwise
        m2cerror('OMP_clause_reduction:TooManyArguments', ...
            'There are too many input arguments.');
end
