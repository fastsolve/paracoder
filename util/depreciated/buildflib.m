function buildflib(fcomp, libname, opts, inpfiles, libs)

if ~isunix
    error('Building Fortran libraries is only supported on UNIX.');
end

switch (fcomp)
    case {'GFORTRAN','GNU'}
        fc = 'gfortran';
        fopts = [opts ' -fcray-pointer -fPIC'];
        ld = 'gfortran';
    case {'INTEL','INTEL_F90','INTEL_F95','IFORT'}
        fc = 'ifort';
        fopts = [opts ' -fPIC'];
        if ~isempty(regexp(opts, '-g', 'match')); 
            fopts = [fopts ' -check'];
        end
        ld = 'ifort';
    case {'IBM_','IBM_F90_','IBM_F95_','XLF_','IBM','IBM_F90','IBM_F95','XLF'}
        fc = 'xlf95_r';
        fopts = [opts ' -qpic -qlanglvl=95std -qspill=21648'];
        if ~isempty(regexp(opts, '-g', 'match')); 
            fopts = [fopts ' -qcheck'];
        end
        if fcomp(end)=='_'; fopts = [fopts ' -qextname']; end

        ld = 'gcc';
        libs = [libs ' -L/opt/ibmcmp/xlf/11.1/lib -lxlf90_r -lxlopt -lxl -lxlfmath'...
            ' -L/opt/ibmcmp/xlsmp/1.7/lib -lxlsmp'];

    case {'NAG','NAG_F90','NAG_F95'}
        fc = 'f95'; fopts = [opts ' -dusty -PIC -w=all'];
        ld = 'gcc';
        libs = [libs ' -L/usr/local/lib/NAGWare -lf98'...
            ' /usr/local/lib/NAGWare/quickfit.o'];
end

% Convert input files into list
list_files = regexp(inpfiles, '\S+', 'match');
list = char(zeros(1,length(inpfiles)));

c = 0;
for i=1:length(list_files)
    f = list_files{i};
    if strcmp(f(end-1:end),'.f') || strcmp(f(end-1:end),'.F')
        s = [f(1:end-1) 'o '];
        command = [fc ' ' fopts];
    elseif strcmp(f(end-3:end),'.f90') || strcmp(f(end-3:end),'.f95') || ...
           strcmp(f(end-3:end),'.f03') || strcmp(f(end-3:end),'.F90') || ...
           strcmp(f(end-3:end),'.F95') || strcmp(f(end-3:end),'.F03')
        s = [f(1:end-3) 'o '];
        command = [fc ' ' fopts];
    elseif strcmp(f(end-1:end),'.c') && ~strcmp(ld, 'gcc')
        s = [f(1:end-1) 'o '];
        command = ['gcc ' opts ' -fPIC'];
    else
        c1 = c+length(f)+1; list(c+1:c1) = [f ' ']; c = c1;
        continue;
    end

    % Find last '/'
    for j=length(s):-1:1
        if s(j)=='/'; s(1:j) = []; break; end
    end
    command = [command ' -c ' f ' -o ' s]; %#ok<AGROW>

    disp(command);
    system(command);

    c1 = c+length(s); list(c+1:c1) = s; c = c1;
end

if ismac
    command = [ld ' -fno-common -Wl,-flat_namespace -dynamiclib -undefined error ' ...
        opts ' -o ' libname '.dylib ' list(1:c) libs];
else
    command = [ld ' -shared ' ...
        opts ' -o ' libname '.so ' list(1:c) libs];
end

disp(command);
system(command);
