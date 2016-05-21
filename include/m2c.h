/*
 * This file contains some macros and function declarations for m2c.
 */

#ifndef __M2C_H__
#define __M2C_H__

#include <stdio.h>
#include <string.h>

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

#else

/* Define M2C_DEBUG to be the opposite of NDEBUG by default. It can be overwritten 
   by compiler options -DM2C_DEBUG=1 or -DM2C_DEBUG=0 */
#ifndef M2C_DEBUG
#ifdef NDEBUG
#define M2C_DEBUG  0
#else
#define M2C_DEBUG  1
#endif
#endif

#endif


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

#else

extern void M2C_error(const char * id, const char * msg, ...);
extern void M2C_warn(const char * id, const char * msg, ...);
#define M2C_printf  printf

#define emlrtIsMATLABThread(s)  0

#endif


extern double M2C_wtime();

#define M2C_OFFSET_PTR(ptr,offset)    ((char *)ptr)+(offset)
#define M2C_GET_FIELD(s,field)        s.field
#define M2C_GET_FIELD_IND(s,field)    s->field
#define M2C_BEGIN_REGION()            {
#define M2C_END_REGION()              }

typedef int int32_triple[3];
typedef int int32_double[2];

#ifdef MATLAB_MEX_FILE
#define M2C_CHK_OPAQUE_PTR(ptr,parent,offset)                         \
        if ((parent) && (ptr) != ((char*)mxGetData(parent))+(offset)) \
        mexErrMsgIdAndTxt("opaque_ptr:ParentObjectChanged", \
        "The parent mxArray has changed. Avoid changing a MATLAB variable when dereferenced by an opaque_ptr.");
#else
/* Issue formatted error message with corresponding error identifier */
#define M2C_CHK_OPAQUE_PTR(ptr,parent,offset) 
#endif

#ifndef struct_emxArray__common
#define struct_emxArray__common

#ifndef ONCUDA
# define ONCUDA (255U)
#endif

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

#define define_emxEnsureCapacity \
void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel, \
  int32_T elementSize) \
{ \
  int32_T newNumel; \
  int32_T i; \
  void *newData; \
  newNumel = 1; \
  for (i = 0; i < emxArray->numDimensions; i++) { \
    newNumel *= emxArray->size[i]; \
  } \
  \
  if (newNumel > emxArray->allocatedSize) { \
    if (emxArray->allocatedSize==0) \
      i = newNumel; \
    else { \
      i = emxArray->allocatedSize; \
      if (i < 16) { \
        i = 16; \
      } \
    \
      while (i < newNumel) { \
        i <<= 1; \
      } \
    } \
    \
    newData = calloc((uint32_T)i, (uint32_T)elementSize); \
    if (emxArray->data != NULL) { \
      memcpy(newData, emxArray->data, (uint32_T)(elementSize * oldNumel)); \
      if (emxArray->canFreeData) { \
        free(emxArray->data); \
      } \
    } \
    \
    emxArray->data = newData; \
    emxArray->allocatedSize = i; \
    emxArray->canFreeData = TRUE; \
  } \
  \
}

#define declare_emxEnsureCapacityStruct(emxtype) \
void emxEnsureCapacity_##emxtype(emxArray_##emxtype *emxArray, int32_T oldNumel);

#define define_emxEnsureCapacityStruct(emxtype) \
void emxEnsureCapacity_##emxtype(emxArray_##emxtype *emxArray, int32_T oldNumel) \
{ \
  int32_T elementSize; \
  int32_T newNumel; \
  int32_T i; \
  void *newData; \
  elementSize = (int32_T)sizeof(*emxArray->data); \
  newNumel = 1; \
  for (i = 0; i < emxArray->numDimensions; i++) { \
    newNumel *= emxArray->size[i]; \
  } \
  \
  if (newNumel > emxArray->allocatedSize) { \
    if (emxArray->allocatedSize==0) \
      i = newNumel; \
    else { \
      i = emxArray->allocatedSize; \
      if (i < 16) { \
        i = 16; \
      } \
      \
      while (i < newNumel) { \
        i <<= 1; \
      } \
    } \
    \
    newData = calloc((uint32_T)i, (uint32_T)elementSize); \
    if (emxArray->data != NULL) { \
      memcpy(newData, (void *)emxArray->data, (uint32_T)(elementSize * oldNumel)); \
      if (emxArray->canFreeData) { \
        free((void *)emxArray->data); \
      } \
    } \
    \
    *(void **)&emxArray->data = newData; \
    emxArray->allocatedSize = i; \
    emxArray->canFreeData = TRUE; \
  } \
  \
  if (oldNumel > newNumel) { \
    emxTrim_##emxtype(emxArray, newNumel, oldNumel); \
  } else { \
    if (oldNumel < newNumel) { \
      emxExpand_##emxtype(emxArray, oldNumel, newNumel); \
    } \
  } \
}

