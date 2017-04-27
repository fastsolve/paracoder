function x = m2c_atomic_sub(x, val)

coder.inline('always');
x = x - val;