#include "crs_prodAAtx.h"
#include "m2c.h"
#include "omp.h"

static void b_crs_prodAAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b);
static void b_crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b);
static void b_crs_prodAx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, const
  emxArray_real_T *x, emxArray_real_T *b);
static void b_m2c_error(void);
static void c_crs_prodAAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b);
static void c_m2c_error(void);
static void crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b);
static void crs_prodAtx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int ncols, int nrhs,
  boolean_T ismt);
static void crs_prodAx(const emxArray_int32_T *A_row_ptr, const emxArray_int32_T
  *A_col_ind, const emxArray_real_T *A_val, int A_nrows, const emxArray_real_T
  *x, emxArray_real_T *b);
static void crs_prodAx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int nrhs, boolean_T ismt);
static void d_m2c_error(void);
static void m2c_error(void);
static void m2c_warn(void);
static void b_crs_prodAAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  emxArray_real_T *Atx;
  int i0;
  int loop_ub;
  emxInit_real_T(&Atx, 2);
  i0 = Atx->size[0] * Atx->size[1];
  Atx->size[0] = A_ncols;
  Atx->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)Atx, i0, sizeof(double));
  loop_ub = A_ncols * x->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Atx->data[i0] = 0.0;
  }

  b_crs_prodAtx(A_row_ptr, A_col_ind, A_val, A_nrows, A_ncols, x, Atx);
  i0 = b->size[0] * b->size[1];
  b->size[0] = A_nrows;
  b->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b, i0, sizeof(double));
  loop_ub = A_nrows * x->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b->data[i0] = 0.0;
  }

  b_crs_prodAx(A_row_ptr, A_col_ind, A_val, A_nrows, Atx, b);
  emxFree_real_T(&Atx);
}

static void b_crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  int i3;
  if ((b->size[0] < A_ncols) || (b->size[1] < x->size[1])) {
    c_m2c_error();
  }

  i3 = b->size[0];
  crs_prodAtx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i3, A_nrows,
                     A_ncols, x->size[1], false);
}

static void b_crs_prodAx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, const
  emxArray_real_T *x, emxArray_real_T *b)
{
  int i4;
  if ((b->size[0] < A_nrows) || (b->size[1] < x->size[1])) {
    d_m2c_error();
  }

  i4 = b->size[0];
  crs_prodAx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i4, A_nrows,
                    x->size[1], false);
}

static void b_m2c_error(void)
{
  M2C_error("prodAAtx:IncorrectBuffer", "Buffer Atx has incorrect size.");
}

static void c_crs_prodAAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  emxArray_real_T *Atx;
  int i5;
  int loop_ub;
  if ((b->size[0] < A_nrows) || (b->size[1] != x->size[1])) {

#pragma omp master
    {
      m2c_error();
    }

  }

  emxInit_real_T(&Atx, 2);
  i5 = Atx->size[0] * Atx->size[1];
  Atx->size[0] = A_ncols;
  Atx->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)Atx, i5, sizeof(double));
  loop_ub = A_ncols * x->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    Atx->data[i5] = 0.0;
  }

  b_crs_prodAtx(A_row_ptr, A_col_ind, A_val, A_nrows, A_ncols, x, Atx);
  b_crs_prodAx(A_row_ptr, A_col_ind, A_val, A_nrows, Atx, b);
  emxFree_real_T(&Atx);
}

static void c_m2c_error(void)
{
  M2C_error("crs_prodAtx:BufferTooSmal",
            "Buffer space for output b is too small.");
}

static void crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  int n;
  int i1;
  if ((b->size[0] < A_ncols) || (b->size[1] < x->size[1])) {
    c_m2c_error();
  }

  n = omp_get_num_threads();
  i1 = b->size[0];
  crs_prodAtx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i1, A_nrows,
                     A_ncols, x->size[1], n > 1);
}

static void crs_prodAtx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int ncols, int nrhs,
  boolean_T ismt)
{
  int nthreads;
  int boffset;
  int b_nthreads;
  int istart;
  int iend;
  int b_remainder;
  int k;
  int threadID;
  int j;
  int i;
  if (ismt) {
    b_nthreads = omp_get_num_threads();
    nthreads = (int)floor((double)b_m / (double)ncols);
    if (b_nthreads < nthreads) {
      nthreads = b_nthreads;
    }

    b_nthreads = omp_get_thread_num();
    boffset = b_nthreads * ncols;
    if (nthreads == 1) {
      istart = 0;
      iend = nrows;
    } else {
      threadID = omp_get_thread_num();
      if (threadID >= nthreads) {
        istart = 0;
        iend = 0;
      } else {
        iend = nrows / nthreads;
        b_remainder = nrows - nthreads * iend;
        if (b_remainder < threadID) {
          b_nthreads = b_remainder;
        } else {
          b_nthreads = threadID;
        }

        istart = threadID * iend + b_nthreads;
        iend = (istart + iend) + (threadID < b_remainder);
      }
    }

    istart++;
  } else {
    nthreads = 1;
    boffset = 0;
    istart = 1;
    iend = nrows;
  }

  if (istart <= iend) {
    b_remainder = -1;
    for (k = 1; k <= nrhs; k++) {
      threadID = boffset + ncols;
      for (j = boffset; j + 1 <= threadID; j++) {
        b->data[j] = 0.0;
      }

      for (i = istart; i <= iend; i++) {
        for (j = row_ptr->data[i - 1]; j < row_ptr->data[i]; j++) {
          b_nthreads = (boffset + col_ind->data[j - 1]) - 1;
          b->data[b_nthreads] += x->data[i + b_remainder] * val->data[j - 1];
        }
      }

      b_remainder += x_m;
      boffset += b_m;
    }
  }

  if (nthreads > 1) {

#pragma omp barrier

    b_nthreads = omp_get_num_threads();
    if (b_nthreads == 1) {
      istart = 0;
      iend = ncols;
    } else {
      threadID = omp_get_thread_num();
      iend = ncols / b_nthreads;
      b_remainder = ncols - b_nthreads * iend;
      if (b_remainder < threadID) {
        b_nthreads = b_remainder;
      } else {
        b_nthreads = threadID;
      }

      istart = threadID * iend + b_nthreads;
      iend = (istart + iend) + (threadID < b_remainder);
    }

    b_nthreads = ncols;
    for (j = 2; j <= nthreads; j++) {
      boffset = 1;
      for (k = 1; k <= nrhs; k++) {
        threadID = (boffset + iend) - 1;
        for (i = boffset + istart; i <= threadID; i++) {
          b->data[i - 1] += b->data[(b_nthreads + i) - 1];
        }

        boffset += b_m;
      }

      b_nthreads += ncols;
    }
  }
}

