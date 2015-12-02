/*
 * glow-1.0.0: public-domain OpenGL function loader
 *
 * This file was generated with glow https://github.com/jshrake/glow
 * 
 * Version: 1.0.0
 * Date: 2015-11-27 09:08:25.676504087 -0800 PST
 * Language: C
 * Specification: 1.0
 * API: gles1
 * Profile: core
 * Command-line: glow --api="gles1" --spec="1.0" --profile="core" --debug=true
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
#define GL_VERSION_ES_CM_1_0

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
typedef khronos_int32_t GLclampx;
typedef khronos_int8_t GLbyte;
typedef khronos_uint8_t GLubyte;
typedef khronos_float_t GLfloat;
typedef khronos_float_t GLclampf;
typedef khronos_int32_t GLfixed;
typedef khronos_int64_t GLint64;
typedef khronos_uint64_t GLuint64;
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
#define GL_LIGHT5 0x4005
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_BLEND_SRC 0x0BE1
#define GL_VERTEX_ARRAY_SIZE 0x807A
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE26 0x84DA
#define GL_TRIANGLE_FAN 0x0006
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_OUT_OF_MEMORY 0x0505
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_SRC2_RGB 0x8582
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_VERSION 0x1F02
#define GL_INVALID_VALUE 0x0501
#define GL_CULL_FACE_MODE 0x0B45
#define GL_NORMAL_ARRAY_STRIDE 0x807F
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE9 0x84C9
#define GL_SRC1_ALPHA 0x8589
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_TEXTURE17 0x84D1
#define GL_SRC0_RGB 0x8580
#define GL_GREATER 0x0204
#define GL_TEXTURE_2D 0x0DE1
#define GL_FOG_MODE 0x0B65
#define GL_CURRENT_COLOR 0x0B00
#define GL_DEPTH_RANGE 0x0B70
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_TEXTURE_MATRIX 0x0BA8
#define GL_UNSIGNED_BYTE 0x1401
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE15 0x84CF
#define GL_VERSION_ES_CL_1_1 1
#define GL_TRIANGLES 0x0004
#define GL_ALWAYS 0x0207
#define GL_COLOR_ARRAY_SIZE 0x8081
#define GL_NAND 0x150E
#define GL_GENERATE_MIPMAP 0x8191
#define GL_BLEND 0x0BE2
#define GL_TEXTURE_STACK_DEPTH 0x0BA5
#define GL_MODELVIEW_MATRIX 0x0BA6
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_RGB 0x1907
#define GL_ZERO 0
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_BACK 0x0405
#define GL_SMOOTH 0x1D01
#define GL_AMBIENT_AND_DIFFUSE 0x1602
#define GL_DECR 0x1E03
#define GL_NEAREST 0x2600
#define GL_TEXTURE14 0x84CE
#define GL_COLOR_ARRAY 0x8076
#define GL_AMBIENT 0x1200
#define GL_CLEAR 0x1500
#define GL_FLOAT 0x1406
#define GL_AND 0x1501
#define GL_OR_REVERSE 0x150B
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE13 0x84CD
#define GL_DST_ALPHA 0x0304
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_SPECULAR 0x1202
#define GL_REPEAT 0x2901
#define GL_INTERPOLATE 0x8575
#define GL_EXP2 0x0801
#define GL_FOG_END 0x0B64
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_DEPTH_BITS 0x0D56
#define GL_BYTE 0x1400
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_VIEWPORT 0x0BA2
#define GL_LIGHT2 0x4002
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_OR 0x1507
#define GL_TEXTURE23 0x84D7
#define GL_MULTISAMPLE 0x809D
#define GL_NICEST 0x1102
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE7 0x84C7
#define GL_ONE 1
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_RESCALE_NORMAL 0x803A
#define GL_LUMINANCE 0x1909
#define GL_TEXTURE18 0x84D2
#define GL_SUBTRACT 0x84E7
#define GL_EQUAL 0x0202
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_ARRAY_BUFFER 0x8892
#define GL_SHININESS 0x1601
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_TEXTURE16 0x84D0
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_RGBA 0x1908
#define GL_GREEN_BITS 0x0D53
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_AND_INVERTED 0x1504
#define GL_INVALID_OPERATION 0x0502
#define GL_STACK_UNDERFLOW 0x0504
#define GL_POINT_SIZE_MIN 0x8126
#define GL_PROJECTION 0x1701
#define GL_TEXTURE12 0x84CC
#define GL_COMBINE 0x8570
#define GL_RGB_SCALE 0x8573
#define GL_CLIP_PLANE0 0x3000
#define GL_INVALID_ENUM 0x0500
#define GL_OR_INVERTED 0x150D
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE20 0x84D4
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_COLOR_ARRAY_STRIDE 0x8083
#define GL_REPLACE 0x1E01
#define GL_OPERAND0_ALPHA 0x8598
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_MAX_LIGHTS 0x0D31
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_CONSTANT 0x8576
#define GL_ALPHA_SCALE 0x0D1C
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_COMBINE_RGB 0x8571
#define GL_VERSION_ES_CL_1_0 1
#define GL_POINT_SMOOTH 0x0B10
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_VENDOR 0x1F00
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_CLIP_PLANE1 0x3001
#define GL_LIGHTING 0x0B50
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
#define GL_TEXTURE22 0x84D6
#define GL_LIGHT1 0x4001
#define GL_NEVER 0x0200
#define GL_NO_ERROR 0
#define GL_FOG_COLOR 0x0B66
#define GL_CULL_FACE 0x0B44
#define GL_MATRIX_MODE 0x0BA0
#define GL_DIFFUSE 0x1201
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_LESS 0x0201
#define GL_SRC_ALPHA 0x0302
#define GL_COMBINE_ALPHA 0x8572
#define GL_STENCIL_FUNC 0x0B92
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_NORMAL_ARRAY_TYPE 0x807E
#define GL_DOT3_RGB 0x86AE
#define GL_STENCIL_REF 0x0B97
#define GL_SAMPLES 0x80A9
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_EMISSION 0x1600
#define GL_TEXTURE10 0x84CA
#define GL_LIGHT7 0x4007
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_CLIP_PLANE4 0x3004
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_STENCIL_FAIL 0x0B94
#define GL_EQUIV 0x1509
#define GL_COPY_INVERTED 0x150C
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_CURRENT_NORMAL 0x0B02
#define GL_NOR 0x1508
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_TEXTURE3 0x84C3
#define GL_BUFFER_USAGE 0x8765
#define GL_DOT3_RGBA 0x86AF
#define GL_CCW 0x0901
#define GL_FRONT_FACE 0x0B46
#define GL_SHORT 0x1402
#define GL_TEXTURE30 0x84DE
#define GL_SRC0_ALPHA 0x8588
#define GL_POINT_SIZE 0x0B11
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_OPERAND1_RGB 0x8591
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_TEXTURE_ENV 0x2300
#define GL_TEXTURE1 0x84C1
#define GL_POINTS 0x0000
#define GL_FRONT 0x0404
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_TEXTURE27 0x84DB
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_SRC1_RGB 0x8581
#define GL_FOG 0x0B60
#define GL_FOG_START 0x0B63
#define GL_COLOR_ARRAY_TYPE 0x8082
#define GL_VERTEX_ARRAY 0x8074
#define GL_PROJECTION_MATRIX 0x0BA7
#define GL_LINE_WIDTH 0x0B21
#define GL_BLEND_DST 0x0BE0
#define GL_BUFFER_SIZE 0x8764
#define GL_SPOT_EXPONENT 0x1205
#define GL_TEXTURE 0x1702
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_DITHER 0x0BD0
#define GL_NORMALIZE 0x0BA1
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_INCR 0x1E02
#define GL_CLIP_PLANE2 0x3002
#define GL_EXP 0x0800
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_TEXTURE25 0x84D9
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND2_ALPHA 0x859A
#define GL_TRIANGLE_STRIP 0x0005
#define GL_NOOP 0x1505
#define GL_EXTENSIONS 0x1F03
#define GL_POSITION 0x1203
#define GL_COPY 0x1503
#define GL_FLAT 0x1D00
#define GL_ADD_SIGNED 0x8574
#define GL_OPERAND0_RGB 0x8590
#define GL_LINE_STRIP 0x0003
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_VERTEX_ARRAY_TYPE 0x807B
#define GL_MAX_CLIP_PLANES 0x0D32
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_ALPHA 0x1906
#define GL_TEXTURE8 0x84C8
#define GL_CLIP_PLANE3 0x3003
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_SRC2_ALPHA 0x858A
#define GL_LINES 0x0001
#define GL_ALPHA_TEST 0x0BC0
#define GL_FIXED 0x140C
#define GL_STENCIL_BITS 0x0D57
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_XOR 0x1506
#define GL_MODULATE 0x2100
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_GEQUAL 0x0206
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_BLUE_BITS 0x0D54
#define GL_STATIC_DRAW 0x88E4
#define GL_OPERAND1_ALPHA 0x8599
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_DONT_CARE 0x1100
#define GL_UNSIGNED_SHORT 0x1403
#define GL_FOG_HINT 0x0C54
#define GL_DECAL 0x2101
#define GL_TEXTURE4 0x84C4
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
#define GL_SHADE_MODEL 0x0B54
#define GL_DEPTH_FUNC 0x0B74
#define GL_FRONT_AND_BACK 0x0408
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_VERTEX_ARRAY_STRIDE 0x807C
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_FASTEST 0x1101
#define GL_RENDERER 0x1F01
#define GL_TEXTURE29 0x84DD
#define GL_LIGHT0 0x4000
#define GL_LINE_LOOP 0x0002
#define GL_FOG_DENSITY 0x0B62
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_TEXTURE24 0x84D8
#define GL_LINE_SMOOTH 0x0B20
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_LIGHT4 0x4004
#define GL_STENCIL_TEST 0x0B90
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_SPOT_CUTOFF 0x1206
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_RED_BITS 0x0D52
#define GL_AND_REVERSE 0x1502
#define GL_MODELVIEW 0x1700
#define GL_DST_COLOR 0x0306
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_SPOT_DIRECTION 0x1204
#define GL_LINEAR_ATTENUATION 0x1208
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_ADD 0x0104
#define GL_TEXTURE19 0x84D3
#define GL_CLIP_PLANE5 0x3005
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_POINT_SIZE_MAX 0x8127
#define GL_LINEAR 0x2601
#define GL_VERSION_ES_CM_1_1 1
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_LIGHT3 0x4003
#define GL_KEEP 0x1E00
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_NOTEQUAL 0x0205
#define GL_COLOR_MATERIAL 0x0B57
#define GL_CW 0x0900
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_SET 0x150F
#define GL_TEXTURE28 0x84DC
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_STACK_OVERFLOW 0x0503
#define GL_LIGHT6 0x4006
#define GL_LEQUAL 0x0203
#define GL_SRC_COLOR 0x0300
#define GL_ALPHA_BITS 0x0D55
#define GL_INVERT 0x150A
#define GL_TEXTURE5 0x84C5
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_SCISSOR_TEST 0x0C11
#define GL_NORMAL_ARRAY 0x8075
#define GL_SCISSOR_BOX 0x0C10

/*
 * ---------------------------
 * Commands
 * ---------------------------
 */

typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
GLOWDEF PFNGLACTIVETEXTUREPROC glow_glActiveTexture;
typedef void (APIENTRYP PFNGLGETCLIPPLANEXPROC)(GLenum plane, GLfixed *equation);
GLOWDEF PFNGLGETCLIPPLANEXPROC glow_glGetClipPlanex;
typedef GLubyte (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
GLOWDEF PFNGLGETSTRINGPROC glow_glGetString;
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
GLOWDEF PFNGLISENABLEDPROC glow_glIsEnabled;
typedef void (APIENTRYP PFNGLSHADEMODELPROC)(GLenum mode);
GLOWDEF PFNGLSHADEMODELPROC glow_glShadeModel;
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLTEXIMAGE2DPROC glow_glTexImage2D;
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLVIEWPORTPROC glow_glViewport;
typedef void (APIENTRYP PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETLIGHTFVPROC glow_glGetLightfv;
typedef void (APIENTRYP PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLMATERIALFVPROC glow_glMaterialfv;
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)();
GLOWDEF PFNGLGETERRORPROC glow_glGetError;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERXVPROC)(GLenum target, GLenum pname, GLfixed *params);
GLOWDEF PFNGLGETTEXPARAMETERXVPROC glow_glGetTexParameterxv;
typedef void (APIENTRYP PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLOWDEF PFNGLCOLOR4FPROC glow_glColor4f;
typedef void (APIENTRYP PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETMATERIALFVPROC glow_glGetMaterialfv;
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLOWDEF PFNGLCOLORMASKPROC glow_glColorMask;
typedef void (APIENTRYP PFNGLMULTITEXCOORD4XPROC)(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
GLOWDEF PFNGLMULTITEXCOORD4XPROC glow_glMultiTexCoord4x;
typedef void (APIENTRYP PFNGLTRANSLATEXPROC)(GLfixed x, GLfixed y, GLfixed z);
GLOWDEF PFNGLTRANSLATEXPROC glow_glTranslatex;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETTEXPARAMETERFVPROC glow_glGetTexParameterfv;
typedef void (APIENTRYP PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
GLOWDEF PFNGLSCALEFPROC glow_glScalef;
typedef void (APIENTRYP PFNGLORTHOFPROC)(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
GLOWDEF PFNGLORTHOFPROC glow_glOrthof;
typedef void (APIENTRYP PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLOWDEF PFNGLCOLORPOINTERPROC glow_glColorPointer;
typedef void (APIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, void **params);
GLOWDEF PFNGLGETPOINTERVPROC glow_glGetPointerv;
typedef void (APIENTRYP PFNGLPOINTPARAMETERXVPROC)(GLenum pname, const GLfixed *params);
GLOWDEF PFNGLPOINTPARAMETERXVPROC glow_glPointParameterxv;
typedef void (APIENTRYP PFNGLLOADIDENTITYPROC)();
GLOWDEF PFNGLLOADIDENTITYPROC glow_glLoadIdentity;
typedef void (APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
GLOWDEF PFNGLLOGICOPPROC glow_glLogicOp;
typedef void (APIENTRYP PFNGLMATRIXMODEPROC)(GLenum mode);
GLOWDEF PFNGLMATRIXMODEPROC glow_glMatrixMode;
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETBUFFERPARAMETERIVPROC glow_glGetBufferParameteriv;
typedef void (APIENTRYP PFNGLGETMATERIALXVPROC)(GLenum face, GLenum pname, GLfixed *params);
GLOWDEF PFNGLGETMATERIALXVPROC glow_glGetMaterialxv;
typedef void (APIENTRYP PFNGLPOPMATRIXPROC)();
GLOWDEF PFNGLPOPMATRIXPROC glow_glPopMatrix;
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
GLOWDEF PFNGLDELETEBUFFERSPROC glow_glDeleteBuffers;
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLOWDEF PFNGLCLEARCOLORPROC glow_glClearColor;
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
GLOWDEF PFNGLDEPTHRANGEFPROC glow_glDepthRangef;
typedef void (APIENTRYP PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
GLOWDEF PFNGLMATERIALFPROC glow_glMaterialf;
typedef void (APIENTRYP PFNGLMULTMATRIXFPROC)(const GLfloat *m);
GLOWDEF PFNGLMULTMATRIXFPROC glow_glMultMatrixf;
typedef void (APIENTRYP PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
GLOWDEF PFNGLNORMAL3FPROC glow_glNormal3f;
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
GLOWDEF PFNGLPOLYGONOFFSETPROC glow_glPolygonOffset;
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
GLOWDEF PFNGLCLEARSTENCILPROC glow_glClearStencil;
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
GLOWDEF PFNGLDEPTHFUNCPROC glow_glDepthFunc;
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
GLOWDEF PFNGLDISABLEPROC glow_glDisable;
typedef void (APIENTRYP PFNGLLIGHTXPROC)(GLenum light, GLenum pname, GLfixed param);
GLOWDEF PFNGLLIGHTXPROC glow_glLightx;
typedef void (APIENTRYP PFNGLALPHAFUNCXPROC)(GLenum func, GLfixed ref);
GLOWDEF PFNGLALPHAFUNCXPROC glow_glAlphaFuncx;
typedef void (APIENTRYP PFNGLCOLOR4XPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
GLOWDEF PFNGLCOLOR4XPROC glow_glColor4x;
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLOWDEF PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glow_glCompressedTexSubImage2D;
typedef void (APIENTRYP PFNGLTEXPARAMETERXVPROC)(GLenum target, GLenum pname, const GLfixed *params);
GLOWDEF PFNGLTEXPARAMETERXVPROC glow_glTexParameterxv;
typedef void (APIENTRYP PFNGLCLIPPLANEXPROC)(GLenum plane, const GLfixed *equation);
GLOWDEF PFNGLCLIPPLANEXPROC glow_glClipPlanex;
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLOWDEF PFNGLCOPYTEXIMAGE2DPROC glow_glCopyTexImage2D;
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
GLOWDEF PFNGLFRONTFACEPROC glow_glFrontFace;
typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
GLOWDEF PFNGLGENBUFFERSPROC glow_glGenBuffers;
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
GLOWDEF PFNGLSTENCILOPPROC glow_glStencilOp;
typedef void (APIENTRYP PFNGLTEXPARAMETERXPROC)(GLenum target, GLenum pname, GLfixed param);
GLOWDEF PFNGLTEXPARAMETERXPROC glow_glTexParameterx;
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLOWDEF PFNGLTEXPARAMETERIVPROC glow_glTexParameteriv;
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLOWDEF PFNGLBUFFERSUBDATAPROC glow_glBufferSubData;
typedef void (APIENTRYP PFNGLCLEARCOLORXPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
GLOWDEF PFNGLCLEARCOLORXPROC glow_glClearColorx;
typedef void (APIENTRYP PFNGLPUSHMATRIXPROC)();
GLOWDEF PFNGLPUSHMATRIXPROC glow_glPushMatrix;
typedef void (APIENTRYP PFNGLTEXENVXPROC)(GLenum target, GLenum pname, GLfixed param);
GLOWDEF PFNGLTEXENVXPROC glow_glTexEnvx;
typedef void (APIENTRYP PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat *params);
GLOWDEF PFNGLLIGHTMODELFVPROC glow_glLightModelfv;
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat *data);
GLOWDEF PFNGLGETFLOATVPROC glow_glGetFloatv;
typedef void (APIENTRYP PFNGLLOADMATRIXFPROC)(const GLfloat *m);
GLOWDEF PFNGLLOADMATRIXFPROC glow_glLoadMatrixf;
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
GLOWDEF PFNGLPOINTPARAMETERFPROC glow_glPointParameterf;
typedef void (APIENTRYP PFNGLPOLYGONOFFSETXPROC)(GLfixed factor, GLfixed units);
GLOWDEF PFNGLPOLYGONOFFSETXPROC glow_glPolygonOffsetx;
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLOWDEF PFNGLCOMPRESSEDTEXIMAGE2DPROC glow_glCompressedTexImage2D;
typedef void (APIENTRYP PFNGLLIGHTMODELXPROC)(GLenum pname, GLfixed param);
GLOWDEF PFNGLLIGHTMODELXPROC glow_glLightModelx;
typedef void (APIENTRYP PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLOWDEF PFNGLVERTEXPOINTERPROC glow_glVertexPointer;
typedef void (APIENTRYP PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
GLOWDEF PFNGLNORMALPOINTERPROC glow_glNormalPointer;
typedef void (APIENTRYP PFNGLLIGHTMODELXVPROC)(GLenum pname, const GLfixed *param);
GLOWDEF PFNGLLIGHTMODELXVPROC glow_glLightModelxv;
typedef void (APIENTRYP PFNGLFRUSTUMFPROC)(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
GLOWDEF PFNGLFRUSTUMFPROC glow_glFrustumf;
typedef void (APIENTRYP PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
GLOWDEF PFNGLLIGHTMODELFPROC glow_glLightModelf;
typedef void (APIENTRYP PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLTEXENVFVPROC glow_glTexEnvfv;
typedef void (APIENTRYP PFNGLDEPTHRANGEXPROC)(GLfixed n, GLfixed f);
GLOWDEF PFNGLDEPTHRANGEXPROC glow_glDepthRangex;
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
GLOWDEF PFNGLENABLEPROC glow_glEnable;
typedef void (APIENTRYP PFNGLFINISHPROC)();
GLOWDEF PFNGLFINISHPROC glow_glFinish;
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
GLOWDEF PFNGLHINTPROC glow_glHint;
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLOWDEF PFNGLREADPIXELSPROC glow_glReadPixels;
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
GLOWDEF PFNGLSTENCILMASKPROC glow_glStencilMask;
typedef void (APIENTRYP PFNGLGETLIGHTXVPROC)(GLenum light, GLenum pname, GLfixed *params);
GLOWDEF PFNGLGETLIGHTXVPROC glow_glGetLightxv;
typedef void (APIENTRYP PFNGLORTHOXPROC)(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
GLOWDEF PFNGLORTHOXPROC glow_glOrthox;
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
GLOWDEF PFNGLPIXELSTOREIPROC glow_glPixelStorei;
typedef void (APIENTRYP PFNGLROTATEXPROC)(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
GLOWDEF PFNGLROTATEXPROC glow_glRotatex;
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEXPROC)(GLclampx value, GLboolean invert);
GLOWDEF PFNGLSAMPLECOVERAGEXPROC glow_glSampleCoveragex;
typedef void (APIENTRYP PFNGLSCALEXPROC)(GLfixed x, GLfixed y, GLfixed z);
GLOWDEF PFNGLSCALEXPROC glow_glScalex;
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLSCISSORPROC glow_glScissor;
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLOWDEF PFNGLMULTITEXCOORD4FPROC glow_glMultiTexCoord4f;
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat *params);
GLOWDEF PFNGLPOINTPARAMETERFVPROC glow_glPointParameterfv;
typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLOWDEF PFNGLBUFFERDATAPROC glow_glBufferData;
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
GLOWDEF PFNGLTEXPARAMETERIPROC glow_glTexParameteri;
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREPROC)(GLenum texture);
GLOWDEF PFNGLCLIENTACTIVETEXTUREPROC glow_glClientActiveTexture;
typedef void (APIENTRYP PFNGLMULTMATRIXXPROC)(const GLfixed *m);
GLOWDEF PFNGLMULTMATRIXXPROC glow_glMultMatrixx;
typedef void (APIENTRYP PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
GLOWDEF PFNGLLIGHTFPROC glow_glLightf;
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
GLOWDEF PFNGLLINEWIDTHPROC glow_glLineWidth;
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
GLOWDEF PFNGLCLEARPROC glow_glClear;
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEPROC)(GLenum array);
GLOWDEF PFNGLDISABLECLIENTSTATEPROC glow_glDisableClientState;
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint *data);
GLOWDEF PFNGLGETINTEGERVPROC glow_glGetIntegerv;
typedef void (APIENTRYP PFNGLMATERIALXPROC)(GLenum face, GLenum pname, GLfixed param);
GLOWDEF PFNGLMATERIALXPROC glow_glMaterialx;
typedef void (APIENTRYP PFNGLALPHAFUNCPROC)(GLenum func, GLfloat ref);
GLOWDEF PFNGLALPHAFUNCPROC glow_glAlphaFunc;
typedef void (APIENTRYP PFNGLCLIPPLANEFPROC)(GLenum p, const GLfloat *eqn);
GLOWDEF PFNGLCLIPPLANEFPROC glow_glClipPlanef;
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
GLOWDEF PFNGLSTENCILFUNCPROC glow_glStencilFunc;
typedef void (APIENTRYP PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLLIGHTFVPROC glow_glLightfv;
typedef void (APIENTRYP PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);
GLOWDEF PFNGLTRANSLATEFPROC glow_glTranslatef;
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
GLOWDEF PFNGLGENTEXTURESPROC glow_glGenTextures;
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
GLOWDEF PFNGLISBUFFERPROC glow_glIsBuffer;
typedef void (APIENTRYP PFNGLPOINTPARAMETERXPROC)(GLenum pname, GLfixed param);
GLOWDEF PFNGLPOINTPARAMETERXPROC glow_glPointParameterx;
typedef void (APIENTRYP PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLOWDEF PFNGLTEXENVIVPROC glow_glTexEnviv;
typedef void (APIENTRYP PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETTEXENVFVPROC glow_glGetTexEnvfv;
typedef void (APIENTRYP PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLOWDEF PFNGLROTATEFPROC glow_glRotatef;
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
GLOWDEF PFNGLTEXPARAMETERFPROC glow_glTexParameterf;
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
GLOWDEF PFNGLDRAWARRAYSPROC glow_glDrawArrays;
typedef void (APIENTRYP PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETTEXENVIVPROC glow_glGetTexEnviv;
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
GLOWDEF PFNGLISTEXTUREPROC glow_glIsTexture;
typedef void (APIENTRYP PFNGLMATERIALXVPROC)(GLenum face, GLenum pname, const GLfixed *param);
GLOWDEF PFNGLMATERIALXVPROC glow_glMaterialxv;
typedef void (APIENTRYP PFNGLGETCLIPPLANEFPROC)(GLenum plane, GLfloat *equation);
GLOWDEF PFNGLGETCLIPPLANEFPROC glow_glGetClipPlanef;
typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
GLOWDEF PFNGLBINDBUFFERPROC glow_glBindBuffer;
typedef void (APIENTRYP PFNGLGETFIXEDVPROC)(GLenum pname, GLfixed *params);
GLOWDEF PFNGLGETFIXEDVPROC glow_glGetFixedv;
typedef void (APIENTRYP PFNGLLIGHTXVPROC)(GLenum light, GLenum pname, const GLfixed *params);
GLOWDEF PFNGLLIGHTXVPROC glow_glLightxv;
typedef void (APIENTRYP PFNGLLOADMATRIXXPROC)(const GLfixed *m);
GLOWDEF PFNGLLOADMATRIXXPROC glow_glLoadMatrixx;
typedef void (APIENTRYP PFNGLFOGFPROC)(GLenum pname, GLfloat param);
GLOWDEF PFNGLFOGFPROC glow_glFogf;
typedef void (APIENTRYP PFNGLFOGFVPROC)(GLenum pname, const GLfloat *params);
GLOWDEF PFNGLFOGFVPROC glow_glFogfv;
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLTEXPARAMETERFVPROC glow_glTexParameterfv;
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
GLOWDEF PFNGLDEPTHMASKPROC glow_glDepthMask;
typedef void (APIENTRYP PFNGLFLUSHPROC)();
GLOWDEF PFNGLFLUSHPROC glow_glFlush;
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean *data);
GLOWDEF PFNGLGETBOOLEANVPROC glow_glGetBooleanv;
typedef void (APIENTRYP PFNGLPOINTSIZEXPROC)(GLfixed size);
GLOWDEF PFNGLPOINTSIZEXPROC glow_glPointSizex;
typedef void (APIENTRYP PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
GLOWDEF PFNGLTEXENVFPROC glow_glTexEnvf;
typedef void (APIENTRYP PFNGLNORMAL3XPROC)(GLfixed nx, GLfixed ny, GLfixed nz);
GLOWDEF PFNGLNORMAL3XPROC glow_glNormal3x;
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
GLOWDEF PFNGLBLENDFUNCPROC glow_glBlendFunc;
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
GLOWDEF PFNGLSAMPLECOVERAGEPROC glow_glSampleCoverage;
typedef void (APIENTRYP PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
GLOWDEF PFNGLTEXENVIPROC glow_glTexEnvi;
typedef void (APIENTRYP PFNGLCLEARDEPTHXPROC)(GLfixed depth);
GLOWDEF PFNGLCLEARDEPTHXPROC glow_glClearDepthx;
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLOWDEF PFNGLTEXCOORDPOINTERPROC glow_glTexCoordPointer;
typedef void (APIENTRYP PFNGLFRUSTUMXPROC)(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
GLOWDEF PFNGLFRUSTUMXPROC glow_glFrustumx;
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
GLOWDEF PFNGLCLEARDEPTHFPROC glow_glClearDepthf;
typedef void (APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
GLOWDEF PFNGLPOINTSIZEPROC glow_glPointSize;
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLCOPYTEXSUBIMAGE2DPROC glow_glCopyTexSubImage2D;
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
GLOWDEF PFNGLDRAWELEMENTSPROC glow_glDrawElements;
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEPROC)(GLenum array);
GLOWDEF PFNGLENABLECLIENTSTATEPROC glow_glEnableClientState;
typedef void (APIENTRYP PFNGLFOGXPROC)(GLenum pname, GLfixed param);
GLOWDEF PFNGLFOGXPROC glow_glFogx;
typedef void (APIENTRYP PFNGLFOGXVPROC)(GLenum pname, const GLfixed *param);
GLOWDEF PFNGLFOGXVPROC glow_glFogxv;
typedef void (APIENTRYP PFNGLGETTEXENVXVPROC)(GLenum target, GLenum pname, GLfixed *params);
GLOWDEF PFNGLGETTEXENVXVPROC glow_glGetTexEnvxv;
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLTEXSUBIMAGE2DPROC glow_glTexSubImage2D;
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
GLOWDEF PFNGLBINDTEXTUREPROC glow_glBindTexture;
typedef void (APIENTRYP PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
GLOWDEF PFNGLCOLOR4UBPROC glow_glColor4ub;
typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
GLOWDEF PFNGLCULLFACEPROC glow_glCullFace;
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
GLOWDEF PFNGLDELETETEXTURESPROC glow_glDeleteTextures;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETTEXPARAMETERIVPROC glow_glGetTexParameteriv;
typedef void (APIENTRYP PFNGLLINEWIDTHXPROC)(GLfixed width);
GLOWDEF PFNGLLINEWIDTHXPROC glow_glLineWidthx;
typedef void (APIENTRYP PFNGLTEXENVXVPROC)(GLenum target, GLenum pname, const GLfixed *params);
GLOWDEF PFNGLTEXENVXVPROC glow_glTexEnvxv;


#ifndef GLOW_DEBUG

#define glActiveTexture glow_glActiveTexture
#define glGetClipPlanex glow_glGetClipPlanex
#define glGetString glow_glGetString
#define glIsEnabled glow_glIsEnabled
#define glShadeModel glow_glShadeModel
#define glTexImage2D glow_glTexImage2D
#define glViewport glow_glViewport
#define glGetLightfv glow_glGetLightfv
#define glMaterialfv glow_glMaterialfv
#define glGetError glow_glGetError
#define glGetTexParameterxv glow_glGetTexParameterxv
#define glColor4f glow_glColor4f
#define glGetMaterialfv glow_glGetMaterialfv
#define glColorMask glow_glColorMask
#define glMultiTexCoord4x glow_glMultiTexCoord4x
#define glTranslatex glow_glTranslatex
#define glGetTexParameterfv glow_glGetTexParameterfv
#define glScalef glow_glScalef
#define glOrthof glow_glOrthof
#define glColorPointer glow_glColorPointer
#define glGetPointerv glow_glGetPointerv
#define glPointParameterxv glow_glPointParameterxv
#define glLoadIdentity glow_glLoadIdentity
#define glLogicOp glow_glLogicOp
#define glMatrixMode glow_glMatrixMode
#define glGetBufferParameteriv glow_glGetBufferParameteriv
#define glGetMaterialxv glow_glGetMaterialxv
#define glPopMatrix glow_glPopMatrix
#define glDeleteBuffers glow_glDeleteBuffers
#define glClearColor glow_glClearColor
#define glDepthRangef glow_glDepthRangef
#define glMaterialf glow_glMaterialf
#define glMultMatrixf glow_glMultMatrixf
#define glNormal3f glow_glNormal3f
#define glPolygonOffset glow_glPolygonOffset
#define glClearStencil glow_glClearStencil
#define glDepthFunc glow_glDepthFunc
#define glDisable glow_glDisable
#define glLightx glow_glLightx
#define glAlphaFuncx glow_glAlphaFuncx
#define glColor4x glow_glColor4x
#define glCompressedTexSubImage2D glow_glCompressedTexSubImage2D
#define glTexParameterxv glow_glTexParameterxv
#define glClipPlanex glow_glClipPlanex
#define glCopyTexImage2D glow_glCopyTexImage2D
#define glFrontFace glow_glFrontFace
#define glGenBuffers glow_glGenBuffers
#define glStencilOp glow_glStencilOp
#define glTexParameterx glow_glTexParameterx
#define glTexParameteriv glow_glTexParameteriv
#define glBufferSubData glow_glBufferSubData
#define glClearColorx glow_glClearColorx
#define glPushMatrix glow_glPushMatrix
#define glTexEnvx glow_glTexEnvx
#define glLightModelfv glow_glLightModelfv
#define glGetFloatv glow_glGetFloatv
#define glLoadMatrixf glow_glLoadMatrixf
#define glPointParameterf glow_glPointParameterf
#define glPolygonOffsetx glow_glPolygonOffsetx
#define glCompressedTexImage2D glow_glCompressedTexImage2D
#define glLightModelx glow_glLightModelx
#define glVertexPointer glow_glVertexPointer
#define glNormalPointer glow_glNormalPointer
#define glLightModelxv glow_glLightModelxv
#define glFrustumf glow_glFrustumf
#define glLightModelf glow_glLightModelf
#define glTexEnvfv glow_glTexEnvfv
#define glDepthRangex glow_glDepthRangex
#define glEnable glow_glEnable
#define glFinish glow_glFinish
#define glHint glow_glHint
#define glReadPixels glow_glReadPixels
#define glStencilMask glow_glStencilMask
#define glGetLightxv glow_glGetLightxv
#define glOrthox glow_glOrthox
#define glPixelStorei glow_glPixelStorei
#define glRotatex glow_glRotatex
#define glSampleCoveragex glow_glSampleCoveragex
#define glScalex glow_glScalex
#define glScissor glow_glScissor
#define glMultiTexCoord4f glow_glMultiTexCoord4f
#define glPointParameterfv glow_glPointParameterfv
#define glBufferData glow_glBufferData
#define glTexParameteri glow_glTexParameteri
#define glClientActiveTexture glow_glClientActiveTexture
#define glMultMatrixx glow_glMultMatrixx
#define glLightf glow_glLightf
#define glLineWidth glow_glLineWidth
#define glClear glow_glClear
#define glDisableClientState glow_glDisableClientState
#define glGetIntegerv glow_glGetIntegerv
#define glMaterialx glow_glMaterialx
#define glAlphaFunc glow_glAlphaFunc
#define glClipPlanef glow_glClipPlanef
#define glStencilFunc glow_glStencilFunc
#define glLightfv glow_glLightfv
#define glTranslatef glow_glTranslatef
#define glGenTextures glow_glGenTextures
#define glIsBuffer glow_glIsBuffer
#define glPointParameterx glow_glPointParameterx
#define glTexEnviv glow_glTexEnviv
#define glGetTexEnvfv glow_glGetTexEnvfv
#define glRotatef glow_glRotatef
#define glTexParameterf glow_glTexParameterf
#define glDrawArrays glow_glDrawArrays
#define glGetTexEnviv glow_glGetTexEnviv
#define glIsTexture glow_glIsTexture
#define glMaterialxv glow_glMaterialxv
#define glGetClipPlanef glow_glGetClipPlanef
#define glBindBuffer glow_glBindBuffer
#define glGetFixedv glow_glGetFixedv
#define glLightxv glow_glLightxv
#define glLoadMatrixx glow_glLoadMatrixx
#define glFogf glow_glFogf
#define glFogfv glow_glFogfv
#define glTexParameterfv glow_glTexParameterfv
#define glDepthMask glow_glDepthMask
#define glFlush glow_glFlush
#define glGetBooleanv glow_glGetBooleanv
#define glPointSizex glow_glPointSizex
#define glTexEnvf glow_glTexEnvf
#define glNormal3x glow_glNormal3x
#define glBlendFunc glow_glBlendFunc
#define glSampleCoverage glow_glSampleCoverage
#define glTexEnvi glow_glTexEnvi
#define glClearDepthx glow_glClearDepthx
#define glTexCoordPointer glow_glTexCoordPointer
#define glFrustumx glow_glFrustumx
#define glClearDepthf glow_glClearDepthf
#define glPointSize glow_glPointSize
#define glCopyTexSubImage2D glow_glCopyTexSubImage2D
#define glDrawElements glow_glDrawElements
#define glEnableClientState glow_glEnableClientState
#define glFogx glow_glFogx
#define glFogxv glow_glFogxv
#define glGetTexEnvxv glow_glGetTexEnvxv
#define glTexSubImage2D glow_glTexSubImage2D
#define glBindTexture glow_glBindTexture
#define glColor4ub glow_glColor4ub
#define glCullFace glow_glCullFace
#define glDeleteTextures glow_glDeleteTextures
#define glGetTexParameteriv glow_glGetTexParameteriv
#define glLineWidthx glow_glLineWidthx
#define glTexEnvxv glow_glTexEnvxv

#endif /* GLOW_DEBUG */


#ifdef GLOW_DEBUG

GLOWDEF PFNGLACTIVETEXTUREPROC glow_debug_glActiveTexture;
#define glActiveTexture glow_debug_glActiveTexture
GLOWDEF PFNGLGETCLIPPLANEXPROC glow_debug_glGetClipPlanex;
#define glGetClipPlanex glow_debug_glGetClipPlanex
GLOWDEF PFNGLGETSTRINGPROC glow_debug_glGetString;
#define glGetString glow_debug_glGetString
GLOWDEF PFNGLISENABLEDPROC glow_debug_glIsEnabled;
#define glIsEnabled glow_debug_glIsEnabled
GLOWDEF PFNGLSHADEMODELPROC glow_debug_glShadeModel;
#define glShadeModel glow_debug_glShadeModel
GLOWDEF PFNGLTEXIMAGE2DPROC glow_debug_glTexImage2D;
#define glTexImage2D glow_debug_glTexImage2D
GLOWDEF PFNGLVIEWPORTPROC glow_debug_glViewport;
#define glViewport glow_debug_glViewport
GLOWDEF PFNGLGETLIGHTFVPROC glow_debug_glGetLightfv;
#define glGetLightfv glow_debug_glGetLightfv
GLOWDEF PFNGLMATERIALFVPROC glow_debug_glMaterialfv;
#define glMaterialfv glow_debug_glMaterialfv
GLOWDEF PFNGLGETERRORPROC glow_debug_glGetError;
#define glGetError glow_debug_glGetError
GLOWDEF PFNGLGETTEXPARAMETERXVPROC glow_debug_glGetTexParameterxv;
#define glGetTexParameterxv glow_debug_glGetTexParameterxv
GLOWDEF PFNGLCOLOR4FPROC glow_debug_glColor4f;
#define glColor4f glow_debug_glColor4f
GLOWDEF PFNGLGETMATERIALFVPROC glow_debug_glGetMaterialfv;
#define glGetMaterialfv glow_debug_glGetMaterialfv
GLOWDEF PFNGLCOLORMASKPROC glow_debug_glColorMask;
#define glColorMask glow_debug_glColorMask
GLOWDEF PFNGLMULTITEXCOORD4XPROC glow_debug_glMultiTexCoord4x;
#define glMultiTexCoord4x glow_debug_glMultiTexCoord4x
GLOWDEF PFNGLTRANSLATEXPROC glow_debug_glTranslatex;
#define glTranslatex glow_debug_glTranslatex
GLOWDEF PFNGLGETTEXPARAMETERFVPROC glow_debug_glGetTexParameterfv;
#define glGetTexParameterfv glow_debug_glGetTexParameterfv
GLOWDEF PFNGLSCALEFPROC glow_debug_glScalef;
#define glScalef glow_debug_glScalef
GLOWDEF PFNGLORTHOFPROC glow_debug_glOrthof;
#define glOrthof glow_debug_glOrthof
GLOWDEF PFNGLCOLORPOINTERPROC glow_debug_glColorPointer;
#define glColorPointer glow_debug_glColorPointer
GLOWDEF PFNGLGETPOINTERVPROC glow_debug_glGetPointerv;
#define glGetPointerv glow_debug_glGetPointerv
GLOWDEF PFNGLPOINTPARAMETERXVPROC glow_debug_glPointParameterxv;
#define glPointParameterxv glow_debug_glPointParameterxv
GLOWDEF PFNGLLOADIDENTITYPROC glow_debug_glLoadIdentity;
#define glLoadIdentity glow_debug_glLoadIdentity
GLOWDEF PFNGLLOGICOPPROC glow_debug_glLogicOp;
#define glLogicOp glow_debug_glLogicOp
GLOWDEF PFNGLMATRIXMODEPROC glow_debug_glMatrixMode;
#define glMatrixMode glow_debug_glMatrixMode
GLOWDEF PFNGLGETBUFFERPARAMETERIVPROC glow_debug_glGetBufferParameteriv;
#define glGetBufferParameteriv glow_debug_glGetBufferParameteriv
GLOWDEF PFNGLGETMATERIALXVPROC glow_debug_glGetMaterialxv;
#define glGetMaterialxv glow_debug_glGetMaterialxv
GLOWDEF PFNGLPOPMATRIXPROC glow_debug_glPopMatrix;
#define glPopMatrix glow_debug_glPopMatrix
GLOWDEF PFNGLDELETEBUFFERSPROC glow_debug_glDeleteBuffers;
#define glDeleteBuffers glow_debug_glDeleteBuffers
GLOWDEF PFNGLCLEARCOLORPROC glow_debug_glClearColor;
#define glClearColor glow_debug_glClearColor
GLOWDEF PFNGLDEPTHRANGEFPROC glow_debug_glDepthRangef;
#define glDepthRangef glow_debug_glDepthRangef
GLOWDEF PFNGLMATERIALFPROC glow_debug_glMaterialf;
#define glMaterialf glow_debug_glMaterialf
GLOWDEF PFNGLMULTMATRIXFPROC glow_debug_glMultMatrixf;
#define glMultMatrixf glow_debug_glMultMatrixf
GLOWDEF PFNGLNORMAL3FPROC glow_debug_glNormal3f;
#define glNormal3f glow_debug_glNormal3f
GLOWDEF PFNGLPOLYGONOFFSETPROC glow_debug_glPolygonOffset;
#define glPolygonOffset glow_debug_glPolygonOffset
GLOWDEF PFNGLCLEARSTENCILPROC glow_debug_glClearStencil;
#define glClearStencil glow_debug_glClearStencil
GLOWDEF PFNGLDEPTHFUNCPROC glow_debug_glDepthFunc;
#define glDepthFunc glow_debug_glDepthFunc
GLOWDEF PFNGLDISABLEPROC glow_debug_glDisable;
#define glDisable glow_debug_glDisable
GLOWDEF PFNGLLIGHTXPROC glow_debug_glLightx;
#define glLightx glow_debug_glLightx
GLOWDEF PFNGLALPHAFUNCXPROC glow_debug_glAlphaFuncx;
#define glAlphaFuncx glow_debug_glAlphaFuncx
GLOWDEF PFNGLCOLOR4XPROC glow_debug_glColor4x;
#define glColor4x glow_debug_glColor4x
GLOWDEF PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glow_debug_glCompressedTexSubImage2D;
#define glCompressedTexSubImage2D glow_debug_glCompressedTexSubImage2D
GLOWDEF PFNGLTEXPARAMETERXVPROC glow_debug_glTexParameterxv;
#define glTexParameterxv glow_debug_glTexParameterxv
GLOWDEF PFNGLCLIPPLANEXPROC glow_debug_glClipPlanex;
#define glClipPlanex glow_debug_glClipPlanex
GLOWDEF PFNGLCOPYTEXIMAGE2DPROC glow_debug_glCopyTexImage2D;
#define glCopyTexImage2D glow_debug_glCopyTexImage2D
GLOWDEF PFNGLFRONTFACEPROC glow_debug_glFrontFace;
#define glFrontFace glow_debug_glFrontFace
GLOWDEF PFNGLGENBUFFERSPROC glow_debug_glGenBuffers;
#define glGenBuffers glow_debug_glGenBuffers
GLOWDEF PFNGLSTENCILOPPROC glow_debug_glStencilOp;
#define glStencilOp glow_debug_glStencilOp
GLOWDEF PFNGLTEXPARAMETERXPROC glow_debug_glTexParameterx;
#define glTexParameterx glow_debug_glTexParameterx
GLOWDEF PFNGLTEXPARAMETERIVPROC glow_debug_glTexParameteriv;
#define glTexParameteriv glow_debug_glTexParameteriv
GLOWDEF PFNGLBUFFERSUBDATAPROC glow_debug_glBufferSubData;
#define glBufferSubData glow_debug_glBufferSubData
GLOWDEF PFNGLCLEARCOLORXPROC glow_debug_glClearColorx;
#define glClearColorx glow_debug_glClearColorx
GLOWDEF PFNGLPUSHMATRIXPROC glow_debug_glPushMatrix;
#define glPushMatrix glow_debug_glPushMatrix
GLOWDEF PFNGLTEXENVXPROC glow_debug_glTexEnvx;
#define glTexEnvx glow_debug_glTexEnvx
GLOWDEF PFNGLLIGHTMODELFVPROC glow_debug_glLightModelfv;
#define glLightModelfv glow_debug_glLightModelfv
GLOWDEF PFNGLGETFLOATVPROC glow_debug_glGetFloatv;
#define glGetFloatv glow_debug_glGetFloatv
GLOWDEF PFNGLLOADMATRIXFPROC glow_debug_glLoadMatrixf;
#define glLoadMatrixf glow_debug_glLoadMatrixf
GLOWDEF PFNGLPOINTPARAMETERFPROC glow_debug_glPointParameterf;
#define glPointParameterf glow_debug_glPointParameterf
GLOWDEF PFNGLPOLYGONOFFSETXPROC glow_debug_glPolygonOffsetx;
#define glPolygonOffsetx glow_debug_glPolygonOffsetx
GLOWDEF PFNGLCOMPRESSEDTEXIMAGE2DPROC glow_debug_glCompressedTexImage2D;
#define glCompressedTexImage2D glow_debug_glCompressedTexImage2D
GLOWDEF PFNGLLIGHTMODELXPROC glow_debug_glLightModelx;
#define glLightModelx glow_debug_glLightModelx
GLOWDEF PFNGLVERTEXPOINTERPROC glow_debug_glVertexPointer;
#define glVertexPointer glow_debug_glVertexPointer
GLOWDEF PFNGLNORMALPOINTERPROC glow_debug_glNormalPointer;
#define glNormalPointer glow_debug_glNormalPointer
GLOWDEF PFNGLLIGHTMODELXVPROC glow_debug_glLightModelxv;
#define glLightModelxv glow_debug_glLightModelxv
GLOWDEF PFNGLFRUSTUMFPROC glow_debug_glFrustumf;
#define glFrustumf glow_debug_glFrustumf
GLOWDEF PFNGLLIGHTMODELFPROC glow_debug_glLightModelf;
#define glLightModelf glow_debug_glLightModelf
GLOWDEF PFNGLTEXENVFVPROC glow_debug_glTexEnvfv;
#define glTexEnvfv glow_debug_glTexEnvfv
GLOWDEF PFNGLDEPTHRANGEXPROC glow_debug_glDepthRangex;
#define glDepthRangex glow_debug_glDepthRangex
GLOWDEF PFNGLENABLEPROC glow_debug_glEnable;
#define glEnable glow_debug_glEnable
GLOWDEF PFNGLFINISHPROC glow_debug_glFinish;
#define glFinish glow_debug_glFinish
GLOWDEF PFNGLHINTPROC glow_debug_glHint;
#define glHint glow_debug_glHint
GLOWDEF PFNGLREADPIXELSPROC glow_debug_glReadPixels;
#define glReadPixels glow_debug_glReadPixels
GLOWDEF PFNGLSTENCILMASKPROC glow_debug_glStencilMask;
#define glStencilMask glow_debug_glStencilMask
GLOWDEF PFNGLGETLIGHTXVPROC glow_debug_glGetLightxv;
#define glGetLightxv glow_debug_glGetLightxv
GLOWDEF PFNGLORTHOXPROC glow_debug_glOrthox;
#define glOrthox glow_debug_glOrthox
GLOWDEF PFNGLPIXELSTOREIPROC glow_debug_glPixelStorei;
#define glPixelStorei glow_debug_glPixelStorei
GLOWDEF PFNGLROTATEXPROC glow_debug_glRotatex;
#define glRotatex glow_debug_glRotatex
GLOWDEF PFNGLSAMPLECOVERAGEXPROC glow_debug_glSampleCoveragex;
#define glSampleCoveragex glow_debug_glSampleCoveragex
GLOWDEF PFNGLSCALEXPROC glow_debug_glScalex;
#define glScalex glow_debug_glScalex
GLOWDEF PFNGLSCISSORPROC glow_debug_glScissor;
#define glScissor glow_debug_glScissor
GLOWDEF PFNGLMULTITEXCOORD4FPROC glow_debug_glMultiTexCoord4f;
#define glMultiTexCoord4f glow_debug_glMultiTexCoord4f
GLOWDEF PFNGLPOINTPARAMETERFVPROC glow_debug_glPointParameterfv;
#define glPointParameterfv glow_debug_glPointParameterfv
GLOWDEF PFNGLBUFFERDATAPROC glow_debug_glBufferData;
#define glBufferData glow_debug_glBufferData
GLOWDEF PFNGLTEXPARAMETERIPROC glow_debug_glTexParameteri;
#define glTexParameteri glow_debug_glTexParameteri
GLOWDEF PFNGLCLIENTACTIVETEXTUREPROC glow_debug_glClientActiveTexture;
#define glClientActiveTexture glow_debug_glClientActiveTexture
GLOWDEF PFNGLMULTMATRIXXPROC glow_debug_glMultMatrixx;
#define glMultMatrixx glow_debug_glMultMatrixx
GLOWDEF PFNGLLIGHTFPROC glow_debug_glLightf;
#define glLightf glow_debug_glLightf
GLOWDEF PFNGLLINEWIDTHPROC glow_debug_glLineWidth;
#define glLineWidth glow_debug_glLineWidth
GLOWDEF PFNGLCLEARPROC glow_debug_glClear;
#define glClear glow_debug_glClear
GLOWDEF PFNGLDISABLECLIENTSTATEPROC glow_debug_glDisableClientState;
#define glDisableClientState glow_debug_glDisableClientState
GLOWDEF PFNGLGETINTEGERVPROC glow_debug_glGetIntegerv;
#define glGetIntegerv glow_debug_glGetIntegerv
GLOWDEF PFNGLMATERIALXPROC glow_debug_glMaterialx;
#define glMaterialx glow_debug_glMaterialx
GLOWDEF PFNGLALPHAFUNCPROC glow_debug_glAlphaFunc;
#define glAlphaFunc glow_debug_glAlphaFunc
GLOWDEF PFNGLCLIPPLANEFPROC glow_debug_glClipPlanef;
#define glClipPlanef glow_debug_glClipPlanef
GLOWDEF PFNGLSTENCILFUNCPROC glow_debug_glStencilFunc;
#define glStencilFunc glow_debug_glStencilFunc
GLOWDEF PFNGLLIGHTFVPROC glow_debug_glLightfv;
#define glLightfv glow_debug_glLightfv
GLOWDEF PFNGLTRANSLATEFPROC glow_debug_glTranslatef;
#define glTranslatef glow_debug_glTranslatef
GLOWDEF PFNGLGENTEXTURESPROC glow_debug_glGenTextures;
#define glGenTextures glow_debug_glGenTextures
GLOWDEF PFNGLISBUFFERPROC glow_debug_glIsBuffer;
#define glIsBuffer glow_debug_glIsBuffer
GLOWDEF PFNGLPOINTPARAMETERXPROC glow_debug_glPointParameterx;
#define glPointParameterx glow_debug_glPointParameterx
GLOWDEF PFNGLTEXENVIVPROC glow_debug_glTexEnviv;
#define glTexEnviv glow_debug_glTexEnviv
GLOWDEF PFNGLGETTEXENVFVPROC glow_debug_glGetTexEnvfv;
#define glGetTexEnvfv glow_debug_glGetTexEnvfv
GLOWDEF PFNGLROTATEFPROC glow_debug_glRotatef;
#define glRotatef glow_debug_glRotatef
GLOWDEF PFNGLTEXPARAMETERFPROC glow_debug_glTexParameterf;
#define glTexParameterf glow_debug_glTexParameterf
GLOWDEF PFNGLDRAWARRAYSPROC glow_debug_glDrawArrays;
#define glDrawArrays glow_debug_glDrawArrays
GLOWDEF PFNGLGETTEXENVIVPROC glow_debug_glGetTexEnviv;
#define glGetTexEnviv glow_debug_glGetTexEnviv
GLOWDEF PFNGLISTEXTUREPROC glow_debug_glIsTexture;
#define glIsTexture glow_debug_glIsTexture
GLOWDEF PFNGLMATERIALXVPROC glow_debug_glMaterialxv;
#define glMaterialxv glow_debug_glMaterialxv
GLOWDEF PFNGLGETCLIPPLANEFPROC glow_debug_glGetClipPlanef;
#define glGetClipPlanef glow_debug_glGetClipPlanef
GLOWDEF PFNGLBINDBUFFERPROC glow_debug_glBindBuffer;
#define glBindBuffer glow_debug_glBindBuffer
GLOWDEF PFNGLGETFIXEDVPROC glow_debug_glGetFixedv;
#define glGetFixedv glow_debug_glGetFixedv
GLOWDEF PFNGLLIGHTXVPROC glow_debug_glLightxv;
#define glLightxv glow_debug_glLightxv
GLOWDEF PFNGLLOADMATRIXXPROC glow_debug_glLoadMatrixx;
#define glLoadMatrixx glow_debug_glLoadMatrixx
GLOWDEF PFNGLFOGFPROC glow_debug_glFogf;
#define glFogf glow_debug_glFogf
GLOWDEF PFNGLFOGFVPROC glow_debug_glFogfv;
#define glFogfv glow_debug_glFogfv
GLOWDEF PFNGLTEXPARAMETERFVPROC glow_debug_glTexParameterfv;
#define glTexParameterfv glow_debug_glTexParameterfv
GLOWDEF PFNGLDEPTHMASKPROC glow_debug_glDepthMask;
#define glDepthMask glow_debug_glDepthMask
GLOWDEF PFNGLFLUSHPROC glow_debug_glFlush;
#define glFlush glow_debug_glFlush
GLOWDEF PFNGLGETBOOLEANVPROC glow_debug_glGetBooleanv;
#define glGetBooleanv glow_debug_glGetBooleanv
GLOWDEF PFNGLPOINTSIZEXPROC glow_debug_glPointSizex;
#define glPointSizex glow_debug_glPointSizex
GLOWDEF PFNGLTEXENVFPROC glow_debug_glTexEnvf;
#define glTexEnvf glow_debug_glTexEnvf
GLOWDEF PFNGLNORMAL3XPROC glow_debug_glNormal3x;
#define glNormal3x glow_debug_glNormal3x
GLOWDEF PFNGLBLENDFUNCPROC glow_debug_glBlendFunc;
#define glBlendFunc glow_debug_glBlendFunc
GLOWDEF PFNGLSAMPLECOVERAGEPROC glow_debug_glSampleCoverage;
#define glSampleCoverage glow_debug_glSampleCoverage
GLOWDEF PFNGLTEXENVIPROC glow_debug_glTexEnvi;
#define glTexEnvi glow_debug_glTexEnvi
GLOWDEF PFNGLCLEARDEPTHXPROC glow_debug_glClearDepthx;
#define glClearDepthx glow_debug_glClearDepthx
GLOWDEF PFNGLTEXCOORDPOINTERPROC glow_debug_glTexCoordPointer;
#define glTexCoordPointer glow_debug_glTexCoordPointer
GLOWDEF PFNGLFRUSTUMXPROC glow_debug_glFrustumx;
#define glFrustumx glow_debug_glFrustumx
GLOWDEF PFNGLCLEARDEPTHFPROC glow_debug_glClearDepthf;
#define glClearDepthf glow_debug_glClearDepthf
GLOWDEF PFNGLPOINTSIZEPROC glow_debug_glPointSize;
#define glPointSize glow_debug_glPointSize
GLOWDEF PFNGLCOPYTEXSUBIMAGE2DPROC glow_debug_glCopyTexSubImage2D;
#define glCopyTexSubImage2D glow_debug_glCopyTexSubImage2D
GLOWDEF PFNGLDRAWELEMENTSPROC glow_debug_glDrawElements;
#define glDrawElements glow_debug_glDrawElements
GLOWDEF PFNGLENABLECLIENTSTATEPROC glow_debug_glEnableClientState;
#define glEnableClientState glow_debug_glEnableClientState
GLOWDEF PFNGLFOGXPROC glow_debug_glFogx;
#define glFogx glow_debug_glFogx
GLOWDEF PFNGLFOGXVPROC glow_debug_glFogxv;
#define glFogxv glow_debug_glFogxv
GLOWDEF PFNGLGETTEXENVXVPROC glow_debug_glGetTexEnvxv;
#define glGetTexEnvxv glow_debug_glGetTexEnvxv
GLOWDEF PFNGLTEXSUBIMAGE2DPROC glow_debug_glTexSubImage2D;
#define glTexSubImage2D glow_debug_glTexSubImage2D
GLOWDEF PFNGLBINDTEXTUREPROC glow_debug_glBindTexture;
#define glBindTexture glow_debug_glBindTexture
GLOWDEF PFNGLCOLOR4UBPROC glow_debug_glColor4ub;
#define glColor4ub glow_debug_glColor4ub
GLOWDEF PFNGLCULLFACEPROC glow_debug_glCullFace;
#define glCullFace glow_debug_glCullFace
GLOWDEF PFNGLDELETETEXTURESPROC glow_debug_glDeleteTextures;
#define glDeleteTextures glow_debug_glDeleteTextures
GLOWDEF PFNGLGETTEXPARAMETERIVPROC glow_debug_glGetTexParameteriv;
#define glGetTexParameteriv glow_debug_glGetTexParameteriv
GLOWDEF PFNGLLINEWIDTHXPROC glow_debug_glLineWidthx;
#define glLineWidthx glow_debug_glLineWidthx
GLOWDEF PFNGLTEXENVXVPROC glow_debug_glTexEnvxv;
#define glTexEnvxv glow_debug_glTexEnvxv
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
static void glow_lazy_glGetClipPlanex(GLenum plane, GLfixed *equation) {
  glow_glGetClipPlanex = (PFNGLGETCLIPPLANEXPROC)((ptrdiff_t)(glow_get_proc("glGetClipPlanex")));
  if (glow_glGetClipPlanex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetClipPlanex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetClipPlanex\n");
#endif
  }
  glow_glGetClipPlanex(plane, equation);
}
PFNGLGETCLIPPLANEXPROC glow_glGetClipPlanex = glow_lazy_glGetClipPlanex;
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
static void glow_lazy_glShadeModel(GLenum mode) {
  glow_glShadeModel = (PFNGLSHADEMODELPROC)((ptrdiff_t)(glow_get_proc("glShadeModel")));
  if (glow_glShadeModel == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glShadeModel\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glShadeModel\n");
#endif
  }
  glow_glShadeModel(mode);
}
PFNGLSHADEMODELPROC glow_glShadeModel = glow_lazy_glShadeModel;
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
static void glow_lazy_glGetLightfv(GLenum light, GLenum pname, GLfloat *params) {
  glow_glGetLightfv = (PFNGLGETLIGHTFVPROC)((ptrdiff_t)(glow_get_proc("glGetLightfv")));
  if (glow_glGetLightfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetLightfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetLightfv\n");
#endif
  }
  glow_glGetLightfv(light, pname, params);
}
PFNGLGETLIGHTFVPROC glow_glGetLightfv = glow_lazy_glGetLightfv;
static void glow_lazy_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {
  glow_glMaterialfv = (PFNGLMATERIALFVPROC)((ptrdiff_t)(glow_get_proc("glMaterialfv")));
  if (glow_glMaterialfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMaterialfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMaterialfv\n");
#endif
  }
  glow_glMaterialfv(face, pname, params);
}
PFNGLMATERIALFVPROC glow_glMaterialfv = glow_lazy_glMaterialfv;
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
static void glow_lazy_glGetTexParameterxv(GLenum target, GLenum pname, GLfixed *params) {
  glow_glGetTexParameterxv = (PFNGLGETTEXPARAMETERXVPROC)((ptrdiff_t)(glow_get_proc("glGetTexParameterxv")));
  if (glow_glGetTexParameterxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameterxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameterxv\n");
#endif
  }
  glow_glGetTexParameterxv(target, pname, params);
}
PFNGLGETTEXPARAMETERXVPROC glow_glGetTexParameterxv = glow_lazy_glGetTexParameterxv;
static void glow_lazy_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
  glow_glColor4f = (PFNGLCOLOR4FPROC)((ptrdiff_t)(glow_get_proc("glColor4f")));
  if (glow_glColor4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4f\n");
#endif
  }
  glow_glColor4f(red, green, blue, alpha);
}
PFNGLCOLOR4FPROC glow_glColor4f = glow_lazy_glColor4f;
static void glow_lazy_glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params) {
  glow_glGetMaterialfv = (PFNGLGETMATERIALFVPROC)((ptrdiff_t)(glow_get_proc("glGetMaterialfv")));
  if (glow_glGetMaterialfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMaterialfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMaterialfv\n");
#endif
  }
  glow_glGetMaterialfv(face, pname, params);
}
PFNGLGETMATERIALFVPROC glow_glGetMaterialfv = glow_lazy_glGetMaterialfv;
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
static void glow_lazy_glMultiTexCoord4x(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
  glow_glMultiTexCoord4x = (PFNGLMULTITEXCOORD4XPROC)((ptrdiff_t)(glow_get_proc("glMultiTexCoord4x")));
  if (glow_glMultiTexCoord4x == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMultiTexCoord4x\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMultiTexCoord4x\n");
#endif
  }
  glow_glMultiTexCoord4x(texture, s, t, r, q);
}
PFNGLMULTITEXCOORD4XPROC glow_glMultiTexCoord4x = glow_lazy_glMultiTexCoord4x;
static void glow_lazy_glTranslatex(GLfixed x, GLfixed y, GLfixed z) {
  glow_glTranslatex = (PFNGLTRANSLATEXPROC)((ptrdiff_t)(glow_get_proc("glTranslatex")));
  if (glow_glTranslatex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTranslatex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTranslatex\n");
#endif
  }
  glow_glTranslatex(x, y, z);
}
PFNGLTRANSLATEXPROC glow_glTranslatex = glow_lazy_glTranslatex;
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
static void glow_lazy_glScalef(GLfloat x, GLfloat y, GLfloat z) {
  glow_glScalef = (PFNGLSCALEFPROC)((ptrdiff_t)(glow_get_proc("glScalef")));
  if (glow_glScalef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glScalef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glScalef\n");
#endif
  }
  glow_glScalef(x, y, z);
}
PFNGLSCALEFPROC glow_glScalef = glow_lazy_glScalef;
static void glow_lazy_glOrthof(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
  glow_glOrthof = (PFNGLORTHOFPROC)((ptrdiff_t)(glow_get_proc("glOrthof")));
  if (glow_glOrthof == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glOrthof\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glOrthof\n");
#endif
  }
  glow_glOrthof(l, r, b, t, n, f);
}
PFNGLORTHOFPROC glow_glOrthof = glow_lazy_glOrthof;
static void glow_lazy_glColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) {
  glow_glColorPointer = (PFNGLCOLORPOINTERPROC)((ptrdiff_t)(glow_get_proc("glColorPointer")));
  if (glow_glColorPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColorPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColorPointer\n");
#endif
  }
  glow_glColorPointer(size, type, stride, pointer);
}
PFNGLCOLORPOINTERPROC glow_glColorPointer = glow_lazy_glColorPointer;
static void glow_lazy_glGetPointerv(GLenum pname, void **params) {
  glow_glGetPointerv = (PFNGLGETPOINTERVPROC)((ptrdiff_t)(glow_get_proc("glGetPointerv")));
  if (glow_glGetPointerv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetPointerv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetPointerv\n");
#endif
  }
  glow_glGetPointerv(pname, params);
}
PFNGLGETPOINTERVPROC glow_glGetPointerv = glow_lazy_glGetPointerv;
static void glow_lazy_glPointParameterxv(GLenum pname, const GLfixed *params) {
  glow_glPointParameterxv = (PFNGLPOINTPARAMETERXVPROC)((ptrdiff_t)(glow_get_proc("glPointParameterxv")));
  if (glow_glPointParameterxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointParameterxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointParameterxv\n");
#endif
  }
  glow_glPointParameterxv(pname, params);
}
PFNGLPOINTPARAMETERXVPROC glow_glPointParameterxv = glow_lazy_glPointParameterxv;
static void glow_lazy_glLoadIdentity() {
  glow_glLoadIdentity = (PFNGLLOADIDENTITYPROC)((ptrdiff_t)(glow_get_proc("glLoadIdentity")));
  if (glow_glLoadIdentity == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadIdentity\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadIdentity\n");
#endif
  }
  glow_glLoadIdentity();
}
PFNGLLOADIDENTITYPROC glow_glLoadIdentity = glow_lazy_glLoadIdentity;
static void glow_lazy_glLogicOp(GLenum opcode) {
  glow_glLogicOp = (PFNGLLOGICOPPROC)((ptrdiff_t)(glow_get_proc("glLogicOp")));
  if (glow_glLogicOp == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLogicOp\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLogicOp\n");
#endif
  }
  glow_glLogicOp(opcode);
}
PFNGLLOGICOPPROC glow_glLogicOp = glow_lazy_glLogicOp;
static void glow_lazy_glMatrixMode(GLenum mode) {
  glow_glMatrixMode = (PFNGLMATRIXMODEPROC)((ptrdiff_t)(glow_get_proc("glMatrixMode")));
  if (glow_glMatrixMode == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMatrixMode\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMatrixMode\n");
#endif
  }
  glow_glMatrixMode(mode);
}
PFNGLMATRIXMODEPROC glow_glMatrixMode = glow_lazy_glMatrixMode;
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
static void glow_lazy_glGetMaterialxv(GLenum face, GLenum pname, GLfixed *params) {
  glow_glGetMaterialxv = (PFNGLGETMATERIALXVPROC)((ptrdiff_t)(glow_get_proc("glGetMaterialxv")));
  if (glow_glGetMaterialxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMaterialxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMaterialxv\n");
#endif
  }
  glow_glGetMaterialxv(face, pname, params);
}
PFNGLGETMATERIALXVPROC glow_glGetMaterialxv = glow_lazy_glGetMaterialxv;
static void glow_lazy_glPopMatrix() {
  glow_glPopMatrix = (PFNGLPOPMATRIXPROC)((ptrdiff_t)(glow_get_proc("glPopMatrix")));
  if (glow_glPopMatrix == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPopMatrix\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPopMatrix\n");
#endif
  }
  glow_glPopMatrix();
}
PFNGLPOPMATRIXPROC glow_glPopMatrix = glow_lazy_glPopMatrix;
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
static void glow_lazy_glMaterialf(GLenum face, GLenum pname, GLfloat param) {
  glow_glMaterialf = (PFNGLMATERIALFPROC)((ptrdiff_t)(glow_get_proc("glMaterialf")));
  if (glow_glMaterialf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMaterialf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMaterialf\n");
#endif
  }
  glow_glMaterialf(face, pname, param);
}
PFNGLMATERIALFPROC glow_glMaterialf = glow_lazy_glMaterialf;
static void glow_lazy_glMultMatrixf(const GLfloat *m) {
  glow_glMultMatrixf = (PFNGLMULTMATRIXFPROC)((ptrdiff_t)(glow_get_proc("glMultMatrixf")));
  if (glow_glMultMatrixf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMultMatrixf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMultMatrixf\n");
#endif
  }
  glow_glMultMatrixf(m);
}
PFNGLMULTMATRIXFPROC glow_glMultMatrixf = glow_lazy_glMultMatrixf;
static void glow_lazy_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
  glow_glNormal3f = (PFNGLNORMAL3FPROC)((ptrdiff_t)(glow_get_proc("glNormal3f")));
  if (glow_glNormal3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3f\n");
#endif
  }
  glow_glNormal3f(nx, ny, nz);
}
PFNGLNORMAL3FPROC glow_glNormal3f = glow_lazy_glNormal3f;
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
static void glow_lazy_glLightx(GLenum light, GLenum pname, GLfixed param) {
  glow_glLightx = (PFNGLLIGHTXPROC)((ptrdiff_t)(glow_get_proc("glLightx")));
  if (glow_glLightx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightx\n");
#endif
  }
  glow_glLightx(light, pname, param);
}
PFNGLLIGHTXPROC glow_glLightx = glow_lazy_glLightx;
static void glow_lazy_glAlphaFuncx(GLenum func, GLfixed ref) {
  glow_glAlphaFuncx = (PFNGLALPHAFUNCXPROC)((ptrdiff_t)(glow_get_proc("glAlphaFuncx")));
  if (glow_glAlphaFuncx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glAlphaFuncx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glAlphaFuncx\n");
#endif
  }
  glow_glAlphaFuncx(func, ref);
}
PFNGLALPHAFUNCXPROC glow_glAlphaFuncx = glow_lazy_glAlphaFuncx;
static void glow_lazy_glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
  glow_glColor4x = (PFNGLCOLOR4XPROC)((ptrdiff_t)(glow_get_proc("glColor4x")));
  if (glow_glColor4x == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4x\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4x\n");
#endif
  }
  glow_glColor4x(red, green, blue, alpha);
}
PFNGLCOLOR4XPROC glow_glColor4x = glow_lazy_glColor4x;
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
static void glow_lazy_glTexParameterxv(GLenum target, GLenum pname, const GLfixed *params) {
  glow_glTexParameterxv = (PFNGLTEXPARAMETERXVPROC)((ptrdiff_t)(glow_get_proc("glTexParameterxv")));
  if (glow_glTexParameterxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterxv\n");
#endif
  }
  glow_glTexParameterxv(target, pname, params);
}
PFNGLTEXPARAMETERXVPROC glow_glTexParameterxv = glow_lazy_glTexParameterxv;
static void glow_lazy_glClipPlanex(GLenum plane, const GLfixed *equation) {
  glow_glClipPlanex = (PFNGLCLIPPLANEXPROC)((ptrdiff_t)(glow_get_proc("glClipPlanex")));
  if (glow_glClipPlanex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClipPlanex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClipPlanex\n");
#endif
  }
  glow_glClipPlanex(plane, equation);
}
PFNGLCLIPPLANEXPROC glow_glClipPlanex = glow_lazy_glClipPlanex;
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
static void glow_lazy_glTexParameterx(GLenum target, GLenum pname, GLfixed param) {
  glow_glTexParameterx = (PFNGLTEXPARAMETERXPROC)((ptrdiff_t)(glow_get_proc("glTexParameterx")));
  if (glow_glTexParameterx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterx\n");
#endif
  }
  glow_glTexParameterx(target, pname, param);
}
PFNGLTEXPARAMETERXPROC glow_glTexParameterx = glow_lazy_glTexParameterx;
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
static void glow_lazy_glClearColorx(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
  glow_glClearColorx = (PFNGLCLEARCOLORXPROC)((ptrdiff_t)(glow_get_proc("glClearColorx")));
  if (glow_glClearColorx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearColorx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearColorx\n");
#endif
  }
  glow_glClearColorx(red, green, blue, alpha);
}
PFNGLCLEARCOLORXPROC glow_glClearColorx = glow_lazy_glClearColorx;
static void glow_lazy_glPushMatrix() {
  glow_glPushMatrix = (PFNGLPUSHMATRIXPROC)((ptrdiff_t)(glow_get_proc("glPushMatrix")));
  if (glow_glPushMatrix == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPushMatrix\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPushMatrix\n");
#endif
  }
  glow_glPushMatrix();
}
PFNGLPUSHMATRIXPROC glow_glPushMatrix = glow_lazy_glPushMatrix;
static void glow_lazy_glTexEnvx(GLenum target, GLenum pname, GLfixed param) {
  glow_glTexEnvx = (PFNGLTEXENVXPROC)((ptrdiff_t)(glow_get_proc("glTexEnvx")));
  if (glow_glTexEnvx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvx\n");
#endif
  }
  glow_glTexEnvx(target, pname, param);
}
PFNGLTEXENVXPROC glow_glTexEnvx = glow_lazy_glTexEnvx;
static void glow_lazy_glLightModelfv(GLenum pname, const GLfloat *params) {
  glow_glLightModelfv = (PFNGLLIGHTMODELFVPROC)((ptrdiff_t)(glow_get_proc("glLightModelfv")));
  if (glow_glLightModelfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModelfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModelfv\n");
#endif
  }
  glow_glLightModelfv(pname, params);
}
PFNGLLIGHTMODELFVPROC glow_glLightModelfv = glow_lazy_glLightModelfv;
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
static void glow_lazy_glLoadMatrixf(const GLfloat *m) {
  glow_glLoadMatrixf = (PFNGLLOADMATRIXFPROC)((ptrdiff_t)(glow_get_proc("glLoadMatrixf")));
  if (glow_glLoadMatrixf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadMatrixf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadMatrixf\n");
#endif
  }
  glow_glLoadMatrixf(m);
}
PFNGLLOADMATRIXFPROC glow_glLoadMatrixf = glow_lazy_glLoadMatrixf;
static void glow_lazy_glPointParameterf(GLenum pname, GLfloat param) {
  glow_glPointParameterf = (PFNGLPOINTPARAMETERFPROC)((ptrdiff_t)(glow_get_proc("glPointParameterf")));
  if (glow_glPointParameterf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointParameterf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointParameterf\n");
#endif
  }
  glow_glPointParameterf(pname, param);
}
PFNGLPOINTPARAMETERFPROC glow_glPointParameterf = glow_lazy_glPointParameterf;
static void glow_lazy_glPolygonOffsetx(GLfixed factor, GLfixed units) {
  glow_glPolygonOffsetx = (PFNGLPOLYGONOFFSETXPROC)((ptrdiff_t)(glow_get_proc("glPolygonOffsetx")));
  if (glow_glPolygonOffsetx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPolygonOffsetx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPolygonOffsetx\n");
#endif
  }
  glow_glPolygonOffsetx(factor, units);
}
PFNGLPOLYGONOFFSETXPROC glow_glPolygonOffsetx = glow_lazy_glPolygonOffsetx;
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
static void glow_lazy_glLightModelx(GLenum pname, GLfixed param) {
  glow_glLightModelx = (PFNGLLIGHTMODELXPROC)((ptrdiff_t)(glow_get_proc("glLightModelx")));
  if (glow_glLightModelx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModelx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModelx\n");
#endif
  }
  glow_glLightModelx(pname, param);
}
PFNGLLIGHTMODELXPROC glow_glLightModelx = glow_lazy_glLightModelx;
static void glow_lazy_glVertexPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) {
  glow_glVertexPointer = (PFNGLVERTEXPOINTERPROC)((ptrdiff_t)(glow_get_proc("glVertexPointer")));
  if (glow_glVertexPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexPointer\n");
#endif
  }
  glow_glVertexPointer(size, type, stride, pointer);
}
PFNGLVERTEXPOINTERPROC glow_glVertexPointer = glow_lazy_glVertexPointer;
static void glow_lazy_glNormalPointer(GLenum type, GLsizei stride, const void *pointer) {
  glow_glNormalPointer = (PFNGLNORMALPOINTERPROC)((ptrdiff_t)(glow_get_proc("glNormalPointer")));
  if (glow_glNormalPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormalPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormalPointer\n");
#endif
  }
  glow_glNormalPointer(type, stride, pointer);
}
PFNGLNORMALPOINTERPROC glow_glNormalPointer = glow_lazy_glNormalPointer;
static void glow_lazy_glLightModelxv(GLenum pname, const GLfixed *param) {
  glow_glLightModelxv = (PFNGLLIGHTMODELXVPROC)((ptrdiff_t)(glow_get_proc("glLightModelxv")));
  if (glow_glLightModelxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModelxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModelxv\n");
#endif
  }
  glow_glLightModelxv(pname, param);
}
PFNGLLIGHTMODELXVPROC glow_glLightModelxv = glow_lazy_glLightModelxv;
static void glow_lazy_glFrustumf(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
  glow_glFrustumf = (PFNGLFRUSTUMFPROC)((ptrdiff_t)(glow_get_proc("glFrustumf")));
  if (glow_glFrustumf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFrustumf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFrustumf\n");
#endif
  }
  glow_glFrustumf(l, r, b, t, n, f);
}
PFNGLFRUSTUMFPROC glow_glFrustumf = glow_lazy_glFrustumf;
static void glow_lazy_glLightModelf(GLenum pname, GLfloat param) {
  glow_glLightModelf = (PFNGLLIGHTMODELFPROC)((ptrdiff_t)(glow_get_proc("glLightModelf")));
  if (glow_glLightModelf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModelf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModelf\n");
#endif
  }
  glow_glLightModelf(pname, param);
}
PFNGLLIGHTMODELFPROC glow_glLightModelf = glow_lazy_glLightModelf;
static void glow_lazy_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params) {
  glow_glTexEnvfv = (PFNGLTEXENVFVPROC)((ptrdiff_t)(glow_get_proc("glTexEnvfv")));
  if (glow_glTexEnvfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvfv\n");
#endif
  }
  glow_glTexEnvfv(target, pname, params);
}
PFNGLTEXENVFVPROC glow_glTexEnvfv = glow_lazy_glTexEnvfv;
static void glow_lazy_glDepthRangex(GLfixed n, GLfixed f) {
  glow_glDepthRangex = (PFNGLDEPTHRANGEXPROC)((ptrdiff_t)(glow_get_proc("glDepthRangex")));
  if (glow_glDepthRangex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthRangex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthRangex\n");
#endif
  }
  glow_glDepthRangex(n, f);
}
PFNGLDEPTHRANGEXPROC glow_glDepthRangex = glow_lazy_glDepthRangex;
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
static void glow_lazy_glGetLightxv(GLenum light, GLenum pname, GLfixed *params) {
  glow_glGetLightxv = (PFNGLGETLIGHTXVPROC)((ptrdiff_t)(glow_get_proc("glGetLightxv")));
  if (glow_glGetLightxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetLightxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetLightxv\n");
#endif
  }
  glow_glGetLightxv(light, pname, params);
}
PFNGLGETLIGHTXVPROC glow_glGetLightxv = glow_lazy_glGetLightxv;
static void glow_lazy_glOrthox(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
  glow_glOrthox = (PFNGLORTHOXPROC)((ptrdiff_t)(glow_get_proc("glOrthox")));
  if (glow_glOrthox == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glOrthox\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glOrthox\n");
#endif
  }
  glow_glOrthox(l, r, b, t, n, f);
}
PFNGLORTHOXPROC glow_glOrthox = glow_lazy_glOrthox;
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
static void glow_lazy_glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
  glow_glRotatex = (PFNGLROTATEXPROC)((ptrdiff_t)(glow_get_proc("glRotatex")));
  if (glow_glRotatex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRotatex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRotatex\n");
#endif
  }
  glow_glRotatex(angle, x, y, z);
}
PFNGLROTATEXPROC glow_glRotatex = glow_lazy_glRotatex;
static void glow_lazy_glSampleCoveragex(GLclampx value, GLboolean invert) {
  glow_glSampleCoveragex = (PFNGLSAMPLECOVERAGEXPROC)((ptrdiff_t)(glow_get_proc("glSampleCoveragex")));
  if (glow_glSampleCoveragex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSampleCoveragex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSampleCoveragex\n");
#endif
  }
  glow_glSampleCoveragex(value, invert);
}
PFNGLSAMPLECOVERAGEXPROC glow_glSampleCoveragex = glow_lazy_glSampleCoveragex;
static void glow_lazy_glScalex(GLfixed x, GLfixed y, GLfixed z) {
  glow_glScalex = (PFNGLSCALEXPROC)((ptrdiff_t)(glow_get_proc("glScalex")));
  if (glow_glScalex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glScalex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glScalex\n");
#endif
  }
  glow_glScalex(x, y, z);
}
PFNGLSCALEXPROC glow_glScalex = glow_lazy_glScalex;
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
static void glow_lazy_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
  glow_glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)((ptrdiff_t)(glow_get_proc("glMultiTexCoord4f")));
  if (glow_glMultiTexCoord4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMultiTexCoord4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMultiTexCoord4f\n");
#endif
  }
  glow_glMultiTexCoord4f(target, s, t, r, q);
}
PFNGLMULTITEXCOORD4FPROC glow_glMultiTexCoord4f = glow_lazy_glMultiTexCoord4f;
static void glow_lazy_glPointParameterfv(GLenum pname, const GLfloat *params) {
  glow_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)((ptrdiff_t)(glow_get_proc("glPointParameterfv")));
  if (glow_glPointParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointParameterfv\n");
#endif
  }
  glow_glPointParameterfv(pname, params);
}
PFNGLPOINTPARAMETERFVPROC glow_glPointParameterfv = glow_lazy_glPointParameterfv;
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
static void glow_lazy_glClientActiveTexture(GLenum texture) {
  glow_glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)((ptrdiff_t)(glow_get_proc("glClientActiveTexture")));
  if (glow_glClientActiveTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClientActiveTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClientActiveTexture\n");
#endif
  }
  glow_glClientActiveTexture(texture);
}
PFNGLCLIENTACTIVETEXTUREPROC glow_glClientActiveTexture = glow_lazy_glClientActiveTexture;
static void glow_lazy_glMultMatrixx(const GLfixed *m) {
  glow_glMultMatrixx = (PFNGLMULTMATRIXXPROC)((ptrdiff_t)(glow_get_proc("glMultMatrixx")));
  if (glow_glMultMatrixx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMultMatrixx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMultMatrixx\n");
#endif
  }
  glow_glMultMatrixx(m);
}
PFNGLMULTMATRIXXPROC glow_glMultMatrixx = glow_lazy_glMultMatrixx;
static void glow_lazy_glLightf(GLenum light, GLenum pname, GLfloat param) {
  glow_glLightf = (PFNGLLIGHTFPROC)((ptrdiff_t)(glow_get_proc("glLightf")));
  if (glow_glLightf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightf\n");
#endif
  }
  glow_glLightf(light, pname, param);
}
PFNGLLIGHTFPROC glow_glLightf = glow_lazy_glLightf;
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
static void glow_lazy_glDisableClientState(GLenum array) {
  glow_glDisableClientState = (PFNGLDISABLECLIENTSTATEPROC)((ptrdiff_t)(glow_get_proc("glDisableClientState")));
  if (glow_glDisableClientState == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisableClientState\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisableClientState\n");
#endif
  }
  glow_glDisableClientState(array);
}
PFNGLDISABLECLIENTSTATEPROC glow_glDisableClientState = glow_lazy_glDisableClientState;
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
static void glow_lazy_glMaterialx(GLenum face, GLenum pname, GLfixed param) {
  glow_glMaterialx = (PFNGLMATERIALXPROC)((ptrdiff_t)(glow_get_proc("glMaterialx")));
  if (glow_glMaterialx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMaterialx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMaterialx\n");
#endif
  }
  glow_glMaterialx(face, pname, param);
}
PFNGLMATERIALXPROC glow_glMaterialx = glow_lazy_glMaterialx;
static void glow_lazy_glAlphaFunc(GLenum func, GLfloat ref) {
  glow_glAlphaFunc = (PFNGLALPHAFUNCPROC)((ptrdiff_t)(glow_get_proc("glAlphaFunc")));
  if (glow_glAlphaFunc == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glAlphaFunc\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glAlphaFunc\n");
#endif
  }
  glow_glAlphaFunc(func, ref);
}
PFNGLALPHAFUNCPROC glow_glAlphaFunc = glow_lazy_glAlphaFunc;
static void glow_lazy_glClipPlanef(GLenum p, const GLfloat *eqn) {
  glow_glClipPlanef = (PFNGLCLIPPLANEFPROC)((ptrdiff_t)(glow_get_proc("glClipPlanef")));
  if (glow_glClipPlanef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClipPlanef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClipPlanef\n");
#endif
  }
  glow_glClipPlanef(p, eqn);
}
PFNGLCLIPPLANEFPROC glow_glClipPlanef = glow_lazy_glClipPlanef;
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
static void glow_lazy_glLightfv(GLenum light, GLenum pname, const GLfloat *params) {
  glow_glLightfv = (PFNGLLIGHTFVPROC)((ptrdiff_t)(glow_get_proc("glLightfv")));
  if (glow_glLightfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightfv\n");
#endif
  }
  glow_glLightfv(light, pname, params);
}
PFNGLLIGHTFVPROC glow_glLightfv = glow_lazy_glLightfv;
static void glow_lazy_glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
  glow_glTranslatef = (PFNGLTRANSLATEFPROC)((ptrdiff_t)(glow_get_proc("glTranslatef")));
  if (glow_glTranslatef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTranslatef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTranslatef\n");
#endif
  }
  glow_glTranslatef(x, y, z);
}
PFNGLTRANSLATEFPROC glow_glTranslatef = glow_lazy_glTranslatef;
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
static void glow_lazy_glPointParameterx(GLenum pname, GLfixed param) {
  glow_glPointParameterx = (PFNGLPOINTPARAMETERXPROC)((ptrdiff_t)(glow_get_proc("glPointParameterx")));
  if (glow_glPointParameterx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointParameterx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointParameterx\n");
#endif
  }
  glow_glPointParameterx(pname, param);
}
PFNGLPOINTPARAMETERXPROC glow_glPointParameterx = glow_lazy_glPointParameterx;
static void glow_lazy_glTexEnviv(GLenum target, GLenum pname, const GLint *params) {
  glow_glTexEnviv = (PFNGLTEXENVIVPROC)((ptrdiff_t)(glow_get_proc("glTexEnviv")));
  if (glow_glTexEnviv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnviv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnviv\n");
#endif
  }
  glow_glTexEnviv(target, pname, params);
}
PFNGLTEXENVIVPROC glow_glTexEnviv = glow_lazy_glTexEnviv;
static void glow_lazy_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params) {
  glow_glGetTexEnvfv = (PFNGLGETTEXENVFVPROC)((ptrdiff_t)(glow_get_proc("glGetTexEnvfv")));
  if (glow_glGetTexEnvfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexEnvfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexEnvfv\n");
#endif
  }
  glow_glGetTexEnvfv(target, pname, params);
}
PFNGLGETTEXENVFVPROC glow_glGetTexEnvfv = glow_lazy_glGetTexEnvfv;
static void glow_lazy_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
  glow_glRotatef = (PFNGLROTATEFPROC)((ptrdiff_t)(glow_get_proc("glRotatef")));
  if (glow_glRotatef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRotatef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRotatef\n");
#endif
  }
  glow_glRotatef(angle, x, y, z);
}
PFNGLROTATEFPROC glow_glRotatef = glow_lazy_glRotatef;
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
static void glow_lazy_glGetTexEnviv(GLenum target, GLenum pname, GLint *params) {
  glow_glGetTexEnviv = (PFNGLGETTEXENVIVPROC)((ptrdiff_t)(glow_get_proc("glGetTexEnviv")));
  if (glow_glGetTexEnviv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexEnviv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexEnviv\n");
#endif
  }
  glow_glGetTexEnviv(target, pname, params);
}
PFNGLGETTEXENVIVPROC glow_glGetTexEnviv = glow_lazy_glGetTexEnviv;
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
static void glow_lazy_glMaterialxv(GLenum face, GLenum pname, const GLfixed *param) {
  glow_glMaterialxv = (PFNGLMATERIALXVPROC)((ptrdiff_t)(glow_get_proc("glMaterialxv")));
  if (glow_glMaterialxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMaterialxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMaterialxv\n");
#endif
  }
  glow_glMaterialxv(face, pname, param);
}
PFNGLMATERIALXVPROC glow_glMaterialxv = glow_lazy_glMaterialxv;
static void glow_lazy_glGetClipPlanef(GLenum plane, GLfloat *equation) {
  glow_glGetClipPlanef = (PFNGLGETCLIPPLANEFPROC)((ptrdiff_t)(glow_get_proc("glGetClipPlanef")));
  if (glow_glGetClipPlanef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetClipPlanef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetClipPlanef\n");
#endif
  }
  glow_glGetClipPlanef(plane, equation);
}
PFNGLGETCLIPPLANEFPROC glow_glGetClipPlanef = glow_lazy_glGetClipPlanef;
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
static void glow_lazy_glGetFixedv(GLenum pname, GLfixed *params) {
  glow_glGetFixedv = (PFNGLGETFIXEDVPROC)((ptrdiff_t)(glow_get_proc("glGetFixedv")));
  if (glow_glGetFixedv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFixedv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFixedv\n");
#endif
  }
  glow_glGetFixedv(pname, params);
}
PFNGLGETFIXEDVPROC glow_glGetFixedv = glow_lazy_glGetFixedv;
static void glow_lazy_glLightxv(GLenum light, GLenum pname, const GLfixed *params) {
  glow_glLightxv = (PFNGLLIGHTXVPROC)((ptrdiff_t)(glow_get_proc("glLightxv")));
  if (glow_glLightxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightxv\n");
#endif
  }
  glow_glLightxv(light, pname, params);
}
PFNGLLIGHTXVPROC glow_glLightxv = glow_lazy_glLightxv;
static void glow_lazy_glLoadMatrixx(const GLfixed *m) {
  glow_glLoadMatrixx = (PFNGLLOADMATRIXXPROC)((ptrdiff_t)(glow_get_proc("glLoadMatrixx")));
  if (glow_glLoadMatrixx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadMatrixx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadMatrixx\n");
#endif
  }
  glow_glLoadMatrixx(m);
}
PFNGLLOADMATRIXXPROC glow_glLoadMatrixx = glow_lazy_glLoadMatrixx;
static void glow_lazy_glFogf(GLenum pname, GLfloat param) {
  glow_glFogf = (PFNGLFOGFPROC)((ptrdiff_t)(glow_get_proc("glFogf")));
  if (glow_glFogf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogf\n");
#endif
  }
  glow_glFogf(pname, param);
}
PFNGLFOGFPROC glow_glFogf = glow_lazy_glFogf;
static void glow_lazy_glFogfv(GLenum pname, const GLfloat *params) {
  glow_glFogfv = (PFNGLFOGFVPROC)((ptrdiff_t)(glow_get_proc("glFogfv")));
  if (glow_glFogfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogfv\n");
#endif
  }
  glow_glFogfv(pname, params);
}
PFNGLFOGFVPROC glow_glFogfv = glow_lazy_glFogfv;
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
static void glow_lazy_glPointSizex(GLfixed size) {
  glow_glPointSizex = (PFNGLPOINTSIZEXPROC)((ptrdiff_t)(glow_get_proc("glPointSizex")));
  if (glow_glPointSizex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointSizex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointSizex\n");
#endif
  }
  glow_glPointSizex(size);
}
PFNGLPOINTSIZEXPROC glow_glPointSizex = glow_lazy_glPointSizex;
static void glow_lazy_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
  glow_glTexEnvf = (PFNGLTEXENVFPROC)((ptrdiff_t)(glow_get_proc("glTexEnvf")));
  if (glow_glTexEnvf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvf\n");
#endif
  }
  glow_glTexEnvf(target, pname, param);
}
PFNGLTEXENVFPROC glow_glTexEnvf = glow_lazy_glTexEnvf;
static void glow_lazy_glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {
  glow_glNormal3x = (PFNGLNORMAL3XPROC)((ptrdiff_t)(glow_get_proc("glNormal3x")));
  if (glow_glNormal3x == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3x\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3x\n");
#endif
  }
  glow_glNormal3x(nx, ny, nz);
}
PFNGLNORMAL3XPROC glow_glNormal3x = glow_lazy_glNormal3x;
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
static void glow_lazy_glTexEnvi(GLenum target, GLenum pname, GLint param) {
  glow_glTexEnvi = (PFNGLTEXENVIPROC)((ptrdiff_t)(glow_get_proc("glTexEnvi")));
  if (glow_glTexEnvi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvi\n");
#endif
  }
  glow_glTexEnvi(target, pname, param);
}
PFNGLTEXENVIPROC glow_glTexEnvi = glow_lazy_glTexEnvi;
static void glow_lazy_glClearDepthx(GLfixed depth) {
  glow_glClearDepthx = (PFNGLCLEARDEPTHXPROC)((ptrdiff_t)(glow_get_proc("glClearDepthx")));
  if (glow_glClearDepthx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearDepthx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearDepthx\n");
#endif
  }
  glow_glClearDepthx(depth);
}
PFNGLCLEARDEPTHXPROC glow_glClearDepthx = glow_lazy_glClearDepthx;
static void glow_lazy_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) {
  glow_glTexCoordPointer = (PFNGLTEXCOORDPOINTERPROC)((ptrdiff_t)(glow_get_proc("glTexCoordPointer")));
  if (glow_glTexCoordPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoordPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoordPointer\n");
#endif
  }
  glow_glTexCoordPointer(size, type, stride, pointer);
}
PFNGLTEXCOORDPOINTERPROC glow_glTexCoordPointer = glow_lazy_glTexCoordPointer;
static void glow_lazy_glFrustumx(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
  glow_glFrustumx = (PFNGLFRUSTUMXPROC)((ptrdiff_t)(glow_get_proc("glFrustumx")));
  if (glow_glFrustumx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFrustumx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFrustumx\n");
#endif
  }
  glow_glFrustumx(l, r, b, t, n, f);
}
PFNGLFRUSTUMXPROC glow_glFrustumx = glow_lazy_glFrustumx;
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
static void glow_lazy_glPointSize(GLfloat size) {
  glow_glPointSize = (PFNGLPOINTSIZEPROC)((ptrdiff_t)(glow_get_proc("glPointSize")));
  if (glow_glPointSize == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointSize\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointSize\n");
#endif
  }
  glow_glPointSize(size);
}
PFNGLPOINTSIZEPROC glow_glPointSize = glow_lazy_glPointSize;
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
static void glow_lazy_glEnableClientState(GLenum array) {
  glow_glEnableClientState = (PFNGLENABLECLIENTSTATEPROC)((ptrdiff_t)(glow_get_proc("glEnableClientState")));
  if (glow_glEnableClientState == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnableClientState\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnableClientState\n");
#endif
  }
  glow_glEnableClientState(array);
}
PFNGLENABLECLIENTSTATEPROC glow_glEnableClientState = glow_lazy_glEnableClientState;
static void glow_lazy_glFogx(GLenum pname, GLfixed param) {
  glow_glFogx = (PFNGLFOGXPROC)((ptrdiff_t)(glow_get_proc("glFogx")));
  if (glow_glFogx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogx\n");
#endif
  }
  glow_glFogx(pname, param);
}
PFNGLFOGXPROC glow_glFogx = glow_lazy_glFogx;
static void glow_lazy_glFogxv(GLenum pname, const GLfixed *param) {
  glow_glFogxv = (PFNGLFOGXVPROC)((ptrdiff_t)(glow_get_proc("glFogxv")));
  if (glow_glFogxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogxv\n");
#endif
  }
  glow_glFogxv(pname, param);
}
PFNGLFOGXVPROC glow_glFogxv = glow_lazy_glFogxv;
static void glow_lazy_glGetTexEnvxv(GLenum target, GLenum pname, GLfixed *params) {
  glow_glGetTexEnvxv = (PFNGLGETTEXENVXVPROC)((ptrdiff_t)(glow_get_proc("glGetTexEnvxv")));
  if (glow_glGetTexEnvxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexEnvxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexEnvxv\n");
#endif
  }
  glow_glGetTexEnvxv(target, pname, params);
}
PFNGLGETTEXENVXVPROC glow_glGetTexEnvxv = glow_lazy_glGetTexEnvxv;
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
static void glow_lazy_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
  glow_glColor4ub = (PFNGLCOLOR4UBPROC)((ptrdiff_t)(glow_get_proc("glColor4ub")));
  if (glow_glColor4ub == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4ub\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4ub\n");
#endif
  }
  glow_glColor4ub(red, green, blue, alpha);
}
PFNGLCOLOR4UBPROC glow_glColor4ub = glow_lazy_glColor4ub;
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
static void glow_lazy_glLineWidthx(GLfixed width) {
  glow_glLineWidthx = (PFNGLLINEWIDTHXPROC)((ptrdiff_t)(glow_get_proc("glLineWidthx")));
  if (glow_glLineWidthx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLineWidthx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLineWidthx\n");
#endif
  }
  glow_glLineWidthx(width);
}
PFNGLLINEWIDTHXPROC glow_glLineWidthx = glow_lazy_glLineWidthx;
static void glow_lazy_glTexEnvxv(GLenum target, GLenum pname, const GLfixed *params) {
  glow_glTexEnvxv = (PFNGLTEXENVXVPROC)((ptrdiff_t)(glow_get_proc("glTexEnvxv")));
  if (glow_glTexEnvxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvxv\n");
#endif
  }
  glow_glTexEnvxv(target, pname, params);
}
PFNGLTEXENVXVPROC glow_glTexEnvxv = glow_lazy_glTexEnvxv;


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

static void glow_debug_impl_glActiveTexture(GLenum texture) {

  glow_pre_callback_("glActiveTexture", (void*)(ptrdiff_t)glow_glActiveTexture, texture);
  glow_glActiveTexture(texture);
  glow_post_callback_("glActiveTexture", (void*)(ptrdiff_t)glow_glActiveTexture, texture);
}
PFNGLACTIVETEXTUREPROC glow_debug_glActiveTexture = glow_debug_impl_glActiveTexture;

static void glow_debug_impl_glGetClipPlanex(GLenum plane, GLfixed *equation) {

  glow_pre_callback_("glGetClipPlanex", (void*)(ptrdiff_t)glow_glGetClipPlanex, plane, equation);
  glow_glGetClipPlanex(plane, equation);
  glow_post_callback_("glGetClipPlanex", (void*)(ptrdiff_t)glow_glGetClipPlanex, plane, equation);
}
PFNGLGETCLIPPLANEXPROC glow_debug_glGetClipPlanex = glow_debug_impl_glGetClipPlanex;

static GLubyte glow_debug_impl_glGetString(GLenum name) {

  GLubyte ret;
  glow_pre_callback_("glGetString", (void*)(ptrdiff_t)glow_glGetString, name);
  ret = glow_glGetString(name);
  glow_post_callback_("glGetString", (void*)(ptrdiff_t)glow_glGetString, name);
  return ret;
}
PFNGLGETSTRINGPROC glow_debug_glGetString = glow_debug_impl_glGetString;

static GLboolean glow_debug_impl_glIsEnabled(GLenum cap) {

  GLboolean ret;
  glow_pre_callback_("glIsEnabled", (void*)(ptrdiff_t)glow_glIsEnabled, cap);
  ret = glow_glIsEnabled(cap);
  glow_post_callback_("glIsEnabled", (void*)(ptrdiff_t)glow_glIsEnabled, cap);
  return ret;
}
PFNGLISENABLEDPROC glow_debug_glIsEnabled = glow_debug_impl_glIsEnabled;

static void glow_debug_impl_glShadeModel(GLenum mode) {

  glow_pre_callback_("glShadeModel", (void*)(ptrdiff_t)glow_glShadeModel, mode);
  glow_glShadeModel(mode);
  glow_post_callback_("glShadeModel", (void*)(ptrdiff_t)glow_glShadeModel, mode);
}
PFNGLSHADEMODELPROC glow_debug_glShadeModel = glow_debug_impl_glShadeModel;

static void glow_debug_impl_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glTexImage2D", (void*)(ptrdiff_t)glow_glTexImage2D, target, level, internalformat, width, height, border, format, type, pixels);
  glow_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
  glow_post_callback_("glTexImage2D", (void*)(ptrdiff_t)glow_glTexImage2D, target, level, internalformat, width, height, border, format, type, pixels);
}
PFNGLTEXIMAGE2DPROC glow_debug_glTexImage2D = glow_debug_impl_glTexImage2D;

static void glow_debug_impl_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glViewport", (void*)(ptrdiff_t)glow_glViewport, x, y, width, height);
  glow_glViewport(x, y, width, height);
  glow_post_callback_("glViewport", (void*)(ptrdiff_t)glow_glViewport, x, y, width, height);
}
PFNGLVIEWPORTPROC glow_debug_glViewport = glow_debug_impl_glViewport;

static void glow_debug_impl_glGetLightfv(GLenum light, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetLightfv", (void*)(ptrdiff_t)glow_glGetLightfv, light, pname, params);
  glow_glGetLightfv(light, pname, params);
  glow_post_callback_("glGetLightfv", (void*)(ptrdiff_t)glow_glGetLightfv, light, pname, params);
}
PFNGLGETLIGHTFVPROC glow_debug_glGetLightfv = glow_debug_impl_glGetLightfv;

static void glow_debug_impl_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glMaterialfv", (void*)(ptrdiff_t)glow_glMaterialfv, face, pname, params);
  glow_glMaterialfv(face, pname, params);
  glow_post_callback_("glMaterialfv", (void*)(ptrdiff_t)glow_glMaterialfv, face, pname, params);
}
PFNGLMATERIALFVPROC glow_debug_glMaterialfv = glow_debug_impl_glMaterialfv;

static GLenum glow_debug_impl_glGetError() {

  GLenum ret;
  glow_pre_callback_("glGetError", (void*)(ptrdiff_t)glow_glGetError);
  ret = glow_glGetError();
  glow_post_callback_("glGetError", (void*)(ptrdiff_t)glow_glGetError);
  return ret;
}
PFNGLGETERRORPROC glow_debug_glGetError = glow_debug_impl_glGetError;

static void glow_debug_impl_glGetTexParameterxv(GLenum target, GLenum pname, GLfixed *params) {

  glow_pre_callback_("glGetTexParameterxv", (void*)(ptrdiff_t)glow_glGetTexParameterxv, target, pname, params);
  glow_glGetTexParameterxv(target, pname, params);
  glow_post_callback_("glGetTexParameterxv", (void*)(ptrdiff_t)glow_glGetTexParameterxv, target, pname, params);
}
PFNGLGETTEXPARAMETERXVPROC glow_debug_glGetTexParameterxv = glow_debug_impl_glGetTexParameterxv;

static void glow_debug_impl_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {

  glow_pre_callback_("glColor4f", (void*)(ptrdiff_t)glow_glColor4f, red, green, blue, alpha);
  glow_glColor4f(red, green, blue, alpha);
  glow_post_callback_("glColor4f", (void*)(ptrdiff_t)glow_glColor4f, red, green, blue, alpha);
}
PFNGLCOLOR4FPROC glow_debug_glColor4f = glow_debug_impl_glColor4f;

static void glow_debug_impl_glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetMaterialfv", (void*)(ptrdiff_t)glow_glGetMaterialfv, face, pname, params);
  glow_glGetMaterialfv(face, pname, params);
  glow_post_callback_("glGetMaterialfv", (void*)(ptrdiff_t)glow_glGetMaterialfv, face, pname, params);
}
PFNGLGETMATERIALFVPROC glow_debug_glGetMaterialfv = glow_debug_impl_glGetMaterialfv;

