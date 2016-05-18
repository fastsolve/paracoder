/*
 * m2c_opaque_ptr.c
 *
 */

#include "mex.h"
#include "string.h"

#if !defined(CONST_PTR)
#define TYPESTR "void *"
#else
#define TYPESTR "const void *"
#endif

#if 0
/* One undocumented MATLAB functions for supporting copy-on-write. */
extern int mxIsSharedArray(const mxArray *a);
#else
#define mxIsSharedArray(a) 0
#endif


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    mxArray *output, *field;
    const char *fields[] = {"data", "type", "nbytes", "parent", "offset"};
    int offset = 0;
    int saveparent=0;
    
    /* Check input and output arguments */
    if ( nlhs>1)
        mexErrMsgIdAndTxt("m2c_opaque_ptr:WrongNumberOfOutputs",
                "Function m2c_opaque_ptr requires one output argument.");
    if ( nrhs==0) {
        mexCallMATLAB( 1, &output, nrhs, (mxArray **)prhs, "m2c_opaque_ptr_type");
        plhs[0] = output;
        return;
    }
    if ( nrhs>3)
        mexErrMsgIdAndTxt("opaque_ptr:WrongNumberOfInputs",
                "Function opaque_ptr requires no more than three input arguments.");
    if ( nrhs>1 && mxGetClassID(prhs[1])!=mxCHAR_CLASS)
        mexErrMsgIdAndTxt("opaque_ptr:WrongInputArgument",
                "Second input argument must be a character string.");
    
    if (nrhs==3 && mxGetClassID(prhs[2])==mxINT32_CLASS)
        offset = *(int*)mxGetData(prhs[2]);
    else if (nrhs==3 && mxGetClassID(prhs[2])==mxDOUBLE_CLASS)
        offset = (int)(*(double *)mxGetData(prhs[2]));
    else if (nrhs==3)
        mexErrMsgIdAndTxt("opaque_ptr:WrongInputType",
                "The second argument (offset) must be int32 or double.");
    
    /* Copy pointer object */
    if ( mxGetClassID( prhs[0])==mxSTRUCT_CLASS) {
        if (mxGetNumberOfFields( prhs[0]) == 5 &&
                mxGetFieldNumber( prhs[0], fields[0])==0 &&
                mxGetFieldNumber( prhs[0], fields[1])==1 &&
                mxGetFieldNumber( prhs[0], fields[2])==2 &&
                mxGetFieldNumber( prhs[0], fields[3])==3 &&
                mxGetFieldNumber( prhs[0], fields[4])==4) {
            /* Verify parent mxArray still has the same address */
            void *data = mxGetData(mxGetFieldByNumber( prhs[0], 0, 3));
            mxArray *parent = NULL;
            int *poffset = (int *)mxGetData(mxGetFieldByNumber(prhs[0], 0, 4));
            
            if (data) parent = *(mxArray **)data;
            if (parent && ((char *)mxGetData(parent))+*poffset !=
                    *(char **)mxGetData( mxGetFieldByNumber( prhs[0], 0, 0)))
                mexErrMsgIdAndTxt("opaque_ptr:ParentObjectChanged",
                        "The parent mxArray has changed. Avoid changing a MATLAB variable when dereferenced by an opaque_ptr.");
            
            plhs[0] = mxDuplicateArray( prhs[0]);
            if (nrhs==3 && offset != *(int *)mxGetData(plhs[0])) {
                *(char **)mxGetData(mxGetFieldByNumber(plhs[0], 0, 0)) += offset;
                poffset = (int *)mxGetData(mxGetFieldByNumber(plhs[0], 0, 4));
                *poffset += offset;
            }
#ifndef CONST_PTR
            {
                char type[128];

                field = mxGetFieldByNumber( plhs[0], 0, 1);
                mxGetString(field, type, 127);
                if (strncmp( type, "const ", 6)==0) {
                    mexWarnMsgIdAndTxt("opaque_ptr:ConstPtr", "Discarding a const modifier of am opaque_ptr.");
                    mxDestroyArray( field);
                    mxSetFieldByNumber( plhs[0], 0, 1, mxCreateString( type+6));
                }
            }
#endif
            return;
        }
    }
    
    if ( !mxIsNumeric( prhs[0])) {
        mexErrMsgIdAndTxt("opaque_ptr:NonNumericArrays",
                "Function opaque_ptr only works with numeric arrays.");
    }
#if !defined(CONST_PTR) && !defined(HAVE_OCTAVE)
    if (mxIsSharedArray(prhs[0]))
        mexWarnMsgIdAndTxt("opaque_ptr:SharedArray",
                "The array you are dereferencing with opaque_prt is shared by multiple variables. Modifying the array would alter all the variables.\nTo unshare the array, write to the array before calling opaque_ptr.");
    else
        saveparent = 1;
#endif    
    /* Create a new pointer object */
    output = mxCreateStructMatrix(1, 1, 5, fields);
    
    field = mxCreateNumericMatrix(sizeof(void*), 1, mxUINT8_CLASS, mxREAL);
    *(char **)mxGetData(field) = ((char*)mxGetData( prhs[0]))+offset;
    mxSetFieldByNumber( output, 0, 0,  field);
    
    if (nrhs>=2)
        field = mxDuplicateArray( prhs[1]);
    else
        field = mxCreateString( TYPESTR);
    mxSetFieldByNumber( output, 0, 1,  field);
    
    field = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int *)mxGetData(field) = mxGetNumberOfElements( prhs[0])*mxGetElementSize(prhs[0]);
    mxSetFieldByNumber( output, 0, 2,  field);
    
    field = mxCreateNumericMatrix(sizeof( void*), 1, mxUINT8_CLASS, mxREAL);
    *(void **)mxGetData(field) = saveparent ? (void *)prhs[0] : (void *)NULL;
    mxSetFieldByNumber( output, 0, 3,  field);
    
    field = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int *)mxGetData(field) = offset;
    mxSetFieldByNumber( output, 0, 4,  field);
    
    plhs[0] = output;
}
