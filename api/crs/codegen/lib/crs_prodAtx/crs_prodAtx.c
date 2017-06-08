#include "crs_prodAtx.h"
#include "omp.h"
#include "m2c.h"

static void b_crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b);
static void c_crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b);
static void crs_prodAtx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int ncols, int nrhs,
  boolean_T ismt);
static void m2c_error(void);
static void m2c_warn(void);
static void b_crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  int i0;
  i0 = b->size[0] * b->size[1];
  b->size[0] = A_ncols;
  b->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b, i0, sizeof(double));
  i0 = b->size[0];
  crs_prodAtx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i0, A_nrows,
                     A_ncols, x->size[1], false);
}

static void c_crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  int i2;
  if ((b->size[0] < A_ncols) || (b->size[1] < x->size[1])) {
    m2c_error();
  }

  i2 = b->size[0];
  crs_prodAtx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i2, A_nrows,
                     A_ncols, x->size[1], false);
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

static void m2c_error(void)
{
  M2C_error("crs_prodAtx:BufferTooSmal",
            "Buffer space for output b is too small.");
}

static void m2c_warn(void)
{
  M2C_warn("crs_prodAtx:NestedParallel",
           "You are trying to use nested parallel regions. Solution may be incorrect.");
}

void crs_prodAtx(const struct0_T *A, const emxArray_real_T *x, emxArray_real_T
                 *b, const emxArray_int32_T *nthreads)
{
  int n;
  boolean_T ismt;
  int i1;
  if ((b->size[0] < A->ncols) || (b->size[1] < x->size[1])) {
    m2c_error();
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
      n = omp_get_num_threads();
      i1 = b->size[0];
      crs_prodAtx_kernel(A->row_ptr, A->col_ind, A->val, x, x->size[0], b, i1,
                         A->nrows, A->ncols, x->size[1], n > 1);
    }

  } else {
    i1 = b->size[0];
    crs_prodAtx_kernel(A->row_ptr, A->col_ind, A->val, x, x->size[0], b, i1,
                       A->nrows, A->ncols, x->size[1], ismt);
  }
}

void crs_prodAtx_initialize(void)
{
}

void crs_prodAtx_ser(const struct0_T *A, const emxArray_real_T *x,
                     emxArray_real_T *b)
{
  b_crs_prodAtx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, x, b);
}

void crs_prodAtx_ser1(const struct0_T *A, const emxArray_real_T *x,
                      emxArray_real_T *b)
{
  c_crs_prodAtx(A->row_ptr, A->col_ind, A->val, A->nrows, A->ncols, x, b);
}

void crs_prodAtx_terminate(void)
{
}
