/*
 * This file contains some helper functions used by the MEX wrapper
 * generated by lib2mex.
 */

#include <string.h>
#include <stdio.h>

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common
{
    void *data;
    int *size;
    int allocatedSize;
    int numDimensions;
    boolean_T canFreeData;
} emxArray__common;

#endif

#ifdef CGEN_MAXDIM
#undef CGEN_MAXDIM
#endif
#define CGEN_MAXDIM 10

static int numElements(int nDims, const int *dims) {
    int      i, nElems=dims[0];
    
    for (i=1; i<nDims; ++i)
        nElems *= dims[i];
    
    return nElems;
}

/*****************************************************************
 * Initialize an emxArray.
 *****************************************************************/
void init_emxArray(emxArray__common *emx, int dim) {
    emx->data = NULL;
    emx->numDimensions = dim;
    emx->size = (int*)mxCalloc(dim, sizeof(int));
    emx->allocatedSize = 0;
    emx->canFreeData = 1;
}

/*****************************************************************
 * Free up space allocated for emx.
 *****************************************************************/
void free_emxArray(emxArray__common *emx) {
    if (emx->canFreeData && emx->data) mxFree(emx->data);
    if (emx->size) mxFree(emx->size);
    emx->data = NULL; emx->size=NULL;
    emx->allocatedSize=0; emx->canFreeData=0;
}

/*****************************************************************
 * Initialize dimension of emxArray from mxArray.
 *****************************************************************/
void init_emxArray_from_mxArray(const mxArray *a, emxArray__common *emx,
        const char *name, int dim) {
    
    const mwSize *dims = mxGetDimensions(a);
    int   i, mxdim = mxGetNumberOfDimensions(a);
    
    init_emxArray(emx, dim);
    
    if (mxGetNumberOfElements(a)==0) return;
    
    /* Check the compatibility of the mxArray */
    if (mxdim>dim) {
        for (i=dim; i<mxdim; ++i) {
            if (dims[i]!=1) {
                M2C_error("m2c:WrongDimension",
                        "Varialble %s has incorrect dimension.", name);
            }
        }
        mxdim = dim;
    }
    
    /* copy dimension */
    for (i=0; i<mxdim; ++i) emx->size[i] = dims[i];
    for (i=mxdim; i<dim; ++i) emx->size[i] = 1;
}

/*****************************************************************
 * Initialize dimension of emxArray from mxArray.
 *****************************************************************/
void alloc_emxArray_from_mxArray(const mxArray *a, emxArray__common *emx,
        const char *name, int dim, int sizepe) {
    
    init_emxArray_from_mxArray(a, emx, name, dim);

    if (mxGetClassID(a) == mxCHAR_CLASS) {
        emx->allocatedSize = mxGetNumberOfElements(a) + (mxGetClassID(a) == mxCHAR_CLASS);
        emx->data = mxCalloc(emx->allocatedSize, 1);
    } else {
        emx->allocatedSize = mxGetNumberOfElements(a);
        emx->data = mxCalloc(emx->allocatedSize, sizepe);
    }
            
    emx->canFreeData = 1;
}

/*****************************************************************
 * Alias an mxArray to data and size fields separately
 *****************************************************************/
static void alias_mxArray_to_DataSize(void **data, int dim, int *size,
        const mxArray *a, const char *name, int maxlen) {
    
    mxClassID type=mxGetClassID(a);
    const mwSize *dims = mxGetDimensions(a);
    int   i, mxdim = mxGetNumberOfDimensions(a);
    
    /* Check the compatibility of the mxArray */
    if (mxdim>dim) {
        for (i=dim; i<mxdim; ++i) {
            if (dims[i]!=1) {
                M2C_error("m2c:WrongDimension",
                        "Varialble %s has incorrect dimension.", name);
            }
        }
        mxdim = dim;
    }
    
    /* copy dimension */
    if (size) {
        for (i=0; i<mxdim; ++i) size[i] = dims[i];
        for (i=mxdim; i<dim; ++i) size[i] = 1;
    }
    
    switch (type) {
        case mxLOGICAL_CLASS:
        case mxDOUBLE_CLASS:
        case mxSINGLE_CLASS:
        case mxINT8_CLASS:
        case mxUINT8_CLASS:
        case mxINT16_CLASS:
        case mxUINT16_CLASS:
        case mxINT32_CLASS:
        case mxUINT32_CLASS:
        case mxINT64_CLASS:
        case mxUINT64_CLASS:
            *data = mxGetData(a);
            break;
        case mxCHAR_CLASS: {
            if (maxlen==0)
                maxlen = mxGetNumberOfElements(a);
            
            /* Data was preallocated by m2c to size maxsize+1. */
            mxGetString(a, (char*)*data, maxlen+1);
            break;
        }
        case mxSTRUCT_CLASS:
            mxAssert(0, "mxSTRUCT_CLASS is not supported.");
        case mxFUNCTION_CLASS:
            mxAssert(0, "mxFUNCTION_CLASS is not supported.");
        default:
            mxAssert(0, "Unsupported data type.");
    }
}

