function sub = sub_matrix( A, start_row, end_row, start_col, end_col) %#codegen
%SUB_MATRIX   Obtain a sub-matrix
%    sub = sub_matrix( A, start_row, end_row, start_col, end_col)
% The function is equivalent to the operation 
% sub = A(start_row:end_row, start_col:end_col) in MATLAB, but it allows 
% generating more more efficient.

coder.inline('always');

if isempty(coder.target)
    sub = A(start_row:end_row, start_col:end_col);
else
    sub = nullcopy(zeros(end_row-start_row+1,end_col-start_col+1,class(A)));
    
    for j=0:end_col-start_col
        for i=0:end_row-start_row
            sub(i+1,j+1) = A(start_row+i,start_col+j);
        end
    end
end
