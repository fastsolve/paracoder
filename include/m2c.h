/*
 * This file contains some macros and function declarations for m2c.
 */

#ifndef __M2C_H__
#define __M2C_H__

#include <stdio.h>
#include <string.h>

/* Define M2C_DEBUG to be the opposite of NDEBUG by default. It can be overwritten
 * by compiler options -DM2C_DEBUG=1 or -DM2C_DEBUG=0 */
#ifndef M2C_DEBUG
#ifdef NDEBUG
#define M2C_DEBUG  0
#else
#define M2C_DEBUG  1
#endif /* NDEBUG */
#endif /* M2C_DEBUG */

#if defined(MATLAB_MEX_FILE) || defined(BUILD_MAT)

extern void *mxMalloc(size_t n);
extern void *mxCalloc(size_t n, size_t size);
extern void *mxRealloc(void *ptr, size_t size);
extern void mxFree(void *ptr);

/* Define macros to support building function into MATLAB executable. */
#ifdef malloc
# error Function malloc was previously defined as a macro. This can cause MEX functions to fail.
#endif

#define malloc  mxMalloc
#define calloc  mxCalloc
#define realloc mxRealloc
#define free    mxFree

#endif /* MATLAB_MEX_FILE || BUILD_MAT */

#if defined(MATLAB_MEX_FILE)
extern void mexErrMsgIdAndTxt(const char * id, const char * msg, ...);
extern void mexWarnMsgIdAndTxt(const char * id, const char * msg, ...);
extern int  mexPrintf(const char * msg, ...);

#define M2C_error   mexErrMsgIdAndTxt
#define M2C_warn    mexWarnMsgIdAndTxt
#define M2C_printf  mexPrintf

#define emlrtIsMATLABThread(s)  1

#elif defined(BUILD_MAT)

extern void mexErrMsgIdAndTxt(const char * id, const char * msg, ...);
extern void mexWarnMsgIdAndTxt(const char * id, const char * msg, ...);

#define M2C_error   mexErrMsgIdAndTxt
#define M2C_warn    mexWarnMsgIdAndTxt
#define M2C_printf  printf

#define emlrtIsMATLABThread(s)  0

#else /* MATLAB_MEX_FILE */

extern void M2C_error(const char * id, const char * msg, ...);
extern void M2C_warn(const char * id, const char * msg, ...);
#define M2C_printf  printf

#define emlrtIsMATLABThread(s)  0

#endif /* MATLAB_MEX_FILE */

#define M2C_OFFSET_PTR(ptr,offset)        ((ptr)+(offset))
#define M2C_GET_FIELD(s,field)            (s)->field
#define M2C_SET_FIELD(s,field,val)        (s)->field=val
#define M2C_BEGIN_REGION()                {
#define M2C_END_REGION()                  }
#define M2C_BEGIN_REGION_MISMATCH()
#define M2C_END_REGION_MISMATCH()
#define M2C_INTDIV(a,b)                   ((int)(a) / (int)(b))

/* Define emxArray__common and other standard emxInit and emxFree 
 * functions for basic data types. */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
    void *data;
    int *size;
    int allocatedSize;
    int numDimensions;
    unsigned char canFreeData;
};

#endif

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif

#ifndef INLINE_ENSURE_CAPACITY
#if !defined(M2C_DEBUG) && defined(_STDC_C99)
#define INLINE_ENSURE_CAPACITY  1
#else
#define INLINE_ENSURE_CAPACITY  0
#endif /* M2C_DEBUG */
#endif /* INLINE_ENSURE_CAPACITY */

extern void m2cExpandCapacity(emxArray__common *emxArray, int oldNumel,
        int newNumel, int elementSize);

/* emxEnsureCapacity is called very frequently, so better to inline it */
#if INLINE_ENSURE_CAPACITY
inline
void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel,
        int elementSize) {
    int i;
    int newNumel = emxArray->size[0];
    for (i = emxArray->numDimensions-1; i >= 1 ; i--) {
        newNumel *= emxArray->size[i];
    }
    if (newNumel > emxArray->allocatedSize)
        m2cExpandCapacity(emxArray, oldNumel, newNumel, elementSize);
}
#else
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel,
        int elementSize);
#endif

#define declare_emxInit(emxtype) \
extern void emxInit_##emxtype(emxArray_##emxtype **pEmxArray, int numDimensions)

#define declare_emxFree(emxtype) \
extern void emxFree_##emxtype(emxArray_##emxtype **pEmxArray)

#ifdef struct_emxArray_boolean_T
declare_emxInit(boolean_T);
declare_emxFree(boolean_T);
#endif

#ifdef struct_emxArray_char_T
declare_emxInit(char_T);
declare_emxFree(char_T);
#endif

#ifdef struct_emxArray_int8_T
declare_emxInit(int8_T);
declare_emxFree(int8_T);
#endif

