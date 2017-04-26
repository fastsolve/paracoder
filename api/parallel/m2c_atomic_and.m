function x = m2c_atomic_and(x, val)

coder.inline('always');
x = bitand(x, val);