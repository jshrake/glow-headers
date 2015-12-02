/*
 * glow-1.0.0: public-domain OpenGL function loader
 *
 * This file was generated with glow https://github.com/jshrake/glow
 * 
 * Version: 1.0.0
 * Date: 2015-11-27 09:08:26.126723687 -0800 PST
 * Language: C
 * Specification: 2.0
 * API: gles2
 * Profile: core
 * Command-line: glow --api="gles2" --spec="2.0" --profile="core" --debug=true
 * Extensions:

 * 
 * -----
 * USAGE
 * -----
 * Do this:
 *    #define GLOW_IMPLEMENTATION
 * before you include this file in *one* C or C++ file to create the implementation.
 *
 * -------
 * EXAMPLE
 * -------
 * #include ...
 * #include ...
 * #define GLOW_IMPLEMENTATION
 * #include "glow.h"
 * 
 
 * - #define GLOW_DEBUG before the #include to enable pre and post function callbacks
 * - #define GLOW_ASSERT(x) before the #include to avoid including assert.h
 * - #define GLOW_NO_STDIO before the #include to avoid including stdio.h for print debugging
 *
 * Users are encouraged to call glow_init or glow_init_with after OpenGL context creation
 * to eagerly load the OpenGL function pointers. If no initialization function
 * is called, the function pointers are lazily loaded during the first call.
 *
 * Users can specify their own function to load the OpenGL procedures via glow_init_with.
 * Calling glow_init is equivalent to calling glow_init_with(&glow_get_proc);
 *
 */
#ifndef GLOW_INCLUDE_GLOW_H
#define GLOW_INCLUDE_GLOW_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef GLOW_STATIC
#define GLOWDEF static
#else
#define GLOWDEF extern
#endif
/*
 * ---------------------------
 * Glow API
 * ---------------------------
 */
typedef void* (*glow_load_proc_t)(char const *name);
/*
 * Platform specific function for returning OpenGL function pointers by name
 * Returns NULL on failure to to open the OpenGL library image and on failure
 * to load the procedure given by name.
 */
GLOWDEF void *glow_get_proc(char const *name);
/*
 * Eagerly load OpenGL function pointers using glow_get_proc. Returns the
 * number of functions that failed to load. A return value of 0 indicates
 * success.
 */
GLOWDEF int glow_init(void);
/*
 * Eagerly load OpenGL function pointers with the specified loading function.
 * Returns the number of functions that failed to load. A return value of 0
 * indicates success.
 */
GLOWDEF int glow_init_with(glow_load_proc_t get_proc);


typedef void (*glow_debug_proc_t)(char const *name, void *funcptr, ...);
/*
 * Specify a callback to call before OpenGL function calls
 */
GLOWDEF void glow_set_pre_callback(glow_debug_proc_t callback);
/*
 * Specify a callback to call after OpenGL function calls
 */
GLOWDEF void glow_set_post_callback(glow_debug_proc_t callback);


#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif

/*
 * ---------------------------
 * Required includes
 * ---------------------------
 */

#ifndef __khrplatform_h_
#define __khrplatform_h_

/*
** Copyright (c) 2008-2009 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

/* Khronos platform-specific types and definitions.
 *
 * $Revision: 23298 $ on $Date: 2013-09-30 17:07:13 -0700 (Mon, 30 Sep 2013) $
 *
 * Adopters may modify this file to suit their platform. Adopters are
 * encouraged to submit platform specific modifications to the Khronos
 * group so that they can be included in future versions of this file.
 * Please submit changes by sending them to the public Khronos Bugzilla
 * (http://khronos.org/bugzilla) by filing a bug against product
 * "Khronos (general)" component "Registry".
 *
 * A predefined template which fills in some of the bug fields can be
 * reached using http://tinyurl.com/khrplatform-h-bugreport, but you
 * must create a Bugzilla login first.
 *
 *
 * See the Implementer's Guidelines for information about where this file
 * should be located on your system and for more details of its use:
 *    http://www.khronos.org/registry/implementers_guide.pdf
 *
 * This file should be included as
 *        #include <KHR/khrplatform.h>
 * by Khronos client API header files that use its types and defines.
 *
 * The types in khrplatform.h should only be used to define API-specific types.
 *
 * Types defined in khrplatform.h:
 *    khronos_int8_t              signed   8  bit
 *    khronos_uint8_t             unsigned 8  bit
 *    khronos_int16_t             signed   16 bit
 *    khronos_uint16_t            unsigned 16 bit
 *    khronos_int32_t             signed   32 bit
 *    khronos_uint32_t            unsigned 32 bit
 *    khronos_int64_t             signed   64 bit
 *    khronos_uint64_t            unsigned 64 bit
 *    khronos_intptr_t            signed   same number of bits as a pointer
 *    khronos_uintptr_t           unsigned same number of bits as a pointer
 *    khronos_ssize_t             signed   size
 *    khronos_usize_t             unsigned size
 *    khronos_float_t             signed   32 bit floating point
 *    khronos_time_ns_t           unsigned 64 bit time in nanoseconds
 *    khronos_utime_nanoseconds_t unsigned time interval or absolute time in
 *                                         nanoseconds
 *    khronos_stime_nanoseconds_t signed time interval in nanoseconds
 *    khronos_boolean_enum_t      enumerated boolean type. This should
 *      only be used as a base type when a client API's boolean type is
 *      an enum. Client APIs which use an integer or other type for
 *      booleans cannot use this as the base type for their boolean.
 *
 * Tokens defined in khrplatform.h:
 *
 *    KHRONOS_FALSE, KHRONOS_TRUE Enumerated boolean false/true values.
 *
 *    KHRONOS_SUPPORT_INT64 is 1 if 64 bit integers are supported; otherwise 0.
 *    KHRONOS_SUPPORT_FLOAT is 1 if floats are supported; otherwise 0.
 *
 * Calling convention macros defined in this file:
 *    KHRONOS_APICALL
 *    KHRONOS_APIENTRY
 *    KHRONOS_APIATTRIBUTES
 *
 * These may be used in function prototypes as:
 *
 *      KHRONOS_APICALL void KHRONOS_APIENTRY funcname(
 *                                  int arg1,
 *                                  int arg2) KHRONOS_APIATTRIBUTES;
 */

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APICALL
 *-------------------------------------------------------------------------
 * This precedes the return type of the function in the function prototype.
 */
#if defined(_WIN32) && !defined(__SCITECH_SNAP__)
#   define KHRONOS_APICALL __declspec(dllimport)
#elif defined (__SYMBIAN32__)
#   define KHRONOS_APICALL IMPORT_C
#else
#   define KHRONOS_APICALL
#endif

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APIENTRY
 *-------------------------------------------------------------------------
 * This follows the return type of the function  and precedes the function
 * name in the function prototype.
 */
#if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__SCITECH_SNAP__)
    /* Win32 but not WinCE */
#   define KHRONOS_APIENTRY __stdcall
#else
#   define KHRONOS_APIENTRY
#endif

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APIATTRIBUTES
 *-------------------------------------------------------------------------
 * This follows the closing parenthesis of the function prototype arguments.
 */
#if defined (__ARMCC_2__)
#define KHRONOS_APIATTRIBUTES __softfp
#else
#define KHRONOS_APIATTRIBUTES
#endif

/*-------------------------------------------------------------------------
 * basic type definitions
 *-----------------------------------------------------------------------*/
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)


/*
 * Using <stdint.h>
 */
#include <stdint.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__VMS ) || defined(__sgi)

/*
 * Using <inttypes.h>
 */
#include <inttypes.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)

/*
 * Win32
 */
typedef __int32                 khronos_int32_t;
typedef unsigned __int32        khronos_uint32_t;
typedef __int64                 khronos_int64_t;
typedef unsigned __int64        khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__sun__) || defined(__digital__)

/*
 * Sun or Digital
 */
typedef int                     khronos_int32_t;
typedef unsigned int            khronos_uint32_t;
#if defined(__arch64__) || defined(_LP64)
typedef long int                khronos_int64_t;
typedef unsigned long int       khronos_uint64_t;
#else
typedef long long int           khronos_int64_t;
typedef unsigned long long int  khronos_uint64_t;
#endif /* __arch64__ */
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif 0

/*
 * Hypothetical platform with no float or int64 support
 */
typedef int                     khronos_int32_t;
typedef unsigned int            khronos_uint32_t;
#define KHRONOS_SUPPORT_INT64   0
#define KHRONOS_SUPPORT_FLOAT   0

#else

/*
 * Generic fallback
 */
#include <stdint.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#endif


/*
 * Types that are (so far) the same on all platforms
 */
typedef signed   char          khronos_int8_t;
typedef unsigned char          khronos_uint8_t;
typedef signed   short int     khronos_int16_t;
typedef unsigned short int     khronos_uint16_t;

/*
 * Types that differ between LLP64 and LP64 architectures - in LLP64, 
 * pointers are 64 bits, but 'long' is still 32 bits. Win64 appears
 * to be the only LLP64 architecture in current use.
 */
#ifdef _WIN64
typedef signed   long long int khronos_intptr_t;
typedef unsigned long long int khronos_uintptr_t;
typedef signed   long long int khronos_ssize_t;
typedef unsigned long long int khronos_usize_t;
#else
typedef signed   long  int     khronos_intptr_t;
typedef unsigned long  int     khronos_uintptr_t;
typedef signed   long  int     khronos_ssize_t;
typedef unsigned long  int     khronos_usize_t;
#endif

#if KHRONOS_SUPPORT_FLOAT
/*
 * Float type
 */
typedef          float         khronos_float_t;
#endif

#if KHRONOS_SUPPORT_INT64
/* Time types
 *
 * These types can be used to represent a time interval in nanoseconds or
 * an absolute Unadjusted System Time.  Unadjusted System Time is the number
 * of nanoseconds since some arbitrary system event (e.g. since the last
 * time the system booted).  The Unadjusted System Time is an unsigned
 * 64 bit value that wraps back to 0 every 584 years.  Time intervals
 * may be either signed or unsigned.
 */
typedef khronos_uint64_t       khronos_utime_nanoseconds_t;
typedef khronos_int64_t        khronos_stime_nanoseconds_t;
#endif

/*
 * Dummy value used to pad enum types to 32 bits.
 */
#ifndef KHRONOS_MAX_ENUM
#define KHRONOS_MAX_ENUM 0x7FFFFFFF
#endif

/*
 * Enumerated boolean type
 *
 * Values other than zero should be considered to be true.  Therefore
 * comparisons should not be made against KHRONOS_TRUE.
 */
typedef enum {
    KHRONOS_FALSE = 0,
    KHRONOS_TRUE  = 1,
    KHRONOS_BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM
} khronos_boolean_enum_t;

#endif /* __khrplatform_h_ */


#include <stddef.h>
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif

/*
 * ---------------------------
 * Versions
 * ---------------------------
 */
#define GL_ES_VERSION_2_0

