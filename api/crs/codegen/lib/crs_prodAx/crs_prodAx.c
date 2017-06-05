#include "crs_prodAx.h"
#include "omp.h"
#include "m2c.h"

static void b_crs_prodAx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, const
  emxArray_real_T *x, emxArray_real_T *b);
static void c_crs_prodAx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, const
  emxArray_real_T *x, emxArray_real_T *b);
static void crs_prodAx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int nrhs, boolean_T ismt);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(void);
static void m2c_warn(void);
static void b_crs_prodAx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, const
  emxArray_real_T *x, emxArray_real_T *b)
{
  int i0;
  i0 = b->size[0] * b->size[1];
  b->size[0] = A_nrows;
  b->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b, i0, (int)sizeof(double));
  i0 = b->size[0];
  crs_prodAx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i0, A_nrows,
                    x->size[1], false);
}

static void c_crs_prodAx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, const
  emxArray_real_T *x, emxArray_real_T *b)
{
  int i2;
  if ((b->size[0] < A_nrows) || (b->size[1] < x->size[1])) {
    m2c_error();
  }

  i2 = b->size[0];
  crs_prodAx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i2, A_nrows,
                    x->size[1], false);
}

static void crs_prodAx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int nrhs, boolean_T ismt)
{
  int istart;
  int iend;
  int threadID;
  int chunk;
  int k;
  int i;
  int b_iend;
  double t;
  int i1;
  int j;
  if (ismt) {
    iend = omp_get_num_threads();
    if (iend == 1) {
      istart = 0;
      iend = nrows;
    } else {
      threadID = omp_get_thread_num();
      chunk = nrows / iend;
      iend = nrows - iend * chunk;
      if (iend <= threadID) {
        b_iend = iend;
      } else {
        b_iend = threadID;
      }

      istart = threadID * chunk + b_iend;
      iend = (istart + chunk) + (threadID < iend);
    }
  } else {
    istart = 0;
    iend = nrows;
  }

  threadID = -1;
  chunk = -1;
  for (k = 1; k <= nrhs; k++) {
    for (i = istart + 1; i <= iend; i++) {
      t = 0.0;
      i1 = row_ptr->data[i] - 1;
      for (j = row_ptr->data[i - 1]; j <= i1; j++) {
        t += val->data[j - 1] * x->data[threadID + col_ind->data[j - 1]];
      }

      b->data[chunk + i] = t;
    }

    threadID += x_m;
    chunk += b_m;
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

static void m2c_error(void)
{
  M2C_error("crs_prodAx:BufferTooSmal",
            "Buffer space for output b is too small.");
}

static void m2c_warn(void)
{
  M2C_warn("crs_prodAx:NestedParallel",
           "You are trying to use nested parallel regions. Solution may be incorrect.");
}

void crs_prodAx(const struct0_T *A, const emxArray_real_T *x, emxArray_real_T *b,
                int nthreads)
{
  int n;
  int b_n;
  if ((b->size[0] < A->nrows) || (b->size[1] < x->size[1])) {
    m2c_error();
  }

  n = omp_get_num_threads();
  b_n = omp_get_nested();
  if ((!(b_n != 0)) && (n > 1) && (nthreads > 1)) {

#pragma omp master
    {
      m2c_warn();
    }

  }

#pragma omp parallel default(shared) num_threads(nthreads)
  {
    n = omp_get_num_threads();
    b_n = b->size[0];
    crs_prodAx_kernel(A->row_ptr, A->col_ind, A->val, x, x->size[0], b, b_n,
                      A->nrows, x->size[1], n > 1);
  }

}

void crs_prodAx_initialize(void)
{
}

void crs_prodAx_ser(const struct0_T *A, const emxArray_real_T *x,
                    emxArray_real_T *b)
{
  b_crs_prodAx(A->row_ptr, A->col_ind, A->val, A->nrows, x, b);
}

void crs_prodAx_ser1(const struct0_T *A, const emxArray_real_T *x,
                     emxArray_real_T *b)
{
  c_crs_prodAx(A->row_ptr, A->col_ind, A->val, A->nrows, x, b);
}

void crs_prodAx_terminate(void)
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