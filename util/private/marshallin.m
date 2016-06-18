function [str, structDefs, useDims, hasCuError, hasAlias] = marshallin(vars, ...
    funcname, iscuda, structDefs, cprefix, mx_index, rw_mode)
% Marshall function input arguments and preallocate output arguments.

if nargin<6
    cprefix = '';
    mx_index = 0;
    rw_mode = false;
end

str = '';
useDims = false;
hasCuError = false;
hasAlias = false;

for i=1:length(vars)
    var = vars(i);

    if isempty(cprefix) && isempty(var.iindex) && isempty(var.oindex)
        continue;
    end

    j = var.iindex;
    wmode_var = isempty(cprefix) && isempty(var.iindex) && ~isempty(var.oindex);
    rwmode_var = rw_mode || isempty(cprefix) && ~isempty(var.oindex) && ~isempty(var.iindex);
    
    str = sprintf('%s\n', str);
    cvarname = [cprefix var.cname];

    % Determine some shared variables
    if isempty(cprefix)
        if ~wmode_var
            rhs = ['prhs[' num2str(j-1) ']'];
        else
            rhs = '';
        end
        
        if ~iscuda
            cvarname_ptr = ['&' cvarname];
        else
            cvarname_ptr = cvarname;
        end
    else
        if ~isempty(cprefix) && ~wmode_var
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

    if wmode_var
        if iscuda
            if ~isequal(var.subfields) || ~isempty(var.modifier) && prod(var.size)>0
                % Preallocate the structures on GPU
                hasCuError = true;
                str = sprintf('%s%s\n%s\n', str, ...
                    ['    _ierr = cudaMalloc((void **)&' var.cname, ', ' ...
                    num2str(prod(var.size)) ' * sizeof(' var.type '));'], ...
                    '    CHKCUERR(_ierr);');
            else
                error('All varilable-size output arrays must also be input for CUDA kernel functions.');
            end
        elseif isequal(var.type, ['emxArray_', var.basetype])
            if isfield(structDefs, var.type) && structDefs.(var.type).hasInit
                str = sprintf('%s%s\n', str, ...
                    ['    emxInit_' var.type '(&' var.cname ');']);
            else
                str = sprintf('%s%s\n', str, ...
                    ['    init_emxArray((emxArray__common*)&' var.cname ', ' num2str(length(var.size)) ');']);
            end
        elseif ~isempty(var.subfields) || ~isempty(var.modifier) && prod(var.size)>0 && ~isequal(var.type, 'char_T')
            str = sprintf('%s\n', str, ...
                ['    {mwSize l_size[] = {', ...
                regexprep(strtrim(sprintf('%d ', var.size)), ' ', ', '), '};'], ...
                ['    *(void **)&' var.cname ' = prealloc_mxArray((mxArray**)&plhs[' ...
                num2str(var.oindex-1) '], ' getMxClassID(var.basetype) ', ' ...
                num2str(length(var.size)) ', l_size); }']);
        end
    elseif ~isempty(var.subfields)
        hasArray = ~strncmp(var.type, 'emxArray_', 9) && (prod(var.size)>1 || any(var.vardim));
        [marshallinFuncName, structDefs] = gen_marshallinFunc(structDefs, var.type, ...
            hasArray, iscuda, rwmode_var);

        if hasArray
            str = sprintf('%s%s', str, ...
                ['    ' marshallinFuncName '(' cvarname_ptr ', "' var.mname '", ' rhs ');']);
        else
            if ~isempty(var.sizefield) && ~ischar(var.sizefield)
                str = sprintf('%s%s', str, ...
                    ['    ' marshallinFuncName '(' cvarname_ptr ', ' ...
                    cprefix vars(var.sizefield).cname ', "' var.mname '", ' rhs ');']);
            else
                str = sprintf('%s%s', str, ...
                    ['    ' marshallinFuncName '(' cvarname_ptr ', "' var.mname '", ' rhs ');']);
            end
        end
    else
        errchk = sprintf('%s\n', ...
            ['if (mxGetNumberOfElements(' rhs ...
            ') && mxGetClassID(' rhs ') != ' getMxClassID(var.basetype) ') {'], ...
            ['        mexErrMsgIdAndTxt("' funcname ':WrongInputType",'],...
            ['            "Input argument ' var.mname ' has incorrect data type; ' ...
            getMatlabClass(var.basetype) ' is expected.");'],  '    }');
        
        if ~iscuda || isempty(var.modifier)
            str = sprintf('%s', str, ['    ' errchk]);
        else
            str = sprintf('%s\n', str, ...
                ['    _isGpuArray = mxIsClass(' rhs ', "m2c_gpuArray");'], ...
                ['    _dims = _isGpuArray ? (int*)mxGetData(mxGetFieldByNumber(' rhs ', 0, 2)) : NULL;'], ...
                '    if (_isGpuArray) {', ...
                '        char _type[64];', ...
                ['        mxGetString(mxGetFieldByNumber(' rhs ', 0, 1), _type, 64);'], ...
                ['        if (strcmp(_type, "' getMatlabClass(var.basetype) '"))'], ...
                ['            mexErrMsgIdAndTxt("' funcname ':WrongInputType",'],...
                ['                "Input argument ' var.mname ' has incorrect data type; ' ...
                getMatlabClass(var.basetype) ' is expected.");'], ...
                ['    } else ' errchk(1:end-1)]);
        end

        if var.isemx || prod(var.size)~=1 || any(var.vardim)
            useDims = length(var.size)>2 || iscuda;
            if ~iscuda && length(var.size)>2
                str = sprintf('%s\n', str, ...
                    ['    _nDims = mxGetNumberOfDimensions(' rhs ');']);
            elseif iscuda && length(var.size)>1
                str = sprintf('%s\n', str, ...
                    ['    _nDims = _isGpuArray ? mxGetNumberOfElements(mxGetFieldByNumber(' rhs ', 0, 2)) :'], ...
                    ['        mxGetNumberOfDimensions(' rhs ');']);
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
                        ['if (mxGetNumberOfElements(' rhs ') && ' dimerr_mx ') {'], ...
                        ['        mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                        ['            "Dimension ' num2str(k) ' of ' var.mname ...
                        ' should equal 1.");'], '    }');
                    if ~iscuda
                        str = sprintf('%s', str, ['    ' errchk]);
                    else
                        dimerr_gpu = ['_nDims>' num2str(k) ' && ' getdim_gpu ' != 1'];
                        str = sprintf('%s\n', str, ...
                            '    if (_isGpuArray) {', ...
                            ['        if (' dimerr_gpu ')'], ...
                            ['            mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                            ['                "Dimension ' num2str(k) ' of ' var.mname ...
                            ' should equal 1.");'], ...
                            ['    } else ' errchk(1:end-1)]);
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
                        ['if (mxGetNumberOfElements(' rhs ') && ' dimerr_mx ') {'], ...
                        ['        mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                        ['            "Dimension ' num2str(k) ' of ' var.mname ...
                        ' should equal ' num2str(var.size(k)) '.");'], '    }');
                    if ~iscuda
                        str = sprintf('%s', str, ['    ' errchk]);
                    else
                        str = sprintf('%s\n', str, ...
                            '    if (_isGpuArray) {', ...
                            ['        if (' dimerr_gpu ')'], ...
                            ['            mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                            ['                "Dimension ' num2str(k) ' of ' var.mname ...
                            ' should equal ' num2str(var.size(k)) '.");'], ...
                            ['    } else ' errchk(1:end-1)]);
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
                        ['if (mxGetNumberOfElements(' rhs ') && ' dimerr_mx ') {'], ...
                        ['        mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                        ['            "Dimension ' num2str(k) ' of ' var.mname ...
                        ' should be no greater than ' num2str(var.size(k)) '.");'], ...
                        '    }');
                    if ~iscuda
                        str = sprintf('%s', str, ['    ' errchk]);
                    else
                        str = sprintf('%s\n', str, ...
                            '    if (_isGpuArray) {', ...
                            ['        if (' dimerr_gpu  ')'], ...
                            ['            mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'], ...
                            ['                "Dimension ' num2str(k) ' of ' var.mname ...
                            ' should be no greater than ' num2str(var.size(k)) '.");'], ...
                            ['    } else ' errchk(1:end-1)]);
                    end
                end
            end
            
            % There are four cases for emxArrays:
            % Case 1: A full emxArray
            % Case 2: A reduced emxArray with only data and size fields
            % Case 3: emxArray split into _data and _size arguments (with two subcases)
            % Case 4: emxArray simplified to _data without _size field
            if isequal(var.type, ['emxArray_', var.basetype])
                % Case 1: A full emxArray
                if ~iscuda
                    if rwmode_var
                        copyFunc = 'copy_mxArray_to_emxArray';
                    else
                        copyFunc = 'alias_mxArray_to_emxArray';
                        hasAlias = true;
                    end
                    str = sprintf('%s%s\n', str, ...
                        ['    ' copyFunc '(' rhs ', (emxArray__common *)' ...
                        cvarname_ptr ', "' var.mname '", ' num2str(length(var.size)) ');']);
                else
                    str = sprintf('%s\n', str, ...
                        '    if (_isGpuArray)', ...
                        ['        ' cvarname ' = wrap_mxArray_to_gpuEmxArray<' var.type ', true>(' rhs ');'], ...
                        '    else', ...
                        ['        ' cvarname ' = copy_mxArray_to_gpuEmxArray<' var.type '>(' ...
                        rhs ', "' var.mname '", ' num2str(length(var.size)) ');']);
                end
            elseif var.isemx && (isempty(var.sizefield) || isempty(var.modifier))
                % Case 2. A reduced emxArray with only data and size fields
                if ~iscuda
                    str = sprintf('%s%s\n', str, ...
                        ['    copy_mxArray_to_DataSize(' rhs ', ' cvarname '.data, ' ...
                        cvarname '.size, ' num2str(length(var.size)) ', "' ...
                        var.mname '", ' num2str( prod(var.size)) ');']);
                else
                    str = sprintf('%s\n', str, ...
                        '    if (_isGpuArray)', ...
                        ['        ' cvarname ' = wrap_mxArray_to_gpuEmxArray<' var.type ', false>(' rhs ');'], ...
                        '    else ', ...
                        ['        ' cvarname ' = copy_mxArray_to_gpuEmxArrayStatic<' var.type '>(' rhs ...
                        ', ' num2str(length(var.size)) ', "' var.mname '", ' num2str( prod(var.size)) ');']);
                end
            elseif var.isemx && ~isempty(var.sizefield) && isnumeric(var.sizefield)
                % Case 3. emxArray split into _data and _size arguments
                if ~iscuda
                    if rwmode_var || ~any(var.vardim)
                        if any(var.vardim)
                            str = sprintf('%s%s\n', str, ...
                                ['    ' cvarname ' = mxMalloc(' num2str(prod(var.size)) ' * sizeof(' var.type '))']);
                        end
                        str = sprintf('%s%s\n', str, ...
                            ['    copy_mxArray_to_DataSize(' rhs ', (void **)&' cvarname ', ' ...
                            vars(var.sizefield).cname ', ' num2str(length(var.size)) ', "' ...
                            var.mname '", ' num2str(prod(var.size)) ');']);
                    else
                        str = sprintf('%s%s\n', str, ...
                            ['    alias_mxArray_to_DataSize(' rhs ', (void **)&' cvarname ', ' ...
                            vars(var.sizefield).cname ', ' num2str(length(var.size)) ', "' ...
                            var.mname '", ' num2str( prod(var.size)) ');']);
                        hasAlias = true;
                    end
                else
                    str = sprintf('%s\n', str, ...
                        '    if (_isGpuArray)', ...
                        ['        wrap_mxArray_to_gpuDataSize(&' cvarname_ptr ', &' ...
                        vars(var.sizefield).cname, ', ' rhs ');'], ...
                        '    else ', ...
                        ['        copy_mxArray_to_gpuDataSize(&' cvarname ', ', ...
                        num2str(length(var.size)) ', &' vars(var.sizefield).cname, ', ' rhs ');']);
                end
            else
                % Case 4: emxArray simplified to _data without _size field
                if ~iscuda && isequal(var.basetype, 'char_T')
                    str = sprintf('%s%s\n', str, ...
                        ['    mxGetString(' rhs ', ' cvarname ', ' num2str(prod(var.size)+1) ');']);
                elseif ~iscuda && ~isempty(cprefix) && ~any(var.vardim)
                    if rwmode_var || ~any(var.vardim)
                        if any(var.vardim)
                            str = sprintf('%s%s\n', str, ...
                                ['    ' cvarname ' = mxMalloc(' num2str(prod(var.size)) ' * sizeof(' var.type '))']);
                        end
                        str = sprintf('%s%s\n', str, ...
                            ['    copy_mxArray_to_DataSize(' rhs ', (void **)&' cvarname ', ' ...
                            'NULL, ' num2str(length(var.size)) ', "' ...
                            var.mname '", ' num2str(prod(var.size)) ');']);
                    else
                        str = sprintf('%s%s\n', str, ...
                            ['    alias_mxArray_to_DataSize(' rhs ', (void **)&' cvarname ', ' ...
                            'NULL, ' num2str(length(var.size)) ', "' ...
                            var.mname '", ' num2str( prod(var.size)) ');']);
                        hasAlias = true;
                    end
                elseif ~iscuda
                    if rwmode_var
                        assert(false); % Implement this one
                        str = sprintf('%s%s\n', str, ...
                            ['    ' cvarname ' = (' var.basetype '*)mxGetData(' rhs ');']);
                    else
                        str = sprintf('%s%s\n', str, ...
                            ['    ' cvarname ' = (' var.basetype '*)mxGetData(' rhs ');']);
                    end
                else
                    str = sprintf('%s\n', str, ...
                        '    if (_isGpuArray)', ...
                        ['        ' cvarname ' = *(' var.basetype ...
                        '**)mxGetData(mxGetFieldByNumber(' rhs ', 0, 0));'], ...
                        '    else', ...
                        ['        ' cvarname ' = copy_mxArray_to_gpuArray<' var.basetype '>(' rhs ...
                        ', "' var.mname '", ' num2str( length(var.size)) ');']);
                end
            end
        else
            str = sprintf('%s\n', str(1:end-1), ...
                ['    if (mxGetNumberOfElements(' rhs ') != 1)'], ...
                ['        mexErrMsgIdAndTxt("' funcname ':WrongSizeOfInputArg",'],...
                ['            "Argument ' var.mname ' should be a scalar.");']);
            if isempty(var.modifier)
                if isequal(var.type, 'char_T') || isequal(var.type, 'char')
                    % This is a single character, so we can simply cast it
                    str = sprintf('%s%s\n', str, ...
                        ['    ' cvarname ' = *(mxChar*)mxGetData(' rhs ');']);
                else
                    str = sprintf('%s%s\n', str, ...
                        ['    ' cvarname ' = *(' var.type '*)mxGetData(' rhs ');']);
                end
            else
                str = sprintf('%s\n', str, ...
                    ['    ' cvarname ' = (' var.type '*)mxGetData(' rhs ');']);
            end
        end
    end
