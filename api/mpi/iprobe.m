function [flag, stat, info] = iprobe(source, tag, comm ) %#codegen
%iprobe    Non-blocking test for a message
%
%  [flag, stat, info] = iprobe (source, tag, comm)
%
%  source is source rank or MPI_ANY_SOURCE
%  tag is tag value or MPI_ANY_TAG (integer)
%  comm is an opaque MPI_Comm object
%
% flag True if a message with the specified source, tag, and communicator is available (logical)
%  stat is an MPI_Status object
%  info (int) return code
%
%  SEE ALSO: probe, irecv, recv

[flag, stat, info] = mpi_Iprobe(int32(source), int32(tag), MPI_Comm(comm));
