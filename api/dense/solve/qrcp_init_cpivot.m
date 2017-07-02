function cpivot = qrcp_init_cpivot(m, n, cpivot) %#codegen
% Initialize a struct for qrcp for matrix with M rows and N cols.
cpivot.coldep = zeros(0,0,'uint8');
coder.varsize('cpivot.coldep', [inf,inf]);

% Output for qrcp
coder.varsize('cpivot.new2old','cpivot.old2new', 'cpivot.fronts', ...
    'cpivot.deps', 'cpivot.hv', 'cpivot.cnorms', 'cpivot.x', 'cpivot.z', ...
    [inf 1]);
cpivot.new2old = coder.nullcopy(zeros(n,1,'int32'));
cpivot.old2new = coder.nullcopy(zeros(n,1,'int32'));

% Work buffers
cpivot.fronts  = coder.nullcopy(zeros(n,1,'int32'));
cpivot.deps    = coder.nullcopy(zeros(n,1, 'uint8'));
cpivot.hv      = coder.nullcopy(zeros(m,1));
cpivot.cnorms  = coder.nullcopy(zeros(n,1));

% Buffers for estimating rank
cpivot.x = coder.nullcopy(zeros(n,1));
cpivot.z = coder.nullcopy(zeros(n,1));
