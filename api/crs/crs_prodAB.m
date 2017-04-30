function C = crs_prodAB(A, B)
% crs_prodAB Matrix-matrix multiplication C=A*B in compressed row format.
%     C = crs_prodAB(A, B)

% Note: Algorithm is based on SMMP (http://www.netlib.org/aicm/smmp).

%#codegen -args {crs_matrix, crs_matrix}

%The whole process contains three steps
%1. Determine C.row_ptr
%2. Fill in C.col_ind
%3. Fill in C.val

if A.ncols~=B.nrows
    m2c_error('crs_prodMatMat:WrongSizes', 'Number of columns of A must be equal to number of rows in B.');
end

% initialization of row vector. It has the size of A.row_ptr.
C = crs_matrix(A.nrows, B.ncols);
C.row_ptr = coder.nullcopy(zeros(length(A.row_ptr),1,'int32'));
C.row_ptr(1)=1;

index=zeros(max(A.ncols,B.ncols),1,'int32');

%Step one: Determine C.row_ptr
for i=1:A.nrows
    istart=int32(-1);
    clength=int32(0);
    for jj=A.row_ptr(i):A.row_ptr(i+1)-1
        j=A.col_ind(jj);
        for k=B.row_ptr(j):B.row_ptr(j+1)-1
            if index(B.col_ind(k))==0
                index(B.col_ind(k))=istart;
                istart=B.col_ind(k);
                clength=clength+1;
            end
        end
    end
    C.row_ptr(i+1)=C.row_ptr(i)+clength;
    for j=C.row_ptr(i):C.row_ptr(i+1)-1
        k=istart;
        istart=index(istart);
        index(k)=0;
    end
    index(i)=0;
end

%step two: Fill in C.col_ind
C.col_ind = coder.nullcopy(zeros(C.row_ptr(A.nrows+1)-1,1,'int32'));

for i=1:A.nrows
    istart=int32(-1);
    clength=int32(0);
    for jj=A.row_ptr(i):A.row_ptr(i+1)-1
        j=A.col_ind(jj);
        for k=B.row_ptr(j):B.row_ptr(j+1)-1
            if index(B.col_ind(k))==0
                index(B.col_ind(k))=istart;
                istart=B.col_ind(k);
                clength=clength+1;
            end
        end
    end
    C.row_ptr(i+1)=C.row_ptr(i)+clength;
    for j=C.row_ptr(i):C.row_ptr(i+1)-1
        C.col_ind(j)=istart;
        istart=index(istart);
        index(C.col_ind(j))=0;
    end
    index(i)=0;
end

%The final step: Fill in values of C.val
C.val = coder.nullcopy(zeros(C.row_ptr(A.nrows+1)-1,1, class(A.val)));
temp  = zeros(length(index),1,class(A.val));

for i=1:A.nrows
    for jj=A.row_ptr(i):A.row_ptr(i+1)-1
        j=A.col_ind(jj);
        ajj=A.val(jj);
        for k=B.row_ptr(j):B.row_ptr(j+1)-1
            temp(B.col_ind(k))=temp(B.col_ind(k))+ajj*B.val(k);
        end
    end
    for j=C.row_ptr(i):C.row_ptr(i+1)-1
        C.val(j)=temp(C.col_ind(j));
        temp(C.col_ind(j))=0;
    end
end

function test  %#ok<DEFNU>
%!test
%! for k=1:100
%!     spA = sprand(20,10,0.1);
%!     spB = sprand(10,30,0.1);
%!     spC = spA*spB;
%!     A = crs_matrix(spA);
%!     B = crs_matrix(spB);
%!     C = crs_prodAB(A, B);
%!     assert(norm(spC-crs_2sparse(C), 'fro')<1.e-12);
%! end
