/*
 * m2c_opaque_ptr.c
 *
 */

#include "mex.h"
#include "string.h"

#if !defined(CONST_PTR)
#define TYPESTR "char *"
#else
#define TYPESTR "const char *"
#endif

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    mxArray *output, *field, *data;
    const char *fields[] = {"data", "type", "nbytes", "offset"};
    int offset = 0;
    char type[128];
    
    /* Check input and output arguments */
    if (nlhs>1)
        mexErrMsgIdAndTxt("m2c_opaque_ptr:WrongNumberOfOutputs",
                "Function m2c_opaque_ptr requires one output argument.");
    if (nrhs==0) {
        mexCallMATLAB(1, &output, nrhs, (mxArray **)prhs, "m2c_opaque_ptr_type");
        plhs[0] = output;
        return;
    }
    if (nrhs>3)
        mexErrMsgIdAndTxt("opaque_ptr:WrongNumberOfInputs",
                "Function opaque_ptr requires no more than three input arguments.");
    if (nrhs>1 && mxGetClassID(prhs[1])!=mxCHAR_CLASS)
        mexErrMsgIdAndTxt("opaque_ptr:WrongInputArgument",
                "Second input argument must be a character string.");
    
    if (nrhs==3 && mxGetClassID(prhs[2])==mxINT32_CLASS)
        offset = *(int*)mxGetData(prhs[2]);
    else if (nrhs==3 && mxGetClassID(prhs[2])==mxDOUBLE_CLASS)
        offset = (int)(*(double *)mxGetData(prhs[2]));
    else if (nrhs==3)
        mexErrMsgIdAndTxt("opaque_ptr:WrongInputType",
                "The third argument (offset) must be int32 or double.");
    
    if (offset) {
        mxGetString(prhs[1], type, 127);
        if (!strstr(type, "char")) {
            mexErrMsgIdAndTxt("opaque_ptr:PresetNonzeroOffset",
                    "You can only preset offset for 'char *' or 'const char *'.");
        }
    }
    
    /* Copy pointer object */
    if (mxGetClassID(prhs[0])==mxSTRUCT_CLASS) {
        if (mxGetNumberOfFields(prhs[0]) == 4 &&
                mxGetFieldNumber(prhs[0], fields[0])==0 &&
                mxGetFieldNumber(prhs[0], fields[1])==1 &&
                mxGetFieldNumber(prhs[0], fields[2])==2 &&
                mxGetFieldNumber(prhs[0], fields[3])==3) {
            
            plhs[0] = mxDuplicateArray(prhs[0]);
            if (nrhs>=2) {
                /* Overwrite the type name */
                mxDestroyArray(mxGetFieldByNumber(plhs[0], 0, 1));
                mxSetFieldByNumber(plhs[0], 0, 1, mxDuplicateArray(prhs[1]));
            }
            if (nrhs==3) {
                /* Overwrite offset */
                int *poffset = (int *)mxGetData(mxGetFieldByNumber(plhs[0], 0, 3));
                *poffset = offset;
            }
#ifndef CONST_PTR
            {
                field = mxGetFieldByNumber(plhs[0], 0, 1);
                mxGetString(field, type, 127);
                if (strncmp(type, "const ", 6)==0) {
                    mexWarnMsgIdAndTxt("opaque_ptr:ConstPtr", "Discarding a const modifier of an opaque_ptr.");
                    mxDestroyArray(field);
                    mxSetFieldByNumber(plhs[0], 0, 1, mxCreateString(type+6));
                }
            }
#endif
            return;
        }
        else {
            mexErrMsgIdAndTxt("opaque_ptr:NonNumericArrays",
                              "opaque_ptr takes only numeric array or opaque_ptr as input.");
        }
    }
    else if (!mxIsNumeric(prhs[0])) {
        mexErrMsgIdAndTxt("opaque_ptr:NonNumericArrays",
                "Function opaque_ptr only works with numeric arrays.");
    }
    else
        data = (mxArray *)prhs[0];

    /* Create a new pointer object */
    output = mxCreateStructMatrix(1, 1, 4, fields);
    
    field = mxCreateNumericMatrix(1, 1, mxUINT64_CLASS, mxREAL);
    *(char **)mxGetData(field) = (char*)mxGetData(data);
    mxSetFieldByNumber(output, 0, 0,  field);
    
    if (nrhs>=2)
        field = mxDuplicateArray(prhs[1]);
    else
        field = mxCreateString(TYPESTR);
    mxSetFieldByNumber(output, 0, 1,  field);
    
    field = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int *)mxGetData(field) = mxGetNumberOfElements(data)*mxGetElementSize(data);
    mxSetFieldByNumber(output, 0, 2,  field);
    
    field = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int *)mxGetData(field) = offset;
    mxSetFieldByNumber(output, 0, 3,  field);
    
    plhs[0] = output;
}
