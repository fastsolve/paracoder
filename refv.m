function [var1, var2, var3, var4, var5, var6, var7, var8, var9, var10] = ...
    refv( var1, var2, var3, var4, ...
    var5, var6, var7, var8, var9, var10) %#codegen
%refv  Access the variable to avoid aliasing in code generation.
%   [var1, var2, ...] = refv( var1, var2, ...)
%
% It is important that all the input variables are listed as output variables.
%
% Example: [var1, var2] = refv( var1, var2)

coder.inline('always');

if nargin~=nargout
    error('All the input variables must also be output variables.');
end

if ~strcmp(coder.target,'rtw')
    if nargin>=1 && ~isempty(var1); t = var1(1); var1(1) = t; end
    if nargin>=2 && ~isempty(var2); t = var2(1); var2(1) = t; end
    if nargin>=3 && ~isempty(var3); t = var3(1); var3(1) = t; end
    if nargin>=4 && ~isempty(var4); t = var4(1); var4(1) = t; end
    if nargin>=5 && ~isempty(var5); t = var5(1); var5(1) = t; end
    if nargin>=6 && ~isempty(var6); t = var6(1); var6(1) = t; end
    if nargin>=7 && ~isempty(var7); t = var7(1); var7(1) = t; end
    if nargin>=8 && ~isempty(var8); t = var8(1); var8(1) = t; end
    if nargin>=9 && ~isempty(var9); t = var9(1); var9(1) = t; end
    if nargin>=10 && ~isempty(var10); t = var10(1); var10(1) = t; end
else
    if nargin>=1; coder.ceval( '#ref', coder.ref(var1)); end
    if nargin>=2; coder.ceval( '#ref', coder.ref(var2)); end
    if nargin>=3; coder.ceval( '#ref', coder.ref(var3)); end
    if nargin>=4; coder.ceval( '#ref', coder.ref(var4)); end
    if nargin>=5; coder.ceval( '#ref', coder.ref(var5)); end
    if nargin>=6; coder.ceval( '#ref', coder.ref(var6)); end
    if nargin>=7; coder.ceval( '#ref', coder.ref(var7)); end
    if nargin>=8; coder.ceval( '#ref', coder.ref(var8)); end
    if nargin>=9; coder.ceval( '#ref', coder.ref(var9)); end
    if nargin>=10; coder.ceval( '#ref', coder.ref(var10)); end
end
