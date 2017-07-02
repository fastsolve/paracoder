function [mpicflag, mpildflag] = mpiflags
% Obtain MPI flags

mpicflag = '';
mpildflag = '';

if ispc
    % Assume MPICH2 was installed. http://www.mpich.org/downloads/
    if exist('C:\Program Files\MPICH2\include', 'dir')
        mpicflag = '-IC:\"Program Files"\MPICH2\include';
        mpildflag = '-LC:\"Program Files"\MPICH2\lib -lmpi -lcxx';
    else
        error('Could not locate MPICH2.');
    end
else
    % Use mpicxx so that we obtain libraries for both C and C++.
    [status, str] = system('mpicxx -show');
    
    if ~status
        cflags = regexp(str, '(-[iI][^\s]+)', 'tokens');
        
        for i=1:length(cflags)
            mpicflag = sprintf('%s %s', mpicflag, cflags{i}{1});
        end
        
        ldflags = regexp(str, '(-[Ll][^\s]+)|(-Wl,[^\s]+)', 'tokens');
        for i=1:length(ldflags)
            if isequal(ldflags{i}{1},'-Wl,-z,noexecstack'); continue; end
            if isequal(ldflags{i}{1},'-Wl,-Bsymbolic-functions'); continue; end
            if isequal(ldflags{i}{1},'-Wl,-z,relro'); continue; end
            
            mpildflag = sprintf('%s ''%s''', mpildflag, ldflags{i}{1});
        end
    end
end
