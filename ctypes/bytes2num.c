/*
 * bytes2num.c
 *
 * Copy bytes into given number type.
 */

#include "mex.h"
#include "string.h"

/* Main entry */
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    size_t  offset=0, len, rem;
    
    /* Check input and output arguments */
    if ( nrhs!=3)
        mexErrMsgIdAndTxt("bytes2num:WrongNumberOfInputs",
                "Function bytes2num requires three input arguments.");
    if ( nlhs>2)
        mexErrMsgIdAndTxt("bytes2num:WrongNumberOfOutputs",
                "Function bytes2num requires two or fewer output arguments.");

    /* Determine offset */
    switch (mxGetClassID(prhs[1])) {
        case mxINT64_CLASS:
        case mxUINT64_CLASS:
            offset = *(unsigned long long *)mxGetData(prhs[1]); break;
        case mxDOUBLE_CLASS:
            offset = (size_t)*mxGetPr(prhs[1]); break;
        case mxINT32_CLASS:
        case mxUINT32_CLASS:
            offset = *(unsigned *)mxGetData(prhs[1]); break;
        default:
            mexErrMsgIdAndTxt("bytes2num:WrongInputType",
                    "The second argument (offset) must be int or double.");
    }
     
    /* Copy input template into plhs[0] */
    plhs[0] = mxDuplicateArray( prhs[2]);
    len = mxGetNumberOfElements( plhs[0])*mxGetElementSize(plhs[0]);
       
    rem = mxGetNumberOfElements(prhs[0])-offset;
    if (rem<len) len = rem;
    memcpy( mxGetData( plhs[0]), ((char*)mxGetData( prhs[0]))+offset, len);
    
    /* Set the number of putput */
    if (nlhs>1) {
        if (sizeof( size_t)==4)
            plhs[1] = mxCreateNumericMatrix( 1, 1, mxUINT32_CLASS, mxREAL);
        else
            plhs[1] = mxCreateNumericMatrix( 1, 1, mxUINT64_CLASS, mxREAL);
        
        *(size_t *)mxGetData(plhs[1]) = len;
    }
}
