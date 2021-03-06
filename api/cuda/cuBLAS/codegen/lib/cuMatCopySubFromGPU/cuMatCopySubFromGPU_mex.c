/*
 * cuMatCopySubFromGPU_mex.c
 *
 * Auxiliary code for mexFunction of cuMatCopySubFromGPU
 *
 * C source code generated by m2c.
 * %#m2c options:3b19fd523b8adb887cd08dee68ea8b05
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "cuMatCopySubFromGPU.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void marshallin_struct0_T(struct0_T *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "data"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field data.", mname);
    if (!mxGetField(mx, 0, "type"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field type.", mname);
    if (!mxGetField(mx, 0, "dims"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field dims.", mname);
    if (mxGetNumberOfFields(mx) > 3)
        M2C_warn("marshallin_const_struct0_T:ExtraFields",
            "Extra fields in %s and are ignored.", mname);

    sub_mx = mxGetField(mx, 0, "data");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxUINT64_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument data has incorrect data type; uint64 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Argument data should be a scalar.");
    pStruct->data = *(uint64_T*)mxGetData(sub_mx);

    sub_mx = mxGetField(mx, 0, "type");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument type has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Argument type should be a scalar.");
    pStruct->type = *(int32_T*)mxGetData(sub_mx);

    sub_mx = mxGetField(mx, 0, "dims");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument dims has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[0] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 1 of dims should equal 1.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 2) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 2 of dims should equal 2.");
    copy_mxArray_to_DataSize(pStruct->dims, 2, NULL, sub_mx, "dims", 2);
}



static void marshallin_const_struct1_T(struct1_T *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_struct1_T:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "data"))
        M2C_error("marshallin_const_struct1_T:WrongType",
            "Input argument %s is missing the field data.", mname);
    if (!mxGetField(mx, 0, "type"))
        M2C_error("marshallin_const_struct1_T:WrongType",
            "Input argument %s is missing the field type.", mname);
    if (!mxGetField(mx, 0, "nitems"))
        M2C_error("marshallin_const_struct1_T:WrongType",
            "Input argument %s is missing the field nitems.", mname);
    if (mxGetNumberOfFields(mx) > 3)
        M2C_warn("marshallin_const_struct1_T:ExtraFields",
            "Extra fields in %s and are ignored.", mname);

    sub_mx = mxGetField(mx, 0, "data");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct1_T:WrongInputType",
            "Input argument data has incorrect data type; uint8 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct1_T:WrongSizeOfInputArg",
            "Dimension 2 of data should equal 1.");
    pStruct->data = mxMalloc(sizeof(emxArray_uint8_T));
    init_emxArray((emxArray__common*)(pStruct->data), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->data), "data", 1);

    sub_mx = mxGetField(mx, 0, "type");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct1_T:WrongInputType",
            "Input argument type has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[0] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct1_T:WrongSizeOfInputArg",
            "Dimension 1 of type should equal 1.");
    pStruct->type = mxMalloc(sizeof(emxArray_char_T));
    init_emxArray((emxArray__common*)(pStruct->type), 2);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->type), "type", 2);

    sub_mx = mxGetField(mx, 0, "nitems");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct1_T:WrongInputType",
            "Input argument nitems has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_struct1_T:WrongSizeOfInputArg",
            "Argument nitems should be a scalar.");
    pStruct->nitems = *(int32_T*)mxGetData(sub_mx);
}
static void destroy_struct1_T(struct1_T *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->data));
    mxFree(pStruct->data);

    free_emxArray((emxArray__common*)(pStruct->type));
    mxFree(pStruct->type);


}


static void __cuMatCopySubFromGPU_api(mxArray **plhs, const mxArray ** prhs) {
    int32_T              nrows;
    int32_T              ncols;
    struct0_T            cuMat;
    emxArray_real_T      mat;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU:WrongInputType",
            "Input argument nrows has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU:WrongSizeOfInputArg",
            "Argument nrows should be a scalar.");
    nrows = *(int32_T*)mxGetData(prhs[0]);

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU:WrongInputType",
            "Input argument ncols has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU:WrongSizeOfInputArg",
            "Argument ncols should be a scalar.");
    ncols = *(int32_T*)mxGetData(prhs[1]);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU:WrongInputType",
            "Input argument cuMat has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU:WrongSizeOfInputArg",
            "Argument cuMat should be a scalar.");
    marshallin_struct0_T(&cuMat, prhs[2], "cuMat");

    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU:WrongInputType",
            "Input argument mat has incorrect data type; double is expected.");
    copy_mxArray_to_emxArray(prhs[3], (emxArray__common *)(&mat), "mat", 2);

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    cuMatCopySubFromGPU(nrows, ncols, &cuMat, &mat, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    /* Nothing to be done for nrows */
    /* Nothing to be done for ncols */
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&mat), mxDOUBLE_CLASS);
    mxFree(mat.size);
    plhs[1] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}

static void __cuMatCopySubFromGPU_async_api(mxArray **plhs, const mxArray ** prhs) {
    int32_T              nrows;
    int32_T              ncols;
    struct0_T            cuMat;
    emxArray_real_T      mat;
    struct1_T            strm;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU_async:WrongInputType",
            "Input argument nrows has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU_async:WrongSizeOfInputArg",
            "Argument nrows should be a scalar.");
    nrows = *(int32_T*)mxGetData(prhs[0]);

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU_async:WrongInputType",
            "Input argument ncols has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU_async:WrongSizeOfInputArg",
            "Argument ncols should be a scalar.");
    ncols = *(int32_T*)mxGetData(prhs[1]);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU_async:WrongInputType",
            "Input argument cuMat has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU_async:WrongSizeOfInputArg",
            "Argument cuMat should be a scalar.");
    marshallin_struct0_T(&cuMat, prhs[2], "cuMat");

    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU_async:WrongInputType",
            "Input argument mat has incorrect data type; double is expected.");
    copy_mxArray_to_emxArray(prhs[3], (emxArray__common *)(&mat), "mat", 2);

    if (mxGetNumberOfElements(prhs[4]) && mxGetClassID(prhs[4]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU_async:WrongInputType",
            "Input argument strm has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[4]) != 1)
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU_async:WrongSizeOfInputArg",
            "Argument strm should be a scalar.");
    marshallin_const_struct1_T(&strm, prhs[4], "strm");

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    cuMatCopySubFromGPU_async(nrows, ncols, &cuMat, &mat, &strm, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    /* Nothing to be done for nrows */
    /* Nothing to be done for ncols */
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&mat), mxDOUBLE_CLASS);
    mxFree(mat.size);
    destroy_struct1_T(&strm);
    plhs[1] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 4) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("cuMatCopySubFromGPU:TooManyOutputArguments",
                "Too many output arguments for entry-point cuMatCopySubFromGPU.\n");
        /* Call the API function. */
        __cuMatCopySubFromGPU_api(outputs, prhs);
    }
    else if (nrhs == 5) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("cuMatCopySubFromGPU_async:TooManyOutputArguments",
                "Too many output arguments for entry-point cuMatCopySubFromGPU_async.\n");
        /* Call the API function. */
        __cuMatCopySubFromGPU_async_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("cuMatCopySubFromGPU:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point cuMatCopySubFromGPU.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
