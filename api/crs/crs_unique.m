function [row_ptr, col_ind, val] = crs_unique(row_ptr, col_ind, val)
% Make column indices unique within each row. Values with duplicae entries
%  are added together.

% %#codegen -args {coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1]),
% %#codegen coder.typeof(0, [inf,1]}

assert(nargin==nargout && nargin>=2);

if nargin==2
    col_ind = crs_sort(row_ptr, col_ind);
else
    [col_ind, val] = crs_sort(row_ptr, col_ind, val);
end

offset = int32(0);
start = int32(1);

for i=1:int32(length(row_ptr))-1
    if offset
        col_ind(start-offset) = col_ind(start);
        if nargin>2; val(start-offset) = val(start); end
    end
    for j=start+1 : row_ptr(i+1)-1
        if col_ind(j)==col_ind(j-1-offset)
            if nargin>2; val(j-1-offset) = val(j-1-offset) + val(j); end
            offset = offset+1;
        elseif offset
            col_ind(j-offset) = col_ind(j);
            if nargin>2; val(j-offset) = val(j); end
        end
    end
    
    start = row_ptr(i+1);
    row_ptr(i+1) = row_ptr(i+1) - offset;
end

if offset
    newlen = int32(length(col_ind))-offset;
    col_ind = sub_colvec(col_ind, 1, newlen);
    if nargin>2; val = sub_colvec(val, 1, newlen); end
end
