function obj = opaque_obj( type, data, nitems) %#codegen
%OPAQUE_OBJ Create an opaque object
%   obj = opaque_obj( type, data, [nitems])
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
coder.allowpcode('plain');

if nargin==0
    obj = opaque_obj_type; return;
end

if nargin<3; nitems=int32(1); end

coder.varsize( 'obj.data', [inf,1]);
coder.varsize( 'obj.type', [1,inf]);
coder.varsize( 'obj.nitems', [1,1]);

if isempty(coder.target)
    assert(isa(data, 'uint8') && size(data,2)==1);
    obj = struct( 'data', data, 'type', char(type(:)'), ...
        'nitems', int32(nitems));
else
    sizepe = int32(0);
    sizepe = coder.ceval('sizeof', coder.opaque('ctype',type));
    
    % Allocate data
    obj = struct('data', nullcopy(zeros( sizepe*nitems, 1, 'uint8')), ...
        'type', char(type(:)'), 'nitems', int32(nitems));
    if ~isempty(data)
        ptr = coder.opaque('char *', 'NULL');
        ptr = coder.ceval('(char *)', coder.rref(data));
        for i=int32(0):sizepe*nitems-1
            obj.data(i+1) = coder.ceval( '*', ptr);
            ptr = M2C_offset_ptr( ptr, int32(1));
        end
    end
end
