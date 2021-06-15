function [str, structDefs, useNDims, hasCuError, hasAlias] = marshallin(vars, ...
    funcname, iscuda, structDefs, cprefix, mx_index, rw_mode, writeonly)
% Marshall function input arguments and preallocate output arguments.

if nargin<6
    cprefix = '';
    mx_index = 0;
    rw_mode = false;
    writeonly = false;
end

str = '';
useNDims = false;
hasCuError = false;
hasAlias = false;

for i=1:length(vars)
    var = vars(i);

    if isempty(cprefix) && isempty(var.iindex) && isempty(var.oindex)
        continue;
    end

    j = var.iindex;
    writeonly_var = writeonly || isempty(cprefix) && isempty(var.iindex) && ~isempty(var.oindex);
    rwmode_var = rw_mode || isempty(cprefix) && ~isempty(var.oindex) && ~isempty(var.iindex);

    str = sprintf('%s\n', str);
    cvarname = [cprefix var.cname];

    % Determine some shared variables
    if isempty(cprefix)
        if ~writeonly_var
            rhs = ['prhs[' num2str(j-1) ']'];
        else
            rhs = '';
        end

        if ~iscuda && (strncmp(var.type, 'emxArray_', 9) || prod(var.size)==1 && ...
                ~var.vardim && (~isempty(var.subfields) || isempty(var.modifier)))
            cvarname_ptr = ['&' cvarname];
        else
            cvarname_ptr = cvarname;
        end
    else
        if ~isempty(cprefix) && ~writeonly_var
            str = sprintf('%s\n', str, ...
                ['    sub_mx = mxGetField(mx, ' mx_index  ', "' var.mname '");']);
            rhs = 'sub_mx';
        else
            rhs = '';
        end

        if isempty(var.modifier)
            cvarname_ptr = ['&' cvarname];
        else
            cvarname_ptr = cvarname;
        end
    end

    str_gpu = '';
    str_mx = '';

    if ~writeonly_var
        % Check type
        errchk = sprintf('%s\n', ...
            ['    if (mxGetNumberOfElements(' rhs ...
            ') && mxGetClassID(' rhs ') != ' getMxClassID(var.basetype) ')'], ...
            ['        mexErrMsgIdAndTxt("' funcname ':WrongInputType",'],...
            ['            "Input argument ' var.mname ' has incorrect data type; ' ...
            getMatlabClass(var.basetype) ' is expected.");']);

        if ~iscuda || isempty(var.modifier)
            str = sprintf('%s\n', str, errchk);
        else
            str_gpu = sprintf('%s\n', str_gpu, ...
                '        char _type[64];', ...
                ['        mxGetString(mxGetFieldByNumber(' rhs ', 0, 1), _type, 64);'], ...
                ['        if (strcmp(_type, "' getMatlabClass(var.basetype) '"))'], ...
                ['            mexErrMsgIdAndTxt("' funcname ':WrongInputType",'],...
                ['                "Input argument ' var.mname ' has incorrect data type; ' ...
                getMatlabClass(var.basetype) ' is expected.");']);

            str_mx = sprintf('%s    %s', str_mx, ....
                strrep(errchk, [newline '    '], [newline '        ']));
        end
    end

    if ~writeonly_var && prod(var.size) == 1 && ~any(var.vardim)
        % Check size of a scalar input
        str = sprintf('%s\n', str(1:end-1), ...
            ['    if (mxGetNumberOfElements(' rhs ') != 1)'], ...
            ['        mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'],...
            ['            "Argument ' var.mname ' should be a scalar.");']);
    elseif ~writeonly_var
        % Check size and all dimensions
        if ~iscuda && length(var.size)>2
            str = sprintf('%s\n', str, ...
                ['    _nDims = mxGetNumberOfDimensions(' rhs ');']);
            useNDims = true;
        elseif iscuda
            str_gpu = sprintf('%s\n', str_gpu, ...
                ['        int _nDims = mxGetNumberOfElements(mxGetFieldByNumber(' rhs ', 0, 2));'], ...
                ['        int *_dims = (int*)mxGetData(mxGetFieldByNumber(' rhs ', 0, 2));']);
            if length(var.size)>2
                str_mx = sprintf('%s', str_mx, ...
                    ['        int  _nDims = mxGetNumberOfDimensions(' rhs ');']);
            end
        end

        for k=1:max(length(var.size),2)
            % The higher dimensions are checked in lib2mex_helper.c
            getdim_mx = ['mxGetDimensions(' rhs ')[' num2str(k-1) ']'];
            getdim_gpu = ['_dims[' num2str(k-1) ']'];

            if k>length(var.vardim) || var.size(k)==1 && ~var.vardim(k)
                if k>2
                    dimerr_mx = ['_nDims>' num2str(k) ' && ' getdim_mx ' != 1'];
                else
                    dimerr_mx = [getdim_mx ' != 1'];
                end

                errchk = sprintf('%s\n', ...
                    ['    if (mxGetNumberOfElements(' rhs ') && ' dimerr_mx ') '], ...
                    ['        mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                    ['            "Dimension ' num2str(k) ' of ' var.mname ...
                    ' should be equal to 1.");']);
                if ~iscuda
                    str = sprintf('%s', str, errchk);
                else
                    dimerr_gpu = ['_nDims>' num2str(k) ' && ' getdim_gpu ' != 1'];
                    str_gpu = sprintf('%s\n', str_gpu, ...
                        ['        if (' dimerr_gpu ')'], ...
                        ['            mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                        ['                "Dimension ' num2str(k) ' of ' var.mname ...
                        ' should be equal to 1.");']);
                    str_mx = sprintf('%s    %s', str_mx, ....
                        strrep(errchk, [newline '    '], [newline '        ']));
                end
            elseif ~var.vardim(k)
                if k>2
                    dimerr_mx = ['_nDims<=' num2str(k) ' || ' getdim_mx ' != ' num2str(var.size(k))];
                else
                    dimerr_mx = [getdim_mx ' != ' num2str(var.size(k))];
                end
                if k>1
                    dimerr_gpu = ['_nDims<=' num2str(k) ' || ' getdim_gpu ' != ' num2str(var.size(k))];
                else
                    dimerr_gpu = [getdim_gpu ' != ' num2str(var.size(k))];
                end

                errchk = sprintf('%s\n', ...
                    ['    if (mxGetNumberOfElements(' rhs ') && ' dimerr_mx ') '], ...
                    ['        mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                    ['            "Dimension ' num2str(k) ' of ' var.mname ...
                    ' should be equal to ' num2str(var.size(k)) '.");']);
                if ~iscuda
                    str = sprintf('%s', str, errchk);
                else
                    str_gpu = sprintf('%s\n', str_gpu, ...
                        ['        if (' dimerr_gpu ')'], ...
                        ['            mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                        ['                "Dimension ' num2str(k) ' of ' var.mname ...
                        ' should be equal to ' num2str(var.size(k)) '.");']);
                    str_mx = sprintf('%s    %s', str_mx, ....
                        strrep(errchk, [newline '    '], [newline '        ']));
                end
            elseif isfinite(var.size(k))
                if k>2
                    dimerr_mx = ['_nDims>' num2str(k) ' && ' getdim_mx ' > ' num2str(var.size(k))];
                else
                    dimerr_mx = [getdim_mx ' > ' num2str(var.size(k))];
                end
                if k>1
                    dimerr_gpu = ['_nDims>' num2str(k) ' && ' getdim_gpu ' > ' num2str(var.size(k))];
                else
                    dimerr_gpu = [getdim_gpu ' > ' num2str(var.size(k))];
                end

                errchk = sprintf('%s\n', ...
                    ['    if (mxGetNumberOfElements(' rhs ') && ' dimerr_mx ')'], ...
                    ['        mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                    ['            "Dimension ' num2str(k) ' of ' var.mname ...
                    ' should be no greater than ' num2str(var.size(k)) '.");']);
                if ~iscuda
                    str = sprintf('%s', str, errchk);
                else
                    str_gpu = sprintf('%s\n', str_gpu, ...
                        ['        if (' dimerr_gpu  ')'], ...
                        ['            mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                        ['                "Dimension ' num2str(k) ' of ' var.mname ...
                        ' should be no greater than ' num2str(var.size(k)) '.");']);

                    str_mx = sprintf('%s    %s', str_mx, ....
                        strrep(errchk, [newline '    '], [newline '        ']));
                end
            end
        end
    end

    if ~isempty(var.subfields) && ~writeonly_var
        hasArray = ~strncmp(var.type, 'emxArray_', 9) && (prod(var.size)>1 || any(var.vardim));
        [marshallinFunc, structDefs] = gen_marshallinFunc(structDefs, var.type, ...
            hasArray, iscuda, rwmode_var, writeonly_var);
    end

    if var.isemx || prod(var.size)>1 || any(var.vardim) || ...
            ~isempty(var.modifier) && ~isempty(var.oindex) && ...
            (isempty(var.subfields) || ~isequal(var.size, 1))
        if isequal(var.type, ['emxArray_', var.basetype]) || ...
                isequal(var.type, ['emxArray_', var.structname])
            % Case 1: A full emxArray
            if ~iscuda
                if ~writeonly_var
                    if ~isempty(var.subfields)
                        copyFunc = marshallinFunc;
                        str = sprintf('%s%s\n', str, ...
                            ['    ' copyFunc '(' cvarname_ptr ', ' ...
                             rhs ', "' var.mname '", ' num2str(length(var.size)) ');']);
                    else
                        if rwmode_var
                            copyFunc = 'copy_mxArray_to_emxArray';
                        else
                            copyFunc = 'alias_mxArray_to_emxArray';
                            hasAlias = true;
                        end
                        if ~isempty(cprefix)
                            str = sprintf('%s\n', str, ...
                                ['    ' cvarname ' = (' var.type '*)mxMalloc(sizeof(' var.type '));'], ...
                                ['    init_emxArray((emxArray__common*)(' cvarname_ptr ...
                                '), ' num2str(length(var.size)) ');']);
                        end
                        str = sprintf('%s%s\n', str, ...
                            ['    ' copyFunc '(' rhs ', (emxArray__common *)(' ...
                            cvarname_ptr '), "' var.mname '", ' num2str(length(var.size)) ');']);
                    end
                elseif ~iscuda
                    if ~isempty(cprefix)
                        str = sprintf('%s\n', str, ...
                            ['    ' cvarname ' = (' var.type '*)mxMalloc(sizeof(' var.type '));']);
                    end
                    str = sprintf('%s\n', str(1:end-1), ...
                        ['    init_emxArray((emxArray__common*)(' cvarname_ptr ...
                        '), ' num2str(length(var.size)) ');']);
                end
            elseif writeonly_var
                error('All varilable-size output arrays must also be input for CUDA kernel functions.');
            else
                str_gpu = sprintf('%s\n', str_gpu, ...
                    ['        ' cvarname ' = wrap_mxArray_to_gpuEmxArray<' var.type ', true>(' rhs ');']);

                if ~isempty(var.subfields)
                    copyFunc = marshallinFunc;
                else
                    copyFunc = ['copy_mxArray_to_gpuEmxArray<' var.type '>'];
                end

                str_mx = sprintf('%s\n', str_mx, ...
                    ['        ' cvarname ' = ' copyFunc '(' ...
                    rhs ', "' var.mname '", ' num2str(length(var.size)) ');']);
            end
        elseif var.isemx && (isempty(var.sizefield) || isempty(var.modifier))
            % Case 2. A reduced emxArray with only data and size fields
            assert(~isempty(cprefix));

            if ~iscuda
                if ~writeonly_var
                    if ~isempty(var.subfields)
                        copyFunc = marshallinFunc;
                    else
                        copyFunc = 'copy_mxArray_to_DataSize';
                    end
                    str = sprintf('%s%s\n', str, ...
                        ['    ' copyFunc '(' cvarname '.data, ' ...
                        num2str(length(var.size)) ', ' cvarname '.size, ' rhs ', "' ...
                        var.mname '", ' num2str(prod(var.size)) ');']);
                end
            elseif iscuda
                if ~writeonly_var
                    str_gpu = sprintf('%s\n', str_gpu, ...
                        ['        ' cvarname ' = wrap_mxArray_to_gpuEmxArray<' var.type ', false>(' rhs ');']);

                    if ~isempty(var.subfields)
                        copyFunc = marshallinFunc;
                    else
                        copyFunc = ['copy_mxArray_to_gpuEmxArrayStatic<' var.type '>'];
                    end
                    str_mx = sprintf('%s\n', str_mx, ...
                        ['        ' cvarname ' = ' copyFunc '(' rhs ...
                        ', ' num2str(length(var.size)) ', "' var.mname '", ' num2str(prod(var.size)) ');']);
                else
                    error('All varilable-size output arrays must also be input for CUDA kernel functions.');
                end
            end
        else
            if prod(var.size)==1
                multiple = '';
            elseif all(isfinite(var.size))
                multiple = [' * ' num2str(prod(var.size)+isequal(var.type, 'char_T'))];
            else
                multiple = [' * mxGetNumberOfElements(' rhs ')'];
            end

            if ~iscuda
                if var.isemx && ~isempty(var.sizefield) && isnumeric(var.sizefield)
                    % Case 3. emxArray split into _data and _size arguments
                    sizefield = vars(var.sizefield).cname;
                else
                    % Case 4: emxArray simplified to _data without _size field
                    sizefield = 'NULL';
                end

                if any(isinf(var.size))
                    maxlen = '0';
                else
                    maxlen = num2str(prod(var.size));
                end
                if ~isempty(cprefix) || rwmode_var || writeonly_var || ...
                        ~isempty(var.subfields) || isequal(var.type, 'char_T')
                    if isempty(cprefix)
                        str = sprintf('%s\n', str, ...
                            ['    ' cvarname ' = (' var.type '*)mxMalloc(sizeof(' var.type ')' multiple ');']);
                        if ~isequal(sizefield, 'NULL')
                            if ~writeonly_var
                                % Copy in size information
                                for k=1:length(var.size)
                                    str = sprintf('%s\n', str(1:end-1), ...
                                        ['    ' sizefield '[' num2str(k-1) ...
                                        '] = mxGetDimensions(' rhs ')[' num2str(k-1) '];']);
                                end
                            else
                                % Copy in size information
                                for k=1:length(var.size)
                                    if var.vardim(k)
                                        str = sprintf('%s\n', str(1:end-1), ...
                                            ['    ' sizefield '[' num2str(k-1) '] = 0;']);
                                    else
                                        str = sprintf('%s\n', str(1:end-1), ...
                                            ['    ' sizefield '[' num2str(k-1) '] = ' num2str(var.size(k)) ';']);
                                    end
                                end
                            end
                        end
                    end

                    if ~writeonly_var
                        if ~isempty(var.subfields)
                            str = sprintf('%s%s\n', str, ...
                                ['    ' marshallinFunc '(' cvarname_ptr ', ', ...
                                rhs ', "' var.mname '");']);
                        else
                            str = sprintf('%s%s\n', str, ...
                                ['    copy_mxArray_to_DataSize(' cvarname_ptr ', ' ...
                                num2str(length(var.size)) ', ' sizefield ', ' rhs ', "' ...
                                var.mname '", ' maxlen ');']);
                        end
                    elseif ~isempty(var.subfields) && ~any(var.vardim)
                        [preallocFunc, structDefs] = gen_marshallinFunc(structDefs, var.type, ...
                            true, false, rwmode_var, writeonly_var);

                        if ~isempty(preallocFunc)
                            % Preallocate structures
                            str = sprintf('%s%s\n', str, ...
                                ['    ' preallocFunc '(' cvarname_ptr ', ', maxlen ');']);
                        end
                    end
                else
                    % Alias an input-only array
                    str = sprintf('%s%s\n', str, ...
                        ['    alias_mxArray_to_DataSize((void **)&' cvarname ', ' ...
                        num2str(length(var.size)) ', ' sizefield ', ' rhs ', "' ...
                        var.mname '", ' maxlen ');']);
                    hasAlias = true;
                end
            elseif ~writeonly_var
                if var.isemx && ~isempty(var.sizefield) && isnumeric(var.sizefield)
                    % Case 3. emxArray split into _data and _size arguments
                    sizefield = ['&' vars(var.sizefield).cname];
                else
                    % Case 4: emxArray simplified to _data without _size field
                    sizefield = 'NULL';
                end

                str_gpu = sprintf('%s\n', str_gpu, ...
                    ['        wrap_mxArray_to_gpuDataSize(&' cvarname_ptr ', ' ...
                    sizefield, ', ' rhs ');']);

                if ~isempty(var.subfields)
                    copyFunc = marshallinFunc;
                else
                    copyFunc = 'copy_mxArray_to_gpuDataSize';
                end
                str_mx = sprintf('%s\n', str_mx, ...
                    ['        ' copyFunc '(&' cvarname ', ', ...
                    num2str(length(var.size)) ', ' sizefield, ', ' rhs ');']);
            else
                if any(var.vardim)
                    error('All varilable-size output arrays must also be input for CUDA kernel functions.');
                end

                str_mx = sprintf('%s\n', str_mx, ...
                    ['        _ierr = cudaMalloc(&' cvarname ...
                    ', sizeof(' var.type ')' multiple ');'], ...
                    '    CHKCUERR(_ierr, "cudaMalloc");');
                hasCuError = true;
            end
        end
    else
        % Process a scalar input variable
        if ~isempty(var.subfields)
            if ~iscuda || isempty(var.modifier)
                if ~writeonly_var
                    str = sprintf('%s%s\n', str, ...
                        ['    ' marshallinFunc '(' cvarname_ptr ...
                        ', ' rhs ', "' var.mname '");']);
                elseif ~isempty(var.subfields)
                    [preallocFunc, structDefs] = gen_marshallinFunc(structDefs, var.type, ...
                        false, iscuda, rwmode_var, writeonly_var);

                    if ~isempty(preallocFunc)
                        % Preallocate a structure
                        str = sprintf('%s%s\n', str, ...
                            ['    ' preallocFunc '(' cvarname_ptr ');']);
                    end
                end
            else
                % For CUDA with modifier, we need to preallocate the object on CUDA
                str_mx = sprintf('%s\n', str_mx, ...
                    ['    _ierr = cudaMalloc(&' cvarname ', sizeof(' var.type ');'], ...
                    '    CHKCUERR(_ierr, "cudaMalloc");');
                if ~writeonly_var
                    str_mx = sprintf('%s\n', str_mx(1:end-1), ...
                        ['    ' marshallinFunc '(' cvarname_ptr ', ' rhs ', "' var.mname '");']);
                elseif ~isempty(var.subfields)
                    [preallocFunc, structDefs] = gen_marshallinFunc(structDefs, var.type, ...
                        false, iscuda, rwmode_var, writeonly_var);

                    if ~isempty(preallocFunc)
                        % Preallocate a structure
                        str_mx = sprintf('%s%s\n', str_mx, ...
                            ['    ' preallocFunc '(' cvarname_ptr ');']);
                    end
                end
                hasCuError = true;
            end
        elseif ~writeonly_var
            assert(isempty(var.modifier));
            if isequal(var.type, 'char_T') || isequal(var.type, 'char')
                % This is a single character, so we can simply cast it
                str = sprintf('%s%s\n', str, ...
                    ['    ' cvarname ' = *(mxChar*)mxGetData(' rhs ');']);
            else
                str = sprintf('%s%s\n', str, ...
                    ['    ' cvarname ' = *(' var.type '*)mxGetData(' rhs ');']);
            end
        end
    end

    if ~isempty(str_gpu) || ~isempty(str_mx)
        str = sprintf('%s\n', str, ...
            ['    if (mxIsClass(' rhs ', "m2c_gpuArray")) {'], ...
            str_gpu, ...
            '    } else {', ...
            str_mx, ...
            '    }');
    end
