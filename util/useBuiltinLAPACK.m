% Use MATLAB's built-in LAPACK

classdef useBuiltinLAPACK < coder.LAPACKCallback
    methods (Static)
        function hn = getHeaderFilename()
            hn = 'lapacke.h';
        end
        
        function updateBuildInfo(~, ~)
        end
    end
end
