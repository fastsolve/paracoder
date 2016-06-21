function [str, structDefs, maxDim, hasCuError] = marshallout(vars, pruned_vars, iscuda, ...
    structDefs, cprefix, mx_index, readonly)
% Marshall function output arguments.
% In readonly, the variables are readonly and are not marshallled out.

if nargin<6; 
    cprefix = ''; 
    mx_index = [];
    readonly = false;
end

str=char(10);

maxDim = false;
hasCuError = false;

for i=1:length(vars)
    var = vars(i);
    if isempty(cprefix) && isempty(var.iindex) && isempty(var.oindex)
        continue;
    end
    
    readonly_var = readonly || isempty(cprefix) && isempty(var.oindex);
    j = var.oindex;
    cvarname = [cprefix var.cname];
    
    if isempty(cprefix)
        if ~readonly_var
            lhs = ['plhs[' num2str(j-1) '] = '];
        else
            lhs = '';
        end
        if ~isempty(var.iindex)
            rhs = ['prhs[' num2str(var.iindex-1) ']'];
        else
            rhs = '';
        end
        
        closeParen = '';

        if ~iscuda && (strncmp(var.type, 'emxArray_', 9) || prod(var.size)==1 && ...
                ~var.vardim && (~isempty(var.subfields) || isempty(var.modifier)))
            cvarname_ptr = ['&' cvarname];
        else
            cvarname_ptr = cvarname;
        end
    else
        if ~readonly_var && ~readonly_var
            lhs = ['mxSetField(mx, ' mx_index ', "' var.mname '", '];
            closeParen = ')';
        else
            lhs = '';
            closeParen = '';
        end
        if iscuda
            rhs = ['mxGetField(mx_in, ' mx_index  ', "' var.mname '")'];
        else
            rhs = '';
        end
        
        if isempty(var.modifier)
            cvarname_ptr = ['&' cvarname];
        else
            cvarname_ptr = cvarname;
        end
    end

    if ~isempty(var.subfields)
        hasArray = ~strncmp(var.type, 'emxArray_', 9) && (prod(var.size)>1 || any(var.vardim));
        [marshalloutFuncName, structDefs] = gen_marshalloutFunc(structDefs, var.type, ...
            hasArray, iscuda, readonly_var);
    end

    str_gpu = '';
    str_mx = '';
    
    if isequal(var.type, ['emxArray_', var.basetype]) || ...
            isequal(var.type, ['emxArray_', var.structname])
        % Case 1: A full emxArray
        if ~iscuda
            if ~isempty(var.subfields)
                if ~isempty(marshalloutFuncName)
                    str = sprintf('%s%s\n', str, ...
                        ['    ' lhs marshalloutFuncName '(' cvarname_ptr ')' closeParen ';']);
                end
            else
                if ~readonly_var
                    str = sprintf('%s\n', str(1:end-1), ...
                        ['    ' lhs 'move_emxArray_to_mxArray((emxArray__common*)(' ...
                        cvarname_ptr '), ' getMxClassID(var.basetype) closeParen ');']);
                    if cvarname_ptr(1) == '&'
                        str = sprintf('%s\n', str(1:end-1), ...
                            ['    mxFree(' cvarname '.size);']);
                    else
                        str = sprintf('%s\n', str(1:end-1), ...
                            ['    mxFree(' cvarname '->size);']);
                    end
                else
                    str = sprintf('%s\n', str(1:end-1), ...
                        ['    free_emxArray((emxArray__common*)(' cvarname_ptr '));']);
                end
                if ~isempty(cprefix)
                    str = sprintf('%s\n', str(1:end-1), ...
                        ['    mxFree(' cvarname_ptr ');'], '', '');
                end
            end
        else
            if ~isempty(var.subfields)
                if ~isempty(marshalloutFuncName)
                    str = sprintf('%s%s\n', str, ...
                        ['    ' lhs marshalloutFuncName '(' cvarname_ptr ', ' rhs ')' closeParen ';']);
                end
            elseif ~readonly_var
                str_gpu = sprintf('%s\n', str_gpu, ...
                    ['        ' lhs 'move_gpuEmxArray_to_gpuPointer(' ...
                    cvarname_ptr ', ' rhs closeParen ');']);
                str_mx = sprintf('%s%s\n', str_mx, ...
                    ['        ' lhs 'move_gpuEmxArray_to_mxArray(' ...
                    cvarname_ptr ', ' getMxClassID(var.basetype) ')' closeParen ';']);
            else
                str = sprintf('%s%s\n', str, ...
                    ['    destroy_gpuEmxArray(' cvarname_ptr ');']);
            end
        end
    elseif var.isemx && (isempty(var.sizefield) || isempty(var.modifier))
        % Case 2. A reduced emxArray with only data and size fields
        assert(~isempty(cprefix));
            
        if ~readonly_var && ~iscuda
            str = sprintf('%s%s\n', str, ...
                ['    ' lhs 'copy_array_to_mxArray(' ...
                cvarname '.data, ' getMxClassID(var.basetype) ', ' ...
                num2str(length(var.size)) ', ' cvarname, '.size)' closeParen ';']);
        elseif ~readonly_var
            str_gpu = sprintf('%s\n', str_gpu, ...
                ['        ' lhs 'move_gpuSize_to_gpuPointer(' num2str(length(var.size)) ', ' ...
                cvarname '.size, ' rhs closeParen ');']);
            str_mx = sprintf('%s%s\n', str_mx, ...
                ['        ' lhs 'move_gpuDataSize_to_mxArray(' ...
                cvarname '.data, ' num2str(length(var.size)) ', ' ...
                cvarname '.size, ' getMxClassID(var.basetype) ');']);
        elseif iscuda && isempty(cprefix)
            str_gpu = sprintf('%s%s\n', str_gpu, ...
                ['        destroy_gpuEmxArray_reduced(' cvarname_ptr ', false);']);
            str_mx = sprintf('%s%s\n', str_mx, ...
                ['        destroy_gpuEmxArray_reduced(' cvarname_ptr ', true);']);
        elseif isempty(cprefix)
            str = sprintf('%s%s\n', str, ...
                ['    /* Nothing to be done for ' var.mname ' */']);
        end
    elseif var.isemx && ~isempty(var.sizefield) && isnumeric(var.sizefield)
        % Case 3. emxArray split into _data and _size arguments
        if ~iscuda
            if ~isempty(var.subfields)
                if ~readonly_var
                    args = [cvarname_ptr ', ' num2str(length(var.size)) ', ' ...
                        cprefix vars(var.sizefield).cname];                    
                    str = sprintf('%s\n', str(1:end-1), ...
                        ['    ' lhs marshalloutFuncName '(' args ')' closeParen ';']);
                elseif ~isempty(marshalloutFuncName)
                    args = [cvarname_ptr ', ' num2str(prod(var.size))];
                    str = sprintf('%s\n', str(1:end-1), ...
                        ['    ' lhs marshalloutFuncName '(' args ')' closeParen ';']);
                end
                if isempty(cprefix) && prod(var.size)>1 || var.vardim
                    str = sprintf('%s%s\n', str, ...
                        ['    mxFree(' cvarname_ptr ');']);
                end
            elseif ~readonly_var
                if ~isempty(cprefix)
                    copyFunc = 'copy_array_to_mxArray';
                else
                    copyFunc = 'move_array_to_mxArray';
                end
                str = sprintf('%s%s\n', str, ...
                    ['    ' lhs copyFunc '(' ...
                    cvarname_ptr ', ' getMxClassID(var.basetype) ', ' ...
                    num2str(vars(var.sizefield).size) ', ' ...
                    cprefix vars(var.sizefield).cname closeParen ');']);
            elseif isempty(cprefix) && (var.iscomplex || isequal(var.basetype, 'char_T'))
                str = sprintf('%s%s\n', str, ...
                    ['    mxFree(' cvarname_ptr ');']);
            elseif ~isempty(cprefix)
                str = sprintf('%s%s\n', str, ...
                    ['    /* Nothing to be done for ' var.mname ' */']);
            end
        else
            if ~isempty(var.subfields)
                assert(false);
            elseif ~readonly_var
                str_gpu = sprintf('%s\n', str_gpu, ...
                    ['        ' lhs 'move_gpuSize_to_gpuPointer(' num2str(length(var.size)) ', ' ...
                    cprefix vars(var.sizefield).cname ', ' rhs closeParen ');']);
                str_mx = sprintf('%s\n', str_mx, ...
                    ['        ' lhs 'move_gpuDataSize_to_mxArray(' ...
                    cvarname_ptr ', ' num2str(length(var.size)) ', ' ...
                    cprefix vars(var.sizefield).cname ', ' getMxClassID(var.basetype) ');']);
            elseif isempty(cprefix)
                str = sprintf('%s\n', str, ...
                    ['    _ierr = cudaFree(' cprefix vars(var.sizefield).cname '); CHKCUERR(_ierr, "cudaFree");']);
                str_mx = sprintf('%s\n', str_mx, ...
                    ['        _ierr = cudaFree(' cvarname_ptr '); CHKCUERR(_ierr, "cudaFree");']);
                hasCuError = true;
            end
        end
    elseif var.isemx || prod(var.size)~=1 || any(var.vardim) || ...
            ~isempty(var.modifier) && ~isempty(var.oindex) && ...
            (isempty(var.subfields) || ~isequal(var.size, 1) || any(var.vardim))
        % Case 4: emxArray simplified to _data without _size field
        if ~iscuda
            if ~isempty(var.subfields)
                if ~readonly_var
                    maxDim = max(maxDim, length(var.size));
                    for k = 1:length(var.size)
                        str = sprintf('%s\n', str(1:end-1), ...
                            ['    _dims[' num2str(k-1) '] = ' num2str(var.size(k)) ';']);
                    end

                    args = [cvarname_ptr ', ' num2str(length(var.size)) ', _dims'];                    
                    str = sprintf('%s\n', str(1:end-1), ...
                        ['    ' lhs marshalloutFuncName '(' args ')' closeParen ';']);
                elseif ~isempty(marshalloutFuncName)
                    args = [cvarname_ptr ', ' num2str(prod(var.size))];
                    str = sprintf('%s\n', str(1:end-1), ...
                        ['    ' lhs marshalloutFuncName '(' args ')' closeParen ';']);
                end
                if isempty(cprefix) && prod(var.size)>1 || var.vardim
                    str = sprintf('%s%s\n', str, ...
                        ['    mxFree(' cvarname_ptr ');']);
                end                
            elseif ~readonly_var
                if ~isempty(rhs)
                    str = sprintf('%s%s\n', str, ...
                        ['    ' lhs 'move_ioArray_to_mxArray(' cvarname_ptr ', ' ...
                        getMxClassID(var.basetype) ', ' rhs closeParen ');']);
                elseif prod(var.size)==1 && ~var.vardim
                    if ~isempty(cprefix)
                        copyFunc = 'copy_scalar_to_mxArray';
                    else
                        copyFunc = 'move_scalar_to_mxArray';
                    end
                    str = sprintf('%s\n', str, ...
                        ['    ' lhs copyFunc '(' cvarname_ptr ', ' ...
                        getMxClassID(var.basetype) closeParen ');']);
                else
                    if ~isempty(cprefix)
                        copyFunc = 'copy_array_to_mxArray';
                    else
                        copyFunc = 'move_array_to_mxArray';
                    end
                    
                    maxDim = max(maxDim, length(var.size));
                    for k = 1:length(var.size)
                        str = sprintf('%s\n', str(1:end-1), ...
                            ['    _dims[' num2str(k-1) '] = ' num2str(var.size(k)) ';']);
                    end
                    
                    str = sprintf('%s\n', str, ...
                        ['    ' lhs copyFunc '(' cvarname_ptr ', ' ...
                        getMxClassID(var.basetype) ', ' num2str(length(var.size)) ', _dims' closeParen ');']);
                end
            elseif isempty(cprefix) && (var.iscomplex || isequal(var.basetype, 'char_T'))
                str = sprintf('%s%s\n', str, ...
                    ['    mxFree(' cvarname_ptr ');']);
            elseif isempty(cprefix)
                str = sprintf('%s%s\n', str, ...
                    ['    /* Nothing to be done for ' var.mname ' */']);
            end
        else
            if ~isempty(var.subfields)
                assert(false);
            elseif ~readonly_var
                str_gpu = sprintf('%s\n', str_gpu, ...
                    ['        ' lhs 'mxDuplicateArray(' rhs closeParen ');']);
                str_mx = sprintf('%s%s\n', str_mx, ...
                    ['        ' lhs 'move_gpuArray_to_mxArray(' ...
                    cvarname_ptr ', ' rhs closeParen ');']);
            elseif isempty(cprefix)
                str_mx = sprintf('%s%s\n', str_mx, ...
                    ['        _ierr = cudaFree(' cvarname_ptr '); CHKCUERR(_ierr, "cudaFree");']);
                hasCuError = true;
            end
        end        
    else
        if ~isempty(var.subfields)
            if ~isempty(marshalloutFuncName)
                str = sprintf('%s%s\n', str, ...
                    ['    ' lhs marshalloutFuncName '(' cvarname_ptr ')' closeParen ';']);
            end
        elseif ~readonly_var && (~isempty(cprefix) || ~isempty(var.oindex))
            str = sprintf('%s%s\n', str, ...
                ['    ' lhs 'copy_scalar_to_mxArray(' cvarname_ptr, ', '...
                getMxClassID(var.basetype) closeParen ');']);
        elseif readonly_var && iscuda
            if isempty(cprefix) && ~isempty(var.modifier)
                % Need to deallocate size field on CUDA
                str = sprintf('%s%s\n', str, ...
                    ['    _ierr = cudaFree(' cvarname_ptr '); CHKCUERR(_ierr, "cudaFree");']);
                hasCuError = true;
            elseif ~isempty(var.modifier)
                str_mx = sprintf('%s\n', str_mx, ...
                    ['        _ierr = cudaFree(' cvarname_ptr '); CHKCUERR(_ierr, "cudaFree");']);
                hasCuError = true;
            end
        elseif isempty(cprefix)
            str = sprintf('%s%s\n', str, ...
                ['    /* Nothing to be done for ' var.mname ' */']);
        end
    end
    
    if ~isempty(str_gpu) && ~isempty(str_mx)
        assert(~isempty(rhs));
        str = sprintf('%s\n', str, ...
            ['    if (mxIsClass(' rhs ', "m2c_gpuArray")) {'], ...
            str_gpu, ...
            '    } else {', ...
            str_mx, ...
            '    }');
    elseif ~isempty(str_mx)
        assert(~isempty(rhs));
        str = sprintf('%s\n', str, ...
            ['    if (!mxIsClass(' rhs ', "m2c_gpuArray")) {'], ...
            str_mx, ...
            '    }');
    elseif ~isempty(str_gpu)
        assert(~isempty(rhs));
        str = sprintf('%s\n', str, ...
            ['    if (mxIsClass(' rhs ', "m2c_gpuArray")) {'], ...
            str_gpu, ...
            '    }');
    end
