#include "crs_triu.h"
#include "m2c.h"

static void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
                     emxArray_real_T *val);
static void emxCopyStruct_struct0_T(struct0_T *dst, const struct0_T *src);
static void emxCopy_int32_T(emxArray_int32_T **dst, emxArray_int32_T * const
  *src);
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
                     emxArray_real_T *val)
{
  int i2;
  int i;
  emxArray_real_T *buf_val;
  emxArray_int32_T *buf_indx;
  boolean_T ascend;
  int l;
  int j;
  boolean_T exitg3;
  int n;
  unsigned int ind;
  int exitg1;
  boolean_T guard1 = false;
  int r0;
  double t0;
  int exitg2;
  int b_i;
  boolean_T guard2 = false;
  i2 = row_ptr->size[0] - 1;
  i = 1;
  emxInit_real_T(&buf_val, 1);
  emxInit_int32_T(&buf_indx, 1);
  while (i <= i2) {
    ascend = true;
    l = row_ptr->data[i] - 1;
    j = row_ptr->data[i - 1];
    exitg3 = false;
    while ((!exitg3) && (j + 1 <= l)) {
      if (col_ind->data[j] < col_ind->data[j - 1]) {
        ascend = false;
        exitg3 = true;
      } else {
        j++;
      }
    }

    if (!ascend) {
      l = buf_indx->size[0];
      buf_indx->size[0] = row_ptr->data[i] - row_ptr->data[i - 1];
      emxEnsureCapacity((emxArray__common *)buf_indx, l, (int)sizeof(int));
      n = row_ptr->data[i] - row_ptr->data[i - 1];
      for (l = 0; l < n; l++) {
        buf_indx->data[l] = 0;
      }

      l = buf_val->size[0];
      buf_val->size[0] = row_ptr->data[i] - row_ptr->data[i - 1];
      emxEnsureCapacity((emxArray__common *)buf_val, l, (int)sizeof(double));
      n = row_ptr->data[i] - row_ptr->data[i - 1];
      for (l = 0; l < n; l++) {
        buf_val->data[l] = 0.0;
      }

      ind = 1U;
      l = row_ptr->data[i] - 1;
      for (j = row_ptr->data[i - 1]; j <= l; j++) {
        buf_indx->data[(int)ind - 1] = col_ind->data[j - 1];
        buf_val->data[(int)ind - 1] = val->data[j - 1];
        ind++;
      }

      n = buf_indx->size[0];
      if (!(n <= 1)) {
        l = (int)((unsigned int)n >> 1U);
        do {
          exitg1 = 0;
          guard1 = false;
          if (l + 1 <= 1) {
            r0 = buf_indx->data[n - 1];
            t0 = buf_val->data[n - 1];
            buf_indx->data[n - 1] = buf_indx->data[0];
            buf_val->data[n - 1] = buf_val->data[0];
            n--;
            if (n == 1) {
              exitg1 = 1;
            } else {
              guard1 = true;
            }
          } else {
            l--;
            r0 = buf_indx->data[l];
            t0 = buf_val->data[l];
            guard1 = true;
          }

          if (guard1) {
            j = l;
            do {
              exitg2 = 0;
              b_i = j;
              j = ((j + 1) << 1) - 1;
              ascend = false;
              guard2 = false;
              if (j + 1 >= n) {
                if (j + 1 == n) {
                  ascend = true;
                  guard2 = true;
                } else if (j + 1 > n) {
                  exitg2 = 1;
                } else {
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }

              if (guard2) {
                if ((!ascend) && (buf_indx->data[j] < buf_indx->data[j + 1])) {
                  j++;
                }

                if (r0 >= buf_indx->data[j]) {
                  exitg2 = 1;
                } else {
                  buf_indx->data[b_i] = buf_indx->data[j];
                  buf_val->data[b_i] = buf_val->data[j];
                }
              }
            } while (exitg2 == 0);

            buf_indx->data[b_i] = r0;
            buf_val->data[b_i] = t0;
          }
        } while (exitg1 == 0);

        buf_indx->data[0] = r0;
        buf_val->data[0] = t0;
      }

      ind = 1U;
      l = row_ptr->data[i] - 1;
      for (j = row_ptr->data[i - 1]; j <= l; j++) {
        col_ind->data[j - 1] = buf_indx->data[(int)ind - 1];
        val->data[j - 1] = buf_val->data[(int)ind - 1];
        ind++;
      }
    }

    i++;
  }

  emxFree_int32_T(&buf_indx);
  emxFree_real_T(&buf_val);
}

static void emxCopyStruct_struct0_T(struct0_T *dst, const struct0_T *src)
{
  emxCopy_int32_T(&dst->row_ptr, &src->row_ptr);
  emxCopy_int32_T(&dst->col_ind, &src->col_ind);
  emxCopy_real_T(&dst->val, &src->val);
  dst->nrows = src->nrows;
  dst->ncols = src->ncols;
}

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

  emxEnsureCapacity((emxArray__common *)*dst, numElDst, (int)sizeof(int));
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

  emxEnsureCapacity((emxArray__common *)*dst, numElDst, (int)sizeof(double));
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_int32_T(&pStruct->row_ptr);
  emxFree_int32_T(&pStruct->col_ind);
  emxFree_real_T(&pStruct->val);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_int32_T(&pStruct->row_ptr, 1);
  emxInit_int32_T(&pStruct->col_ind, 1);
  emxInit_real_T(&pStruct->val, 1);
}

