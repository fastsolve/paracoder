function [t1, t2, V, ls] = orth_dirs(v0, A) %#codegen
% Determine two vectors orthogonal to v0.
%
% [t1, t2] = orth_dirs(v0) computes two arbitrary unit vectors orthogonal to v0.
%
% [t1, t2] = orth_dirs(v0, A) computes two arbitrary unit vectors
%          orthogonal to v0 from most orthogonal components in A.
%
% [t1, t2, V, ls] = orth_dirs(v0, A) also returns the eigenvectors and
%          eigenvalues of TAT, where T=I-v0*v0'.

if nargin>1 && ~isempty(A) && any(A(:))
    assert(abs(norm2_vec(v0)-1)<1.e-12);
    
    A(2,1)=A(1,2); A(3,1)=A(1,3); A(3,2)=A(2,3);
    
    % Compute TAT, where T=I-v0*v0'.
    B = A-(A*v0)*v0';
    
    % A = B - v0*(v0'*B);
    v = v0'*B;
    A(1,1) = B(1,1)-v0(1)*v(1); A(1,2) = B(1,2)-v0(1)*v(2); A(1,3) = B(1,3)-v0(1)*v(3);
    A(2,2) = B(2,2)-v0(2)*v(2); A(2,3) = B(2,3)-v0(2)*v(3);
    A(3,3) = B(3,3)-v0(3)*v(3);
    
    [V, ls] = eig3_sorted(A);
else
    ls = zeros(3,1); V=zeros(3,3);
end

if ls(1)>0
    t1 = V(:,1);
    assert(abs(norm2_vec(t1)-1)<1.e-12 && abs(v0'*t1)<1.e-12);
else
    absv0 = abs(v0);
    if (absv0(1)>absv0(2) && absv0(1)>absv0(3));
        % t1 = [0; 1; 0]; t1 = t1 - t1' * v0 * v0;
        t1 = [-v0(2)*v0(1); 1-v0(2)*v0(2); v0(2)*v0(3)];
    else
        % t1 = [1; 0; 0]; t1 = t1 - t1' * v0 * v0;
        t1 = [1-v0(1)*v0(1); -v0(1)*v0(2); v0(1)*v0(3)];
    end
    t1 = t1 / sqrt(t1'*t1);
end

if nargout>1
    t2 = cross_col(v0, t1);
end