/*****************************************************************
 * Wrap the data in mxArray into emxArray.
 * Data within emxArray is overwritten.
 *****************************************************************/
static void alias_mxArray_to_emxArray(const mxArray *a, emxArray__common *emx,
        const char *name, int dim) {
    mxClassID type=mxGetClassID(a);    
   
    switch (type) {
        case mxLOGICAL_CLASS:
        case mxDOUBLE_CLASS:
        case mxSINGLE_CLASS:
        case mxINT8_CLASS:
        case mxUINT8_CLASS:
        case mxINT16_CLASS:
        case mxUINT16_CLASS:
        case mxINT32_CLASS:
        case mxUINT32_CLASS:
        case mxINT64_CLASS:
        case mxUINT64_CLASS:
            init_emxArray_from_mxArray(a, emx, name, dim);
            
            emx->allocatedSize = mxGetNumberOfElements(a);
            if (emx->allocatedSize) emx->data = mxGetData(a);
            emx->canFreeData = 0;
            break;
        case mxCHAR_CLASS:
            alloc_emxArray_from_mxArray(a, emx, name, dim, 1);
            
            mxGetString(a, (char*)emx->data, emx->allocatedSize);
            break;
        case mxSTRUCT_CLASS:
            mxAssert(0, "mxSTRUCT_CLASS is not supported.");
        case mxFUNCTION_CLASS:
            mxAssert(0, "mxFUNCTION_CLASS is not supported.");
        default:
            mxAssert(0, "Unsupported data type.");
    }
}

/*****************************************************************
 * Copy data in mxArray into emxArray.
 * Data within emxArray is overwritten.
 *****************************************************************/
static void copy_mxArray_to_emxArray(const mxArray *a, emxArray__common *emx,
        const char *name, int dim) {
    mxClassID type=mxGetClassID(a);
    
    alloc_emxArray_from_mxArray(a, emx, name, dim, mxGetElementSize(a));
    
    switch (type) {
        case mxLOGICAL_CLASS:
        case mxDOUBLE_CLASS:
        case mxSINGLE_CLASS:
        case mxINT8_CLASS:
        case mxUINT8_CLASS:
        case mxINT16_CLASS:
        case mxUINT16_CLASS:
        case mxINT32_CLASS:
        case mxUINT32_CLASS:
        case mxINT64_CLASS:
        case mxUINT64_CLASS:
            memcpy(emx->data, mxGetData(a), emx->allocatedSize * mxGetElementSize(a));
            break;
        case mxCHAR_CLASS:
            mxGetString(a, (char*)emx->data, emx->allocatedSize);
            break;
        case mxSTRUCT_CLASS:
            mxAssert(0, "mxSTRUCT_CLASS is not supported.");
        case mxFUNCTION_CLASS:
            mxAssert(0, "mxFUNCTION_CLASS is not supported.");
        default:
            mxAssert(0, "Unsupported data type.");
    }
}

/*****************************************************************
 * Copy size and data from mxArray to a preallocated static emxArray.
 *****************************************************************/
