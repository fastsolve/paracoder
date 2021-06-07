/*
 * ccs/codegen/lib/ccs_solve_tril/ccs_solve_tril_mex.c
 *
 * Auxiliary code for mexFunction of ccs_solve_tril
 *
 * C source code generated by m2c.
 * %#m2c options:7bcae51bbe8d9dcfe56f59105b2a61b2
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "ccs_solve_tril.h"
#include "ccs_solve_tril_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void marshallin_const_CCS_Matrix(CCS_Matrix *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_CCS_Matrix:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "col_ptr"))
        M2C_error("marshallin_const_CCS_Matrix:WrongType",
            "Input argument %s is missing the field col_ptr.", mname);
    if (!mxGetField(mx, 0, "row_ind"))
        M2C_error("marshallin_const_CCS_Matrix:WrongType",
            "Input argument %s is missing the field row_ind.", mname);
    if (!mxGetField(mx, 0, "val"))
        M2C_error("marshallin_const_CCS_Matrix:WrongType",
            "Input argument %s is missing the field val.", mname);
    if (!mxGetField(mx, 0, "nrows"))
        M2C_error("marshallin_const_CCS_Matrix:WrongType",
            "Input argument %s is missing the field nrows.", mname);
    if (!mxGetField(mx, 0, "ncols"))
        M2C_error("marshallin_const_CCS_Matrix:WrongType",
            "Input argument %s is missing the field ncols.", mname);
    if (mxGetNumberOfFields(mx) > 5)
        M2C_warn("marshallin_const_CCS_Matrix:ExtraFields",
            "Extra fields in %s and are ignored.", mname);

    sub_mx = mxGetField(mx, 0, "col_ptr");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_CCS_Matrix:WrongInputType",
            "Input argument col_ptr has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_CCS_Matrix:WrongSizeOfInputArg",
            "Dimension 2 of col_ptr should be equal to 1.");
    pStruct->col_ptr = (emxArray_int32_T*)mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->col_ptr), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->col_ptr), "col_ptr", 1);

    sub_mx = mxGetField(mx, 0, "row_ind");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_CCS_Matrix:WrongInputType",
            "Input argument row_ind has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_CCS_Matrix:WrongSizeOfInputArg",
            "Dimension 2 of row_ind should be equal to 1.");
    pStruct->row_ind = (emxArray_int32_T*)mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->row_ind), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->row_ind), "row_ind", 1);

    sub_mx = mxGetField(mx, 0, "val");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_CCS_Matrix:WrongInputType",
            "Input argument val has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_CCS_Matrix:WrongSizeOfInputArg",
            "Dimension 2 of val should be equal to 1.");
    pStruct->val = (emxArray_real_T*)mxMalloc(sizeof(emxArray_real_T));
    init_emxArray((emxArray__common*)(pStruct->val), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->val), "val", 1);

    sub_mx = mxGetField(mx, 0, "nrows");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_CCS_Matrix:WrongInputType",
            "Input argument nrows has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_CCS_Matrix:WrongSizeOfInputArg",
            "Argument nrows should be a scalar.");
    pStruct->nrows = *(int32_T*)mxGetData(sub_mx);

    sub_mx = mxGetField(mx, 0, "ncols");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_CCS_Matrix:WrongInputType",
            "Input argument ncols has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_CCS_Matrix:WrongSizeOfInputArg",
            "Argument ncols should be a scalar.");
    pStruct->ncols = *(int32_T*)mxGetData(sub_mx);
}
static void destroy_CCS_Matrix(CCS_Matrix *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->col_ptr));
    mxFree(pStruct->col_ptr);

    free_emxArray((emxArray__common*)(pStruct->row_ind));
    mxFree(pStruct->row_ind);

    free_emxArray((emxArray__common*)(pStruct->val));
    mxFree(pStruct->val);


}


static void __ccs_solve_tril_api(mxArray **plhs, const mxArray ** prhs) {
    CCS_Matrix           L;
    emxArray_real_T      b;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("ccs_solve_tril:WrongInputType",
            "Input argument L has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("ccs_solve_tril:WrongSizeOfInputArg",
            "Argument L should be a scalar.");
    marshallin_const_CCS_Matrix(&L, prhs[0], "L");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("ccs_solve_tril:WrongInputType",
            "Input argument b has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(prhs[1]) && mxGetDimensions(prhs[1])[1] != 1) 
        mexErrMsgIdAndTxt("ccs_solve_tril:WrongSizeOfInputArg",
            "Dimension 2 of b should be equal to 1.");
    copy_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&b), "b", 1);

    /* Invoke the target function */
    ccs_solve_tril(&L, &b);

    /* Deallocate input and marshall out function outputs */
    destroy_CCS_Matrix(&L);
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&b), mxDOUBLE_CLASS);
    mxFree(b.size);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs == 2) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("ccs_solve_tril:TooManyOutputArguments",
                "Too many output arguments for entry-point ccs_solve_tril.\n");
        /* Call the API function. */
        __ccs_solve_tril_api(plhs, prhs);
    }
    else
        mexErrMsgIdAndTxt("ccs_solve_tril:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point ccs_solve_tril.");
}
