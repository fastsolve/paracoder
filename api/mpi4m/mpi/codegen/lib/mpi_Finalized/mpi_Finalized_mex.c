/*
 * mpi/codegen/lib/mpi_Finalized/mpi_Finalized_mex.c
 *
 * Auxiliary code for mexFunction of mpi_Finalized
 *
 * C source code generated by m2c.
 * %#m2c options:a86f06273668c7ee1c254c6a92bd888a
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "mpi_Finalized.h"
#include "mpi_Finalized_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __mpi_Finalized_api(mxArray **plhs, const mxArray ** prhs) {
    int32_T             *flag;
    int32_T             *info;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    flag = (int32_T*)mxMalloc(sizeof(int32_T));

    info = (int32_T*)mxMalloc(sizeof(int32_T));

    toplevel = (boolean_T*)mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    mpi_Finalized(flag, info, toplevel);

    /* Deallocate input and marshall out function outputs */
    plhs[0] = move_scalar_to_mxArray(flag, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(info, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3] = {NULL, NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 0) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("mpi_Finalized:TooManyOutputArguments",
                "Too many output arguments for entry-point mpi_Finalized.\n");
        /* Call the API function. */
        __mpi_Finalized_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("mpi_Finalized:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point mpi_Finalized.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
