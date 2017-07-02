function s = solve_quadratic_eq(a, b, c) %#codegen
%SOLVE_QUADRATIC_EQ A numerically stable solver for quadratic equations.
% SOLVE_QUADRATIC_EQ(A, B, C) Solves for the roots of a quadratic 
% equation: Ax^2 + Bx + C = 0, where A, B, and C are the provided scalar 
% coefficients. The function outputs a 2x1 array of the function's roots. 
% If solution does not exist, the solution is set to a very large number, 
% (such as 1.e100).

max_abc = max(abs(a), max(abs(b),abs(c)));

if max_abc > 0 % Scale
    a = a / max_abc; b = b / max_abc; c = c / max_abc;
end

if (a == 0)
    if (b == 0)
        s = [1.e100; 1.e100];
    else
        s = [-c/b; 1.e100];
    end
else
    discr = b*b - 4*a*c;

    % Use 1.e-10 as tolerance against roundoff error
    if discr < -1.e-10         % No solution
        s = [1.e100; 1.e100];
    elseif abs(discr) < 1.e-10 % One solution
        s1 = -0.5*b / a;
        s = [s1; s1];
    else
        % Two solutions
        sqrt_d = sqrt(discr);

        if (b>0)
            temp = -b - sqrt_d;
            s = [2*c/temp; 0.5*temp/a];
        else
            temp = -b + sqrt_d;
            s = [0.5*temp/a; 2*c/temp];
        end
    end
end
