function [stat, req, info] = wait(req) %#codegen
%WAIT Waits for an MPI request to complete
%   [stat, req, info] = wait(req)
%
%See also irecv, isend, waitany, waitall

coder.inline('always');

[stat, req, info] = mpi_Wait(req);
