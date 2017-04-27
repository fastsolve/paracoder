function load_momp

if isempty(getenv('OMP_NUM_THREADS'))
    if ismac
        [~, nprocs] = system('sysctl -n hw.ncpu');
    elseif isunix
        [~, nprocs] = system('nproc');
    end
    
    nprocs = strtrim(nprocs);
    setenv('OMP_NUM_THREADS', nprocs);
    fprintf(1, ['Set OMP_NUM_THREADS to ' nprocs '.\n']);
end
