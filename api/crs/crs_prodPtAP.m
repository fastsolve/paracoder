function B = crs_prodPtAP(A, P)
% crs_prodPtAP Compute B=P'*A*P
%      B = crs_prodPtAP(A, P)
% A and P are stored in compressed row storage.

%#codegen -args {crs_matrix, crs_matrix}

% Computes B=P'*A*B;
C = crs_prodAB(A, P);
Pt = crs_transp(P);
B = crs_prodAB(Pt, C);