end

% Process pruned variables
for i=1:length(pruned_vars)
    var = pruned_vars(i);    
    str = sprintf('%s\n', str, ...
        ['    /* Creating empty mxArray for pruned variable ' var.mname ' */']);

    maxDim = max(maxDim, length(var.size));
    for k = 1:length(var.size)
        str = sprintf('%s\n', str(1:end-1), ...
            ['    _dims[' num2str(k-1) '] = ' num2str(var.size(k)) ';']);
    end

    str = sprintf('%s\n', str, ...
        ['    plhs[' num2str(pruned_vars(i).oindex-1) '] = copy_array_to_mxArray(NULL, ' ...
        'mx' upper(var.type) '_CLASS, ' num2str(length(var.size)) ', _dims);']);
end

if isempty(cprefix) && ~isempty(str)
    str = ['    /* Deallocate input and marshall out function outputs */', ...
        regexprep(str, '\n\n', '\n')];
end

end

function [funcname, structDefs] = gen_marshalloutFunc(structDefs, type, ...
    hasArray, iscuda, readonly)
% Generate function for marshalloutg out a struct or an array of struct objects.
% It may recursively generate additional marshallout functions for other structs.

if hasArray && ~readonly
    funcField = 'marshalloutArrayFunc';
    funcname = ['marshallout_'  type '_Array'];
