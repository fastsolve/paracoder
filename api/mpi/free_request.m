function [req, info] = free_request(req) %#codegen
%FREE_REQUEST Frees a communication request object
%   [req, info] = free_request(req)
%
%See also irecv, isend

coder.inline('always');

[req, info] = mpi_Request_free(req);
