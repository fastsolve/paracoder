function trg = m2c_par_target(mode)
% Returns parallel compilation target

if (nargin==0)
    trg = 'cuda';
else
    trg = isequal(mode, 'cuda') || isequal(mode, 'gpu');
end

