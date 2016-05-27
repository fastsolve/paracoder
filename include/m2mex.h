/*
 * This file contains some macros and function declarations for m2mex.
 */

#ifndef __M2MEX_H__
#define __M2MEX_H__

#define M2C_OFFSET_PTR(ptr,offset)    ((ptr)+(offset))
#define M2C_GET_FIELD(s,field)        (s).field
#define M2C_GET_FIELD_IND(s,field)    (s)->field
#define M2C_BEGIN_REGION()            {
#define M2C_END_REGION()              }
#define M2C_INTDIV(a,b)               ((int)(a) / (int)(b))

#ifndef M2C_DEBUG
#ifdef NDEBUG
#define M2C_DEBUG  0
#else
#define M2C_DEBUG  1
#endif
#endif

#endif
