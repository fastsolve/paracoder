function [stat, info] = probe(source, tag, comm ) %#codegen
%probe    Blocking test for a message
%
%  [stat, info] = probe (source, tag, comm)
%
%  source is source rank or MPI_ANY_SOURCE
%  tag is tag value or MPI_ANY_TAG (integer)
%  comm is an opaque MPI_Comm object
%
%  stat is an MPI_Status object
%  info (int) return code
%
%  SEE ALSO: iprobe, irecv, recv

[stat, info] = mpi_Probe(int32(source), int32(tag), MPI_Comm(comm));
