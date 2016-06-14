/*
 * This file contains additional helper functions for CUDA.
 */

#include <lib2mex_helper.c>

#include "mcuda.h"

/*****************************************************************
 * Copy emxArray from CPU to GPU
 *****************************************************************/
template <typename emxArray, bool hasDim>
emxArray *copy_emxArray_to_GPU(const emxArray *a, int nElems=0, int nDims=0) {
    emxArray a_buf;
    emxArray *a_gpu;
    cudaError_t ierr;
    
    /* Allocate and copy size field */
    if (hasDim) {
        nElems = a->size[0];
        for (int i=1; i<nDims; ++i)
            nElems *= a->size[i];
        
        a_buf.allocatedSize = nElems;
        a_buf.canFreeData = true;
        
        nDims = a_buf.numDimensions = a->numDimensions;
        ierr = cudaMalloc((void **)&a_buf.size, sizeof(int) * 
                    a_buf.numDimensions); CHKCUERR(ierr, "cudaMalloc");
        ierr = cudaMemcpyAsync(a_buf.size, a->size, sizeof(int) * a_buf.numDimensions,
                cudaMemcpyHostToDevice); CHKCUERR(ierr, "cudaMemcpyAsync");
    }
    else {
        nElems = a_buf.size[0] = a->size[0];
        for (int i=1; i<nDims; ++i) {
            nElems *= a_buf.size[i] = a->size[i];
        }
    }
    
    /* Allocate and copy data field */
    ierr = cudaMalloc((void **)&a_buf.data, sizeof(a->data[0]) * nElems); 
    CHKCUERR(ierr, "cudaMalloc");

    ierr = cudaMemcpyAsync(a_buf.data, a->data, sizeof(a->data[0]) * nElems, cudaMemcpyHostToDevice);
    CHKCUERR(ierr, "cudaMemcpyAsync");
    
    /* Allocate and copy the emxArray */
    ierr = cudaMalloc((void **)&a_gpu, sizeof(emxArray)); 
    CHKCUERR(ierr, "cudaMalloc");

    ierr = cudaMemcpy(a_gpu, &a_buf, sizeof(emxArray), cudaMemcpyHostToDevice); 
    CHKCUERR(ierr, "cudaMemcpy");
    
    return a_gpu;
}

/*****************************************************************
 * Wraps the data in mxArray into an emxArray on GPU.
 *****************************************************************/
template <typename emxArray>
emxArray *copy_mxArray_to_gpuEmxArray(const mxArray *mx, const char *name, int32_T dim) {
    emxArray__common a_buf;

    alias_mxArray_to_emxArray(mx, &a_buf, name, dim);
    return copy_emxArray_to_GPU<emxArray, true>((emxArray *)&a_buf);
}

/**************************************************************************
 * Copy size and data from mxArray to a preallocated static emxArray on GPU.
 **************************************************************************/
template <typename emxArray>
emxArray *copy_mxArray_to_gpuEmxArrayStatic(const mxArray *mx, 
    int32_T dim, const char *name, int32_T maxlen) {

    emxArray a_buf;

    copy_mxArray_to_DataSize(mx, a_buf.data, a_buf.size, dim, name, maxlen);
    return copy_emxArray_to_GPU<emxArray, false>((emxArray *)&a_buf);    
}

/*****************************************************************
 * Copy numeric array from CPU to GPU
 *****************************************************************/
template <typename type>
type *copy_mxArray_to_gpuArray(const mxArray *mx, const char *name, int32_T dim) {
    emxArray__common a_buf;
    type *ptr;

    alias_mxArray_to_emxArray(mx, &a_buf, name, dim);

    int nElems = a_buf.size[0];
    for (int i=1; i<dim; ++i) nElems *= a_buf.size[i];

    /* Allocate and copy data field */
    cudaError_t ierr = cudaMalloc((void **)&ptr, sizeof(type) * nElems);
    CHKCUERR(ierr, "cudaMalloc");

    ierr = cudaMemcpyAsync(ptr, a_buf.data, sizeof(type) * nElems, 
                           cudaMemcpyHostToDevice);
    CHKCUERR(ierr, "cudaMemcpy");

    free_emxArray(&a_buf);
    return ptr;
}

/*****************************************************************
 * Copy numeric array from CPU to GPU
 *****************************************************************/
