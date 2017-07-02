function [V,D] = eig2(A)  %#codegen
% EIG2 Computes eigenvalues and eigenvectors of 2x2 symmetric matrix.
% [V,D] = eig2(A) Computes the 2x2 eigenvector matrix V, and the 2x2 diagonal
% eigenvalue matrix D, provided any 2x2 symmetric matrix A.  It has same 
% I/O conventions as eig.
% 
% See also eig2_sorted, eig, eig3, eig3_sorted

tr = A(1,1)+A(2,2);
tmp = sqrt((A(1,1)-A(2,2))*(A(1,1)-A(2,2))+4*A(1,2)*A(1,2));
if (isempty(coder.target) && isa(A, 'sym')) || tr>0
    D = [0.5*(tr+tmp) 0; 0 0.5*(tr-tmp)];
else
    D = [0.5*(tr-tmp) 0; 0 0.5*(tr+tmp)];
end

if nargout==1
    V = [D(1,1); D(2,2)];
else
    if (~isempty(coder.target) || ~isa(A, 'sym')) && D(1,1)==D(2,2)
        V = cast([1 0; 0 1], class(A));
    else
        d1 = [A(1,1)-D(2,2); A(1,2)]; l1=sqrt(d1'*d1);
        d2 = [A(1,1)-D(1,1); A(1,2)]; l2=sqrt(d2'*d2);

        if (isempty(coder.target) && isa(A, 'sym')) || (l1>l2)
            d1 = d1/l1;
            d2 = [d1(2); -d1(1)];
        else
            d2 = d2/l2;
            d1 = [d2(2); -d2(1)];
        end

        V = [d1,d2];
    end
end
