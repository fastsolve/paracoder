function load_mmpi

% [~,ldflags]=mpiflags;
% if ~isempty(strfind(ldflags,'/usr/lib/openmpi/lib')) && isempty(getenv('LD_PRELOAD'))
%    warning('MMPI:OpenMPI', 'MMPI is not started, because you are using OpenMPI but did not set the environment variable LD_PRELOAD to /usr/lib/openmpi/lib/libmpi.so. Fix it by using command "export LD_PRELOAD=/usr/lib/openmpi/lib/libmpi.so" in bash or "setenv LD_PRELOAD /usr/lib/openmpi/lib/libmpi.so" in csh before starting MATLAB. ');
% end

try
    if exist(['mpi_Initialized.' mexext], 'file') && ...
            exist(['mpi_Init.' mexext], 'file') && ...
            exist(['mpi_Comm_set_errhandler.' mexext], 'file') && ...
            ~mpi_Initialized
        mpi_Init;
        
        if ~isempty(getenv('DISPLAY'))
            % When running without mpirun or in an interactive mode, return on errors.
            mpi_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
        else
            % When running with mpirun in batch mode, errors are fatal.
            mpi_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_ARE_FATAL);
        end
    end
catch
    warning('mpi_Init failed.');
end
