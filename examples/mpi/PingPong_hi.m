function PingPong_hi(N, mod, varargin)
% PingPong_hi  Ping-pong test for high-level functions
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
%  $ mpirun -np 2 octave -q --eval "addpath ./examples; PingPong_hi(1E8,'r')"
%
%  To run from command line with two Matlab instances.
%  $ mpirun -np 2 matlab -nojvm -nodisplay -r "addpath ./examples; PingPong_hi(1E8,'r'); exit"

%#codegen -args {0, 'i'} PingPong_hi0 -args {} PingPong_hi1 -args {0}

%% Check arguments
if nargin<1,  N=1E8;  end
if nargin<2,  mod='s';  end
DEBUG=nargin>=3 && varargin{1};

NTIMES=10;

%% Results array
[FCT,NIP] = log2(N);                    % factor and nearest integer power
if FCT<0.75; NIP=NIP-1; end             % f.i. log2(8) returns [0.5 4]

%% initialization
rnk = comm_rank (MPI_COMM_WORLD);
siz = comm_size (MPI_COMM_WORLD);

if siz~=2                       % 2 processes required
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
            barrier(MPI_COMM_WORLD);
            
            if rnk==0
                T=wtime;   % stopwatch only required at master
                for i=1:NTIMES
                    % first get slv mark
                    array = irecv_init(array);
                    req1 = irecv_sub(array, 1, SZ, [], 1, TAG, MPI_COMM_WORLD);
                    stat = wait(req1);
                    if DEBUG
                        m2c_printf(['Received message from ' ...
                            'process %d with tag %d \n'], ...
                            MPI_Status(stat, 'get', 'source'), ...
                            MPI_Status(stat, 'get', 'tag'));
                    end
                    
                    % then circulate it
                    req2 = isend_sub(array, 1, SZ, [], 1, TAG, MPI_COMM_WORLD);
                    wait(req2);
                end
                
                T=wtime-T;  % done
                if sum(array) ~= TAG
                    m2c_error('**** isend or irecv malfunction ****')
                end
            else
                array(ceil(rand(1)*SZ))=int8(TAG);
                
                for i=1:NTIMES
                    % first send slv mark
                    req1 = isend_sub(array, 1, SZ, [], 0, TAG, MPI_COMM_WORLD);
                    wait(req1);
                    
                    % circulate on
                   array = irecv_init(array);
                   req2 = irecv_sub(array, 1, SZ, [], 0, TAG, MPI_COMM_WORLD);
                    stat = wait(req2);
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
            barrier(MPI_COMM_WORLD);
            
            if rnk==0
                T=wtime;   % stopwatch only required at master
                for i=1:NTIMES
                    % first get slv mark
                    [array, stat] = recv_sub(array, 1, SZ, [], 1, TAG, MPI_COMM_WORLD);
                    if DEBUG
                        m2c_printf(['Received message from ' ...
                            'process %d with tag %d \n'], ...
                            MPI_Status(stat, 'get', 'source'), ...
                            MPI_Status(stat, 'get', 'tag'));
                    end
                    
                    % then circulate it
                    send_sub(array, 1, SZ, [], 1, TAG, MPI_COMM_WORLD);
                end
                T=wtime-T;
                if sum(array) ~= TAG
                    m2c_error('**** send or recv malfunction ****')
                end
            else
                array(ceil(rand(1)*SZ))=int8(TAG);
                
                for i=1:NTIMES
                    % first send slv mark
                    send_sub(array, 1, SZ, [], 0, TAG, MPI_COMM_WORLD);
                    
                    % circulate on
                    [array, stat] = recv_sub(array, 1, SZ, [], 0, TAG, MPI_COMM_WORLD);
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
            barrier(MPI_COMM_WORLD);
            
            if rnk==0
                T=wtime;
                for i=1:NTIMES
                    reduce(array, [], MPI_SUM, MPI_COMM_WORLD, int32(1));
                    array = reduce(arr_1, [], MPI_SUM, MPI_COMM_WORLD, int32(0));
                end
                T=wtime-T;
                if any(array ~= 2*NTIMES)
                    m2c_error ('**** reduce malfunction ****')
                end
            else
                for i=1:NTIMES
                    array = reduce(arr_1, [], MPI_SUM, MPI_COMM_WORLD, int32(1));
                    reduce(array, [], MPI_SUM, MPI_COMM_WORLD, int32(0));
                end
            end  % MST / SLV
    end % switch mod
    
    if rnk==0
        m2c_printf('%10d\t%9.6f\t%10.6f\n', int32(SZ), ...
            T/2/NTIMES,SZ*2E-6*NTIMES/T);
    end
    
end % for pow
