function x = m2c_atomic_add(x, val)

coder.inline('always');
x = x + val;