static void crs_prodAx(const emxArray_int32_T *A_row_ptr, const emxArray_int32_T
  *A_col_ind, const emxArray_real_T *A_val, int A_nrows, const emxArray_real_T
  *x, emxArray_real_T *b)
{
  int n;
  int i2;
  if ((b->size[0] < A_nrows) || (b->size[1] < x->size[1])) {
    d_m2c_error();
  }

  n = omp_get_num_threads();
  i2 = b->size[0];
  crs_prodAx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i2, A_nrows,
                    x->size[1], n > 1);
}

static void crs_prodAx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int nrhs, boolean_T ismt)
{
  int istart;
  int iend;
  int b_remainder;
  int threadID;
  int chunk;
  int i;
  double t;
  int j;
  if (ismt) {
    iend = omp_get_num_threads();
    if (iend == 1) {
      istart = 0;
      iend = nrows;
    } else {
      threadID = omp_get_thread_num();
      chunk = nrows / iend;
      b_remainder = nrows - iend * chunk;
      if (b_remainder < threadID) {
        iend = b_remainder;
      } else {
        iend = threadID;
      }

      istart = threadID * chunk + iend;
      iend = (istart + chunk) + (threadID < b_remainder);
    }
  } else {
    istart = 0;
    iend = nrows;
  }

  b_remainder = -1;
  threadID = -1;
  for (chunk = 1; chunk <= nrhs; chunk++) {
    for (i = istart + 1; i <= iend; i++) {
      t = 0.0;
      for (j = row_ptr->data[i - 1]; j < row_ptr->data[i]; j++) {
        t += val->data[j - 1] * x->data[b_remainder + col_ind->data[j - 1]];
      }

      b->data[threadID + i] = t;
    }

    b_remainder += x_m;
    threadID += b_m;
  }
}

static void d_m2c_error(void)
{
  M2C_error("crs_prodAx:BufferTooSmal",
            "Buffer space for output b is too small.");
}

static void m2c_error(void)
{
  M2C_error("crs_prodAAtx:IncorrectBuffer", "Buffer b has incorrect size.");
}

static void m2c_warn(void)
{
  M2C_warn("crs_prodAAtx:NestedParallel",
           "You are trying to use nested parallel regions, but nested parallelism is not enabled.");
}

void crs_prodAAtx(const struct0_T *A, const emxArray_real_T *x, emxArray_real_T *
                  b, emxArray_real_T *Atx, const emxArray_int32_T *nthreads)
{
  int n;
  boolean_T ismt;
  if ((b->size[0] < A->nrows) || (b->size[1] != x->size[1])) {

#pragma omp master
    {
      m2c_error();
    }

  }

  if ((Atx->size[0] < A->ncols) || (Atx->size[1] != x->size[1])) {

#pragma omp master
    {
      b_m2c_error();
    }

  }

  n = omp_get_num_threads();
  ismt = (n > 1);
  if (!(nthreads->size[0] == 0)) {
    n = omp_get_nested();
    if ((!(n != 0)) && ismt && (nthreads->data[0] > 1)) {

#pragma omp master
      {
        m2c_warn();
      }

    }

#pragma omp parallel default(shared) num_threads(nthreads->data[0])
    {
      crs_prodAtx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, x, Atx);

#pragma omp barrier

      crs_prodAx(A->row_ptr, A->col_ind, A->val, A->nrows, Atx, b);
    }

  } else if (ismt) {
    crs_prodAtx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, x, Atx);

#pragma omp barrier

    crs_prodAx(A->row_ptr, A->col_ind, A->val, A->nrows, Atx, b);
  } else {
    b_crs_prodAtx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, x, Atx);
    b_crs_prodAx(A->row_ptr, A->col_ind, A->val, A->nrows, Atx, b);
  }
}

void crs_prodAAtx_initialize(void)
{
}

void crs_prodAAtx_ser(const struct0_T *A, const emxArray_real_T *x,
                      emxArray_real_T *b)
{
  b_crs_prodAAtx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, x, b);
}

void crs_prodAAtx_ser1(const struct0_T *A, const emxArray_real_T *x,
  emxArray_real_T *b)
{
  c_crs_prodAAtx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, x, b);
}

void crs_prodAAtx_terminate(void)
{
}
