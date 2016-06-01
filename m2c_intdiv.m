function quotient = m2c_intdiv(a, b) %#codegen

coder.inline('always');

if isempty(coder.target)
    quotient = int32(fix(double(a)/double(b)));
else
    if coder.target('rtw')
        coder.cinclude('m2c.h');
    end

    quotient = int32(0);
    quotient = coder.ceval('M2C_INTDIV', a, b);
end
