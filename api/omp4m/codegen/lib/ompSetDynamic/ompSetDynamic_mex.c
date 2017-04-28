/*
 * codegen/lib/ompSetDynamic/ompSetDynamic_mex.c
 *
 * Auxiliary code for mexFunction of ompSetDynamic
 *
 * C source code generated by m2c.
 * %#m2c options:f0c8daf676ad9872b69ad961a41f2cd1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C header file generated by codegen in lib mode */
#include "ompSetDynamic.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __ompSetDynamic_api(mxArray **plhs, const mxArray ** prhs) {
    int32_T              dynamic;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("ompSetDynamic:WrongInputType",
            "Input argument dynamic has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("ompSetDynamic:WrongSizeOfInputArg",
            "Argument dynamic should be a scalar.");
    dynamic = *(int32_T*)mxGetData(prhs[0]);

    /* Invoke the target function */
    ompSetDynamic(dynamic);

    /* Deallocate input and marshall out function outputs */
    /* Nothing to be done for dynamic */

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs == 1) {
        if (nlhs > 0)
            mexErrMsgIdAndTxt("ompSetDynamic:TooManyOutputArguments",
                "Too many output arguments for entry-point ompSetDynamic.\n");
        /* Call the API function. */
        __ompSetDynamic_api(plhs, prhs);
    }
    else
        mexErrMsgIdAndTxt("ompSetDynamic:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point ompSetDynamic.");
}