/*
 * ---------------------------
 * Types
 * ---------------------------
 */
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLclampx;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void *GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;
#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
typedef unsigned short GLhalfARB;
typedef unsigned short GLhalf;
typedef GLint GLfixed;
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;
typedef int64_t GLint64;
typedef uint64_t GLuint64;
typedef ptrdiff_t GLintptrARB;
typedef ptrdiff_t GLsizeiptrARB;
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;
typedef struct __GLsync *GLsync;
struct _cl_context;
struct _cl_event;
typedef void (APIENTRYP *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRYP *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRYP *GLDEBUGPROCKHR)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef khronos_int8_t GLbyte;
typedef khronos_uint8_t GLubyte;
typedef khronos_float_t GLfloat;
typedef khronos_float_t GLclampf;
typedef khronos_int32_t GLfixed;
typedef khronos_int64_t GLint64;
typedef khronos_uint64_t GLuint64;
typedef khronos_int64_t GLint64EXT;
typedef khronos_uint64_t GLuint64EXT;
typedef khronos_intptr_t GLintptr;
typedef khronos_ssize_t GLsizeiptr;
typedef void (APIENTRYP *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;

/*
 * ---------------------------
 * Enums
 * ---------------------------
 */
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_NO_ERROR 0
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_LINK_STATUS 0x8B82
#define GL_INT_VEC2 0x8B53
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT4 0x8B5C
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_GREATER 0x0204
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE26 0x84DA
#define GL_LINE_LOOP 0x0002
#define GL_SRC_COLOR 0x0300
#define GL_CULL_FACE 0x0B44
#define GL_TEXTURE2 0x84C2
#define GL_HIGH_INT 0x8DF5
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_FLOAT 0x1406
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_TEXTURE11 0x84CB
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_TEXTURE9 0x84C9
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE28 0x84DC
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_RGB565 0x8D62
#define GL_DEPTH_TEST 0x0B71
#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_SHORT 0x1403
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE31 0x84DF
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_INCR_WRAP 0x8507
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_RGBA 0x1908
#define GL_SHADER_TYPE 0x8B4F
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_TEXTURE13 0x84CD
#define GL_RGB5_A1 0x8057
#define GL_TRIANGLE_FAN 0x0006
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_ALPHA_BITS 0x0D55
#define GL_SRC_ALPHA 0x0302
#define GL_STATIC_DRAW 0x88E4
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_FRONT_FACE 0x0B46
#define GL_SCISSOR_BOX 0x0C10
#define GL_VERSION 0x1F02
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_TRIANGLES 0x0004
#define GL_BLEND 0x0BE2
#define GL_REPLACE 0x1E01
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE18 0x84D2
#define GL_POINTS 0x0000
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE14 0x84CE
#define GL_NEVER 0x0200
#define GL_DITHER 0x0BD0
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_HIGH_FLOAT 0x8DF2
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_SAMPLES 0x80A9
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_LESS 0x0201
#define GL_TEXTURE0 0x84C0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_LUMINANCE 0x1909
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_RED_BITS 0x0D52
#define GL_DECR 0x1E03
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_DEPTH_FUNC 0x0B74
#define GL_OUT_OF_MEMORY 0x0505
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_TEXTURE1 0x84C1
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_FALSE 0
#define GL_KEEP 0x1E00
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_FRAMEBUFFER 0x8D40
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_TEXTURE30 0x84DE
#define GL_FLOAT_MAT3 0x8B5B
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_STENCIL_BITS 0x0D57
#define GL_SHADER_COMPILER 0x8DFA
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_VENDOR 0x1F00
#define GL_FLOAT_VEC3 0x8B51
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_MEDIUM_INT 0x8DF4
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_TEXTURE3 0x84C3
#define GL_REPEAT 0x2901
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_VIEWPORT 0x0BA2
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE23 0x84D7
#define GL_STENCIL_FAIL 0x0B94
#define GL_UNSIGNED_INT 0x1405
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_TEXTURE21 0x84D5
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_BLUE_BITS 0x0D54
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FRONT_AND_BACK 0x0408
#define GL_CW 0x0900
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_INCR 0x1E02
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_ZERO 0
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_FRONT 0x0404
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_SCISSOR_TEST 0x0C11
#define GL_CCW 0x0901
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_FUNC_SUBTRACT 0x800A
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_BUFFER_SIZE 0x8764
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE22 0x84D6
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_FLOAT_VEC2 0x8B50
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE25 0x84D9
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_SAMPLER_CUBE 0x8B60
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_RGB 0x1907
#define GL_STENCIL_INDEX8 0x8D48
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_TEXTURE24 0x84D8
#define GL_SAMPLER_2D 0x8B5E
#define GL_RENDERER 0x1F01
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_ARRAY_BUFFER 0x8892
#define GL_STENCIL_FUNC 0x0B92
#define GL_VERTEX_SHADER 0x8B31
#define GL_EQUAL 0x0202
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE17 0x84D1
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_DEPTH_BITS 0x0D56
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_TEXTURE_2D 0x0DE1
#define GL_LINEAR 0x2601
#define GL_LINE_WIDTH 0x0B21
#define GL_TEXTURE5 0x84C5
#define GL_FLOAT_VEC4 0x8B52
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_TEXTURE29 0x84DD
#define GL_NEAREST 0x2600
#define GL_LOW_FLOAT 0x8DF0
#define GL_ONE 1
#define GL_GREEN_BITS 0x0D53
#define GL_DONT_CARE 0x1100
#define GL_TEXTURE10 0x84CA
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_TEXTURE 0x1702
#define GL_FLOAT_MAT2 0x8B5A
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_INVALID_ENUM 0x0500
#define GL_STENCIL_REF 0x0B97
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_LINE_STRIP 0x0003
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_NONE 0
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_VALIDATE_STATUS 0x8B83
#define GL_LEQUAL 0x0203
#define GL_TEXTURE20 0x84D4
#define GL_CONSTANT_COLOR 0x8001
#define GL_BLEND_COLOR 0x8005
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_INT 0x1404
#define GL_BOOL 0x8B56
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_FIXED 0x140C
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_TRUE 1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_BUFFER_USAGE 0x8765
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_BOOL_VEC2 0x8B57
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_DEPTH_RANGE 0x0B70
#define GL_NICEST 0x1102
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS 0x8CD9
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_STREAM_DRAW 0x88E0
#define GL_NOTEQUAL 0x0205
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_INVERT 0x150A
#define GL_TEXTURE19 0x84D3
#define GL_DST_ALPHA 0x0304
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_TEST 0x0B90
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_DELETE_STATUS 0x8B80
#define GL_FUNC_ADD 0x8006
#define GL_INVALID_OPERATION 0x0502
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_TRIANGLE_STRIP 0x0005
#define GL_BLEND_EQUATION 0x8009
#define GL_BYTE 0x1400
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_TEXTURE27 0x84DB
#define GL_LOW_INT 0x8DF3
#define GL_BLEND_DST_RGB 0x80C8
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_BACK 0x0405
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_BOOL_VEC3 0x8B58
#define GL_SHORT 0x1402
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_CULL_FACE_MODE 0x0B45
#define GL_ALPHA 0x1906
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_EXTENSIONS 0x1F03
#define GL_FASTEST 0x1101
#define GL_TEXTURE16 0x84D0
#define GL_RGBA4 0x8056
#define GL_LINES 0x0001
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_INVALID_VALUE 0x0501
#define GL_DEPTH_COMPONENT 0x1902
#define GL_MIRRORED_REPEAT 0x8370
#define GL_COMPILE_STATUS 0x8B81
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_DST_COLOR 0x0306
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB

/*
 * ---------------------------
 * Commands
 * ---------------------------
 */

typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLOWDEF PFNGLBLENDCOLORPROC glow_glBlendColor;
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLSCISSORPROC glow_glScissor;
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat *v);
GLOWDEF PFNGLVERTEXATTRIB1FVPROC glow_glVertexAttrib1fv;
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
GLOWDEF PFNGLBLENDEQUATIONPROC glow_glBlendEquation;
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
GLOWDEF PFNGLBLENDFUNCPROC glow_glBlendFunc;
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
GLOWDEF PFNGLISBUFFERPROC glow_glIsBuffer;
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLUNIFORM3IVPROC glow_glUniform3iv;
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
GLOWDEF PFNGLDISABLEVERTEXATTRIBARRAYPROC glow_glDisableVertexAttribArray;
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
GLOWDEF PFNGLGENFRAMEBUFFERSPROC glow_glGenFramebuffers;
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
GLOWDEF PFNGLHINTPROC glow_glHint;
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
GLOWDEF PFNGLSTENCILOPPROC glow_glStencilOp;
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLOWDEF PFNGLFRAMEBUFFERRENDERBUFFERPROC glow_glFramebufferRenderbuffer;
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETVERTEXATTRIBFVPROC glow_glGetVertexAttribfv;
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLOWDEF PFNGLRENDERBUFFERSTORAGEPROC glow_glRenderbufferStorage;
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLTEXSUBIMAGE2DPROC glow_glTexSubImage2D;
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLUNIFORM1FVPROC glow_glUniform1fv;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX4FVPROC glow_glUniformMatrix4fv;
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
GLOWDEF PFNGLFRONTFACEPROC glow_glFrontFace;
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLOWDEF PFNGLGETACTIVEATTRIBPROC glow_glGetActiveAttrib;
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)();
GLOWDEF PFNGLRELEASESHADERCOMPILERPROC glow_glReleaseShaderCompiler;
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
GLOWDEF PFNGLTEXPARAMETERIPROC glow_glTexParameteri;
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
GLOWDEF PFNGLCHECKFRAMEBUFFERSTATUSPROC glow_glCheckFramebufferStatus;
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLOWDEF PFNGLGETATTACHEDSHADERSPROC glow_glGetAttachedShaders;
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
GLOWDEF PFNGLGENERATEMIPMAPPROC glow_glGenerateMipmap;
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
GLOWDEF PFNGLISFRAMEBUFFERPROC glow_glIsFramebuffer;
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint *params);
GLOWDEF PFNGLGETUNIFORMIVPROC glow_glGetUniformiv;
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void **pointer);
GLOWDEF PFNGLGETVERTEXATTRIBPOINTERVPROC glow_glGetVertexAttribPointerv;
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
GLOWDEF PFNGLUSEPROGRAMPROC glow_glUseProgram;
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
GLOWDEF PFNGLGENRENDERBUFFERSPROC glow_glGenRenderbuffers;
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean *data);
GLOWDEF PFNGLGETBOOLEANVPROC glow_glGetBooleanv;
typedef void (APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint *params);
GLOWDEF PFNGLGETSHADERIVPROC glow_glGetShaderiv;
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLOWDEF PFNGLGETSHADERSOURCEPROC glow_glGetShaderSource;
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint *params);
GLOWDEF PFNGLGETPROGRAMIVPROC glow_glGetProgramiv;
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
GLOWDEF PFNGLPIXELSTOREIPROC glow_glPixelStorei;
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLUNIFORM2IVPROC glow_glUniform2iv;
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)();
GLOWDEF PFNGLGETERRORPROC glow_glGetError;
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLOWDEF PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glow_glGetFramebufferAttachmentParameteriv;
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat *v);
GLOWDEF PFNGLVERTEXATTRIB2FVPROC glow_glVertexAttrib2fv;
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
GLOWDEF PFNGLVERTEXATTRIBPOINTERPROC glow_glVertexAttribPointer;
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
GLOWDEF PFNGLBINDTEXTUREPROC glow_glBindTexture;
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC)();
GLOWDEF PFNGLCREATEPROGRAMPROC glow_glCreateProgram;
typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
GLOWDEF PFNGLGENBUFFERSPROC glow_glGenBuffers;
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
GLOWDEF PFNGLGENTEXTURESPROC glow_glGenTextures;
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETRENDERBUFFERPARAMETERIVPROC glow_glGetRenderbufferParameteriv;
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLOWDEF PFNGLBLENDFUNCSEPARATEPROC glow_glBlendFuncSeparate;
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
GLOWDEF PFNGLCLEARSTENCILPROC glow_glClearStencil;
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint *renderbuffers);
GLOWDEF PFNGLDELETERENDERBUFFERSPROC glow_glDeleteRenderbuffers;
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
GLOWDEF PFNGLDEPTHMASKPROC glow_glDepthMask;
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLOWDEF PFNGLCLEARCOLORPROC glow_glClearColor;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETTEXPARAMETERFVPROC glow_glGetTexParameterfv;
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint *framebuffers);
GLOWDEF PFNGLDELETEFRAMEBUFFERSPROC glow_glDeleteFramebuffers;
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
GLOWDEF PFNGLSTENCILFUNCPROC glow_glStencilFunc;
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLUNIFORM4IVPROC glow_glUniform4iv;
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLVIEWPORTPROC glow_glViewport;
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
GLOWDEF PFNGLISSHADERPROC glow_glIsShader;
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLOWDEF PFNGLREADPIXELSPROC glow_glReadPixels;
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
GLOWDEF PFNGLTEXPARAMETERFPROC glow_glTexParameterf;
typedef void (APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
GLOWDEF PFNGLUNIFORM2FPROC glow_glUniform2f;
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
GLOWDEF PFNGLDEPTHRANGEFPROC glow_glDepthRangef;
typedef void (APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLOWDEF PFNGLUNIFORM3FPROC glow_glUniform3f;
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
GLOWDEF PFNGLVERTEXATTRIB2FPROC glow_glVertexAttrib2f;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETTEXPARAMETERIVPROC glow_glGetTexParameteriv;
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat *params);
GLOWDEF PFNGLGETUNIFORMFVPROC glow_glGetUniformfv;
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
GLOWDEF PFNGLLINEWIDTHPROC glow_glLineWidth;
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLTEXIMAGE2DPROC glow_glTexImage2D;
typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLOWDEF PFNGLBUFFERDATAPROC glow_glBufferData;
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLOWDEF PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glow_glCompressedTexSubImage2D;
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
GLOWDEF PFNGLDRAWARRAYSPROC glow_glDrawArrays;
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLOWDEF PFNGLFRAMEBUFFERTEXTURE2DPROC glow_glFramebufferTexture2D;
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLTEXPARAMETERFVPROC glow_glTexParameterfv;
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
GLOWDEF PFNGLVERTEXATTRIB1FPROC glow_glVertexAttrib1f;
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat *data);
GLOWDEF PFNGLGETFLOATVPROC glow_glGetFloatv;
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint *data);
GLOWDEF PFNGLGETINTEGERVPROC glow_glGetIntegerv;
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint *params);
GLOWDEF PFNGLGETVERTEXATTRIBIVPROC glow_glGetVertexAttribiv;
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat *v);
GLOWDEF PFNGLVERTEXATTRIB4FVPROC glow_glVertexAttrib4fv;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX3FVPROC glow_glUniformMatrix3fv;
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
GLOWDEF PFNGLCLEARPROC glow_glClear;
typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
GLOWDEF PFNGLDELETESHADERPROC glow_glDeleteShader;
typedef void (APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
GLOWDEF PFNGLUNIFORM1IPROC glow_glUniform1i;
typedef void (APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLOWDEF PFNGLUNIFORM4IPROC glow_glUniform4i;
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
GLOWDEF PFNGLSTENCILFUNCSEPARATEPROC glow_glStencilFuncSeparate;
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLUNIFORM4FVPROC glow_glUniform4fv;
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
GLOWDEF PFNGLCLEARDEPTHFPROC glow_glClearDepthf;
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
GLOWDEF PFNGLENABLEVERTEXATTRIBARRAYPROC glow_glEnableVertexAttribArray;
typedef void (APIENTRYP PFNGLFLUSHPROC)();
GLOWDEF PFNGLFLUSHPROC glow_glFlush;
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GLOWDEF PFNGLGETSHADERPRECISIONFORMATPROC glow_glGetShaderPrecisionFormat;
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
GLOWDEF PFNGLLINKPROGRAMPROC glow_glLinkProgram;
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLUNIFORM2FVPROC glow_glUniform2fv;
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
GLOWDEF PFNGLVALIDATEPROGRAMPROC glow_glValidateProgram;
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat *v);
GLOWDEF PFNGLVERTEXATTRIB3FVPROC glow_glVertexAttrib3fv;
typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
GLOWDEF PFNGLCULLFACEPROC glow_glCullFace;
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
GLOWDEF PFNGLDEPTHFUNCPROC glow_glDepthFunc;
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GLOWDEF PFNGLSHADERSOURCEPROC glow_glShaderSource;
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLUNIFORM1IVPROC glow_glUniform1iv;
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLOWDEF PFNGLCOMPRESSEDTEXIMAGE2DPROC glow_glCompressedTexImage2D;
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
GLOWDEF PFNGLISPROGRAMPROC glow_glIsProgram;
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
GLOWDEF PFNGLSAMPLECOVERAGEPROC glow_glSampleCoverage;
typedef void (APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
GLOWDEF PFNGLUNIFORM2IPROC glow_glUniform2i;
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
GLOWDEF PFNGLCOMPILESHADERPROC glow_glCompileShader;
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar *name);
GLOWDEF PFNGLGETATTRIBLOCATIONPROC glow_glGetAttribLocation;
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
GLOWDEF PFNGLISENABLEDPROC glow_glIsEnabled;
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
GLOWDEF PFNGLSTENCILMASKSEPARATEPROC glow_glStencilMaskSeparate;
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLOWDEF PFNGLVERTEXATTRIB3FPROC glow_glVertexAttrib3f;
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
GLOWDEF PFNGLACTIVETEXTUREPROC glow_glActiveTexture;
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLOWDEF PFNGLCOLORMASKPROC glow_glColorMask;
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
GLOWDEF PFNGLDISABLEPROC glow_glDisable;
typedef void (APIENTRYP PFNGLFINISHPROC)();
GLOWDEF PFNGLFINISHPROC glow_glFinish;
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
GLOWDEF PFNGLBINDRENDERBUFFERPROC glow_glBindRenderbuffer;
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
GLOWDEF PFNGLCREATESHADERPROC glow_glCreateShader;
typedef void (APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
GLOWDEF PFNGLDETACHSHADERPROC glow_glDetachShader;
typedef void (APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
GLOWDEF PFNGLSHADERBINARYPROC glow_glShaderBinary;
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLOWDEF PFNGLSTENCILOPSEPARATEPROC glow_glStencilOpSeparate;
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLOWDEF PFNGLTEXPARAMETERIVPROC glow_glTexParameteriv;
typedef void (APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLOWDEF PFNGLUNIFORM4FPROC glow_glUniform4f;
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar *name);
GLOWDEF PFNGLBINDATTRIBLOCATIONPROC glow_glBindAttribLocation;
typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
GLOWDEF PFNGLBINDBUFFERPROC glow_glBindBuffer;
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
GLOWDEF PFNGLDELETETEXTURESPROC glow_glDeleteTextures;
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLOWDEF PFNGLGETPROGRAMINFOLOGPROC glow_glGetProgramInfoLog;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX2FVPROC glow_glUniformMatrix2fv;
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLOWDEF PFNGLVERTEXATTRIB4FPROC glow_glVertexAttrib4f;
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
GLOWDEF PFNGLDELETEPROGRAMPROC glow_glDeleteProgram;
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETBUFFERPARAMETERIVPROC glow_glGetBufferParameteriv;
typedef void (APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
GLOWDEF PFNGLUNIFORM1FPROC glow_glUniform1f;
typedef GLubyte (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
GLOWDEF PFNGLGETSTRINGPROC glow_glGetString;
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar *name);
GLOWDEF PFNGLGETUNIFORMLOCATIONPROC glow_glGetUniformLocation;
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
GLOWDEF PFNGLISRENDERBUFFERPROC glow_glIsRenderbuffer;
typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
GLOWDEF PFNGLATTACHSHADERPROC glow_glAttachShader;
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLOWDEF PFNGLBUFFERSUBDATAPROC glow_glBufferSubData;
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLOWDEF PFNGLCOPYTEXIMAGE2DPROC glow_glCopyTexImage2D;
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
GLOWDEF PFNGLDELETEBUFFERSPROC glow_glDeleteBuffers;
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLOWDEF PFNGLGETSHADERINFOLOGPROC glow_glGetShaderInfoLog;
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
GLOWDEF PFNGLBLENDEQUATIONSEPARATEPROC glow_glBlendEquationSeparate;
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
GLOWDEF PFNGLDRAWELEMENTSPROC glow_glDrawElements;
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
GLOWDEF PFNGLENABLEPROC glow_glEnable;
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLOWDEF PFNGLGETACTIVEUNIFORMPROC glow_glGetActiveUniform;
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
GLOWDEF PFNGLSTENCILMASKPROC glow_glStencilMask;
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLUNIFORM3FVPROC glow_glUniform3fv;
typedef void (APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
GLOWDEF PFNGLUNIFORM3IPROC glow_glUniform3i;
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
GLOWDEF PFNGLBINDFRAMEBUFFERPROC glow_glBindFramebuffer;
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLCOPYTEXSUBIMAGE2DPROC glow_glCopyTexSubImage2D;
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
GLOWDEF PFNGLISTEXTUREPROC glow_glIsTexture;
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
GLOWDEF PFNGLPOLYGONOFFSETPROC glow_glPolygonOffset;


#ifndef GLOW_DEBUG

#define glBlendColor glow_glBlendColor
#define glScissor glow_glScissor
#define glVertexAttrib1fv glow_glVertexAttrib1fv
#define glBlendEquation glow_glBlendEquation
#define glBlendFunc glow_glBlendFunc
#define glIsBuffer glow_glIsBuffer
#define glUniform3iv glow_glUniform3iv
#define glDisableVertexAttribArray glow_glDisableVertexAttribArray
#define glGenFramebuffers glow_glGenFramebuffers
#define glHint glow_glHint
#define glStencilOp glow_glStencilOp
#define glFramebufferRenderbuffer glow_glFramebufferRenderbuffer
#define glGetVertexAttribfv glow_glGetVertexAttribfv
#define glRenderbufferStorage glow_glRenderbufferStorage
#define glTexSubImage2D glow_glTexSubImage2D
#define glUniform1fv glow_glUniform1fv
#define glUniformMatrix4fv glow_glUniformMatrix4fv
#define glFrontFace glow_glFrontFace
#define glGetActiveAttrib glow_glGetActiveAttrib
#define glReleaseShaderCompiler glow_glReleaseShaderCompiler
#define glTexParameteri glow_glTexParameteri
#define glCheckFramebufferStatus glow_glCheckFramebufferStatus
#define glGetAttachedShaders glow_glGetAttachedShaders
#define glGenerateMipmap glow_glGenerateMipmap
#define glIsFramebuffer glow_glIsFramebuffer
#define glGetUniformiv glow_glGetUniformiv
#define glGetVertexAttribPointerv glow_glGetVertexAttribPointerv
#define glUseProgram glow_glUseProgram
#define glGenRenderbuffers glow_glGenRenderbuffers
#define glGetBooleanv glow_glGetBooleanv
#define glGetShaderiv glow_glGetShaderiv
#define glGetShaderSource glow_glGetShaderSource
#define glGetProgramiv glow_glGetProgramiv
#define glPixelStorei glow_glPixelStorei
#define glUniform2iv glow_glUniform2iv
#define glGetError glow_glGetError
#define glGetFramebufferAttachmentParameteriv glow_glGetFramebufferAttachmentParameteriv
#define glVertexAttrib2fv glow_glVertexAttrib2fv
#define glVertexAttribPointer glow_glVertexAttribPointer
#define glBindTexture glow_glBindTexture
#define glCreateProgram glow_glCreateProgram
#define glGenBuffers glow_glGenBuffers
#define glGenTextures glow_glGenTextures
#define glGetRenderbufferParameteriv glow_glGetRenderbufferParameteriv
#define glBlendFuncSeparate glow_glBlendFuncSeparate
#define glClearStencil glow_glClearStencil
#define glDeleteRenderbuffers glow_glDeleteRenderbuffers
#define glDepthMask glow_glDepthMask
#define glClearColor glow_glClearColor
#define glGetTexParameterfv glow_glGetTexParameterfv
#define glDeleteFramebuffers glow_glDeleteFramebuffers
#define glStencilFunc glow_glStencilFunc
#define glUniform4iv glow_glUniform4iv
#define glViewport glow_glViewport
#define glIsShader glow_glIsShader
#define glReadPixels glow_glReadPixels
#define glTexParameterf glow_glTexParameterf
#define glUniform2f glow_glUniform2f
#define glDepthRangef glow_glDepthRangef
#define glUniform3f glow_glUniform3f
#define glVertexAttrib2f glow_glVertexAttrib2f
#define glGetTexParameteriv glow_glGetTexParameteriv
#define glGetUniformfv glow_glGetUniformfv
#define glLineWidth glow_glLineWidth
#define glTexImage2D glow_glTexImage2D
#define glBufferData glow_glBufferData
#define glCompressedTexSubImage2D glow_glCompressedTexSubImage2D
#define glDrawArrays glow_glDrawArrays
#define glFramebufferTexture2D glow_glFramebufferTexture2D
#define glTexParameterfv glow_glTexParameterfv
#define glVertexAttrib1f glow_glVertexAttrib1f
#define glGetFloatv glow_glGetFloatv
#define glGetIntegerv glow_glGetIntegerv
#define glGetVertexAttribiv glow_glGetVertexAttribiv
#define glVertexAttrib4fv glow_glVertexAttrib4fv
#define glUniformMatrix3fv glow_glUniformMatrix3fv
#define glClear glow_glClear
#define glDeleteShader glow_glDeleteShader
#define glUniform1i glow_glUniform1i
#define glUniform4i glow_glUniform4i
#define glStencilFuncSeparate glow_glStencilFuncSeparate
#define glUniform4fv glow_glUniform4fv
#define glClearDepthf glow_glClearDepthf
#define glEnableVertexAttribArray glow_glEnableVertexAttribArray
#define glFlush glow_glFlush
#define glGetShaderPrecisionFormat glow_glGetShaderPrecisionFormat
#define glLinkProgram glow_glLinkProgram
#define glUniform2fv glow_glUniform2fv
#define glValidateProgram glow_glValidateProgram
#define glVertexAttrib3fv glow_glVertexAttrib3fv
#define glCullFace glow_glCullFace
#define glDepthFunc glow_glDepthFunc
#define glShaderSource glow_glShaderSource
#define glUniform1iv glow_glUniform1iv
#define glCompressedTexImage2D glow_glCompressedTexImage2D
#define glIsProgram glow_glIsProgram
#define glSampleCoverage glow_glSampleCoverage
#define glUniform2i glow_glUniform2i
#define glCompileShader glow_glCompileShader
#define glGetAttribLocation glow_glGetAttribLocation
#define glIsEnabled glow_glIsEnabled
#define glStencilMaskSeparate glow_glStencilMaskSeparate
#define glVertexAttrib3f glow_glVertexAttrib3f
#define glActiveTexture glow_glActiveTexture
#define glColorMask glow_glColorMask
#define glDisable glow_glDisable
#define glFinish glow_glFinish
#define glBindRenderbuffer glow_glBindRenderbuffer
#define glCreateShader glow_glCreateShader
#define glDetachShader glow_glDetachShader
#define glShaderBinary glow_glShaderBinary
#define glStencilOpSeparate glow_glStencilOpSeparate
#define glTexParameteriv glow_glTexParameteriv
#define glUniform4f glow_glUniform4f
#define glBindAttribLocation glow_glBindAttribLocation
#define glBindBuffer glow_glBindBuffer
#define glDeleteTextures glow_glDeleteTextures
#define glGetProgramInfoLog glow_glGetProgramInfoLog
#define glUniformMatrix2fv glow_glUniformMatrix2fv
#define glVertexAttrib4f glow_glVertexAttrib4f
#define glDeleteProgram glow_glDeleteProgram
#define glGetBufferParameteriv glow_glGetBufferParameteriv
#define glUniform1f glow_glUniform1f
#define glGetString glow_glGetString
#define glGetUniformLocation glow_glGetUniformLocation
#define glIsRenderbuffer glow_glIsRenderbuffer
#define glAttachShader glow_glAttachShader
#define glBufferSubData glow_glBufferSubData
#define glCopyTexImage2D glow_glCopyTexImage2D
#define glDeleteBuffers glow_glDeleteBuffers
#define glGetShaderInfoLog glow_glGetShaderInfoLog
#define glBlendEquationSeparate glow_glBlendEquationSeparate
#define glDrawElements glow_glDrawElements
#define glEnable glow_glEnable
#define glGetActiveUniform glow_glGetActiveUniform
#define glStencilMask glow_glStencilMask
#define glUniform3fv glow_glUniform3fv
#define glUniform3i glow_glUniform3i
#define glBindFramebuffer glow_glBindFramebuffer
#define glCopyTexSubImage2D glow_glCopyTexSubImage2D
#define glIsTexture glow_glIsTexture
#define glPolygonOffset glow_glPolygonOffset

#endif /* GLOW_DEBUG */


#ifdef GLOW_DEBUG

GLOWDEF PFNGLBLENDCOLORPROC glow_debug_glBlendColor;
#define glBlendColor glow_debug_glBlendColor
GLOWDEF PFNGLSCISSORPROC glow_debug_glScissor;
#define glScissor glow_debug_glScissor
GLOWDEF PFNGLVERTEXATTRIB1FVPROC glow_debug_glVertexAttrib1fv;
#define glVertexAttrib1fv glow_debug_glVertexAttrib1fv
GLOWDEF PFNGLBLENDEQUATIONPROC glow_debug_glBlendEquation;
#define glBlendEquation glow_debug_glBlendEquation
GLOWDEF PFNGLBLENDFUNCPROC glow_debug_glBlendFunc;
#define glBlendFunc glow_debug_glBlendFunc
GLOWDEF PFNGLISBUFFERPROC glow_debug_glIsBuffer;
#define glIsBuffer glow_debug_glIsBuffer
GLOWDEF PFNGLUNIFORM3IVPROC glow_debug_glUniform3iv;
#define glUniform3iv glow_debug_glUniform3iv
GLOWDEF PFNGLDISABLEVERTEXATTRIBARRAYPROC glow_debug_glDisableVertexAttribArray;
#define glDisableVertexAttribArray glow_debug_glDisableVertexAttribArray
GLOWDEF PFNGLGENFRAMEBUFFERSPROC glow_debug_glGenFramebuffers;
#define glGenFramebuffers glow_debug_glGenFramebuffers
GLOWDEF PFNGLHINTPROC glow_debug_glHint;
#define glHint glow_debug_glHint
GLOWDEF PFNGLSTENCILOPPROC glow_debug_glStencilOp;
#define glStencilOp glow_debug_glStencilOp
GLOWDEF PFNGLFRAMEBUFFERRENDERBUFFERPROC glow_debug_glFramebufferRenderbuffer;
#define glFramebufferRenderbuffer glow_debug_glFramebufferRenderbuffer
GLOWDEF PFNGLGETVERTEXATTRIBFVPROC glow_debug_glGetVertexAttribfv;
#define glGetVertexAttribfv glow_debug_glGetVertexAttribfv
GLOWDEF PFNGLRENDERBUFFERSTORAGEPROC glow_debug_glRenderbufferStorage;
#define glRenderbufferStorage glow_debug_glRenderbufferStorage
GLOWDEF PFNGLTEXSUBIMAGE2DPROC glow_debug_glTexSubImage2D;
#define glTexSubImage2D glow_debug_glTexSubImage2D
GLOWDEF PFNGLUNIFORM1FVPROC glow_debug_glUniform1fv;
#define glUniform1fv glow_debug_glUniform1fv
GLOWDEF PFNGLUNIFORMMATRIX4FVPROC glow_debug_glUniformMatrix4fv;
#define glUniformMatrix4fv glow_debug_glUniformMatrix4fv
GLOWDEF PFNGLFRONTFACEPROC glow_debug_glFrontFace;
#define glFrontFace glow_debug_glFrontFace
GLOWDEF PFNGLGETACTIVEATTRIBPROC glow_debug_glGetActiveAttrib;
#define glGetActiveAttrib glow_debug_glGetActiveAttrib
GLOWDEF PFNGLRELEASESHADERCOMPILERPROC glow_debug_glReleaseShaderCompiler;
#define glReleaseShaderCompiler glow_debug_glReleaseShaderCompiler
GLOWDEF PFNGLTEXPARAMETERIPROC glow_debug_glTexParameteri;
#define glTexParameteri glow_debug_glTexParameteri
GLOWDEF PFNGLCHECKFRAMEBUFFERSTATUSPROC glow_debug_glCheckFramebufferStatus;
#define glCheckFramebufferStatus glow_debug_glCheckFramebufferStatus
GLOWDEF PFNGLGETATTACHEDSHADERSPROC glow_debug_glGetAttachedShaders;
#define glGetAttachedShaders glow_debug_glGetAttachedShaders
GLOWDEF PFNGLGENERATEMIPMAPPROC glow_debug_glGenerateMipmap;
#define glGenerateMipmap glow_debug_glGenerateMipmap
GLOWDEF PFNGLISFRAMEBUFFERPROC glow_debug_glIsFramebuffer;
#define glIsFramebuffer glow_debug_glIsFramebuffer
GLOWDEF PFNGLGETUNIFORMIVPROC glow_debug_glGetUniformiv;
#define glGetUniformiv glow_debug_glGetUniformiv
GLOWDEF PFNGLGETVERTEXATTRIBPOINTERVPROC glow_debug_glGetVertexAttribPointerv;
#define glGetVertexAttribPointerv glow_debug_glGetVertexAttribPointerv
GLOWDEF PFNGLUSEPROGRAMPROC glow_debug_glUseProgram;
#define glUseProgram glow_debug_glUseProgram
GLOWDEF PFNGLGENRENDERBUFFERSPROC glow_debug_glGenRenderbuffers;
#define glGenRenderbuffers glow_debug_glGenRenderbuffers
GLOWDEF PFNGLGETBOOLEANVPROC glow_debug_glGetBooleanv;
#define glGetBooleanv glow_debug_glGetBooleanv
GLOWDEF PFNGLGETSHADERIVPROC glow_debug_glGetShaderiv;
#define glGetShaderiv glow_debug_glGetShaderiv
GLOWDEF PFNGLGETSHADERSOURCEPROC glow_debug_glGetShaderSource;
#define glGetShaderSource glow_debug_glGetShaderSource
GLOWDEF PFNGLGETPROGRAMIVPROC glow_debug_glGetProgramiv;
#define glGetProgramiv glow_debug_glGetProgramiv
GLOWDEF PFNGLPIXELSTOREIPROC glow_debug_glPixelStorei;
#define glPixelStorei glow_debug_glPixelStorei
GLOWDEF PFNGLUNIFORM2IVPROC glow_debug_glUniform2iv;
#define glUniform2iv glow_debug_glUniform2iv
GLOWDEF PFNGLGETERRORPROC glow_debug_glGetError;
#define glGetError glow_debug_glGetError
GLOWDEF PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glow_debug_glGetFramebufferAttachmentParameteriv;
#define glGetFramebufferAttachmentParameteriv glow_debug_glGetFramebufferAttachmentParameteriv
GLOWDEF PFNGLVERTEXATTRIB2FVPROC glow_debug_glVertexAttrib2fv;
#define glVertexAttrib2fv glow_debug_glVertexAttrib2fv
GLOWDEF PFNGLVERTEXATTRIBPOINTERPROC glow_debug_glVertexAttribPointer;
#define glVertexAttribPointer glow_debug_glVertexAttribPointer
GLOWDEF PFNGLBINDTEXTUREPROC glow_debug_glBindTexture;
#define glBindTexture glow_debug_glBindTexture
GLOWDEF PFNGLCREATEPROGRAMPROC glow_debug_glCreateProgram;
#define glCreateProgram glow_debug_glCreateProgram
GLOWDEF PFNGLGENBUFFERSPROC glow_debug_glGenBuffers;
#define glGenBuffers glow_debug_glGenBuffers
GLOWDEF PFNGLGENTEXTURESPROC glow_debug_glGenTextures;
#define glGenTextures glow_debug_glGenTextures
GLOWDEF PFNGLGETRENDERBUFFERPARAMETERIVPROC glow_debug_glGetRenderbufferParameteriv;
#define glGetRenderbufferParameteriv glow_debug_glGetRenderbufferParameteriv
GLOWDEF PFNGLBLENDFUNCSEPARATEPROC glow_debug_glBlendFuncSeparate;
#define glBlendFuncSeparate glow_debug_glBlendFuncSeparate
GLOWDEF PFNGLCLEARSTENCILPROC glow_debug_glClearStencil;
#define glClearStencil glow_debug_glClearStencil
GLOWDEF PFNGLDELETERENDERBUFFERSPROC glow_debug_glDeleteRenderbuffers;
#define glDeleteRenderbuffers glow_debug_glDeleteRenderbuffers
GLOWDEF PFNGLDEPTHMASKPROC glow_debug_glDepthMask;
#define glDepthMask glow_debug_glDepthMask
GLOWDEF PFNGLCLEARCOLORPROC glow_debug_glClearColor;
#define glClearColor glow_debug_glClearColor
GLOWDEF PFNGLGETTEXPARAMETERFVPROC glow_debug_glGetTexParameterfv;
#define glGetTexParameterfv glow_debug_glGetTexParameterfv
GLOWDEF PFNGLDELETEFRAMEBUFFERSPROC glow_debug_glDeleteFramebuffers;
#define glDeleteFramebuffers glow_debug_glDeleteFramebuffers
GLOWDEF PFNGLSTENCILFUNCPROC glow_debug_glStencilFunc;
#define glStencilFunc glow_debug_glStencilFunc
GLOWDEF PFNGLUNIFORM4IVPROC glow_debug_glUniform4iv;
#define glUniform4iv glow_debug_glUniform4iv
GLOWDEF PFNGLVIEWPORTPROC glow_debug_glViewport;
#define glViewport glow_debug_glViewport
GLOWDEF PFNGLISSHADERPROC glow_debug_glIsShader;
#define glIsShader glow_debug_glIsShader
GLOWDEF PFNGLREADPIXELSPROC glow_debug_glReadPixels;
#define glReadPixels glow_debug_glReadPixels
GLOWDEF PFNGLTEXPARAMETERFPROC glow_debug_glTexParameterf;
#define glTexParameterf glow_debug_glTexParameterf
GLOWDEF PFNGLUNIFORM2FPROC glow_debug_glUniform2f;
#define glUniform2f glow_debug_glUniform2f
GLOWDEF PFNGLDEPTHRANGEFPROC glow_debug_glDepthRangef;
#define glDepthRangef glow_debug_glDepthRangef
GLOWDEF PFNGLUNIFORM3FPROC glow_debug_glUniform3f;
#define glUniform3f glow_debug_glUniform3f
GLOWDEF PFNGLVERTEXATTRIB2FPROC glow_debug_glVertexAttrib2f;
#define glVertexAttrib2f glow_debug_glVertexAttrib2f
GLOWDEF PFNGLGETTEXPARAMETERIVPROC glow_debug_glGetTexParameteriv;
#define glGetTexParameteriv glow_debug_glGetTexParameteriv
GLOWDEF PFNGLGETUNIFORMFVPROC glow_debug_glGetUniformfv;
#define glGetUniformfv glow_debug_glGetUniformfv
GLOWDEF PFNGLLINEWIDTHPROC glow_debug_glLineWidth;
#define glLineWidth glow_debug_glLineWidth
GLOWDEF PFNGLTEXIMAGE2DPROC glow_debug_glTexImage2D;
#define glTexImage2D glow_debug_glTexImage2D
GLOWDEF PFNGLBUFFERDATAPROC glow_debug_glBufferData;
#define glBufferData glow_debug_glBufferData
GLOWDEF PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glow_debug_glCompressedTexSubImage2D;
#define glCompressedTexSubImage2D glow_debug_glCompressedTexSubImage2D
GLOWDEF PFNGLDRAWARRAYSPROC glow_debug_glDrawArrays;
#define glDrawArrays glow_debug_glDrawArrays
GLOWDEF PFNGLFRAMEBUFFERTEXTURE2DPROC glow_debug_glFramebufferTexture2D;
#define glFramebufferTexture2D glow_debug_glFramebufferTexture2D
GLOWDEF PFNGLTEXPARAMETERFVPROC glow_debug_glTexParameterfv;
#define glTexParameterfv glow_debug_glTexParameterfv
GLOWDEF PFNGLVERTEXATTRIB1FPROC glow_debug_glVertexAttrib1f;
#define glVertexAttrib1f glow_debug_glVertexAttrib1f
GLOWDEF PFNGLGETFLOATVPROC glow_debug_glGetFloatv;
#define glGetFloatv glow_debug_glGetFloatv
GLOWDEF PFNGLGETINTEGERVPROC glow_debug_glGetIntegerv;
#define glGetIntegerv glow_debug_glGetIntegerv
GLOWDEF PFNGLGETVERTEXATTRIBIVPROC glow_debug_glGetVertexAttribiv;
#define glGetVertexAttribiv glow_debug_glGetVertexAttribiv
GLOWDEF PFNGLVERTEXATTRIB4FVPROC glow_debug_glVertexAttrib4fv;
#define glVertexAttrib4fv glow_debug_glVertexAttrib4fv
GLOWDEF PFNGLUNIFORMMATRIX3FVPROC glow_debug_glUniformMatrix3fv;
#define glUniformMatrix3fv glow_debug_glUniformMatrix3fv
GLOWDEF PFNGLCLEARPROC glow_debug_glClear;
#define glClear glow_debug_glClear
GLOWDEF PFNGLDELETESHADERPROC glow_debug_glDeleteShader;
#define glDeleteShader glow_debug_glDeleteShader
GLOWDEF PFNGLUNIFORM1IPROC glow_debug_glUniform1i;
#define glUniform1i glow_debug_glUniform1i
GLOWDEF PFNGLUNIFORM4IPROC glow_debug_glUniform4i;
#define glUniform4i glow_debug_glUniform4i
GLOWDEF PFNGLSTENCILFUNCSEPARATEPROC glow_debug_glStencilFuncSeparate;
#define glStencilFuncSeparate glow_debug_glStencilFuncSeparate
GLOWDEF PFNGLUNIFORM4FVPROC glow_debug_glUniform4fv;
#define glUniform4fv glow_debug_glUniform4fv
GLOWDEF PFNGLCLEARDEPTHFPROC glow_debug_glClearDepthf;
#define glClearDepthf glow_debug_glClearDepthf
GLOWDEF PFNGLENABLEVERTEXATTRIBARRAYPROC glow_debug_glEnableVertexAttribArray;
#define glEnableVertexAttribArray glow_debug_glEnableVertexAttribArray
GLOWDEF PFNGLFLUSHPROC glow_debug_glFlush;
#define glFlush glow_debug_glFlush
GLOWDEF PFNGLGETSHADERPRECISIONFORMATPROC glow_debug_glGetShaderPrecisionFormat;
#define glGetShaderPrecisionFormat glow_debug_glGetShaderPrecisionFormat
GLOWDEF PFNGLLINKPROGRAMPROC glow_debug_glLinkProgram;
#define glLinkProgram glow_debug_glLinkProgram
GLOWDEF PFNGLUNIFORM2FVPROC glow_debug_glUniform2fv;
#define glUniform2fv glow_debug_glUniform2fv
GLOWDEF PFNGLVALIDATEPROGRAMPROC glow_debug_glValidateProgram;
#define glValidateProgram glow_debug_glValidateProgram
GLOWDEF PFNGLVERTEXATTRIB3FVPROC glow_debug_glVertexAttrib3fv;
#define glVertexAttrib3fv glow_debug_glVertexAttrib3fv
GLOWDEF PFNGLCULLFACEPROC glow_debug_glCullFace;
#define glCullFace glow_debug_glCullFace
GLOWDEF PFNGLDEPTHFUNCPROC glow_debug_glDepthFunc;
#define glDepthFunc glow_debug_glDepthFunc
GLOWDEF PFNGLSHADERSOURCEPROC glow_debug_glShaderSource;
#define glShaderSource glow_debug_glShaderSource
GLOWDEF PFNGLUNIFORM1IVPROC glow_debug_glUniform1iv;
#define glUniform1iv glow_debug_glUniform1iv
GLOWDEF PFNGLCOMPRESSEDTEXIMAGE2DPROC glow_debug_glCompressedTexImage2D;
#define glCompressedTexImage2D glow_debug_glCompressedTexImage2D
GLOWDEF PFNGLISPROGRAMPROC glow_debug_glIsProgram;
#define glIsProgram glow_debug_glIsProgram
GLOWDEF PFNGLSAMPLECOVERAGEPROC glow_debug_glSampleCoverage;
#define glSampleCoverage glow_debug_glSampleCoverage
GLOWDEF PFNGLUNIFORM2IPROC glow_debug_glUniform2i;
#define glUniform2i glow_debug_glUniform2i
GLOWDEF PFNGLCOMPILESHADERPROC glow_debug_glCompileShader;
#define glCompileShader glow_debug_glCompileShader
GLOWDEF PFNGLGETATTRIBLOCATIONPROC glow_debug_glGetAttribLocation;
#define glGetAttribLocation glow_debug_glGetAttribLocation
GLOWDEF PFNGLISENABLEDPROC glow_debug_glIsEnabled;
#define glIsEnabled glow_debug_glIsEnabled
GLOWDEF PFNGLSTENCILMASKSEPARATEPROC glow_debug_glStencilMaskSeparate;
#define glStencilMaskSeparate glow_debug_glStencilMaskSeparate
GLOWDEF PFNGLVERTEXATTRIB3FPROC glow_debug_glVertexAttrib3f;
#define glVertexAttrib3f glow_debug_glVertexAttrib3f
GLOWDEF PFNGLACTIVETEXTUREPROC glow_debug_glActiveTexture;
#define glActiveTexture glow_debug_glActiveTexture
GLOWDEF PFNGLCOLORMASKPROC glow_debug_glColorMask;
#define glColorMask glow_debug_glColorMask
GLOWDEF PFNGLDISABLEPROC glow_debug_glDisable;
#define glDisable glow_debug_glDisable
GLOWDEF PFNGLFINISHPROC glow_debug_glFinish;
#define glFinish glow_debug_glFinish
GLOWDEF PFNGLBINDRENDERBUFFERPROC glow_debug_glBindRenderbuffer;
#define glBindRenderbuffer glow_debug_glBindRenderbuffer
GLOWDEF PFNGLCREATESHADERPROC glow_debug_glCreateShader;
#define glCreateShader glow_debug_glCreateShader
GLOWDEF PFNGLDETACHSHADERPROC glow_debug_glDetachShader;
#define glDetachShader glow_debug_glDetachShader
GLOWDEF PFNGLSHADERBINARYPROC glow_debug_glShaderBinary;
#define glShaderBinary glow_debug_glShaderBinary
GLOWDEF PFNGLSTENCILOPSEPARATEPROC glow_debug_glStencilOpSeparate;
#define glStencilOpSeparate glow_debug_glStencilOpSeparate
GLOWDEF PFNGLTEXPARAMETERIVPROC glow_debug_glTexParameteriv;
#define glTexParameteriv glow_debug_glTexParameteriv
GLOWDEF PFNGLUNIFORM4FPROC glow_debug_glUniform4f;
#define glUniform4f glow_debug_glUniform4f
GLOWDEF PFNGLBINDATTRIBLOCATIONPROC glow_debug_glBindAttribLocation;
#define glBindAttribLocation glow_debug_glBindAttribLocation
GLOWDEF PFNGLBINDBUFFERPROC glow_debug_glBindBuffer;
#define glBindBuffer glow_debug_glBindBuffer
GLOWDEF PFNGLDELETETEXTURESPROC glow_debug_glDeleteTextures;
#define glDeleteTextures glow_debug_glDeleteTextures
GLOWDEF PFNGLGETPROGRAMINFOLOGPROC glow_debug_glGetProgramInfoLog;
#define glGetProgramInfoLog glow_debug_glGetProgramInfoLog
GLOWDEF PFNGLUNIFORMMATRIX2FVPROC glow_debug_glUniformMatrix2fv;
#define glUniformMatrix2fv glow_debug_glUniformMatrix2fv
GLOWDEF PFNGLVERTEXATTRIB4FPROC glow_debug_glVertexAttrib4f;
#define glVertexAttrib4f glow_debug_glVertexAttrib4f
GLOWDEF PFNGLDELETEPROGRAMPROC glow_debug_glDeleteProgram;
#define glDeleteProgram glow_debug_glDeleteProgram
GLOWDEF PFNGLGETBUFFERPARAMETERIVPROC glow_debug_glGetBufferParameteriv;
#define glGetBufferParameteriv glow_debug_glGetBufferParameteriv
GLOWDEF PFNGLUNIFORM1FPROC glow_debug_glUniform1f;
#define glUniform1f glow_debug_glUniform1f
GLOWDEF PFNGLGETSTRINGPROC glow_debug_glGetString;
#define glGetString glow_debug_glGetString
GLOWDEF PFNGLGETUNIFORMLOCATIONPROC glow_debug_glGetUniformLocation;
#define glGetUniformLocation glow_debug_glGetUniformLocation
GLOWDEF PFNGLISRENDERBUFFERPROC glow_debug_glIsRenderbuffer;
#define glIsRenderbuffer glow_debug_glIsRenderbuffer
GLOWDEF PFNGLATTACHSHADERPROC glow_debug_glAttachShader;
#define glAttachShader glow_debug_glAttachShader
GLOWDEF PFNGLBUFFERSUBDATAPROC glow_debug_glBufferSubData;
#define glBufferSubData glow_debug_glBufferSubData
GLOWDEF PFNGLCOPYTEXIMAGE2DPROC glow_debug_glCopyTexImage2D;
#define glCopyTexImage2D glow_debug_glCopyTexImage2D
GLOWDEF PFNGLDELETEBUFFERSPROC glow_debug_glDeleteBuffers;
#define glDeleteBuffers glow_debug_glDeleteBuffers
GLOWDEF PFNGLGETSHADERINFOLOGPROC glow_debug_glGetShaderInfoLog;
#define glGetShaderInfoLog glow_debug_glGetShaderInfoLog
GLOWDEF PFNGLBLENDEQUATIONSEPARATEPROC glow_debug_glBlendEquationSeparate;
#define glBlendEquationSeparate glow_debug_glBlendEquationSeparate
GLOWDEF PFNGLDRAWELEMENTSPROC glow_debug_glDrawElements;
#define glDrawElements glow_debug_glDrawElements
GLOWDEF PFNGLENABLEPROC glow_debug_glEnable;
#define glEnable glow_debug_glEnable
GLOWDEF PFNGLGETACTIVEUNIFORMPROC glow_debug_glGetActiveUniform;
#define glGetActiveUniform glow_debug_glGetActiveUniform
GLOWDEF PFNGLSTENCILMASKPROC glow_debug_glStencilMask;
#define glStencilMask glow_debug_glStencilMask
GLOWDEF PFNGLUNIFORM3FVPROC glow_debug_glUniform3fv;
#define glUniform3fv glow_debug_glUniform3fv
GLOWDEF PFNGLUNIFORM3IPROC glow_debug_glUniform3i;
#define glUniform3i glow_debug_glUniform3i
GLOWDEF PFNGLBINDFRAMEBUFFERPROC glow_debug_glBindFramebuffer;
#define glBindFramebuffer glow_debug_glBindFramebuffer
GLOWDEF PFNGLCOPYTEXSUBIMAGE2DPROC glow_debug_glCopyTexSubImage2D;
#define glCopyTexSubImage2D glow_debug_glCopyTexSubImage2D
GLOWDEF PFNGLISTEXTUREPROC glow_debug_glIsTexture;
#define glIsTexture glow_debug_glIsTexture
GLOWDEF PFNGLPOLYGONOFFSETPROC glow_debug_glPolygonOffset;
#define glPolygonOffset glow_debug_glPolygonOffset
#endif /* GLOW_DEBUG */


#ifdef __cplusplus
}
#endif
#endif  /* GLOW_INCLUDE_GLOW_H */
/*
 * END HEADER, BEGIN IMPLEMENTATION
 */
#ifdef GLOW_IMPLEMENTATION

#include <stddef.h> /* for size_t */

#ifndef GLOW_NO_STDIO
#include <stdio.h>
#endif /* GLOW_NO_STDIO */

#ifndef GLOW_ASSERT
#include <assert.h>
#define GLOW_ASSERT(x) assert(x)
#endif /* GLOW_ASSERT */

#if defined(__APPLE__)
#include <dlfcn.h>
void *glow_get_proc(char const *name) {
  static void *lib = NULL;
  if (lib == NULL) {
    lib = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY);
  }
  GLOW_ASSERT(lib && "Can't open OpenGL shared library for function loading!");
  return lib ? dlsym(lib, name) : NULL;
}
#else
void *glow_get_proc(char const *name) {
  GLOW_ASSERT(0! && "Platform not supported. You must call glow_init_with.");
  return NULL;
}
#endif


static void glow_lazy_glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
  glow_glBlendColor = (PFNGLBLENDCOLORPROC)((ptrdiff_t)(glow_get_proc("glBlendColor")));
  if (glow_glBlendColor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendColor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendColor\n");
#endif
  }
  glow_glBlendColor(red, green, blue, alpha);
}
PFNGLBLENDCOLORPROC glow_glBlendColor = glow_lazy_glBlendColor;
static void glow_lazy_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
  glow_glScissor = (PFNGLSCISSORPROC)((ptrdiff_t)(glow_get_proc("glScissor")));
  if (glow_glScissor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glScissor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glScissor\n");
#endif
  }
  glow_glScissor(x, y, width, height);
}
PFNGLSCISSORPROC glow_glScissor = glow_lazy_glScissor;
static void glow_lazy_glVertexAttrib1fv(GLuint index, const GLfloat *v) {
  glow_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)((ptrdiff_t)(glow_get_proc("glVertexAttrib1fv")));
  if (glow_glVertexAttrib1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib1fv\n");
#endif
  }
  glow_glVertexAttrib1fv(index, v);
}
PFNGLVERTEXATTRIB1FVPROC glow_glVertexAttrib1fv = glow_lazy_glVertexAttrib1fv;
static void glow_lazy_glBlendEquation(GLenum mode) {
  glow_glBlendEquation = (PFNGLBLENDEQUATIONPROC)((ptrdiff_t)(glow_get_proc("glBlendEquation")));
  if (glow_glBlendEquation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendEquation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendEquation\n");
#endif
  }
  glow_glBlendEquation(mode);
}
PFNGLBLENDEQUATIONPROC glow_glBlendEquation = glow_lazy_glBlendEquation;
static void glow_lazy_glBlendFunc(GLenum sfactor, GLenum dfactor) {
  glow_glBlendFunc = (PFNGLBLENDFUNCPROC)((ptrdiff_t)(glow_get_proc("glBlendFunc")));
  if (glow_glBlendFunc == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendFunc\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendFunc\n");
#endif
  }
  glow_glBlendFunc(sfactor, dfactor);
}
PFNGLBLENDFUNCPROC glow_glBlendFunc = glow_lazy_glBlendFunc;
static GLboolean glow_lazy_glIsBuffer(GLuint buffer) {
  glow_glIsBuffer = (PFNGLISBUFFERPROC)((ptrdiff_t)(glow_get_proc("glIsBuffer")));
  if (glow_glIsBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsBuffer\n");
#endif
  }
  return glow_glIsBuffer(buffer);
}
PFNGLISBUFFERPROC glow_glIsBuffer = glow_lazy_glIsBuffer;
static void glow_lazy_glUniform3iv(GLint location, GLsizei count, const GLint *value) {
  glow_glUniform3iv = (PFNGLUNIFORM3IVPROC)((ptrdiff_t)(glow_get_proc("glUniform3iv")));
  if (glow_glUniform3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3iv\n");
#endif
  }
  glow_glUniform3iv(location, count, value);
}
PFNGLUNIFORM3IVPROC glow_glUniform3iv = glow_lazy_glUniform3iv;
static void glow_lazy_glDisableVertexAttribArray(GLuint index) {
  glow_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)((ptrdiff_t)(glow_get_proc("glDisableVertexAttribArray")));
  if (glow_glDisableVertexAttribArray == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisableVertexAttribArray\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisableVertexAttribArray\n");
#endif
  }
  glow_glDisableVertexAttribArray(index);
}
PFNGLDISABLEVERTEXATTRIBARRAYPROC glow_glDisableVertexAttribArray = glow_lazy_glDisableVertexAttribArray;
static void glow_lazy_glGenFramebuffers(GLsizei n, GLuint *framebuffers) {
  glow_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)((ptrdiff_t)(glow_get_proc("glGenFramebuffers")));
  if (glow_glGenFramebuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenFramebuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenFramebuffers\n");
#endif
  }
  glow_glGenFramebuffers(n, framebuffers);
}
PFNGLGENFRAMEBUFFERSPROC glow_glGenFramebuffers = glow_lazy_glGenFramebuffers;
static void glow_lazy_glHint(GLenum target, GLenum mode) {
  glow_glHint = (PFNGLHINTPROC)((ptrdiff_t)(glow_get_proc("glHint")));
  if (glow_glHint == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glHint\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glHint\n");
#endif
  }
  glow_glHint(target, mode);
}
PFNGLHINTPROC glow_glHint = glow_lazy_glHint;
static void glow_lazy_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
  glow_glStencilOp = (PFNGLSTENCILOPPROC)((ptrdiff_t)(glow_get_proc("glStencilOp")));
  if (glow_glStencilOp == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilOp\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilOp\n");
#endif
  }
  glow_glStencilOp(fail, zfail, zpass);
}
PFNGLSTENCILOPPROC glow_glStencilOp = glow_lazy_glStencilOp;
static void glow_lazy_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
  glow_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)((ptrdiff_t)(glow_get_proc("glFramebufferRenderbuffer")));
  if (glow_glFramebufferRenderbuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferRenderbuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferRenderbuffer\n");
#endif
  }
  glow_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