elseif ~readonly
    funcField = 'marshalloutFunc';
    funcname = ['marshallout_'  type];
elseif hasArray
    funcField = 'destroyArrayFunc';
    funcname = ['destroy_' type '_Array'];
else
    funcField = 'destroyFunc';
    funcname = ['destroy_' type];
end

if isempty(structDefs.(type).(funcField))
    structDefs.(type).(funcField) = ...
        '/* Set it to nonempty to prevent the same function being created again */';
else
    if isempty(strtrim(structDefs.(type).(funcField)))
        % A deallocation routine may be empty
        assert(strncmp(funcname, 'destroy_', 8));
        funcname = '';
    end
    return;
end

if ~readonly
    fieldstr = sprintf(', "%s"', structDefs.(type).fields.mname);
    decl_vars = sprintf('    %-20s %s;', 'const char', ['*fields[] = {' fieldstr(3:end) '}']);
else
    decl_vars = '';
end

if strncmp(type, 'emxArray_', 9)
    varname = 'pEmx';
    args = [type ' *' varname];
    if ~readonly
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'mxArray', ...
            ['*mx = create_struct_mxArray(pEmx->numDimensions, pEmx->size, ' ...
            num2str(length(structDefs.(type).fields)) ', fields)']), ...
            sprintf('    %-20s %s;', 'int', 'nElems = mxGetNumberOfElements(mx)'));
    else
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'int', 'nElems = numElements(pEmx->numDimensions, pEmx->size)'));
    end
    
    mx_index = 'i';
    decl_vars = sprintf('%s\n', decl_vars, ...
        sprintf('    %-20s %s;', 'int', 'i'));
    cprefix = 'pEmx->data[i].';