static void copy_mxArray_to_DataSize(void *data, int dim, int *size,
        const mxArray *a, const char *name, int maxlen) {
    /* if maxlen==0, there is no limit. */
    
    mxClassID type=mxGetClassID(a);
    int   i, mxdim = mxGetNumberOfDimensions(a);
    const mwSize *dims = mxGetDimensions(a);
    int   n = mxGetNumberOfElements(a);
    
    if (n==0) {
        if (size) {
            for (i=dim; i<mxdim; ++i)
                size[i] = 0;
        }
        return;
    }
    /* Check the compatibility of the mxArray */
    if (mxdim>dim) {
        for (i=dim; i<mxdim; ++i) {
            if (dims[i]!=1) {
                M2C_error("m2c:WrongDimension",
                        "Varialble %s has incorrect dimension.", name);
            }
        }
        mxdim = dim;
    }
    
    /* Copy the size from mxArray to emxArray */
    if (size) {
        for (i=0; i<mxdim; ++i) size[i] = dims[i];
        for (i=mxdim; i<dim; ++i) size[i] = 1;
    }
    
    switch (type) {
        case mxLOGICAL_CLASS:
        case mxDOUBLE_CLASS:
        case mxSINGLE_CLASS:
        case mxINT8_CLASS:
        case mxUINT8_CLASS:
        case mxINT16_CLASS:
        case mxUINT16_CLASS:
        case mxINT32_CLASS:
        case mxUINT32_CLASS:
        case mxINT64_CLASS:
        case mxUINT64_CLASS: {
            if (maxlen && n>maxlen) n=maxlen;
            
            memcpy(data, mxGetData(a), n*mxGetElementSize(a));
            break;
        }
        case mxCHAR_CLASS:
            if (maxlen==0)
                maxlen = mxGetNumberOfElements(a);

            mxGetString(a, (char*)data, maxlen+1);
            break;
        case mxSTRUCT_CLASS:
            mxAssert(0, "mxSTRUCT_CLASS is not supported.");
        case mxFUNCTION_CLASS:
            mxAssert(0, "mxFUNCTION_CLASS is not supported.");
        default:
            mxAssert(0, "Unsupported data type.");
    }
}

/*****************************************************************
 * Copy data from a scalar into mxArray. The function should be used
 * only at the end of a mex wrapper.
 *****************************************************************/
static mxArray *copy_scalar_to_mxArray(const void *s, mxClassID type) {
    mxArray *a = NULL;
    const mwSize  ones[2]={1,1};
    
    switch (type) {
        case mxLOGICAL_CLASS:
            a = mxCreateLogicalArray(2, ones);
            *(boolean_T*)mxGetData(a) = *(const boolean_T*)s;
            break;
        case mxCHAR_CLASS: {
            a = mxCreateCharArray(2, ones);
            *(mxChar*)mxGetData(a) = *(const char*)s;
            break;
        }
        case mxDOUBLE_CLASS:
            a = mxCreateNumericArray(2, ones, type, mxREAL);
            *(double*)mxGetData(a) = *(const double*)s;
            break;
        case mxSINGLE_CLASS:
            a = mxCreateNumericArray(2, ones, type, mxREAL);
            *(float*)mxGetData(a) = *(const float*)s;
            break;
        case mxINT8_CLASS:
        case mxUINT8_CLASS:
            a = mxCreateNumericArray(2, ones, type, mxREAL);
            *(char*)mxGetData(a) = *(const char*)s;
            break;
        case mxINT16_CLASS:
        case mxUINT16_CLASS:
            a = mxCreateNumericArray(2, ones, type, mxREAL);
            *(short*)mxGetData(a) = *(const short*)s;
            break;
        case mxINT32_CLASS:
        case mxUINT32_CLASS:
            a = mxCreateNumericArray(2, ones, type, mxREAL);
            *(int*)mxGetData(a) = *(const int*)s;
            break;
        case mxINT64_CLASS:
        case mxUINT64_CLASS:
            a = mxCreateNumericArray(2, ones, type, mxREAL);
            *(int64_T*)mxGetData(a) = *(const int64_T*)s;
            break;
        case mxFUNCTION_CLASS:
            mxAssert(0, "mxFUNCTION_CLASS is not supported.");
        default:
            mxAssert(0, "Unsupported data type.");
    }
    
    return a;
}

/*****************************************************************
 * Copy data from an array into mxArray.
 *****************************************************************/
static mxArray *copy_DataSize_to_mxArray(void *s, mxClassID type,
        int dim, const mwSize *dims) {
    mxArray *a=NULL;
    
    switch (type) {
        case mxLOGICAL_CLASS:
        case mxDOUBLE_CLASS:
        case mxSINGLE_CLASS:
        case mxINT8_CLASS:
        case mxUINT8_CLASS:
        case mxINT16_CLASS:
        case mxUINT16_CLASS:
        case mxINT32_CLASS:
        case mxUINT32_CLASS:
        case mxINT64_CLASS:
        case mxUINT64_CLASS: {
            a = (type==mxLOGICAL_CLASS) ?
                mxCreateLogicalArray(dim, dims) :
                mxCreateNumericArray(dim, dims, type, mxREAL);
                
            if (s) {
                memcpy(mxGetData(a), s, mxGetNumberOfElements(a)*mxGetElementSize(a));
            }
            break;
        }
        case mxCHAR_CLASS: {
            mxChar  *d;
            char    *p = (char*)s;
            int     len=1, i;
            int     j;
            
            a = mxCreateCharArray(dim, dims);
            
            if (s) {
                d = (mxChar*)mxGetData(a);
                for (j=0; j<dim; ++j) len*=dims[j];
                for (i=0; i<len; ++i) d[i] = p[i];
            }
            break;
        }
        case mxSTRUCT_CLASS:
            mxAssert(0, "mxSTRUCT_CLASS is not yet supported.");
            break;
        case mxFUNCTION_CLASS:
            mxAssert(0, "mxFUNCTION_CLASS is not yet supported.");
        default:
            mxAssert(0, "Unsupported data type.");
    }
    
    return a;
}

