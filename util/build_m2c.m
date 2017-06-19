function build_m2c(varargin)

funcs = {'m2c_opaque_ptr', 'm2c_opaque_ptr_const'};

% Compile m2c_opaque_ptr and m2c_opaque_ptr_const
for j=1:length(funcs)
    dir = fileparts(which([funcs{j} '.m']));
    if isoctave && contains(['' varargin{:}], '-matlab')
        if ~isnewer([dir '/' funcs{j} '.' mexext_matlab], [dir '/' funcs{j} '.m'])
            system(['mex ' dir '/' funcs{j} '.c', ' -output ', ...
                    dir '/' funcs{j} '.' mexext]);
        end
    elseif isoctave
        if ~isnewer([dir '/' funcs{j} '.' mexext], [dir '/' funcs{j} '.m'])
            mmex([dir '/' funcs{j} '.c'], '-output', ...
                [dir '/' funcs{j} '.' mexext]);
            delete([funcs{j} '.o'])
        end
    elseif ~isnewer([dir '/' funcs{j} '.' mexext], [dir '/' funcs{j} '.m'])
        mex([dir '/' funcs{j} '.c'], '-output', ...
            [dir '/' funcs{j} '.' mexext]);
    end
end

dir = [m2croot '/util/getMD5/'];

if ~isoctave && ~exist([dir 'GetMD5.' mexext], 'file')
    mex('-O', 'CFLAGS="\$CFLAGS -std=c99"', '-largeArrayDims', ...
        '-D_LITTLE_ENDIAN', '-outdir', dir, [dir 'GetMD5.c']);
elseif isoctave && contains(['' varargin{:}], '-matlab') && ...
        ~exist([dir 'GetMD5.' mexext_matlab], 'file')
    system(['mex -O CFLAGS="\$CFLAGS -std=c99" -largeArrayDims ', ...
        ' -D_LITTLE_ENDIAN -outdir ' dir ' ' dir 'GetMD5.c']);
end

% Build CRS
build_crs(varargin{:})

% Build OpenMP
build_omp(varargin{:})

% Build MPI
build_mpi(varargin{:})

if ~isempty(m2c_cuda_opts)
    % Build CUDA
    build_cuda(varargin{:})
end
