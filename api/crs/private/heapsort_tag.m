function [r,TAGS]=heapsort_tag(r,TAGS, n) %#codegen
% [r,TAGS]=heapsort_tag(r,TAGS);
% [r,TAGS]=heapsort_tag(r,TAGS, n);
%
%  HEAPSORT FROM ALGORITHM H IN KNUTH VOL. 3 PP 146-147
%
%  VARIABLE USAGE:
%  r -> INPUT/OUTPUT OF KEYS TO BE SORTED.
%  TAGS -> INPUT OUTPUT OF TAGS THAT WILL FOLLOW r IN SORT ORDER
%          if TAGS is omitted, TAGS will be set to TAGS=1:length(r)
%  n -> number of entries. If not present, then n=length(r).
%
% EXAMPLE:
%  r=[4,5,1,5,8,5,9,5];
%  t=1:8;
%  [r,t]=tagged_real_heapsort(r,t)
%  r =
%       1     4     5     5     5     5     8     9
%  t =
%       3     1     6     2     4     8     5     7

if nargin<3
    n=int32(length(r));
end

if n <= 1
    return;
end;
%
%STEP H1
%
l = int32(bitshift( uint32(n), -1)) +1;
ir = n;
%
%STEP H2
%
while(true);
    if l<=1
        r0 = r(ir);
        t0 = TAGS(ir);
        r(ir) = r(1);
        TAGS(ir) = TAGS(1);
        ir = ir - 1;
        if ir==1
            r(1) = r0;
            TAGS(1) = t0;
            return;
        end;
    else
        l = l - 1;
        r0 = r(l);
        t0 = TAGS(l);
    end;
    %
    %STEP H3
    %
    j = l;
    %
    %STEP H4
    %
    while(true);
        i = j;
        j = j*2;
        gt=false;
        if j >= ir
            if j==ir
                gt=true;
            else
                if j>ir
                    break;
                end;
            end;
        end;
        %
        %STEP H5
        %
        if ~gt
            if r(j)<r(j+1)
                j = j+1;
            end;
        end;
        %
        %STEP H6
        %
        if r0>=r(j)
            break;
        end;
        %
        %STEP H7
        %
        r(i) = r(j);
        TAGS(i) = TAGS(j);
    end;
    %
    %STEP H8
    %
    r(i) = r0;
    TAGS(i) = t0;
end
