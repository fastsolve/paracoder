#include "crs_triu.h"
#include "m2c.h"
#include "crs_triu_emxutil.h"

static void emxCopy_int32_T(emxArray_int32_T **dst, emxArray_int32_T * const
  *src);
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src);
static void emxCopy_int32_T(emxArray_int32_T **dst, emxArray_int32_T * const
  *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity((emxArray__common *)*dst, numElDst, sizeof(int));
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity((emxArray__common *)*dst, numElDst, sizeof(double));
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

void emxCopyStruct_struct0_T(struct0_T *dst, const struct0_T *src)
{
  emxCopy_int32_T(&dst->row_ptr, &src->row_ptr);
  emxCopy_int32_T(&dst->col_ind, &src->col_ind);
  emxCopy_real_T(&dst->val, &src->val);
  dst->nrows = src->nrows;
  dst->ncols = src->ncols;
}

void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_int32_T(&pStruct->row_ptr);
  emxFree_int32_T(&pStruct->col_ind);
  emxFree_real_T(&pStruct->val);
}

void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_int32_T(&pStruct->row_ptr, 1);
  emxInit_int32_T(&pStruct->col_ind, 1);
  emxInit_real_T(&pStruct->val, 1);
}

