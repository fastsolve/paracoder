function k = crs_find(row_ptr, col_ind, r, c) %#codegen
%CRS_FIND Find linear index of an entry in the CRS format of a sparse matrix.
%    k = crs_find(row_ptr, col_ind, r, c) 
% The entry A(r,c) is then A.val(k). If not found, then k==0.
% The cost of this function is linear in the number of entries in the row.

for i= row_ptr(r) : row_ptr(r+1)-1 
    if col_ind(i)==c
        k=i; return;
    end
end

k=int32(0);