template <typename type>
void copy_mxArray_to_gpuDataSize(type **data, int nDims, int **size, const mxArray *mx) {

    int *dims = (int*)mxMalloc(nDims);

    int nElems = 1;
    for (int i=0; i<nDims; ++i) 
        nElems *= dims[i] = mxGetDimensions(mx)[i];

    /* Allocate and copy data field */
    cudaError_t ierr = cudaMalloc((void **)data, sizeof(type) * nElems);
    CHKCUERR(ierr, "cudaMalloc");
    
    ierr = cudaMemcpyAsync(*data, mxGetData(mx), sizeof(type) * nElems,
            cudaMemcpyHostToDevice);
    CHKCUERR(ierr, "cudaMemcpyAsync");
    
    ierr = cudaMalloc((void **)size, sizeof(int) * nDims);
    CHKCUERR(ierr, "cudaMalloc");
    
    ierr = cudaMemcpyAsync(*size, dims, sizeof(int) * nDims,
            cudaMemcpyHostToDevice);
    CHKCUERR(ierr, "cudaMemcpyAsync");
            
    mxFree(dims);
    return;
}

/*****************************************************************
 * Wrap GPU array into an emxArray
 *****************************************************************/
template <typename emxArray, bool hasDim>
emxArray *wrap_mxArray_to_gpuEmxArray(const mxArray *mx) {
    
    emxArray a_buf;
    cudaError_t ierr;
    
    *(void **)&a_buf.data = *(void **)mxGetData(mxGetFieldByNumber(mx, 0, 0));
    
    int nDims = mxGetNumberOfElements(mxGetFieldByNumber(mx, 0, 2));
    int *dims = (int*)mxGetData(mxGetFieldByNumber(mx, 0, 2));
            
    /* Allocate and copy size field */
    if (hasDim) {
        a_buf.numDimensions = nDims;

        ierr= cudaMalloc((void **)&a_buf.size, sizeof(int) * nDims);
        CHKCUERR(ierr, "cudaMalloc");
        ierr = cudaMemcpy(a_buf.size, dims, sizeof(int) * nDims,
                cudaMemcpyHostToDevice);
        CHKCUERR(ierr, "cudaMemcpy");

        int nElems = dims[0];
        for (int i=1; i<nDims; ++i) nElems *= dims[i];
        
        a_buf.allocatedSize = nElems;
        /* The emxArray takes the ownership of the GPU Array*/
        a_buf.canFreeData = true;
    }
    else {
        for (int i=0; i<nDims; ++i) {
            a_buf.size[i] = dims[i];
        }
    }

    emxArray *a_gpu;
    ierr = cudaMemcpy(a_gpu, &a_buf, sizeof(emxArray), cudaMemcpyHostToDevice);
    CHKCUERR(ierr, "cudaMemcpy");

    return a_gpu;
}

/*****************************************************************
 * Wrap GPU array into an emxArray
 *****************************************************************/
template <typename type>
void wrap_mxArray_to_gpuDataSize(type **data, int **size, const mxArray *mx) {
    
    *(void **)data = *(void **)mxGetData(mxGetFieldByNumber(mx, 0, 0));
    
    int nDims = mxGetNumberOfElements(mxGetFieldByNumber(mx, 0, 2));
    int *dims = (int*)mxGetData(mxGetFieldByNumber(mx, 0, 2));

    cudaError_t ierr = cudaMalloc((void **)size, sizeof(int) * nDims);
    CHKCUERR(ierr, "cudaMalloc");

    ierr = cudaMemcpy(*size, dims, sizeof(int) * nDims,
            cudaMemcpyHostToDevice); 
    CHKCUERR(ierr, "cudaMemcpy");

    return;
}

/*****************************************************************
 * Copy a GPU DataSize to a CPU mxArray
 *****************************************************************/
template <typename type>
mxArray *copy_gpuDataSize_to_mxArray(type *data_gpu, int nDims, 
        int *size_gpu, mxClassID mtype) {
 
    emxArray__common a_buf;
    init_emxArray(&a_buf, nDims);

    cudaError_t ierr = cudaMemcpy(a_buf.size, size_gpu, sizeof(int) * nDims,
            cudaMemcpyDeviceToHost); CHKCUERR(ierr, "cudaMemcpy");

    int nElems = a_buf.size[0];
    for (int i=1; i<nDims; ++i) nElems *= a_buf.size[i];

    /* Copy data field */    
    emxEnsureCapacity(&a_buf, 0, sizeof(type));
    ierr = cudaMemcpy(a_buf.data, data_gpu, sizeof(type) * nElems,
            cudaMemcpyDeviceToHost); CHKCUERR(ierr, "cudaMemcpy");

    mxArray *mx = move_emxArray_to_mxArray(&a_buf, mtype);

    mxFree(a_buf.size);    
    return mx;
}

/*****************************************************************
 * Copy an emxArray on GPU to a CPU mxArray
 *****************************************************************/