void crs_triu(const struct0_T *A, struct0_T *U)
{
  emxArray_int32_T *b_U;
  int i0;
  int offset;
  int start;
  int i;
  emxArray_int32_T *b_A;
  emxArray_real_T *c_A;
  emxInit_int32_T(&b_U, 1);
  emxCopyStruct_struct0_T(U, A);
  i0 = b_U->size[0];
  b_U->size[0] = U->row_ptr->size[0];
  emxEnsureCapacity((emxArray__common *)b_U, i0, (int)sizeof(int));
  offset = U->row_ptr->size[0];
  for (i0 = 0; i0 < offset; i0++) {
    b_U->data[i0] = U->row_ptr->data[i0];
  }

  crs_sort(b_U, U->col_ind, U->val);
  offset = 0;
  start = 0;
  i = 1;
  emxFree_int32_T(&b_U);
  while (i <= U->nrows) {
    i0 = U->row_ptr->data[i] - 1;
    while (start + 1 <= i0) {
      if (U->col_ind->data[start] < i) {
        offset++;
      } else {
        if (offset != 0) {
          U->col_ind->data[start - offset] = U->col_ind->data[start];
          U->val->data[start - offset] = U->val->data[start];
        }
      }

      start++;
    }

    start = U->row_ptr->data[i] - 1;
    U->row_ptr->data[i] -= offset;
    i++;
  }

  if (offset != 0) {
    emxInit_int32_T(&b_A, 1);
    start = U->col_ind->size[0] - offset;
    i0 = b_A->size[0];
    b_A->size[0] = U->col_ind->size[0];
    emxEnsureCapacity((emxArray__common *)b_A, i0, (int)sizeof(int));
    offset = U->col_ind->size[0];
    for (i0 = 0; i0 < offset; i0++) {
      b_A->data[i0] = U->col_ind->data[i0];
    }

    if (start < 1) {
      i0 = U->col_ind->size[0];
      U->col_ind->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)U->col_ind, i0, (int)sizeof(int));
    } else {
      i0 = U->col_ind->size[0];
      U->col_ind->size[0] = start;
      emxEnsureCapacity((emxArray__common *)U->col_ind, i0, (int)sizeof(int));
      for (i = 0; i < start; i++) {
        U->col_ind->data[i] = b_A->data[i];
      }
    }

    emxFree_int32_T(&b_A);
    emxInit_real_T(&c_A, 1);
    i0 = c_A->size[0];
    c_A->size[0] = U->val->size[0];
    emxEnsureCapacity((emxArray__common *)c_A, i0, (int)sizeof(double));
    offset = U->val->size[0];
    for (i0 = 0; i0 < offset; i0++) {
      c_A->data[i0] = U->val->data[i0];
    }

    if (start < 1) {
      i0 = U->val->size[0];
      U->val->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)U->val, i0, (int)sizeof(double));
    } else {
      i0 = U->val->size[0];
      U->val->size[0] = start;
      emxEnsureCapacity((emxArray__common *)U->val, i0, (int)sizeof(double));
      for (i = 0; i < start; i++) {
        U->val->data[i] = c_A->data[i];
      }
    }

    emxFree_real_T(&c_A);
  }
}

