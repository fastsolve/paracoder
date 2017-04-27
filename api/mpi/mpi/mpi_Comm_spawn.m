function [intercomm, errcodes, info, toplevel] = mpi_Comm_spawn(command, argv, ...
    maxprocs, mpiinfo, root, comm)
%mpi_Comm_spawn Spawn up to maxprocs instances of a single MPI application
%
%  [intercomm, errcodes, info] = mpi_Comm_spawn(commmand, argv, ...
%              maxprocs, info, root, coom)
%
% Input arguments
%  command    name of program to be spawned (string, significant only at root)
%  argv       arguments to command (opaque pointer to char **, significant only at root)
%  maxprocs   maximum number of processes to start (integer, significant only at root)
%  mpiinfo    a set of key-value pairs telling the runtime system where and
%             how to start the processes (handle, significant only at root)
%  root       rank of process in which previous arguments are examined (integer)
%  comm       intracommunicator containing group of spawning processes (opaque MPI_Comm object)
%
% Output arguments
%  intercomm   intercommunicator between original group and the
%              newly spawned group (opaque MPI_Comm object)
%  errcodes    one code per process (array of integer)
%  info        return code (int)
%
% C interface:
% int MPI_Comm_spawn(char *command, char *argv[], int maxprocs, MPI_Info info,
%    int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[]);
% http://mpi.deino.net/mpi_functions/MPI_Comm_spawn.html

%#codegen -args {coder.typeof('i', [1,inf]), m2c_opaque_type,
%#codegen int32(0), MPI_Info, int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>
errcodes = coder.nullcopy(zeros(maxprocs, 1, 'int32'));

intercomm0 = coder.opaque('MPI_Comm');

if isstruct(argv)
    if ~isequal(argv.type, 'char **')
        m2c_error('mpi_Comm_spawn:WrongType', ...
            'Incorrect data type %s. Expected char **.', [argv.type char(0)]);
    end
    args = m2c_castdata('char **', argv.data);
else
    args = argv;
end

info = coder.ceval('MPI_Comm_spawn', [command char(0)], args, ...
    int32(maxprocs), MPI_Info(mpiinfo), int32(root), MPI_Comm(comm), ...
    coder.wref(intercomm0), coder.ref(errcodes));

toplevel = nargout>3;
intercomm = MPI_Comm(intercomm0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_spawn failed with error message %s\n', mpi_Error_string(info))
end
