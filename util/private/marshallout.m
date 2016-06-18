function [str, structDefs, hasDim, hasCuError] = marshallout(vars, pruned_vars, iscuda, ...
    structDefs, cprefix, mx_index, readonly_mode)
% Marshall function output arguments.
% In readonly_mode, the variables are readonly and are not marshallled out.

if nargin<6; 
    cprefix = ''; 
    mx_index = [];
    readonly_mode = false;
end

str=char(10);

hasDim = false;
hasCuError = false;

for i=1:length(vars)
    var = vars(i);
    if isempty(cprefix) && isempty(var.iindex) && isempty(var.oindex)
        continue;
    end
    
    rmode_var = readonly_mode || isempty(cprefix) && isempty(var.oindex);
    j = var.oindex;
    cvarname = [cprefix var.cname];
    
    if isempty(cprefix)
        if ~rmode_var
            lhs = ['plhs[' num2str(j-1) '] = '];
        else
            lhs = '';
        end
        if ~isempty(var.iindex) && ~rmode_var
            rhs = ['prhs[' num2str(var.iindex-1) ']'];
        else
            rhs = '';
        end
        
        closeParen = '';
        if ~iscuda
            cvarname_ptr = ['&' cvarname];
        else
            cvarname_ptr = cvarname;
        end
    else
        if ~rmode_var && ~rmode_var
            lhs = ['mxSetField(mx, ' mx_index ', "' var.mname '", '];
            closeParen = ')';
        else
            lhs = '';
            closeParen = '';
        end
        if iscuda && ~rmode_var
            str = sprintf('%s\n', str, ...
                ['    sub_mx = mxGetField(mx, ' mx_index  ', "' var.mname '")']);
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
    
    if ~isempty(var.subfields)
        hasArray = ~strncmp(var.type, 'emxArray_', 9) && (prod(var.size)>1 || any(var.vardim));
        [marshalloutFuncName, structDefs] = gen_marshalloutFunc(structDefs, var.type, ...
            hasArray, iscuda, rmode_var);

        if ~hasArray || rmode_var
            str = sprintf('%s%s\n', str, ...
                ['    ' lhs marshalloutFuncName '(' cvarname_ptr ')' closeParen ';']);
        elseif ~isempty(var.sizefield) && ~ischar(var.sizefield)
            args = [cvarname_ptr ', ' num2str(var.size) ', ' ...
                cprefix vars(var.sizefield).cname];
            str = sprintf('%s%s\n', str, ...
                ['    ' lhs marshalloutFuncName '(' args ')' closeParen ';']);
        else
            sizes = sprintf(', %d', var.size);
            args = [cvarname_ptr ', ' num2str(var.size) ', _dims'];
            
            str = sprintf('%s\n', str(1:end-1), ...
                ['    {int _dims[] = {' sizes(3:end) '};'], ...
                ['    ' lhs marshalloutFuncName '(' args ')' closeParen '; }']);
        end
    elseif isequal(var.type, ['emxArray_', var.basetype])
        % Case 1: A full emxArray
        if ~rmode_var && ~iscuda
            str = sprintf('%s\n', str(1:end-1), ...
                ['    ' lhs 'move_emxArray_to_mxArray((emxArray__common*)' ...
                cvarname_ptr ', ' getMxClassID(var.basetype) closeParen ');']);
        elseif ~rmode_var
            str = sprintf('%s\n', str, ...
                ['    if (!mxIsClass(' rhs ', "m2c_gpuArray"))'], ...0
                ['        ' lhs 'move_gpuEmxArray_to_mxArray(' ...
                cvarname_ptr ', ' getMxClassID(var.basetype) ')' closeParen ';'], ...
                '    else', ...
                ['        ' lhs 'move_gpuEmxArray_to_gpuPointer(' ...
                cvarname_ptr ', ' rhs closeParen ');']);
        elseif ~iscuda
            str = sprintf('%s%s\n', str, ...
                ['    free_emxArray((emxArray__common*)' cvarname_ptr ');']);
        else
            str = sprintf('%s%s\n', str, ...
                ['    destroy_gpuEmxArray<' var.type ', true>(' cvarname_ptr ');']);
        end
    elseif var.isemx && (isempty(var.sizefield) || isempty(var.modifier))
        % Case 2. A reduced emxArray with only data and size fields
        if ~rmode_var && ~iscuda
            str = sprintf('%s%s\n', str, ...
                ['    ' lhs 'copy_array_to_mxArray(' ...
                cvarname '.data, ' getMxClassID(var.basetype) ', ' ...
                num2str(length(var.size)) ', ' cvarname, '.size)' closeParen ';']);
        elseif ~rmode_var
            str = sprintf('%s\n', str(1:end-1), ...
                ['    if (!mxIsClass(' rhs ', "m2c_gpuArray"))'], ...
                ['        ' lhs 'move_gpuDataSize_to_mxArray(' ...
                cvarname '.data, ' num2str(length(var.size)) ', ' ...
                cvarname '.size, ' getMxClassID(var.basetype) ');'], ...
                '    else', ...
                ['        ' lhs 'move_gpuSize_to_gpuPointer(' num2str(length(var.size)) ', ' ...
                cvarname '.size, ' rhs closeParen ');']);
        elseif iscuda && isempty(cprefix)
            str = sprintf('%s%s\n', str, ...
                ['    destroy_gpuEmxArray<' var.type ', false>('  cvarname_ptr ');']);
        else
            str = sprintf('%s%s\n', str, ...
                ['    /* Nothing to be done for ' var.mname ' */']);
        end
    elseif var.isemx && ~isempty(var.sizefield) && isnumeric(var.sizefield)
        % Case 3. emxArray split into _data and _size arguments
        if ~rmode_var && ~iscuda
            str = sprintf('%s%s\n', str, ...
                ['    ' lhs 'copy_array_to_mxArray(' ...
                cvarname_ptr ', ' getMxClassID(var.basetype) ', ' ...
                num2str(vars(var.sizefield).size) ', ' ...
                cprefix vars(var.sizefield).cname closeParen ');']);
        elseif ~rmode_var
            str = sprintf('%s\n', str, ...
                ['    if (!mxIsClass(' rhs ', "m2c_gpuArray"))'], ...
                ['        ' lhs 'move_gpuDataSize_to_mxArray(' ...
                cvarname_ptr ', ' num2str(length(var.size)) ', ' ...
                cprefix vars(var.sizefield).cname ', ' getMxClassID(var.basetype) ');'], ...
                '    else', ...
                ['        ' lhs 'move_gpuSize_to_gpuPointer(' num2str(length(var.size)) ', ' ...
                cprefix vars(var.sizefield).cname ', ' rhs closeParen ');']);
        elseif iscuda && isempty(cprefix)
            str = sprintf('%s\n%s', str, ...
                ['    _ierr = cudaFree(' cvarname_ptr '); CHKCUERR(_ierr);'], ...
                ['    _ierr = cudaFree(' cprefix vars(var.sizefield).cname '); CHKCUERR(_ierr);']);
            hasCuError = true;
        elseif any(var.vardim)
            str = sprintf('%s%s\n', str, ...
                ['    mxFree(' cvarname_ptr ');']);
        else
            str = sprintf('%s%s\n', str, ...
                ['    /* Nothing to be done for ' var.mname ' */']);
        end
    elseif var.isemx || prod(var.size)~=1 || any(var.vardim)
        % Case 4: emxArray simplified to _data without _size field
        if ~rmode_var && ~iscuda
            if any(var.vardim)
                assert(isempty(var.modifier));
                str = sprintf('%s%s\n', str, ...
                    ['    ' lhs 'copy_array_to_mxArray(' ...
                    cvarname '.data, ' getMxClassID(var.basetype) ', ' ...
                    num2str(length(var.size)) ', ' cvarname '.size' closeParen ');']);
            elseif length(var.size)>1
                str = sprintf('%s\n', str, ...
                    '    {', ...
                    ['        int _dims[] = {' regexprep(strtrim(sprintf('%d ', var.size)), ' ', ', '), '};'], ...
                    ['        ' lhs 'copy_array_to_mxArray(' cvarname_ptr ', ' ...
                    getMxClassID(var.basetype) ', ' num2str(length(var.size)) ', _dims' closeParen ');'], ...
                    '    }');
            else
                hasDim = true;
                str = sprintf('%s\n', str(1:end-1), ...
                    ['    _dim = ' num2str(var.size) ';'], ...
                    ['    ' lhs 'copy_array_to_mxArray(' cvarname_ptr ', ' ...
                    getMxClassID(var.basetype) ', ' num2str(length(var.size)) ', &_dim' closeParen ');']);
            end
        elseif ~rmode_var
            str = sprintf('%s\n', str, ...
                ['    if (!mxIsClass(' rhs ', "m2c_gpuArray"))'], ...
                ['        ' lhs 'move_gpuArray_to_mxArray(' ...
                cvarname_ptr ', ' rhs closeParen ');'], ...
                '    else', ...
                ['        ' lhs 'mxDuplicateArray(' rhs closeParen ');']);
        elseif iscuda && isempty(cprefix)
            str = sprintf('%s%s\n', str, ...
                ['    _ierr = cudaFree(' cvarname_ptr '); CHKCUERR(_ierr);']);
            hasCuError = true;
        elseif any(var.vardim)
            str = sprintf('%s%s\n', str, ...
                ['    mxFree(' cvarname_ptr ');']);
        else
            str = sprintf('%s%s\n', str, ...
                ['    /* Nothing to be done for ' var.mname ' */']);
        end        
    elseif ~rmode_var && isempty(var.modifier)
        str = sprintf('%s%s\n', str, ...
            ['    ' lhs 'copy_scalar_to_mxArray(' cvarname_ptr, ', '...
            getMxClassID(var.basetype) closeParen ');']);
    elseif rmode_var && iscuda
        if isempty(cprefix) && isempty(var.modifier)
            % Need to deallocate size field on CUDA
            str = sprintf('%s%s\n', str, ...
                ['    _ierr = cudaFree(' cvarname_ptr '); CHKCUERR(_ierr);']);
            hasCuError = true;
        elseif ~isempty(var.modifier)
            str = sprintf('%s\n', str(1:end-1), ...
                ['    if (!mxIsClass(' mx_field ', "m2c_gpuArray"))', ...
                '        _ierr = cudaFree(' cvarname_ptr '); CHKCUERR(_ierr);']);
            hasCuError = true;
        end
    else
        str = sprintf('%s%s\n', str, ...
            ['    /* Nothing to be done for ' var.mname ' */']);
    end