#ifdef struct_emxArray_int16_T
declare_emxInit(int16_T);
declare_emxFree(int16_T);
#endif

#ifdef struct_emxArray_int32_T
declare_emxInit(int32_T);
declare_emxFree(int32_T);
#endif

#ifdef struct_emxArray_int64_T
declare_emxInit(int64_T);
declare_emxFree(int64_T);
#endif

#ifdef struct_emxArray_uint8_T
declare_emxInit(uint8_T);
declare_emxFree(uint8_T);
#endif

#ifdef struct_emxArray_uint16_T
declare_emxInit(uint16_T);
declare_emxFree(uint16_T);
#endif

#ifdef struct_emxArray_uint32_T
declare_emxInit(uint32_T);
declare_emxFree(uint32_T);
#endif

#ifdef struct_emxArray_uint64_T
declare_emxInit(uint64_T);
declare_emxFree(uint64_T);
#endif

#ifdef struct_emxArray_real_T
declare_emxInit(real_T);
declare_emxFree(real_T);
#endif

#ifdef struct_emxArray_real32_T
declare_emxInit(real32_T);
declare_emxFree(real32_T);
#endif

#ifdef struct_emxArray_real64_T
declare_emxInit(real64_T);
declare_emxFree(real64_T);
#endif

#define define_emxCreate(emxInit, emxtype) \
emxArray_##emxtype *emxCreate_##emxtype(int rows, int cols) \
{ \
    emxArray_##emxtype *emx; \
    int numEl; \
    emxInit(&emx, 2); \
    emx->size[0] = rows; \
    emx->size[1] = cols; \
    numEl = rows*cols; \
    *(void **)&emx->data = calloc((uint32_T)numEl, sizeof(*emx->data)); \
    emx->numDimensions = 2; \
    emx->allocatedSize = numEl; \
    return emx; \
}

#define define_emxFreeStruct(emxFree, emxtype) \
void emxFree(emxArray_##emxtype **pEmxArray) \
{ \
    int numEl; \
    int i; \
    if (*pEmxArray != (emxArray_##emxtype*)NULL) { \
        numEl = 1; \
        for (i = 0; i < (*pEmxArray)->numDimensions; i++) { \
            numEl *= (*pEmxArray)->size[i]; \
        } \
        \
        for (i = 0; i < numEl; i++) { \
            emxFreeStruct_##emxtype(&(*pEmxArray)->data[i]); \
        } \
        \
        if ((*pEmxArray)->canFreeData) { \
            free((void *)(*pEmxArray)->data); \
        } \
        \
        free((void *)(*pEmxArray)->size); \
        free((void *)*pEmxArray); \
        *pEmxArray = (emxArray_##emxtype *)NULL; \
    } \
}

#define define_emxCreateND(emxInit, emxtype) \
emxArray_##emxtype *emxCreateND_##emxtype(int numDimensions, int *size)  \
{ \
    emxArray_##emxtype *emx; \
    int numEl; \
    int i; \
    emxInit(&emx, numDimensions); \
    numEl = 1; \
    for (i = 0; i < numDimensions; i++) { \
        numEl *= size[i]; \
        emx->size[i] = size[i]; \
    } \
    \
    *(void **)&emx->data = calloc((uint32_T)numEl, sizeof(*emx->data)); \
    emx->numDimensions = numDimensions; \
    emx->allocatedSize = numEl; \
    return emx; \
}


#define define_emxCreateWrapper(emxInit, emxtype, type) \
emxArray_##emxtype *emxCreateWrapper_##emxtype(type *data, int rows, int cols) \
{ \
    emxArray_##emxtype *emx; \
    emxInit(&emx, 2); \
    emx->size[0] = rows; \
    emx->size[1] = cols; \
    \
    emx->data = data; \
    emx->numDimensions = 2; \
    emx->allocatedSize = rows*cols; \
    emx->canFreeData = FALSE; \
    return emx; \
}

#define define_emxCreateWrapperND(emxInit, emxtype, type) \
emxArray_##emxtype *emxCreateWrapperND_##emxtype(type *data, int numDimensions, \
        int *size) \
{ \
    emxArray_##emxtype *emx; \
    int numEl; \
    int i; \
    emxInit(&emx, numDimensions); \
    numEl = 1; \
    for (i = 0; i < numDimensions; i++) { \
        numEl *= size[i]; \
        emx->size[i] = size[i]; \
    } \
    \
    emx->data = data; \
    emx->numDimensions = numDimensions; \
    emx->allocatedSize = numEl; \
    emx->canFreeData = FALSE; \
    return emx; \
}

#define define_emxDestroyArray(emxFree, type) \
void emxDestroyArray_##type(emxArray_##type *emxArray) \
{ \
    emxFree(&emxArray); \
}

extern double M2C_wtime();

#endif
