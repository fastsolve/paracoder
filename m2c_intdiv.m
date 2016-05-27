function quotient = m2c_intdiv(a, b) %#codegen

if isempty(coder.target)
    quotient = int32(fix(double(a)/double(b)));
else
    quotient = int32(0);
    quotient = coder.ceval('M2C_INTDIV', a, b);
end
