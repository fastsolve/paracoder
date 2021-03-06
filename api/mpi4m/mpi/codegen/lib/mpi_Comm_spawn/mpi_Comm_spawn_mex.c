/*
 * mpi/codegen/lib/mpi_Comm_spawn/mpi_Comm_spawn_mex.c
 *
 * Auxiliary code for mexFunction of mpi_Comm_spawn
 *
 * C source code generated by m2c.
 * %#m2c options:aaf44063b3ec3b8ad3ceba92a0421280
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "mpi_Comm_spawn.h"
#include "mpi_Comm_spawn_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void marshallin_const_M2C_OpaqueType(M2C_OpaqueType *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "data"))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s is missing the field data.", mname);
    if (!mxGetField(mx, 0, "type"))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s is missing the field type.", mname);
    if (!mxGetField(mx, 0, "nitems"))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s is missing the field nitems.", mname);
    if (mxGetNumberOfFields(mx) > 3)
        M2C_warn("marshallin_const_M2C_OpaqueType:ExtraFields",
            "Extra fields in %s and are ignored.", mname);

    sub_mx = mxGetField(mx, 0, "data");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongInputType",
            "Input argument data has incorrect data type; uint8 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongSizeOfInputArg",
            "Dimension 2 of data should be equal to 1.");
    pStruct->data = (emxArray_uint8_T*)mxMalloc(sizeof(emxArray_uint8_T));
    init_emxArray((emxArray__common*)(pStruct->data), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->data), "data", 1);

    sub_mx = mxGetField(mx, 0, "type");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongInputType",
            "Input argument type has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[0] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongSizeOfInputArg",
            "Dimension 1 of type should be equal to 1.");
    pStruct->type = (emxArray_char_T*)mxMalloc(sizeof(emxArray_char_T));
    init_emxArray((emxArray__common*)(pStruct->type), 2);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->type), "type", 2);

    sub_mx = mxGetField(mx, 0, "nitems");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongInputType",
            "Input argument nitems has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongSizeOfInputArg",
            "Argument nitems should be a scalar.");
    pStruct->nitems = *(int32_T*)mxGetData(sub_mx);
}
static void prealloc_M2C_OpaqueType(M2C_OpaqueType *pStruct) {


    pStruct->data = (emxArray_uint8_T*)mxMalloc(sizeof(emxArray_uint8_T));
    init_emxArray((emxArray__common*)(pStruct->data), 1);

    pStruct->type = (emxArray_char_T*)mxMalloc(sizeof(emxArray_char_T));
    init_emxArray((emxArray__common*)(pStruct->type), 2);

}
static mxArray *marshallout_M2C_OpaqueType(M2C_OpaqueType *pStruct) {
    const char           *fields[] = {"data", "type", "nitems"};
    int                  one=1;
    mxArray              *mx = create_struct_mxArray(1, &one, 3, fields);

    mxSetField(mx, 0, "data", move_emxArray_to_mxArray((emxArray__common*)(pStruct->data), mxUINT8_CLASS));
    mxFree(pStruct->data->size);
    mxFree(pStruct->data);

    mxSetField(mx, 0, "type", move_emxArray_to_mxArray((emxArray__common*)(pStruct->type), mxCHAR_CLASS));
    mxFree(pStruct->type->size);
    mxFree(pStruct->type);

    mxSetField(mx, 0, "nitems", copy_scalar_to_mxArray(&pStruct->nitems, mxINT32_CLASS));
    return mx;
}
static void destroy_M2C_OpaqueType(M2C_OpaqueType *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->data));
    mxFree(pStruct->data);

    free_emxArray((emxArray__common*)(pStruct->type));
    mxFree(pStruct->type);


}


static void __mpi_Comm_spawn_api(mxArray **plhs, const mxArray ** prhs) {
    emxArray_char_T      command;
    M2C_OpaqueType       argv;
    int32_T              maxprocs;
    M2C_OpaqueType       mpiinfo;
    int32_T              root;
    M2C_OpaqueType       comm;
    M2C_OpaqueType       intercomm;
    emxArray_int32_T     errcodes;
    int32_T             *info;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongInputType",
            "Input argument command has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(prhs[0]) && mxGetDimensions(prhs[0])[0] != 1) 
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongSizeOfInputArg",
            "Dimension 1 of command should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[0], (emxArray__common *)(&command), "command", 2);

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongInputType",
            "Input argument argv has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongSizeOfInputArg",
            "Argument argv should be a scalar.");
    marshallin_const_M2C_OpaqueType(&argv, prhs[1], "argv");

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongInputType",
            "Input argument maxprocs has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongSizeOfInputArg",
            "Argument maxprocs should be a scalar.");
    maxprocs = *(int32_T*)mxGetData(prhs[2]);

    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongInputType",
            "Input argument mpiinfo has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[3]) != 1)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongSizeOfInputArg",
            "Argument mpiinfo should be a scalar.");
    marshallin_const_M2C_OpaqueType(&mpiinfo, prhs[3], "mpiinfo");

    if (mxGetNumberOfElements(prhs[4]) && mxGetClassID(prhs[4]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongInputType",
            "Input argument root has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[4]) != 1)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongSizeOfInputArg",
            "Argument root should be a scalar.");
    root = *(int32_T*)mxGetData(prhs[4]);

    if (mxGetNumberOfElements(prhs[5]) && mxGetClassID(prhs[5]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongInputType",
            "Input argument comm has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[5]) != 1)
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongSizeOfInputArg",
            "Argument comm should be a scalar.");
    marshallin_const_M2C_OpaqueType(&comm, prhs[5], "comm");
    prealloc_M2C_OpaqueType(&intercomm);
    init_emxArray((emxArray__common*)(&errcodes), 1);

    info = (int32_T*)mxMalloc(sizeof(int32_T));

    toplevel = (boolean_T*)mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    mpi_Comm_spawn(&command, &argv, maxprocs, &mpiinfo, root, &comm, &intercomm, &errcodes, info, toplevel);

    /* Deallocate input and marshall out function outputs */
    free_emxArray((emxArray__common*)(&command));
    destroy_M2C_OpaqueType(&argv);
    /* Nothing to be done for maxprocs */
    destroy_M2C_OpaqueType(&mpiinfo);
    /* Nothing to be done for root */
    destroy_M2C_OpaqueType(&comm);
    plhs[0] = marshallout_M2C_OpaqueType(&intercomm);
    plhs[1] = move_emxArray_to_mxArray((emxArray__common*)(&errcodes), mxINT32_CLASS);
    mxFree(errcodes.size);
    plhs[2] = move_scalar_to_mxArray(info, mxINT32_CLASS);
    plhs[3] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[4] = {NULL, NULL, NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 6) {
        if (nlhs > 4)
            mexErrMsgIdAndTxt("mpi_Comm_spawn:TooManyOutputArguments",
                "Too many output arguments for entry-point mpi_Comm_spawn.\n");
        /* Call the API function. */
        __mpi_Comm_spawn_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("mpi_Comm_spawn:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point mpi_Comm_spawn.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