PFNGLFRAMEBUFFERRENDERBUFFERPROC glow_glFramebufferRenderbuffer = glow_lazy_glFramebufferRenderbuffer;
static void glow_lazy_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) {
  glow_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)((ptrdiff_t)(glow_get_proc("glGetVertexAttribfv")));
  if (glow_glGetVertexAttribfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribfv\n");
#endif
  }
  glow_glGetVertexAttribfv(index, pname, params);
}
PFNGLGETVERTEXATTRIBFVPROC glow_glGetVertexAttribfv = glow_lazy_glGetVertexAttribfv;
static void glow_lazy_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
  glow_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)((ptrdiff_t)(glow_get_proc("glRenderbufferStorage")));
  if (glow_glRenderbufferStorage == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRenderbufferStorage\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRenderbufferStorage\n");
#endif
  }
  glow_glRenderbufferStorage(target, internalformat, width, height);
}
PFNGLRENDERBUFFERSTORAGEPROC glow_glRenderbufferStorage = glow_lazy_glRenderbufferStorage;
static void glow_lazy_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {
  glow_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)((ptrdiff_t)(glow_get_proc("glTexSubImage2D")));
  if (glow_glTexSubImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexSubImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexSubImage2D\n");
#endif
  }
  glow_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLTEXSUBIMAGE2DPROC glow_glTexSubImage2D = glow_lazy_glTexSubImage2D;
static void glow_lazy_glUniform1fv(GLint location, GLsizei count, const GLfloat *value) {
  glow_glUniform1fv = (PFNGLUNIFORM1FVPROC)((ptrdiff_t)(glow_get_proc("glUniform1fv")));
  if (glow_glUniform1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1fv\n");
#endif
  }
  glow_glUniform1fv(location, count, value);
}
PFNGLUNIFORM1FVPROC glow_glUniform1fv = glow_lazy_glUniform1fv;
static void glow_lazy_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)((ptrdiff_t)(glow_get_proc("glUniformMatrix4fv")));
  if (glow_glUniformMatrix4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix4fv\n");
#endif
  }
  glow_glUniformMatrix4fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4FVPROC glow_glUniformMatrix4fv = glow_lazy_glUniformMatrix4fv;
static void glow_lazy_glFrontFace(GLenum mode) {
  glow_glFrontFace = (PFNGLFRONTFACEPROC)((ptrdiff_t)(glow_get_proc("glFrontFace")));
  if (glow_glFrontFace == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFrontFace\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFrontFace\n");
#endif
  }
  glow_glFrontFace(mode);
}
PFNGLFRONTFACEPROC glow_glFrontFace = glow_lazy_glFrontFace;
static void glow_lazy_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {
  glow_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)((ptrdiff_t)(glow_get_proc("glGetActiveAttrib")));
  if (glow_glGetActiveAttrib == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetActiveAttrib\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetActiveAttrib\n");
#endif
  }
  glow_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEATTRIBPROC glow_glGetActiveAttrib = glow_lazy_glGetActiveAttrib;
static void glow_lazy_glReleaseShaderCompiler() {
  glow_glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)((ptrdiff_t)(glow_get_proc("glReleaseShaderCompiler")));
  if (glow_glReleaseShaderCompiler == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReleaseShaderCompiler\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReleaseShaderCompiler\n");
#endif
  }
  glow_glReleaseShaderCompiler();
}
PFNGLRELEASESHADERCOMPILERPROC glow_glReleaseShaderCompiler = glow_lazy_glReleaseShaderCompiler;
static void glow_lazy_glTexParameteri(GLenum target, GLenum pname, GLint param) {
  glow_glTexParameteri = (PFNGLTEXPARAMETERIPROC)((ptrdiff_t)(glow_get_proc("glTexParameteri")));
  if (glow_glTexParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameteri\n");
#endif
  }
  glow_glTexParameteri(target, pname, param);
}
PFNGLTEXPARAMETERIPROC glow_glTexParameteri = glow_lazy_glTexParameteri;
static GLenum glow_lazy_glCheckFramebufferStatus(GLenum target) {
  glow_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)((ptrdiff_t)(glow_get_proc("glCheckFramebufferStatus")));
  if (glow_glCheckFramebufferStatus == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCheckFramebufferStatus\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCheckFramebufferStatus\n");
#endif
  }
  return glow_glCheckFramebufferStatus(target);
}
PFNGLCHECKFRAMEBUFFERSTATUSPROC glow_glCheckFramebufferStatus = glow_lazy_glCheckFramebufferStatus;
static void glow_lazy_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) {
  glow_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)((ptrdiff_t)(glow_get_proc("glGetAttachedShaders")));
  if (glow_glGetAttachedShaders == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetAttachedShaders\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetAttachedShaders\n");
#endif
  }
  glow_glGetAttachedShaders(program, maxCount, count, shaders);
}
PFNGLGETATTACHEDSHADERSPROC glow_glGetAttachedShaders = glow_lazy_glGetAttachedShaders;
static void glow_lazy_glGenerateMipmap(GLenum target) {
  glow_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)((ptrdiff_t)(glow_get_proc("glGenerateMipmap")));
  if (glow_glGenerateMipmap == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenerateMipmap\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenerateMipmap\n");
#endif
  }
  glow_glGenerateMipmap(target);
}
PFNGLGENERATEMIPMAPPROC glow_glGenerateMipmap = glow_lazy_glGenerateMipmap;
static GLboolean glow_lazy_glIsFramebuffer(GLuint framebuffer) {
  glow_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)((ptrdiff_t)(glow_get_proc("glIsFramebuffer")));
  if (glow_glIsFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsFramebuffer\n");
#endif
  }
  return glow_glIsFramebuffer(framebuffer);
}
PFNGLISFRAMEBUFFERPROC glow_glIsFramebuffer = glow_lazy_glIsFramebuffer;
static void glow_lazy_glGetUniformiv(GLuint program, GLint location, GLint *params) {
  glow_glGetUniformiv = (PFNGLGETUNIFORMIVPROC)((ptrdiff_t)(glow_get_proc("glGetUniformiv")));
  if (glow_glGetUniformiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformiv\n");
#endif
  }
  glow_glGetUniformiv(program, location, params);
}
PFNGLGETUNIFORMIVPROC glow_glGetUniformiv = glow_lazy_glGetUniformiv;
static void glow_lazy_glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer) {
  glow_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)((ptrdiff_t)(glow_get_proc("glGetVertexAttribPointerv")));
  if (glow_glGetVertexAttribPointerv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribPointerv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribPointerv\n");
#endif
  }
  glow_glGetVertexAttribPointerv(index, pname, pointer);
}
PFNGLGETVERTEXATTRIBPOINTERVPROC glow_glGetVertexAttribPointerv = glow_lazy_glGetVertexAttribPointerv;
static void glow_lazy_glUseProgram(GLuint program) {
  glow_glUseProgram = (PFNGLUSEPROGRAMPROC)((ptrdiff_t)(glow_get_proc("glUseProgram")));
  if (glow_glUseProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUseProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUseProgram\n");
#endif
  }
  glow_glUseProgram(program);
}
PFNGLUSEPROGRAMPROC glow_glUseProgram = glow_lazy_glUseProgram;
static void glow_lazy_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) {
  glow_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)((ptrdiff_t)(glow_get_proc("glGenRenderbuffers")));
  if (glow_glGenRenderbuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenRenderbuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenRenderbuffers\n");
#endif
  }
  glow_glGenRenderbuffers(n, renderbuffers);
}
PFNGLGENRENDERBUFFERSPROC glow_glGenRenderbuffers = glow_lazy_glGenRenderbuffers;
static void glow_lazy_glGetBooleanv(GLenum pname, GLboolean *data) {
  glow_glGetBooleanv = (PFNGLGETBOOLEANVPROC)((ptrdiff_t)(glow_get_proc("glGetBooleanv")));
  if (glow_glGetBooleanv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBooleanv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBooleanv\n");
#endif
  }
  glow_glGetBooleanv(pname, data);
}
PFNGLGETBOOLEANVPROC glow_glGetBooleanv = glow_lazy_glGetBooleanv;
static void glow_lazy_glGetShaderiv(GLuint shader, GLenum pname, GLint *params) {
  glow_glGetShaderiv = (PFNGLGETSHADERIVPROC)((ptrdiff_t)(glow_get_proc("glGetShaderiv")));
  if (glow_glGetShaderiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetShaderiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetShaderiv\n");
#endif
  }
  glow_glGetShaderiv(shader, pname, params);
}
PFNGLGETSHADERIVPROC glow_glGetShaderiv = glow_lazy_glGetShaderiv;
static void glow_lazy_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) {
  glow_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)((ptrdiff_t)(glow_get_proc("glGetShaderSource")));
  if (glow_glGetShaderSource == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetShaderSource\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetShaderSource\n");
#endif
  }
  glow_glGetShaderSource(shader, bufSize, length, source);
}
PFNGLGETSHADERSOURCEPROC glow_glGetShaderSource = glow_lazy_glGetShaderSource;
static void glow_lazy_glGetProgramiv(GLuint program, GLenum pname, GLint *params) {
  glow_glGetProgramiv = (PFNGLGETPROGRAMIVPROC)((ptrdiff_t)(glow_get_proc("glGetProgramiv")));
  if (glow_glGetProgramiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramiv\n");
#endif
  }
  glow_glGetProgramiv(program, pname, params);
}
PFNGLGETPROGRAMIVPROC glow_glGetProgramiv = glow_lazy_glGetProgramiv;
static void glow_lazy_glPixelStorei(GLenum pname, GLint param) {
  glow_glPixelStorei = (PFNGLPIXELSTOREIPROC)((ptrdiff_t)(glow_get_proc("glPixelStorei")));
  if (glow_glPixelStorei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelStorei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelStorei\n");
#endif
  }
  glow_glPixelStorei(pname, param);
}
PFNGLPIXELSTOREIPROC glow_glPixelStorei = glow_lazy_glPixelStorei;
static void glow_lazy_glUniform2iv(GLint location, GLsizei count, const GLint *value) {
  glow_glUniform2iv = (PFNGLUNIFORM2IVPROC)((ptrdiff_t)(glow_get_proc("glUniform2iv")));
  if (glow_glUniform2iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2iv\n");
#endif
  }
  glow_glUniform2iv(location, count, value);
}
PFNGLUNIFORM2IVPROC glow_glUniform2iv = glow_lazy_glUniform2iv;
static GLenum glow_lazy_glGetError() {
  glow_glGetError = (PFNGLGETERRORPROC)((ptrdiff_t)(glow_get_proc("glGetError")));
  if (glow_glGetError == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetError\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetError\n");
#endif
  }
  return glow_glGetError();
}
PFNGLGETERRORPROC glow_glGetError = glow_lazy_glGetError;
static void glow_lazy_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) {
  glow_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)((ptrdiff_t)(glow_get_proc("glGetFramebufferAttachmentParameteriv")));
  if (glow_glGetFramebufferAttachmentParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFramebufferAttachmentParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFramebufferAttachmentParameteriv\n");
#endif
  }
  glow_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glow_glGetFramebufferAttachmentParameteriv = glow_lazy_glGetFramebufferAttachmentParameteriv;
static void glow_lazy_glVertexAttrib2fv(GLuint index, const GLfloat *v) {
  glow_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)((ptrdiff_t)(glow_get_proc("glVertexAttrib2fv")));
  if (glow_glVertexAttrib2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib2fv\n");
#endif
  }
  glow_glVertexAttrib2fv(index, v);
}
PFNGLVERTEXATTRIB2FVPROC glow_glVertexAttrib2fv = glow_lazy_glVertexAttrib2fv;
static void glow_lazy_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
  glow_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)((ptrdiff_t)(glow_get_proc("glVertexAttribPointer")));
  if (glow_glVertexAttribPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribPointer\n");
#endif
  }
  glow_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