static void glow_debug_impl_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {

  glow_pre_callback_("glColorMask", (void*)(ptrdiff_t)glow_glColorMask, red, green, blue, alpha);
  glow_glColorMask(red, green, blue, alpha);
  glow_post_callback_("glColorMask", (void*)(ptrdiff_t)glow_glColorMask, red, green, blue, alpha);
}
PFNGLCOLORMASKPROC glow_debug_glColorMask = glow_debug_impl_glColorMask;

static void glow_debug_impl_glMultiTexCoord4x(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {

  glow_pre_callback_("glMultiTexCoord4x", (void*)(ptrdiff_t)glow_glMultiTexCoord4x, texture, s, t, r, q);
  glow_glMultiTexCoord4x(texture, s, t, r, q);
  glow_post_callback_("glMultiTexCoord4x", (void*)(ptrdiff_t)glow_glMultiTexCoord4x, texture, s, t, r, q);
}
PFNGLMULTITEXCOORD4XPROC glow_debug_glMultiTexCoord4x = glow_debug_impl_glMultiTexCoord4x;

static void glow_debug_impl_glTranslatex(GLfixed x, GLfixed y, GLfixed z) {

  glow_pre_callback_("glTranslatex", (void*)(ptrdiff_t)glow_glTranslatex, x, y, z);
  glow_glTranslatex(x, y, z);
  glow_post_callback_("glTranslatex", (void*)(ptrdiff_t)glow_glTranslatex, x, y, z);
}
PFNGLTRANSLATEXPROC glow_debug_glTranslatex = glow_debug_impl_glTranslatex;

static void glow_debug_impl_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetTexParameterfv", (void*)(ptrdiff_t)glow_glGetTexParameterfv, target, pname, params);
  glow_glGetTexParameterfv(target, pname, params);
  glow_post_callback_("glGetTexParameterfv", (void*)(ptrdiff_t)glow_glGetTexParameterfv, target, pname, params);
}
PFNGLGETTEXPARAMETERFVPROC glow_debug_glGetTexParameterfv = glow_debug_impl_glGetTexParameterfv;

