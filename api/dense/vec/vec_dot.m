function x = vec_dot(a, b) %#codegen
% Compute dot product of a(:)'*b(:)

x = cast(0, class(a));
for i = 1:int32(numel(a))
    x = x + conj(a(i)) * b(i);
end

%!test
%! x = rand(10, 1) + rand(10, 1)*1i;
%! y = rand(10, 1) + rand(10, 1)*1i;
%! assert(abs(dot(x, y) - vec_dot(x, y)) < 1.e-14);
