function type = m2c_doublemat(maxrow, maxcol, varrow, varcol) %#codegen
% Specifies a real (double-precision) matrix.
%    m2c_doublemat specifies a variable-size matrix.
%
%    m2c_doublemat(m, n) specifies fixed-size m-by-n matrix when m and n 
%    are both constants. Use inf for either m or n to specify a
%    variable dimension without upper bound.
%
%    m2c_doublemat(m, n, varrow, varcol) specifies variable-size m-by-n
%    with upper bound of sizes. Set varrow and varcol to false if
%    the row or column has varible sizes, respectively.
%
% See also m2c_doublevec, m2c_intmat, m2c_intvec, m2c_string

if nargin==0
    type = coder.typeof(0, [inf, inf]);
elseif nargin==1
    type = coder.typeof(0, [maxrow, inf]);
elseif nargin==2
    type = coder.typeof(0, [maxrow, maxcol]);
elseif nargin==3
    type = coder.typeof(0, [maxrow, maxcol], [varrow, maxcol==inf]);
else
    type = coder.typeof(0, [maxrow, maxcol], [varrow, varcol]);
end
