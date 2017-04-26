function x = m2c_atomic_or(x, val)

coder.inline('always');
x = bitor(x, val);
