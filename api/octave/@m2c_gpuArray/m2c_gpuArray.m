function obj = m2c_gpuArray
obj = struct('data', int64(0), 'type', '', 'dims', int32(0), 'counter', int32(0));
obj = class(obj, 'm2c_gpuArray');
end