#define declare_emxInit( emxInit, emxtype) \
void emxInit(emxArray_##emxtype **pEmxArray, int32_T numDimensions)

#define define_emxInit( emxInit, emxtype) \
void emxInit(emxArray_##emxtype **pEmxArray, int32_T numDimensions) \
{ \
  emxArray_##emxtype *emxArray; \
  int32_T i; \
  *pEmxArray = (emxArray_##emxtype *)malloc(sizeof(emxArray_##emxtype)); \
  emxArray = *pEmxArray; \
  emxArray->data = NULL; \
  emxArray->numDimensions = numDimensions; \
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions)); \
  emxArray->allocatedSize = 0; \
  emxArray->canFreeData = TRUE; \
  for (i = 0; i < numDimensions; i++) { \
    emxArray->size[i] = 0; \
  } \
}

#define declare_emxFree( emxFree, emxtype) \
void emxFree(emxArray_##emxtype **pEmxArray)

/* Define emxFree for standard data types */
#define define_emxFree( emxFree, emxtype) \
void emxFree(emxArray_##emxtype **pEmxArray) \
{ \
  if (*pEmxArray != (emxArray_##emxtype *)NULL) { \
    if ((*pEmxArray)->canFreeData) { \
      free((void *)(*pEmxArray)->data); \
    } \
    \
    free((void *)(*pEmxArray)->size); \
    free((void *)*pEmxArray); \
    *pEmxArray = (emxArray_##emxtype *)NULL; \
  } \
}

#define declare_emxFreeStruct( emxFree, emxtype) \
void emxFree(emxArray_##emxtype **pEmxArray)

#define define_emxFreeStruct( emxFree, emxtype) \
void emxFree(emxArray_##emxtype **pEmxArray) \
{ \
  int32_T numEl; \
  int32_T i; \
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

void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
        int32_T elementSize);

#ifdef struct_emxArray_boolean_T
extern declare_emxInit( emxInit_boolean_T, boolean_T);
extern declare_emxFree( emxFree_boolean_T, boolean_T);
#endif

#ifdef struct_emxArray_char_T
extern declare_emxInit( emxInit_char_T, char_T);
extern declare_emxFree( emxFree_char_T, char_T);
#endif

#ifdef struct_emxArray_int8_T
extern declare_emxInit( emxInit_int8_T, int8_T);
extern declare_emxFree( emxFree_int8_T, int8_T);
#endif

#ifdef struct_emxArray_int16_T
extern declare_emxInit( emxInit_int16_T, int16_T);
extern declare_emxFree( emxFree_int16_T, int16_T);
#endif

#ifdef struct_emxArray_int32_T
extern declare_emxInit( emxInit_int32_T, int32_T);
extern declare_emxFree( emxFree_int32_T, int32_T);
#endif

#ifdef struct_emxArray_int64_T
extern declare_emxInit( emxInit_int64_T, int64_T);
extern declare_emxFree( emxFree_int64_T, int64_T);
#endif

#ifdef struct_emxArray_uint8_T
extern declare_emxInit( emxInit_uint8_T, uint8_T);
extern declare_emxFree( emxFree_uint8_T, uint8_T);
#endif

#ifdef struct_emxArray_uint16_T
extern declare_emxInit( emxInit_uint16_T, uint16_T);
extern declare_emxFree( emxFree_uint16_T, uint16_T);
#endif

#ifdef struct_emxArray_uint32_T
extern declare_emxInit( emxInit_uint32_T, uint32_T);
extern declare_emxFree( emxFree_uint32_T, uint32_T);
#endif

#ifdef struct_emxArray_uint64_T
extern declare_emxInit( emxInit_uint64_T, uint64_T);
extern declare_emxFree( emxFree_uint64_T, uint64_T);
#endif

#ifdef struct_emxArray_real_T
extern declare_emxInit( emxInit_real_T, real_T);
extern declare_emxFree( emxFree_real_T, real_T);
#endif

#ifdef struct_emxArray_real32_T
extern declare_emxInit( emxInit_real32_T, real32_T);
extern declare_emxFree( emxFree_real32_T, real32_T);
#endif

#ifdef struct_emxArray_real64_T
extern declare_emxInit( emxInit_real64_T, real64_T);
extern declare_emxFree( emxFree_real64_T, real64_T);
#endif


#define define_emxCreate( emxInit, emxtype) \
emxArray_##emxtype *emxCreate_##emxtype(int32_T rows, int32_T cols) \
{ \
  emxArray_##emxtype *emx; \
  int32_T size[2]; \
  int32_T numEl; \
  int32_T i; \
  size[0] = rows; \
  size[1] = cols; \
  emxInit(&emx, 2); \
  numEl = 1; \
  for (i = 0; i < 2; i++) { \
    numEl *= size[i]; \
    emx->size[i] = size[i]; \
  } \
  \
  *(void **)&emx->data = calloc((uint32_T)numEl, sizeof(*emx->data)); \
  emx->numDimensions = 2; \
  emx->allocatedSize = numEl; \
  return emx; \
}

#define define_emxCreateND( emxInit, emxtype) \
emxArray_##emxtype *emxCreateND_##emxtype(int32_T numDimensions, int32_T *size)  \
{ \
  emxArray_##emxtype *emx; \
  int32_T numEl; \
  int32_T i; \
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


#define define_emxCreateWrapper( emxInit, emxtype, type) \
emxArray_##emxtype *emxCreateWrapper_##emxtype(type *data, int32_T rows, int32_T cols) \
{ \
  emxArray_##emxtype *emx; \
  int32_T size[2]; \
  int32_T numEl; \
  int32_T i; \
  size[0] = rows; \
  size[1] = cols; \
  emxInit(&emx, 2); \
  numEl = 1; \
  for (i = 0; i < 2; i++) { \
    numEl *= size[i]; \
    emx->size[i] = size[i]; \
  } \
  \
  emx->data = data; \
  emx->numDimensions = 2; \
  emx->allocatedSize = numEl; \
  emx->canFreeData = FALSE; \
  return emx; \
}

#define define_emxCreateWrapperND( emxInit, emxtype, type) \
emxArray_##emxtype *emxCreateWrapperND_##emxtype(type *data, int32_T numDimensions, \
  int32_T *size) \
{ \
  emxArray_##emxtype *emx; \
  int32_T numEl; \
  int32_T i; \
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

#define define_emxDestroyArray( emxFree, type) \
void emxDestroyArray_##type(emxArray_##type *emxArray) \
{ \
  emxFree(&emxArray); \
}

#endif
