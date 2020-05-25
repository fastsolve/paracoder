/*
 * ccs/codegen/lib/ccs_solve_utriu/ccs_solve_utriu_mex.c
 *
 * Auxiliary code for mexFunction of ccs_solve_utriu
 *
 * C source code generated by m2c.
 * %#m2c options:f40f4a2100e05d6ef1337d6400b6dd37
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "ccs_solve_utriu.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void marshallin_const_struct0_T(struct0_T *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "col_ptr"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field col_ptr.", mname);
    if (!mxGetField(mx, 0, "row_ind"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field row_ind.", mname);
    if (!mxGetField(mx, 0, "val"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field val.", mname);
    if (!mxGetField(mx, 0, "nrows"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field nrows.", mname);
    if (!mxGetField(mx, 0, "ncols"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field ncols.", mname);
    if (mxGetNumberOfFields(mx) > 5)
        M2C_warn("marshallin_const_struct0_T:ExtraFields",
            "Extra fields in %s and are ignored.", mname);

    sub_mx = mxGetField(mx, 0, "col_ptr");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument col_ptr has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 2 of col_ptr should be equal to 1.");
    pStruct->col_ptr = mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->col_ptr), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->col_ptr), "col_ptr", 1);

    sub_mx = mxGetField(mx, 0, "row_ind");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument row_ind has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 2 of row_ind should be equal to 1.");
    pStruct->row_ind = mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->row_ind), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->row_ind), "row_ind", 1);

    sub_mx = mxGetField(mx, 0, "val");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument val has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 2 of val should be equal to 1.");
    pStruct->val = mxMalloc(sizeof(emxArray_real_T));
    init_emxArray((emxArray__common*)(pStruct->val), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->val), "val", 1);

    sub_mx = mxGetField(mx, 0, "nrows");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument nrows has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Argument nrows should be a scalar.");
    pStruct->nrows = *(int32_T*)mxGetData(sub_mx);

    sub_mx = mxGetField(mx, 0, "ncols");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument ncols has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Argument ncols should be a scalar.");
    pStruct->ncols = *(int32_T*)mxGetData(sub_mx);
}
static void destroy_struct0_T(struct0_T *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->col_ptr));
    mxFree(pStruct->col_ptr);

    free_emxArray((emxArray__common*)(pStruct->row_ind));
    mxFree(pStruct->row_ind);

    free_emxArray((emxArray__common*)(pStruct->val));
    mxFree(pStruct->val);


}


static void __ccs_solve_utriu_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            U;
    emxArray_real_T      b;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("ccs_solve_utriu:WrongInputType",
            "Input argument U has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("ccs_solve_utriu:WrongSizeOfInputArg",
            "Argument U should be a scalar.");
    marshallin_const_struct0_T(&U, prhs[0], "U");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("ccs_solve_utriu:WrongInputType",
            "Input argument b has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(prhs[1]) && mxGetDimensions(prhs[1])[1] != 1) 
        mexErrMsgIdAndTxt("ccs_solve_utriu:WrongSizeOfInputArg",
            "Dimension 2 of b should be equal to 1.");
    copy_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&b), "b", 1);

    /* Invoke the target function */
    ccs_solve_utriu(&U, &b);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&U);
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&b), mxDOUBLE_CLASS);
    mxFree(b.size);

}

static void __ccs_solve_utriu_3args_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            U;
    emxArray_real_T      b;
    int32_T              offset;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("ccs_solve_utriu_3args:WrongInputType",
            "Input argument U has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("ccs_solve_utriu_3args:WrongSizeOfInputArg",
            "Argument U should be a scalar.");
    marshallin_const_struct0_T(&U, prhs[0], "U");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("ccs_solve_utriu_3args:WrongInputType",
            "Input argument b has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(prhs[1]) && mxGetDimensions(prhs[1])[1] != 1) 
        mexErrMsgIdAndTxt("ccs_solve_utriu_3args:WrongSizeOfInputArg",
            "Dimension 2 of b should be equal to 1.");
    copy_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&b), "b", 1);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("ccs_solve_utriu_3args:WrongInputType",
            "Input argument offset has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("ccs_solve_utriu_3args:WrongSizeOfInputArg",
            "Argument offset should be a scalar.");
    offset = *(int32_T*)mxGetData(prhs[2]);

    /* Invoke the target function */
    ccs_solve_utriu_3args(&U, &b, offset);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&U);
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&b), mxDOUBLE_CLASS);
    mxFree(b.size);
    /* Nothing to be done for offset */

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs == 2) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("ccs_solve_utriu:TooManyOutputArguments",
                "Too many output arguments for entry-point ccs_solve_utriu.\n");
        /* Call the API function. */
        __ccs_solve_utriu_api(plhs, prhs);
    }
    else if (nrhs == 3) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("ccs_solve_utriu_3args:TooManyOutputArguments",
                "Too many output arguments for entry-point ccs_solve_utriu_3args.\n");
        /* Call the API function. */
        __ccs_solve_utriu_3args_api(plhs, prhs);
    }
    else
        mexErrMsgIdAndTxt("ccs_solve_utriu:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point ccs_solve_utriu.");
}
