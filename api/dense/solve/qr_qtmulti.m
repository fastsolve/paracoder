function bs = qr_qtmulti(A, bs, ncols, V)
% Compute a = Q'*b, where A is stored implicitly in the strictly lower
% triangular part of A as Householder reflector vectors. The first entries
% of the Householder reflectors are not stored in A, as these entries can
% be recovered as sqrt(1-v(2:end)'*v(2:end)). Alternatively, they may be
% passed in array V.
%
% See also qr_qmulti, qrcp, qrcp_forwardsolve_trans

%#codegen -args {coder.typeof(0,[inf,inf]), coder.typeof(0,[inf,inf]),
%#codegen int32(0), coder.typeof(0,[inf,1])}

nrows = int32(size(A, 1));
if nargin < 3; ncols = int32(size(A, 2)); end

if int32(size(bs, 1)) < nrows
    bs = [bs; zeros(nrows-size(bs, 1), size(bs, 2))];
end

for k = 1:ncols
    % bs(k:nrows,:) = bs(k:nrows,:) - 2*v*(v'*bs(k:nrows,:)),
    % where v is [V(k); A(k+1:npngs,k)]
    if nargin > 3
        v1 = V(k);
    else
        % Compute sqrt(1-v(2:end)'*v(2:end));
        v1 = 1;
        for ii = k + 1:nrows
            v1 = v1 - A(ii, k) * A(ii, k);
        end
        if v1 < 0
            v1 = 0;
        else
            v1 = sqrt(v1);
        end
    end

    for jj = 1:int32(size(bs, 2))
        t2 = v1 * bs(k, jj);
        for ii = k + 1:nrows
            t2 = t2 + A(ii, k) * bs(ii, jj);
        end

        t2 = t2 + t2;
        bs(k, jj) = bs(k, jj) - t2 * v1;
        for ii = k + 1:nrows
            bs(ii, jj) = bs(ii, jj) - t2 * A(ii, k);
        end
    end
end

if size(bs, 1) > size(A, 1)
    bs = bs(1:size(A, 1), :);
end

function test %#ok<DEFNU>
%!test
%! for i=1:1000
%!   m = 20; n = 10;
%!   A = rand(m,n); bs = rand(m,2);
%!   xs1 = A\bs;
%!   [A, rnk] = qr_rescale(A);
%!   bs = qr_qtmulti(A, bs, n);
%!   xs2 = backsolve(A, bs(1:n,:));
%!   assert(norm(xs1-xs2)<=1.e-10);
%! end
