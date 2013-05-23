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

#include <time.h>

#if defined( __GNUC__) && !defined(__LCC__)
#include <sys/time.h>
#else

#ifdef _MSC_VER
/* Provides an implementation of gettimeofday for Windows
 */
#include <windows.h> 
#else
#include <math.h>
#endif

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif

struct timezone
{
    int  tz_minuteswest; /* minutes W of Greenwich */
    int  tz_dsttime;     /* type of dst correction */
};

// Definition of a gettimeofday function

int gettimeofday(struct timeval *tv, struct timezone *tz)
{
#ifdef _MSC_VER
    // Define a structure to receive the current Windows filetime
    FILETIME ft;
    
    // Initialize the present time to 0 and the timezone to UTC
    unsigned __int64 tmpres = 0;
    static int tzflag = 0;
    
    if (NULL != tv)
    {
        GetSystemTimeAsFileTime(&ft);
        
        // The GetSystemTimeAsFileTime returns the number of 100 nanosecond
        // intervals since Jan 1, 1601 in a structure. Copy the high bits to
        // the 64 bit tmpres, shift it left by 32 then or in the low 32 bits.
        tmpres |= ft.dwHighDateTime;
        tmpres <<= 32;
        tmpres |= ft.dwLowDateTime;
        
        // Convert to microseconds by dividing by 10
        tmpres /= 10;
        
        // The Unix epoch starts on Jan 1 1970.  Need to subtract the difference
        // in seconds from Jan 1 1601.
        tmpres -= DELTA_EPOCH_IN_MICROSECS;
        
        // Finally change microseconds to seconds and place in the seconds value.
        // The modulus picks up the microseconds.
        tv->tv_sec = (long)(tmpres / 1000000UL);
        tv->tv_usec = (long)(tmpres % 1000000UL);
    }
    
    if (NULL != tz) {
        if (!tzflag) {
            _tzset();
            tzflag++;
        }
        
        // Adjust for the timezone west of Greenwich
        tz->tz_minuteswest = _timezone / 60;
        tz->tz_dsttime = _daylight;
    }
#else
    double t = clock(); 
    t /= CLOCKS_PER_SEC;
    tv->tv_sec = (long)(floor(t));
    tv->tv_usec = (long)(floor((t-tv->tv_sec)*1.e6));
#endif

    return 0;
}

#endif

/*-----------------------------------------------------------------------------
 * wtime - Wall-clock time. This function is not thread safe.
 * --------------------------------------------------------------------------*/
double M2C_wtime() {
    double y = -1;
    struct timeval cur_time;
    
    gettimeofday(&cur_time, NULL);
    
    y = (double)(cur_time.tv_sec) + (double)(cur_time.tv_usec)*1.e-6;
    
    return (y);
}
