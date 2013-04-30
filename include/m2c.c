/*
 * This file contains public functions for m2c.
 */

#include "rtwtypes.h"
#include "m2c.h"

define_emxEnsureCapacity

#ifdef struct_emxArray_boolean_T
define_emxInit( emxInit_boolean_T, boolean_T)
define_emxFree( emxFree_boolean_T, boolean_T)

define_emxCreate( emxInit_boolean_T, boolean_T)
define_emxCreateND( emxInit_boolean_T, boolean_T)
define_emxCreateWrapper( emxInit_boolean_T, boolean_T, boolean_T)
define_emxCreateWrapperND( emxInit_boolean_T, boolean_T, boolean_T)
define_emxDestroyArray( emxFree_boolean_T, boolean_T)
#endif


#ifdef struct_emxArray_char_T
define_emxInit( emxInit_char_T, char_T)
define_emxFree( emxFree_char_T, char_T)

define_emxCreate( emxInit_char_T, char_T)
define_emxCreateND( emxInit_char_T, char_T)
define_emxCreateWrapper( emxInit_char_T, char_T, char_T)
define_emxCreateWrapperND( emxInit_char_T, char_T, char_T)
define_emxDestroyArray( emxFree_char_T, char_T)
#endif

#ifdef struct_emxArray_int8_T
define_emxInit( emxInit_int8_T, int8_T)
define_emxFree( emxFree_int8_T, int8_T)

define_emxCreate( emxInit_int8_T, int8_T)
define_emxCreateND( emxInit_int8_T, int8_T)
define_emxCreateWrapper( emxInit_int8_T, int8_T, int8_T)
define_emxCreateWrapperND( emxInit_int8_T, int8_T, int8_T)
define_emxDestroyArray( emxFree_int8_T, int8_T)
#endif

#ifdef struct_emxArray_int16_T
define_emxInit( emxInit_int16_T, int16_T)
define_emxFree( emxFree_int16_T, int16_T)

define_emxCreate( emxInit_int16_T, int16_T)
define_emxCreateND( emxInit_int16_T, int16_T)
define_emxCreateWrapper( emxInit_int16_T, int16_T, int16_T)
define_emxCreateWrapperND( emxInit_int16_T, int16_T, int16_T)
define_emxDestroyArray( emxFree_int16_T, int16_T)
#endif

#ifdef struct_emxArray_int32_T
define_emxInit( emxInit_int32_T, int32_T)
define_emxFree( emxFree_int32_T, int32_T)

define_emxCreate( emxInit_int32_T, int32_T)
define_emxCreateND( emxInit_int32_T, int32_T)
define_emxCreateWrapper( emxInit_int32_T, int32_T, int32_T)
define_emxCreateWrapperND( emxInit_int32_T, int32_T, int32_T)
define_emxDestroyArray( emxFree_int32_T, int32_T)
#endif

#ifdef struct_emxArray_int64_T
define_emxInit( emxInit_int64_T, int64_T)
define_emxFree( emxFree_int64_T, int64_T)

define_emxCreate( emxInit_int64_T, int64_T)
define_emxCreateND( emxInit_int64_T, int64_T)
define_emxCreateWrapper( emxInit_int64_T, int64_T, int64_T)
define_emxCreateWrapperND( emxInit_int64_T, int64_T, int64_T)
define_emxDestroyArray( emxFree_int64_T, int64_T)
#endif

#ifdef struct_emxArray_uint8_T
define_emxInit( emxInit_uint8_T, uint8_T)
define_emxFree( emxFree_uint8_T, uint8_T)

define_emxCreate( emxInit_uint8_T, uint8_T)
define_emxCreateND( emxInit_uint8_T, uint8_T)
define_emxCreateWrapper( emxInit_uint8_T, uint8_T, uint8_T)
define_emxCreateWrapperND( emxInit_uint8_T, uint8_T, uint8_T)
define_emxDestroyArray( emxFree_uint8_T, uint8_T)
#endif

#ifdef struct_emxArray_uint16_T
define_emxInit( emxInit_uint16_T, uint16_T)
define_emxFree( emxFree_uint16_T, uint16_T)

define_emxCreate( emxInit_uint16_T, uint16_T)
define_emxCreateND( emxInit_uint16_T, uint16_T)
define_emxCreateWrapper( emxInit_uint16_T, uint16_T, uint16_T)
define_emxCreateWrapperND( emxInit_uint16_T, uint16_T, uint16_T)
define_emxDestroyArray( emxFree_uint16_T, uint16_T)
#endif

#ifdef struct_emxArray_uint32_T
define_emxInit( emxInit_uint32_T, uint32_T)
define_emxFree( emxFree_uint32_T, uint32_T)

define_emxCreate( emxInit_uint32_T, uint32_T)
define_emxCreateND( emxInit_uint32_T, uint32_T)
define_emxCreateWrapper( emxInit_uint32_T, uint32_T, uint32_T)
define_emxCreateWrapperND( emxInit_uint32_T, uint32_T, uint32_T)
define_emxDestroyArray( emxFree_uint32_T, uint32_T)
#endif

#ifdef struct_emxArray_uint64_T
define_emxInit( emxInit_uint64_T, uint64_T)
define_emxFree( emxFree_uint64_T, uint64_T)

define_emxCreate( emxInit_uint64_T, uint64_T)
define_emxCreateND( emxInit_uint64_T, uint64_T)
define_emxCreateWrapper( emxInit_uint64_T, uint64_T, uint64_T)
define_emxCreateWrapperND( emxInit_uint64_T, uint64_T, uint64_T)
define_emxDestroyArray( emxFree_uint64_T, uint64_T)
#endif

#ifdef struct_emxArray_real_T
define_emxInit( emxInit_real_T, real_T)
define_emxFree( emxFree_real_T, real_T)

define_emxCreate( emxInit_real_T, real_T)
define_emxCreateND( emxInit_real_T, real_T)
define_emxCreateWrapper( emxInit_real_T, real_T, real_T)
define_emxCreateWrapperND( emxInit_real_T, real_T, real_T)
define_emxDestroyArray( emxFree_real_T, real_T)
#endif

#ifdef struct_emxArray_real32_T
define_emxInit( emxInit_real32_T, real32_T)
define_emxFree( emxFree_real32_T, real32_T)

define_emxCreate( emxInit_real32_T, real32_T)
define_emxCreateND( emxInit_real32_T, real32_T)
define_emxCreateWrapper( emxInit_real32_T, real32_T, real32_T)
define_emxCreateWrapperND( emxInit_real32_T, real32_T, real32_T)
define_emxDestroyArray( emxFree_real32_T, real32_T)
#endif

#ifdef struct_emxArray_real64_T
define_emxInit( emxInit_real64_T, real64_T)
define_emxFree( emxFree_real64_T, real64_T)

define_emxCreate( emxInit_real64_T, real64_T)
define_emxCreateND( emxInit_real64_T, real64_T)
define_emxCreateWrapper( emxInit_real64_T, real64_T, real64_T)
define_emxCreateWrapperND( emxInit_real64_T, real64_T, real64_T)
define_emxDestroyArray( emxFree_real64_T, real64_T)
#endif