end

if ~isempty(str) && isempty(cprefix)
    str = ['    /* Marshall in inputs and preallocate outputs */' str];
end

end

function [funcname, structDefs] = gen_marshallinFunc(structDefs, type, ...
    hasArray, iscuda, rw_mode)
% Generate function for marshalling in a struct or an array of struct objects. 
% It may recursively generate additional marshallin functions for other structs .

if ~iscuda && hasArray && rw_mode
    funcField = 'marshallinRWArrayFunc';
    funcname = ['marshallinRW_'  type '_Array'];
elseif ~iscuda && ~hasArray && rw_mode
    funcField = 'marshallinRWFunc';
    funcname = ['marshallinRW_'  type];
elseif hasArray && ~rw_mode
    funcField = 'marshallinArrayFunc';
    funcname = ['marshallin_'  type '_Array'];
else
    funcField = 'marshallinFunc';
    funcname = ['marshallin_'  type];
end

if isempty(structDefs.(type).(funcField))
    structDefs.(type).(funcField) = ...
        '/* Set it to nonempty to prevent the same function being created again */';
else
    if isnumeric(structDefs.(type).(funcField))
        funcname = regexprep(funcname, '^marshallinRW_', 'marshallin_');
    end
    return;
end

% Check struct type and fields
str_chk = '';
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

