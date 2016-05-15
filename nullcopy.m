function B = nullcopy(A) %#codegen
coder.inline('always')

if isempty(coder.target)
    if isfloat(A)
        B = nan(size(A), class(A));
    elseif isinteger(A)
        B = repmat(intmax(class(A)), size(A));
    elseif islogical(A)
        B = true(size(A));
    end
else
    B = coder.nullcopy(A);
end
