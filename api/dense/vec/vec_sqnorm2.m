function s = vec_sqnorm2(a) %#codegen
%VEC_SQNORM2Computes square of the 2-norm of a vector.
% VEC_SQNORM2(V) returns square of the 2-norm of column vector V.
%
% See also VEC_NORM2
%
% Note: This function does not guard against overflow/underflow.

coder.inline('always');

s = 0;
for ii=1:numel(a)
    s = s + a(ii)*a(ii);
end
