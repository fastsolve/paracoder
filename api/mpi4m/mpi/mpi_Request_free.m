function [req, info, toplevel] = mpi_Request_free(req)
%mpi_Request_free    Frees a user-defined combination function handle
%
%  [req, info] = mpi_Request_free(req)
%
% Input argument:
%  req 	    communication request (MPI_Request). 
%
% Output argument:
%  req 	    communication request (MPI_Request). 
%  info     return code (int32)
%
%  SEE ALSO: mpi_Request_create
%
% C interface:
%   int MPI_Request_free(MPI_Request *req)
% http://mpi.deino.net/mpi_functions/MPI_Request_free.html

%#codegen -args {MPI_Request}


info = int32(0); %#ok<NASGU>
t_req = MPI_Request(req);
info = coder.ceval('MPI_Request_free', coder.ref(t_req));

toplevel = nargout>2;
req = MPI_Request(t_req, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Request_free failed with error message %s\n', mpi_Error_string(info))
end