elseif hasArray
    varname = 'pArr';
    if ~readonly
        args = [type ' *' varname ', int nDims, const int *dims'];
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'mxArray', ['*mx = create_struct_mxArray(nDims, dims, ' ...
            num2str(length(structDefs.(type).fields)) ', fields)']));
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'int', 'nElems = numElements(nDims, dims)'));
    else        
        args = [type ' *' varname ', int nElems'];
    end
    
    mx_index = 'i';
    decl_vars = sprintf('%s\n', decl_vars, ...
        sprintf('    %-20s %s;', 'int', 'i'));
    cprefix = 'pArr[i].';
else
    varname = 'pStruct';
    if ~readonly
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'int', 'one=1'), ...
            sprintf('    %-20s %s;', 'mxArray', ['*mx = create_struct_mxArray(1, &one, ' ...
            num2str(length(structDefs.(type).fields)) ', fields)']));
    end
    
    args = [type ' *' varname];
    mx_index = '0';
    cprefix = 'pStruct->';
end

if iscuda
    decl_vars = [decl_vars ...
        sprintf('    %-20s %s;\n', 'mxArray', '*sub_mx')];
    if strncmp(type, 'emxArray_', 9)
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', type, 'pEmx_buf'), ...
            sprintf('    %-20s %s;', structDefs.(type).structname, '*data_gpu'), ...
            sprintf('    %-20s %s;', 'int', '*size_gpu'));
        if ~readonly
            decl_vars = sprintf('%s\n', decl_vars, ...
                '    copy_gpuEmxArray_to_emxArray(pEmx, pEmx_buf, &data_gpu, &size_gpu);');
        else
            decl_vars = sprintf('%s\n', decl_vars, ...
            '    get_gpuEmxArray_DataSize(pEmx, &data_gpu, &size_gpu);');
        end
        cprefix = 'pEmx_buf.data[i].';
    elseif hasArray
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', type, ['*pArr_buf = (' type '*)mxMalloc(sizeof(type) * nElems);']), ...
            ['    cudaStatus_T _ierr = cudaMemcpy(&pArr_buf, pStruct, sizeof(' type ...
            ') * nElems, cudaMemcpyDeviceToHost);'], ...
            '    CHKCUERR(_ierr, "cudaMemcpy");');
        cprefix = 'pArr_buf[i].';
    else
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', type, 'obj'));
        cprefix = 'obj.';
    end
