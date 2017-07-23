#include "crs_prodAtAx.h"
#include "omp.h"
#include "m2c.h"

static void b_crs_prodAtAx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b);
static void b_crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b);
static void b_crs_prodAtx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int ncols, int nrhs,
  boolean_T varargin_1);
static void b_crs_prodAx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int nrhs, boolean_T
  varargin_1);
static void b_m2c_error(void);
static void c_crs_prodAtAx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b);
static void c_m2c_error(void);
static void crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b);
static void crs_prodAtx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int ncols, int nrhs);
static void crs_prodAx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int nrhs);
static void d_m2c_error(void);
static void m2c_error(void);
static void m2c_warn(void);
static void b_crs_prodAtAx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  int A_nrows_idx_1;
  emxArray_real_T *Ax;
  int loop_ub;
  A_nrows_idx_1 = x->size[1];
  if (A_nrows_idx_1 < x->size[1]) {
    c_m2c_error();
  }

  emxInit_real_T(&Ax, 2);
  A_nrows_idx_1 = Ax->size[0] * Ax->size[1];
  Ax->size[0] = A_nrows;
  Ax->size[1] = x->size[1];
  emxEnsureCapacity_real_T(Ax, A_nrows_idx_1);
  loop_ub = A_nrows * x->size[1];
  for (A_nrows_idx_1 = 0; A_nrows_idx_1 < loop_ub; A_nrows_idx_1++) {
    Ax->data[A_nrows_idx_1] = 0.0;
  }

  crs_prodAx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], Ax, A_nrows,
                    A_nrows, x->size[1]);
  A_nrows_idx_1 = b->size[0] * b->size[1];
  b->size[0] = A_ncols;
  b->size[1] = x->size[1];
  emxEnsureCapacity_real_T(b, A_nrows_idx_1);
  loop_ub = A_ncols * x->size[1];
  for (A_nrows_idx_1 = 0; A_nrows_idx_1 < loop_ub; A_nrows_idx_1++) {
    b->data[A_nrows_idx_1] = 0.0;
  }

  b_crs_prodAtx(A_row_ptr, A_col_ind, A_val, A_nrows, A_ncols, Ax, b);
  emxFree_real_T(&Ax);
}

static void b_crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  int i0;
  if ((b->size[0] < A_ncols) || (b->size[1] < x->size[1])) {
    d_m2c_error();
  }

  i0 = b->size[0];
  crs_prodAtx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i0, A_nrows,
                     A_ncols, x->size[1]);
}

static void b_crs_prodAtx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int ncols, int nrhs,
  boolean_T varargin_1)
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
  if (varargin_1) {
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

static void b_crs_prodAx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int nrhs, boolean_T
  varargin_1)
{
  int istart;
  int iend;
  int b_remainder;
  int threadID;
  int chunk;
  int i;
  double t;
  int j;
  if (varargin_1) {
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

static void b_m2c_error(void)
{
  M2C_error("prodAAtx:IncorrectBuffer", "Buffer Ax has incorrect size.");
}

static void c_crs_prodAtAx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  int A_nrows_idx_1;
  emxArray_real_T *Ax;
  int loop_ub;
  if ((b->size[0] < A_ncols) || (b->size[1] != x->size[1])) {

#pragma omp master
    {
      m2c_error();
    }

  }

  A_nrows_idx_1 = x->size[1];
  if (A_nrows_idx_1 < x->size[1]) {
    c_m2c_error();
  }

  emxInit_real_T(&Ax, 2);
  A_nrows_idx_1 = Ax->size[0] * Ax->size[1];
  Ax->size[0] = A_nrows;
  Ax->size[1] = x->size[1];
  emxEnsureCapacity_real_T(Ax, A_nrows_idx_1);
  loop_ub = A_nrows * x->size[1];
  for (A_nrows_idx_1 = 0; A_nrows_idx_1 < loop_ub; A_nrows_idx_1++) {
    Ax->data[A_nrows_idx_1] = 0.0;
  }

  crs_prodAx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], Ax, A_nrows,
                    A_nrows, x->size[1]);
  b_crs_prodAtx(A_row_ptr, A_col_ind, A_val, A_nrows, A_ncols, Ax, b);
  emxFree_real_T(&Ax);
}

static void c_m2c_error(void)
{
  M2C_error("crs_prodAx:BufferTooSmal",
            "Buffer space for output b is too small.");
}

static void crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  int n;
  if ((b->size[0] < A_ncols) || (b->size[1] < x->size[1])) {
    d_m2c_error();
  }

  n = omp_get_num_threads();
  if (n == 1) {
    n = b->size[0];
    crs_prodAtx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, n, A_nrows,
                       A_ncols, x->size[1]);
  } else {
    n = b->size[0];
    b_crs_prodAtx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, n,
                         A_nrows, A_ncols, x->size[1], true);
  }
}

