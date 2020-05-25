/*
 * crs/codegen/lib/crs_prodAB/crs_prodAB_mex.c
 *
 * Auxiliary code for mexFunction of crs_prodAB
 *
 * C source code generated by m2c.
 * %#m2c options:20fc9f7c64014ebef957c89e8cb98922
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "crs_prodAB.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void marshallin_const_struct0_T(struct0_T *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "row_ptr"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field row_ptr.", mname);
    if (!mxGetField(mx, 0, "col_ind"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field col_ind.", mname);
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

    sub_mx = mxGetField(mx, 0, "row_ptr");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument row_ptr has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 2 of row_ptr should be equal to 1.");
    pStruct->row_ptr = mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->row_ptr), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->row_ptr), "row_ptr", 1);

    sub_mx = mxGetField(mx, 0, "col_ind");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument col_ind has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 2 of col_ind should be equal to 1.");
    pStruct->col_ind = mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->col_ind), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->col_ind), "col_ind", 1);

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
static void prealloc_struct0_T(struct0_T *pStruct) {


    pStruct->row_ptr = mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->row_ptr), 1);

    pStruct->col_ind = mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->col_ind), 1);

    pStruct->val = mxMalloc(sizeof(emxArray_real_T));
    init_emxArray((emxArray__common*)(pStruct->val), 1);

}
static mxArray *marshallout_struct0_T(struct0_T *pStruct) {
    const char           *fields[] = {"row_ptr", "col_ind", "val", "nrows", "ncols"};
    int                  one=1;
    mxArray              *mx = create_struct_mxArray(1, &one, 5, fields);

    mxSetField(mx, 0, "row_ptr", move_emxArray_to_mxArray((emxArray__common*)(pStruct->row_ptr), mxINT32_CLASS));
    mxFree(pStruct->row_ptr->size);
    mxFree(pStruct->row_ptr);

    mxSetField(mx, 0, "col_ind", move_emxArray_to_mxArray((emxArray__common*)(pStruct->col_ind), mxINT32_CLASS));
    mxFree(pStruct->col_ind->size);
    mxFree(pStruct->col_ind);

    mxSetField(mx, 0, "val", move_emxArray_to_mxArray((emxArray__common*)(pStruct->val), mxDOUBLE_CLASS));
    mxFree(pStruct->val->size);
    mxFree(pStruct->val);

    mxSetField(mx, 0, "nrows", copy_scalar_to_mxArray(&pStruct->nrows, mxINT32_CLASS));
    mxSetField(mx, 0, "ncols", copy_scalar_to_mxArray(&pStruct->ncols, mxINT32_CLASS));
    return mx;
}
static void destroy_struct0_T(struct0_T *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->row_ptr));
    mxFree(pStruct->row_ptr);

    free_emxArray((emxArray__common*)(pStruct->col_ind));
    mxFree(pStruct->col_ind);

    free_emxArray((emxArray__common*)(pStruct->val));
    mxFree(pStruct->val);


}


static void __crs_prodAB_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            A;
    struct0_T            B;
    struct0_T            C;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("crs_prodAB:WrongInputType",
            "Input argument A has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("crs_prodAB:WrongSizeOfInputArg",
            "Argument A should be a scalar.");
    marshallin_const_struct0_T(&A, prhs[0], "A");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("crs_prodAB:WrongInputType",
            "Input argument B has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("crs_prodAB:WrongSizeOfInputArg",
            "Argument B should be a scalar.");
    marshallin_const_struct0_T(&B, prhs[1], "B");
    prealloc_struct0_T(&C);

    /* Invoke the target function */
    crs_prodAB(&A, &B, &C);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&A);
    destroy_struct0_T(&B);
    plhs[0] = marshallout_struct0_T(&C);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs == 2) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("crs_prodAB:TooManyOutputArguments",
                "Too many output arguments for entry-point crs_prodAB.\n");
        /* Call the API function. */
        __crs_prodAB_api(plhs, prhs);
    }
    else
        mexErrMsgIdAndTxt("crs_prodAB:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point crs_prodAB.");
}