end

% Process pruned variables
for k=1:length(pruned_vars)
    var = pruned_vars(k);
    
    str = sprintf('%s\n', str, ...
        ['    /* Creating empty mxArray for pruned variable ' var.mname ' */']);
    dims = sprintf(', %d', var.size);
    str = sprintf('%s\n', str, ...
        ['    {mwSize _dims[] = {', dims(3:end) '};'], ...
        ['    prealloc_mxArray((mxArray**)&plhs[' num2str(pruned_vars(k).oindex-1) '], ' ...
        'mx' upper(var.type) '_CLASS, ' num2str(length(var.size)) ', _dims); }']);
end

if isempty(cprefix) && ~isempty(str)
    str = ['    /* Deallocate input and marshall out function outputs */' str];
end

end

function [funcname, structDefs] = gen_marshalloutFunc(structDefs, type, ...
    hasArray, iscuda, readonly_mode)
% Generate function for marshalloutg out a struct or an array of struct objects.
% It may recursively generate additional marshallout functions for other structs.

if hasArray && ~readonly_mode
    funcField = 'marshalloutArrayFunc';
    funcname = ['marshallout_'  type '_Array'];
elseif ~readonly_mode
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
    return;
end

if ~readonly_mode
    fieldstr = sprintf(', "%s"', structDefs.(type).fields.mname);
    decl_vars = sprintf('    %-20s %s;', 'const char', ['*fields[] = {' fieldstr(3:end) '}']);
