function m2c_sync(buf1, buf2, buf3, buf4, buf5, buf6, buf7, buf8, buf9, buf10)
%Makes sure a buffer allocation has completed.
%
%   m2c_sync(buf1, buf2, ...)

coder.inline('always');

if strcmp(coder.target,'rtw')
    if nargin>=1; coder.ceval('#ref', coder.rref(buf1)); end
    if nargin>=2; coder.ceval('#ref', coder.rref(buf2)); end
    if nargin>=3; coder.ceval('#ref', coder.rref(buf3)); end
    if nargin>=4; coder.ceval('#ref', coder.rref(buf4)); end
    if nargin>=5; coder.ceval('#ref', coder.rref(buf5)); end
    if nargin>=6; coder.ceval('#ref', coder.rref(buf6)); end
    if nargin>=7; coder.ceval('#ref', coder.rref(buf7)); end
    if nargin>=8; coder.ceval('#ref', coder.rref(buf8)); end
    if nargin>=9; coder.ceval('#ref', coder.rref(buf9)); end
    if nargin>=10; coder.ceval('#ref', coder.rref(buf10)); end
end
