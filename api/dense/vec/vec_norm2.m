function s = vec_norm2(v, dim) %#codegen
%VEC_NORM2Computes the 2-norm of a vector.
% VEC_NORM2(V) Computes the 2-norm of a row or column vector V.
% VEC_NORM2(V,dim) If dim==1, computes the 2-norm of column vectors of V,
%       If dim==2, computes the 2-norm of row vectors of V.
%
% See also VEC_SQNORM2
%
% Note: This function uses rescaling to guard against overflow/underflow.
% It does not inline. Use sqrt(vec_sqnorm2(v)) to produce more efficient
% code that can be inlined but does not perform rescaling.

coder.inline('never');

assert(nargin==1 || dim==1 || dim==2);

if nargin==1
    w = cast(0, class(v));
    for ii=1:numel(v); w = max(w,abs(v(ii))); end

    s = cast(0, class(v));
    if w==0
        % W can be zero for max(0,nan,...). Adding all three entries
        % together will make sure NaN will be preserved.
        for ii=1:numel(v); s = s + v(ii); end
    else
        for ii=1:numel(v); s = s + (v(ii)/w)^2; end

        s = w*sqrt(s);
    end
elseif dim==1
    ncol = int32(size(v,2));
    s = zeros(1, ncol);
    for k=1:ncol
        w = cast(0, class(v));
        for ii=1:size(v,1); w = max(w,abs(v(ii,k))); end

        s(k) = cast(0, class(v));
        if w==0
            % W can be zero for max(0,nan,...). Adding all three entries
            % together will make sure NaN will be preserved.
            for ii=1:size(v,1); s = s + v(ii,k); end
        else
            for ii=1:size(v,1); s = s + (v(ii,k)/w)^2; end

            s = w*sqrt(s);
        end
    end
else
    nrow = int32(size(v,1));
    s = zeros(nrow, 1);
    for k=1:nrow
        w = cast(0, class(v));
        for ii=1:size(v,2); w = max(w,abs(v(k,ii))); end

        s(k) = cast(0, class(v));
        if w==0
            % W can be zero for max(0,nan,...). Adding all three entries
            % together will make sure NaN will be preserved.
            for ii=1:size(v,2); s = s + v(k,ii); end
        else
            for ii=1:size(v,2); s = s + (v(k,ii)/w)^2; end

            s = w*sqrt(s);
        end
    end
end

function test %#ok<DEFNU>
% Integrated unit test. Test by running test_mcode('vec_norm2').
% Put inside "if 0" to avoid Agility inserting this into C code.

%!test
%! assert(vec_norm2([0,0,0])==0);
%! assert(vec_norm2([0,0,0]')==0);
%!
%! assert(isnan(vec_norm2([0,NaN,0])));
%! assert(abs(vec_norm2([1,2,3])-sqrt(14)) < 1.e-14);

%! assert(isequal(vec_norm2(zeros(3,4),1),zeros(1,4)));
%! assert(isequal(vec_norm2(zeros(3,4),2),zeros(3,1)));
