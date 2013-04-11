function M2C_begin_region( comment) %#codegen
%M2C_begin_region Equivalent to "{" in C.
%   M2C_begin_region
%   M2C_begin_region( comment)

coder.inline('always');
if nargin==0
    coder.ceval( 'M2C_BEGIN_REGION');
else
    if length(comment)>2 && isequal( comment(end-1:end), '*/')
        comment = comment(1:end-2);
    end
    coder.ceval( 'M2C_BEGIN_REGION', coder.opaque('const char *', ['/* ' comment ' */']));
end
M2C_use_region
