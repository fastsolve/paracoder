function obj = m2c_opaque_obj(type, data, nitems) %#codegen
%M2C_OPAQUE_OBJ Create an opaque object
%   obj = m2c_opaque_obj(type, data, [nitems])
%
% The function creates a struct with the following fields:
%     type: a character string
%     data: a column array of uint8.
%     nitems: number of items of the objects (default is 1)
%
% At input, type is a character string.
%
% Note: When the function is called without any argument, it will return
% a type declaration, which can be used in the argument list for codegen.
% If it is called with one argument, it will return a type declaration
% with optimal arguments.

coder.inline('always');

if nargin==0
    obj = m2c_opaque_type; return;
end

if nargin<3; nitems=int32(1); end

coder.varsize('obj.data', [inf,1]);
coder.varsize('obj.type', [1,inf]);
coder.varsize('obj.nitems', [1,1]);

if isempty(coder.target)
    data = typecast(data, 'uint8');
    if isrow(data); data = data'; end
    obj = struct('data', data, 'type', char(type(:)'), ...
        'nitems', int32(nitems));
else
    sizepe = int32(0);
    sizepe = coder.ceval('sizeof', coder.opaque('ctype',type));
    
    % Allocate data
    data0 = coder.nullcopy(zeros(sizepe*nitems, 1, 'uint8'));
    obj = struct('data', data0, 'type', char(type(:)'), 'nitems', int32(nitems));
    if ~isempty(data)
        ptr = coder.opaque('char *', 'NULL');
        ptr = coder.ceval('(char *)', coder.rref(data));
        for i=int32(1):sizepe*nitems
            obj.data(i) = coder.ceval('*', ptr);
            ptr = m2c_offset_ptr(ptr, int32(1));
        end
    end
end
end