end

if ~isempty(str) && isempty(cprefix)
    str = ['    /* Marshall in inputs and preallocate outputs */' ...
        regexprep(str, '\n\n', '\n')];
end

end

function [funcname, structDefs] = gen_marshallinFunc(structDefs, type, ...
    hasArray, iscuda, rw_mode, writeonly)
% Generate function for marshalling in a struct or an array of struct objects.
% It may recursively generate additional marshallin functions for other structs .

if ~writeonly
    if ~iscuda && hasArray && rw_mode
        funcField = 'marshallinArrayFunc';
        funcname = ['marshallin_'  type '_Array'];
    elseif ~iscuda && ~hasArray && rw_mode
        funcField = 'marshallinFunc';
        funcname = ['marshallin_'  type];
    elseif hasArray && ~rw_mode
        funcField = 'marshallinConstArrayFunc';
        funcname = ['marshallin_const_'  type '_Array'];
    else
        funcField = 'marshallinConstFunc';
        funcname = ['marshallin_const_'  type];
    end
else
    if hasArray
        funcField = 'preallocArrayFunc';
        funcname = ['prealloc_'  type '_Array'];
    else
        funcField = 'preallocFunc';
        funcname = ['prealloc_'  type];
    end
end

if isnumeric(structDefs.(type).(funcField))
    % A read-write function may be the same as readonly
    funcname = regexprep(funcname, '^marshallin_const_', 'marshallin_');
    return;
