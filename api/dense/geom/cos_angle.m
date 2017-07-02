function ca = cos_angle(v1, v2) %#codegen 
%COS_ANGLE Compute the cosine of two column vectors.
% COS_ANGLE(V1,V2) returns the cosine of the angle between column vector
% V1, and column vector V2.

ca = v1'*v2/sqrt((v1'*v1)*(v2'*v2)+1.e-100);
if ca>1; ca=1; elseif ca<-1; ca=-1; end