PFNGLVERTEXATTRIBPOINTERPROC glow_glVertexAttribPointer = glow_lazy_glVertexAttribPointer;
static void glow_lazy_glBindTexture(GLenum target, GLuint texture) {
  glow_glBindTexture = (PFNGLBINDTEXTUREPROC)((ptrdiff_t)(glow_get_proc("glBindTexture")));
  if (glow_glBindTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindTexture\n");
#endif
  }
  glow_glBindTexture(target, texture);
}
PFNGLBINDTEXTUREPROC glow_glBindTexture = glow_lazy_glBindTexture;
static GLuint glow_lazy_glCreateProgram() {
  glow_glCreateProgram = (PFNGLCREATEPROGRAMPROC)((ptrdiff_t)(glow_get_proc("glCreateProgram")));
  if (glow_glCreateProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCreateProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCreateProgram\n");
#endif
  }
  return glow_glCreateProgram();
}
PFNGLCREATEPROGRAMPROC glow_glCreateProgram = glow_lazy_glCreateProgram;
static void glow_lazy_glGenBuffers(GLsizei n, GLuint *buffers) {
  glow_glGenBuffers = (PFNGLGENBUFFERSPROC)((ptrdiff_t)(glow_get_proc("glGenBuffers")));
  if (glow_glGenBuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenBuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenBuffers\n");
#endif
  }
  glow_glGenBuffers(n, buffers);
}
PFNGLGENBUFFERSPROC glow_glGenBuffers = glow_lazy_glGenBuffers;
static void glow_lazy_glGenTextures(GLsizei n, GLuint *textures) {
  glow_glGenTextures = (PFNGLGENTEXTURESPROC)((ptrdiff_t)(glow_get_proc("glGenTextures")));
  if (glow_glGenTextures == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenTextures\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenTextures\n");
#endif
  }
  glow_glGenTextures(n, textures);
}
PFNGLGENTEXTURESPROC glow_glGenTextures = glow_lazy_glGenTextures;
static void glow_lazy_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) {
  glow_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)((ptrdiff_t)(glow_get_proc("glGetRenderbufferParameteriv")));
  if (glow_glGetRenderbufferParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetRenderbufferParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetRenderbufferParameteriv\n");
#endif
  }
  glow_glGetRenderbufferParameteriv(target, pname, params);
}
PFNGLGETRENDERBUFFERPARAMETERIVPROC glow_glGetRenderbufferParameteriv = glow_lazy_glGetRenderbufferParameteriv;
static void glow_lazy_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
  glow_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)((ptrdiff_t)(glow_get_proc("glBlendFuncSeparate")));
  if (glow_glBlendFuncSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendFuncSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendFuncSeparate\n");
#endif
  }
  glow_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
PFNGLBLENDFUNCSEPARATEPROC glow_glBlendFuncSeparate = glow_lazy_glBlendFuncSeparate;
static void glow_lazy_glClearStencil(GLint s) {
  glow_glClearStencil = (PFNGLCLEARSTENCILPROC)((ptrdiff_t)(glow_get_proc("glClearStencil")));
  if (glow_glClearStencil == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearStencil\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearStencil\n");
#endif
  }
  glow_glClearStencil(s);
}
PFNGLCLEARSTENCILPROC glow_glClearStencil = glow_lazy_glClearStencil;
static void glow_lazy_glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) {
  glow_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)((ptrdiff_t)(glow_get_proc("glDeleteRenderbuffers")));
  if (glow_glDeleteRenderbuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteRenderbuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteRenderbuffers\n");
#endif
  }
  glow_glDeleteRenderbuffers(n, renderbuffers);
}
PFNGLDELETERENDERBUFFERSPROC glow_glDeleteRenderbuffers = glow_lazy_glDeleteRenderbuffers;
static void glow_lazy_glDepthMask(GLboolean flag) {
  glow_glDepthMask = (PFNGLDEPTHMASKPROC)((ptrdiff_t)(glow_get_proc("glDepthMask")));
  if (glow_glDepthMask == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthMask\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthMask\n");
#endif
  }
  glow_glDepthMask(flag);
}
PFNGLDEPTHMASKPROC glow_glDepthMask = glow_lazy_glDepthMask;
static void glow_lazy_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
  glow_glClearColor = (PFNGLCLEARCOLORPROC)((ptrdiff_t)(glow_get_proc("glClearColor")));
  if (glow_glClearColor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearColor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearColor\n");
#endif
  }
  glow_glClearColor(red, green, blue, alpha);
}
PFNGLCLEARCOLORPROC glow_glClearColor = glow_lazy_glClearColor;
static void glow_lazy_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) {
  glow_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)((ptrdiff_t)(glow_get_proc("glGetTexParameterfv")));
  if (glow_glGetTexParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameterfv\n");
#endif
  }
  glow_glGetTexParameterfv(target, pname, params);
}
PFNGLGETTEXPARAMETERFVPROC glow_glGetTexParameterfv = glow_lazy_glGetTexParameterfv;
static void glow_lazy_glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers) {
  glow_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)((ptrdiff_t)(glow_get_proc("glDeleteFramebuffers")));
  if (glow_glDeleteFramebuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteFramebuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteFramebuffers\n");
#endif
  }
  glow_glDeleteFramebuffers(n, framebuffers);
}
PFNGLDELETEFRAMEBUFFERSPROC glow_glDeleteFramebuffers = glow_lazy_glDeleteFramebuffers;
static void glow_lazy_glStencilFunc(GLenum func, GLint ref, GLuint mask) {
  glow_glStencilFunc = (PFNGLSTENCILFUNCPROC)((ptrdiff_t)(glow_get_proc("glStencilFunc")));
  if (glow_glStencilFunc == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilFunc\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilFunc\n");
#endif
  }
  glow_glStencilFunc(func, ref, mask);
}
PFNGLSTENCILFUNCPROC glow_glStencilFunc = glow_lazy_glStencilFunc;
static void glow_lazy_glUniform4iv(GLint location, GLsizei count, const GLint *value) {
  glow_glUniform4iv = (PFNGLUNIFORM4IVPROC)((ptrdiff_t)(glow_get_proc("glUniform4iv")));
  if (glow_glUniform4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4iv\n");
#endif
  }
  glow_glUniform4iv(location, count, value);
}
PFNGLUNIFORM4IVPROC glow_glUniform4iv = glow_lazy_glUniform4iv;
static void glow_lazy_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
  glow_glViewport = (PFNGLVIEWPORTPROC)((ptrdiff_t)(glow_get_proc("glViewport")));
  if (glow_glViewport == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glViewport\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glViewport\n");
#endif
  }
  glow_glViewport(x, y, width, height);
}
PFNGLVIEWPORTPROC glow_glViewport = glow_lazy_glViewport;
static GLboolean glow_lazy_glIsShader(GLuint shader) {
  glow_glIsShader = (PFNGLISSHADERPROC)((ptrdiff_t)(glow_get_proc("glIsShader")));
  if (glow_glIsShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsShader\n");
#endif
  }
  return glow_glIsShader(shader);
}
PFNGLISSHADERPROC glow_glIsShader = glow_lazy_glIsShader;
static void glow_lazy_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) {
  glow_glReadPixels = (PFNGLREADPIXELSPROC)((ptrdiff_t)(glow_get_proc("glReadPixels")));
  if (glow_glReadPixels == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReadPixels\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReadPixels\n");
#endif
  }
  glow_glReadPixels(x, y, width, height, format, type, pixels);
}
PFNGLREADPIXELSPROC glow_glReadPixels = glow_lazy_glReadPixels;
static void glow_lazy_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
  glow_glTexParameterf = (PFNGLTEXPARAMETERFPROC)((ptrdiff_t)(glow_get_proc("glTexParameterf")));
  if (glow_glTexParameterf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterf\n");
#endif
  }
  glow_glTexParameterf(target, pname, param);
}
PFNGLTEXPARAMETERFPROC glow_glTexParameterf = glow_lazy_glTexParameterf;
static void glow_lazy_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
  glow_glUniform2f = (PFNGLUNIFORM2FPROC)((ptrdiff_t)(glow_get_proc("glUniform2f")));
  if (glow_glUniform2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2f\n");
#endif
  }
  glow_glUniform2f(location, v0, v1);
}
PFNGLUNIFORM2FPROC glow_glUniform2f = glow_lazy_glUniform2f;
static void glow_lazy_glDepthRangef(GLfloat n, GLfloat f) {
  glow_glDepthRangef = (PFNGLDEPTHRANGEFPROC)((ptrdiff_t)(glow_get_proc("glDepthRangef")));
  if (glow_glDepthRangef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthRangef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthRangef\n");
#endif
  }
  glow_glDepthRangef(n, f);
}
PFNGLDEPTHRANGEFPROC glow_glDepthRangef = glow_lazy_glDepthRangef;
static void glow_lazy_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
  glow_glUniform3f = (PFNGLUNIFORM3FPROC)((ptrdiff_t)(glow_get_proc("glUniform3f")));
  if (glow_glUniform3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3f\n");
#endif
  }
  glow_glUniform3f(location, v0, v1, v2);
}
PFNGLUNIFORM3FPROC glow_glUniform3f = glow_lazy_glUniform3f;
static void glow_lazy_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
  glow_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)((ptrdiff_t)(glow_get_proc("glVertexAttrib2f")));
  if (glow_glVertexAttrib2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib2f\n");
#endif
  }
  glow_glVertexAttrib2f(index, x, y);
}
PFNGLVERTEXATTRIB2FPROC glow_glVertexAttrib2f = glow_lazy_glVertexAttrib2f;
static void glow_lazy_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) {
  glow_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)((ptrdiff_t)(glow_get_proc("glGetTexParameteriv")));
  if (glow_glGetTexParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameteriv\n");
#endif
  }
  glow_glGetTexParameteriv(target, pname, params);
}
PFNGLGETTEXPARAMETERIVPROC glow_glGetTexParameteriv = glow_lazy_glGetTexParameteriv;
static void glow_lazy_glGetUniformfv(GLuint program, GLint location, GLfloat *params) {
  glow_glGetUniformfv = (PFNGLGETUNIFORMFVPROC)((ptrdiff_t)(glow_get_proc("glGetUniformfv")));
  if (glow_glGetUniformfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformfv\n");
#endif
  }
  glow_glGetUniformfv(program, location, params);
}
PFNGLGETUNIFORMFVPROC glow_glGetUniformfv = glow_lazy_glGetUniformfv;
static void glow_lazy_glLineWidth(GLfloat width) {
  glow_glLineWidth = (PFNGLLINEWIDTHPROC)((ptrdiff_t)(glow_get_proc("glLineWidth")));
  if (glow_glLineWidth == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLineWidth\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLineWidth\n");
#endif
  }
  glow_glLineWidth(width);
}
PFNGLLINEWIDTHPROC glow_glLineWidth = glow_lazy_glLineWidth;
static void glow_lazy_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) {
  glow_glTexImage2D = (PFNGLTEXIMAGE2DPROC)((ptrdiff_t)(glow_get_proc("glTexImage2D")));
  if (glow_glTexImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexImage2D\n");
#endif
  }
  glow_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
PFNGLTEXIMAGE2DPROC glow_glTexImage2D = glow_lazy_glTexImage2D;
static void glow_lazy_glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) {
  glow_glBufferData = (PFNGLBUFFERDATAPROC)((ptrdiff_t)(glow_get_proc("glBufferData")));
  if (glow_glBufferData == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBufferData\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBufferData\n");
#endif
  }
  glow_glBufferData(target, size, data, usage);
}
PFNGLBUFFERDATAPROC glow_glBufferData = glow_lazy_glBufferData;
static void glow_lazy_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) {
  glow_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)((ptrdiff_t)(glow_get_proc("glCompressedTexSubImage2D")));
  if (glow_glCompressedTexSubImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompressedTexSubImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompressedTexSubImage2D\n");
#endif
  }
  glow_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glow_glCompressedTexSubImage2D = glow_lazy_glCompressedTexSubImage2D;
static void glow_lazy_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
  glow_glDrawArrays = (PFNGLDRAWARRAYSPROC)((ptrdiff_t)(glow_get_proc("glDrawArrays")));
  if (glow_glDrawArrays == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawArrays\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawArrays\n");
#endif
  }
  glow_glDrawArrays(mode, first, count);
}
PFNGLDRAWARRAYSPROC glow_glDrawArrays = glow_lazy_glDrawArrays;
static void glow_lazy_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
  glow_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)((ptrdiff_t)(glow_get_proc("glFramebufferTexture2D")));
  if (glow_glFramebufferTexture2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferTexture2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferTexture2D\n");
#endif
  }
  glow_glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE2DPROC glow_glFramebufferTexture2D = glow_lazy_glFramebufferTexture2D;
static void glow_lazy_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) {
  glow_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)((ptrdiff_t)(glow_get_proc("glTexParameterfv")));
  if (glow_glTexParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterfv\n");
#endif
  }
  glow_glTexParameterfv(target, pname, params);
}
PFNGLTEXPARAMETERFVPROC glow_glTexParameterfv = glow_lazy_glTexParameterfv;
static void glow_lazy_glVertexAttrib1f(GLuint index, GLfloat x) {
  glow_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)((ptrdiff_t)(glow_get_proc("glVertexAttrib1f")));
  if (glow_glVertexAttrib1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib1f\n");
#endif
  }
  glow_glVertexAttrib1f(index, x);
}
PFNGLVERTEXATTRIB1FPROC glow_glVertexAttrib1f = glow_lazy_glVertexAttrib1f;
static void glow_lazy_glGetFloatv(GLenum pname, GLfloat *data) {
  glow_glGetFloatv = (PFNGLGETFLOATVPROC)((ptrdiff_t)(glow_get_proc("glGetFloatv")));
  if (glow_glGetFloatv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFloatv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFloatv\n");
#endif
  }
  glow_glGetFloatv(pname, data);
}
PFNGLGETFLOATVPROC glow_glGetFloatv = glow_lazy_glGetFloatv;
static void glow_lazy_glGetIntegerv(GLenum pname, GLint *data) {
  glow_glGetIntegerv = (PFNGLGETINTEGERVPROC)((ptrdiff_t)(glow_get_proc("glGetIntegerv")));
  if (glow_glGetIntegerv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetIntegerv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetIntegerv\n");
#endif
  }
  glow_glGetIntegerv(pname, data);
}
PFNGLGETINTEGERVPROC glow_glGetIntegerv = glow_lazy_glGetIntegerv;
static void glow_lazy_glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) {
  glow_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)((ptrdiff_t)(glow_get_proc("glGetVertexAttribiv")));
  if (glow_glGetVertexAttribiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribiv\n");
#endif
  }
  glow_glGetVertexAttribiv(index, pname, params);
}
PFNGLGETVERTEXATTRIBIVPROC glow_glGetVertexAttribiv = glow_lazy_glGetVertexAttribiv;
static void glow_lazy_glVertexAttrib4fv(GLuint index, const GLfloat *v) {
  glow_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)((ptrdiff_t)(glow_get_proc("glVertexAttrib4fv")));
  if (glow_glVertexAttrib4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib4fv\n");
#endif
  }
  glow_glVertexAttrib4fv(index, v);
}
PFNGLVERTEXATTRIB4FVPROC glow_glVertexAttrib4fv = glow_lazy_glVertexAttrib4fv;
static void glow_lazy_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)((ptrdiff_t)(glow_get_proc("glUniformMatrix3fv")));
  if (glow_glUniformMatrix3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix3fv\n");
#endif
  }
  glow_glUniformMatrix3fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3FVPROC glow_glUniformMatrix3fv = glow_lazy_glUniformMatrix3fv;
static void glow_lazy_glClear(GLbitfield mask) {
  glow_glClear = (PFNGLCLEARPROC)((ptrdiff_t)(glow_get_proc("glClear")));
  if (glow_glClear == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClear\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClear\n");
#endif
  }
  glow_glClear(mask);
}
PFNGLCLEARPROC glow_glClear = glow_lazy_glClear;
static void glow_lazy_glDeleteShader(GLuint shader) {
  glow_glDeleteShader = (PFNGLDELETESHADERPROC)((ptrdiff_t)(glow_get_proc("glDeleteShader")));
  if (glow_glDeleteShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteShader\n");
#endif
  }
  glow_glDeleteShader(shader);
}
PFNGLDELETESHADERPROC glow_glDeleteShader = glow_lazy_glDeleteShader;
static void glow_lazy_glUniform1i(GLint location, GLint v0) {
  glow_glUniform1i = (PFNGLUNIFORM1IPROC)((ptrdiff_t)(glow_get_proc("glUniform1i")));
  if (glow_glUniform1i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1i\n");
#endif
  }
  glow_glUniform1i(location, v0);
}
PFNGLUNIFORM1IPROC glow_glUniform1i = glow_lazy_glUniform1i;
static void glow_lazy_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
  glow_glUniform4i = (PFNGLUNIFORM4IPROC)((ptrdiff_t)(glow_get_proc("glUniform4i")));
  if (glow_glUniform4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4i\n");
#endif
  }
  glow_glUniform4i(location, v0, v1, v2, v3);
}
PFNGLUNIFORM4IPROC glow_glUniform4i = glow_lazy_glUniform4i;
static void glow_lazy_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
  glow_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)((ptrdiff_t)(glow_get_proc("glStencilFuncSeparate")));
  if (glow_glStencilFuncSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilFuncSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilFuncSeparate\n");
#endif
  }
  glow_glStencilFuncSeparate(face, func, ref, mask);
}
PFNGLSTENCILFUNCSEPARATEPROC glow_glStencilFuncSeparate = glow_lazy_glStencilFuncSeparate;
static void glow_lazy_glUniform4fv(GLint location, GLsizei count, const GLfloat *value) {
  glow_glUniform4fv = (PFNGLUNIFORM4FVPROC)((ptrdiff_t)(glow_get_proc("glUniform4fv")));
  if (glow_glUniform4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4fv\n");
#endif
  }
  glow_glUniform4fv(location, count, value);
}
PFNGLUNIFORM4FVPROC glow_glUniform4fv = glow_lazy_glUniform4fv;
static void glow_lazy_glClearDepthf(GLfloat d) {
  glow_glClearDepthf = (PFNGLCLEARDEPTHFPROC)((ptrdiff_t)(glow_get_proc("glClearDepthf")));
  if (glow_glClearDepthf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearDepthf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearDepthf\n");
#endif
  }
  glow_glClearDepthf(d);
}
PFNGLCLEARDEPTHFPROC glow_glClearDepthf = glow_lazy_glClearDepthf;
static void glow_lazy_glEnableVertexAttribArray(GLuint index) {
  glow_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)((ptrdiff_t)(glow_get_proc("glEnableVertexAttribArray")));
  if (glow_glEnableVertexAttribArray == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnableVertexAttribArray\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnableVertexAttribArray\n");
#endif
  }
  glow_glEnableVertexAttribArray(index);
}
PFNGLENABLEVERTEXATTRIBARRAYPROC glow_glEnableVertexAttribArray = glow_lazy_glEnableVertexAttribArray;
static void glow_lazy_glFlush() {
  glow_glFlush = (PFNGLFLUSHPROC)((ptrdiff_t)(glow_get_proc("glFlush")));
  if (glow_glFlush == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFlush\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFlush\n");
#endif
  }
  glow_glFlush();
}
PFNGLFLUSHPROC glow_glFlush = glow_lazy_glFlush;
static void glow_lazy_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) {
  glow_glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)((ptrdiff_t)(glow_get_proc("glGetShaderPrecisionFormat")));
  if (glow_glGetShaderPrecisionFormat == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetShaderPrecisionFormat\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetShaderPrecisionFormat\n");
#endif
  }
  glow_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
PFNGLGETSHADERPRECISIONFORMATPROC glow_glGetShaderPrecisionFormat = glow_lazy_glGetShaderPrecisionFormat;
static void glow_lazy_glLinkProgram(GLuint program) {
  glow_glLinkProgram = (PFNGLLINKPROGRAMPROC)((ptrdiff_t)(glow_get_proc("glLinkProgram")));
  if (glow_glLinkProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLinkProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLinkProgram\n");
#endif
  }
  glow_glLinkProgram(program);
}
PFNGLLINKPROGRAMPROC glow_glLinkProgram = glow_lazy_glLinkProgram;
static void glow_lazy_glUniform2fv(GLint location, GLsizei count, const GLfloat *value) {
  glow_glUniform2fv = (PFNGLUNIFORM2FVPROC)((ptrdiff_t)(glow_get_proc("glUniform2fv")));
  if (glow_glUniform2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2fv\n");
#endif
  }
  glow_glUniform2fv(location, count, value);
}
PFNGLUNIFORM2FVPROC glow_glUniform2fv = glow_lazy_glUniform2fv;
static void glow_lazy_glValidateProgram(GLuint program) {
  glow_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)((ptrdiff_t)(glow_get_proc("glValidateProgram")));
  if (glow_glValidateProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glValidateProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glValidateProgram\n");
#endif
  }
  glow_glValidateProgram(program);
}
PFNGLVALIDATEPROGRAMPROC glow_glValidateProgram = glow_lazy_glValidateProgram;
static void glow_lazy_glVertexAttrib3fv(GLuint index, const GLfloat *v) {
  glow_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)((ptrdiff_t)(glow_get_proc("glVertexAttrib3fv")));
  if (glow_glVertexAttrib3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib3fv\n");
#endif
  }
  glow_glVertexAttrib3fv(index, v);
}
PFNGLVERTEXATTRIB3FVPROC glow_glVertexAttrib3fv = glow_lazy_glVertexAttrib3fv;
static void glow_lazy_glCullFace(GLenum mode) {
  glow_glCullFace = (PFNGLCULLFACEPROC)((ptrdiff_t)(glow_get_proc("glCullFace")));
  if (glow_glCullFace == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCullFace\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCullFace\n");
#endif
  }
  glow_glCullFace(mode);
}
PFNGLCULLFACEPROC glow_glCullFace = glow_lazy_glCullFace;
static void glow_lazy_glDepthFunc(GLenum func) {
  glow_glDepthFunc = (PFNGLDEPTHFUNCPROC)((ptrdiff_t)(glow_get_proc("glDepthFunc")));
  if (glow_glDepthFunc == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthFunc\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthFunc\n");
#endif
  }
  glow_glDepthFunc(func);
}
PFNGLDEPTHFUNCPROC glow_glDepthFunc = glow_lazy_glDepthFunc;
static void glow_lazy_glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) {
  glow_glShaderSource = (PFNGLSHADERSOURCEPROC)((ptrdiff_t)(glow_get_proc("glShaderSource")));
  if (glow_glShaderSource == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glShaderSource\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glShaderSource\n");
#endif
  }
  glow_glShaderSource(shader, count, string, length);
}
PFNGLSHADERSOURCEPROC glow_glShaderSource = glow_lazy_glShaderSource;
static void glow_lazy_glUniform1iv(GLint location, GLsizei count, const GLint *value) {
  glow_glUniform1iv = (PFNGLUNIFORM1IVPROC)((ptrdiff_t)(glow_get_proc("glUniform1iv")));
  if (glow_glUniform1iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1iv\n");
#endif
  }
  glow_glUniform1iv(location, count, value);
}
PFNGLUNIFORM1IVPROC glow_glUniform1iv = glow_lazy_glUniform1iv;
static void glow_lazy_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) {
  glow_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)((ptrdiff_t)(glow_get_proc("glCompressedTexImage2D")));
  if (glow_glCompressedTexImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompressedTexImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompressedTexImage2D\n");
#endif
  }
  glow_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE2DPROC glow_glCompressedTexImage2D = glow_lazy_glCompressedTexImage2D;
