function N = tensor_pavvt(N, a, v) %#codegen
%TENSOR_PAVVT Compute N = N + a*v*v'. 
% TENSOR_PAVVT(N,A,V) Computes N = N + a*v*v'. Updates only upper-
% triangular part.
v1 = a*v;
N = [N(1,1)+v1(1)*v(1), N(1,2)+v1(1)*v(2), N(1,3)+v1(1)*v(3); 
    0, N(2,2)+v1(2)*v(2), N(2,3)+v1(2)*v(3);
    0, 0, N(3,3)+v1(3)*v(3)];
