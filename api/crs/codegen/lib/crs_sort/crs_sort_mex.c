/*
 * crs/codegen/lib/crs_sort/crs_sort_mex.c
 *
 * Auxiliary code for mexFunction of crs_sort
 *
 * C source code generated by m2c.
 * %#m2c options:9017fddc2ca5daf140374f688e9dff6b
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "crs_sort.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __crs_sort_api(mxArray **plhs, const mxArray ** prhs) {
    emxArray_int32_T     row_ptr;
    emxArray_int32_T     col_ind;
    emxArray_real_T      val;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("crs_sort:WrongInputType",
            "Input argument row_ptr has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[0]) && mxGetDimensions(prhs[0])[1] != 1) 
        mexErrMsgIdAndTxt("crs_sort:WrongSizeOfInputArg",
            "Dimension 2 of row_ptr should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[0], (emxArray__common *)(&row_ptr), "row_ptr", 1);

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("crs_sort:WrongInputType",
            "Input argument col_ind has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) && mxGetDimensions(prhs[1])[1] != 1) 
        mexErrMsgIdAndTxt("crs_sort:WrongSizeOfInputArg",
            "Dimension 2 of col_ind should be equal to 1.");
    copy_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&col_ind), "col_ind", 1);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("crs_sort:WrongInputType",
            "Input argument val has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(prhs[2]) && mxGetDimensions(prhs[2])[1] != 1) 
        mexErrMsgIdAndTxt("crs_sort:WrongSizeOfInputArg",
            "Dimension 2 of val should be equal to 1.");
    copy_mxArray_to_emxArray(prhs[2], (emxArray__common *)(&val), "val", 1);

    /* Invoke the target function */
    crs_sort(&row_ptr, &col_ind, &val);

    /* Deallocate input and marshall out function outputs */
    free_emxArray((emxArray__common*)(&row_ptr));
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&col_ind), mxINT32_CLASS);
    mxFree(col_ind.size);
    plhs[1] = move_emxArray_to_mxArray((emxArray__common*)(&val), mxDOUBLE_CLASS);
    mxFree(val.size);

}

static void __crs_sort0_api(mxArray **plhs, const mxArray ** prhs) {
    emxArray_int32_T     row_ptr;
    emxArray_int32_T     col_ind;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("crs_sort0:WrongInputType",
            "Input argument row_ptr has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[0]) && mxGetDimensions(prhs[0])[1] != 1) 
        mexErrMsgIdAndTxt("crs_sort0:WrongSizeOfInputArg",
            "Dimension 2 of row_ptr should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[0], (emxArray__common *)(&row_ptr), "row_ptr", 1);

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("crs_sort0:WrongInputType",
            "Input argument col_ind has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) && mxGetDimensions(prhs[1])[1] != 1) 
        mexErrMsgIdAndTxt("crs_sort0:WrongSizeOfInputArg",
            "Dimension 2 of col_ind should be equal to 1.");
    copy_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&col_ind), "col_ind", 1);

    /* Invoke the target function */
    crs_sort0(&row_ptr, &col_ind);

    /* Deallocate input and marshall out function outputs */
    free_emxArray((emxArray__common*)(&row_ptr));
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&col_ind), mxINT32_CLASS);
    mxFree(col_ind.size);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2] = {NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 3) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("crs_sort:TooManyOutputArguments",
                "Too many output arguments for entry-point crs_sort.\n");
        /* Call the API function. */
        __crs_sort_api(outputs, prhs);
    }
    else if (nrhs == 2) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("crs_sort0:TooManyOutputArguments",
                "Too many output arguments for entry-point crs_sort0.\n");
        /* Call the API function. */
        __crs_sort0_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("crs_sort:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point crs_sort.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
