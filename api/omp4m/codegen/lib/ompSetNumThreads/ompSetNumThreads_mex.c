/*
 * codegen/lib/ompSetNumThreads/ompSetNumThreads_mex.c
 *
 * Auxiliary code for mexFunction of ompSetNumThreads
 *
 * C source code generated by m2c.
 * %#m2c options:f0c8daf676ad9872b69ad961a41f2cd1
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "ompSetNumThreads.h"
#include "ompSetNumThreads_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __ompSetNumThreads_api(mxArray **plhs, const mxArray ** prhs) {
    int32_T              num_threads;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("ompSetNumThreads:WrongInputType",
            "Input argument num_threads has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("ompSetNumThreads:WrongSizeOfInputArg",
            "Argument num_threads should be a scalar.");
    num_threads = *(int32_T*)mxGetData(prhs[0]);

    /* Invoke the target function */
    ompSetNumThreads(num_threads);

    /* Deallocate input and marshall out function outputs */
    /* Nothing to be done for num_threads */

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs == 1) {
        if (nlhs > 0)
            mexErrMsgIdAndTxt("ompSetNumThreads:TooManyOutputArguments",
                "Too many output arguments for entry-point ompSetNumThreads.\n");
        /* Call the API function. */
        __ompSetNumThreads_api(plhs, prhs);
    }
    else
        mexErrMsgIdAndTxt("ompSetNumThreads:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point ompSetNumThreads.");
}