end

[loopBody, structDefs, maxDim, hasCuError_struct] = marshallout(structDefs.(type).fields, [], iscuda, ...
    structDefs, cprefix, mx_index, readonly);

if maxDim
    decl_vars = sprintf('%s\n', decl_vars, ...
        sprintf('    %-20s %s;', 'int', ['_dims[' num2str(maxDim) ']']));
end

hasCuError_local = false;
if (strncmp(type, 'emxArray_', 9) || hasArray) && ~isempty(strtrim(loopBody))
    if iscuda
        % TO BE IMPLEMENTED
        assert(false);
    end
    % Add loop if there are arrays
    funcBody = sprintf('%s\n%s%s\n', ...
        '    for (i=0; i<nElems; ++i) {', ...
        regexprep(loopBody, '\n    ', '\n        '), ...
        '    }');
else
    if iscuda
        loopBody = sprintf('%s\n', ...
            ['    _ierr = cudaMemcpy(&obj, pStruct, sizeof(' type '), cudaMemcpyDeviceToHost);'], ...
            '    CHKCUERR(_ierr, "cudaMemcpy");', ...
            loopBody);
        hasCuError_local = true;
    end
    funcBody = loopBody;
end

if isequal(type, ['emxArray_', structDefs.(type).structname])
    dealloc = '    free_emxArray((emxArray__common *)pEmx);';
