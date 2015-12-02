/*
 * glow-1.0.0: public-domain OpenGL function loader
 *
 * This file was generated with glow https://github.com/jshrake/glow
 * 
 * Version: 1.0.0
 * Date: 2015-11-27 09:08:27.660754955 -0800 PST
 * Language: C
 * Specification: 3.2
 * API: gles2
 * Profile: core
 * Command-line: glow --api="gles2" --spec="3.2" --profile="core" --debug=true
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
#define GL_ES_VERSION_3_0
#define GL_ES_VERSION_3_1
#define GL_ES_VERSION_3_2

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
#define GL_DEBUG_OUTPUT 0x92E0
#define GL_VERTEX_SHADER 0x8B31
#define GL_BOOL 0x8B56
#define GL_COLORDODGE 0x9299
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_HARDLIGHT 0x929B
#define GL_VENDOR 0x1F00
#define GL_COLOR_ATTACHMENT19 0x8CF3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5 0x93D5
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#define GL_COLOR_ATTACHMENT27 0x8CFB
#define GL_DEBUG_SOURCE_APPLICATION 0x824A
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_INVALID_VALUE 0x0501
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_CONTEXT_FLAGS 0x821E
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_KEEP 0x1E00
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_DIFFERENCE 0x929E
#define GL_TEXTURE8 0x84C8
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_R8I 0x8231
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_TEXTURE15 0x84CF
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_TEXTURE19 0x84D3
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_DRAW_BUFFER4 0x8829
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#define GL_VERTEX_SHADER_BIT 0x00000001
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_TEXTURE26 0x84DA
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_FLOAT_VEC3 0x8B51
#define GL_RGB16I 0x8D89
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6 0x93D9
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_DRAW_BUFFER2 0x8827
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_DITHER 0x0BD0
#define GL_NICEST 0x1102
#define GL_SAMPLES 0x80A9
#define GL_TEXTURE4 0x84C4
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_TEXTURE16 0x84D0
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_HSL_SATURATION 0x92AE
#define GL_QUADS 0x0007
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_UNSIGNED_SHORT 0x1403
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_PROGRAM_BINARY_FORMATS 0x87FF
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_IMAGE_BUFFER 0x9051
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6 0x93D6
#define GL_TEXTURE29 0x84DD
#define GL_FLOAT_MAT4 0x8B5C
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_RG16UI 0x823A
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_MAX_UNIFORM_LOCATIONS 0x826E
#define GL_TESS_GEN_MODE 0x8E76
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_DRAW_BUFFER7 0x882C
#define GL_COLOR_ATTACHMENT17 0x8CF1
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_MATRIX_STRIDE 0x92FF
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_CONSTANT_COLOR 0x8001
#define GL_DRAW_BUFFER0 0x8825
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_RGB 0x1907
#define GL_TEXTURE 0x1702
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_DST_ALPHA 0x0304
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_RGB8I 0x8D8F
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_MEDIUM_INT 0x8DF4
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_COMPRESSED_RGBA_ASTC_8x6 0x93B6
#define GL_DRAW_BUFFER15 0x8834
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_COMPRESSED_RGBA_ASTC_8x5 0x93B5
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5 0x93D8
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_STENCIL_INDEX 0x1901
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_INVALID_INDEX 0xFFFFFFFF
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#define GL_COLOR 0x1800
#define GL_R8UI 0x8232
#define GL_RGB10_A2UI 0x906F
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_DEBUG_TYPE_OTHER 0x8251
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_SYNC_FENCE 0x9116
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_DEPTH_TEST 0x0B71
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_TEXTURE31 0x84DF
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_STATIC_READ 0x88E5
#define GL_MINOR_VERSION 0x821C
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_COLOR_ATTACHMENT20 0x8CF4
#define GL_HALF_FLOAT 0x140B
#define GL_R16I 0x8233
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_ACTIVE_RESOURCES 0x92F5
#define GL_DECR 0x1E03
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_COLOR_ATTACHMENT21 0x8CF5
#define GL_DEBUG_TYPE_ERROR 0x824C
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_LESS 0x0201
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_STATIC_DRAW 0x88E4
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_R32I 0x8235
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_SAMPLER 0x82E6
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_COPY_WRITE_BUFFER 0x8F37
#define GL_DEBUG_TYPE_MARKER 0x8268
#define GL_TESS_CONTROL_SHADER 0x8E88
#define GL_GREEN_BITS 0x0D53
#define GL_TEXTURE28 0x84DC
#define GL_RGBA8 0x8058
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_TRUE 1
#define GL_SAMPLER_2D 0x8B5E
#define GL_RG8 0x822B
#define GL_IMAGE_2D 0x904D
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_STREAM_READ 0x88E1
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_SAMPLES 0x8D57
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_ALPHA 0x1906
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_DRAW_BUFFER14 0x8833
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_DEBUG_SEVERITY_LOW 0x9148
#define GL_ZERO 0
#define GL_BUFFER_SIZE 0x8764
#define GL_HSL_LUMINOSITY 0x92B0
#define GL_MULTIPLY 0x9294
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_MAX 0x8008
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COMPRESSED_RGB8_ETC2 0x9274
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_STREAM_DRAW 0x88E0
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY 0x9382
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define GL_ARRAY_SIZE 0x92FB
#define GL_DEBUG_LOGGED_MESSAGES 0x9145
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_COMPRESSED_SRGB8_ETC2 0x9275
#define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
#define GL_VERTEX_ARRAY 0x8074
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_LOW_FLOAT 0x8DF0
#define GL_CULL_FACE 0x0B44
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_TRIANGLES 0x0004
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_SAMPLE_POSITION 0x8E50
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_COLOR_ATTACHMENT16 0x8CF0
#define GL_RG8UI 0x8238
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_RGB9_E5 0x8C3D
#define GL_ACTIVE_PROGRAM 0x8259
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_DEBUG_SEVERITY_MEDIUM 0x9147
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGB32UI 0x8D71
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_ONE 1
#define GL_COLOR_ATTACHMENT25 0x8CF9
#define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23
#define GL_UNIFORM_BLOCK 0x92E2
#define GL_COMPRESSED_RGBA_ASTC_5x5 0x93B2
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#define GL_OVERLAY 0x9296
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_WAIT_FAILED 0x911D
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_ALL_SHADER_BITS 0xFFFFFFFF
#define GL_SAMPLE_MASK 0x8E51
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8 0x93DA
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69
#define GL_UNKNOWN_CONTEXT_RESET 0x8255
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_BUFFER_VARIABLE 0x92E5
#define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
#define GL_DECR_WRAP 0x8508
#define GL_FRAMEBUFFER 0x8D40
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_BOOL_VEC3 0x8B58
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_OFFSET 0x92FC
#define GL_PROGRAM_INPUT 0x92E3
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_FASTEST 0x1101
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_COMPUTE_SHADER_BIT 0x00000020
#define GL_NOTEQUAL 0x0205
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_DEBUG_TYPE_PORTABILITY 0x824F
#define GL_RGB8_SNORM 0x8F96
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4
#define GL_MAX_INTEGER_SAMPLES 0x9110
#define GL_RG32UI 0x823C
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA
#define GL_MAP_READ_BIT 0x0001
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_ALPHA_BITS 0x0D55
#define GL_RGB16UI 0x8D77
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_INVALID_ENUM 0x0500
#define GL_CULL_FACE_MODE 0x0B45
#define GL_RGBA8UI 0x8D7C
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_GUILTY_CONTEXT_RESET 0x8253
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_COMPRESSED_RGBA_ASTC_6x6 0x93B4
#define GL_FIXED 0x140C
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_SRGB8 0x8C41
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_RGBA32I 0x8D82
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_BLUE 0x1905
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_LOW_INT 0x8DF3
#define GL_RG16I 0x8239
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_ACTIVE_VARIABLES 0x9305
#define GL_CURRENT_QUERY 0x8865
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_BUFFER_DATA_SIZE 0x9303
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_RG32I 0x823B
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_R16UI 0x8234
#define GL_TEXTURE_3D 0x806F
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_COMPILE_STATUS 0x8B81
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS 0x8CD9
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12 0x93DD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10 0x93DC
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_SRC_ALPHA 0x0302
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_BLEND_COLOR 0x8005
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_DRAW_BUFFER13 0x8832
#define GL_COMPRESSED_RGBA_ASTC_10x5 0x93B8
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#define GL_MAX_LABEL_LENGTH 0x82E8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4 0x93D1
#define GL_DEPTH_COMPONENT 0x1902
#define GL_VERSION 0x1F02
#define GL_BOOL_VEC4 0x8B59
#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_VERTEX_BINDING_DIVISOR 0x82D6
#define GL_LINE_STRIP 0x0003
#define GL_EXTENSIONS 0x1F03
#define GL_SHADER_COMPILER 0x8DFA
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_WIDTH 0x1000
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_RG_INTEGER 0x8228
#define GL_MIRRORED_REPEAT 0x8370
#define GL_RGBA_INTEGER 0x8D99
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_LINE_WIDTH 0x0B21
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_VALIDATE_STATUS 0x8B83
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLORBURN 0x929A
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_BYTE 0x1400
#define GL_NEVER 0x0200
#define GL_VERTEX_BINDING_STRIDE 0x82D8
#define GL_STENCIL_FAIL 0x0B94
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_LINEAR 0x2601
#define GL_REPEAT 0x2901
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_SHADER_STORAGE_BUFFER 0x90D2
#define GL_ISOLINES 0x8E7A
#define GL_COMPRESSED_RGBA_ASTC_4x4 0x93B0
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_DEPTH_FUNC 0x0B74
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE11 0x84CB
#define GL_LOSE_CONTEXT_ON_RESET 0x8252
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_BUFFER_MAPPED 0x88BC
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RGBA32UI 0x8D70
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_RED 0x1903
#define GL_WRITE_ONLY 0x88B9
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#define GL_RG8I 0x8237
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_VERTEX_ATTRIB_BINDING 0x82D4
#define GL_ARRAY_BUFFER 0x8892
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_DELETE_STATUS 0x8B80
#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_ARRAY_STRIDE 0x92FE
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_LINK_STATUS 0x8B82
#define GL_TEXTURE22 0x84D6
#define GL_STENCIL_INDEX8 0x8D48
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_DEBUG_TYPE_POP_GROUP 0x826A
#define GL_STACK_OVERFLOW 0x0503
#define GL_DEPTH_STENCIL 0x84F9
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE 0x9381
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#define GL_BUFFER 0x82E0
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_STENCIL_REF 0x0B97
#define GL_DRAW_BUFFER6 0x882B
#define GL_BLOCK_INDEX 0x92FD
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_RESET_NOTIFICATION_STRATEGY 0x8256
#define GL_GREATER 0x0204
#define GL_COLOR_ATTACHMENT24 0x8CF8
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_BUFFER_USAGE 0x8765
#define GL_MAJOR_VERSION 0x821B
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_UNIFORM 0x92E1
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_COMPRESSED_RGBA_ASTC_12x10 0x93BC
#define GL_VIEWPORT 0x0BA2
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_INT 0x1404
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_ALL_BARRIER_BITS 0xFFFFFFFF
#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#define GL_LINE_STRIP_ADJACENCY 0x000B
#define GL_READ_ONLY 0x88B8
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_INT_IMAGE_2D 0x9058
#define GL_RGBA16F 0x881A
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_EXCLUSION 0x92A0
#define GL_RGBA16I 0x8D88
#define GL_R32F 0x822E
#define GL_VERTEX_BINDING_BUFFER 0x8F4F
#define GL_UNIFORM_TYPE 0x8A37
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_RGB32F 0x8815
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_FLOAT_MAT2 0x8B5A
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_SAMPLER_BINDING 0x8919
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_FLOAT_MAT3 0x8B5B
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_SOFTLIGHT 0x929C
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#define GL_IS_PER_PATCH 0x92E7
#define GL_NO_ERROR 0
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_RGBA8I 0x8D8E
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_FRONT 0x0404
#define GL_RENDERER 0x1F01
#define GL_TEXTURE3 0x84C3
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_SYNC_FLAGS 0x9115
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define GL_RG16F 0x822F
#define GL_DEBUG_SOURCE_API 0x8246
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_TEXTURE5 0x84C5
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_UNDEFINED_VERTEX 0x8260
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_PROGRAM_PIPELINE_BINDING 0x825A
#define GL_DEBUG_CALLBACK_FUNCTION 0x8244
#define GL_PROGRAM 0x82E2
#define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE12 0x84CC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_GEQUAL 0x0206
#define GL_NEAREST 0x2600
#define GL_COMPRESSED_R11_EAC 0x9270
#define GL_NUM_SAMPLE_COUNTS 0x9380
#define GL_NAME_LENGTH 0x92F9
#define GL_COMPRESSED_RGBA_ASTC_5x4 0x93B1
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_SIGNALED 0x9119
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
#define GL_RGB565 0x8D62
#define GL_UNSIGNALED 0x9118
#define GL_SHADER 0x82E1
#define GL_SAMPLE_SHADING 0x8C36
#define GL_READ_BUFFER 0x0C02
#define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_INCR 0x1E02
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_CONTEXT_LOST 0x0507
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE18 0x84D2
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_TEXTURE_BUFFER_BINDING 0x8C2A
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE24 0x84D8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_DRAW_BUFFER3 0x8828
#define GL_IS_ROW_MAJOR 0x9300
#define GL_SRC_COLOR 0x0300
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_TEXTURE13 0x84CD
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_CONSTANT_ALPHA 0x8003
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_REPLACE 0x1E01
#define GL_STATIC_COPY 0x88E6
#define GL_R16F 0x822D
#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TRIANGLE_STRIP 0x0005
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_TEXTURE_BUFFER_SIZE 0x919E
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_ANY_SAMPLES_PASSED 0x8C2F
#define GL_SHADER_STORAGE_BLOCK 0x92E6
#define GL_DEBUG_TYPE_PERFORMANCE 0x8250
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_COLOR_ATTACHMENT22 0x8CF6
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_SHADER_STORAGE_BARRIER_BIT 0x00002000
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5 0x93D2
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_TEXTURE20 0x84D4
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_RGB16F 0x881B
#define GL_LIGHTEN 0x9298
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_QUERY 0x82E3
#define GL_OUT_OF_MEMORY 0x0505
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_DYNAMIC_COPY 0x88EA
#define GL_SHADER_TYPE 0x8B4F
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_IMAGE_CUBE 0x9050
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002
#define GL_TRIANGLE_FAN 0x0006
#define GL_LEQUAL 0x0203
#define GL_RGBA4 0x8056
#define GL_LINES_ADJACENCY 0x000A
#define GL_CW 0x0900
#define GL_STENCIL_BITS 0x0D57
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_COMPRESSED_RGBA_ASTC_8x8 0x93B7
#define GL_TEXTURE27 0x84DB
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define GL_COMPRESSED_RGBA_ASTC_10x8 0x93BA
#define GL_OBJECT_TYPE 0x9112
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_MAX_ELEMENT_INDEX 0x8D6B
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_READ_WRITE 0x88BA
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#define GL_EQUAL 0x0202
#define GL_TEXTURE7 0x84C7
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER12 0x8831
#define GL_TEXTURE14 0x84CE
#define GL_HIGH_FLOAT 0x8DF2
#define GL_STREAM_COPY 0x88E2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4 0x93D0
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_DRAW_BUFFER9 0x882E
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_RED_BITS 0x0D52
#define GL_BOOL_VEC2 0x8B57
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_HIGH_INT 0x8DF5
#define GL_COPY_READ_BUFFER 0x8F36
#define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_INCR_WRAP 0x8507
#define GL_STENCIL 0x1802
#define GL_RED_INTEGER 0x8D94
#define GL_SHORT 0x1402
#define GL_R8_SNORM 0x8F94
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_SRGB 0x8C40
#define GL_GREEN 0x1904
#define GL_ALWAYS 0x0207
#define GL_TEXTURE1 0x84C1
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_ALREADY_SIGNALED 0x911A
#define GL_INT_2_10_10_10_REV 0x8D9F
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_RGBA8_SNORM 0x8F97
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_DARKEN 0x9297
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_INNOCENT_CONTEXT_RESET 0x8254
#define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8 0x93D7
#define GL_QUERY_RESULT 0x8866
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_IMAGE_3D 0x904E
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_DYNAMIC_READ 0x88E9
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_LINES 0x0001
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_COMPRESSED_RGBA_ASTC_6x5 0x93B3
#define GL_BLEND_DST_RGB 0x80C8
#define GL_CCW 0x0901
#define GL_DEPTH 0x1801
#define GL_GEOMETRY_VERTICES_OUT 0x8916
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_COMPRESSED_RGBA_ASTC_12x12 0x93BD
#define GL_INVERT 0x150A
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_MIN 0x8007
#define GL_INT_IMAGE_3D 0x9059
#define GL_TEXTURE17 0x84D1
#define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
#define GL_COMPUTE_SHADER 0x91B9
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_BACK 0x0405
#define GL_RGB8UI 0x8D7D
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT26 0x8CFA
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_COLOR_ATTACHMENT18 0x8CF2
#define GL_RENDERBUFFER 0x8D41
#define GL_DEPTH_BITS 0x0D56
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_TEXTURE30 0x84DE
#define GL_PATCH_VERTICES 0x8E72
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5 0x93D3
#define GL_STENCIL_FUNC 0x0B92
#define GL_DRAW_BUFFER8 0x882D
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_RGB5_A1 0x8057
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_CONDITION_SATISFIED 0x911C
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10 0x93DB
#define GL_TEXTURE2 0x84C2
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#define GL_COMPRESSED_RGBA_ASTC_10x10 0x93BB
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_OFFSET 0x9121
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_FUNC_ADD 0x8006
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_COLOR_ATTACHMENT31 0x8CFF
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_POINTS 0x0000
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_RGB32I 0x8D83
#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE6 0x84C6
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_RG32F 0x8230
#define GL_DEPTH_RANGE 0x0B70
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_COLOR_ATTACHMENT30 0x8CFE
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_VERTEX_BINDING_OFFSET 0x82D7
#define GL_DEBUG_SOURCE_OTHER 0x824B
#define GL_NO_RESET_NOTIFICATION 0x8261
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6 0x93D4
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_RG8_SNORM 0x8F95
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_FRONT_FACE 0x0B46
#define GL_R8 0x8229
#define GL_HSL_HUE 0x92AD
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_LOCATION 0x930E
#define GL_SCREEN 0x9295
#define GL_RGB8 0x8051
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_PATCHES 0x000E
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_FLOAT 0x1406
#define GL_TEXTURE23 0x84D7
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_HSL_COLOR 0x92AF
#define GL_RGBA 0x1908
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_PROGRAM_OUTPUT 0x92E4
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_COMPRESSED_RGBA_ASTC_10x6 0x93B9
#define GL_BLEND 0x0BE2
#define GL_SCISSOR_BOX 0x0C10
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_COMPRESSED_RG11_EAC 0x9272
#define GL_DRAW_BUFFER11 0x8830
#define GL_RGB_INTEGER 0x8D98
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_TEXTURE_2D 0x0DE1
#define GL_FLOAT_VEC4 0x8B52
#define GL_NONE 0
#define GL_MAX_NAME_LENGTH 0x92F6
#define GL_STACK_UNDERFLOW 0x0504
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_PRIMITIVE_BOUNDING_BOX 0x92BE
#define GL_DEBUG_SEVERITY_HIGH 0x9146
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_RGBA32F 0x8814
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_COLOR_ATTACHMENT23 0x8CF7
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_VERTEX_ARRAY_BINDING 0x85B5
#define GL_NUM_ACTIVE_VARIABLES 0x9304
#define GL_DRAW_BUFFER5 0x882A
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_SAMPLER_CUBE 0x8B60
#define GL_INT_VEC4 0x8B55
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_COLOR_ATTACHMENT28 0x8CFC
#define GL_COLOR_ATTACHMENT29 0x8CFD
#define GL_UNIFORM_SIZE 0x8A38
#define GL_SYNC_CONDITION 0x9113
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_BLEND_EQUATION 0x8009
#define GL_FRONT_AND_BACK 0x0408
#define GL_DRAW_BUFFER10 0x882F
#define GL_BLUE_BITS 0x0D54
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_DST_COLOR 0x0306
#define GL_FUNC_SUBTRACT 0x800A
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
#define GL_UNSIGNED_INT 0x1405
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_TEXTURE25 0x84D9
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_MAP_WRITE_BIT 0x0002
#define GL_R32UI 0x8236
#define GL_SYNC_STATUS 0x9114
#define GL_DONT_CARE 0x1100
#define GL_LUMINANCE 0x1909
#define GL_TEXTURE21 0x84D5
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_SCISSOR_TEST 0x0C11
#define GL_FLOAT_VEC2 0x8B50
#define GL_RGBA16UI 0x8D76
#define GL_RGB10_A2 0x8059
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_BUFFER_BINDING 0x9302
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318
#define GL_TYPE 0x92FA
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_FALSE 0
#define GL_LINE_LOOP 0x0002
#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_RG 0x8227
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_PROGRAM_PIPELINE 0x82E4
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_INVALID_OPERATION 0x0502
#define GL_NUM_EXTENSIONS 0x821D
#define GL_INT_SAMPLER_2D 0x8DCA

/*
 * ---------------------------
 * Commands
 * ---------------------------
 */

typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
GLOWDEF PFNGLDISABLEVERTEXATTRIBARRAYPROC glow_glDisableVertexAttribArray;
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint *samplers);
GLOWDEF PFNGLDELETESAMPLERSPROC glow_glDeleteSamplers;
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint *v);
GLOWDEF PFNGLVERTEXATTRIBI4UIVPROC glow_glVertexAttribI4uiv;
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
GLOWDEF PFNGLGETPROGRAMBINARYPROC glow_glGetProgramBinary;
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLOWDEF PFNGLGETDEBUGMESSAGELOGPROC glow_glGetDebugMessageLog;
typedef void (APIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
GLOWDEF PFNGLDISABLEIPROC glow_glDisablei;
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
GLOWDEF PFNGLDRAWELEMENTSPROC glow_glDrawElements;
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)();
GLOWDEF PFNGLRELEASESHADERCOMPILERPROC glow_glReleaseShaderCompiler;
typedef void (APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
GLOWDEF PFNGLUNIFORM3IPROC glow_glUniform3i;
typedef GLboolean (APIENTRYP PFNGLISQUERYPROC)(GLuint id);
GLOWDEF PFNGLISQUERYPROC glow_glIsQuery;
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint *ids);
GLOWDEF PFNGLDELETETRANSFORMFEEDBACKSPROC glow_glDeleteTransformFeedbacks;
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar *name);
GLOWDEF PFNGLGETATTRIBLOCATIONPROC glow_glGetAttribLocation;
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLOWDEF PFNGLGETSHADERSOURCEPROC glow_glGetShaderSource;
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GLOWDEF PFNGLSHADERSOURCEPROC glow_glShaderSource;
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLOWDEF PFNGLFRAMEBUFFERTEXTURELAYERPROC glow_glFramebufferTextureLayer;
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint *value);
GLOWDEF PFNGLCLEARBUFFERUIVPROC glow_glClearBufferuiv;
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat *param);
GLOWDEF PFNGLSAMPLERPARAMETERFVPROC glow_glSamplerParameterfv;
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLOWDEF PFNGLBLENDEQUATIONSEPARATEIPROC glow_glBlendEquationSeparatei;
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
GLOWDEF PFNGLFRAMEBUFFERTEXTUREPROC glow_glFramebufferTexture;
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLOWDEF PFNGLCOLORMASKPROC glow_glColorMask;
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
GLOWDEF PFNGLDISABLEPROC glow_glDisable;
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETRENDERBUFFERPARAMETERIVPROC glow_glGetRenderbufferParameteriv;
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint *params);
GLOWDEF PFNGLGETPROGRAMPIPELINEIVPROC glow_glGetProgramPipelineiv;
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
GLOWDEF PFNGLCOPYIMAGESUBDATAPROC glow_glCopyImageSubData;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETTEXPARAMETERIIVPROC glow_glGetTexParameterIiv;
typedef void (APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
GLOWDEF PFNGLUNIFORM1FPROC glow_glUniform1f;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX4X2FVPROC glow_glUniformMatrix4x2fv;
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
GLOWDEF PFNGLUNIFORM2UIPROC glow_glUniform2ui;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORM1FVPROC glow_glProgramUniform1fv;
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
GLOWDEF PFNGLMEMORYBARRIERPROC glow_glMemoryBarrier;
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
GLOWDEF PFNGLSTENCILMASKPROC glow_glStencilMask;
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
GLOWDEF PFNGLDRAWELEMENTSINSTANCEDPROC glow_glDrawElementsInstanced;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLPROGRAMUNIFORM1IVPROC glow_glProgramUniform1iv;
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
GLOWDEF PFNGLACTIVESHADERPROGRAMPROC glow_glActiveShaderProgram;
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLOWDEF PFNGLBINDIMAGETEXTUREPROC glow_glBindImageTexture;
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLOWDEF PFNGLTEXPARAMETERIVPROC glow_glTexParameteriv;
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLUNIFORM3FVPROC glow_glUniform3fv;
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat *v);
GLOWDEF PFNGLVERTEXATTRIB1FVPROC glow_glVertexAttrib1fv;
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETFRAMEBUFFERPARAMETERIVPROC glow_glGetFramebufferParameteriv;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLOWDEF PFNGLPROGRAMUNIFORM3UIVPROC glow_glProgramUniform3uiv;
typedef void (APIENTRYP PFNGLBLENDBARRIERPROC)();
GLOWDEF PFNGLBLENDBARRIERPROC glow_glBlendBarrier;
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLOWDEF PFNGLTEXSTORAGE3DMULTISAMPLEPROC glow_glTexStorage3DMultisample;
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLUNIFORM2FVPROC glow_glUniform2fv;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX2X3FVPROC glow_glUniformMatrix2x3fv;
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
GLOWDEF PFNGLISSYNCPROC glow_glIsSync;
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint *value);
GLOWDEF PFNGLCLEARBUFFERIVPROC glow_glClearBufferiv;
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean *data);
GLOWDEF PFNGLGETBOOLEANI_VPROC glow_glGetBooleani_v;
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
GLOWDEF PFNGLGENTEXTURESPROC glow_glGenTextures;
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
GLOWDEF PFNGLISSHADERPROC glow_glIsShader;
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLOWDEF PFNGLDRAWRANGEELEMENTSPROC glow_glDrawRangeElements;
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
GLOWDEF PFNGLISBUFFERPROC glow_glIsBuffer;
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
GLOWDEF PFNGLUSEPROGRAMPROC glow_glUseProgram;
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar *uniformBlockName);
GLOWDEF PFNGLGETUNIFORMBLOCKINDEXPROC glow_glGetUniformBlockIndex;
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
GLOWDEF PFNGLGETINTERNALFORMATIVPROC glow_glGetInternalformativ;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glow_glProgramUniformMatrix4x2fv;
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
GLOWDEF PFNGLCLEARPROC glow_glClear;
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLOWDEF PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glow_glCompressedTexSubImage2D;
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLOWDEF PFNGLFRAMEBUFFERTEXTURE2DPROC glow_glFramebufferTexture2D;
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
GLOWDEF PFNGLVALIDATEPROGRAMPIPELINEPROC glow_glValidateProgramPipeline;
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLOWDEF PFNGLTEXPARAMETERIIVPROC glow_glTexParameterIiv;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
GLOWDEF PFNGLPROGRAMUNIFORM1IPROC glow_glProgramUniform1i;
typedef void (APIENTRYP PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLOWDEF PFNGLREADNPIXELSPROC glow_glReadnPixels;
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLOWDEF PFNGLGETACTIVEUNIFORMPROC glow_glGetActiveUniform;
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
GLOWDEF PFNGLVERTEXATTRIBPOINTERPROC glow_glVertexAttribPointer;
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
GLOWDEF PFNGLBINDPROGRAMPIPELINEPROC glow_glBindProgramPipeline;
typedef void (APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
GLOWDEF PFNGLUNIFORM2IPROC glow_glUniform2i;
typedef void * (APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLOWDEF PFNGLMAPBUFFERRANGEPROC glow_glMapBufferRange;
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint *params);
GLOWDEF PFNGLGETVERTEXATTRIBIIVPROC glow_glGetVertexAttribIiv;
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLOWDEF PFNGLTEXSTORAGE2DPROC glow_glTexStorage2D;
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLOWDEF PFNGLGETNUNIFORMUIVPROC glow_glGetnUniformuiv;
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
GLOWDEF PFNGLCHECKFRAMEBUFFERSTATUSPROC glow_glCheckFramebufferStatus;
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
GLOWDEF PFNGLCLEARDEPTHFPROC glow_glClearDepthf;
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint *params);
GLOWDEF PFNGLGETPROGRAMIVPROC glow_glGetProgramiv;
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint *param);
GLOWDEF PFNGLSAMPLERPARAMETERIUIVPROC glow_glSamplerParameterIuiv;
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
GLOWDEF PFNGLVERTEXATTRIB1FPROC glow_glVertexAttrib1f;
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
GLOWDEF PFNGLBINDVERTEXARRAYPROC glow_glBindVertexArray;
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLOWDEF PFNGLREADPIXELSPROC glow_glReadPixels;
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLTEXSUBIMAGE2DPROC glow_glTexSubImage2D;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX4FVPROC glow_glUniformMatrix4fv;
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
GLOWDEF PFNGLSTENCILMASKSEPARATEPROC glow_glStencilMaskSeparate;
typedef void (APIENTRYP PFNGLGENQUERIESPROC)(GLsizei n, GLuint *ids);
GLOWDEF PFNGLGENQUERIESPROC glow_glGenQueries;
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLOWDEF PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glow_glRenderbufferStorageMultisample;
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void *indirect);
GLOWDEF PFNGLDRAWELEMENTSINDIRECTPROC glow_glDrawElementsIndirect;
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLOWDEF PFNGLGETNUNIFORMFVPROC glow_glGetnUniformfv;
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLOWDEF PFNGLDISPATCHCOMPUTEPROC glow_glDispatchCompute;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
GLOWDEF PFNGLPROGRAMUNIFORM1UIPROC glow_glProgramUniform1ui;
typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
GLOWDEF PFNGLISENABLEDIPROC glow_glIsEnabledi;
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLOWDEF PFNGLRENDERBUFFERSTORAGEPROC glow_glRenderbufferStorage;
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLOWDEF PFNGLVERTEXATTRIBI4UIPROC glow_glVertexAttribI4ui;
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
GLOWDEF PFNGLSAMPLERPARAMETERIPROC glow_glSamplerParameteri;
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
GLOWDEF PFNGLDEPTHMASKPROC glow_glDepthMask;
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
GLOWDEF PFNGLISPROGRAMPROC glow_glIsProgram;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
GLOWDEF PFNGLPROGRAMUNIFORM2IPROC glow_glProgramUniform2i;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORM4FVPROC glow_glProgramUniform4fv;
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLSCISSORPROC glow_glScissor;
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum programInterface, const GLchar *name);
GLOWDEF PFNGLGETPROGRAMRESOURCEINDEXPROC glow_glGetProgramResourceIndex;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLOWDEF PFNGLPROGRAMUNIFORM3IPROC glow_glProgramUniform3i;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX2X4FVPROC glow_glUniformMatrix2x4fv;
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLOWDEF PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glow_glDrawRangeElementsBaseVertex;
typedef void (APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLOWDEF PFNGLUNIFORM4FPROC glow_glUniform4f;
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
GLOWDEF PFNGLFLUSHMAPPEDBUFFERRANGEPROC glow_glFlushMappedBufferRange;
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
GLOWDEF PFNGLISSAMPLERPROC glow_glIsSampler;
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
GLOWDEF PFNGLPROGRAMBINARYPROC glow_glProgramBinary;
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar *const*strings);
GLOWDEF PFNGLCREATESHADERPROGRAMVPROC glow_glCreateShaderProgramv;
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
GLOWDEF PFNGLBINDTEXTUREPROC glow_glBindTexture;
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
GLOWDEF PFNGLGENRENDERBUFFERSPROC glow_glGenRenderbuffers;
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLUNIFORM1IVPROC glow_glUniform1iv;
typedef void (APIENTRYP PFNGLCOLORMASKIPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLOWDEF PFNGLCOLORMASKIPROC glow_glColorMaski;
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLOWDEF PFNGLVERTEXATTRIBIPOINTERPROC glow_glVertexAttribIPointer;
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
GLOWDEF PFNGLUNIFORMBLOCKBINDINGPROC glow_glUniformBlockBinding;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glow_glProgramUniformMatrix3x4fv;
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void *userParam);
GLOWDEF PFNGLDEBUGMESSAGECALLBACKPROC glow_glDebugMessageCallback;
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint *param);
GLOWDEF PFNGLSAMPLERPARAMETERIIVPROC glow_glSamplerParameterIiv;
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
GLOWDEF PFNGLCOMPILESHADERPROC glow_glCompileShader;
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
GLOWDEF PFNGLTEXPARAMETERFPROC glow_glTexParameterf;
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLOWDEF PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glow_glCompressedTexSubImage3D;
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETTEXLEVELPARAMETERFVPROC glow_glGetTexLevelParameterfv;
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
GLOWDEF PFNGLDRAWARRAYSPROC glow_glDrawArrays;
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
GLOWDEF PFNGLLINKPROGRAMPROC glow_glLinkProgram;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLOWDEF PFNGLPROGRAMUNIFORM2FPROC glow_glProgramUniform2f;
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC)();
GLOWDEF PFNGLCREATEPROGRAMPROC glow_glCreateProgram;
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
GLOWDEF PFNGLGETPROGRAMINTERFACEIVPROC glow_glGetProgramInterfaceiv;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
GLOWDEF PFNGLPROGRAMUNIFORM2UIPROC glow_glProgramUniform2ui;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLOWDEF PFNGLPROGRAMUNIFORM1UIVPROC glow_glProgramUniform1uiv;
typedef void (APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
GLOWDEF PFNGLUNIFORM1IPROC glow_glUniform1i;
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void **params);
GLOWDEF PFNGLGETBUFFERPOINTERVPROC glow_glGetBufferPointerv;
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)();
GLOWDEF PFNGLENDTRANSFORMFEEDBACKPROC glow_glEndTransformFeedback;
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint *params);
GLOWDEF PFNGLGETSAMPLERPARAMETERIIVPROC glow_glGetSamplerParameterIiv;
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
GLOWDEF PFNGLGENFRAMEBUFFERSPROC glow_glGenFramebuffers;
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint *samplers);
GLOWDEF PFNGLGENSAMPLERSPROC glow_glGenSamplers;
typedef void (APIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
GLOWDEF PFNGLENABLEIPROC glow_glEnablei;
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void *ptr, GLsizei length, const GLchar *label);
GLOWDEF PFNGLOBJECTPTRLABELPROC glow_glObjectPtrLabel;
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
GLOWDEF PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glow_glDrawElementsInstancedBaseVertex;
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
GLOWDEF PFNGLFRONTFACEPROC glow_glFrontFace;
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat *v);
GLOWDEF PFNGLVERTEXATTRIB4FVPROC glow_glVertexAttrib4fv;
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint *pipelines);
GLOWDEF PFNGLDELETEPROGRAMPIPELINESPROC glow_glDeleteProgramPipelines;
typedef void (APIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
GLOWDEF PFNGLTEXBUFFERPROC glow_glTexBuffer;
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
GLOWDEF PFNGLSTENCILOPPROC glow_glStencilOp;
typedef void (APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
GLOWDEF PFNGLUNIFORM2FPROC glow_glUniform2f;
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint *params);
GLOWDEF PFNGLGETUNIFORMUIVPROC glow_glGetUniformuiv;
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLVIEWPORTPROC glow_glViewport;
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint *arrays);
GLOWDEF PFNGLDELETEVERTEXARRAYSPROC glow_glDeleteVertexArrays;
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
GLOWDEF PFNGLVERTEXATTRIBI4IPROC glow_glVertexAttribI4i;
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64 *data);
GLOWDEF PFNGLGETINTEGER64I_VPROC glow_glGetInteger64i_v;
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint *param);
GLOWDEF PFNGLSAMPLERPARAMETERIVPROC glow_glSamplerParameteriv;
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean *data);
GLOWDEF PFNGLGETBOOLEANVPROC glow_glGetBooleanv;
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLTEXIMAGE2DPROC glow_glTexImage2D;
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLUNIFORM3IVPROC glow_glUniform3iv;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORM2FVPROC glow_glProgramUniform2fv;
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint *params);
GLOWDEF PFNGLGETQUERYOBJECTUIVPROC glow_glGetQueryObjectuiv;
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint *v);
GLOWDEF PFNGLVERTEXATTRIBI4IVPROC glow_glVertexAttribI4iv;
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
GLOWDEF PFNGLGETUNIFORMINDICESPROC glow_glGetUniformIndices;
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
GLOWDEF PFNGLDELETETEXTURESPROC glow_glDeleteTextures;
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
GLOWDEF PFNGLISTEXTUREPROC glow_glIsTexture;
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
GLOWDEF PFNGLPIXELSTOREIPROC glow_glPixelStorei;
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
GLOWDEF PFNGLINVALIDATEFRAMEBUFFERPROC glow_glInvalidateFramebuffer;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glow_glProgramUniformMatrix2x3fv;
typedef void (APIENTRYP PFNGLBLENDFUNCIPROC)(GLuint buf, GLenum src, GLenum dst);
GLOWDEF PFNGLBLENDFUNCIPROC glow_glBlendFunci;
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
GLOWDEF PFNGLCLEARSTENCILPROC glow_glClearStencil;
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
GLOWDEF PFNGLVALIDATEPROGRAMPROC glow_glValidateProgram;
typedef void (APIENTRYP PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETQUERYIVPROC glow_glGetQueryiv;
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLOWDEF PFNGLBLITFRAMEBUFFERPROC glow_glBlitFramebuffer;
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLOWDEF PFNGLCOPYBUFFERSUBDATAPROC glow_glCopyBufferSubData;
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void *indirect);
GLOWDEF PFNGLDRAWARRAYSINDIRECTPROC glow_glDrawArraysIndirect;
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
GLOWDEF PFNGLUSEPROGRAMSTAGESPROC glow_glUseProgramStages;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX4FVPROC glow_glProgramUniformMatrix4fv;
typedef void (APIENTRYP PFNGLFINISHPROC)();
GLOWDEF PFNGLFINISHPROC glow_glFinish;
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLOWDEF PFNGLGETSHADERINFOLOGPROC glow_glGetShaderInfoLog;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX3X4FVPROC glow_glUniformMatrix3x4fv;
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLOWDEF PFNGLVERTEXATTRIBFORMATPROC glow_glVertexAttribFormat;
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLOWDEF PFNGLGETNUNIFORMIVPROC glow_glGetnUniformiv;
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
GLOWDEF PFNGLHINTPROC glow_glHint;
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum target);
GLOWDEF PFNGLUNMAPBUFFERPROC glow_glUnmapBuffer;
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
GLOWDEF PFNGLVERTEXBINDINGDIVISORPROC glow_glVertexBindingDivisor;
typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint buf, GLenum mode);
GLOWDEF PFNGLBLENDEQUATIONIPROC glow_glBlendEquationi;
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLCOPYTEXSUBIMAGE2DPROC glow_glCopyTexSubImage2D;
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
GLOWDEF PFNGLENABLEPROC glow_glEnable;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLPROGRAMUNIFORM4IVPROC glow_glProgramUniform4iv;
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint *params);
GLOWDEF PFNGLGETVERTEXATTRIBIVPROC glow_glGetVertexAttribiv;
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLUNIFORM1FVPROC glow_glUniform1fv;
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum programInterface, const GLchar *name);
GLOWDEF PFNGLGETPROGRAMRESOURCELOCATIONPROC glow_glGetProgramResourceLocation;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLOWDEF PFNGLPROGRAMUNIFORM3UIPROC glow_glProgramUniform3ui;
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLOWDEF PFNGLDRAWELEMENTSBASEVERTEXPROC glow_glDrawElementsBaseVertex;
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
GLOWDEF PFNGLBLENDEQUATIONPROC glow_glBlendEquation;
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
GLOWDEF PFNGLCREATESHADERPROC glow_glCreateShader;
typedef void (APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
GLOWDEF PFNGLDETACHSHADERPROC glow_glDetachShader;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glow_glProgramUniformMatrix4x3fv;
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
GLOWDEF PFNGLBINDRENDERBUFFERPROC glow_glBindRenderbuffer;
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLOWDEF PFNGLVERTEXATTRIB4FPROC glow_glVertexAttrib4f;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLOWDEF PFNGLPROGRAMUNIFORM4UIVPROC glow_glProgramUniform4uiv;
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC)(GLfloat value);
GLOWDEF PFNGLMINSAMPLESHADINGPROC glow_glMinSampleShading;
typedef void (APIENTRYP PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
GLOWDEF PFNGLBEGINQUERYPROC glow_glBeginQuery;
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
GLOWDEF PFNGLBINDBUFFERBASEPROC glow_glBindBufferBase;
typedef GLubyte (APIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
GLOWDEF PFNGLGETSTRINGIPROC glow_glGetStringi;
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint *ids);
GLOWDEF PFNGLGENTRANSFORMFEEDBACKSPROC glow_glGenTransformFeedbacks;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glow_glProgramUniformMatrix2x4fv;
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLOWDEF PFNGLBLENDFUNCSEPARATEIPROC glow_glBlendFuncSeparatei;
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GLOWDEF PFNGLGETSHADERPRECISIONFORMATPROC glow_glGetShaderPrecisionFormat;
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar *name);
GLOWDEF PFNGLGETUNIFORMLOCATIONPROC glow_glGetUniformLocation;
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
GLOWDEF PFNGLSAMPLERPARAMETERFPROC glow_glSamplerParameterf;
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
GLOWDEF PFNGLISTRANSFORMFEEDBACKPROC glow_glIsTransformFeedback;
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLINVALIDATESUBFRAMEBUFFERPROC glow_glInvalidateSubFramebuffer;
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint *params);
GLOWDEF PFNGLGETTEXLEVELPARAMETERIVPROC glow_glGetTexLevelParameteriv;
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLOWDEF PFNGLTEXBUFFERRANGEPROC glow_glTexBufferRange;
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat *params);
GLOWDEF PFNGLGETUNIFORMFVPROC glow_glGetUniformfv;
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLOWDEF PFNGLBINDBUFFERRANGEPROC glow_glBindBufferRange;
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETSAMPLERPARAMETERFVPROC glow_glGetSamplerParameterfv;
typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLOWDEF PFNGLBUFFERDATAPROC glow_glBufferData;
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
GLOWDEF PFNGLISFRAMEBUFFERPROC glow_glIsFramebuffer;
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
GLOWDEF PFNGLPOLYGONOFFSETPROC glow_glPolygonOffset;
typedef void (APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLOWDEF PFNGLUNIFORM4IPROC glow_glUniform4i;
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLTEXIMAGE3DPROC glow_glTexImage3D;
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
GLOWDEF PFNGLDISPATCHCOMPUTEINDIRECTPROC glow_glDispatchComputeIndirect;
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLOWDEF PFNGLDEBUGMESSAGECONTROLPROC glow_glDebugMessageControl;
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLOWDEF PFNGLCOMPRESSEDTEXIMAGE2DPROC glow_glCompressedTexImage2D;
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
GLOWDEF PFNGLDELETEPROGRAMPROC glow_glDeleteProgram;
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
GLOWDEF PFNGLSTENCILFUNCPROC glow_glStencilFunc;
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLOWDEF PFNGLGETPROGRAMINFOLOGPROC glow_glGetProgramInfoLog;
typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
GLOWDEF PFNGLDELETESYNCPROC glow_glDeleteSync;
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
GLOWDEF PFNGLBLENDFUNCPROC glow_glBlendFunc;
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLOWDEF PFNGLCOPYTEXIMAGE2DPROC glow_glCopyTexImage2D;
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
GLOWDEF PFNGLDELETEBUFFERSPROC glow_glDeleteBuffers;
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
GLOWDEF PFNGLGETPROGRAMRESOURCEIVPROC glow_glGetProgramResourceiv;
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLOWDEF PFNGLGETPROGRAMPIPELINEINFOLOGPROC glow_glGetProgramPipelineInfoLog;
typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
GLOWDEF PFNGLBINDBUFFERPROC glow_glBindBuffer;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETTEXPARAMETERFVPROC glow_glGetTexParameterfv;
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLOWDEF PFNGLTEXSTORAGE3DPROC glow_glTexStorage3D;
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
GLOWDEF PFNGLDEPTHFUNCPROC glow_glDepthFunc;
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLOWDEF PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glow_glGetFramebufferAttachmentParameteriv;
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLOWDEF PFNGLVERTEXATTRIBIFORMATPROC glow_glVertexAttribIFormat;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX4X3FVPROC glow_glUniformMatrix4x3fv;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLOWDEF PFNGLPROGRAMUNIFORM3FPROC glow_glProgramUniform3f;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLOWDEF PFNGLPROGRAMUNIFORM2UIVPROC glow_glProgramUniform2uiv;
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum pname, GLint value);
GLOWDEF PFNGLPATCHPARAMETERIPROC glow_glPatchParameteri;
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint *renderbuffers);
GLOWDEF PFNGLDELETERENDERBUFFERSPROC glow_glDeleteRenderbuffers;
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
GLOWDEF PFNGLISRENDERBUFFERPROC glow_glIsRenderbuffer;
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat *v);
GLOWDEF PFNGLVERTEXATTRIB3FVPROC glow_glVertexAttrib3fv;
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLOWDEF PFNGLUNIFORM4UIPROC glow_glUniform4ui;
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 *data);
GLOWDEF PFNGLGETINTEGER64VPROC glow_glGetInteger64v;
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint *pipelines);
GLOWDEF PFNGLGENPROGRAMPIPELINESPROC glow_glGenProgramPipelines;
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLOWDEF PFNGLTEXSTORAGE2DMULTISAMPLEPROC glow_glTexStorage2DMultisample;
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar *name);
GLOWDEF PFNGLBINDATTRIBLOCATIONPROC glow_glBindAttribLocation;
typedef void (APIENTRYP PFNGLENDQUERYPROC)(GLenum target);
GLOWDEF PFNGLENDQUERYPROC glow_glEndQuery;
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint *params);
GLOWDEF PFNGLGETVERTEXATTRIBIUIVPROC glow_glGetVertexAttribIuiv;
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLOWDEF PFNGLSTENCILOPSEPARATEPROC glow_glStencilOpSeparate;
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLOWDEF PFNGLCOMPRESSEDTEXIMAGE3DPROC glow_glCompressedTexImage3D;
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint *data);
GLOWDEF PFNGLGETINTEGERI_VPROC glow_glGetIntegeri_v;
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
GLOWDEF PFNGLTRANSFORMFEEDBACKVARYINGSPROC glow_glTransformFeedbackVaryings;
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint *value);
GLOWDEF PFNGLUNIFORM1UIVPROC glow_glUniform1uiv;
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
GLOWDEF PFNGLENABLEVERTEXATTRIBARRAYPROC glow_glEnableVertexAttribArray;
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETVERTEXATTRIBFVPROC glow_glGetVertexAttribfv;
typedef void (APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
GLOWDEF PFNGLSHADERBINARYPROC glow_glShaderBinary;
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)();
GLOWDEF PFNGLRESUMETRANSFORMFEEDBACKPROC glow_glResumeTransformFeedback;
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
GLOWDEF PFNGLFRAMEBUFFERPARAMETERIPROC glow_glFramebufferParameteri;
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint *params);
GLOWDEF PFNGLTEXPARAMETERIUIVPROC glow_glTexParameterIuiv;
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
GLOWDEF PFNGLGETACTIVEUNIFORMSIVPROC glow_glGetActiveUniformsiv;
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
GLOWDEF PFNGLGETACTIVEUNIFORMBLOCKIVPROC glow_glGetActiveUniformBlockiv;
typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
GLOWDEF PFNGLFENCESYNCPROC glow_glFenceSync;
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint *data);
GLOWDEF PFNGLGETINTEGERVPROC glow_glGetIntegerv;
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
GLOWDEF PFNGLISENABLEDPROC glow_glIsEnabled;
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
GLOWDEF PFNGLLINEWIDTHPROC glow_glLineWidth;
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLOWDEF PFNGLVERTEXATTRIB3FPROC glow_glVertexAttrib3f;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint *params);
GLOWDEF PFNGLGETTEXPARAMETERIUIVPROC glow_glGetTexParameterIuiv;
typedef void (APIENTRYP PFNGLFLUSHPROC)();
GLOWDEF PFNGLFLUSHPROC glow_glFlush;
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLOWDEF PFNGLFRAMEBUFFERRENDERBUFFERPROC glow_glFramebufferRenderbuffer;
typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
GLOWDEF PFNGLGENBUFFERSPROC glow_glGenBuffers;
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLOWDEF PFNGLGETATTACHEDSHADERSPROC glow_glGetAttachedShaders;
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum *bufs);
GLOWDEF PFNGLDRAWBUFFERSPROC glow_glDrawBuffers;
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint *value);
GLOWDEF PFNGLUNIFORM4UIVPROC glow_glUniform4uiv;
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)();
GLOWDEF PFNGLPAUSETRANSFORMFEEDBACKPROC glow_glPauseTransformFeedback;
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLOWDEF PFNGLBINDVERTEXBUFFERPROC glow_glBindVertexBuffer;
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
GLOWDEF PFNGLPUSHDEBUGGROUPPROC glow_glPushDebugGroup;
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLUNIFORM2IVPROC glow_glUniform2iv;
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLUNIFORM4FVPROC glow_glUniform4fv;
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
GLOWDEF PFNGLBINDTRANSFORMFEEDBACKPROC glow_glBindTransformFeedback;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLPROGRAMUNIFORM2IVPROC glow_glProgramUniform2iv;
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat *val);
GLOWDEF PFNGLGETMULTISAMPLEFVPROC glow_glGetMultisamplefv;
typedef void (APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint *params);
GLOWDEF PFNGLGETSHADERIVPROC glow_glGetShaderiv;
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLUNIFORM4IVPROC glow_glUniform4iv;
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64 *params);
GLOWDEF PFNGLGETBUFFERPARAMETERI64VPROC glow_glGetBufferParameteri64v;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX2FVPROC glow_glUniformMatrix2fv;
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint *value);
GLOWDEF PFNGLUNIFORM3UIVPROC glow_glUniform3uiv;
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLOWDEF PFNGLGETPROGRAMRESOURCENAMEPROC glow_glGetProgramResourceName;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLOWDEF PFNGLPROGRAMUNIFORM4IPROC glow_glProgramUniform4i;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
GLOWDEF PFNGLPROGRAMUNIFORM1FPROC glow_glProgramUniform1f;
typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
GLOWDEF PFNGLCULLFACEPROC glow_glCullFace;
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
GLOWDEF PFNGLDEPTHRANGEFPROC glow_glDepthRangef;
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
GLOWDEF PFNGLSAMPLECOVERAGEPROC glow_glSampleCoverage;
typedef void (APIENTRYP PFNGLPRIMITIVEBOUNDINGBOXPROC)(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
GLOWDEF PFNGLPRIMITIVEBOUNDINGBOXPROC glow_glPrimitiveBoundingBox;
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
GLOWDEF PFNGLBEGINTRANSFORMFEEDBACKPROC glow_glBeginTransformFeedback;
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLOWDEF PFNGLCLEARBUFFERFVPROC glow_glClearBufferfv;
typedef void (APIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, void **params);
GLOWDEF PFNGLGETPOINTERVPROC glow_glGetPointerv;
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLTEXSUBIMAGE3DPROC glow_glTexSubImage3D;
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
GLOWDEF PFNGLUNIFORM1UIPROC glow_glUniform1ui;
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
GLOWDEF PFNGLACTIVETEXTUREPROC glow_glActiveTexture;
typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
GLOWDEF PFNGLATTACHSHADERPROC glow_glAttachShader;
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat *data);
GLOWDEF PFNGLGETFLOATVPROC glow_glGetFloatv;
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLCOPYTEXSUBIMAGE3DPROC glow_glCopyTexSubImage3D;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX3X2FVPROC glow_glUniformMatrix3x2fv;
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
GLOWDEF PFNGLBINDSAMPLERPROC glow_glBindSampler;
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
GLOWDEF PFNGLVERTEXATTRIBBINDINGPROC glow_glVertexAttribBinding;
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint *framebuffers);
GLOWDEF PFNGLDELETEFRAMEBUFFERSPROC glow_glDeleteFramebuffers;
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)();
GLOWDEF PFNGLGETERRORPROC glow_glGetError;
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLTEXPARAMETERFVPROC glow_glTexParameterfv;
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLOWDEF PFNGLDRAWARRAYSINSTANCEDPROC glow_glDrawArraysInstanced;
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLOWDEF PFNGLBLENDFUNCSEPARATEPROC glow_glBlendFuncSeparate;
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
GLOWDEF PFNGLGENVERTEXARRAYSPROC glow_glGenVertexArrays;
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
GLOWDEF PFNGLISVERTEXARRAYPROC glow_glIsVertexArray;
typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLOWDEF PFNGLWAITSYNCPROC glow_glWaitSync;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLOWDEF PFNGLPROGRAMUNIFORM4UIPROC glow_glProgramUniform4ui;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX2FVPROC glow_glProgramUniformMatrix2fv;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETTEXPARAMETERIVPROC glow_glGetTexParameteriv;
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void **pointer);
GLOWDEF PFNGLGETVERTEXATTRIBPOINTERVPROC glow_glGetVertexAttribPointerv;
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLOWDEF PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glow_glGetTransformFeedbackVarying;
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
GLOWDEF PFNGLUNIFORM3UIPROC glow_glUniform3ui;
typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
GLOWDEF PFNGLGETSYNCIVPROC glow_glGetSynciv;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLOWDEF PFNGLPROGRAMUNIFORM4FPROC glow_glProgramUniform4f;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLOWDEF PFNGLPROGRAMUNIFORM3IVPROC glow_glProgramUniform3iv;
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLOWDEF PFNGLDEBUGMESSAGEINSERTPROC glow_glDebugMessageInsert;
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
GLOWDEF PFNGLGENERATEMIPMAPPROC glow_glGenerateMipmap;
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint *params);
GLOWDEF PFNGLGETUNIFORMIVPROC glow_glGetUniformiv;
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
GLOWDEF PFNGLTEXPARAMETERIPROC glow_glTexParameteri;
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC)();
GLOWDEF PFNGLPOPDEBUGGROUPPROC glow_glPopDebugGroup;
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
GLOWDEF PFNGLGETOBJECTPTRLABELPROC glow_glGetObjectPtrLabel;
typedef GLubyte (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
GLOWDEF PFNGLGETSTRINGPROC glow_glGetString;
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
GLOWDEF PFNGLSTENCILFUNCSEPARATEPROC glow_glStencilFuncSeparate;
typedef void (APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLOWDEF PFNGLUNIFORM3FPROC glow_glUniform3f;
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
GLOWDEF PFNGLBINDFRAMEBUFFERPROC glow_glBindFramebuffer;
typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLOWDEF PFNGLBLENDCOLORPROC glow_glBlendColor;
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
GLOWDEF PFNGLBLENDEQUATIONSEPARATEPROC glow_glBlendEquationSeparate;
typedef void (APIENTRYP PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
GLOWDEF PFNGLOBJECTLABELPROC glow_glObjectLabel;
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
GLOWDEF PFNGLGETOBJECTLABELPROC glow_glGetObjectLabel;
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)();
GLOWDEF PFNGLGETGRAPHICSRESETSTATUSPROC glow_glGetGraphicsResetStatus;
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLOWDEF PFNGLCLEARBUFFERFIPROC glow_glClearBufferfi;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORM3FVPROC glow_glProgramUniform3fv;
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
GLOWDEF PFNGLSAMPLEMASKIPROC glow_glSampleMaski;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glow_glProgramUniformMatrix3x2fv;
typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
GLOWDEF PFNGLDELETESHADERPROC glow_glDeleteShader;
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar *name);
GLOWDEF PFNGLGETFRAGDATALOCATIONPROC glow_glGetFragDataLocation;
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX3FVPROC glow_glProgramUniformMatrix3fv;
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint *params);
GLOWDEF PFNGLGETSAMPLERPARAMETERIUIVPROC glow_glGetSamplerParameterIuiv;
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLOWDEF PFNGLBUFFERSUBDATAPROC glow_glBufferSubData;
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLOWDEF PFNGLCLEARCOLORPROC glow_glClearColor;
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat *v);
GLOWDEF PFNGLVERTEXATTRIB2FVPROC glow_glVertexAttrib2fv;
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint *params);
GLOWDEF PFNGLGETSAMPLERPARAMETERIVPROC glow_glGetSamplerParameteriv;
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
GLOWDEF PFNGLPROGRAMPARAMETERIPROC glow_glProgramParameteri;
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint *ids);
GLOWDEF PFNGLDELETEQUERIESPROC glow_glDeleteQueries;
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
GLOWDEF PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glow_glGetActiveUniformBlockName;
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLOWDEF PFNGLCLIENTWAITSYNCPROC glow_glClientWaitSync;
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
GLOWDEF PFNGLVERTEXATTRIBDIVISORPROC glow_glVertexAttribDivisor;
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
GLOWDEF PFNGLISPROGRAMPIPELINEPROC glow_glIsProgramPipeline;
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLOWDEF PFNGLUNIFORMMATRIX3FVPROC glow_glUniformMatrix3fv;
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
GLOWDEF PFNGLVERTEXATTRIB2FPROC glow_glVertexAttrib2f;
typedef void (APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
GLOWDEF PFNGLREADBUFFERPROC glow_glReadBuffer;
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
GLOWDEF PFNGLMEMORYBARRIERBYREGIONPROC glow_glMemoryBarrierByRegion;
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLOWDEF PFNGLGETACTIVEATTRIBPROC glow_glGetActiveAttrib;
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETBUFFERPARAMETERIVPROC glow_glGetBufferParameteriv;
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint *value);
GLOWDEF PFNGLUNIFORM2UIVPROC glow_glUniform2uiv;


#ifndef GLOW_DEBUG

#define glDisableVertexAttribArray glow_glDisableVertexAttribArray
#define glDeleteSamplers glow_glDeleteSamplers
#define glVertexAttribI4uiv glow_glVertexAttribI4uiv
#define glGetProgramBinary glow_glGetProgramBinary
#define glGetDebugMessageLog glow_glGetDebugMessageLog
#define glDisablei glow_glDisablei
#define glDrawElements glow_glDrawElements
#define glReleaseShaderCompiler glow_glReleaseShaderCompiler
#define glUniform3i glow_glUniform3i
#define glIsQuery glow_glIsQuery
#define glDeleteTransformFeedbacks glow_glDeleteTransformFeedbacks
#define glGetAttribLocation glow_glGetAttribLocation
#define glGetShaderSource glow_glGetShaderSource
#define glShaderSource glow_glShaderSource
#define glFramebufferTextureLayer glow_glFramebufferTextureLayer
#define glClearBufferuiv glow_glClearBufferuiv
#define glSamplerParameterfv glow_glSamplerParameterfv
#define glBlendEquationSeparatei glow_glBlendEquationSeparatei
#define glFramebufferTexture glow_glFramebufferTexture
#define glColorMask glow_glColorMask
#define glDisable glow_glDisable
#define glGetRenderbufferParameteriv glow_glGetRenderbufferParameteriv
#define glGetProgramPipelineiv glow_glGetProgramPipelineiv
#define glCopyImageSubData glow_glCopyImageSubData
#define glGetTexParameterIiv glow_glGetTexParameterIiv
#define glUniform1f glow_glUniform1f
#define glUniformMatrix4x2fv glow_glUniformMatrix4x2fv
#define glUniform2ui glow_glUniform2ui
#define glProgramUniform1fv glow_glProgramUniform1fv
#define glMemoryBarrier glow_glMemoryBarrier
#define glStencilMask glow_glStencilMask
#define glDrawElementsInstanced glow_glDrawElementsInstanced
#define glProgramUniform1iv glow_glProgramUniform1iv
#define glActiveShaderProgram glow_glActiveShaderProgram
#define glBindImageTexture glow_glBindImageTexture
#define glTexParameteriv glow_glTexParameteriv
#define glUniform3fv glow_glUniform3fv
#define glVertexAttrib1fv glow_glVertexAttrib1fv
#define glGetFramebufferParameteriv glow_glGetFramebufferParameteriv
#define glProgramUniform3uiv glow_glProgramUniform3uiv
#define glBlendBarrier glow_glBlendBarrier
#define glTexStorage3DMultisample glow_glTexStorage3DMultisample
#define glUniform2fv glow_glUniform2fv
#define glUniformMatrix2x3fv glow_glUniformMatrix2x3fv
#define glIsSync glow_glIsSync
#define glClearBufferiv glow_glClearBufferiv
#define glGetBooleani_v glow_glGetBooleani_v
#define glGenTextures glow_glGenTextures
#define glIsShader glow_glIsShader
#define glDrawRangeElements glow_glDrawRangeElements
#define glIsBuffer glow_glIsBuffer
#define glUseProgram glow_glUseProgram
#define glGetUniformBlockIndex glow_glGetUniformBlockIndex
#define glGetInternalformativ glow_glGetInternalformativ
#define glProgramUniformMatrix4x2fv glow_glProgramUniformMatrix4x2fv
#define glClear glow_glClear
#define glCompressedTexSubImage2D glow_glCompressedTexSubImage2D
#define glFramebufferTexture2D glow_glFramebufferTexture2D
#define glValidateProgramPipeline glow_glValidateProgramPipeline
#define glTexParameterIiv glow_glTexParameterIiv
#define glProgramUniform1i glow_glProgramUniform1i
#define glReadnPixels glow_glReadnPixels
#define glGetActiveUniform glow_glGetActiveUniform
#define glVertexAttribPointer glow_glVertexAttribPointer
#define glBindProgramPipeline glow_glBindProgramPipeline
#define glUniform2i glow_glUniform2i
#define glMapBufferRange glow_glMapBufferRange
#define glGetVertexAttribIiv glow_glGetVertexAttribIiv
#define glTexStorage2D glow_glTexStorage2D
#define glGetnUniformuiv glow_glGetnUniformuiv
#define glCheckFramebufferStatus glow_glCheckFramebufferStatus
#define glClearDepthf glow_glClearDepthf
#define glGetProgramiv glow_glGetProgramiv
#define glSamplerParameterIuiv glow_glSamplerParameterIuiv
#define glVertexAttrib1f glow_glVertexAttrib1f
#define glBindVertexArray glow_glBindVertexArray
#define glReadPixels glow_glReadPixels
#define glTexSubImage2D glow_glTexSubImage2D
#define glUniformMatrix4fv glow_glUniformMatrix4fv
#define glStencilMaskSeparate glow_glStencilMaskSeparate
#define glGenQueries glow_glGenQueries
#define glRenderbufferStorageMultisample glow_glRenderbufferStorageMultisample
#define glDrawElementsIndirect glow_glDrawElementsIndirect
#define glGetnUniformfv glow_glGetnUniformfv
#define glDispatchCompute glow_glDispatchCompute
#define glProgramUniform1ui glow_glProgramUniform1ui
#define glIsEnabledi glow_glIsEnabledi
#define glRenderbufferStorage glow_glRenderbufferStorage
#define glVertexAttribI4ui glow_glVertexAttribI4ui
#define glSamplerParameteri glow_glSamplerParameteri
#define glDepthMask glow_glDepthMask
#define glIsProgram glow_glIsProgram
#define glProgramUniform2i glow_glProgramUniform2i
#define glProgramUniform4fv glow_glProgramUniform4fv
#define glScissor glow_glScissor
#define glGetProgramResourceIndex glow_glGetProgramResourceIndex
#define glProgramUniform3i glow_glProgramUniform3i
#define glUniformMatrix2x4fv glow_glUniformMatrix2x4fv
#define glDrawRangeElementsBaseVertex glow_glDrawRangeElementsBaseVertex
#define glUniform4f glow_glUniform4f
#define glFlushMappedBufferRange glow_glFlushMappedBufferRange
#define glIsSampler glow_glIsSampler
#define glProgramBinary glow_glProgramBinary
#define glCreateShaderProgramv glow_glCreateShaderProgramv
#define glBindTexture glow_glBindTexture
#define glGenRenderbuffers glow_glGenRenderbuffers
#define glUniform1iv glow_glUniform1iv
#define glColorMaski glow_glColorMaski
#define glVertexAttribIPointer glow_glVertexAttribIPointer
#define glUniformBlockBinding glow_glUniformBlockBinding
#define glProgramUniformMatrix3x4fv glow_glProgramUniformMatrix3x4fv
#define glDebugMessageCallback glow_glDebugMessageCallback
#define glSamplerParameterIiv glow_glSamplerParameterIiv
#define glCompileShader glow_glCompileShader
#define glTexParameterf glow_glTexParameterf
#define glCompressedTexSubImage3D glow_glCompressedTexSubImage3D
#define glGetTexLevelParameterfv glow_glGetTexLevelParameterfv
#define glDrawArrays glow_glDrawArrays
#define glLinkProgram glow_glLinkProgram
#define glProgramUniform2f glow_glProgramUniform2f
#define glCreateProgram glow_glCreateProgram
#define glGetProgramInterfaceiv glow_glGetProgramInterfaceiv
#define glProgramUniform2ui glow_glProgramUniform2ui
#define glProgramUniform1uiv glow_glProgramUniform1uiv
#define glUniform1i glow_glUniform1i
#define glGetBufferPointerv glow_glGetBufferPointerv
#define glEndTransformFeedback glow_glEndTransformFeedback
#define glGetSamplerParameterIiv glow_glGetSamplerParameterIiv
#define glGenFramebuffers glow_glGenFramebuffers
#define glGenSamplers glow_glGenSamplers
#define glEnablei glow_glEnablei
#define glObjectPtrLabel glow_glObjectPtrLabel
#define glDrawElementsInstancedBaseVertex glow_glDrawElementsInstancedBaseVertex
#define glFrontFace glow_glFrontFace
#define glVertexAttrib4fv glow_glVertexAttrib4fv
#define glDeleteProgramPipelines glow_glDeleteProgramPipelines
#define glTexBuffer glow_glTexBuffer
#define glStencilOp glow_glStencilOp
#define glUniform2f glow_glUniform2f
#define glGetUniformuiv glow_glGetUniformuiv
#define glViewport glow_glViewport
#define glDeleteVertexArrays glow_glDeleteVertexArrays
#define glVertexAttribI4i glow_glVertexAttribI4i
#define glGetInteger64i_v glow_glGetInteger64i_v
#define glSamplerParameteriv glow_glSamplerParameteriv
#define glGetBooleanv glow_glGetBooleanv
#define glTexImage2D glow_glTexImage2D
#define glUniform3iv glow_glUniform3iv
#define glProgramUniform2fv glow_glProgramUniform2fv
#define glGetQueryObjectuiv glow_glGetQueryObjectuiv
#define glVertexAttribI4iv glow_glVertexAttribI4iv
#define glGetUniformIndices glow_glGetUniformIndices
#define glDeleteTextures glow_glDeleteTextures
#define glIsTexture glow_glIsTexture
#define glPixelStorei glow_glPixelStorei
#define glInvalidateFramebuffer glow_glInvalidateFramebuffer
#define glProgramUniformMatrix2x3fv glow_glProgramUniformMatrix2x3fv
#define glBlendFunci glow_glBlendFunci
#define glClearStencil glow_glClearStencil
#define glValidateProgram glow_glValidateProgram
#define glGetQueryiv glow_glGetQueryiv
#define glBlitFramebuffer glow_glBlitFramebuffer
#define glCopyBufferSubData glow_glCopyBufferSubData
#define glDrawArraysIndirect glow_glDrawArraysIndirect
#define glUseProgramStages glow_glUseProgramStages
#define glProgramUniformMatrix4fv glow_glProgramUniformMatrix4fv
#define glFinish glow_glFinish
#define glGetShaderInfoLog glow_glGetShaderInfoLog
#define glUniformMatrix3x4fv glow_glUniformMatrix3x4fv
#define glVertexAttribFormat glow_glVertexAttribFormat
#define glGetnUniformiv glow_glGetnUniformiv
#define glHint glow_glHint
#define glUnmapBuffer glow_glUnmapBuffer
#define glVertexBindingDivisor glow_glVertexBindingDivisor
#define glBlendEquationi glow_glBlendEquationi
#define glCopyTexSubImage2D glow_glCopyTexSubImage2D
#define glEnable glow_glEnable
#define glProgramUniform4iv glow_glProgramUniform4iv
#define glGetVertexAttribiv glow_glGetVertexAttribiv
#define glUniform1fv glow_glUniform1fv
#define glGetProgramResourceLocation glow_glGetProgramResourceLocation
#define glProgramUniform3ui glow_glProgramUniform3ui
#define glDrawElementsBaseVertex glow_glDrawElementsBaseVertex
#define glBlendEquation glow_glBlendEquation
#define glCreateShader glow_glCreateShader
#define glDetachShader glow_glDetachShader
#define glProgramUniformMatrix4x3fv glow_glProgramUniformMatrix4x3fv
#define glBindRenderbuffer glow_glBindRenderbuffer
#define glVertexAttrib4f glow_glVertexAttrib4f
#define glProgramUniform4uiv glow_glProgramUniform4uiv
#define glMinSampleShading glow_glMinSampleShading
#define glBeginQuery glow_glBeginQuery
#define glBindBufferBase glow_glBindBufferBase
#define glGetStringi glow_glGetStringi
#define glGenTransformFeedbacks glow_glGenTransformFeedbacks
#define glProgramUniformMatrix2x4fv glow_glProgramUniformMatrix2x4fv
#define glBlendFuncSeparatei glow_glBlendFuncSeparatei
#define glGetShaderPrecisionFormat glow_glGetShaderPrecisionFormat
#define glGetUniformLocation glow_glGetUniformLocation
#define glSamplerParameterf glow_glSamplerParameterf
#define glIsTransformFeedback glow_glIsTransformFeedback
#define glInvalidateSubFramebuffer glow_glInvalidateSubFramebuffer
#define glGetTexLevelParameteriv glow_glGetTexLevelParameteriv
#define glTexBufferRange glow_glTexBufferRange
#define glGetUniformfv glow_glGetUniformfv
#define glBindBufferRange glow_glBindBufferRange
#define glGetSamplerParameterfv glow_glGetSamplerParameterfv
#define glBufferData glow_glBufferData
#define glIsFramebuffer glow_glIsFramebuffer
#define glPolygonOffset glow_glPolygonOffset
#define glUniform4i glow_glUniform4i
#define glTexImage3D glow_glTexImage3D
#define glDispatchComputeIndirect glow_glDispatchComputeIndirect
#define glDebugMessageControl glow_glDebugMessageControl
#define glCompressedTexImage2D glow_glCompressedTexImage2D
#define glDeleteProgram glow_glDeleteProgram
#define glStencilFunc glow_glStencilFunc
#define glGetProgramInfoLog glow_glGetProgramInfoLog
#define glDeleteSync glow_glDeleteSync
#define glBlendFunc glow_glBlendFunc
#define glCopyTexImage2D glow_glCopyTexImage2D
#define glDeleteBuffers glow_glDeleteBuffers
#define glGetProgramResourceiv glow_glGetProgramResourceiv
#define glGetProgramPipelineInfoLog glow_glGetProgramPipelineInfoLog
#define glBindBuffer glow_glBindBuffer
#define glGetTexParameterfv glow_glGetTexParameterfv
#define glTexStorage3D glow_glTexStorage3D
#define glDepthFunc glow_glDepthFunc
#define glGetFramebufferAttachmentParameteriv glow_glGetFramebufferAttachmentParameteriv
#define glVertexAttribIFormat glow_glVertexAttribIFormat
#define glUniformMatrix4x3fv glow_glUniformMatrix4x3fv
#define glProgramUniform3f glow_glProgramUniform3f
#define glProgramUniform2uiv glow_glProgramUniform2uiv
#define glPatchParameteri glow_glPatchParameteri
#define glDeleteRenderbuffers glow_glDeleteRenderbuffers
#define glIsRenderbuffer glow_glIsRenderbuffer
#define glVertexAttrib3fv glow_glVertexAttrib3fv
#define glUniform4ui glow_glUniform4ui
#define glGetInteger64v glow_glGetInteger64v
#define glGenProgramPipelines glow_glGenProgramPipelines
#define glTexStorage2DMultisample glow_glTexStorage2DMultisample
#define glBindAttribLocation glow_glBindAttribLocation
#define glEndQuery glow_glEndQuery
#define glGetVertexAttribIuiv glow_glGetVertexAttribIuiv
#define glStencilOpSeparate glow_glStencilOpSeparate
#define glCompressedTexImage3D glow_glCompressedTexImage3D
#define glGetIntegeri_v glow_glGetIntegeri_v
#define glTransformFeedbackVaryings glow_glTransformFeedbackVaryings
#define glUniform1uiv glow_glUniform1uiv
#define glEnableVertexAttribArray glow_glEnableVertexAttribArray
#define glGetVertexAttribfv glow_glGetVertexAttribfv
#define glShaderBinary glow_glShaderBinary
#define glResumeTransformFeedback glow_glResumeTransformFeedback
#define glFramebufferParameteri glow_glFramebufferParameteri
#define glTexParameterIuiv glow_glTexParameterIuiv
#define glGetActiveUniformsiv glow_glGetActiveUniformsiv
#define glGetActiveUniformBlockiv glow_glGetActiveUniformBlockiv
#define glFenceSync glow_glFenceSync
#define glGetIntegerv glow_glGetIntegerv
#define glIsEnabled glow_glIsEnabled
#define glLineWidth glow_glLineWidth
#define glVertexAttrib3f glow_glVertexAttrib3f
#define glGetTexParameterIuiv glow_glGetTexParameterIuiv
#define glFlush glow_glFlush
#define glFramebufferRenderbuffer glow_glFramebufferRenderbuffer
#define glGenBuffers glow_glGenBuffers
#define glGetAttachedShaders glow_glGetAttachedShaders
#define glDrawBuffers glow_glDrawBuffers
#define glUniform4uiv glow_glUniform4uiv
#define glPauseTransformFeedback glow_glPauseTransformFeedback
#define glBindVertexBuffer glow_glBindVertexBuffer
#define glPushDebugGroup glow_glPushDebugGroup
#define glUniform2iv glow_glUniform2iv
#define glUniform4fv glow_glUniform4fv
#define glBindTransformFeedback glow_glBindTransformFeedback
#define glProgramUniform2iv glow_glProgramUniform2iv
#define glGetMultisamplefv glow_glGetMultisamplefv
#define glGetShaderiv glow_glGetShaderiv
#define glUniform4iv glow_glUniform4iv
#define glGetBufferParameteri64v glow_glGetBufferParameteri64v
#define glUniformMatrix2fv glow_glUniformMatrix2fv
#define glUniform3uiv glow_glUniform3uiv
#define glGetProgramResourceName glow_glGetProgramResourceName
#define glProgramUniform4i glow_glProgramUniform4i
#define glProgramUniform1f glow_glProgramUniform1f
#define glCullFace glow_glCullFace
#define glDepthRangef glow_glDepthRangef
#define glSampleCoverage glow_glSampleCoverage
#define glPrimitiveBoundingBox glow_glPrimitiveBoundingBox
#define glBeginTransformFeedback glow_glBeginTransformFeedback
#define glClearBufferfv glow_glClearBufferfv
#define glGetPointerv glow_glGetPointerv
#define glTexSubImage3D glow_glTexSubImage3D
#define glUniform1ui glow_glUniform1ui
#define glActiveTexture glow_glActiveTexture
#define glAttachShader glow_glAttachShader
#define glGetFloatv glow_glGetFloatv
#define glCopyTexSubImage3D glow_glCopyTexSubImage3D
#define glUniformMatrix3x2fv glow_glUniformMatrix3x2fv
#define glBindSampler glow_glBindSampler
#define glVertexAttribBinding glow_glVertexAttribBinding
#define glDeleteFramebuffers glow_glDeleteFramebuffers
#define glGetError glow_glGetError
#define glTexParameterfv glow_glTexParameterfv
#define glDrawArraysInstanced glow_glDrawArraysInstanced
#define glBlendFuncSeparate glow_glBlendFuncSeparate
#define glGenVertexArrays glow_glGenVertexArrays
#define glIsVertexArray glow_glIsVertexArray
#define glWaitSync glow_glWaitSync
#define glProgramUniform4ui glow_glProgramUniform4ui
#define glProgramUniformMatrix2fv glow_glProgramUniformMatrix2fv
#define glGetTexParameteriv glow_glGetTexParameteriv
#define glGetVertexAttribPointerv glow_glGetVertexAttribPointerv
#define glGetTransformFeedbackVarying glow_glGetTransformFeedbackVarying
#define glUniform3ui glow_glUniform3ui
#define glGetSynciv glow_glGetSynciv
#define glProgramUniform4f glow_glProgramUniform4f
#define glProgramUniform3iv glow_glProgramUniform3iv
#define glDebugMessageInsert glow_glDebugMessageInsert
#define glGenerateMipmap glow_glGenerateMipmap
#define glGetUniformiv glow_glGetUniformiv
#define glTexParameteri glow_glTexParameteri
#define glPopDebugGroup glow_glPopDebugGroup
#define glGetObjectPtrLabel glow_glGetObjectPtrLabel
#define glGetString glow_glGetString
#define glStencilFuncSeparate glow_glStencilFuncSeparate
#define glUniform3f glow_glUniform3f
#define glBindFramebuffer glow_glBindFramebuffer
#define glBlendColor glow_glBlendColor
#define glBlendEquationSeparate glow_glBlendEquationSeparate
#define glObjectLabel glow_glObjectLabel
#define glGetObjectLabel glow_glGetObjectLabel
#define glGetGraphicsResetStatus glow_glGetGraphicsResetStatus
#define glClearBufferfi glow_glClearBufferfi
#define glProgramUniform3fv glow_glProgramUniform3fv
#define glSampleMaski glow_glSampleMaski
#define glProgramUniformMatrix3x2fv glow_glProgramUniformMatrix3x2fv
#define glDeleteShader glow_glDeleteShader
#define glGetFragDataLocation glow_glGetFragDataLocation
#define glProgramUniformMatrix3fv glow_glProgramUniformMatrix3fv
#define glGetSamplerParameterIuiv glow_glGetSamplerParameterIuiv
#define glBufferSubData glow_glBufferSubData
#define glClearColor glow_glClearColor
#define glVertexAttrib2fv glow_glVertexAttrib2fv
#define glGetSamplerParameteriv glow_glGetSamplerParameteriv
#define glProgramParameteri glow_glProgramParameteri
#define glDeleteQueries glow_glDeleteQueries
#define glGetActiveUniformBlockName glow_glGetActiveUniformBlockName
#define glClientWaitSync glow_glClientWaitSync
#define glVertexAttribDivisor glow_glVertexAttribDivisor
#define glIsProgramPipeline glow_glIsProgramPipeline
#define glUniformMatrix3fv glow_glUniformMatrix3fv
#define glVertexAttrib2f glow_glVertexAttrib2f
#define glReadBuffer glow_glReadBuffer
#define glMemoryBarrierByRegion glow_glMemoryBarrierByRegion
#define glGetActiveAttrib glow_glGetActiveAttrib
#define glGetBufferParameteriv glow_glGetBufferParameteriv
#define glUniform2uiv glow_glUniform2uiv

#endif /* GLOW_DEBUG */


#ifdef GLOW_DEBUG

GLOWDEF PFNGLDISABLEVERTEXATTRIBARRAYPROC glow_debug_glDisableVertexAttribArray;
#define glDisableVertexAttribArray glow_debug_glDisableVertexAttribArray
GLOWDEF PFNGLDELETESAMPLERSPROC glow_debug_glDeleteSamplers;
#define glDeleteSamplers glow_debug_glDeleteSamplers
GLOWDEF PFNGLVERTEXATTRIBI4UIVPROC glow_debug_glVertexAttribI4uiv;
#define glVertexAttribI4uiv glow_debug_glVertexAttribI4uiv
GLOWDEF PFNGLGETPROGRAMBINARYPROC glow_debug_glGetProgramBinary;
#define glGetProgramBinary glow_debug_glGetProgramBinary
GLOWDEF PFNGLGETDEBUGMESSAGELOGPROC glow_debug_glGetDebugMessageLog;
#define glGetDebugMessageLog glow_debug_glGetDebugMessageLog
GLOWDEF PFNGLDISABLEIPROC glow_debug_glDisablei;
#define glDisablei glow_debug_glDisablei
GLOWDEF PFNGLDRAWELEMENTSPROC glow_debug_glDrawElements;
#define glDrawElements glow_debug_glDrawElements
GLOWDEF PFNGLRELEASESHADERCOMPILERPROC glow_debug_glReleaseShaderCompiler;
#define glReleaseShaderCompiler glow_debug_glReleaseShaderCompiler
GLOWDEF PFNGLUNIFORM3IPROC glow_debug_glUniform3i;
#define glUniform3i glow_debug_glUniform3i
GLOWDEF PFNGLISQUERYPROC glow_debug_glIsQuery;
#define glIsQuery glow_debug_glIsQuery
GLOWDEF PFNGLDELETETRANSFORMFEEDBACKSPROC glow_debug_glDeleteTransformFeedbacks;
#define glDeleteTransformFeedbacks glow_debug_glDeleteTransformFeedbacks
GLOWDEF PFNGLGETATTRIBLOCATIONPROC glow_debug_glGetAttribLocation;
#define glGetAttribLocation glow_debug_glGetAttribLocation
GLOWDEF PFNGLGETSHADERSOURCEPROC glow_debug_glGetShaderSource;
#define glGetShaderSource glow_debug_glGetShaderSource
GLOWDEF PFNGLSHADERSOURCEPROC glow_debug_glShaderSource;
#define glShaderSource glow_debug_glShaderSource
GLOWDEF PFNGLFRAMEBUFFERTEXTURELAYERPROC glow_debug_glFramebufferTextureLayer;
#define glFramebufferTextureLayer glow_debug_glFramebufferTextureLayer
GLOWDEF PFNGLCLEARBUFFERUIVPROC glow_debug_glClearBufferuiv;
#define glClearBufferuiv glow_debug_glClearBufferuiv
GLOWDEF PFNGLSAMPLERPARAMETERFVPROC glow_debug_glSamplerParameterfv;
#define glSamplerParameterfv glow_debug_glSamplerParameterfv
GLOWDEF PFNGLBLENDEQUATIONSEPARATEIPROC glow_debug_glBlendEquationSeparatei;
#define glBlendEquationSeparatei glow_debug_glBlendEquationSeparatei
GLOWDEF PFNGLFRAMEBUFFERTEXTUREPROC glow_debug_glFramebufferTexture;
#define glFramebufferTexture glow_debug_glFramebufferTexture
GLOWDEF PFNGLCOLORMASKPROC glow_debug_glColorMask;
#define glColorMask glow_debug_glColorMask
GLOWDEF PFNGLDISABLEPROC glow_debug_glDisable;
#define glDisable glow_debug_glDisable
GLOWDEF PFNGLGETRENDERBUFFERPARAMETERIVPROC glow_debug_glGetRenderbufferParameteriv;
#define glGetRenderbufferParameteriv glow_debug_glGetRenderbufferParameteriv
GLOWDEF PFNGLGETPROGRAMPIPELINEIVPROC glow_debug_glGetProgramPipelineiv;
#define glGetProgramPipelineiv glow_debug_glGetProgramPipelineiv
GLOWDEF PFNGLCOPYIMAGESUBDATAPROC glow_debug_glCopyImageSubData;
#define glCopyImageSubData glow_debug_glCopyImageSubData
GLOWDEF PFNGLGETTEXPARAMETERIIVPROC glow_debug_glGetTexParameterIiv;
#define glGetTexParameterIiv glow_debug_glGetTexParameterIiv
GLOWDEF PFNGLUNIFORM1FPROC glow_debug_glUniform1f;
#define glUniform1f glow_debug_glUniform1f
GLOWDEF PFNGLUNIFORMMATRIX4X2FVPROC glow_debug_glUniformMatrix4x2fv;
#define glUniformMatrix4x2fv glow_debug_glUniformMatrix4x2fv
GLOWDEF PFNGLUNIFORM2UIPROC glow_debug_glUniform2ui;
#define glUniform2ui glow_debug_glUniform2ui
GLOWDEF PFNGLPROGRAMUNIFORM1FVPROC glow_debug_glProgramUniform1fv;
#define glProgramUniform1fv glow_debug_glProgramUniform1fv
GLOWDEF PFNGLMEMORYBARRIERPROC glow_debug_glMemoryBarrier;
#define glMemoryBarrier glow_debug_glMemoryBarrier
GLOWDEF PFNGLSTENCILMASKPROC glow_debug_glStencilMask;
#define glStencilMask glow_debug_glStencilMask
GLOWDEF PFNGLDRAWELEMENTSINSTANCEDPROC glow_debug_glDrawElementsInstanced;
#define glDrawElementsInstanced glow_debug_glDrawElementsInstanced
GLOWDEF PFNGLPROGRAMUNIFORM1IVPROC glow_debug_glProgramUniform1iv;
#define glProgramUniform1iv glow_debug_glProgramUniform1iv
GLOWDEF PFNGLACTIVESHADERPROGRAMPROC glow_debug_glActiveShaderProgram;
#define glActiveShaderProgram glow_debug_glActiveShaderProgram
GLOWDEF PFNGLBINDIMAGETEXTUREPROC glow_debug_glBindImageTexture;
#define glBindImageTexture glow_debug_glBindImageTexture
GLOWDEF PFNGLTEXPARAMETERIVPROC glow_debug_glTexParameteriv;
#define glTexParameteriv glow_debug_glTexParameteriv
GLOWDEF PFNGLUNIFORM3FVPROC glow_debug_glUniform3fv;
#define glUniform3fv glow_debug_glUniform3fv
GLOWDEF PFNGLVERTEXATTRIB1FVPROC glow_debug_glVertexAttrib1fv;
#define glVertexAttrib1fv glow_debug_glVertexAttrib1fv
GLOWDEF PFNGLGETFRAMEBUFFERPARAMETERIVPROC glow_debug_glGetFramebufferParameteriv;
#define glGetFramebufferParameteriv glow_debug_glGetFramebufferParameteriv
GLOWDEF PFNGLPROGRAMUNIFORM3UIVPROC glow_debug_glProgramUniform3uiv;
#define glProgramUniform3uiv glow_debug_glProgramUniform3uiv
GLOWDEF PFNGLBLENDBARRIERPROC glow_debug_glBlendBarrier;
#define glBlendBarrier glow_debug_glBlendBarrier
GLOWDEF PFNGLTEXSTORAGE3DMULTISAMPLEPROC glow_debug_glTexStorage3DMultisample;
#define glTexStorage3DMultisample glow_debug_glTexStorage3DMultisample
GLOWDEF PFNGLUNIFORM2FVPROC glow_debug_glUniform2fv;
#define glUniform2fv glow_debug_glUniform2fv
GLOWDEF PFNGLUNIFORMMATRIX2X3FVPROC glow_debug_glUniformMatrix2x3fv;
#define glUniformMatrix2x3fv glow_debug_glUniformMatrix2x3fv
GLOWDEF PFNGLISSYNCPROC glow_debug_glIsSync;
#define glIsSync glow_debug_glIsSync
GLOWDEF PFNGLCLEARBUFFERIVPROC glow_debug_glClearBufferiv;
#define glClearBufferiv glow_debug_glClearBufferiv
GLOWDEF PFNGLGETBOOLEANI_VPROC glow_debug_glGetBooleani_v;
#define glGetBooleani_v glow_debug_glGetBooleani_v
GLOWDEF PFNGLGENTEXTURESPROC glow_debug_glGenTextures;
#define glGenTextures glow_debug_glGenTextures
GLOWDEF PFNGLISSHADERPROC glow_debug_glIsShader;
#define glIsShader glow_debug_glIsShader
GLOWDEF PFNGLDRAWRANGEELEMENTSPROC glow_debug_glDrawRangeElements;
#define glDrawRangeElements glow_debug_glDrawRangeElements
GLOWDEF PFNGLISBUFFERPROC glow_debug_glIsBuffer;
#define glIsBuffer glow_debug_glIsBuffer
GLOWDEF PFNGLUSEPROGRAMPROC glow_debug_glUseProgram;
#define glUseProgram glow_debug_glUseProgram
GLOWDEF PFNGLGETUNIFORMBLOCKINDEXPROC glow_debug_glGetUniformBlockIndex;
#define glGetUniformBlockIndex glow_debug_glGetUniformBlockIndex
GLOWDEF PFNGLGETINTERNALFORMATIVPROC glow_debug_glGetInternalformativ;
#define glGetInternalformativ glow_debug_glGetInternalformativ
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glow_debug_glProgramUniformMatrix4x2fv;
#define glProgramUniformMatrix4x2fv glow_debug_glProgramUniformMatrix4x2fv
GLOWDEF PFNGLCLEARPROC glow_debug_glClear;
#define glClear glow_debug_glClear
GLOWDEF PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glow_debug_glCompressedTexSubImage2D;
#define glCompressedTexSubImage2D glow_debug_glCompressedTexSubImage2D
GLOWDEF PFNGLFRAMEBUFFERTEXTURE2DPROC glow_debug_glFramebufferTexture2D;
#define glFramebufferTexture2D glow_debug_glFramebufferTexture2D
GLOWDEF PFNGLVALIDATEPROGRAMPIPELINEPROC glow_debug_glValidateProgramPipeline;
#define glValidateProgramPipeline glow_debug_glValidateProgramPipeline
GLOWDEF PFNGLTEXPARAMETERIIVPROC glow_debug_glTexParameterIiv;
#define glTexParameterIiv glow_debug_glTexParameterIiv
GLOWDEF PFNGLPROGRAMUNIFORM1IPROC glow_debug_glProgramUniform1i;
#define glProgramUniform1i glow_debug_glProgramUniform1i
GLOWDEF PFNGLREADNPIXELSPROC glow_debug_glReadnPixels;
#define glReadnPixels glow_debug_glReadnPixels
GLOWDEF PFNGLGETACTIVEUNIFORMPROC glow_debug_glGetActiveUniform;
#define glGetActiveUniform glow_debug_glGetActiveUniform
GLOWDEF PFNGLVERTEXATTRIBPOINTERPROC glow_debug_glVertexAttribPointer;
#define glVertexAttribPointer glow_debug_glVertexAttribPointer
GLOWDEF PFNGLBINDPROGRAMPIPELINEPROC glow_debug_glBindProgramPipeline;
#define glBindProgramPipeline glow_debug_glBindProgramPipeline
GLOWDEF PFNGLUNIFORM2IPROC glow_debug_glUniform2i;
#define glUniform2i glow_debug_glUniform2i
GLOWDEF PFNGLMAPBUFFERRANGEPROC glow_debug_glMapBufferRange;
#define glMapBufferRange glow_debug_glMapBufferRange
GLOWDEF PFNGLGETVERTEXATTRIBIIVPROC glow_debug_glGetVertexAttribIiv;
#define glGetVertexAttribIiv glow_debug_glGetVertexAttribIiv
GLOWDEF PFNGLTEXSTORAGE2DPROC glow_debug_glTexStorage2D;
#define glTexStorage2D glow_debug_glTexStorage2D
GLOWDEF PFNGLGETNUNIFORMUIVPROC glow_debug_glGetnUniformuiv;
#define glGetnUniformuiv glow_debug_glGetnUniformuiv
GLOWDEF PFNGLCHECKFRAMEBUFFERSTATUSPROC glow_debug_glCheckFramebufferStatus;
#define glCheckFramebufferStatus glow_debug_glCheckFramebufferStatus
GLOWDEF PFNGLCLEARDEPTHFPROC glow_debug_glClearDepthf;
#define glClearDepthf glow_debug_glClearDepthf
GLOWDEF PFNGLGETPROGRAMIVPROC glow_debug_glGetProgramiv;
#define glGetProgramiv glow_debug_glGetProgramiv
GLOWDEF PFNGLSAMPLERPARAMETERIUIVPROC glow_debug_glSamplerParameterIuiv;
#define glSamplerParameterIuiv glow_debug_glSamplerParameterIuiv
GLOWDEF PFNGLVERTEXATTRIB1FPROC glow_debug_glVertexAttrib1f;
#define glVertexAttrib1f glow_debug_glVertexAttrib1f
GLOWDEF PFNGLBINDVERTEXARRAYPROC glow_debug_glBindVertexArray;
#define glBindVertexArray glow_debug_glBindVertexArray
GLOWDEF PFNGLREADPIXELSPROC glow_debug_glReadPixels;
#define glReadPixels glow_debug_glReadPixels
GLOWDEF PFNGLTEXSUBIMAGE2DPROC glow_debug_glTexSubImage2D;
#define glTexSubImage2D glow_debug_glTexSubImage2D
GLOWDEF PFNGLUNIFORMMATRIX4FVPROC glow_debug_glUniformMatrix4fv;
#define glUniformMatrix4fv glow_debug_glUniformMatrix4fv
GLOWDEF PFNGLSTENCILMASKSEPARATEPROC glow_debug_glStencilMaskSeparate;
#define glStencilMaskSeparate glow_debug_glStencilMaskSeparate
GLOWDEF PFNGLGENQUERIESPROC glow_debug_glGenQueries;
#define glGenQueries glow_debug_glGenQueries
GLOWDEF PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glow_debug_glRenderbufferStorageMultisample;
#define glRenderbufferStorageMultisample glow_debug_glRenderbufferStorageMultisample
GLOWDEF PFNGLDRAWELEMENTSINDIRECTPROC glow_debug_glDrawElementsIndirect;
#define glDrawElementsIndirect glow_debug_glDrawElementsIndirect
GLOWDEF PFNGLGETNUNIFORMFVPROC glow_debug_glGetnUniformfv;
#define glGetnUniformfv glow_debug_glGetnUniformfv
GLOWDEF PFNGLDISPATCHCOMPUTEPROC glow_debug_glDispatchCompute;
#define glDispatchCompute glow_debug_glDispatchCompute
GLOWDEF PFNGLPROGRAMUNIFORM1UIPROC glow_debug_glProgramUniform1ui;
#define glProgramUniform1ui glow_debug_glProgramUniform1ui
GLOWDEF PFNGLISENABLEDIPROC glow_debug_glIsEnabledi;
#define glIsEnabledi glow_debug_glIsEnabledi
GLOWDEF PFNGLRENDERBUFFERSTORAGEPROC glow_debug_glRenderbufferStorage;
#define glRenderbufferStorage glow_debug_glRenderbufferStorage
GLOWDEF PFNGLVERTEXATTRIBI4UIPROC glow_debug_glVertexAttribI4ui;
#define glVertexAttribI4ui glow_debug_glVertexAttribI4ui
GLOWDEF PFNGLSAMPLERPARAMETERIPROC glow_debug_glSamplerParameteri;
#define glSamplerParameteri glow_debug_glSamplerParameteri
GLOWDEF PFNGLDEPTHMASKPROC glow_debug_glDepthMask;
#define glDepthMask glow_debug_glDepthMask
GLOWDEF PFNGLISPROGRAMPROC glow_debug_glIsProgram;
#define glIsProgram glow_debug_glIsProgram
GLOWDEF PFNGLPROGRAMUNIFORM2IPROC glow_debug_glProgramUniform2i;
#define glProgramUniform2i glow_debug_glProgramUniform2i
GLOWDEF PFNGLPROGRAMUNIFORM4FVPROC glow_debug_glProgramUniform4fv;
#define glProgramUniform4fv glow_debug_glProgramUniform4fv
GLOWDEF PFNGLSCISSORPROC glow_debug_glScissor;
#define glScissor glow_debug_glScissor
GLOWDEF PFNGLGETPROGRAMRESOURCEINDEXPROC glow_debug_glGetProgramResourceIndex;
#define glGetProgramResourceIndex glow_debug_glGetProgramResourceIndex
GLOWDEF PFNGLPROGRAMUNIFORM3IPROC glow_debug_glProgramUniform3i;
#define glProgramUniform3i glow_debug_glProgramUniform3i
GLOWDEF PFNGLUNIFORMMATRIX2X4FVPROC glow_debug_glUniformMatrix2x4fv;
#define glUniformMatrix2x4fv glow_debug_glUniformMatrix2x4fv
GLOWDEF PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glow_debug_glDrawRangeElementsBaseVertex;
#define glDrawRangeElementsBaseVertex glow_debug_glDrawRangeElementsBaseVertex
GLOWDEF PFNGLUNIFORM4FPROC glow_debug_glUniform4f;
#define glUniform4f glow_debug_glUniform4f
GLOWDEF PFNGLFLUSHMAPPEDBUFFERRANGEPROC glow_debug_glFlushMappedBufferRange;
#define glFlushMappedBufferRange glow_debug_glFlushMappedBufferRange
GLOWDEF PFNGLISSAMPLERPROC glow_debug_glIsSampler;
#define glIsSampler glow_debug_glIsSampler
GLOWDEF PFNGLPROGRAMBINARYPROC glow_debug_glProgramBinary;
#define glProgramBinary glow_debug_glProgramBinary
GLOWDEF PFNGLCREATESHADERPROGRAMVPROC glow_debug_glCreateShaderProgramv;
#define glCreateShaderProgramv glow_debug_glCreateShaderProgramv
GLOWDEF PFNGLBINDTEXTUREPROC glow_debug_glBindTexture;
#define glBindTexture glow_debug_glBindTexture
GLOWDEF PFNGLGENRENDERBUFFERSPROC glow_debug_glGenRenderbuffers;
#define glGenRenderbuffers glow_debug_glGenRenderbuffers
GLOWDEF PFNGLUNIFORM1IVPROC glow_debug_glUniform1iv;
#define glUniform1iv glow_debug_glUniform1iv
GLOWDEF PFNGLCOLORMASKIPROC glow_debug_glColorMaski;
#define glColorMaski glow_debug_glColorMaski
GLOWDEF PFNGLVERTEXATTRIBIPOINTERPROC glow_debug_glVertexAttribIPointer;
#define glVertexAttribIPointer glow_debug_glVertexAttribIPointer
GLOWDEF PFNGLUNIFORMBLOCKBINDINGPROC glow_debug_glUniformBlockBinding;
#define glUniformBlockBinding glow_debug_glUniformBlockBinding
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glow_debug_glProgramUniformMatrix3x4fv;
#define glProgramUniformMatrix3x4fv glow_debug_glProgramUniformMatrix3x4fv
GLOWDEF PFNGLDEBUGMESSAGECALLBACKPROC glow_debug_glDebugMessageCallback;
#define glDebugMessageCallback glow_debug_glDebugMessageCallback
GLOWDEF PFNGLSAMPLERPARAMETERIIVPROC glow_debug_glSamplerParameterIiv;
#define glSamplerParameterIiv glow_debug_glSamplerParameterIiv
GLOWDEF PFNGLCOMPILESHADERPROC glow_debug_glCompileShader;
#define glCompileShader glow_debug_glCompileShader
GLOWDEF PFNGLTEXPARAMETERFPROC glow_debug_glTexParameterf;
#define glTexParameterf glow_debug_glTexParameterf
GLOWDEF PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glow_debug_glCompressedTexSubImage3D;
#define glCompressedTexSubImage3D glow_debug_glCompressedTexSubImage3D
GLOWDEF PFNGLGETTEXLEVELPARAMETERFVPROC glow_debug_glGetTexLevelParameterfv;
#define glGetTexLevelParameterfv glow_debug_glGetTexLevelParameterfv
GLOWDEF PFNGLDRAWARRAYSPROC glow_debug_glDrawArrays;
#define glDrawArrays glow_debug_glDrawArrays
GLOWDEF PFNGLLINKPROGRAMPROC glow_debug_glLinkProgram;
#define glLinkProgram glow_debug_glLinkProgram
GLOWDEF PFNGLPROGRAMUNIFORM2FPROC glow_debug_glProgramUniform2f;
#define glProgramUniform2f glow_debug_glProgramUniform2f
GLOWDEF PFNGLCREATEPROGRAMPROC glow_debug_glCreateProgram;
#define glCreateProgram glow_debug_glCreateProgram
GLOWDEF PFNGLGETPROGRAMINTERFACEIVPROC glow_debug_glGetProgramInterfaceiv;
#define glGetProgramInterfaceiv glow_debug_glGetProgramInterfaceiv
GLOWDEF PFNGLPROGRAMUNIFORM2UIPROC glow_debug_glProgramUniform2ui;
#define glProgramUniform2ui glow_debug_glProgramUniform2ui
GLOWDEF PFNGLPROGRAMUNIFORM1UIVPROC glow_debug_glProgramUniform1uiv;
#define glProgramUniform1uiv glow_debug_glProgramUniform1uiv
GLOWDEF PFNGLUNIFORM1IPROC glow_debug_glUniform1i;
#define glUniform1i glow_debug_glUniform1i
GLOWDEF PFNGLGETBUFFERPOINTERVPROC glow_debug_glGetBufferPointerv;
#define glGetBufferPointerv glow_debug_glGetBufferPointerv
GLOWDEF PFNGLENDTRANSFORMFEEDBACKPROC glow_debug_glEndTransformFeedback;
#define glEndTransformFeedback glow_debug_glEndTransformFeedback
GLOWDEF PFNGLGETSAMPLERPARAMETERIIVPROC glow_debug_glGetSamplerParameterIiv;
#define glGetSamplerParameterIiv glow_debug_glGetSamplerParameterIiv
GLOWDEF PFNGLGENFRAMEBUFFERSPROC glow_debug_glGenFramebuffers;
#define glGenFramebuffers glow_debug_glGenFramebuffers
GLOWDEF PFNGLGENSAMPLERSPROC glow_debug_glGenSamplers;
#define glGenSamplers glow_debug_glGenSamplers
GLOWDEF PFNGLENABLEIPROC glow_debug_glEnablei;
#define glEnablei glow_debug_glEnablei
GLOWDEF PFNGLOBJECTPTRLABELPROC glow_debug_glObjectPtrLabel;
#define glObjectPtrLabel glow_debug_glObjectPtrLabel
GLOWDEF PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glow_debug_glDrawElementsInstancedBaseVertex;
#define glDrawElementsInstancedBaseVertex glow_debug_glDrawElementsInstancedBaseVertex
GLOWDEF PFNGLFRONTFACEPROC glow_debug_glFrontFace;
#define glFrontFace glow_debug_glFrontFace
GLOWDEF PFNGLVERTEXATTRIB4FVPROC glow_debug_glVertexAttrib4fv;
#define glVertexAttrib4fv glow_debug_glVertexAttrib4fv
GLOWDEF PFNGLDELETEPROGRAMPIPELINESPROC glow_debug_glDeleteProgramPipelines;
#define glDeleteProgramPipelines glow_debug_glDeleteProgramPipelines
GLOWDEF PFNGLTEXBUFFERPROC glow_debug_glTexBuffer;
#define glTexBuffer glow_debug_glTexBuffer
GLOWDEF PFNGLSTENCILOPPROC glow_debug_glStencilOp;
#define glStencilOp glow_debug_glStencilOp
GLOWDEF PFNGLUNIFORM2FPROC glow_debug_glUniform2f;
#define glUniform2f glow_debug_glUniform2f
GLOWDEF PFNGLGETUNIFORMUIVPROC glow_debug_glGetUniformuiv;
#define glGetUniformuiv glow_debug_glGetUniformuiv
GLOWDEF PFNGLVIEWPORTPROC glow_debug_glViewport;
#define glViewport glow_debug_glViewport
GLOWDEF PFNGLDELETEVERTEXARRAYSPROC glow_debug_glDeleteVertexArrays;
#define glDeleteVertexArrays glow_debug_glDeleteVertexArrays
GLOWDEF PFNGLVERTEXATTRIBI4IPROC glow_debug_glVertexAttribI4i;
#define glVertexAttribI4i glow_debug_glVertexAttribI4i
GLOWDEF PFNGLGETINTEGER64I_VPROC glow_debug_glGetInteger64i_v;
#define glGetInteger64i_v glow_debug_glGetInteger64i_v
GLOWDEF PFNGLSAMPLERPARAMETERIVPROC glow_debug_glSamplerParameteriv;
#define glSamplerParameteriv glow_debug_glSamplerParameteriv
GLOWDEF PFNGLGETBOOLEANVPROC glow_debug_glGetBooleanv;
#define glGetBooleanv glow_debug_glGetBooleanv
GLOWDEF PFNGLTEXIMAGE2DPROC glow_debug_glTexImage2D;
#define glTexImage2D glow_debug_glTexImage2D
GLOWDEF PFNGLUNIFORM3IVPROC glow_debug_glUniform3iv;
#define glUniform3iv glow_debug_glUniform3iv
GLOWDEF PFNGLPROGRAMUNIFORM2FVPROC glow_debug_glProgramUniform2fv;
#define glProgramUniform2fv glow_debug_glProgramUniform2fv
GLOWDEF PFNGLGETQUERYOBJECTUIVPROC glow_debug_glGetQueryObjectuiv;
#define glGetQueryObjectuiv glow_debug_glGetQueryObjectuiv
GLOWDEF PFNGLVERTEXATTRIBI4IVPROC glow_debug_glVertexAttribI4iv;
#define glVertexAttribI4iv glow_debug_glVertexAttribI4iv
GLOWDEF PFNGLGETUNIFORMINDICESPROC glow_debug_glGetUniformIndices;
#define glGetUniformIndices glow_debug_glGetUniformIndices
GLOWDEF PFNGLDELETETEXTURESPROC glow_debug_glDeleteTextures;
#define glDeleteTextures glow_debug_glDeleteTextures
GLOWDEF PFNGLISTEXTUREPROC glow_debug_glIsTexture;
#define glIsTexture glow_debug_glIsTexture
GLOWDEF PFNGLPIXELSTOREIPROC glow_debug_glPixelStorei;
#define glPixelStorei glow_debug_glPixelStorei
GLOWDEF PFNGLINVALIDATEFRAMEBUFFERPROC glow_debug_glInvalidateFramebuffer;
#define glInvalidateFramebuffer glow_debug_glInvalidateFramebuffer
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glow_debug_glProgramUniformMatrix2x3fv;
#define glProgramUniformMatrix2x3fv glow_debug_glProgramUniformMatrix2x3fv
GLOWDEF PFNGLBLENDFUNCIPROC glow_debug_glBlendFunci;
#define glBlendFunci glow_debug_glBlendFunci
GLOWDEF PFNGLCLEARSTENCILPROC glow_debug_glClearStencil;
#define glClearStencil glow_debug_glClearStencil
GLOWDEF PFNGLVALIDATEPROGRAMPROC glow_debug_glValidateProgram;
#define glValidateProgram glow_debug_glValidateProgram
GLOWDEF PFNGLGETQUERYIVPROC glow_debug_glGetQueryiv;
#define glGetQueryiv glow_debug_glGetQueryiv
GLOWDEF PFNGLBLITFRAMEBUFFERPROC glow_debug_glBlitFramebuffer;
#define glBlitFramebuffer glow_debug_glBlitFramebuffer
GLOWDEF PFNGLCOPYBUFFERSUBDATAPROC glow_debug_glCopyBufferSubData;
#define glCopyBufferSubData glow_debug_glCopyBufferSubData
GLOWDEF PFNGLDRAWARRAYSINDIRECTPROC glow_debug_glDrawArraysIndirect;
#define glDrawArraysIndirect glow_debug_glDrawArraysIndirect
GLOWDEF PFNGLUSEPROGRAMSTAGESPROC glow_debug_glUseProgramStages;
#define glUseProgramStages glow_debug_glUseProgramStages
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX4FVPROC glow_debug_glProgramUniformMatrix4fv;
#define glProgramUniformMatrix4fv glow_debug_glProgramUniformMatrix4fv
GLOWDEF PFNGLFINISHPROC glow_debug_glFinish;
#define glFinish glow_debug_glFinish
GLOWDEF PFNGLGETSHADERINFOLOGPROC glow_debug_glGetShaderInfoLog;
#define glGetShaderInfoLog glow_debug_glGetShaderInfoLog
GLOWDEF PFNGLUNIFORMMATRIX3X4FVPROC glow_debug_glUniformMatrix3x4fv;
#define glUniformMatrix3x4fv glow_debug_glUniformMatrix3x4fv
GLOWDEF PFNGLVERTEXATTRIBFORMATPROC glow_debug_glVertexAttribFormat;
#define glVertexAttribFormat glow_debug_glVertexAttribFormat
GLOWDEF PFNGLGETNUNIFORMIVPROC glow_debug_glGetnUniformiv;
#define glGetnUniformiv glow_debug_glGetnUniformiv
GLOWDEF PFNGLHINTPROC glow_debug_glHint;
#define glHint glow_debug_glHint
GLOWDEF PFNGLUNMAPBUFFERPROC glow_debug_glUnmapBuffer;
#define glUnmapBuffer glow_debug_glUnmapBuffer
GLOWDEF PFNGLVERTEXBINDINGDIVISORPROC glow_debug_glVertexBindingDivisor;
#define glVertexBindingDivisor glow_debug_glVertexBindingDivisor
GLOWDEF PFNGLBLENDEQUATIONIPROC glow_debug_glBlendEquationi;
#define glBlendEquationi glow_debug_glBlendEquationi
GLOWDEF PFNGLCOPYTEXSUBIMAGE2DPROC glow_debug_glCopyTexSubImage2D;
#define glCopyTexSubImage2D glow_debug_glCopyTexSubImage2D
GLOWDEF PFNGLENABLEPROC glow_debug_glEnable;
#define glEnable glow_debug_glEnable
GLOWDEF PFNGLPROGRAMUNIFORM4IVPROC glow_debug_glProgramUniform4iv;
#define glProgramUniform4iv glow_debug_glProgramUniform4iv
GLOWDEF PFNGLGETVERTEXATTRIBIVPROC glow_debug_glGetVertexAttribiv;
#define glGetVertexAttribiv glow_debug_glGetVertexAttribiv
GLOWDEF PFNGLUNIFORM1FVPROC glow_debug_glUniform1fv;
#define glUniform1fv glow_debug_glUniform1fv
GLOWDEF PFNGLGETPROGRAMRESOURCELOCATIONPROC glow_debug_glGetProgramResourceLocation;
#define glGetProgramResourceLocation glow_debug_glGetProgramResourceLocation
GLOWDEF PFNGLPROGRAMUNIFORM3UIPROC glow_debug_glProgramUniform3ui;
#define glProgramUniform3ui glow_debug_glProgramUniform3ui
GLOWDEF PFNGLDRAWELEMENTSBASEVERTEXPROC glow_debug_glDrawElementsBaseVertex;
#define glDrawElementsBaseVertex glow_debug_glDrawElementsBaseVertex
GLOWDEF PFNGLBLENDEQUATIONPROC glow_debug_glBlendEquation;
#define glBlendEquation glow_debug_glBlendEquation
GLOWDEF PFNGLCREATESHADERPROC glow_debug_glCreateShader;
#define glCreateShader glow_debug_glCreateShader
GLOWDEF PFNGLDETACHSHADERPROC glow_debug_glDetachShader;
#define glDetachShader glow_debug_glDetachShader
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glow_debug_glProgramUniformMatrix4x3fv;
#define glProgramUniformMatrix4x3fv glow_debug_glProgramUniformMatrix4x3fv
GLOWDEF PFNGLBINDRENDERBUFFERPROC glow_debug_glBindRenderbuffer;
#define glBindRenderbuffer glow_debug_glBindRenderbuffer
GLOWDEF PFNGLVERTEXATTRIB4FPROC glow_debug_glVertexAttrib4f;
#define glVertexAttrib4f glow_debug_glVertexAttrib4f
GLOWDEF PFNGLPROGRAMUNIFORM4UIVPROC glow_debug_glProgramUniform4uiv;
#define glProgramUniform4uiv glow_debug_glProgramUniform4uiv
GLOWDEF PFNGLMINSAMPLESHADINGPROC glow_debug_glMinSampleShading;
#define glMinSampleShading glow_debug_glMinSampleShading
GLOWDEF PFNGLBEGINQUERYPROC glow_debug_glBeginQuery;
#define glBeginQuery glow_debug_glBeginQuery
GLOWDEF PFNGLBINDBUFFERBASEPROC glow_debug_glBindBufferBase;
#define glBindBufferBase glow_debug_glBindBufferBase
GLOWDEF PFNGLGETSTRINGIPROC glow_debug_glGetStringi;
#define glGetStringi glow_debug_glGetStringi
GLOWDEF PFNGLGENTRANSFORMFEEDBACKSPROC glow_debug_glGenTransformFeedbacks;
#define glGenTransformFeedbacks glow_debug_glGenTransformFeedbacks
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glow_debug_glProgramUniformMatrix2x4fv;
#define glProgramUniformMatrix2x4fv glow_debug_glProgramUniformMatrix2x4fv
GLOWDEF PFNGLBLENDFUNCSEPARATEIPROC glow_debug_glBlendFuncSeparatei;
#define glBlendFuncSeparatei glow_debug_glBlendFuncSeparatei
GLOWDEF PFNGLGETSHADERPRECISIONFORMATPROC glow_debug_glGetShaderPrecisionFormat;
#define glGetShaderPrecisionFormat glow_debug_glGetShaderPrecisionFormat
GLOWDEF PFNGLGETUNIFORMLOCATIONPROC glow_debug_glGetUniformLocation;
#define glGetUniformLocation glow_debug_glGetUniformLocation
GLOWDEF PFNGLSAMPLERPARAMETERFPROC glow_debug_glSamplerParameterf;
#define glSamplerParameterf glow_debug_glSamplerParameterf
GLOWDEF PFNGLISTRANSFORMFEEDBACKPROC glow_debug_glIsTransformFeedback;
#define glIsTransformFeedback glow_debug_glIsTransformFeedback
GLOWDEF PFNGLINVALIDATESUBFRAMEBUFFERPROC glow_debug_glInvalidateSubFramebuffer;
#define glInvalidateSubFramebuffer glow_debug_glInvalidateSubFramebuffer
GLOWDEF PFNGLGETTEXLEVELPARAMETERIVPROC glow_debug_glGetTexLevelParameteriv;
#define glGetTexLevelParameteriv glow_debug_glGetTexLevelParameteriv
GLOWDEF PFNGLTEXBUFFERRANGEPROC glow_debug_glTexBufferRange;
#define glTexBufferRange glow_debug_glTexBufferRange
GLOWDEF PFNGLGETUNIFORMFVPROC glow_debug_glGetUniformfv;
#define glGetUniformfv glow_debug_glGetUniformfv
GLOWDEF PFNGLBINDBUFFERRANGEPROC glow_debug_glBindBufferRange;
#define glBindBufferRange glow_debug_glBindBufferRange
GLOWDEF PFNGLGETSAMPLERPARAMETERFVPROC glow_debug_glGetSamplerParameterfv;
#define glGetSamplerParameterfv glow_debug_glGetSamplerParameterfv
GLOWDEF PFNGLBUFFERDATAPROC glow_debug_glBufferData;
#define glBufferData glow_debug_glBufferData
GLOWDEF PFNGLISFRAMEBUFFERPROC glow_debug_glIsFramebuffer;
#define glIsFramebuffer glow_debug_glIsFramebuffer
GLOWDEF PFNGLPOLYGONOFFSETPROC glow_debug_glPolygonOffset;
#define glPolygonOffset glow_debug_glPolygonOffset
GLOWDEF PFNGLUNIFORM4IPROC glow_debug_glUniform4i;
#define glUniform4i glow_debug_glUniform4i
GLOWDEF PFNGLTEXIMAGE3DPROC glow_debug_glTexImage3D;
#define glTexImage3D glow_debug_glTexImage3D
GLOWDEF PFNGLDISPATCHCOMPUTEINDIRECTPROC glow_debug_glDispatchComputeIndirect;
#define glDispatchComputeIndirect glow_debug_glDispatchComputeIndirect
GLOWDEF PFNGLDEBUGMESSAGECONTROLPROC glow_debug_glDebugMessageControl;
#define glDebugMessageControl glow_debug_glDebugMessageControl
GLOWDEF PFNGLCOMPRESSEDTEXIMAGE2DPROC glow_debug_glCompressedTexImage2D;
#define glCompressedTexImage2D glow_debug_glCompressedTexImage2D
GLOWDEF PFNGLDELETEPROGRAMPROC glow_debug_glDeleteProgram;
#define glDeleteProgram glow_debug_glDeleteProgram
GLOWDEF PFNGLSTENCILFUNCPROC glow_debug_glStencilFunc;
#define glStencilFunc glow_debug_glStencilFunc
GLOWDEF PFNGLGETPROGRAMINFOLOGPROC glow_debug_glGetProgramInfoLog;
#define glGetProgramInfoLog glow_debug_glGetProgramInfoLog
GLOWDEF PFNGLDELETESYNCPROC glow_debug_glDeleteSync;
#define glDeleteSync glow_debug_glDeleteSync
GLOWDEF PFNGLBLENDFUNCPROC glow_debug_glBlendFunc;
#define glBlendFunc glow_debug_glBlendFunc
GLOWDEF PFNGLCOPYTEXIMAGE2DPROC glow_debug_glCopyTexImage2D;
#define glCopyTexImage2D glow_debug_glCopyTexImage2D
GLOWDEF PFNGLDELETEBUFFERSPROC glow_debug_glDeleteBuffers;
#define glDeleteBuffers glow_debug_glDeleteBuffers
GLOWDEF PFNGLGETPROGRAMRESOURCEIVPROC glow_debug_glGetProgramResourceiv;
#define glGetProgramResourceiv glow_debug_glGetProgramResourceiv
GLOWDEF PFNGLGETPROGRAMPIPELINEINFOLOGPROC glow_debug_glGetProgramPipelineInfoLog;
#define glGetProgramPipelineInfoLog glow_debug_glGetProgramPipelineInfoLog
GLOWDEF PFNGLBINDBUFFERPROC glow_debug_glBindBuffer;
#define glBindBuffer glow_debug_glBindBuffer
GLOWDEF PFNGLGETTEXPARAMETERFVPROC glow_debug_glGetTexParameterfv;
#define glGetTexParameterfv glow_debug_glGetTexParameterfv
GLOWDEF PFNGLTEXSTORAGE3DPROC glow_debug_glTexStorage3D;
#define glTexStorage3D glow_debug_glTexStorage3D
GLOWDEF PFNGLDEPTHFUNCPROC glow_debug_glDepthFunc;
#define glDepthFunc glow_debug_glDepthFunc
GLOWDEF PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glow_debug_glGetFramebufferAttachmentParameteriv;
#define glGetFramebufferAttachmentParameteriv glow_debug_glGetFramebufferAttachmentParameteriv
GLOWDEF PFNGLVERTEXATTRIBIFORMATPROC glow_debug_glVertexAttribIFormat;
#define glVertexAttribIFormat glow_debug_glVertexAttribIFormat
GLOWDEF PFNGLUNIFORMMATRIX4X3FVPROC glow_debug_glUniformMatrix4x3fv;
#define glUniformMatrix4x3fv glow_debug_glUniformMatrix4x3fv
GLOWDEF PFNGLPROGRAMUNIFORM3FPROC glow_debug_glProgramUniform3f;
#define glProgramUniform3f glow_debug_glProgramUniform3f
GLOWDEF PFNGLPROGRAMUNIFORM2UIVPROC glow_debug_glProgramUniform2uiv;
#define glProgramUniform2uiv glow_debug_glProgramUniform2uiv
GLOWDEF PFNGLPATCHPARAMETERIPROC glow_debug_glPatchParameteri;
#define glPatchParameteri glow_debug_glPatchParameteri
GLOWDEF PFNGLDELETERENDERBUFFERSPROC glow_debug_glDeleteRenderbuffers;
#define glDeleteRenderbuffers glow_debug_glDeleteRenderbuffers
GLOWDEF PFNGLISRENDERBUFFERPROC glow_debug_glIsRenderbuffer;
#define glIsRenderbuffer glow_debug_glIsRenderbuffer
GLOWDEF PFNGLVERTEXATTRIB3FVPROC glow_debug_glVertexAttrib3fv;
#define glVertexAttrib3fv glow_debug_glVertexAttrib3fv
GLOWDEF PFNGLUNIFORM4UIPROC glow_debug_glUniform4ui;
#define glUniform4ui glow_debug_glUniform4ui
GLOWDEF PFNGLGETINTEGER64VPROC glow_debug_glGetInteger64v;
#define glGetInteger64v glow_debug_glGetInteger64v
GLOWDEF PFNGLGENPROGRAMPIPELINESPROC glow_debug_glGenProgramPipelines;
#define glGenProgramPipelines glow_debug_glGenProgramPipelines
GLOWDEF PFNGLTEXSTORAGE2DMULTISAMPLEPROC glow_debug_glTexStorage2DMultisample;
#define glTexStorage2DMultisample glow_debug_glTexStorage2DMultisample
GLOWDEF PFNGLBINDATTRIBLOCATIONPROC glow_debug_glBindAttribLocation;
#define glBindAttribLocation glow_debug_glBindAttribLocation
GLOWDEF PFNGLENDQUERYPROC glow_debug_glEndQuery;
#define glEndQuery glow_debug_glEndQuery
GLOWDEF PFNGLGETVERTEXATTRIBIUIVPROC glow_debug_glGetVertexAttribIuiv;
#define glGetVertexAttribIuiv glow_debug_glGetVertexAttribIuiv
GLOWDEF PFNGLSTENCILOPSEPARATEPROC glow_debug_glStencilOpSeparate;
#define glStencilOpSeparate glow_debug_glStencilOpSeparate
GLOWDEF PFNGLCOMPRESSEDTEXIMAGE3DPROC glow_debug_glCompressedTexImage3D;
#define glCompressedTexImage3D glow_debug_glCompressedTexImage3D
GLOWDEF PFNGLGETINTEGERI_VPROC glow_debug_glGetIntegeri_v;
#define glGetIntegeri_v glow_debug_glGetIntegeri_v
GLOWDEF PFNGLTRANSFORMFEEDBACKVARYINGSPROC glow_debug_glTransformFeedbackVaryings;
#define glTransformFeedbackVaryings glow_debug_glTransformFeedbackVaryings
GLOWDEF PFNGLUNIFORM1UIVPROC glow_debug_glUniform1uiv;
#define glUniform1uiv glow_debug_glUniform1uiv
GLOWDEF PFNGLENABLEVERTEXATTRIBARRAYPROC glow_debug_glEnableVertexAttribArray;
#define glEnableVertexAttribArray glow_debug_glEnableVertexAttribArray
GLOWDEF PFNGLGETVERTEXATTRIBFVPROC glow_debug_glGetVertexAttribfv;
#define glGetVertexAttribfv glow_debug_glGetVertexAttribfv
GLOWDEF PFNGLSHADERBINARYPROC glow_debug_glShaderBinary;
#define glShaderBinary glow_debug_glShaderBinary
GLOWDEF PFNGLRESUMETRANSFORMFEEDBACKPROC glow_debug_glResumeTransformFeedback;
#define glResumeTransformFeedback glow_debug_glResumeTransformFeedback
GLOWDEF PFNGLFRAMEBUFFERPARAMETERIPROC glow_debug_glFramebufferParameteri;
#define glFramebufferParameteri glow_debug_glFramebufferParameteri
GLOWDEF PFNGLTEXPARAMETERIUIVPROC glow_debug_glTexParameterIuiv;
#define glTexParameterIuiv glow_debug_glTexParameterIuiv
GLOWDEF PFNGLGETACTIVEUNIFORMSIVPROC glow_debug_glGetActiveUniformsiv;
#define glGetActiveUniformsiv glow_debug_glGetActiveUniformsiv
GLOWDEF PFNGLGETACTIVEUNIFORMBLOCKIVPROC glow_debug_glGetActiveUniformBlockiv;
#define glGetActiveUniformBlockiv glow_debug_glGetActiveUniformBlockiv
GLOWDEF PFNGLFENCESYNCPROC glow_debug_glFenceSync;
#define glFenceSync glow_debug_glFenceSync
GLOWDEF PFNGLGETINTEGERVPROC glow_debug_glGetIntegerv;
#define glGetIntegerv glow_debug_glGetIntegerv
GLOWDEF PFNGLISENABLEDPROC glow_debug_glIsEnabled;
#define glIsEnabled glow_debug_glIsEnabled
GLOWDEF PFNGLLINEWIDTHPROC glow_debug_glLineWidth;
#define glLineWidth glow_debug_glLineWidth
GLOWDEF PFNGLVERTEXATTRIB3FPROC glow_debug_glVertexAttrib3f;
#define glVertexAttrib3f glow_debug_glVertexAttrib3f
GLOWDEF PFNGLGETTEXPARAMETERIUIVPROC glow_debug_glGetTexParameterIuiv;
#define glGetTexParameterIuiv glow_debug_glGetTexParameterIuiv
GLOWDEF PFNGLFLUSHPROC glow_debug_glFlush;
#define glFlush glow_debug_glFlush
GLOWDEF PFNGLFRAMEBUFFERRENDERBUFFERPROC glow_debug_glFramebufferRenderbuffer;
#define glFramebufferRenderbuffer glow_debug_glFramebufferRenderbuffer
GLOWDEF PFNGLGENBUFFERSPROC glow_debug_glGenBuffers;
#define glGenBuffers glow_debug_glGenBuffers
GLOWDEF PFNGLGETATTACHEDSHADERSPROC glow_debug_glGetAttachedShaders;
#define glGetAttachedShaders glow_debug_glGetAttachedShaders
GLOWDEF PFNGLDRAWBUFFERSPROC glow_debug_glDrawBuffers;
#define glDrawBuffers glow_debug_glDrawBuffers
GLOWDEF PFNGLUNIFORM4UIVPROC glow_debug_glUniform4uiv;
#define glUniform4uiv glow_debug_glUniform4uiv
GLOWDEF PFNGLPAUSETRANSFORMFEEDBACKPROC glow_debug_glPauseTransformFeedback;
#define glPauseTransformFeedback glow_debug_glPauseTransformFeedback
GLOWDEF PFNGLBINDVERTEXBUFFERPROC glow_debug_glBindVertexBuffer;
#define glBindVertexBuffer glow_debug_glBindVertexBuffer
GLOWDEF PFNGLPUSHDEBUGGROUPPROC glow_debug_glPushDebugGroup;
#define glPushDebugGroup glow_debug_glPushDebugGroup
GLOWDEF PFNGLUNIFORM2IVPROC glow_debug_glUniform2iv;
#define glUniform2iv glow_debug_glUniform2iv
GLOWDEF PFNGLUNIFORM4FVPROC glow_debug_glUniform4fv;
#define glUniform4fv glow_debug_glUniform4fv
GLOWDEF PFNGLBINDTRANSFORMFEEDBACKPROC glow_debug_glBindTransformFeedback;
#define glBindTransformFeedback glow_debug_glBindTransformFeedback
GLOWDEF PFNGLPROGRAMUNIFORM2IVPROC glow_debug_glProgramUniform2iv;
#define glProgramUniform2iv glow_debug_glProgramUniform2iv
GLOWDEF PFNGLGETMULTISAMPLEFVPROC glow_debug_glGetMultisamplefv;
#define glGetMultisamplefv glow_debug_glGetMultisamplefv
GLOWDEF PFNGLGETSHADERIVPROC glow_debug_glGetShaderiv;
#define glGetShaderiv glow_debug_glGetShaderiv
GLOWDEF PFNGLUNIFORM4IVPROC glow_debug_glUniform4iv;
#define glUniform4iv glow_debug_glUniform4iv
GLOWDEF PFNGLGETBUFFERPARAMETERI64VPROC glow_debug_glGetBufferParameteri64v;
#define glGetBufferParameteri64v glow_debug_glGetBufferParameteri64v
GLOWDEF PFNGLUNIFORMMATRIX2FVPROC glow_debug_glUniformMatrix2fv;
#define glUniformMatrix2fv glow_debug_glUniformMatrix2fv
GLOWDEF PFNGLUNIFORM3UIVPROC glow_debug_glUniform3uiv;
#define glUniform3uiv glow_debug_glUniform3uiv
GLOWDEF PFNGLGETPROGRAMRESOURCENAMEPROC glow_debug_glGetProgramResourceName;
#define glGetProgramResourceName glow_debug_glGetProgramResourceName
GLOWDEF PFNGLPROGRAMUNIFORM4IPROC glow_debug_glProgramUniform4i;
#define glProgramUniform4i glow_debug_glProgramUniform4i
GLOWDEF PFNGLPROGRAMUNIFORM1FPROC glow_debug_glProgramUniform1f;
#define glProgramUniform1f glow_debug_glProgramUniform1f
GLOWDEF PFNGLCULLFACEPROC glow_debug_glCullFace;
#define glCullFace glow_debug_glCullFace
GLOWDEF PFNGLDEPTHRANGEFPROC glow_debug_glDepthRangef;
#define glDepthRangef glow_debug_glDepthRangef
GLOWDEF PFNGLSAMPLECOVERAGEPROC glow_debug_glSampleCoverage;
#define glSampleCoverage glow_debug_glSampleCoverage
GLOWDEF PFNGLPRIMITIVEBOUNDINGBOXPROC glow_debug_glPrimitiveBoundingBox;
#define glPrimitiveBoundingBox glow_debug_glPrimitiveBoundingBox
GLOWDEF PFNGLBEGINTRANSFORMFEEDBACKPROC glow_debug_glBeginTransformFeedback;
#define glBeginTransformFeedback glow_debug_glBeginTransformFeedback
GLOWDEF PFNGLCLEARBUFFERFVPROC glow_debug_glClearBufferfv;
#define glClearBufferfv glow_debug_glClearBufferfv
GLOWDEF PFNGLGETPOINTERVPROC glow_debug_glGetPointerv;
#define glGetPointerv glow_debug_glGetPointerv
GLOWDEF PFNGLTEXSUBIMAGE3DPROC glow_debug_glTexSubImage3D;
#define glTexSubImage3D glow_debug_glTexSubImage3D
GLOWDEF PFNGLUNIFORM1UIPROC glow_debug_glUniform1ui;
#define glUniform1ui glow_debug_glUniform1ui
GLOWDEF PFNGLACTIVETEXTUREPROC glow_debug_glActiveTexture;
#define glActiveTexture glow_debug_glActiveTexture
GLOWDEF PFNGLATTACHSHADERPROC glow_debug_glAttachShader;
#define glAttachShader glow_debug_glAttachShader
GLOWDEF PFNGLGETFLOATVPROC glow_debug_glGetFloatv;
#define glGetFloatv glow_debug_glGetFloatv
GLOWDEF PFNGLCOPYTEXSUBIMAGE3DPROC glow_debug_glCopyTexSubImage3D;
#define glCopyTexSubImage3D glow_debug_glCopyTexSubImage3D
GLOWDEF PFNGLUNIFORMMATRIX3X2FVPROC glow_debug_glUniformMatrix3x2fv;
#define glUniformMatrix3x2fv glow_debug_glUniformMatrix3x2fv
GLOWDEF PFNGLBINDSAMPLERPROC glow_debug_glBindSampler;
#define glBindSampler glow_debug_glBindSampler
GLOWDEF PFNGLVERTEXATTRIBBINDINGPROC glow_debug_glVertexAttribBinding;
#define glVertexAttribBinding glow_debug_glVertexAttribBinding
GLOWDEF PFNGLDELETEFRAMEBUFFERSPROC glow_debug_glDeleteFramebuffers;
#define glDeleteFramebuffers glow_debug_glDeleteFramebuffers
GLOWDEF PFNGLGETERRORPROC glow_debug_glGetError;
#define glGetError glow_debug_glGetError
GLOWDEF PFNGLTEXPARAMETERFVPROC glow_debug_glTexParameterfv;
#define glTexParameterfv glow_debug_glTexParameterfv
GLOWDEF PFNGLDRAWARRAYSINSTANCEDPROC glow_debug_glDrawArraysInstanced;
#define glDrawArraysInstanced glow_debug_glDrawArraysInstanced
GLOWDEF PFNGLBLENDFUNCSEPARATEPROC glow_debug_glBlendFuncSeparate;
#define glBlendFuncSeparate glow_debug_glBlendFuncSeparate
GLOWDEF PFNGLGENVERTEXARRAYSPROC glow_debug_glGenVertexArrays;
#define glGenVertexArrays glow_debug_glGenVertexArrays
GLOWDEF PFNGLISVERTEXARRAYPROC glow_debug_glIsVertexArray;
#define glIsVertexArray glow_debug_glIsVertexArray
GLOWDEF PFNGLWAITSYNCPROC glow_debug_glWaitSync;
#define glWaitSync glow_debug_glWaitSync
GLOWDEF PFNGLPROGRAMUNIFORM4UIPROC glow_debug_glProgramUniform4ui;
#define glProgramUniform4ui glow_debug_glProgramUniform4ui
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX2FVPROC glow_debug_glProgramUniformMatrix2fv;
#define glProgramUniformMatrix2fv glow_debug_glProgramUniformMatrix2fv
GLOWDEF PFNGLGETTEXPARAMETERIVPROC glow_debug_glGetTexParameteriv;
#define glGetTexParameteriv glow_debug_glGetTexParameteriv
GLOWDEF PFNGLGETVERTEXATTRIBPOINTERVPROC glow_debug_glGetVertexAttribPointerv;
#define glGetVertexAttribPointerv glow_debug_glGetVertexAttribPointerv
GLOWDEF PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glow_debug_glGetTransformFeedbackVarying;
#define glGetTransformFeedbackVarying glow_debug_glGetTransformFeedbackVarying
GLOWDEF PFNGLUNIFORM3UIPROC glow_debug_glUniform3ui;
#define glUniform3ui glow_debug_glUniform3ui
GLOWDEF PFNGLGETSYNCIVPROC glow_debug_glGetSynciv;
#define glGetSynciv glow_debug_glGetSynciv
GLOWDEF PFNGLPROGRAMUNIFORM4FPROC glow_debug_glProgramUniform4f;
#define glProgramUniform4f glow_debug_glProgramUniform4f
GLOWDEF PFNGLPROGRAMUNIFORM3IVPROC glow_debug_glProgramUniform3iv;
#define glProgramUniform3iv glow_debug_glProgramUniform3iv
GLOWDEF PFNGLDEBUGMESSAGEINSERTPROC glow_debug_glDebugMessageInsert;
#define glDebugMessageInsert glow_debug_glDebugMessageInsert
GLOWDEF PFNGLGENERATEMIPMAPPROC glow_debug_glGenerateMipmap;
#define glGenerateMipmap glow_debug_glGenerateMipmap
GLOWDEF PFNGLGETUNIFORMIVPROC glow_debug_glGetUniformiv;
#define glGetUniformiv glow_debug_glGetUniformiv
GLOWDEF PFNGLTEXPARAMETERIPROC glow_debug_glTexParameteri;
#define glTexParameteri glow_debug_glTexParameteri
GLOWDEF PFNGLPOPDEBUGGROUPPROC glow_debug_glPopDebugGroup;
#define glPopDebugGroup glow_debug_glPopDebugGroup
GLOWDEF PFNGLGETOBJECTPTRLABELPROC glow_debug_glGetObjectPtrLabel;
#define glGetObjectPtrLabel glow_debug_glGetObjectPtrLabel
GLOWDEF PFNGLGETSTRINGPROC glow_debug_glGetString;
#define glGetString glow_debug_glGetString
GLOWDEF PFNGLSTENCILFUNCSEPARATEPROC glow_debug_glStencilFuncSeparate;
#define glStencilFuncSeparate glow_debug_glStencilFuncSeparate
GLOWDEF PFNGLUNIFORM3FPROC glow_debug_glUniform3f;
#define glUniform3f glow_debug_glUniform3f
GLOWDEF PFNGLBINDFRAMEBUFFERPROC glow_debug_glBindFramebuffer;
#define glBindFramebuffer glow_debug_glBindFramebuffer
GLOWDEF PFNGLBLENDCOLORPROC glow_debug_glBlendColor;
#define glBlendColor glow_debug_glBlendColor
GLOWDEF PFNGLBLENDEQUATIONSEPARATEPROC glow_debug_glBlendEquationSeparate;
#define glBlendEquationSeparate glow_debug_glBlendEquationSeparate
GLOWDEF PFNGLOBJECTLABELPROC glow_debug_glObjectLabel;
#define glObjectLabel glow_debug_glObjectLabel
GLOWDEF PFNGLGETOBJECTLABELPROC glow_debug_glGetObjectLabel;
#define glGetObjectLabel glow_debug_glGetObjectLabel
GLOWDEF PFNGLGETGRAPHICSRESETSTATUSPROC glow_debug_glGetGraphicsResetStatus;
#define glGetGraphicsResetStatus glow_debug_glGetGraphicsResetStatus
GLOWDEF PFNGLCLEARBUFFERFIPROC glow_debug_glClearBufferfi;
#define glClearBufferfi glow_debug_glClearBufferfi
GLOWDEF PFNGLPROGRAMUNIFORM3FVPROC glow_debug_glProgramUniform3fv;
#define glProgramUniform3fv glow_debug_glProgramUniform3fv
GLOWDEF PFNGLSAMPLEMASKIPROC glow_debug_glSampleMaski;
#define glSampleMaski glow_debug_glSampleMaski
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glow_debug_glProgramUniformMatrix3x2fv;
#define glProgramUniformMatrix3x2fv glow_debug_glProgramUniformMatrix3x2fv
GLOWDEF PFNGLDELETESHADERPROC glow_debug_glDeleteShader;
#define glDeleteShader glow_debug_glDeleteShader
GLOWDEF PFNGLGETFRAGDATALOCATIONPROC glow_debug_glGetFragDataLocation;
#define glGetFragDataLocation glow_debug_glGetFragDataLocation
GLOWDEF PFNGLPROGRAMUNIFORMMATRIX3FVPROC glow_debug_glProgramUniformMatrix3fv;
#define glProgramUniformMatrix3fv glow_debug_glProgramUniformMatrix3fv
GLOWDEF PFNGLGETSAMPLERPARAMETERIUIVPROC glow_debug_glGetSamplerParameterIuiv;
#define glGetSamplerParameterIuiv glow_debug_glGetSamplerParameterIuiv
GLOWDEF PFNGLBUFFERSUBDATAPROC glow_debug_glBufferSubData;
#define glBufferSubData glow_debug_glBufferSubData
GLOWDEF PFNGLCLEARCOLORPROC glow_debug_glClearColor;
#define glClearColor glow_debug_glClearColor
GLOWDEF PFNGLVERTEXATTRIB2FVPROC glow_debug_glVertexAttrib2fv;
#define glVertexAttrib2fv glow_debug_glVertexAttrib2fv
GLOWDEF PFNGLGETSAMPLERPARAMETERIVPROC glow_debug_glGetSamplerParameteriv;
#define glGetSamplerParameteriv glow_debug_glGetSamplerParameteriv
GLOWDEF PFNGLPROGRAMPARAMETERIPROC glow_debug_glProgramParameteri;
#define glProgramParameteri glow_debug_glProgramParameteri
GLOWDEF PFNGLDELETEQUERIESPROC glow_debug_glDeleteQueries;
#define glDeleteQueries glow_debug_glDeleteQueries
GLOWDEF PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glow_debug_glGetActiveUniformBlockName;
#define glGetActiveUniformBlockName glow_debug_glGetActiveUniformBlockName
GLOWDEF PFNGLCLIENTWAITSYNCPROC glow_debug_glClientWaitSync;
#define glClientWaitSync glow_debug_glClientWaitSync
GLOWDEF PFNGLVERTEXATTRIBDIVISORPROC glow_debug_glVertexAttribDivisor;
#define glVertexAttribDivisor glow_debug_glVertexAttribDivisor
GLOWDEF PFNGLISPROGRAMPIPELINEPROC glow_debug_glIsProgramPipeline;
#define glIsProgramPipeline glow_debug_glIsProgramPipeline
GLOWDEF PFNGLUNIFORMMATRIX3FVPROC glow_debug_glUniformMatrix3fv;
#define glUniformMatrix3fv glow_debug_glUniformMatrix3fv
GLOWDEF PFNGLVERTEXATTRIB2FPROC glow_debug_glVertexAttrib2f;
#define glVertexAttrib2f glow_debug_glVertexAttrib2f
GLOWDEF PFNGLREADBUFFERPROC glow_debug_glReadBuffer;
#define glReadBuffer glow_debug_glReadBuffer
GLOWDEF PFNGLMEMORYBARRIERBYREGIONPROC glow_debug_glMemoryBarrierByRegion;
#define glMemoryBarrierByRegion glow_debug_glMemoryBarrierByRegion
GLOWDEF PFNGLGETACTIVEATTRIBPROC glow_debug_glGetActiveAttrib;
#define glGetActiveAttrib glow_debug_glGetActiveAttrib
GLOWDEF PFNGLGETBUFFERPARAMETERIVPROC glow_debug_glGetBufferParameteriv;
#define glGetBufferParameteriv glow_debug_glGetBufferParameteriv
GLOWDEF PFNGLUNIFORM2UIVPROC glow_debug_glUniform2uiv;
#define glUniform2uiv glow_debug_glUniform2uiv
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
static void glow_lazy_glDeleteSamplers(GLsizei count, const GLuint *samplers) {
  glow_glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)((ptrdiff_t)(glow_get_proc("glDeleteSamplers")));
  if (glow_glDeleteSamplers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteSamplers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteSamplers\n");
#endif
  }
  glow_glDeleteSamplers(count, samplers);
}
PFNGLDELETESAMPLERSPROC glow_glDeleteSamplers = glow_lazy_glDeleteSamplers;
static void glow_lazy_glVertexAttribI4uiv(GLuint index, const GLuint *v) {
  glow_glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)((ptrdiff_t)(glow_get_proc("glVertexAttribI4uiv")));
  if (glow_glVertexAttribI4uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribI4uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribI4uiv\n");
#endif
  }
  glow_glVertexAttribI4uiv(index, v);
}
PFNGLVERTEXATTRIBI4UIVPROC glow_glVertexAttribI4uiv = glow_lazy_glVertexAttribI4uiv;
static void glow_lazy_glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) {
  glow_glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)((ptrdiff_t)(glow_get_proc("glGetProgramBinary")));
  if (glow_glGetProgramBinary == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramBinary\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramBinary\n");
#endif
  }
  glow_glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
}
PFNGLGETPROGRAMBINARYPROC glow_glGetProgramBinary = glow_lazy_glGetProgramBinary;
static GLuint glow_lazy_glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) {
  glow_glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)((ptrdiff_t)(glow_get_proc("glGetDebugMessageLog")));
  if (glow_glGetDebugMessageLog == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetDebugMessageLog\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetDebugMessageLog\n");
#endif
  }
  return glow_glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}
PFNGLGETDEBUGMESSAGELOGPROC glow_glGetDebugMessageLog = glow_lazy_glGetDebugMessageLog;
static void glow_lazy_glDisablei(GLenum target, GLuint index) {
  glow_glDisablei = (PFNGLDISABLEIPROC)((ptrdiff_t)(glow_get_proc("glDisablei")));
  if (glow_glDisablei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisablei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisablei\n");
#endif
  }
  glow_glDisablei(target, index);
}
PFNGLDISABLEIPROC glow_glDisablei = glow_lazy_glDisablei;
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
static GLboolean glow_lazy_glIsQuery(GLuint id) {
  glow_glIsQuery = (PFNGLISQUERYPROC)((ptrdiff_t)(glow_get_proc("glIsQuery")));
  if (glow_glIsQuery == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsQuery\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsQuery\n");
#endif
  }
  return glow_glIsQuery(id);
}
PFNGLISQUERYPROC glow_glIsQuery = glow_lazy_glIsQuery;
static void glow_lazy_glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids) {
  glow_glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)((ptrdiff_t)(glow_get_proc("glDeleteTransformFeedbacks")));
  if (glow_glDeleteTransformFeedbacks == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteTransformFeedbacks\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteTransformFeedbacks\n");
#endif
  }
  glow_glDeleteTransformFeedbacks(n, ids);
}
PFNGLDELETETRANSFORMFEEDBACKSPROC glow_glDeleteTransformFeedbacks = glow_lazy_glDeleteTransformFeedbacks;
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
static void glow_lazy_glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
  glow_glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)((ptrdiff_t)(glow_get_proc("glFramebufferTextureLayer")));
  if (glow_glFramebufferTextureLayer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferTextureLayer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferTextureLayer\n");
#endif
  }
  glow_glFramebufferTextureLayer(target, attachment, texture, level, layer);
}
PFNGLFRAMEBUFFERTEXTURELAYERPROC glow_glFramebufferTextureLayer = glow_lazy_glFramebufferTextureLayer;
static void glow_lazy_glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) {
  glow_glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)((ptrdiff_t)(glow_get_proc("glClearBufferuiv")));
  if (glow_glClearBufferuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearBufferuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearBufferuiv\n");
#endif
  }
  glow_glClearBufferuiv(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERUIVPROC glow_glClearBufferuiv = glow_lazy_glClearBufferuiv;
static void glow_lazy_glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param) {
  glow_glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)((ptrdiff_t)(glow_get_proc("glSamplerParameterfv")));
  if (glow_glSamplerParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameterfv\n");
#endif
  }
  glow_glSamplerParameterfv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERFVPROC glow_glSamplerParameterfv = glow_lazy_glSamplerParameterfv;
static void glow_lazy_glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
  glow_glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)((ptrdiff_t)(glow_get_proc("glBlendEquationSeparatei")));
  if (glow_glBlendEquationSeparatei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendEquationSeparatei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendEquationSeparatei\n");
#endif
  }
  glow_glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
}
PFNGLBLENDEQUATIONSEPARATEIPROC glow_glBlendEquationSeparatei = glow_lazy_glBlendEquationSeparatei;
static void glow_lazy_glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) {
  glow_glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)((ptrdiff_t)(glow_get_proc("glFramebufferTexture")));
  if (glow_glFramebufferTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferTexture\n");
#endif
  }
  glow_glFramebufferTexture(target, attachment, texture, level);
}
PFNGLFRAMEBUFFERTEXTUREPROC glow_glFramebufferTexture = glow_lazy_glFramebufferTexture;
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
static void glow_lazy_glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) {
  glow_glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)((ptrdiff_t)(glow_get_proc("glGetProgramPipelineiv")));
  if (glow_glGetProgramPipelineiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramPipelineiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramPipelineiv\n");
#endif
  }
  glow_glGetProgramPipelineiv(pipeline, pname, params);
}
PFNGLGETPROGRAMPIPELINEIVPROC glow_glGetProgramPipelineiv = glow_lazy_glGetProgramPipelineiv;
static void glow_lazy_glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
  glow_glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)((ptrdiff_t)(glow_get_proc("glCopyImageSubData")));
  if (glow_glCopyImageSubData == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyImageSubData\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyImageSubData\n");
#endif
  }
  glow_glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
PFNGLCOPYIMAGESUBDATAPROC glow_glCopyImageSubData = glow_lazy_glCopyImageSubData;
static void glow_lazy_glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params) {
  glow_glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)((ptrdiff_t)(glow_get_proc("glGetTexParameterIiv")));
  if (glow_glGetTexParameterIiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameterIiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameterIiv\n");
#endif
  }
  glow_glGetTexParameterIiv(target, pname, params);
}
PFNGLGETTEXPARAMETERIIVPROC glow_glGetTexParameterIiv = glow_lazy_glGetTexParameterIiv;
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
static void glow_lazy_glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)((ptrdiff_t)(glow_get_proc("glUniformMatrix4x2fv")));
  if (glow_glUniformMatrix4x2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix4x2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix4x2fv\n");
#endif
  }
  glow_glUniformMatrix4x2fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X2FVPROC glow_glUniformMatrix4x2fv = glow_lazy_glUniformMatrix4x2fv;
static void glow_lazy_glUniform2ui(GLint location, GLuint v0, GLuint v1) {
  glow_glUniform2ui = (PFNGLUNIFORM2UIPROC)((ptrdiff_t)(glow_get_proc("glUniform2ui")));
  if (glow_glUniform2ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2ui\n");
#endif
  }
  glow_glUniform2ui(location, v0, v1);
}
PFNGLUNIFORM2UIPROC glow_glUniform2ui = glow_lazy_glUniform2ui;
static void glow_lazy_glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {
  glow_glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform1fv")));
  if (glow_glProgramUniform1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1fv\n");
#endif
  }
  glow_glProgramUniform1fv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1FVPROC glow_glProgramUniform1fv = glow_lazy_glProgramUniform1fv;
static void glow_lazy_glMemoryBarrier(GLbitfield barriers) {
  glow_glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)((ptrdiff_t)(glow_get_proc("glMemoryBarrier")));
  if (glow_glMemoryBarrier == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMemoryBarrier\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMemoryBarrier\n");
#endif
  }
  glow_glMemoryBarrier(barriers);
}
PFNGLMEMORYBARRIERPROC glow_glMemoryBarrier = glow_lazy_glMemoryBarrier;
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
static void glow_lazy_glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) {
  glow_glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)((ptrdiff_t)(glow_get_proc("glDrawElementsInstanced")));
  if (glow_glDrawElementsInstanced == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElementsInstanced\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElementsInstanced\n");
#endif
  }
  glow_glDrawElementsInstanced(mode, count, type, indices, instancecount);
}
PFNGLDRAWELEMENTSINSTANCEDPROC glow_glDrawElementsInstanced = glow_lazy_glDrawElementsInstanced;
static void glow_lazy_glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) {
  glow_glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform1iv")));
  if (glow_glProgramUniform1iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1iv\n");
#endif
  }
  glow_glProgramUniform1iv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1IVPROC glow_glProgramUniform1iv = glow_lazy_glProgramUniform1iv;
static void glow_lazy_glActiveShaderProgram(GLuint pipeline, GLuint program) {
  glow_glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)((ptrdiff_t)(glow_get_proc("glActiveShaderProgram")));
  if (glow_glActiveShaderProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glActiveShaderProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glActiveShaderProgram\n");
#endif
  }
  glow_glActiveShaderProgram(pipeline, program);
}
PFNGLACTIVESHADERPROGRAMPROC glow_glActiveShaderProgram = glow_lazy_glActiveShaderProgram;
static void glow_lazy_glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) {
  glow_glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)((ptrdiff_t)(glow_get_proc("glBindImageTexture")));
  if (glow_glBindImageTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindImageTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindImageTexture\n");
#endif
  }
  glow_glBindImageTexture(unit, texture, level, layered, layer, access, format);
}
PFNGLBINDIMAGETEXTUREPROC glow_glBindImageTexture = glow_lazy_glBindImageTexture;
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
static void glow_lazy_glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) {
  glow_glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)((ptrdiff_t)(glow_get_proc("glGetFramebufferParameteriv")));
  if (glow_glGetFramebufferParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFramebufferParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFramebufferParameteriv\n");
#endif
  }
  glow_glGetFramebufferParameteriv(target, pname, params);
}
PFNGLGETFRAMEBUFFERPARAMETERIVPROC glow_glGetFramebufferParameteriv = glow_lazy_glGetFramebufferParameteriv;
static void glow_lazy_glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) {
  glow_glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform3uiv")));
  if (glow_glProgramUniform3uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3uiv\n");
#endif
  }
  glow_glProgramUniform3uiv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3UIVPROC glow_glProgramUniform3uiv = glow_lazy_glProgramUniform3uiv;
static void glow_lazy_glBlendBarrier() {
  glow_glBlendBarrier = (PFNGLBLENDBARRIERPROC)((ptrdiff_t)(glow_get_proc("glBlendBarrier")));
  if (glow_glBlendBarrier == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendBarrier\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendBarrier\n");
#endif
  }
  glow_glBlendBarrier();
}
PFNGLBLENDBARRIERPROC glow_glBlendBarrier = glow_lazy_glBlendBarrier;
static void glow_lazy_glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
  glow_glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)((ptrdiff_t)(glow_get_proc("glTexStorage3DMultisample")));
  if (glow_glTexStorage3DMultisample == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexStorage3DMultisample\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexStorage3DMultisample\n");
#endif
  }
  glow_glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
PFNGLTEXSTORAGE3DMULTISAMPLEPROC glow_glTexStorage3DMultisample = glow_lazy_glTexStorage3DMultisample;
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
static void glow_lazy_glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)((ptrdiff_t)(glow_get_proc("glUniformMatrix2x3fv")));
  if (glow_glUniformMatrix2x3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix2x3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix2x3fv\n");
#endif
  }
  glow_glUniformMatrix2x3fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X3FVPROC glow_glUniformMatrix2x3fv = glow_lazy_glUniformMatrix2x3fv;
static GLboolean glow_lazy_glIsSync(GLsync sync) {
  glow_glIsSync = (PFNGLISSYNCPROC)((ptrdiff_t)(glow_get_proc("glIsSync")));
  if (glow_glIsSync == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsSync\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsSync\n");
#endif
  }
  return glow_glIsSync(sync);
}
PFNGLISSYNCPROC glow_glIsSync = glow_lazy_glIsSync;
static void glow_lazy_glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value) {
  glow_glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)((ptrdiff_t)(glow_get_proc("glClearBufferiv")));
  if (glow_glClearBufferiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearBufferiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearBufferiv\n");
#endif
  }
  glow_glClearBufferiv(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERIVPROC glow_glClearBufferiv = glow_lazy_glClearBufferiv;
static void glow_lazy_glGetBooleani_v(GLenum target, GLuint index, GLboolean *data) {
  glow_glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)((ptrdiff_t)(glow_get_proc("glGetBooleani_v")));
  if (glow_glGetBooleani_v == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBooleani_v\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBooleani_v\n");
#endif
  }
  glow_glGetBooleani_v(target, index, data);
}
PFNGLGETBOOLEANI_VPROC glow_glGetBooleani_v = glow_lazy_glGetBooleani_v;
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
static void glow_lazy_glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) {
  glow_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)((ptrdiff_t)(glow_get_proc("glDrawRangeElements")));
  if (glow_glDrawRangeElements == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawRangeElements\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawRangeElements\n");
#endif
  }
  glow_glDrawRangeElements(mode, start, end, count, type, indices);
}
PFNGLDRAWRANGEELEMENTSPROC glow_glDrawRangeElements = glow_lazy_glDrawRangeElements;
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
static GLuint glow_lazy_glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) {
  glow_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)((ptrdiff_t)(glow_get_proc("glGetUniformBlockIndex")));
  if (glow_glGetUniformBlockIndex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformBlockIndex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformBlockIndex\n");
#endif
  }
  return glow_glGetUniformBlockIndex(program, uniformBlockName);
}
PFNGLGETUNIFORMBLOCKINDEXPROC glow_glGetUniformBlockIndex = glow_lazy_glGetUniformBlockIndex;
static void glow_lazy_glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params) {
  glow_glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)((ptrdiff_t)(glow_get_proc("glGetInternalformativ")));
  if (glow_glGetInternalformativ == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetInternalformativ\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetInternalformativ\n");
#endif
  }
  glow_glGetInternalformativ(target, internalformat, pname, bufSize, params);
}
PFNGLGETINTERNALFORMATIVPROC glow_glGetInternalformativ = glow_lazy_glGetInternalformativ;
static void glow_lazy_glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniformMatrix4x2fv")));
  if (glow_glProgramUniformMatrix4x2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix4x2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix4x2fv\n");
#endif
  }
  glow_glProgramUniformMatrix4x2fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glow_glProgramUniformMatrix4x2fv = glow_lazy_glProgramUniformMatrix4x2fv;
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
static void glow_lazy_glValidateProgramPipeline(GLuint pipeline) {
  glow_glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)((ptrdiff_t)(glow_get_proc("glValidateProgramPipeline")));
  if (glow_glValidateProgramPipeline == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glValidateProgramPipeline\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glValidateProgramPipeline\n");
#endif
  }
  glow_glValidateProgramPipeline(pipeline);
}
PFNGLVALIDATEPROGRAMPIPELINEPROC glow_glValidateProgramPipeline = glow_lazy_glValidateProgramPipeline;
static void glow_lazy_glTexParameterIiv(GLenum target, GLenum pname, const GLint *params) {
  glow_glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)((ptrdiff_t)(glow_get_proc("glTexParameterIiv")));
  if (glow_glTexParameterIiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterIiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterIiv\n");
#endif
  }
  glow_glTexParameterIiv(target, pname, params);
}
PFNGLTEXPARAMETERIIVPROC glow_glTexParameterIiv = glow_lazy_glTexParameterIiv;
static void glow_lazy_glProgramUniform1i(GLuint program, GLint location, GLint v0) {
  glow_glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform1i")));
  if (glow_glProgramUniform1i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1i\n");
#endif
  }
  glow_glProgramUniform1i(program, location, v0);
}
PFNGLPROGRAMUNIFORM1IPROC glow_glProgramUniform1i = glow_lazy_glProgramUniform1i;
static void glow_lazy_glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) {
  glow_glReadnPixels = (PFNGLREADNPIXELSPROC)((ptrdiff_t)(glow_get_proc("glReadnPixels")));
  if (glow_glReadnPixels == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReadnPixels\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReadnPixels\n");
#endif
  }
  glow_glReadnPixels(x, y, width, height, format, type, bufSize, data);
}
PFNGLREADNPIXELSPROC glow_glReadnPixels = glow_lazy_glReadnPixels;
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
static void glow_lazy_glBindProgramPipeline(GLuint pipeline) {
  glow_glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)((ptrdiff_t)(glow_get_proc("glBindProgramPipeline")));
  if (glow_glBindProgramPipeline == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindProgramPipeline\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindProgramPipeline\n");
#endif
  }
  glow_glBindProgramPipeline(pipeline);
}
PFNGLBINDPROGRAMPIPELINEPROC glow_glBindProgramPipeline = glow_lazy_glBindProgramPipeline;
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
static void * glow_lazy_glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
  glow_glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)((ptrdiff_t)(glow_get_proc("glMapBufferRange")));
  if (glow_glMapBufferRange == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMapBufferRange\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMapBufferRange\n");
#endif
  }
  return glow_glMapBufferRange(target, offset, length, access);
}
PFNGLMAPBUFFERRANGEPROC glow_glMapBufferRange = glow_lazy_glMapBufferRange;
static void glow_lazy_glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) {
  glow_glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)((ptrdiff_t)(glow_get_proc("glGetVertexAttribIiv")));
  if (glow_glGetVertexAttribIiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribIiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribIiv\n");
#endif
  }
  glow_glGetVertexAttribIiv(index, pname, params);
}
PFNGLGETVERTEXATTRIBIIVPROC glow_glGetVertexAttribIiv = glow_lazy_glGetVertexAttribIiv;
static void glow_lazy_glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
  glow_glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)((ptrdiff_t)(glow_get_proc("glTexStorage2D")));
  if (glow_glTexStorage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexStorage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexStorage2D\n");
#endif
  }
  glow_glTexStorage2D(target, levels, internalformat, width, height);
}
PFNGLTEXSTORAGE2DPROC glow_glTexStorage2D = glow_lazy_glTexStorage2D;
static void glow_lazy_glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params) {
  glow_glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC)((ptrdiff_t)(glow_get_proc("glGetnUniformuiv")));
  if (glow_glGetnUniformuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetnUniformuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetnUniformuiv\n");
#endif
  }
  glow_glGetnUniformuiv(program, location, bufSize, params);
}
PFNGLGETNUNIFORMUIVPROC glow_glGetnUniformuiv = glow_lazy_glGetnUniformuiv;
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
static void glow_lazy_glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param) {
  glow_glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)((ptrdiff_t)(glow_get_proc("glSamplerParameterIuiv")));
  if (glow_glSamplerParameterIuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameterIuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameterIuiv\n");
#endif
  }
  glow_glSamplerParameterIuiv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIUIVPROC glow_glSamplerParameterIuiv = glow_lazy_glSamplerParameterIuiv;
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
static void glow_lazy_glBindVertexArray(GLuint array) {
  glow_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)((ptrdiff_t)(glow_get_proc("glBindVertexArray")));
  if (glow_glBindVertexArray == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindVertexArray\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindVertexArray\n");
#endif
  }
  glow_glBindVertexArray(array);
}
PFNGLBINDVERTEXARRAYPROC glow_glBindVertexArray = glow_lazy_glBindVertexArray;
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
static void glow_lazy_glGenQueries(GLsizei n, GLuint *ids) {
  glow_glGenQueries = (PFNGLGENQUERIESPROC)((ptrdiff_t)(glow_get_proc("glGenQueries")));
  if (glow_glGenQueries == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenQueries\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenQueries\n");
#endif
  }
  glow_glGenQueries(n, ids);
}
PFNGLGENQUERIESPROC glow_glGenQueries = glow_lazy_glGenQueries;
static void glow_lazy_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
  glow_glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)((ptrdiff_t)(glow_get_proc("glRenderbufferStorageMultisample")));
  if (glow_glRenderbufferStorageMultisample == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRenderbufferStorageMultisample\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRenderbufferStorageMultisample\n");
#endif
  }
  glow_glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
}
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glow_glRenderbufferStorageMultisample = glow_lazy_glRenderbufferStorageMultisample;
static void glow_lazy_glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect) {
  glow_glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)((ptrdiff_t)(glow_get_proc("glDrawElementsIndirect")));
  if (glow_glDrawElementsIndirect == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElementsIndirect\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElementsIndirect\n");
#endif
  }
  glow_glDrawElementsIndirect(mode, type, indirect);
}
PFNGLDRAWELEMENTSINDIRECTPROC glow_glDrawElementsIndirect = glow_lazy_glDrawElementsIndirect;
static void glow_lazy_glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params) {
  glow_glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC)((ptrdiff_t)(glow_get_proc("glGetnUniformfv")));
  if (glow_glGetnUniformfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetnUniformfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetnUniformfv\n");
#endif
  }
  glow_glGetnUniformfv(program, location, bufSize, params);
}
PFNGLGETNUNIFORMFVPROC glow_glGetnUniformfv = glow_lazy_glGetnUniformfv;
static void glow_lazy_glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) {
  glow_glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)((ptrdiff_t)(glow_get_proc("glDispatchCompute")));
  if (glow_glDispatchCompute == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDispatchCompute\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDispatchCompute\n");
#endif
  }
  glow_glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
}
PFNGLDISPATCHCOMPUTEPROC glow_glDispatchCompute = glow_lazy_glDispatchCompute;
static void glow_lazy_glProgramUniform1ui(GLuint program, GLint location, GLuint v0) {
  glow_glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform1ui")));
  if (glow_glProgramUniform1ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1ui\n");
#endif
  }
  glow_glProgramUniform1ui(program, location, v0);
}
PFNGLPROGRAMUNIFORM1UIPROC glow_glProgramUniform1ui = glow_lazy_glProgramUniform1ui;
static GLboolean glow_lazy_glIsEnabledi(GLenum target, GLuint index) {
  glow_glIsEnabledi = (PFNGLISENABLEDIPROC)((ptrdiff_t)(glow_get_proc("glIsEnabledi")));
  if (glow_glIsEnabledi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsEnabledi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsEnabledi\n");
#endif
  }
  return glow_glIsEnabledi(target, index);
}
PFNGLISENABLEDIPROC glow_glIsEnabledi = glow_lazy_glIsEnabledi;
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
static void glow_lazy_glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
  glow_glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)((ptrdiff_t)(glow_get_proc("glVertexAttribI4ui")));
  if (glow_glVertexAttribI4ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribI4ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribI4ui\n");
#endif
  }
  glow_glVertexAttribI4ui(index, x, y, z, w);
}
PFNGLVERTEXATTRIBI4UIPROC glow_glVertexAttribI4ui = glow_lazy_glVertexAttribI4ui;
static void glow_lazy_glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) {
  glow_glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)((ptrdiff_t)(glow_get_proc("glSamplerParameteri")));
  if (glow_glSamplerParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameteri\n");
#endif
  }
  glow_glSamplerParameteri(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIPROC glow_glSamplerParameteri = glow_lazy_glSamplerParameteri;
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
static void glow_lazy_glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) {
  glow_glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform2i")));
  if (glow_glProgramUniform2i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2i\n");
#endif
  }
  glow_glProgramUniform2i(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2IPROC glow_glProgramUniform2i = glow_lazy_glProgramUniform2i;
static void glow_lazy_glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {
  glow_glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform4fv")));
  if (glow_glProgramUniform4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4fv\n");
#endif
  }
  glow_glProgramUniform4fv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4FVPROC glow_glProgramUniform4fv = glow_lazy_glProgramUniform4fv;
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
static GLuint glow_lazy_glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name) {
  glow_glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)((ptrdiff_t)(glow_get_proc("glGetProgramResourceIndex")));
  if (glow_glGetProgramResourceIndex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramResourceIndex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramResourceIndex\n");
#endif
  }
  return glow_glGetProgramResourceIndex(program, programInterface, name);
}
PFNGLGETPROGRAMRESOURCEINDEXPROC glow_glGetProgramResourceIndex = glow_lazy_glGetProgramResourceIndex;
static void glow_lazy_glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
  glow_glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform3i")));
  if (glow_glProgramUniform3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3i\n");
#endif
  }
  glow_glProgramUniform3i(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3IPROC glow_glProgramUniform3i = glow_lazy_glProgramUniform3i;
static void glow_lazy_glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)((ptrdiff_t)(glow_get_proc("glUniformMatrix2x4fv")));
  if (glow_glUniformMatrix2x4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix2x4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix2x4fv\n");
#endif
  }
  glow_glUniformMatrix2x4fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X4FVPROC glow_glUniformMatrix2x4fv = glow_lazy_glUniformMatrix2x4fv;
static void glow_lazy_glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) {
  glow_glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)((ptrdiff_t)(glow_get_proc("glDrawRangeElementsBaseVertex")));
  if (glow_glDrawRangeElementsBaseVertex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawRangeElementsBaseVertex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawRangeElementsBaseVertex\n");
#endif
  }
  glow_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
}
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glow_glDrawRangeElementsBaseVertex = glow_lazy_glDrawRangeElementsBaseVertex;
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
static void glow_lazy_glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) {
  glow_glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)((ptrdiff_t)(glow_get_proc("glFlushMappedBufferRange")));
  if (glow_glFlushMappedBufferRange == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFlushMappedBufferRange\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFlushMappedBufferRange\n");
#endif
  }
  glow_glFlushMappedBufferRange(target, offset, length);
}
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glow_glFlushMappedBufferRange = glow_lazy_glFlushMappedBufferRange;
static GLboolean glow_lazy_glIsSampler(GLuint sampler) {
  glow_glIsSampler = (PFNGLISSAMPLERPROC)((ptrdiff_t)(glow_get_proc("glIsSampler")));
  if (glow_glIsSampler == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsSampler\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsSampler\n");
#endif
  }
  return glow_glIsSampler(sampler);
}
PFNGLISSAMPLERPROC glow_glIsSampler = glow_lazy_glIsSampler;
static void glow_lazy_glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) {
  glow_glProgramBinary = (PFNGLPROGRAMBINARYPROC)((ptrdiff_t)(glow_get_proc("glProgramBinary")));
  if (glow_glProgramBinary == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramBinary\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramBinary\n");
#endif
  }
  glow_glProgramBinary(program, binaryFormat, binary, length);
}
PFNGLPROGRAMBINARYPROC glow_glProgramBinary = glow_lazy_glProgramBinary;
static GLuint glow_lazy_glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings) {
  glow_glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)((ptrdiff_t)(glow_get_proc("glCreateShaderProgramv")));
  if (glow_glCreateShaderProgramv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCreateShaderProgramv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCreateShaderProgramv\n");
#endif
  }
  return glow_glCreateShaderProgramv(type, count, strings);
}
PFNGLCREATESHADERPROGRAMVPROC glow_glCreateShaderProgramv = glow_lazy_glCreateShaderProgramv;
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
static void glow_lazy_glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
  glow_glColorMaski = (PFNGLCOLORMASKIPROC)((ptrdiff_t)(glow_get_proc("glColorMaski")));
  if (glow_glColorMaski == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColorMaski\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColorMaski\n");
#endif
  }
  glow_glColorMaski(index, r, g, b, a);
}
PFNGLCOLORMASKIPROC glow_glColorMaski = glow_lazy_glColorMaski;
static void glow_lazy_glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) {
  glow_glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)((ptrdiff_t)(glow_get_proc("glVertexAttribIPointer")));
  if (glow_glVertexAttribIPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribIPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribIPointer\n");
#endif
  }
  glow_glVertexAttribIPointer(index, size, type, stride, pointer);
}
PFNGLVERTEXATTRIBIPOINTERPROC glow_glVertexAttribIPointer = glow_lazy_glVertexAttribIPointer;
static void glow_lazy_glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
  glow_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)((ptrdiff_t)(glow_get_proc("glUniformBlockBinding")));
  if (glow_glUniformBlockBinding == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformBlockBinding\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformBlockBinding\n");
#endif
  }
  glow_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}
PFNGLUNIFORMBLOCKBINDINGPROC glow_glUniformBlockBinding = glow_lazy_glUniformBlockBinding;
static void glow_lazy_glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniformMatrix3x4fv")));
  if (glow_glProgramUniformMatrix3x4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix3x4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix3x4fv\n");
#endif
  }
  glow_glProgramUniformMatrix3x4fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glow_glProgramUniformMatrix3x4fv = glow_lazy_glProgramUniformMatrix3x4fv;
static void glow_lazy_glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam) {
  glow_glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)((ptrdiff_t)(glow_get_proc("glDebugMessageCallback")));
  if (glow_glDebugMessageCallback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDebugMessageCallback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDebugMessageCallback\n");
#endif
  }
  glow_glDebugMessageCallback(callback, userParam);
}
PFNGLDEBUGMESSAGECALLBACKPROC glow_glDebugMessageCallback = glow_lazy_glDebugMessageCallback;
static void glow_lazy_glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param) {
  glow_glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)((ptrdiff_t)(glow_get_proc("glSamplerParameterIiv")));
  if (glow_glSamplerParameterIiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameterIiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameterIiv\n");
#endif
  }
  glow_glSamplerParameterIiv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIIVPROC glow_glSamplerParameterIiv = glow_lazy_glSamplerParameterIiv;
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
static void glow_lazy_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) {
  glow_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)((ptrdiff_t)(glow_get_proc("glCompressedTexSubImage3D")));
  if (glow_glCompressedTexSubImage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompressedTexSubImage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompressedTexSubImage3D\n");
#endif
  }
  glow_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glow_glCompressedTexSubImage3D = glow_lazy_glCompressedTexSubImage3D;
static void glow_lazy_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) {
  glow_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)((ptrdiff_t)(glow_get_proc("glGetTexLevelParameterfv")));
  if (glow_glGetTexLevelParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexLevelParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexLevelParameterfv\n");
#endif
  }
  glow_glGetTexLevelParameterfv(target, level, pname, params);
}
PFNGLGETTEXLEVELPARAMETERFVPROC glow_glGetTexLevelParameterfv = glow_lazy_glGetTexLevelParameterfv;
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
static void glow_lazy_glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
  glow_glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform2f")));
  if (glow_glProgramUniform2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2f\n");
#endif
  }
  glow_glProgramUniform2f(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2FPROC glow_glProgramUniform2f = glow_lazy_glProgramUniform2f;
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
static void glow_lazy_glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params) {
  glow_glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)((ptrdiff_t)(glow_get_proc("glGetProgramInterfaceiv")));
  if (glow_glGetProgramInterfaceiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramInterfaceiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramInterfaceiv\n");
#endif
  }
  glow_glGetProgramInterfaceiv(program, programInterface, pname, params);
}
PFNGLGETPROGRAMINTERFACEIVPROC glow_glGetProgramInterfaceiv = glow_lazy_glGetProgramInterfaceiv;
static void glow_lazy_glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) {
  glow_glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform2ui")));
  if (glow_glProgramUniform2ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2ui\n");
#endif
  }
  glow_glProgramUniform2ui(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2UIPROC glow_glProgramUniform2ui = glow_lazy_glProgramUniform2ui;
static void glow_lazy_glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) {
  glow_glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform1uiv")));
  if (glow_glProgramUniform1uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1uiv\n");
#endif
  }
  glow_glProgramUniform1uiv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1UIVPROC glow_glProgramUniform1uiv = glow_lazy_glProgramUniform1uiv;
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
static void glow_lazy_glGetBufferPointerv(GLenum target, GLenum pname, void **params) {
  glow_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)((ptrdiff_t)(glow_get_proc("glGetBufferPointerv")));
  if (glow_glGetBufferPointerv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBufferPointerv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBufferPointerv\n");
#endif
  }
  glow_glGetBufferPointerv(target, pname, params);
}
PFNGLGETBUFFERPOINTERVPROC glow_glGetBufferPointerv = glow_lazy_glGetBufferPointerv;
static void glow_lazy_glEndTransformFeedback() {
  glow_glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)((ptrdiff_t)(glow_get_proc("glEndTransformFeedback")));
  if (glow_glEndTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEndTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEndTransformFeedback\n");
#endif
  }
  glow_glEndTransformFeedback();
}
PFNGLENDTRANSFORMFEEDBACKPROC glow_glEndTransformFeedback = glow_lazy_glEndTransformFeedback;
static void glow_lazy_glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params) {
  glow_glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)((ptrdiff_t)(glow_get_proc("glGetSamplerParameterIiv")));
  if (glow_glGetSamplerParameterIiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetSamplerParameterIiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetSamplerParameterIiv\n");
#endif
  }
  glow_glGetSamplerParameterIiv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIIVPROC glow_glGetSamplerParameterIiv = glow_lazy_glGetSamplerParameterIiv;
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
static void glow_lazy_glGenSamplers(GLsizei count, GLuint *samplers) {
  glow_glGenSamplers = (PFNGLGENSAMPLERSPROC)((ptrdiff_t)(glow_get_proc("glGenSamplers")));
  if (glow_glGenSamplers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenSamplers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenSamplers\n");
#endif
  }
  glow_glGenSamplers(count, samplers);
}
PFNGLGENSAMPLERSPROC glow_glGenSamplers = glow_lazy_glGenSamplers;
static void glow_lazy_glEnablei(GLenum target, GLuint index) {
  glow_glEnablei = (PFNGLENABLEIPROC)((ptrdiff_t)(glow_get_proc("glEnablei")));
  if (glow_glEnablei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnablei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnablei\n");
#endif
  }
  glow_glEnablei(target, index);
}
PFNGLENABLEIPROC glow_glEnablei = glow_lazy_glEnablei;
static void glow_lazy_glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label) {
  glow_glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)((ptrdiff_t)(glow_get_proc("glObjectPtrLabel")));
  if (glow_glObjectPtrLabel == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glObjectPtrLabel\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glObjectPtrLabel\n");
#endif
  }
  glow_glObjectPtrLabel(ptr, length, label);
}
PFNGLOBJECTPTRLABELPROC glow_glObjectPtrLabel = glow_lazy_glObjectPtrLabel;
static void glow_lazy_glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) {
  glow_glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)((ptrdiff_t)(glow_get_proc("glDrawElementsInstancedBaseVertex")));
  if (glow_glDrawElementsInstancedBaseVertex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElementsInstancedBaseVertex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElementsInstancedBaseVertex\n");
#endif
  }
  glow_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
}
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glow_glDrawElementsInstancedBaseVertex = glow_lazy_glDrawElementsInstancedBaseVertex;
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
static void glow_lazy_glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines) {
  glow_glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)((ptrdiff_t)(glow_get_proc("glDeleteProgramPipelines")));
  if (glow_glDeleteProgramPipelines == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteProgramPipelines\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteProgramPipelines\n");
#endif
  }
  glow_glDeleteProgramPipelines(n, pipelines);
}
PFNGLDELETEPROGRAMPIPELINESPROC glow_glDeleteProgramPipelines = glow_lazy_glDeleteProgramPipelines;
static void glow_lazy_glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) {
  glow_glTexBuffer = (PFNGLTEXBUFFERPROC)((ptrdiff_t)(glow_get_proc("glTexBuffer")));
  if (glow_glTexBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexBuffer\n");
#endif
  }
  glow_glTexBuffer(target, internalformat, buffer);
}
PFNGLTEXBUFFERPROC glow_glTexBuffer = glow_lazy_glTexBuffer;
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
static void glow_lazy_glGetUniformuiv(GLuint program, GLint location, GLuint *params) {
  glow_glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)((ptrdiff_t)(glow_get_proc("glGetUniformuiv")));
  if (glow_glGetUniformuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformuiv\n");
#endif
  }
  glow_glGetUniformuiv(program, location, params);
}
PFNGLGETUNIFORMUIVPROC glow_glGetUniformuiv = glow_lazy_glGetUniformuiv;
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
static void glow_lazy_glDeleteVertexArrays(GLsizei n, const GLuint *arrays) {
  glow_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)((ptrdiff_t)(glow_get_proc("glDeleteVertexArrays")));
  if (glow_glDeleteVertexArrays == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteVertexArrays\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteVertexArrays\n");
#endif
  }
  glow_glDeleteVertexArrays(n, arrays);
}
PFNGLDELETEVERTEXARRAYSPROC glow_glDeleteVertexArrays = glow_lazy_glDeleteVertexArrays;
static void glow_lazy_glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {
  glow_glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)((ptrdiff_t)(glow_get_proc("glVertexAttribI4i")));
  if (glow_glVertexAttribI4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribI4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribI4i\n");
#endif
  }
  glow_glVertexAttribI4i(index, x, y, z, w);
}
PFNGLVERTEXATTRIBI4IPROC glow_glVertexAttribI4i = glow_lazy_glVertexAttribI4i;
static void glow_lazy_glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data) {
  glow_glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)((ptrdiff_t)(glow_get_proc("glGetInteger64i_v")));
  if (glow_glGetInteger64i_v == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetInteger64i_v\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetInteger64i_v\n");
#endif
  }
  glow_glGetInteger64i_v(target, index, data);
}
PFNGLGETINTEGER64I_VPROC glow_glGetInteger64i_v = glow_lazy_glGetInteger64i_v;
static void glow_lazy_glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param) {
  glow_glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)((ptrdiff_t)(glow_get_proc("glSamplerParameteriv")));
  if (glow_glSamplerParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameteriv\n");
#endif
  }
  glow_glSamplerParameteriv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIVPROC glow_glSamplerParameteriv = glow_lazy_glSamplerParameteriv;
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
static void glow_lazy_glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {
  glow_glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform2fv")));
  if (glow_glProgramUniform2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2fv\n");
#endif
  }
  glow_glProgramUniform2fv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2FVPROC glow_glProgramUniform2fv = glow_lazy_glProgramUniform2fv;
static void glow_lazy_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) {
  glow_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)((ptrdiff_t)(glow_get_proc("glGetQueryObjectuiv")));
  if (glow_glGetQueryObjectuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetQueryObjectuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetQueryObjectuiv\n");
#endif
  }
  glow_glGetQueryObjectuiv(id, pname, params);
}
PFNGLGETQUERYOBJECTUIVPROC glow_glGetQueryObjectuiv = glow_lazy_glGetQueryObjectuiv;
static void glow_lazy_glVertexAttribI4iv(GLuint index, const GLint *v) {
  glow_glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)((ptrdiff_t)(glow_get_proc("glVertexAttribI4iv")));
  if (glow_glVertexAttribI4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribI4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribI4iv\n");
#endif
  }
  glow_glVertexAttribI4iv(index, v);
}
PFNGLVERTEXATTRIBI4IVPROC glow_glVertexAttribI4iv = glow_lazy_glVertexAttribI4iv;
static void glow_lazy_glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) {
  glow_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)((ptrdiff_t)(glow_get_proc("glGetUniformIndices")));
  if (glow_glGetUniformIndices == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformIndices\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformIndices\n");
#endif
  }
  glow_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
}
PFNGLGETUNIFORMINDICESPROC glow_glGetUniformIndices = glow_lazy_glGetUniformIndices;
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
static void glow_lazy_glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments) {
  glow_glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)((ptrdiff_t)(glow_get_proc("glInvalidateFramebuffer")));
  if (glow_glInvalidateFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glInvalidateFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glInvalidateFramebuffer\n");
#endif
  }
  glow_glInvalidateFramebuffer(target, numAttachments, attachments);
}
PFNGLINVALIDATEFRAMEBUFFERPROC glow_glInvalidateFramebuffer = glow_lazy_glInvalidateFramebuffer;
static void glow_lazy_glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniformMatrix2x3fv")));
  if (glow_glProgramUniformMatrix2x3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix2x3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix2x3fv\n");
#endif
  }
  glow_glProgramUniformMatrix2x3fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glow_glProgramUniformMatrix2x3fv = glow_lazy_glProgramUniformMatrix2x3fv;
static void glow_lazy_glBlendFunci(GLuint buf, GLenum src, GLenum dst) {
  glow_glBlendFunci = (PFNGLBLENDFUNCIPROC)((ptrdiff_t)(glow_get_proc("glBlendFunci")));
  if (glow_glBlendFunci == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendFunci\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendFunci\n");
#endif
  }
  glow_glBlendFunci(buf, src, dst);
}
PFNGLBLENDFUNCIPROC glow_glBlendFunci = glow_lazy_glBlendFunci;
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
static void glow_lazy_glGetQueryiv(GLenum target, GLenum pname, GLint *params) {
  glow_glGetQueryiv = (PFNGLGETQUERYIVPROC)((ptrdiff_t)(glow_get_proc("glGetQueryiv")));
  if (glow_glGetQueryiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetQueryiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetQueryiv\n");
#endif
  }
  glow_glGetQueryiv(target, pname, params);
}
PFNGLGETQUERYIVPROC glow_glGetQueryiv = glow_lazy_glGetQueryiv;
static void glow_lazy_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
  glow_glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)((ptrdiff_t)(glow_get_proc("glBlitFramebuffer")));
  if (glow_glBlitFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlitFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlitFramebuffer\n");
#endif
  }
  glow_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNGLBLITFRAMEBUFFERPROC glow_glBlitFramebuffer = glow_lazy_glBlitFramebuffer;
static void glow_lazy_glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
  glow_glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)((ptrdiff_t)(glow_get_proc("glCopyBufferSubData")));
  if (glow_glCopyBufferSubData == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyBufferSubData\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyBufferSubData\n");
#endif
  }
  glow_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
}
PFNGLCOPYBUFFERSUBDATAPROC glow_glCopyBufferSubData = glow_lazy_glCopyBufferSubData;
static void glow_lazy_glDrawArraysIndirect(GLenum mode, const void *indirect) {
  glow_glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)((ptrdiff_t)(glow_get_proc("glDrawArraysIndirect")));
  if (glow_glDrawArraysIndirect == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawArraysIndirect\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawArraysIndirect\n");
#endif
  }
  glow_glDrawArraysIndirect(mode, indirect);
}
PFNGLDRAWARRAYSINDIRECTPROC glow_glDrawArraysIndirect = glow_lazy_glDrawArraysIndirect;
static void glow_lazy_glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) {
  glow_glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)((ptrdiff_t)(glow_get_proc("glUseProgramStages")));
  if (glow_glUseProgramStages == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUseProgramStages\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUseProgramStages\n");
#endif
  }
  glow_glUseProgramStages(pipeline, stages, program);
}
PFNGLUSEPROGRAMSTAGESPROC glow_glUseProgramStages = glow_lazy_glUseProgramStages;
static void glow_lazy_glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniformMatrix4fv")));
  if (glow_glProgramUniformMatrix4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix4fv\n");
#endif
  }
  glow_glProgramUniformMatrix4fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glow_glProgramUniformMatrix4fv = glow_lazy_glProgramUniformMatrix4fv;
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
static void glow_lazy_glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)((ptrdiff_t)(glow_get_proc("glUniformMatrix3x4fv")));
  if (glow_glUniformMatrix3x4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix3x4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix3x4fv\n");
#endif
  }
  glow_glUniformMatrix3x4fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X4FVPROC glow_glUniformMatrix3x4fv = glow_lazy_glUniformMatrix3x4fv;
static void glow_lazy_glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
  glow_glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)((ptrdiff_t)(glow_get_proc("glVertexAttribFormat")));
  if (glow_glVertexAttribFormat == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribFormat\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribFormat\n");
#endif
  }
  glow_glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
}
PFNGLVERTEXATTRIBFORMATPROC glow_glVertexAttribFormat = glow_lazy_glVertexAttribFormat;
static void glow_lazy_glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params) {
  glow_glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC)((ptrdiff_t)(glow_get_proc("glGetnUniformiv")));
  if (glow_glGetnUniformiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetnUniformiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetnUniformiv\n");
#endif
  }
  glow_glGetnUniformiv(program, location, bufSize, params);
}
PFNGLGETNUNIFORMIVPROC glow_glGetnUniformiv = glow_lazy_glGetnUniformiv;
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
static GLboolean glow_lazy_glUnmapBuffer(GLenum target) {
  glow_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)((ptrdiff_t)(glow_get_proc("glUnmapBuffer")));
  if (glow_glUnmapBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUnmapBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUnmapBuffer\n");
#endif
  }
  return glow_glUnmapBuffer(target);
}
PFNGLUNMAPBUFFERPROC glow_glUnmapBuffer = glow_lazy_glUnmapBuffer;
static void glow_lazy_glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) {
  glow_glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)((ptrdiff_t)(glow_get_proc("glVertexBindingDivisor")));
  if (glow_glVertexBindingDivisor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexBindingDivisor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexBindingDivisor\n");
#endif
  }
  glow_glVertexBindingDivisor(bindingindex, divisor);
}
PFNGLVERTEXBINDINGDIVISORPROC glow_glVertexBindingDivisor = glow_lazy_glVertexBindingDivisor;
static void glow_lazy_glBlendEquationi(GLuint buf, GLenum mode) {
  glow_glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)((ptrdiff_t)(glow_get_proc("glBlendEquationi")));
  if (glow_glBlendEquationi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendEquationi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendEquationi\n");
#endif
  }
  glow_glBlendEquationi(buf, mode);
}
PFNGLBLENDEQUATIONIPROC glow_glBlendEquationi = glow_lazy_glBlendEquationi;
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
static void glow_lazy_glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) {
  glow_glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform4iv")));
  if (glow_glProgramUniform4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4iv\n");
#endif
  }
  glow_glProgramUniform4iv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4IVPROC glow_glProgramUniform4iv = glow_lazy_glProgramUniform4iv;
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
static GLint glow_lazy_glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name) {
  glow_glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)((ptrdiff_t)(glow_get_proc("glGetProgramResourceLocation")));
  if (glow_glGetProgramResourceLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramResourceLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramResourceLocation\n");
#endif
  }
  return glow_glGetProgramResourceLocation(program, programInterface, name);
}
PFNGLGETPROGRAMRESOURCELOCATIONPROC glow_glGetProgramResourceLocation = glow_lazy_glGetProgramResourceLocation;
static void glow_lazy_glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
  glow_glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform3ui")));
  if (glow_glProgramUniform3ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3ui\n");
#endif
  }
  glow_glProgramUniform3ui(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3UIPROC glow_glProgramUniform3ui = glow_lazy_glProgramUniform3ui;
static void glow_lazy_glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) {
  glow_glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)((ptrdiff_t)(glow_get_proc("glDrawElementsBaseVertex")));
  if (glow_glDrawElementsBaseVertex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElementsBaseVertex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElementsBaseVertex\n");
#endif
  }
  glow_glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
}
PFNGLDRAWELEMENTSBASEVERTEXPROC glow_glDrawElementsBaseVertex = glow_lazy_glDrawElementsBaseVertex;
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
static void glow_lazy_glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniformMatrix4x3fv")));
  if (glow_glProgramUniformMatrix4x3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix4x3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix4x3fv\n");
#endif
  }
  glow_glProgramUniformMatrix4x3fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glow_glProgramUniformMatrix4x3fv = glow_lazy_glProgramUniformMatrix4x3fv;
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
static void glow_lazy_glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) {
  glow_glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform4uiv")));
  if (glow_glProgramUniform4uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4uiv\n");
#endif
  }
  glow_glProgramUniform4uiv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4UIVPROC glow_glProgramUniform4uiv = glow_lazy_glProgramUniform4uiv;
static void glow_lazy_glMinSampleShading(GLfloat value) {
  glow_glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)((ptrdiff_t)(glow_get_proc("glMinSampleShading")));
  if (glow_glMinSampleShading == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMinSampleShading\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMinSampleShading\n");
#endif
  }
  glow_glMinSampleShading(value);
}
PFNGLMINSAMPLESHADINGPROC glow_glMinSampleShading = glow_lazy_glMinSampleShading;
static void glow_lazy_glBeginQuery(GLenum target, GLuint id) {
  glow_glBeginQuery = (PFNGLBEGINQUERYPROC)((ptrdiff_t)(glow_get_proc("glBeginQuery")));
  if (glow_glBeginQuery == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBeginQuery\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBeginQuery\n");
#endif
  }
  glow_glBeginQuery(target, id);
}
PFNGLBEGINQUERYPROC glow_glBeginQuery = glow_lazy_glBeginQuery;
static void glow_lazy_glBindBufferBase(GLenum target, GLuint index, GLuint buffer) {
  glow_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)((ptrdiff_t)(glow_get_proc("glBindBufferBase")));
  if (glow_glBindBufferBase == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindBufferBase\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindBufferBase\n");
#endif
  }
  glow_glBindBufferBase(target, index, buffer);
}
PFNGLBINDBUFFERBASEPROC glow_glBindBufferBase = glow_lazy_glBindBufferBase;
static GLubyte glow_lazy_glGetStringi(GLenum name, GLuint index) {
  glow_glGetStringi = (PFNGLGETSTRINGIPROC)((ptrdiff_t)(glow_get_proc("glGetStringi")));
  if (glow_glGetStringi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetStringi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetStringi\n");
#endif
  }
  return glow_glGetStringi(name, index);
}
PFNGLGETSTRINGIPROC glow_glGetStringi = glow_lazy_glGetStringi;
static void glow_lazy_glGenTransformFeedbacks(GLsizei n, GLuint *ids) {
  glow_glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)((ptrdiff_t)(glow_get_proc("glGenTransformFeedbacks")));
  if (glow_glGenTransformFeedbacks == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenTransformFeedbacks\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenTransformFeedbacks\n");
#endif
  }
  glow_glGenTransformFeedbacks(n, ids);
}
PFNGLGENTRANSFORMFEEDBACKSPROC glow_glGenTransformFeedbacks = glow_lazy_glGenTransformFeedbacks;
static void glow_lazy_glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniformMatrix2x4fv")));
  if (glow_glProgramUniformMatrix2x4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix2x4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix2x4fv\n");
#endif
  }
  glow_glProgramUniformMatrix2x4fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glow_glProgramUniformMatrix2x4fv = glow_lazy_glProgramUniformMatrix2x4fv;
static void glow_lazy_glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
  glow_glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)((ptrdiff_t)(glow_get_proc("glBlendFuncSeparatei")));
  if (glow_glBlendFuncSeparatei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendFuncSeparatei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendFuncSeparatei\n");
#endif
  }
  glow_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
PFNGLBLENDFUNCSEPARATEIPROC glow_glBlendFuncSeparatei = glow_lazy_glBlendFuncSeparatei;
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
static void glow_lazy_glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) {
  glow_glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)((ptrdiff_t)(glow_get_proc("glSamplerParameterf")));
  if (glow_glSamplerParameterf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameterf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameterf\n");
#endif
  }
  glow_glSamplerParameterf(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERFPROC glow_glSamplerParameterf = glow_lazy_glSamplerParameterf;
static GLboolean glow_lazy_glIsTransformFeedback(GLuint id) {
  glow_glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)((ptrdiff_t)(glow_get_proc("glIsTransformFeedback")));
  if (glow_glIsTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsTransformFeedback\n");
#endif
  }
  return glow_glIsTransformFeedback(id);
}
PFNGLISTRANSFORMFEEDBACKPROC glow_glIsTransformFeedback = glow_lazy_glIsTransformFeedback;
static void glow_lazy_glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
  glow_glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)((ptrdiff_t)(glow_get_proc("glInvalidateSubFramebuffer")));
  if (glow_glInvalidateSubFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glInvalidateSubFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glInvalidateSubFramebuffer\n");
#endif
  }
  glow_glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
}
PFNGLINVALIDATESUBFRAMEBUFFERPROC glow_glInvalidateSubFramebuffer = glow_lazy_glInvalidateSubFramebuffer;
static void glow_lazy_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) {
  glow_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)((ptrdiff_t)(glow_get_proc("glGetTexLevelParameteriv")));
  if (glow_glGetTexLevelParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexLevelParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexLevelParameteriv\n");
#endif
  }
  glow_glGetTexLevelParameteriv(target, level, pname, params);
}
PFNGLGETTEXLEVELPARAMETERIVPROC glow_glGetTexLevelParameteriv = glow_lazy_glGetTexLevelParameteriv;
static void glow_lazy_glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
  glow_glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)((ptrdiff_t)(glow_get_proc("glTexBufferRange")));
  if (glow_glTexBufferRange == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexBufferRange\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexBufferRange\n");
#endif
  }
  glow_glTexBufferRange(target, internalformat, buffer, offset, size);
}
PFNGLTEXBUFFERRANGEPROC glow_glTexBufferRange = glow_lazy_glTexBufferRange;
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
static void glow_lazy_glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
  glow_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)((ptrdiff_t)(glow_get_proc("glBindBufferRange")));
  if (glow_glBindBufferRange == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindBufferRange\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindBufferRange\n");
#endif
  }
  glow_glBindBufferRange(target, index, buffer, offset, size);
}
PFNGLBINDBUFFERRANGEPROC glow_glBindBufferRange = glow_lazy_glBindBufferRange;
static void glow_lazy_glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params) {
  glow_glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)((ptrdiff_t)(glow_get_proc("glGetSamplerParameterfv")));
  if (glow_glGetSamplerParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetSamplerParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetSamplerParameterfv\n");
#endif
  }
  glow_glGetSamplerParameterfv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERFVPROC glow_glGetSamplerParameterfv = glow_lazy_glGetSamplerParameterfv;
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
static void glow_lazy_glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) {
  glow_glTexImage3D = (PFNGLTEXIMAGE3DPROC)((ptrdiff_t)(glow_get_proc("glTexImage3D")));
  if (glow_glTexImage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexImage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexImage3D\n");
#endif
  }
  glow_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
PFNGLTEXIMAGE3DPROC glow_glTexImage3D = glow_lazy_glTexImage3D;
static void glow_lazy_glDispatchComputeIndirect(GLintptr indirect) {
  glow_glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)((ptrdiff_t)(glow_get_proc("glDispatchComputeIndirect")));
  if (glow_glDispatchComputeIndirect == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDispatchComputeIndirect\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDispatchComputeIndirect\n");
#endif
  }
  glow_glDispatchComputeIndirect(indirect);
}
PFNGLDISPATCHCOMPUTEINDIRECTPROC glow_glDispatchComputeIndirect = glow_lazy_glDispatchComputeIndirect;
static void glow_lazy_glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) {
  glow_glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)((ptrdiff_t)(glow_get_proc("glDebugMessageControl")));
  if (glow_glDebugMessageControl == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDebugMessageControl\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDebugMessageControl\n");
#endif
  }
  glow_glDebugMessageControl(source, type, severity, count, ids, enabled);
}
PFNGLDEBUGMESSAGECONTROLPROC glow_glDebugMessageControl = glow_lazy_glDebugMessageControl;
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
static void glow_lazy_glDeleteSync(GLsync sync) {
  glow_glDeleteSync = (PFNGLDELETESYNCPROC)((ptrdiff_t)(glow_get_proc("glDeleteSync")));
  if (glow_glDeleteSync == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteSync\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteSync\n");
#endif
  }
  glow_glDeleteSync(sync);
}
PFNGLDELETESYNCPROC glow_glDeleteSync = glow_lazy_glDeleteSync;
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
static void glow_lazy_glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params) {
  glow_glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)((ptrdiff_t)(glow_get_proc("glGetProgramResourceiv")));
  if (glow_glGetProgramResourceiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramResourceiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramResourceiv\n");
#endif
  }
  glow_glGetProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params);
}
PFNGLGETPROGRAMRESOURCEIVPROC glow_glGetProgramResourceiv = glow_lazy_glGetProgramResourceiv;
static void glow_lazy_glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
  glow_glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)((ptrdiff_t)(glow_get_proc("glGetProgramPipelineInfoLog")));
  if (glow_glGetProgramPipelineInfoLog == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramPipelineInfoLog\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramPipelineInfoLog\n");
#endif
  }
  glow_glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
}
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glow_glGetProgramPipelineInfoLog = glow_lazy_glGetProgramPipelineInfoLog;
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
static void glow_lazy_glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
  glow_glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)((ptrdiff_t)(glow_get_proc("glTexStorage3D")));
  if (glow_glTexStorage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexStorage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexStorage3D\n");
#endif
  }
  glow_glTexStorage3D(target, levels, internalformat, width, height, depth);
}
PFNGLTEXSTORAGE3DPROC glow_glTexStorage3D = glow_lazy_glTexStorage3D;
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
static void glow_lazy_glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
  glow_glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)((ptrdiff_t)(glow_get_proc("glVertexAttribIFormat")));
  if (glow_glVertexAttribIFormat == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribIFormat\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribIFormat\n");
#endif
  }
  glow_glVertexAttribIFormat(attribindex, size, type, relativeoffset);
}
PFNGLVERTEXATTRIBIFORMATPROC glow_glVertexAttribIFormat = glow_lazy_glVertexAttribIFormat;
static void glow_lazy_glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)((ptrdiff_t)(glow_get_proc("glUniformMatrix4x3fv")));
  if (glow_glUniformMatrix4x3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix4x3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix4x3fv\n");
#endif
  }
  glow_glUniformMatrix4x3fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X3FVPROC glow_glUniformMatrix4x3fv = glow_lazy_glUniformMatrix4x3fv;
static void glow_lazy_glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
  glow_glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform3f")));
  if (glow_glProgramUniform3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3f\n");
#endif
  }
  glow_glProgramUniform3f(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3FPROC glow_glProgramUniform3f = glow_lazy_glProgramUniform3f;
static void glow_lazy_glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) {
  glow_glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform2uiv")));
  if (glow_glProgramUniform2uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2uiv\n");
#endif
  }
  glow_glProgramUniform2uiv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2UIVPROC glow_glProgramUniform2uiv = glow_lazy_glProgramUniform2uiv;
static void glow_lazy_glPatchParameteri(GLenum pname, GLint value) {
  glow_glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)((ptrdiff_t)(glow_get_proc("glPatchParameteri")));
  if (glow_glPatchParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPatchParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPatchParameteri\n");
#endif
  }
  glow_glPatchParameteri(pname, value);
}
PFNGLPATCHPARAMETERIPROC glow_glPatchParameteri = glow_lazy_glPatchParameteri;
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
static void glow_lazy_glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
  glow_glUniform4ui = (PFNGLUNIFORM4UIPROC)((ptrdiff_t)(glow_get_proc("glUniform4ui")));
  if (glow_glUniform4ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4ui\n");
#endif
  }
  glow_glUniform4ui(location, v0, v1, v2, v3);
}
PFNGLUNIFORM4UIPROC glow_glUniform4ui = glow_lazy_glUniform4ui;
static void glow_lazy_glGetInteger64v(GLenum pname, GLint64 *data) {
  glow_glGetInteger64v = (PFNGLGETINTEGER64VPROC)((ptrdiff_t)(glow_get_proc("glGetInteger64v")));
  if (glow_glGetInteger64v == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetInteger64v\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetInteger64v\n");
#endif
  }
  glow_glGetInteger64v(pname, data);
}
PFNGLGETINTEGER64VPROC glow_glGetInteger64v = glow_lazy_glGetInteger64v;
static void glow_lazy_glGenProgramPipelines(GLsizei n, GLuint *pipelines) {
  glow_glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)((ptrdiff_t)(glow_get_proc("glGenProgramPipelines")));
  if (glow_glGenProgramPipelines == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenProgramPipelines\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenProgramPipelines\n");
#endif
  }
  glow_glGenProgramPipelines(n, pipelines);
}
PFNGLGENPROGRAMPIPELINESPROC glow_glGenProgramPipelines = glow_lazy_glGenProgramPipelines;
static void glow_lazy_glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
  glow_glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)((ptrdiff_t)(glow_get_proc("glTexStorage2DMultisample")));
  if (glow_glTexStorage2DMultisample == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexStorage2DMultisample\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexStorage2DMultisample\n");
#endif
  }
  glow_glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}
PFNGLTEXSTORAGE2DMULTISAMPLEPROC glow_glTexStorage2DMultisample = glow_lazy_glTexStorage2DMultisample;
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
static void glow_lazy_glEndQuery(GLenum target) {
  glow_glEndQuery = (PFNGLENDQUERYPROC)((ptrdiff_t)(glow_get_proc("glEndQuery")));
  if (glow_glEndQuery == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEndQuery\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEndQuery\n");
#endif
  }
  glow_glEndQuery(target);
}
PFNGLENDQUERYPROC glow_glEndQuery = glow_lazy_glEndQuery;
static void glow_lazy_glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) {
  glow_glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)((ptrdiff_t)(glow_get_proc("glGetVertexAttribIuiv")));
  if (glow_glGetVertexAttribIuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribIuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribIuiv\n");
#endif
  }
  glow_glGetVertexAttribIuiv(index, pname, params);
}
PFNGLGETVERTEXATTRIBIUIVPROC glow_glGetVertexAttribIuiv = glow_lazy_glGetVertexAttribIuiv;
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
static void glow_lazy_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) {
  glow_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)((ptrdiff_t)(glow_get_proc("glCompressedTexImage3D")));
  if (glow_glCompressedTexImage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompressedTexImage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompressedTexImage3D\n");
#endif
  }
  glow_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE3DPROC glow_glCompressedTexImage3D = glow_lazy_glCompressedTexImage3D;
static void glow_lazy_glGetIntegeri_v(GLenum target, GLuint index, GLint *data) {
  glow_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)((ptrdiff_t)(glow_get_proc("glGetIntegeri_v")));
  if (glow_glGetIntegeri_v == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetIntegeri_v\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetIntegeri_v\n");
#endif
  }
  glow_glGetIntegeri_v(target, index, data);
}
PFNGLGETINTEGERI_VPROC glow_glGetIntegeri_v = glow_lazy_glGetIntegeri_v;
static void glow_lazy_glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) {
  glow_glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)((ptrdiff_t)(glow_get_proc("glTransformFeedbackVaryings")));
  if (glow_glTransformFeedbackVaryings == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTransformFeedbackVaryings\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTransformFeedbackVaryings\n");
#endif
  }
  glow_glTransformFeedbackVaryings(program, count, varyings, bufferMode);
}
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glow_glTransformFeedbackVaryings = glow_lazy_glTransformFeedbackVaryings;
static void glow_lazy_glUniform1uiv(GLint location, GLsizei count, const GLuint *value) {
  glow_glUniform1uiv = (PFNGLUNIFORM1UIVPROC)((ptrdiff_t)(glow_get_proc("glUniform1uiv")));
  if (glow_glUniform1uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1uiv\n");
#endif
  }
  glow_glUniform1uiv(location, count, value);
}
PFNGLUNIFORM1UIVPROC glow_glUniform1uiv = glow_lazy_glUniform1uiv;
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
static void glow_lazy_glResumeTransformFeedback() {
  glow_glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)((ptrdiff_t)(glow_get_proc("glResumeTransformFeedback")));
  if (glow_glResumeTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glResumeTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glResumeTransformFeedback\n");
#endif
  }
  glow_glResumeTransformFeedback();
}
PFNGLRESUMETRANSFORMFEEDBACKPROC glow_glResumeTransformFeedback = glow_lazy_glResumeTransformFeedback;
static void glow_lazy_glFramebufferParameteri(GLenum target, GLenum pname, GLint param) {
  glow_glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)((ptrdiff_t)(glow_get_proc("glFramebufferParameteri")));
  if (glow_glFramebufferParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferParameteri\n");
#endif
  }
  glow_glFramebufferParameteri(target, pname, param);
}
PFNGLFRAMEBUFFERPARAMETERIPROC glow_glFramebufferParameteri = glow_lazy_glFramebufferParameteri;
static void glow_lazy_glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params) {
  glow_glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)((ptrdiff_t)(glow_get_proc("glTexParameterIuiv")));
  if (glow_glTexParameterIuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterIuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterIuiv\n");
#endif
  }
  glow_glTexParameterIuiv(target, pname, params);
}
PFNGLTEXPARAMETERIUIVPROC glow_glTexParameterIuiv = glow_lazy_glTexParameterIuiv;
static void glow_lazy_glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) {
  glow_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)((ptrdiff_t)(glow_get_proc("glGetActiveUniformsiv")));
  if (glow_glGetActiveUniformsiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetActiveUniformsiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetActiveUniformsiv\n");
#endif
  }
  glow_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
}
PFNGLGETACTIVEUNIFORMSIVPROC glow_glGetActiveUniformsiv = glow_lazy_glGetActiveUniformsiv;
static void glow_lazy_glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) {
  glow_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)((ptrdiff_t)(glow_get_proc("glGetActiveUniformBlockiv")));
  if (glow_glGetActiveUniformBlockiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetActiveUniformBlockiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetActiveUniformBlockiv\n");
#endif
  }
  glow_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
}
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glow_glGetActiveUniformBlockiv = glow_lazy_glGetActiveUniformBlockiv;
static GLsync glow_lazy_glFenceSync(GLenum condition, GLbitfield flags) {
  glow_glFenceSync = (PFNGLFENCESYNCPROC)((ptrdiff_t)(glow_get_proc("glFenceSync")));
  if (glow_glFenceSync == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFenceSync\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFenceSync\n");
#endif
  }
  return glow_glFenceSync(condition, flags);
}
PFNGLFENCESYNCPROC glow_glFenceSync = glow_lazy_glFenceSync;
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
static void glow_lazy_glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params) {
  glow_glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)((ptrdiff_t)(glow_get_proc("glGetTexParameterIuiv")));
  if (glow_glGetTexParameterIuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameterIuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameterIuiv\n");
#endif
  }
  glow_glGetTexParameterIuiv(target, pname, params);
}
PFNGLGETTEXPARAMETERIUIVPROC glow_glGetTexParameterIuiv = glow_lazy_glGetTexParameterIuiv;
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
static void glow_lazy_glDrawBuffers(GLsizei n, const GLenum *bufs) {
  glow_glDrawBuffers = (PFNGLDRAWBUFFERSPROC)((ptrdiff_t)(glow_get_proc("glDrawBuffers")));
  if (glow_glDrawBuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawBuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawBuffers\n");
#endif
  }
  glow_glDrawBuffers(n, bufs);
}
PFNGLDRAWBUFFERSPROC glow_glDrawBuffers = glow_lazy_glDrawBuffers;
static void glow_lazy_glUniform4uiv(GLint location, GLsizei count, const GLuint *value) {
  glow_glUniform4uiv = (PFNGLUNIFORM4UIVPROC)((ptrdiff_t)(glow_get_proc("glUniform4uiv")));
  if (glow_glUniform4uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4uiv\n");
#endif
  }
  glow_glUniform4uiv(location, count, value);
}
PFNGLUNIFORM4UIVPROC glow_glUniform4uiv = glow_lazy_glUniform4uiv;
static void glow_lazy_glPauseTransformFeedback() {
  glow_glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)((ptrdiff_t)(glow_get_proc("glPauseTransformFeedback")));
  if (glow_glPauseTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPauseTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPauseTransformFeedback\n");
#endif
  }
  glow_glPauseTransformFeedback();
}
PFNGLPAUSETRANSFORMFEEDBACKPROC glow_glPauseTransformFeedback = glow_lazy_glPauseTransformFeedback;
static void glow_lazy_glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
  glow_glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)((ptrdiff_t)(glow_get_proc("glBindVertexBuffer")));
  if (glow_glBindVertexBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindVertexBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindVertexBuffer\n");
#endif
  }
  glow_glBindVertexBuffer(bindingindex, buffer, offset, stride);
}
PFNGLBINDVERTEXBUFFERPROC glow_glBindVertexBuffer = glow_lazy_glBindVertexBuffer;
static void glow_lazy_glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message) {
  glow_glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)((ptrdiff_t)(glow_get_proc("glPushDebugGroup")));
  if (glow_glPushDebugGroup == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPushDebugGroup\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPushDebugGroup\n");
#endif
  }
  glow_glPushDebugGroup(source, id, length, message);
}
PFNGLPUSHDEBUGGROUPPROC glow_glPushDebugGroup = glow_lazy_glPushDebugGroup;
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
static void glow_lazy_glBindTransformFeedback(GLenum target, GLuint id) {
  glow_glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)((ptrdiff_t)(glow_get_proc("glBindTransformFeedback")));
  if (glow_glBindTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindTransformFeedback\n");
#endif
  }
  glow_glBindTransformFeedback(target, id);
}
PFNGLBINDTRANSFORMFEEDBACKPROC glow_glBindTransformFeedback = glow_lazy_glBindTransformFeedback;
static void glow_lazy_glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) {
  glow_glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform2iv")));
  if (glow_glProgramUniform2iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2iv\n");
#endif
  }
  glow_glProgramUniform2iv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2IVPROC glow_glProgramUniform2iv = glow_lazy_glProgramUniform2iv;
static void glow_lazy_glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) {
  glow_glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)((ptrdiff_t)(glow_get_proc("glGetMultisamplefv")));
  if (glow_glGetMultisamplefv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMultisamplefv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMultisamplefv\n");
#endif
  }
  glow_glGetMultisamplefv(pname, index, val);
}
PFNGLGETMULTISAMPLEFVPROC glow_glGetMultisamplefv = glow_lazy_glGetMultisamplefv;
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
static void glow_lazy_glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params) {
  glow_glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)((ptrdiff_t)(glow_get_proc("glGetBufferParameteri64v")));
  if (glow_glGetBufferParameteri64v == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBufferParameteri64v\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBufferParameteri64v\n");
#endif
  }
  glow_glGetBufferParameteri64v(target, pname, params);
}
PFNGLGETBUFFERPARAMETERI64VPROC glow_glGetBufferParameteri64v = glow_lazy_glGetBufferParameteri64v;
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
static void glow_lazy_glUniform3uiv(GLint location, GLsizei count, const GLuint *value) {
  glow_glUniform3uiv = (PFNGLUNIFORM3UIVPROC)((ptrdiff_t)(glow_get_proc("glUniform3uiv")));
  if (glow_glUniform3uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3uiv\n");
#endif
  }
  glow_glUniform3uiv(location, count, value);
}
PFNGLUNIFORM3UIVPROC glow_glUniform3uiv = glow_lazy_glUniform3uiv;
static void glow_lazy_glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) {
  glow_glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)((ptrdiff_t)(glow_get_proc("glGetProgramResourceName")));
  if (glow_glGetProgramResourceName == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramResourceName\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramResourceName\n");
#endif
  }
  glow_glGetProgramResourceName(program, programInterface, index, bufSize, length, name);
}
PFNGLGETPROGRAMRESOURCENAMEPROC glow_glGetProgramResourceName = glow_lazy_glGetProgramResourceName;
static void glow_lazy_glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
  glow_glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform4i")));
  if (glow_glProgramUniform4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4i\n");
#endif
  }
  glow_glProgramUniform4i(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4IPROC glow_glProgramUniform4i = glow_lazy_glProgramUniform4i;
static void glow_lazy_glProgramUniform1f(GLuint program, GLint location, GLfloat v0) {
  glow_glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform1f")));
  if (glow_glProgramUniform1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1f\n");
#endif
  }
  glow_glProgramUniform1f(program, location, v0);
}
PFNGLPROGRAMUNIFORM1FPROC glow_glProgramUniform1f = glow_lazy_glProgramUniform1f;
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
static void glow_lazy_glPrimitiveBoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) {
  glow_glPrimitiveBoundingBox = (PFNGLPRIMITIVEBOUNDINGBOXPROC)((ptrdiff_t)(glow_get_proc("glPrimitiveBoundingBox")));
  if (glow_glPrimitiveBoundingBox == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPrimitiveBoundingBox\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPrimitiveBoundingBox\n");
#endif
  }
  glow_glPrimitiveBoundingBox(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
PFNGLPRIMITIVEBOUNDINGBOXPROC glow_glPrimitiveBoundingBox = glow_lazy_glPrimitiveBoundingBox;
static void glow_lazy_glBeginTransformFeedback(GLenum primitiveMode) {
  glow_glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)((ptrdiff_t)(glow_get_proc("glBeginTransformFeedback")));
  if (glow_glBeginTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBeginTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBeginTransformFeedback\n");
#endif
  }
  glow_glBeginTransformFeedback(primitiveMode);
}
PFNGLBEGINTRANSFORMFEEDBACKPROC glow_glBeginTransformFeedback = glow_lazy_glBeginTransformFeedback;
static void glow_lazy_glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) {
  glow_glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)((ptrdiff_t)(glow_get_proc("glClearBufferfv")));
  if (glow_glClearBufferfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearBufferfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearBufferfv\n");
#endif
  }
  glow_glClearBufferfv(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERFVPROC glow_glClearBufferfv = glow_lazy_glClearBufferfv;
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
static void glow_lazy_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) {
  glow_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)((ptrdiff_t)(glow_get_proc("glTexSubImage3D")));
  if (glow_glTexSubImage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexSubImage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexSubImage3D\n");
#endif
  }
  glow_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
PFNGLTEXSUBIMAGE3DPROC glow_glTexSubImage3D = glow_lazy_glTexSubImage3D;
static void glow_lazy_glUniform1ui(GLint location, GLuint v0) {
  glow_glUniform1ui = (PFNGLUNIFORM1UIPROC)((ptrdiff_t)(glow_get_proc("glUniform1ui")));
  if (glow_glUniform1ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1ui\n");
#endif
  }
  glow_glUniform1ui(location, v0);
}
PFNGLUNIFORM1UIPROC glow_glUniform1ui = glow_lazy_glUniform1ui;
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
static void glow_lazy_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
  glow_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)((ptrdiff_t)(glow_get_proc("glCopyTexSubImage3D")));
  if (glow_glCopyTexSubImage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyTexSubImage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyTexSubImage3D\n");
#endif
  }
  glow_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE3DPROC glow_glCopyTexSubImage3D = glow_lazy_glCopyTexSubImage3D;
static void glow_lazy_glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)((ptrdiff_t)(glow_get_proc("glUniformMatrix3x2fv")));
  if (glow_glUniformMatrix3x2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix3x2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix3x2fv\n");
#endif
  }
  glow_glUniformMatrix3x2fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X2FVPROC glow_glUniformMatrix3x2fv = glow_lazy_glUniformMatrix3x2fv;
static void glow_lazy_glBindSampler(GLuint unit, GLuint sampler) {
  glow_glBindSampler = (PFNGLBINDSAMPLERPROC)((ptrdiff_t)(glow_get_proc("glBindSampler")));
  if (glow_glBindSampler == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindSampler\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindSampler\n");
#endif
  }
  glow_glBindSampler(unit, sampler);
}
PFNGLBINDSAMPLERPROC glow_glBindSampler = glow_lazy_glBindSampler;
static void glow_lazy_glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) {
  glow_glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)((ptrdiff_t)(glow_get_proc("glVertexAttribBinding")));
  if (glow_glVertexAttribBinding == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribBinding\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribBinding\n");
#endif
  }
  glow_glVertexAttribBinding(attribindex, bindingindex);
}
PFNGLVERTEXATTRIBBINDINGPROC glow_glVertexAttribBinding = glow_lazy_glVertexAttribBinding;
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
static void glow_lazy_glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {
  glow_glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)((ptrdiff_t)(glow_get_proc("glDrawArraysInstanced")));
  if (glow_glDrawArraysInstanced == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawArraysInstanced\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawArraysInstanced\n");
#endif
  }
  glow_glDrawArraysInstanced(mode, first, count, instancecount);
}
PFNGLDRAWARRAYSINSTANCEDPROC glow_glDrawArraysInstanced = glow_lazy_glDrawArraysInstanced;
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
static void glow_lazy_glGenVertexArrays(GLsizei n, GLuint *arrays) {
  glow_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)((ptrdiff_t)(glow_get_proc("glGenVertexArrays")));
  if (glow_glGenVertexArrays == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenVertexArrays\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenVertexArrays\n");
#endif
  }
  glow_glGenVertexArrays(n, arrays);
}
PFNGLGENVERTEXARRAYSPROC glow_glGenVertexArrays = glow_lazy_glGenVertexArrays;
static GLboolean glow_lazy_glIsVertexArray(GLuint array) {
  glow_glIsVertexArray = (PFNGLISVERTEXARRAYPROC)((ptrdiff_t)(glow_get_proc("glIsVertexArray")));
  if (glow_glIsVertexArray == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsVertexArray\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsVertexArray\n");
#endif
  }
  return glow_glIsVertexArray(array);
}
PFNGLISVERTEXARRAYPROC glow_glIsVertexArray = glow_lazy_glIsVertexArray;
static void glow_lazy_glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
  glow_glWaitSync = (PFNGLWAITSYNCPROC)((ptrdiff_t)(glow_get_proc("glWaitSync")));
  if (glow_glWaitSync == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glWaitSync\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glWaitSync\n");
#endif
  }
  glow_glWaitSync(sync, flags, timeout);
}
PFNGLWAITSYNCPROC glow_glWaitSync = glow_lazy_glWaitSync;
static void glow_lazy_glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
  glow_glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform4ui")));
  if (glow_glProgramUniform4ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4ui\n");
#endif
  }
  glow_glProgramUniform4ui(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4UIPROC glow_glProgramUniform4ui = glow_lazy_glProgramUniform4ui;
static void glow_lazy_glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniformMatrix2fv")));
  if (glow_glProgramUniformMatrix2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix2fv\n");
#endif
  }
  glow_glProgramUniformMatrix2fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glow_glProgramUniformMatrix2fv = glow_lazy_glProgramUniformMatrix2fv;
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
static void glow_lazy_glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) {
  glow_glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)((ptrdiff_t)(glow_get_proc("glGetTransformFeedbackVarying")));
  if (glow_glGetTransformFeedbackVarying == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTransformFeedbackVarying\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTransformFeedbackVarying\n");
#endif
  }
  glow_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glow_glGetTransformFeedbackVarying = glow_lazy_glGetTransformFeedbackVarying;
static void glow_lazy_glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {
  glow_glUniform3ui = (PFNGLUNIFORM3UIPROC)((ptrdiff_t)(glow_get_proc("glUniform3ui")));
  if (glow_glUniform3ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3ui\n");
#endif
  }
  glow_glUniform3ui(location, v0, v1, v2);
}
PFNGLUNIFORM3UIPROC glow_glUniform3ui = glow_lazy_glUniform3ui;
static void glow_lazy_glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) {
  glow_glGetSynciv = (PFNGLGETSYNCIVPROC)((ptrdiff_t)(glow_get_proc("glGetSynciv")));
  if (glow_glGetSynciv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetSynciv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetSynciv\n");
#endif
  }
  glow_glGetSynciv(sync, pname, bufSize, length, values);
}
PFNGLGETSYNCIVPROC glow_glGetSynciv = glow_lazy_glGetSynciv;
static void glow_lazy_glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
  glow_glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform4f")));
  if (glow_glProgramUniform4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4f\n");
#endif
  }
  glow_glProgramUniform4f(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4FPROC glow_glProgramUniform4f = glow_lazy_glProgramUniform4f;
static void glow_lazy_glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) {
  glow_glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform3iv")));
  if (glow_glProgramUniform3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3iv\n");
#endif
  }
  glow_glProgramUniform3iv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3IVPROC glow_glProgramUniform3iv = glow_lazy_glProgramUniform3iv;
static void glow_lazy_glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) {
  glow_glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)((ptrdiff_t)(glow_get_proc("glDebugMessageInsert")));
  if (glow_glDebugMessageInsert == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDebugMessageInsert\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDebugMessageInsert\n");
#endif
  }
  glow_glDebugMessageInsert(source, type, id, severity, length, buf);
}
PFNGLDEBUGMESSAGEINSERTPROC glow_glDebugMessageInsert = glow_lazy_glDebugMessageInsert;
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
static void glow_lazy_glPopDebugGroup() {
  glow_glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)((ptrdiff_t)(glow_get_proc("glPopDebugGroup")));
  if (glow_glPopDebugGroup == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPopDebugGroup\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPopDebugGroup\n");
#endif
  }
  glow_glPopDebugGroup();
}
PFNGLPOPDEBUGGROUPPROC glow_glPopDebugGroup = glow_lazy_glPopDebugGroup;
static void glow_lazy_glGetObjectPtrLabel(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) {
  glow_glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)((ptrdiff_t)(glow_get_proc("glGetObjectPtrLabel")));
  if (glow_glGetObjectPtrLabel == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetObjectPtrLabel\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetObjectPtrLabel\n");
#endif
  }
  glow_glGetObjectPtrLabel(ptr, bufSize, length, label);
}
PFNGLGETOBJECTPTRLABELPROC glow_glGetObjectPtrLabel = glow_lazy_glGetObjectPtrLabel;
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
static void glow_lazy_glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label) {
  glow_glObjectLabel = (PFNGLOBJECTLABELPROC)((ptrdiff_t)(glow_get_proc("glObjectLabel")));
  if (glow_glObjectLabel == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glObjectLabel\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glObjectLabel\n");
#endif
  }
  glow_glObjectLabel(identifier, name, length, label);
}
PFNGLOBJECTLABELPROC glow_glObjectLabel = glow_lazy_glObjectLabel;
static void glow_lazy_glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) {
  glow_glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)((ptrdiff_t)(glow_get_proc("glGetObjectLabel")));
  if (glow_glGetObjectLabel == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetObjectLabel\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetObjectLabel\n");
#endif
  }
  glow_glGetObjectLabel(identifier, name, bufSize, length, label);
}
PFNGLGETOBJECTLABELPROC glow_glGetObjectLabel = glow_lazy_glGetObjectLabel;
static GLenum glow_lazy_glGetGraphicsResetStatus() {
  glow_glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC)((ptrdiff_t)(glow_get_proc("glGetGraphicsResetStatus")));
  if (glow_glGetGraphicsResetStatus == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetGraphicsResetStatus\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetGraphicsResetStatus\n");
#endif
  }
  return glow_glGetGraphicsResetStatus();
}
PFNGLGETGRAPHICSRESETSTATUSPROC glow_glGetGraphicsResetStatus = glow_lazy_glGetGraphicsResetStatus;
static void glow_lazy_glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
  glow_glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)((ptrdiff_t)(glow_get_proc("glClearBufferfi")));
  if (glow_glClearBufferfi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearBufferfi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearBufferfi\n");
#endif
  }
  glow_glClearBufferfi(buffer, drawbuffer, depth, stencil);
}
PFNGLCLEARBUFFERFIPROC glow_glClearBufferfi = glow_lazy_glClearBufferfi;
static void glow_lazy_glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {
  glow_glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniform3fv")));
  if (glow_glProgramUniform3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3fv\n");
#endif
  }
  glow_glProgramUniform3fv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3FVPROC glow_glProgramUniform3fv = glow_lazy_glProgramUniform3fv;
static void glow_lazy_glSampleMaski(GLuint maskNumber, GLbitfield mask) {
  glow_glSampleMaski = (PFNGLSAMPLEMASKIPROC)((ptrdiff_t)(glow_get_proc("glSampleMaski")));
  if (glow_glSampleMaski == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSampleMaski\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSampleMaski\n");
#endif
  }
  glow_glSampleMaski(maskNumber, mask);
}
PFNGLSAMPLEMASKIPROC glow_glSampleMaski = glow_lazy_glSampleMaski;
static void glow_lazy_glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniformMatrix3x2fv")));
  if (glow_glProgramUniformMatrix3x2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix3x2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix3x2fv\n");
#endif
  }
  glow_glProgramUniformMatrix3x2fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glow_glProgramUniformMatrix3x2fv = glow_lazy_glProgramUniformMatrix3x2fv;
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
static GLint glow_lazy_glGetFragDataLocation(GLuint program, const GLchar *name) {
  glow_glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)((ptrdiff_t)(glow_get_proc("glGetFragDataLocation")));
  if (glow_glGetFragDataLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFragDataLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFragDataLocation\n");
#endif
  }
  return glow_glGetFragDataLocation(program, name);
}
PFNGLGETFRAGDATALOCATIONPROC glow_glGetFragDataLocation = glow_lazy_glGetFragDataLocation;
static void glow_lazy_glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
  glow_glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)((ptrdiff_t)(glow_get_proc("glProgramUniformMatrix3fv")));
  if (glow_glProgramUniformMatrix3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix3fv\n");
#endif
  }
  glow_glProgramUniformMatrix3fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glow_glProgramUniformMatrix3fv = glow_lazy_glProgramUniformMatrix3fv;
static void glow_lazy_glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params) {
  glow_glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)((ptrdiff_t)(glow_get_proc("glGetSamplerParameterIuiv")));
  if (glow_glGetSamplerParameterIuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetSamplerParameterIuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetSamplerParameterIuiv\n");
#endif
  }
  glow_glGetSamplerParameterIuiv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIUIVPROC glow_glGetSamplerParameterIuiv = glow_lazy_glGetSamplerParameterIuiv;
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
static void glow_lazy_glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params) {
  glow_glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)((ptrdiff_t)(glow_get_proc("glGetSamplerParameteriv")));
  if (glow_glGetSamplerParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetSamplerParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetSamplerParameteriv\n");
#endif
  }
  glow_glGetSamplerParameteriv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIVPROC glow_glGetSamplerParameteriv = glow_lazy_glGetSamplerParameteriv;
static void glow_lazy_glProgramParameteri(GLuint program, GLenum pname, GLint value) {
  glow_glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)((ptrdiff_t)(glow_get_proc("glProgramParameteri")));
  if (glow_glProgramParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramParameteri\n");
#endif
  }
  glow_glProgramParameteri(program, pname, value);
}
PFNGLPROGRAMPARAMETERIPROC glow_glProgramParameteri = glow_lazy_glProgramParameteri;
static void glow_lazy_glDeleteQueries(GLsizei n, const GLuint *ids) {
  glow_glDeleteQueries = (PFNGLDELETEQUERIESPROC)((ptrdiff_t)(glow_get_proc("glDeleteQueries")));
  if (glow_glDeleteQueries == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteQueries\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteQueries\n");
#endif
  }
  glow_glDeleteQueries(n, ids);
}
PFNGLDELETEQUERIESPROC glow_glDeleteQueries = glow_lazy_glDeleteQueries;
static void glow_lazy_glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) {
  glow_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)((ptrdiff_t)(glow_get_proc("glGetActiveUniformBlockName")));
  if (glow_glGetActiveUniformBlockName == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetActiveUniformBlockName\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetActiveUniformBlockName\n");
#endif
  }
  glow_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glow_glGetActiveUniformBlockName = glow_lazy_glGetActiveUniformBlockName;
static GLenum glow_lazy_glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
  glow_glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)((ptrdiff_t)(glow_get_proc("glClientWaitSync")));
  if (glow_glClientWaitSync == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClientWaitSync\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClientWaitSync\n");
#endif
  }
  return glow_glClientWaitSync(sync, flags, timeout);
}
PFNGLCLIENTWAITSYNCPROC glow_glClientWaitSync = glow_lazy_glClientWaitSync;
static void glow_lazy_glVertexAttribDivisor(GLuint index, GLuint divisor) {
  glow_glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)((ptrdiff_t)(glow_get_proc("glVertexAttribDivisor")));
  if (glow_glVertexAttribDivisor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribDivisor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribDivisor\n");
#endif
  }
  glow_glVertexAttribDivisor(index, divisor);
}
PFNGLVERTEXATTRIBDIVISORPROC glow_glVertexAttribDivisor = glow_lazy_glVertexAttribDivisor;
static GLboolean glow_lazy_glIsProgramPipeline(GLuint pipeline) {
  glow_glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)((ptrdiff_t)(glow_get_proc("glIsProgramPipeline")));
  if (glow_glIsProgramPipeline == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsProgramPipeline\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsProgramPipeline\n");
#endif
  }
  return glow_glIsProgramPipeline(pipeline);
}
PFNGLISPROGRAMPIPELINEPROC glow_glIsProgramPipeline = glow_lazy_glIsProgramPipeline;
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
static void glow_lazy_glReadBuffer(GLenum src) {
  glow_glReadBuffer = (PFNGLREADBUFFERPROC)((ptrdiff_t)(glow_get_proc("glReadBuffer")));
  if (glow_glReadBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReadBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReadBuffer\n");
#endif
  }
  glow_glReadBuffer(src);
}
PFNGLREADBUFFERPROC glow_glReadBuffer = glow_lazy_glReadBuffer;
static void glow_lazy_glMemoryBarrierByRegion(GLbitfield barriers) {
  glow_glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)((ptrdiff_t)(glow_get_proc("glMemoryBarrierByRegion")));
  if (glow_glMemoryBarrierByRegion == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMemoryBarrierByRegion\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMemoryBarrierByRegion\n");
#endif
  }
  glow_glMemoryBarrierByRegion(barriers);
}
PFNGLMEMORYBARRIERBYREGIONPROC glow_glMemoryBarrierByRegion = glow_lazy_glMemoryBarrierByRegion;
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
static void glow_lazy_glUniform2uiv(GLint location, GLsizei count, const GLuint *value) {
  glow_glUniform2uiv = (PFNGLUNIFORM2UIVPROC)((ptrdiff_t)(glow_get_proc("glUniform2uiv")));
  if (glow_glUniform2uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2uiv\n");
#endif
  }
  glow_glUniform2uiv(location, count, value);
}
PFNGLUNIFORM2UIVPROC glow_glUniform2uiv = glow_lazy_glUniform2uiv;


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

static void glow_debug_impl_glDisableVertexAttribArray(GLuint index) {

  glow_pre_callback_("glDisableVertexAttribArray", (void*)(ptrdiff_t)glow_glDisableVertexAttribArray, index);
  glow_glDisableVertexAttribArray(index);
  glow_post_callback_("glDisableVertexAttribArray", (void*)(ptrdiff_t)glow_glDisableVertexAttribArray, index);
}
PFNGLDISABLEVERTEXATTRIBARRAYPROC glow_debug_glDisableVertexAttribArray = glow_debug_impl_glDisableVertexAttribArray;

static void glow_debug_impl_glDeleteSamplers(GLsizei count, const GLuint *samplers) {

  glow_pre_callback_("glDeleteSamplers", (void*)(ptrdiff_t)glow_glDeleteSamplers, count, samplers);
  glow_glDeleteSamplers(count, samplers);
  glow_post_callback_("glDeleteSamplers", (void*)(ptrdiff_t)glow_glDeleteSamplers, count, samplers);
}
PFNGLDELETESAMPLERSPROC glow_debug_glDeleteSamplers = glow_debug_impl_glDeleteSamplers;

static void glow_debug_impl_glVertexAttribI4uiv(GLuint index, const GLuint *v) {

  glow_pre_callback_("glVertexAttribI4uiv", (void*)(ptrdiff_t)glow_glVertexAttribI4uiv, index, v);
  glow_glVertexAttribI4uiv(index, v);
  glow_post_callback_("glVertexAttribI4uiv", (void*)(ptrdiff_t)glow_glVertexAttribI4uiv, index, v);
}
PFNGLVERTEXATTRIBI4UIVPROC glow_debug_glVertexAttribI4uiv = glow_debug_impl_glVertexAttribI4uiv;

static void glow_debug_impl_glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) {

  glow_pre_callback_("glGetProgramBinary", (void*)(ptrdiff_t)glow_glGetProgramBinary, program, bufSize, length, binaryFormat, binary);
  glow_glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
  glow_post_callback_("glGetProgramBinary", (void*)(ptrdiff_t)glow_glGetProgramBinary, program, bufSize, length, binaryFormat, binary);
}
PFNGLGETPROGRAMBINARYPROC glow_debug_glGetProgramBinary = glow_debug_impl_glGetProgramBinary;

static GLuint glow_debug_impl_glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) {

  GLuint ret;
  glow_pre_callback_("glGetDebugMessageLog", (void*)(ptrdiff_t)glow_glGetDebugMessageLog, count, bufSize, sources, types, ids, severities, lengths, messageLog);
  ret = glow_glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog);
  glow_post_callback_("glGetDebugMessageLog", (void*)(ptrdiff_t)glow_glGetDebugMessageLog, count, bufSize, sources, types, ids, severities, lengths, messageLog);
  return ret;
}
PFNGLGETDEBUGMESSAGELOGPROC glow_debug_glGetDebugMessageLog = glow_debug_impl_glGetDebugMessageLog;

static void glow_debug_impl_glDisablei(GLenum target, GLuint index) {

  glow_pre_callback_("glDisablei", (void*)(ptrdiff_t)glow_glDisablei, target, index);
  glow_glDisablei(target, index);
  glow_post_callback_("glDisablei", (void*)(ptrdiff_t)glow_glDisablei, target, index);
}
PFNGLDISABLEIPROC glow_debug_glDisablei = glow_debug_impl_glDisablei;

static void glow_debug_impl_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) {

  glow_pre_callback_("glDrawElements", (void*)(ptrdiff_t)glow_glDrawElements, mode, count, type, indices);
  glow_glDrawElements(mode, count, type, indices);
  glow_post_callback_("glDrawElements", (void*)(ptrdiff_t)glow_glDrawElements, mode, count, type, indices);
}
PFNGLDRAWELEMENTSPROC glow_debug_glDrawElements = glow_debug_impl_glDrawElements;

static void glow_debug_impl_glReleaseShaderCompiler() {

  glow_pre_callback_("glReleaseShaderCompiler", (void*)(ptrdiff_t)glow_glReleaseShaderCompiler);
  glow_glReleaseShaderCompiler();
  glow_post_callback_("glReleaseShaderCompiler", (void*)(ptrdiff_t)glow_glReleaseShaderCompiler);
}
PFNGLRELEASESHADERCOMPILERPROC glow_debug_glReleaseShaderCompiler = glow_debug_impl_glReleaseShaderCompiler;

static void glow_debug_impl_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {

  glow_pre_callback_("glUniform3i", (void*)(ptrdiff_t)glow_glUniform3i, location, v0, v1, v2);
  glow_glUniform3i(location, v0, v1, v2);
  glow_post_callback_("glUniform3i", (void*)(ptrdiff_t)glow_glUniform3i, location, v0, v1, v2);
}
PFNGLUNIFORM3IPROC glow_debug_glUniform3i = glow_debug_impl_glUniform3i;

static GLboolean glow_debug_impl_glIsQuery(GLuint id) {

  GLboolean ret;
  glow_pre_callback_("glIsQuery", (void*)(ptrdiff_t)glow_glIsQuery, id);
  ret = glow_glIsQuery(id);
  glow_post_callback_("glIsQuery", (void*)(ptrdiff_t)glow_glIsQuery, id);
  return ret;
}
PFNGLISQUERYPROC glow_debug_glIsQuery = glow_debug_impl_glIsQuery;

static void glow_debug_impl_glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids) {

  glow_pre_callback_("glDeleteTransformFeedbacks", (void*)(ptrdiff_t)glow_glDeleteTransformFeedbacks, n, ids);
  glow_glDeleteTransformFeedbacks(n, ids);
  glow_post_callback_("glDeleteTransformFeedbacks", (void*)(ptrdiff_t)glow_glDeleteTransformFeedbacks, n, ids);
}
PFNGLDELETETRANSFORMFEEDBACKSPROC glow_debug_glDeleteTransformFeedbacks = glow_debug_impl_glDeleteTransformFeedbacks;

static GLint glow_debug_impl_glGetAttribLocation(GLuint program, const GLchar *name) {

  GLint ret;
  glow_pre_callback_("glGetAttribLocation", (void*)(ptrdiff_t)glow_glGetAttribLocation, program, name);
  ret = glow_glGetAttribLocation(program, name);
  glow_post_callback_("glGetAttribLocation", (void*)(ptrdiff_t)glow_glGetAttribLocation, program, name);
  return ret;
}
PFNGLGETATTRIBLOCATIONPROC glow_debug_glGetAttribLocation = glow_debug_impl_glGetAttribLocation;

static void glow_debug_impl_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) {

  glow_pre_callback_("glGetShaderSource", (void*)(ptrdiff_t)glow_glGetShaderSource, shader, bufSize, length, source);
  glow_glGetShaderSource(shader, bufSize, length, source);
  glow_post_callback_("glGetShaderSource", (void*)(ptrdiff_t)glow_glGetShaderSource, shader, bufSize, length, source);
}
PFNGLGETSHADERSOURCEPROC glow_debug_glGetShaderSource = glow_debug_impl_glGetShaderSource;

static void glow_debug_impl_glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) {

  glow_pre_callback_("glShaderSource", (void*)(ptrdiff_t)glow_glShaderSource, shader, count, string, length);
  glow_glShaderSource(shader, count, string, length);
  glow_post_callback_("glShaderSource", (void*)(ptrdiff_t)glow_glShaderSource, shader, count, string, length);
}
PFNGLSHADERSOURCEPROC glow_debug_glShaderSource = glow_debug_impl_glShaderSource;

static void glow_debug_impl_glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {

  glow_pre_callback_("glFramebufferTextureLayer", (void*)(ptrdiff_t)glow_glFramebufferTextureLayer, target, attachment, texture, level, layer);
  glow_glFramebufferTextureLayer(target, attachment, texture, level, layer);
  glow_post_callback_("glFramebufferTextureLayer", (void*)(ptrdiff_t)glow_glFramebufferTextureLayer, target, attachment, texture, level, layer);
}
PFNGLFRAMEBUFFERTEXTURELAYERPROC glow_debug_glFramebufferTextureLayer = glow_debug_impl_glFramebufferTextureLayer;

static void glow_debug_impl_glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) {

  glow_pre_callback_("glClearBufferuiv", (void*)(ptrdiff_t)glow_glClearBufferuiv, buffer, drawbuffer, value);
  glow_glClearBufferuiv(buffer, drawbuffer, value);
  glow_post_callback_("glClearBufferuiv", (void*)(ptrdiff_t)glow_glClearBufferuiv, buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERUIVPROC glow_debug_glClearBufferuiv = glow_debug_impl_glClearBufferuiv;

static void glow_debug_impl_glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param) {

  glow_pre_callback_("glSamplerParameterfv", (void*)(ptrdiff_t)glow_glSamplerParameterfv, sampler, pname, param);
  glow_glSamplerParameterfv(sampler, pname, param);
  glow_post_callback_("glSamplerParameterfv", (void*)(ptrdiff_t)glow_glSamplerParameterfv, sampler, pname, param);
}
PFNGLSAMPLERPARAMETERFVPROC glow_debug_glSamplerParameterfv = glow_debug_impl_glSamplerParameterfv;

static void glow_debug_impl_glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {

  glow_pre_callback_("glBlendEquationSeparatei", (void*)(ptrdiff_t)glow_glBlendEquationSeparatei, buf, modeRGB, modeAlpha);
  glow_glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
  glow_post_callback_("glBlendEquationSeparatei", (void*)(ptrdiff_t)glow_glBlendEquationSeparatei, buf, modeRGB, modeAlpha);
}
PFNGLBLENDEQUATIONSEPARATEIPROC glow_debug_glBlendEquationSeparatei = glow_debug_impl_glBlendEquationSeparatei;

static void glow_debug_impl_glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) {

  glow_pre_callback_("glFramebufferTexture", (void*)(ptrdiff_t)glow_glFramebufferTexture, target, attachment, texture, level);
  glow_glFramebufferTexture(target, attachment, texture, level);
  glow_post_callback_("glFramebufferTexture", (void*)(ptrdiff_t)glow_glFramebufferTexture, target, attachment, texture, level);
}
PFNGLFRAMEBUFFERTEXTUREPROC glow_debug_glFramebufferTexture = glow_debug_impl_glFramebufferTexture;

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

static void glow_debug_impl_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetRenderbufferParameteriv", (void*)(ptrdiff_t)glow_glGetRenderbufferParameteriv, target, pname, params);
  glow_glGetRenderbufferParameteriv(target, pname, params);
  glow_post_callback_("glGetRenderbufferParameteriv", (void*)(ptrdiff_t)glow_glGetRenderbufferParameteriv, target, pname, params);
}
PFNGLGETRENDERBUFFERPARAMETERIVPROC glow_debug_glGetRenderbufferParameteriv = glow_debug_impl_glGetRenderbufferParameteriv;

static void glow_debug_impl_glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetProgramPipelineiv", (void*)(ptrdiff_t)glow_glGetProgramPipelineiv, pipeline, pname, params);
  glow_glGetProgramPipelineiv(pipeline, pname, params);
  glow_post_callback_("glGetProgramPipelineiv", (void*)(ptrdiff_t)glow_glGetProgramPipelineiv, pipeline, pname, params);
}
PFNGLGETPROGRAMPIPELINEIVPROC glow_debug_glGetProgramPipelineiv = glow_debug_impl_glGetProgramPipelineiv;

static void glow_debug_impl_glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {

  glow_pre_callback_("glCopyImageSubData", (void*)(ptrdiff_t)glow_glCopyImageSubData, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
  glow_glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
  glow_post_callback_("glCopyImageSubData", (void*)(ptrdiff_t)glow_glCopyImageSubData, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
PFNGLCOPYIMAGESUBDATAPROC glow_debug_glCopyImageSubData = glow_debug_impl_glCopyImageSubData;

static void glow_debug_impl_glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetTexParameterIiv", (void*)(ptrdiff_t)glow_glGetTexParameterIiv, target, pname, params);
  glow_glGetTexParameterIiv(target, pname, params);
  glow_post_callback_("glGetTexParameterIiv", (void*)(ptrdiff_t)glow_glGetTexParameterIiv, target, pname, params);
}
PFNGLGETTEXPARAMETERIIVPROC glow_debug_glGetTexParameterIiv = glow_debug_impl_glGetTexParameterIiv;

static void glow_debug_impl_glUniform1f(GLint location, GLfloat v0) {

  glow_pre_callback_("glUniform1f", (void*)(ptrdiff_t)glow_glUniform1f, location, v0);
  glow_glUniform1f(location, v0);
  glow_post_callback_("glUniform1f", (void*)(ptrdiff_t)glow_glUniform1f, location, v0);
}
PFNGLUNIFORM1FPROC glow_debug_glUniform1f = glow_debug_impl_glUniform1f;

static void glow_debug_impl_glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix4x2fv", (void*)(ptrdiff_t)glow_glUniformMatrix4x2fv, location, count, transpose, value);
  glow_glUniformMatrix4x2fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix4x2fv", (void*)(ptrdiff_t)glow_glUniformMatrix4x2fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X2FVPROC glow_debug_glUniformMatrix4x2fv = glow_debug_impl_glUniformMatrix4x2fv;

static void glow_debug_impl_glUniform2ui(GLint location, GLuint v0, GLuint v1) {

  glow_pre_callback_("glUniform2ui", (void*)(ptrdiff_t)glow_glUniform2ui, location, v0, v1);
  glow_glUniform2ui(location, v0, v1);
  glow_post_callback_("glUniform2ui", (void*)(ptrdiff_t)glow_glUniform2ui, location, v0, v1);
}
PFNGLUNIFORM2UIPROC glow_debug_glUniform2ui = glow_debug_impl_glUniform2ui;

static void glow_debug_impl_glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glProgramUniform1fv", (void*)(ptrdiff_t)glow_glProgramUniform1fv, program, location, count, value);
  glow_glProgramUniform1fv(program, location, count, value);
  glow_post_callback_("glProgramUniform1fv", (void*)(ptrdiff_t)glow_glProgramUniform1fv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM1FVPROC glow_debug_glProgramUniform1fv = glow_debug_impl_glProgramUniform1fv;

static void glow_debug_impl_glMemoryBarrier(GLbitfield barriers) {

  glow_pre_callback_("glMemoryBarrier", (void*)(ptrdiff_t)glow_glMemoryBarrier, barriers);
  glow_glMemoryBarrier(barriers);
  glow_post_callback_("glMemoryBarrier", (void*)(ptrdiff_t)glow_glMemoryBarrier, barriers);
}
PFNGLMEMORYBARRIERPROC glow_debug_glMemoryBarrier = glow_debug_impl_glMemoryBarrier;

static void glow_debug_impl_glStencilMask(GLuint mask) {

  glow_pre_callback_("glStencilMask", (void*)(ptrdiff_t)glow_glStencilMask, mask);
  glow_glStencilMask(mask);
  glow_post_callback_("glStencilMask", (void*)(ptrdiff_t)glow_glStencilMask, mask);
}
PFNGLSTENCILMASKPROC glow_debug_glStencilMask = glow_debug_impl_glStencilMask;

static void glow_debug_impl_glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) {

  glow_pre_callback_("glDrawElementsInstanced", (void*)(ptrdiff_t)glow_glDrawElementsInstanced, mode, count, type, indices, instancecount);
  glow_glDrawElementsInstanced(mode, count, type, indices, instancecount);
  glow_post_callback_("glDrawElementsInstanced", (void*)(ptrdiff_t)glow_glDrawElementsInstanced, mode, count, type, indices, instancecount);
}
PFNGLDRAWELEMENTSINSTANCEDPROC glow_debug_glDrawElementsInstanced = glow_debug_impl_glDrawElementsInstanced;

static void glow_debug_impl_glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glProgramUniform1iv", (void*)(ptrdiff_t)glow_glProgramUniform1iv, program, location, count, value);
  glow_glProgramUniform1iv(program, location, count, value);
  glow_post_callback_("glProgramUniform1iv", (void*)(ptrdiff_t)glow_glProgramUniform1iv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM1IVPROC glow_debug_glProgramUniform1iv = glow_debug_impl_glProgramUniform1iv;

static void glow_debug_impl_glActiveShaderProgram(GLuint pipeline, GLuint program) {

  glow_pre_callback_("glActiveShaderProgram", (void*)(ptrdiff_t)glow_glActiveShaderProgram, pipeline, program);
  glow_glActiveShaderProgram(pipeline, program);
  glow_post_callback_("glActiveShaderProgram", (void*)(ptrdiff_t)glow_glActiveShaderProgram, pipeline, program);
}
PFNGLACTIVESHADERPROGRAMPROC glow_debug_glActiveShaderProgram = glow_debug_impl_glActiveShaderProgram;

static void glow_debug_impl_glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) {

  glow_pre_callback_("glBindImageTexture", (void*)(ptrdiff_t)glow_glBindImageTexture, unit, texture, level, layered, layer, access, format);
  glow_glBindImageTexture(unit, texture, level, layered, layer, access, format);
  glow_post_callback_("glBindImageTexture", (void*)(ptrdiff_t)glow_glBindImageTexture, unit, texture, level, layered, layer, access, format);
}
PFNGLBINDIMAGETEXTUREPROC glow_debug_glBindImageTexture = glow_debug_impl_glBindImageTexture;

static void glow_debug_impl_glTexParameteriv(GLenum target, GLenum pname, const GLint *params) {

  glow_pre_callback_("glTexParameteriv", (void*)(ptrdiff_t)glow_glTexParameteriv, target, pname, params);
  glow_glTexParameteriv(target, pname, params);
  glow_post_callback_("glTexParameteriv", (void*)(ptrdiff_t)glow_glTexParameteriv, target, pname, params);
}
PFNGLTEXPARAMETERIVPROC glow_debug_glTexParameteriv = glow_debug_impl_glTexParameteriv;

static void glow_debug_impl_glUniform3fv(GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glUniform3fv", (void*)(ptrdiff_t)glow_glUniform3fv, location, count, value);
  glow_glUniform3fv(location, count, value);
  glow_post_callback_("glUniform3fv", (void*)(ptrdiff_t)glow_glUniform3fv, location, count, value);
}
PFNGLUNIFORM3FVPROC glow_debug_glUniform3fv = glow_debug_impl_glUniform3fv;

static void glow_debug_impl_glVertexAttrib1fv(GLuint index, const GLfloat *v) {

  glow_pre_callback_("glVertexAttrib1fv", (void*)(ptrdiff_t)glow_glVertexAttrib1fv, index, v);
  glow_glVertexAttrib1fv(index, v);
  glow_post_callback_("glVertexAttrib1fv", (void*)(ptrdiff_t)glow_glVertexAttrib1fv, index, v);
}
PFNGLVERTEXATTRIB1FVPROC glow_debug_glVertexAttrib1fv = glow_debug_impl_glVertexAttrib1fv;

static void glow_debug_impl_glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetFramebufferParameteriv", (void*)(ptrdiff_t)glow_glGetFramebufferParameteriv, target, pname, params);
  glow_glGetFramebufferParameteriv(target, pname, params);
  glow_post_callback_("glGetFramebufferParameteriv", (void*)(ptrdiff_t)glow_glGetFramebufferParameteriv, target, pname, params);
}
PFNGLGETFRAMEBUFFERPARAMETERIVPROC glow_debug_glGetFramebufferParameteriv = glow_debug_impl_glGetFramebufferParameteriv;

static void glow_debug_impl_glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) {

  glow_pre_callback_("glProgramUniform3uiv", (void*)(ptrdiff_t)glow_glProgramUniform3uiv, program, location, count, value);
  glow_glProgramUniform3uiv(program, location, count, value);
  glow_post_callback_("glProgramUniform3uiv", (void*)(ptrdiff_t)glow_glProgramUniform3uiv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM3UIVPROC glow_debug_glProgramUniform3uiv = glow_debug_impl_glProgramUniform3uiv;

static void glow_debug_impl_glBlendBarrier() {

  glow_pre_callback_("glBlendBarrier", (void*)(ptrdiff_t)glow_glBlendBarrier);
  glow_glBlendBarrier();
  glow_post_callback_("glBlendBarrier", (void*)(ptrdiff_t)glow_glBlendBarrier);
}
PFNGLBLENDBARRIERPROC glow_debug_glBlendBarrier = glow_debug_impl_glBlendBarrier;

static void glow_debug_impl_glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {

  glow_pre_callback_("glTexStorage3DMultisample", (void*)(ptrdiff_t)glow_glTexStorage3DMultisample, target, samples, internalformat, width, height, depth, fixedsamplelocations);
  glow_glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
  glow_post_callback_("glTexStorage3DMultisample", (void*)(ptrdiff_t)glow_glTexStorage3DMultisample, target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
PFNGLTEXSTORAGE3DMULTISAMPLEPROC glow_debug_glTexStorage3DMultisample = glow_debug_impl_glTexStorage3DMultisample;

static void glow_debug_impl_glUniform2fv(GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glUniform2fv", (void*)(ptrdiff_t)glow_glUniform2fv, location, count, value);
  glow_glUniform2fv(location, count, value);
  glow_post_callback_("glUniform2fv", (void*)(ptrdiff_t)glow_glUniform2fv, location, count, value);
}
PFNGLUNIFORM2FVPROC glow_debug_glUniform2fv = glow_debug_impl_glUniform2fv;

static void glow_debug_impl_glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix2x3fv", (void*)(ptrdiff_t)glow_glUniformMatrix2x3fv, location, count, transpose, value);
  glow_glUniformMatrix2x3fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix2x3fv", (void*)(ptrdiff_t)glow_glUniformMatrix2x3fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X3FVPROC glow_debug_glUniformMatrix2x3fv = glow_debug_impl_glUniformMatrix2x3fv;

static GLboolean glow_debug_impl_glIsSync(GLsync sync) {

  GLboolean ret;
  glow_pre_callback_("glIsSync", (void*)(ptrdiff_t)glow_glIsSync, sync);
  ret = glow_glIsSync(sync);
  glow_post_callback_("glIsSync", (void*)(ptrdiff_t)glow_glIsSync, sync);
  return ret;
}
PFNGLISSYNCPROC glow_debug_glIsSync = glow_debug_impl_glIsSync;

static void glow_debug_impl_glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value) {

  glow_pre_callback_("glClearBufferiv", (void*)(ptrdiff_t)glow_glClearBufferiv, buffer, drawbuffer, value);
  glow_glClearBufferiv(buffer, drawbuffer, value);
  glow_post_callback_("glClearBufferiv", (void*)(ptrdiff_t)glow_glClearBufferiv, buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERIVPROC glow_debug_glClearBufferiv = glow_debug_impl_glClearBufferiv;

static void glow_debug_impl_glGetBooleani_v(GLenum target, GLuint index, GLboolean *data) {

  glow_pre_callback_("glGetBooleani_v", (void*)(ptrdiff_t)glow_glGetBooleani_v, target, index, data);
  glow_glGetBooleani_v(target, index, data);
  glow_post_callback_("glGetBooleani_v", (void*)(ptrdiff_t)glow_glGetBooleani_v, target, index, data);
}
PFNGLGETBOOLEANI_VPROC glow_debug_glGetBooleani_v = glow_debug_impl_glGetBooleani_v;

static void glow_debug_impl_glGenTextures(GLsizei n, GLuint *textures) {

  glow_pre_callback_("glGenTextures", (void*)(ptrdiff_t)glow_glGenTextures, n, textures);
  glow_glGenTextures(n, textures);
  glow_post_callback_("glGenTextures", (void*)(ptrdiff_t)glow_glGenTextures, n, textures);
}
PFNGLGENTEXTURESPROC glow_debug_glGenTextures = glow_debug_impl_glGenTextures;

static GLboolean glow_debug_impl_glIsShader(GLuint shader) {

  GLboolean ret;
  glow_pre_callback_("glIsShader", (void*)(ptrdiff_t)glow_glIsShader, shader);
  ret = glow_glIsShader(shader);
  glow_post_callback_("glIsShader", (void*)(ptrdiff_t)glow_glIsShader, shader);
  return ret;
}
PFNGLISSHADERPROC glow_debug_glIsShader = glow_debug_impl_glIsShader;

static void glow_debug_impl_glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) {

  glow_pre_callback_("glDrawRangeElements", (void*)(ptrdiff_t)glow_glDrawRangeElements, mode, start, end, count, type, indices);
  glow_glDrawRangeElements(mode, start, end, count, type, indices);
  glow_post_callback_("glDrawRangeElements", (void*)(ptrdiff_t)glow_glDrawRangeElements, mode, start, end, count, type, indices);
}
PFNGLDRAWRANGEELEMENTSPROC glow_debug_glDrawRangeElements = glow_debug_impl_glDrawRangeElements;

static GLboolean glow_debug_impl_glIsBuffer(GLuint buffer) {

  GLboolean ret;
  glow_pre_callback_("glIsBuffer", (void*)(ptrdiff_t)glow_glIsBuffer, buffer);
  ret = glow_glIsBuffer(buffer);
  glow_post_callback_("glIsBuffer", (void*)(ptrdiff_t)glow_glIsBuffer, buffer);
  return ret;
}
PFNGLISBUFFERPROC glow_debug_glIsBuffer = glow_debug_impl_glIsBuffer;

static void glow_debug_impl_glUseProgram(GLuint program) {

  glow_pre_callback_("glUseProgram", (void*)(ptrdiff_t)glow_glUseProgram, program);
  glow_glUseProgram(program);
  glow_post_callback_("glUseProgram", (void*)(ptrdiff_t)glow_glUseProgram, program);
}
PFNGLUSEPROGRAMPROC glow_debug_glUseProgram = glow_debug_impl_glUseProgram;

static GLuint glow_debug_impl_glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) {

  GLuint ret;
  glow_pre_callback_("glGetUniformBlockIndex", (void*)(ptrdiff_t)glow_glGetUniformBlockIndex, program, uniformBlockName);
  ret = glow_glGetUniformBlockIndex(program, uniformBlockName);
  glow_post_callback_("glGetUniformBlockIndex", (void*)(ptrdiff_t)glow_glGetUniformBlockIndex, program, uniformBlockName);
  return ret;
}
PFNGLGETUNIFORMBLOCKINDEXPROC glow_debug_glGetUniformBlockIndex = glow_debug_impl_glGetUniformBlockIndex;

static void glow_debug_impl_glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params) {

  glow_pre_callback_("glGetInternalformativ", (void*)(ptrdiff_t)glow_glGetInternalformativ, target, internalformat, pname, bufSize, params);
  glow_glGetInternalformativ(target, internalformat, pname, bufSize, params);
  glow_post_callback_("glGetInternalformativ", (void*)(ptrdiff_t)glow_glGetInternalformativ, target, internalformat, pname, bufSize, params);
}
PFNGLGETINTERNALFORMATIVPROC glow_debug_glGetInternalformativ = glow_debug_impl_glGetInternalformativ;

static void glow_debug_impl_glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glProgramUniformMatrix4x2fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix4x2fv, program, location, count, transpose, value);
  glow_glProgramUniformMatrix4x2fv(program, location, count, transpose, value);
  glow_post_callback_("glProgramUniformMatrix4x2fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix4x2fv, program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glow_debug_glProgramUniformMatrix4x2fv = glow_debug_impl_glProgramUniformMatrix4x2fv;

static void glow_debug_impl_glClear(GLbitfield mask) {

  glow_pre_callback_("glClear", (void*)(ptrdiff_t)glow_glClear, mask);
  glow_glClear(mask);
  glow_post_callback_("glClear", (void*)(ptrdiff_t)glow_glClear, mask);
}
PFNGLCLEARPROC glow_debug_glClear = glow_debug_impl_glClear;

static void glow_debug_impl_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) {

  glow_pre_callback_("glCompressedTexSubImage2D", (void*)(ptrdiff_t)glow_glCompressedTexSubImage2D, target, level, xoffset, yoffset, width, height, format, imageSize, data);
  glow_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
  glow_post_callback_("glCompressedTexSubImage2D", (void*)(ptrdiff_t)glow_glCompressedTexSubImage2D, target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glow_debug_glCompressedTexSubImage2D = glow_debug_impl_glCompressedTexSubImage2D;

static void glow_debug_impl_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {

  glow_pre_callback_("glFramebufferTexture2D", (void*)(ptrdiff_t)glow_glFramebufferTexture2D, target, attachment, textarget, texture, level);
  glow_glFramebufferTexture2D(target, attachment, textarget, texture, level);
  glow_post_callback_("glFramebufferTexture2D", (void*)(ptrdiff_t)glow_glFramebufferTexture2D, target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE2DPROC glow_debug_glFramebufferTexture2D = glow_debug_impl_glFramebufferTexture2D;

static void glow_debug_impl_glValidateProgramPipeline(GLuint pipeline) {

  glow_pre_callback_("glValidateProgramPipeline", (void*)(ptrdiff_t)glow_glValidateProgramPipeline, pipeline);
  glow_glValidateProgramPipeline(pipeline);
  glow_post_callback_("glValidateProgramPipeline", (void*)(ptrdiff_t)glow_glValidateProgramPipeline, pipeline);
}
PFNGLVALIDATEPROGRAMPIPELINEPROC glow_debug_glValidateProgramPipeline = glow_debug_impl_glValidateProgramPipeline;

static void glow_debug_impl_glTexParameterIiv(GLenum target, GLenum pname, const GLint *params) {

  glow_pre_callback_("glTexParameterIiv", (void*)(ptrdiff_t)glow_glTexParameterIiv, target, pname, params);
  glow_glTexParameterIiv(target, pname, params);
  glow_post_callback_("glTexParameterIiv", (void*)(ptrdiff_t)glow_glTexParameterIiv, target, pname, params);
}
PFNGLTEXPARAMETERIIVPROC glow_debug_glTexParameterIiv = glow_debug_impl_glTexParameterIiv;

static void glow_debug_impl_glProgramUniform1i(GLuint program, GLint location, GLint v0) {

  glow_pre_callback_("glProgramUniform1i", (void*)(ptrdiff_t)glow_glProgramUniform1i, program, location, v0);
  glow_glProgramUniform1i(program, location, v0);
  glow_post_callback_("glProgramUniform1i", (void*)(ptrdiff_t)glow_glProgramUniform1i, program, location, v0);
}
PFNGLPROGRAMUNIFORM1IPROC glow_debug_glProgramUniform1i = glow_debug_impl_glProgramUniform1i;

static void glow_debug_impl_glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) {

  glow_pre_callback_("glReadnPixels", (void*)(ptrdiff_t)glow_glReadnPixels, x, y, width, height, format, type, bufSize, data);
  glow_glReadnPixels(x, y, width, height, format, type, bufSize, data);
  glow_post_callback_("glReadnPixels", (void*)(ptrdiff_t)glow_glReadnPixels, x, y, width, height, format, type, bufSize, data);
}
PFNGLREADNPIXELSPROC glow_debug_glReadnPixels = glow_debug_impl_glReadnPixels;

static void glow_debug_impl_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {

  glow_pre_callback_("glGetActiveUniform", (void*)(ptrdiff_t)glow_glGetActiveUniform, program, index, bufSize, length, size, type, name);
  glow_glGetActiveUniform(program, index, bufSize, length, size, type, name);
  glow_post_callback_("glGetActiveUniform", (void*)(ptrdiff_t)glow_glGetActiveUniform, program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEUNIFORMPROC glow_debug_glGetActiveUniform = glow_debug_impl_glGetActiveUniform;

static void glow_debug_impl_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {

  glow_pre_callback_("glVertexAttribPointer", (void*)(ptrdiff_t)glow_glVertexAttribPointer, index, size, type, normalized, stride, pointer);
  glow_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
  glow_post_callback_("glVertexAttribPointer", (void*)(ptrdiff_t)glow_glVertexAttribPointer, index, size, type, normalized, stride, pointer);
}
PFNGLVERTEXATTRIBPOINTERPROC glow_debug_glVertexAttribPointer = glow_debug_impl_glVertexAttribPointer;

static void glow_debug_impl_glBindProgramPipeline(GLuint pipeline) {

  glow_pre_callback_("glBindProgramPipeline", (void*)(ptrdiff_t)glow_glBindProgramPipeline, pipeline);
  glow_glBindProgramPipeline(pipeline);
  glow_post_callback_("glBindProgramPipeline", (void*)(ptrdiff_t)glow_glBindProgramPipeline, pipeline);
}
PFNGLBINDPROGRAMPIPELINEPROC glow_debug_glBindProgramPipeline = glow_debug_impl_glBindProgramPipeline;

static void glow_debug_impl_glUniform2i(GLint location, GLint v0, GLint v1) {

  glow_pre_callback_("glUniform2i", (void*)(ptrdiff_t)glow_glUniform2i, location, v0, v1);
  glow_glUniform2i(location, v0, v1);
  glow_post_callback_("glUniform2i", (void*)(ptrdiff_t)glow_glUniform2i, location, v0, v1);
}
PFNGLUNIFORM2IPROC glow_debug_glUniform2i = glow_debug_impl_glUniform2i;

static void * glow_debug_impl_glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {

  void * ret;
  glow_pre_callback_("glMapBufferRange", (void*)(ptrdiff_t)glow_glMapBufferRange, target, offset, length, access);
  ret = glow_glMapBufferRange(target, offset, length, access);
  glow_post_callback_("glMapBufferRange", (void*)(ptrdiff_t)glow_glMapBufferRange, target, offset, length, access);
  return ret;
}
PFNGLMAPBUFFERRANGEPROC glow_debug_glMapBufferRange = glow_debug_impl_glMapBufferRange;

static void glow_debug_impl_glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetVertexAttribIiv", (void*)(ptrdiff_t)glow_glGetVertexAttribIiv, index, pname, params);
  glow_glGetVertexAttribIiv(index, pname, params);
  glow_post_callback_("glGetVertexAttribIiv", (void*)(ptrdiff_t)glow_glGetVertexAttribIiv, index, pname, params);
}
PFNGLGETVERTEXATTRIBIIVPROC glow_debug_glGetVertexAttribIiv = glow_debug_impl_glGetVertexAttribIiv;

static void glow_debug_impl_glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {

  glow_pre_callback_("glTexStorage2D", (void*)(ptrdiff_t)glow_glTexStorage2D, target, levels, internalformat, width, height);
  glow_glTexStorage2D(target, levels, internalformat, width, height);
  glow_post_callback_("glTexStorage2D", (void*)(ptrdiff_t)glow_glTexStorage2D, target, levels, internalformat, width, height);
}
PFNGLTEXSTORAGE2DPROC glow_debug_glTexStorage2D = glow_debug_impl_glTexStorage2D;

static void glow_debug_impl_glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params) {

  glow_pre_callback_("glGetnUniformuiv", (void*)(ptrdiff_t)glow_glGetnUniformuiv, program, location, bufSize, params);
  glow_glGetnUniformuiv(program, location, bufSize, params);
  glow_post_callback_("glGetnUniformuiv", (void*)(ptrdiff_t)glow_glGetnUniformuiv, program, location, bufSize, params);
}
PFNGLGETNUNIFORMUIVPROC glow_debug_glGetnUniformuiv = glow_debug_impl_glGetnUniformuiv;

static GLenum glow_debug_impl_glCheckFramebufferStatus(GLenum target) {

  GLenum ret;
  glow_pre_callback_("glCheckFramebufferStatus", (void*)(ptrdiff_t)glow_glCheckFramebufferStatus, target);
  ret = glow_glCheckFramebufferStatus(target);
  glow_post_callback_("glCheckFramebufferStatus", (void*)(ptrdiff_t)glow_glCheckFramebufferStatus, target);
  return ret;
}
PFNGLCHECKFRAMEBUFFERSTATUSPROC glow_debug_glCheckFramebufferStatus = glow_debug_impl_glCheckFramebufferStatus;

static void glow_debug_impl_glClearDepthf(GLfloat d) {

  glow_pre_callback_("glClearDepthf", (void*)(ptrdiff_t)glow_glClearDepthf, d);
  glow_glClearDepthf(d);
  glow_post_callback_("glClearDepthf", (void*)(ptrdiff_t)glow_glClearDepthf, d);
}
PFNGLCLEARDEPTHFPROC glow_debug_glClearDepthf = glow_debug_impl_glClearDepthf;

static void glow_debug_impl_glGetProgramiv(GLuint program, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetProgramiv", (void*)(ptrdiff_t)glow_glGetProgramiv, program, pname, params);
  glow_glGetProgramiv(program, pname, params);
  glow_post_callback_("glGetProgramiv", (void*)(ptrdiff_t)glow_glGetProgramiv, program, pname, params);
}
PFNGLGETPROGRAMIVPROC glow_debug_glGetProgramiv = glow_debug_impl_glGetProgramiv;

static void glow_debug_impl_glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param) {

  glow_pre_callback_("glSamplerParameterIuiv", (void*)(ptrdiff_t)glow_glSamplerParameterIuiv, sampler, pname, param);
  glow_glSamplerParameterIuiv(sampler, pname, param);
  glow_post_callback_("glSamplerParameterIuiv", (void*)(ptrdiff_t)glow_glSamplerParameterIuiv, sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIUIVPROC glow_debug_glSamplerParameterIuiv = glow_debug_impl_glSamplerParameterIuiv;

static void glow_debug_impl_glVertexAttrib1f(GLuint index, GLfloat x) {

  glow_pre_callback_("glVertexAttrib1f", (void*)(ptrdiff_t)glow_glVertexAttrib1f, index, x);
  glow_glVertexAttrib1f(index, x);
  glow_post_callback_("glVertexAttrib1f", (void*)(ptrdiff_t)glow_glVertexAttrib1f, index, x);
}
PFNGLVERTEXATTRIB1FPROC glow_debug_glVertexAttrib1f = glow_debug_impl_glVertexAttrib1f;

static void glow_debug_impl_glBindVertexArray(GLuint array) {

  glow_pre_callback_("glBindVertexArray", (void*)(ptrdiff_t)glow_glBindVertexArray, array);
  glow_glBindVertexArray(array);
  glow_post_callback_("glBindVertexArray", (void*)(ptrdiff_t)glow_glBindVertexArray, array);
}
PFNGLBINDVERTEXARRAYPROC glow_debug_glBindVertexArray = glow_debug_impl_glBindVertexArray;

static void glow_debug_impl_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) {

  glow_pre_callback_("glReadPixels", (void*)(ptrdiff_t)glow_glReadPixels, x, y, width, height, format, type, pixels);
  glow_glReadPixels(x, y, width, height, format, type, pixels);
  glow_post_callback_("glReadPixels", (void*)(ptrdiff_t)glow_glReadPixels, x, y, width, height, format, type, pixels);
}
PFNGLREADPIXELSPROC glow_debug_glReadPixels = glow_debug_impl_glReadPixels;

static void glow_debug_impl_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glTexSubImage2D", (void*)(ptrdiff_t)glow_glTexSubImage2D, target, level, xoffset, yoffset, width, height, format, type, pixels);
  glow_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
  glow_post_callback_("glTexSubImage2D", (void*)(ptrdiff_t)glow_glTexSubImage2D, target, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLTEXSUBIMAGE2DPROC glow_debug_glTexSubImage2D = glow_debug_impl_glTexSubImage2D;

static void glow_debug_impl_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix4fv", (void*)(ptrdiff_t)glow_glUniformMatrix4fv, location, count, transpose, value);
  glow_glUniformMatrix4fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix4fv", (void*)(ptrdiff_t)glow_glUniformMatrix4fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4FVPROC glow_debug_glUniformMatrix4fv = glow_debug_impl_glUniformMatrix4fv;

static void glow_debug_impl_glStencilMaskSeparate(GLenum face, GLuint mask) {

  glow_pre_callback_("glStencilMaskSeparate", (void*)(ptrdiff_t)glow_glStencilMaskSeparate, face, mask);
  glow_glStencilMaskSeparate(face, mask);
  glow_post_callback_("glStencilMaskSeparate", (void*)(ptrdiff_t)glow_glStencilMaskSeparate, face, mask);
}
PFNGLSTENCILMASKSEPARATEPROC glow_debug_glStencilMaskSeparate = glow_debug_impl_glStencilMaskSeparate;

static void glow_debug_impl_glGenQueries(GLsizei n, GLuint *ids) {

  glow_pre_callback_("glGenQueries", (void*)(ptrdiff_t)glow_glGenQueries, n, ids);
  glow_glGenQueries(n, ids);
  glow_post_callback_("glGenQueries", (void*)(ptrdiff_t)glow_glGenQueries, n, ids);
}
PFNGLGENQUERIESPROC glow_debug_glGenQueries = glow_debug_impl_glGenQueries;

static void glow_debug_impl_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {

  glow_pre_callback_("glRenderbufferStorageMultisample", (void*)(ptrdiff_t)glow_glRenderbufferStorageMultisample, target, samples, internalformat, width, height);
  glow_glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
  glow_post_callback_("glRenderbufferStorageMultisample", (void*)(ptrdiff_t)glow_glRenderbufferStorageMultisample, target, samples, internalformat, width, height);
}
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glow_debug_glRenderbufferStorageMultisample = glow_debug_impl_glRenderbufferStorageMultisample;

static void glow_debug_impl_glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect) {

  glow_pre_callback_("glDrawElementsIndirect", (void*)(ptrdiff_t)glow_glDrawElementsIndirect, mode, type, indirect);
  glow_glDrawElementsIndirect(mode, type, indirect);
  glow_post_callback_("glDrawElementsIndirect", (void*)(ptrdiff_t)glow_glDrawElementsIndirect, mode, type, indirect);
}
PFNGLDRAWELEMENTSINDIRECTPROC glow_debug_glDrawElementsIndirect = glow_debug_impl_glDrawElementsIndirect;

static void glow_debug_impl_glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params) {

  glow_pre_callback_("glGetnUniformfv", (void*)(ptrdiff_t)glow_glGetnUniformfv, program, location, bufSize, params);
  glow_glGetnUniformfv(program, location, bufSize, params);
  glow_post_callback_("glGetnUniformfv", (void*)(ptrdiff_t)glow_glGetnUniformfv, program, location, bufSize, params);
}
PFNGLGETNUNIFORMFVPROC glow_debug_glGetnUniformfv = glow_debug_impl_glGetnUniformfv;

static void glow_debug_impl_glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) {

  glow_pre_callback_("glDispatchCompute", (void*)(ptrdiff_t)glow_glDispatchCompute, num_groups_x, num_groups_y, num_groups_z);
  glow_glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
  glow_post_callback_("glDispatchCompute", (void*)(ptrdiff_t)glow_glDispatchCompute, num_groups_x, num_groups_y, num_groups_z);
}
PFNGLDISPATCHCOMPUTEPROC glow_debug_glDispatchCompute = glow_debug_impl_glDispatchCompute;

static void glow_debug_impl_glProgramUniform1ui(GLuint program, GLint location, GLuint v0) {

  glow_pre_callback_("glProgramUniform1ui", (void*)(ptrdiff_t)glow_glProgramUniform1ui, program, location, v0);
  glow_glProgramUniform1ui(program, location, v0);
  glow_post_callback_("glProgramUniform1ui", (void*)(ptrdiff_t)glow_glProgramUniform1ui, program, location, v0);
}
PFNGLPROGRAMUNIFORM1UIPROC glow_debug_glProgramUniform1ui = glow_debug_impl_glProgramUniform1ui;

static GLboolean glow_debug_impl_glIsEnabledi(GLenum target, GLuint index) {

  GLboolean ret;
  glow_pre_callback_("glIsEnabledi", (void*)(ptrdiff_t)glow_glIsEnabledi, target, index);
  ret = glow_glIsEnabledi(target, index);
  glow_post_callback_("glIsEnabledi", (void*)(ptrdiff_t)glow_glIsEnabledi, target, index);
  return ret;
}
PFNGLISENABLEDIPROC glow_debug_glIsEnabledi = glow_debug_impl_glIsEnabledi;

static void glow_debug_impl_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {

  glow_pre_callback_("glRenderbufferStorage", (void*)(ptrdiff_t)glow_glRenderbufferStorage, target, internalformat, width, height);
  glow_glRenderbufferStorage(target, internalformat, width, height);
  glow_post_callback_("glRenderbufferStorage", (void*)(ptrdiff_t)glow_glRenderbufferStorage, target, internalformat, width, height);
}
PFNGLRENDERBUFFERSTORAGEPROC glow_debug_glRenderbufferStorage = glow_debug_impl_glRenderbufferStorage;

static void glow_debug_impl_glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {

  glow_pre_callback_("glVertexAttribI4ui", (void*)(ptrdiff_t)glow_glVertexAttribI4ui, index, x, y, z, w);
  glow_glVertexAttribI4ui(index, x, y, z, w);
  glow_post_callback_("glVertexAttribI4ui", (void*)(ptrdiff_t)glow_glVertexAttribI4ui, index, x, y, z, w);
}
PFNGLVERTEXATTRIBI4UIPROC glow_debug_glVertexAttribI4ui = glow_debug_impl_glVertexAttribI4ui;

static void glow_debug_impl_glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) {

  glow_pre_callback_("glSamplerParameteri", (void*)(ptrdiff_t)glow_glSamplerParameteri, sampler, pname, param);
  glow_glSamplerParameteri(sampler, pname, param);
  glow_post_callback_("glSamplerParameteri", (void*)(ptrdiff_t)glow_glSamplerParameteri, sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIPROC glow_debug_glSamplerParameteri = glow_debug_impl_glSamplerParameteri;

static void glow_debug_impl_glDepthMask(GLboolean flag) {

  glow_pre_callback_("glDepthMask", (void*)(ptrdiff_t)glow_glDepthMask, flag);
  glow_glDepthMask(flag);
  glow_post_callback_("glDepthMask", (void*)(ptrdiff_t)glow_glDepthMask, flag);
}
PFNGLDEPTHMASKPROC glow_debug_glDepthMask = glow_debug_impl_glDepthMask;

static GLboolean glow_debug_impl_glIsProgram(GLuint program) {

  GLboolean ret;
  glow_pre_callback_("glIsProgram", (void*)(ptrdiff_t)glow_glIsProgram, program);
  ret = glow_glIsProgram(program);
  glow_post_callback_("glIsProgram", (void*)(ptrdiff_t)glow_glIsProgram, program);
  return ret;
}
PFNGLISPROGRAMPROC glow_debug_glIsProgram = glow_debug_impl_glIsProgram;

static void glow_debug_impl_glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) {

  glow_pre_callback_("glProgramUniform2i", (void*)(ptrdiff_t)glow_glProgramUniform2i, program, location, v0, v1);
  glow_glProgramUniform2i(program, location, v0, v1);
  glow_post_callback_("glProgramUniform2i", (void*)(ptrdiff_t)glow_glProgramUniform2i, program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2IPROC glow_debug_glProgramUniform2i = glow_debug_impl_glProgramUniform2i;

static void glow_debug_impl_glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glProgramUniform4fv", (void*)(ptrdiff_t)glow_glProgramUniform4fv, program, location, count, value);
  glow_glProgramUniform4fv(program, location, count, value);
  glow_post_callback_("glProgramUniform4fv", (void*)(ptrdiff_t)glow_glProgramUniform4fv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM4FVPROC glow_debug_glProgramUniform4fv = glow_debug_impl_glProgramUniform4fv;

static void glow_debug_impl_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glScissor", (void*)(ptrdiff_t)glow_glScissor, x, y, width, height);
  glow_glScissor(x, y, width, height);
  glow_post_callback_("glScissor", (void*)(ptrdiff_t)glow_glScissor, x, y, width, height);
}
PFNGLSCISSORPROC glow_debug_glScissor = glow_debug_impl_glScissor;

static GLuint glow_debug_impl_glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name) {

  GLuint ret;
  glow_pre_callback_("glGetProgramResourceIndex", (void*)(ptrdiff_t)glow_glGetProgramResourceIndex, program, programInterface, name);
  ret = glow_glGetProgramResourceIndex(program, programInterface, name);
  glow_post_callback_("glGetProgramResourceIndex", (void*)(ptrdiff_t)glow_glGetProgramResourceIndex, program, programInterface, name);
  return ret;
}
PFNGLGETPROGRAMRESOURCEINDEXPROC glow_debug_glGetProgramResourceIndex = glow_debug_impl_glGetProgramResourceIndex;

static void glow_debug_impl_glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {

  glow_pre_callback_("glProgramUniform3i", (void*)(ptrdiff_t)glow_glProgramUniform3i, program, location, v0, v1, v2);
  glow_glProgramUniform3i(program, location, v0, v1, v2);
  glow_post_callback_("glProgramUniform3i", (void*)(ptrdiff_t)glow_glProgramUniform3i, program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3IPROC glow_debug_glProgramUniform3i = glow_debug_impl_glProgramUniform3i;

static void glow_debug_impl_glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix2x4fv", (void*)(ptrdiff_t)glow_glUniformMatrix2x4fv, location, count, transpose, value);
  glow_glUniformMatrix2x4fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix2x4fv", (void*)(ptrdiff_t)glow_glUniformMatrix2x4fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X4FVPROC glow_debug_glUniformMatrix2x4fv = glow_debug_impl_glUniformMatrix2x4fv;

static void glow_debug_impl_glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) {

  glow_pre_callback_("glDrawRangeElementsBaseVertex", (void*)(ptrdiff_t)glow_glDrawRangeElementsBaseVertex, mode, start, end, count, type, indices, basevertex);
  glow_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
  glow_post_callback_("glDrawRangeElementsBaseVertex", (void*)(ptrdiff_t)glow_glDrawRangeElementsBaseVertex, mode, start, end, count, type, indices, basevertex);
}
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glow_debug_glDrawRangeElementsBaseVertex = glow_debug_impl_glDrawRangeElementsBaseVertex;

static void glow_debug_impl_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {

  glow_pre_callback_("glUniform4f", (void*)(ptrdiff_t)glow_glUniform4f, location, v0, v1, v2, v3);
  glow_glUniform4f(location, v0, v1, v2, v3);
  glow_post_callback_("glUniform4f", (void*)(ptrdiff_t)glow_glUniform4f, location, v0, v1, v2, v3);
}
PFNGLUNIFORM4FPROC glow_debug_glUniform4f = glow_debug_impl_glUniform4f;

static void glow_debug_impl_glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) {

  glow_pre_callback_("glFlushMappedBufferRange", (void*)(ptrdiff_t)glow_glFlushMappedBufferRange, target, offset, length);
  glow_glFlushMappedBufferRange(target, offset, length);
  glow_post_callback_("glFlushMappedBufferRange", (void*)(ptrdiff_t)glow_glFlushMappedBufferRange, target, offset, length);
}
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glow_debug_glFlushMappedBufferRange = glow_debug_impl_glFlushMappedBufferRange;

static GLboolean glow_debug_impl_glIsSampler(GLuint sampler) {

  GLboolean ret;
  glow_pre_callback_("glIsSampler", (void*)(ptrdiff_t)glow_glIsSampler, sampler);
  ret = glow_glIsSampler(sampler);
  glow_post_callback_("glIsSampler", (void*)(ptrdiff_t)glow_glIsSampler, sampler);
  return ret;
}
PFNGLISSAMPLERPROC glow_debug_glIsSampler = glow_debug_impl_glIsSampler;

static void glow_debug_impl_glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) {

  glow_pre_callback_("glProgramBinary", (void*)(ptrdiff_t)glow_glProgramBinary, program, binaryFormat, binary, length);
  glow_glProgramBinary(program, binaryFormat, binary, length);
  glow_post_callback_("glProgramBinary", (void*)(ptrdiff_t)glow_glProgramBinary, program, binaryFormat, binary, length);
}
PFNGLPROGRAMBINARYPROC glow_debug_glProgramBinary = glow_debug_impl_glProgramBinary;

static GLuint glow_debug_impl_glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings) {

  GLuint ret;
  glow_pre_callback_("glCreateShaderProgramv", (void*)(ptrdiff_t)glow_glCreateShaderProgramv, type, count, strings);
  ret = glow_glCreateShaderProgramv(type, count, strings);
  glow_post_callback_("glCreateShaderProgramv", (void*)(ptrdiff_t)glow_glCreateShaderProgramv, type, count, strings);
  return ret;
}
PFNGLCREATESHADERPROGRAMVPROC glow_debug_glCreateShaderProgramv = glow_debug_impl_glCreateShaderProgramv;

static void glow_debug_impl_glBindTexture(GLenum target, GLuint texture) {

  glow_pre_callback_("glBindTexture", (void*)(ptrdiff_t)glow_glBindTexture, target, texture);
  glow_glBindTexture(target, texture);
  glow_post_callback_("glBindTexture", (void*)(ptrdiff_t)glow_glBindTexture, target, texture);
}
PFNGLBINDTEXTUREPROC glow_debug_glBindTexture = glow_debug_impl_glBindTexture;

static void glow_debug_impl_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) {

  glow_pre_callback_("glGenRenderbuffers", (void*)(ptrdiff_t)glow_glGenRenderbuffers, n, renderbuffers);
  glow_glGenRenderbuffers(n, renderbuffers);
  glow_post_callback_("glGenRenderbuffers", (void*)(ptrdiff_t)glow_glGenRenderbuffers, n, renderbuffers);
}
PFNGLGENRENDERBUFFERSPROC glow_debug_glGenRenderbuffers = glow_debug_impl_glGenRenderbuffers;

static void glow_debug_impl_glUniform1iv(GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glUniform1iv", (void*)(ptrdiff_t)glow_glUniform1iv, location, count, value);
  glow_glUniform1iv(location, count, value);
  glow_post_callback_("glUniform1iv", (void*)(ptrdiff_t)glow_glUniform1iv, location, count, value);
}
PFNGLUNIFORM1IVPROC glow_debug_glUniform1iv = glow_debug_impl_glUniform1iv;

static void glow_debug_impl_glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {

  glow_pre_callback_("glColorMaski", (void*)(ptrdiff_t)glow_glColorMaski, index, r, g, b, a);
  glow_glColorMaski(index, r, g, b, a);
  glow_post_callback_("glColorMaski", (void*)(ptrdiff_t)glow_glColorMaski, index, r, g, b, a);
}
PFNGLCOLORMASKIPROC glow_debug_glColorMaski = glow_debug_impl_glColorMaski;

static void glow_debug_impl_glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) {

  glow_pre_callback_("glVertexAttribIPointer", (void*)(ptrdiff_t)glow_glVertexAttribIPointer, index, size, type, stride, pointer);
  glow_glVertexAttribIPointer(index, size, type, stride, pointer);
  glow_post_callback_("glVertexAttribIPointer", (void*)(ptrdiff_t)glow_glVertexAttribIPointer, index, size, type, stride, pointer);
}
PFNGLVERTEXATTRIBIPOINTERPROC glow_debug_glVertexAttribIPointer = glow_debug_impl_glVertexAttribIPointer;

static void glow_debug_impl_glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {

  glow_pre_callback_("glUniformBlockBinding", (void*)(ptrdiff_t)glow_glUniformBlockBinding, program, uniformBlockIndex, uniformBlockBinding);
  glow_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
  glow_post_callback_("glUniformBlockBinding", (void*)(ptrdiff_t)glow_glUniformBlockBinding, program, uniformBlockIndex, uniformBlockBinding);
}
PFNGLUNIFORMBLOCKBINDINGPROC glow_debug_glUniformBlockBinding = glow_debug_impl_glUniformBlockBinding;

static void glow_debug_impl_glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glProgramUniformMatrix3x4fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix3x4fv, program, location, count, transpose, value);
  glow_glProgramUniformMatrix3x4fv(program, location, count, transpose, value);
  glow_post_callback_("glProgramUniformMatrix3x4fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix3x4fv, program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glow_debug_glProgramUniformMatrix3x4fv = glow_debug_impl_glProgramUniformMatrix3x4fv;

static void glow_debug_impl_glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam) {

  glow_pre_callback_("glDebugMessageCallback", (void*)(ptrdiff_t)glow_glDebugMessageCallback, callback, userParam);
  glow_glDebugMessageCallback(callback, userParam);
  glow_post_callback_("glDebugMessageCallback", (void*)(ptrdiff_t)glow_glDebugMessageCallback, callback, userParam);
}
PFNGLDEBUGMESSAGECALLBACKPROC glow_debug_glDebugMessageCallback = glow_debug_impl_glDebugMessageCallback;

static void glow_debug_impl_glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param) {

  glow_pre_callback_("glSamplerParameterIiv", (void*)(ptrdiff_t)glow_glSamplerParameterIiv, sampler, pname, param);
  glow_glSamplerParameterIiv(sampler, pname, param);
  glow_post_callback_("glSamplerParameterIiv", (void*)(ptrdiff_t)glow_glSamplerParameterIiv, sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIIVPROC glow_debug_glSamplerParameterIiv = glow_debug_impl_glSamplerParameterIiv;

static void glow_debug_impl_glCompileShader(GLuint shader) {

  glow_pre_callback_("glCompileShader", (void*)(ptrdiff_t)glow_glCompileShader, shader);
  glow_glCompileShader(shader);
  glow_post_callback_("glCompileShader", (void*)(ptrdiff_t)glow_glCompileShader, shader);
}
PFNGLCOMPILESHADERPROC glow_debug_glCompileShader = glow_debug_impl_glCompileShader;

static void glow_debug_impl_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {

  glow_pre_callback_("glTexParameterf", (void*)(ptrdiff_t)glow_glTexParameterf, target, pname, param);
  glow_glTexParameterf(target, pname, param);
  glow_post_callback_("glTexParameterf", (void*)(ptrdiff_t)glow_glTexParameterf, target, pname, param);
}
PFNGLTEXPARAMETERFPROC glow_debug_glTexParameterf = glow_debug_impl_glTexParameterf;

static void glow_debug_impl_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) {

  glow_pre_callback_("glCompressedTexSubImage3D", (void*)(ptrdiff_t)glow_glCompressedTexSubImage3D, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
  glow_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
  glow_post_callback_("glCompressedTexSubImage3D", (void*)(ptrdiff_t)glow_glCompressedTexSubImage3D, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glow_debug_glCompressedTexSubImage3D = glow_debug_impl_glCompressedTexSubImage3D;

static void glow_debug_impl_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetTexLevelParameterfv", (void*)(ptrdiff_t)glow_glGetTexLevelParameterfv, target, level, pname, params);
  glow_glGetTexLevelParameterfv(target, level, pname, params);
  glow_post_callback_("glGetTexLevelParameterfv", (void*)(ptrdiff_t)glow_glGetTexLevelParameterfv, target, level, pname, params);
}
PFNGLGETTEXLEVELPARAMETERFVPROC glow_debug_glGetTexLevelParameterfv = glow_debug_impl_glGetTexLevelParameterfv;

static void glow_debug_impl_glDrawArrays(GLenum mode, GLint first, GLsizei count) {

  glow_pre_callback_("glDrawArrays", (void*)(ptrdiff_t)glow_glDrawArrays, mode, first, count);
  glow_glDrawArrays(mode, first, count);
  glow_post_callback_("glDrawArrays", (void*)(ptrdiff_t)glow_glDrawArrays, mode, first, count);
}
PFNGLDRAWARRAYSPROC glow_debug_glDrawArrays = glow_debug_impl_glDrawArrays;

static void glow_debug_impl_glLinkProgram(GLuint program) {

  glow_pre_callback_("glLinkProgram", (void*)(ptrdiff_t)glow_glLinkProgram, program);
  glow_glLinkProgram(program);
  glow_post_callback_("glLinkProgram", (void*)(ptrdiff_t)glow_glLinkProgram, program);
}
PFNGLLINKPROGRAMPROC glow_debug_glLinkProgram = glow_debug_impl_glLinkProgram;

static void glow_debug_impl_glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) {

  glow_pre_callback_("glProgramUniform2f", (void*)(ptrdiff_t)glow_glProgramUniform2f, program, location, v0, v1);
  glow_glProgramUniform2f(program, location, v0, v1);
  glow_post_callback_("glProgramUniform2f", (void*)(ptrdiff_t)glow_glProgramUniform2f, program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2FPROC glow_debug_glProgramUniform2f = glow_debug_impl_glProgramUniform2f;

static GLuint glow_debug_impl_glCreateProgram() {

  GLuint ret;
  glow_pre_callback_("glCreateProgram", (void*)(ptrdiff_t)glow_glCreateProgram);
  ret = glow_glCreateProgram();
  glow_post_callback_("glCreateProgram", (void*)(ptrdiff_t)glow_glCreateProgram);
  return ret;
}
PFNGLCREATEPROGRAMPROC glow_debug_glCreateProgram = glow_debug_impl_glCreateProgram;

static void glow_debug_impl_glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetProgramInterfaceiv", (void*)(ptrdiff_t)glow_glGetProgramInterfaceiv, program, programInterface, pname, params);
  glow_glGetProgramInterfaceiv(program, programInterface, pname, params);
  glow_post_callback_("glGetProgramInterfaceiv", (void*)(ptrdiff_t)glow_glGetProgramInterfaceiv, program, programInterface, pname, params);
}
PFNGLGETPROGRAMINTERFACEIVPROC glow_debug_glGetProgramInterfaceiv = glow_debug_impl_glGetProgramInterfaceiv;

static void glow_debug_impl_glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) {

  glow_pre_callback_("glProgramUniform2ui", (void*)(ptrdiff_t)glow_glProgramUniform2ui, program, location, v0, v1);
  glow_glProgramUniform2ui(program, location, v0, v1);
  glow_post_callback_("glProgramUniform2ui", (void*)(ptrdiff_t)glow_glProgramUniform2ui, program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2UIPROC glow_debug_glProgramUniform2ui = glow_debug_impl_glProgramUniform2ui;

static void glow_debug_impl_glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) {

  glow_pre_callback_("glProgramUniform1uiv", (void*)(ptrdiff_t)glow_glProgramUniform1uiv, program, location, count, value);
  glow_glProgramUniform1uiv(program, location, count, value);
  glow_post_callback_("glProgramUniform1uiv", (void*)(ptrdiff_t)glow_glProgramUniform1uiv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM1UIVPROC glow_debug_glProgramUniform1uiv = glow_debug_impl_glProgramUniform1uiv;

static void glow_debug_impl_glUniform1i(GLint location, GLint v0) {

  glow_pre_callback_("glUniform1i", (void*)(ptrdiff_t)glow_glUniform1i, location, v0);
  glow_glUniform1i(location, v0);
  glow_post_callback_("glUniform1i", (void*)(ptrdiff_t)glow_glUniform1i, location, v0);
}
PFNGLUNIFORM1IPROC glow_debug_glUniform1i = glow_debug_impl_glUniform1i;

static void glow_debug_impl_glGetBufferPointerv(GLenum target, GLenum pname, void **params) {

  glow_pre_callback_("glGetBufferPointerv", (void*)(ptrdiff_t)glow_glGetBufferPointerv, target, pname, params);
  glow_glGetBufferPointerv(target, pname, params);
  glow_post_callback_("glGetBufferPointerv", (void*)(ptrdiff_t)glow_glGetBufferPointerv, target, pname, params);
}
PFNGLGETBUFFERPOINTERVPROC glow_debug_glGetBufferPointerv = glow_debug_impl_glGetBufferPointerv;

static void glow_debug_impl_glEndTransformFeedback() {

  glow_pre_callback_("glEndTransformFeedback", (void*)(ptrdiff_t)glow_glEndTransformFeedback);
  glow_glEndTransformFeedback();
  glow_post_callback_("glEndTransformFeedback", (void*)(ptrdiff_t)glow_glEndTransformFeedback);
}
PFNGLENDTRANSFORMFEEDBACKPROC glow_debug_glEndTransformFeedback = glow_debug_impl_glEndTransformFeedback;

static void glow_debug_impl_glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetSamplerParameterIiv", (void*)(ptrdiff_t)glow_glGetSamplerParameterIiv, sampler, pname, params);
  glow_glGetSamplerParameterIiv(sampler, pname, params);
  glow_post_callback_("glGetSamplerParameterIiv", (void*)(ptrdiff_t)glow_glGetSamplerParameterIiv, sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIIVPROC glow_debug_glGetSamplerParameterIiv = glow_debug_impl_glGetSamplerParameterIiv;

static void glow_debug_impl_glGenFramebuffers(GLsizei n, GLuint *framebuffers) {

  glow_pre_callback_("glGenFramebuffers", (void*)(ptrdiff_t)glow_glGenFramebuffers, n, framebuffers);
  glow_glGenFramebuffers(n, framebuffers);
  glow_post_callback_("glGenFramebuffers", (void*)(ptrdiff_t)glow_glGenFramebuffers, n, framebuffers);
}
PFNGLGENFRAMEBUFFERSPROC glow_debug_glGenFramebuffers = glow_debug_impl_glGenFramebuffers;

static void glow_debug_impl_glGenSamplers(GLsizei count, GLuint *samplers) {

  glow_pre_callback_("glGenSamplers", (void*)(ptrdiff_t)glow_glGenSamplers, count, samplers);
  glow_glGenSamplers(count, samplers);
  glow_post_callback_("glGenSamplers", (void*)(ptrdiff_t)glow_glGenSamplers, count, samplers);
}
PFNGLGENSAMPLERSPROC glow_debug_glGenSamplers = glow_debug_impl_glGenSamplers;

static void glow_debug_impl_glEnablei(GLenum target, GLuint index) {

  glow_pre_callback_("glEnablei", (void*)(ptrdiff_t)glow_glEnablei, target, index);
  glow_glEnablei(target, index);
  glow_post_callback_("glEnablei", (void*)(ptrdiff_t)glow_glEnablei, target, index);
}
PFNGLENABLEIPROC glow_debug_glEnablei = glow_debug_impl_glEnablei;

static void glow_debug_impl_glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label) {

  glow_pre_callback_("glObjectPtrLabel", (void*)(ptrdiff_t)glow_glObjectPtrLabel, ptr, length, label);
  glow_glObjectPtrLabel(ptr, length, label);
  glow_post_callback_("glObjectPtrLabel", (void*)(ptrdiff_t)glow_glObjectPtrLabel, ptr, length, label);
}
PFNGLOBJECTPTRLABELPROC glow_debug_glObjectPtrLabel = glow_debug_impl_glObjectPtrLabel;

static void glow_debug_impl_glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) {

  glow_pre_callback_("glDrawElementsInstancedBaseVertex", (void*)(ptrdiff_t)glow_glDrawElementsInstancedBaseVertex, mode, count, type, indices, instancecount, basevertex);
  glow_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
  glow_post_callback_("glDrawElementsInstancedBaseVertex", (void*)(ptrdiff_t)glow_glDrawElementsInstancedBaseVertex, mode, count, type, indices, instancecount, basevertex);
}
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glow_debug_glDrawElementsInstancedBaseVertex = glow_debug_impl_glDrawElementsInstancedBaseVertex;

static void glow_debug_impl_glFrontFace(GLenum mode) {

  glow_pre_callback_("glFrontFace", (void*)(ptrdiff_t)glow_glFrontFace, mode);
  glow_glFrontFace(mode);
  glow_post_callback_("glFrontFace", (void*)(ptrdiff_t)glow_glFrontFace, mode);
}
PFNGLFRONTFACEPROC glow_debug_glFrontFace = glow_debug_impl_glFrontFace;

static void glow_debug_impl_glVertexAttrib4fv(GLuint index, const GLfloat *v) {

  glow_pre_callback_("glVertexAttrib4fv", (void*)(ptrdiff_t)glow_glVertexAttrib4fv, index, v);
  glow_glVertexAttrib4fv(index, v);
  glow_post_callback_("glVertexAttrib4fv", (void*)(ptrdiff_t)glow_glVertexAttrib4fv, index, v);
}
PFNGLVERTEXATTRIB4FVPROC glow_debug_glVertexAttrib4fv = glow_debug_impl_glVertexAttrib4fv;

static void glow_debug_impl_glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines) {

  glow_pre_callback_("glDeleteProgramPipelines", (void*)(ptrdiff_t)glow_glDeleteProgramPipelines, n, pipelines);
  glow_glDeleteProgramPipelines(n, pipelines);
  glow_post_callback_("glDeleteProgramPipelines", (void*)(ptrdiff_t)glow_glDeleteProgramPipelines, n, pipelines);
}
PFNGLDELETEPROGRAMPIPELINESPROC glow_debug_glDeleteProgramPipelines = glow_debug_impl_glDeleteProgramPipelines;

static void glow_debug_impl_glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) {

  glow_pre_callback_("glTexBuffer", (void*)(ptrdiff_t)glow_glTexBuffer, target, internalformat, buffer);
  glow_glTexBuffer(target, internalformat, buffer);
  glow_post_callback_("glTexBuffer", (void*)(ptrdiff_t)glow_glTexBuffer, target, internalformat, buffer);
}
PFNGLTEXBUFFERPROC glow_debug_glTexBuffer = glow_debug_impl_glTexBuffer;

static void glow_debug_impl_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {

  glow_pre_callback_("glStencilOp", (void*)(ptrdiff_t)glow_glStencilOp, fail, zfail, zpass);
  glow_glStencilOp(fail, zfail, zpass);
  glow_post_callback_("glStencilOp", (void*)(ptrdiff_t)glow_glStencilOp, fail, zfail, zpass);
}
PFNGLSTENCILOPPROC glow_debug_glStencilOp = glow_debug_impl_glStencilOp;

static void glow_debug_impl_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {

  glow_pre_callback_("glUniform2f", (void*)(ptrdiff_t)glow_glUniform2f, location, v0, v1);
  glow_glUniform2f(location, v0, v1);
  glow_post_callback_("glUniform2f", (void*)(ptrdiff_t)glow_glUniform2f, location, v0, v1);
}
PFNGLUNIFORM2FPROC glow_debug_glUniform2f = glow_debug_impl_glUniform2f;

static void glow_debug_impl_glGetUniformuiv(GLuint program, GLint location, GLuint *params) {

  glow_pre_callback_("glGetUniformuiv", (void*)(ptrdiff_t)glow_glGetUniformuiv, program, location, params);
  glow_glGetUniformuiv(program, location, params);
  glow_post_callback_("glGetUniformuiv", (void*)(ptrdiff_t)glow_glGetUniformuiv, program, location, params);
}
PFNGLGETUNIFORMUIVPROC glow_debug_glGetUniformuiv = glow_debug_impl_glGetUniformuiv;

static void glow_debug_impl_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glViewport", (void*)(ptrdiff_t)glow_glViewport, x, y, width, height);
  glow_glViewport(x, y, width, height);
  glow_post_callback_("glViewport", (void*)(ptrdiff_t)glow_glViewport, x, y, width, height);
}
PFNGLVIEWPORTPROC glow_debug_glViewport = glow_debug_impl_glViewport;

static void glow_debug_impl_glDeleteVertexArrays(GLsizei n, const GLuint *arrays) {

  glow_pre_callback_("glDeleteVertexArrays", (void*)(ptrdiff_t)glow_glDeleteVertexArrays, n, arrays);
  glow_glDeleteVertexArrays(n, arrays);
  glow_post_callback_("glDeleteVertexArrays", (void*)(ptrdiff_t)glow_glDeleteVertexArrays, n, arrays);
}
PFNGLDELETEVERTEXARRAYSPROC glow_debug_glDeleteVertexArrays = glow_debug_impl_glDeleteVertexArrays;

static void glow_debug_impl_glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {

  glow_pre_callback_("glVertexAttribI4i", (void*)(ptrdiff_t)glow_glVertexAttribI4i, index, x, y, z, w);
  glow_glVertexAttribI4i(index, x, y, z, w);
  glow_post_callback_("glVertexAttribI4i", (void*)(ptrdiff_t)glow_glVertexAttribI4i, index, x, y, z, w);
}
PFNGLVERTEXATTRIBI4IPROC glow_debug_glVertexAttribI4i = glow_debug_impl_glVertexAttribI4i;

static void glow_debug_impl_glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data) {

  glow_pre_callback_("glGetInteger64i_v", (void*)(ptrdiff_t)glow_glGetInteger64i_v, target, index, data);
  glow_glGetInteger64i_v(target, index, data);
  glow_post_callback_("glGetInteger64i_v", (void*)(ptrdiff_t)glow_glGetInteger64i_v, target, index, data);
}
PFNGLGETINTEGER64I_VPROC glow_debug_glGetInteger64i_v = glow_debug_impl_glGetInteger64i_v;

static void glow_debug_impl_glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param) {

  glow_pre_callback_("glSamplerParameteriv", (void*)(ptrdiff_t)glow_glSamplerParameteriv, sampler, pname, param);
  glow_glSamplerParameteriv(sampler, pname, param);
  glow_post_callback_("glSamplerParameteriv", (void*)(ptrdiff_t)glow_glSamplerParameteriv, sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIVPROC glow_debug_glSamplerParameteriv = glow_debug_impl_glSamplerParameteriv;

static void glow_debug_impl_glGetBooleanv(GLenum pname, GLboolean *data) {

  glow_pre_callback_("glGetBooleanv", (void*)(ptrdiff_t)glow_glGetBooleanv, pname, data);
  glow_glGetBooleanv(pname, data);
  glow_post_callback_("glGetBooleanv", (void*)(ptrdiff_t)glow_glGetBooleanv, pname, data);
}
PFNGLGETBOOLEANVPROC glow_debug_glGetBooleanv = glow_debug_impl_glGetBooleanv;

static void glow_debug_impl_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glTexImage2D", (void*)(ptrdiff_t)glow_glTexImage2D, target, level, internalformat, width, height, border, format, type, pixels);
  glow_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
  glow_post_callback_("glTexImage2D", (void*)(ptrdiff_t)glow_glTexImage2D, target, level, internalformat, width, height, border, format, type, pixels);
}
PFNGLTEXIMAGE2DPROC glow_debug_glTexImage2D = glow_debug_impl_glTexImage2D;

static void glow_debug_impl_glUniform3iv(GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glUniform3iv", (void*)(ptrdiff_t)glow_glUniform3iv, location, count, value);
  glow_glUniform3iv(location, count, value);
  glow_post_callback_("glUniform3iv", (void*)(ptrdiff_t)glow_glUniform3iv, location, count, value);
}
PFNGLUNIFORM3IVPROC glow_debug_glUniform3iv = glow_debug_impl_glUniform3iv;

static void glow_debug_impl_glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glProgramUniform2fv", (void*)(ptrdiff_t)glow_glProgramUniform2fv, program, location, count, value);
  glow_glProgramUniform2fv(program, location, count, value);
  glow_post_callback_("glProgramUniform2fv", (void*)(ptrdiff_t)glow_glProgramUniform2fv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM2FVPROC glow_debug_glProgramUniform2fv = glow_debug_impl_glProgramUniform2fv;

static void glow_debug_impl_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) {

  glow_pre_callback_("glGetQueryObjectuiv", (void*)(ptrdiff_t)glow_glGetQueryObjectuiv, id, pname, params);
  glow_glGetQueryObjectuiv(id, pname, params);
  glow_post_callback_("glGetQueryObjectuiv", (void*)(ptrdiff_t)glow_glGetQueryObjectuiv, id, pname, params);
}
PFNGLGETQUERYOBJECTUIVPROC glow_debug_glGetQueryObjectuiv = glow_debug_impl_glGetQueryObjectuiv;

static void glow_debug_impl_glVertexAttribI4iv(GLuint index, const GLint *v) {

  glow_pre_callback_("glVertexAttribI4iv", (void*)(ptrdiff_t)glow_glVertexAttribI4iv, index, v);
  glow_glVertexAttribI4iv(index, v);
  glow_post_callback_("glVertexAttribI4iv", (void*)(ptrdiff_t)glow_glVertexAttribI4iv, index, v);
}
PFNGLVERTEXATTRIBI4IVPROC glow_debug_glVertexAttribI4iv = glow_debug_impl_glVertexAttribI4iv;

static void glow_debug_impl_glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) {

  glow_pre_callback_("glGetUniformIndices", (void*)(ptrdiff_t)glow_glGetUniformIndices, program, uniformCount, uniformNames, uniformIndices);
  glow_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
  glow_post_callback_("glGetUniformIndices", (void*)(ptrdiff_t)glow_glGetUniformIndices, program, uniformCount, uniformNames, uniformIndices);
}
PFNGLGETUNIFORMINDICESPROC glow_debug_glGetUniformIndices = glow_debug_impl_glGetUniformIndices;

static void glow_debug_impl_glDeleteTextures(GLsizei n, const GLuint *textures) {

  glow_pre_callback_("glDeleteTextures", (void*)(ptrdiff_t)glow_glDeleteTextures, n, textures);
  glow_glDeleteTextures(n, textures);
  glow_post_callback_("glDeleteTextures", (void*)(ptrdiff_t)glow_glDeleteTextures, n, textures);
}
PFNGLDELETETEXTURESPROC glow_debug_glDeleteTextures = glow_debug_impl_glDeleteTextures;

static GLboolean glow_debug_impl_glIsTexture(GLuint texture) {

  GLboolean ret;
  glow_pre_callback_("glIsTexture", (void*)(ptrdiff_t)glow_glIsTexture, texture);
  ret = glow_glIsTexture(texture);
  glow_post_callback_("glIsTexture", (void*)(ptrdiff_t)glow_glIsTexture, texture);
  return ret;
}
PFNGLISTEXTUREPROC glow_debug_glIsTexture = glow_debug_impl_glIsTexture;

static void glow_debug_impl_glPixelStorei(GLenum pname, GLint param) {

  glow_pre_callback_("glPixelStorei", (void*)(ptrdiff_t)glow_glPixelStorei, pname, param);
  glow_glPixelStorei(pname, param);
  glow_post_callback_("glPixelStorei", (void*)(ptrdiff_t)glow_glPixelStorei, pname, param);
}
PFNGLPIXELSTOREIPROC glow_debug_glPixelStorei = glow_debug_impl_glPixelStorei;

static void glow_debug_impl_glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments) {

  glow_pre_callback_("glInvalidateFramebuffer", (void*)(ptrdiff_t)glow_glInvalidateFramebuffer, target, numAttachments, attachments);
  glow_glInvalidateFramebuffer(target, numAttachments, attachments);
  glow_post_callback_("glInvalidateFramebuffer", (void*)(ptrdiff_t)glow_glInvalidateFramebuffer, target, numAttachments, attachments);
}
PFNGLINVALIDATEFRAMEBUFFERPROC glow_debug_glInvalidateFramebuffer = glow_debug_impl_glInvalidateFramebuffer;

static void glow_debug_impl_glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glProgramUniformMatrix2x3fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix2x3fv, program, location, count, transpose, value);
  glow_glProgramUniformMatrix2x3fv(program, location, count, transpose, value);
  glow_post_callback_("glProgramUniformMatrix2x3fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix2x3fv, program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glow_debug_glProgramUniformMatrix2x3fv = glow_debug_impl_glProgramUniformMatrix2x3fv;

static void glow_debug_impl_glBlendFunci(GLuint buf, GLenum src, GLenum dst) {

  glow_pre_callback_("glBlendFunci", (void*)(ptrdiff_t)glow_glBlendFunci, buf, src, dst);
  glow_glBlendFunci(buf, src, dst);
  glow_post_callback_("glBlendFunci", (void*)(ptrdiff_t)glow_glBlendFunci, buf, src, dst);
}
PFNGLBLENDFUNCIPROC glow_debug_glBlendFunci = glow_debug_impl_glBlendFunci;

static void glow_debug_impl_glClearStencil(GLint s) {

  glow_pre_callback_("glClearStencil", (void*)(ptrdiff_t)glow_glClearStencil, s);
  glow_glClearStencil(s);
  glow_post_callback_("glClearStencil", (void*)(ptrdiff_t)glow_glClearStencil, s);
}
PFNGLCLEARSTENCILPROC glow_debug_glClearStencil = glow_debug_impl_glClearStencil;

static void glow_debug_impl_glValidateProgram(GLuint program) {

  glow_pre_callback_("glValidateProgram", (void*)(ptrdiff_t)glow_glValidateProgram, program);
  glow_glValidateProgram(program);
  glow_post_callback_("glValidateProgram", (void*)(ptrdiff_t)glow_glValidateProgram, program);
}
PFNGLVALIDATEPROGRAMPROC glow_debug_glValidateProgram = glow_debug_impl_glValidateProgram;

static void glow_debug_impl_glGetQueryiv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetQueryiv", (void*)(ptrdiff_t)glow_glGetQueryiv, target, pname, params);
  glow_glGetQueryiv(target, pname, params);
  glow_post_callback_("glGetQueryiv", (void*)(ptrdiff_t)glow_glGetQueryiv, target, pname, params);
}
PFNGLGETQUERYIVPROC glow_debug_glGetQueryiv = glow_debug_impl_glGetQueryiv;

static void glow_debug_impl_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {

  glow_pre_callback_("glBlitFramebuffer", (void*)(ptrdiff_t)glow_glBlitFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
  glow_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
  glow_post_callback_("glBlitFramebuffer", (void*)(ptrdiff_t)glow_glBlitFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNGLBLITFRAMEBUFFERPROC glow_debug_glBlitFramebuffer = glow_debug_impl_glBlitFramebuffer;

static void glow_debug_impl_glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {

  glow_pre_callback_("glCopyBufferSubData", (void*)(ptrdiff_t)glow_glCopyBufferSubData, readTarget, writeTarget, readOffset, writeOffset, size);
  glow_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
  glow_post_callback_("glCopyBufferSubData", (void*)(ptrdiff_t)glow_glCopyBufferSubData, readTarget, writeTarget, readOffset, writeOffset, size);
}
PFNGLCOPYBUFFERSUBDATAPROC glow_debug_glCopyBufferSubData = glow_debug_impl_glCopyBufferSubData;

static void glow_debug_impl_glDrawArraysIndirect(GLenum mode, const void *indirect) {

  glow_pre_callback_("glDrawArraysIndirect", (void*)(ptrdiff_t)glow_glDrawArraysIndirect, mode, indirect);
  glow_glDrawArraysIndirect(mode, indirect);
  glow_post_callback_("glDrawArraysIndirect", (void*)(ptrdiff_t)glow_glDrawArraysIndirect, mode, indirect);
}
PFNGLDRAWARRAYSINDIRECTPROC glow_debug_glDrawArraysIndirect = glow_debug_impl_glDrawArraysIndirect;

static void glow_debug_impl_glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) {

  glow_pre_callback_("glUseProgramStages", (void*)(ptrdiff_t)glow_glUseProgramStages, pipeline, stages, program);
  glow_glUseProgramStages(pipeline, stages, program);
  glow_post_callback_("glUseProgramStages", (void*)(ptrdiff_t)glow_glUseProgramStages, pipeline, stages, program);
}
PFNGLUSEPROGRAMSTAGESPROC glow_debug_glUseProgramStages = glow_debug_impl_glUseProgramStages;

static void glow_debug_impl_glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glProgramUniformMatrix4fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix4fv, program, location, count, transpose, value);
  glow_glProgramUniformMatrix4fv(program, location, count, transpose, value);
  glow_post_callback_("glProgramUniformMatrix4fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix4fv, program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glow_debug_glProgramUniformMatrix4fv = glow_debug_impl_glProgramUniformMatrix4fv;

static void glow_debug_impl_glFinish() {

  glow_pre_callback_("glFinish", (void*)(ptrdiff_t)glow_glFinish);
  glow_glFinish();
  glow_post_callback_("glFinish", (void*)(ptrdiff_t)glow_glFinish);
}
PFNGLFINISHPROC glow_debug_glFinish = glow_debug_impl_glFinish;

static void glow_debug_impl_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {

  glow_pre_callback_("glGetShaderInfoLog", (void*)(ptrdiff_t)glow_glGetShaderInfoLog, shader, bufSize, length, infoLog);
  glow_glGetShaderInfoLog(shader, bufSize, length, infoLog);
  glow_post_callback_("glGetShaderInfoLog", (void*)(ptrdiff_t)glow_glGetShaderInfoLog, shader, bufSize, length, infoLog);
}
PFNGLGETSHADERINFOLOGPROC glow_debug_glGetShaderInfoLog = glow_debug_impl_glGetShaderInfoLog;

static void glow_debug_impl_glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix3x4fv", (void*)(ptrdiff_t)glow_glUniformMatrix3x4fv, location, count, transpose, value);
  glow_glUniformMatrix3x4fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix3x4fv", (void*)(ptrdiff_t)glow_glUniformMatrix3x4fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X4FVPROC glow_debug_glUniformMatrix3x4fv = glow_debug_impl_glUniformMatrix3x4fv;

static void glow_debug_impl_glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {

  glow_pre_callback_("glVertexAttribFormat", (void*)(ptrdiff_t)glow_glVertexAttribFormat, attribindex, size, type, normalized, relativeoffset);
  glow_glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
  glow_post_callback_("glVertexAttribFormat", (void*)(ptrdiff_t)glow_glVertexAttribFormat, attribindex, size, type, normalized, relativeoffset);
}
PFNGLVERTEXATTRIBFORMATPROC glow_debug_glVertexAttribFormat = glow_debug_impl_glVertexAttribFormat;

static void glow_debug_impl_glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params) {

  glow_pre_callback_("glGetnUniformiv", (void*)(ptrdiff_t)glow_glGetnUniformiv, program, location, bufSize, params);
  glow_glGetnUniformiv(program, location, bufSize, params);
  glow_post_callback_("glGetnUniformiv", (void*)(ptrdiff_t)glow_glGetnUniformiv, program, location, bufSize, params);
}
PFNGLGETNUNIFORMIVPROC glow_debug_glGetnUniformiv = glow_debug_impl_glGetnUniformiv;

static void glow_debug_impl_glHint(GLenum target, GLenum mode) {

  glow_pre_callback_("glHint", (void*)(ptrdiff_t)glow_glHint, target, mode);
  glow_glHint(target, mode);
  glow_post_callback_("glHint", (void*)(ptrdiff_t)glow_glHint, target, mode);
}
PFNGLHINTPROC glow_debug_glHint = glow_debug_impl_glHint;

static GLboolean glow_debug_impl_glUnmapBuffer(GLenum target) {

  GLboolean ret;
  glow_pre_callback_("glUnmapBuffer", (void*)(ptrdiff_t)glow_glUnmapBuffer, target);
  ret = glow_glUnmapBuffer(target);
  glow_post_callback_("glUnmapBuffer", (void*)(ptrdiff_t)glow_glUnmapBuffer, target);
  return ret;
}
PFNGLUNMAPBUFFERPROC glow_debug_glUnmapBuffer = glow_debug_impl_glUnmapBuffer;

static void glow_debug_impl_glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) {

  glow_pre_callback_("glVertexBindingDivisor", (void*)(ptrdiff_t)glow_glVertexBindingDivisor, bindingindex, divisor);
  glow_glVertexBindingDivisor(bindingindex, divisor);
  glow_post_callback_("glVertexBindingDivisor", (void*)(ptrdiff_t)glow_glVertexBindingDivisor, bindingindex, divisor);
}
PFNGLVERTEXBINDINGDIVISORPROC glow_debug_glVertexBindingDivisor = glow_debug_impl_glVertexBindingDivisor;

static void glow_debug_impl_glBlendEquationi(GLuint buf, GLenum mode) {

  glow_pre_callback_("glBlendEquationi", (void*)(ptrdiff_t)glow_glBlendEquationi, buf, mode);
  glow_glBlendEquationi(buf, mode);
  glow_post_callback_("glBlendEquationi", (void*)(ptrdiff_t)glow_glBlendEquationi, buf, mode);
}
PFNGLBLENDEQUATIONIPROC glow_debug_glBlendEquationi = glow_debug_impl_glBlendEquationi;

static void glow_debug_impl_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glCopyTexSubImage2D", (void*)(ptrdiff_t)glow_glCopyTexSubImage2D, target, level, xoffset, yoffset, x, y, width, height);
  glow_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
  glow_post_callback_("glCopyTexSubImage2D", (void*)(ptrdiff_t)glow_glCopyTexSubImage2D, target, level, xoffset, yoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE2DPROC glow_debug_glCopyTexSubImage2D = glow_debug_impl_glCopyTexSubImage2D;

static void glow_debug_impl_glEnable(GLenum cap) {

  glow_pre_callback_("glEnable", (void*)(ptrdiff_t)glow_glEnable, cap);
  glow_glEnable(cap);
  glow_post_callback_("glEnable", (void*)(ptrdiff_t)glow_glEnable, cap);
}
PFNGLENABLEPROC glow_debug_glEnable = glow_debug_impl_glEnable;

static void glow_debug_impl_glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glProgramUniform4iv", (void*)(ptrdiff_t)glow_glProgramUniform4iv, program, location, count, value);
  glow_glProgramUniform4iv(program, location, count, value);
  glow_post_callback_("glProgramUniform4iv", (void*)(ptrdiff_t)glow_glProgramUniform4iv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM4IVPROC glow_debug_glProgramUniform4iv = glow_debug_impl_glProgramUniform4iv;

static void glow_debug_impl_glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetVertexAttribiv", (void*)(ptrdiff_t)glow_glGetVertexAttribiv, index, pname, params);
  glow_glGetVertexAttribiv(index, pname, params);
  glow_post_callback_("glGetVertexAttribiv", (void*)(ptrdiff_t)glow_glGetVertexAttribiv, index, pname, params);
}
PFNGLGETVERTEXATTRIBIVPROC glow_debug_glGetVertexAttribiv = glow_debug_impl_glGetVertexAttribiv;

static void glow_debug_impl_glUniform1fv(GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glUniform1fv", (void*)(ptrdiff_t)glow_glUniform1fv, location, count, value);
  glow_glUniform1fv(location, count, value);
  glow_post_callback_("glUniform1fv", (void*)(ptrdiff_t)glow_glUniform1fv, location, count, value);
}
PFNGLUNIFORM1FVPROC glow_debug_glUniform1fv = glow_debug_impl_glUniform1fv;

static GLint glow_debug_impl_glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name) {

  GLint ret;
  glow_pre_callback_("glGetProgramResourceLocation", (void*)(ptrdiff_t)glow_glGetProgramResourceLocation, program, programInterface, name);
  ret = glow_glGetProgramResourceLocation(program, programInterface, name);
  glow_post_callback_("glGetProgramResourceLocation", (void*)(ptrdiff_t)glow_glGetProgramResourceLocation, program, programInterface, name);
  return ret;
}
PFNGLGETPROGRAMRESOURCELOCATIONPROC glow_debug_glGetProgramResourceLocation = glow_debug_impl_glGetProgramResourceLocation;

static void glow_debug_impl_glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {

  glow_pre_callback_("glProgramUniform3ui", (void*)(ptrdiff_t)glow_glProgramUniform3ui, program, location, v0, v1, v2);
  glow_glProgramUniform3ui(program, location, v0, v1, v2);
  glow_post_callback_("glProgramUniform3ui", (void*)(ptrdiff_t)glow_glProgramUniform3ui, program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3UIPROC glow_debug_glProgramUniform3ui = glow_debug_impl_glProgramUniform3ui;

static void glow_debug_impl_glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) {

  glow_pre_callback_("glDrawElementsBaseVertex", (void*)(ptrdiff_t)glow_glDrawElementsBaseVertex, mode, count, type, indices, basevertex);
  glow_glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
  glow_post_callback_("glDrawElementsBaseVertex", (void*)(ptrdiff_t)glow_glDrawElementsBaseVertex, mode, count, type, indices, basevertex);
}
PFNGLDRAWELEMENTSBASEVERTEXPROC glow_debug_glDrawElementsBaseVertex = glow_debug_impl_glDrawElementsBaseVertex;

static void glow_debug_impl_glBlendEquation(GLenum mode) {

  glow_pre_callback_("glBlendEquation", (void*)(ptrdiff_t)glow_glBlendEquation, mode);
  glow_glBlendEquation(mode);
  glow_post_callback_("glBlendEquation", (void*)(ptrdiff_t)glow_glBlendEquation, mode);
}
PFNGLBLENDEQUATIONPROC glow_debug_glBlendEquation = glow_debug_impl_glBlendEquation;

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

static void glow_debug_impl_glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glProgramUniformMatrix4x3fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix4x3fv, program, location, count, transpose, value);
  glow_glProgramUniformMatrix4x3fv(program, location, count, transpose, value);
  glow_post_callback_("glProgramUniformMatrix4x3fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix4x3fv, program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glow_debug_glProgramUniformMatrix4x3fv = glow_debug_impl_glProgramUniformMatrix4x3fv;

static void glow_debug_impl_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {

  glow_pre_callback_("glBindRenderbuffer", (void*)(ptrdiff_t)glow_glBindRenderbuffer, target, renderbuffer);
  glow_glBindRenderbuffer(target, renderbuffer);
  glow_post_callback_("glBindRenderbuffer", (void*)(ptrdiff_t)glow_glBindRenderbuffer, target, renderbuffer);
}
PFNGLBINDRENDERBUFFERPROC glow_debug_glBindRenderbuffer = glow_debug_impl_glBindRenderbuffer;

static void glow_debug_impl_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {

  glow_pre_callback_("glVertexAttrib4f", (void*)(ptrdiff_t)glow_glVertexAttrib4f, index, x, y, z, w);
  glow_glVertexAttrib4f(index, x, y, z, w);
  glow_post_callback_("glVertexAttrib4f", (void*)(ptrdiff_t)glow_glVertexAttrib4f, index, x, y, z, w);
}
PFNGLVERTEXATTRIB4FPROC glow_debug_glVertexAttrib4f = glow_debug_impl_glVertexAttrib4f;

static void glow_debug_impl_glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) {

  glow_pre_callback_("glProgramUniform4uiv", (void*)(ptrdiff_t)glow_glProgramUniform4uiv, program, location, count, value);
  glow_glProgramUniform4uiv(program, location, count, value);
  glow_post_callback_("glProgramUniform4uiv", (void*)(ptrdiff_t)glow_glProgramUniform4uiv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM4UIVPROC glow_debug_glProgramUniform4uiv = glow_debug_impl_glProgramUniform4uiv;

static void glow_debug_impl_glMinSampleShading(GLfloat value) {

  glow_pre_callback_("glMinSampleShading", (void*)(ptrdiff_t)glow_glMinSampleShading, value);
  glow_glMinSampleShading(value);
  glow_post_callback_("glMinSampleShading", (void*)(ptrdiff_t)glow_glMinSampleShading, value);
}
PFNGLMINSAMPLESHADINGPROC glow_debug_glMinSampleShading = glow_debug_impl_glMinSampleShading;

static void glow_debug_impl_glBeginQuery(GLenum target, GLuint id) {

  glow_pre_callback_("glBeginQuery", (void*)(ptrdiff_t)glow_glBeginQuery, target, id);
  glow_glBeginQuery(target, id);
  glow_post_callback_("glBeginQuery", (void*)(ptrdiff_t)glow_glBeginQuery, target, id);
}
PFNGLBEGINQUERYPROC glow_debug_glBeginQuery = glow_debug_impl_glBeginQuery;

static void glow_debug_impl_glBindBufferBase(GLenum target, GLuint index, GLuint buffer) {

  glow_pre_callback_("glBindBufferBase", (void*)(ptrdiff_t)glow_glBindBufferBase, target, index, buffer);
  glow_glBindBufferBase(target, index, buffer);
  glow_post_callback_("glBindBufferBase", (void*)(ptrdiff_t)glow_glBindBufferBase, target, index, buffer);
}
PFNGLBINDBUFFERBASEPROC glow_debug_glBindBufferBase = glow_debug_impl_glBindBufferBase;

static GLubyte glow_debug_impl_glGetStringi(GLenum name, GLuint index) {

  GLubyte ret;
  glow_pre_callback_("glGetStringi", (void*)(ptrdiff_t)glow_glGetStringi, name, index);
  ret = glow_glGetStringi(name, index);
  glow_post_callback_("glGetStringi", (void*)(ptrdiff_t)glow_glGetStringi, name, index);
  return ret;
}
PFNGLGETSTRINGIPROC glow_debug_glGetStringi = glow_debug_impl_glGetStringi;

static void glow_debug_impl_glGenTransformFeedbacks(GLsizei n, GLuint *ids) {

  glow_pre_callback_("glGenTransformFeedbacks", (void*)(ptrdiff_t)glow_glGenTransformFeedbacks, n, ids);
  glow_glGenTransformFeedbacks(n, ids);
  glow_post_callback_("glGenTransformFeedbacks", (void*)(ptrdiff_t)glow_glGenTransformFeedbacks, n, ids);
}
PFNGLGENTRANSFORMFEEDBACKSPROC glow_debug_glGenTransformFeedbacks = glow_debug_impl_glGenTransformFeedbacks;

static void glow_debug_impl_glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glProgramUniformMatrix2x4fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix2x4fv, program, location, count, transpose, value);
  glow_glProgramUniformMatrix2x4fv(program, location, count, transpose, value);
  glow_post_callback_("glProgramUniformMatrix2x4fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix2x4fv, program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glow_debug_glProgramUniformMatrix2x4fv = glow_debug_impl_glProgramUniformMatrix2x4fv;

static void glow_debug_impl_glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {

  glow_pre_callback_("glBlendFuncSeparatei", (void*)(ptrdiff_t)glow_glBlendFuncSeparatei, buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
  glow_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
  glow_post_callback_("glBlendFuncSeparatei", (void*)(ptrdiff_t)glow_glBlendFuncSeparatei, buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
PFNGLBLENDFUNCSEPARATEIPROC glow_debug_glBlendFuncSeparatei = glow_debug_impl_glBlendFuncSeparatei;

static void glow_debug_impl_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) {

  glow_pre_callback_("glGetShaderPrecisionFormat", (void*)(ptrdiff_t)glow_glGetShaderPrecisionFormat, shadertype, precisiontype, range, precision);
  glow_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
  glow_post_callback_("glGetShaderPrecisionFormat", (void*)(ptrdiff_t)glow_glGetShaderPrecisionFormat, shadertype, precisiontype, range, precision);
}
PFNGLGETSHADERPRECISIONFORMATPROC glow_debug_glGetShaderPrecisionFormat = glow_debug_impl_glGetShaderPrecisionFormat;

static GLint glow_debug_impl_glGetUniformLocation(GLuint program, const GLchar *name) {

  GLint ret;
  glow_pre_callback_("glGetUniformLocation", (void*)(ptrdiff_t)glow_glGetUniformLocation, program, name);
  ret = glow_glGetUniformLocation(program, name);
  glow_post_callback_("glGetUniformLocation", (void*)(ptrdiff_t)glow_glGetUniformLocation, program, name);
  return ret;
}
PFNGLGETUNIFORMLOCATIONPROC glow_debug_glGetUniformLocation = glow_debug_impl_glGetUniformLocation;

static void glow_debug_impl_glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) {

  glow_pre_callback_("glSamplerParameterf", (void*)(ptrdiff_t)glow_glSamplerParameterf, sampler, pname, param);
  glow_glSamplerParameterf(sampler, pname, param);
  glow_post_callback_("glSamplerParameterf", (void*)(ptrdiff_t)glow_glSamplerParameterf, sampler, pname, param);
}
PFNGLSAMPLERPARAMETERFPROC glow_debug_glSamplerParameterf = glow_debug_impl_glSamplerParameterf;

static GLboolean glow_debug_impl_glIsTransformFeedback(GLuint id) {

  GLboolean ret;
  glow_pre_callback_("glIsTransformFeedback", (void*)(ptrdiff_t)glow_glIsTransformFeedback, id);
  ret = glow_glIsTransformFeedback(id);
  glow_post_callback_("glIsTransformFeedback", (void*)(ptrdiff_t)glow_glIsTransformFeedback, id);
  return ret;
}
PFNGLISTRANSFORMFEEDBACKPROC glow_debug_glIsTransformFeedback = glow_debug_impl_glIsTransformFeedback;

static void glow_debug_impl_glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glInvalidateSubFramebuffer", (void*)(ptrdiff_t)glow_glInvalidateSubFramebuffer, target, numAttachments, attachments, x, y, width, height);
  glow_glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
  glow_post_callback_("glInvalidateSubFramebuffer", (void*)(ptrdiff_t)glow_glInvalidateSubFramebuffer, target, numAttachments, attachments, x, y, width, height);
}
PFNGLINVALIDATESUBFRAMEBUFFERPROC glow_debug_glInvalidateSubFramebuffer = glow_debug_impl_glInvalidateSubFramebuffer;

static void glow_debug_impl_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetTexLevelParameteriv", (void*)(ptrdiff_t)glow_glGetTexLevelParameteriv, target, level, pname, params);
  glow_glGetTexLevelParameteriv(target, level, pname, params);
  glow_post_callback_("glGetTexLevelParameteriv", (void*)(ptrdiff_t)glow_glGetTexLevelParameteriv, target, level, pname, params);
}
PFNGLGETTEXLEVELPARAMETERIVPROC glow_debug_glGetTexLevelParameteriv = glow_debug_impl_glGetTexLevelParameteriv;

static void glow_debug_impl_glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {

  glow_pre_callback_("glTexBufferRange", (void*)(ptrdiff_t)glow_glTexBufferRange, target, internalformat, buffer, offset, size);
  glow_glTexBufferRange(target, internalformat, buffer, offset, size);
  glow_post_callback_("glTexBufferRange", (void*)(ptrdiff_t)glow_glTexBufferRange, target, internalformat, buffer, offset, size);
}
PFNGLTEXBUFFERRANGEPROC glow_debug_glTexBufferRange = glow_debug_impl_glTexBufferRange;

static void glow_debug_impl_glGetUniformfv(GLuint program, GLint location, GLfloat *params) {

  glow_pre_callback_("glGetUniformfv", (void*)(ptrdiff_t)glow_glGetUniformfv, program, location, params);
  glow_glGetUniformfv(program, location, params);
  glow_post_callback_("glGetUniformfv", (void*)(ptrdiff_t)glow_glGetUniformfv, program, location, params);
}
PFNGLGETUNIFORMFVPROC glow_debug_glGetUniformfv = glow_debug_impl_glGetUniformfv;

static void glow_debug_impl_glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {

  glow_pre_callback_("glBindBufferRange", (void*)(ptrdiff_t)glow_glBindBufferRange, target, index, buffer, offset, size);
  glow_glBindBufferRange(target, index, buffer, offset, size);
  glow_post_callback_("glBindBufferRange", (void*)(ptrdiff_t)glow_glBindBufferRange, target, index, buffer, offset, size);
}
PFNGLBINDBUFFERRANGEPROC glow_debug_glBindBufferRange = glow_debug_impl_glBindBufferRange;

static void glow_debug_impl_glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetSamplerParameterfv", (void*)(ptrdiff_t)glow_glGetSamplerParameterfv, sampler, pname, params);
  glow_glGetSamplerParameterfv(sampler, pname, params);
  glow_post_callback_("glGetSamplerParameterfv", (void*)(ptrdiff_t)glow_glGetSamplerParameterfv, sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERFVPROC glow_debug_glGetSamplerParameterfv = glow_debug_impl_glGetSamplerParameterfv;

static void glow_debug_impl_glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) {

  glow_pre_callback_("glBufferData", (void*)(ptrdiff_t)glow_glBufferData, target, size, data, usage);
  glow_glBufferData(target, size, data, usage);
  glow_post_callback_("glBufferData", (void*)(ptrdiff_t)glow_glBufferData, target, size, data, usage);
}
PFNGLBUFFERDATAPROC glow_debug_glBufferData = glow_debug_impl_glBufferData;

static GLboolean glow_debug_impl_glIsFramebuffer(GLuint framebuffer) {

  GLboolean ret;
  glow_pre_callback_("glIsFramebuffer", (void*)(ptrdiff_t)glow_glIsFramebuffer, framebuffer);
  ret = glow_glIsFramebuffer(framebuffer);
  glow_post_callback_("glIsFramebuffer", (void*)(ptrdiff_t)glow_glIsFramebuffer, framebuffer);
  return ret;
}
PFNGLISFRAMEBUFFERPROC glow_debug_glIsFramebuffer = glow_debug_impl_glIsFramebuffer;

static void glow_debug_impl_glPolygonOffset(GLfloat factor, GLfloat units) {

  glow_pre_callback_("glPolygonOffset", (void*)(ptrdiff_t)glow_glPolygonOffset, factor, units);
  glow_glPolygonOffset(factor, units);
  glow_post_callback_("glPolygonOffset", (void*)(ptrdiff_t)glow_glPolygonOffset, factor, units);
}
PFNGLPOLYGONOFFSETPROC glow_debug_glPolygonOffset = glow_debug_impl_glPolygonOffset;

static void glow_debug_impl_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {

  glow_pre_callback_("glUniform4i", (void*)(ptrdiff_t)glow_glUniform4i, location, v0, v1, v2, v3);
  glow_glUniform4i(location, v0, v1, v2, v3);
  glow_post_callback_("glUniform4i", (void*)(ptrdiff_t)glow_glUniform4i, location, v0, v1, v2, v3);
}
PFNGLUNIFORM4IPROC glow_debug_glUniform4i = glow_debug_impl_glUniform4i;

static void glow_debug_impl_glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glTexImage3D", (void*)(ptrdiff_t)glow_glTexImage3D, target, level, internalformat, width, height, depth, border, format, type, pixels);
  glow_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
  glow_post_callback_("glTexImage3D", (void*)(ptrdiff_t)glow_glTexImage3D, target, level, internalformat, width, height, depth, border, format, type, pixels);
}
PFNGLTEXIMAGE3DPROC glow_debug_glTexImage3D = glow_debug_impl_glTexImage3D;

static void glow_debug_impl_glDispatchComputeIndirect(GLintptr indirect) {

  glow_pre_callback_("glDispatchComputeIndirect", (void*)(ptrdiff_t)glow_glDispatchComputeIndirect, indirect);
  glow_glDispatchComputeIndirect(indirect);
  glow_post_callback_("glDispatchComputeIndirect", (void*)(ptrdiff_t)glow_glDispatchComputeIndirect, indirect);
}
PFNGLDISPATCHCOMPUTEINDIRECTPROC glow_debug_glDispatchComputeIndirect = glow_debug_impl_glDispatchComputeIndirect;

static void glow_debug_impl_glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) {

  glow_pre_callback_("glDebugMessageControl", (void*)(ptrdiff_t)glow_glDebugMessageControl, source, type, severity, count, ids, enabled);
  glow_glDebugMessageControl(source, type, severity, count, ids, enabled);
  glow_post_callback_("glDebugMessageControl", (void*)(ptrdiff_t)glow_glDebugMessageControl, source, type, severity, count, ids, enabled);
}
PFNGLDEBUGMESSAGECONTROLPROC glow_debug_glDebugMessageControl = glow_debug_impl_glDebugMessageControl;

static void glow_debug_impl_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) {

  glow_pre_callback_("glCompressedTexImage2D", (void*)(ptrdiff_t)glow_glCompressedTexImage2D, target, level, internalformat, width, height, border, imageSize, data);
  glow_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
  glow_post_callback_("glCompressedTexImage2D", (void*)(ptrdiff_t)glow_glCompressedTexImage2D, target, level, internalformat, width, height, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE2DPROC glow_debug_glCompressedTexImage2D = glow_debug_impl_glCompressedTexImage2D;

static void glow_debug_impl_glDeleteProgram(GLuint program) {

  glow_pre_callback_("glDeleteProgram", (void*)(ptrdiff_t)glow_glDeleteProgram, program);
  glow_glDeleteProgram(program);
  glow_post_callback_("glDeleteProgram", (void*)(ptrdiff_t)glow_glDeleteProgram, program);
}
PFNGLDELETEPROGRAMPROC glow_debug_glDeleteProgram = glow_debug_impl_glDeleteProgram;

static void glow_debug_impl_glStencilFunc(GLenum func, GLint ref, GLuint mask) {

  glow_pre_callback_("glStencilFunc", (void*)(ptrdiff_t)glow_glStencilFunc, func, ref, mask);
  glow_glStencilFunc(func, ref, mask);
  glow_post_callback_("glStencilFunc", (void*)(ptrdiff_t)glow_glStencilFunc, func, ref, mask);
}
PFNGLSTENCILFUNCPROC glow_debug_glStencilFunc = glow_debug_impl_glStencilFunc;

static void glow_debug_impl_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {

  glow_pre_callback_("glGetProgramInfoLog", (void*)(ptrdiff_t)glow_glGetProgramInfoLog, program, bufSize, length, infoLog);
  glow_glGetProgramInfoLog(program, bufSize, length, infoLog);
  glow_post_callback_("glGetProgramInfoLog", (void*)(ptrdiff_t)glow_glGetProgramInfoLog, program, bufSize, length, infoLog);
}
PFNGLGETPROGRAMINFOLOGPROC glow_debug_glGetProgramInfoLog = glow_debug_impl_glGetProgramInfoLog;

static void glow_debug_impl_glDeleteSync(GLsync sync) {

  glow_pre_callback_("glDeleteSync", (void*)(ptrdiff_t)glow_glDeleteSync, sync);
  glow_glDeleteSync(sync);
  glow_post_callback_("glDeleteSync", (void*)(ptrdiff_t)glow_glDeleteSync, sync);
}
PFNGLDELETESYNCPROC glow_debug_glDeleteSync = glow_debug_impl_glDeleteSync;

static void glow_debug_impl_glBlendFunc(GLenum sfactor, GLenum dfactor) {

  glow_pre_callback_("glBlendFunc", (void*)(ptrdiff_t)glow_glBlendFunc, sfactor, dfactor);
  glow_glBlendFunc(sfactor, dfactor);
  glow_post_callback_("glBlendFunc", (void*)(ptrdiff_t)glow_glBlendFunc, sfactor, dfactor);
}
PFNGLBLENDFUNCPROC glow_debug_glBlendFunc = glow_debug_impl_glBlendFunc;

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

static void glow_debug_impl_glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params) {

  glow_pre_callback_("glGetProgramResourceiv", (void*)(ptrdiff_t)glow_glGetProgramResourceiv, program, programInterface, index, propCount, props, bufSize, length, params);
  glow_glGetProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params);
  glow_post_callback_("glGetProgramResourceiv", (void*)(ptrdiff_t)glow_glGetProgramResourceiv, program, programInterface, index, propCount, props, bufSize, length, params);
}
PFNGLGETPROGRAMRESOURCEIVPROC glow_debug_glGetProgramResourceiv = glow_debug_impl_glGetProgramResourceiv;

static void glow_debug_impl_glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {

  glow_pre_callback_("glGetProgramPipelineInfoLog", (void*)(ptrdiff_t)glow_glGetProgramPipelineInfoLog, pipeline, bufSize, length, infoLog);
  glow_glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
  glow_post_callback_("glGetProgramPipelineInfoLog", (void*)(ptrdiff_t)glow_glGetProgramPipelineInfoLog, pipeline, bufSize, length, infoLog);
}
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glow_debug_glGetProgramPipelineInfoLog = glow_debug_impl_glGetProgramPipelineInfoLog;

static void glow_debug_impl_glBindBuffer(GLenum target, GLuint buffer) {

  glow_pre_callback_("glBindBuffer", (void*)(ptrdiff_t)glow_glBindBuffer, target, buffer);
  glow_glBindBuffer(target, buffer);
  glow_post_callback_("glBindBuffer", (void*)(ptrdiff_t)glow_glBindBuffer, target, buffer);
}
PFNGLBINDBUFFERPROC glow_debug_glBindBuffer = glow_debug_impl_glBindBuffer;

static void glow_debug_impl_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetTexParameterfv", (void*)(ptrdiff_t)glow_glGetTexParameterfv, target, pname, params);
  glow_glGetTexParameterfv(target, pname, params);
  glow_post_callback_("glGetTexParameterfv", (void*)(ptrdiff_t)glow_glGetTexParameterfv, target, pname, params);
}
PFNGLGETTEXPARAMETERFVPROC glow_debug_glGetTexParameterfv = glow_debug_impl_glGetTexParameterfv;

static void glow_debug_impl_glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {

  glow_pre_callback_("glTexStorage3D", (void*)(ptrdiff_t)glow_glTexStorage3D, target, levels, internalformat, width, height, depth);
  glow_glTexStorage3D(target, levels, internalformat, width, height, depth);
  glow_post_callback_("glTexStorage3D", (void*)(ptrdiff_t)glow_glTexStorage3D, target, levels, internalformat, width, height, depth);
}
PFNGLTEXSTORAGE3DPROC glow_debug_glTexStorage3D = glow_debug_impl_glTexStorage3D;

static void glow_debug_impl_glDepthFunc(GLenum func) {

  glow_pre_callback_("glDepthFunc", (void*)(ptrdiff_t)glow_glDepthFunc, func);
  glow_glDepthFunc(func);
  glow_post_callback_("glDepthFunc", (void*)(ptrdiff_t)glow_glDepthFunc, func);
}
PFNGLDEPTHFUNCPROC glow_debug_glDepthFunc = glow_debug_impl_glDepthFunc;

static void glow_debug_impl_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetFramebufferAttachmentParameteriv", (void*)(ptrdiff_t)glow_glGetFramebufferAttachmentParameteriv, target, attachment, pname, params);
  glow_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
  glow_post_callback_("glGetFramebufferAttachmentParameteriv", (void*)(ptrdiff_t)glow_glGetFramebufferAttachmentParameteriv, target, attachment, pname, params);
}
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glow_debug_glGetFramebufferAttachmentParameteriv = glow_debug_impl_glGetFramebufferAttachmentParameteriv;

static void glow_debug_impl_glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {

  glow_pre_callback_("glVertexAttribIFormat", (void*)(ptrdiff_t)glow_glVertexAttribIFormat, attribindex, size, type, relativeoffset);
  glow_glVertexAttribIFormat(attribindex, size, type, relativeoffset);
  glow_post_callback_("glVertexAttribIFormat", (void*)(ptrdiff_t)glow_glVertexAttribIFormat, attribindex, size, type, relativeoffset);
}
PFNGLVERTEXATTRIBIFORMATPROC glow_debug_glVertexAttribIFormat = glow_debug_impl_glVertexAttribIFormat;

static void glow_debug_impl_glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix4x3fv", (void*)(ptrdiff_t)glow_glUniformMatrix4x3fv, location, count, transpose, value);
  glow_glUniformMatrix4x3fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix4x3fv", (void*)(ptrdiff_t)glow_glUniformMatrix4x3fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X3FVPROC glow_debug_glUniformMatrix4x3fv = glow_debug_impl_glUniformMatrix4x3fv;

static void glow_debug_impl_glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {

  glow_pre_callback_("glProgramUniform3f", (void*)(ptrdiff_t)glow_glProgramUniform3f, program, location, v0, v1, v2);
  glow_glProgramUniform3f(program, location, v0, v1, v2);
  glow_post_callback_("glProgramUniform3f", (void*)(ptrdiff_t)glow_glProgramUniform3f, program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3FPROC glow_debug_glProgramUniform3f = glow_debug_impl_glProgramUniform3f;

static void glow_debug_impl_glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) {

  glow_pre_callback_("glProgramUniform2uiv", (void*)(ptrdiff_t)glow_glProgramUniform2uiv, program, location, count, value);
  glow_glProgramUniform2uiv(program, location, count, value);
  glow_post_callback_("glProgramUniform2uiv", (void*)(ptrdiff_t)glow_glProgramUniform2uiv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM2UIVPROC glow_debug_glProgramUniform2uiv = glow_debug_impl_glProgramUniform2uiv;

static void glow_debug_impl_glPatchParameteri(GLenum pname, GLint value) {

  glow_pre_callback_("glPatchParameteri", (void*)(ptrdiff_t)glow_glPatchParameteri, pname, value);
  glow_glPatchParameteri(pname, value);
  glow_post_callback_("glPatchParameteri", (void*)(ptrdiff_t)glow_glPatchParameteri, pname, value);
}
PFNGLPATCHPARAMETERIPROC glow_debug_glPatchParameteri = glow_debug_impl_glPatchParameteri;

static void glow_debug_impl_glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) {

  glow_pre_callback_("glDeleteRenderbuffers", (void*)(ptrdiff_t)glow_glDeleteRenderbuffers, n, renderbuffers);
  glow_glDeleteRenderbuffers(n, renderbuffers);
  glow_post_callback_("glDeleteRenderbuffers", (void*)(ptrdiff_t)glow_glDeleteRenderbuffers, n, renderbuffers);
}
PFNGLDELETERENDERBUFFERSPROC glow_debug_glDeleteRenderbuffers = glow_debug_impl_glDeleteRenderbuffers;

static GLboolean glow_debug_impl_glIsRenderbuffer(GLuint renderbuffer) {

  GLboolean ret;
  glow_pre_callback_("glIsRenderbuffer", (void*)(ptrdiff_t)glow_glIsRenderbuffer, renderbuffer);
  ret = glow_glIsRenderbuffer(renderbuffer);
  glow_post_callback_("glIsRenderbuffer", (void*)(ptrdiff_t)glow_glIsRenderbuffer, renderbuffer);
  return ret;
}
PFNGLISRENDERBUFFERPROC glow_debug_glIsRenderbuffer = glow_debug_impl_glIsRenderbuffer;

static void glow_debug_impl_glVertexAttrib3fv(GLuint index, const GLfloat *v) {

  glow_pre_callback_("glVertexAttrib3fv", (void*)(ptrdiff_t)glow_glVertexAttrib3fv, index, v);
  glow_glVertexAttrib3fv(index, v);
  glow_post_callback_("glVertexAttrib3fv", (void*)(ptrdiff_t)glow_glVertexAttrib3fv, index, v);
}
PFNGLVERTEXATTRIB3FVPROC glow_debug_glVertexAttrib3fv = glow_debug_impl_glVertexAttrib3fv;

static void glow_debug_impl_glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {

  glow_pre_callback_("glUniform4ui", (void*)(ptrdiff_t)glow_glUniform4ui, location, v0, v1, v2, v3);
  glow_glUniform4ui(location, v0, v1, v2, v3);
  glow_post_callback_("glUniform4ui", (void*)(ptrdiff_t)glow_glUniform4ui, location, v0, v1, v2, v3);
}
PFNGLUNIFORM4UIPROC glow_debug_glUniform4ui = glow_debug_impl_glUniform4ui;

static void glow_debug_impl_glGetInteger64v(GLenum pname, GLint64 *data) {

  glow_pre_callback_("glGetInteger64v", (void*)(ptrdiff_t)glow_glGetInteger64v, pname, data);
  glow_glGetInteger64v(pname, data);
  glow_post_callback_("glGetInteger64v", (void*)(ptrdiff_t)glow_glGetInteger64v, pname, data);
}
PFNGLGETINTEGER64VPROC glow_debug_glGetInteger64v = glow_debug_impl_glGetInteger64v;

static void glow_debug_impl_glGenProgramPipelines(GLsizei n, GLuint *pipelines) {

  glow_pre_callback_("glGenProgramPipelines", (void*)(ptrdiff_t)glow_glGenProgramPipelines, n, pipelines);
  glow_glGenProgramPipelines(n, pipelines);
  glow_post_callback_("glGenProgramPipelines", (void*)(ptrdiff_t)glow_glGenProgramPipelines, n, pipelines);
}
PFNGLGENPROGRAMPIPELINESPROC glow_debug_glGenProgramPipelines = glow_debug_impl_glGenProgramPipelines;

static void glow_debug_impl_glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {

  glow_pre_callback_("glTexStorage2DMultisample", (void*)(ptrdiff_t)glow_glTexStorage2DMultisample, target, samples, internalformat, width, height, fixedsamplelocations);
  glow_glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
  glow_post_callback_("glTexStorage2DMultisample", (void*)(ptrdiff_t)glow_glTexStorage2DMultisample, target, samples, internalformat, width, height, fixedsamplelocations);
}
PFNGLTEXSTORAGE2DMULTISAMPLEPROC glow_debug_glTexStorage2DMultisample = glow_debug_impl_glTexStorage2DMultisample;

static void glow_debug_impl_glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) {

  glow_pre_callback_("glBindAttribLocation", (void*)(ptrdiff_t)glow_glBindAttribLocation, program, index, name);
  glow_glBindAttribLocation(program, index, name);
  glow_post_callback_("glBindAttribLocation", (void*)(ptrdiff_t)glow_glBindAttribLocation, program, index, name);
}
PFNGLBINDATTRIBLOCATIONPROC glow_debug_glBindAttribLocation = glow_debug_impl_glBindAttribLocation;

static void glow_debug_impl_glEndQuery(GLenum target) {

  glow_pre_callback_("glEndQuery", (void*)(ptrdiff_t)glow_glEndQuery, target);
  glow_glEndQuery(target);
  glow_post_callback_("glEndQuery", (void*)(ptrdiff_t)glow_glEndQuery, target);
}
PFNGLENDQUERYPROC glow_debug_glEndQuery = glow_debug_impl_glEndQuery;

static void glow_debug_impl_glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) {

  glow_pre_callback_("glGetVertexAttribIuiv", (void*)(ptrdiff_t)glow_glGetVertexAttribIuiv, index, pname, params);
  glow_glGetVertexAttribIuiv(index, pname, params);
  glow_post_callback_("glGetVertexAttribIuiv", (void*)(ptrdiff_t)glow_glGetVertexAttribIuiv, index, pname, params);
}
PFNGLGETVERTEXATTRIBIUIVPROC glow_debug_glGetVertexAttribIuiv = glow_debug_impl_glGetVertexAttribIuiv;

static void glow_debug_impl_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {

  glow_pre_callback_("glStencilOpSeparate", (void*)(ptrdiff_t)glow_glStencilOpSeparate, face, sfail, dpfail, dppass);
  glow_glStencilOpSeparate(face, sfail, dpfail, dppass);
  glow_post_callback_("glStencilOpSeparate", (void*)(ptrdiff_t)glow_glStencilOpSeparate, face, sfail, dpfail, dppass);
}
PFNGLSTENCILOPSEPARATEPROC glow_debug_glStencilOpSeparate = glow_debug_impl_glStencilOpSeparate;

static void glow_debug_impl_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) {

  glow_pre_callback_("glCompressedTexImage3D", (void*)(ptrdiff_t)glow_glCompressedTexImage3D, target, level, internalformat, width, height, depth, border, imageSize, data);
  glow_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
  glow_post_callback_("glCompressedTexImage3D", (void*)(ptrdiff_t)glow_glCompressedTexImage3D, target, level, internalformat, width, height, depth, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE3DPROC glow_debug_glCompressedTexImage3D = glow_debug_impl_glCompressedTexImage3D;

static void glow_debug_impl_glGetIntegeri_v(GLenum target, GLuint index, GLint *data) {

  glow_pre_callback_("glGetIntegeri_v", (void*)(ptrdiff_t)glow_glGetIntegeri_v, target, index, data);
  glow_glGetIntegeri_v(target, index, data);
  glow_post_callback_("glGetIntegeri_v", (void*)(ptrdiff_t)glow_glGetIntegeri_v, target, index, data);
}
PFNGLGETINTEGERI_VPROC glow_debug_glGetIntegeri_v = glow_debug_impl_glGetIntegeri_v;

static void glow_debug_impl_glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) {

  glow_pre_callback_("glTransformFeedbackVaryings", (void*)(ptrdiff_t)glow_glTransformFeedbackVaryings, program, count, varyings, bufferMode);
  glow_glTransformFeedbackVaryings(program, count, varyings, bufferMode);
  glow_post_callback_("glTransformFeedbackVaryings", (void*)(ptrdiff_t)glow_glTransformFeedbackVaryings, program, count, varyings, bufferMode);
}
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glow_debug_glTransformFeedbackVaryings = glow_debug_impl_glTransformFeedbackVaryings;

static void glow_debug_impl_glUniform1uiv(GLint location, GLsizei count, const GLuint *value) {

  glow_pre_callback_("glUniform1uiv", (void*)(ptrdiff_t)glow_glUniform1uiv, location, count, value);
  glow_glUniform1uiv(location, count, value);
  glow_post_callback_("glUniform1uiv", (void*)(ptrdiff_t)glow_glUniform1uiv, location, count, value);
}
PFNGLUNIFORM1UIVPROC glow_debug_glUniform1uiv = glow_debug_impl_glUniform1uiv;

static void glow_debug_impl_glEnableVertexAttribArray(GLuint index) {

  glow_pre_callback_("glEnableVertexAttribArray", (void*)(ptrdiff_t)glow_glEnableVertexAttribArray, index);
  glow_glEnableVertexAttribArray(index);
  glow_post_callback_("glEnableVertexAttribArray", (void*)(ptrdiff_t)glow_glEnableVertexAttribArray, index);
}
PFNGLENABLEVERTEXATTRIBARRAYPROC glow_debug_glEnableVertexAttribArray = glow_debug_impl_glEnableVertexAttribArray;

static void glow_debug_impl_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetVertexAttribfv", (void*)(ptrdiff_t)glow_glGetVertexAttribfv, index, pname, params);
  glow_glGetVertexAttribfv(index, pname, params);
  glow_post_callback_("glGetVertexAttribfv", (void*)(ptrdiff_t)glow_glGetVertexAttribfv, index, pname, params);
}
PFNGLGETVERTEXATTRIBFVPROC glow_debug_glGetVertexAttribfv = glow_debug_impl_glGetVertexAttribfv;

static void glow_debug_impl_glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) {

  glow_pre_callback_("glShaderBinary", (void*)(ptrdiff_t)glow_glShaderBinary, count, shaders, binaryformat, binary, length);
  glow_glShaderBinary(count, shaders, binaryformat, binary, length);
  glow_post_callback_("glShaderBinary", (void*)(ptrdiff_t)glow_glShaderBinary, count, shaders, binaryformat, binary, length);
}
PFNGLSHADERBINARYPROC glow_debug_glShaderBinary = glow_debug_impl_glShaderBinary;

static void glow_debug_impl_glResumeTransformFeedback() {

  glow_pre_callback_("glResumeTransformFeedback", (void*)(ptrdiff_t)glow_glResumeTransformFeedback);
  glow_glResumeTransformFeedback();
  glow_post_callback_("glResumeTransformFeedback", (void*)(ptrdiff_t)glow_glResumeTransformFeedback);
}
PFNGLRESUMETRANSFORMFEEDBACKPROC glow_debug_glResumeTransformFeedback = glow_debug_impl_glResumeTransformFeedback;

static void glow_debug_impl_glFramebufferParameteri(GLenum target, GLenum pname, GLint param) {

  glow_pre_callback_("glFramebufferParameteri", (void*)(ptrdiff_t)glow_glFramebufferParameteri, target, pname, param);
  glow_glFramebufferParameteri(target, pname, param);
  glow_post_callback_("glFramebufferParameteri", (void*)(ptrdiff_t)glow_glFramebufferParameteri, target, pname, param);
}
PFNGLFRAMEBUFFERPARAMETERIPROC glow_debug_glFramebufferParameteri = glow_debug_impl_glFramebufferParameteri;

static void glow_debug_impl_glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params) {

  glow_pre_callback_("glTexParameterIuiv", (void*)(ptrdiff_t)glow_glTexParameterIuiv, target, pname, params);
  glow_glTexParameterIuiv(target, pname, params);
  glow_post_callback_("glTexParameterIuiv", (void*)(ptrdiff_t)glow_glTexParameterIuiv, target, pname, params);
}
PFNGLTEXPARAMETERIUIVPROC glow_debug_glTexParameterIuiv = glow_debug_impl_glTexParameterIuiv;

static void glow_debug_impl_glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetActiveUniformsiv", (void*)(ptrdiff_t)glow_glGetActiveUniformsiv, program, uniformCount, uniformIndices, pname, params);
  glow_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
  glow_post_callback_("glGetActiveUniformsiv", (void*)(ptrdiff_t)glow_glGetActiveUniformsiv, program, uniformCount, uniformIndices, pname, params);
}
PFNGLGETACTIVEUNIFORMSIVPROC glow_debug_glGetActiveUniformsiv = glow_debug_impl_glGetActiveUniformsiv;

static void glow_debug_impl_glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetActiveUniformBlockiv", (void*)(ptrdiff_t)glow_glGetActiveUniformBlockiv, program, uniformBlockIndex, pname, params);
  glow_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
  glow_post_callback_("glGetActiveUniformBlockiv", (void*)(ptrdiff_t)glow_glGetActiveUniformBlockiv, program, uniformBlockIndex, pname, params);
}
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glow_debug_glGetActiveUniformBlockiv = glow_debug_impl_glGetActiveUniformBlockiv;

static GLsync glow_debug_impl_glFenceSync(GLenum condition, GLbitfield flags) {

  GLsync ret;
  glow_pre_callback_("glFenceSync", (void*)(ptrdiff_t)glow_glFenceSync, condition, flags);
  ret = glow_glFenceSync(condition, flags);
  glow_post_callback_("glFenceSync", (void*)(ptrdiff_t)glow_glFenceSync, condition, flags);
  return ret;
}
PFNGLFENCESYNCPROC glow_debug_glFenceSync = glow_debug_impl_glFenceSync;

static void glow_debug_impl_glGetIntegerv(GLenum pname, GLint *data) {

  glow_pre_callback_("glGetIntegerv", (void*)(ptrdiff_t)glow_glGetIntegerv, pname, data);
  glow_glGetIntegerv(pname, data);
  glow_post_callback_("glGetIntegerv", (void*)(ptrdiff_t)glow_glGetIntegerv, pname, data);
}
PFNGLGETINTEGERVPROC glow_debug_glGetIntegerv = glow_debug_impl_glGetIntegerv;

static GLboolean glow_debug_impl_glIsEnabled(GLenum cap) {

  GLboolean ret;
  glow_pre_callback_("glIsEnabled", (void*)(ptrdiff_t)glow_glIsEnabled, cap);
  ret = glow_glIsEnabled(cap);
  glow_post_callback_("glIsEnabled", (void*)(ptrdiff_t)glow_glIsEnabled, cap);
  return ret;
}
PFNGLISENABLEDPROC glow_debug_glIsEnabled = glow_debug_impl_glIsEnabled;

static void glow_debug_impl_glLineWidth(GLfloat width) {

  glow_pre_callback_("glLineWidth", (void*)(ptrdiff_t)glow_glLineWidth, width);
  glow_glLineWidth(width);
  glow_post_callback_("glLineWidth", (void*)(ptrdiff_t)glow_glLineWidth, width);
}
PFNGLLINEWIDTHPROC glow_debug_glLineWidth = glow_debug_impl_glLineWidth;

static void glow_debug_impl_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {

  glow_pre_callback_("glVertexAttrib3f", (void*)(ptrdiff_t)glow_glVertexAttrib3f, index, x, y, z);
  glow_glVertexAttrib3f(index, x, y, z);
  glow_post_callback_("glVertexAttrib3f", (void*)(ptrdiff_t)glow_glVertexAttrib3f, index, x, y, z);
}
PFNGLVERTEXATTRIB3FPROC glow_debug_glVertexAttrib3f = glow_debug_impl_glVertexAttrib3f;

static void glow_debug_impl_glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params) {

  glow_pre_callback_("glGetTexParameterIuiv", (void*)(ptrdiff_t)glow_glGetTexParameterIuiv, target, pname, params);
  glow_glGetTexParameterIuiv(target, pname, params);
  glow_post_callback_("glGetTexParameterIuiv", (void*)(ptrdiff_t)glow_glGetTexParameterIuiv, target, pname, params);
}
PFNGLGETTEXPARAMETERIUIVPROC glow_debug_glGetTexParameterIuiv = glow_debug_impl_glGetTexParameterIuiv;

static void glow_debug_impl_glFlush() {

  glow_pre_callback_("glFlush", (void*)(ptrdiff_t)glow_glFlush);
  glow_glFlush();
  glow_post_callback_("glFlush", (void*)(ptrdiff_t)glow_glFlush);
}
PFNGLFLUSHPROC glow_debug_glFlush = glow_debug_impl_glFlush;

static void glow_debug_impl_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {

  glow_pre_callback_("glFramebufferRenderbuffer", (void*)(ptrdiff_t)glow_glFramebufferRenderbuffer, target, attachment, renderbuffertarget, renderbuffer);
  glow_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
  glow_post_callback_("glFramebufferRenderbuffer", (void*)(ptrdiff_t)glow_glFramebufferRenderbuffer, target, attachment, renderbuffertarget, renderbuffer);
}
PFNGLFRAMEBUFFERRENDERBUFFERPROC glow_debug_glFramebufferRenderbuffer = glow_debug_impl_glFramebufferRenderbuffer;

static void glow_debug_impl_glGenBuffers(GLsizei n, GLuint *buffers) {

  glow_pre_callback_("glGenBuffers", (void*)(ptrdiff_t)glow_glGenBuffers, n, buffers);
  glow_glGenBuffers(n, buffers);
  glow_post_callback_("glGenBuffers", (void*)(ptrdiff_t)glow_glGenBuffers, n, buffers);
}
PFNGLGENBUFFERSPROC glow_debug_glGenBuffers = glow_debug_impl_glGenBuffers;

static void glow_debug_impl_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) {

  glow_pre_callback_("glGetAttachedShaders", (void*)(ptrdiff_t)glow_glGetAttachedShaders, program, maxCount, count, shaders);
  glow_glGetAttachedShaders(program, maxCount, count, shaders);
  glow_post_callback_("glGetAttachedShaders", (void*)(ptrdiff_t)glow_glGetAttachedShaders, program, maxCount, count, shaders);
}
PFNGLGETATTACHEDSHADERSPROC glow_debug_glGetAttachedShaders = glow_debug_impl_glGetAttachedShaders;

static void glow_debug_impl_glDrawBuffers(GLsizei n, const GLenum *bufs) {

  glow_pre_callback_("glDrawBuffers", (void*)(ptrdiff_t)glow_glDrawBuffers, n, bufs);
  glow_glDrawBuffers(n, bufs);
  glow_post_callback_("glDrawBuffers", (void*)(ptrdiff_t)glow_glDrawBuffers, n, bufs);
}
PFNGLDRAWBUFFERSPROC glow_debug_glDrawBuffers = glow_debug_impl_glDrawBuffers;

static void glow_debug_impl_glUniform4uiv(GLint location, GLsizei count, const GLuint *value) {

  glow_pre_callback_("glUniform4uiv", (void*)(ptrdiff_t)glow_glUniform4uiv, location, count, value);
  glow_glUniform4uiv(location, count, value);
  glow_post_callback_("glUniform4uiv", (void*)(ptrdiff_t)glow_glUniform4uiv, location, count, value);
}
PFNGLUNIFORM4UIVPROC glow_debug_glUniform4uiv = glow_debug_impl_glUniform4uiv;

static void glow_debug_impl_glPauseTransformFeedback() {

  glow_pre_callback_("glPauseTransformFeedback", (void*)(ptrdiff_t)glow_glPauseTransformFeedback);
  glow_glPauseTransformFeedback();
  glow_post_callback_("glPauseTransformFeedback", (void*)(ptrdiff_t)glow_glPauseTransformFeedback);
}
PFNGLPAUSETRANSFORMFEEDBACKPROC glow_debug_glPauseTransformFeedback = glow_debug_impl_glPauseTransformFeedback;

static void glow_debug_impl_glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {

  glow_pre_callback_("glBindVertexBuffer", (void*)(ptrdiff_t)glow_glBindVertexBuffer, bindingindex, buffer, offset, stride);
  glow_glBindVertexBuffer(bindingindex, buffer, offset, stride);
  glow_post_callback_("glBindVertexBuffer", (void*)(ptrdiff_t)glow_glBindVertexBuffer, bindingindex, buffer, offset, stride);
}
PFNGLBINDVERTEXBUFFERPROC glow_debug_glBindVertexBuffer = glow_debug_impl_glBindVertexBuffer;

static void glow_debug_impl_glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message) {

  glow_pre_callback_("glPushDebugGroup", (void*)(ptrdiff_t)glow_glPushDebugGroup, source, id, length, message);
  glow_glPushDebugGroup(source, id, length, message);
  glow_post_callback_("glPushDebugGroup", (void*)(ptrdiff_t)glow_glPushDebugGroup, source, id, length, message);
}
PFNGLPUSHDEBUGGROUPPROC glow_debug_glPushDebugGroup = glow_debug_impl_glPushDebugGroup;

static void glow_debug_impl_glUniform2iv(GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glUniform2iv", (void*)(ptrdiff_t)glow_glUniform2iv, location, count, value);
  glow_glUniform2iv(location, count, value);
  glow_post_callback_("glUniform2iv", (void*)(ptrdiff_t)glow_glUniform2iv, location, count, value);
}
PFNGLUNIFORM2IVPROC glow_debug_glUniform2iv = glow_debug_impl_glUniform2iv;

static void glow_debug_impl_glUniform4fv(GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glUniform4fv", (void*)(ptrdiff_t)glow_glUniform4fv, location, count, value);
  glow_glUniform4fv(location, count, value);
  glow_post_callback_("glUniform4fv", (void*)(ptrdiff_t)glow_glUniform4fv, location, count, value);
}
PFNGLUNIFORM4FVPROC glow_debug_glUniform4fv = glow_debug_impl_glUniform4fv;

static void glow_debug_impl_glBindTransformFeedback(GLenum target, GLuint id) {

  glow_pre_callback_("glBindTransformFeedback", (void*)(ptrdiff_t)glow_glBindTransformFeedback, target, id);
  glow_glBindTransformFeedback(target, id);
  glow_post_callback_("glBindTransformFeedback", (void*)(ptrdiff_t)glow_glBindTransformFeedback, target, id);
}
PFNGLBINDTRANSFORMFEEDBACKPROC glow_debug_glBindTransformFeedback = glow_debug_impl_glBindTransformFeedback;

static void glow_debug_impl_glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glProgramUniform2iv", (void*)(ptrdiff_t)glow_glProgramUniform2iv, program, location, count, value);
  glow_glProgramUniform2iv(program, location, count, value);
  glow_post_callback_("glProgramUniform2iv", (void*)(ptrdiff_t)glow_glProgramUniform2iv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM2IVPROC glow_debug_glProgramUniform2iv = glow_debug_impl_glProgramUniform2iv;

static void glow_debug_impl_glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) {

  glow_pre_callback_("glGetMultisamplefv", (void*)(ptrdiff_t)glow_glGetMultisamplefv, pname, index, val);
  glow_glGetMultisamplefv(pname, index, val);
  glow_post_callback_("glGetMultisamplefv", (void*)(ptrdiff_t)glow_glGetMultisamplefv, pname, index, val);
}
PFNGLGETMULTISAMPLEFVPROC glow_debug_glGetMultisamplefv = glow_debug_impl_glGetMultisamplefv;

static void glow_debug_impl_glGetShaderiv(GLuint shader, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetShaderiv", (void*)(ptrdiff_t)glow_glGetShaderiv, shader, pname, params);
  glow_glGetShaderiv(shader, pname, params);
  glow_post_callback_("glGetShaderiv", (void*)(ptrdiff_t)glow_glGetShaderiv, shader, pname, params);
}
PFNGLGETSHADERIVPROC glow_debug_glGetShaderiv = glow_debug_impl_glGetShaderiv;

static void glow_debug_impl_glUniform4iv(GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glUniform4iv", (void*)(ptrdiff_t)glow_glUniform4iv, location, count, value);
  glow_glUniform4iv(location, count, value);
  glow_post_callback_("glUniform4iv", (void*)(ptrdiff_t)glow_glUniform4iv, location, count, value);
}
PFNGLUNIFORM4IVPROC glow_debug_glUniform4iv = glow_debug_impl_glUniform4iv;

static void glow_debug_impl_glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params) {

  glow_pre_callback_("glGetBufferParameteri64v", (void*)(ptrdiff_t)glow_glGetBufferParameteri64v, target, pname, params);
  glow_glGetBufferParameteri64v(target, pname, params);
  glow_post_callback_("glGetBufferParameteri64v", (void*)(ptrdiff_t)glow_glGetBufferParameteri64v, target, pname, params);
}
PFNGLGETBUFFERPARAMETERI64VPROC glow_debug_glGetBufferParameteri64v = glow_debug_impl_glGetBufferParameteri64v;

static void glow_debug_impl_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix2fv", (void*)(ptrdiff_t)glow_glUniformMatrix2fv, location, count, transpose, value);
  glow_glUniformMatrix2fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix2fv", (void*)(ptrdiff_t)glow_glUniformMatrix2fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2FVPROC glow_debug_glUniformMatrix2fv = glow_debug_impl_glUniformMatrix2fv;

static void glow_debug_impl_glUniform3uiv(GLint location, GLsizei count, const GLuint *value) {

  glow_pre_callback_("glUniform3uiv", (void*)(ptrdiff_t)glow_glUniform3uiv, location, count, value);
  glow_glUniform3uiv(location, count, value);
  glow_post_callback_("glUniform3uiv", (void*)(ptrdiff_t)glow_glUniform3uiv, location, count, value);
}
PFNGLUNIFORM3UIVPROC glow_debug_glUniform3uiv = glow_debug_impl_glUniform3uiv;

static void glow_debug_impl_glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) {

  glow_pre_callback_("glGetProgramResourceName", (void*)(ptrdiff_t)glow_glGetProgramResourceName, program, programInterface, index, bufSize, length, name);
  glow_glGetProgramResourceName(program, programInterface, index, bufSize, length, name);
  glow_post_callback_("glGetProgramResourceName", (void*)(ptrdiff_t)glow_glGetProgramResourceName, program, programInterface, index, bufSize, length, name);
}
PFNGLGETPROGRAMRESOURCENAMEPROC glow_debug_glGetProgramResourceName = glow_debug_impl_glGetProgramResourceName;

static void glow_debug_impl_glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {

  glow_pre_callback_("glProgramUniform4i", (void*)(ptrdiff_t)glow_glProgramUniform4i, program, location, v0, v1, v2, v3);
  glow_glProgramUniform4i(program, location, v0, v1, v2, v3);
  glow_post_callback_("glProgramUniform4i", (void*)(ptrdiff_t)glow_glProgramUniform4i, program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4IPROC glow_debug_glProgramUniform4i = glow_debug_impl_glProgramUniform4i;

static void glow_debug_impl_glProgramUniform1f(GLuint program, GLint location, GLfloat v0) {

  glow_pre_callback_("glProgramUniform1f", (void*)(ptrdiff_t)glow_glProgramUniform1f, program, location, v0);
  glow_glProgramUniform1f(program, location, v0);
  glow_post_callback_("glProgramUniform1f", (void*)(ptrdiff_t)glow_glProgramUniform1f, program, location, v0);
}
PFNGLPROGRAMUNIFORM1FPROC glow_debug_glProgramUniform1f = glow_debug_impl_glProgramUniform1f;

static void glow_debug_impl_glCullFace(GLenum mode) {

  glow_pre_callback_("glCullFace", (void*)(ptrdiff_t)glow_glCullFace, mode);
  glow_glCullFace(mode);
  glow_post_callback_("glCullFace", (void*)(ptrdiff_t)glow_glCullFace, mode);
}
PFNGLCULLFACEPROC glow_debug_glCullFace = glow_debug_impl_glCullFace;

static void glow_debug_impl_glDepthRangef(GLfloat n, GLfloat f) {

  glow_pre_callback_("glDepthRangef", (void*)(ptrdiff_t)glow_glDepthRangef, n, f);
  glow_glDepthRangef(n, f);
  glow_post_callback_("glDepthRangef", (void*)(ptrdiff_t)glow_glDepthRangef, n, f);
}
PFNGLDEPTHRANGEFPROC glow_debug_glDepthRangef = glow_debug_impl_glDepthRangef;

static void glow_debug_impl_glSampleCoverage(GLfloat value, GLboolean invert) {

  glow_pre_callback_("glSampleCoverage", (void*)(ptrdiff_t)glow_glSampleCoverage, value, invert);
  glow_glSampleCoverage(value, invert);
  glow_post_callback_("glSampleCoverage", (void*)(ptrdiff_t)glow_glSampleCoverage, value, invert);
}
PFNGLSAMPLECOVERAGEPROC glow_debug_glSampleCoverage = glow_debug_impl_glSampleCoverage;

static void glow_debug_impl_glPrimitiveBoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) {

  glow_pre_callback_("glPrimitiveBoundingBox", (void*)(ptrdiff_t)glow_glPrimitiveBoundingBox, minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
  glow_glPrimitiveBoundingBox(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
  glow_post_callback_("glPrimitiveBoundingBox", (void*)(ptrdiff_t)glow_glPrimitiveBoundingBox, minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
PFNGLPRIMITIVEBOUNDINGBOXPROC glow_debug_glPrimitiveBoundingBox = glow_debug_impl_glPrimitiveBoundingBox;

static void glow_debug_impl_glBeginTransformFeedback(GLenum primitiveMode) {

  glow_pre_callback_("glBeginTransformFeedback", (void*)(ptrdiff_t)glow_glBeginTransformFeedback, primitiveMode);
  glow_glBeginTransformFeedback(primitiveMode);
  glow_post_callback_("glBeginTransformFeedback", (void*)(ptrdiff_t)glow_glBeginTransformFeedback, primitiveMode);
}
PFNGLBEGINTRANSFORMFEEDBACKPROC glow_debug_glBeginTransformFeedback = glow_debug_impl_glBeginTransformFeedback;

static void glow_debug_impl_glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) {

  glow_pre_callback_("glClearBufferfv", (void*)(ptrdiff_t)glow_glClearBufferfv, buffer, drawbuffer, value);
  glow_glClearBufferfv(buffer, drawbuffer, value);
  glow_post_callback_("glClearBufferfv", (void*)(ptrdiff_t)glow_glClearBufferfv, buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERFVPROC glow_debug_glClearBufferfv = glow_debug_impl_glClearBufferfv;

static void glow_debug_impl_glGetPointerv(GLenum pname, void **params) {

  glow_pre_callback_("glGetPointerv", (void*)(ptrdiff_t)glow_glGetPointerv, pname, params);
  glow_glGetPointerv(pname, params);
  glow_post_callback_("glGetPointerv", (void*)(ptrdiff_t)glow_glGetPointerv, pname, params);
}
PFNGLGETPOINTERVPROC glow_debug_glGetPointerv = glow_debug_impl_glGetPointerv;

static void glow_debug_impl_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glTexSubImage3D", (void*)(ptrdiff_t)glow_glTexSubImage3D, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
  glow_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
  glow_post_callback_("glTexSubImage3D", (void*)(ptrdiff_t)glow_glTexSubImage3D, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
PFNGLTEXSUBIMAGE3DPROC glow_debug_glTexSubImage3D = glow_debug_impl_glTexSubImage3D;

static void glow_debug_impl_glUniform1ui(GLint location, GLuint v0) {

  glow_pre_callback_("glUniform1ui", (void*)(ptrdiff_t)glow_glUniform1ui, location, v0);
  glow_glUniform1ui(location, v0);
  glow_post_callback_("glUniform1ui", (void*)(ptrdiff_t)glow_glUniform1ui, location, v0);
}
PFNGLUNIFORM1UIPROC glow_debug_glUniform1ui = glow_debug_impl_glUniform1ui;

static void glow_debug_impl_glActiveTexture(GLenum texture) {

  glow_pre_callback_("glActiveTexture", (void*)(ptrdiff_t)glow_glActiveTexture, texture);
  glow_glActiveTexture(texture);
  glow_post_callback_("glActiveTexture", (void*)(ptrdiff_t)glow_glActiveTexture, texture);
}
PFNGLACTIVETEXTUREPROC glow_debug_glActiveTexture = glow_debug_impl_glActiveTexture;

static void glow_debug_impl_glAttachShader(GLuint program, GLuint shader) {

  glow_pre_callback_("glAttachShader", (void*)(ptrdiff_t)glow_glAttachShader, program, shader);
  glow_glAttachShader(program, shader);
  glow_post_callback_("glAttachShader", (void*)(ptrdiff_t)glow_glAttachShader, program, shader);
}
PFNGLATTACHSHADERPROC glow_debug_glAttachShader = glow_debug_impl_glAttachShader;

static void glow_debug_impl_glGetFloatv(GLenum pname, GLfloat *data) {

  glow_pre_callback_("glGetFloatv", (void*)(ptrdiff_t)glow_glGetFloatv, pname, data);
  glow_glGetFloatv(pname, data);
  glow_post_callback_("glGetFloatv", (void*)(ptrdiff_t)glow_glGetFloatv, pname, data);
}
PFNGLGETFLOATVPROC glow_debug_glGetFloatv = glow_debug_impl_glGetFloatv;

static void glow_debug_impl_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glCopyTexSubImage3D", (void*)(ptrdiff_t)glow_glCopyTexSubImage3D, target, level, xoffset, yoffset, zoffset, x, y, width, height);
  glow_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
  glow_post_callback_("glCopyTexSubImage3D", (void*)(ptrdiff_t)glow_glCopyTexSubImage3D, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE3DPROC glow_debug_glCopyTexSubImage3D = glow_debug_impl_glCopyTexSubImage3D;

static void glow_debug_impl_glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix3x2fv", (void*)(ptrdiff_t)glow_glUniformMatrix3x2fv, location, count, transpose, value);
  glow_glUniformMatrix3x2fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix3x2fv", (void*)(ptrdiff_t)glow_glUniformMatrix3x2fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X2FVPROC glow_debug_glUniformMatrix3x2fv = glow_debug_impl_glUniformMatrix3x2fv;

static void glow_debug_impl_glBindSampler(GLuint unit, GLuint sampler) {

  glow_pre_callback_("glBindSampler", (void*)(ptrdiff_t)glow_glBindSampler, unit, sampler);
  glow_glBindSampler(unit, sampler);
  glow_post_callback_("glBindSampler", (void*)(ptrdiff_t)glow_glBindSampler, unit, sampler);
}
PFNGLBINDSAMPLERPROC glow_debug_glBindSampler = glow_debug_impl_glBindSampler;

static void glow_debug_impl_glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) {

  glow_pre_callback_("glVertexAttribBinding", (void*)(ptrdiff_t)glow_glVertexAttribBinding, attribindex, bindingindex);
  glow_glVertexAttribBinding(attribindex, bindingindex);
  glow_post_callback_("glVertexAttribBinding", (void*)(ptrdiff_t)glow_glVertexAttribBinding, attribindex, bindingindex);
}
PFNGLVERTEXATTRIBBINDINGPROC glow_debug_glVertexAttribBinding = glow_debug_impl_glVertexAttribBinding;

static void glow_debug_impl_glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers) {

  glow_pre_callback_("glDeleteFramebuffers", (void*)(ptrdiff_t)glow_glDeleteFramebuffers, n, framebuffers);
  glow_glDeleteFramebuffers(n, framebuffers);
  glow_post_callback_("glDeleteFramebuffers", (void*)(ptrdiff_t)glow_glDeleteFramebuffers, n, framebuffers);
}
PFNGLDELETEFRAMEBUFFERSPROC glow_debug_glDeleteFramebuffers = glow_debug_impl_glDeleteFramebuffers;

static GLenum glow_debug_impl_glGetError() {

  GLenum ret;
  glow_pre_callback_("glGetError", (void*)(ptrdiff_t)glow_glGetError);
  ret = glow_glGetError();
  glow_post_callback_("glGetError", (void*)(ptrdiff_t)glow_glGetError);
  return ret;
}
PFNGLGETERRORPROC glow_debug_glGetError = glow_debug_impl_glGetError;

static void glow_debug_impl_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glTexParameterfv", (void*)(ptrdiff_t)glow_glTexParameterfv, target, pname, params);
  glow_glTexParameterfv(target, pname, params);
  glow_post_callback_("glTexParameterfv", (void*)(ptrdiff_t)glow_glTexParameterfv, target, pname, params);
}
PFNGLTEXPARAMETERFVPROC glow_debug_glTexParameterfv = glow_debug_impl_glTexParameterfv;

static void glow_debug_impl_glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {

  glow_pre_callback_("glDrawArraysInstanced", (void*)(ptrdiff_t)glow_glDrawArraysInstanced, mode, first, count, instancecount);
  glow_glDrawArraysInstanced(mode, first, count, instancecount);
  glow_post_callback_("glDrawArraysInstanced", (void*)(ptrdiff_t)glow_glDrawArraysInstanced, mode, first, count, instancecount);
}
PFNGLDRAWARRAYSINSTANCEDPROC glow_debug_glDrawArraysInstanced = glow_debug_impl_glDrawArraysInstanced;

static void glow_debug_impl_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {

  glow_pre_callback_("glBlendFuncSeparate", (void*)(ptrdiff_t)glow_glBlendFuncSeparate, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
  glow_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
  glow_post_callback_("glBlendFuncSeparate", (void*)(ptrdiff_t)glow_glBlendFuncSeparate, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
PFNGLBLENDFUNCSEPARATEPROC glow_debug_glBlendFuncSeparate = glow_debug_impl_glBlendFuncSeparate;

static void glow_debug_impl_glGenVertexArrays(GLsizei n, GLuint *arrays) {

  glow_pre_callback_("glGenVertexArrays", (void*)(ptrdiff_t)glow_glGenVertexArrays, n, arrays);
  glow_glGenVertexArrays(n, arrays);
  glow_post_callback_("glGenVertexArrays", (void*)(ptrdiff_t)glow_glGenVertexArrays, n, arrays);
}
PFNGLGENVERTEXARRAYSPROC glow_debug_glGenVertexArrays = glow_debug_impl_glGenVertexArrays;

static GLboolean glow_debug_impl_glIsVertexArray(GLuint array) {

  GLboolean ret;
  glow_pre_callback_("glIsVertexArray", (void*)(ptrdiff_t)glow_glIsVertexArray, array);
  ret = glow_glIsVertexArray(array);
  glow_post_callback_("glIsVertexArray", (void*)(ptrdiff_t)glow_glIsVertexArray, array);
  return ret;
}
PFNGLISVERTEXARRAYPROC glow_debug_glIsVertexArray = glow_debug_impl_glIsVertexArray;

static void glow_debug_impl_glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {

  glow_pre_callback_("glWaitSync", (void*)(ptrdiff_t)glow_glWaitSync, sync, flags, timeout);
  glow_glWaitSync(sync, flags, timeout);
  glow_post_callback_("glWaitSync", (void*)(ptrdiff_t)glow_glWaitSync, sync, flags, timeout);
}
PFNGLWAITSYNCPROC glow_debug_glWaitSync = glow_debug_impl_glWaitSync;

static void glow_debug_impl_glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {

  glow_pre_callback_("glProgramUniform4ui", (void*)(ptrdiff_t)glow_glProgramUniform4ui, program, location, v0, v1, v2, v3);
  glow_glProgramUniform4ui(program, location, v0, v1, v2, v3);
  glow_post_callback_("glProgramUniform4ui", (void*)(ptrdiff_t)glow_glProgramUniform4ui, program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4UIPROC glow_debug_glProgramUniform4ui = glow_debug_impl_glProgramUniform4ui;

static void glow_debug_impl_glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glProgramUniformMatrix2fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix2fv, program, location, count, transpose, value);
  glow_glProgramUniformMatrix2fv(program, location, count, transpose, value);
  glow_post_callback_("glProgramUniformMatrix2fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix2fv, program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glow_debug_glProgramUniformMatrix2fv = glow_debug_impl_glProgramUniformMatrix2fv;

static void glow_debug_impl_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetTexParameteriv", (void*)(ptrdiff_t)glow_glGetTexParameteriv, target, pname, params);
  glow_glGetTexParameteriv(target, pname, params);
  glow_post_callback_("glGetTexParameteriv", (void*)(ptrdiff_t)glow_glGetTexParameteriv, target, pname, params);
}
PFNGLGETTEXPARAMETERIVPROC glow_debug_glGetTexParameteriv = glow_debug_impl_glGetTexParameteriv;

static void glow_debug_impl_glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer) {

  glow_pre_callback_("glGetVertexAttribPointerv", (void*)(ptrdiff_t)glow_glGetVertexAttribPointerv, index, pname, pointer);
  glow_glGetVertexAttribPointerv(index, pname, pointer);
  glow_post_callback_("glGetVertexAttribPointerv", (void*)(ptrdiff_t)glow_glGetVertexAttribPointerv, index, pname, pointer);
}
PFNGLGETVERTEXATTRIBPOINTERVPROC glow_debug_glGetVertexAttribPointerv = glow_debug_impl_glGetVertexAttribPointerv;

static void glow_debug_impl_glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) {

  glow_pre_callback_("glGetTransformFeedbackVarying", (void*)(ptrdiff_t)glow_glGetTransformFeedbackVarying, program, index, bufSize, length, size, type, name);
  glow_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
  glow_post_callback_("glGetTransformFeedbackVarying", (void*)(ptrdiff_t)glow_glGetTransformFeedbackVarying, program, index, bufSize, length, size, type, name);
}
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glow_debug_glGetTransformFeedbackVarying = glow_debug_impl_glGetTransformFeedbackVarying;

static void glow_debug_impl_glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {

  glow_pre_callback_("glUniform3ui", (void*)(ptrdiff_t)glow_glUniform3ui, location, v0, v1, v2);
  glow_glUniform3ui(location, v0, v1, v2);
  glow_post_callback_("glUniform3ui", (void*)(ptrdiff_t)glow_glUniform3ui, location, v0, v1, v2);
}
PFNGLUNIFORM3UIPROC glow_debug_glUniform3ui = glow_debug_impl_glUniform3ui;

static void glow_debug_impl_glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) {

  glow_pre_callback_("glGetSynciv", (void*)(ptrdiff_t)glow_glGetSynciv, sync, pname, bufSize, length, values);
  glow_glGetSynciv(sync, pname, bufSize, length, values);
  glow_post_callback_("glGetSynciv", (void*)(ptrdiff_t)glow_glGetSynciv, sync, pname, bufSize, length, values);
}
PFNGLGETSYNCIVPROC glow_debug_glGetSynciv = glow_debug_impl_glGetSynciv;

static void glow_debug_impl_glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {

  glow_pre_callback_("glProgramUniform4f", (void*)(ptrdiff_t)glow_glProgramUniform4f, program, location, v0, v1, v2, v3);
  glow_glProgramUniform4f(program, location, v0, v1, v2, v3);
  glow_post_callback_("glProgramUniform4f", (void*)(ptrdiff_t)glow_glProgramUniform4f, program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4FPROC glow_debug_glProgramUniform4f = glow_debug_impl_glProgramUniform4f;

static void glow_debug_impl_glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) {

  glow_pre_callback_("glProgramUniform3iv", (void*)(ptrdiff_t)glow_glProgramUniform3iv, program, location, count, value);
  glow_glProgramUniform3iv(program, location, count, value);
  glow_post_callback_("glProgramUniform3iv", (void*)(ptrdiff_t)glow_glProgramUniform3iv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM3IVPROC glow_debug_glProgramUniform3iv = glow_debug_impl_glProgramUniform3iv;

static void glow_debug_impl_glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) {

  glow_pre_callback_("glDebugMessageInsert", (void*)(ptrdiff_t)glow_glDebugMessageInsert, source, type, id, severity, length, buf);
  glow_glDebugMessageInsert(source, type, id, severity, length, buf);
  glow_post_callback_("glDebugMessageInsert", (void*)(ptrdiff_t)glow_glDebugMessageInsert, source, type, id, severity, length, buf);
}
PFNGLDEBUGMESSAGEINSERTPROC glow_debug_glDebugMessageInsert = glow_debug_impl_glDebugMessageInsert;

static void glow_debug_impl_glGenerateMipmap(GLenum target) {

  glow_pre_callback_("glGenerateMipmap", (void*)(ptrdiff_t)glow_glGenerateMipmap, target);
  glow_glGenerateMipmap(target);
  glow_post_callback_("glGenerateMipmap", (void*)(ptrdiff_t)glow_glGenerateMipmap, target);
}
PFNGLGENERATEMIPMAPPROC glow_debug_glGenerateMipmap = glow_debug_impl_glGenerateMipmap;

static void glow_debug_impl_glGetUniformiv(GLuint program, GLint location, GLint *params) {

  glow_pre_callback_("glGetUniformiv", (void*)(ptrdiff_t)glow_glGetUniformiv, program, location, params);
  glow_glGetUniformiv(program, location, params);
  glow_post_callback_("glGetUniformiv", (void*)(ptrdiff_t)glow_glGetUniformiv, program, location, params);
}
PFNGLGETUNIFORMIVPROC glow_debug_glGetUniformiv = glow_debug_impl_glGetUniformiv;

static void glow_debug_impl_glTexParameteri(GLenum target, GLenum pname, GLint param) {

  glow_pre_callback_("glTexParameteri", (void*)(ptrdiff_t)glow_glTexParameteri, target, pname, param);
  glow_glTexParameteri(target, pname, param);
  glow_post_callback_("glTexParameteri", (void*)(ptrdiff_t)glow_glTexParameteri, target, pname, param);
}
PFNGLTEXPARAMETERIPROC glow_debug_glTexParameteri = glow_debug_impl_glTexParameteri;

static void glow_debug_impl_glPopDebugGroup() {

  glow_pre_callback_("glPopDebugGroup", (void*)(ptrdiff_t)glow_glPopDebugGroup);
  glow_glPopDebugGroup();
  glow_post_callback_("glPopDebugGroup", (void*)(ptrdiff_t)glow_glPopDebugGroup);
}
PFNGLPOPDEBUGGROUPPROC glow_debug_glPopDebugGroup = glow_debug_impl_glPopDebugGroup;

static void glow_debug_impl_glGetObjectPtrLabel(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) {

  glow_pre_callback_("glGetObjectPtrLabel", (void*)(ptrdiff_t)glow_glGetObjectPtrLabel, ptr, bufSize, length, label);
  glow_glGetObjectPtrLabel(ptr, bufSize, length, label);
  glow_post_callback_("glGetObjectPtrLabel", (void*)(ptrdiff_t)glow_glGetObjectPtrLabel, ptr, bufSize, length, label);
}
PFNGLGETOBJECTPTRLABELPROC glow_debug_glGetObjectPtrLabel = glow_debug_impl_glGetObjectPtrLabel;

static GLubyte glow_debug_impl_glGetString(GLenum name) {

  GLubyte ret;
  glow_pre_callback_("glGetString", (void*)(ptrdiff_t)glow_glGetString, name);
  ret = glow_glGetString(name);
  glow_post_callback_("glGetString", (void*)(ptrdiff_t)glow_glGetString, name);
  return ret;
}
PFNGLGETSTRINGPROC glow_debug_glGetString = glow_debug_impl_glGetString;

static void glow_debug_impl_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {

  glow_pre_callback_("glStencilFuncSeparate", (void*)(ptrdiff_t)glow_glStencilFuncSeparate, face, func, ref, mask);
  glow_glStencilFuncSeparate(face, func, ref, mask);
  glow_post_callback_("glStencilFuncSeparate", (void*)(ptrdiff_t)glow_glStencilFuncSeparate, face, func, ref, mask);
}
PFNGLSTENCILFUNCSEPARATEPROC glow_debug_glStencilFuncSeparate = glow_debug_impl_glStencilFuncSeparate;

static void glow_debug_impl_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {

  glow_pre_callback_("glUniform3f", (void*)(ptrdiff_t)glow_glUniform3f, location, v0, v1, v2);
  glow_glUniform3f(location, v0, v1, v2);
  glow_post_callback_("glUniform3f", (void*)(ptrdiff_t)glow_glUniform3f, location, v0, v1, v2);
}
PFNGLUNIFORM3FPROC glow_debug_glUniform3f = glow_debug_impl_glUniform3f;

static void glow_debug_impl_glBindFramebuffer(GLenum target, GLuint framebuffer) {

  glow_pre_callback_("glBindFramebuffer", (void*)(ptrdiff_t)glow_glBindFramebuffer, target, framebuffer);
  glow_glBindFramebuffer(target, framebuffer);
  glow_post_callback_("glBindFramebuffer", (void*)(ptrdiff_t)glow_glBindFramebuffer, target, framebuffer);
}
PFNGLBINDFRAMEBUFFERPROC glow_debug_glBindFramebuffer = glow_debug_impl_glBindFramebuffer;

static void glow_debug_impl_glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {

  glow_pre_callback_("glBlendColor", (void*)(ptrdiff_t)glow_glBlendColor, red, green, blue, alpha);
  glow_glBlendColor(red, green, blue, alpha);
  glow_post_callback_("glBlendColor", (void*)(ptrdiff_t)glow_glBlendColor, red, green, blue, alpha);
}
PFNGLBLENDCOLORPROC glow_debug_glBlendColor = glow_debug_impl_glBlendColor;

static void glow_debug_impl_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {

  glow_pre_callback_("glBlendEquationSeparate", (void*)(ptrdiff_t)glow_glBlendEquationSeparate, modeRGB, modeAlpha);
  glow_glBlendEquationSeparate(modeRGB, modeAlpha);
  glow_post_callback_("glBlendEquationSeparate", (void*)(ptrdiff_t)glow_glBlendEquationSeparate, modeRGB, modeAlpha);
}
PFNGLBLENDEQUATIONSEPARATEPROC glow_debug_glBlendEquationSeparate = glow_debug_impl_glBlendEquationSeparate;

static void glow_debug_impl_glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label) {

  glow_pre_callback_("glObjectLabel", (void*)(ptrdiff_t)glow_glObjectLabel, identifier, name, length, label);
  glow_glObjectLabel(identifier, name, length, label);
  glow_post_callback_("glObjectLabel", (void*)(ptrdiff_t)glow_glObjectLabel, identifier, name, length, label);
}
PFNGLOBJECTLABELPROC glow_debug_glObjectLabel = glow_debug_impl_glObjectLabel;

static void glow_debug_impl_glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) {

  glow_pre_callback_("glGetObjectLabel", (void*)(ptrdiff_t)glow_glGetObjectLabel, identifier, name, bufSize, length, label);
  glow_glGetObjectLabel(identifier, name, bufSize, length, label);
  glow_post_callback_("glGetObjectLabel", (void*)(ptrdiff_t)glow_glGetObjectLabel, identifier, name, bufSize, length, label);
}
PFNGLGETOBJECTLABELPROC glow_debug_glGetObjectLabel = glow_debug_impl_glGetObjectLabel;

static GLenum glow_debug_impl_glGetGraphicsResetStatus() {

  GLenum ret;
  glow_pre_callback_("glGetGraphicsResetStatus", (void*)(ptrdiff_t)glow_glGetGraphicsResetStatus);
  ret = glow_glGetGraphicsResetStatus();
  glow_post_callback_("glGetGraphicsResetStatus", (void*)(ptrdiff_t)glow_glGetGraphicsResetStatus);
  return ret;
}
PFNGLGETGRAPHICSRESETSTATUSPROC glow_debug_glGetGraphicsResetStatus = glow_debug_impl_glGetGraphicsResetStatus;

static void glow_debug_impl_glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {

  glow_pre_callback_("glClearBufferfi", (void*)(ptrdiff_t)glow_glClearBufferfi, buffer, drawbuffer, depth, stencil);
  glow_glClearBufferfi(buffer, drawbuffer, depth, stencil);
  glow_post_callback_("glClearBufferfi", (void*)(ptrdiff_t)glow_glClearBufferfi, buffer, drawbuffer, depth, stencil);
}
PFNGLCLEARBUFFERFIPROC glow_debug_glClearBufferfi = glow_debug_impl_glClearBufferfi;

static void glow_debug_impl_glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {

  glow_pre_callback_("glProgramUniform3fv", (void*)(ptrdiff_t)glow_glProgramUniform3fv, program, location, count, value);
  glow_glProgramUniform3fv(program, location, count, value);
  glow_post_callback_("glProgramUniform3fv", (void*)(ptrdiff_t)glow_glProgramUniform3fv, program, location, count, value);
}
PFNGLPROGRAMUNIFORM3FVPROC glow_debug_glProgramUniform3fv = glow_debug_impl_glProgramUniform3fv;

static void glow_debug_impl_glSampleMaski(GLuint maskNumber, GLbitfield mask) {

  glow_pre_callback_("glSampleMaski", (void*)(ptrdiff_t)glow_glSampleMaski, maskNumber, mask);
  glow_glSampleMaski(maskNumber, mask);
  glow_post_callback_("glSampleMaski", (void*)(ptrdiff_t)glow_glSampleMaski, maskNumber, mask);
}
PFNGLSAMPLEMASKIPROC glow_debug_glSampleMaski = glow_debug_impl_glSampleMaski;

static void glow_debug_impl_glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glProgramUniformMatrix3x2fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix3x2fv, program, location, count, transpose, value);
  glow_glProgramUniformMatrix3x2fv(program, location, count, transpose, value);
  glow_post_callback_("glProgramUniformMatrix3x2fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix3x2fv, program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glow_debug_glProgramUniformMatrix3x2fv = glow_debug_impl_glProgramUniformMatrix3x2fv;

static void glow_debug_impl_glDeleteShader(GLuint shader) {

  glow_pre_callback_("glDeleteShader", (void*)(ptrdiff_t)glow_glDeleteShader, shader);
  glow_glDeleteShader(shader);
  glow_post_callback_("glDeleteShader", (void*)(ptrdiff_t)glow_glDeleteShader, shader);
}
PFNGLDELETESHADERPROC glow_debug_glDeleteShader = glow_debug_impl_glDeleteShader;

static GLint glow_debug_impl_glGetFragDataLocation(GLuint program, const GLchar *name) {

  GLint ret;
  glow_pre_callback_("glGetFragDataLocation", (void*)(ptrdiff_t)glow_glGetFragDataLocation, program, name);
  ret = glow_glGetFragDataLocation(program, name);
  glow_post_callback_("glGetFragDataLocation", (void*)(ptrdiff_t)glow_glGetFragDataLocation, program, name);
  return ret;
}
PFNGLGETFRAGDATALOCATIONPROC glow_debug_glGetFragDataLocation = glow_debug_impl_glGetFragDataLocation;

static void glow_debug_impl_glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glProgramUniformMatrix3fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix3fv, program, location, count, transpose, value);
  glow_glProgramUniformMatrix3fv(program, location, count, transpose, value);
  glow_post_callback_("glProgramUniformMatrix3fv", (void*)(ptrdiff_t)glow_glProgramUniformMatrix3fv, program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glow_debug_glProgramUniformMatrix3fv = glow_debug_impl_glProgramUniformMatrix3fv;

static void glow_debug_impl_glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params) {

  glow_pre_callback_("glGetSamplerParameterIuiv", (void*)(ptrdiff_t)glow_glGetSamplerParameterIuiv, sampler, pname, params);
  glow_glGetSamplerParameterIuiv(sampler, pname, params);
  glow_post_callback_("glGetSamplerParameterIuiv", (void*)(ptrdiff_t)glow_glGetSamplerParameterIuiv, sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIUIVPROC glow_debug_glGetSamplerParameterIuiv = glow_debug_impl_glGetSamplerParameterIuiv;

static void glow_debug_impl_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) {

  glow_pre_callback_("glBufferSubData", (void*)(ptrdiff_t)glow_glBufferSubData, target, offset, size, data);
  glow_glBufferSubData(target, offset, size, data);
  glow_post_callback_("glBufferSubData", (void*)(ptrdiff_t)glow_glBufferSubData, target, offset, size, data);
}
PFNGLBUFFERSUBDATAPROC glow_debug_glBufferSubData = glow_debug_impl_glBufferSubData;

static void glow_debug_impl_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {

  glow_pre_callback_("glClearColor", (void*)(ptrdiff_t)glow_glClearColor, red, green, blue, alpha);
  glow_glClearColor(red, green, blue, alpha);
  glow_post_callback_("glClearColor", (void*)(ptrdiff_t)glow_glClearColor, red, green, blue, alpha);
}
PFNGLCLEARCOLORPROC glow_debug_glClearColor = glow_debug_impl_glClearColor;

static void glow_debug_impl_glVertexAttrib2fv(GLuint index, const GLfloat *v) {

  glow_pre_callback_("glVertexAttrib2fv", (void*)(ptrdiff_t)glow_glVertexAttrib2fv, index, v);
  glow_glVertexAttrib2fv(index, v);
  glow_post_callback_("glVertexAttrib2fv", (void*)(ptrdiff_t)glow_glVertexAttrib2fv, index, v);
}
PFNGLVERTEXATTRIB2FVPROC glow_debug_glVertexAttrib2fv = glow_debug_impl_glVertexAttrib2fv;

static void glow_debug_impl_glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetSamplerParameteriv", (void*)(ptrdiff_t)glow_glGetSamplerParameteriv, sampler, pname, params);
  glow_glGetSamplerParameteriv(sampler, pname, params);
  glow_post_callback_("glGetSamplerParameteriv", (void*)(ptrdiff_t)glow_glGetSamplerParameteriv, sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIVPROC glow_debug_glGetSamplerParameteriv = glow_debug_impl_glGetSamplerParameteriv;

static void glow_debug_impl_glProgramParameteri(GLuint program, GLenum pname, GLint value) {

  glow_pre_callback_("glProgramParameteri", (void*)(ptrdiff_t)glow_glProgramParameteri, program, pname, value);
  glow_glProgramParameteri(program, pname, value);
  glow_post_callback_("glProgramParameteri", (void*)(ptrdiff_t)glow_glProgramParameteri, program, pname, value);
}
PFNGLPROGRAMPARAMETERIPROC glow_debug_glProgramParameteri = glow_debug_impl_glProgramParameteri;

static void glow_debug_impl_glDeleteQueries(GLsizei n, const GLuint *ids) {

  glow_pre_callback_("glDeleteQueries", (void*)(ptrdiff_t)glow_glDeleteQueries, n, ids);
  glow_glDeleteQueries(n, ids);
  glow_post_callback_("glDeleteQueries", (void*)(ptrdiff_t)glow_glDeleteQueries, n, ids);
}
PFNGLDELETEQUERIESPROC glow_debug_glDeleteQueries = glow_debug_impl_glDeleteQueries;

static void glow_debug_impl_glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) {

  glow_pre_callback_("glGetActiveUniformBlockName", (void*)(ptrdiff_t)glow_glGetActiveUniformBlockName, program, uniformBlockIndex, bufSize, length, uniformBlockName);
  glow_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
  glow_post_callback_("glGetActiveUniformBlockName", (void*)(ptrdiff_t)glow_glGetActiveUniformBlockName, program, uniformBlockIndex, bufSize, length, uniformBlockName);
}
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glow_debug_glGetActiveUniformBlockName = glow_debug_impl_glGetActiveUniformBlockName;

static GLenum glow_debug_impl_glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {

  GLenum ret;
  glow_pre_callback_("glClientWaitSync", (void*)(ptrdiff_t)glow_glClientWaitSync, sync, flags, timeout);
  ret = glow_glClientWaitSync(sync, flags, timeout);
  glow_post_callback_("glClientWaitSync", (void*)(ptrdiff_t)glow_glClientWaitSync, sync, flags, timeout);
  return ret;
}
PFNGLCLIENTWAITSYNCPROC glow_debug_glClientWaitSync = glow_debug_impl_glClientWaitSync;

static void glow_debug_impl_glVertexAttribDivisor(GLuint index, GLuint divisor) {

  glow_pre_callback_("glVertexAttribDivisor", (void*)(ptrdiff_t)glow_glVertexAttribDivisor, index, divisor);
  glow_glVertexAttribDivisor(index, divisor);
  glow_post_callback_("glVertexAttribDivisor", (void*)(ptrdiff_t)glow_glVertexAttribDivisor, index, divisor);
}
PFNGLVERTEXATTRIBDIVISORPROC glow_debug_glVertexAttribDivisor = glow_debug_impl_glVertexAttribDivisor;

static GLboolean glow_debug_impl_glIsProgramPipeline(GLuint pipeline) {

  GLboolean ret;
  glow_pre_callback_("glIsProgramPipeline", (void*)(ptrdiff_t)glow_glIsProgramPipeline, pipeline);
  ret = glow_glIsProgramPipeline(pipeline);
  glow_post_callback_("glIsProgramPipeline", (void*)(ptrdiff_t)glow_glIsProgramPipeline, pipeline);
  return ret;
}
PFNGLISPROGRAMPIPELINEPROC glow_debug_glIsProgramPipeline = glow_debug_impl_glIsProgramPipeline;

static void glow_debug_impl_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {

  glow_pre_callback_("glUniformMatrix3fv", (void*)(ptrdiff_t)glow_glUniformMatrix3fv, location, count, transpose, value);
  glow_glUniformMatrix3fv(location, count, transpose, value);
  glow_post_callback_("glUniformMatrix3fv", (void*)(ptrdiff_t)glow_glUniformMatrix3fv, location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3FVPROC glow_debug_glUniformMatrix3fv = glow_debug_impl_glUniformMatrix3fv;

static void glow_debug_impl_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {

  glow_pre_callback_("glVertexAttrib2f", (void*)(ptrdiff_t)glow_glVertexAttrib2f, index, x, y);
  glow_glVertexAttrib2f(index, x, y);
  glow_post_callback_("glVertexAttrib2f", (void*)(ptrdiff_t)glow_glVertexAttrib2f, index, x, y);
}
PFNGLVERTEXATTRIB2FPROC glow_debug_glVertexAttrib2f = glow_debug_impl_glVertexAttrib2f;

static void glow_debug_impl_glReadBuffer(GLenum src) {

  glow_pre_callback_("glReadBuffer", (void*)(ptrdiff_t)glow_glReadBuffer, src);
  glow_glReadBuffer(src);
  glow_post_callback_("glReadBuffer", (void*)(ptrdiff_t)glow_glReadBuffer, src);
}
PFNGLREADBUFFERPROC glow_debug_glReadBuffer = glow_debug_impl_glReadBuffer;

static void glow_debug_impl_glMemoryBarrierByRegion(GLbitfield barriers) {

  glow_pre_callback_("glMemoryBarrierByRegion", (void*)(ptrdiff_t)glow_glMemoryBarrierByRegion, barriers);
  glow_glMemoryBarrierByRegion(barriers);
  glow_post_callback_("glMemoryBarrierByRegion", (void*)(ptrdiff_t)glow_glMemoryBarrierByRegion, barriers);
}
PFNGLMEMORYBARRIERBYREGIONPROC glow_debug_glMemoryBarrierByRegion = glow_debug_impl_glMemoryBarrierByRegion;

static void glow_debug_impl_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {

  glow_pre_callback_("glGetActiveAttrib", (void*)(ptrdiff_t)glow_glGetActiveAttrib, program, index, bufSize, length, size, type, name);
  glow_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
  glow_post_callback_("glGetActiveAttrib", (void*)(ptrdiff_t)glow_glGetActiveAttrib, program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEATTRIBPROC glow_debug_glGetActiveAttrib = glow_debug_impl_glGetActiveAttrib;

static void glow_debug_impl_glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetBufferParameteriv", (void*)(ptrdiff_t)glow_glGetBufferParameteriv, target, pname, params);
  glow_glGetBufferParameteriv(target, pname, params);
  glow_post_callback_("glGetBufferParameteriv", (void*)(ptrdiff_t)glow_glGetBufferParameteriv, target, pname, params);
}
PFNGLGETBUFFERPARAMETERIVPROC glow_debug_glGetBufferParameteriv = glow_debug_impl_glGetBufferParameteriv;

static void glow_debug_impl_glUniform2uiv(GLint location, GLsizei count, const GLuint *value) {

  glow_pre_callback_("glUniform2uiv", (void*)(ptrdiff_t)glow_glUniform2uiv, location, count, value);
  glow_glUniform2uiv(location, count, value);
  glow_post_callback_("glUniform2uiv", (void*)(ptrdiff_t)glow_glUniform2uiv, location, count, value);
}
PFNGLUNIFORM2UIVPROC glow_debug_glUniform2uiv = glow_debug_impl_glUniform2uiv;

#endif /* GLOW_DEBUG */



int glow_init(void) {
  return glow_init_with(&glow_get_proc);
}

int glow_init_with(glow_load_proc_t get_proc) {
  int unresolved_count = 0;

  glow_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)(ptrdiff_t)get_proc("glDisableVertexAttribArray");
  if (glow_glDisableVertexAttribArray == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisableVertexAttribArray\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisableVertexAttribArray\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)(ptrdiff_t)get_proc("glDeleteSamplers");
  if (glow_glDeleteSamplers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteSamplers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteSamplers\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)(ptrdiff_t)get_proc("glVertexAttribI4uiv");
  if (glow_glVertexAttribI4uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribI4uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribI4uiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)(ptrdiff_t)get_proc("glGetProgramBinary");
  if (glow_glGetProgramBinary == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramBinary\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramBinary\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)(ptrdiff_t)get_proc("glGetDebugMessageLog");
  if (glow_glGetDebugMessageLog == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetDebugMessageLog\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetDebugMessageLog\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDisablei = (PFNGLDISABLEIPROC)(ptrdiff_t)get_proc("glDisablei");
  if (glow_glDisablei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisablei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisablei\n");
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
  glow_glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)(ptrdiff_t)get_proc("glReleaseShaderCompiler");
  if (glow_glReleaseShaderCompiler == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReleaseShaderCompiler\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReleaseShaderCompiler\n");
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
  glow_glIsQuery = (PFNGLISQUERYPROC)(ptrdiff_t)get_proc("glIsQuery");
  if (glow_glIsQuery == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsQuery\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsQuery\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)(ptrdiff_t)get_proc("glDeleteTransformFeedbacks");
  if (glow_glDeleteTransformFeedbacks == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteTransformFeedbacks\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteTransformFeedbacks\n");
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
  glow_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)(ptrdiff_t)get_proc("glGetShaderSource");
  if (glow_glGetShaderSource == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetShaderSource\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetShaderSource\n");
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
  glow_glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)(ptrdiff_t)get_proc("glFramebufferTextureLayer");
  if (glow_glFramebufferTextureLayer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferTextureLayer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferTextureLayer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)(ptrdiff_t)get_proc("glClearBufferuiv");
  if (glow_glClearBufferuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearBufferuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearBufferuiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)(ptrdiff_t)get_proc("glSamplerParameterfv");
  if (glow_glSamplerParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameterfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)(ptrdiff_t)get_proc("glBlendEquationSeparatei");
  if (glow_glBlendEquationSeparatei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendEquationSeparatei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendEquationSeparatei\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)(ptrdiff_t)get_proc("glFramebufferTexture");
  if (glow_glFramebufferTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferTexture\n");
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
  glow_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetRenderbufferParameteriv");
  if (glow_glGetRenderbufferParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetRenderbufferParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetRenderbufferParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)(ptrdiff_t)get_proc("glGetProgramPipelineiv");
  if (glow_glGetProgramPipelineiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramPipelineiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramPipelineiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)(ptrdiff_t)get_proc("glCopyImageSubData");
  if (glow_glCopyImageSubData == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyImageSubData\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyImageSubData\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)(ptrdiff_t)get_proc("glGetTexParameterIiv");
  if (glow_glGetTexParameterIiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameterIiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameterIiv\n");
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
  glow_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)(ptrdiff_t)get_proc("glUniformMatrix4x2fv");
  if (glow_glUniformMatrix4x2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix4x2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix4x2fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform2ui = (PFNGLUNIFORM2UIPROC)(ptrdiff_t)get_proc("glUniform2ui");
  if (glow_glUniform2ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2ui\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)(ptrdiff_t)get_proc("glProgramUniform1fv");
  if (glow_glProgramUniform1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)(ptrdiff_t)get_proc("glMemoryBarrier");
  if (glow_glMemoryBarrier == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMemoryBarrier\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMemoryBarrier\n");
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
  glow_glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)(ptrdiff_t)get_proc("glDrawElementsInstanced");
  if (glow_glDrawElementsInstanced == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElementsInstanced\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElementsInstanced\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)(ptrdiff_t)get_proc("glProgramUniform1iv");
  if (glow_glProgramUniform1iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)(ptrdiff_t)get_proc("glActiveShaderProgram");
  if (glow_glActiveShaderProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glActiveShaderProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glActiveShaderProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)(ptrdiff_t)get_proc("glBindImageTexture");
  if (glow_glBindImageTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindImageTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindImageTexture\n");
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
  glow_glUniform3fv = (PFNGLUNIFORM3FVPROC)(ptrdiff_t)get_proc("glUniform3fv");
  if (glow_glUniform3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3fv\n");
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
  glow_glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetFramebufferParameteriv");
  if (glow_glGetFramebufferParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFramebufferParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFramebufferParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)(ptrdiff_t)get_proc("glProgramUniform3uiv");
  if (glow_glProgramUniform3uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3uiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlendBarrier = (PFNGLBLENDBARRIERPROC)(ptrdiff_t)get_proc("glBlendBarrier");
  if (glow_glBlendBarrier == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendBarrier\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendBarrier\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(ptrdiff_t)get_proc("glTexStorage3DMultisample");
  if (glow_glTexStorage3DMultisample == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexStorage3DMultisample\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexStorage3DMultisample\n");
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
  glow_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)(ptrdiff_t)get_proc("glUniformMatrix2x3fv");
  if (glow_glUniformMatrix2x3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix2x3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix2x3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsSync = (PFNGLISSYNCPROC)(ptrdiff_t)get_proc("glIsSync");
  if (glow_glIsSync == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsSync\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsSync\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)(ptrdiff_t)get_proc("glClearBufferiv");
  if (glow_glClearBufferiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearBufferiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearBufferiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)(ptrdiff_t)get_proc("glGetBooleani_v");
  if (glow_glGetBooleani_v == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBooleani_v\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBooleani_v\n");
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
  glow_glIsShader = (PFNGLISSHADERPROC)(ptrdiff_t)get_proc("glIsShader");
  if (glow_glIsShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsShader\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)(ptrdiff_t)get_proc("glDrawRangeElements");
  if (glow_glDrawRangeElements == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawRangeElements\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawRangeElements\n");
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
  glow_glUseProgram = (PFNGLUSEPROGRAMPROC)(ptrdiff_t)get_proc("glUseProgram");
  if (glow_glUseProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUseProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUseProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)(ptrdiff_t)get_proc("glGetUniformBlockIndex");
  if (glow_glGetUniformBlockIndex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformBlockIndex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformBlockIndex\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)(ptrdiff_t)get_proc("glGetInternalformativ");
  if (glow_glGetInternalformativ == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetInternalformativ\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetInternalformativ\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(ptrdiff_t)get_proc("glProgramUniformMatrix4x2fv");
  if (glow_glProgramUniformMatrix4x2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix4x2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix4x2fv\n");
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
  glow_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(ptrdiff_t)get_proc("glCompressedTexSubImage2D");
  if (glow_glCompressedTexSubImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompressedTexSubImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompressedTexSubImage2D\n");
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
  glow_glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)(ptrdiff_t)get_proc("glValidateProgramPipeline");
  if (glow_glValidateProgramPipeline == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glValidateProgramPipeline\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glValidateProgramPipeline\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)(ptrdiff_t)get_proc("glTexParameterIiv");
  if (glow_glTexParameterIiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterIiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterIiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)(ptrdiff_t)get_proc("glProgramUniform1i");
  if (glow_glProgramUniform1i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glReadnPixels = (PFNGLREADNPIXELSPROC)(ptrdiff_t)get_proc("glReadnPixels");
  if (glow_glReadnPixels == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReadnPixels\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReadnPixels\n");
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
  glow_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)(ptrdiff_t)get_proc("glVertexAttribPointer");
  if (glow_glVertexAttribPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribPointer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)(ptrdiff_t)get_proc("glBindProgramPipeline");
  if (glow_glBindProgramPipeline == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindProgramPipeline\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindProgramPipeline\n");
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
  glow_glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)(ptrdiff_t)get_proc("glMapBufferRange");
  if (glow_glMapBufferRange == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMapBufferRange\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMapBufferRange\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)(ptrdiff_t)get_proc("glGetVertexAttribIiv");
  if (glow_glGetVertexAttribIiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribIiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribIiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)(ptrdiff_t)get_proc("glTexStorage2D");
  if (glow_glTexStorage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexStorage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexStorage2D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC)(ptrdiff_t)get_proc("glGetnUniformuiv");
  if (glow_glGetnUniformuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetnUniformuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetnUniformuiv\n");
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
  glow_glClearDepthf = (PFNGLCLEARDEPTHFPROC)(ptrdiff_t)get_proc("glClearDepthf");
  if (glow_glClearDepthf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearDepthf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearDepthf\n");
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
  glow_glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)(ptrdiff_t)get_proc("glSamplerParameterIuiv");
  if (glow_glSamplerParameterIuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameterIuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameterIuiv\n");
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
  glow_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)(ptrdiff_t)get_proc("glBindVertexArray");
  if (glow_glBindVertexArray == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindVertexArray\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindVertexArray\n");
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
  glow_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)(ptrdiff_t)get_proc("glTexSubImage2D");
  if (glow_glTexSubImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexSubImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexSubImage2D\n");
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
  glow_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)(ptrdiff_t)get_proc("glStencilMaskSeparate");
  if (glow_glStencilMaskSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilMaskSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilMaskSeparate\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGenQueries = (PFNGLGENQUERIESPROC)(ptrdiff_t)get_proc("glGenQueries");
  if (glow_glGenQueries == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenQueries\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenQueries\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(ptrdiff_t)get_proc("glRenderbufferStorageMultisample");
  if (glow_glRenderbufferStorageMultisample == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRenderbufferStorageMultisample\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRenderbufferStorageMultisample\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)(ptrdiff_t)get_proc("glDrawElementsIndirect");
  if (glow_glDrawElementsIndirect == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElementsIndirect\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElementsIndirect\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC)(ptrdiff_t)get_proc("glGetnUniformfv");
  if (glow_glGetnUniformfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetnUniformfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetnUniformfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)(ptrdiff_t)get_proc("glDispatchCompute");
  if (glow_glDispatchCompute == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDispatchCompute\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDispatchCompute\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)(ptrdiff_t)get_proc("glProgramUniform1ui");
  if (glow_glProgramUniform1ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1ui\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsEnabledi = (PFNGLISENABLEDIPROC)(ptrdiff_t)get_proc("glIsEnabledi");
  if (glow_glIsEnabledi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsEnabledi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsEnabledi\n");
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
  glow_glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)(ptrdiff_t)get_proc("glVertexAttribI4ui");
  if (glow_glVertexAttribI4ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribI4ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribI4ui\n");
#endif
    unresolved_count += 1;
  } 
  glow_glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)(ptrdiff_t)get_proc("glSamplerParameteri");
  if (glow_glSamplerParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameteri\n");
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
  glow_glIsProgram = (PFNGLISPROGRAMPROC)(ptrdiff_t)get_proc("glIsProgram");
  if (glow_glIsProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)(ptrdiff_t)get_proc("glProgramUniform2i");
  if (glow_glProgramUniform2i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)(ptrdiff_t)get_proc("glProgramUniform4fv");
  if (glow_glProgramUniform4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4fv\n");
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
  glow_glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)(ptrdiff_t)get_proc("glGetProgramResourceIndex");
  if (glow_glGetProgramResourceIndex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramResourceIndex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramResourceIndex\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)(ptrdiff_t)get_proc("glProgramUniform3i");
  if (glow_glProgramUniform3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)(ptrdiff_t)get_proc("glUniformMatrix2x4fv");
  if (glow_glUniformMatrix2x4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix2x4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix2x4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(ptrdiff_t)get_proc("glDrawRangeElementsBaseVertex");
  if (glow_glDrawRangeElementsBaseVertex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawRangeElementsBaseVertex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawRangeElementsBaseVertex\n");
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
  glow_glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(ptrdiff_t)get_proc("glFlushMappedBufferRange");
  if (glow_glFlushMappedBufferRange == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFlushMappedBufferRange\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFlushMappedBufferRange\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsSampler = (PFNGLISSAMPLERPROC)(ptrdiff_t)get_proc("glIsSampler");
  if (glow_glIsSampler == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsSampler\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsSampler\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramBinary = (PFNGLPROGRAMBINARYPROC)(ptrdiff_t)get_proc("glProgramBinary");
  if (glow_glProgramBinary == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramBinary\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramBinary\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)(ptrdiff_t)get_proc("glCreateShaderProgramv");
  if (glow_glCreateShaderProgramv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCreateShaderProgramv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCreateShaderProgramv\n");
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
  glow_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)(ptrdiff_t)get_proc("glGenRenderbuffers");
  if (glow_glGenRenderbuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenRenderbuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenRenderbuffers\n");
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
  glow_glColorMaski = (PFNGLCOLORMASKIPROC)(ptrdiff_t)get_proc("glColorMaski");
  if (glow_glColorMaski == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColorMaski\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColorMaski\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)(ptrdiff_t)get_proc("glVertexAttribIPointer");
  if (glow_glVertexAttribIPointer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribIPointer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribIPointer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)(ptrdiff_t)get_proc("glUniformBlockBinding");
  if (glow_glUniformBlockBinding == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformBlockBinding\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformBlockBinding\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(ptrdiff_t)get_proc("glProgramUniformMatrix3x4fv");
  if (glow_glProgramUniformMatrix3x4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix3x4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix3x4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)(ptrdiff_t)get_proc("glDebugMessageCallback");
  if (glow_glDebugMessageCallback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDebugMessageCallback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDebugMessageCallback\n");
#endif
    unresolved_count += 1;
  } 
  glow_glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)(ptrdiff_t)get_proc("glSamplerParameterIiv");
  if (glow_glSamplerParameterIiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameterIiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameterIiv\n");
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
  glow_glTexParameterf = (PFNGLTEXPARAMETERFPROC)(ptrdiff_t)get_proc("glTexParameterf");
  if (glow_glTexParameterf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(ptrdiff_t)get_proc("glCompressedTexSubImage3D");
  if (glow_glCompressedTexSubImage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompressedTexSubImage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompressedTexSubImage3D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)(ptrdiff_t)get_proc("glGetTexLevelParameterfv");
  if (glow_glGetTexLevelParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexLevelParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexLevelParameterfv\n");
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
  glow_glLinkProgram = (PFNGLLINKPROGRAMPROC)(ptrdiff_t)get_proc("glLinkProgram");
  if (glow_glLinkProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLinkProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLinkProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)(ptrdiff_t)get_proc("glProgramUniform2f");
  if (glow_glProgramUniform2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2f\n");
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
  glow_glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)(ptrdiff_t)get_proc("glGetProgramInterfaceiv");
  if (glow_glGetProgramInterfaceiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramInterfaceiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramInterfaceiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)(ptrdiff_t)get_proc("glProgramUniform2ui");
  if (glow_glProgramUniform2ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2ui\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)(ptrdiff_t)get_proc("glProgramUniform1uiv");
  if (glow_glProgramUniform1uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1uiv\n");
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
  glow_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)(ptrdiff_t)get_proc("glGetBufferPointerv");
  if (glow_glGetBufferPointerv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBufferPointerv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBufferPointerv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)(ptrdiff_t)get_proc("glEndTransformFeedback");
  if (glow_glEndTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEndTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEndTransformFeedback\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)(ptrdiff_t)get_proc("glGetSamplerParameterIiv");
  if (glow_glGetSamplerParameterIiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetSamplerParameterIiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetSamplerParameterIiv\n");
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
  glow_glGenSamplers = (PFNGLGENSAMPLERSPROC)(ptrdiff_t)get_proc("glGenSamplers");
  if (glow_glGenSamplers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenSamplers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenSamplers\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEnablei = (PFNGLENABLEIPROC)(ptrdiff_t)get_proc("glEnablei");
  if (glow_glEnablei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnablei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnablei\n");
#endif
    unresolved_count += 1;
  } 
  glow_glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)(ptrdiff_t)get_proc("glObjectPtrLabel");
  if (glow_glObjectPtrLabel == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glObjectPtrLabel\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glObjectPtrLabel\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(ptrdiff_t)get_proc("glDrawElementsInstancedBaseVertex");
  if (glow_glDrawElementsInstancedBaseVertex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElementsInstancedBaseVertex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElementsInstancedBaseVertex\n");
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
  glow_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)(ptrdiff_t)get_proc("glVertexAttrib4fv");
  if (glow_glVertexAttrib4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)(ptrdiff_t)get_proc("glDeleteProgramPipelines");
  if (glow_glDeleteProgramPipelines == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteProgramPipelines\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteProgramPipelines\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexBuffer = (PFNGLTEXBUFFERPROC)(ptrdiff_t)get_proc("glTexBuffer");
  if (glow_glTexBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexBuffer\n");
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
  glow_glUniform2f = (PFNGLUNIFORM2FPROC)(ptrdiff_t)get_proc("glUniform2f");
  if (glow_glUniform2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)(ptrdiff_t)get_proc("glGetUniformuiv");
  if (glow_glGetUniformuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformuiv\n");
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
  glow_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)(ptrdiff_t)get_proc("glDeleteVertexArrays");
  if (glow_glDeleteVertexArrays == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteVertexArrays\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteVertexArrays\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)(ptrdiff_t)get_proc("glVertexAttribI4i");
  if (glow_glVertexAttribI4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribI4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribI4i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)(ptrdiff_t)get_proc("glGetInteger64i_v");
  if (glow_glGetInteger64i_v == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetInteger64i_v\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetInteger64i_v\n");
#endif
    unresolved_count += 1;
  } 
  glow_glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)(ptrdiff_t)get_proc("glSamplerParameteriv");
  if (glow_glSamplerParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameteriv\n");
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
  glow_glTexImage2D = (PFNGLTEXIMAGE2DPROC)(ptrdiff_t)get_proc("glTexImage2D");
  if (glow_glTexImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexImage2D\n");
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
  glow_glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)(ptrdiff_t)get_proc("glProgramUniform2fv");
  if (glow_glProgramUniform2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)(ptrdiff_t)get_proc("glGetQueryObjectuiv");
  if (glow_glGetQueryObjectuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetQueryObjectuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetQueryObjectuiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)(ptrdiff_t)get_proc("glVertexAttribI4iv");
  if (glow_glVertexAttribI4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribI4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribI4iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)(ptrdiff_t)get_proc("glGetUniformIndices");
  if (glow_glGetUniformIndices == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformIndices\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformIndices\n");
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
  glow_glIsTexture = (PFNGLISTEXTUREPROC)(ptrdiff_t)get_proc("glIsTexture");
  if (glow_glIsTexture == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsTexture\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsTexture\n");
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
  glow_glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)(ptrdiff_t)get_proc("glInvalidateFramebuffer");
  if (glow_glInvalidateFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glInvalidateFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glInvalidateFramebuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(ptrdiff_t)get_proc("glProgramUniformMatrix2x3fv");
  if (glow_glProgramUniformMatrix2x3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix2x3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix2x3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlendFunci = (PFNGLBLENDFUNCIPROC)(ptrdiff_t)get_proc("glBlendFunci");
  if (glow_glBlendFunci == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendFunci\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendFunci\n");
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
  glow_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)(ptrdiff_t)get_proc("glValidateProgram");
  if (glow_glValidateProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glValidateProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glValidateProgram\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetQueryiv = (PFNGLGETQUERYIVPROC)(ptrdiff_t)get_proc("glGetQueryiv");
  if (glow_glGetQueryiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetQueryiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetQueryiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)(ptrdiff_t)get_proc("glBlitFramebuffer");
  if (glow_glBlitFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlitFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlitFramebuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)(ptrdiff_t)get_proc("glCopyBufferSubData");
  if (glow_glCopyBufferSubData == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyBufferSubData\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyBufferSubData\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)(ptrdiff_t)get_proc("glDrawArraysIndirect");
  if (glow_glDrawArraysIndirect == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawArraysIndirect\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawArraysIndirect\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)(ptrdiff_t)get_proc("glUseProgramStages");
  if (glow_glUseProgramStages == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUseProgramStages\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUseProgramStages\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(ptrdiff_t)get_proc("glProgramUniformMatrix4fv");
  if (glow_glProgramUniformMatrix4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix4fv\n");
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
  glow_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)(ptrdiff_t)get_proc("glGetShaderInfoLog");
  if (glow_glGetShaderInfoLog == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetShaderInfoLog\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetShaderInfoLog\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)(ptrdiff_t)get_proc("glUniformMatrix3x4fv");
  if (glow_glUniformMatrix3x4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix3x4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix3x4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)(ptrdiff_t)get_proc("glVertexAttribFormat");
  if (glow_glVertexAttribFormat == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribFormat\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribFormat\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC)(ptrdiff_t)get_proc("glGetnUniformiv");
  if (glow_glGetnUniformiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetnUniformiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetnUniformiv\n");
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
  glow_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)(ptrdiff_t)get_proc("glUnmapBuffer");
  if (glow_glUnmapBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUnmapBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUnmapBuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)(ptrdiff_t)get_proc("glVertexBindingDivisor");
  if (glow_glVertexBindingDivisor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexBindingDivisor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexBindingDivisor\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)(ptrdiff_t)get_proc("glBlendEquationi");
  if (glow_glBlendEquationi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendEquationi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendEquationi\n");
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
  glow_glEnable = (PFNGLENABLEPROC)(ptrdiff_t)get_proc("glEnable");
  if (glow_glEnable == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnable\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnable\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)(ptrdiff_t)get_proc("glProgramUniform4iv");
  if (glow_glProgramUniform4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4iv\n");
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
  glow_glUniform1fv = (PFNGLUNIFORM1FVPROC)(ptrdiff_t)get_proc("glUniform1fv");
  if (glow_glUniform1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)(ptrdiff_t)get_proc("glGetProgramResourceLocation");
  if (glow_glGetProgramResourceLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramResourceLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramResourceLocation\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)(ptrdiff_t)get_proc("glProgramUniform3ui");
  if (glow_glProgramUniform3ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3ui\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)(ptrdiff_t)get_proc("glDrawElementsBaseVertex");
  if (glow_glDrawElementsBaseVertex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawElementsBaseVertex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawElementsBaseVertex\n");
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
  glow_glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(ptrdiff_t)get_proc("glProgramUniformMatrix4x3fv");
  if (glow_glProgramUniformMatrix4x3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix4x3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix4x3fv\n");
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
  glow_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)(ptrdiff_t)get_proc("glVertexAttrib4f");
  if (glow_glVertexAttrib4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib4f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)(ptrdiff_t)get_proc("glProgramUniform4uiv");
  if (glow_glProgramUniform4uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4uiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)(ptrdiff_t)get_proc("glMinSampleShading");
  if (glow_glMinSampleShading == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMinSampleShading\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMinSampleShading\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBeginQuery = (PFNGLBEGINQUERYPROC)(ptrdiff_t)get_proc("glBeginQuery");
  if (glow_glBeginQuery == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBeginQuery\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBeginQuery\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)(ptrdiff_t)get_proc("glBindBufferBase");
  if (glow_glBindBufferBase == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindBufferBase\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindBufferBase\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetStringi = (PFNGLGETSTRINGIPROC)(ptrdiff_t)get_proc("glGetStringi");
  if (glow_glGetStringi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetStringi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetStringi\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)(ptrdiff_t)get_proc("glGenTransformFeedbacks");
  if (glow_glGenTransformFeedbacks == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenTransformFeedbacks\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenTransformFeedbacks\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(ptrdiff_t)get_proc("glProgramUniformMatrix2x4fv");
  if (glow_glProgramUniformMatrix2x4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix2x4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix2x4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)(ptrdiff_t)get_proc("glBlendFuncSeparatei");
  if (glow_glBlendFuncSeparatei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendFuncSeparatei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendFuncSeparatei\n");
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
  glow_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)(ptrdiff_t)get_proc("glGetUniformLocation");
  if (glow_glGetUniformLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformLocation\n");
#endif
    unresolved_count += 1;
  } 
  glow_glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)(ptrdiff_t)get_proc("glSamplerParameterf");
  if (glow_glSamplerParameterf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSamplerParameterf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSamplerParameterf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)(ptrdiff_t)get_proc("glIsTransformFeedback");
  if (glow_glIsTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsTransformFeedback\n");
#endif
    unresolved_count += 1;
  } 
  glow_glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)(ptrdiff_t)get_proc("glInvalidateSubFramebuffer");
  if (glow_glInvalidateSubFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glInvalidateSubFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glInvalidateSubFramebuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetTexLevelParameteriv");
  if (glow_glGetTexLevelParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexLevelParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexLevelParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)(ptrdiff_t)get_proc("glTexBufferRange");
  if (glow_glTexBufferRange == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexBufferRange\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexBufferRange\n");
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
  glow_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)(ptrdiff_t)get_proc("glBindBufferRange");
  if (glow_glBindBufferRange == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindBufferRange\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindBufferRange\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)(ptrdiff_t)get_proc("glGetSamplerParameterfv");
  if (glow_glGetSamplerParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetSamplerParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetSamplerParameterfv\n");
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
  glow_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)(ptrdiff_t)get_proc("glIsFramebuffer");
  if (glow_glIsFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsFramebuffer\n");
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
  glow_glUniform4i = (PFNGLUNIFORM4IPROC)(ptrdiff_t)get_proc("glUniform4i");
  if (glow_glUniform4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexImage3D = (PFNGLTEXIMAGE3DPROC)(ptrdiff_t)get_proc("glTexImage3D");
  if (glow_glTexImage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexImage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexImage3D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)(ptrdiff_t)get_proc("glDispatchComputeIndirect");
  if (glow_glDispatchComputeIndirect == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDispatchComputeIndirect\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDispatchComputeIndirect\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)(ptrdiff_t)get_proc("glDebugMessageControl");
  if (glow_glDebugMessageControl == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDebugMessageControl\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDebugMessageControl\n");
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
  glow_glDeleteProgram = (PFNGLDELETEPROGRAMPROC)(ptrdiff_t)get_proc("glDeleteProgram");
  if (glow_glDeleteProgram == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteProgram\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteProgram\n");
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
  glow_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)(ptrdiff_t)get_proc("glGetProgramInfoLog");
  if (glow_glGetProgramInfoLog == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramInfoLog\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramInfoLog\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteSync = (PFNGLDELETESYNCPROC)(ptrdiff_t)get_proc("glDeleteSync");
  if (glow_glDeleteSync == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteSync\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteSync\n");
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
  glow_glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)(ptrdiff_t)get_proc("glGetProgramResourceiv");
  if (glow_glGetProgramResourceiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramResourceiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramResourceiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(ptrdiff_t)get_proc("glGetProgramPipelineInfoLog");
  if (glow_glGetProgramPipelineInfoLog == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramPipelineInfoLog\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramPipelineInfoLog\n");
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
  glow_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)(ptrdiff_t)get_proc("glGetTexParameterfv");
  if (glow_glGetTexParameterfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameterfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameterfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)(ptrdiff_t)get_proc("glTexStorage3D");
  if (glow_glTexStorage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexStorage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexStorage3D\n");
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
  glow_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetFramebufferAttachmentParameteriv");
  if (glow_glGetFramebufferAttachmentParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFramebufferAttachmentParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFramebufferAttachmentParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)(ptrdiff_t)get_proc("glVertexAttribIFormat");
  if (glow_glVertexAttribIFormat == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribIFormat\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribIFormat\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)(ptrdiff_t)get_proc("glUniformMatrix4x3fv");
  if (glow_glUniformMatrix4x3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix4x3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix4x3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)(ptrdiff_t)get_proc("glProgramUniform3f");
  if (glow_glProgramUniform3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)(ptrdiff_t)get_proc("glProgramUniform2uiv");
  if (glow_glProgramUniform2uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2uiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)(ptrdiff_t)get_proc("glPatchParameteri");
  if (glow_glPatchParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPatchParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPatchParameteri\n");
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
  glow_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)(ptrdiff_t)get_proc("glIsRenderbuffer");
  if (glow_glIsRenderbuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsRenderbuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsRenderbuffer\n");
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
  glow_glUniform4ui = (PFNGLUNIFORM4UIPROC)(ptrdiff_t)get_proc("glUniform4ui");
  if (glow_glUniform4ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4ui\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetInteger64v = (PFNGLGETINTEGER64VPROC)(ptrdiff_t)get_proc("glGetInteger64v");
  if (glow_glGetInteger64v == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetInteger64v\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetInteger64v\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)(ptrdiff_t)get_proc("glGenProgramPipelines");
  if (glow_glGenProgramPipelines == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenProgramPipelines\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenProgramPipelines\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(ptrdiff_t)get_proc("glTexStorage2DMultisample");
  if (glow_glTexStorage2DMultisample == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexStorage2DMultisample\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexStorage2DMultisample\n");
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
  glow_glEndQuery = (PFNGLENDQUERYPROC)(ptrdiff_t)get_proc("glEndQuery");
  if (glow_glEndQuery == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEndQuery\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEndQuery\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)(ptrdiff_t)get_proc("glGetVertexAttribIuiv");
  if (glow_glGetVertexAttribIuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribIuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribIuiv\n");
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
  glow_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)(ptrdiff_t)get_proc("glCompressedTexImage3D");
  if (glow_glCompressedTexImage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCompressedTexImage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCompressedTexImage3D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)(ptrdiff_t)get_proc("glGetIntegeri_v");
  if (glow_glGetIntegeri_v == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetIntegeri_v\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetIntegeri_v\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(ptrdiff_t)get_proc("glTransformFeedbackVaryings");
  if (glow_glTransformFeedbackVaryings == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTransformFeedbackVaryings\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTransformFeedbackVaryings\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform1uiv = (PFNGLUNIFORM1UIVPROC)(ptrdiff_t)get_proc("glUniform1uiv");
  if (glow_glUniform1uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1uiv\n");
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
  glow_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)(ptrdiff_t)get_proc("glGetVertexAttribfv");
  if (glow_glGetVertexAttribfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribfv\n");
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
  glow_glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)(ptrdiff_t)get_proc("glResumeTransformFeedback");
  if (glow_glResumeTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glResumeTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glResumeTransformFeedback\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)(ptrdiff_t)get_proc("glFramebufferParameteri");
  if (glow_glFramebufferParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferParameteri\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)(ptrdiff_t)get_proc("glTexParameterIuiv");
  if (glow_glTexParameterIuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexParameterIuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexParameterIuiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)(ptrdiff_t)get_proc("glGetActiveUniformsiv");
  if (glow_glGetActiveUniformsiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetActiveUniformsiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetActiveUniformsiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(ptrdiff_t)get_proc("glGetActiveUniformBlockiv");
  if (glow_glGetActiveUniformBlockiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetActiveUniformBlockiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetActiveUniformBlockiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFenceSync = (PFNGLFENCESYNCPROC)(ptrdiff_t)get_proc("glFenceSync");
  if (glow_glFenceSync == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFenceSync\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFenceSync\n");
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
  glow_glIsEnabled = (PFNGLISENABLEDPROC)(ptrdiff_t)get_proc("glIsEnabled");
  if (glow_glIsEnabled == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsEnabled\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsEnabled\n");
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
  glow_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)(ptrdiff_t)get_proc("glVertexAttrib3f");
  if (glow_glVertexAttrib3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib3f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)(ptrdiff_t)get_proc("glGetTexParameterIuiv");
  if (glow_glGetTexParameterIuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameterIuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameterIuiv\n");
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
  glow_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)(ptrdiff_t)get_proc("glFramebufferRenderbuffer");
  if (glow_glFramebufferRenderbuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFramebufferRenderbuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFramebufferRenderbuffer\n");
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
  glow_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)(ptrdiff_t)get_proc("glGetAttachedShaders");
  if (glow_glGetAttachedShaders == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetAttachedShaders\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetAttachedShaders\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDrawBuffers = (PFNGLDRAWBUFFERSPROC)(ptrdiff_t)get_proc("glDrawBuffers");
  if (glow_glDrawBuffers == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawBuffers\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawBuffers\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform4uiv = (PFNGLUNIFORM4UIVPROC)(ptrdiff_t)get_proc("glUniform4uiv");
  if (glow_glUniform4uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4uiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)(ptrdiff_t)get_proc("glPauseTransformFeedback");
  if (glow_glPauseTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPauseTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPauseTransformFeedback\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)(ptrdiff_t)get_proc("glBindVertexBuffer");
  if (glow_glBindVertexBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindVertexBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindVertexBuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)(ptrdiff_t)get_proc("glPushDebugGroup");
  if (glow_glPushDebugGroup == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPushDebugGroup\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPushDebugGroup\n");
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
  glow_glUniform4fv = (PFNGLUNIFORM4FVPROC)(ptrdiff_t)get_proc("glUniform4fv");
  if (glow_glUniform4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)(ptrdiff_t)get_proc("glBindTransformFeedback");
  if (glow_glBindTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindTransformFeedback\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)(ptrdiff_t)get_proc("glProgramUniform2iv");
  if (glow_glProgramUniform2iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform2iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform2iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)(ptrdiff_t)get_proc("glGetMultisamplefv");
  if (glow_glGetMultisamplefv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMultisamplefv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMultisamplefv\n");
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
  glow_glUniform4iv = (PFNGLUNIFORM4IVPROC)(ptrdiff_t)get_proc("glUniform4iv");
  if (glow_glUniform4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform4iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)(ptrdiff_t)get_proc("glGetBufferParameteri64v");
  if (glow_glGetBufferParameteri64v == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBufferParameteri64v\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBufferParameteri64v\n");
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
  glow_glUniform3uiv = (PFNGLUNIFORM3UIVPROC)(ptrdiff_t)get_proc("glUniform3uiv");
  if (glow_glUniform3uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3uiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)(ptrdiff_t)get_proc("glGetProgramResourceName");
  if (glow_glGetProgramResourceName == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetProgramResourceName\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetProgramResourceName\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)(ptrdiff_t)get_proc("glProgramUniform4i");
  if (glow_glProgramUniform4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)(ptrdiff_t)get_proc("glProgramUniform1f");
  if (glow_glProgramUniform1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform1f\n");
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
  glow_glDepthRangef = (PFNGLDEPTHRANGEFPROC)(ptrdiff_t)get_proc("glDepthRangef");
  if (glow_glDepthRangef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthRangef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthRangef\n");
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
  glow_glPrimitiveBoundingBox = (PFNGLPRIMITIVEBOUNDINGBOXPROC)(ptrdiff_t)get_proc("glPrimitiveBoundingBox");
  if (glow_glPrimitiveBoundingBox == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPrimitiveBoundingBox\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPrimitiveBoundingBox\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)(ptrdiff_t)get_proc("glBeginTransformFeedback");
  if (glow_glBeginTransformFeedback == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBeginTransformFeedback\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBeginTransformFeedback\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)(ptrdiff_t)get_proc("glClearBufferfv");
  if (glow_glClearBufferfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearBufferfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearBufferfv\n");
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
  glow_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)(ptrdiff_t)get_proc("glTexSubImage3D");
  if (glow_glTexSubImage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexSubImage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexSubImage3D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform1ui = (PFNGLUNIFORM1UIPROC)(ptrdiff_t)get_proc("glUniform1ui");
  if (glow_glUniform1ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform1ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform1ui\n");
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
  glow_glAttachShader = (PFNGLATTACHSHADERPROC)(ptrdiff_t)get_proc("glAttachShader");
  if (glow_glAttachShader == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glAttachShader\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glAttachShader\n");
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
  glow_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)(ptrdiff_t)get_proc("glCopyTexSubImage3D");
  if (glow_glCopyTexSubImage3D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyTexSubImage3D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyTexSubImage3D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)(ptrdiff_t)get_proc("glUniformMatrix3x2fv");
  if (glow_glUniformMatrix3x2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniformMatrix3x2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniformMatrix3x2fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBindSampler = (PFNGLBINDSAMPLERPROC)(ptrdiff_t)get_proc("glBindSampler");
  if (glow_glBindSampler == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindSampler\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindSampler\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)(ptrdiff_t)get_proc("glVertexAttribBinding");
  if (glow_glVertexAttribBinding == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribBinding\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribBinding\n");
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
  glow_glGetError = (PFNGLGETERRORPROC)(ptrdiff_t)get_proc("glGetError");
  if (glow_glGetError == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetError\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetError\n");
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
  glow_glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)(ptrdiff_t)get_proc("glDrawArraysInstanced");
  if (glow_glDrawArraysInstanced == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawArraysInstanced\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawArraysInstanced\n");
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
  glow_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)(ptrdiff_t)get_proc("glGenVertexArrays");
  if (glow_glGenVertexArrays == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenVertexArrays\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenVertexArrays\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsVertexArray = (PFNGLISVERTEXARRAYPROC)(ptrdiff_t)get_proc("glIsVertexArray");
  if (glow_glIsVertexArray == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsVertexArray\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsVertexArray\n");
#endif
    unresolved_count += 1;
  } 
  glow_glWaitSync = (PFNGLWAITSYNCPROC)(ptrdiff_t)get_proc("glWaitSync");
  if (glow_glWaitSync == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glWaitSync\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glWaitSync\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)(ptrdiff_t)get_proc("glProgramUniform4ui");
  if (glow_glProgramUniform4ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4ui\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(ptrdiff_t)get_proc("glProgramUniformMatrix2fv");
  if (glow_glProgramUniformMatrix2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix2fv\n");
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
  glow_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)(ptrdiff_t)get_proc("glGetVertexAttribPointerv");
  if (glow_glGetVertexAttribPointerv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetVertexAttribPointerv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetVertexAttribPointerv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(ptrdiff_t)get_proc("glGetTransformFeedbackVarying");
  if (glow_glGetTransformFeedbackVarying == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTransformFeedbackVarying\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTransformFeedbackVarying\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform3ui = (PFNGLUNIFORM3UIPROC)(ptrdiff_t)get_proc("glUniform3ui");
  if (glow_glUniform3ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform3ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform3ui\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetSynciv = (PFNGLGETSYNCIVPROC)(ptrdiff_t)get_proc("glGetSynciv");
  if (glow_glGetSynciv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetSynciv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetSynciv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)(ptrdiff_t)get_proc("glProgramUniform4f");
  if (glow_glProgramUniform4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform4f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)(ptrdiff_t)get_proc("glProgramUniform3iv");
  if (glow_glProgramUniform3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)(ptrdiff_t)get_proc("glDebugMessageInsert");
  if (glow_glDebugMessageInsert == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDebugMessageInsert\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDebugMessageInsert\n");
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
  glow_glGetUniformiv = (PFNGLGETUNIFORMIVPROC)(ptrdiff_t)get_proc("glGetUniformiv");
  if (glow_glGetUniformiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetUniformiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetUniformiv\n");
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
  glow_glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)(ptrdiff_t)get_proc("glPopDebugGroup");
  if (glow_glPopDebugGroup == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPopDebugGroup\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPopDebugGroup\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)(ptrdiff_t)get_proc("glGetObjectPtrLabel");
  if (glow_glGetObjectPtrLabel == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetObjectPtrLabel\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetObjectPtrLabel\n");
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
  glow_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)(ptrdiff_t)get_proc("glStencilFuncSeparate");
  if (glow_glStencilFuncSeparate == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilFuncSeparate\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilFuncSeparate\n");
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
  glow_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)(ptrdiff_t)get_proc("glBindFramebuffer");
  if (glow_glBindFramebuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBindFramebuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBindFramebuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBlendColor = (PFNGLBLENDCOLORPROC)(ptrdiff_t)get_proc("glBlendColor");
  if (glow_glBlendColor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBlendColor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBlendColor\n");
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
  glow_glObjectLabel = (PFNGLOBJECTLABELPROC)(ptrdiff_t)get_proc("glObjectLabel");
  if (glow_glObjectLabel == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glObjectLabel\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glObjectLabel\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)(ptrdiff_t)get_proc("glGetObjectLabel");
  if (glow_glGetObjectLabel == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetObjectLabel\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetObjectLabel\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC)(ptrdiff_t)get_proc("glGetGraphicsResetStatus");
  if (glow_glGetGraphicsResetStatus == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetGraphicsResetStatus\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetGraphicsResetStatus\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)(ptrdiff_t)get_proc("glClearBufferfi");
  if (glow_glClearBufferfi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearBufferfi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearBufferfi\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)(ptrdiff_t)get_proc("glProgramUniform3fv");
  if (glow_glProgramUniform3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniform3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniform3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glSampleMaski = (PFNGLSAMPLEMASKIPROC)(ptrdiff_t)get_proc("glSampleMaski");
  if (glow_glSampleMaski == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSampleMaski\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSampleMaski\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(ptrdiff_t)get_proc("glProgramUniformMatrix3x2fv");
  if (glow_glProgramUniformMatrix3x2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix3x2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix3x2fv\n");
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
  glow_glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)(ptrdiff_t)get_proc("glGetFragDataLocation");
  if (glow_glGetFragDataLocation == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFragDataLocation\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFragDataLocation\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(ptrdiff_t)get_proc("glProgramUniformMatrix3fv");
  if (glow_glProgramUniformMatrix3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramUniformMatrix3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramUniformMatrix3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)(ptrdiff_t)get_proc("glGetSamplerParameterIuiv");
  if (glow_glGetSamplerParameterIuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetSamplerParameterIuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetSamplerParameterIuiv\n");
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
  glow_glClearColor = (PFNGLCLEARCOLORPROC)(ptrdiff_t)get_proc("glClearColor");
  if (glow_glClearColor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearColor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearColor\n");
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
  glow_glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetSamplerParameteriv");
  if (glow_glGetSamplerParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetSamplerParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetSamplerParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)(ptrdiff_t)get_proc("glProgramParameteri");
  if (glow_glProgramParameteri == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glProgramParameteri\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glProgramParameteri\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDeleteQueries = (PFNGLDELETEQUERIESPROC)(ptrdiff_t)get_proc("glDeleteQueries");
  if (glow_glDeleteQueries == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteQueries\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteQueries\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(ptrdiff_t)get_proc("glGetActiveUniformBlockName");
  if (glow_glGetActiveUniformBlockName == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetActiveUniformBlockName\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetActiveUniformBlockName\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)(ptrdiff_t)get_proc("glClientWaitSync");
  if (glow_glClientWaitSync == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClientWaitSync\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClientWaitSync\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)(ptrdiff_t)get_proc("glVertexAttribDivisor");
  if (glow_glVertexAttribDivisor == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttribDivisor\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttribDivisor\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)(ptrdiff_t)get_proc("glIsProgramPipeline");
  if (glow_glIsProgramPipeline == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsProgramPipeline\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsProgramPipeline\n");
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
  glow_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)(ptrdiff_t)get_proc("glVertexAttrib2f");
  if (glow_glVertexAttrib2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertexAttrib2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertexAttrib2f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glReadBuffer = (PFNGLREADBUFFERPROC)(ptrdiff_t)get_proc("glReadBuffer");
  if (glow_glReadBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReadBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReadBuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)(ptrdiff_t)get_proc("glMemoryBarrierByRegion");
  if (glow_glMemoryBarrierByRegion == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMemoryBarrierByRegion\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMemoryBarrierByRegion\n");
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
  glow_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetBufferParameteriv");
  if (glow_glGetBufferParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetBufferParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetBufferParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glUniform2uiv = (PFNGLUNIFORM2UIVPROC)(ptrdiff_t)get_proc("glUniform2uiv");
  if (glow_glUniform2uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glUniform2uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glUniform2uiv\n");
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
