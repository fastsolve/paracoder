function x = vec_dot(a, b) %#codegen
% Compute dot product of a(:)'*b(:)

x = cast(0, class(a));
for i = 1:numel(a)
    x = x + a(i)*b(i);
end
