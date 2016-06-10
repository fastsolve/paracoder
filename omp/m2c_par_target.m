function trg = m2c_par_target(mode)
% Returns parallel compilation target

if (nargin==0)
    trg = 'omp';
else
    trg = isequal(mode, 'omp') || isequal(mode, 'openmp');
end
