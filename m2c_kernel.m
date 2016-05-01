function m2c_kernel %#codegen
%M2C_KERNEL  Mark the function as a kernel function.
%       m2c_kernel
%
% A kernel function has all the following limitations:
%  - It cannot take arrays of struct or struct of arrays as input.
%  - It cannot have any dynamically allocated arrays.
%  - It must access arrays using 1-D indices without using size information
%       (except for the size information passed in as function arguments).
%  - It can pass arrays only to other kernel functions.
%  - It must be a local function and be declared with coder.inline('never').

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')

coder.ceval('#pragma kernel');