static GLboolean glow_lazy_glIsProgram(GLuint program) {
  glow_glIsProgram = (PFNGLISPROGRAMPROC)((ptrdiff_t)(glow_get_proc("glIsProgram")));
  if (glow_glIsProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsProgram\n");
#endif
  }
  return glow_glIsProgram(program);
}
PFNGLISPROGRAMPROC glow_glIsProgram = glow_lazy_glIsProgram;
static void glow_lazy_glSampleCoverage(GLfloat value, GLboolean invert) {
  glow_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)((ptrdiff_t)(glow_get_proc("glSampleCoverage")));
  if (glow_glSampleCoverage == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSampleCoverage\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSampleCoverage\n");
#endif
  }
  glow_glSampleCoverage(value, invert);
}
PFNGLSAMPLECOVERAGEPROC glow_glSampleCoverage = glow_lazy_glSampleCoverage;
static void glow_lazy_glUniform2i(GLint location, GLint v0, GLint v1) {
  glow_glUniform2i = (PFNGLUNIFORM2IPROC)((ptrdiff_t)(glow_get_proc("glUniform2i")));
  if (glow_glUniform2i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2i\n");
#endif
  }
  glow_glUniform2i(location, v0, v1);
}
PFNGLUNIFORM2IPROC glow_glUniform2i = glow_lazy_glUniform2i;
static void glow_lazy_glCompileShader(GLuint shader) {
  glow_glCompileShader = (PFNGLCOMPILESHADERPROC)((ptrdiff_t)(glow_get_proc("glCompileShader")));
  if (glow_glCompileShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompileShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompileShader\n");
#endif
  }
  glow_glCompileShader(shader);
}
PFNGLCOMPILESHADERPROC glow_glCompileShader = glow_lazy_glCompileShader;
static GLint glow_lazy_glGetAttribLocation(GLuint program, const GLchar *name) {
  glow_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)((ptrdiff_t)(glow_get_proc("glGetAttribLocation")));
  if (glow_glGetAttribLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetAttribLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetAttribLocation\n");
#endif
  }
  return glow_glGetAttribLocation(program, name);
}
PFNGLGETATTRIBLOCATIONPROC glow_glGetAttribLocation = glow_lazy_glGetAttribLocation;
static GLboolean glow_lazy_glIsEnabled(GLenum cap) {
  glow_glIsEnabled = (PFNGLISENABLEDPROC)((ptrdiff_t)(glow_get_proc("glIsEnabled")));
  if (glow_glIsEnabled == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsEnabled\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsEnabled\n");
#endif
  }
  return glow_glIsEnabled(cap);
}
PFNGLISENABLEDPROC glow_glIsEnabled = glow_lazy_glIsEnabled;
static void glow_lazy_glStencilMaskSeparate(GLenum face, GLuint mask) {
  glow_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)((ptrdiff_t)(glow_get_proc("glStencilMaskSeparate")));
  if (glow_glStencilMaskSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilMaskSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilMaskSeparate\n");
#endif
  }
  glow_glStencilMaskSeparate(face, mask);
}
PFNGLSTENCILMASKSEPARATEPROC glow_glStencilMaskSeparate = glow_lazy_glStencilMaskSeparate;
static void glow_lazy_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
  glow_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)((ptrdiff_t)(glow_get_proc("glVertexAttrib3f")));
  if (glow_glVertexAttrib3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib3f\n");
#endif
  }
  glow_glVertexAttrib3f(index, x, y, z);
}
PFNGLVERTEXATTRIB3FPROC glow_glVertexAttrib3f = glow_lazy_glVertexAttrib3f;
static void glow_lazy_glActiveTexture(GLenum texture) {
  glow_glActiveTexture = (PFNGLACTIVETEXTUREPROC)((ptrdiff_t)(glow_get_proc("glActiveTexture")));
  if (glow_glActiveTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glActiveTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glActiveTexture\n");
#endif
  }
  glow_glActiveTexture(texture);
}
PFNGLACTIVETEXTUREPROC glow_glActiveTexture = glow_lazy_glActiveTexture;
static void glow_lazy_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
  glow_glColorMask = (PFNGLCOLORMASKPROC)((ptrdiff_t)(glow_get_proc("glColorMask")));
  if (glow_glColorMask == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColorMask\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColorMask\n");
#endif
  }
  glow_glColorMask(red, green, blue, alpha);
}
PFNGLCOLORMASKPROC glow_glColorMask = glow_lazy_glColorMask;
static void glow_lazy_glDisable(GLenum cap) {
  glow_glDisable = (PFNGLDISABLEPROC)((ptrdiff_t)(glow_get_proc("glDisable")));
  if (glow_glDisable == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisable\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisable\n");
#endif
  }
  glow_glDisable(cap);
}
PFNGLDISABLEPROC glow_glDisable = glow_lazy_glDisable;
static void glow_lazy_glFinish() {
  glow_glFinish = (PFNGLFINISHPROC)((ptrdiff_t)(glow_get_proc("glFinish")));
  if (glow_glFinish == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFinish\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFinish\n");
#endif
  }
  glow_glFinish();
}
PFNGLFINISHPROC glow_glFinish = glow_lazy_glFinish;
static void glow_lazy_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
  glow_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)((ptrdiff_t)(glow_get_proc("glBindRenderbuffer")));
  if (glow_glBindRenderbuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindRenderbuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindRenderbuffer\n");
#endif
  }
  glow_glBindRenderbuffer(target, renderbuffer);
}
PFNGLBINDRENDERBUFFERPROC glow_glBindRenderbuffer = glow_lazy_glBindRenderbuffer;
static GLuint glow_lazy_glCreateShader(GLenum type) {
  glow_glCreateShader = (PFNGLCREATESHADERPROC)((ptrdiff_t)(glow_get_proc("glCreateShader")));
  if (glow_glCreateShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCreateShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCreateShader\n");
#endif
  }
  return glow_glCreateShader(type);
}
PFNGLCREATESHADERPROC glow_glCreateShader = glow_lazy_glCreateShader;
static void glow_lazy_glDetachShader(GLuint program, GLuint shader) {
  glow_glDetachShader = (PFNGLDETACHSHADERPROC)((ptrdiff_t)(glow_get_proc("glDetachShader")));
  if (glow_glDetachShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDetachShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDetachShader\n");
#endif
  }
  glow_glDetachShader(program, shader);
}
PFNGLDETACHSHADERPROC glow_glDetachShader = glow_lazy_glDetachShader;
static void glow_lazy_glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) {
  glow_glShaderBinary = (PFNGLSHADERBINARYPROC)((ptrdiff_t)(glow_get_proc("glShaderBinary")));
  if (glow_glShaderBinary == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glShaderBinary\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glShaderBinary\n");
#endif
  }
  glow_glShaderBinary(count, shaders, binaryformat, binary, length);
}
PFNGLSHADERBINARYPROC glow_glShaderBinary = glow_lazy_glShaderBinary;
static void glow_lazy_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
  glow_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)((ptrdiff_t)(glow_get_proc("glStencilOpSeparate")));
  if (glow_glStencilOpSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilOpSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilOpSeparate\n");
#endif
  }
  glow_glStencilOpSeparate(face, sfail, dpfail, dppass);
}
PFNGLSTENCILOPSEPARATEPROC glow_glStencilOpSeparate = glow_lazy_glStencilOpSeparate;
static void glow_lazy_glTexParameteriv(GLenum target, GLenum pname, const GLint *params) {
  glow_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)((ptrdiff_t)(glow_get_proc("glTexParameteriv")));
  if (glow_glTexParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameteriv\n");
#endif
  }
  glow_glTexParameteriv(target, pname, params);
}
PFNGLTEXPARAMETERIVPROC glow_glTexParameteriv = glow_lazy_glTexParameteriv;
static void glow_lazy_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
  glow_glUniform4f = (PFNGLUNIFORM4FPROC)((ptrdiff_t)(glow_get_proc("glUniform4f")));
  if (glow_glUniform4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4f\n");
#endif
  }
  glow_glUniform4f(location, v0, v1, v2, v3);
}
PFNGLUNIFORM4FPROC glow_glUniform4f = glow_lazy_glUniform4f;
static void glow_lazy_glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) {
  glow_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)((ptrdiff_t)(glow_get_proc("glBindAttribLocation")));
  if (glow_glBindAttribLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindAttribLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindAttribLocation\n");
#endif
  }
  glow_glBindAttribLocation(program, index, name);
}
PFNGLBINDATTRIBLOCATIONPROC glow_glBindAttribLocation = glow_lazy_glBindAttribLocation;
static void glow_lazy_glBindBuffer(GLenum target, GLuint buffer) {
  glow_glBindBuffer = (PFNGLBINDBUFFERPROC)((ptrdiff_t)(glow_get_proc("glBindBuffer")));
  if (glow_glBindBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindBuffer\n");
#endif
  }
  glow_glBindBuffer(target, buffer);
}
PFNGLBINDBUFFERPROC glow_glBindBuffer = glow_lazy_glBindBuffer;
static void glow_lazy_glDeleteTextures(GLsizei n, const GLuint *textures) {
  glow_glDeleteTextures = (PFNGLDELETETEXTURESPROC)((ptrdiff_t)(glow_get_proc("glDeleteTextures")));
  if (glow_glDeleteTextures == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteTextures\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteTextures\n");
#endif
  }
  glow_glDeleteTextures(n, textures);
}
PFNGLDELETETEXTURESPROC glow_glDeleteTextures = glow_lazy_glDeleteTextures;
static void glow_lazy_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
  glow_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)((ptrdiff_t)(glow_get_proc("glGetProgramInfoLog")));
  if (glow_glGetProgramInfoLog == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramInfoLog\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramInfoLog\n");
#endif
  }
  glow_glGetProgramInfoLog(program, bufSize, length, infoLog);
}
PFNGLGETPROGRAMINFOLOGPROC glow_glGetProgramInfoLog = glow_lazy_glGetProgramInfoLog;
static void glow_lazy_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)((ptrdiff_t)(glow_get_proc("glUniformMatrix2fv")));
  if (glow_glUniformMatrix2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix2fv\n");
#endif
  }
  glow_glUniformMatrix2fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2FVPROC glow_glUniformMatrix2fv = glow_lazy_glUniformMatrix2fv;
static void glow_lazy_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
  glow_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)((ptrdiff_t)(glow_get_proc("glVertexAttrib4f")));
  if (glow_glVertexAttrib4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib4f\n");
#endif
  }
  glow_glVertexAttrib4f(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4FPROC glow_glVertexAttrib4f = glow_lazy_glVertexAttrib4f;
static void glow_lazy_glDeleteProgram(GLuint program) {
  glow_glDeleteProgram = (PFNGLDELETEPROGRAMPROC)((ptrdiff_t)(glow_get_proc("glDeleteProgram")));
  if (glow_glDeleteProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteProgram\n");
#endif
  }
  glow_glDeleteProgram(program);
}
PFNGLDELETEPROGRAMPROC glow_glDeleteProgram = glow_lazy_glDeleteProgram;
static void glow_lazy_glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params) {
  glow_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)((ptrdiff_t)(glow_get_proc("glGetBufferParameteriv")));
  if (glow_glGetBufferParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBufferParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBufferParameteriv\n");
#endif
  }
  glow_glGetBufferParameteriv(target, pname, params);
}
PFNGLGETBUFFERPARAMETERIVPROC glow_glGetBufferParameteriv = glow_lazy_glGetBufferParameteriv;
static void glow_lazy_glUniform1f(GLint location, GLfloat v0) {
  glow_glUniform1f = (PFNGLUNIFORM1FPROC)((ptrdiff_t)(glow_get_proc("glUniform1f")));
  if (glow_glUniform1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1f\n");
#endif
  }
  glow_glUniform1f(location, v0);
}
PFNGLUNIFORM1FPROC glow_glUniform1f = glow_lazy_glUniform1f;
static GLubyte glow_lazy_glGetString(GLenum name) {
  glow_glGetString = (PFNGLGETSTRINGPROC)((ptrdiff_t)(glow_get_proc("glGetString")));
  if (glow_glGetString == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetString\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetString\n");
#endif
  }
  return glow_glGetString(name);
}
PFNGLGETSTRINGPROC glow_glGetString = glow_lazy_glGetString;
static GLint glow_lazy_glGetUniformLocation(GLuint program, const GLchar *name) {
  glow_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)((ptrdiff_t)(glow_get_proc("glGetUniformLocation")));
  if (glow_glGetUniformLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformLocation\n");
#endif
  }
  return glow_glGetUniformLocation(program, name);
}
PFNGLGETUNIFORMLOCATIONPROC glow_glGetUniformLocation = glow_lazy_glGetUniformLocation;
static GLboolean glow_lazy_glIsRenderbuffer(GLuint renderbuffer) {
  glow_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)((ptrdiff_t)(glow_get_proc("glIsRenderbuffer")));
  if (glow_glIsRenderbuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsRenderbuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsRenderbuffer\n");
#endif
  }
  return glow_glIsRenderbuffer(renderbuffer);
}
PFNGLISRENDERBUFFERPROC glow_glIsRenderbuffer = glow_lazy_glIsRenderbuffer;
static void glow_lazy_glAttachShader(GLuint program, GLuint shader) {
  glow_glAttachShader = (PFNGLATTACHSHADERPROC)((ptrdiff_t)(glow_get_proc("glAttachShader")));
  if (glow_glAttachShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glAttachShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glAttachShader\n");
#endif
  }
  glow_glAttachShader(program, shader);
}
PFNGLATTACHSHADERPROC glow_glAttachShader = glow_lazy_glAttachShader;
static void glow_lazy_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) {
  glow_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)((ptrdiff_t)(glow_get_proc("glBufferSubData")));
  if (glow_glBufferSubData == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBufferSubData\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBufferSubData\n");
#endif
  }
  glow_glBufferSubData(target, offset, size, data);
}
PFNGLBUFFERSUBDATAPROC glow_glBufferSubData = glow_lazy_glBufferSubData;
static void glow_lazy_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
  glow_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)((ptrdiff_t)(glow_get_proc("glCopyTexImage2D")));
  if (glow_glCopyTexImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyTexImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyTexImage2D\n");
#endif
  }
  glow_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
PFNGLCOPYTEXIMAGE2DPROC glow_glCopyTexImage2D = glow_lazy_glCopyTexImage2D;
static void glow_lazy_glDeleteBuffers(GLsizei n, const GLuint *buffers) {
  glow_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)((ptrdiff_t)(glow_get_proc("glDeleteBuffers")));
  if (glow_glDeleteBuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteBuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteBuffers\n");
#endif
  }
  glow_glDeleteBuffers(n, buffers);
}
PFNGLDELETEBUFFERSPROC glow_glDeleteBuffers = glow_lazy_glDeleteBuffers;
static void glow_lazy_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
  glow_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)((ptrdiff_t)(glow_get_proc("glGetShaderInfoLog")));
  if (glow_glGetShaderInfoLog == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetShaderInfoLog\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetShaderInfoLog\n");
#endif
  }
  glow_glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
PFNGLGETSHADERINFOLOGPROC glow_glGetShaderInfoLog = glow_lazy_glGetShaderInfoLog;
static void glow_lazy_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
  glow_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)((ptrdiff_t)(glow_get_proc("glBlendEquationSeparate")));
  if (glow_glBlendEquationSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendEquationSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendEquationSeparate\n");
#endif
  }
  glow_glBlendEquationSeparate(modeRGB, modeAlpha);
}
PFNGLBLENDEQUATIONSEPARATEPROC glow_glBlendEquationSeparate = glow_lazy_glBlendEquationSeparate;
static void glow_lazy_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) {
  glow_glDrawElements = (PFNGLDRAWELEMENTSPROC)((ptrdiff_t)(glow_get_proc("glDrawElements")));
  if (glow_glDrawElements == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElements\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElements\n");
#endif
  }
  glow_glDrawElements(mode, count, type, indices);
}
PFNGLDRAWELEMENTSPROC glow_glDrawElements = glow_lazy_glDrawElements;
static void glow_lazy_glEnable(GLenum cap) {
  glow_glEnable = (PFNGLENABLEPROC)((ptrdiff_t)(glow_get_proc("glEnable")));
  if (glow_glEnable == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnable\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnable\n");
#endif
  }
  glow_glEnable(cap);
}
PFNGLENABLEPROC glow_glEnable = glow_lazy_glEnable;
static void glow_lazy_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {
  glow_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)((ptrdiff_t)(glow_get_proc("glGetActiveUniform")));
  if (glow_glGetActiveUniform == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetActiveUniform\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetActiveUniform\n");
#endif
  }
  glow_glGetActiveUniform(program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEUNIFORMPROC glow_glGetActiveUniform = glow_lazy_glGetActiveUniform;
static void glow_lazy_glStencilMask(GLuint mask) {
  glow_glStencilMask = (PFNGLSTENCILMASKPROC)((ptrdiff_t)(glow_get_proc("glStencilMask")));
  if (glow_glStencilMask == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilMask\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilMask\n");
#endif
  }
  glow_glStencilMask(mask);
}
PFNGLSTENCILMASKPROC glow_glStencilMask = glow_lazy_glStencilMask;
static void glow_lazy_glUniform3fv(GLint location, GLsizei count, const GLfloat *value) {
  glow_glUniform3fv = (PFNGLUNIFORM3FVPROC)((ptrdiff_t)(glow_get_proc("glUniform3fv")));
  if (glow_glUniform3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3fv\n");
#endif
  }
  glow_glUniform3fv(location, count, value);
}
PFNGLUNIFORM3FVPROC glow_glUniform3fv = glow_lazy_glUniform3fv;
static void glow_lazy_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
  glow_glUniform3i = (PFNGLUNIFORM3IPROC)((ptrdiff_t)(glow_get_proc("glUniform3i")));
  if (glow_glUniform3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3i\n");
#endif
  }
  glow_glUniform3i(location, v0, v1, v2);
}
PFNGLUNIFORM3IPROC glow_glUniform3i = glow_lazy_glUniform3i;
static void glow_lazy_glBindFramebuffer(GLenum target, GLuint framebuffer) {
  glow_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)((ptrdiff_t)(glow_get_proc("glBindFramebuffer")));
  if (glow_glBindFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindFramebuffer\n");
#endif
  }
  glow_glBindFramebuffer(target, framebuffer);
}
PFNGLBINDFRAMEBUFFERPROC glow_glBindFramebuffer = glow_lazy_glBindFramebuffer;
static void glow_lazy_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
  glow_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)((ptrdiff_t)(glow_get_proc("glCopyTexSubImage2D")));
  if (glow_glCopyTexSubImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyTexSubImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyTexSubImage2D\n");
#endif
  }
  glow_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE2DPROC glow_glCopyTexSubImage2D = glow_lazy_glCopyTexSubImage2D;
static GLboolean glow_lazy_glIsTexture(GLuint texture) {
  glow_glIsTexture = (PFNGLISTEXTUREPROC)((ptrdiff_t)(glow_get_proc("glIsTexture")));
  if (glow_glIsTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsTexture\n");
#endif
  }
  return glow_glIsTexture(texture);
}
PFNGLISTEXTUREPROC glow_glIsTexture = glow_lazy_glIsTexture;
static void glow_lazy_glPolygonOffset(GLfloat factor, GLfloat units) {
  glow_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)((ptrdiff_t)(glow_get_proc("glPolygonOffset")));
  if (glow_glPolygonOffset == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPolygonOffset\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPolygonOffset\n");
#endif
  }
  glow_glPolygonOffset(factor, units);
}
PFNGLPOLYGONOFFSETPROC glow_glPolygonOffset = glow_lazy_glPolygonOffset;


static void glow_pre_callback_default_(char const *name, void *funcptr, ...) {
  (void)name;
  (void)funcptr;
}
static void glow_post_callback_default_(char const *name, void *funcptr, ...) {
  (void)name;
  (void)funcptr;
}
static glow_debug_proc_t glow_pre_callback_ = glow_pre_callback_default_;
static glow_debug_proc_t glow_post_callback_ = glow_post_callback_default_;
#ifdef GLOW_DEBUG

static void glow_debug_impl_glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {

  glow_pre_callback_("glBlendColor", (void*)(ptrdiff_t)glow_glBlendColor, red, green, blue, alpha);
  glow_glBlendColor(red, green, blue, alpha);
  glow_post_callback_("glBlendColor", (void*)(ptrdiff_t)glow_glBlendColor, red, green, blue, alpha);
}
PFNGLBLENDCOLORPROC glow_debug_glBlendColor = glow_debug_impl_glBlendColor;

static void glow_debug_impl_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glScissor", (void*)(ptrdiff_t)glow_glScissor, x, y, width, height);
  glow_glScissor(x, y, width, height);
  glow_post_callback_("glScissor", (void*)(ptrdiff_t)glow_glScissor, x, y, width, height);
}
PFNGLSCISSORPROC glow_debug_glScissor = glow_debug_impl_glScissor;

static void glow_debug_impl_glVertexAttrib1fv(GLuint index, const GLfloat *v) {

  glow_pre_callback_("glVertexAttrib1fv", (void*)(ptrdiff_t)glow_glVertexAttrib1fv, index, v);
  glow_glVertexAttrib1fv(index, v);
  glow_post_callback_("glVertexAttrib1fv", (void*)(ptrdiff_t)glow_glVertexAttrib1fv, index, v);
}
PFNGLVERTEXATTRIB1FVPROC glow_debug_glVertexAttrib1fv = glow_debug_impl_glVertexAttrib1fv;

static void glow_debug_impl_glBlendEquation(GLenum mode) {

  glow_pre_callback_("glBlendEquation", (void*)(ptrdiff_t)glow_glBlendEquation, mode);
  glow_glBlendEquation(mode);
  glow_post_callback_("glBlendEquation", (void*)(ptrdiff_t)glow_glBlendEquation, mode);
}
PFNGLBLENDEQUATIONPROC glow_debug_glBlendEquation = glow_debug_impl_glBlendEquation;

static void glow_debug_impl_glBlendFunc(GLenum sfactor, GLenum dfactor) {

  glow_pre_callback_("glBlendFunc", (void*)(ptrdiff_t)glow_glBlendFunc, sfactor, dfactor);
  glow_glBlendFunc(sfactor, dfactor);
  glow_post_callback_("glBlendFunc", (void*)(ptrdiff_t)glow_glBlendFunc, sfactor, dfactor);
}
PFNGLBLENDFUNCPROC glow_debug_glBlendFunc = glow_debug_impl_glBlendFunc;

static GLboolean glow_debug_impl_glIsBuffer(GLuint buffer) {

  GLboolean ret;
  glow_pre_callback_("glIsBuffer", (void*)(ptrdiff_t)glow_glIsBuffer, buffer);
  ret = glow_glIsBuffer(buffer);
  glow_post_callback_("glIsBuffer", (void*)(ptrdiff_t)glow_glIsBuffer, buffer);
  return ret;
}
PFNGLISBUFFERPROC glow_debug_glIsBuffer = glow_debug_impl_glIsBuffer;

static void glow_debug_impl_glUniform3iv(GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glUniform3iv", (void*)(ptrdiff_t)glow_glUniform3iv, location, count, value);
  glow_glUniform3iv(location, count, value);
  glow_post_callback_("glUniform3iv", (void*)(ptrdiff_t)glow_glUniform3iv, location, count, value);
}
PFNGLUNIFORM3IVPROC glow_debug_glUniform3iv = glow_debug_impl_glUniform3iv;

static void glow_debug_impl_glDisableVertexAttribArray(GLuint index) {

  glow_pre_callback_("glDisableVertexAttribArray", (void*)(ptrdiff_t)glow_glDisableVertexAttribArray, index);
  glow_glDisableVertexAttribArray(index);
  glow_post_callback_("glDisableVertexAttribArray", (void*)(ptrdiff_t)glow_glDisableVertexAttribArray, index);
}
PFNGLDISABLEVERTEXATTRIBARRAYPROC glow_debug_glDisableVertexAttribArray = glow_debug_impl_glDisableVertexAttribArray;

static void glow_debug_impl_glGenFramebuffers(GLsizei n, GLuint *framebuffers) {

  glow_pre_callback_("glGenFramebuffers", (void*)(ptrdiff_t)glow_glGenFramebuffers, n, framebuffers);
  glow_glGenFramebuffers(n, framebuffers);
  glow_post_callback_("glGenFramebuffers", (void*)(ptrdiff_t)glow_glGenFramebuffers, n, framebuffers);
}
PFNGLGENFRAMEBUFFERSPROC glow_debug_glGenFramebuffers = glow_debug_impl_glGenFramebuffers;

static void glow_debug_impl_glHint(GLenum target, GLenum mode) {

  glow_pre_callback_("glHint", (void*)(ptrdiff_t)glow_glHint, target, mode);
  glow_glHint(target, mode);
  glow_post_callback_("glHint", (void*)(ptrdiff_t)glow_glHint, target, mode);
}
PFNGLHINTPROC glow_debug_glHint = glow_debug_impl_glHint;

static void glow_debug_impl_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {

  glow_pre_callback_("glStencilOp", (void*)(ptrdiff_t)glow_glStencilOp, fail, zfail, zpass);
  glow_glStencilOp(fail, zfail, zpass);
  glow_post_callback_("glStencilOp", (void*)(ptrdiff_t)glow_glStencilOp, fail, zfail, zpass);
}
PFNGLSTENCILOPPROC glow_debug_glStencilOp = glow_debug_impl_glStencilOp;

static void glow_debug_impl_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {

  glow_pre_callback_("glFramebufferRenderbuffer", (void*)(ptrdiff_t)glow_glFramebufferRenderbuffer, target, attachment, renderbuffertarget, renderbuffer);
  glow_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
  glow_post_callback_("glFramebufferRenderbuffer", (void*)(ptrdiff_t)glow_glFramebufferRenderbuffer, target, attachment, renderbuffertarget, renderbuffer);
}
PFNGLFRAMEBUFFERRENDERBUFFERPROC glow_debug_glFramebufferRenderbuffer = glow_debug_impl_glFramebufferRenderbuffer;

static void glow_debug_impl_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetVertexAttribfv", (void*)(ptrdiff_t)glow_glGetVertexAttribfv, index, pname, params);
  glow_glGetVertexAttribfv(index, pname, params);
  glow_post_callback_("glGetVertexAttribfv", (void*)(ptrdiff_t)glow_glGetVertexAttribfv, index, pname, params);
}
PFNGLGETVERTEXATTRIBFVPROC glow_debug_glGetVertexAttribfv = glow_debug_impl_glGetVertexAttribfv;

static void glow_debug_impl_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {

  glow_pre_callback_("glRenderbufferStorage", (void*)(ptrdiff_t)glow_glRenderbufferStorage, target, internalformat, width, height);
  glow_glRenderbufferStorage(target, internalformat, width, height);
  glow_post_callback_("glRenderbufferStorage", (void*)(ptrdiff_t)glow_glRenderbufferStorage, target, internalformat, width, height);
}
PFNGLRENDERBUFFERSTORAGEPROC glow_debug_glRenderbufferStorage = glow_debug_impl_glRenderbufferStorage;

static void glow_debug_impl_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glTexSubImage2D", (void*)(ptrdiff_t)glow_glTexSubImage2D, target, level, xoffset, yoffset, width, height, format, type, pixels);
  glow_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
  glow_post_callback_("glTexSubImage2D", (void*)(ptrdiff_t)glow_glTexSubImage2D, target, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLTEXSUBIMAGE2DPROC glow_debug_glTexSubImage2D = glow_debug_impl_glTexSubImage2D;

static void glow_debug_impl_glUniform1fv(GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glUniform1fv", (void*)(ptrdiff_t)glow_glUniform1fv, location, count, value);
  glow_glUniform1fv(location, count, value);
  glow_post_callback_("glUniform1fv", (void*)(ptrdiff_t)glow_glUniform1fv, location, count, value);
}
PFNGLUNIFORM1FVPROC glow_debug_glUniform1fv = glow_debug_impl_glUniform1fv;

static void glow_debug_impl_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix4fv", (void*)(ptrdiff_t)glow_glUniformMatrix4fv, location, count, transpose, value);
  glow_glUniformMatrix4fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix4fv", (void*)(ptrdiff_t)glow_glUniformMatrix4fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4FVPROC glow_debug_glUniformMatrix4fv = glow_debug_impl_glUniformMatrix4fv;

static void glow_debug_impl_glFrontFace(GLenum mode) {

  glow_pre_callback_("glFrontFace", (void*)(ptrdiff_t)glow_glFrontFace, mode);
  glow_glFrontFace(mode);
  glow_post_callback_("glFrontFace", (void*)(ptrdiff_t)glow_glFrontFace, mode);
}
PFNGLFRONTFACEPROC glow_debug_glFrontFace = glow_debug_impl_glFrontFace;

static void glow_debug_impl_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {

  glow_pre_callback_("glGetActiveAttrib", (void*)(ptrdiff_t)glow_glGetActiveAttrib, program, index, bufSize, length, size, type, name);
  glow_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
  glow_post_callback_("glGetActiveAttrib", (void*)(ptrdiff_t)glow_glGetActiveAttrib, program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEATTRIBPROC glow_debug_glGetActiveAttrib = glow_debug_impl_glGetActiveAttrib;

static void glow_debug_impl_glReleaseShaderCompiler() {

  glow_pre_callback_("glReleaseShaderCompiler", (void*)(ptrdiff_t)glow_glReleaseShaderCompiler);
  glow_glReleaseShaderCompiler();
  glow_post_callback_("glReleaseShaderCompiler", (void*)(ptrdiff_t)glow_glReleaseShaderCompiler);
}
PFNGLRELEASESHADERCOMPILERPROC glow_debug_glReleaseShaderCompiler = glow_debug_impl_glReleaseShaderCompiler;

static void glow_debug_impl_glTexParameteri(GLenum target, GLenum pname, GLint param) {

  glow_pre_callback_("glTexParameteri", (void*)(ptrdiff_t)glow_glTexParameteri, target, pname, param);
  glow_glTexParameteri(target, pname, param);
  glow_post_callback_("glTexParameteri", (void*)(ptrdiff_t)glow_glTexParameteri, target, pname, param);
}
PFNGLTEXPARAMETERIPROC glow_debug_glTexParameteri = glow_debug_impl_glTexParameteri;

static GLenum glow_debug_impl_glCheckFramebufferStatus(GLenum target) {

  GLenum ret;
  glow_pre_callback_("glCheckFramebufferStatus", (void*)(ptrdiff_t)glow_glCheckFramebufferStatus, target);
  ret = glow_glCheckFramebufferStatus(target);
  glow_post_callback_("glCheckFramebufferStatus", (void*)(ptrdiff_t)glow_glCheckFramebufferStatus, target);
  return ret;
}
PFNGLCHECKFRAMEBUFFERSTATUSPROC glow_debug_glCheckFramebufferStatus = glow_debug_impl_glCheckFramebufferStatus;

static void glow_debug_impl_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) {

  glow_pre_callback_("glGetAttachedShaders", (void*)(ptrdiff_t)glow_glGetAttachedShaders, program, maxCount, count, shaders);
  glow_glGetAttachedShaders(program, maxCount, count, shaders);
  glow_post_callback_("glGetAttachedShaders", (void*)(ptrdiff_t)glow_glGetAttachedShaders, program, maxCount, count, shaders);
}
PFNGLGETATTACHEDSHADERSPROC glow_debug_glGetAttachedShaders = glow_debug_impl_glGetAttachedShaders;

static void glow_debug_impl_glGenerateMipmap(GLenum target) {

  glow_pre_callback_("glGenerateMipmap", (void*)(ptrdiff_t)glow_glGenerateMipmap, target);
  glow_glGenerateMipmap(target);
  glow_post_callback_("glGenerateMipmap", (void*)(ptrdiff_t)glow_glGenerateMipmap, target);
}
PFNGLGENERATEMIPMAPPROC glow_debug_glGenerateMipmap = glow_debug_impl_glGenerateMipmap;

static GLboolean glow_debug_impl_glIsFramebuffer(GLuint framebuffer) {

  GLboolean ret;
  glow_pre_callback_("glIsFramebuffer", (void*)(ptrdiff_t)glow_glIsFramebuffer, framebuffer);
  ret = glow_glIsFramebuffer(framebuffer);
  glow_post_callback_("glIsFramebuffer", (void*)(ptrdiff_t)glow_glIsFramebuffer, framebuffer);
  return ret;
}
PFNGLISFRAMEBUFFERPROC glow_debug_glIsFramebuffer = glow_debug_impl_glIsFramebuffer;

static void glow_debug_impl_glGetUniformiv(GLuint program, GLint location, GLint *params) {

  glow_pre_callback_("glGetUniformiv", (void*)(ptrdiff_t)glow_glGetUniformiv, program, location, params);
  glow_glGetUniformiv(program, location, params);
  glow_post_callback_("glGetUniformiv", (void*)(ptrdiff_t)glow_glGetUniformiv, program, location, params);
}
PFNGLGETUNIFORMIVPROC glow_debug_glGetUniformiv = glow_debug_impl_glGetUniformiv;

static void glow_debug_impl_glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer) {

  glow_pre_callback_("glGetVertexAttribPointerv", (void*)(ptrdiff_t)glow_glGetVertexAttribPointerv, index, pname, pointer);
  glow_glGetVertexAttribPointerv(index, pname, pointer);
  glow_post_callback_("glGetVertexAttribPointerv", (void*)(ptrdiff_t)glow_glGetVertexAttribPointerv, index, pname, pointer);
}
PFNGLGETVERTEXATTRIBPOINTERVPROC glow_debug_glGetVertexAttribPointerv = glow_debug_impl_glGetVertexAttribPointerv;

static void glow_debug_impl_glUseProgram(GLuint program) {

  glow_pre_callback_("glUseProgram", (void*)(ptrdiff_t)glow_glUseProgram, program);
  glow_glUseProgram(program);
  glow_post_callback_("glUseProgram", (void*)(ptrdiff_t)glow_glUseProgram, program);
}
PFNGLUSEPROGRAMPROC glow_debug_glUseProgram = glow_debug_impl_glUseProgram;

static void glow_debug_impl_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) {

  glow_pre_callback_("glGenRenderbuffers", (void*)(ptrdiff_t)glow_glGenRenderbuffers, n, renderbuffers);
  glow_glGenRenderbuffers(n, renderbuffers);
  glow_post_callback_("glGenRenderbuffers", (void*)(ptrdiff_t)glow_glGenRenderbuffers, n, renderbuffers);
}
PFNGLGENRENDERBUFFERSPROC glow_debug_glGenRenderbuffers = glow_debug_impl_glGenRenderbuffers;

