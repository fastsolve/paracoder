function build_mmpi_essential(varargin)

% Change to MMPI's root directory to build.
mmpiroot = fileparts(which('startup_mmpi'));
curpath = pwd;
cd(mmpiroot);

try
    %Compile mpi functions into their own directory
    files = {'mpi_Init', 'mpi_Finalize', 'mpi_Initialized', 'mpi_Finalized', ...
        'mpi_Abort', 'mpi_Barrier', 'mpi_Error_string', ...
        'mpi_Comm_rank', 'mpi_Comm_size', 'mpi_Wtick', 'mpi_Wtime'};
    opts = {'-mpi', '-O', '-mex'};
    
    for i=1:length(files)
        m2c(opts{:}, files{i});
    end
catch ME
    cd(curpath);
    rethrow(ME);
end

cd(curpath);
