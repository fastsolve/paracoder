function unload_mmpi
try
    if exist(['mpi_Initialized.' mexext], 'file') && ...
            exist(['mpi_Finalized.' mexext], 'file') && ...
            exist(['mpi_Finalize.' mexext], 'file') && ...
            mpi_Initialized && ~mpi_Finalized
        mpi_Finalize; 
    end
catch
end