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
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(void);
static void m2c_warn(void);
static double rt_roundd(double u);
static void b_crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  int i0;
  i0 = b->size[0] * b->size[1];
  b->size[0] = A_ncols;
  b->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b, i0, (int)sizeof(double));
  i0 = b->size[0];
  crs_prodAtx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i0, A_nrows,
                     A_ncols, x->size[1], false);
}

static void c_crs_prodAtx(const emxArray_int32_T *A_row_ptr, const
  emxArray_int32_T *A_col_ind, const emxArray_real_T *A_val, int A_nrows, int
  A_ncols, const emxArray_real_T *x, emxArray_real_T *b)
{
  int i3;
  if ((b->size[0] < A_ncols) || (b->size[1] < x->size[1])) {
    m2c_error();
  }

  i3 = b->size[0];
  crs_prodAtx_kernel(A_row_ptr, A_col_ind, A_val, x, x->size[0], b, i3, A_nrows,
                     A_ncols, x->size[1], false);
}

static void crs_prodAtx_kernel(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, const emxArray_real_T
  *x, int x_m, emxArray_real_T *b, int b_m, int nrows, int ncols, int nrhs,
  boolean_T ismt)
{
  int nthreads;
  int boffset;
  int xoffset;
  int istart;
  int b_remainder;
  int iend;
  int chunk;
  int i2;
  int j;
  int i;
  int c_remainder;
  int d_remainder;
  if (ismt) {
    xoffset = omp_get_num_threads();
    b_remainder = (int)rt_roundd(floor((double)b_m / (double)ncols));
    if (xoffset <= b_remainder) {
      nthreads = xoffset;
    } else {
      nthreads = b_remainder;
    }

    xoffset = omp_get_thread_num();
    boffset = xoffset * ncols;
    if (nthreads == 1) {
      istart = 0;
      iend = nrows;
    } else {
      iend = omp_get_thread_num();
      if (iend >= nthreads) {
        istart = 0;
        iend = 0;
      } else {
        chunk = nrows / nthreads;
        b_remainder = nrows - nthreads * chunk;
        if (b_remainder <= iend) {
          c_remainder = b_remainder;
        } else {
          c_remainder = iend;
        }

        istart = iend * chunk + c_remainder;
        iend = (istart + chunk) + (iend < b_remainder);
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
    xoffset = -1;
    for (chunk = 1; chunk <= nrhs; chunk++) {
      i2 = boffset + ncols;
      for (j = boffset; j + 1 <= i2; j++) {
        b->data[j] = 0.0;
      }

      for (i = istart; i <= iend; i++) {
        i2 = row_ptr->data[i] - 1;
        for (j = row_ptr->data[i - 1]; j <= i2; j++) {
          b_remainder = (boffset + col_ind->data[j - 1]) - 1;
          b->data[b_remainder] += x->data[i + xoffset] * val->data[j - 1];
        }
      }

      xoffset += x_m;
      boffset += b_m;
    }
  }

  if (nthreads > 1) {

#pragma omp barrier

    xoffset = omp_get_num_threads();
    if (xoffset == 1) {
      istart = 0;
      iend = ncols;
    } else {
      iend = omp_get_thread_num();
      chunk = ncols / xoffset;
      b_remainder = ncols - xoffset * chunk;
      if (b_remainder <= iend) {
        d_remainder = b_remainder;
      } else {
        d_remainder = iend;
      }

      istart = iend * chunk + d_remainder;
      iend = (istart + chunk) + (iend < b_remainder);
    }

    xoffset = ncols;
    for (j = 2; j <= nthreads; j++) {
      boffset = 1;
      for (chunk = 1; chunk <= nrhs; chunk++) {
        i2 = (boffset + iend) - 1;
        for (i = boffset + istart; i <= i2; i++) {
          b->data[i - 1] += b->data[(xoffset + i) - 1];
        }

        boffset += b_m;
      }

      xoffset += ncols;
    }
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
  M2C_error("crs_prodAtx:BufferTooSmal",
            "Buffer space for output b is too small.");
}

static void m2c_warn(void)
{
  M2C_warn("crs_prodAtx:NestedParallel",
           "You are trying to use nested parallel regions. Solution may be incorrect.");
}

static double rt_roundd(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
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

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}
