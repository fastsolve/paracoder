/*
 * crs/codegen/lib/crs_prodAtAx/crs_prodAtAx_mex.c
 *
 * Auxiliary code for mexFunction of crs_prodAtAx
 *
 * C source code generated by m2c.
 * %#m2c options:1ac233ddfeb1f6a8fb544d191095d480
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "crs_prodAtAx.h"
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
static void destroy_CRS_Matrix(CRS_Matrix *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->row_ptr));
    mxFree(pStruct->row_ptr);

    free_emxArray((emxArray__common*)(pStruct->col_ind));
    mxFree(pStruct->col_ind);

    free_emxArray((emxArray__common*)(pStruct->val));
    mxFree(pStruct->val);


}


static void __crs_prodAtAx_api(mxArray **plhs, const mxArray ** prhs) {
    CRS_Matrix           A;
    emxArray_real_T      x;
    emxArray_real_T      b;
    emxArray_real_T      Ax;
    emxArray_int32_T     nthreads;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("crs_prodAtAx:WrongInputType",
            "Input argument A has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("crs_prodAtAx:WrongSizeOfInputArg",
            "Argument A should be a scalar.");
    marshallin_const_CRS_Matrix(&A, prhs[0], "A");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("crs_prodAtAx:WrongInputType",
            "Input argument x has incorrect data type; double is expected.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&x), "x", 2);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("crs_prodAtAx:WrongInputType",
            "Input argument b has incorrect data type; double is expected.");
    copy_mxArray_to_emxArray(prhs[2], (emxArray__common *)(&b), "b", 2);

    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("crs_prodAtAx:WrongInputType",
            "Input argument Ax has incorrect data type; double is expected.");
    copy_mxArray_to_emxArray(prhs[3], (emxArray__common *)(&Ax), "Ax", 2);

    if (mxGetNumberOfElements(prhs[4]) && mxGetClassID(prhs[4]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("crs_prodAtAx:WrongInputType",
            "Input argument nthreads has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[4]) && mxGetDimensions(prhs[4])[0] > 1)
        mexErrMsgIdAndTxt("crs_prodAtAx:WrongSizeOfInputArg",
            "Dimension 1 of nthreads should be no greater than 1.");
    if (mxGetNumberOfElements(prhs[4]) && mxGetDimensions(prhs[4])[1] != 1) 
        mexErrMsgIdAndTxt("crs_prodAtAx:WrongSizeOfInputArg",
            "Dimension 2 of nthreads should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[4], (emxArray__common *)(&nthreads), "nthreads", 1);

    /* Invoke the target function */
    crs_prodAtAx(&A, &x, &b, &Ax, &nthreads);

    /* Deallocate input and marshall out function outputs */
    destroy_CRS_Matrix(&A);
    free_emxArray((emxArray__common*)(&x));
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&b), mxDOUBLE_CLASS);
    mxFree(b.size);
    plhs[1] = move_emxArray_to_mxArray((emxArray__common*)(&Ax), mxDOUBLE_CLASS);
    mxFree(Ax.size);
    free_emxArray((emxArray__common*)(&nthreads));

}

static void __crs_prodAtAx_ser_api(mxArray **plhs, const mxArray ** prhs) {
    CRS_Matrix           A;
    emxArray_real_T      x;
    emxArray_real_T      b;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("crs_prodAtAx_ser:WrongInputType",
            "Input argument A has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("crs_prodAtAx_ser:WrongSizeOfInputArg",
            "Argument A should be a scalar.");
    marshallin_const_CRS_Matrix(&A, prhs[0], "A");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("crs_prodAtAx_ser:WrongInputType",
            "Input argument x has incorrect data type; double is expected.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&x), "x", 2);
    init_emxArray((emxArray__common*)(&b), 2);

    /* Invoke the target function */
    crs_prodAtAx_ser(&A, &x, &b);

    /* Deallocate input and marshall out function outputs */
    destroy_CRS_Matrix(&A);
    free_emxArray((emxArray__common*)(&x));
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&b), mxDOUBLE_CLASS);
    mxFree(b.size);

}

static void __crs_prodAtAx_ser1_api(mxArray **plhs, const mxArray ** prhs) {
    CRS_Matrix           A;
    emxArray_real_T      x;
    emxArray_real_T      b;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("crs_prodAtAx_ser1:WrongInputType",
            "Input argument A has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("crs_prodAtAx_ser1:WrongSizeOfInputArg",
            "Argument A should be a scalar.");
    marshallin_const_CRS_Matrix(&A, prhs[0], "A");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("crs_prodAtAx_ser1:WrongInputType",
            "Input argument x has incorrect data type; double is expected.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&x), "x", 2);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("crs_prodAtAx_ser1:WrongInputType",
            "Input argument b has incorrect data type; double is expected.");
    copy_mxArray_to_emxArray(prhs[2], (emxArray__common *)(&b), "b", 2);

    /* Invoke the target function */
    crs_prodAtAx_ser1(&A, &x, &b);

    /* Deallocate input and marshall out function outputs */
    destroy_CRS_Matrix(&A);
    free_emxArray((emxArray__common*)(&x));
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&b), mxDOUBLE_CLASS);
    mxFree(b.size);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2] = {NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 5) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("crs_prodAtAx:TooManyOutputArguments",
                "Too many output arguments for entry-point crs_prodAtAx.\n");
        /* Call the API function. */
        __crs_prodAtAx_api(outputs, prhs);
    }
    else if (nrhs == 2) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("crs_prodAtAx_ser:TooManyOutputArguments",
                "Too many output arguments for entry-point crs_prodAtAx_ser.\n");
        /* Call the API function. */
        __crs_prodAtAx_ser_api(outputs, prhs);
    }
    else if (nrhs == 3) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("crs_prodAtAx_ser1:TooManyOutputArguments",
                "Too many output arguments for entry-point crs_prodAtAx_ser1.\n");
        /* Call the API function. */
        __crs_prodAtAx_ser1_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("crs_prodAtAx:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point crs_prodAtAx.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