/*****************************************************************
 * Copy data from an array into mxArray.
 *****************************************************************/
static mxArray *copy_array_to_mxArray(void *s, mxClassID type,
        int dim, const int *size) {
    mxArray *a=NULL;
    mwSize   dims_buf[CGEN_MAXDIM];
    mwSize  *dims=NULL;
    
    if  (dim==1) {
        dims = dims_buf; dims[0] = size[0]; dims[1] = 1; dim = 2;
    }
    else if (sizeof(mwSize) == sizeof(*size))
        dims = (mwSize*)size;
    else {
        int      i;
        dims = (dim<=CGEN_MAXDIM)? dims_buf: (mwSize *)mxMalloc(sizeof(mwSize)*dim);
        for (i=0; i<dim; ++i) dims[i] = size[i];
    }
    
    a = copy_DataSize_to_mxArray(s, type, dim, dims);
    
    if (dims != (mwSize*)size && dims != dims_buf) mxFree(dims);
    return a;
}

/*****************************************************************
 * Resize mxArray without reallocation
 *****************************************************************/
static void resize_mxArray(mxArray *a, int dim, const int *size) {
    mwSize   dims_buf[CGEN_MAXDIM];
    mwSize  *dims=NULL;
    int      i;
    
    if  (dim==1) {
        dims = dims_buf; dims[0] = size[0]; dims[1] = 1; dim = 2;
    }
    else if (sizeof(mwSize) == sizeof(*size))
        dims = (mwSize*)size;
    else {
        dims = (dim<=CGEN_MAXDIM)? dims_buf: (mwSize *)mxMalloc(sizeof(mwSize)*dim);
        for (i=0; i<dim; ++i) dims[i] = size[i];
    }
    
    mxSetDimensions(a, dims, dim);
    
    if (dims != (mwSize*)size && dims != dims_buf) mxFree(dims);
}

/*****************************************************************
 * Create a struct array.
 *****************************************************************/
static mxArray *create_struct_mxArray(int dim, const int *size,
        int nfields, const char **fields) {
    mxArray *a=NULL;
    mwSize   dims_buf[CGEN_MAXDIM];
    mwSize  *dims=NULL;
    int      i;
    
    if  (dim==1) {
        dims = dims_buf; dims[0] = size[0]; dims[1] = 1; dim = 2;
    }
    else if (sizeof(mwSize) == sizeof(*size))
        dims = (mwSize*)size;
    else {
        dims = (dim<=CGEN_MAXDIM)? dims_buf: (mwSize *)mxMalloc(sizeof(mwSize)*dim);
        for (i=0; i<dim; ++i) dims[i] = size[i];
    }
    
    a = mxCreateStructArray(dim, dims, nfields, fields);
    if (dims != (mwSize*)size && dims != dims_buf) mxFree(dims);
    return a;
}

/*****************************************************************
 * Move data and size into mxArray.
 *****************************************************************/