else
    decl_vars = '';
end

if strncmp(type, 'emxArray_', 9)
    varname = 'pArr';
    args = [type ' *' varname];
    if ~readonly_mode
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'mxArray', ...
            ['*mx = create_struct_mxArray(pArr->numDimensions, pArr->size, ' ...
            num2str(length(structDefs.(type).fields)) ', fields)']), ...
            sprintf('    %-20s %s;', 'int', 'nElems = numElements(nDims, dims)'));
        mx_index = 'i';
    else
        mx_index = '';
    end
    decl_vars = sprintf('%s\n', decl_vars, ...
        sprintf('    %-20s %s;', 'int', 'i'));
    cprefix = 'pArr->data[i].';
elseif hasArray
    varname = 'pArr';
    args = [type ' *' varname ', int nDims, const int *dims'];
    if ~readonly_mode
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'mxArray', ['*mx = create_struct_mxArray(nDim, dims, ' ...
            num2str(length(structDefs.(type).fields)) ', fields)']), ...
            sprintf('    %-20s %s;', 'int', 'nElems = numElements(nDims, dims)'));
        mx_index = 'i';
    else
        mx_index = '';
    end
    decl_vars = sprintf('%s\n', decl_vars, ...
        sprintf('    %-20s %s;', 'int', 'i'));
    cprefix = 'pArr[i].';
else
    varname = 'pStruct';
    args = [type ' *' varname];
    if ~readonly_mode
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'int', 'one=1'), ...
            sprintf('    %-20s %s;', 'mxArray', ['*mx = create_struct_mxArray(1, &one, ' ...
            num2str(length(structDefs.(type).fields)) ', fields)']));
        mx_index = '0';
    else
        mx_index = '';
    end
    cprefix = 'pStruct->';