static void glow_debug_impl_glScalef(GLfloat x, GLfloat y, GLfloat z) {

  glow_pre_callback_("glScalef", (void*)(ptrdiff_t)glow_glScalef, x, y, z);
  glow_glScalef(x, y, z);
  glow_post_callback_("glScalef", (void*)(ptrdiff_t)glow_glScalef, x, y, z);
}
PFNGLSCALEFPROC glow_debug_glScalef = glow_debug_impl_glScalef;

static void glow_debug_impl_glOrthof(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {

  glow_pre_callback_("glOrthof", (void*)(ptrdiff_t)glow_glOrthof, l, r, b, t, n, f);
  glow_glOrthof(l, r, b, t, n, f);
  glow_post_callback_("glOrthof", (void*)(ptrdiff_t)glow_glOrthof, l, r, b, t, n, f);
}
PFNGLORTHOFPROC glow_debug_glOrthof = glow_debug_impl_glOrthof;

static void glow_debug_impl_glColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) {

  glow_pre_callback_("glColorPointer", (void*)(ptrdiff_t)glow_glColorPointer, size, type, stride, pointer);
  glow_glColorPointer(size, type, stride, pointer);
  glow_post_callback_("glColorPointer", (void*)(ptrdiff_t)glow_glColorPointer, size, type, stride, pointer);
}
PFNGLCOLORPOINTERPROC glow_debug_glColorPointer = glow_debug_impl_glColorPointer;

