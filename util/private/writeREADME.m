function writeREADME(funcname, cpath, genexe, iscuda)
% Print out README file.

outfile = [cpath '/README'];
fid = fopen(outfile, 'w');
if (fid<0); error('m2c:OpenOutputFile', msg); end

if genexe
    k = 'three';
else
    k = 'two';
end

if iscuda
    mainCFile = [funcname '.cu'];
    mexCFile = [funcname '_mex.cpp'];
else
    mainCFile = [funcname '.c'];
    mexCFile = [funcname '_mex.c'];
end

fprintf(fid, '%s\n', ...
    ['This directory contains the C codes for ' funcname ' generated by m2c.'], '', ...
    ['There are ' k ' sets of files:'], ...
    'Core Library Files (for building a portable library for C):', ...
    ['    ' funcname '_types.h: Declaration of data types'], ...
    ['    ' funcname '.h: Declaration of functions'], ...
    ['    ' mainCFile ': Implementation of functions'], ...
    '    Dependent files m2c.h, m2c.c and rtwtypes.h are in <M2CROOT>/include.', '', ...
    'MEX Function Files (for building a MATLAB/Octave executable):', ...
    ['    ' mexCFile ': Definition of MexFunction.'], ...
    ['    mex_' funcname '.m: MATLAB script for compiling MEX function'], ...
    '    Additional dependent file lib2mex_helper.c is in <M2CROOT>/include.');

if genexe
    fprintf(fid, '%s\n', '', ...
        'Main Function (for building a standalone executable for debugging/profiling):', ...
        ['    ' funcname '_exe.c: Definition of main function that read/write MAT files.'], ...
        ['    build_' funcname '_exe.m: MATLAB script for compiling executible.'], ...
        '    Additional dependent file lib2exe_helper.c is in <M2CROOT>/include.' ...
        );
end

fclose(fid);
end