static void crs_prodAtx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int ncols, int nrhs)
{
  int boffset;
  int xoffset;
  int k;
  int i;
  int j;
  int r;
  boffset = 0;
  if (1 <= nrows) {
    xoffset = -1;
    for (k = 1; k <= nrhs; k++) {
      i = boffset + ncols;
      for (j = boffset; j + 1 <= i; j++) {
        b->data[j] = 0.0;
      }

      for (i = 1; i <= nrows; i++) {
        for (j = row_ptr->data[i - 1]; j < row_ptr->data[i]; j++) {
          r = (boffset + col_ind->data[j - 1]) - 1;
          b->data[r] += x->data[i + xoffset] * val->data[j - 1];
        }
      }

      xoffset += x_m;
      boffset += b_m;
    }
  }
}

static void crs_prodAx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int nrhs)
{
  int xoffset;
  int boffset;
  int k;
  int i;
  double t;
  int j;
  xoffset = -1;
  boffset = -1;
  for (k = 1; k <= nrhs; k++) {
    for (i = 1; i <= nrows; i++) {
      t = 0.0;
      for (j = row_ptr->data[i - 1]; j < row_ptr->data[i]; j++) {
        t += val->data[j - 1] * x->data[xoffset + col_ind->data[j - 1]];
      }

      b->data[boffset + i] = t;
    }

    xoffset += x_m;
    boffset += b_m;
  }
}

static void d_m2c_error(void)
{
  M2C_error("crs_prodAtx:BufferTooSmal",
            "Buffer space for output b is too small.");
}

static void m2c_error(void)
{
  M2C_error("crs_prodAAtx:IncorrectBuffer", "Buffer b has incorrect size.");
}

static void m2c_warn(void)
{
  M2C_warn("crs_prodAtAx:NestedParallel",
           "You are trying to use nested parallel regions, but nested parallelism is not enabled.");
}

void crs_prodAtAx(const struct0_T *A, const emxArray_real_T *x, emxArray_real_T *
                  b, emxArray_real_T *Ax, const emxArray_int32_T *nthreads)
{
  int n;
  if ((b->size[0] < A->ncols) || (b->size[1] != x->size[1])) {

#pragma omp master
    {
      m2c_error();
    }

  }

  if ((Ax->size[0] < A->nrows) || (Ax->size[1] != x->size[1])) {

#pragma omp master
    {
      b_m2c_error();
    }

  }

  if (!(nthreads->size[0] == 0)) {
    n = omp_get_nested();
    if (!(n != 0)) {
      n = omp_get_num_threads();
      if ((n > 1) && (nthreads->data[0] > 1)) {

#pragma omp master
        {
          m2c_warn();
        }

      }
    }

#pragma omp parallel default(shared) num_threads(nthreads->data[0])
    {
      if ((Ax->size[0] < A->nrows) || (Ax->size[1] < x->size[1])) {
        c_m2c_error();
      }

      n = omp_get_num_threads();
      if (n == 1) {
        n = Ax->size[0];
        crs_prodAx_kernel(A->row_ptr, A->col_ind, A->val, x, x->size[0], Ax, n,
                          A->nrows, x->size[1]);
      } else {
        n = Ax->size[0];
        b_crs_prodAx_kernel(A->row_ptr, A->col_ind, A->val, x, x->size[0], Ax, n,
                            A->nrows, x->size[1], true);
      }

#pragma omp barrier

      crs_prodAtx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, Ax, b);
    }

  } else {
    n = omp_get_num_threads();
    if (n > 1) {
      if ((Ax->size[0] < A->nrows) || (Ax->size[1] < x->size[1])) {
        c_m2c_error();
      }

      n = omp_get_num_threads();
      if (n == 1) {
        n = Ax->size[0];
        crs_prodAx_kernel(A->row_ptr, A->col_ind, A->val, x, x->size[0], Ax, n,
                          A->nrows, x->size[1]);
      } else {
        n = Ax->size[0];
        b_crs_prodAx_kernel(A->row_ptr, A->col_ind, A->val, x, x->size[0], Ax, n,
                            A->nrows, x->size[1], true);
      }

#pragma omp barrier

      crs_prodAtx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, Ax, b);
    } else {
      if ((Ax->size[0] < A->nrows) || (Ax->size[1] < x->size[1])) {
        c_m2c_error();
      }

      n = Ax->size[0];
      crs_prodAx_kernel(A->row_ptr, A->col_ind, A->val, x, x->size[0], Ax, n,
                        A->nrows, x->size[1]);
      b_crs_prodAtx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, Ax, b);
    }
  }
}

void crs_prodAtAx_initialize(void)
{
}

void crs_prodAtAx_ser(const struct0_T *A, const emxArray_real_T *x,
                      emxArray_real_T *b)
{
  b_crs_prodAtAx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, x, b);
}

void crs_prodAtAx_ser1(const struct0_T *A, const emxArray_real_T *x,
  emxArray_real_T *b)
{
  c_crs_prodAtAx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, x, b);
}

void crs_prodAtAx_terminate(void)
{
}