static void glow_debug_impl_glGetPointerv(GLenum pname, void **params) {

  glow_pre_callback_("glGetPointerv", (void*)(ptrdiff_t)glow_glGetPointerv, pname, params);
  glow_glGetPointerv(pname, params);
  glow_post_callback_("glGetPointerv", (void*)(ptrdiff_t)glow_glGetPointerv, pname, params);
}
PFNGLGETPOINTERVPROC glow_debug_glGetPointerv = glow_debug_impl_glGetPointerv;

static void glow_debug_impl_glPointParameterxv(GLenum pname, const GLfixed *params) {

  glow_pre_callback_("glPointParameterxv", (void*)(ptrdiff_t)glow_glPointParameterxv, pname, params);
  glow_glPointParameterxv(pname, params);
  glow_post_callback_("glPointParameterxv", (void*)(ptrdiff_t)glow_glPointParameterxv, pname, params);
}
PFNGLPOINTPARAMETERXVPROC glow_debug_glPointParameterxv = glow_debug_impl_glPointParameterxv;

static void glow_debug_impl_glLoadIdentity() {

  glow_pre_callback_("glLoadIdentity", (void*)(ptrdiff_t)glow_glLoadIdentity);
  glow_glLoadIdentity();
  glow_post_callback_("glLoadIdentity", (void*)(ptrdiff_t)glow_glLoadIdentity);
}
PFNGLLOADIDENTITYPROC glow_debug_glLoadIdentity = glow_debug_impl_glLoadIdentity;

static void glow_debug_impl_glLogicOp(GLenum opcode) {

  glow_pre_callback_("glLogicOp", (void*)(ptrdiff_t)glow_glLogicOp, opcode);
  glow_glLogicOp(opcode);
  glow_post_callback_("glLogicOp", (void*)(ptrdiff_t)glow_glLogicOp, opcode);
}
PFNGLLOGICOPPROC glow_debug_glLogicOp = glow_debug_impl_glLogicOp;

static void glow_debug_impl_glMatrixMode(GLenum mode) {

  glow_pre_callback_("glMatrixMode", (void*)(ptrdiff_t)glow_glMatrixMode, mode);
  glow_glMatrixMode(mode);
  glow_post_callback_("glMatrixMode", (void*)(ptrdiff_t)glow_glMatrixMode, mode);
}
PFNGLMATRIXMODEPROC glow_debug_glMatrixMode = glow_debug_impl_glMatrixMode;

static void glow_debug_impl_glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetBufferParameteriv", (void*)(ptrdiff_t)glow_glGetBufferParameteriv, target, pname, params);
  glow_glGetBufferParameteriv(target, pname, params);
  glow_post_callback_("glGetBufferParameteriv", (void*)(ptrdiff_t)glow_glGetBufferParameteriv, target, pname, params);
}
PFNGLGETBUFFERPARAMETERIVPROC glow_debug_glGetBufferParameteriv = glow_debug_impl_glGetBufferParameteriv;

static void glow_debug_impl_glGetMaterialxv(GLenum face, GLenum pname, GLfixed *params) {

  glow_pre_callback_("glGetMaterialxv", (void*)(ptrdiff_t)glow_glGetMaterialxv, face, pname, params);
  glow_glGetMaterialxv(face, pname, params);
  glow_post_callback_("glGetMaterialxv", (void*)(ptrdiff_t)glow_glGetMaterialxv, face, pname, params);
}
PFNGLGETMATERIALXVPROC glow_debug_glGetMaterialxv = glow_debug_impl_glGetMaterialxv;

static void glow_debug_impl_glPopMatrix() {

  glow_pre_callback_("glPopMatrix", (void*)(ptrdiff_t)glow_glPopMatrix);
  glow_glPopMatrix();
  glow_post_callback_("glPopMatrix", (void*)(ptrdiff_t)glow_glPopMatrix);
}
PFNGLPOPMATRIXPROC glow_debug_glPopMatrix = glow_debug_impl_glPopMatrix;

static void glow_debug_impl_glDeleteBuffers(GLsizei n, const GLuint *buffers) {

  glow_pre_callback_("glDeleteBuffers", (void*)(ptrdiff_t)glow_glDeleteBuffers, n, buffers);
  glow_glDeleteBuffers(n, buffers);
  glow_post_callback_("glDeleteBuffers", (void*)(ptrdiff_t)glow_glDeleteBuffers, n, buffers);
}
PFNGLDELETEBUFFERSPROC glow_debug_glDeleteBuffers = glow_debug_impl_glDeleteBuffers;

static void glow_debug_impl_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {

  glow_pre_callback_("glClearColor", (void*)(ptrdiff_t)glow_glClearColor, red, green, blue, alpha);
  glow_glClearColor(red, green, blue, alpha);
  glow_post_callback_("glClearColor", (void*)(ptrdiff_t)glow_glClearColor, red, green, blue, alpha);
}
PFNGLCLEARCOLORPROC glow_debug_glClearColor = glow_debug_impl_glClearColor;

static void glow_debug_impl_glDepthRangef(GLfloat n, GLfloat f) {

  glow_pre_callback_("glDepthRangef", (void*)(ptrdiff_t)glow_glDepthRangef, n, f);
  glow_glDepthRangef(n, f);
  glow_post_callback_("glDepthRangef", (void*)(ptrdiff_t)glow_glDepthRangef, n, f);
}
PFNGLDEPTHRANGEFPROC glow_debug_glDepthRangef = glow_debug_impl_glDepthRangef;

static void glow_debug_impl_glMaterialf(GLenum face, GLenum pname, GLfloat param) {

  glow_pre_callback_("glMaterialf", (void*)(ptrdiff_t)glow_glMaterialf, face, pname, param);
  glow_glMaterialf(face, pname, param);
  glow_post_callback_("glMaterialf", (void*)(ptrdiff_t)glow_glMaterialf, face, pname, param);
}
PFNGLMATERIALFPROC glow_debug_glMaterialf = glow_debug_impl_glMaterialf;

static void glow_debug_impl_glMultMatrixf(const GLfloat *m) {

  glow_pre_callback_("glMultMatrixf", (void*)(ptrdiff_t)glow_glMultMatrixf, m);
  glow_glMultMatrixf(m);
  glow_post_callback_("glMultMatrixf", (void*)(ptrdiff_t)glow_glMultMatrixf, m);
}
PFNGLMULTMATRIXFPROC glow_debug_glMultMatrixf = glow_debug_impl_glMultMatrixf;

static void glow_debug_impl_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {

  glow_pre_callback_("glNormal3f", (void*)(ptrdiff_t)glow_glNormal3f, nx, ny, nz);
  glow_glNormal3f(nx, ny, nz);
  glow_post_callback_("glNormal3f", (void*)(ptrdiff_t)glow_glNormal3f, nx, ny, nz);
}
PFNGLNORMAL3FPROC glow_debug_glNormal3f = glow_debug_impl_glNormal3f;

static void glow_debug_impl_glPolygonOffset(GLfloat factor, GLfloat units) {

  glow_pre_callback_("glPolygonOffset", (void*)(ptrdiff_t)glow_glPolygonOffset, factor, units);
  glow_glPolygonOffset(factor, units);
  glow_post_callback_("glPolygonOffset", (void*)(ptrdiff_t)glow_glPolygonOffset, factor, units);
}
PFNGLPOLYGONOFFSETPROC glow_debug_glPolygonOffset = glow_debug_impl_glPolygonOffset;

static void glow_debug_impl_glClearStencil(GLint s) {

  glow_pre_callback_("glClearStencil", (void*)(ptrdiff_t)glow_glClearStencil, s);
  glow_glClearStencil(s);
  glow_post_callback_("glClearStencil", (void*)(ptrdiff_t)glow_glClearStencil, s);
}
PFNGLCLEARSTENCILPROC glow_debug_glClearStencil = glow_debug_impl_glClearStencil;

static void glow_debug_impl_glDepthFunc(GLenum func) {

  glow_pre_callback_("glDepthFunc", (void*)(ptrdiff_t)glow_glDepthFunc, func);
  glow_glDepthFunc(func);
  glow_post_callback_("glDepthFunc", (void*)(ptrdiff_t)glow_glDepthFunc, func);
}
PFNGLDEPTHFUNCPROC glow_debug_glDepthFunc = glow_debug_impl_glDepthFunc;

static void glow_debug_impl_glDisable(GLenum cap) {

  glow_pre_callback_("glDisable", (void*)(ptrdiff_t)glow_glDisable, cap);
  glow_glDisable(cap);
  glow_post_callback_("glDisable", (void*)(ptrdiff_t)glow_glDisable, cap);
}
PFNGLDISABLEPROC glow_debug_glDisable = glow_debug_impl_glDisable;

static void glow_debug_impl_glLightx(GLenum light, GLenum pname, GLfixed param) {

  glow_pre_callback_("glLightx", (void*)(ptrdiff_t)glow_glLightx, light, pname, param);
  glow_glLightx(light, pname, param);
  glow_post_callback_("glLightx", (void*)(ptrdiff_t)glow_glLightx, light, pname, param);
}
PFNGLLIGHTXPROC glow_debug_glLightx = glow_debug_impl_glLightx;

static void glow_debug_impl_glAlphaFuncx(GLenum func, GLfixed ref) {

  glow_pre_callback_("glAlphaFuncx", (void*)(ptrdiff_t)glow_glAlphaFuncx, func, ref);
  glow_glAlphaFuncx(func, ref);
  glow_post_callback_("glAlphaFuncx", (void*)(ptrdiff_t)glow_glAlphaFuncx, func, ref);
}
PFNGLALPHAFUNCXPROC glow_debug_glAlphaFuncx = glow_debug_impl_glAlphaFuncx;

