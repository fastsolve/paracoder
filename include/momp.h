/* 
 * momp.h
 * 
 * Include this header file allows disabling OpenMP API in the code.
 */

#ifndef __MOMP_H__
#define __MOMP_H__

/* Include omp.h if M2C_OPENMP is defined */
#ifdef M2C_OPENMP
#include "omp.h"
#else

/* Disable all the OpenMP API functions used by MOMP */

#define omp_get_dynamic()        1
#define omp_get_max_threads()    1
#define omp_get_nested()         0
#define omp_get_num_procs()      1
#define omp_get_num_threads()    1
#define omp_get_thread_num()     0
#define omp_get_wtick()          0
#define omp_get_wtime()          0
#define omp_in_parallel()        0
#define omp_set_dynamic(a)
#define omp_set_nested(a)      
#define omp_set_num_threads(n)

#endif

#endif /* __MOMP_H__ */