decl_vars = sprintf('    %-20s %s;', 'mxArray', '*sub_mx');
if strncmp(type, 'emxArray_', 9)
    assert(isequal(type, ['emxArray_', structDefs.(type).structname]));
    varname = 'pArr';
    args = [type ' *' varname ', const char *mname, const mxArray *mx'];
    
    decl_vars = sprintf('%s\n', decl_vars, ...
        sprintf('    %-20s %s;', 'int', 'i'), ...
        ['    init_emxArray_from_mxArray(mx, (emxArray__common*)pArr, mname, ' ...
        num2str(length(structDefs.(type).fields)) ' , sizeof(' structDefs.(type).data.type '));']);
    mx_index = 'i';
    cprefix = 'pArr->data[i].';
elseif hasArray
    varname = 'pArr';
    args = [type ' *' varname ', int * size, const char *mname, const mxArray *mx'];
    decl_vars = sprintf('%s\n', decl_vars, ...
        sprintf('    %-20s %s;', 'int', 'i'));
    mx_index = 'i';
    cprefix = 'pArr[i].';
else
    varname = 'pStruct';
    args = [type ' *' varname ', const char *mname, const mxArray *mx'];
    mx_index = '0';
    cprefix = 'pStruct->';
end

% TODO: Copy data and size from mxArray
if iscuda
    if strncmp(type, 'emxArray_', 9)
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', type, 'pArr_buf'), ...
            sprintf('    %-20s %s;', 'void', '*data_gpu'), ...
            sprintf('    %-20s %s;', 'int', '*size_gpu;'), ...
            '    copy_gpuEmxArray_to_emxArray(pArr, pArr_buf, &data_gpu, &size_gpu);');
        cprefix = 'pArr_buf[i].';
    elseif hasArray
        decl_vars = sprintf('%s\n', decl_vars, ...
            ['    ' type '    *pArr_buf = (' type '*)mxMalloc(sizeof(type) * nElems);'], ...
            ['    cudaStatus_T ierr = cudaMemcpy(&pArr_buf, pStruct, sizeof(' type ...
            ') * nElems, cudaMemcpyDeviceToHost);'], ...
            '    CHKCUERR(ierr, "cudaMemcpy");;');
        cprefix = 'pArr_buf[i].';
    else
        decl_vars = sprintf('%s\n', decl_vars, ...
            ['    ' type '    obj;'], ...
            ['    cudaStatus_T ierr = cudaMemcpy(&obj, pStruct, sizeof(' type ...
            ')' times ', cudaMemcpyDeviceToHost);'], ...
            '    CHKCUERR(ierr, "cudaMemcpy");;');
        cprefix = 'obj.';
    end
