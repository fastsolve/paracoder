function writeExeFile(funcname, cpath, m2c_opts)
% Write out _exe.c file

outCfile = [cpath funcname '_exe.' m2c_opts.suf];

str = sprintf('%s\n', ...
    '/*', ...
    [' * Auxiliary code for standalone executable of ' funcname], ' *', ...
    ' * C source code generated by m2c.', ' *', ' */', '');

if ~isempty(m2c_opts.petscInc)
    str = sprintf('%s\n', str, ...
        '#include "petscsys.h"', '');
elseif ~isempty(m2c_opts.mpiInc)
    str = sprintf('%s\n', str, ...
        '#include "mpi.h"', '');
end

str = sprintf('%s\n', str, ...
    '/* Include declaration of some helper functions. */', ...
    '#include "lib2exe_helper.c"', '', ...
    'int main(int argc, const char * const argv[]) {', ...
    '    int nlhs, nrhs, k;', ...
    '    mxArray **prhs = NULL;', ...
    '    mxArray **plhs = NULL;');

if ~isempty(m2c_opts.petscInc)
    str = sprintf('%s\n', str, ...
        '    PetscErrorCode ierr;', '', ...
        '    ierr = PetscInitializeNoArguments(); CHKERRQ(ierr);', '');
elseif ~isempty(m2c_opts.mpiInc)
    str = sprintf('%s\n', str, ...
        '    MPI_Init(NULL, NULL);', '');
end

str = sprintf('%s\n', str, ...
    '    if (argc<5) {', ...
    '        printf("Too few input arguments. Usage:\n\t %s <nrhs> <infile> <nlhs> <outfile>\n", argv[0]);', ...
    '        return(EXIT_FAILURE);', ...
    '    }', '', ...
    '    nrhs = atoi(argv[1]);', ...
    '    nlhs = atoi(argv[3]);', '', ...
    '    if (nrhs<0 || nlhs<0) {', ...
    '        printf("nrhs and nlhs must be nonnegative. Received %d and %d instead.\n", nrhs, nlhs);', ...
    '        return(EXIT_FAILURE);', ...
    '    }', '', ...
    '    if (nrhs) {', ...
    '        prhs = (mxArray **)calloc(nrhs, sizeof(mxArray*));', ...
    '    }', '', ...
    '    plhs = (mxArray **)calloc((nlhs?nlhs:1), sizeof(mxArray*));', ...
    '    if (nrhs && readInputArgs(argv[2], nrhs, prhs))', ...
    '       return(EXIT_FAILURE);', '', ...
    '    /* Call the MEX function. */', ...
    '    mexFunction(nlhs, plhs, nrhs, (const mxArray **)prhs);', '', ...
    '    if (writeOuputArgs(argv[4], nlhs, plhs))', ...
    '        return(EXIT_FAILURE);', '', ...
    '    for (k=0; k<nrhs; ++k) {', ...
    '        if (prhs[k])', ...
    '            mxDestroyArray(prhs[k]);', ...
    '    }', '', ...
    '    if (nrhs>1) free(prhs);', ...
    '    for (k=0; k<(nlhs?nlhs:1); ++k) {', ...
    '        if (plhs[k])', ...
    '            mxDestroyArray(plhs[k]);', ...
    '    }', ...
    '    free(plhs);');

if ~isempty(m2c_opts.petscInc)
    str = sprintf('%s\n', str, ...
        '    ierr = PetscFinalize(); CHKERRQ(ierr);', '');
elseif ~isempty(m2c_opts.mpiInc)
    str = sprintf('%s\n', str, ...
        '    MPI_Finalize();');
end

str = sprintf('%s\n', str, ...
    '    return(EXIT_SUCCESS);', ...
    '}');

writeFile(outCfile, str);

end
