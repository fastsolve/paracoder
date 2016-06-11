function sub = sub_colvec( A, start_index, end_index) %#codegen
%SUB_COLVEC   Obtain a sub-vector
%    sub = sub_colvec( A, start_index, end_index)
% The function is equivalent to the operation sub = A(start_index:end_index, :)
% in MATLAB, but it allows generating more more efficient.

coder.inline('always');

if end_index<start_index;
    sub = zeros(0,size(A,2),class(A));
elseif isempty( coder.target)
    sub = A(start_index:end_index, :);
else
    sub = coder.nullcopy(zeros(end_index-start_index+1,size(A,2),class(A)));

    for i=0:end_index-start_index
        sub(i+1,:) = A(start_index+i,:);
    end
end