end

% Obtain the main function body for 
[loopBody, structDefs, useDims, hasCuError, hasAlias] = marshallin(structDefs.(type).fields, funcname, ...
    iscuda, structDefs, cprefix, mx_index, rw_mode);

if strncmp(type, 'emxArray_', 9) || hasArray
    if structDefs.(type).hasInit
        loopBody = ['    emxInit_' type '(&' cprefix(1:end-1) ');' char(10) loopBody];
    end
    % Add loop if there are arrays
    funcBody = sprintf('%s\n%s\n%s%s\n', ...
        '    for (i=0; i<nElems; ++i) {', ...
        regexprep(loopBody, '\n    ', '\n        '), ...
        '    }');
else
    if structDefs.(type).hasInit
        loopBody = ['    emxInit_' type '(pStruct);' char(10) loopBody];
    end
    funcBody = loopBody;
end

if useDims
    decl_vars = sprintf('%s\n    %-20s _nDims;', decl_vars, 'int32_T');
end
if iscuda
    decl_vars = sprintf('%s\n    %-20s *_dims;\n    %-20s _isGpuArray;',...
        decl_vars, 'int32_T', 'int32_T');
    if hasCuError
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'cudaError_t', '_ierr'));
    end
end

dealloc = '';

if ~rw_mode && ~hasAlias
    funcField_RW = strrep(funcField, 'marshallin', 'marshallinRW');
    funcname_RW = regexprep(funcname, '^marshallin', 'marshallinRW');
    structDefs.(funcname_RW).(funcField_RW) = [];
end

func = sprintf('%s\n', '', ...
    ['static void ' funcname '(' args ') {'], ...
    decl_vars, [str_chk, funcBody, dealloc], ...
    '}');

structDefs.(type).(funcField) = func;

end
