function yes = ismpiroot
% Determine whether it is the root process

yes = ~isempty(getenv('MPICH_INTERFACE_HOSTNAME_R0')) || ...
    isequal(getenv('OMPI_COMM_WORLD_RANK'), '0');