static void glow_debug_impl_glGetBooleanv(GLenum pname, GLboolean *data) {

  glow_pre_callback_("glGetBooleanv", (void*)(ptrdiff_t)glow_glGetBooleanv, pname, data);
  glow_glGetBooleanv(pname, data);
  glow_post_callback_("glGetBooleanv", (void*)(ptrdiff_t)glow_glGetBooleanv, pname, data);
}
PFNGLGETBOOLEANVPROC glow_debug_glGetBooleanv = glow_debug_impl_glGetBooleanv;

static void glow_debug_impl_glGetShaderiv(GLuint shader, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetShaderiv", (void*)(ptrdiff_t)glow_glGetShaderiv, shader, pname, params);
  glow_glGetShaderiv(shader, pname, params);
  glow_post_callback_("glGetShaderiv", (void*)(ptrdiff_t)glow_glGetShaderiv, shader, pname, params);
}
PFNGLGETSHADERIVPROC glow_debug_glGetShaderiv = glow_debug_impl_glGetShaderiv;

static void glow_debug_impl_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) {

  glow_pre_callback_("glGetShaderSource", (void*)(ptrdiff_t)glow_glGetShaderSource, shader, bufSize, length, source);
  glow_glGetShaderSource(shader, bufSize, length, source);
  glow_post_callback_("glGetShaderSource", (void*)(ptrdiff_t)glow_glGetShaderSource, shader, bufSize, length, source);
}
PFNGLGETSHADERSOURCEPROC glow_debug_glGetShaderSource = glow_debug_impl_glGetShaderSource;

static void glow_debug_impl_glGetProgramiv(GLuint program, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetProgramiv", (void*)(ptrdiff_t)glow_glGetProgramiv, program, pname, params);
  glow_glGetProgramiv(program, pname, params);
  glow_post_callback_("glGetProgramiv", (void*)(ptrdiff_t)glow_glGetProgramiv, program, pname, params);
}
PFNGLGETPROGRAMIVPROC glow_debug_glGetProgramiv = glow_debug_impl_glGetProgramiv;

static void glow_debug_impl_glPixelStorei(GLenum pname, GLint param) {

  glow_pre_callback_("glPixelStorei", (void*)(ptrdiff_t)glow_glPixelStorei, pname, param);
  glow_glPixelStorei(pname, param);
  glow_post_callback_("glPixelStorei", (void*)(ptrdiff_t)glow_glPixelStorei, pname, param);
}
PFNGLPIXELSTOREIPROC glow_debug_glPixelStorei = glow_debug_impl_glPixelStorei;

static void glow_debug_impl_glUniform2iv(GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glUniform2iv", (void*)(ptrdiff_t)glow_glUniform2iv, location, count, value);
  glow_glUniform2iv(location, count, value);
  glow_post_callback_("glUniform2iv", (void*)(ptrdiff_t)glow_glUniform2iv, location, count, value);
}
PFNGLUNIFORM2IVPROC glow_debug_glUniform2iv = glow_debug_impl_glUniform2iv;

static GLenum glow_debug_impl_glGetError() {

  GLenum ret;
  glow_pre_callback_("glGetError", (void*)(ptrdiff_t)glow_glGetError);
  ret = glow_glGetError();
  glow_post_callback_("glGetError", (void*)(ptrdiff_t)glow_glGetError);
  return ret;
}
PFNGLGETERRORPROC glow_debug_glGetError = glow_debug_impl_glGetError;

static void glow_debug_impl_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetFramebufferAttachmentParameteriv", (void*)(ptrdiff_t)glow_glGetFramebufferAttachmentParameteriv, target, attachment, pname, params);
  glow_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
  glow_post_callback_("glGetFramebufferAttachmentParameteriv", (void*)(ptrdiff_t)glow_glGetFramebufferAttachmentParameteriv, target, attachment, pname, params);
}
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glow_debug_glGetFramebufferAttachmentParameteriv = glow_debug_impl_glGetFramebufferAttachmentParameteriv;

static void glow_debug_impl_glVertexAttrib2fv(GLuint index, const GLfloat *v) {

  glow_pre_callback_("glVertexAttrib2fv", (void*)(ptrdiff_t)glow_glVertexAttrib2fv, index, v);
  glow_glVertexAttrib2fv(index, v);
  glow_post_callback_("glVertexAttrib2fv", (void*)(ptrdiff_t)glow_glVertexAttrib2fv, index, v);
}
PFNGLVERTEXATTRIB2FVPROC glow_debug_glVertexAttrib2fv = glow_debug_impl_glVertexAttrib2fv;

static void glow_debug_impl_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {

  glow_pre_callback_("glVertexAttribPointer", (void*)(ptrdiff_t)glow_glVertexAttribPointer, index, size, type, normalized, stride, pointer);
  glow_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
  glow_post_callback_("glVertexAttribPointer", (void*)(ptrdiff_t)glow_glVertexAttribPointer, index, size, type, normalized, stride, pointer);
}
PFNGLVERTEXATTRIBPOINTERPROC glow_debug_glVertexAttribPointer = glow_debug_impl_glVertexAttribPointer;

static void glow_debug_impl_glBindTexture(GLenum target, GLuint texture) {

  glow_pre_callback_("glBindTexture", (void*)(ptrdiff_t)glow_glBindTexture, target, texture);
  glow_glBindTexture(target, texture);
  glow_post_callback_("glBindTexture", (void*)(ptrdiff_t)glow_glBindTexture, target, texture);
}
PFNGLBINDTEXTUREPROC glow_debug_glBindTexture = glow_debug_impl_glBindTexture;

static GLuint glow_debug_impl_glCreateProgram() {

  GLuint ret;
  glow_pre_callback_("glCreateProgram", (void*)(ptrdiff_t)glow_glCreateProgram);
  ret = glow_glCreateProgram();
  glow_post_callback_("glCreateProgram", (void*)(ptrdiff_t)glow_glCreateProgram);
  return ret;
}
PFNGLCREATEPROGRAMPROC glow_debug_glCreateProgram = glow_debug_impl_glCreateProgram;

static void glow_debug_impl_glGenBuffers(GLsizei n, GLuint *buffers) {

  glow_pre_callback_("glGenBuffers", (void*)(ptrdiff_t)glow_glGenBuffers, n, buffers);
  glow_glGenBuffers(n, buffers);
  glow_post_callback_("glGenBuffers", (void*)(ptrdiff_t)glow_glGenBuffers, n, buffers);
}
PFNGLGENBUFFERSPROC glow_debug_glGenBuffers = glow_debug_impl_glGenBuffers;

static void glow_debug_impl_glGenTextures(GLsizei n, GLuint *textures) {

  glow_pre_callback_("glGenTextures", (void*)(ptrdiff_t)glow_glGenTextures, n, textures);
  glow_glGenTextures(n, textures);
  glow_post_callback_("glGenTextures", (void*)(ptrdiff_t)glow_glGenTextures, n, textures);
}
PFNGLGENTEXTURESPROC glow_debug_glGenTextures = glow_debug_impl_glGenTextures;

static void glow_debug_impl_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetRenderbufferParameteriv", (void*)(ptrdiff_t)glow_glGetRenderbufferParameteriv, target, pname, params);
  glow_glGetRenderbufferParameteriv(target, pname, params);
  glow_post_callback_("glGetRenderbufferParameteriv", (void*)(ptrdiff_t)glow_glGetRenderbufferParameteriv, target, pname, params);
}
PFNGLGETRENDERBUFFERPARAMETERIVPROC glow_debug_glGetRenderbufferParameteriv = glow_debug_impl_glGetRenderbufferParameteriv;

static void glow_debug_impl_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {

  glow_pre_callback_("glBlendFuncSeparate", (void*)(ptrdiff_t)glow_glBlendFuncSeparate, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
  glow_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
  glow_post_callback_("glBlendFuncSeparate", (void*)(ptrdiff_t)glow_glBlendFuncSeparate, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
PFNGLBLENDFUNCSEPARATEPROC glow_debug_glBlendFuncSeparate = glow_debug_impl_glBlendFuncSeparate;

static void glow_debug_impl_glClearStencil(GLint s) {

  glow_pre_callback_("glClearStencil", (void*)(ptrdiff_t)glow_glClearStencil, s);
  glow_glClearStencil(s);
  glow_post_callback_("glClearStencil", (void*)(ptrdiff_t)glow_glClearStencil, s);
}
PFNGLCLEARSTENCILPROC glow_debug_glClearStencil = glow_debug_impl_glClearStencil;

static void glow_debug_impl_glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) {

  glow_pre_callback_("glDeleteRenderbuffers", (void*)(ptrdiff_t)glow_glDeleteRenderbuffers, n, renderbuffers);
  glow_glDeleteRenderbuffers(n, renderbuffers);
  glow_post_callback_("glDeleteRenderbuffers", (void*)(ptrdiff_t)glow_glDeleteRenderbuffers, n, renderbuffers);
}
PFNGLDELETERENDERBUFFERSPROC glow_debug_glDeleteRenderbuffers = glow_debug_impl_glDeleteRenderbuffers;

static void glow_debug_impl_glDepthMask(GLboolean flag) {

  glow_pre_callback_("glDepthMask", (void*)(ptrdiff_t)glow_glDepthMask, flag);
  glow_glDepthMask(flag);
  glow_post_callback_("glDepthMask", (void*)(ptrdiff_t)glow_glDepthMask, flag);
}
PFNGLDEPTHMASKPROC glow_debug_glDepthMask = glow_debug_impl_glDepthMask;

static void glow_debug_impl_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {

  glow_pre_callback_("glClearColor", (void*)(ptrdiff_t)glow_glClearColor, red, green, blue, alpha);
  glow_glClearColor(red, green, blue, alpha);
  glow_post_callback_("glClearColor", (void*)(ptrdiff_t)glow_glClearColor, red, green, blue, alpha);
}
PFNGLCLEARCOLORPROC glow_debug_glClearColor = glow_debug_impl_glClearColor;

static void glow_debug_impl_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetTexParameterfv", (void*)(ptrdiff_t)glow_glGetTexParameterfv, target, pname, params);
  glow_glGetTexParameterfv(target, pname, params);
  glow_post_callback_("glGetTexParameterfv", (void*)(ptrdiff_t)glow_glGetTexParameterfv, target, pname, params);
}
PFNGLGETTEXPARAMETERFVPROC glow_debug_glGetTexParameterfv = glow_debug_impl_glGetTexParameterfv;

static void glow_debug_impl_glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers) {

  glow_pre_callback_("glDeleteFramebuffers", (void*)(ptrdiff_t)glow_glDeleteFramebuffers, n, framebuffers);
  glow_glDeleteFramebuffers(n, framebuffers);
  glow_post_callback_("glDeleteFramebuffers", (void*)(ptrdiff_t)glow_glDeleteFramebuffers, n, framebuffers);
}
PFNGLDELETEFRAMEBUFFERSPROC glow_debug_glDeleteFramebuffers = glow_debug_impl_glDeleteFramebuffers;

static void glow_debug_impl_glStencilFunc(GLenum func, GLint ref, GLuint mask) {

  glow_pre_callback_("glStencilFunc", (void*)(ptrdiff_t)glow_glStencilFunc, func, ref, mask);
  glow_glStencilFunc(func, ref, mask);
  glow_post_callback_("glStencilFunc", (void*)(ptrdiff_t)glow_glStencilFunc, func, ref, mask);
}
PFNGLSTENCILFUNCPROC glow_debug_glStencilFunc = glow_debug_impl_glStencilFunc;

static void glow_debug_impl_glUniform4iv(GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glUniform4iv", (void*)(ptrdiff_t)glow_glUniform4iv, location, count, value);
  glow_glUniform4iv(location, count, value);
  glow_post_callback_("glUniform4iv", (void*)(ptrdiff_t)glow_glUniform4iv, location, count, value);
}
PFNGLUNIFORM4IVPROC glow_debug_glUniform4iv = glow_debug_impl_glUniform4iv;

static void glow_debug_impl_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glViewport", (void*)(ptrdiff_t)glow_glViewport, x, y, width, height);
  glow_glViewport(x, y, width, height);
  glow_post_callback_("glViewport", (void*)(ptrdiff_t)glow_glViewport, x, y, width, height);
}
PFNGLVIEWPORTPROC glow_debug_glViewport = glow_debug_impl_glViewport;

static GLboolean glow_debug_impl_glIsShader(GLuint shader) {

  GLboolean ret;
  glow_pre_callback_("glIsShader", (void*)(ptrdiff_t)glow_glIsShader, shader);
  ret = glow_glIsShader(shader);
  glow_post_callback_("glIsShader", (void*)(ptrdiff_t)glow_glIsShader, shader);
  return ret;
}
PFNGLISSHADERPROC glow_debug_glIsShader = glow_debug_impl_glIsShader;

static void glow_debug_impl_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) {

  glow_pre_callback_("glReadPixels", (void*)(ptrdiff_t)glow_glReadPixels, x, y, width, height, format, type, pixels);
  glow_glReadPixels(x, y, width, height, format, type, pixels);
  glow_post_callback_("glReadPixels", (void*)(ptrdiff_t)glow_glReadPixels, x, y, width, height, format, type, pixels);
}
PFNGLREADPIXELSPROC glow_debug_glReadPixels = glow_debug_impl_glReadPixels;

static void glow_debug_impl_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {

  glow_pre_callback_("glTexParameterf", (void*)(ptrdiff_t)glow_glTexParameterf, target, pname, param);
  glow_glTexParameterf(target, pname, param);
  glow_post_callback_("glTexParameterf", (void*)(ptrdiff_t)glow_glTexParameterf, target, pname, param);
}
PFNGLTEXPARAMETERFPROC glow_debug_glTexParameterf = glow_debug_impl_glTexParameterf;

static void glow_debug_impl_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {

  glow_pre_callback_("glUniform2f", (void*)(ptrdiff_t)glow_glUniform2f, location, v0, v1);
  glow_glUniform2f(location, v0, v1);
  glow_post_callback_("glUniform2f", (void*)(ptrdiff_t)glow_glUniform2f, location, v0, v1);
}
PFNGLUNIFORM2FPROC glow_debug_glUniform2f = glow_debug_impl_glUniform2f;

static void glow_debug_impl_glDepthRangef(GLfloat n, GLfloat f) {

  glow_pre_callback_("glDepthRangef", (void*)(ptrdiff_t)glow_glDepthRangef, n, f);
  glow_glDepthRangef(n, f);
  glow_post_callback_("glDepthRangef", (void*)(ptrdiff_t)glow_glDepthRangef, n, f);
}
PFNGLDEPTHRANGEFPROC glow_debug_glDepthRangef = glow_debug_impl_glDepthRangef;

static void glow_debug_impl_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {

  glow_pre_callback_("glUniform3f", (void*)(ptrdiff_t)glow_glUniform3f, location, v0, v1, v2);
  glow_glUniform3f(location, v0, v1, v2);
  glow_post_callback_("glUniform3f", (void*)(ptrdiff_t)glow_glUniform3f, location, v0, v1, v2);
}
PFNGLUNIFORM3FPROC glow_debug_glUniform3f = glow_debug_impl_glUniform3f;

static void glow_debug_impl_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {

  glow_pre_callback_("glVertexAttrib2f", (void*)(ptrdiff_t)glow_glVertexAttrib2f, index, x, y);
  glow_glVertexAttrib2f(index, x, y);
  glow_post_callback_("glVertexAttrib2f", (void*)(ptrdiff_t)glow_glVertexAttrib2f, index, x, y);
}
PFNGLVERTEXATTRIB2FPROC glow_debug_glVertexAttrib2f = glow_debug_impl_glVertexAttrib2f;

static void glow_debug_impl_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetTexParameteriv", (void*)(ptrdiff_t)glow_glGetTexParameteriv, target, pname, params);
  glow_glGetTexParameteriv(target, pname, params);
  glow_post_callback_("glGetTexParameteriv", (void*)(ptrdiff_t)glow_glGetTexParameteriv, target, pname, params);
}
PFNGLGETTEXPARAMETERIVPROC glow_debug_glGetTexParameteriv = glow_debug_impl_glGetTexParameteriv;

static void glow_debug_impl_glGetUniformfv(GLuint program, GLint location, GLfloat *params) {

  glow_pre_callback_("glGetUniformfv", (void*)(ptrdiff_t)glow_glGetUniformfv, program, location, params);
  glow_glGetUniformfv(program, location, params);
  glow_post_callback_("glGetUniformfv", (void*)(ptrdiff_t)glow_glGetUniformfv, program, location, params);
}
PFNGLGETUNIFORMFVPROC glow_debug_glGetUniformfv = glow_debug_impl_glGetUniformfv;

static void glow_debug_impl_glLineWidth(GLfloat width) {

  glow_pre_callback_("glLineWidth", (void*)(ptrdiff_t)glow_glLineWidth, width);
  glow_glLineWidth(width);
  glow_post_callback_("glLineWidth", (void*)(ptrdiff_t)glow_glLineWidth, width);
}
PFNGLLINEWIDTHPROC glow_debug_glLineWidth = glow_debug_impl_glLineWidth;

static void glow_debug_impl_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glTexImage2D", (void*)(ptrdiff_t)glow_glTexImage2D, target, level, internalformat, width, height, border, format, type, pixels);
  glow_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
  glow_post_callback_("glTexImage2D", (void*)(ptrdiff_t)glow_glTexImage2D, target, level, internalformat, width, height, border, format, type, pixels);
}
PFNGLTEXIMAGE2DPROC glow_debug_glTexImage2D = glow_debug_impl_glTexImage2D;

static void glow_debug_impl_glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) {

  glow_pre_callback_("glBufferData", (void*)(ptrdiff_t)glow_glBufferData, target, size, data, usage);
  glow_glBufferData(target, size, data, usage);
  glow_post_callback_("glBufferData", (void*)(ptrdiff_t)glow_glBufferData, target, size, data, usage);
}
PFNGLBUFFERDATAPROC glow_debug_glBufferData = glow_debug_impl_glBufferData;

