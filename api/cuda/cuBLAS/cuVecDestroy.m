function [vec, errCode, toplevel] = cuVecDestroy(vec)
%Destroys a vector on a CUDA device.
%
%  errCode = cuVecDestroy(vec)
%  vec - Handle to vector
%
%  SEE ALSO: cuVecCreate

%#codegen -args {CuVec}

errCode = int32(-1);  %#ok<NASGU>
toplevel = nargout>2;

errCode = coder.ceval('cudaFree', CuVec(vec, 'void *'));

if errCode && (toplevel || m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaFree returned error code %s\n', cuGetErrorString(errCode));
end

if toplevel || m2c_debug
    % Set pointer to null for debugging
    if isnumeric(vec)
        vec = uint64(0);
    else
        vec.data = uint64(0);
    end
end
