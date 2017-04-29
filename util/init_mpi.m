function init_mpi
% Initialize MPI

if exist(['mpi_Initialized.' mexext], 'file') && ...
        exist(['mpi_Init.' mexext], 'file') && ...
        exist(['mpi_Comm_set_errhandler.' mexext], 'file')
    try
        if ~mpi_Initialized
            mpi_Init;
        end
    catch
        error('mpi_Init failed.');
    end
    
    if ~isoctave || isguirunning
        % When running in MATLAB or in Octave with GUI, return on error
        mpi_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    else
        % When running in Octave without GUI, abort on error
        mpi_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_ARE_FATAL);
    end
    
    if isoctave
        atexit('uninit_mpi')
    end
else
    warning('MPI has not been built')
end