else
    dealloc = '';
end

if iscuda
    % Deallocate additional buffers created for CUDA
    if strncmp(type, 'emxArray_', 9)
        dealloc = sprintf('%s\n', dealloc, ...
            '    _ierr = cudaFree(data_gpu); CHKCUERR(_ierr, "cudaFree");', ...
            '    _ierr = cudaFree(size_gpu); CHKCUERR(_ierr, "cudaFree");', ...
            '    _ierr = cudaFree(pEmx); CHKCUERR(_ierr, "cudaFree");', ...
            '    mxFree(pEmx_buf.size);');
    elseif hasArray
        dealloc = sprintf('%s\n', dealloc, ...
            '    _ierr = cudaFree(pArr); CHKCUERR(_ierr, "cudaFree");', ...
            '    mxFree(pArr_buf);');
    else
        dealloc = sprintf('%s\n', dealloc, ...
            '    _ierr = cudaFree(pStruct); CHKCUERR(_ierr, "cudaFree");');
    end
end
    
if hasCuError_local || hasCuError_struct
    decl_vars = sprintf('%s%s\n', decl_vars, ...
        sprintf('    %-20s %s;', 'cudaError_t', '_ierr'));
end

if ~readonly
    return_val = 'mxArray *';
    return_mx = '    return mx;';
else
    return_val = 'void ';
    return_mx = '';
end

if ~isempty(strtrim(funcBody))
    func = sprintf('%s\n', '', ...
        ['static ' return_val funcname '(' args ') {'], ...
        decl_vars, '', [funcBody, dealloc], return_mx, ...
        '}');
    structDefs.(type).(funcField) = regexprep(func, '\n\n', '\n');
else
    assert(strncmp(funcname, 'destroy_', 8));
    % No deallocation needed for the given structure
    funcname = '';
    structDefs.(type).(funcField) = ' ';
end


end
