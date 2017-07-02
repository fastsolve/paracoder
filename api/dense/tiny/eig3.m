function [Q, lambdas] = eig3(A)  %#codegen
%EIG3 Computes eigenvalues and eigenvectors of 3x3 symmetric matrix.
% [Q,LAMBDAS] = EIG3(A) Computes the 3x3 eigenvector matrix Q, and the 3x3 
% diagonal eigenvalue matrix LAMBDAS, provided any 3x3 symmetric matrix A. 
% It has same I/O convention as EIG.
%
% See also EIG, EIG2, EIG3_SORTED

% Calculates the eigenvalues and normalized eigenvectors of a symmetric 3x3
% matrix A using the QL algorithm with implicit shifts, preceded by a
% Householder reduction to tridiagonal form.
% The function accesses only the diagonal and upper triangular parts of A.
% The access is read-only.
% ----------------------------------------------------------------------------
% Parameters:
%   A: The symmetric input matrix
%   Q: Storage buffer for eigenvectors
%   lambdas: Storage buffer for eigenvalues

% ----------------------------------------------------------------------------
% Note: Modified from implementation of Joachim Kopp (www.mpi-hd.mpg.de/~jkopp/3x3/)
% -------------------------------------------------------------------------

% Transform A to real tridiagonal form by the Householder method
assert(isa(A,'double'));

[Q,w,e1] = dsytrd3(A);
e = [e1(1); e1(2); 0];

% Calculate eigensystem of the remaining real symmetric tridiagonal matrix
% with the QL method
%
% Loop over all off-diagonal elements
for k=int32(1):2
    nIter = int32(0);
    while true
        % Check for convergence and exit iteration loop if off-diagonal
        % element e(k) is zero
        g = abs(w(k))+abs(w(k+1));
        if (abs(e(k)) + g == g); break; end

        if k==1
            g = abs(w(2))+abs(w(3));
            m = int32(3 - (abs(e(2)) + g == g));
        else
            m = int32(3);
        end

        nIter = nIter + 1; if (nIter >= 30); break; end

        % Calculate g = d_m - k
        g = (w(k+1) - w(k)) / (e(k) + e(k));
        r = sqrt(g*g + 1.0);
        if (g > 0)
            g = w(m) - w(k) + e(k)/(g + r);
        else
            g = w(m) - w(k) + e(k)/(g - r);
        end

        s = cast(1.0, class(A)); c = cast(1.0, class(A));
        p = cast(0.0, class(A));
        for i=m-1:-1:k
            f = s * e(i);
            b = c * e(i);
            if (abs(f) > abs(g))
                c      = g / f;
                r      = sqrt(c*c + 1.0);
                e(i+1) = f * r;
                s      = 1.0/r;
                c      = c * s;
            else
                s      = f / g;
                r      = sqrt(s*s + 1.0);
                e(i+1) = g * r;
                c      = 1.0/r;
                s      = s * c;
            end

            g = w(i+1) - p;
            r = (w(i) - g)*s + 2.0*c*b;
            p = s * r;
            w(i+1) = g + p;
            g = c*r - b;

            % Form eigenvectors
            for j=int32(1):3
                t = Q(j,i+1);
                Q(j,i+1) = s*Q(j,i) + c*t;
                Q(j,i)   = c*Q(j,i) - s*t;
            end
        end
        w(k)  = w(k) - p;
        e(k)  = g;
        e(m)  = 0.0;
    end
end

% If only one output, then set first output argument to eigenvalues.
% Otherwise, set second output argument to eigenvalues.
if nargout<=1
    Q = w;
else
    lambdas = [w(1), 0 0 ; 0 w(2) 0; 0 0 w(3)];
end

function [Q,d,e] = dsytrd3(A)
% ----------------------------------------------------------------------------
% Reduces a symmetric 3x3 matrix to tridiagonal form by applying
% (unitary) Householder transformations:
%            [ d[0]  e[0]       ]
%    A = Q . [ e[0]  d[1]  e[1] ] . Q^T
%            [       e[1]  d[2] ]
% The function accesses only the diagonal and upper triangular
% parts of A. The access is read-only.

% Bring first row and column to the desired form
h = A(1,2:3)*A(1,2:3)';

if A(1,2) > 0
    g = -sqrt(h);
else
    g = sqrt(h);
end

e = [g; A(2,3)];
f = g * A(1,2);
u2 = A(1,2) - g; u3 = A(1,3);

omega = h - f;
if omega > 0.0
    omega = 1.0 / omega;

    f    = A(2,2) * u2 + A(2,3) * u3;
    q2 = omega * f;                  % p
    K    = u2 * f;                   % u* A u

    f    = A(2,3) * u2 + A(3,3) * u3;
    q3 = omega * f;                  % p
    K   = K + u3 * f;                % u* A u

    K   = 0.5 * K * omega * omega;

    q2 = q2 - K * u2;
    q3 = q3 - K * u3;
    d = [A(1,1); A(2,2)-2.0*q2*u2; A(3,3)-2.0*q3*u3];

    % Store inverse Householder transformation in Q
    Q = [1, 0, 0;
        0, 1 - omega * u2 *u2, - omega * u2 *u3;
        0, 0, 1 - omega * u3 *u3];
    Q(3,2) = Q(2,3);

    % Calculate updated A(2,3) and store it in e(2)
    e(2) = e(2) - q2*u3 - u2*q3;
else
    Q = eye(3,class(A));
    d = [A(1,1); A(2,2); A(3,3)];
end

