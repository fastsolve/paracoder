/*
 * codegen/lib/ompGetNested/ompGetNested_mex.c
 *
 * Auxiliary code for mexFunction of ompGetNested
 *
 * C source code generated by m2c.
 * %#m2c options:c92b43727942398fd1cb3a62677cc8c1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C header file generated by codegen in lib mode */
#include "ompGetNested.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __ompGetNested_api(mxArray **plhs, const mxArray ** prhs) {
    int32_T              _n;

    /* Marshall in inputs and preallocate outputs */

    /* Invoke the target function */
    _n = ompGetNested();

    /* Deallocate input and marshall out function outputs */
    plhs[0] = copy_scalar_to_mxArray(&_n, mxINT32_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs == 0) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("ompGetNested:TooManyOutputArguments",
                "Too many output arguments for entry-point ompGetNested.\n");
        /* Call the API function. */
        __ompGetNested_api(plhs, prhs);
    }
    else
        mexErrMsgIdAndTxt("ompGetNested:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point ompGetNested.");
}