elseif ~isempty(structDefs.(type).(funcField))
    if isempty(strtrim(structDefs.(type).(funcField)))
        % A preallocation routine may be empty
        assert(strncmp(funcname, 'prealloc_', 9));
        funcname = '';
    end
    return;
else
    structDefs.(type).(funcField) = ...
        '/* Set it to nonempty to prevent the same function being created again */';
end

% Check struct type and fields
str_chk = '';
if ~writeonly
    str_chk = sprintf('%s\n', str_chk, ...
        '    if (!mxIsStruct(mx))', ...
        ['        M2C_error("' funcname ':WrongType",'],...
        '            "Input argument %s has incorrect data type; struct is expected.", mname);');

    fields = {structDefs.(type).fields.mname};
    for i=1:length(fields)
        str_chk = sprintf('%s\n', str_chk(1:end-1), ...
            ['    if (!mxGetField(mx, 0, "' fields{i} '"))'], ...
            ['        M2C_error("' funcname ':WrongType",'],...
            ['            "Input argument %s is missing the field ' fields{i} '.", mname);']);
    end

    str_chk = sprintf('%s\n', str_chk(1:end-1), ...
        ['    if (mxGetNumberOfFields(mx) > ' num2str(length(fields)) ')'], ...
        ['        M2C_warn("' funcname ':ExtraFields",'], ...
        '            "Extra fields in %s and are ignored.", mname);');

    decl_vars = sprintf('    %-20s*%s;', 'mxArray', 'sub_mx');
