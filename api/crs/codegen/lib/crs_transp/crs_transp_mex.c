/*
 * crs/codegen/lib/crs_transp/crs_transp_mex.c
 *
 * Auxiliary code for mexFunction of crs_transp
 *
 * C source code generated by m2c.
 * %#m2c options:0620aeb4f2a268ec25ca44fd659f6065
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "crs_transp.h"
#include "crs_transp_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void marshallin_const_CRS_Matrix(CRS_Matrix *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_CRS_Matrix:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "row_ptr"))
        M2C_error("marshallin_const_CRS_Matrix:WrongType",
            "Input argument %s is missing the field row_ptr.", mname);
    if (!mxGetField(mx, 0, "col_ind"))
        M2C_error("marshallin_const_CRS_Matrix:WrongType",
            "Input argument %s is missing the field col_ind.", mname);
    if (!mxGetField(mx, 0, "val"))
        M2C_error("marshallin_const_CRS_Matrix:WrongType",
            "Input argument %s is missing the field val.", mname);
    if (!mxGetField(mx, 0, "nrows"))
        M2C_error("marshallin_const_CRS_Matrix:WrongType",
            "Input argument %s is missing the field nrows.", mname);
    if (!mxGetField(mx, 0, "ncols"))
        M2C_error("marshallin_const_CRS_Matrix:WrongType",
            "Input argument %s is missing the field ncols.", mname);
    if (mxGetNumberOfFields(mx) > 5)
        M2C_warn("marshallin_const_CRS_Matrix:ExtraFields",
            "Extra fields in %s and are ignored.", mname);

    sub_mx = mxGetField(mx, 0, "row_ptr");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_CRS_Matrix:WrongInputType",
            "Input argument row_ptr has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_CRS_Matrix:WrongSizeOfInputArg",
            "Dimension 2 of row_ptr should be equal to 1.");
    pStruct->row_ptr = (emxArray_int32_T*)mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->row_ptr), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->row_ptr), "row_ptr", 1);

    sub_mx = mxGetField(mx, 0, "col_ind");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_CRS_Matrix:WrongInputType",
            "Input argument col_ind has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_CRS_Matrix:WrongSizeOfInputArg",
            "Dimension 2 of col_ind should be equal to 1.");
    pStruct->col_ind = (emxArray_int32_T*)mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->col_ind), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->col_ind), "col_ind", 1);

    sub_mx = mxGetField(mx, 0, "val");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_CRS_Matrix:WrongInputType",
            "Input argument val has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_CRS_Matrix:WrongSizeOfInputArg",
            "Dimension 2 of val should be equal to 1.");
    pStruct->val = (emxArray_real_T*)mxMalloc(sizeof(emxArray_real_T));
    init_emxArray((emxArray__common*)(pStruct->val), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->val), "val", 1);

    sub_mx = mxGetField(mx, 0, "nrows");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_CRS_Matrix:WrongInputType",
            "Input argument nrows has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_CRS_Matrix:WrongSizeOfInputArg",
            "Argument nrows should be a scalar.");
    pStruct->nrows = *(int32_T*)mxGetData(sub_mx);

    sub_mx = mxGetField(mx, 0, "ncols");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_CRS_Matrix:WrongInputType",
            "Input argument ncols has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_CRS_Matrix:WrongSizeOfInputArg",
            "Argument ncols should be a scalar.");
    pStruct->ncols = *(int32_T*)mxGetData(sub_mx);
}
static void prealloc_CRS_Matrix(CRS_Matrix *pStruct) {


    pStruct->row_ptr = (emxArray_int32_T*)mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->row_ptr), 1);

    pStruct->col_ind = (emxArray_int32_T*)mxMalloc(sizeof(emxArray_int32_T));
    init_emxArray((emxArray__common*)(pStruct->col_ind), 1);

    pStruct->val = (emxArray_real_T*)mxMalloc(sizeof(emxArray_real_T));
    init_emxArray((emxArray__common*)(pStruct->val), 1);

}
static mxArray *marshallout_CRS_Matrix(CRS_Matrix *pStruct) {
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
static void destroy_CRS_Matrix(CRS_Matrix *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->row_ptr));
    mxFree(pStruct->row_ptr);

    free_emxArray((emxArray__common*)(pStruct->col_ind));
    mxFree(pStruct->col_ind);

    free_emxArray((emxArray__common*)(pStruct->val));
    mxFree(pStruct->val);


}


static void __crs_transp_api(mxArray **plhs, const mxArray ** prhs) {
    CRS_Matrix           A;
    CRS_Matrix           At;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("crs_transp:WrongInputType",
            "Input argument A has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("crs_transp:WrongSizeOfInputArg",
            "Argument A should be a scalar.");
    marshallin_const_CRS_Matrix(&A, prhs[0], "A");
    prealloc_CRS_Matrix(&At);

    /* Invoke the target function */
    crs_transp(&A, &At);

    /* Deallocate input and marshall out function outputs */
    destroy_CRS_Matrix(&A);
    plhs[0] = marshallout_CRS_Matrix(&At);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs == 1) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("crs_transp:TooManyOutputArguments",
                "Too many output arguments for entry-point crs_transp.\n");
        /* Call the API function. */
        __crs_transp_api(plhs, prhs);
    }
    else
        mexErrMsgIdAndTxt("crs_transp:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point crs_transp.");
}
