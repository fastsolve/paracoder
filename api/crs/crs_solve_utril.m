function b = crs_solve_utril(L, b, varargin)
% crs_solve_utril Solves L\b, where L is unit lower triangular
%     b = crs_solve_utril(L, b) solves L\b, where L stores the strict 
%     lower triangular part of L. The right-hand side vector will be 
%     overwritten by L\b at output.
%
%     b = crs_solve_utril(L, b, offset) uses b(offset+1:offset+n) 
%     instead of b for the rhs and solution vector, where n=size(L,1).
%
% See also crs_solve_tril, crs_solve_trilt

%#codegen -args {crs_matrix, coder.typeof(0, [inf,1])}
%#codegen crs_solve_utril_3args -args {crs_matrix, m2c_vec, int32(0)}

coder.inline('always');

if nargin < 3
    offset = int32(0);
else
    offset = int32(varargin{1});
end
n = int32(length(L.row_ptr) - 1);

for i = 1:n
    for k = L.row_ptr(i):L.row_ptr(i+1) - 1
        b(i+offset) = b(i+offset) - L.val(k) * b(L.col_ind(k)+offset);
    end
end

function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     L = tril(rand(10,10), -1); b = rand(10,1);
%!     if condest(L) < 1.e5
%!         L = crs_createFromSparse(sparse(L));
%!         us = crs_solve_utril(L, b);
%!         assert(norm((L+speye(10)) * us - b) <= 1.e-10);
%!     end
%! end