else
    decl_vars = '';
end

if strncmp(type, 'emxArray_', 9)
    assert(~writeonly);
    basetype = structDefs.(type).structname;
    assert(isequal(type, ['emxArray_', basetype]));
    varname = 'pEmx';

    if ~iscuda
        return_type = 'void ';
        args = [type ' *pEmx, const mxArray *mx, const char *mname, const int dim'];
        return_str = '';
    else
        return_type = [type ' *'];
        args = 'const char *mname, const mxArray *mx';

        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s*%s;', type, varname));
        return_str = ['    return ' varname ';'];
    end

    mx_index = 'i';
    cprefix = 'pEmx->data[i].';
elseif hasArray
    varname = 'pArr';
    return_type = 'void ';

    if ~writeonly
        args = [type ' *pArr, const mxArray *mx, const char *mname'];
        return_str = '';
    else
        args = [type ' *pArr, int nElems'];
        return_str = '';
    end
    mx_index = 'i';
    cprefix = 'pArr[i].';
else
    varname = 'pStruct';
    return_type = 'void ';

    if ~writeonly
        args = [type ' *' varname ', const mxArray *mx, const char *mname'];
    else
        args = [type ' *' varname];
    end

    return_str = '';

    mx_index = '0';
    cprefix = 'pStruct->';
