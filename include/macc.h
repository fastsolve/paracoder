/* 
 * macc.h
 * 
 * Include this header file allows disabling OpenACC API in the code.
 */

#ifndef __MACC_H__
#define __MACC_H__

/* Include openacc.h if M2C_OPENACC is defined */
#if M2C_OPENACC
#include "openacc.h"
#else

/* Disable all the OpenACC API functions used by MACC */

typedef void * acc_device_t;

#define acc_get_num_devices(a)   0
#define acc_set_num_devices(a)

#define acc_get_device_type(a)   NULL
#define acc_set_num_devices(a)   NULL

#define acc_set_device_num(a)   
#define acc_set_device_num(a)    0

#define acc_async_test(a)        1
#define acc_async_test_all()     1

#define acc_async_wait(a)
#define acc_async_wait_async(a, b)
#define acc_async_wait_all()
#define acc_async_wait_all_all(a)

#define acc_init(a)
#define acc_shutdown(a)

#define acc_on_device(a)              0

#define acc_malloc(a)                 NULL
#define acc_free(a)

#define acc_copyin(a, b)              NULL
#define acc_present_or_copyin(a, b)   NULL
#define acc_create(a, b)              NULL
#define acc_present_or_create(a, b)   NULL
#define acc_copyout(a, b)
#define acc_delete(a, b)
#define acc_update_device(a, b)
#define acc_update_self(a, b)
#define acc_map_data(a, b, c)
#define acc_unmap_data(a)

#define acc_deviceptr(a)              NULL
#define acc_hostptr(a)                NULL
#define acc_is_present(a, b)          0
#define acc_memcpy_to_device(a, b)    0
#define acc_memcpy_from_device(a, b)  0

#endif

#endif /* __MACC_H__ */