end

if iscuda
    decl_vars = [decl_vars ...
        sprintf('    %-20s %s;\n', 'mxArray', '*sub_mx')];
    if strncmp(type, 'emxArray_', 9)
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', type, 'pArr_buf'), ...
            sprintf('    %-20s %s;', structDefs.(type).structname, '*data_gpu'), ...
            sprintf('    %-20s %s;', 'int', '*size_gpu'));
        if ~readonly_mode
            decl_vars = sprintf('%s\n', decl_vars, ...
                '    copy_gpuEmxArray_to_emxArray(pArr, pArr_buf, &data_gpu, &size_gpu);');
        else
            decl_vars = sprintf('%s\n', decl_vars, ...
            '    get_gpuEmxArray_DataSize(pArr, &data_gpu, &size_gpu);');
        end
        cprefix = 'pArr_buf.data[i].';
    elseif hasArray
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', type, ['*pArr_buf = (' type '*)mxMalloc(sizeof(type) * nElems);']), ...
            ['    cudaStatus_T _ierr = cudaMemcpy(&pArr_buf, pStruct, sizeof(' type ...
            ') * nElems, cudaMemcpyDeviceToHost);'], ...
            '    CHKCUERR(_ierr, "cudaMemcpy");');
        cprefix = 'pArr_buf[i].';
    else
        decl_vars = sprintf('%s\n', decl_vars, ...
            ['    ' type '    obj;'], ...
            ['    cudaStatus_T _ierr = cudaMemcpy(&obj, pStruct, sizeof(' type ...
            ')' times ', cudaMemcpyDeviceToHost);'], ...
            '    CHKCUERR(_ierr, "cudaMemcpy");');
        cprefix = 'obj.';
    end
end

if readonly_mode && ~iscuda && structDefs.(type).hasInit
    loopBody = '';
else
    [loopBody, structDefs, hasDim, hasCuError] = marshallout(structDefs.(type).fields, [], iscuda, ...
        structDefs, cprefix, mx_index, readonly_mode);

    if hasDim
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'int', '_dim'));
    end
    
    if hasCuError
        decl_vars = sprintf('%s\n', decl_vars, ...
            sprintf('    %-20s %s;', 'cudaError_t', '_ierr'));
    end
end

if strncmp(type, 'emxArray_', 9) || hasArray
    if structDefs.(type).hasInit
        loopBody = sprintf('%s\n', loopBody, ...
            ['    emxDestroy_' type '(' cprefix(1:end-1) ');']);
    end
    % Add loop if there are arrays
    funcBody = sprintf('%s\n%s%s\n', ...
        '    for (i=0; i<nElems; ++i) {', ...
        regexprep(loopBody, '\n    ', '\n        '), ...
        '    }');
else
    if structDefs.(type).hasInit
        loopBody = sprintf('%s\n', loopBody, ...
            ['    emxDestroy_' type '(*pStruct);']);
    end
    funcBody = loopBody;
end

if strncmp(type, 'emxArray_', 9)
    dealloc = '    mxFree(pArr->size);';
else
    dealloc = '';
end

if iscuda
    % Deallocate additional buffers created for CUDA
    if strncmp(type, 'emxArray_', 9)
        dealloc = sprintf('%s\n', dealloc, ...
            '    _ierr = cudaFree(data_gpu); CHKCUERR(_ierr, "cudaFree");', ...
            '    _ierr = cudaFree(size_gpu); CHKCUERR(_ierr, "cudaFree");', ...
            '    _ierr = cudaFree(pArr); CHKCUERR(_ierr, "cudaFree");', ...
            '    mxFree(pArr_buf.size);');
    elseif hasArray
        dealloc = sprintf('%s\n', dealloc, ...
            '    _ierr = cudaFree(pArr); CHKCUERR(_ierr, "cudaFree");', ...
            '    mxFree(pArr_buf);');
    else
        dealloc = sprintf('%s\n', dealloc, ...
            '    _ierr = cudaFree(pStruct); CHKCUERR(_ierr, "cudaFree");');
    end
end

if ~readonly_mode
    return_val = 'mxArray *';
    return_mx = '    return mx;';
else
    return_val = 'void ';
    return_mx = '';
end

func = sprintf('%s\n', '', ...
    ['static ' return_val funcname '(' args ') {'], ...
    [decl_vars, funcBody, dealloc, return_mx], ...
    '}');

structDefs.(type).(funcField) = func;

end
