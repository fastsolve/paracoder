function PingPong(N, mod, varargin)
% PingPong  Classic ping-pong test to exercise basic primitive performance
%
%       PingPong [ ( N [,mod] ) ]
%
%  N    [1E8]   maximum message size to transmit (bytes)
%  mod  ['s']   communication modality:  (s)end, (i)send, (r)educe
%
%  printed results array format is
%       1st col size    array size 1-N bytes in exponential sweep
%       2nd col time    transmission time--ping (one-way)
%
%  Examples:
%  Note: Make sure your start-up script adds the directory of MMPI
%        into the path of MATLAB/Octave.
%  To run within MATLAB or Octave:
%  >> PingPong
%
%  To run from command line with two octave instances.
%  $ mpirun -np 2 octave -q --eval "addpath ./examples; PingPong(1E8,'r')"
%
%  To run from command line with two Matlab instances.
%  $ mpirun -np 2 matlab -nojvm -nodisplay -r "addpath ./examples; PingPong(1E8,'r'); exit"

%#codegen -args {0, 'i'} PingPong0 -args {} PingPong1 -args {0}

%% Check arguments
if nargin<1,  N=1E8;  end
if nargin<2,  mod='s';  end
DEBUG=nargin>=3 && varargin{1};

NTIMES=10;

%% Results array
[FCT,NIP] = log2(N);                    % factor and nearest integer power
if FCT<0.75; NIP=NIP-1; end             % f.i. log2(8) returns [0.5 4]

%% initialization
rnk = mpi_Comm_rank (MPI_COMM_WORLD);
siz = mpi_Comm_size (MPI_COMM_WORLD);

if siz~=2                       % 2 processes required
    mpi_Finalize;
    if rnk==0
        m2c_warn('Two Octave/Matlab instances required.\n');
    end
    return;
elseif rnk==0
    m2c_printf('    Size(B)      Time(s)         BWdth(MB/s)\n');
end

TAG=int32(7);
T=0;

