function OMP_end_parallel(var1, var2, var3, var4, ...
    var5, var6, var7, var8, var9, var10) %#codegen
%OMP_end_parallel Marks the end of the OpenMP parallel section.
%
%     OMP_end_parallel(var1, var2, ...)
% The list of variables declare them not to be deallocated/reused within the
% region. This is particularly important for arrays local to the caller.
% This function takes up to 10 variables. If you have more than 10 variables,
% you can use refv to declare additional variables after this function.
%
% See also OMP_begin_parallel, refv

coder.inline('always');
coder.allowpcode('plain')

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('#}parallel');

if nargin>=1; coder.ceval('#ref', coder.rref(var1)); end
if nargin>=2; coder.ceval('#ref', coder.rref(var2)); end
if nargin>=3; coder.ceval('#ref', coder.rref(var3)); end
if nargin>=4; coder.ceval('#ref', coder.rref(var4)); end
if nargin>=5; coder.ceval('#ref', coder.rref(var5)); end
if nargin>=6; coder.ceval('#ref', coder.rref(var6)); end
if nargin>=7; coder.ceval('#ref', coder.rref(var7)); end
if nargin>=8; coder.ceval('#ref', coder.rref(var8)); end
if nargin>=9; coder.ceval('#ref', coder.rref(var9)); end
if nargin>=10; coder.ceval('#ref', coder.rref(var10)); end
