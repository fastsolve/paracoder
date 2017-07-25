function b = ccs_solve_utril(L, b, varargin)
% ccs_solve_utril Solves L\b, where L is unit lower triangular
%     b = ccs_solve_utril(L, b) solves L\b, where L stores the strict
%     lower triangular part of L. The right-hand side vector will be
%     overwritten by L\b at output.
%
%     b = ccs_solve_utril(L, b, offset) uses b(offset+1:offset+n)
%     instead of b for the rhs and solution vector, where n=size(L,1).
%
% See also ccs_solve_tril, ccs_solve_triut

%#codegen -args {ccs_matrix, coder.typeof(0, [inf, 1])}
%#codegen ccs_solve_utril_3args -args {ccs_matrix, m2c_vec, int32(0)}

coder.inline('always');

if nargin < 3
    offset = int32(0);
else
    offset = int32(varargin{1});
end
n = int32(length(L.col_ptr) - 1);

for j = 1:n
    for k = L.col_ptr(j):(L.col_ptr(j+1) - 1)
        i = L.row_ind(k);
        % This can be done concurrently
        b(i+offset) = b(i+offset) - L.val(k) * b(j+offset);
    end
end

function test %#ok<DEFNU>
%!test
%! for k=1:100
%!     T = tril(rand(10,10), -1); b = rand(10, 1);
%!     L = ccs_createFromSparse(sparse(T));
%!     us = ccs_solve_utril(L, b);
%!     assert(norm((T + speye(10)) * us - b) <= 1.e-10);
%! end