static mxArray *move_array_to_mxArray(void *data, mxClassID type,
        int dim, const int *size) {
    mxArray *a=NULL;
    mwSize   dims_buf[CGEN_MAXDIM];
    mwSize  *dims;
    int      i;
    
    /* Always use copy for robustness */
#ifdef HAVE_OCTAVE
    a = copy_array_to_mxArray(data, type, dim, size);
    mxFree(data);
    return a;
#endif
    
    if  (dim==1) {
        dims = dims_buf; dims[0] = size[0]; dims[1] = 1; dim = 2;
    }
    else if (sizeof(mwSize) == sizeof(int))
        dims = (mwSize*)size;
    else {
        dims = (dim<=CGEN_MAXDIM)? dims_buf: (mwSize *)mxMalloc(sizeof(mwSize)*dim);
        for (i=0; i<dim; ++i) dims[i] = size[i];
    }
    
    switch (type) {
        case mxDOUBLE_CLASS:
        case mxSINGLE_CLASS:
        case mxINT8_CLASS:
        case mxUINT8_CLASS:
        case mxINT16_CLASS:
        case mxUINT16_CLASS:
        case mxINT32_CLASS:
        case mxUINT32_CLASS:
        case mxINT64_CLASS:
        case mxUINT64_CLASS:
        case mxLOGICAL_CLASS: {
            /* The allocated size must be equal to the dimension */
            a = (type != mxLOGICAL_CLASS) ? mxCreateNumericArray(0, 0, type, mxREAL) :
                mxCreateLogicalArray(0, 0);
                
            if (data) {
                /* Set pointer */
                mxSetData(a, data);
            }
            /* Set size */
            mxSetDimensions(a, dims, dim);
            break;
        }
        case mxCHAR_CLASS: {
            mxChar  *d;
            int      len=1;
            
            a = mxCreateCharArray(dim, dims);
            for (i=0; i<dim; ++i) len*=dims[i];
            
            if (data) {
                char    *p = (char*)data;
                d = (mxChar*)mxGetData(a);
                for (i=0; i<len; ++i) d[i] = p[i];
            }
            break;
        }
        case mxSTRUCT_CLASS:
            mxAssert(0, "mxSTRUCT_CLASS is not supported.");
        case mxFUNCTION_CLASS:
            mxAssert(0, "mxFUNCTION_CLASS is not supported.");
        default:
            mxAssert(0, "Unsupported data type.");
    }
    
    if (dims != (mwSize*)size && dims != dims_buf) mxFree(dims);
    return a;
}

/*****************************************************************
 * Move data and size into mxArray.
 *****************************************************************/
static mxArray *move_scalar_to_mxArray(void *data, mxClassID type) {
    int one=1;
    return move_array_to_mxArray(data, type, 1, &one);
}

/*****************************************************************
 * Move data from emxArray into mxArray. The function should be used
 * only at the end of a mex wrapper to transfer ownership of data.
 * It is assumed that the data in mxArray are allocated using mxMalloc,
 * mxCalloc, or mxRelloc.
 *****************************************************************/
static mxArray *move_emxArray_to_mxArray(emxArray__common *emx, mxClassID type) {
    mxArray *a;
    
    a = move_array_to_mxArray(emx->data, type, emx->numDimensions, emx->size);
    emx->data = NULL;
    emx->canFreeData = 0;
    
    return a;
}

/*****************************************************************
 * Move data from an array into mxArray.
 *****************************************************************/
static mxArray *move_ioArray_to_mxArray(void *s, mxClassID type,
        const mxArray *rhs) {
    mxArray *a=NULL;
    int      dim = mxGetNumberOfDimensions(rhs);
    const mwSize  *dims = mxGetDimensions(rhs);
    
    /* Always use copy for robustness */
#ifdef HAVE_OCTAVE
    a = copy_DataSize_to_mxArray(s, type, dim, dims);
    mxFree(s);
    return a;
#endif
    
    switch (type) {
        case mxDOUBLE_CLASS:
        case mxSINGLE_CLASS:
        case mxINT8_CLASS:
        case mxUINT8_CLASS:
        case mxINT16_CLASS:
        case mxUINT16_CLASS:
        case mxINT32_CLASS:
        case mxUINT32_CLASS:
        case mxINT64_CLASS:
        case mxUINT64_CLASS:
        case mxLOGICAL_CLASS: {
            /* The allocated size must be equal to the dimension */
            a = (type != mxLOGICAL_CLASS) ? mxCreateNumericArray(0, 0, type, mxREAL) :
                mxCreateLogicalArray(0, 0);
                
                /* Set pointer */
                mxSetData(a, s);
                
                /* Set size */
                mxSetDimensions(a, dims, dim);
                break;
        }
        case mxCHAR_CLASS: {
            mxChar  *d;
            char    *p = (char*)s;
            int     len=1;
            int     i;
            
            a = mxCreateCharArray(dim, dims);
            for (i=0; i<dim; ++i) len*=dims[i];
            
            if (p) {
                d = (mxChar*)mxGetData(a);
                for (i=0; i<len; ++i) d[i] = p[i];
            }
            mxFree(s);
            break;
        }
        case mxSTRUCT_CLASS:
            mxAssert(0, "mxSTRUCT_CLASS is not supported.");
        case mxFUNCTION_CLASS:
            mxAssert(0, "mxFUNCTION_CLASS is not supported.");
        default:
            mxAssert(0, "Unsupported data type.");
    }
    
    return a;
}

#undef CGEN_MAXDIM

#ifdef MATLAB_MEX_FILE
#include "mex.h"

__attribute__((visibility("default")))
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

#else
#include "matrix.h"
#endif