end

if hasArray
    multiple = ' * nElems';
else
    multiple = '';
end

hasCuError_local = false;
if iscuda
    if strncmp(type, 'emxArray_', 9)
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s*%s;', 'type', [varname '_buf = (' ...
            type '*)mxMalloc(sizeof(type));']), ...
            sprintf('    %-20s*%s;', 'void', 'data_gpu'), ...
            sprintf('    %-20s*%s;', 'int', 'size_gpu;'));
        cprefix = [varname '_buf->data[i].'];
    elseif hasArray
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s*%s;', 'type', [varname '_buf = (' ...
            type '*)mxMalloc(sizeof(type)' multiple ');']));
        cprefix = [varname '_buf[i].'];
    else
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s*%s;', 'type', [varname '_buf = (' ...
            type '*)mxMalloc(sizeof(type));']));
        cprefix = [varname '_buf->'];
    end
end

% Obtain the main loop body for each object
[loopBody, structDefs, useNDims, hasCuError_struct, hasAlias] = marshallin ...
    (structDefs.(type).fields, funcname, iscuda, structDefs, cprefix, mx_index, rw_mode, writeonly);

% Add loop if there are arrays
if strncmp(type, 'emxArray_', 9) || hasArray && ~isempty(strtrim(loopBody))
    decl_vars = sprintf('%s\n', decl_vars, ...
        sprintf('    %-20s %s;', 'int', 'i'));
    if strncmp(type, 'emxArray_', 9) || hasArray && ~writeonly
        decl_vars = sprintf('%s\n', decl_vars(1:end-1), ...
            sprintf('    %-20s %s;', 'int', 'nElems = mxGetNumberOfElements(mx);'));
    end

    funcBody = sprintf('%s\n', ...
        ['    for (i=0; i<nElems; ++i) {', ...
        regexprep(loopBody(1:end-1), '\n    ', '\n        ')], ...
        '    }');