static void glow_debug_impl_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) {

  glow_pre_callback_("glCompressedTexSubImage2D", (void*)(ptrdiff_t)glow_glCompressedTexSubImage2D, target, level, xoffset, yoffset, width, height, format, imageSize, data);
  glow_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
  glow_post_callback_("glCompressedTexSubImage2D", (void*)(ptrdiff_t)glow_glCompressedTexSubImage2D, target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glow_debug_glCompressedTexSubImage2D = glow_debug_impl_glCompressedTexSubImage2D;

static void glow_debug_impl_glDrawArrays(GLenum mode, GLint first, GLsizei count) {

  glow_pre_callback_("glDrawArrays", (void*)(ptrdiff_t)glow_glDrawArrays, mode, first, count);
  glow_glDrawArrays(mode, first, count);
  glow_post_callback_("glDrawArrays", (void*)(ptrdiff_t)glow_glDrawArrays, mode, first, count);
}
PFNGLDRAWARRAYSPROC glow_debug_glDrawArrays = glow_debug_impl_glDrawArrays;

static void glow_debug_impl_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {

  glow_pre_callback_("glFramebufferTexture2D", (void*)(ptrdiff_t)glow_glFramebufferTexture2D, target, attachment, textarget, texture, level);
  glow_glFramebufferTexture2D(target, attachment, textarget, texture, level);
  glow_post_callback_("glFramebufferTexture2D", (void*)(ptrdiff_t)glow_glFramebufferTexture2D, target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE2DPROC glow_debug_glFramebufferTexture2D = glow_debug_impl_glFramebufferTexture2D;

static void glow_debug_impl_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glTexParameterfv", (void*)(ptrdiff_t)glow_glTexParameterfv, target, pname, params);
  glow_glTexParameterfv(target, pname, params);
  glow_post_callback_("glTexParameterfv", (void*)(ptrdiff_t)glow_glTexParameterfv, target, pname, params);
}
PFNGLTEXPARAMETERFVPROC glow_debug_glTexParameterfv = glow_debug_impl_glTexParameterfv;

static void glow_debug_impl_glVertexAttrib1f(GLuint index, GLfloat x) {

  glow_pre_callback_("glVertexAttrib1f", (void*)(ptrdiff_t)glow_glVertexAttrib1f, index, x);
  glow_glVertexAttrib1f(index, x);
  glow_post_callback_("glVertexAttrib1f", (void*)(ptrdiff_t)glow_glVertexAttrib1f, index, x);
}
PFNGLVERTEXATTRIB1FPROC glow_debug_glVertexAttrib1f = glow_debug_impl_glVertexAttrib1f;

static void glow_debug_impl_glGetFloatv(GLenum pname, GLfloat *data) {

  glow_pre_callback_("glGetFloatv", (void*)(ptrdiff_t)glow_glGetFloatv, pname, data);
  glow_glGetFloatv(pname, data);
  glow_post_callback_("glGetFloatv", (void*)(ptrdiff_t)glow_glGetFloatv, pname, data);
}
PFNGLGETFLOATVPROC glow_debug_glGetFloatv = glow_debug_impl_glGetFloatv;

static void glow_debug_impl_glGetIntegerv(GLenum pname, GLint *data) {

  glow_pre_callback_("glGetIntegerv", (void*)(ptrdiff_t)glow_glGetIntegerv, pname, data);
  glow_glGetIntegerv(pname, data);
  glow_post_callback_("glGetIntegerv", (void*)(ptrdiff_t)glow_glGetIntegerv, pname, data);
}
PFNGLGETINTEGERVPROC glow_debug_glGetIntegerv = glow_debug_impl_glGetIntegerv;

static void glow_debug_impl_glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetVertexAttribiv", (void*)(ptrdiff_t)glow_glGetVertexAttribiv, index, pname, params);
  glow_glGetVertexAttribiv(index, pname, params);
  glow_post_callback_("glGetVertexAttribiv", (void*)(ptrdiff_t)glow_glGetVertexAttribiv, index, pname, params);
}
PFNGLGETVERTEXATTRIBIVPROC glow_debug_glGetVertexAttribiv = glow_debug_impl_glGetVertexAttribiv;

static void glow_debug_impl_glVertexAttrib4fv(GLuint index, const GLfloat *v) {

  glow_pre_callback_("glVertexAttrib4fv", (void*)(ptrdiff_t)glow_glVertexAttrib4fv, index, v);
  glow_glVertexAttrib4fv(index, v);
  glow_post_callback_("glVertexAttrib4fv", (void*)(ptrdiff_t)glow_glVertexAttrib4fv, index, v);
}
PFNGLVERTEXATTRIB4FVPROC glow_debug_glVertexAttrib4fv = glow_debug_impl_glVertexAttrib4fv;

static void glow_debug_impl_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix3fv", (void*)(ptrdiff_t)glow_glUniformMatrix3fv, location, count, transpose, value);
  glow_glUniformMatrix3fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix3fv", (void*)(ptrdiff_t)glow_glUniformMatrix3fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3FVPROC glow_debug_glUniformMatrix3fv = glow_debug_impl_glUniformMatrix3fv;

static void glow_debug_impl_glClear(GLbitfield mask) {

  glow_pre_callback_("glClear", (void*)(ptrdiff_t)glow_glClear, mask);
  glow_glClear(mask);
  glow_post_callback_("glClear", (void*)(ptrdiff_t)glow_glClear, mask);
}
PFNGLCLEARPROC glow_debug_glClear = glow_debug_impl_glClear;

static void glow_debug_impl_glDeleteShader(GLuint shader) {

  glow_pre_callback_("glDeleteShader", (void*)(ptrdiff_t)glow_glDeleteShader, shader);
  glow_glDeleteShader(shader);
  glow_post_callback_("glDeleteShader", (void*)(ptrdiff_t)glow_glDeleteShader, shader);
}
PFNGLDELETESHADERPROC glow_debug_glDeleteShader = glow_debug_impl_glDeleteShader;

static void glow_debug_impl_glUniform1i(GLint location, GLint v0) {

  glow_pre_callback_("glUniform1i", (void*)(ptrdiff_t)glow_glUniform1i, location, v0);
  glow_glUniform1i(location, v0);
  glow_post_callback_("glUniform1i", (void*)(ptrdiff_t)glow_glUniform1i, location, v0);
}
PFNGLUNIFORM1IPROC glow_debug_glUniform1i = glow_debug_impl_glUniform1i;

static void glow_debug_impl_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {

  glow_pre_callback_("glUniform4i", (void*)(ptrdiff_t)glow_glUniform4i, location, v0, v1, v2, v3);
  glow_glUniform4i(location, v0, v1, v2, v3);
  glow_post_callback_("glUniform4i", (void*)(ptrdiff_t)glow_glUniform4i, location, v0, v1, v2, v3);
}
PFNGLUNIFORM4IPROC glow_debug_glUniform4i = glow_debug_impl_glUniform4i;

static void glow_debug_impl_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {

  glow_pre_callback_("glStencilFuncSeparate", (void*)(ptrdiff_t)glow_glStencilFuncSeparate, face, func, ref, mask);
  glow_glStencilFuncSeparate(face, func, ref, mask);
  glow_post_callback_("glStencilFuncSeparate", (void*)(ptrdiff_t)glow_glStencilFuncSeparate, face, func, ref, mask);
}
PFNGLSTENCILFUNCSEPARATEPROC glow_debug_glStencilFuncSeparate = glow_debug_impl_glStencilFuncSeparate;

static void glow_debug_impl_glUniform4fv(GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glUniform4fv", (void*)(ptrdiff_t)glow_glUniform4fv, location, count, value);
  glow_glUniform4fv(location, count, value);
  glow_post_callback_("glUniform4fv", (void*)(ptrdiff_t)glow_glUniform4fv, location, count, value);
}
PFNGLUNIFORM4FVPROC glow_debug_glUniform4fv = glow_debug_impl_glUniform4fv;

static void glow_debug_impl_glClearDepthf(GLfloat d) {

  glow_pre_callback_("glClearDepthf", (void*)(ptrdiff_t)glow_glClearDepthf, d);
  glow_glClearDepthf(d);
  glow_post_callback_("glClearDepthf", (void*)(ptrdiff_t)glow_glClearDepthf, d);
}
PFNGLCLEARDEPTHFPROC glow_debug_glClearDepthf = glow_debug_impl_glClearDepthf;

static void glow_debug_impl_glEnableVertexAttribArray(GLuint index) {

  glow_pre_callback_("glEnableVertexAttribArray", (void*)(ptrdiff_t)glow_glEnableVertexAttribArray, index);
  glow_glEnableVertexAttribArray(index);
  glow_post_callback_("glEnableVertexAttribArray", (void*)(ptrdiff_t)glow_glEnableVertexAttribArray, index);
}
PFNGLENABLEVERTEXATTRIBARRAYPROC glow_debug_glEnableVertexAttribArray = glow_debug_impl_glEnableVertexAttribArray;

static void glow_debug_impl_glFlush() {

  glow_pre_callback_("glFlush", (void*)(ptrdiff_t)glow_glFlush);
  glow_glFlush();
  glow_post_callback_("glFlush", (void*)(ptrdiff_t)glow_glFlush);
}
PFNGLFLUSHPROC glow_debug_glFlush = glow_debug_impl_glFlush;

static void glow_debug_impl_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) {

  glow_pre_callback_("glGetShaderPrecisionFormat", (void*)(ptrdiff_t)glow_glGetShaderPrecisionFormat, shadertype, precisiontype, range, precision);
  glow_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
  glow_post_callback_("glGetShaderPrecisionFormat", (void*)(ptrdiff_t)glow_glGetShaderPrecisionFormat, shadertype, precisiontype, range, precision);
}
PFNGLGETSHADERPRECISIONFORMATPROC glow_debug_glGetShaderPrecisionFormat = glow_debug_impl_glGetShaderPrecisionFormat;

static void glow_debug_impl_glLinkProgram(GLuint program) {

  glow_pre_callback_("glLinkProgram", (void*)(ptrdiff_t)glow_glLinkProgram, program);
  glow_glLinkProgram(program);
  glow_post_callback_("glLinkProgram", (void*)(ptrdiff_t)glow_glLinkProgram, program);
}
PFNGLLINKPROGRAMPROC glow_debug_glLinkProgram = glow_debug_impl_glLinkProgram;

static void glow_debug_impl_glUniform2fv(GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glUniform2fv", (void*)(ptrdiff_t)glow_glUniform2fv, location, count, value);
  glow_glUniform2fv(location, count, value);
  glow_post_callback_("glUniform2fv", (void*)(ptrdiff_t)glow_glUniform2fv, location, count, value);
}
PFNGLUNIFORM2FVPROC glow_debug_glUniform2fv = glow_debug_impl_glUniform2fv;

static void glow_debug_impl_glValidateProgram(GLuint program) {

  glow_pre_callback_("glValidateProgram", (void*)(ptrdiff_t)glow_glValidateProgram, program);
  glow_glValidateProgram(program);
  glow_post_callback_("glValidateProgram", (void*)(ptrdiff_t)glow_glValidateProgram, program);
}
PFNGLVALIDATEPROGRAMPROC glow_debug_glValidateProgram = glow_debug_impl_glValidateProgram;

static void glow_debug_impl_glVertexAttrib3fv(GLuint index, const GLfloat *v) {

  glow_pre_callback_("glVertexAttrib3fv", (void*)(ptrdiff_t)glow_glVertexAttrib3fv, index, v);
  glow_glVertexAttrib3fv(index, v);
  glow_post_callback_("glVertexAttrib3fv", (void*)(ptrdiff_t)glow_glVertexAttrib3fv, index, v);
}
PFNGLVERTEXATTRIB3FVPROC glow_debug_glVertexAttrib3fv = glow_debug_impl_glVertexAttrib3fv;

static void glow_debug_impl_glCullFace(GLenum mode) {

  glow_pre_callback_("glCullFace", (void*)(ptrdiff_t)glow_glCullFace, mode);
  glow_glCullFace(mode);
  glow_post_callback_("glCullFace", (void*)(ptrdiff_t)glow_glCullFace, mode);
}
PFNGLCULLFACEPROC glow_debug_glCullFace = glow_debug_impl_glCullFace;

static void glow_debug_impl_glDepthFunc(GLenum func) {

  glow_pre_callback_("glDepthFunc", (void*)(ptrdiff_t)glow_glDepthFunc, func);
  glow_glDepthFunc(func);
  glow_post_callback_("glDepthFunc", (void*)(ptrdiff_t)glow_glDepthFunc, func);
}
PFNGLDEPTHFUNCPROC glow_debug_glDepthFunc = glow_debug_impl_glDepthFunc;

static void glow_debug_impl_glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) {

  glow_pre_callback_("glShaderSource", (void*)(ptrdiff_t)glow_glShaderSource, shader, count, string, length);
  glow_glShaderSource(shader, count, string, length);
  glow_post_callback_("glShaderSource", (void*)(ptrdiff_t)glow_glShaderSource, shader, count, string, length);
}
PFNGLSHADERSOURCEPROC glow_debug_glShaderSource = glow_debug_impl_glShaderSource;

static void glow_debug_impl_glUniform1iv(GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glUniform1iv", (void*)(ptrdiff_t)glow_glUniform1iv, location, count, value);
  glow_glUniform1iv(location, count, value);
  glow_post_callback_("glUniform1iv", (void*)(ptrdiff_t)glow_glUniform1iv, location, count, value);
}
PFNGLUNIFORM1IVPROC glow_debug_glUniform1iv = glow_debug_impl_glUniform1iv;

static void glow_debug_impl_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) {

  glow_pre_callback_("glCompressedTexImage2D", (void*)(ptrdiff_t)glow_glCompressedTexImage2D, target, level, internalformat, width, height, border, imageSize, data);
  glow_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
  glow_post_callback_("glCompressedTexImage2D", (void*)(ptrdiff_t)glow_glCompressedTexImage2D, target, level, internalformat, width, height, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE2DPROC glow_debug_glCompressedTexImage2D = glow_debug_impl_glCompressedTexImage2D;

static GLboolean glow_debug_impl_glIsProgram(GLuint program) {

  GLboolean ret;
  glow_pre_callback_("glIsProgram", (void*)(ptrdiff_t)glow_glIsProgram, program);
  ret = glow_glIsProgram(program);
  glow_post_callback_("glIsProgram", (void*)(ptrdiff_t)glow_glIsProgram, program);
  return ret;
}
PFNGLISPROGRAMPROC glow_debug_glIsProgram = glow_debug_impl_glIsProgram;

static void glow_debug_impl_glSampleCoverage(GLfloat value, GLboolean invert) {

  glow_pre_callback_("glSampleCoverage", (void*)(ptrdiff_t)glow_glSampleCoverage, value, invert);
  glow_glSampleCoverage(value, invert);
  glow_post_callback_("glSampleCoverage", (void*)(ptrdiff_t)glow_glSampleCoverage, value, invert);
}
PFNGLSAMPLECOVERAGEPROC glow_debug_glSampleCoverage = glow_debug_impl_glSampleCoverage;

static void glow_debug_impl_glUniform2i(GLint location, GLint v0, GLint v1) {

  glow_pre_callback_("glUniform2i", (void*)(ptrdiff_t)glow_glUniform2i, location, v0, v1);
  glow_glUniform2i(location, v0, v1);
  glow_post_callback_("glUniform2i", (void*)(ptrdiff_t)glow_glUniform2i, location, v0, v1);
}
PFNGLUNIFORM2IPROC glow_debug_glUniform2i = glow_debug_impl_glUniform2i;

static void glow_debug_impl_glCompileShader(GLuint shader) {

  glow_pre_callback_("glCompileShader", (void*)(ptrdiff_t)glow_glCompileShader, shader);
  glow_glCompileShader(shader);
  glow_post_callback_("glCompileShader", (void*)(ptrdiff_t)glow_glCompileShader, shader);
}
PFNGLCOMPILESHADERPROC glow_debug_glCompileShader = glow_debug_impl_glCompileShader;

static GLint glow_debug_impl_glGetAttribLocation(GLuint program, const GLchar *name) {

  GLint ret;
  glow_pre_callback_("glGetAttribLocation", (void*)(ptrdiff_t)glow_glGetAttribLocation, program, name);
  ret = glow_glGetAttribLocation(program, name);
  glow_post_callback_("glGetAttribLocation", (void*)(ptrdiff_t)glow_glGetAttribLocation, program, name);
  return ret;
}
PFNGLGETATTRIBLOCATIONPROC glow_debug_glGetAttribLocation = glow_debug_impl_glGetAttribLocation;

static GLboolean glow_debug_impl_glIsEnabled(GLenum cap) {

  GLboolean ret;
  glow_pre_callback_("glIsEnabled", (void*)(ptrdiff_t)glow_glIsEnabled, cap);
  ret = glow_glIsEnabled(cap);
  glow_post_callback_("glIsEnabled", (void*)(ptrdiff_t)glow_glIsEnabled, cap);
  return ret;
}
PFNGLISENABLEDPROC glow_debug_glIsEnabled = glow_debug_impl_glIsEnabled;

static void glow_debug_impl_glStencilMaskSeparate(GLenum face, GLuint mask) {

  glow_pre_callback_("glStencilMaskSeparate", (void*)(ptrdiff_t)glow_glStencilMaskSeparate, face, mask);
  glow_glStencilMaskSeparate(face, mask);
  glow_post_callback_("glStencilMaskSeparate", (void*)(ptrdiff_t)glow_glStencilMaskSeparate, face, mask);
}
PFNGLSTENCILMASKSEPARATEPROC glow_debug_glStencilMaskSeparate = glow_debug_impl_glStencilMaskSeparate;

static void glow_debug_impl_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {

  glow_pre_callback_("glVertexAttrib3f", (void*)(ptrdiff_t)glow_glVertexAttrib3f, index, x, y, z);
  glow_glVertexAttrib3f(index, x, y, z);
  glow_post_callback_("glVertexAttrib3f", (void*)(ptrdiff_t)glow_glVertexAttrib3f, index, x, y, z);
}
PFNGLVERTEXATTRIB3FPROC glow_debug_glVertexAttrib3f = glow_debug_impl_glVertexAttrib3f;

static void glow_debug_impl_glActiveTexture(GLenum texture) {

  glow_pre_callback_("glActiveTexture", (void*)(ptrdiff_t)glow_glActiveTexture, texture);
  glow_glActiveTexture(texture);
  glow_post_callback_("glActiveTexture", (void*)(ptrdiff_t)glow_glActiveTexture, texture);
}
PFNGLACTIVETEXTUREPROC glow_debug_glActiveTexture = glow_debug_impl_glActiveTexture;

static void glow_debug_impl_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {

  glow_pre_callback_("glColorMask", (void*)(ptrdiff_t)glow_glColorMask, red, green, blue, alpha);
  glow_glColorMask(red, green, blue, alpha);
  glow_post_callback_("glColorMask", (void*)(ptrdiff_t)glow_glColorMask, red, green, blue, alpha);
}
PFNGLCOLORMASKPROC glow_debug_glColorMask = glow_debug_impl_glColorMask;

static void glow_debug_impl_glDisable(GLenum cap) {

  glow_pre_callback_("glDisable", (void*)(ptrdiff_t)glow_glDisable, cap);
  glow_glDisable(cap);
  glow_post_callback_("glDisable", (void*)(ptrdiff_t)glow_glDisable, cap);
}
PFNGLDISABLEPROC glow_debug_glDisable = glow_debug_impl_glDisable;

static void glow_debug_impl_glFinish() {

  glow_pre_callback_("glFinish", (void*)(ptrdiff_t)glow_glFinish);
  glow_glFinish();
  glow_post_callback_("glFinish", (void*)(ptrdiff_t)glow_glFinish);
}
PFNGLFINISHPROC glow_debug_glFinish = glow_debug_impl_glFinish;

static void glow_debug_impl_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {

  glow_pre_callback_("glBindRenderbuffer", (void*)(ptrdiff_t)glow_glBindRenderbuffer, target, renderbuffer);
  glow_glBindRenderbuffer(target, renderbuffer);
  glow_post_callback_("glBindRenderbuffer", (void*)(ptrdiff_t)glow_glBindRenderbuffer, target, renderbuffer);
}
PFNGLBINDRENDERBUFFERPROC glow_debug_glBindRenderbuffer = glow_debug_impl_glBindRenderbuffer;

static GLuint glow_debug_impl_glCreateShader(GLenum type) {

  GLuint ret;
  glow_pre_callback_("glCreateShader", (void*)(ptrdiff_t)glow_glCreateShader, type);
  ret = glow_glCreateShader(type);
  glow_post_callback_("glCreateShader", (void*)(ptrdiff_t)glow_glCreateShader, type);
  return ret;
}
PFNGLCREATESHADERPROC glow_debug_glCreateShader = glow_debug_impl_glCreateShader;

static void glow_debug_impl_glDetachShader(GLuint program, GLuint shader) {

  glow_pre_callback_("glDetachShader", (void*)(ptrdiff_t)glow_glDetachShader, program, shader);
  glow_glDetachShader(program, shader);
  glow_post_callback_("glDetachShader", (void*)(ptrdiff_t)glow_glDetachShader, program, shader);
}
PFNGLDETACHSHADERPROC glow_debug_glDetachShader = glow_debug_impl_glDetachShader;

static void glow_debug_impl_glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) {

  glow_pre_callback_("glShaderBinary", (void*)(ptrdiff_t)glow_glShaderBinary, count, shaders, binaryformat, binary, length);
  glow_glShaderBinary(count, shaders, binaryformat, binary, length);
  glow_post_callback_("glShaderBinary", (void*)(ptrdiff_t)glow_glShaderBinary, count, shaders, binaryformat, binary, length);
}
PFNGLSHADERBINARYPROC glow_debug_glShaderBinary = glow_debug_impl_glShaderBinary;

static void glow_debug_impl_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {

  glow_pre_callback_("glStencilOpSeparate", (void*)(ptrdiff_t)glow_glStencilOpSeparate, face, sfail, dpfail, dppass);
  glow_glStencilOpSeparate(face, sfail, dpfail, dppass);
  glow_post_callback_("glStencilOpSeparate", (void*)(ptrdiff_t)glow_glStencilOpSeparate, face, sfail, dpfail, dppass);
}
PFNGLSTENCILOPSEPARATEPROC glow_debug_glStencilOpSeparate = glow_debug_impl_glStencilOpSeparate;

static void glow_debug_impl_glTexParameteriv(GLenum target, GLenum pname, const GLint *params) {

  glow_pre_callback_("glTexParameteriv", (void*)(ptrdiff_t)glow_glTexParameteriv, target, pname, params);
  glow_glTexParameteriv(target, pname, params);
  glow_post_callback_("glTexParameteriv", (void*)(ptrdiff_t)glow_glTexParameteriv, target, pname, params);
}
PFNGLTEXPARAMETERIVPROC glow_debug_glTexParameteriv = glow_debug_impl_glTexParameteriv;

static void glow_debug_impl_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {

  glow_pre_callback_("glUniform4f", (void*)(ptrdiff_t)glow_glUniform4f, location, v0, v1, v2, v3);
  glow_glUniform4f(location, v0, v1, v2, v3);
  glow_post_callback_("glUniform4f", (void*)(ptrdiff_t)glow_glUniform4f, location, v0, v1, v2, v3);
}
PFNGLUNIFORM4FPROC glow_debug_glUniform4f = glow_debug_impl_glUniform4f;

static void glow_debug_impl_glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) {

  glow_pre_callback_("glBindAttribLocation", (void*)(ptrdiff_t)glow_glBindAttribLocation, program, index, name);
  glow_glBindAttribLocation(program, index, name);
  glow_post_callback_("glBindAttribLocation", (void*)(ptrdiff_t)glow_glBindAttribLocation, program, index, name);
}
PFNGLBINDATTRIBLOCATIONPROC glow_debug_glBindAttribLocation = glow_debug_impl_glBindAttribLocation;

static void glow_debug_impl_glBindBuffer(GLenum target, GLuint buffer) {

  glow_pre_callback_("glBindBuffer", (void*)(ptrdiff_t)glow_glBindBuffer, target, buffer);
  glow_glBindBuffer(target, buffer);
  glow_post_callback_("glBindBuffer", (void*)(ptrdiff_t)glow_glBindBuffer, target, buffer);
}
PFNGLBINDBUFFERPROC glow_debug_glBindBuffer = glow_debug_impl_glBindBuffer;

static void glow_debug_impl_glDeleteTextures(GLsizei n, const GLuint *textures) {

  glow_pre_callback_("glDeleteTextures", (void*)(ptrdiff_t)glow_glDeleteTextures, n, textures);
  glow_glDeleteTextures(n, textures);
  glow_post_callback_("glDeleteTextures", (void*)(ptrdiff_t)glow_glDeleteTextures, n, textures);
}
PFNGLDELETETEXTURESPROC glow_debug_glDeleteTextures = glow_debug_impl_glDeleteTextures;

static void glow_debug_impl_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {

  glow_pre_callback_("glGetProgramInfoLog", (void*)(ptrdiff_t)glow_glGetProgramInfoLog, program, bufSize, length, infoLog);
  glow_glGetProgramInfoLog(program, bufSize, length, infoLog);
  glow_post_callback_("glGetProgramInfoLog", (void*)(ptrdiff_t)glow_glGetProgramInfoLog, program, bufSize, length, infoLog);
}
PFNGLGETPROGRAMINFOLOGPROC glow_debug_glGetProgramInfoLog = glow_debug_impl_glGetProgramInfoLog;

static void glow_debug_impl_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix2fv", (void*)(ptrdiff_t)glow_glUniformMatrix2fv, location, count, transpose, value);
  glow_glUniformMatrix2fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix2fv", (void*)(ptrdiff_t)glow_glUniformMatrix2fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2FVPROC glow_debug_glUniformMatrix2fv = glow_debug_impl_glUniformMatrix2fv;

static void glow_debug_impl_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {

  glow_pre_callback_("glVertexAttrib4f", (void*)(ptrdiff_t)glow_glVertexAttrib4f, index, x, y, z, w);
  glow_glVertexAttrib4f(index, x, y, z, w);
  glow_post_callback_("glVertexAttrib4f", (void*)(ptrdiff_t)glow_glVertexAttrib4f, index, x, y, z, w);
}
PFNGLVERTEXATTRIB4FPROC glow_debug_glVertexAttrib4f = glow_debug_impl_glVertexAttrib4f;

static void glow_debug_impl_glDeleteProgram(GLuint program) {

  glow_pre_callback_("glDeleteProgram", (void*)(ptrdiff_t)glow_glDeleteProgram, program);
  glow_glDeleteProgram(program);
  glow_post_callback_("glDeleteProgram", (void*)(ptrdiff_t)glow_glDeleteProgram, program);
}
PFNGLDELETEPROGRAMPROC glow_debug_glDeleteProgram = glow_debug_impl_glDeleteProgram;

static void glow_debug_impl_glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetBufferParameteriv", (void*)(ptrdiff_t)glow_glGetBufferParameteriv, target, pname, params);
  glow_glGetBufferParameteriv(target, pname, params);
  glow_post_callback_("glGetBufferParameteriv", (void*)(ptrdiff_t)glow_glGetBufferParameteriv, target, pname, params);
}
PFNGLGETBUFFERPARAMETERIVPROC glow_debug_glGetBufferParameteriv = glow_debug_impl_glGetBufferParameteriv;

static void glow_debug_impl_glUniform1f(GLint location, GLfloat v0) {

  glow_pre_callback_("glUniform1f", (void*)(ptrdiff_t)glow_glUniform1f, location, v0);
  glow_glUniform1f(location, v0);
  glow_post_callback_("glUniform1f", (void*)(ptrdiff_t)glow_glUniform1f, location, v0);
}
PFNGLUNIFORM1FPROC glow_debug_glUniform1f = glow_debug_impl_glUniform1f;

static GLubyte glow_debug_impl_glGetString(GLenum name) {

  GLubyte ret;
  glow_pre_callback_("glGetString", (void*)(ptrdiff_t)glow_glGetString, name);
  ret = glow_glGetString(name);
  glow_post_callback_("glGetString", (void*)(ptrdiff_t)glow_glGetString, name);
  return ret;
}
PFNGLGETSTRINGPROC glow_debug_glGetString = glow_debug_impl_glGetString;

static GLint glow_debug_impl_glGetUniformLocation(GLuint program, const GLchar *name) {

  GLint ret;
  glow_pre_callback_("glGetUniformLocation", (void*)(ptrdiff_t)glow_glGetUniformLocation, program, name);
  ret = glow_glGetUniformLocation(program, name);
  glow_post_callback_("glGetUniformLocation", (void*)(ptrdiff_t)glow_glGetUniformLocation, program, name);
  return ret;
}
PFNGLGETUNIFORMLOCATIONPROC glow_debug_glGetUniformLocation = glow_debug_impl_glGetUniformLocation;

static GLboolean glow_debug_impl_glIsRenderbuffer(GLuint renderbuffer) {

  GLboolean ret;
  glow_pre_callback_("glIsRenderbuffer", (void*)(ptrdiff_t)glow_glIsRenderbuffer, renderbuffer);
  ret = glow_glIsRenderbuffer(renderbuffer);
  glow_post_callback_("glIsRenderbuffer", (void*)(ptrdiff_t)glow_glIsRenderbuffer, renderbuffer);
  return ret;
}
PFNGLISRENDERBUFFERPROC glow_debug_glIsRenderbuffer = glow_debug_impl_glIsRenderbuffer;

static void glow_debug_impl_glAttachShader(GLuint program, GLuint shader) {

  glow_pre_callback_("glAttachShader", (void*)(ptrdiff_t)glow_glAttachShader, program, shader);
  glow_glAttachShader(program, shader);
  glow_post_callback_("glAttachShader", (void*)(ptrdiff_t)glow_glAttachShader, program, shader);
}
PFNGLATTACHSHADERPROC glow_debug_glAttachShader = glow_debug_impl_glAttachShader;

static void glow_debug_impl_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) {

  glow_pre_callback_("glBufferSubData", (void*)(ptrdiff_t)glow_glBufferSubData, target, offset, size, data);
  glow_glBufferSubData(target, offset, size, data);
  glow_post_callback_("glBufferSubData", (void*)(ptrdiff_t)glow_glBufferSubData, target, offset, size, data);
}
PFNGLBUFFERSUBDATAPROC glow_debug_glBufferSubData = glow_debug_impl_glBufferSubData;

static void glow_debug_impl_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {

  glow_pre_callback_("glCopyTexImage2D", (void*)(ptrdiff_t)glow_glCopyTexImage2D, target, level, internalformat, x, y, width, height, border);
  glow_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
  glow_post_callback_("glCopyTexImage2D", (void*)(ptrdiff_t)glow_glCopyTexImage2D, target, level, internalformat, x, y, width, height, border);
}
PFNGLCOPYTEXIMAGE2DPROC glow_debug_glCopyTexImage2D = glow_debug_impl_glCopyTexImage2D;

static void glow_debug_impl_glDeleteBuffers(GLsizei n, const GLuint *buffers) {

  glow_pre_callback_("glDeleteBuffers", (void*)(ptrdiff_t)glow_glDeleteBuffers, n, buffers);
  glow_glDeleteBuffers(n, buffers);
  glow_post_callback_("glDeleteBuffers", (void*)(ptrdiff_t)glow_glDeleteBuffers, n, buffers);
}
PFNGLDELETEBUFFERSPROC glow_debug_glDeleteBuffers = glow_debug_impl_glDeleteBuffers;

static void glow_debug_impl_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {

  glow_pre_callback_("glGetShaderInfoLog", (void*)(ptrdiff_t)glow_glGetShaderInfoLog, shader, bufSize, length, infoLog);
  glow_glGetShaderInfoLog(shader, bufSize, length, infoLog);
  glow_post_callback_("glGetShaderInfoLog", (void*)(ptrdiff_t)glow_glGetShaderInfoLog, shader, bufSize, length, infoLog);
}
PFNGLGETSHADERINFOLOGPROC glow_debug_glGetShaderInfoLog = glow_debug_impl_glGetShaderInfoLog;

static void glow_debug_impl_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {

  glow_pre_callback_("glBlendEquationSeparate", (void*)(ptrdiff_t)glow_glBlendEquationSeparate, modeRGB, modeAlpha);
  glow_glBlendEquationSeparate(modeRGB, modeAlpha);
  glow_post_callback_("glBlendEquationSeparate", (void*)(ptrdiff_t)glow_glBlendEquationSeparate, modeRGB, modeAlpha);
}
PFNGLBLENDEQUATIONSEPARATEPROC glow_debug_glBlendEquationSeparate = glow_debug_impl_glBlendEquationSeparate;

static void glow_debug_impl_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) {

  glow_pre_callback_("glDrawElements", (void*)(ptrdiff_t)glow_glDrawElements, mode, count, type, indices);
  glow_glDrawElements(mode, count, type, indices);
  glow_post_callback_("glDrawElements", (void*)(ptrdiff_t)glow_glDrawElements, mode, count, type, indices);
}
PFNGLDRAWELEMENTSPROC glow_debug_glDrawElements = glow_debug_impl_glDrawElements;

