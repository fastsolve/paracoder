function expr = re_funccall(func)
% Locate a particular function call.

if nargin==1
    expr = ['\n\s+(?:(\w+|[\*\[\]\.]|->)+\s*=\s*)?' func '\s*\([^\};]+\)\s*;'];
else
    expr = '\n\s+(?:(\w+|[\*\[\]\.]|->)+\s*=\s*)?\w+\s*\([^\};]+\)\s*;';
end
