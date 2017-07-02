function c = cross_col(a, b) %#codegen
%CROSS_COL Efficient routine for computing cross product of two 
%3-dimensional column vectors.
% CROSS_COL(A,B) Efficiently computes the cross product between
% 3-dimensional column vector A, and 3-dimensional column vector B.

c = [a(2)*b(3)-a(3)*b(2); a(3)*b(1)-a(1)*b(3); a(1)*b(2)-a(2)*b(1)];
