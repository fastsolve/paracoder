function inmpi = isinmpi
% Determine whether running within MPI

inmpi = ~isempty( getenv('MPICH_INTERFACE_HOSTNAME')) || ...
    ~isempty( getenv('OMPI_COMM_WORLD_SIZE'));