static void glow_debug_impl_glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {

  glow_pre_callback_("glColor4x", (void*)(ptrdiff_t)glow_glColor4x, red, green, blue, alpha);
  glow_glColor4x(red, green, blue, alpha);
  glow_post_callback_("glColor4x", (void*)(ptrdiff_t)glow_glColor4x, red, green, blue, alpha);
}
PFNGLCOLOR4XPROC glow_debug_glColor4x = glow_debug_impl_glColor4x;

static void glow_debug_impl_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) {

  glow_pre_callback_("glCompressedTexSubImage2D", (void*)(ptrdiff_t)glow_glCompressedTexSubImage2D, target, level, xoffset, yoffset, width, height, format, imageSize, data);
  glow_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
  glow_post_callback_("glCompressedTexSubImage2D", (void*)(ptrdiff_t)glow_glCompressedTexSubImage2D, target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glow_debug_glCompressedTexSubImage2D = glow_debug_impl_glCompressedTexSubImage2D;

static void glow_debug_impl_glTexParameterxv(GLenum target, GLenum pname, const GLfixed *params) {

  glow_pre_callback_("glTexParameterxv", (void*)(ptrdiff_t)glow_glTexParameterxv, target, pname, params);
  glow_glTexParameterxv(target, pname, params);
  glow_post_callback_("glTexParameterxv", (void*)(ptrdiff_t)glow_glTexParameterxv, target, pname, params);
}
PFNGLTEXPARAMETERXVPROC glow_debug_glTexParameterxv = glow_debug_impl_glTexParameterxv;

static void glow_debug_impl_glClipPlanex(GLenum plane, const GLfixed *equation) {

  glow_pre_callback_("glClipPlanex", (void*)(ptrdiff_t)glow_glClipPlanex, plane, equation);
  glow_glClipPlanex(plane, equation);
  glow_post_callback_("glClipPlanex", (void*)(ptrdiff_t)glow_glClipPlanex, plane, equation);
}
PFNGLCLIPPLANEXPROC glow_debug_glClipPlanex = glow_debug_impl_glClipPlanex;

static void glow_debug_impl_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {

  glow_pre_callback_("glCopyTexImage2D", (void*)(ptrdiff_t)glow_glCopyTexImage2D, target, level, internalformat, x, y, width, height, border);
  glow_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
  glow_post_callback_("glCopyTexImage2D", (void*)(ptrdiff_t)glow_glCopyTexImage2D, target, level, internalformat, x, y, width, height, border);
}
PFNGLCOPYTEXIMAGE2DPROC glow_debug_glCopyTexImage2D = glow_debug_impl_glCopyTexImage2D;

static void glow_debug_impl_glFrontFace(GLenum mode) {

  glow_pre_callback_("glFrontFace", (void*)(ptrdiff_t)glow_glFrontFace, mode);
  glow_glFrontFace(mode);
  glow_post_callback_("glFrontFace", (void*)(ptrdiff_t)glow_glFrontFace, mode);
}
PFNGLFRONTFACEPROC glow_debug_glFrontFace = glow_debug_impl_glFrontFace;

static void glow_debug_impl_glGenBuffers(GLsizei n, GLuint *buffers) {

  glow_pre_callback_("glGenBuffers", (void*)(ptrdiff_t)glow_glGenBuffers, n, buffers);
  glow_glGenBuffers(n, buffers);
  glow_post_callback_("glGenBuffers", (void*)(ptrdiff_t)glow_glGenBuffers, n, buffers);
}
PFNGLGENBUFFERSPROC glow_debug_glGenBuffers = glow_debug_impl_glGenBuffers;

static void glow_debug_impl_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {

  glow_pre_callback_("glStencilOp", (void*)(ptrdiff_t)glow_glStencilOp, fail, zfail, zpass);
  glow_glStencilOp(fail, zfail, zpass);
  glow_post_callback_("glStencilOp", (void*)(ptrdiff_t)glow_glStencilOp, fail, zfail, zpass);
}
PFNGLSTENCILOPPROC glow_debug_glStencilOp = glow_debug_impl_glStencilOp;

static void glow_debug_impl_glTexParameterx(GLenum target, GLenum pname, GLfixed param) {

  glow_pre_callback_("glTexParameterx", (void*)(ptrdiff_t)glow_glTexParameterx, target, pname, param);
  glow_glTexParameterx(target, pname, param);
  glow_post_callback_("glTexParameterx", (void*)(ptrdiff_t)glow_glTexParameterx, target, pname, param);
}
PFNGLTEXPARAMETERXPROC glow_debug_glTexParameterx = glow_debug_impl_glTexParameterx;

static void glow_debug_impl_glTexParameteriv(GLenum target, GLenum pname, const GLint *params) {

  glow_pre_callback_("glTexParameteriv", (void*)(ptrdiff_t)glow_glTexParameteriv, target, pname, params);
  glow_glTexParameteriv(target, pname, params);
  glow_post_callback_("glTexParameteriv", (void*)(ptrdiff_t)glow_glTexParameteriv, target, pname, params);
}
PFNGLTEXPARAMETERIVPROC glow_debug_glTexParameteriv = glow_debug_impl_glTexParameteriv;

static void glow_debug_impl_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) {

  glow_pre_callback_("glBufferSubData", (void*)(ptrdiff_t)glow_glBufferSubData, target, offset, size, data);
  glow_glBufferSubData(target, offset, size, data);
  glow_post_callback_("glBufferSubData", (void*)(ptrdiff_t)glow_glBufferSubData, target, offset, size, data);
}
PFNGLBUFFERSUBDATAPROC glow_debug_glBufferSubData = glow_debug_impl_glBufferSubData;

static void glow_debug_impl_glClearColorx(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {

  glow_pre_callback_("glClearColorx", (void*)(ptrdiff_t)glow_glClearColorx, red, green, blue, alpha);
  glow_glClearColorx(red, green, blue, alpha);
  glow_post_callback_("glClearColorx", (void*)(ptrdiff_t)glow_glClearColorx, red, green, blue, alpha);
}
PFNGLCLEARCOLORXPROC glow_debug_glClearColorx = glow_debug_impl_glClearColorx;

static void glow_debug_impl_glPushMatrix() {

  glow_pre_callback_("glPushMatrix", (void*)(ptrdiff_t)glow_glPushMatrix);
  glow_glPushMatrix();
  glow_post_callback_("glPushMatrix", (void*)(ptrdiff_t)glow_glPushMatrix);
}
PFNGLPUSHMATRIXPROC glow_debug_glPushMatrix = glow_debug_impl_glPushMatrix;

static void glow_debug_impl_glTexEnvx(GLenum target, GLenum pname, GLfixed param) {

  glow_pre_callback_("glTexEnvx", (void*)(ptrdiff_t)glow_glTexEnvx, target, pname, param);
  glow_glTexEnvx(target, pname, param);
  glow_post_callback_("glTexEnvx", (void*)(ptrdiff_t)glow_glTexEnvx, target, pname, param);
}
PFNGLTEXENVXPROC glow_debug_glTexEnvx = glow_debug_impl_glTexEnvx;

static void glow_debug_impl_glLightModelfv(GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glLightModelfv", (void*)(ptrdiff_t)glow_glLightModelfv, pname, params);
  glow_glLightModelfv(pname, params);
  glow_post_callback_("glLightModelfv", (void*)(ptrdiff_t)glow_glLightModelfv, pname, params);
}
PFNGLLIGHTMODELFVPROC glow_debug_glLightModelfv = glow_debug_impl_glLightModelfv;

static void glow_debug_impl_glGetFloatv(GLenum pname, GLfloat *data) {

  glow_pre_callback_("glGetFloatv", (void*)(ptrdiff_t)glow_glGetFloatv, pname, data);
  glow_glGetFloatv(pname, data);
  glow_post_callback_("glGetFloatv", (void*)(ptrdiff_t)glow_glGetFloatv, pname, data);
}
PFNGLGETFLOATVPROC glow_debug_glGetFloatv = glow_debug_impl_glGetFloatv;

static void glow_debug_impl_glLoadMatrixf(const GLfloat *m) {

  glow_pre_callback_("glLoadMatrixf", (void*)(ptrdiff_t)glow_glLoadMatrixf, m);
  glow_glLoadMatrixf(m);
  glow_post_callback_("glLoadMatrixf", (void*)(ptrdiff_t)glow_glLoadMatrixf, m);
}
PFNGLLOADMATRIXFPROC glow_debug_glLoadMatrixf = glow_debug_impl_glLoadMatrixf;

static void glow_debug_impl_glPointParameterf(GLenum pname, GLfloat param) {

  glow_pre_callback_("glPointParameterf", (void*)(ptrdiff_t)glow_glPointParameterf, pname, param);
  glow_glPointParameterf(pname, param);
  glow_post_callback_("glPointParameterf", (void*)(ptrdiff_t)glow_glPointParameterf, pname, param);
}
PFNGLPOINTPARAMETERFPROC glow_debug_glPointParameterf = glow_debug_impl_glPointParameterf;

static void glow_debug_impl_glPolygonOffsetx(GLfixed factor, GLfixed units) {

  glow_pre_callback_("glPolygonOffsetx", (void*)(ptrdiff_t)glow_glPolygonOffsetx, factor, units);
  glow_glPolygonOffsetx(factor, units);
  glow_post_callback_("glPolygonOffsetx", (void*)(ptrdiff_t)glow_glPolygonOffsetx, factor, units);
}
PFNGLPOLYGONOFFSETXPROC glow_debug_glPolygonOffsetx = glow_debug_impl_glPolygonOffsetx;

static void glow_debug_impl_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) {

  glow_pre_callback_("glCompressedTexImage2D", (void*)(ptrdiff_t)glow_glCompressedTexImage2D, target, level, internalformat, width, height, border, imageSize, data);
  glow_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
  glow_post_callback_("glCompressedTexImage2D", (void*)(ptrdiff_t)glow_glCompressedTexImage2D, target, level, internalformat, width, height, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE2DPROC glow_debug_glCompressedTexImage2D = glow_debug_impl_glCompressedTexImage2D;

static void glow_debug_impl_glLightModelx(GLenum pname, GLfixed param) {

  glow_pre_callback_("glLightModelx", (void*)(ptrdiff_t)glow_glLightModelx, pname, param);
  glow_glLightModelx(pname, param);
  glow_post_callback_("glLightModelx", (void*)(ptrdiff_t)glow_glLightModelx, pname, param);
}
PFNGLLIGHTMODELXPROC glow_debug_glLightModelx = glow_debug_impl_glLightModelx;

static void glow_debug_impl_glVertexPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) {

  glow_pre_callback_("glVertexPointer", (void*)(ptrdiff_t)glow_glVertexPointer, size, type, stride, pointer);
  glow_glVertexPointer(size, type, stride, pointer);
  glow_post_callback_("glVertexPointer", (void*)(ptrdiff_t)glow_glVertexPointer, size, type, stride, pointer);
}
PFNGLVERTEXPOINTERPROC glow_debug_glVertexPointer = glow_debug_impl_glVertexPointer;

static void glow_debug_impl_glNormalPointer(GLenum type, GLsizei stride, const void *pointer) {

  glow_pre_callback_("glNormalPointer", (void*)(ptrdiff_t)glow_glNormalPointer, type, stride, pointer);
  glow_glNormalPointer(type, stride, pointer);
  glow_post_callback_("glNormalPointer", (void*)(ptrdiff_t)glow_glNormalPointer, type, stride, pointer);
}
PFNGLNORMALPOINTERPROC glow_debug_glNormalPointer = glow_debug_impl_glNormalPointer;

static void glow_debug_impl_glLightModelxv(GLenum pname, const GLfixed *param) {

  glow_pre_callback_("glLightModelxv", (void*)(ptrdiff_t)glow_glLightModelxv, pname, param);
  glow_glLightModelxv(pname, param);
  glow_post_callback_("glLightModelxv", (void*)(ptrdiff_t)glow_glLightModelxv, pname, param);
}
PFNGLLIGHTMODELXVPROC glow_debug_glLightModelxv = glow_debug_impl_glLightModelxv;

static void glow_debug_impl_glFrustumf(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {

  glow_pre_callback_("glFrustumf", (void*)(ptrdiff_t)glow_glFrustumf, l, r, b, t, n, f);
  glow_glFrustumf(l, r, b, t, n, f);
  glow_post_callback_("glFrustumf", (void*)(ptrdiff_t)glow_glFrustumf, l, r, b, t, n, f);
}
PFNGLFRUSTUMFPROC glow_debug_glFrustumf = glow_debug_impl_glFrustumf;

static void glow_debug_impl_glLightModelf(GLenum pname, GLfloat param) {

  glow_pre_callback_("glLightModelf", (void*)(ptrdiff_t)glow_glLightModelf, pname, param);
  glow_glLightModelf(pname, param);
  glow_post_callback_("glLightModelf", (void*)(ptrdiff_t)glow_glLightModelf, pname, param);
}
PFNGLLIGHTMODELFPROC glow_debug_glLightModelf = glow_debug_impl_glLightModelf;

static void glow_debug_impl_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glTexEnvfv", (void*)(ptrdiff_t)glow_glTexEnvfv, target, pname, params);
  glow_glTexEnvfv(target, pname, params);
  glow_post_callback_("glTexEnvfv", (void*)(ptrdiff_t)glow_glTexEnvfv, target, pname, params);
}
PFNGLTEXENVFVPROC glow_debug_glTexEnvfv = glow_debug_impl_glTexEnvfv;

static void glow_debug_impl_glDepthRangex(GLfixed n, GLfixed f) {

  glow_pre_callback_("glDepthRangex", (void*)(ptrdiff_t)glow_glDepthRangex, n, f);
  glow_glDepthRangex(n, f);
  glow_post_callback_("glDepthRangex", (void*)(ptrdiff_t)glow_glDepthRangex, n, f);
}
PFNGLDEPTHRANGEXPROC glow_debug_glDepthRangex = glow_debug_impl_glDepthRangex;

static void glow_debug_impl_glEnable(GLenum cap) {

  glow_pre_callback_("glEnable", (void*)(ptrdiff_t)glow_glEnable, cap);
  glow_glEnable(cap);
  glow_post_callback_("glEnable", (void*)(ptrdiff_t)glow_glEnable, cap);
}
PFNGLENABLEPROC glow_debug_glEnable = glow_debug_impl_glEnable;

static void glow_debug_impl_glFinish() {

  glow_pre_callback_("glFinish", (void*)(ptrdiff_t)glow_glFinish);
  glow_glFinish();
  glow_post_callback_("glFinish", (void*)(ptrdiff_t)glow_glFinish);
}
PFNGLFINISHPROC glow_debug_glFinish = glow_debug_impl_glFinish;

static void glow_debug_impl_glHint(GLenum target, GLenum mode) {

  glow_pre_callback_("glHint", (void*)(ptrdiff_t)glow_glHint, target, mode);
  glow_glHint(target, mode);
  glow_post_callback_("glHint", (void*)(ptrdiff_t)glow_glHint, target, mode);
}
PFNGLHINTPROC glow_debug_glHint = glow_debug_impl_glHint;

static void glow_debug_impl_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) {

  glow_pre_callback_("glReadPixels", (void*)(ptrdiff_t)glow_glReadPixels, x, y, width, height, format, type, pixels);
  glow_glReadPixels(x, y, width, height, format, type, pixels);
  glow_post_callback_("glReadPixels", (void*)(ptrdiff_t)glow_glReadPixels, x, y, width, height, format, type, pixels);
}
PFNGLREADPIXELSPROC glow_debug_glReadPixels = glow_debug_impl_glReadPixels;

static void glow_debug_impl_glStencilMask(GLuint mask) {

  glow_pre_callback_("glStencilMask", (void*)(ptrdiff_t)glow_glStencilMask, mask);
  glow_glStencilMask(mask);
  glow_post_callback_("glStencilMask", (void*)(ptrdiff_t)glow_glStencilMask, mask);
}
PFNGLSTENCILMASKPROC glow_debug_glStencilMask = glow_debug_impl_glStencilMask;

static void glow_debug_impl_glGetLightxv(GLenum light, GLenum pname, GLfixed *params) {

  glow_pre_callback_("glGetLightxv", (void*)(ptrdiff_t)glow_glGetLightxv, light, pname, params);
  glow_glGetLightxv(light, pname, params);
  glow_post_callback_("glGetLightxv", (void*)(ptrdiff_t)glow_glGetLightxv, light, pname, params);
}
PFNGLGETLIGHTXVPROC glow_debug_glGetLightxv = glow_debug_impl_glGetLightxv;

static void glow_debug_impl_glOrthox(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {

  glow_pre_callback_("glOrthox", (void*)(ptrdiff_t)glow_glOrthox, l, r, b, t, n, f);
  glow_glOrthox(l, r, b, t, n, f);
  glow_post_callback_("glOrthox", (void*)(ptrdiff_t)glow_glOrthox, l, r, b, t, n, f);
}
PFNGLORTHOXPROC glow_debug_glOrthox = glow_debug_impl_glOrthox;

static void glow_debug_impl_glPixelStorei(GLenum pname, GLint param) {

  glow_pre_callback_("glPixelStorei", (void*)(ptrdiff_t)glow_glPixelStorei, pname, param);
  glow_glPixelStorei(pname, param);
  glow_post_callback_("glPixelStorei", (void*)(ptrdiff_t)glow_glPixelStorei, pname, param);
}
PFNGLPIXELSTOREIPROC glow_debug_glPixelStorei = glow_debug_impl_glPixelStorei;

static void glow_debug_impl_glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {

  glow_pre_callback_("glRotatex", (void*)(ptrdiff_t)glow_glRotatex, angle, x, y, z);
  glow_glRotatex(angle, x, y, z);
  glow_post_callback_("glRotatex", (void*)(ptrdiff_t)glow_glRotatex, angle, x, y, z);
}
PFNGLROTATEXPROC glow_debug_glRotatex = glow_debug_impl_glRotatex;

static void glow_debug_impl_glSampleCoveragex(GLclampx value, GLboolean invert) {

  glow_pre_callback_("glSampleCoveragex", (void*)(ptrdiff_t)glow_glSampleCoveragex, value, invert);
  glow_glSampleCoveragex(value, invert);
  glow_post_callback_("glSampleCoveragex", (void*)(ptrdiff_t)glow_glSampleCoveragex, value, invert);
}
PFNGLSAMPLECOVERAGEXPROC glow_debug_glSampleCoveragex = glow_debug_impl_glSampleCoveragex;

static void glow_debug_impl_glScalex(GLfixed x, GLfixed y, GLfixed z) {

  glow_pre_callback_("glScalex", (void*)(ptrdiff_t)glow_glScalex, x, y, z);
  glow_glScalex(x, y, z);
  glow_post_callback_("glScalex", (void*)(ptrdiff_t)glow_glScalex, x, y, z);
}
PFNGLSCALEXPROC glow_debug_glScalex = glow_debug_impl_glScalex;

static void glow_debug_impl_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glScissor", (void*)(ptrdiff_t)glow_glScissor, x, y, width, height);
  glow_glScissor(x, y, width, height);
  glow_post_callback_("glScissor", (void*)(ptrdiff_t)glow_glScissor, x, y, width, height);
}
PFNGLSCISSORPROC glow_debug_glScissor = glow_debug_impl_glScissor;

static void glow_debug_impl_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {

  glow_pre_callback_("glMultiTexCoord4f", (void*)(ptrdiff_t)glow_glMultiTexCoord4f, target, s, t, r, q);
  glow_glMultiTexCoord4f(target, s, t, r, q);
  glow_post_callback_("glMultiTexCoord4f", (void*)(ptrdiff_t)glow_glMultiTexCoord4f, target, s, t, r, q);
}
PFNGLMULTITEXCOORD4FPROC glow_debug_glMultiTexCoord4f = glow_debug_impl_glMultiTexCoord4f;

static void glow_debug_impl_glPointParameterfv(GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glPointParameterfv", (void*)(ptrdiff_t)glow_glPointParameterfv, pname, params);
  glow_glPointParameterfv(pname, params);
  glow_post_callback_("glPointParameterfv", (void*)(ptrdiff_t)glow_glPointParameterfv, pname, params);
}
PFNGLPOINTPARAMETERFVPROC glow_debug_glPointParameterfv = glow_debug_impl_glPointParameterfv;

static void glow_debug_impl_glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) {

  glow_pre_callback_("glBufferData", (void*)(ptrdiff_t)glow_glBufferData, target, size, data, usage);
  glow_glBufferData(target, size, data, usage);
  glow_post_callback_("glBufferData", (void*)(ptrdiff_t)glow_glBufferData, target, size, data, usage);
}
PFNGLBUFFERDATAPROC glow_debug_glBufferData = glow_debug_impl_glBufferData;

static void glow_debug_impl_glTexParameteri(GLenum target, GLenum pname, GLint param) {

  glow_pre_callback_("glTexParameteri", (void*)(ptrdiff_t)glow_glTexParameteri, target, pname, param);
  glow_glTexParameteri(target, pname, param);
  glow_post_callback_("glTexParameteri", (void*)(ptrdiff_t)glow_glTexParameteri, target, pname, param);
}
PFNGLTEXPARAMETERIPROC glow_debug_glTexParameteri = glow_debug_impl_glTexParameteri;

static void glow_debug_impl_glClientActiveTexture(GLenum texture) {

  glow_pre_callback_("glClientActiveTexture", (void*)(ptrdiff_t)glow_glClientActiveTexture, texture);
  glow_glClientActiveTexture(texture);
  glow_post_callback_("glClientActiveTexture", (void*)(ptrdiff_t)glow_glClientActiveTexture, texture);
}
PFNGLCLIENTACTIVETEXTUREPROC glow_debug_glClientActiveTexture = glow_debug_impl_glClientActiveTexture;

static void glow_debug_impl_glMultMatrixx(const GLfixed *m) {

  glow_pre_callback_("glMultMatrixx", (void*)(ptrdiff_t)glow_glMultMatrixx, m);
  glow_glMultMatrixx(m);
  glow_post_callback_("glMultMatrixx", (void*)(ptrdiff_t)glow_glMultMatrixx, m);
}
PFNGLMULTMATRIXXPROC glow_debug_glMultMatrixx = glow_debug_impl_glMultMatrixx;

static void glow_debug_impl_glLightf(GLenum light, GLenum pname, GLfloat param) {

  glow_pre_callback_("glLightf", (void*)(ptrdiff_t)glow_glLightf, light, pname, param);
  glow_glLightf(light, pname, param);
  glow_post_callback_("glLightf", (void*)(ptrdiff_t)glow_glLightf, light, pname, param);
}
PFNGLLIGHTFPROC glow_debug_glLightf = glow_debug_impl_glLightf;

static void glow_debug_impl_glLineWidth(GLfloat width) {

  glow_pre_callback_("glLineWidth", (void*)(ptrdiff_t)glow_glLineWidth, width);
  glow_glLineWidth(width);
  glow_post_callback_("glLineWidth", (void*)(ptrdiff_t)glow_glLineWidth, width);
}
PFNGLLINEWIDTHPROC glow_debug_glLineWidth = glow_debug_impl_glLineWidth;

static void glow_debug_impl_glClear(GLbitfield mask) {

  glow_pre_callback_("glClear", (void*)(ptrdiff_t)glow_glClear, mask);
  glow_glClear(mask);
  glow_post_callback_("glClear", (void*)(ptrdiff_t)glow_glClear, mask);
}
PFNGLCLEARPROC glow_debug_glClear = glow_debug_impl_glClear;

