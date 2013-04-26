/*
 * This file contains some helper functions used by the MEX wrapper 
 * generated by lib2mex.
 */

#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray__common;

#endif

#ifdef CGEN_MAXDIM 
#undef CGEN_MAXDIM
#endif
#define CGEN_MAXDIM 10

/*****************************************************************
 * Initialize an emxArray.
 *****************************************************************/
void init_emxArray( emxArray__common *emx, int32_T dim) {
    emx->data = NULL;
    emx->numDimensions = dim;
    emx->size = (int32_T*)mxCalloc(dim, sizeof(int32_T));
    emx->allocatedSize = 0;
    emx->canFreeData = TRUE;
}

/*****************************************************************
 * Free up space allocated for emx.
 *****************************************************************/
void free_emxArray( emxArray__common *emx) {
    if ( emx->canFreeData && emx->data) mxFree(emx->data);
    if ( emx->size) mxFree(emx->size);
    emx->data = NULL; emx->size=NULL;
    emx->allocatedSize=0; emx->canFreeData=FALSE;
}

/*****************************************************************
 * Obtain number of items of an emxArray.
 *****************************************************************/
int32_T nelems_emxArray( const emxArray__common *emx) {
    int32_T i, dim=emx->numDimensions;
    int32_T nitems = emx->size[0];
    
    for (i=1; i<dim; ++i) nitems *= emx->size[i];
    return nitems;
}

/*****************************************************************
 * Initialize dimension of emxArray from mxArray.
 *****************************************************************/
void init_emxArray_from_mxArray(const mxArray *a, emxArray__common *emx,
        const char *name, int32_T dim, int32_T sizeof_type) {

    const mwSize *dims = mxGetDimensions(a);
    int   i, mxdim = mxGetNumberOfDimensions(a);
    
    init_emxArray( emx, dim);
    
    if ( mxGetNumberOfElements(a)==0) return;

    /* Check the compatibility of the mxArray */
    if ( mxdim>dim) {
        for (i=dim; i<mxdim; ++i) {
            if (dims[i]!=1)
                mexErrMsgIdAndTxt("lib2mex:WrongDimension",
                        "Varialble %s has incorrect dimension.", name);
        }
        mxdim = dim;
    }
    
    /* copy dimension */
    for (i=0; i<mxdim; ++i) emx->size[i] = dims[i];
    for (i=mxdim; i<dim; ++i) emx->size[i] = 1;
    
    if (sizeof_type>0) {
        emx->allocatedSize = nelems_emxArray( emx);
        emx->data = mxCalloc( emx->allocatedSize, sizeof_type);
    }
}

/*****************************************************************
 * Wrap the data in mxArray into emxArray.
 * Data within emxArray is overwritten.
 *****************************************************************/