template <typename emxArray>
mxArray *copy_gpuEmxArray_to_mxArray(emxArray *a_gpu, mxClassID type) {
    emxArray__common a_buf;

    /* Copy emxArray */
    cudaError_t ierr = cudaMemcpy(&a_buf, a_gpu, sizeof(emxArray), 
                cudaMemcpyDeviceToHost); CHKCUERR(ierr, "cudaMemcpy");

    /* Copy size field */
    void *data_gpu = a_buf.data;
    int *size_gpu = a_buf.size;
    int nDims = a_buf.numDimensions;
    
    init_emxArray(&a_buf, nDims);
    ierr = cudaMemcpy(a_buf.size, size_gpu, sizeof(int) * nDims,
            cudaMemcpyDeviceToHost); CHKCUERR(ierr, "cudaMemcpy");
    
    int nElems = a_buf.size[0];
    for (int i=1; i<nDims; ++i) nElems *= a_buf.size[i];

    /* Copy data field */    
    emxEnsureCapacity(&a_buf, 0, sizeof(*a_gpu->data));
    ierr = cudaMemcpy(a_buf.data, data_gpu, sizeof(*a_gpu->data) * nElems,
            cudaMemcpyDeviceToHost); CHKCUERR(ierr, "cudaMemcpy");

    mxArray *mx = move_emxArray_to_mxArray(&a_buf, type);

    mxFree(a_buf.size);    
    return mx;
}

/*****************************************************************
 * Copy a plain GPU array to a CPU mxArray
 *****************************************************************/
template <typename type>
mxArray *copy_gpuArray_to_mxArray(type *a_gpu, const mxArray *mx_in) {
    mxArray *mx = mxDuplicateArray(mx_in);
    cudaError_t ierr;
    
    /* Get size information */
    int nElems = mxGetNumberOfElements(mx);
    
    if (mxGetClassID(mx) == mxCHAR_CLASS) {
        /* Copy character string manually */
        char *buf = (char *)mxMalloc(nElems+1);
        
        ierr = cudaMemcpy(buf, a_gpu, nElems, cudaMemcpyDeviceToHost);        

        mxChar *data = (mxChar *)mxGetData(mx);
        for (int i=0; i<nElems; ++i) data[i] = buf[i];
        
        mxFree(buf);
    }
    else {
        ierr = cudaMemcpyAsync(mxGetData(mx), a_gpu,
                nElems * mxGetElementSize(mx), cudaMemcpyDeviceToHost);
    }
    
    CHKCUERR(ierr, "cudaMemcpy");
    
    return mx;
}

/*****************************************************************
 * Copy GPU pointer and update size
 *****************************************************************/
template <typename emxArray>
mxArray *update_mxArray_from_gpuEmxArray(const emxArray *a_gpu, 
        const mxArray *mx_in) {
    emxArray__common a_buf;

    /* Copy emxArray */
    cudaError_t ierr = cudaMemcpy(&a_buf, a_gpu, sizeof(emxArray), 
                cudaMemcpyDeviceToHost); CHKCUERR(ierr, "cudaMemcpy");

    /* Copy size field from GPU to CPU */
    int nDims = a_buf.numDimensions;

    mxArray *mx = mxDuplicateArray(mx_in);

    /* Update data and size field */    
    ierr = cudaMemcpy(mxGetData(mxGetFieldByNumber(mx, 0, 0)),
            a_buf.data, sizeof(int64_T), cudaMemcpyDeviceToHost);
    ierr = cudaMemcpy(mxGetData(mxGetFieldByNumber(mx, 0, 2)),
            a_buf.size, sizeof(int) * nDims, cudaMemcpyDeviceToHost);
    CHKCUERR(ierr, "cudaMemcpy");

    return mx;
}

/*****************************************************************
 * Wrap GPU array into an emxArray
 *****************************************************************/
mxArray *update_mxArray_from_gpuSize(int nDims, int *size_gpu,
        const mxArray *mx_in) {
    /* Update size field */    
    mxArray *mx = mxDuplicateArray(mx_in);

    cudaError_t ierr = cudaMemcpy(mxGetData(mxGetFieldByNumber(mx, 0, 2)), 
            size_gpu, sizeof(int) * nDims, cudaMemcpyDeviceToHost); 
    CHKCUERR(ierr, "cudaMemcpy");
    return mx;
}

/*****************************************************************
 * Destroy an array on GPU
 *****************************************************************/
template <typename emxArray, bool hasDim>
void destroy_gpuEmxArray(emxArray *a_gpu, bool freeData=true) {
    cudaError_t ierr;
    emxArray a_buf;

    ierr = cudaMemcpy(&a_buf, a_gpu, sizeof(emxArray), cudaMemcpyDeviceToHost);
    CHKCUERR(ierr, "cudaMemcpy");

    /* Destroy size and data fields */
    if (hasDim) {
        ierr = cudaFree(a_buf.size); CHKCUERR(ierr, "cudaFree");
        if (a_buf.canFreeData) {
            ierr = cudaFree(a_buf.data); CHKCUERR(ierr, "cudaFree");
        }
    }
    else if (freeData) {
        ierr = cudaFree(a_buf.data); CHKCUERR(ierr, "cudaFree");
    }

    ierr = cudaFree(a_gpu); CHKCUERR(ierr, "cudaFree");
}
