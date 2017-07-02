function x = solve_nx2(A, b) %#codegen 
% This function solves the system Au=b, where A is Nx2, b is NxM.
% X = SOLVE_NX2(A, B)
% It is solves using Gram-Schimdt QR factorization of A.

% Q is a Nx2 matrix and R is 2x2.
Q = zeros(size(A,1),2);
R = zeros(2,2);
R(1,1) = norm2_vec(A(:,1));
Q(:,1) = A(:,1)/R(1,1);
R(1,2) = Q(:,1)'*A(:,2);

Q(:,2) = A(:,2) - R(1,2)*Q(:,1);
R(2,2) = norm2_vec(Q(:,2));
Q(:,2) = Q(:,2)/R(2,2);

x = Q'*b;

x(2,:) = x(2,:)/R(2,2);
x(1,:) = (x(1,:) - R(1,2)*x(2,:))/R(1,1);
