function [intercomm, info] = spawn(command, maxprocs) %#codegen
%spawn Spawn up to maxprocs instances of a single MPI application 
%      from root process of MPI_COMM_WORLD.
%
%  [intercomm, info] = spawn(commmand, maxprocs)
%
% Input arguments
%  command    name of program to be spawned (string, significant only at root)
%  maxprocs   maximum number of processes to start (integer, significant only at root)
%
% Output arguments
%  intercomm   intercommunicator between original group and the
%              newly spawned group (opaque MPI_Comm object)
%  info        return code (int)

[intercomm, ~, info] = mpi_Comm_spawn(command, MPI_ARGV_NULL, ...
    maxprocs, MPI_INFO_NULL, int32(0), MPI_COMM_WORLD);