static void glow_debug_impl_glDisableClientState(GLenum array) {

  glow_pre_callback_("glDisableClientState", (void*)(ptrdiff_t)glow_glDisableClientState, array);
  glow_glDisableClientState(array);
  glow_post_callback_("glDisableClientState", (void*)(ptrdiff_t)glow_glDisableClientState, array);
}
PFNGLDISABLECLIENTSTATEPROC glow_debug_glDisableClientState = glow_debug_impl_glDisableClientState;

static void glow_debug_impl_glGetIntegerv(GLenum pname, GLint *data) {

  glow_pre_callback_("glGetIntegerv", (void*)(ptrdiff_t)glow_glGetIntegerv, pname, data);
  glow_glGetIntegerv(pname, data);
  glow_post_callback_("glGetIntegerv", (void*)(ptrdiff_t)glow_glGetIntegerv, pname, data);
}
PFNGLGETINTEGERVPROC glow_debug_glGetIntegerv = glow_debug_impl_glGetIntegerv;

static void glow_debug_impl_glMaterialx(GLenum face, GLenum pname, GLfixed param) {

  glow_pre_callback_("glMaterialx", (void*)(ptrdiff_t)glow_glMaterialx, face, pname, param);
  glow_glMaterialx(face, pname, param);
  glow_post_callback_("glMaterialx", (void*)(ptrdiff_t)glow_glMaterialx, face, pname, param);
}
PFNGLMATERIALXPROC glow_debug_glMaterialx = glow_debug_impl_glMaterialx;

static void glow_debug_impl_glAlphaFunc(GLenum func, GLfloat ref) {

  glow_pre_callback_("glAlphaFunc", (void*)(ptrdiff_t)glow_glAlphaFunc, func, ref);
  glow_glAlphaFunc(func, ref);
  glow_post_callback_("glAlphaFunc", (void*)(ptrdiff_t)glow_glAlphaFunc, func, ref);
}
PFNGLALPHAFUNCPROC glow_debug_glAlphaFunc = glow_debug_impl_glAlphaFunc;

static void glow_debug_impl_glClipPlanef(GLenum p, const GLfloat *eqn) {

  glow_pre_callback_("glClipPlanef", (void*)(ptrdiff_t)glow_glClipPlanef, p, eqn);
  glow_glClipPlanef(p, eqn);
  glow_post_callback_("glClipPlanef", (void*)(ptrdiff_t)glow_glClipPlanef, p, eqn);
}
PFNGLCLIPPLANEFPROC glow_debug_glClipPlanef = glow_debug_impl_glClipPlanef;

static void glow_debug_impl_glStencilFunc(GLenum func, GLint ref, GLuint mask) {

  glow_pre_callback_("glStencilFunc", (void*)(ptrdiff_t)glow_glStencilFunc, func, ref, mask);
  glow_glStencilFunc(func, ref, mask);
  glow_post_callback_("glStencilFunc", (void*)(ptrdiff_t)glow_glStencilFunc, func, ref, mask);
}
PFNGLSTENCILFUNCPROC glow_debug_glStencilFunc = glow_debug_impl_glStencilFunc;

static void glow_debug_impl_glLightfv(GLenum light, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glLightfv", (void*)(ptrdiff_t)glow_glLightfv, light, pname, params);
  glow_glLightfv(light, pname, params);
  glow_post_callback_("glLightfv", (void*)(ptrdiff_t)glow_glLightfv, light, pname, params);
}
PFNGLLIGHTFVPROC glow_debug_glLightfv = glow_debug_impl_glLightfv;

static void glow_debug_impl_glTranslatef(GLfloat x, GLfloat y, GLfloat z) {

  glow_pre_callback_("glTranslatef", (void*)(ptrdiff_t)glow_glTranslatef, x, y, z);
  glow_glTranslatef(x, y, z);
  glow_post_callback_("glTranslatef", (void*)(ptrdiff_t)glow_glTranslatef, x, y, z);
}
PFNGLTRANSLATEFPROC glow_debug_glTranslatef = glow_debug_impl_glTranslatef;

static void glow_debug_impl_glGenTextures(GLsizei n, GLuint *textures) {

  glow_pre_callback_("glGenTextures", (void*)(ptrdiff_t)glow_glGenTextures, n, textures);
  glow_glGenTextures(n, textures);
  glow_post_callback_("glGenTextures", (void*)(ptrdiff_t)glow_glGenTextures, n, textures);
}
PFNGLGENTEXTURESPROC glow_debug_glGenTextures = glow_debug_impl_glGenTextures;

static GLboolean glow_debug_impl_glIsBuffer(GLuint buffer) {

  GLboolean ret;
  glow_pre_callback_("glIsBuffer", (void*)(ptrdiff_t)glow_glIsBuffer, buffer);
  ret = glow_glIsBuffer(buffer);
  glow_post_callback_("glIsBuffer", (void*)(ptrdiff_t)glow_glIsBuffer, buffer);
  return ret;
}
PFNGLISBUFFERPROC glow_debug_glIsBuffer = glow_debug_impl_glIsBuffer;

static void glow_debug_impl_glPointParameterx(GLenum pname, GLfixed param) {

  glow_pre_callback_("glPointParameterx", (void*)(ptrdiff_t)glow_glPointParameterx, pname, param);
  glow_glPointParameterx(pname, param);
  glow_post_callback_("glPointParameterx", (void*)(ptrdiff_t)glow_glPointParameterx, pname, param);
}
PFNGLPOINTPARAMETERXPROC glow_debug_glPointParameterx = glow_debug_impl_glPointParameterx;

static void glow_debug_impl_glTexEnviv(GLenum target, GLenum pname, const GLint *params) {

  glow_pre_callback_("glTexEnviv", (void*)(ptrdiff_t)glow_glTexEnviv, target, pname, params);
  glow_glTexEnviv(target, pname, params);
  glow_post_callback_("glTexEnviv", (void*)(ptrdiff_t)glow_glTexEnviv, target, pname, params);
}
PFNGLTEXENVIVPROC glow_debug_glTexEnviv = glow_debug_impl_glTexEnviv;

static void glow_debug_impl_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetTexEnvfv", (void*)(ptrdiff_t)glow_glGetTexEnvfv, target, pname, params);
  glow_glGetTexEnvfv(target, pname, params);
  glow_post_callback_("glGetTexEnvfv", (void*)(ptrdiff_t)glow_glGetTexEnvfv, target, pname, params);
}
PFNGLGETTEXENVFVPROC glow_debug_glGetTexEnvfv = glow_debug_impl_glGetTexEnvfv;

static void glow_debug_impl_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {

  glow_pre_callback_("glRotatef", (void*)(ptrdiff_t)glow_glRotatef, angle, x, y, z);
  glow_glRotatef(angle, x, y, z);
  glow_post_callback_("glRotatef", (void*)(ptrdiff_t)glow_glRotatef, angle, x, y, z);
}
PFNGLROTATEFPROC glow_debug_glRotatef = glow_debug_impl_glRotatef;

static void glow_debug_impl_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {

  glow_pre_callback_("glTexParameterf", (void*)(ptrdiff_t)glow_glTexParameterf, target, pname, param);
  glow_glTexParameterf(target, pname, param);
  glow_post_callback_("glTexParameterf", (void*)(ptrdiff_t)glow_glTexParameterf, target, pname, param);
}
PFNGLTEXPARAMETERFPROC glow_debug_glTexParameterf = glow_debug_impl_glTexParameterf;

static void glow_debug_impl_glDrawArrays(GLenum mode, GLint first, GLsizei count) {

  glow_pre_callback_("glDrawArrays", (void*)(ptrdiff_t)glow_glDrawArrays, mode, first, count);
  glow_glDrawArrays(mode, first, count);
  glow_post_callback_("glDrawArrays", (void*)(ptrdiff_t)glow_glDrawArrays, mode, first, count);
}
PFNGLDRAWARRAYSPROC glow_debug_glDrawArrays = glow_debug_impl_glDrawArrays;

static void glow_debug_impl_glGetTexEnviv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetTexEnviv", (void*)(ptrdiff_t)glow_glGetTexEnviv, target, pname, params);
  glow_glGetTexEnviv(target, pname, params);
  glow_post_callback_("glGetTexEnviv", (void*)(ptrdiff_t)glow_glGetTexEnviv, target, pname, params);
}
PFNGLGETTEXENVIVPROC glow_debug_glGetTexEnviv = glow_debug_impl_glGetTexEnviv;

static GLboolean glow_debug_impl_glIsTexture(GLuint texture) {

  GLboolean ret;
  glow_pre_callback_("glIsTexture", (void*)(ptrdiff_t)glow_glIsTexture, texture);
  ret = glow_glIsTexture(texture);
  glow_post_callback_("glIsTexture", (void*)(ptrdiff_t)glow_glIsTexture, texture);
  return ret;
}
PFNGLISTEXTUREPROC glow_debug_glIsTexture = glow_debug_impl_glIsTexture;

static void glow_debug_impl_glMaterialxv(GLenum face, GLenum pname, const GLfixed *param) {

  glow_pre_callback_("glMaterialxv", (void*)(ptrdiff_t)glow_glMaterialxv, face, pname, param);
  glow_glMaterialxv(face, pname, param);
  glow_post_callback_("glMaterialxv", (void*)(ptrdiff_t)glow_glMaterialxv, face, pname, param);
}
PFNGLMATERIALXVPROC glow_debug_glMaterialxv = glow_debug_impl_glMaterialxv;

static void glow_debug_impl_glGetClipPlanef(GLenum plane, GLfloat *equation) {

  glow_pre_callback_("glGetClipPlanef", (void*)(ptrdiff_t)glow_glGetClipPlanef, plane, equation);
  glow_glGetClipPlanef(plane, equation);
  glow_post_callback_("glGetClipPlanef", (void*)(ptrdiff_t)glow_glGetClipPlanef, plane, equation);
}
PFNGLGETCLIPPLANEFPROC glow_debug_glGetClipPlanef = glow_debug_impl_glGetClipPlanef;

static void glow_debug_impl_glBindBuffer(GLenum target, GLuint buffer) {

  glow_pre_callback_("glBindBuffer", (void*)(ptrdiff_t)glow_glBindBuffer, target, buffer);
  glow_glBindBuffer(target, buffer);
  glow_post_callback_("glBindBuffer", (void*)(ptrdiff_t)glow_glBindBuffer, target, buffer);
}
PFNGLBINDBUFFERPROC glow_debug_glBindBuffer = glow_debug_impl_glBindBuffer;

static void glow_debug_impl_glGetFixedv(GLenum pname, GLfixed *params) {

  glow_pre_callback_("glGetFixedv", (void*)(ptrdiff_t)glow_glGetFixedv, pname, params);
  glow_glGetFixedv(pname, params);
  glow_post_callback_("glGetFixedv", (void*)(ptrdiff_t)glow_glGetFixedv, pname, params);
}
PFNGLGETFIXEDVPROC glow_debug_glGetFixedv = glow_debug_impl_glGetFixedv;

static void glow_debug_impl_glLightxv(GLenum light, GLenum pname, const GLfixed *params) {

  glow_pre_callback_("glLightxv", (void*)(ptrdiff_t)glow_glLightxv, light, pname, params);
  glow_glLightxv(light, pname, params);
  glow_post_callback_("glLightxv", (void*)(ptrdiff_t)glow_glLightxv, light, pname, params);
}
PFNGLLIGHTXVPROC glow_debug_glLightxv = glow_debug_impl_glLightxv;

static void glow_debug_impl_glLoadMatrixx(const GLfixed *m) {

  glow_pre_callback_("glLoadMatrixx", (void*)(ptrdiff_t)glow_glLoadMatrixx, m);
  glow_glLoadMatrixx(m);
  glow_post_callback_("glLoadMatrixx", (void*)(ptrdiff_t)glow_glLoadMatrixx, m);
}
PFNGLLOADMATRIXXPROC glow_debug_glLoadMatrixx = glow_debug_impl_glLoadMatrixx;

static void glow_debug_impl_glFogf(GLenum pname, GLfloat param) {

  glow_pre_callback_("glFogf", (void*)(ptrdiff_t)glow_glFogf, pname, param);
  glow_glFogf(pname, param);
  glow_post_callback_("glFogf", (void*)(ptrdiff_t)glow_glFogf, pname, param);
}
PFNGLFOGFPROC glow_debug_glFogf = glow_debug_impl_glFogf;

static void glow_debug_impl_glFogfv(GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glFogfv", (void*)(ptrdiff_t)glow_glFogfv, pname, params);
  glow_glFogfv(pname, params);
  glow_post_callback_("glFogfv", (void*)(ptrdiff_t)glow_glFogfv, pname, params);
}
PFNGLFOGFVPROC glow_debug_glFogfv = glow_debug_impl_glFogfv;

static void glow_debug_impl_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glTexParameterfv", (void*)(ptrdiff_t)glow_glTexParameterfv, target, pname, params);
  glow_glTexParameterfv(target, pname, params);
  glow_post_callback_("glTexParameterfv", (void*)(ptrdiff_t)glow_glTexParameterfv, target, pname, params);
}
PFNGLTEXPARAMETERFVPROC glow_debug_glTexParameterfv = glow_debug_impl_glTexParameterfv;

static void glow_debug_impl_glDepthMask(GLboolean flag) {

  glow_pre_callback_("glDepthMask", (void*)(ptrdiff_t)glow_glDepthMask, flag);
  glow_glDepthMask(flag);
  glow_post_callback_("glDepthMask", (void*)(ptrdiff_t)glow_glDepthMask, flag);
}
PFNGLDEPTHMASKPROC glow_debug_glDepthMask = glow_debug_impl_glDepthMask;

static void glow_debug_impl_glFlush() {

  glow_pre_callback_("glFlush", (void*)(ptrdiff_t)glow_glFlush);
  glow_glFlush();
  glow_post_callback_("glFlush", (void*)(ptrdiff_t)glow_glFlush);
}
PFNGLFLUSHPROC glow_debug_glFlush = glow_debug_impl_glFlush;

static void glow_debug_impl_glGetBooleanv(GLenum pname, GLboolean *data) {

  glow_pre_callback_("glGetBooleanv", (void*)(ptrdiff_t)glow_glGetBooleanv, pname, data);
  glow_glGetBooleanv(pname, data);
  glow_post_callback_("glGetBooleanv", (void*)(ptrdiff_t)glow_glGetBooleanv, pname, data);
}
PFNGLGETBOOLEANVPROC glow_debug_glGetBooleanv = glow_debug_impl_glGetBooleanv;

static void glow_debug_impl_glPointSizex(GLfixed size) {

  glow_pre_callback_("glPointSizex", (void*)(ptrdiff_t)glow_glPointSizex, size);
  glow_glPointSizex(size);
  glow_post_callback_("glPointSizex", (void*)(ptrdiff_t)glow_glPointSizex, size);
}
PFNGLPOINTSIZEXPROC glow_debug_glPointSizex = glow_debug_impl_glPointSizex;

static void glow_debug_impl_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {

  glow_pre_callback_("glTexEnvf", (void*)(ptrdiff_t)glow_glTexEnvf, target, pname, param);
  glow_glTexEnvf(target, pname, param);
  glow_post_callback_("glTexEnvf", (void*)(ptrdiff_t)glow_glTexEnvf, target, pname, param);
}
PFNGLTEXENVFPROC glow_debug_glTexEnvf = glow_debug_impl_glTexEnvf;

static void glow_debug_impl_glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {

  glow_pre_callback_("glNormal3x", (void*)(ptrdiff_t)glow_glNormal3x, nx, ny, nz);
  glow_glNormal3x(nx, ny, nz);
  glow_post_callback_("glNormal3x", (void*)(ptrdiff_t)glow_glNormal3x, nx, ny, nz);
}
PFNGLNORMAL3XPROC glow_debug_glNormal3x = glow_debug_impl_glNormal3x;

static void glow_debug_impl_glBlendFunc(GLenum sfactor, GLenum dfactor) {

  glow_pre_callback_("glBlendFunc", (void*)(ptrdiff_t)glow_glBlendFunc, sfactor, dfactor);
  glow_glBlendFunc(sfactor, dfactor);
  glow_post_callback_("glBlendFunc", (void*)(ptrdiff_t)glow_glBlendFunc, sfactor, dfactor);
}
PFNGLBLENDFUNCPROC glow_debug_glBlendFunc = glow_debug_impl_glBlendFunc;

static void glow_debug_impl_glSampleCoverage(GLfloat value, GLboolean invert) {

  glow_pre_callback_("glSampleCoverage", (void*)(ptrdiff_t)glow_glSampleCoverage, value, invert);
  glow_glSampleCoverage(value, invert);
  glow_post_callback_("glSampleCoverage", (void*)(ptrdiff_t)glow_glSampleCoverage, value, invert);
}
PFNGLSAMPLECOVERAGEPROC glow_debug_glSampleCoverage = glow_debug_impl_glSampleCoverage;

static void glow_debug_impl_glTexEnvi(GLenum target, GLenum pname, GLint param) {

  glow_pre_callback_("glTexEnvi", (void*)(ptrdiff_t)glow_glTexEnvi, target, pname, param);
  glow_glTexEnvi(target, pname, param);
  glow_post_callback_("glTexEnvi", (void*)(ptrdiff_t)glow_glTexEnvi, target, pname, param);
}
PFNGLTEXENVIPROC glow_debug_glTexEnvi = glow_debug_impl_glTexEnvi;

static void glow_debug_impl_glClearDepthx(GLfixed depth) {

  glow_pre_callback_("glClearDepthx", (void*)(ptrdiff_t)glow_glClearDepthx, depth);
  glow_glClearDepthx(depth);
  glow_post_callback_("glClearDepthx", (void*)(ptrdiff_t)glow_glClearDepthx, depth);
}
PFNGLCLEARDEPTHXPROC glow_debug_glClearDepthx = glow_debug_impl_glClearDepthx;

static void glow_debug_impl_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) {

  glow_pre_callback_("glTexCoordPointer", (void*)(ptrdiff_t)glow_glTexCoordPointer, size, type, stride, pointer);
  glow_glTexCoordPointer(size, type, stride, pointer);
  glow_post_callback_("glTexCoordPointer", (void*)(ptrdiff_t)glow_glTexCoordPointer, size, type, stride, pointer);
}
PFNGLTEXCOORDPOINTERPROC glow_debug_glTexCoordPointer = glow_debug_impl_glTexCoordPointer;

