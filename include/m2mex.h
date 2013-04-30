/*
 * This file contains some macros and function declarations for m2mex.
 */

#ifndef __M2MEX_H__
#define __M2MEX_H__

#define M2C_OFFSET_PTR(a,b)    ((char *)a)+(b)
#define M2C_BEGIN_REGION()     {
#define M2C_END_REGION()       }

#define M2C_CHK_OPAQUE_PTR(ptr,parent,offset) \
        if ((parent) && (ptr) != ((char*)mxGetData(parent))+(offset)) \
        mexErrMsgIdAndTxt("opaque_ptr:ParentObjectChanged", \
        "The parent mxArray has changed. Avoid changing a MATLAB variable when dereferenced by an opaque_ptr.");

#endif
