function At = crs_transp(A)
%crs_transp Transpose a give matrix in CRS format.
%     At = crs_trans(A)
% It is equivalent to constructing a compressed-column format of the 
% matrix by treating row_ptr as col_ptr and treating col_ind as row_ind.

%#codegen -args {crs_matrix}

is = A.col_ind;
js = crs_rowind(A.row_ptr, A.col_ind);

% Exchange row and col_ind.
At = crs_createFromAIJ(is, js, A.val);

end

function test %#ok<DEFNU>
%!test
%! tic; sp = sprand(10000, 2000, 0.1);
%! fprintf(1, '\n\tGenerated random matrix in %g seconds\n', toc);
%! tic; A = crs_matrix(sp);
%! fprintf(1, '\tConverted into crs_matrix in %g seconds\n', toc);
%! tic; At = crs_transp(A);
%! fprintf(1, '\tComputed transpose in %g seconds\n', toc);
%! assert(isequal(sp', crs_2sparse(At)));
end