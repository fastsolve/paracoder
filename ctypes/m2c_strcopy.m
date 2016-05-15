function str_out = m2c_strcopy(str_in, opaque)
% Copy one string into another

coder.inline('always')

if ~opaque || ischar(str_in)
    str_out = str_in;
else
    str = coder.opaque('const char *'); %#ok<NASGU>
    str = coder.ceval(' ', str_in);
    
    empty = int32(0); %#ok<NASGU>
    empty = coder.ceval('!', str);
    
    if ~empty
        n = int32(0); %#ok<NASGU>
        n = coder.ceval('strlen', str);

        % We use uint8 here instead of a char array because MATLAB Coder
        % in R2016a does not allocate sizes correctly for constant characters.
        str1 = zeros(1, n+1, 'uint8');
        
        ptr = coder.opaque('char *'); %#ok<NASGU>
        ptr = coder.ceval('(char *)', str);
        for i=int32(1):n+1
            str1(i) = coder.ceval('*', ptr);
            ptr = m2c_offset_ptr(ptr, int32(1));
        end
    else
        str1 = zeros(1, 0, 'uint8');
    end
    
    str_out = char(str1);
end
