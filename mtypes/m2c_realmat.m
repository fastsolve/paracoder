function type = m2c_realmat(maxrow, maxcol, varrow, varcol) %#codegen
% Specifies a real (double-precision) matrix.
%    m2c_realmat specifies a variable-size matrix.
%
%    m2c_realmat(m, n) specifies fixed-size m-by-n matrix when m and n 
%    are both constants. Use inf for either m or n to specify a
%    variable dimension without upper bound.
%
%    m2c_realmat(m, n, varrow, varcol) specifies variable-size m-by-n
%    with upper bound of sizes. Set varrow and varcol to false if
%    the row or column has varible sizes, respectively.
%
% See also m2c_realrow, m2c_realcol, m2c_introw, m2c_intcol, m2c_string

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