void crs_triu1(const struct0_T *A, int k, struct0_T *U)
{
  emxArray_int32_T *b_U;
  int i1;
  int offset;
  int start;
  int i;
  emxArray_int32_T *b_A;
  emxArray_real_T *c_A;
  emxInit_int32_T(&b_U, 1);
  emxCopyStruct_struct0_T(U, A);
  i1 = b_U->size[0];
  b_U->size[0] = U->row_ptr->size[0];
  emxEnsureCapacity((emxArray__common *)b_U, i1, (int)sizeof(int));
  offset = U->row_ptr->size[0];
  for (i1 = 0; i1 < offset; i1++) {
    b_U->data[i1] = U->row_ptr->data[i1];
  }

  crs_sort(b_U, U->col_ind, U->val);
  offset = 0;
  start = 0;
  i = 1;
  emxFree_int32_T(&b_U);
  while (i <= U->nrows) {
    i1 = U->row_ptr->data[i] - 1;
    while (start + 1 <= i1) {
      if (U->col_ind->data[start] < i + k) {
        offset++;
      } else {
        if (offset != 0) {
          U->col_ind->data[start - offset] = U->col_ind->data[start];
          U->val->data[start - offset] = U->val->data[start];
        }
      }

      start++;
    }

    start = U->row_ptr->data[i] - 1;
    U->row_ptr->data[i] -= offset;
    i++;
  }

  if (offset != 0) {
    emxInit_int32_T(&b_A, 1);
    start = U->col_ind->size[0] - offset;
    i1 = b_A->size[0];
    b_A->size[0] = U->col_ind->size[0];
    emxEnsureCapacity((emxArray__common *)b_A, i1, (int)sizeof(int));
    offset = U->col_ind->size[0];
    for (i1 = 0; i1 < offset; i1++) {
      b_A->data[i1] = U->col_ind->data[i1];
    }

    if (start < 1) {
      i1 = U->col_ind->size[0];
      U->col_ind->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)U->col_ind, i1, (int)sizeof(int));
    } else {
      i1 = U->col_ind->size[0];
      U->col_ind->size[0] = start;
      emxEnsureCapacity((emxArray__common *)U->col_ind, i1, (int)sizeof(int));
      for (i = 0; i < start; i++) {
        U->col_ind->data[i] = b_A->data[i];
      }
    }

    emxFree_int32_T(&b_A);
    emxInit_real_T(&c_A, 1);
    i1 = c_A->size[0];
    c_A->size[0] = U->val->size[0];
    emxEnsureCapacity((emxArray__common *)c_A, i1, (int)sizeof(double));
    offset = U->val->size[0];
    for (i1 = 0; i1 < offset; i1++) {
      c_A->data[i1] = U->val->data[i1];
    }

    if (start < 1) {
      i1 = U->val->size[0];
      U->val->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)U->val, i1, (int)sizeof(double));
    } else {
      i1 = U->val->size[0];
      U->val->size[0] = start;
      emxEnsureCapacity((emxArray__common *)U->val, i1, (int)sizeof(double));
      for (i = 0; i < start; i++) {
        U->val->data[i] = c_A->data[i];
      }
    }

    emxFree_real_T(&c_A);
  }
}

void crs_triu_initialize(void)
{
}

void crs_triu_terminate(void)
{
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}
