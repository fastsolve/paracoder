function sub = sub_rowvec( A, start_index, end_index) %#codegen
%SUB_ROWVEC   Obtain a sub-row-vector
%    sub = sub_rowvec( A, start_col, end_col)
% The function is equivalent to the operation sub = A(:, start_col:end_col) 
% in MATLAB, but it allows generating more more efficient.

coder.inline('always');

assert(size(A,1)==1);
if end_index<start_index;
    sub = zeros(size(A,1),0,class(A));
elseif isempty( coder.target)
    sub = A(:, start_index:end_index);
else
    sub = coder.nullcopy(zeros(size(A,1),end_index-start_index+1, class(A)));

    for i=0:end_index-start_index
        sub(:,i+1) = A(:,start_index+i);
    end
end