static void alias_mxArray_to_emxArray(const mxArray *a, emxArray__common *emx, 
                                      const char *name, int32_T dim) {
    mxClassID type=mxGetClassID(a);

    init_emxArray_from_mxArray( a, emx, name, dim, 0);

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
        emx->allocatedSize = mxGetNumberOfElements(a);
        emx->data = mxGetData( a);
        emx->canFreeData = false;
        break;
    case mxCHAR_CLASS:
        emx->allocatedSize = mxGetNumberOfElements(a)+1;
        emx->data = mxMalloc( emx->allocatedSize);
        emx->canFreeData = true;
        
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
 * Copy data in mxArray into a given array.
 *****************************************************************/
static void copy_mxArray_to_array(const mxArray *a, emxArray__common *emx, 
                                  mwSize maxlen) {
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
    case mxUINT64_CLASS: {
        mwSize n = mxGetNumberOfElements(a);
        if (n>maxlen) n=maxlen;

        memcpy( emx->data, mxGetData(a), n*mxGetElementSize(a));
        break;
    }
    case mxCHAR_CLASS:           
        mxGetString(a, (char*)emx, maxlen);
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
 * Preallocate storage for mxArray.
 *****************************************************************/
static void *prealloc_mxArray( mxArray **pa, mxClassID type, 
                               int32_T dim, mwSize *size) {
    mxArray *a=NULL;

    switch (type) {
    case mxLOGICAL_CLASS:
        a = mxCreateLogicalArray(dim, size);
        break;
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
        a = mxCreateNumericArray(dim, size, type, mxREAL);
        break;
    case mxSTRUCT_CLASS:
        a = mxCreateStructArray(dim, size, 0, NULL);
        break;
    case mxFUNCTION_CLASS:
        mxAssert(0, "mxFUNCTION_CLASS is not supported.");
    default:
        mxAssert(0, "Unsupported data type.");
    }

    *pa = a;    
    return mxGetData( a);
}

/*****************************************************************
 * Copy data from a scalar into mxArray. The function should be used
 * only at the end of a mex wrapper.
 *****************************************************************/
static mxArray *copy_scalar_to_mxArray(void *s, mxClassID type) {
    mxArray *a = NULL;
    const mwSize  one=1;

    switch (type) {
    case mxLOGICAL_CLASS:
        a = mxCreateLogicalArray(1, &one);
        *(boolean_T*)mxGetData(a) = *(boolean_T*)s;
        break;
    case mxCHAR_CLASS: {
        a = mxCreateCharArray(1, &one);
        *(mxChar*)mxGetData(a) = *(char_T*)s;
        break;
    }
    case mxDOUBLE_CLASS:
        a = mxCreateNumericArray(1, &one, type, mxREAL);
        *(real64_T*)mxGetData(a) = *(real64_T*)s;
        break;
    case mxSINGLE_CLASS:
        a = mxCreateNumericArray(1, &one, type, mxREAL);
        *(real32_T*)mxGetData(a) = *(real32_T*)s;
        break;
    case mxINT8_CLASS:
    case mxUINT8_CLASS:
        a = mxCreateNumericArray(1, &one, type, mxREAL);
        *(int8_T*)mxGetData(a) = *(int8_T*)s;
        break;
    case mxINT16_CLASS:
    case mxUINT16_CLASS:
        a = mxCreateNumericArray(1, &one, type, mxREAL);
        *(uint16_T*)mxGetData(a) = *(uint16_T*)s;
        break;
    case mxINT32_CLASS:
    case mxUINT32_CLASS:
        a = mxCreateNumericArray(1, &one, type, mxREAL);
        *(uint32_T*)mxGetData(a) = *(uint32_T*)s;
        break;
    case mxINT64_CLASS:
    case mxUINT64_CLASS:
        a = mxCreateNumericArray(1, &one, type, mxREAL);
        *(uint64_T*)mxGetData(a) = *(uint64_T*)s;
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
static mxArray *copy_array_to_mxArray(void *s, mxClassID type, 
                                      int32_T dim, int32_T *size) {
    mxArray *a=NULL;
    mwSize   dims_buf[CGEN_MAXDIM];
    mwSize  *dims=NULL;
    int      i;

    if  (size[0]==0 && dim==1) {
        dims = dims_buf; dims[0] = 0; dims[1] = 1; dim = 2;
    }
    else if (sizeof(mwSize) == sizeof(*size))
        dims = (mwSize*)size;
    else {
        dims = (dim<=CGEN_MAXDIM)? dims_buf: (mwSize *)mxMalloc(sizeof(mwSize)*dim);
        for (i=0; i<dim; ++i) dims[i] = size[i];
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
        a = (type==mxLOGICAL_CLASS) ?
            mxCreateLogicalArray(dim, dims) :
            mxCreateNumericArray(dim, dims, type, mxREAL);

        memcpy(mxGetData(a), s, mxGetNumberOfElements(a)*mxGetElementSize(a));
        break;
    }
    case mxCHAR_CLASS: {
        mxChar  *d;
        char    *p = (char*)s;
        mwSize  len=1, i;
        int32_T j;

        a = mxCreateCharArray(dim, dims);
        d = (mxChar*)mxGetData(a);
        
        for (j=0; j<dim; ++j) len*=size[j];
        for (i=0; i<len; ++i) d[i] = p[i];
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
    
    if (dims != (mwSize*)size && dim>CGEN_MAXDIM) mxFree(dims);
    return a;
}

/*****************************************************************
 * create struct array.
 *****************************************************************/
static mxArray *create_struct_mxArray(int32_T dim, int32_T *size, 
            int32_T nfields, const char **fields) {
    mxArray *a=NULL;
    mwSize   dims_buf[CGEN_MAXDIM];
    mwSize  *dims=NULL;
    int      i;

    if  (size[0]==0 && dim==1) {
        dims = dims_buf; dims[0] = 0; dims[1] = 1; dim = 2;
    }
    else if (sizeof(mwSize) == sizeof(*size))
        dims = (mwSize*)size;
    else {
        dims = (dim<=CGEN_MAXDIM)? dims_buf: (mwSize *)mxMalloc(sizeof(mwSize)*dim);
        for (i=0; i<dim; ++i) dims[i] = size[i];
    }

    a = mxCreateStructArray(dim, dims, nfields, fields);
    if (dims != (mwSize*)size && dim>CGEN_MAXDIM) mxFree(dims);
    return a;
}

/*****************************************************************
 * Move data from emxArray into mxArray. The function should be used
 * only at the end of a mex wrapper to transfer ownership of data.
 * It is assumed that the data in mxArray are allocated using mxMalloc,
 * mxCalloc, or mxRelloc.
 *****************************************************************/
static mxArray *move_emxArray_to_mxArray(emxArray__common *emx, mxClassID type) {
    mxArray *a=NULL;
    int      dim = emx->numDimensions;
    mwSize   dims_buf[CGEN_MAXDIM];
    mwSize  *dims;
    int      i;

    /* Always use copy for robustness */
#ifdef HAVE_OCTAVE
    a = copy_array_to_mxArray( emx->data, type,
            emx->numDimensions, emx->size);
    free_emxArray( emx);
    return a;
#else
    if ( !emx->canFreeData) {
        a = copy_array_to_mxArray( emx->data, type,
                emx->numDimensions, emx->size);
        free_emxArray( emx);
        return a;
    }
#endif

    if  (dim==1 && emx->size[0]==0) {
        dims = dims_buf; dims[0] = 0; dims[1] = 1; dim = 2;
    }
    else if (sizeof(mwSize) == sizeof(*emx->size))
        dims = (mwSize*)emx->size;
    else {
        dims = (dim<=CGEN_MAXDIM)? dims_buf: (mwSize *)mxMalloc(sizeof(mwSize)*dim);
        for (i=0; i<dim; ++i) dims[i] = emx->size[i];
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
    case mxUINT64_CLASS: {
        /* The allocated size must be equal to the dimension */
        a = mxCreateNumericArray(0, 0, type, mxREAL);
        if (emx->data) {
            /* Set pointer */
            mxSetData( a, emx->data);
        }
        /* Set size */
        mxSetDimensions(a, dims, dim);
        emx->canFreeData = FALSE;

        free_emxArray( emx);
        break;
    }
    case mxLOGICAL_CLASS: {
        mxLogical  *d;
        boolean_T  *p = (boolean_T*)emx->data;
        mwSize  len=1;
        int     i;

        a = mxCreateLogicalArray(dim, dims);
        for (i=0; i<dim; ++i) len*=dims[i];

        if (p) {
            mwSize  i;
            d = (mxLogical*)mxGetLogicals(a);
            for (i=0; i<len; ++i) d[i] = p[i];
        }

        /* Free up emx */
        free_emxArray(emx);
        break;
    }
    case mxCHAR_CLASS: {
        mxChar  *d;
        char    *p = (char*)emx->data;
        mwSize  len=1;
        int     i;

        a = mxCreateCharArray(dim, dims);
        for (i=0; i<dim; ++i) len*=dims[i];

        if (p) {
            mwSize  i;
            d = (mxChar*)mxGetData(a);
            for (i=0; i<len; ++i) d[i] = p[i];
        }

        /* Free up emx */
        free_emxArray(emx);
        break;
    }
    case mxSTRUCT_CLASS:
        mxAssert(0, "mxSTRUCT_CLASS is not supported.");
    case mxFUNCTION_CLASS:
        mxAssert(0, "mxFUNCTION_CLASS is not supported.");
    default:
        mxAssert(0, "Unsupported data type.");
    }

    if (dims != (mwSize*)emx->size && dim>CGEN_MAXDIM) mxFree(dims);
    return a;
}

#undef CGEN_MAXDIM
