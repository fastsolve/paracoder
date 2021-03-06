/*
 * mpi/codegen/lib/mpi_Get_version/mpi_Get_version_mex.c
 *
 * Auxiliary code for mexFunction of mpi_Get_version
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
#include "mpi_Get_version.h"
#include "mpi_Get_version_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __mpi_Get_version_api(mxArray **plhs, const mxArray ** prhs) {
    int32_T             *version;
    int32_T             *subversion;
    int32_T             *info;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    version = (int32_T*)mxMalloc(sizeof(int32_T));

    subversion = (int32_T*)mxMalloc(sizeof(int32_T));

    info = (int32_T*)mxMalloc(sizeof(int32_T));

    toplevel = (boolean_T*)mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    mpi_Get_version(version, subversion, info, toplevel);

    /* Deallocate input and marshall out function outputs */
    plhs[0] = move_scalar_to_mxArray(version, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(subversion, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(info, mxINT32_CLASS);
    plhs[3] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[4] = {NULL, NULL, NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 0) {
        if (nlhs > 4)
            mexErrMsgIdAndTxt("mpi_Get_version:TooManyOutputArguments",
                "Too many output arguments for entry-point mpi_Get_version.\n");
        /* Call the API function. */
        __mpi_Get_version_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("mpi_Get_version:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point mpi_Get_version.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