static void glow_debug_impl_glFrustumx(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {

  glow_pre_callback_("glFrustumx", (void*)(ptrdiff_t)glow_glFrustumx, l, r, b, t, n, f);
  glow_glFrustumx(l, r, b, t, n, f);
  glow_post_callback_("glFrustumx", (void*)(ptrdiff_t)glow_glFrustumx, l, r, b, t, n, f);
}
PFNGLFRUSTUMXPROC glow_debug_glFrustumx = glow_debug_impl_glFrustumx;

static void glow_debug_impl_glClearDepthf(GLfloat d) {

  glow_pre_callback_("glClearDepthf", (void*)(ptrdiff_t)glow_glClearDepthf, d);
  glow_glClearDepthf(d);
  glow_post_callback_("glClearDepthf", (void*)(ptrdiff_t)glow_glClearDepthf, d);
}
PFNGLCLEARDEPTHFPROC glow_debug_glClearDepthf = glow_debug_impl_glClearDepthf;

static void glow_debug_impl_glPointSize(GLfloat size) {

  glow_pre_callback_("glPointSize", (void*)(ptrdiff_t)glow_glPointSize, size);
  glow_glPointSize(size);
  glow_post_callback_("glPointSize", (void*)(ptrdiff_t)glow_glPointSize, size);
}
PFNGLPOINTSIZEPROC glow_debug_glPointSize = glow_debug_impl_glPointSize;

static void glow_debug_impl_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glCopyTexSubImage2D", (void*)(ptrdiff_t)glow_glCopyTexSubImage2D, target, level, xoffset, yoffset, x, y, width, height);
  glow_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
  glow_post_callback_("glCopyTexSubImage2D", (void*)(ptrdiff_t)glow_glCopyTexSubImage2D, target, level, xoffset, yoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE2DPROC glow_debug_glCopyTexSubImage2D = glow_debug_impl_glCopyTexSubImage2D;

static void glow_debug_impl_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) {

  glow_pre_callback_("glDrawElements", (void*)(ptrdiff_t)glow_glDrawElements, mode, count, type, indices);
  glow_glDrawElements(mode, count, type, indices);
  glow_post_callback_("glDrawElements", (void*)(ptrdiff_t)glow_glDrawElements, mode, count, type, indices);
}
PFNGLDRAWELEMENTSPROC glow_debug_glDrawElements = glow_debug_impl_glDrawElements;

static void glow_debug_impl_glEnableClientState(GLenum array) {

  glow_pre_callback_("glEnableClientState", (void*)(ptrdiff_t)glow_glEnableClientState, array);
  glow_glEnableClientState(array);
  glow_post_callback_("glEnableClientState", (void*)(ptrdiff_t)glow_glEnableClientState, array);
}
PFNGLENABLECLIENTSTATEPROC glow_debug_glEnableClientState = glow_debug_impl_glEnableClientState;

static void glow_debug_impl_glFogx(GLenum pname, GLfixed param) {

  glow_pre_callback_("glFogx", (void*)(ptrdiff_t)glow_glFogx, pname, param);
  glow_glFogx(pname, param);
  glow_post_callback_("glFogx", (void*)(ptrdiff_t)glow_glFogx, pname, param);
}
PFNGLFOGXPROC glow_debug_glFogx = glow_debug_impl_glFogx;

static void glow_debug_impl_glFogxv(GLenum pname, const GLfixed *param) {

  glow_pre_callback_("glFogxv", (void*)(ptrdiff_t)glow_glFogxv, pname, param);
  glow_glFogxv(pname, param);
  glow_post_callback_("glFogxv", (void*)(ptrdiff_t)glow_glFogxv, pname, param);
}
PFNGLFOGXVPROC glow_debug_glFogxv = glow_debug_impl_glFogxv;

static void glow_debug_impl_glGetTexEnvxv(GLenum target, GLenum pname, GLfixed *params) {

  glow_pre_callback_("glGetTexEnvxv", (void*)(ptrdiff_t)glow_glGetTexEnvxv, target, pname, params);
  glow_glGetTexEnvxv(target, pname, params);
  glow_post_callback_("glGetTexEnvxv", (void*)(ptrdiff_t)glow_glGetTexEnvxv, target, pname, params);
}
PFNGLGETTEXENVXVPROC glow_debug_glGetTexEnvxv = glow_debug_impl_glGetTexEnvxv;

static void glow_debug_impl_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glTexSubImage2D", (void*)(ptrdiff_t)glow_glTexSubImage2D, target, level, xoffset, yoffset, width, height, format, type, pixels);
  glow_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
  glow_post_callback_("glTexSubImage2D", (void*)(ptrdiff_t)glow_glTexSubImage2D, target, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLTEXSUBIMAGE2DPROC glow_debug_glTexSubImage2D = glow_debug_impl_glTexSubImage2D;

static void glow_debug_impl_glBindTexture(GLenum target, GLuint texture) {

  glow_pre_callback_("glBindTexture", (void*)(ptrdiff_t)glow_glBindTexture, target, texture);
  glow_glBindTexture(target, texture);
  glow_post_callback_("glBindTexture", (void*)(ptrdiff_t)glow_glBindTexture, target, texture);
}
PFNGLBINDTEXTUREPROC glow_debug_glBindTexture = glow_debug_impl_glBindTexture;

static void glow_debug_impl_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {

  glow_pre_callback_("glColor4ub", (void*)(ptrdiff_t)glow_glColor4ub, red, green, blue, alpha);
  glow_glColor4ub(red, green, blue, alpha);
  glow_post_callback_("glColor4ub", (void*)(ptrdiff_t)glow_glColor4ub, red, green, blue, alpha);
}
PFNGLCOLOR4UBPROC glow_debug_glColor4ub = glow_debug_impl_glColor4ub;

static void glow_debug_impl_glCullFace(GLenum mode) {

  glow_pre_callback_("glCullFace", (void*)(ptrdiff_t)glow_glCullFace, mode);
  glow_glCullFace(mode);
  glow_post_callback_("glCullFace", (void*)(ptrdiff_t)glow_glCullFace, mode);
}
PFNGLCULLFACEPROC glow_debug_glCullFace = glow_debug_impl_glCullFace;

static void glow_debug_impl_glDeleteTextures(GLsizei n, const GLuint *textures) {

  glow_pre_callback_("glDeleteTextures", (void*)(ptrdiff_t)glow_glDeleteTextures, n, textures);
  glow_glDeleteTextures(n, textures);
  glow_post_callback_("glDeleteTextures", (void*)(ptrdiff_t)glow_glDeleteTextures, n, textures);
}
PFNGLDELETETEXTURESPROC glow_debug_glDeleteTextures = glow_debug_impl_glDeleteTextures;

static void glow_debug_impl_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetTexParameteriv", (void*)(ptrdiff_t)glow_glGetTexParameteriv, target, pname, params);
  glow_glGetTexParameteriv(target, pname, params);
  glow_post_callback_("glGetTexParameteriv", (void*)(ptrdiff_t)glow_glGetTexParameteriv, target, pname, params);
}
PFNGLGETTEXPARAMETERIVPROC glow_debug_glGetTexParameteriv = glow_debug_impl_glGetTexParameteriv;

static void glow_debug_impl_glLineWidthx(GLfixed width) {

  glow_pre_callback_("glLineWidthx", (void*)(ptrdiff_t)glow_glLineWidthx, width);
  glow_glLineWidthx(width);
  glow_post_callback_("glLineWidthx", (void*)(ptrdiff_t)glow_glLineWidthx, width);
}
PFNGLLINEWIDTHXPROC glow_debug_glLineWidthx = glow_debug_impl_glLineWidthx;

static void glow_debug_impl_glTexEnvxv(GLenum target, GLenum pname, const GLfixed *params) {

  glow_pre_callback_("glTexEnvxv", (void*)(ptrdiff_t)glow_glTexEnvxv, target, pname, params);
  glow_glTexEnvxv(target, pname, params);
  glow_post_callback_("glTexEnvxv", (void*)(ptrdiff_t)glow_glTexEnvxv, target, pname, params);
}
PFNGLTEXENVXVPROC glow_debug_glTexEnvxv = glow_debug_impl_glTexEnvxv;

#endif /* GLOW_DEBUG */



int glow_init(void) {
  return glow_init_with(&glow_get_proc);
}

int glow_init_with(glow_load_proc_t get_proc) {
  int unresolved_count = 0;

  glow_glActiveTexture = (PFNGLACTIVETEXTUREPROC)(ptrdiff_t)get_proc("glActiveTexture");
  if (glow_glActiveTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glActiveTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glActiveTexture\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetClipPlanex = (PFNGLGETCLIPPLANEXPROC)(ptrdiff_t)get_proc("glGetClipPlanex");
  if (glow_glGetClipPlanex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetClipPlanex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetClipPlanex\n");
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
  glow_glIsEnabled = (PFNGLISENABLEDPROC)(ptrdiff_t)get_proc("glIsEnabled");
  if (glow_glIsEnabled == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsEnabled\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsEnabled\n");
#endif
    unresolved_count += 1;
  } 
  glow_glShadeModel = (PFNGLSHADEMODELPROC)(ptrdiff_t)get_proc("glShadeModel");
  if (glow_glShadeModel == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glShadeModel\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glShadeModel\n");
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
  glow_glViewport = (PFNGLVIEWPORTPROC)(ptrdiff_t)get_proc("glViewport");
  if (glow_glViewport == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glViewport\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glViewport\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetLightfv = (PFNGLGETLIGHTFVPROC)(ptrdiff_t)get_proc("glGetLightfv");
  if (glow_glGetLightfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetLightfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetLightfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMaterialfv = (PFNGLMATERIALFVPROC)(ptrdiff_t)get_proc("glMaterialfv");
  if (glow_glMaterialfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMaterialfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMaterialfv\n");
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
  glow_glGetTexParameterxv = (PFNGLGETTEXPARAMETERXVPROC)(ptrdiff_t)get_proc("glGetTexParameterxv");
  if (glow_glGetTexParameterxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameterxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameterxv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4f = (PFNGLCOLOR4FPROC)(ptrdiff_t)get_proc("glColor4f");
  if (glow_glColor4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetMaterialfv = (PFNGLGETMATERIALFVPROC)(ptrdiff_t)get_proc("glGetMaterialfv");
  if (glow_glGetMaterialfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMaterialfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMaterialfv\n");
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
  glow_glMultiTexCoord4x = (PFNGLMULTITEXCOORD4XPROC)(ptrdiff_t)get_proc("glMultiTexCoord4x");
  if (glow_glMultiTexCoord4x == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMultiTexCoord4x\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMultiTexCoord4x\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTranslatex = (PFNGLTRANSLATEXPROC)(ptrdiff_t)get_proc("glTranslatex");
  if (glow_glTranslatex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTranslatex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTranslatex\n");
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
  glow_glScalef = (PFNGLSCALEFPROC)(ptrdiff_t)get_proc("glScalef");
  if (glow_glScalef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glScalef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glScalef\n");
#endif
    unresolved_count += 1;
  } 
  glow_glOrthof = (PFNGLORTHOFPROC)(ptrdiff_t)get_proc("glOrthof");
  if (glow_glOrthof == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glOrthof\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glOrthof\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColorPointer = (PFNGLCOLORPOINTERPROC)(ptrdiff_t)get_proc("glColorPointer");
  if (glow_glColorPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColorPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColorPointer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetPointerv = (PFNGLGETPOINTERVPROC)(ptrdiff_t)get_proc("glGetPointerv");
  if (glow_glGetPointerv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetPointerv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetPointerv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPointParameterxv = (PFNGLPOINTPARAMETERXVPROC)(ptrdiff_t)get_proc("glPointParameterxv");
  if (glow_glPointParameterxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointParameterxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointParameterxv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLoadIdentity = (PFNGLLOADIDENTITYPROC)(ptrdiff_t)get_proc("glLoadIdentity");
  if (glow_glLoadIdentity == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadIdentity\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadIdentity\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLogicOp = (PFNGLLOGICOPPROC)(ptrdiff_t)get_proc("glLogicOp");
  if (glow_glLogicOp == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLogicOp\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLogicOp\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMatrixMode = (PFNGLMATRIXMODEPROC)(ptrdiff_t)get_proc("glMatrixMode");
  if (glow_glMatrixMode == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMatrixMode\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMatrixMode\n");
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
  glow_glGetMaterialxv = (PFNGLGETMATERIALXVPROC)(ptrdiff_t)get_proc("glGetMaterialxv");
  if (glow_glGetMaterialxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMaterialxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMaterialxv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPopMatrix = (PFNGLPOPMATRIXPROC)(ptrdiff_t)get_proc("glPopMatrix");
  if (glow_glPopMatrix == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPopMatrix\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPopMatrix\n");
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
  glow_glClearColor = (PFNGLCLEARCOLORPROC)(ptrdiff_t)get_proc("glClearColor");
  if (glow_glClearColor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearColor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearColor\n");
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
  glow_glMaterialf = (PFNGLMATERIALFPROC)(ptrdiff_t)get_proc("glMaterialf");
  if (glow_glMaterialf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMaterialf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMaterialf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMultMatrixf = (PFNGLMULTMATRIXFPROC)(ptrdiff_t)get_proc("glMultMatrixf");
  if (glow_glMultMatrixf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMultMatrixf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMultMatrixf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNormal3f = (PFNGLNORMAL3FPROC)(ptrdiff_t)get_proc("glNormal3f");
  if (glow_glNormal3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3f\n");
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
  glow_glClearStencil = (PFNGLCLEARSTENCILPROC)(ptrdiff_t)get_proc("glClearStencil");
  if (glow_glClearStencil == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearStencil\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearStencil\n");
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
  glow_glDisable = (PFNGLDISABLEPROC)(ptrdiff_t)get_proc("glDisable");
  if (glow_glDisable == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisable\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisable\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLightx = (PFNGLLIGHTXPROC)(ptrdiff_t)get_proc("glLightx");
  if (glow_glLightx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glAlphaFuncx = (PFNGLALPHAFUNCXPROC)(ptrdiff_t)get_proc("glAlphaFuncx");
  if (glow_glAlphaFuncx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glAlphaFuncx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glAlphaFuncx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4x = (PFNGLCOLOR4XPROC)(ptrdiff_t)get_proc("glColor4x");
  if (glow_glColor4x == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4x\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4x\n");
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
  glow_glTexParameterxv = (PFNGLTEXPARAMETERXVPROC)(ptrdiff_t)get_proc("glTexParameterxv");
  if (glow_glTexParameterxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterxv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClipPlanex = (PFNGLCLIPPLANEXPROC)(ptrdiff_t)get_proc("glClipPlanex");
  if (glow_glClipPlanex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClipPlanex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClipPlanex\n");
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
  glow_glFrontFace = (PFNGLFRONTFACEPROC)(ptrdiff_t)get_proc("glFrontFace");
  if (glow_glFrontFace == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFrontFace\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFrontFace\n");
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
  glow_glStencilOp = (PFNGLSTENCILOPPROC)(ptrdiff_t)get_proc("glStencilOp");
  if (glow_glStencilOp == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilOp\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilOp\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexParameterx = (PFNGLTEXPARAMETERXPROC)(ptrdiff_t)get_proc("glTexParameterx");
  if (glow_glTexParameterx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterx\n");
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
  glow_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)(ptrdiff_t)get_proc("glBufferSubData");
  if (glow_glBufferSubData == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBufferSubData\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBufferSubData\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClearColorx = (PFNGLCLEARCOLORXPROC)(ptrdiff_t)get_proc("glClearColorx");
  if (glow_glClearColorx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearColorx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearColorx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPushMatrix = (PFNGLPUSHMATRIXPROC)(ptrdiff_t)get_proc("glPushMatrix");
  if (glow_glPushMatrix == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPushMatrix\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPushMatrix\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexEnvx = (PFNGLTEXENVXPROC)(ptrdiff_t)get_proc("glTexEnvx");
  if (glow_glTexEnvx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLightModelfv = (PFNGLLIGHTMODELFVPROC)(ptrdiff_t)get_proc("glLightModelfv");
  if (glow_glLightModelfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModelfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModelfv\n");
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
  glow_glLoadMatrixf = (PFNGLLOADMATRIXFPROC)(ptrdiff_t)get_proc("glLoadMatrixf");
  if (glow_glLoadMatrixf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadMatrixf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadMatrixf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPointParameterf = (PFNGLPOINTPARAMETERFPROC)(ptrdiff_t)get_proc("glPointParameterf");
  if (glow_glPointParameterf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointParameterf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointParameterf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPolygonOffsetx = (PFNGLPOLYGONOFFSETXPROC)(ptrdiff_t)get_proc("glPolygonOffsetx");
  if (glow_glPolygonOffsetx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPolygonOffsetx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPolygonOffsetx\n");
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
  glow_glLightModelx = (PFNGLLIGHTMODELXPROC)(ptrdiff_t)get_proc("glLightModelx");
  if (glow_glLightModelx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModelx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModelx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexPointer = (PFNGLVERTEXPOINTERPROC)(ptrdiff_t)get_proc("glVertexPointer");
  if (glow_glVertexPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexPointer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNormalPointer = (PFNGLNORMALPOINTERPROC)(ptrdiff_t)get_proc("glNormalPointer");
  if (glow_glNormalPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormalPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormalPointer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLightModelxv = (PFNGLLIGHTMODELXVPROC)(ptrdiff_t)get_proc("glLightModelxv");
  if (glow_glLightModelxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModelxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModelxv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFrustumf = (PFNGLFRUSTUMFPROC)(ptrdiff_t)get_proc("glFrustumf");
  if (glow_glFrustumf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFrustumf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFrustumf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLightModelf = (PFNGLLIGHTMODELFPROC)(ptrdiff_t)get_proc("glLightModelf");
  if (glow_glLightModelf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModelf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModelf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexEnvfv = (PFNGLTEXENVFVPROC)(ptrdiff_t)get_proc("glTexEnvfv");
  if (glow_glTexEnvfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDepthRangex = (PFNGLDEPTHRANGEXPROC)(ptrdiff_t)get_proc("glDepthRangex");
  if (glow_glDepthRangex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthRangex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthRangex\n");
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
  glow_glFinish = (PFNGLFINISHPROC)(ptrdiff_t)get_proc("glFinish");
  if (glow_glFinish == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFinish\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFinish\n");
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
  glow_glReadPixels = (PFNGLREADPIXELSPROC)(ptrdiff_t)get_proc("glReadPixels");
  if (glow_glReadPixels == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReadPixels\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReadPixels\n");
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
  glow_glGetLightxv = (PFNGLGETLIGHTXVPROC)(ptrdiff_t)get_proc("glGetLightxv");
  if (glow_glGetLightxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetLightxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetLightxv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glOrthox = (PFNGLORTHOXPROC)(ptrdiff_t)get_proc("glOrthox");
  if (glow_glOrthox == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glOrthox\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glOrthox\n");
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
  glow_glRotatex = (PFNGLROTATEXPROC)(ptrdiff_t)get_proc("glRotatex");
  if (glow_glRotatex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRotatex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRotatex\n");
#endif
    unresolved_count += 1;
  } 
  glow_glSampleCoveragex = (PFNGLSAMPLECOVERAGEXPROC)(ptrdiff_t)get_proc("glSampleCoveragex");
  if (glow_glSampleCoveragex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSampleCoveragex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSampleCoveragex\n");
#endif
    unresolved_count += 1;
  } 
  glow_glScalex = (PFNGLSCALEXPROC)(ptrdiff_t)get_proc("glScalex");
  if (glow_glScalex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glScalex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glScalex\n");
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
  glow_glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)(ptrdiff_t)get_proc("glMultiTexCoord4f");
  if (glow_glMultiTexCoord4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMultiTexCoord4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMultiTexCoord4f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)(ptrdiff_t)get_proc("glPointParameterfv");
  if (glow_glPointParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointParameterfv\n");
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
  glow_glTexParameteri = (PFNGLTEXPARAMETERIPROC)(ptrdiff_t)get_proc("glTexParameteri");
  if (glow_glTexParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameteri\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)(ptrdiff_t)get_proc("glClientActiveTexture");
  if (glow_glClientActiveTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClientActiveTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClientActiveTexture\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMultMatrixx = (PFNGLMULTMATRIXXPROC)(ptrdiff_t)get_proc("glMultMatrixx");
  if (glow_glMultMatrixx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMultMatrixx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMultMatrixx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLightf = (PFNGLLIGHTFPROC)(ptrdiff_t)get_proc("glLightf");
  if (glow_glLightf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightf\n");
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
  glow_glClear = (PFNGLCLEARPROC)(ptrdiff_t)get_proc("glClear");
  if (glow_glClear == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClear\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClear\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDisableClientState = (PFNGLDISABLECLIENTSTATEPROC)(ptrdiff_t)get_proc("glDisableClientState");
  if (glow_glDisableClientState == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisableClientState\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisableClientState\n");
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
  glow_glMaterialx = (PFNGLMATERIALXPROC)(ptrdiff_t)get_proc("glMaterialx");
  if (glow_glMaterialx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMaterialx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMaterialx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glAlphaFunc = (PFNGLALPHAFUNCPROC)(ptrdiff_t)get_proc("glAlphaFunc");
  if (glow_glAlphaFunc == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glAlphaFunc\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glAlphaFunc\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClipPlanef = (PFNGLCLIPPLANEFPROC)(ptrdiff_t)get_proc("glClipPlanef");
  if (glow_glClipPlanef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClipPlanef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClipPlanef\n");
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
  glow_glLightfv = (PFNGLLIGHTFVPROC)(ptrdiff_t)get_proc("glLightfv");
  if (glow_glLightfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTranslatef = (PFNGLTRANSLATEFPROC)(ptrdiff_t)get_proc("glTranslatef");
  if (glow_glTranslatef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTranslatef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTranslatef\n");
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
  glow_glIsBuffer = (PFNGLISBUFFERPROC)(ptrdiff_t)get_proc("glIsBuffer");
  if (glow_glIsBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsBuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPointParameterx = (PFNGLPOINTPARAMETERXPROC)(ptrdiff_t)get_proc("glPointParameterx");
  if (glow_glPointParameterx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointParameterx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointParameterx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexEnviv = (PFNGLTEXENVIVPROC)(ptrdiff_t)get_proc("glTexEnviv");
  if (glow_glTexEnviv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnviv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnviv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexEnvfv = (PFNGLGETTEXENVFVPROC)(ptrdiff_t)get_proc("glGetTexEnvfv");
  if (glow_glGetTexEnvfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexEnvfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexEnvfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRotatef = (PFNGLROTATEFPROC)(ptrdiff_t)get_proc("glRotatef");
  if (glow_glRotatef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRotatef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRotatef\n");
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
  glow_glDrawArrays = (PFNGLDRAWARRAYSPROC)(ptrdiff_t)get_proc("glDrawArrays");
  if (glow_glDrawArrays == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawArrays\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawArrays\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexEnviv = (PFNGLGETTEXENVIVPROC)(ptrdiff_t)get_proc("glGetTexEnviv");
  if (glow_glGetTexEnviv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexEnviv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexEnviv\n");
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
  glow_glMaterialxv = (PFNGLMATERIALXVPROC)(ptrdiff_t)get_proc("glMaterialxv");
  if (glow_glMaterialxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMaterialxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMaterialxv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetClipPlanef = (PFNGLGETCLIPPLANEFPROC)(ptrdiff_t)get_proc("glGetClipPlanef");
  if (glow_glGetClipPlanef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetClipPlanef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetClipPlanef\n");
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
  glow_glGetFixedv = (PFNGLGETFIXEDVPROC)(ptrdiff_t)get_proc("glGetFixedv");
  if (glow_glGetFixedv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFixedv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFixedv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLightxv = (PFNGLLIGHTXVPROC)(ptrdiff_t)get_proc("glLightxv");
  if (glow_glLightxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightxv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLoadMatrixx = (PFNGLLOADMATRIXXPROC)(ptrdiff_t)get_proc("glLoadMatrixx");
  if (glow_glLoadMatrixx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadMatrixx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadMatrixx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFogf = (PFNGLFOGFPROC)(ptrdiff_t)get_proc("glFogf");
  if (glow_glFogf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFogfv = (PFNGLFOGFVPROC)(ptrdiff_t)get_proc("glFogfv");
  if (glow_glFogfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogfv\n");
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
  glow_glDepthMask = (PFNGLDEPTHMASKPROC)(ptrdiff_t)get_proc("glDepthMask");
  if (glow_glDepthMask == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthMask\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthMask\n");
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
  glow_glGetBooleanv = (PFNGLGETBOOLEANVPROC)(ptrdiff_t)get_proc("glGetBooleanv");
  if (glow_glGetBooleanv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBooleanv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBooleanv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPointSizex = (PFNGLPOINTSIZEXPROC)(ptrdiff_t)get_proc("glPointSizex");
  if (glow_glPointSizex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointSizex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointSizex\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexEnvf = (PFNGLTEXENVFPROC)(ptrdiff_t)get_proc("glTexEnvf");
  if (glow_glTexEnvf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNormal3x = (PFNGLNORMAL3XPROC)(ptrdiff_t)get_proc("glNormal3x");
  if (glow_glNormal3x == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3x\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3x\n");
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
  glow_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)(ptrdiff_t)get_proc("glSampleCoverage");
  if (glow_glSampleCoverage == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSampleCoverage\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSampleCoverage\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexEnvi = (PFNGLTEXENVIPROC)(ptrdiff_t)get_proc("glTexEnvi");
  if (glow_glTexEnvi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvi\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClearDepthx = (PFNGLCLEARDEPTHXPROC)(ptrdiff_t)get_proc("glClearDepthx");
  if (glow_glClearDepthx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearDepthx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearDepthx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoordPointer = (PFNGLTEXCOORDPOINTERPROC)(ptrdiff_t)get_proc("glTexCoordPointer");
  if (glow_glTexCoordPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoordPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoordPointer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFrustumx = (PFNGLFRUSTUMXPROC)(ptrdiff_t)get_proc("glFrustumx");
  if (glow_glFrustumx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFrustumx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFrustumx\n");
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
  glow_glPointSize = (PFNGLPOINTSIZEPROC)(ptrdiff_t)get_proc("glPointSize");
  if (glow_glPointSize == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPointSize\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPointSize\n");
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
  glow_glDrawElements = (PFNGLDRAWELEMENTSPROC)(ptrdiff_t)get_proc("glDrawElements");
  if (glow_glDrawElements == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElements\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElements\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEnableClientState = (PFNGLENABLECLIENTSTATEPROC)(ptrdiff_t)get_proc("glEnableClientState");
  if (glow_glEnableClientState == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnableClientState\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnableClientState\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFogx = (PFNGLFOGXPROC)(ptrdiff_t)get_proc("glFogx");
  if (glow_glFogx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFogxv = (PFNGLFOGXVPROC)(ptrdiff_t)get_proc("glFogxv");
  if (glow_glFogxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogxv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexEnvxv = (PFNGLGETTEXENVXVPROC)(ptrdiff_t)get_proc("glGetTexEnvxv");
  if (glow_glGetTexEnvxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexEnvxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexEnvxv\n");
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
  glow_glBindTexture = (PFNGLBINDTEXTUREPROC)(ptrdiff_t)get_proc("glBindTexture");
  if (glow_glBindTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindTexture\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4ub = (PFNGLCOLOR4UBPROC)(ptrdiff_t)get_proc("glColor4ub");
  if (glow_glColor4ub == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4ub\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4ub\n");
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
  glow_glDeleteTextures = (PFNGLDELETETEXTURESPROC)(ptrdiff_t)get_proc("glDeleteTextures");
  if (glow_glDeleteTextures == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteTextures\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteTextures\n");
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
  glow_glLineWidthx = (PFNGLLINEWIDTHXPROC)(ptrdiff_t)get_proc("glLineWidthx");
  if (glow_glLineWidthx == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLineWidthx\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLineWidthx\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexEnvxv = (PFNGLTEXENVXVPROC)(ptrdiff_t)get_proc("glTexEnvxv");
  if (glow_glTexEnvxv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvxv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvxv\n");
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