for pow=0:NIP                           % Foreach power of two
    SZ=2^pow;                           % compute size
    
    switch mod
        case 'i'
            array=zeros(SZ,1,'int8');   % allocate array of bytes (col in fact)
            mpi_Barrier(MPI_COMM_WORLD);
            
            if rnk==0
                T=mpi_Wtime;   % stopwatch only required at master
                for i=1:NTIMES
                    % first get slv mark
                    array = m2c_unalias(array);
                    req1 = mpi_Irecv(m2c_opaque_ptr(array), int32(SZ), ...
                        MPI_Datatype(array), int32(1), TAG, MPI_COMM_WORLD);
                    stat = mpi_Wait(req1); m2c_rref(array);
                    if DEBUG
                        m2c_printf(['Received message from ' ...
                            'process %d with tag %d \n'], ...
                            MPI_Status(stat, 'get', 'source'), ...
                            MPI_Status(stat, 'get', 'tag'));
                    end
                    
                    % then circulate it
                    req2 = mpi_Isend(m2c_opaque_ptr_const(array), int32(SZ),...
                        MPI_Datatype(array), int32(1), TAG, MPI_COMM_WORLD);
                    mpi_Wait(req2); m2c_rref(array);
                end
                
                T=mpi_Wtime-T;  % done
                if sum(array) ~= TAG
                    m2c_error('**** mpi_Isend/Irecv malfunction ****')
                end
            else
                array(ceil(rand(1)*SZ))=int8(TAG);
                
                for i=1:NTIMES
                    % first send slv mark
                    req1 = mpi_Isend(m2c_opaque_ptr_const(array), int32(SZ), ...
                        MPI_Datatype(array), int32(0), TAG, MPI_COMM_WORLD);
                    mpi_Wait(req1); m2c_rref(array);
                    
                    % circulate on
                    array = m2c_unalias(array);
                    req2 = mpi_Irecv(m2c_opaque_ptr(array), int32(SZ), ...
                        MPI_Datatype(array), int32(0), TAG, MPI_COMM_WORLD);
                    stat = mpi_Wait(req2); m2c_rref(array);                   
                    if DEBUG
                        m2c_printf(['Received message from ' ...
                            'process %d with tag %d \n'], ...
                            MPI_Status(stat, 'get', 'source'), ...
                            MPI_Status(stat, 'get', 'tag'));
                    end
                end
            end
        case 's'
            array=zeros(SZ,1,'int8');  % allocate array of bytes (col in fact)
            mpi_Barrier(MPI_COMM_WORLD);
            
            if rnk==0
                T=mpi_Wtime;   % stopwatch only required at master
                for i=1:NTIMES
                    % first get slv mark
                    array = m2c_unalias(array);
                    stat = mpi_Recv(m2c_opaque_ptr(array), int32(SZ), ...
                        MPI_Datatype(array), int32(1), TAG, MPI_COMM_WORLD);
                    if DEBUG
                        m2c_printf(['Received message from ' ...
                            'process %d with tag %d \n'], ...
                            MPI_Status(stat, 'get', 'source'), ...
                            MPI_Status(stat, 'get', 'tag'));
                    end
                    
                    % then circulate it
                    mpi_Send(m2c_opaque_ptr_const(array), int32(SZ),...
                        MPI_Datatype(array), int32(1), TAG, MPI_COMM_WORLD);
                end
                T=mpi_Wtime-T;
                if sum(array) ~= TAG
                    m2c_error('**** mpi_Send or Recv malfunction ****')
                end
            else
                array(ceil(rand(1)*SZ))=int8(TAG);
                
                for i=1:NTIMES
                    % first send slv mark
                    mpi_Send(m2c_opaque_ptr_const(array), int32(SZ), ...
                        MPI_Datatype(array), int32(0), TAG, MPI_COMM_WORLD);
                    
                    % circulate on
                    array = m2c_unalias(array);
                    stat = mpi_Recv(m2c_opaque_ptr(array), int32(SZ), ...
                        MPI_Datatype(array), int32(0), TAG, MPI_COMM_WORLD);
                    if DEBUG
                        m2c_printf(['Received message from ' ...
                            'process %d with tag %d \n'], ...
                            MPI_Status(stat, 'get', 'source'), ...
                            MPI_Status(stat, 'get', 'tag'));
                    end
                end
            end
        case 'r'
            SIZ =        SZ ;
            SOD =        8;                     % sizeof(double)==8==2^3
            if SIZ<SOD, SIZ =SOD; end
            SIZ=SIZ/SOD;
            array=zeros(SIZ,1);
            arr_1=ones (SIZ,1);
            nullptr = zeros(0, 1);
            op=MPI_SUM;
            mpi_Barrier(MPI_COMM_WORLD);
            
            if rnk==0
                T=mpi_Wtime;
                for i=1:NTIMES
                    array = m2c_unalias(array);
                    mpi_Reduce(m2c_opaque_ptr_const(array), m2c_opaque_ptr(nullptr), int32(SIZ), ...
                        MPI_Datatype(array), op, int32(1), MPI_COMM_WORLD);
                    [arr_1, array] = m2c_unalias(arr_1, array);
                    mpi_Reduce(m2c_opaque_ptr_const(arr_1), m2c_opaque_ptr(array), int32(SIZ), ...
                        MPI_Datatype(array), op, int32(0), MPI_COMM_WORLD);
                end % whatever slv sent +1 => in array here
                T=mpi_Wtime-T;
                if any(array ~= 2*NTIMES)
                    m2c_error ('**** mpi_Reduce malfunction ****')
                end
            else
                for i=1:NTIMES                  % whatever mst sent +1 => in array here
                    [arr_1, array] = m2c_unalias(arr_1, array);
                    mpi_Reduce(m2c_opaque_ptr_const(arr_1), m2c_opaque_ptr(array), int32(SIZ), ...
                        MPI_Datatype(array), op, int32(1), MPI_COMM_WORLD);
                    array = m2c_unalias(array);
                    mpi_Reduce(m2c_opaque_ptr_const(array), m2c_opaque_ptr(nullptr), int32(SIZ), ...
                        MPI_Datatype(array), op, int32(0), MPI_COMM_WORLD);
                end
            end  % MST / SLV
    end % switch mod
    
    if rnk==0
        m2c_printf('%10d\t%9.6f\t%10.6f\n', int32(SZ), ...
            T/2/NTIMES,SZ*2E-6*NTIMES/T);
    end
    
end % for pow
