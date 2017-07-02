function x = solve_singular(A, b, rnk)
% Solve a singular system (or rank-deficient least squares problem) 
% using QR factorization with column pivoting.
%     x = solve_singular(A, b, rnk)
% A is m-by-n, and is potentially rank deficient.
% b is m-by-k, where k is th enumber of columns of the right-hand side.
% rnk specifies the rank of A (if specified). If not specified, 
%    then rnk is estimated based on diagonal entries of R in QR
%    factorization with column pivoting.
% Note: The funciton works best if the null space of A is 1.

[c,R,e] = qr(A,b,'vector');
x = zeros(size(A,2),size(b,2));

if nargin<3
    tol = 1.e-10;
    rnk = size(A,1);
    for k=size(A,1):-1:1
        if abs(R(k,k)) < abs(R(1,1))*tol
            rnk = rnk - 1;
        else
            break;
        end
    end
end

x(e(1:rnk),:)=R(1:rnk,1:rnk)\c(1:rnk,:);
