function c = cross_row(a, b) %#codegen
%CROSS_ROW Efficient computaiton of cross product between two 
% 3-dimensional row vectors.
% CROSS_ROW(A,B) Efficiently computes the cross product between
% 3-dimensional row vector A, and 3-dimensional row vector B.
% The result is a row vector.

c = [a(2)*b(3)-a(3)*b(2), a(3)*b(1)-a(1)*b(3), a(1)*b(2)-a(2)*b(1)];
