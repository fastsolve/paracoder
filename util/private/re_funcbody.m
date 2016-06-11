function expr = re_funcbody
% This assumes that the function is properly indented.
expr = '{(?:[^}][^\n]*\n)*\n*}';
end