static void glow_debug_impl_glEnable(GLenum cap) {

  glow_pre_callback_("glEnable", (void*)(ptrdiff_t)glow_glEnable, cap);
  glow_glEnable(cap);
  glow_post_callback_("glEnable", (void*)(ptrdiff_t)glow_glEnable, cap);
}
PFNGLENABLEPROC glow_debug_glEnable = glow_debug_impl_glEnable;

static void glow_debug_impl_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {

  glow_pre_callback_("glGetActiveUniform", (void*)(ptrdiff_t)glow_glGetActiveUniform, program, index, bufSize, length, size, type, name);
  glow_glGetActiveUniform(program, index, bufSize, length, size, type, name);
  glow_post_callback_("glGetActiveUniform", (void*)(ptrdiff_t)glow_glGetActiveUniform, program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEUNIFORMPROC glow_debug_glGetActiveUniform = glow_debug_impl_glGetActiveUniform;

static void glow_debug_impl_glStencilMask(GLuint mask) {

  glow_pre_callback_("glStencilMask", (void*)(ptrdiff_t)glow_glStencilMask, mask);
  glow_glStencilMask(mask);
  glow_post_callback_("glStencilMask", (void*)(ptrdiff_t)glow_glStencilMask, mask);
}
PFNGLSTENCILMASKPROC glow_debug_glStencilMask = glow_debug_impl_glStencilMask;

static void glow_debug_impl_glUniform3fv(GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glUniform3fv", (void*)(ptrdiff_t)glow_glUniform3fv, location, count, value);
  glow_glUniform3fv(location, count, value);
  glow_post_callback_("glUniform3fv", (void*)(ptrdiff_t)glow_glUniform3fv, location, count, value);
}
PFNGLUNIFORM3FVPROC glow_debug_glUniform3fv = glow_debug_impl_glUniform3fv;

static void glow_debug_impl_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {

  glow_pre_callback_("glUniform3i", (void*)(ptrdiff_t)glow_glUniform3i, location, v0, v1, v2);
  glow_glUniform3i(location, v0, v1, v2);
  glow_post_callback_("glUniform3i", (void*)(ptrdiff_t)glow_glUniform3i, location, v0, v1, v2);
}
PFNGLUNIFORM3IPROC glow_debug_glUniform3i = glow_debug_impl_glUniform3i;

static void glow_debug_impl_glBindFramebuffer(GLenum target, GLuint framebuffer) {

  glow_pre_callback_("glBindFramebuffer", (void*)(ptrdiff_t)glow_glBindFramebuffer, target, framebuffer);
  glow_glBindFramebuffer(target, framebuffer);
  glow_post_callback_("glBindFramebuffer", (void*)(ptrdiff_t)glow_glBindFramebuffer, target, framebuffer);
}
PFNGLBINDFRAMEBUFFERPROC glow_debug_glBindFramebuffer = glow_debug_impl_glBindFramebuffer;

static void glow_debug_impl_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glCopyTexSubImage2D", (void*)(ptrdiff_t)glow_glCopyTexSubImage2D, target, level, xoffset, yoffset, x, y, width, height);
  glow_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
  glow_post_callback_("glCopyTexSubImage2D", (void*)(ptrdiff_t)glow_glCopyTexSubImage2D, target, level, xoffset, yoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE2DPROC glow_debug_glCopyTexSubImage2D = glow_debug_impl_glCopyTexSubImage2D;

static GLboolean glow_debug_impl_glIsTexture(GLuint texture) {

  GLboolean ret;
  glow_pre_callback_("glIsTexture", (void*)(ptrdiff_t)glow_glIsTexture, texture);
  ret = glow_glIsTexture(texture);
  glow_post_callback_("glIsTexture", (void*)(ptrdiff_t)glow_glIsTexture, texture);
  return ret;
}
PFNGLISTEXTUREPROC glow_debug_glIsTexture = glow_debug_impl_glIsTexture;

static void glow_debug_impl_glPolygonOffset(GLfloat factor, GLfloat units) {

  glow_pre_callback_("glPolygonOffset", (void*)(ptrdiff_t)glow_glPolygonOffset, factor, units);
  glow_glPolygonOffset(factor, units);
  glow_post_callback_("glPolygonOffset", (void*)(ptrdiff_t)glow_glPolygonOffset, factor, units);
}
PFNGLPOLYGONOFFSETPROC glow_debug_glPolygonOffset = glow_debug_impl_glPolygonOffset;

#endif /* GLOW_DEBUG */



int glow_init(void) {
  return glow_init_with(&glow_get_proc);
}

int glow_init_with(glow_load_proc_t get_proc) {
  int unresolved_count = 0;

  glow_glBlendColor = (PFNGLBLENDCOLORPROC)(ptrdiff_t)get_proc("glBlendColor");
  if (glow_glBlendColor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendColor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendColor\n");
#endif
    unresolved_count += 1;
  } 
  glow_glScissor = (PFNGLSCISSORPROC)(ptrdiff_t)get_proc("glScissor");
  if (glow_glScissor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glScissor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glScissor\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)(ptrdiff_t)get_proc("glVertexAttrib1fv");
  if (glow_glVertexAttrib1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib1fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlendEquation = (PFNGLBLENDEQUATIONPROC)(ptrdiff_t)get_proc("glBlendEquation");
  if (glow_glBlendEquation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendEquation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendEquation\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlendFunc = (PFNGLBLENDFUNCPROC)(ptrdiff_t)get_proc("glBlendFunc");
  if (glow_glBlendFunc == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendFunc\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendFunc\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsBuffer = (PFNGLISBUFFERPROC)(ptrdiff_t)get_proc("glIsBuffer");
  if (glow_glIsBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsBuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform3iv = (PFNGLUNIFORM3IVPROC)(ptrdiff_t)get_proc("glUniform3iv");
  if (glow_glUniform3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)(ptrdiff_t)get_proc("glDisableVertexAttribArray");
  if (glow_glDisableVertexAttribArray == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisableVertexAttribArray\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisableVertexAttribArray\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)(ptrdiff_t)get_proc("glGenFramebuffers");
  if (glow_glGenFramebuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenFramebuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenFramebuffers\n");
#endif
    unresolved_count += 1;
  } 
  glow_glHint = (PFNGLHINTPROC)(ptrdiff_t)get_proc("glHint");
  if (glow_glHint == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glHint\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glHint\n");
#endif
    unresolved_count += 1;
  } 
  glow_glStencilOp = (PFNGLSTENCILOPPROC)(ptrdiff_t)get_proc("glStencilOp");
  if (glow_glStencilOp == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilOp\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilOp\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)(ptrdiff_t)get_proc("glFramebufferRenderbuffer");
  if (glow_glFramebufferRenderbuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferRenderbuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferRenderbuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)(ptrdiff_t)get_proc("glGetVertexAttribfv");
  if (glow_glGetVertexAttribfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)(ptrdiff_t)get_proc("glRenderbufferStorage");
  if (glow_glRenderbufferStorage == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRenderbufferStorage\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRenderbufferStorage\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)(ptrdiff_t)get_proc("glTexSubImage2D");
  if (glow_glTexSubImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexSubImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexSubImage2D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform1fv = (PFNGLUNIFORM1FVPROC)(ptrdiff_t)get_proc("glUniform1fv");
  if (glow_glUniform1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)(ptrdiff_t)get_proc("glUniformMatrix4fv");
  if (glow_glUniformMatrix4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFrontFace = (PFNGLFRONTFACEPROC)(ptrdiff_t)get_proc("glFrontFace");
  if (glow_glFrontFace == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFrontFace\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFrontFace\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)(ptrdiff_t)get_proc("glGetActiveAttrib");
  if (glow_glGetActiveAttrib == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetActiveAttrib\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetActiveAttrib\n");
#endif
    unresolved_count += 1;
  } 
  glow_glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)(ptrdiff_t)get_proc("glReleaseShaderCompiler");
  if (glow_glReleaseShaderCompiler == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReleaseShaderCompiler\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReleaseShaderCompiler\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexParameteri = (PFNGLTEXPARAMETERIPROC)(ptrdiff_t)get_proc("glTexParameteri");
  if (glow_glTexParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameteri\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)(ptrdiff_t)get_proc("glCheckFramebufferStatus");
  if (glow_glCheckFramebufferStatus == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCheckFramebufferStatus\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCheckFramebufferStatus\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)(ptrdiff_t)get_proc("glGetAttachedShaders");
  if (glow_glGetAttachedShaders == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetAttachedShaders\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetAttachedShaders\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)(ptrdiff_t)get_proc("glGenerateMipmap");
  if (glow_glGenerateMipmap == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenerateMipmap\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenerateMipmap\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)(ptrdiff_t)get_proc("glIsFramebuffer");
  if (glow_glIsFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsFramebuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetUniformiv = (PFNGLGETUNIFORMIVPROC)(ptrdiff_t)get_proc("glGetUniformiv");
  if (glow_glGetUniformiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)(ptrdiff_t)get_proc("glGetVertexAttribPointerv");
  if (glow_glGetVertexAttribPointerv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribPointerv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribPointerv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUseProgram = (PFNGLUSEPROGRAMPROC)(ptrdiff_t)get_proc("glUseProgram");
  if (glow_glUseProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUseProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUseProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)(ptrdiff_t)get_proc("glGenRenderbuffers");
  if (glow_glGenRenderbuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenRenderbuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenRenderbuffers\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetBooleanv = (PFNGLGETBOOLEANVPROC)(ptrdiff_t)get_proc("glGetBooleanv");
  if (glow_glGetBooleanv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBooleanv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBooleanv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetShaderiv = (PFNGLGETSHADERIVPROC)(ptrdiff_t)get_proc("glGetShaderiv");
  if (glow_glGetShaderiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetShaderiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetShaderiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)(ptrdiff_t)get_proc("glGetShaderSource");
  if (glow_glGetShaderSource == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetShaderSource\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetShaderSource\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetProgramiv = (PFNGLGETPROGRAMIVPROC)(ptrdiff_t)get_proc("glGetProgramiv");
  if (glow_glGetProgramiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPixelStorei = (PFNGLPIXELSTOREIPROC)(ptrdiff_t)get_proc("glPixelStorei");
  if (glow_glPixelStorei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelStorei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelStorei\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform2iv = (PFNGLUNIFORM2IVPROC)(ptrdiff_t)get_proc("glUniform2iv");
  if (glow_glUniform2iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetError = (PFNGLGETERRORPROC)(ptrdiff_t)get_proc("glGetError");
  if (glow_glGetError == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetError\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetError\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetFramebufferAttachmentParameteriv");
  if (glow_glGetFramebufferAttachmentParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFramebufferAttachmentParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFramebufferAttachmentParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)(ptrdiff_t)get_proc("glVertexAttrib2fv");
  if (glow_glVertexAttrib2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib2fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)(ptrdiff_t)get_proc("glVertexAttribPointer");
  if (glow_glVertexAttribPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribPointer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindTexture = (PFNGLBINDTEXTUREPROC)(ptrdiff_t)get_proc("glBindTexture");
  if (glow_glBindTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindTexture\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCreateProgram = (PFNGLCREATEPROGRAMPROC)(ptrdiff_t)get_proc("glCreateProgram");
  if (glow_glCreateProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCreateProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCreateProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGenBuffers = (PFNGLGENBUFFERSPROC)(ptrdiff_t)get_proc("glGenBuffers");
  if (glow_glGenBuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenBuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenBuffers\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGenTextures = (PFNGLGENTEXTURESPROC)(ptrdiff_t)get_proc("glGenTextures");
  if (glow_glGenTextures == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenTextures\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenTextures\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetRenderbufferParameteriv");
  if (glow_glGetRenderbufferParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetRenderbufferParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetRenderbufferParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)(ptrdiff_t)get_proc("glBlendFuncSeparate");
  if (glow_glBlendFuncSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendFuncSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendFuncSeparate\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClearStencil = (PFNGLCLEARSTENCILPROC)(ptrdiff_t)get_proc("glClearStencil");
  if (glow_glClearStencil == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearStencil\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearStencil\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)(ptrdiff_t)get_proc("glDeleteRenderbuffers");
  if (glow_glDeleteRenderbuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteRenderbuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteRenderbuffers\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDepthMask = (PFNGLDEPTHMASKPROC)(ptrdiff_t)get_proc("glDepthMask");
  if (glow_glDepthMask == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthMask\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthMask\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClearColor = (PFNGLCLEARCOLORPROC)(ptrdiff_t)get_proc("glClearColor");
  if (glow_glClearColor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearColor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearColor\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)(ptrdiff_t)get_proc("glGetTexParameterfv");
  if (glow_glGetTexParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameterfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)(ptrdiff_t)get_proc("glDeleteFramebuffers");
  if (glow_glDeleteFramebuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteFramebuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteFramebuffers\n");
#endif
    unresolved_count += 1;
  } 
  glow_glStencilFunc = (PFNGLSTENCILFUNCPROC)(ptrdiff_t)get_proc("glStencilFunc");
  if (glow_glStencilFunc == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilFunc\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilFunc\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform4iv = (PFNGLUNIFORM4IVPROC)(ptrdiff_t)get_proc("glUniform4iv");
  if (glow_glUniform4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glViewport = (PFNGLVIEWPORTPROC)(ptrdiff_t)get_proc("glViewport");
  if (glow_glViewport == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glViewport\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glViewport\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsShader = (PFNGLISSHADERPROC)(ptrdiff_t)get_proc("glIsShader");
  if (glow_glIsShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsShader\n");
#endif
    unresolved_count += 1;
  } 
  glow_glReadPixels = (PFNGLREADPIXELSPROC)(ptrdiff_t)get_proc("glReadPixels");
  if (glow_glReadPixels == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReadPixels\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReadPixels\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexParameterf = (PFNGLTEXPARAMETERFPROC)(ptrdiff_t)get_proc("glTexParameterf");
  if (glow_glTexParameterf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform2f = (PFNGLUNIFORM2FPROC)(ptrdiff_t)get_proc("glUniform2f");
  if (glow_glUniform2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDepthRangef = (PFNGLDEPTHRANGEFPROC)(ptrdiff_t)get_proc("glDepthRangef");
  if (glow_glDepthRangef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthRangef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthRangef\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform3f = (PFNGLUNIFORM3FPROC)(ptrdiff_t)get_proc("glUniform3f");
  if (glow_glUniform3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)(ptrdiff_t)get_proc("glVertexAttrib2f");
  if (glow_glVertexAttrib2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib2f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetTexParameteriv");
  if (glow_glGetTexParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetUniformfv = (PFNGLGETUNIFORMFVPROC)(ptrdiff_t)get_proc("glGetUniformfv");
  if (glow_glGetUniformfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLineWidth = (PFNGLLINEWIDTHPROC)(ptrdiff_t)get_proc("glLineWidth");
  if (glow_glLineWidth == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLineWidth\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLineWidth\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexImage2D = (PFNGLTEXIMAGE2DPROC)(ptrdiff_t)get_proc("glTexImage2D");
  if (glow_glTexImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexImage2D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBufferData = (PFNGLBUFFERDATAPROC)(ptrdiff_t)get_proc("glBufferData");
  if (glow_glBufferData == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBufferData\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBufferData\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(ptrdiff_t)get_proc("glCompressedTexSubImage2D");
  if (glow_glCompressedTexSubImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompressedTexSubImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompressedTexSubImage2D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDrawArrays = (PFNGLDRAWARRAYSPROC)(ptrdiff_t)get_proc("glDrawArrays");
  if (glow_glDrawArrays == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawArrays\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawArrays\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)(ptrdiff_t)get_proc("glFramebufferTexture2D");
  if (glow_glFramebufferTexture2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferTexture2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferTexture2D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)(ptrdiff_t)get_proc("glTexParameterfv");
  if (glow_glTexParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)(ptrdiff_t)get_proc("glVertexAttrib1f");
  if (glow_glVertexAttrib1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib1f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetFloatv = (PFNGLGETFLOATVPROC)(ptrdiff_t)get_proc("glGetFloatv");
  if (glow_glGetFloatv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFloatv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFloatv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetIntegerv = (PFNGLGETINTEGERVPROC)(ptrdiff_t)get_proc("glGetIntegerv");
  if (glow_glGetIntegerv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetIntegerv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetIntegerv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)(ptrdiff_t)get_proc("glGetVertexAttribiv");
  if (glow_glGetVertexAttribiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)(ptrdiff_t)get_proc("glVertexAttrib4fv");
  if (glow_glVertexAttrib4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)(ptrdiff_t)get_proc("glUniformMatrix3fv");
  if (glow_glUniformMatrix3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClear = (PFNGLCLEARPROC)(ptrdiff_t)get_proc("glClear");
  if (glow_glClear == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClear\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClear\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteShader = (PFNGLDELETESHADERPROC)(ptrdiff_t)get_proc("glDeleteShader");
  if (glow_glDeleteShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteShader\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform1i = (PFNGLUNIFORM1IPROC)(ptrdiff_t)get_proc("glUniform1i");
  if (glow_glUniform1i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform4i = (PFNGLUNIFORM4IPROC)(ptrdiff_t)get_proc("glUniform4i");
  if (glow_glUniform4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)(ptrdiff_t)get_proc("glStencilFuncSeparate");
  if (glow_glStencilFuncSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilFuncSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilFuncSeparate\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform4fv = (PFNGLUNIFORM4FVPROC)(ptrdiff_t)get_proc("glUniform4fv");
  if (glow_glUniform4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClearDepthf = (PFNGLCLEARDEPTHFPROC)(ptrdiff_t)get_proc("glClearDepthf");
  if (glow_glClearDepthf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearDepthf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearDepthf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)(ptrdiff_t)get_proc("glEnableVertexAttribArray");
  if (glow_glEnableVertexAttribArray == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnableVertexAttribArray\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnableVertexAttribArray\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFlush = (PFNGLFLUSHPROC)(ptrdiff_t)get_proc("glFlush");
  if (glow_glFlush == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFlush\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFlush\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)(ptrdiff_t)get_proc("glGetShaderPrecisionFormat");
  if (glow_glGetShaderPrecisionFormat == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetShaderPrecisionFormat\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetShaderPrecisionFormat\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLinkProgram = (PFNGLLINKPROGRAMPROC)(ptrdiff_t)get_proc("glLinkProgram");
  if (glow_glLinkProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLinkProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLinkProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform2fv = (PFNGLUNIFORM2FVPROC)(ptrdiff_t)get_proc("glUniform2fv");
  if (glow_glUniform2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)(ptrdiff_t)get_proc("glValidateProgram");
  if (glow_glValidateProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glValidateProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glValidateProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)(ptrdiff_t)get_proc("glVertexAttrib3fv");
  if (glow_glVertexAttrib3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCullFace = (PFNGLCULLFACEPROC)(ptrdiff_t)get_proc("glCullFace");
  if (glow_glCullFace == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCullFace\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCullFace\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDepthFunc = (PFNGLDEPTHFUNCPROC)(ptrdiff_t)get_proc("glDepthFunc");
  if (glow_glDepthFunc == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthFunc\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthFunc\n");
#endif
    unresolved_count += 1;
  } 
  glow_glShaderSource = (PFNGLSHADERSOURCEPROC)(ptrdiff_t)get_proc("glShaderSource");
  if (glow_glShaderSource == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glShaderSource\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glShaderSource\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform1iv = (PFNGLUNIFORM1IVPROC)(ptrdiff_t)get_proc("glUniform1iv");
  if (glow_glUniform1iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)(ptrdiff_t)get_proc("glCompressedTexImage2D");
  if (glow_glCompressedTexImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompressedTexImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompressedTexImage2D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsProgram = (PFNGLISPROGRAMPROC)(ptrdiff_t)get_proc("glIsProgram");
  if (glow_glIsProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)(ptrdiff_t)get_proc("glSampleCoverage");
  if (glow_glSampleCoverage == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSampleCoverage\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSampleCoverage\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform2i = (PFNGLUNIFORM2IPROC)(ptrdiff_t)get_proc("glUniform2i");
  if (glow_glUniform2i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCompileShader = (PFNGLCOMPILESHADERPROC)(ptrdiff_t)get_proc("glCompileShader");
  if (glow_glCompileShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompileShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompileShader\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)(ptrdiff_t)get_proc("glGetAttribLocation");
  if (glow_glGetAttribLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetAttribLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetAttribLocation\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsEnabled = (PFNGLISENABLEDPROC)(ptrdiff_t)get_proc("glIsEnabled");
  if (glow_glIsEnabled == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsEnabled\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsEnabled\n");
#endif
    unresolved_count += 1;
  } 
  glow_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)(ptrdiff_t)get_proc("glStencilMaskSeparate");
  if (glow_glStencilMaskSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilMaskSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilMaskSeparate\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)(ptrdiff_t)get_proc("glVertexAttrib3f");
  if (glow_glVertexAttrib3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib3f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glActiveTexture = (PFNGLACTIVETEXTUREPROC)(ptrdiff_t)get_proc("glActiveTexture");
  if (glow_glActiveTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glActiveTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glActiveTexture\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColorMask = (PFNGLCOLORMASKPROC)(ptrdiff_t)get_proc("glColorMask");
  if (glow_glColorMask == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColorMask\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColorMask\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDisable = (PFNGLDISABLEPROC)(ptrdiff_t)get_proc("glDisable");
  if (glow_glDisable == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisable\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisable\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFinish = (PFNGLFINISHPROC)(ptrdiff_t)get_proc("glFinish");
  if (glow_glFinish == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFinish\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFinish\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)(ptrdiff_t)get_proc("glBindRenderbuffer");
  if (glow_glBindRenderbuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindRenderbuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindRenderbuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCreateShader = (PFNGLCREATESHADERPROC)(ptrdiff_t)get_proc("glCreateShader");
  if (glow_glCreateShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCreateShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCreateShader\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDetachShader = (PFNGLDETACHSHADERPROC)(ptrdiff_t)get_proc("glDetachShader");
  if (glow_glDetachShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDetachShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDetachShader\n");
#endif
    unresolved_count += 1;
  } 
  glow_glShaderBinary = (PFNGLSHADERBINARYPROC)(ptrdiff_t)get_proc("glShaderBinary");
  if (glow_glShaderBinary == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glShaderBinary\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glShaderBinary\n");
#endif
    unresolved_count += 1;
  } 
  glow_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)(ptrdiff_t)get_proc("glStencilOpSeparate");
  if (glow_glStencilOpSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilOpSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilOpSeparate\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)(ptrdiff_t)get_proc("glTexParameteriv");
  if (glow_glTexParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform4f = (PFNGLUNIFORM4FPROC)(ptrdiff_t)get_proc("glUniform4f");
  if (glow_glUniform4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)(ptrdiff_t)get_proc("glBindAttribLocation");
  if (glow_glBindAttribLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindAttribLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindAttribLocation\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindBuffer = (PFNGLBINDBUFFERPROC)(ptrdiff_t)get_proc("glBindBuffer");
  if (glow_glBindBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindBuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteTextures = (PFNGLDELETETEXTURESPROC)(ptrdiff_t)get_proc("glDeleteTextures");
  if (glow_glDeleteTextures == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteTextures\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteTextures\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)(ptrdiff_t)get_proc("glGetProgramInfoLog");
  if (glow_glGetProgramInfoLog == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramInfoLog\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramInfoLog\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)(ptrdiff_t)get_proc("glUniformMatrix2fv");
  if (glow_glUniformMatrix2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix2fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)(ptrdiff_t)get_proc("glVertexAttrib4f");
  if (glow_glVertexAttrib4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib4f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteProgram = (PFNGLDELETEPROGRAMPROC)(ptrdiff_t)get_proc("glDeleteProgram");
  if (glow_glDeleteProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetBufferParameteriv");
  if (glow_glGetBufferParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBufferParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBufferParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform1f = (PFNGLUNIFORM1FPROC)(ptrdiff_t)get_proc("glUniform1f");
  if (glow_glUniform1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetString = (PFNGLGETSTRINGPROC)(ptrdiff_t)get_proc("glGetString");
  if (glow_glGetString == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetString\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetString\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)(ptrdiff_t)get_proc("glGetUniformLocation");
  if (glow_glGetUniformLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformLocation\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)(ptrdiff_t)get_proc("glIsRenderbuffer");
  if (glow_glIsRenderbuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsRenderbuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsRenderbuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glAttachShader = (PFNGLATTACHSHADERPROC)(ptrdiff_t)get_proc("glAttachShader");
  if (glow_glAttachShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glAttachShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glAttachShader\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)(ptrdiff_t)get_proc("glBufferSubData");
  if (glow_glBufferSubData == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBufferSubData\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBufferSubData\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)(ptrdiff_t)get_proc("glCopyTexImage2D");
  if (glow_glCopyTexImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyTexImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyTexImage2D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)(ptrdiff_t)get_proc("glDeleteBuffers");
  if (glow_glDeleteBuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteBuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteBuffers\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)(ptrdiff_t)get_proc("glGetShaderInfoLog");
  if (glow_glGetShaderInfoLog == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetShaderInfoLog\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetShaderInfoLog\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)(ptrdiff_t)get_proc("glBlendEquationSeparate");
  if (glow_glBlendEquationSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendEquationSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendEquationSeparate\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDrawElements = (PFNGLDRAWELEMENTSPROC)(ptrdiff_t)get_proc("glDrawElements");
  if (glow_glDrawElements == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElements\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElements\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEnable = (PFNGLENABLEPROC)(ptrdiff_t)get_proc("glEnable");
  if (glow_glEnable == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnable\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnable\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)(ptrdiff_t)get_proc("glGetActiveUniform");
  if (glow_glGetActiveUniform == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetActiveUniform\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetActiveUniform\n");
#endif
    unresolved_count += 1;
  } 
  glow_glStencilMask = (PFNGLSTENCILMASKPROC)(ptrdiff_t)get_proc("glStencilMask");
  if (glow_glStencilMask == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilMask\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilMask\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform3fv = (PFNGLUNIFORM3FVPROC)(ptrdiff_t)get_proc("glUniform3fv");
  if (glow_glUniform3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform3i = (PFNGLUNIFORM3IPROC)(ptrdiff_t)get_proc("glUniform3i");
  if (glow_glUniform3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)(ptrdiff_t)get_proc("glBindFramebuffer");
  if (glow_glBindFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindFramebuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)(ptrdiff_t)get_proc("glCopyTexSubImage2D");
  if (glow_glCopyTexSubImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyTexSubImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyTexSubImage2D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsTexture = (PFNGLISTEXTUREPROC)(ptrdiff_t)get_proc("glIsTexture");
  if (glow_glIsTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsTexture\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)(ptrdiff_t)get_proc("glPolygonOffset");
  if (glow_glPolygonOffset == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPolygonOffset\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPolygonOffset\n");
#endif
    unresolved_count += 1;
  } 
  return unresolved_count;
}


void glow_set_pre_callback(glow_debug_proc_t callback) {
  glow_pre_callback_ = callback;
}

void glow_set_post_callback(glow_debug_proc_t callback) {
  glow_post_callback_ = callback;
}

#endif  /* GLOW_IMPLEMENTATION */
