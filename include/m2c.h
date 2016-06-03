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

#define M2C_OFFSET_PTR(ptr,offset)    ((ptr)+(offset))
#define M2C_GET_FIELD(s,field)        (s).field
#define M2C_GET_FIELD_IND(s,field)    (s)->field
#define M2C_BEGIN_REGION()            {
#define M2C_END_REGION()              }
#define M2C_INTDIV(a,b)               ((int)(a) / (int)(b))

/* Define emxArray__common and other standard emxInit and emxFree 
 * functions for basic data types. */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};

#endif

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif

#ifndef INLINE_ENSURE_CAPACITY
#if M2C_DEBUG
#define INLINE_ENSURE_CAPACITY  0
#else
#define INLINE_ENSURE_CAPACITY  1
#endif /* M2C_DEBUG */
#endif /* INLINE_ENSURE_CAPACITY */

extern void m2cExpandCapacity(emxArray__common *emxArray, int32_T oldNumel,
        int32_T newNumel, int32_T elementSize);

/* emxEnsureCapacity is called very frequently, so better to inline it */
#if INLINE_ENSURE_CAPACITY
inline
void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
        int32_T elementSize) {
    int32_T i;
    int32_T newNumel = emxArray->size[0];
    for (i = emxArray->numDimensions-1; i >= 1 ; i--) {
        newNumel *= emxArray->size[i];
    }
    if (newNumel > emxArray->allocatedSize)
        m2cExpandCapacity(emxArray, oldNumel, newNumel, elementSize);
}
#else
extern void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
        int32_T elementSize);
#endif

#define declare_emxInit(emxInit, emxtype) \
extern void emxInit(emxArray_##emxtype **pEmxArray, int32_T numDimensions)

#define declare_emxFree(emxFree, emxtype) \
extern void emxFree(emxArray_##emxtype **pEmxArray)

#ifdef struct_emxArray_boolean_T
declare_emxInit(emxInit_boolean_T, boolean_T);
declare_emxFree(emxFree_boolean_T, boolean_T);
#endif

#ifdef struct_emxArray_char_T
declare_emxInit(emxInit_char_T, char_T);
declare_emxFree(emxFree_char_T, char_T);
#endif

#ifdef struct_emxArray_int8_T
declare_emxInit(emxInit_int8_T, int8_T);
declare_emxFree(emxFree_int8_T, int8_T);
#endif

#ifdef struct_emxArray_int16_T
declare_emxInit(emxInit_int16_T, int16_T);
declare_emxFree(emxFree_int16_T, int16_T);
#endif

#ifdef struct_emxArray_int32_T
declare_emxInit(emxInit_int32_T, int32_T);
declare_emxFree(emxFree_int32_T, int32_T);
#endif

#ifdef struct_emxArray_int64_T
declare_emxInit(emxInit_int64_T, int64_T);
declare_emxFree(emxFree_int64_T, int64_T);
#endif

#ifdef struct_emxArray_uint8_T
declare_emxInit(emxInit_uint8_T, uint8_T);
declare_emxFree(emxFree_uint8_T, uint8_T);
#endif

#ifdef struct_emxArray_uint16_T
declare_emxInit(emxInit_uint16_T, uint16_T);
declare_emxFree(emxFree_uint16_T, uint16_T);
#endif

#ifdef struct_emxArray_uint32_T
declare_emxInit(emxInit_uint32_T, uint32_T);
declare_emxFree(emxFree_uint32_T, uint32_T);
#endif

#ifdef struct_emxArray_uint64_T
declare_emxInit(emxInit_uint64_T, uint64_T);
declare_emxFree(emxFree_uint64_T, uint64_T);
#endif

#ifdef struct_emxArray_real_T
declare_emxInit(emxInit_real_T, real_T);
declare_emxFree(emxFree_real_T, real_T);
#endif

#ifdef struct_emxArray_real32_T
declare_emxInit(emxInit_real32_T, real32_T);
declare_emxFree(emxFree_real32_T, real32_T);
#endif

#ifdef struct_emxArray_real64_T
declare_emxInit(emxInit_real64_T, real64_T);
declare_emxFree(emxFree_real64_T, real64_T);
#endif

extern double M2C_wtime();

#endif
