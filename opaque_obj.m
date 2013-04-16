%OPAQUE_OBJ Create an opaque object
%   obj = opaque_obj( type, data, [nitems])
%
% The function creates a struct with the following fields:
%     data: a row array of uint8 if it is a constant, or
%           a column array of uint8 if it is a variable.
%     type: a character string
%     nitems: number of items of the objects (default is 1)
%
% At input, type is a character string.
% If data is also a character string (which must be the case if the
% function is called outside codegen), then the string corresponds to
% a constant. If data is not a character string, then the function
% must be called within codegen, and data is an opaque object.
%
% Note: When the function is called without any argument, it will return
% a type declaration, which can be used in the argument list for codegen.
% If it is called with one argument, it will return a type declaration
% with optimal arguments.
