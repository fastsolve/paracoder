function s = vec_sqnorm2(a) %#codegen
%VEC_SQNORM2Computes square of the 2-norm of a vector.
% VEC_SQNORM2(V) returns square of the 2-norm of column vector V.
%
% See also VEC_NORM2
%
% Note: This function does not guard against overflow/underflow.

coder.inline('always');

s = 0;
for ii=1:int32(numel(a))
    s = s + conj(a(ii)) * a(ii);
end

%!test
%! x = rand(10, 1) + rand(10, 1)*1i;
%! assert(abs(vec_norm2(x) - norm(x, 2)) < 1.e-14);

%! x = rand(10, 1) + rand(10, 1)*1i;
%! assert(abs(vec_sqnorm2(x) - norm(x, 2)^2) < 1.e-14);