else
    funcBody = loopBody;
end

% Allocate memory
if strncmp(type, 'emxArray_', 9)
    funcBody = sprintf('%s\n', '', ...
        ['    alloc_emxArray_from_mxArray(mx, (emxArray__common*)pEmx, mname, dim, sizeof(' basetype '));'], ...
        funcBody(1:end-1));
elseif iscuda
    funcBody = sprintf('%s\n', ...
        ['    _ierr = cudaMalloc(&' varname ', sizeof(' type ')' multiple ');'], ...
        '    CHKCUERR(_ierr, "cudaMalloc");', ...
        funcBody, '', ...
        ['    _ierr = cudaMemcpy(' varname ', ' varname '_buf, sizeof(' type ')' ...
        multiple '), cudaMemcpyHostToDevice);'], ...
        '    CHKCUERR(_ierr, "cudaMemcpy");');
    hasCuError_local = true;
end

if useNDims
    decl_vars = sprintf('%s\n    %-20s _nDims;', decl_vars, 'int32_T');
end
if hasCuError_local || hasCuError_struct
    decl_vars = sprintf('%s%s\n', decl_vars, ...
        sprintf('    %-20s %s;', 'cudaError_t', '_ierr'));
end

% Deallocate local buffer for CUDA
if iscuda
    dealloc = sprintf('%s\n', ['    mxFree(' varname '_buf);']);
else
    dealloc = '';
end

if ~rw_mode && ~hasAlias && ~writeonly
    structDefs.(type).(funcField) = [];
    funcField = regexprep(funcField, '^marshallinConst', 'marshallin');
    funcname = regexprep(funcname, '^marshallin_const_', 'marshallin_');
end

if ~isempty(strtrim(funcBody))
    func = sprintf('%s\n', '', ...
        ['static ' return_type funcname '(' args ') {'], ...
        decl_vars, '', str_chk, [funcBody, dealloc, return_str], ...
        '}');

    structDefs.(type).(funcField) = regexprep(func, '\n\n', '\n');
else
    assert(strncmp(funcname, 'prealloc_', 9));
    % No preallocation needed for the given structure
    funcname = '';
    structDefs.(type).(funcField) = ' ';
end

end
