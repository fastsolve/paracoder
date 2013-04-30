/*
 * Some kernel macros for sparse matrices
 */

#ifndef _SPL_KERNEL_
#define _SPL_KERNEL_

/* Computes t = x[0:n-1]'*y[i[0:n-1]-1] */
__inline__ double SPL_ddot(const double *x, const int32_T *i, const double *y, int32_T n) {
    int32_T j;
    double t = 0.0;
    
    y=y-1;
    for (j=0; j<n; ++j) t += (*x++) * y[*i++];
    return t;
}

/* Computes t = x[0:n-1]'*y[i[0:n-1]-1] */
__inline__ float SPL_sdot(const float *x, const int32_T *i, const float *y, int32_T n) {
    int32_T j;
    float t = 0.0;
    
    y=y-1;
    for (j=0; j<n; ++j) t += (*x++) * y[*i++];
    return t;
}

/* Computes y[i[0:n-1]-1] += a*x[0:n-1] */
__inline__ void SPL_saxpy(float a, const float *x, float *y, const int32_T *i, int32_T n) {
    int32_T j=1;
    y = y-1;
    for (j=0; j<n; ++j) y[*i++] += a * (*x++);
}

/* Computes y[i[0:n-1]-1] += a*x[0:n-1] */
__inline__ void SPL_daxpy(double a, const double *x, double *y, const int32_T *i, int32_T n) {
    int32_T j=1;
    y = y-1;
    for (j=0; j<n; ++j) y[*i++] += a * (*x++);
}

#endif
