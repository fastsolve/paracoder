function Pi(N, mod, varargin)
% Classic PI computation by numeric integration of arctan'(x) in [0..1]
%
%       Pi [ ( N [, mod] ) ]
%
%  N    [1E7]   #subdivisions of the [0, 1] interval
%  mod  ['s']   communication modality:  (s)end, (i)send, (r)educe
%
%  printed result struct contains
%       pi      estimated pi value
%       err     error
%       time    from argument xmit to pi computed
%
%  Examples:
%  Note: Make sure your start-up script adds MMPI into the path of MATLAB/Octave
%
%  To run within MATLAB or Octave:
%  >> Pi
%
%  To run from command line with five octave instances.
%  $ mpirun -np 5 octave -q --eval "addpath ./examples; Pi(2E7,'i')"
%
%  To run from command line with five Matlab instances.
%  $ mpirun -np 5 matlab -nojvm -nodisplay -r "addpath ./examples; Pi(2E7,'i'); exit"

%#codegen -args {0, 'i'} Pi0 -args {} Pi1 -args {0}

%% Check arguments
if nargin<1; N=int32(1E7);   end
if nargin<2; mod='r'; end
DEBUG=nargin>=3 && varargin{1};

assert(isnumeric(N) && N>=1 && (mod=='s' || mod=='r' || mod=='i'));

%% Results struct
result.pi   = 0;
result.err  = 0;
result.time = 0;

T=mpi_Wtime;

rnk = mpi_Comm_rank(MPI_COMM_WORLD);
siz = mpi_Comm_size(MPI_COMM_WORLD);

%% computation (depends on rank/size)
width=1/double(N);
i=double(rnk):double(siz):double(N)-1;
x=(i+0.5)*width;
lsum=sum(4./(1+x.^2));
TAG=int32(7);

%% reduction and finish
switch mod
    case 'i'
        if rnk>0   % All slaves send result back
            req = mpi_Isend(m2c_opaque_ptr_const(lsum), int32(1), ...
                MPI_Datatype(lsum), int32(0), TAG, MPI_COMM_WORLD);
            mpi_Wait(req);
            Sum = 0;
        else
            Sum = lsum; lsum=m2c_unalias(lsum); % save local result and unshare lsum
            for slv=siz-1:-1:1  % collect in arbitrary order and accumulate
                req = mpi_Irecv(m2c_opaque_ptr(lsum), int32(1), ...
                    MPI_Datatype(lsum), int32(slv), TAG, MPI_COMM_WORLD);
                stat = mpi_Wait(req);
                m2c_rref(lsum);
                
                if DEBUG
                    m2c_printf(['Received partial sum %g from ' ...
                        'process %d with tag %d \n'], lsum, ...
                        MPI_Status(stat, 'get', 'source'), ...
                        MPI_Status(stat, 'get', 'tag'));
                end
                Sum=Sum+lsum;
            end
        end
    case 's'
        if rnk>0   % All slaves send result back
            mpi_Send(m2c_opaque_ptr_const(lsum), int32(1), ...
                MPI_Datatype(lsum), int32(0), TAG, MPI_COMM_WORLD);
            Sum = 0;
        else
            Sum = lsum; lsum=m2c_unalias(lsum); % save local result and unshare lsum
            for slv=siz-1:-1:1 % collect in any order and accumulate
                stat = mpi_Recv(m2c_opaque_ptr(lsum), int32(1), MPI_Datatype(lsum), ...
                    int32(slv), TAG, MPI_COMM_WORLD);
                if DEBUG;
                    m2c_printf(['Received partial sum %g from ' ...
                        'process %d with tag %d \n'], lsum, ...
                        MPI_Status(stat, 'get', 'source'), ...
                        MPI_Status(stat, 'get', 'tag'));
                end
                Sum=Sum+lsum;
            end
        end
    otherwise
        Sum = 0; Sum=m2c_unalias(Sum); % Unshare Sum by writing to it
        mpi_Reduce(m2c_opaque_ptr_const(lsum), m2c_opaque_ptr(Sum), int32(1), ...
            MPI_Datatype(Sum), MPI_SUM, int32(0), MPI_COMM_WORLD);
end

if rnk==0
    Sum = Sum/double(N);
    % stopwatch measurement
    result.time = mpi_Wtime-T;
    result.err  = Sum-pi;
    result.pi   = Sum;
    
    if abs(result.err)>5E-10
        m2c_warn('Result is a bit off.');
    end
    
    m2c_printf(' result.err=%g\n result.pi=%.15g\n result.time=%g\n', ...
        result.err, result.pi, result.time);
end
