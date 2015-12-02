/*
 * glow-1.0.0: public-domain OpenGL function loader
 *
 * This file was generated with glow https://github.com/jshrake/glow
 * 
 * Version: 1.0.0
 * Date: 2015-11-27 09:08:08.674060428 -0800 PST
 * Language: C
 * Specification: 1.0
 * API: gl
 * Profile: core
 * Command-line: glow --api="gl" --spec="1.0" --profile="core" --debug=true
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
#define GL_VERSION_1_0

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
typedef void (APIENTRYP *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;

/*
 * ---------------------------
 * Enums
 * ---------------------------
 */

/*
 * ---------------------------
 * Commands
 * ---------------------------
 */

typedef void (APIENTRYP PFNGLGETLIGHTIVPROC)(GLenum light, GLenum pname, GLint *params);
GLOWDEF PFNGLGETLIGHTIVPROC glow_glGetLightiv;
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
GLOWDEF PFNGLLINEWIDTHPROC glow_glLineWidth;
typedef void (APIENTRYP PFNGLRASTERPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
GLOWDEF PFNGLRASTERPOS3DPROC glow_glRasterPos3d;
typedef void (APIENTRYP PFNGLLIGHTIVPROC)(GLenum light, GLenum pname, const GLint *params);
GLOWDEF PFNGLLIGHTIVPROC glow_glLightiv;
typedef void (APIENTRYP PFNGLPIXELMAPFVPROC)(GLenum map, GLsizei mapsize, const GLfloat *values);
GLOWDEF PFNGLPIXELMAPFVPROC glow_glPixelMapfv;
typedef void (APIENTRYP PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
GLOWDEF PFNGLSCALEFPROC glow_glScalef;
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLOWDEF PFNGLREADPIXELSPROC glow_glReadPixels;
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint *data);
GLOWDEF PFNGLGETINTEGERVPROC glow_glGetIntegerv;
typedef void (APIENTRYP PFNGLRASTERPOS3IVPROC)(const GLint *v);
GLOWDEF PFNGLRASTERPOS3IVPROC glow_glRasterPos3iv;
typedef void (APIENTRYP PFNGLRASTERPOS4SVPROC)(const GLshort *v);
GLOWDEF PFNGLRASTERPOS4SVPROC glow_glRasterPos4sv;
typedef void (APIENTRYP PFNGLTEXCOORD4DVPROC)(const GLdouble *v);
GLOWDEF PFNGLTEXCOORD4DVPROC glow_glTexCoord4dv;
typedef void (APIENTRYP PFNGLTEXCOORD4FPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLOWDEF PFNGLTEXCOORD4FPROC glow_glTexCoord4f;
typedef void (APIENTRYP PFNGLVERTEX3SPROC)(GLshort x, GLshort y, GLshort z);
GLOWDEF PFNGLVERTEX3SPROC glow_glVertex3s;
typedef void (APIENTRYP PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte *mask);
GLOWDEF PFNGLGETPOLYGONSTIPPLEPROC glow_glGetPolygonStipple;
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
GLOWDEF PFNGLTEXPARAMETERIPROC glow_glTexParameteri;
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLTEXIMAGE2DPROC glow_glTexImage2D;
typedef void (APIENTRYP PFNGLRASTERPOS2DVPROC)(const GLdouble *v);
GLOWDEF PFNGLRASTERPOS2DVPROC glow_glRasterPos2dv;
typedef void (APIENTRYP PFNGLTEXCOORD3DPROC)(GLdouble s, GLdouble t, GLdouble r);
GLOWDEF PFNGLTEXCOORD3DPROC glow_glTexCoord3d;
typedef void (APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
GLOWDEF PFNGLLOGICOPPROC glow_glLogicOp;
typedef void (APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
GLOWDEF PFNGLREADBUFFERPROC glow_glReadBuffer;
typedef void (APIENTRYP PFNGLRASTERPOS2FPROC)(GLfloat x, GLfloat y);
GLOWDEF PFNGLRASTERPOS2FPROC glow_glRasterPos2f;
typedef void (APIENTRYP PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLMATERIALFVPROC glow_glMaterialfv;
typedef void (APIENTRYP PFNGLLOADMATRIXDPROC)(const GLdouble *m);
GLOWDEF PFNGLLOADMATRIXDPROC glow_glLoadMatrixd;
typedef void (APIENTRYP PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);
GLOWDEF PFNGLTRANSLATEFPROC glow_glTranslatef;
typedef void (APIENTRYP PFNGLFLUSHPROC)();
GLOWDEF PFNGLFLUSHPROC glow_glFlush;
typedef void (APIENTRYP PFNGLCOLOR3BVPROC)(const GLbyte *v);
GLOWDEF PFNGLCOLOR3BVPROC glow_glColor3bv;
typedef void (APIENTRYP PFNGLCOLOR4UIVPROC)(const GLuint *v);
GLOWDEF PFNGLCOLOR4UIVPROC glow_glColor4uiv;
typedef void (APIENTRYP PFNGLRASTERPOS4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLOWDEF PFNGLRASTERPOS4DPROC glow_glRasterPos4d;
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLOWDEF PFNGLTEXPARAMETERIVPROC glow_glTexParameteriv;
typedef void (APIENTRYP PFNGLCOLOR4SVPROC)(const GLshort *v);
GLOWDEF PFNGLCOLOR4SVPROC glow_glColor4sv;
typedef void (APIENTRYP PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETTEXENVFVPROC glow_glGetTexEnvfv;
typedef void (APIENTRYP PFNGLRECTFPROC)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
GLOWDEF PFNGLRECTFPROC glow_glRectf;
typedef void (APIENTRYP PFNGLSHADEMODELPROC)(GLenum mode);
GLOWDEF PFNGLSHADEMODELPROC glow_glShadeModel;
typedef void (APIENTRYP PFNGLLOADMATRIXFPROC)(const GLfloat *m);
GLOWDEF PFNGLLOADMATRIXFPROC glow_glLoadMatrixf;
typedef void (APIENTRYP PFNGLLISTBASEPROC)(GLuint base);
GLOWDEF PFNGLLISTBASEPROC glow_glListBase;
typedef void (APIENTRYP PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
GLOWDEF PFNGLCOLOR4UBPROC glow_glColor4ub;
typedef void (APIENTRYP PFNGLINDEXFPROC)(GLfloat c);
GLOWDEF PFNGLINDEXFPROC glow_glIndexf;
typedef void (APIENTRYP PFNGLRASTERPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
GLOWDEF PFNGLRASTERPOS3FPROC glow_glRasterPos3f;
typedef void (APIENTRYP PFNGLEVALPOINT1PROC)(GLint i);
GLOWDEF PFNGLEVALPOINT1PROC glow_glEvalPoint1;
typedef void (APIENTRYP PFNGLGETPIXELMAPUSVPROC)(GLenum map, GLushort *values);
GLOWDEF PFNGLGETPIXELMAPUSVPROC glow_glGetPixelMapusv;
typedef void (APIENTRYP PFNGLGETTEXGENIVPROC)(GLenum coord, GLenum pname, GLint *params);
GLOWDEF PFNGLGETTEXGENIVPROC glow_glGetTexGeniv;
typedef void (APIENTRYP PFNGLBITMAPPROC)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
GLOWDEF PFNGLBITMAPPROC glow_glBitmap;
typedef void (APIENTRYP PFNGLNORMAL3IPROC)(GLint nx, GLint ny, GLint nz);
GLOWDEF PFNGLNORMAL3IPROC glow_glNormal3i;
typedef void (APIENTRYP PFNGLRASTERPOS3SVPROC)(const GLshort *v);
GLOWDEF PFNGLRASTERPOS3SVPROC glow_glRasterPos3sv;
typedef void (APIENTRYP PFNGLMATERIALIVPROC)(GLenum face, GLenum pname, const GLint *params);
GLOWDEF PFNGLMATERIALIVPROC glow_glMaterialiv;
typedef GLubyte (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
GLOWDEF PFNGLGETSTRINGPROC glow_glGetString;
typedef void (APIENTRYP PFNGLLOADNAMEPROC)(GLuint name);
GLOWDEF PFNGLLOADNAMEPROC glow_glLoadName;
typedef void (APIENTRYP PFNGLCLEARINDEXPROC)(GLfloat c);
GLOWDEF PFNGLCLEARINDEXPROC glow_glClearIndex;
typedef void (APIENTRYP PFNGLCLIPPLANEPROC)(GLenum plane, const GLdouble *equation);
GLOWDEF PFNGLCLIPPLANEPROC glow_glClipPlane;
typedef void (APIENTRYP PFNGLGETMAPIVPROC)(GLenum target, GLenum query, GLint *v);
GLOWDEF PFNGLGETMAPIVPROC glow_glGetMapiv;
typedef void (APIENTRYP PFNGLMAP2DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
GLOWDEF PFNGLMAP2DPROC glow_glMap2d;
typedef void (APIENTRYP PFNGLEVALCOORD2FVPROC)(const GLfloat *u);
GLOWDEF PFNGLEVALCOORD2FVPROC glow_glEvalCoord2fv;
typedef void (APIENTRYP PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETTEXENVIVPROC glow_glGetTexEnviv;
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
GLOWDEF PFNGLDISABLEPROC glow_glDisable;
typedef void (APIENTRYP PFNGLCOLOR4IPROC)(GLint red, GLint green, GLint blue, GLint alpha);
GLOWDEF PFNGLCOLOR4IPROC glow_glColor4i;
typedef void (APIENTRYP PFNGLTEXCOORD3IPROC)(GLint s, GLint t, GLint r);
GLOWDEF PFNGLTEXCOORD3IPROC glow_glTexCoord3i;
typedef void (APIENTRYP PFNGLPUSHMATRIXPROC)();
GLOWDEF PFNGLPUSHMATRIXPROC glow_glPushMatrix;
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLTEXIMAGE1DPROC glow_glTexImage1D;
typedef void (APIENTRYP PFNGLTEXCOORD3SPROC)(GLshort s, GLshort t, GLshort r);
GLOWDEF PFNGLTEXCOORD3SPROC glow_glTexCoord3s;
typedef void (APIENTRYP PFNGLEVALCOORD1FPROC)(GLfloat u);
GLOWDEF PFNGLEVALCOORD1FPROC glow_glEvalCoord1f;
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint *params);
GLOWDEF PFNGLGETTEXLEVELPARAMETERIVPROC glow_glGetTexLevelParameteriv;
typedef void (APIENTRYP PFNGLCOLOR4DVPROC)(const GLdouble *v);
GLOWDEF PFNGLCOLOR4DVPROC glow_glColor4dv;
typedef void (APIENTRYP PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLOWDEF PFNGLCOLOR4FPROC glow_glColor4f;
typedef void (APIENTRYP PFNGLEDGEFLAGVPROC)(const GLboolean *flag);
GLOWDEF PFNGLEDGEFLAGVPROC glow_glEdgeFlagv;
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
GLOWDEF PFNGLCLEARSTENCILPROC glow_glClearStencil;
typedef void (APIENTRYP PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLTEXENVFVPROC glow_glTexEnvfv;
typedef void (APIENTRYP PFNGLCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
GLOWDEF PFNGLCOLOR3BPROC glow_glColor3b;
typedef void (APIENTRYP PFNGLCOLOR4DPROC)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
GLOWDEF PFNGLCOLOR4DPROC glow_glColor4d;
typedef void (APIENTRYP PFNGLTEXCOORD2FVPROC)(const GLfloat *v);
GLOWDEF PFNGLTEXCOORD2FVPROC glow_glTexCoord2fv;
typedef void (APIENTRYP PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint *params);
GLOWDEF PFNGLTEXENVIVPROC glow_glTexEnviv;
typedef void (APIENTRYP PFNGLGETCLIPPLANEPROC)(GLenum plane, GLdouble *equation);
GLOWDEF PFNGLGETCLIPPLANEPROC glow_glGetClipPlane;
typedef void (APIENTRYP PFNGLCOLOR4UIPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
GLOWDEF PFNGLCOLOR4UIPROC glow_glColor4ui;
typedef void (APIENTRYP PFNGLTEXCOORD1FVPROC)(const GLfloat *v);
GLOWDEF PFNGLTEXCOORD1FVPROC glow_glTexCoord1fv;
typedef void (APIENTRYP PFNGLVERTEX4IPROC)(GLint x, GLint y, GLint z, GLint w);
GLOWDEF PFNGLVERTEX4IPROC glow_glVertex4i;
typedef void (APIENTRYP PFNGLLIGHTIPROC)(GLenum light, GLenum pname, GLint param);
GLOWDEF PFNGLLIGHTIPROC glow_glLighti;
typedef void (APIENTRYP PFNGLGETTEXGENDVPROC)(GLenum coord, GLenum pname, GLdouble *params);
GLOWDEF PFNGLGETTEXGENDVPROC glow_glGetTexGendv;
typedef void (APIENTRYP PFNGLCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
GLOWDEF PFNGLCOLOR3USPROC glow_glColor3us;
typedef void (APIENTRYP PFNGLRASTERPOS4DVPROC)(const GLdouble *v);
GLOWDEF PFNGLRASTERPOS4DVPROC glow_glRasterPos4dv;
typedef void (APIENTRYP PFNGLRASTERPOS4IVPROC)(const GLint *v);
GLOWDEF PFNGLRASTERPOS4IVPROC glow_glRasterPos4iv;
typedef void (APIENTRYP PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
GLOWDEF PFNGLTEXENVFPROC glow_glTexEnvf;
typedef void (APIENTRYP PFNGLCOLOR3IPROC)(GLint red, GLint green, GLint blue);
GLOWDEF PFNGLCOLOR3IPROC glow_glColor3i;
typedef void (APIENTRYP PFNGLPOLYGONSTIPPLEPROC)(const GLubyte *mask);
GLOWDEF PFNGLPOLYGONSTIPPLEPROC glow_glPolygonStipple;
typedef void (APIENTRYP PFNGLPIXELMAPUIVPROC)(GLenum map, GLsizei mapsize, const GLuint *values);
GLOWDEF PFNGLPIXELMAPUIVPROC glow_glPixelMapuiv;
typedef void (APIENTRYP PFNGLMULTMATRIXFPROC)(const GLfloat *m);
GLOWDEF PFNGLMULTMATRIXFPROC glow_glMultMatrixf;
typedef void (APIENTRYP PFNGLINDEXDVPROC)(const GLdouble *c);
GLOWDEF PFNGLINDEXDVPROC glow_glIndexdv;
typedef void (APIENTRYP PFNGLTEXCOORD4SPROC)(GLshort s, GLshort t, GLshort r, GLshort q);
GLOWDEF PFNGLTEXCOORD4SPROC glow_glTexCoord4s;
typedef void (APIENTRYP PFNGLVERTEX3FPROC)(GLfloat x, GLfloat y, GLfloat z);
GLOWDEF PFNGLVERTEX3FPROC glow_glVertex3f;
typedef void (APIENTRYP PFNGLMAP1FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
GLOWDEF PFNGLMAP1FPROC glow_glMap1f;
typedef void (APIENTRYP PFNGLEVALMESH1PROC)(GLenum mode, GLint i1, GLint i2);
GLOWDEF PFNGLEVALMESH1PROC glow_glEvalMesh1;
typedef GLboolean (APIENTRYP PFNGLISLISTPROC)(GLuint list);
GLOWDEF PFNGLISLISTPROC glow_glIsList;
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETTEXLEVELPARAMETERFVPROC glow_glGetTexLevelParameterfv;
typedef void (APIENTRYP PFNGLNORMAL3SVPROC)(const GLshort *v);
GLOWDEF PFNGLNORMAL3SVPROC glow_glNormal3sv;
typedef void (APIENTRYP PFNGLTEXCOORD3SVPROC)(const GLshort *v);
GLOWDEF PFNGLTEXCOORD3SVPROC glow_glTexCoord3sv;
typedef void (APIENTRYP PFNGLVERTEX3IPROC)(GLint x, GLint y, GLint z);
GLOWDEF PFNGLVERTEX3IPROC glow_glVertex3i;
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
GLOWDEF PFNGLBLENDFUNCPROC glow_glBlendFunc;
typedef void (APIENTRYP PFNGLTEXGENDPROC)(GLenum coord, GLenum pname, GLdouble param);
GLOWDEF PFNGLTEXGENDPROC glow_glTexGend;
typedef void (APIENTRYP PFNGLPIXELTRANSFERIPROC)(GLenum pname, GLint param);
GLOWDEF PFNGLPIXELTRANSFERIPROC glow_glPixelTransferi;
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
GLOWDEF PFNGLCLEARPROC glow_glClear;
typedef void (APIENTRYP PFNGLRECTFVPROC)(const GLfloat *v1, const GLfloat *v2);
GLOWDEF PFNGLRECTFVPROC glow_glRectfv;
typedef void (APIENTRYP PFNGLTEXCOORD1DPROC)(GLdouble s);
GLOWDEF PFNGLTEXCOORD1DPROC glow_glTexCoord1d;
typedef void (APIENTRYP PFNGLTEXGENIVPROC)(GLenum coord, GLenum pname, const GLint *params);
GLOWDEF PFNGLTEXGENIVPROC glow_glTexGeniv;
typedef void (APIENTRYP PFNGLVERTEX4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLOWDEF PFNGLVERTEX4FPROC glow_glVertex4f;
typedef void (APIENTRYP PFNGLEVALCOORD2DVPROC)(const GLdouble *u);
GLOWDEF PFNGLEVALCOORD2DVPROC glow_glEvalCoord2dv;
typedef void (APIENTRYP PFNGLGETTEXGENFVPROC)(GLenum coord, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETTEXGENFVPROC glow_glGetTexGenfv;
typedef void (APIENTRYP PFNGLCOLOR3USVPROC)(const GLushort *v);
GLOWDEF PFNGLCOLOR3USVPROC glow_glColor3usv;
typedef void (APIENTRYP PFNGLCOLOR4SPROC)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
GLOWDEF PFNGLCOLOR4SPROC glow_glColor4s;
typedef void (APIENTRYP PFNGLINDEXSPROC)(GLshort c);
GLOWDEF PFNGLINDEXSPROC glow_glIndexs;
typedef void (APIENTRYP PFNGLTEXCOORD1SPROC)(GLshort s);
GLOWDEF PFNGLTEXCOORD1SPROC glow_glTexCoord1s;
typedef void (APIENTRYP PFNGLRASTERPOS2SVPROC)(const GLshort *v);
GLOWDEF PFNGLRASTERPOS2SVPROC glow_glRasterPos2sv;
typedef void (APIENTRYP PFNGLTEXCOORD4SVPROC)(const GLshort *v);
GLOWDEF PFNGLTEXCOORD4SVPROC glow_glTexCoord4sv;
typedef void (APIENTRYP PFNGLINITNAMESPROC)();
GLOWDEF PFNGLINITNAMESPROC glow_glInitNames;
typedef void (APIENTRYP PFNGLMATRIXMODEPROC)(GLenum mode);
GLOWDEF PFNGLMATRIXMODEPROC glow_glMatrixMode;
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble depth);
GLOWDEF PFNGLCLEARDEPTHPROC glow_glClearDepth;
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLVIEWPORTPROC glow_glViewport;
typedef void (APIENTRYP PFNGLCOLOR3DVPROC)(const GLdouble *v);
GLOWDEF PFNGLCOLOR3DVPROC glow_glColor3dv;
typedef void (APIENTRYP PFNGLCOLOR4BVPROC)(const GLbyte *v);
GLOWDEF PFNGLCOLOR4BVPROC glow_glColor4bv;
typedef void (APIENTRYP PFNGLVERTEX3FVPROC)(const GLfloat *v);
GLOWDEF PFNGLVERTEX3FVPROC glow_glVertex3fv;
typedef void (APIENTRYP PFNGLPOPATTRIBPROC)();
GLOWDEF PFNGLPOPATTRIBPROC glow_glPopAttrib;
typedef void (APIENTRYP PFNGLMAP1DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
GLOWDEF PFNGLMAP1DPROC glow_glMap1d;
typedef void (APIENTRYP PFNGLEVALCOORD2DPROC)(GLdouble u, GLdouble v);
GLOWDEF PFNGLEVALCOORD2DPROC glow_glEvalCoord2d;
typedef void (APIENTRYP PFNGLCOLOR4BPROC)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
GLOWDEF PFNGLCOLOR4BPROC glow_glColor4b;
typedef void (APIENTRYP PFNGLNORMAL3SPROC)(GLshort nx, GLshort ny, GLshort nz);
GLOWDEF PFNGLNORMAL3SPROC glow_glNormal3s;
typedef void (APIENTRYP PFNGLRASTERPOS2IPROC)(GLint x, GLint y);
GLOWDEF PFNGLRASTERPOS2IPROC glow_glRasterPos2i;
typedef void (APIENTRYP PFNGLVERTEX4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
GLOWDEF PFNGLVERTEX4SPROC glow_glVertex4s;
typedef void (APIENTRYP PFNGLRASTERPOS3DVPROC)(const GLdouble *v);
GLOWDEF PFNGLRASTERPOS3DVPROC glow_glRasterPos3dv;
typedef void (APIENTRYP PFNGLTEXCOORD2DPROC)(GLdouble s, GLdouble t);
GLOWDEF PFNGLTEXCOORD2DPROC glow_glTexCoord2d;
typedef void (APIENTRYP PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
GLOWDEF PFNGLLIGHTFPROC glow_glLightf;
typedef void (APIENTRYP PFNGLDRAWPIXELSPROC)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLOWDEF PFNGLDRAWPIXELSPROC glow_glDrawPixels;
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
GLOWDEF PFNGLSCISSORPROC glow_glScissor;
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLOWDEF PFNGLCOLORMASKPROC glow_glColorMask;
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean *data);
GLOWDEF PFNGLGETBOOLEANVPROC glow_glGetBooleanv;
typedef void (APIENTRYP PFNGLCOLOR4IVPROC)(const GLint *v);
GLOWDEF PFNGLCOLOR4IVPROC glow_glColor4iv;
typedef void (APIENTRYP PFNGLCOPYPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
GLOWDEF PFNGLCOPYPIXELSPROC glow_glCopyPixels;
typedef void (APIENTRYP PFNGLROTATEDPROC)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
GLOWDEF PFNGLROTATEDPROC glow_glRotated;
typedef void (APIENTRYP PFNGLTRANSLATEDPROC)(GLdouble x, GLdouble y, GLdouble z);
GLOWDEF PFNGLTRANSLATEDPROC glow_glTranslated;
typedef GLuint (APIENTRYP PFNGLGENLISTSPROC)(GLsizei range);
GLOWDEF PFNGLGENLISTSPROC glow_glGenLists;
typedef void (APIENTRYP PFNGLTEXCOORD1FPROC)(GLfloat s);
GLOWDEF PFNGLTEXCOORD1FPROC glow_glTexCoord1f;
typedef void (APIENTRYP PFNGLFOGFVPROC)(GLenum pname, const GLfloat *params);
GLOWDEF PFNGLFOGFVPROC glow_glFogfv;
typedef void (APIENTRYP PFNGLEVALCOORD1DVPROC)(const GLdouble *u);
GLOWDEF PFNGLEVALCOORD1DVPROC glow_glEvalCoord1dv;
typedef void (APIENTRYP PFNGLTEXCOORD2DVPROC)(const GLdouble *v);
GLOWDEF PFNGLTEXCOORD2DVPROC glow_glTexCoord2dv;
typedef void (APIENTRYP PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat *params);
GLOWDEF PFNGLLIGHTMODELFVPROC glow_glLightModelfv;
typedef void (APIENTRYP PFNGLPOPNAMEPROC)();
GLOWDEF PFNGLPOPNAMEPROC glow_glPopName;
typedef void (APIENTRYP PFNGLPUSHATTRIBPROC)(GLbitfield mask);
GLOWDEF PFNGLPUSHATTRIBPROC glow_glPushAttrib;
typedef void (APIENTRYP PFNGLCOLOR3UBVPROC)(const GLubyte *v);
GLOWDEF PFNGLCOLOR3UBVPROC glow_glColor3ubv;
typedef void (APIENTRYP PFNGLTEXCOORD2IPROC)(GLint s, GLint t);
GLOWDEF PFNGLTEXCOORD2IPROC glow_glTexCoord2i;
typedef void (APIENTRYP PFNGLCOLOR4UBVPROC)(const GLubyte *v);
GLOWDEF PFNGLCOLOR4UBVPROC glow_glColor4ubv;
typedef void (APIENTRYP PFNGLVERTEX2SPROC)(GLshort x, GLshort y);
GLOWDEF PFNGLVERTEX2SPROC glow_glVertex2s;
typedef void (APIENTRYP PFNGLVERTEX3IVPROC)(const GLint *v);
GLOWDEF PFNGLVERTEX3IVPROC glow_glVertex3iv;
typedef void (APIENTRYP PFNGLFEEDBACKBUFFERPROC)(GLsizei size, GLenum type, GLfloat *buffer);
GLOWDEF PFNGLFEEDBACKBUFFERPROC glow_glFeedbackBuffer;
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
GLOWDEF PFNGLSTENCILFUNCPROC glow_glStencilFunc;
typedef void (APIENTRYP PFNGLCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
GLOWDEF PFNGLCOLOR3DPROC glow_glColor3d;
typedef void (APIENTRYP PFNGLCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
GLOWDEF PFNGLCOLOR3SPROC glow_glColor3s;
typedef void (APIENTRYP PFNGLCOLOR3SVPROC)(const GLshort *v);
GLOWDEF PFNGLCOLOR3SVPROC glow_glColor3sv;
typedef void (APIENTRYP PFNGLALPHAFUNCPROC)(GLenum func, GLfloat ref);
GLOWDEF PFNGLALPHAFUNCPROC glow_glAlphaFunc;
typedef void (APIENTRYP PFNGLGETPIXELMAPFVPROC)(GLenum map, GLfloat *values);
GLOWDEF PFNGLGETPIXELMAPFVPROC glow_glGetPixelMapfv;
typedef void (APIENTRYP PFNGLTEXCOORD2IVPROC)(const GLint *v);
GLOWDEF PFNGLTEXCOORD2IVPROC glow_glTexCoord2iv;
typedef void (APIENTRYP PFNGLMAP2FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
GLOWDEF PFNGLMAP2FPROC glow_glMap2f;
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
GLOWDEF PFNGLFRONTFACEPROC glow_glFrontFace;
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum buf);
GLOWDEF PFNGLDRAWBUFFERPROC glow_glDrawBuffer;
typedef void (APIENTRYP PFNGLCALLLISTPROC)(GLuint list);
GLOWDEF PFNGLCALLLISTPROC glow_glCallList;
typedef void (APIENTRYP PFNGLTEXCOORD1SVPROC)(const GLshort *v);
GLOWDEF PFNGLTEXCOORD1SVPROC glow_glTexCoord1sv;
typedef void (APIENTRYP PFNGLGETMAPFVPROC)(GLenum target, GLenum query, GLfloat *v);
GLOWDEF PFNGLGETMAPFVPROC glow_glGetMapfv;
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)();
GLOWDEF PFNGLGETERRORPROC glow_glGetError;
typedef void (APIENTRYP PFNGLTEXCOORD2SPROC)(GLshort s, GLshort t);
GLOWDEF PFNGLTEXCOORD2SPROC glow_glTexCoord2s;
typedef void (APIENTRYP PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLLIGHTFVPROC glow_glLightfv;
typedef void (APIENTRYP PFNGLTEXGENFVPROC)(GLenum coord, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLTEXGENFVPROC glow_glTexGenfv;
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
GLOWDEF PFNGLTEXPARAMETERFPROC glow_glTexParameterf;
typedef void (APIENTRYP PFNGLVERTEX2DPROC)(GLdouble x, GLdouble y);
GLOWDEF PFNGLVERTEX2DPROC glow_glVertex2d;
typedef void (APIENTRYP PFNGLLINESTIPPLEPROC)(GLint factor, GLushort pattern);
GLOWDEF PFNGLLINESTIPPLEPROC glow_glLineStipple;
typedef void (APIENTRYP PFNGLORTHOPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLOWDEF PFNGLORTHOPROC glow_glOrtho;
typedef void (APIENTRYP PFNGLTEXCOORD3DVPROC)(const GLdouble *v);
GLOWDEF PFNGLTEXCOORD3DVPROC glow_glTexCoord3dv;
typedef GLint (APIENTRYP PFNGLRENDERMODEPROC)(GLenum mode);
GLOWDEF PFNGLRENDERMODEPROC glow_glRenderMode;
typedef void (APIENTRYP PFNGLCALLLISTSPROC)(GLsizei n, GLenum type, const void *lists);
GLOWDEF PFNGLCALLLISTSPROC glow_glCallLists;
typedef void (APIENTRYP PFNGLCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
GLOWDEF PFNGLCOLOR3UIPROC glow_glColor3ui;
typedef void (APIENTRYP PFNGLNORMAL3DPROC)(GLdouble nx, GLdouble ny, GLdouble nz);
GLOWDEF PFNGLNORMAL3DPROC glow_glNormal3d;
typedef void (APIENTRYP PFNGLRASTERPOS3IPROC)(GLint x, GLint y, GLint z);
GLOWDEF PFNGLRASTERPOS3IPROC glow_glRasterPos3i;
typedef void (APIENTRYP PFNGLRASTERPOS4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLOWDEF PFNGLRASTERPOS4FPROC glow_glRasterPos4f;
typedef void (APIENTRYP PFNGLFOGFPROC)(GLenum pname, GLfloat param);
GLOWDEF PFNGLFOGFPROC glow_glFogf;
typedef void (APIENTRYP PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLOWDEF PFNGLROTATEFPROC glow_glRotatef;
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
GLOWDEF PFNGLDEPTHFUNCPROC glow_glDepthFunc;
typedef void (APIENTRYP PFNGLCOLOR4USVPROC)(const GLushort *v);
GLOWDEF PFNGLCOLOR4USVPROC glow_glColor4usv;
typedef void (APIENTRYP PFNGLTEXCOORD2FPROC)(GLfloat s, GLfloat t);
GLOWDEF PFNGLTEXCOORD2FPROC glow_glTexCoord2f;
typedef void (APIENTRYP PFNGLVERTEX2IVPROC)(const GLint *v);
GLOWDEF PFNGLVERTEX2IVPROC glow_glVertex2iv;
typedef void (APIENTRYP PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
GLOWDEF PFNGLTEXENVIPROC glow_glTexEnvi;
typedef void (APIENTRYP PFNGLGETPIXELMAPUIVPROC)(GLenum map, GLuint *values);
GLOWDEF PFNGLGETPIXELMAPUIVPROC glow_glGetPixelMapuiv;
typedef void (APIENTRYP PFNGLINDEXIPROC)(GLint c);
GLOWDEF PFNGLINDEXIPROC glow_glIndexi;
typedef void (APIENTRYP PFNGLINDEXSVPROC)(const GLshort *c);
GLOWDEF PFNGLINDEXSVPROC glow_glIndexsv;
typedef void (APIENTRYP PFNGLRECTIVPROC)(const GLint *v1, const GLint *v2);
GLOWDEF PFNGLRECTIVPROC glow_glRectiv;
typedef void (APIENTRYP PFNGLTEXCOORD4IVPROC)(const GLint *v);
GLOWDEF PFNGLTEXCOORD4IVPROC glow_glTexCoord4iv;
typedef void (APIENTRYP PFNGLMAPGRID1DPROC)(GLint un, GLdouble u1, GLdouble u2);
GLOWDEF PFNGLMAPGRID1DPROC glow_glMapGrid1d;
typedef void (APIENTRYP PFNGLPIXELMAPUSVPROC)(GLenum map, GLsizei mapsize, const GLushort *values);
GLOWDEF PFNGLPIXELMAPUSVPROC glow_glPixelMapusv;
typedef void (APIENTRYP PFNGLNORMAL3IVPROC)(const GLint *v);
GLOWDEF PFNGLNORMAL3IVPROC glow_glNormal3iv;
typedef void (APIENTRYP PFNGLRASTERPOS3FVPROC)(const GLfloat *v);
GLOWDEF PFNGLRASTERPOS3FVPROC glow_glRasterPos3fv;
typedef void (APIENTRYP PFNGLTEXCOORD3FVPROC)(const GLfloat *v);
GLOWDEF PFNGLTEXCOORD3FVPROC glow_glTexCoord3fv;
typedef void (APIENTRYP PFNGLTEXGENIPROC)(GLenum coord, GLenum pname, GLint param);
GLOWDEF PFNGLTEXGENIPROC glow_glTexGeni;
typedef void (APIENTRYP PFNGLCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
GLOWDEF PFNGLCOLOR3FPROC glow_glColor3f;
typedef void (APIENTRYP PFNGLRASTERPOS2FVPROC)(const GLfloat *v);
GLOWDEF PFNGLRASTERPOS2FVPROC glow_glRasterPos2fv;
typedef void (APIENTRYP PFNGLTEXCOORD1IPROC)(GLint s);
GLOWDEF PFNGLTEXCOORD1IPROC glow_glTexCoord1i;
typedef void (APIENTRYP PFNGLINDEXMASKPROC)(GLuint mask);
GLOWDEF PFNGLINDEXMASKPROC glow_glIndexMask;
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
GLOWDEF PFNGLHINTPROC glow_glHint;
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLOWDEF PFNGLGETTEXIMAGEPROC glow_glGetTexImage;
typedef void (APIENTRYP PFNGLTEXCOORD4DPROC)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLOWDEF PFNGLTEXCOORD4DPROC glow_glTexCoord4d;
typedef void (APIENTRYP PFNGLPOPMATRIXPROC)();
GLOWDEF PFNGLPOPMATRIXPROC glow_glPopMatrix;
typedef void (APIENTRYP PFNGLCLEARACCUMPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLOWDEF PFNGLCLEARACCUMPROC glow_glClearAccum;
typedef void (APIENTRYP PFNGLMAPGRID2FPROC)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
GLOWDEF PFNGLMAPGRID2FPROC glow_glMapGrid2f;
typedef void (APIENTRYP PFNGLPIXELZOOMPROC)(GLfloat xfactor, GLfloat yfactor);
GLOWDEF PFNGLPIXELZOOMPROC glow_glPixelZoom;
typedef void (APIENTRYP PFNGLFRUSTUMPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLOWDEF PFNGLFRUSTUMPROC glow_glFrustum;
typedef void (APIENTRYP PFNGLRASTERPOS4FVPROC)(const GLfloat *v);
GLOWDEF PFNGLRASTERPOS4FVPROC glow_glRasterPos4fv;
typedef void (APIENTRYP PFNGLVERTEX3DVPROC)(const GLdouble *v);
GLOWDEF PFNGLVERTEX3DVPROC glow_glVertex3dv;
typedef void (APIENTRYP PFNGLFOGIPROC)(GLenum pname, GLint param);
GLOWDEF PFNGLFOGIPROC glow_glFogi;
typedef void (APIENTRYP PFNGLLIGHTMODELIPROC)(GLenum pname, GLint param);
GLOWDEF PFNGLLIGHTMODELIPROC glow_glLightModeli;
typedef void (APIENTRYP PFNGLTEXCOORD1DVPROC)(const GLdouble *v);
GLOWDEF PFNGLTEXCOORD1DVPROC glow_glTexCoord1dv;
typedef void (APIENTRYP PFNGLVERTEX2FPROC)(GLfloat x, GLfloat y);
GLOWDEF PFNGLVERTEX2FPROC glow_glVertex2f;
typedef void (APIENTRYP PFNGLPIXELTRANSFERFPROC)(GLenum pname, GLfloat param);
GLOWDEF PFNGLPIXELTRANSFERFPROC glow_glPixelTransferf;
typedef void (APIENTRYP PFNGLGETMAPDVPROC)(GLenum target, GLenum query, GLdouble *v);
GLOWDEF PFNGLGETMAPDVPROC glow_glGetMapdv;
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
GLOWDEF PFNGLPOLYGONMODEPROC glow_glPolygonMode;
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
GLOWDEF PFNGLPIXELSTOREFPROC glow_glPixelStoref;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETTEXPARAMETERFVPROC glow_glGetTexParameterfv;
typedef void (APIENTRYP PFNGLCOLOR4FVPROC)(const GLfloat *v);
GLOWDEF PFNGLCOLOR4FVPROC glow_glColor4fv;
typedef void (APIENTRYP PFNGLEVALCOORD2FPROC)(GLfloat u, GLfloat v);
GLOWDEF PFNGLEVALCOORD2FPROC glow_glEvalCoord2f;
typedef void (APIENTRYP PFNGLNORMAL3DVPROC)(const GLdouble *v);
GLOWDEF PFNGLNORMAL3DVPROC glow_glNormal3dv;
typedef void (APIENTRYP PFNGLMATERIALIPROC)(GLenum face, GLenum pname, GLint param);
GLOWDEF PFNGLMATERIALIPROC glow_glMateriali;
typedef void (APIENTRYP PFNGLPUSHNAMEPROC)(GLuint name);
GLOWDEF PFNGLPUSHNAMEPROC glow_glPushName;
typedef void (APIENTRYP PFNGLACCUMPROC)(GLenum op, GLfloat value);
GLOWDEF PFNGLACCUMPROC glow_glAccum;
typedef void (APIENTRYP PFNGLRECTIPROC)(GLint x1, GLint y1, GLint x2, GLint y2);
GLOWDEF PFNGLRECTIPROC glow_glRecti;
typedef void (APIENTRYP PFNGLTEXCOORD2SVPROC)(const GLshort *v);
GLOWDEF PFNGLTEXCOORD2SVPROC glow_glTexCoord2sv;
typedef void (APIENTRYP PFNGLVERTEX2SVPROC)(const GLshort *v);
GLOWDEF PFNGLVERTEX2SVPROC glow_glVertex2sv;
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
GLOWDEF PFNGLDEPTHMASKPROC glow_glDepthMask;
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
GLOWDEF PFNGLPIXELSTOREIPROC glow_glPixelStorei;
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
GLOWDEF PFNGLISENABLEDPROC glow_glIsEnabled;
typedef void (APIENTRYP PFNGLCOLOR3UIVPROC)(const GLuint *v);
GLOWDEF PFNGLCOLOR3UIVPROC glow_glColor3uiv;
typedef void (APIENTRYP PFNGLFINISHPROC)();
GLOWDEF PFNGLFINISHPROC glow_glFinish;
typedef void (APIENTRYP PFNGLVERTEX2FVPROC)(const GLfloat *v);
GLOWDEF PFNGLVERTEX2FVPROC glow_glVertex2fv;
typedef void (APIENTRYP PFNGLVERTEX4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLOWDEF PFNGLVERTEX4DPROC glow_glVertex4d;
typedef void (APIENTRYP PFNGLCOLOR3FVPROC)(const GLfloat *v);
GLOWDEF PFNGLCOLOR3FVPROC glow_glColor3fv;
typedef void (APIENTRYP PFNGLPASSTHROUGHPROC)(GLfloat token);
GLOWDEF PFNGLPASSTHROUGHPROC glow_glPassThrough;
typedef void (APIENTRYP PFNGLMAPGRID1FPROC)(GLint un, GLfloat u1, GLfloat u2);
GLOWDEF PFNGLMAPGRID1FPROC glow_glMapGrid1f;
typedef void (APIENTRYP PFNGLEVALCOORD1DPROC)(GLdouble u);
GLOWDEF PFNGLEVALCOORD1DPROC glow_glEvalCoord1d;
typedef void (APIENTRYP PFNGLGETMATERIALIVPROC)(GLenum face, GLenum pname, GLint *params);
GLOWDEF PFNGLGETMATERIALIVPROC glow_glGetMaterialiv;
typedef void (APIENTRYP PFNGLINDEXFVPROC)(const GLfloat *c);
GLOWDEF PFNGLINDEXFVPROC glow_glIndexfv;
typedef void (APIENTRYP PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
GLOWDEF PFNGLNORMAL3FPROC glow_glNormal3f;
typedef void (APIENTRYP PFNGLNORMAL3FVPROC)(const GLfloat *v);
GLOWDEF PFNGLNORMAL3FVPROC glow_glNormal3fv;
typedef void (APIENTRYP PFNGLVERTEX4DVPROC)(const GLdouble *v);
GLOWDEF PFNGLVERTEX4DVPROC glow_glVertex4dv;
typedef void (APIENTRYP PFNGLMAPGRID2DPROC)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
GLOWDEF PFNGLMAPGRID2DPROC glow_glMapGrid2d;
typedef void (APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
GLOWDEF PFNGLPOINTSIZEPROC glow_glPointSize;
typedef void (APIENTRYP PFNGLEDGEFLAGPROC)(GLboolean flag);
GLOWDEF PFNGLEDGEFLAGPROC glow_glEdgeFlag;
typedef void (APIENTRYP PFNGLTEXCOORD4IPROC)(GLint s, GLint t, GLint r, GLint q);
GLOWDEF PFNGLTEXCOORD4IPROC glow_glTexCoord4i;
typedef void (APIENTRYP PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
GLOWDEF PFNGLMATERIALFPROC glow_glMaterialf;
typedef void (APIENTRYP PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETLIGHTFVPROC glow_glGetLightfv;
typedef void (APIENTRYP PFNGLCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
GLOWDEF PFNGLCOLOR3UBPROC glow_glColor3ub;
typedef void (APIENTRYP PFNGLENDPROC)();
GLOWDEF PFNGLENDPROC glow_glEnd;
typedef void (APIENTRYP PFNGLNORMAL3BPROC)(GLbyte nx, GLbyte ny, GLbyte nz);
GLOWDEF PFNGLNORMAL3BPROC glow_glNormal3b;
typedef void (APIENTRYP PFNGLRASTERPOS4IPROC)(GLint x, GLint y, GLint z, GLint w);
GLOWDEF PFNGLRASTERPOS4IPROC glow_glRasterPos4i;
typedef void (APIENTRYP PFNGLVERTEX2DVPROC)(const GLdouble *v);
GLOWDEF PFNGLVERTEX2DVPROC glow_glVertex2dv;
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLOWDEF PFNGLCLEARCOLORPROC glow_glClearColor;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
GLOWDEF PFNGLGETTEXPARAMETERIVPROC glow_glGetTexParameteriv;
typedef void (APIENTRYP PFNGLBEGINPROC)(GLenum mode);
GLOWDEF PFNGLBEGINPROC glow_glBegin;
typedef void (APIENTRYP PFNGLRECTSVPROC)(const GLshort *v1, const GLshort *v2);
GLOWDEF PFNGLRECTSVPROC glow_glRectsv;
typedef void (APIENTRYP PFNGLEVALCOORD1FVPROC)(const GLfloat *u);
GLOWDEF PFNGLEVALCOORD1FVPROC glow_glEvalCoord1fv;
typedef void (APIENTRYP PFNGLMULTMATRIXDPROC)(const GLdouble *m);
GLOWDEF PFNGLMULTMATRIXDPROC glow_glMultMatrixd;
typedef void (APIENTRYP PFNGLNORMAL3BVPROC)(const GLbyte *v);
GLOWDEF PFNGLNORMAL3BVPROC glow_glNormal3bv;
typedef void (APIENTRYP PFNGLVERTEX2IPROC)(GLint x, GLint y);
GLOWDEF PFNGLVERTEX2IPROC glow_glVertex2i;
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
GLOWDEF PFNGLSTENCILMASKPROC glow_glStencilMask;
typedef void (APIENTRYP PFNGLDELETELISTSPROC)(GLuint list, GLsizei range);
GLOWDEF PFNGLDELETELISTSPROC glow_glDeleteLists;
typedef void (APIENTRYP PFNGLCOLOR3IVPROC)(const GLint *v);
GLOWDEF PFNGLCOLOR3IVPROC glow_glColor3iv;
typedef void (APIENTRYP PFNGLCOLOR4USPROC)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
GLOWDEF PFNGLCOLOR4USPROC glow_glColor4us;
typedef void (APIENTRYP PFNGLSELECTBUFFERPROC)(GLsizei size, GLuint *buffer);
GLOWDEF PFNGLSELECTBUFFERPROC glow_glSelectBuffer;
typedef void (APIENTRYP PFNGLRASTERPOS2IVPROC)(const GLint *v);
GLOWDEF PFNGLRASTERPOS2IVPROC glow_glRasterPos2iv;
typedef void (APIENTRYP PFNGLRASTERPOS4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
GLOWDEF PFNGLRASTERPOS4SPROC glow_glRasterPos4s;
typedef void (APIENTRYP PFNGLVERTEX4FVPROC)(const GLfloat *v);
GLOWDEF PFNGLVERTEX4FVPROC glow_glVertex4fv;
typedef void (APIENTRYP PFNGLVERTEX4IVPROC)(const GLint *v);
GLOWDEF PFNGLVERTEX4IVPROC glow_glVertex4iv;
typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
GLOWDEF PFNGLCULLFACEPROC glow_glCullFace;
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat *data);
GLOWDEF PFNGLGETFLOATVPROC glow_glGetFloatv;
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble near, GLdouble far);
GLOWDEF PFNGLDEPTHRANGEPROC glow_glDepthRange;
typedef void (APIENTRYP PFNGLINDEXIVPROC)(const GLint *c);
GLOWDEF PFNGLINDEXIVPROC glow_glIndexiv;
typedef void (APIENTRYP PFNGLENDLISTPROC)();
GLOWDEF PFNGLENDLISTPROC glow_glEndList;
typedef void (APIENTRYP PFNGLRASTERPOS2SPROC)(GLshort x, GLshort y);
GLOWDEF PFNGLRASTERPOS2SPROC glow_glRasterPos2s;
typedef void (APIENTRYP PFNGLTEXCOORD3IVPROC)(const GLint *v);
GLOWDEF PFNGLTEXCOORD3IVPROC glow_glTexCoord3iv;
typedef void (APIENTRYP PFNGLEVALPOINT2PROC)(GLint i, GLint j);
GLOWDEF PFNGLEVALPOINT2PROC glow_glEvalPoint2;
typedef void (APIENTRYP PFNGLTEXGENFPROC)(GLenum coord, GLenum pname, GLfloat param);
GLOWDEF PFNGLTEXGENFPROC glow_glTexGenf;
typedef void (APIENTRYP PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat *params);
GLOWDEF PFNGLGETMATERIALFVPROC glow_glGetMaterialfv;
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble *data);
GLOWDEF PFNGLGETDOUBLEVPROC glow_glGetDoublev;
typedef void (APIENTRYP PFNGLNEWLISTPROC)(GLuint list, GLenum mode);
GLOWDEF PFNGLNEWLISTPROC glow_glNewList;
typedef void (APIENTRYP PFNGLRECTSPROC)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
GLOWDEF PFNGLRECTSPROC glow_glRects;
typedef void (APIENTRYP PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
GLOWDEF PFNGLLIGHTMODELFPROC glow_glLightModelf;
typedef void (APIENTRYP PFNGLLIGHTMODELIVPROC)(GLenum pname, const GLint *params);
GLOWDEF PFNGLLIGHTMODELIVPROC glow_glLightModeliv;
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
GLOWDEF PFNGLTEXPARAMETERFVPROC glow_glTexParameterfv;
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
GLOWDEF PFNGLENABLEPROC glow_glEnable;
typedef void (APIENTRYP PFNGLTEXCOORD1IVPROC)(const GLint *v);
GLOWDEF PFNGLTEXCOORD1IVPROC glow_glTexCoord1iv;
typedef void (APIENTRYP PFNGLVERTEX3SVPROC)(const GLshort *v);
GLOWDEF PFNGLVERTEX3SVPROC glow_glVertex3sv;
typedef void (APIENTRYP PFNGLRASTERPOS2DPROC)(GLdouble x, GLdouble y);
GLOWDEF PFNGLRASTERPOS2DPROC glow_glRasterPos2d;
typedef void (APIENTRYP PFNGLFOGIVPROC)(GLenum pname, const GLint *params);
GLOWDEF PFNGLFOGIVPROC glow_glFogiv;
typedef void (APIENTRYP PFNGLTEXGENDVPROC)(GLenum coord, GLenum pname, const GLdouble *params);
GLOWDEF PFNGLTEXGENDVPROC glow_glTexGendv;
typedef void (APIENTRYP PFNGLCOLORMATERIALPROC)(GLenum face, GLenum mode);
GLOWDEF PFNGLCOLORMATERIALPROC glow_glColorMaterial;
typedef void (APIENTRYP PFNGLEVALMESH2PROC)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
GLOWDEF PFNGLEVALMESH2PROC glow_glEvalMesh2;
typedef void (APIENTRYP PFNGLLOADIDENTITYPROC)();
GLOWDEF PFNGLLOADIDENTITYPROC glow_glLoadIdentity;
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
GLOWDEF PFNGLSTENCILOPPROC glow_glStencilOp;
typedef void (APIENTRYP PFNGLRECTDVPROC)(const GLdouble *v1, const GLdouble *v2);
GLOWDEF PFNGLRECTDVPROC glow_glRectdv;
typedef void (APIENTRYP PFNGLTEXCOORD3FPROC)(GLfloat s, GLfloat t, GLfloat r);
GLOWDEF PFNGLTEXCOORD3FPROC glow_glTexCoord3f;
typedef void (APIENTRYP PFNGLVERTEX3DPROC)(GLdouble x, GLdouble y, GLdouble z);
GLOWDEF PFNGLVERTEX3DPROC glow_glVertex3d;
typedef void (APIENTRYP PFNGLVERTEX4SVPROC)(const GLshort *v);
GLOWDEF PFNGLVERTEX4SVPROC glow_glVertex4sv;
typedef void (APIENTRYP PFNGLSCALEDPROC)(GLdouble x, GLdouble y, GLdouble z);
GLOWDEF PFNGLSCALEDPROC glow_glScaled;
typedef void (APIENTRYP PFNGLINDEXDPROC)(GLdouble c);
GLOWDEF PFNGLINDEXDPROC glow_glIndexd;
typedef void (APIENTRYP PFNGLRASTERPOS3SPROC)(GLshort x, GLshort y, GLshort z);
GLOWDEF PFNGLRASTERPOS3SPROC glow_glRasterPos3s;
typedef void (APIENTRYP PFNGLRECTDPROC)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
GLOWDEF PFNGLRECTDPROC glow_glRectd;
typedef void (APIENTRYP PFNGLTEXCOORD4FVPROC)(const GLfloat *v);
GLOWDEF PFNGLTEXCOORD4FVPROC glow_glTexCoord4fv;


#ifndef GLOW_DEBUG

#define glGetLightiv glow_glGetLightiv
#define glLineWidth glow_glLineWidth
#define glRasterPos3d glow_glRasterPos3d
#define glLightiv glow_glLightiv
#define glPixelMapfv glow_glPixelMapfv
#define glScalef glow_glScalef
#define glReadPixels glow_glReadPixels
#define glGetIntegerv glow_glGetIntegerv
#define glRasterPos3iv glow_glRasterPos3iv
#define glRasterPos4sv glow_glRasterPos4sv
#define glTexCoord4dv glow_glTexCoord4dv
#define glTexCoord4f glow_glTexCoord4f
#define glVertex3s glow_glVertex3s
#define glGetPolygonStipple glow_glGetPolygonStipple
#define glTexParameteri glow_glTexParameteri
#define glTexImage2D glow_glTexImage2D
#define glRasterPos2dv glow_glRasterPos2dv
#define glTexCoord3d glow_glTexCoord3d
#define glLogicOp glow_glLogicOp
#define glReadBuffer glow_glReadBuffer
#define glRasterPos2f glow_glRasterPos2f
#define glMaterialfv glow_glMaterialfv
#define glLoadMatrixd glow_glLoadMatrixd
#define glTranslatef glow_glTranslatef
#define glFlush glow_glFlush
#define glColor3bv glow_glColor3bv
#define glColor4uiv glow_glColor4uiv
#define glRasterPos4d glow_glRasterPos4d
#define glTexParameteriv glow_glTexParameteriv
#define glColor4sv glow_glColor4sv
#define glGetTexEnvfv glow_glGetTexEnvfv
#define glRectf glow_glRectf
#define glShadeModel glow_glShadeModel
#define glLoadMatrixf glow_glLoadMatrixf
#define glListBase glow_glListBase
#define glColor4ub glow_glColor4ub
#define glIndexf glow_glIndexf
#define glRasterPos3f glow_glRasterPos3f
#define glEvalPoint1 glow_glEvalPoint1
#define glGetPixelMapusv glow_glGetPixelMapusv
#define glGetTexGeniv glow_glGetTexGeniv
#define glBitmap glow_glBitmap
#define glNormal3i glow_glNormal3i
#define glRasterPos3sv glow_glRasterPos3sv
#define glMaterialiv glow_glMaterialiv
#define glGetString glow_glGetString
#define glLoadName glow_glLoadName
#define glClearIndex glow_glClearIndex
#define glClipPlane glow_glClipPlane
#define glGetMapiv glow_glGetMapiv
#define glMap2d glow_glMap2d
#define glEvalCoord2fv glow_glEvalCoord2fv
#define glGetTexEnviv glow_glGetTexEnviv
#define glDisable glow_glDisable
#define glColor4i glow_glColor4i
#define glTexCoord3i glow_glTexCoord3i
#define glPushMatrix glow_glPushMatrix
#define glTexImage1D glow_glTexImage1D
#define glTexCoord3s glow_glTexCoord3s
#define glEvalCoord1f glow_glEvalCoord1f
#define glGetTexLevelParameteriv glow_glGetTexLevelParameteriv
#define glColor4dv glow_glColor4dv
#define glColor4f glow_glColor4f
#define glEdgeFlagv glow_glEdgeFlagv
#define glClearStencil glow_glClearStencil
#define glTexEnvfv glow_glTexEnvfv
#define glColor3b glow_glColor3b
#define glColor4d glow_glColor4d
#define glTexCoord2fv glow_glTexCoord2fv
#define glTexEnviv glow_glTexEnviv
#define glGetClipPlane glow_glGetClipPlane
#define glColor4ui glow_glColor4ui
#define glTexCoord1fv glow_glTexCoord1fv
#define glVertex4i glow_glVertex4i
#define glLighti glow_glLighti
#define glGetTexGendv glow_glGetTexGendv
#define glColor3us glow_glColor3us
#define glRasterPos4dv glow_glRasterPos4dv
#define glRasterPos4iv glow_glRasterPos4iv
#define glTexEnvf glow_glTexEnvf
#define glColor3i glow_glColor3i
#define glPolygonStipple glow_glPolygonStipple
#define glPixelMapuiv glow_glPixelMapuiv
#define glMultMatrixf glow_glMultMatrixf
#define glIndexdv glow_glIndexdv
#define glTexCoord4s glow_glTexCoord4s
#define glVertex3f glow_glVertex3f
#define glMap1f glow_glMap1f
#define glEvalMesh1 glow_glEvalMesh1
#define glIsList glow_glIsList
#define glGetTexLevelParameterfv glow_glGetTexLevelParameterfv
#define glNormal3sv glow_glNormal3sv
#define glTexCoord3sv glow_glTexCoord3sv
#define glVertex3i glow_glVertex3i
#define glBlendFunc glow_glBlendFunc
#define glTexGend glow_glTexGend
#define glPixelTransferi glow_glPixelTransferi
#define glClear glow_glClear
#define glRectfv glow_glRectfv
#define glTexCoord1d glow_glTexCoord1d
#define glTexGeniv glow_glTexGeniv
#define glVertex4f glow_glVertex4f
#define glEvalCoord2dv glow_glEvalCoord2dv
#define glGetTexGenfv glow_glGetTexGenfv
#define glColor3usv glow_glColor3usv
#define glColor4s glow_glColor4s
#define glIndexs glow_glIndexs
#define glTexCoord1s glow_glTexCoord1s
#define glRasterPos2sv glow_glRasterPos2sv
#define glTexCoord4sv glow_glTexCoord4sv
#define glInitNames glow_glInitNames
#define glMatrixMode glow_glMatrixMode
#define glClearDepth glow_glClearDepth
#define glViewport glow_glViewport
#define glColor3dv glow_glColor3dv
#define glColor4bv glow_glColor4bv
#define glVertex3fv glow_glVertex3fv
#define glPopAttrib glow_glPopAttrib
#define glMap1d glow_glMap1d
#define glEvalCoord2d glow_glEvalCoord2d
#define glColor4b glow_glColor4b
#define glNormal3s glow_glNormal3s
#define glRasterPos2i glow_glRasterPos2i
#define glVertex4s glow_glVertex4s
#define glRasterPos3dv glow_glRasterPos3dv
#define glTexCoord2d glow_glTexCoord2d
#define glLightf glow_glLightf
#define glDrawPixels glow_glDrawPixels
#define glScissor glow_glScissor
#define glColorMask glow_glColorMask
#define glGetBooleanv glow_glGetBooleanv
#define glColor4iv glow_glColor4iv
#define glCopyPixels glow_glCopyPixels
#define glRotated glow_glRotated
#define glTranslated glow_glTranslated
#define glGenLists glow_glGenLists
#define glTexCoord1f glow_glTexCoord1f
#define glFogfv glow_glFogfv
#define glEvalCoord1dv glow_glEvalCoord1dv
#define glTexCoord2dv glow_glTexCoord2dv
#define glLightModelfv glow_glLightModelfv
#define glPopName glow_glPopName
#define glPushAttrib glow_glPushAttrib
#define glColor3ubv glow_glColor3ubv
#define glTexCoord2i glow_glTexCoord2i
#define glColor4ubv glow_glColor4ubv
#define glVertex2s glow_glVertex2s
#define glVertex3iv glow_glVertex3iv
#define glFeedbackBuffer glow_glFeedbackBuffer
#define glStencilFunc glow_glStencilFunc
#define glColor3d glow_glColor3d
#define glColor3s glow_glColor3s
#define glColor3sv glow_glColor3sv
#define glAlphaFunc glow_glAlphaFunc
#define glGetPixelMapfv glow_glGetPixelMapfv
#define glTexCoord2iv glow_glTexCoord2iv
#define glMap2f glow_glMap2f
#define glFrontFace glow_glFrontFace
#define glDrawBuffer glow_glDrawBuffer
#define glCallList glow_glCallList
#define glTexCoord1sv glow_glTexCoord1sv
#define glGetMapfv glow_glGetMapfv
#define glGetError glow_glGetError
#define glTexCoord2s glow_glTexCoord2s
#define glLightfv glow_glLightfv
#define glTexGenfv glow_glTexGenfv
#define glTexParameterf glow_glTexParameterf
#define glVertex2d glow_glVertex2d
#define glLineStipple glow_glLineStipple
#define glOrtho glow_glOrtho
#define glTexCoord3dv glow_glTexCoord3dv
#define glRenderMode glow_glRenderMode
#define glCallLists glow_glCallLists
#define glColor3ui glow_glColor3ui
#define glNormal3d glow_glNormal3d
#define glRasterPos3i glow_glRasterPos3i
#define glRasterPos4f glow_glRasterPos4f
#define glFogf glow_glFogf
#define glRotatef glow_glRotatef
#define glDepthFunc glow_glDepthFunc
#define glColor4usv glow_glColor4usv
#define glTexCoord2f glow_glTexCoord2f
#define glVertex2iv glow_glVertex2iv
#define glTexEnvi glow_glTexEnvi
#define glGetPixelMapuiv glow_glGetPixelMapuiv
#define glIndexi glow_glIndexi
#define glIndexsv glow_glIndexsv
#define glRectiv glow_glRectiv
#define glTexCoord4iv glow_glTexCoord4iv
#define glMapGrid1d glow_glMapGrid1d
#define glPixelMapusv glow_glPixelMapusv
#define glNormal3iv glow_glNormal3iv
#define glRasterPos3fv glow_glRasterPos3fv
#define glTexCoord3fv glow_glTexCoord3fv
#define glTexGeni glow_glTexGeni
#define glColor3f glow_glColor3f
#define glRasterPos2fv glow_glRasterPos2fv
#define glTexCoord1i glow_glTexCoord1i
#define glIndexMask glow_glIndexMask
#define glHint glow_glHint
#define glGetTexImage glow_glGetTexImage
#define glTexCoord4d glow_glTexCoord4d
#define glPopMatrix glow_glPopMatrix
#define glClearAccum glow_glClearAccum
#define glMapGrid2f glow_glMapGrid2f
#define glPixelZoom glow_glPixelZoom
#define glFrustum glow_glFrustum
#define glRasterPos4fv glow_glRasterPos4fv
#define glVertex3dv glow_glVertex3dv
#define glFogi glow_glFogi
#define glLightModeli glow_glLightModeli
#define glTexCoord1dv glow_glTexCoord1dv
#define glVertex2f glow_glVertex2f
#define glPixelTransferf glow_glPixelTransferf
#define glGetMapdv glow_glGetMapdv
#define glPolygonMode glow_glPolygonMode
#define glPixelStoref glow_glPixelStoref
#define glGetTexParameterfv glow_glGetTexParameterfv
#define glColor4fv glow_glColor4fv
#define glEvalCoord2f glow_glEvalCoord2f
#define glNormal3dv glow_glNormal3dv
#define glMateriali glow_glMateriali
#define glPushName glow_glPushName
#define glAccum glow_glAccum
#define glRecti glow_glRecti
#define glTexCoord2sv glow_glTexCoord2sv
#define glVertex2sv glow_glVertex2sv
#define glDepthMask glow_glDepthMask
#define glPixelStorei glow_glPixelStorei
#define glIsEnabled glow_glIsEnabled
#define glColor3uiv glow_glColor3uiv
#define glFinish glow_glFinish
#define glVertex2fv glow_glVertex2fv
#define glVertex4d glow_glVertex4d
#define glColor3fv glow_glColor3fv
#define glPassThrough glow_glPassThrough
#define glMapGrid1f glow_glMapGrid1f
#define glEvalCoord1d glow_glEvalCoord1d
#define glGetMaterialiv glow_glGetMaterialiv
#define glIndexfv glow_glIndexfv
#define glNormal3f glow_glNormal3f
#define glNormal3fv glow_glNormal3fv
#define glVertex4dv glow_glVertex4dv
#define glMapGrid2d glow_glMapGrid2d
#define glPointSize glow_glPointSize
#define glEdgeFlag glow_glEdgeFlag
#define glTexCoord4i glow_glTexCoord4i
#define glMaterialf glow_glMaterialf
#define glGetLightfv glow_glGetLightfv
#define glColor3ub glow_glColor3ub
#define glEnd glow_glEnd
#define glNormal3b glow_glNormal3b
#define glRasterPos4i glow_glRasterPos4i
#define glVertex2dv glow_glVertex2dv
#define glClearColor glow_glClearColor
#define glGetTexParameteriv glow_glGetTexParameteriv
#define glBegin glow_glBegin
#define glRectsv glow_glRectsv
#define glEvalCoord1fv glow_glEvalCoord1fv
#define glMultMatrixd glow_glMultMatrixd
#define glNormal3bv glow_glNormal3bv
#define glVertex2i glow_glVertex2i
#define glStencilMask glow_glStencilMask
#define glDeleteLists glow_glDeleteLists
#define glColor3iv glow_glColor3iv
#define glColor4us glow_glColor4us
#define glSelectBuffer glow_glSelectBuffer
#define glRasterPos2iv glow_glRasterPos2iv
#define glRasterPos4s glow_glRasterPos4s
#define glVertex4fv glow_glVertex4fv
#define glVertex4iv glow_glVertex4iv
#define glCullFace glow_glCullFace
#define glGetFloatv glow_glGetFloatv
#define glDepthRange glow_glDepthRange
#define glIndexiv glow_glIndexiv
#define glEndList glow_glEndList
#define glRasterPos2s glow_glRasterPos2s
#define glTexCoord3iv glow_glTexCoord3iv
#define glEvalPoint2 glow_glEvalPoint2
#define glTexGenf glow_glTexGenf
#define glGetMaterialfv glow_glGetMaterialfv
#define glGetDoublev glow_glGetDoublev
#define glNewList glow_glNewList
#define glRects glow_glRects
#define glLightModelf glow_glLightModelf
#define glLightModeliv glow_glLightModeliv
#define glTexParameterfv glow_glTexParameterfv
#define glEnable glow_glEnable
#define glTexCoord1iv glow_glTexCoord1iv
#define glVertex3sv glow_glVertex3sv
#define glRasterPos2d glow_glRasterPos2d
#define glFogiv glow_glFogiv
#define glTexGendv glow_glTexGendv
#define glColorMaterial glow_glColorMaterial
#define glEvalMesh2 glow_glEvalMesh2
#define glLoadIdentity glow_glLoadIdentity
#define glStencilOp glow_glStencilOp
#define glRectdv glow_glRectdv
#define glTexCoord3f glow_glTexCoord3f
#define glVertex3d glow_glVertex3d
#define glVertex4sv glow_glVertex4sv
#define glScaled glow_glScaled
#define glIndexd glow_glIndexd
#define glRasterPos3s glow_glRasterPos3s
#define glRectd glow_glRectd
#define glTexCoord4fv glow_glTexCoord4fv

#endif /* GLOW_DEBUG */


#ifdef GLOW_DEBUG

GLOWDEF PFNGLGETLIGHTIVPROC glow_debug_glGetLightiv;
#define glGetLightiv glow_debug_glGetLightiv
GLOWDEF PFNGLLINEWIDTHPROC glow_debug_glLineWidth;
#define glLineWidth glow_debug_glLineWidth
GLOWDEF PFNGLRASTERPOS3DPROC glow_debug_glRasterPos3d;
#define glRasterPos3d glow_debug_glRasterPos3d
GLOWDEF PFNGLLIGHTIVPROC glow_debug_glLightiv;
#define glLightiv glow_debug_glLightiv
GLOWDEF PFNGLPIXELMAPFVPROC glow_debug_glPixelMapfv;
#define glPixelMapfv glow_debug_glPixelMapfv
GLOWDEF PFNGLSCALEFPROC glow_debug_glScalef;
#define glScalef glow_debug_glScalef
GLOWDEF PFNGLREADPIXELSPROC glow_debug_glReadPixels;
#define glReadPixels glow_debug_glReadPixels
GLOWDEF PFNGLGETINTEGERVPROC glow_debug_glGetIntegerv;
#define glGetIntegerv glow_debug_glGetIntegerv
GLOWDEF PFNGLRASTERPOS3IVPROC glow_debug_glRasterPos3iv;
#define glRasterPos3iv glow_debug_glRasterPos3iv
GLOWDEF PFNGLRASTERPOS4SVPROC glow_debug_glRasterPos4sv;
#define glRasterPos4sv glow_debug_glRasterPos4sv
GLOWDEF PFNGLTEXCOORD4DVPROC glow_debug_glTexCoord4dv;
#define glTexCoord4dv glow_debug_glTexCoord4dv
GLOWDEF PFNGLTEXCOORD4FPROC glow_debug_glTexCoord4f;
#define glTexCoord4f glow_debug_glTexCoord4f
GLOWDEF PFNGLVERTEX3SPROC glow_debug_glVertex3s;
#define glVertex3s glow_debug_glVertex3s
GLOWDEF PFNGLGETPOLYGONSTIPPLEPROC glow_debug_glGetPolygonStipple;
#define glGetPolygonStipple glow_debug_glGetPolygonStipple
GLOWDEF PFNGLTEXPARAMETERIPROC glow_debug_glTexParameteri;
#define glTexParameteri glow_debug_glTexParameteri
GLOWDEF PFNGLTEXIMAGE2DPROC glow_debug_glTexImage2D;
#define glTexImage2D glow_debug_glTexImage2D
GLOWDEF PFNGLRASTERPOS2DVPROC glow_debug_glRasterPos2dv;
#define glRasterPos2dv glow_debug_glRasterPos2dv
GLOWDEF PFNGLTEXCOORD3DPROC glow_debug_glTexCoord3d;
#define glTexCoord3d glow_debug_glTexCoord3d
GLOWDEF PFNGLLOGICOPPROC glow_debug_glLogicOp;
#define glLogicOp glow_debug_glLogicOp
GLOWDEF PFNGLREADBUFFERPROC glow_debug_glReadBuffer;
#define glReadBuffer glow_debug_glReadBuffer
GLOWDEF PFNGLRASTERPOS2FPROC glow_debug_glRasterPos2f;
#define glRasterPos2f glow_debug_glRasterPos2f
GLOWDEF PFNGLMATERIALFVPROC glow_debug_glMaterialfv;
#define glMaterialfv glow_debug_glMaterialfv
GLOWDEF PFNGLLOADMATRIXDPROC glow_debug_glLoadMatrixd;
#define glLoadMatrixd glow_debug_glLoadMatrixd
GLOWDEF PFNGLTRANSLATEFPROC glow_debug_glTranslatef;
#define glTranslatef glow_debug_glTranslatef
GLOWDEF PFNGLFLUSHPROC glow_debug_glFlush;
#define glFlush glow_debug_glFlush
GLOWDEF PFNGLCOLOR3BVPROC glow_debug_glColor3bv;
#define glColor3bv glow_debug_glColor3bv
GLOWDEF PFNGLCOLOR4UIVPROC glow_debug_glColor4uiv;
#define glColor4uiv glow_debug_glColor4uiv
GLOWDEF PFNGLRASTERPOS4DPROC glow_debug_glRasterPos4d;
#define glRasterPos4d glow_debug_glRasterPos4d
GLOWDEF PFNGLTEXPARAMETERIVPROC glow_debug_glTexParameteriv;
#define glTexParameteriv glow_debug_glTexParameteriv
GLOWDEF PFNGLCOLOR4SVPROC glow_debug_glColor4sv;
#define glColor4sv glow_debug_glColor4sv
GLOWDEF PFNGLGETTEXENVFVPROC glow_debug_glGetTexEnvfv;
#define glGetTexEnvfv glow_debug_glGetTexEnvfv
GLOWDEF PFNGLRECTFPROC glow_debug_glRectf;
#define glRectf glow_debug_glRectf
GLOWDEF PFNGLSHADEMODELPROC glow_debug_glShadeModel;
#define glShadeModel glow_debug_glShadeModel
GLOWDEF PFNGLLOADMATRIXFPROC glow_debug_glLoadMatrixf;
#define glLoadMatrixf glow_debug_glLoadMatrixf
GLOWDEF PFNGLLISTBASEPROC glow_debug_glListBase;
#define glListBase glow_debug_glListBase
GLOWDEF PFNGLCOLOR4UBPROC glow_debug_glColor4ub;
#define glColor4ub glow_debug_glColor4ub
GLOWDEF PFNGLINDEXFPROC glow_debug_glIndexf;
#define glIndexf glow_debug_glIndexf
GLOWDEF PFNGLRASTERPOS3FPROC glow_debug_glRasterPos3f;
#define glRasterPos3f glow_debug_glRasterPos3f
GLOWDEF PFNGLEVALPOINT1PROC glow_debug_glEvalPoint1;
#define glEvalPoint1 glow_debug_glEvalPoint1
GLOWDEF PFNGLGETPIXELMAPUSVPROC glow_debug_glGetPixelMapusv;
#define glGetPixelMapusv glow_debug_glGetPixelMapusv
GLOWDEF PFNGLGETTEXGENIVPROC glow_debug_glGetTexGeniv;
#define glGetTexGeniv glow_debug_glGetTexGeniv
GLOWDEF PFNGLBITMAPPROC glow_debug_glBitmap;
#define glBitmap glow_debug_glBitmap
GLOWDEF PFNGLNORMAL3IPROC glow_debug_glNormal3i;
#define glNormal3i glow_debug_glNormal3i
GLOWDEF PFNGLRASTERPOS3SVPROC glow_debug_glRasterPos3sv;
#define glRasterPos3sv glow_debug_glRasterPos3sv
GLOWDEF PFNGLMATERIALIVPROC glow_debug_glMaterialiv;
#define glMaterialiv glow_debug_glMaterialiv
GLOWDEF PFNGLGETSTRINGPROC glow_debug_glGetString;
#define glGetString glow_debug_glGetString
GLOWDEF PFNGLLOADNAMEPROC glow_debug_glLoadName;
#define glLoadName glow_debug_glLoadName
GLOWDEF PFNGLCLEARINDEXPROC glow_debug_glClearIndex;
#define glClearIndex glow_debug_glClearIndex
GLOWDEF PFNGLCLIPPLANEPROC glow_debug_glClipPlane;
#define glClipPlane glow_debug_glClipPlane
GLOWDEF PFNGLGETMAPIVPROC glow_debug_glGetMapiv;
#define glGetMapiv glow_debug_glGetMapiv
GLOWDEF PFNGLMAP2DPROC glow_debug_glMap2d;
#define glMap2d glow_debug_glMap2d
GLOWDEF PFNGLEVALCOORD2FVPROC glow_debug_glEvalCoord2fv;
#define glEvalCoord2fv glow_debug_glEvalCoord2fv
GLOWDEF PFNGLGETTEXENVIVPROC glow_debug_glGetTexEnviv;
#define glGetTexEnviv glow_debug_glGetTexEnviv
GLOWDEF PFNGLDISABLEPROC glow_debug_glDisable;
#define glDisable glow_debug_glDisable
GLOWDEF PFNGLCOLOR4IPROC glow_debug_glColor4i;
#define glColor4i glow_debug_glColor4i
GLOWDEF PFNGLTEXCOORD3IPROC glow_debug_glTexCoord3i;
#define glTexCoord3i glow_debug_glTexCoord3i
GLOWDEF PFNGLPUSHMATRIXPROC glow_debug_glPushMatrix;
#define glPushMatrix glow_debug_glPushMatrix
GLOWDEF PFNGLTEXIMAGE1DPROC glow_debug_glTexImage1D;
#define glTexImage1D glow_debug_glTexImage1D
GLOWDEF PFNGLTEXCOORD3SPROC glow_debug_glTexCoord3s;
#define glTexCoord3s glow_debug_glTexCoord3s
GLOWDEF PFNGLEVALCOORD1FPROC glow_debug_glEvalCoord1f;
#define glEvalCoord1f glow_debug_glEvalCoord1f
GLOWDEF PFNGLGETTEXLEVELPARAMETERIVPROC glow_debug_glGetTexLevelParameteriv;
#define glGetTexLevelParameteriv glow_debug_glGetTexLevelParameteriv
GLOWDEF PFNGLCOLOR4DVPROC glow_debug_glColor4dv;
#define glColor4dv glow_debug_glColor4dv
GLOWDEF PFNGLCOLOR4FPROC glow_debug_glColor4f;
#define glColor4f glow_debug_glColor4f
GLOWDEF PFNGLEDGEFLAGVPROC glow_debug_glEdgeFlagv;
#define glEdgeFlagv glow_debug_glEdgeFlagv
GLOWDEF PFNGLCLEARSTENCILPROC glow_debug_glClearStencil;
#define glClearStencil glow_debug_glClearStencil
GLOWDEF PFNGLTEXENVFVPROC glow_debug_glTexEnvfv;
#define glTexEnvfv glow_debug_glTexEnvfv
GLOWDEF PFNGLCOLOR3BPROC glow_debug_glColor3b;
#define glColor3b glow_debug_glColor3b
GLOWDEF PFNGLCOLOR4DPROC glow_debug_glColor4d;
#define glColor4d glow_debug_glColor4d
GLOWDEF PFNGLTEXCOORD2FVPROC glow_debug_glTexCoord2fv;
#define glTexCoord2fv glow_debug_glTexCoord2fv
GLOWDEF PFNGLTEXENVIVPROC glow_debug_glTexEnviv;
#define glTexEnviv glow_debug_glTexEnviv
GLOWDEF PFNGLGETCLIPPLANEPROC glow_debug_glGetClipPlane;
#define glGetClipPlane glow_debug_glGetClipPlane
GLOWDEF PFNGLCOLOR4UIPROC glow_debug_glColor4ui;
#define glColor4ui glow_debug_glColor4ui
GLOWDEF PFNGLTEXCOORD1FVPROC glow_debug_glTexCoord1fv;
#define glTexCoord1fv glow_debug_glTexCoord1fv
GLOWDEF PFNGLVERTEX4IPROC glow_debug_glVertex4i;
#define glVertex4i glow_debug_glVertex4i
GLOWDEF PFNGLLIGHTIPROC glow_debug_glLighti;
#define glLighti glow_debug_glLighti
GLOWDEF PFNGLGETTEXGENDVPROC glow_debug_glGetTexGendv;
#define glGetTexGendv glow_debug_glGetTexGendv
GLOWDEF PFNGLCOLOR3USPROC glow_debug_glColor3us;
#define glColor3us glow_debug_glColor3us
GLOWDEF PFNGLRASTERPOS4DVPROC glow_debug_glRasterPos4dv;
#define glRasterPos4dv glow_debug_glRasterPos4dv
GLOWDEF PFNGLRASTERPOS4IVPROC glow_debug_glRasterPos4iv;
#define glRasterPos4iv glow_debug_glRasterPos4iv
GLOWDEF PFNGLTEXENVFPROC glow_debug_glTexEnvf;
#define glTexEnvf glow_debug_glTexEnvf
GLOWDEF PFNGLCOLOR3IPROC glow_debug_glColor3i;
#define glColor3i glow_debug_glColor3i
GLOWDEF PFNGLPOLYGONSTIPPLEPROC glow_debug_glPolygonStipple;
#define glPolygonStipple glow_debug_glPolygonStipple
GLOWDEF PFNGLPIXELMAPUIVPROC glow_debug_glPixelMapuiv;
#define glPixelMapuiv glow_debug_glPixelMapuiv
GLOWDEF PFNGLMULTMATRIXFPROC glow_debug_glMultMatrixf;
#define glMultMatrixf glow_debug_glMultMatrixf
GLOWDEF PFNGLINDEXDVPROC glow_debug_glIndexdv;
#define glIndexdv glow_debug_glIndexdv
GLOWDEF PFNGLTEXCOORD4SPROC glow_debug_glTexCoord4s;
#define glTexCoord4s glow_debug_glTexCoord4s
GLOWDEF PFNGLVERTEX3FPROC glow_debug_glVertex3f;
#define glVertex3f glow_debug_glVertex3f
GLOWDEF PFNGLMAP1FPROC glow_debug_glMap1f;
#define glMap1f glow_debug_glMap1f
GLOWDEF PFNGLEVALMESH1PROC glow_debug_glEvalMesh1;
#define glEvalMesh1 glow_debug_glEvalMesh1
GLOWDEF PFNGLISLISTPROC glow_debug_glIsList;
#define glIsList glow_debug_glIsList
GLOWDEF PFNGLGETTEXLEVELPARAMETERFVPROC glow_debug_glGetTexLevelParameterfv;
#define glGetTexLevelParameterfv glow_debug_glGetTexLevelParameterfv
GLOWDEF PFNGLNORMAL3SVPROC glow_debug_glNormal3sv;
#define glNormal3sv glow_debug_glNormal3sv
GLOWDEF PFNGLTEXCOORD3SVPROC glow_debug_glTexCoord3sv;
#define glTexCoord3sv glow_debug_glTexCoord3sv
GLOWDEF PFNGLVERTEX3IPROC glow_debug_glVertex3i;
#define glVertex3i glow_debug_glVertex3i
GLOWDEF PFNGLBLENDFUNCPROC glow_debug_glBlendFunc;
#define glBlendFunc glow_debug_glBlendFunc
GLOWDEF PFNGLTEXGENDPROC glow_debug_glTexGend;
#define glTexGend glow_debug_glTexGend
GLOWDEF PFNGLPIXELTRANSFERIPROC glow_debug_glPixelTransferi;
#define glPixelTransferi glow_debug_glPixelTransferi
GLOWDEF PFNGLCLEARPROC glow_debug_glClear;
#define glClear glow_debug_glClear
GLOWDEF PFNGLRECTFVPROC glow_debug_glRectfv;
#define glRectfv glow_debug_glRectfv
GLOWDEF PFNGLTEXCOORD1DPROC glow_debug_glTexCoord1d;
#define glTexCoord1d glow_debug_glTexCoord1d
GLOWDEF PFNGLTEXGENIVPROC glow_debug_glTexGeniv;
#define glTexGeniv glow_debug_glTexGeniv
GLOWDEF PFNGLVERTEX4FPROC glow_debug_glVertex4f;
#define glVertex4f glow_debug_glVertex4f
GLOWDEF PFNGLEVALCOORD2DVPROC glow_debug_glEvalCoord2dv;
#define glEvalCoord2dv glow_debug_glEvalCoord2dv
GLOWDEF PFNGLGETTEXGENFVPROC glow_debug_glGetTexGenfv;
#define glGetTexGenfv glow_debug_glGetTexGenfv
GLOWDEF PFNGLCOLOR3USVPROC glow_debug_glColor3usv;
#define glColor3usv glow_debug_glColor3usv
GLOWDEF PFNGLCOLOR4SPROC glow_debug_glColor4s;
#define glColor4s glow_debug_glColor4s
GLOWDEF PFNGLINDEXSPROC glow_debug_glIndexs;
#define glIndexs glow_debug_glIndexs
GLOWDEF PFNGLTEXCOORD1SPROC glow_debug_glTexCoord1s;
#define glTexCoord1s glow_debug_glTexCoord1s
GLOWDEF PFNGLRASTERPOS2SVPROC glow_debug_glRasterPos2sv;
#define glRasterPos2sv glow_debug_glRasterPos2sv
GLOWDEF PFNGLTEXCOORD4SVPROC glow_debug_glTexCoord4sv;
#define glTexCoord4sv glow_debug_glTexCoord4sv
GLOWDEF PFNGLINITNAMESPROC glow_debug_glInitNames;
#define glInitNames glow_debug_glInitNames
GLOWDEF PFNGLMATRIXMODEPROC glow_debug_glMatrixMode;
#define glMatrixMode glow_debug_glMatrixMode
GLOWDEF PFNGLCLEARDEPTHPROC glow_debug_glClearDepth;
#define glClearDepth glow_debug_glClearDepth
GLOWDEF PFNGLVIEWPORTPROC glow_debug_glViewport;
#define glViewport glow_debug_glViewport
GLOWDEF PFNGLCOLOR3DVPROC glow_debug_glColor3dv;
#define glColor3dv glow_debug_glColor3dv
GLOWDEF PFNGLCOLOR4BVPROC glow_debug_glColor4bv;
#define glColor4bv glow_debug_glColor4bv
GLOWDEF PFNGLVERTEX3FVPROC glow_debug_glVertex3fv;
#define glVertex3fv glow_debug_glVertex3fv
GLOWDEF PFNGLPOPATTRIBPROC glow_debug_glPopAttrib;
#define glPopAttrib glow_debug_glPopAttrib
GLOWDEF PFNGLMAP1DPROC glow_debug_glMap1d;
#define glMap1d glow_debug_glMap1d
GLOWDEF PFNGLEVALCOORD2DPROC glow_debug_glEvalCoord2d;
#define glEvalCoord2d glow_debug_glEvalCoord2d
GLOWDEF PFNGLCOLOR4BPROC glow_debug_glColor4b;
#define glColor4b glow_debug_glColor4b
GLOWDEF PFNGLNORMAL3SPROC glow_debug_glNormal3s;
#define glNormal3s glow_debug_glNormal3s
GLOWDEF PFNGLRASTERPOS2IPROC glow_debug_glRasterPos2i;
#define glRasterPos2i glow_debug_glRasterPos2i
GLOWDEF PFNGLVERTEX4SPROC glow_debug_glVertex4s;
#define glVertex4s glow_debug_glVertex4s
GLOWDEF PFNGLRASTERPOS3DVPROC glow_debug_glRasterPos3dv;
#define glRasterPos3dv glow_debug_glRasterPos3dv
GLOWDEF PFNGLTEXCOORD2DPROC glow_debug_glTexCoord2d;
#define glTexCoord2d glow_debug_glTexCoord2d
GLOWDEF PFNGLLIGHTFPROC glow_debug_glLightf;
#define glLightf glow_debug_glLightf
GLOWDEF PFNGLDRAWPIXELSPROC glow_debug_glDrawPixels;
#define glDrawPixels glow_debug_glDrawPixels
GLOWDEF PFNGLSCISSORPROC glow_debug_glScissor;
#define glScissor glow_debug_glScissor
GLOWDEF PFNGLCOLORMASKPROC glow_debug_glColorMask;
#define glColorMask glow_debug_glColorMask
GLOWDEF PFNGLGETBOOLEANVPROC glow_debug_glGetBooleanv;
#define glGetBooleanv glow_debug_glGetBooleanv
GLOWDEF PFNGLCOLOR4IVPROC glow_debug_glColor4iv;
#define glColor4iv glow_debug_glColor4iv
GLOWDEF PFNGLCOPYPIXELSPROC glow_debug_glCopyPixels;
#define glCopyPixels glow_debug_glCopyPixels
GLOWDEF PFNGLROTATEDPROC glow_debug_glRotated;
#define glRotated glow_debug_glRotated
GLOWDEF PFNGLTRANSLATEDPROC glow_debug_glTranslated;
#define glTranslated glow_debug_glTranslated
GLOWDEF PFNGLGENLISTSPROC glow_debug_glGenLists;
#define glGenLists glow_debug_glGenLists
GLOWDEF PFNGLTEXCOORD1FPROC glow_debug_glTexCoord1f;
#define glTexCoord1f glow_debug_glTexCoord1f
GLOWDEF PFNGLFOGFVPROC glow_debug_glFogfv;
#define glFogfv glow_debug_glFogfv
GLOWDEF PFNGLEVALCOORD1DVPROC glow_debug_glEvalCoord1dv;
#define glEvalCoord1dv glow_debug_glEvalCoord1dv
GLOWDEF PFNGLTEXCOORD2DVPROC glow_debug_glTexCoord2dv;
#define glTexCoord2dv glow_debug_glTexCoord2dv
GLOWDEF PFNGLLIGHTMODELFVPROC glow_debug_glLightModelfv;
#define glLightModelfv glow_debug_glLightModelfv
GLOWDEF PFNGLPOPNAMEPROC glow_debug_glPopName;
#define glPopName glow_debug_glPopName
GLOWDEF PFNGLPUSHATTRIBPROC glow_debug_glPushAttrib;
#define glPushAttrib glow_debug_glPushAttrib
GLOWDEF PFNGLCOLOR3UBVPROC glow_debug_glColor3ubv;
#define glColor3ubv glow_debug_glColor3ubv
GLOWDEF PFNGLTEXCOORD2IPROC glow_debug_glTexCoord2i;
#define glTexCoord2i glow_debug_glTexCoord2i
GLOWDEF PFNGLCOLOR4UBVPROC glow_debug_glColor4ubv;
#define glColor4ubv glow_debug_glColor4ubv
GLOWDEF PFNGLVERTEX2SPROC glow_debug_glVertex2s;
#define glVertex2s glow_debug_glVertex2s
GLOWDEF PFNGLVERTEX3IVPROC glow_debug_glVertex3iv;
#define glVertex3iv glow_debug_glVertex3iv
GLOWDEF PFNGLFEEDBACKBUFFERPROC glow_debug_glFeedbackBuffer;
#define glFeedbackBuffer glow_debug_glFeedbackBuffer
GLOWDEF PFNGLSTENCILFUNCPROC glow_debug_glStencilFunc;
#define glStencilFunc glow_debug_glStencilFunc
GLOWDEF PFNGLCOLOR3DPROC glow_debug_glColor3d;
#define glColor3d glow_debug_glColor3d
GLOWDEF PFNGLCOLOR3SPROC glow_debug_glColor3s;
#define glColor3s glow_debug_glColor3s
GLOWDEF PFNGLCOLOR3SVPROC glow_debug_glColor3sv;
#define glColor3sv glow_debug_glColor3sv
GLOWDEF PFNGLALPHAFUNCPROC glow_debug_glAlphaFunc;
#define glAlphaFunc glow_debug_glAlphaFunc
GLOWDEF PFNGLGETPIXELMAPFVPROC glow_debug_glGetPixelMapfv;
#define glGetPixelMapfv glow_debug_glGetPixelMapfv
GLOWDEF PFNGLTEXCOORD2IVPROC glow_debug_glTexCoord2iv;
#define glTexCoord2iv glow_debug_glTexCoord2iv
GLOWDEF PFNGLMAP2FPROC glow_debug_glMap2f;
#define glMap2f glow_debug_glMap2f
GLOWDEF PFNGLFRONTFACEPROC glow_debug_glFrontFace;
#define glFrontFace glow_debug_glFrontFace
GLOWDEF PFNGLDRAWBUFFERPROC glow_debug_glDrawBuffer;
#define glDrawBuffer glow_debug_glDrawBuffer
GLOWDEF PFNGLCALLLISTPROC glow_debug_glCallList;
#define glCallList glow_debug_glCallList
GLOWDEF PFNGLTEXCOORD1SVPROC glow_debug_glTexCoord1sv;
#define glTexCoord1sv glow_debug_glTexCoord1sv
GLOWDEF PFNGLGETMAPFVPROC glow_debug_glGetMapfv;
#define glGetMapfv glow_debug_glGetMapfv
GLOWDEF PFNGLGETERRORPROC glow_debug_glGetError;
#define glGetError glow_debug_glGetError
GLOWDEF PFNGLTEXCOORD2SPROC glow_debug_glTexCoord2s;
#define glTexCoord2s glow_debug_glTexCoord2s
GLOWDEF PFNGLLIGHTFVPROC glow_debug_glLightfv;
#define glLightfv glow_debug_glLightfv
GLOWDEF PFNGLTEXGENFVPROC glow_debug_glTexGenfv;
#define glTexGenfv glow_debug_glTexGenfv
GLOWDEF PFNGLTEXPARAMETERFPROC glow_debug_glTexParameterf;
#define glTexParameterf glow_debug_glTexParameterf
GLOWDEF PFNGLVERTEX2DPROC glow_debug_glVertex2d;
#define glVertex2d glow_debug_glVertex2d
GLOWDEF PFNGLLINESTIPPLEPROC glow_debug_glLineStipple;
#define glLineStipple glow_debug_glLineStipple
GLOWDEF PFNGLORTHOPROC glow_debug_glOrtho;
#define glOrtho glow_debug_glOrtho
GLOWDEF PFNGLTEXCOORD3DVPROC glow_debug_glTexCoord3dv;
#define glTexCoord3dv glow_debug_glTexCoord3dv
GLOWDEF PFNGLRENDERMODEPROC glow_debug_glRenderMode;
#define glRenderMode glow_debug_glRenderMode
GLOWDEF PFNGLCALLLISTSPROC glow_debug_glCallLists;
#define glCallLists glow_debug_glCallLists
GLOWDEF PFNGLCOLOR3UIPROC glow_debug_glColor3ui;
#define glColor3ui glow_debug_glColor3ui
GLOWDEF PFNGLNORMAL3DPROC glow_debug_glNormal3d;
#define glNormal3d glow_debug_glNormal3d
GLOWDEF PFNGLRASTERPOS3IPROC glow_debug_glRasterPos3i;
#define glRasterPos3i glow_debug_glRasterPos3i
GLOWDEF PFNGLRASTERPOS4FPROC glow_debug_glRasterPos4f;
#define glRasterPos4f glow_debug_glRasterPos4f
GLOWDEF PFNGLFOGFPROC glow_debug_glFogf;
#define glFogf glow_debug_glFogf
GLOWDEF PFNGLROTATEFPROC glow_debug_glRotatef;
#define glRotatef glow_debug_glRotatef
GLOWDEF PFNGLDEPTHFUNCPROC glow_debug_glDepthFunc;
#define glDepthFunc glow_debug_glDepthFunc
GLOWDEF PFNGLCOLOR4USVPROC glow_debug_glColor4usv;
#define glColor4usv glow_debug_glColor4usv
GLOWDEF PFNGLTEXCOORD2FPROC glow_debug_glTexCoord2f;
#define glTexCoord2f glow_debug_glTexCoord2f
GLOWDEF PFNGLVERTEX2IVPROC glow_debug_glVertex2iv;
#define glVertex2iv glow_debug_glVertex2iv
GLOWDEF PFNGLTEXENVIPROC glow_debug_glTexEnvi;
#define glTexEnvi glow_debug_glTexEnvi
GLOWDEF PFNGLGETPIXELMAPUIVPROC glow_debug_glGetPixelMapuiv;
#define glGetPixelMapuiv glow_debug_glGetPixelMapuiv
GLOWDEF PFNGLINDEXIPROC glow_debug_glIndexi;
#define glIndexi glow_debug_glIndexi
GLOWDEF PFNGLINDEXSVPROC glow_debug_glIndexsv;
#define glIndexsv glow_debug_glIndexsv
GLOWDEF PFNGLRECTIVPROC glow_debug_glRectiv;
#define glRectiv glow_debug_glRectiv
GLOWDEF PFNGLTEXCOORD4IVPROC glow_debug_glTexCoord4iv;
#define glTexCoord4iv glow_debug_glTexCoord4iv
GLOWDEF PFNGLMAPGRID1DPROC glow_debug_glMapGrid1d;
#define glMapGrid1d glow_debug_glMapGrid1d
GLOWDEF PFNGLPIXELMAPUSVPROC glow_debug_glPixelMapusv;
#define glPixelMapusv glow_debug_glPixelMapusv
GLOWDEF PFNGLNORMAL3IVPROC glow_debug_glNormal3iv;
#define glNormal3iv glow_debug_glNormal3iv
GLOWDEF PFNGLRASTERPOS3FVPROC glow_debug_glRasterPos3fv;
#define glRasterPos3fv glow_debug_glRasterPos3fv
GLOWDEF PFNGLTEXCOORD3FVPROC glow_debug_glTexCoord3fv;
#define glTexCoord3fv glow_debug_glTexCoord3fv
GLOWDEF PFNGLTEXGENIPROC glow_debug_glTexGeni;
#define glTexGeni glow_debug_glTexGeni
GLOWDEF PFNGLCOLOR3FPROC glow_debug_glColor3f;
#define glColor3f glow_debug_glColor3f
GLOWDEF PFNGLRASTERPOS2FVPROC glow_debug_glRasterPos2fv;
#define glRasterPos2fv glow_debug_glRasterPos2fv
GLOWDEF PFNGLTEXCOORD1IPROC glow_debug_glTexCoord1i;
#define glTexCoord1i glow_debug_glTexCoord1i
GLOWDEF PFNGLINDEXMASKPROC glow_debug_glIndexMask;
#define glIndexMask glow_debug_glIndexMask
GLOWDEF PFNGLHINTPROC glow_debug_glHint;
#define glHint glow_debug_glHint
GLOWDEF PFNGLGETTEXIMAGEPROC glow_debug_glGetTexImage;
#define glGetTexImage glow_debug_glGetTexImage
GLOWDEF PFNGLTEXCOORD4DPROC glow_debug_glTexCoord4d;
#define glTexCoord4d glow_debug_glTexCoord4d
GLOWDEF PFNGLPOPMATRIXPROC glow_debug_glPopMatrix;
#define glPopMatrix glow_debug_glPopMatrix
GLOWDEF PFNGLCLEARACCUMPROC glow_debug_glClearAccum;
#define glClearAccum glow_debug_glClearAccum
GLOWDEF PFNGLMAPGRID2FPROC glow_debug_glMapGrid2f;
#define glMapGrid2f glow_debug_glMapGrid2f
GLOWDEF PFNGLPIXELZOOMPROC glow_debug_glPixelZoom;
#define glPixelZoom glow_debug_glPixelZoom
GLOWDEF PFNGLFRUSTUMPROC glow_debug_glFrustum;
#define glFrustum glow_debug_glFrustum
GLOWDEF PFNGLRASTERPOS4FVPROC glow_debug_glRasterPos4fv;
#define glRasterPos4fv glow_debug_glRasterPos4fv
GLOWDEF PFNGLVERTEX3DVPROC glow_debug_glVertex3dv;
#define glVertex3dv glow_debug_glVertex3dv
GLOWDEF PFNGLFOGIPROC glow_debug_glFogi;
#define glFogi glow_debug_glFogi
GLOWDEF PFNGLLIGHTMODELIPROC glow_debug_glLightModeli;
#define glLightModeli glow_debug_glLightModeli
GLOWDEF PFNGLTEXCOORD1DVPROC glow_debug_glTexCoord1dv;
#define glTexCoord1dv glow_debug_glTexCoord1dv
GLOWDEF PFNGLVERTEX2FPROC glow_debug_glVertex2f;
#define glVertex2f glow_debug_glVertex2f
GLOWDEF PFNGLPIXELTRANSFERFPROC glow_debug_glPixelTransferf;
#define glPixelTransferf glow_debug_glPixelTransferf
GLOWDEF PFNGLGETMAPDVPROC glow_debug_glGetMapdv;
#define glGetMapdv glow_debug_glGetMapdv
GLOWDEF PFNGLPOLYGONMODEPROC glow_debug_glPolygonMode;
#define glPolygonMode glow_debug_glPolygonMode
GLOWDEF PFNGLPIXELSTOREFPROC glow_debug_glPixelStoref;
#define glPixelStoref glow_debug_glPixelStoref
GLOWDEF PFNGLGETTEXPARAMETERFVPROC glow_debug_glGetTexParameterfv;
#define glGetTexParameterfv glow_debug_glGetTexParameterfv
GLOWDEF PFNGLCOLOR4FVPROC glow_debug_glColor4fv;
#define glColor4fv glow_debug_glColor4fv
GLOWDEF PFNGLEVALCOORD2FPROC glow_debug_glEvalCoord2f;
#define glEvalCoord2f glow_debug_glEvalCoord2f
GLOWDEF PFNGLNORMAL3DVPROC glow_debug_glNormal3dv;
#define glNormal3dv glow_debug_glNormal3dv
GLOWDEF PFNGLMATERIALIPROC glow_debug_glMateriali;
#define glMateriali glow_debug_glMateriali
GLOWDEF PFNGLPUSHNAMEPROC glow_debug_glPushName;
#define glPushName glow_debug_glPushName
GLOWDEF PFNGLACCUMPROC glow_debug_glAccum;
#define glAccum glow_debug_glAccum
GLOWDEF PFNGLRECTIPROC glow_debug_glRecti;
#define glRecti glow_debug_glRecti
GLOWDEF PFNGLTEXCOORD2SVPROC glow_debug_glTexCoord2sv;
#define glTexCoord2sv glow_debug_glTexCoord2sv
GLOWDEF PFNGLVERTEX2SVPROC glow_debug_glVertex2sv;
#define glVertex2sv glow_debug_glVertex2sv
GLOWDEF PFNGLDEPTHMASKPROC glow_debug_glDepthMask;
#define glDepthMask glow_debug_glDepthMask
GLOWDEF PFNGLPIXELSTOREIPROC glow_debug_glPixelStorei;
#define glPixelStorei glow_debug_glPixelStorei
GLOWDEF PFNGLISENABLEDPROC glow_debug_glIsEnabled;
#define glIsEnabled glow_debug_glIsEnabled
GLOWDEF PFNGLCOLOR3UIVPROC glow_debug_glColor3uiv;
#define glColor3uiv glow_debug_glColor3uiv
GLOWDEF PFNGLFINISHPROC glow_debug_glFinish;
#define glFinish glow_debug_glFinish
GLOWDEF PFNGLVERTEX2FVPROC glow_debug_glVertex2fv;
#define glVertex2fv glow_debug_glVertex2fv
GLOWDEF PFNGLVERTEX4DPROC glow_debug_glVertex4d;
#define glVertex4d glow_debug_glVertex4d
GLOWDEF PFNGLCOLOR3FVPROC glow_debug_glColor3fv;
#define glColor3fv glow_debug_glColor3fv
GLOWDEF PFNGLPASSTHROUGHPROC glow_debug_glPassThrough;
#define glPassThrough glow_debug_glPassThrough
GLOWDEF PFNGLMAPGRID1FPROC glow_debug_glMapGrid1f;
#define glMapGrid1f glow_debug_glMapGrid1f
GLOWDEF PFNGLEVALCOORD1DPROC glow_debug_glEvalCoord1d;
#define glEvalCoord1d glow_debug_glEvalCoord1d
GLOWDEF PFNGLGETMATERIALIVPROC glow_debug_glGetMaterialiv;
#define glGetMaterialiv glow_debug_glGetMaterialiv
GLOWDEF PFNGLINDEXFVPROC glow_debug_glIndexfv;
#define glIndexfv glow_debug_glIndexfv
GLOWDEF PFNGLNORMAL3FPROC glow_debug_glNormal3f;
#define glNormal3f glow_debug_glNormal3f
GLOWDEF PFNGLNORMAL3FVPROC glow_debug_glNormal3fv;
#define glNormal3fv glow_debug_glNormal3fv
GLOWDEF PFNGLVERTEX4DVPROC glow_debug_glVertex4dv;
#define glVertex4dv glow_debug_glVertex4dv
GLOWDEF PFNGLMAPGRID2DPROC glow_debug_glMapGrid2d;
#define glMapGrid2d glow_debug_glMapGrid2d
GLOWDEF PFNGLPOINTSIZEPROC glow_debug_glPointSize;
#define glPointSize glow_debug_glPointSize
GLOWDEF PFNGLEDGEFLAGPROC glow_debug_glEdgeFlag;
#define glEdgeFlag glow_debug_glEdgeFlag
GLOWDEF PFNGLTEXCOORD4IPROC glow_debug_glTexCoord4i;
#define glTexCoord4i glow_debug_glTexCoord4i
GLOWDEF PFNGLMATERIALFPROC glow_debug_glMaterialf;
#define glMaterialf glow_debug_glMaterialf
GLOWDEF PFNGLGETLIGHTFVPROC glow_debug_glGetLightfv;
#define glGetLightfv glow_debug_glGetLightfv
GLOWDEF PFNGLCOLOR3UBPROC glow_debug_glColor3ub;
#define glColor3ub glow_debug_glColor3ub
GLOWDEF PFNGLENDPROC glow_debug_glEnd;
#define glEnd glow_debug_glEnd
GLOWDEF PFNGLNORMAL3BPROC glow_debug_glNormal3b;
#define glNormal3b glow_debug_glNormal3b
GLOWDEF PFNGLRASTERPOS4IPROC glow_debug_glRasterPos4i;
#define glRasterPos4i glow_debug_glRasterPos4i
GLOWDEF PFNGLVERTEX2DVPROC glow_debug_glVertex2dv;
#define glVertex2dv glow_debug_glVertex2dv
GLOWDEF PFNGLCLEARCOLORPROC glow_debug_glClearColor;
#define glClearColor glow_debug_glClearColor
GLOWDEF PFNGLGETTEXPARAMETERIVPROC glow_debug_glGetTexParameteriv;
#define glGetTexParameteriv glow_debug_glGetTexParameteriv
GLOWDEF PFNGLBEGINPROC glow_debug_glBegin;
#define glBegin glow_debug_glBegin
GLOWDEF PFNGLRECTSVPROC glow_debug_glRectsv;
#define glRectsv glow_debug_glRectsv
GLOWDEF PFNGLEVALCOORD1FVPROC glow_debug_glEvalCoord1fv;
#define glEvalCoord1fv glow_debug_glEvalCoord1fv
GLOWDEF PFNGLMULTMATRIXDPROC glow_debug_glMultMatrixd;
#define glMultMatrixd glow_debug_glMultMatrixd
GLOWDEF PFNGLNORMAL3BVPROC glow_debug_glNormal3bv;
#define glNormal3bv glow_debug_glNormal3bv
GLOWDEF PFNGLVERTEX2IPROC glow_debug_glVertex2i;
#define glVertex2i glow_debug_glVertex2i
GLOWDEF PFNGLSTENCILMASKPROC glow_debug_glStencilMask;
#define glStencilMask glow_debug_glStencilMask
GLOWDEF PFNGLDELETELISTSPROC glow_debug_glDeleteLists;
#define glDeleteLists glow_debug_glDeleteLists
GLOWDEF PFNGLCOLOR3IVPROC glow_debug_glColor3iv;
#define glColor3iv glow_debug_glColor3iv
GLOWDEF PFNGLCOLOR4USPROC glow_debug_glColor4us;
#define glColor4us glow_debug_glColor4us
GLOWDEF PFNGLSELECTBUFFERPROC glow_debug_glSelectBuffer;
#define glSelectBuffer glow_debug_glSelectBuffer
GLOWDEF PFNGLRASTERPOS2IVPROC glow_debug_glRasterPos2iv;
#define glRasterPos2iv glow_debug_glRasterPos2iv
GLOWDEF PFNGLRASTERPOS4SPROC glow_debug_glRasterPos4s;
#define glRasterPos4s glow_debug_glRasterPos4s
GLOWDEF PFNGLVERTEX4FVPROC glow_debug_glVertex4fv;
#define glVertex4fv glow_debug_glVertex4fv
GLOWDEF PFNGLVERTEX4IVPROC glow_debug_glVertex4iv;
#define glVertex4iv glow_debug_glVertex4iv
GLOWDEF PFNGLCULLFACEPROC glow_debug_glCullFace;
#define glCullFace glow_debug_glCullFace
GLOWDEF PFNGLGETFLOATVPROC glow_debug_glGetFloatv;
#define glGetFloatv glow_debug_glGetFloatv
GLOWDEF PFNGLDEPTHRANGEPROC glow_debug_glDepthRange;
#define glDepthRange glow_debug_glDepthRange
GLOWDEF PFNGLINDEXIVPROC glow_debug_glIndexiv;
#define glIndexiv glow_debug_glIndexiv
GLOWDEF PFNGLENDLISTPROC glow_debug_glEndList;
#define glEndList glow_debug_glEndList
GLOWDEF PFNGLRASTERPOS2SPROC glow_debug_glRasterPos2s;
#define glRasterPos2s glow_debug_glRasterPos2s
GLOWDEF PFNGLTEXCOORD3IVPROC glow_debug_glTexCoord3iv;
#define glTexCoord3iv glow_debug_glTexCoord3iv
GLOWDEF PFNGLEVALPOINT2PROC glow_debug_glEvalPoint2;
#define glEvalPoint2 glow_debug_glEvalPoint2
GLOWDEF PFNGLTEXGENFPROC glow_debug_glTexGenf;
#define glTexGenf glow_debug_glTexGenf
GLOWDEF PFNGLGETMATERIALFVPROC glow_debug_glGetMaterialfv;
#define glGetMaterialfv glow_debug_glGetMaterialfv
GLOWDEF PFNGLGETDOUBLEVPROC glow_debug_glGetDoublev;
#define glGetDoublev glow_debug_glGetDoublev
GLOWDEF PFNGLNEWLISTPROC glow_debug_glNewList;
#define glNewList glow_debug_glNewList
GLOWDEF PFNGLRECTSPROC glow_debug_glRects;
#define glRects glow_debug_glRects
GLOWDEF PFNGLLIGHTMODELFPROC glow_debug_glLightModelf;
#define glLightModelf glow_debug_glLightModelf
GLOWDEF PFNGLLIGHTMODELIVPROC glow_debug_glLightModeliv;
#define glLightModeliv glow_debug_glLightModeliv
GLOWDEF PFNGLTEXPARAMETERFVPROC glow_debug_glTexParameterfv;
#define glTexParameterfv glow_debug_glTexParameterfv
GLOWDEF PFNGLENABLEPROC glow_debug_glEnable;
#define glEnable glow_debug_glEnable
GLOWDEF PFNGLTEXCOORD1IVPROC glow_debug_glTexCoord1iv;
#define glTexCoord1iv glow_debug_glTexCoord1iv
GLOWDEF PFNGLVERTEX3SVPROC glow_debug_glVertex3sv;
#define glVertex3sv glow_debug_glVertex3sv
GLOWDEF PFNGLRASTERPOS2DPROC glow_debug_glRasterPos2d;
#define glRasterPos2d glow_debug_glRasterPos2d
GLOWDEF PFNGLFOGIVPROC glow_debug_glFogiv;
#define glFogiv glow_debug_glFogiv
GLOWDEF PFNGLTEXGENDVPROC glow_debug_glTexGendv;
#define glTexGendv glow_debug_glTexGendv
GLOWDEF PFNGLCOLORMATERIALPROC glow_debug_glColorMaterial;
#define glColorMaterial glow_debug_glColorMaterial
GLOWDEF PFNGLEVALMESH2PROC glow_debug_glEvalMesh2;
#define glEvalMesh2 glow_debug_glEvalMesh2
GLOWDEF PFNGLLOADIDENTITYPROC glow_debug_glLoadIdentity;
#define glLoadIdentity glow_debug_glLoadIdentity
GLOWDEF PFNGLSTENCILOPPROC glow_debug_glStencilOp;
#define glStencilOp glow_debug_glStencilOp
GLOWDEF PFNGLRECTDVPROC glow_debug_glRectdv;
#define glRectdv glow_debug_glRectdv
GLOWDEF PFNGLTEXCOORD3FPROC glow_debug_glTexCoord3f;
#define glTexCoord3f glow_debug_glTexCoord3f
GLOWDEF PFNGLVERTEX3DPROC glow_debug_glVertex3d;
#define glVertex3d glow_debug_glVertex3d
GLOWDEF PFNGLVERTEX4SVPROC glow_debug_glVertex4sv;
#define glVertex4sv glow_debug_glVertex4sv
GLOWDEF PFNGLSCALEDPROC glow_debug_glScaled;
#define glScaled glow_debug_glScaled
GLOWDEF PFNGLINDEXDPROC glow_debug_glIndexd;
#define glIndexd glow_debug_glIndexd
GLOWDEF PFNGLRASTERPOS3SPROC glow_debug_glRasterPos3s;
#define glRasterPos3s glow_debug_glRasterPos3s
GLOWDEF PFNGLRECTDPROC glow_debug_glRectd;
#define glRectd glow_debug_glRectd
GLOWDEF PFNGLTEXCOORD4FVPROC glow_debug_glTexCoord4fv;
#define glTexCoord4fv glow_debug_glTexCoord4fv
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


static void glow_lazy_glGetLightiv(GLenum light, GLenum pname, GLint *params) {
  glow_glGetLightiv = (PFNGLGETLIGHTIVPROC)((ptrdiff_t)(glow_get_proc("glGetLightiv")));
  if (glow_glGetLightiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetLightiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetLightiv\n");
#endif
  }
  glow_glGetLightiv(light, pname, params);
}
PFNGLGETLIGHTIVPROC glow_glGetLightiv = glow_lazy_glGetLightiv;
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
static void glow_lazy_glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
  glow_glRasterPos3d = (PFNGLRASTERPOS3DPROC)((ptrdiff_t)(glow_get_proc("glRasterPos3d")));
  if (glow_glRasterPos3d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3d\n");
#endif
  }
  glow_glRasterPos3d(x, y, z);
}
PFNGLRASTERPOS3DPROC glow_glRasterPos3d = glow_lazy_glRasterPos3d;
static void glow_lazy_glLightiv(GLenum light, GLenum pname, const GLint *params) {
  glow_glLightiv = (PFNGLLIGHTIVPROC)((ptrdiff_t)(glow_get_proc("glLightiv")));
  if (glow_glLightiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightiv\n");
#endif
  }
  glow_glLightiv(light, pname, params);
}
PFNGLLIGHTIVPROC glow_glLightiv = glow_lazy_glLightiv;
static void glow_lazy_glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values) {
  glow_glPixelMapfv = (PFNGLPIXELMAPFVPROC)((ptrdiff_t)(glow_get_proc("glPixelMapfv")));
  if (glow_glPixelMapfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelMapfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelMapfv\n");
#endif
  }
  glow_glPixelMapfv(map, mapsize, values);
}
PFNGLPIXELMAPFVPROC glow_glPixelMapfv = glow_lazy_glPixelMapfv;
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
static void glow_lazy_glRasterPos3iv(const GLint *v) {
  glow_glRasterPos3iv = (PFNGLRASTERPOS3IVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos3iv")));
  if (glow_glRasterPos3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3iv\n");
#endif
  }
  glow_glRasterPos3iv(v);
}
PFNGLRASTERPOS3IVPROC glow_glRasterPos3iv = glow_lazy_glRasterPos3iv;
static void glow_lazy_glRasterPos4sv(const GLshort *v) {
  glow_glRasterPos4sv = (PFNGLRASTERPOS4SVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos4sv")));
  if (glow_glRasterPos4sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4sv\n");
#endif
  }
  glow_glRasterPos4sv(v);
}
PFNGLRASTERPOS4SVPROC glow_glRasterPos4sv = glow_lazy_glRasterPos4sv;
static void glow_lazy_glTexCoord4dv(const GLdouble *v) {
  glow_glTexCoord4dv = (PFNGLTEXCOORD4DVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord4dv")));
  if (glow_glTexCoord4dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4dv\n");
#endif
  }
  glow_glTexCoord4dv(v);
}
PFNGLTEXCOORD4DVPROC glow_glTexCoord4dv = glow_lazy_glTexCoord4dv;
static void glow_lazy_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
  glow_glTexCoord4f = (PFNGLTEXCOORD4FPROC)((ptrdiff_t)(glow_get_proc("glTexCoord4f")));
  if (glow_glTexCoord4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4f\n");
#endif
  }
  glow_glTexCoord4f(s, t, r, q);
}
PFNGLTEXCOORD4FPROC glow_glTexCoord4f = glow_lazy_glTexCoord4f;
static void glow_lazy_glVertex3s(GLshort x, GLshort y, GLshort z) {
  glow_glVertex3s = (PFNGLVERTEX3SPROC)((ptrdiff_t)(glow_get_proc("glVertex3s")));
  if (glow_glVertex3s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3s\n");
#endif
  }
  glow_glVertex3s(x, y, z);
}
PFNGLVERTEX3SPROC glow_glVertex3s = glow_lazy_glVertex3s;
static void glow_lazy_glGetPolygonStipple(GLubyte *mask) {
  glow_glGetPolygonStipple = (PFNGLGETPOLYGONSTIPPLEPROC)((ptrdiff_t)(glow_get_proc("glGetPolygonStipple")));
  if (glow_glGetPolygonStipple == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetPolygonStipple\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetPolygonStipple\n");
#endif
  }
  glow_glGetPolygonStipple(mask);
}
PFNGLGETPOLYGONSTIPPLEPROC glow_glGetPolygonStipple = glow_lazy_glGetPolygonStipple;
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
static void glow_lazy_glRasterPos2dv(const GLdouble *v) {
  glow_glRasterPos2dv = (PFNGLRASTERPOS2DVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos2dv")));
  if (glow_glRasterPos2dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2dv\n");
#endif
  }
  glow_glRasterPos2dv(v);
}
PFNGLRASTERPOS2DVPROC glow_glRasterPos2dv = glow_lazy_glRasterPos2dv;
static void glow_lazy_glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
  glow_glTexCoord3d = (PFNGLTEXCOORD3DPROC)((ptrdiff_t)(glow_get_proc("glTexCoord3d")));
  if (glow_glTexCoord3d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3d\n");
#endif
  }
  glow_glTexCoord3d(s, t, r);
}
PFNGLTEXCOORD3DPROC glow_glTexCoord3d = glow_lazy_glTexCoord3d;
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
static void glow_lazy_glRasterPos2f(GLfloat x, GLfloat y) {
  glow_glRasterPos2f = (PFNGLRASTERPOS2FPROC)((ptrdiff_t)(glow_get_proc("glRasterPos2f")));
  if (glow_glRasterPos2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2f\n");
#endif
  }
  glow_glRasterPos2f(x, y);
}
PFNGLRASTERPOS2FPROC glow_glRasterPos2f = glow_lazy_glRasterPos2f;
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
static void glow_lazy_glLoadMatrixd(const GLdouble *m) {
  glow_glLoadMatrixd = (PFNGLLOADMATRIXDPROC)((ptrdiff_t)(glow_get_proc("glLoadMatrixd")));
  if (glow_glLoadMatrixd == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadMatrixd\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadMatrixd\n");
#endif
  }
  glow_glLoadMatrixd(m);
}
PFNGLLOADMATRIXDPROC glow_glLoadMatrixd = glow_lazy_glLoadMatrixd;
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
static void glow_lazy_glColor3bv(const GLbyte *v) {
  glow_glColor3bv = (PFNGLCOLOR3BVPROC)((ptrdiff_t)(glow_get_proc("glColor3bv")));
  if (glow_glColor3bv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3bv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3bv\n");
#endif
  }
  glow_glColor3bv(v);
}
PFNGLCOLOR3BVPROC glow_glColor3bv = glow_lazy_glColor3bv;
static void glow_lazy_glColor4uiv(const GLuint *v) {
  glow_glColor4uiv = (PFNGLCOLOR4UIVPROC)((ptrdiff_t)(glow_get_proc("glColor4uiv")));
  if (glow_glColor4uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4uiv\n");
#endif
  }
  glow_glColor4uiv(v);
}
PFNGLCOLOR4UIVPROC glow_glColor4uiv = glow_lazy_glColor4uiv;
static void glow_lazy_glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
  glow_glRasterPos4d = (PFNGLRASTERPOS4DPROC)((ptrdiff_t)(glow_get_proc("glRasterPos4d")));
  if (glow_glRasterPos4d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4d\n");
#endif
  }
  glow_glRasterPos4d(x, y, z, w);
}
PFNGLRASTERPOS4DPROC glow_glRasterPos4d = glow_lazy_glRasterPos4d;
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
static void glow_lazy_glColor4sv(const GLshort *v) {
  glow_glColor4sv = (PFNGLCOLOR4SVPROC)((ptrdiff_t)(glow_get_proc("glColor4sv")));
  if (glow_glColor4sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4sv\n");
#endif
  }
  glow_glColor4sv(v);
}
PFNGLCOLOR4SVPROC glow_glColor4sv = glow_lazy_glColor4sv;
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
static void glow_lazy_glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
  glow_glRectf = (PFNGLRECTFPROC)((ptrdiff_t)(glow_get_proc("glRectf")));
  if (glow_glRectf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectf\n");
#endif
  }
  glow_glRectf(x1, y1, x2, y2);
}
PFNGLRECTFPROC glow_glRectf = glow_lazy_glRectf;
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
static void glow_lazy_glListBase(GLuint base) {
  glow_glListBase = (PFNGLLISTBASEPROC)((ptrdiff_t)(glow_get_proc("glListBase")));
  if (glow_glListBase == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glListBase\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glListBase\n");
#endif
  }
  glow_glListBase(base);
}
PFNGLLISTBASEPROC glow_glListBase = glow_lazy_glListBase;
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
static void glow_lazy_glIndexf(GLfloat c) {
  glow_glIndexf = (PFNGLINDEXFPROC)((ptrdiff_t)(glow_get_proc("glIndexf")));
  if (glow_glIndexf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexf\n");
#endif
  }
  glow_glIndexf(c);
}
PFNGLINDEXFPROC glow_glIndexf = glow_lazy_glIndexf;
static void glow_lazy_glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
  glow_glRasterPos3f = (PFNGLRASTERPOS3FPROC)((ptrdiff_t)(glow_get_proc("glRasterPos3f")));
  if (glow_glRasterPos3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3f\n");
#endif
  }
  glow_glRasterPos3f(x, y, z);
}
PFNGLRASTERPOS3FPROC glow_glRasterPos3f = glow_lazy_glRasterPos3f;
static void glow_lazy_glEvalPoint1(GLint i) {
  glow_glEvalPoint1 = (PFNGLEVALPOINT1PROC)((ptrdiff_t)(glow_get_proc("glEvalPoint1")));
  if (glow_glEvalPoint1 == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalPoint1\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalPoint1\n");
#endif
  }
  glow_glEvalPoint1(i);
}
PFNGLEVALPOINT1PROC glow_glEvalPoint1 = glow_lazy_glEvalPoint1;
static void glow_lazy_glGetPixelMapusv(GLenum map, GLushort *values) {
  glow_glGetPixelMapusv = (PFNGLGETPIXELMAPUSVPROC)((ptrdiff_t)(glow_get_proc("glGetPixelMapusv")));
  if (glow_glGetPixelMapusv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetPixelMapusv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetPixelMapusv\n");
#endif
  }
  glow_glGetPixelMapusv(map, values);
}
PFNGLGETPIXELMAPUSVPROC glow_glGetPixelMapusv = glow_lazy_glGetPixelMapusv;
static void glow_lazy_glGetTexGeniv(GLenum coord, GLenum pname, GLint *params) {
  glow_glGetTexGeniv = (PFNGLGETTEXGENIVPROC)((ptrdiff_t)(glow_get_proc("glGetTexGeniv")));
  if (glow_glGetTexGeniv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexGeniv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexGeniv\n");
#endif
  }
  glow_glGetTexGeniv(coord, pname, params);
}
PFNGLGETTEXGENIVPROC glow_glGetTexGeniv = glow_lazy_glGetTexGeniv;
static void glow_lazy_glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) {
  glow_glBitmap = (PFNGLBITMAPPROC)((ptrdiff_t)(glow_get_proc("glBitmap")));
  if (glow_glBitmap == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBitmap\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBitmap\n");
#endif
  }
  glow_glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
}
PFNGLBITMAPPROC glow_glBitmap = glow_lazy_glBitmap;
static void glow_lazy_glNormal3i(GLint nx, GLint ny, GLint nz) {
  glow_glNormal3i = (PFNGLNORMAL3IPROC)((ptrdiff_t)(glow_get_proc("glNormal3i")));
  if (glow_glNormal3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3i\n");
#endif
  }
  glow_glNormal3i(nx, ny, nz);
}
PFNGLNORMAL3IPROC glow_glNormal3i = glow_lazy_glNormal3i;
static void glow_lazy_glRasterPos3sv(const GLshort *v) {
  glow_glRasterPos3sv = (PFNGLRASTERPOS3SVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos3sv")));
  if (glow_glRasterPos3sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3sv\n");
#endif
  }
  glow_glRasterPos3sv(v);
}
PFNGLRASTERPOS3SVPROC glow_glRasterPos3sv = glow_lazy_glRasterPos3sv;
static void glow_lazy_glMaterialiv(GLenum face, GLenum pname, const GLint *params) {
  glow_glMaterialiv = (PFNGLMATERIALIVPROC)((ptrdiff_t)(glow_get_proc("glMaterialiv")));
  if (glow_glMaterialiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMaterialiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMaterialiv\n");
#endif
  }
  glow_glMaterialiv(face, pname, params);
}
PFNGLMATERIALIVPROC glow_glMaterialiv = glow_lazy_glMaterialiv;
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
static void glow_lazy_glLoadName(GLuint name) {
  glow_glLoadName = (PFNGLLOADNAMEPROC)((ptrdiff_t)(glow_get_proc("glLoadName")));
  if (glow_glLoadName == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadName\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadName\n");
#endif
  }
  glow_glLoadName(name);
}
PFNGLLOADNAMEPROC glow_glLoadName = glow_lazy_glLoadName;
static void glow_lazy_glClearIndex(GLfloat c) {
  glow_glClearIndex = (PFNGLCLEARINDEXPROC)((ptrdiff_t)(glow_get_proc("glClearIndex")));
  if (glow_glClearIndex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearIndex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearIndex\n");
#endif
  }
  glow_glClearIndex(c);
}
PFNGLCLEARINDEXPROC glow_glClearIndex = glow_lazy_glClearIndex;
static void glow_lazy_glClipPlane(GLenum plane, const GLdouble *equation) {
  glow_glClipPlane = (PFNGLCLIPPLANEPROC)((ptrdiff_t)(glow_get_proc("glClipPlane")));
  if (glow_glClipPlane == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClipPlane\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClipPlane\n");
#endif
  }
  glow_glClipPlane(plane, equation);
}
PFNGLCLIPPLANEPROC glow_glClipPlane = glow_lazy_glClipPlane;
static void glow_lazy_glGetMapiv(GLenum target, GLenum query, GLint *v) {
  glow_glGetMapiv = (PFNGLGETMAPIVPROC)((ptrdiff_t)(glow_get_proc("glGetMapiv")));
  if (glow_glGetMapiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMapiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMapiv\n");
#endif
  }
  glow_glGetMapiv(target, query, v);
}
PFNGLGETMAPIVPROC glow_glGetMapiv = glow_lazy_glGetMapiv;
static void glow_lazy_glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points) {
  glow_glMap2d = (PFNGLMAP2DPROC)((ptrdiff_t)(glow_get_proc("glMap2d")));
  if (glow_glMap2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMap2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMap2d\n");
#endif
  }
  glow_glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
PFNGLMAP2DPROC glow_glMap2d = glow_lazy_glMap2d;
static void glow_lazy_glEvalCoord2fv(const GLfloat *u) {
  glow_glEvalCoord2fv = (PFNGLEVALCOORD2FVPROC)((ptrdiff_t)(glow_get_proc("glEvalCoord2fv")));
  if (glow_glEvalCoord2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord2fv\n");
#endif
  }
  glow_glEvalCoord2fv(u);
}
PFNGLEVALCOORD2FVPROC glow_glEvalCoord2fv = glow_lazy_glEvalCoord2fv;
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
static void glow_lazy_glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
  glow_glColor4i = (PFNGLCOLOR4IPROC)((ptrdiff_t)(glow_get_proc("glColor4i")));
  if (glow_glColor4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4i\n");
#endif
  }
  glow_glColor4i(red, green, blue, alpha);
}
PFNGLCOLOR4IPROC glow_glColor4i = glow_lazy_glColor4i;
static void glow_lazy_glTexCoord3i(GLint s, GLint t, GLint r) {
  glow_glTexCoord3i = (PFNGLTEXCOORD3IPROC)((ptrdiff_t)(glow_get_proc("glTexCoord3i")));
  if (glow_glTexCoord3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3i\n");
#endif
  }
  glow_glTexCoord3i(s, t, r);
}
PFNGLTEXCOORD3IPROC glow_glTexCoord3i = glow_lazy_glTexCoord3i;
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
static void glow_lazy_glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) {
  glow_glTexImage1D = (PFNGLTEXIMAGE1DPROC)((ptrdiff_t)(glow_get_proc("glTexImage1D")));
  if (glow_glTexImage1D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexImage1D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexImage1D\n");
#endif
  }
  glow_glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
}
PFNGLTEXIMAGE1DPROC glow_glTexImage1D = glow_lazy_glTexImage1D;
static void glow_lazy_glTexCoord3s(GLshort s, GLshort t, GLshort r) {
  glow_glTexCoord3s = (PFNGLTEXCOORD3SPROC)((ptrdiff_t)(glow_get_proc("glTexCoord3s")));
  if (glow_glTexCoord3s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3s\n");
#endif
  }
  glow_glTexCoord3s(s, t, r);
}
PFNGLTEXCOORD3SPROC glow_glTexCoord3s = glow_lazy_glTexCoord3s;
static void glow_lazy_glEvalCoord1f(GLfloat u) {
  glow_glEvalCoord1f = (PFNGLEVALCOORD1FPROC)((ptrdiff_t)(glow_get_proc("glEvalCoord1f")));
  if (glow_glEvalCoord1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord1f\n");
#endif
  }
  glow_glEvalCoord1f(u);
}
PFNGLEVALCOORD1FPROC glow_glEvalCoord1f = glow_lazy_glEvalCoord1f;
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
static void glow_lazy_glColor4dv(const GLdouble *v) {
  glow_glColor4dv = (PFNGLCOLOR4DVPROC)((ptrdiff_t)(glow_get_proc("glColor4dv")));
  if (glow_glColor4dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4dv\n");
#endif
  }
  glow_glColor4dv(v);
}
PFNGLCOLOR4DVPROC glow_glColor4dv = glow_lazy_glColor4dv;
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
static void glow_lazy_glEdgeFlagv(const GLboolean *flag) {
  glow_glEdgeFlagv = (PFNGLEDGEFLAGVPROC)((ptrdiff_t)(glow_get_proc("glEdgeFlagv")));
  if (glow_glEdgeFlagv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEdgeFlagv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEdgeFlagv\n");
#endif
  }
  glow_glEdgeFlagv(flag);
}
PFNGLEDGEFLAGVPROC glow_glEdgeFlagv = glow_lazy_glEdgeFlagv;
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
static void glow_lazy_glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
  glow_glColor3b = (PFNGLCOLOR3BPROC)((ptrdiff_t)(glow_get_proc("glColor3b")));
  if (glow_glColor3b == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3b\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3b\n");
#endif
  }
  glow_glColor3b(red, green, blue);
}
PFNGLCOLOR3BPROC glow_glColor3b = glow_lazy_glColor3b;
static void glow_lazy_glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
  glow_glColor4d = (PFNGLCOLOR4DPROC)((ptrdiff_t)(glow_get_proc("glColor4d")));
  if (glow_glColor4d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4d\n");
#endif
  }
  glow_glColor4d(red, green, blue, alpha);
}
PFNGLCOLOR4DPROC glow_glColor4d = glow_lazy_glColor4d;
static void glow_lazy_glTexCoord2fv(const GLfloat *v) {
  glow_glTexCoord2fv = (PFNGLTEXCOORD2FVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord2fv")));
  if (glow_glTexCoord2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2fv\n");
#endif
  }
  glow_glTexCoord2fv(v);
}
PFNGLTEXCOORD2FVPROC glow_glTexCoord2fv = glow_lazy_glTexCoord2fv;
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
static void glow_lazy_glGetClipPlane(GLenum plane, GLdouble *equation) {
  glow_glGetClipPlane = (PFNGLGETCLIPPLANEPROC)((ptrdiff_t)(glow_get_proc("glGetClipPlane")));
  if (glow_glGetClipPlane == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetClipPlane\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetClipPlane\n");
#endif
  }
  glow_glGetClipPlane(plane, equation);
}
PFNGLGETCLIPPLANEPROC glow_glGetClipPlane = glow_lazy_glGetClipPlane;
static void glow_lazy_glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
  glow_glColor4ui = (PFNGLCOLOR4UIPROC)((ptrdiff_t)(glow_get_proc("glColor4ui")));
  if (glow_glColor4ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4ui\n");
#endif
  }
  glow_glColor4ui(red, green, blue, alpha);
}
PFNGLCOLOR4UIPROC glow_glColor4ui = glow_lazy_glColor4ui;
static void glow_lazy_glTexCoord1fv(const GLfloat *v) {
  glow_glTexCoord1fv = (PFNGLTEXCOORD1FVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord1fv")));
  if (glow_glTexCoord1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1fv\n");
#endif
  }
  glow_glTexCoord1fv(v);
}
PFNGLTEXCOORD1FVPROC glow_glTexCoord1fv = glow_lazy_glTexCoord1fv;
static void glow_lazy_glVertex4i(GLint x, GLint y, GLint z, GLint w) {
  glow_glVertex4i = (PFNGLVERTEX4IPROC)((ptrdiff_t)(glow_get_proc("glVertex4i")));
  if (glow_glVertex4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4i\n");
#endif
  }
  glow_glVertex4i(x, y, z, w);
}
PFNGLVERTEX4IPROC glow_glVertex4i = glow_lazy_glVertex4i;
static void glow_lazy_glLighti(GLenum light, GLenum pname, GLint param) {
  glow_glLighti = (PFNGLLIGHTIPROC)((ptrdiff_t)(glow_get_proc("glLighti")));
  if (glow_glLighti == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLighti\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLighti\n");
#endif
  }
  glow_glLighti(light, pname, param);
}
PFNGLLIGHTIPROC glow_glLighti = glow_lazy_glLighti;
static void glow_lazy_glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params) {
  glow_glGetTexGendv = (PFNGLGETTEXGENDVPROC)((ptrdiff_t)(glow_get_proc("glGetTexGendv")));
  if (glow_glGetTexGendv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexGendv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexGendv\n");
#endif
  }
  glow_glGetTexGendv(coord, pname, params);
}
PFNGLGETTEXGENDVPROC glow_glGetTexGendv = glow_lazy_glGetTexGendv;
static void glow_lazy_glColor3us(GLushort red, GLushort green, GLushort blue) {
  glow_glColor3us = (PFNGLCOLOR3USPROC)((ptrdiff_t)(glow_get_proc("glColor3us")));
  if (glow_glColor3us == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3us\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3us\n");
#endif
  }
  glow_glColor3us(red, green, blue);
}
PFNGLCOLOR3USPROC glow_glColor3us = glow_lazy_glColor3us;
static void glow_lazy_glRasterPos4dv(const GLdouble *v) {
  glow_glRasterPos4dv = (PFNGLRASTERPOS4DVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos4dv")));
  if (glow_glRasterPos4dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4dv\n");
#endif
  }
  glow_glRasterPos4dv(v);
}
PFNGLRASTERPOS4DVPROC glow_glRasterPos4dv = glow_lazy_glRasterPos4dv;
static void glow_lazy_glRasterPos4iv(const GLint *v) {
  glow_glRasterPos4iv = (PFNGLRASTERPOS4IVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos4iv")));
  if (glow_glRasterPos4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4iv\n");
#endif
  }
  glow_glRasterPos4iv(v);
}
PFNGLRASTERPOS4IVPROC glow_glRasterPos4iv = glow_lazy_glRasterPos4iv;
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
static void glow_lazy_glColor3i(GLint red, GLint green, GLint blue) {
  glow_glColor3i = (PFNGLCOLOR3IPROC)((ptrdiff_t)(glow_get_proc("glColor3i")));
  if (glow_glColor3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3i\n");
#endif
  }
  glow_glColor3i(red, green, blue);
}
PFNGLCOLOR3IPROC glow_glColor3i = glow_lazy_glColor3i;
static void glow_lazy_glPolygonStipple(const GLubyte *mask) {
  glow_glPolygonStipple = (PFNGLPOLYGONSTIPPLEPROC)((ptrdiff_t)(glow_get_proc("glPolygonStipple")));
  if (glow_glPolygonStipple == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPolygonStipple\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPolygonStipple\n");
#endif
  }
  glow_glPolygonStipple(mask);
}
PFNGLPOLYGONSTIPPLEPROC glow_glPolygonStipple = glow_lazy_glPolygonStipple;
static void glow_lazy_glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values) {
  glow_glPixelMapuiv = (PFNGLPIXELMAPUIVPROC)((ptrdiff_t)(glow_get_proc("glPixelMapuiv")));
  if (glow_glPixelMapuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelMapuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelMapuiv\n");
#endif
  }
  glow_glPixelMapuiv(map, mapsize, values);
}
PFNGLPIXELMAPUIVPROC glow_glPixelMapuiv = glow_lazy_glPixelMapuiv;
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
static void glow_lazy_glIndexdv(const GLdouble *c) {
  glow_glIndexdv = (PFNGLINDEXDVPROC)((ptrdiff_t)(glow_get_proc("glIndexdv")));
  if (glow_glIndexdv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexdv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexdv\n");
#endif
  }
  glow_glIndexdv(c);
}
PFNGLINDEXDVPROC glow_glIndexdv = glow_lazy_glIndexdv;
static void glow_lazy_glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
  glow_glTexCoord4s = (PFNGLTEXCOORD4SPROC)((ptrdiff_t)(glow_get_proc("glTexCoord4s")));
  if (glow_glTexCoord4s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4s\n");
#endif
  }
  glow_glTexCoord4s(s, t, r, q);
}
PFNGLTEXCOORD4SPROC glow_glTexCoord4s = glow_lazy_glTexCoord4s;
static void glow_lazy_glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
  glow_glVertex3f = (PFNGLVERTEX3FPROC)((ptrdiff_t)(glow_get_proc("glVertex3f")));
  if (glow_glVertex3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3f\n");
#endif
  }
  glow_glVertex3f(x, y, z);
}
PFNGLVERTEX3FPROC glow_glVertex3f = glow_lazy_glVertex3f;
static void glow_lazy_glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points) {
  glow_glMap1f = (PFNGLMAP1FPROC)((ptrdiff_t)(glow_get_proc("glMap1f")));
  if (glow_glMap1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMap1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMap1f\n");
#endif
  }
  glow_glMap1f(target, u1, u2, stride, order, points);
}
PFNGLMAP1FPROC glow_glMap1f = glow_lazy_glMap1f;
static void glow_lazy_glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
  glow_glEvalMesh1 = (PFNGLEVALMESH1PROC)((ptrdiff_t)(glow_get_proc("glEvalMesh1")));
  if (glow_glEvalMesh1 == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalMesh1\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalMesh1\n");
#endif
  }
  glow_glEvalMesh1(mode, i1, i2);
}
PFNGLEVALMESH1PROC glow_glEvalMesh1 = glow_lazy_glEvalMesh1;
static GLboolean glow_lazy_glIsList(GLuint list) {
  glow_glIsList = (PFNGLISLISTPROC)((ptrdiff_t)(glow_get_proc("glIsList")));
  if (glow_glIsList == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsList\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsList\n");
#endif
  }
  return glow_glIsList(list);
}
PFNGLISLISTPROC glow_glIsList = glow_lazy_glIsList;
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
static void glow_lazy_glNormal3sv(const GLshort *v) {
  glow_glNormal3sv = (PFNGLNORMAL3SVPROC)((ptrdiff_t)(glow_get_proc("glNormal3sv")));
  if (glow_glNormal3sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3sv\n");
#endif
  }
  glow_glNormal3sv(v);
}
PFNGLNORMAL3SVPROC glow_glNormal3sv = glow_lazy_glNormal3sv;
static void glow_lazy_glTexCoord3sv(const GLshort *v) {
  glow_glTexCoord3sv = (PFNGLTEXCOORD3SVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord3sv")));
  if (glow_glTexCoord3sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3sv\n");
#endif
  }
  glow_glTexCoord3sv(v);
}
PFNGLTEXCOORD3SVPROC glow_glTexCoord3sv = glow_lazy_glTexCoord3sv;
static void glow_lazy_glVertex3i(GLint x, GLint y, GLint z) {
  glow_glVertex3i = (PFNGLVERTEX3IPROC)((ptrdiff_t)(glow_get_proc("glVertex3i")));
  if (glow_glVertex3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3i\n");
#endif
  }
  glow_glVertex3i(x, y, z);
}
PFNGLVERTEX3IPROC glow_glVertex3i = glow_lazy_glVertex3i;
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
static void glow_lazy_glTexGend(GLenum coord, GLenum pname, GLdouble param) {
  glow_glTexGend = (PFNGLTEXGENDPROC)((ptrdiff_t)(glow_get_proc("glTexGend")));
  if (glow_glTexGend == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGend\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGend\n");
#endif
  }
  glow_glTexGend(coord, pname, param);
}
PFNGLTEXGENDPROC glow_glTexGend = glow_lazy_glTexGend;
static void glow_lazy_glPixelTransferi(GLenum pname, GLint param) {
  glow_glPixelTransferi = (PFNGLPIXELTRANSFERIPROC)((ptrdiff_t)(glow_get_proc("glPixelTransferi")));
  if (glow_glPixelTransferi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelTransferi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelTransferi\n");
#endif
  }
  glow_glPixelTransferi(pname, param);
}
PFNGLPIXELTRANSFERIPROC glow_glPixelTransferi = glow_lazy_glPixelTransferi;
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
static void glow_lazy_glRectfv(const GLfloat *v1, const GLfloat *v2) {
  glow_glRectfv = (PFNGLRECTFVPROC)((ptrdiff_t)(glow_get_proc("glRectfv")));
  if (glow_glRectfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectfv\n");
#endif
  }
  glow_glRectfv(v1, v2);
}
PFNGLRECTFVPROC glow_glRectfv = glow_lazy_glRectfv;
static void glow_lazy_glTexCoord1d(GLdouble s) {
  glow_glTexCoord1d = (PFNGLTEXCOORD1DPROC)((ptrdiff_t)(glow_get_proc("glTexCoord1d")));
  if (glow_glTexCoord1d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1d\n");
#endif
  }
  glow_glTexCoord1d(s);
}
PFNGLTEXCOORD1DPROC glow_glTexCoord1d = glow_lazy_glTexCoord1d;
static void glow_lazy_glTexGeniv(GLenum coord, GLenum pname, const GLint *params) {
  glow_glTexGeniv = (PFNGLTEXGENIVPROC)((ptrdiff_t)(glow_get_proc("glTexGeniv")));
  if (glow_glTexGeniv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGeniv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGeniv\n");
#endif
  }
  glow_glTexGeniv(coord, pname, params);
}
PFNGLTEXGENIVPROC glow_glTexGeniv = glow_lazy_glTexGeniv;
static void glow_lazy_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
  glow_glVertex4f = (PFNGLVERTEX4FPROC)((ptrdiff_t)(glow_get_proc("glVertex4f")));
  if (glow_glVertex4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4f\n");
#endif
  }
  glow_glVertex4f(x, y, z, w);
}
PFNGLVERTEX4FPROC glow_glVertex4f = glow_lazy_glVertex4f;
static void glow_lazy_glEvalCoord2dv(const GLdouble *u) {
  glow_glEvalCoord2dv = (PFNGLEVALCOORD2DVPROC)((ptrdiff_t)(glow_get_proc("glEvalCoord2dv")));
  if (glow_glEvalCoord2dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord2dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord2dv\n");
#endif
  }
  glow_glEvalCoord2dv(u);
}
PFNGLEVALCOORD2DVPROC glow_glEvalCoord2dv = glow_lazy_glEvalCoord2dv;
static void glow_lazy_glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params) {
  glow_glGetTexGenfv = (PFNGLGETTEXGENFVPROC)((ptrdiff_t)(glow_get_proc("glGetTexGenfv")));
  if (glow_glGetTexGenfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexGenfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexGenfv\n");
#endif
  }
  glow_glGetTexGenfv(coord, pname, params);
}
PFNGLGETTEXGENFVPROC glow_glGetTexGenfv = glow_lazy_glGetTexGenfv;
static void glow_lazy_glColor3usv(const GLushort *v) {
  glow_glColor3usv = (PFNGLCOLOR3USVPROC)((ptrdiff_t)(glow_get_proc("glColor3usv")));
  if (glow_glColor3usv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3usv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3usv\n");
#endif
  }
  glow_glColor3usv(v);
}
PFNGLCOLOR3USVPROC glow_glColor3usv = glow_lazy_glColor3usv;
static void glow_lazy_glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
  glow_glColor4s = (PFNGLCOLOR4SPROC)((ptrdiff_t)(glow_get_proc("glColor4s")));
  if (glow_glColor4s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4s\n");
#endif
  }
  glow_glColor4s(red, green, blue, alpha);
}
PFNGLCOLOR4SPROC glow_glColor4s = glow_lazy_glColor4s;
static void glow_lazy_glIndexs(GLshort c) {
  glow_glIndexs = (PFNGLINDEXSPROC)((ptrdiff_t)(glow_get_proc("glIndexs")));
  if (glow_glIndexs == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexs\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexs\n");
#endif
  }
  glow_glIndexs(c);
}
PFNGLINDEXSPROC glow_glIndexs = glow_lazy_glIndexs;
static void glow_lazy_glTexCoord1s(GLshort s) {
  glow_glTexCoord1s = (PFNGLTEXCOORD1SPROC)((ptrdiff_t)(glow_get_proc("glTexCoord1s")));
  if (glow_glTexCoord1s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1s\n");
#endif
  }
  glow_glTexCoord1s(s);
}
PFNGLTEXCOORD1SPROC glow_glTexCoord1s = glow_lazy_glTexCoord1s;
static void glow_lazy_glRasterPos2sv(const GLshort *v) {
  glow_glRasterPos2sv = (PFNGLRASTERPOS2SVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos2sv")));
  if (glow_glRasterPos2sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2sv\n");
#endif
  }
  glow_glRasterPos2sv(v);
}
PFNGLRASTERPOS2SVPROC glow_glRasterPos2sv = glow_lazy_glRasterPos2sv;
static void glow_lazy_glTexCoord4sv(const GLshort *v) {
  glow_glTexCoord4sv = (PFNGLTEXCOORD4SVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord4sv")));
  if (glow_glTexCoord4sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4sv\n");
#endif
  }
  glow_glTexCoord4sv(v);
}
PFNGLTEXCOORD4SVPROC glow_glTexCoord4sv = glow_lazy_glTexCoord4sv;
static void glow_lazy_glInitNames() {
  glow_glInitNames = (PFNGLINITNAMESPROC)((ptrdiff_t)(glow_get_proc("glInitNames")));
  if (glow_glInitNames == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glInitNames\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glInitNames\n");
#endif
  }
  glow_glInitNames();
}
PFNGLINITNAMESPROC glow_glInitNames = glow_lazy_glInitNames;
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
static void glow_lazy_glClearDepth(GLdouble depth) {
  glow_glClearDepth = (PFNGLCLEARDEPTHPROC)((ptrdiff_t)(glow_get_proc("glClearDepth")));
  if (glow_glClearDepth == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearDepth\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearDepth\n");
#endif
  }
  glow_glClearDepth(depth);
}
PFNGLCLEARDEPTHPROC glow_glClearDepth = glow_lazy_glClearDepth;
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
static void glow_lazy_glColor3dv(const GLdouble *v) {
  glow_glColor3dv = (PFNGLCOLOR3DVPROC)((ptrdiff_t)(glow_get_proc("glColor3dv")));
  if (glow_glColor3dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3dv\n");
#endif
  }
  glow_glColor3dv(v);
}
PFNGLCOLOR3DVPROC glow_glColor3dv = glow_lazy_glColor3dv;
static void glow_lazy_glColor4bv(const GLbyte *v) {
  glow_glColor4bv = (PFNGLCOLOR4BVPROC)((ptrdiff_t)(glow_get_proc("glColor4bv")));
  if (glow_glColor4bv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4bv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4bv\n");
#endif
  }
  glow_glColor4bv(v);
}
PFNGLCOLOR4BVPROC glow_glColor4bv = glow_lazy_glColor4bv;
static void glow_lazy_glVertex3fv(const GLfloat *v) {
  glow_glVertex3fv = (PFNGLVERTEX3FVPROC)((ptrdiff_t)(glow_get_proc("glVertex3fv")));
  if (glow_glVertex3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3fv\n");
#endif
  }
  glow_glVertex3fv(v);
}
PFNGLVERTEX3FVPROC glow_glVertex3fv = glow_lazy_glVertex3fv;
static void glow_lazy_glPopAttrib() {
  glow_glPopAttrib = (PFNGLPOPATTRIBPROC)((ptrdiff_t)(glow_get_proc("glPopAttrib")));
  if (glow_glPopAttrib == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPopAttrib\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPopAttrib\n");
#endif
  }
  glow_glPopAttrib();
}
PFNGLPOPATTRIBPROC glow_glPopAttrib = glow_lazy_glPopAttrib;
static void glow_lazy_glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points) {
  glow_glMap1d = (PFNGLMAP1DPROC)((ptrdiff_t)(glow_get_proc("glMap1d")));
  if (glow_glMap1d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMap1d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMap1d\n");
#endif
  }
  glow_glMap1d(target, u1, u2, stride, order, points);
}
PFNGLMAP1DPROC glow_glMap1d = glow_lazy_glMap1d;
static void glow_lazy_glEvalCoord2d(GLdouble u, GLdouble v) {
  glow_glEvalCoord2d = (PFNGLEVALCOORD2DPROC)((ptrdiff_t)(glow_get_proc("glEvalCoord2d")));
  if (glow_glEvalCoord2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord2d\n");
#endif
  }
  glow_glEvalCoord2d(u, v);
}
PFNGLEVALCOORD2DPROC glow_glEvalCoord2d = glow_lazy_glEvalCoord2d;
static void glow_lazy_glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
  glow_glColor4b = (PFNGLCOLOR4BPROC)((ptrdiff_t)(glow_get_proc("glColor4b")));
  if (glow_glColor4b == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4b\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4b\n");
#endif
  }
  glow_glColor4b(red, green, blue, alpha);
}
PFNGLCOLOR4BPROC glow_glColor4b = glow_lazy_glColor4b;
static void glow_lazy_glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
  glow_glNormal3s = (PFNGLNORMAL3SPROC)((ptrdiff_t)(glow_get_proc("glNormal3s")));
  if (glow_glNormal3s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3s\n");
#endif
  }
  glow_glNormal3s(nx, ny, nz);
}
PFNGLNORMAL3SPROC glow_glNormal3s = glow_lazy_glNormal3s;
static void glow_lazy_glRasterPos2i(GLint x, GLint y) {
  glow_glRasterPos2i = (PFNGLRASTERPOS2IPROC)((ptrdiff_t)(glow_get_proc("glRasterPos2i")));
  if (glow_glRasterPos2i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2i\n");
#endif
  }
  glow_glRasterPos2i(x, y);
}
PFNGLRASTERPOS2IPROC glow_glRasterPos2i = glow_lazy_glRasterPos2i;
static void glow_lazy_glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
  glow_glVertex4s = (PFNGLVERTEX4SPROC)((ptrdiff_t)(glow_get_proc("glVertex4s")));
  if (glow_glVertex4s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4s\n");
#endif
  }
  glow_glVertex4s(x, y, z, w);
}
PFNGLVERTEX4SPROC glow_glVertex4s = glow_lazy_glVertex4s;
static void glow_lazy_glRasterPos3dv(const GLdouble *v) {
  glow_glRasterPos3dv = (PFNGLRASTERPOS3DVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos3dv")));
  if (glow_glRasterPos3dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3dv\n");
#endif
  }
  glow_glRasterPos3dv(v);
}
PFNGLRASTERPOS3DVPROC glow_glRasterPos3dv = glow_lazy_glRasterPos3dv;
static void glow_lazy_glTexCoord2d(GLdouble s, GLdouble t) {
  glow_glTexCoord2d = (PFNGLTEXCOORD2DPROC)((ptrdiff_t)(glow_get_proc("glTexCoord2d")));
  if (glow_glTexCoord2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2d\n");
#endif
  }
  glow_glTexCoord2d(s, t);
}
PFNGLTEXCOORD2DPROC glow_glTexCoord2d = glow_lazy_glTexCoord2d;
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
static void glow_lazy_glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {
  glow_glDrawPixels = (PFNGLDRAWPIXELSPROC)((ptrdiff_t)(glow_get_proc("glDrawPixels")));
  if (glow_glDrawPixels == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawPixels\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawPixels\n");
#endif
  }
  glow_glDrawPixels(width, height, format, type, pixels);
}
PFNGLDRAWPIXELSPROC glow_glDrawPixels = glow_lazy_glDrawPixels;
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
static void glow_lazy_glColor4iv(const GLint *v) {
  glow_glColor4iv = (PFNGLCOLOR4IVPROC)((ptrdiff_t)(glow_get_proc("glColor4iv")));
  if (glow_glColor4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4iv\n");
#endif
  }
  glow_glColor4iv(v);
}
PFNGLCOLOR4IVPROC glow_glColor4iv = glow_lazy_glColor4iv;
static void glow_lazy_glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
  glow_glCopyPixels = (PFNGLCOPYPIXELSPROC)((ptrdiff_t)(glow_get_proc("glCopyPixels")));
  if (glow_glCopyPixels == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyPixels\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyPixels\n");
#endif
  }
  glow_glCopyPixels(x, y, width, height, type);
}
PFNGLCOPYPIXELSPROC glow_glCopyPixels = glow_lazy_glCopyPixels;
static void glow_lazy_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
  glow_glRotated = (PFNGLROTATEDPROC)((ptrdiff_t)(glow_get_proc("glRotated")));
  if (glow_glRotated == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRotated\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRotated\n");
#endif
  }
  glow_glRotated(angle, x, y, z);
}
PFNGLROTATEDPROC glow_glRotated = glow_lazy_glRotated;
static void glow_lazy_glTranslated(GLdouble x, GLdouble y, GLdouble z) {
  glow_glTranslated = (PFNGLTRANSLATEDPROC)((ptrdiff_t)(glow_get_proc("glTranslated")));
  if (glow_glTranslated == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTranslated\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTranslated\n");
#endif
  }
  glow_glTranslated(x, y, z);
}
PFNGLTRANSLATEDPROC glow_glTranslated = glow_lazy_glTranslated;
static GLuint glow_lazy_glGenLists(GLsizei range) {
  glow_glGenLists = (PFNGLGENLISTSPROC)((ptrdiff_t)(glow_get_proc("glGenLists")));
  if (glow_glGenLists == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenLists\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenLists\n");
#endif
  }
  return glow_glGenLists(range);
}
PFNGLGENLISTSPROC glow_glGenLists = glow_lazy_glGenLists;
static void glow_lazy_glTexCoord1f(GLfloat s) {
  glow_glTexCoord1f = (PFNGLTEXCOORD1FPROC)((ptrdiff_t)(glow_get_proc("glTexCoord1f")));
  if (glow_glTexCoord1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1f\n");
#endif
  }
  glow_glTexCoord1f(s);
}
PFNGLTEXCOORD1FPROC glow_glTexCoord1f = glow_lazy_glTexCoord1f;
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
static void glow_lazy_glEvalCoord1dv(const GLdouble *u) {
  glow_glEvalCoord1dv = (PFNGLEVALCOORD1DVPROC)((ptrdiff_t)(glow_get_proc("glEvalCoord1dv")));
  if (glow_glEvalCoord1dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord1dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord1dv\n");
#endif
  }
  glow_glEvalCoord1dv(u);
}
PFNGLEVALCOORD1DVPROC glow_glEvalCoord1dv = glow_lazy_glEvalCoord1dv;
static void glow_lazy_glTexCoord2dv(const GLdouble *v) {
  glow_glTexCoord2dv = (PFNGLTEXCOORD2DVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord2dv")));
  if (glow_glTexCoord2dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2dv\n");
#endif
  }
  glow_glTexCoord2dv(v);
}
PFNGLTEXCOORD2DVPROC glow_glTexCoord2dv = glow_lazy_glTexCoord2dv;
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
static void glow_lazy_glPopName() {
  glow_glPopName = (PFNGLPOPNAMEPROC)((ptrdiff_t)(glow_get_proc("glPopName")));
  if (glow_glPopName == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPopName\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPopName\n");
#endif
  }
  glow_glPopName();
}
PFNGLPOPNAMEPROC glow_glPopName = glow_lazy_glPopName;
static void glow_lazy_glPushAttrib(GLbitfield mask) {
  glow_glPushAttrib = (PFNGLPUSHATTRIBPROC)((ptrdiff_t)(glow_get_proc("glPushAttrib")));
  if (glow_glPushAttrib == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPushAttrib\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPushAttrib\n");
#endif
  }
  glow_glPushAttrib(mask);
}
PFNGLPUSHATTRIBPROC glow_glPushAttrib = glow_lazy_glPushAttrib;
static void glow_lazy_glColor3ubv(const GLubyte *v) {
  glow_glColor3ubv = (PFNGLCOLOR3UBVPROC)((ptrdiff_t)(glow_get_proc("glColor3ubv")));
  if (glow_glColor3ubv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3ubv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3ubv\n");
#endif
  }
  glow_glColor3ubv(v);
}
PFNGLCOLOR3UBVPROC glow_glColor3ubv = glow_lazy_glColor3ubv;
static void glow_lazy_glTexCoord2i(GLint s, GLint t) {
  glow_glTexCoord2i = (PFNGLTEXCOORD2IPROC)((ptrdiff_t)(glow_get_proc("glTexCoord2i")));
  if (glow_glTexCoord2i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2i\n");
#endif
  }
  glow_glTexCoord2i(s, t);
}
PFNGLTEXCOORD2IPROC glow_glTexCoord2i = glow_lazy_glTexCoord2i;
static void glow_lazy_glColor4ubv(const GLubyte *v) {
  glow_glColor4ubv = (PFNGLCOLOR4UBVPROC)((ptrdiff_t)(glow_get_proc("glColor4ubv")));
  if (glow_glColor4ubv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4ubv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4ubv\n");
#endif
  }
  glow_glColor4ubv(v);
}
PFNGLCOLOR4UBVPROC glow_glColor4ubv = glow_lazy_glColor4ubv;
static void glow_lazy_glVertex2s(GLshort x, GLshort y) {
  glow_glVertex2s = (PFNGLVERTEX2SPROC)((ptrdiff_t)(glow_get_proc("glVertex2s")));
  if (glow_glVertex2s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2s\n");
#endif
  }
  glow_glVertex2s(x, y);
}
PFNGLVERTEX2SPROC glow_glVertex2s = glow_lazy_glVertex2s;
static void glow_lazy_glVertex3iv(const GLint *v) {
  glow_glVertex3iv = (PFNGLVERTEX3IVPROC)((ptrdiff_t)(glow_get_proc("glVertex3iv")));
  if (glow_glVertex3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3iv\n");
#endif
  }
  glow_glVertex3iv(v);
}
PFNGLVERTEX3IVPROC glow_glVertex3iv = glow_lazy_glVertex3iv;
static void glow_lazy_glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer) {
  glow_glFeedbackBuffer = (PFNGLFEEDBACKBUFFERPROC)((ptrdiff_t)(glow_get_proc("glFeedbackBuffer")));
  if (glow_glFeedbackBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFeedbackBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFeedbackBuffer\n");
#endif
  }
  glow_glFeedbackBuffer(size, type, buffer);
}
PFNGLFEEDBACKBUFFERPROC glow_glFeedbackBuffer = glow_lazy_glFeedbackBuffer;
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
static void glow_lazy_glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
  glow_glColor3d = (PFNGLCOLOR3DPROC)((ptrdiff_t)(glow_get_proc("glColor3d")));
  if (glow_glColor3d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3d\n");
#endif
  }
  glow_glColor3d(red, green, blue);
}
PFNGLCOLOR3DPROC glow_glColor3d = glow_lazy_glColor3d;
static void glow_lazy_glColor3s(GLshort red, GLshort green, GLshort blue) {
  glow_glColor3s = (PFNGLCOLOR3SPROC)((ptrdiff_t)(glow_get_proc("glColor3s")));
  if (glow_glColor3s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3s\n");
#endif
  }
  glow_glColor3s(red, green, blue);
}
PFNGLCOLOR3SPROC glow_glColor3s = glow_lazy_glColor3s;
static void glow_lazy_glColor3sv(const GLshort *v) {
  glow_glColor3sv = (PFNGLCOLOR3SVPROC)((ptrdiff_t)(glow_get_proc("glColor3sv")));
  if (glow_glColor3sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3sv\n");
#endif
  }
  glow_glColor3sv(v);
}
PFNGLCOLOR3SVPROC glow_glColor3sv = glow_lazy_glColor3sv;
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
static void glow_lazy_glGetPixelMapfv(GLenum map, GLfloat *values) {
  glow_glGetPixelMapfv = (PFNGLGETPIXELMAPFVPROC)((ptrdiff_t)(glow_get_proc("glGetPixelMapfv")));
  if (glow_glGetPixelMapfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetPixelMapfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetPixelMapfv\n");
#endif
  }
  glow_glGetPixelMapfv(map, values);
}
PFNGLGETPIXELMAPFVPROC glow_glGetPixelMapfv = glow_lazy_glGetPixelMapfv;
static void glow_lazy_glTexCoord2iv(const GLint *v) {
  glow_glTexCoord2iv = (PFNGLTEXCOORD2IVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord2iv")));
  if (glow_glTexCoord2iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2iv\n");
#endif
  }
  glow_glTexCoord2iv(v);
}
PFNGLTEXCOORD2IVPROC glow_glTexCoord2iv = glow_lazy_glTexCoord2iv;
static void glow_lazy_glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points) {
  glow_glMap2f = (PFNGLMAP2FPROC)((ptrdiff_t)(glow_get_proc("glMap2f")));
  if (glow_glMap2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMap2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMap2f\n");
#endif
  }
  glow_glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
PFNGLMAP2FPROC glow_glMap2f = glow_lazy_glMap2f;
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
static void glow_lazy_glDrawBuffer(GLenum buf) {
  glow_glDrawBuffer = (PFNGLDRAWBUFFERPROC)((ptrdiff_t)(glow_get_proc("glDrawBuffer")));
  if (glow_glDrawBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawBuffer\n");
#endif
  }
  glow_glDrawBuffer(buf);
}
PFNGLDRAWBUFFERPROC glow_glDrawBuffer = glow_lazy_glDrawBuffer;
static void glow_lazy_glCallList(GLuint list) {
  glow_glCallList = (PFNGLCALLLISTPROC)((ptrdiff_t)(glow_get_proc("glCallList")));
  if (glow_glCallList == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCallList\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCallList\n");
#endif
  }
  glow_glCallList(list);
}
PFNGLCALLLISTPROC glow_glCallList = glow_lazy_glCallList;
static void glow_lazy_glTexCoord1sv(const GLshort *v) {
  glow_glTexCoord1sv = (PFNGLTEXCOORD1SVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord1sv")));
  if (glow_glTexCoord1sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1sv\n");
#endif
  }
  glow_glTexCoord1sv(v);
}
PFNGLTEXCOORD1SVPROC glow_glTexCoord1sv = glow_lazy_glTexCoord1sv;
static void glow_lazy_glGetMapfv(GLenum target, GLenum query, GLfloat *v) {
  glow_glGetMapfv = (PFNGLGETMAPFVPROC)((ptrdiff_t)(glow_get_proc("glGetMapfv")));
  if (glow_glGetMapfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMapfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMapfv\n");
#endif
  }
  glow_glGetMapfv(target, query, v);
}
PFNGLGETMAPFVPROC glow_glGetMapfv = glow_lazy_glGetMapfv;
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
static void glow_lazy_glTexCoord2s(GLshort s, GLshort t) {
  glow_glTexCoord2s = (PFNGLTEXCOORD2SPROC)((ptrdiff_t)(glow_get_proc("glTexCoord2s")));
  if (glow_glTexCoord2s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2s\n");
#endif
  }
  glow_glTexCoord2s(s, t);
}
PFNGLTEXCOORD2SPROC glow_glTexCoord2s = glow_lazy_glTexCoord2s;
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
static void glow_lazy_glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params) {
  glow_glTexGenfv = (PFNGLTEXGENFVPROC)((ptrdiff_t)(glow_get_proc("glTexGenfv")));
  if (glow_glTexGenfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGenfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGenfv\n");
#endif
  }
  glow_glTexGenfv(coord, pname, params);
}
PFNGLTEXGENFVPROC glow_glTexGenfv = glow_lazy_glTexGenfv;
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
static void glow_lazy_glVertex2d(GLdouble x, GLdouble y) {
  glow_glVertex2d = (PFNGLVERTEX2DPROC)((ptrdiff_t)(glow_get_proc("glVertex2d")));
  if (glow_glVertex2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2d\n");
#endif
  }
  glow_glVertex2d(x, y);
}
PFNGLVERTEX2DPROC glow_glVertex2d = glow_lazy_glVertex2d;
static void glow_lazy_glLineStipple(GLint factor, GLushort pattern) {
  glow_glLineStipple = (PFNGLLINESTIPPLEPROC)((ptrdiff_t)(glow_get_proc("glLineStipple")));
  if (glow_glLineStipple == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLineStipple\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLineStipple\n");
#endif
  }
  glow_glLineStipple(factor, pattern);
}
PFNGLLINESTIPPLEPROC glow_glLineStipple = glow_lazy_glLineStipple;
static void glow_lazy_glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
  glow_glOrtho = (PFNGLORTHOPROC)((ptrdiff_t)(glow_get_proc("glOrtho")));
  if (glow_glOrtho == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glOrtho\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glOrtho\n");
#endif
  }
  glow_glOrtho(left, right, bottom, top, zNear, zFar);
}
PFNGLORTHOPROC glow_glOrtho = glow_lazy_glOrtho;
static void glow_lazy_glTexCoord3dv(const GLdouble *v) {
  glow_glTexCoord3dv = (PFNGLTEXCOORD3DVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord3dv")));
  if (glow_glTexCoord3dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3dv\n");
#endif
  }
  glow_glTexCoord3dv(v);
}
PFNGLTEXCOORD3DVPROC glow_glTexCoord3dv = glow_lazy_glTexCoord3dv;
static GLint glow_lazy_glRenderMode(GLenum mode) {
  glow_glRenderMode = (PFNGLRENDERMODEPROC)((ptrdiff_t)(glow_get_proc("glRenderMode")));
  if (glow_glRenderMode == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRenderMode\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRenderMode\n");
#endif
  }
  return glow_glRenderMode(mode);
}
PFNGLRENDERMODEPROC glow_glRenderMode = glow_lazy_glRenderMode;
static void glow_lazy_glCallLists(GLsizei n, GLenum type, const void *lists) {
  glow_glCallLists = (PFNGLCALLLISTSPROC)((ptrdiff_t)(glow_get_proc("glCallLists")));
  if (glow_glCallLists == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCallLists\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCallLists\n");
#endif
  }
  glow_glCallLists(n, type, lists);
}
PFNGLCALLLISTSPROC glow_glCallLists = glow_lazy_glCallLists;
static void glow_lazy_glColor3ui(GLuint red, GLuint green, GLuint blue) {
  glow_glColor3ui = (PFNGLCOLOR3UIPROC)((ptrdiff_t)(glow_get_proc("glColor3ui")));
  if (glow_glColor3ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3ui\n");
#endif
  }
  glow_glColor3ui(red, green, blue);
}
PFNGLCOLOR3UIPROC glow_glColor3ui = glow_lazy_glColor3ui;
static void glow_lazy_glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
  glow_glNormal3d = (PFNGLNORMAL3DPROC)((ptrdiff_t)(glow_get_proc("glNormal3d")));
  if (glow_glNormal3d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3d\n");
#endif
  }
  glow_glNormal3d(nx, ny, nz);
}
PFNGLNORMAL3DPROC glow_glNormal3d = glow_lazy_glNormal3d;
static void glow_lazy_glRasterPos3i(GLint x, GLint y, GLint z) {
  glow_glRasterPos3i = (PFNGLRASTERPOS3IPROC)((ptrdiff_t)(glow_get_proc("glRasterPos3i")));
  if (glow_glRasterPos3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3i\n");
#endif
  }
  glow_glRasterPos3i(x, y, z);
}
PFNGLRASTERPOS3IPROC glow_glRasterPos3i = glow_lazy_glRasterPos3i;
static void glow_lazy_glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
  glow_glRasterPos4f = (PFNGLRASTERPOS4FPROC)((ptrdiff_t)(glow_get_proc("glRasterPos4f")));
  if (glow_glRasterPos4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4f\n");
#endif
  }
  glow_glRasterPos4f(x, y, z, w);
}
PFNGLRASTERPOS4FPROC glow_glRasterPos4f = glow_lazy_glRasterPos4f;
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
static void glow_lazy_glColor4usv(const GLushort *v) {
  glow_glColor4usv = (PFNGLCOLOR4USVPROC)((ptrdiff_t)(glow_get_proc("glColor4usv")));
  if (glow_glColor4usv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4usv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4usv\n");
#endif
  }
  glow_glColor4usv(v);
}
PFNGLCOLOR4USVPROC glow_glColor4usv = glow_lazy_glColor4usv;
static void glow_lazy_glTexCoord2f(GLfloat s, GLfloat t) {
  glow_glTexCoord2f = (PFNGLTEXCOORD2FPROC)((ptrdiff_t)(glow_get_proc("glTexCoord2f")));
  if (glow_glTexCoord2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2f\n");
#endif
  }
  glow_glTexCoord2f(s, t);
}
PFNGLTEXCOORD2FPROC glow_glTexCoord2f = glow_lazy_glTexCoord2f;
static void glow_lazy_glVertex2iv(const GLint *v) {
  glow_glVertex2iv = (PFNGLVERTEX2IVPROC)((ptrdiff_t)(glow_get_proc("glVertex2iv")));
  if (glow_glVertex2iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2iv\n");
#endif
  }
  glow_glVertex2iv(v);
}
PFNGLVERTEX2IVPROC glow_glVertex2iv = glow_lazy_glVertex2iv;
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
static void glow_lazy_glGetPixelMapuiv(GLenum map, GLuint *values) {
  glow_glGetPixelMapuiv = (PFNGLGETPIXELMAPUIVPROC)((ptrdiff_t)(glow_get_proc("glGetPixelMapuiv")));
  if (glow_glGetPixelMapuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetPixelMapuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetPixelMapuiv\n");
#endif
  }
  glow_glGetPixelMapuiv(map, values);
}
PFNGLGETPIXELMAPUIVPROC glow_glGetPixelMapuiv = glow_lazy_glGetPixelMapuiv;
static void glow_lazy_glIndexi(GLint c) {
  glow_glIndexi = (PFNGLINDEXIPROC)((ptrdiff_t)(glow_get_proc("glIndexi")));
  if (glow_glIndexi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexi\n");
#endif
  }
  glow_glIndexi(c);
}
PFNGLINDEXIPROC glow_glIndexi = glow_lazy_glIndexi;
static void glow_lazy_glIndexsv(const GLshort *c) {
  glow_glIndexsv = (PFNGLINDEXSVPROC)((ptrdiff_t)(glow_get_proc("glIndexsv")));
  if (glow_glIndexsv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexsv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexsv\n");
#endif
  }
  glow_glIndexsv(c);
}
PFNGLINDEXSVPROC glow_glIndexsv = glow_lazy_glIndexsv;
static void glow_lazy_glRectiv(const GLint *v1, const GLint *v2) {
  glow_glRectiv = (PFNGLRECTIVPROC)((ptrdiff_t)(glow_get_proc("glRectiv")));
  if (glow_glRectiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectiv\n");
#endif
  }
  glow_glRectiv(v1, v2);
}
PFNGLRECTIVPROC glow_glRectiv = glow_lazy_glRectiv;
static void glow_lazy_glTexCoord4iv(const GLint *v) {
  glow_glTexCoord4iv = (PFNGLTEXCOORD4IVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord4iv")));
  if (glow_glTexCoord4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4iv\n");
#endif
  }
  glow_glTexCoord4iv(v);
}
PFNGLTEXCOORD4IVPROC glow_glTexCoord4iv = glow_lazy_glTexCoord4iv;
static void glow_lazy_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
  glow_glMapGrid1d = (PFNGLMAPGRID1DPROC)((ptrdiff_t)(glow_get_proc("glMapGrid1d")));
  if (glow_glMapGrid1d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMapGrid1d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMapGrid1d\n");
#endif
  }
  glow_glMapGrid1d(un, u1, u2);
}
PFNGLMAPGRID1DPROC glow_glMapGrid1d = glow_lazy_glMapGrid1d;
static void glow_lazy_glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values) {
  glow_glPixelMapusv = (PFNGLPIXELMAPUSVPROC)((ptrdiff_t)(glow_get_proc("glPixelMapusv")));
  if (glow_glPixelMapusv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelMapusv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelMapusv\n");
#endif
  }
  glow_glPixelMapusv(map, mapsize, values);
}
PFNGLPIXELMAPUSVPROC glow_glPixelMapusv = glow_lazy_glPixelMapusv;
static void glow_lazy_glNormal3iv(const GLint *v) {
  glow_glNormal3iv = (PFNGLNORMAL3IVPROC)((ptrdiff_t)(glow_get_proc("glNormal3iv")));
  if (glow_glNormal3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3iv\n");
#endif
  }
  glow_glNormal3iv(v);
}
PFNGLNORMAL3IVPROC glow_glNormal3iv = glow_lazy_glNormal3iv;
static void glow_lazy_glRasterPos3fv(const GLfloat *v) {
  glow_glRasterPos3fv = (PFNGLRASTERPOS3FVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos3fv")));
  if (glow_glRasterPos3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3fv\n");
#endif
  }
  glow_glRasterPos3fv(v);
}
PFNGLRASTERPOS3FVPROC glow_glRasterPos3fv = glow_lazy_glRasterPos3fv;
static void glow_lazy_glTexCoord3fv(const GLfloat *v) {
  glow_glTexCoord3fv = (PFNGLTEXCOORD3FVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord3fv")));
  if (glow_glTexCoord3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3fv\n");
#endif
  }
  glow_glTexCoord3fv(v);
}
PFNGLTEXCOORD3FVPROC glow_glTexCoord3fv = glow_lazy_glTexCoord3fv;
static void glow_lazy_glTexGeni(GLenum coord, GLenum pname, GLint param) {
  glow_glTexGeni = (PFNGLTEXGENIPROC)((ptrdiff_t)(glow_get_proc("glTexGeni")));
  if (glow_glTexGeni == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGeni\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGeni\n");
#endif
  }
  glow_glTexGeni(coord, pname, param);
}
PFNGLTEXGENIPROC glow_glTexGeni = glow_lazy_glTexGeni;
static void glow_lazy_glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
  glow_glColor3f = (PFNGLCOLOR3FPROC)((ptrdiff_t)(glow_get_proc("glColor3f")));
  if (glow_glColor3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3f\n");
#endif
  }
  glow_glColor3f(red, green, blue);
}
PFNGLCOLOR3FPROC glow_glColor3f = glow_lazy_glColor3f;
static void glow_lazy_glRasterPos2fv(const GLfloat *v) {
  glow_glRasterPos2fv = (PFNGLRASTERPOS2FVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos2fv")));
  if (glow_glRasterPos2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2fv\n");
#endif
  }
  glow_glRasterPos2fv(v);
}
PFNGLRASTERPOS2FVPROC glow_glRasterPos2fv = glow_lazy_glRasterPos2fv;
static void glow_lazy_glTexCoord1i(GLint s) {
  glow_glTexCoord1i = (PFNGLTEXCOORD1IPROC)((ptrdiff_t)(glow_get_proc("glTexCoord1i")));
  if (glow_glTexCoord1i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1i\n");
#endif
  }
  glow_glTexCoord1i(s);
}
PFNGLTEXCOORD1IPROC glow_glTexCoord1i = glow_lazy_glTexCoord1i;
static void glow_lazy_glIndexMask(GLuint mask) {
  glow_glIndexMask = (PFNGLINDEXMASKPROC)((ptrdiff_t)(glow_get_proc("glIndexMask")));
  if (glow_glIndexMask == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexMask\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexMask\n");
#endif
  }
  glow_glIndexMask(mask);
}
PFNGLINDEXMASKPROC glow_glIndexMask = glow_lazy_glIndexMask;
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
static void glow_lazy_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels) {
  glow_glGetTexImage = (PFNGLGETTEXIMAGEPROC)((ptrdiff_t)(glow_get_proc("glGetTexImage")));
  if (glow_glGetTexImage == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexImage\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexImage\n");
#endif
  }
  glow_glGetTexImage(target, level, format, type, pixels);
}
PFNGLGETTEXIMAGEPROC glow_glGetTexImage = glow_lazy_glGetTexImage;
static void glow_lazy_glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
  glow_glTexCoord4d = (PFNGLTEXCOORD4DPROC)((ptrdiff_t)(glow_get_proc("glTexCoord4d")));
  if (glow_glTexCoord4d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4d\n");
#endif
  }
  glow_glTexCoord4d(s, t, r, q);
}
PFNGLTEXCOORD4DPROC glow_glTexCoord4d = glow_lazy_glTexCoord4d;
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
static void glow_lazy_glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
  glow_glClearAccum = (PFNGLCLEARACCUMPROC)((ptrdiff_t)(glow_get_proc("glClearAccum")));
  if (glow_glClearAccum == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearAccum\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearAccum\n");
#endif
  }
  glow_glClearAccum(red, green, blue, alpha);
}
PFNGLCLEARACCUMPROC glow_glClearAccum = glow_lazy_glClearAccum;
static void glow_lazy_glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
  glow_glMapGrid2f = (PFNGLMAPGRID2FPROC)((ptrdiff_t)(glow_get_proc("glMapGrid2f")));
  if (glow_glMapGrid2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMapGrid2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMapGrid2f\n");
#endif
  }
  glow_glMapGrid2f(un, u1, u2, vn, v1, v2);
}
PFNGLMAPGRID2FPROC glow_glMapGrid2f = glow_lazy_glMapGrid2f;
static void glow_lazy_glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
  glow_glPixelZoom = (PFNGLPIXELZOOMPROC)((ptrdiff_t)(glow_get_proc("glPixelZoom")));
  if (glow_glPixelZoom == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelZoom\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelZoom\n");
#endif
  }
  glow_glPixelZoom(xfactor, yfactor);
}
PFNGLPIXELZOOMPROC glow_glPixelZoom = glow_lazy_glPixelZoom;
static void glow_lazy_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
  glow_glFrustum = (PFNGLFRUSTUMPROC)((ptrdiff_t)(glow_get_proc("glFrustum")));
  if (glow_glFrustum == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFrustum\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFrustum\n");
#endif
  }
  glow_glFrustum(left, right, bottom, top, zNear, zFar);
}
PFNGLFRUSTUMPROC glow_glFrustum = glow_lazy_glFrustum;
static void glow_lazy_glRasterPos4fv(const GLfloat *v) {
  glow_glRasterPos4fv = (PFNGLRASTERPOS4FVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos4fv")));
  if (glow_glRasterPos4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4fv\n");
#endif
  }
  glow_glRasterPos4fv(v);
}
PFNGLRASTERPOS4FVPROC glow_glRasterPos4fv = glow_lazy_glRasterPos4fv;
static void glow_lazy_glVertex3dv(const GLdouble *v) {
  glow_glVertex3dv = (PFNGLVERTEX3DVPROC)((ptrdiff_t)(glow_get_proc("glVertex3dv")));
  if (glow_glVertex3dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3dv\n");
#endif
  }
  glow_glVertex3dv(v);
}
PFNGLVERTEX3DVPROC glow_glVertex3dv = glow_lazy_glVertex3dv;
static void glow_lazy_glFogi(GLenum pname, GLint param) {
  glow_glFogi = (PFNGLFOGIPROC)((ptrdiff_t)(glow_get_proc("glFogi")));
  if (glow_glFogi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogi\n");
#endif
  }
  glow_glFogi(pname, param);
}
PFNGLFOGIPROC glow_glFogi = glow_lazy_glFogi;
static void glow_lazy_glLightModeli(GLenum pname, GLint param) {
  glow_glLightModeli = (PFNGLLIGHTMODELIPROC)((ptrdiff_t)(glow_get_proc("glLightModeli")));
  if (glow_glLightModeli == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModeli\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModeli\n");
#endif
  }
  glow_glLightModeli(pname, param);
}
PFNGLLIGHTMODELIPROC glow_glLightModeli = glow_lazy_glLightModeli;
static void glow_lazy_glTexCoord1dv(const GLdouble *v) {
  glow_glTexCoord1dv = (PFNGLTEXCOORD1DVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord1dv")));
  if (glow_glTexCoord1dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1dv\n");
#endif
  }
  glow_glTexCoord1dv(v);
}
PFNGLTEXCOORD1DVPROC glow_glTexCoord1dv = glow_lazy_glTexCoord1dv;
static void glow_lazy_glVertex2f(GLfloat x, GLfloat y) {
  glow_glVertex2f = (PFNGLVERTEX2FPROC)((ptrdiff_t)(glow_get_proc("glVertex2f")));
  if (glow_glVertex2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2f\n");
#endif
  }
  glow_glVertex2f(x, y);
}
PFNGLVERTEX2FPROC glow_glVertex2f = glow_lazy_glVertex2f;
static void glow_lazy_glPixelTransferf(GLenum pname, GLfloat param) {
  glow_glPixelTransferf = (PFNGLPIXELTRANSFERFPROC)((ptrdiff_t)(glow_get_proc("glPixelTransferf")));
  if (glow_glPixelTransferf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelTransferf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelTransferf\n");
#endif
  }
  glow_glPixelTransferf(pname, param);
}
PFNGLPIXELTRANSFERFPROC glow_glPixelTransferf = glow_lazy_glPixelTransferf;
static void glow_lazy_glGetMapdv(GLenum target, GLenum query, GLdouble *v) {
  glow_glGetMapdv = (PFNGLGETMAPDVPROC)((ptrdiff_t)(glow_get_proc("glGetMapdv")));
  if (glow_glGetMapdv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMapdv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMapdv\n");
#endif
  }
  glow_glGetMapdv(target, query, v);
}
PFNGLGETMAPDVPROC glow_glGetMapdv = glow_lazy_glGetMapdv;
static void glow_lazy_glPolygonMode(GLenum face, GLenum mode) {
  glow_glPolygonMode = (PFNGLPOLYGONMODEPROC)((ptrdiff_t)(glow_get_proc("glPolygonMode")));
  if (glow_glPolygonMode == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPolygonMode\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPolygonMode\n");
#endif
  }
  glow_glPolygonMode(face, mode);
}
PFNGLPOLYGONMODEPROC glow_glPolygonMode = glow_lazy_glPolygonMode;
static void glow_lazy_glPixelStoref(GLenum pname, GLfloat param) {
  glow_glPixelStoref = (PFNGLPIXELSTOREFPROC)((ptrdiff_t)(glow_get_proc("glPixelStoref")));
  if (glow_glPixelStoref == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelStoref\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelStoref\n");
#endif
  }
  glow_glPixelStoref(pname, param);
}
PFNGLPIXELSTOREFPROC glow_glPixelStoref = glow_lazy_glPixelStoref;
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
static void glow_lazy_glColor4fv(const GLfloat *v) {
  glow_glColor4fv = (PFNGLCOLOR4FVPROC)((ptrdiff_t)(glow_get_proc("glColor4fv")));
  if (glow_glColor4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4fv\n");
#endif
  }
  glow_glColor4fv(v);
}
PFNGLCOLOR4FVPROC glow_glColor4fv = glow_lazy_glColor4fv;
static void glow_lazy_glEvalCoord2f(GLfloat u, GLfloat v) {
  glow_glEvalCoord2f = (PFNGLEVALCOORD2FPROC)((ptrdiff_t)(glow_get_proc("glEvalCoord2f")));
  if (glow_glEvalCoord2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord2f\n");
#endif
  }
  glow_glEvalCoord2f(u, v);
}
PFNGLEVALCOORD2FPROC glow_glEvalCoord2f = glow_lazy_glEvalCoord2f;
static void glow_lazy_glNormal3dv(const GLdouble *v) {
  glow_glNormal3dv = (PFNGLNORMAL3DVPROC)((ptrdiff_t)(glow_get_proc("glNormal3dv")));
  if (glow_glNormal3dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3dv\n");
#endif
  }
  glow_glNormal3dv(v);
}
PFNGLNORMAL3DVPROC glow_glNormal3dv = glow_lazy_glNormal3dv;
static void glow_lazy_glMateriali(GLenum face, GLenum pname, GLint param) {
  glow_glMateriali = (PFNGLMATERIALIPROC)((ptrdiff_t)(glow_get_proc("glMateriali")));
  if (glow_glMateriali == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMateriali\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMateriali\n");
#endif
  }
  glow_glMateriali(face, pname, param);
}
PFNGLMATERIALIPROC glow_glMateriali = glow_lazy_glMateriali;
static void glow_lazy_glPushName(GLuint name) {
  glow_glPushName = (PFNGLPUSHNAMEPROC)((ptrdiff_t)(glow_get_proc("glPushName")));
  if (glow_glPushName == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPushName\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPushName\n");
#endif
  }
  glow_glPushName(name);
}
PFNGLPUSHNAMEPROC glow_glPushName = glow_lazy_glPushName;
static void glow_lazy_glAccum(GLenum op, GLfloat value) {
  glow_glAccum = (PFNGLACCUMPROC)((ptrdiff_t)(glow_get_proc("glAccum")));
  if (glow_glAccum == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glAccum\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glAccum\n");
#endif
  }
  glow_glAccum(op, value);
}
PFNGLACCUMPROC glow_glAccum = glow_lazy_glAccum;
static void glow_lazy_glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
  glow_glRecti = (PFNGLRECTIPROC)((ptrdiff_t)(glow_get_proc("glRecti")));
  if (glow_glRecti == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRecti\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRecti\n");
#endif
  }
  glow_glRecti(x1, y1, x2, y2);
}
PFNGLRECTIPROC glow_glRecti = glow_lazy_glRecti;
static void glow_lazy_glTexCoord2sv(const GLshort *v) {
  glow_glTexCoord2sv = (PFNGLTEXCOORD2SVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord2sv")));
  if (glow_glTexCoord2sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2sv\n");
#endif
  }
  glow_glTexCoord2sv(v);
}
PFNGLTEXCOORD2SVPROC glow_glTexCoord2sv = glow_lazy_glTexCoord2sv;
static void glow_lazy_glVertex2sv(const GLshort *v) {
  glow_glVertex2sv = (PFNGLVERTEX2SVPROC)((ptrdiff_t)(glow_get_proc("glVertex2sv")));
  if (glow_glVertex2sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2sv\n");
#endif
  }
  glow_glVertex2sv(v);
}
PFNGLVERTEX2SVPROC glow_glVertex2sv = glow_lazy_glVertex2sv;
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
static void glow_lazy_glColor3uiv(const GLuint *v) {
  glow_glColor3uiv = (PFNGLCOLOR3UIVPROC)((ptrdiff_t)(glow_get_proc("glColor3uiv")));
  if (glow_glColor3uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3uiv\n");
#endif
  }
  glow_glColor3uiv(v);
}
PFNGLCOLOR3UIVPROC glow_glColor3uiv = glow_lazy_glColor3uiv;
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
static void glow_lazy_glVertex2fv(const GLfloat *v) {
  glow_glVertex2fv = (PFNGLVERTEX2FVPROC)((ptrdiff_t)(glow_get_proc("glVertex2fv")));
  if (glow_glVertex2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2fv\n");
#endif
  }
  glow_glVertex2fv(v);
}
PFNGLVERTEX2FVPROC glow_glVertex2fv = glow_lazy_glVertex2fv;
static void glow_lazy_glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
  glow_glVertex4d = (PFNGLVERTEX4DPROC)((ptrdiff_t)(glow_get_proc("glVertex4d")));
  if (glow_glVertex4d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4d\n");
#endif
  }
  glow_glVertex4d(x, y, z, w);
}
PFNGLVERTEX4DPROC glow_glVertex4d = glow_lazy_glVertex4d;
static void glow_lazy_glColor3fv(const GLfloat *v) {
  glow_glColor3fv = (PFNGLCOLOR3FVPROC)((ptrdiff_t)(glow_get_proc("glColor3fv")));
  if (glow_glColor3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3fv\n");
#endif
  }
  glow_glColor3fv(v);
}
PFNGLCOLOR3FVPROC glow_glColor3fv = glow_lazy_glColor3fv;
static void glow_lazy_glPassThrough(GLfloat token) {
  glow_glPassThrough = (PFNGLPASSTHROUGHPROC)((ptrdiff_t)(glow_get_proc("glPassThrough")));
  if (glow_glPassThrough == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPassThrough\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPassThrough\n");
#endif
  }
  glow_glPassThrough(token);
}
PFNGLPASSTHROUGHPROC glow_glPassThrough = glow_lazy_glPassThrough;
static void glow_lazy_glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
  glow_glMapGrid1f = (PFNGLMAPGRID1FPROC)((ptrdiff_t)(glow_get_proc("glMapGrid1f")));
  if (glow_glMapGrid1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMapGrid1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMapGrid1f\n");
#endif
  }
  glow_glMapGrid1f(un, u1, u2);
}
PFNGLMAPGRID1FPROC glow_glMapGrid1f = glow_lazy_glMapGrid1f;
static void glow_lazy_glEvalCoord1d(GLdouble u) {
  glow_glEvalCoord1d = (PFNGLEVALCOORD1DPROC)((ptrdiff_t)(glow_get_proc("glEvalCoord1d")));
  if (glow_glEvalCoord1d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord1d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord1d\n");
#endif
  }
  glow_glEvalCoord1d(u);
}
PFNGLEVALCOORD1DPROC glow_glEvalCoord1d = glow_lazy_glEvalCoord1d;
static void glow_lazy_glGetMaterialiv(GLenum face, GLenum pname, GLint *params) {
  glow_glGetMaterialiv = (PFNGLGETMATERIALIVPROC)((ptrdiff_t)(glow_get_proc("glGetMaterialiv")));
  if (glow_glGetMaterialiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMaterialiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMaterialiv\n");
#endif
  }
  glow_glGetMaterialiv(face, pname, params);
}
PFNGLGETMATERIALIVPROC glow_glGetMaterialiv = glow_lazy_glGetMaterialiv;
static void glow_lazy_glIndexfv(const GLfloat *c) {
  glow_glIndexfv = (PFNGLINDEXFVPROC)((ptrdiff_t)(glow_get_proc("glIndexfv")));
  if (glow_glIndexfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexfv\n");
#endif
  }
  glow_glIndexfv(c);
}
PFNGLINDEXFVPROC glow_glIndexfv = glow_lazy_glIndexfv;
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
static void glow_lazy_glNormal3fv(const GLfloat *v) {
  glow_glNormal3fv = (PFNGLNORMAL3FVPROC)((ptrdiff_t)(glow_get_proc("glNormal3fv")));
  if (glow_glNormal3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3fv\n");
#endif
  }
  glow_glNormal3fv(v);
}
PFNGLNORMAL3FVPROC glow_glNormal3fv = glow_lazy_glNormal3fv;
static void glow_lazy_glVertex4dv(const GLdouble *v) {
  glow_glVertex4dv = (PFNGLVERTEX4DVPROC)((ptrdiff_t)(glow_get_proc("glVertex4dv")));
  if (glow_glVertex4dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4dv\n");
#endif
  }
  glow_glVertex4dv(v);
}
PFNGLVERTEX4DVPROC glow_glVertex4dv = glow_lazy_glVertex4dv;
static void glow_lazy_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
  glow_glMapGrid2d = (PFNGLMAPGRID2DPROC)((ptrdiff_t)(glow_get_proc("glMapGrid2d")));
  if (glow_glMapGrid2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMapGrid2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMapGrid2d\n");
#endif
  }
  glow_glMapGrid2d(un, u1, u2, vn, v1, v2);
}
PFNGLMAPGRID2DPROC glow_glMapGrid2d = glow_lazy_glMapGrid2d;
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
static void glow_lazy_glEdgeFlag(GLboolean flag) {
  glow_glEdgeFlag = (PFNGLEDGEFLAGPROC)((ptrdiff_t)(glow_get_proc("glEdgeFlag")));
  if (glow_glEdgeFlag == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEdgeFlag\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEdgeFlag\n");
#endif
  }
  glow_glEdgeFlag(flag);
}
PFNGLEDGEFLAGPROC glow_glEdgeFlag = glow_lazy_glEdgeFlag;
static void glow_lazy_glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
  glow_glTexCoord4i = (PFNGLTEXCOORD4IPROC)((ptrdiff_t)(glow_get_proc("glTexCoord4i")));
  if (glow_glTexCoord4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4i\n");
#endif
  }
  glow_glTexCoord4i(s, t, r, q);
}
PFNGLTEXCOORD4IPROC glow_glTexCoord4i = glow_lazy_glTexCoord4i;
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
static void glow_lazy_glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
  glow_glColor3ub = (PFNGLCOLOR3UBPROC)((ptrdiff_t)(glow_get_proc("glColor3ub")));
  if (glow_glColor3ub == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3ub\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3ub\n");
#endif
  }
  glow_glColor3ub(red, green, blue);
}
PFNGLCOLOR3UBPROC glow_glColor3ub = glow_lazy_glColor3ub;
static void glow_lazy_glEnd() {
  glow_glEnd = (PFNGLENDPROC)((ptrdiff_t)(glow_get_proc("glEnd")));
  if (glow_glEnd == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnd\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnd\n");
#endif
  }
  glow_glEnd();
}
PFNGLENDPROC glow_glEnd = glow_lazy_glEnd;
static void glow_lazy_glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
  glow_glNormal3b = (PFNGLNORMAL3BPROC)((ptrdiff_t)(glow_get_proc("glNormal3b")));
  if (glow_glNormal3b == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3b\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3b\n");
#endif
  }
  glow_glNormal3b(nx, ny, nz);
}
PFNGLNORMAL3BPROC glow_glNormal3b = glow_lazy_glNormal3b;
static void glow_lazy_glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
  glow_glRasterPos4i = (PFNGLRASTERPOS4IPROC)((ptrdiff_t)(glow_get_proc("glRasterPos4i")));
  if (glow_glRasterPos4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4i\n");
#endif
  }
  glow_glRasterPos4i(x, y, z, w);
}
PFNGLRASTERPOS4IPROC glow_glRasterPos4i = glow_lazy_glRasterPos4i;
static void glow_lazy_glVertex2dv(const GLdouble *v) {
  glow_glVertex2dv = (PFNGLVERTEX2DVPROC)((ptrdiff_t)(glow_get_proc("glVertex2dv")));
  if (glow_glVertex2dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2dv\n");
#endif
  }
  glow_glVertex2dv(v);
}
PFNGLVERTEX2DVPROC glow_glVertex2dv = glow_lazy_glVertex2dv;
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
static void glow_lazy_glBegin(GLenum mode) {
  glow_glBegin = (PFNGLBEGINPROC)((ptrdiff_t)(glow_get_proc("glBegin")));
  if (glow_glBegin == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBegin\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBegin\n");
#endif
  }
  glow_glBegin(mode);
}
PFNGLBEGINPROC glow_glBegin = glow_lazy_glBegin;
static void glow_lazy_glRectsv(const GLshort *v1, const GLshort *v2) {
  glow_glRectsv = (PFNGLRECTSVPROC)((ptrdiff_t)(glow_get_proc("glRectsv")));
  if (glow_glRectsv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectsv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectsv\n");
#endif
  }
  glow_glRectsv(v1, v2);
}
PFNGLRECTSVPROC glow_glRectsv = glow_lazy_glRectsv;
static void glow_lazy_glEvalCoord1fv(const GLfloat *u) {
  glow_glEvalCoord1fv = (PFNGLEVALCOORD1FVPROC)((ptrdiff_t)(glow_get_proc("glEvalCoord1fv")));
  if (glow_glEvalCoord1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord1fv\n");
#endif
  }
  glow_glEvalCoord1fv(u);
}
PFNGLEVALCOORD1FVPROC glow_glEvalCoord1fv = glow_lazy_glEvalCoord1fv;
static void glow_lazy_glMultMatrixd(const GLdouble *m) {
  glow_glMultMatrixd = (PFNGLMULTMATRIXDPROC)((ptrdiff_t)(glow_get_proc("glMultMatrixd")));
  if (glow_glMultMatrixd == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMultMatrixd\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMultMatrixd\n");
#endif
  }
  glow_glMultMatrixd(m);
}
PFNGLMULTMATRIXDPROC glow_glMultMatrixd = glow_lazy_glMultMatrixd;
static void glow_lazy_glNormal3bv(const GLbyte *v) {
  glow_glNormal3bv = (PFNGLNORMAL3BVPROC)((ptrdiff_t)(glow_get_proc("glNormal3bv")));
  if (glow_glNormal3bv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3bv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3bv\n");
#endif
  }
  glow_glNormal3bv(v);
}
PFNGLNORMAL3BVPROC glow_glNormal3bv = glow_lazy_glNormal3bv;
static void glow_lazy_glVertex2i(GLint x, GLint y) {
  glow_glVertex2i = (PFNGLVERTEX2IPROC)((ptrdiff_t)(glow_get_proc("glVertex2i")));
  if (glow_glVertex2i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2i\n");
#endif
  }
  glow_glVertex2i(x, y);
}
PFNGLVERTEX2IPROC glow_glVertex2i = glow_lazy_glVertex2i;
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
static void glow_lazy_glDeleteLists(GLuint list, GLsizei range) {
  glow_glDeleteLists = (PFNGLDELETELISTSPROC)((ptrdiff_t)(glow_get_proc("glDeleteLists")));
  if (glow_glDeleteLists == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteLists\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteLists\n");
#endif
  }
  glow_glDeleteLists(list, range);
}
PFNGLDELETELISTSPROC glow_glDeleteLists = glow_lazy_glDeleteLists;
static void glow_lazy_glColor3iv(const GLint *v) {
  glow_glColor3iv = (PFNGLCOLOR3IVPROC)((ptrdiff_t)(glow_get_proc("glColor3iv")));
  if (glow_glColor3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3iv\n");
#endif
  }
  glow_glColor3iv(v);
}
PFNGLCOLOR3IVPROC glow_glColor3iv = glow_lazy_glColor3iv;
static void glow_lazy_glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
  glow_glColor4us = (PFNGLCOLOR4USPROC)((ptrdiff_t)(glow_get_proc("glColor4us")));
  if (glow_glColor4us == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4us\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4us\n");
#endif
  }
  glow_glColor4us(red, green, blue, alpha);
}
PFNGLCOLOR4USPROC glow_glColor4us = glow_lazy_glColor4us;
static void glow_lazy_glSelectBuffer(GLsizei size, GLuint *buffer) {
  glow_glSelectBuffer = (PFNGLSELECTBUFFERPROC)((ptrdiff_t)(glow_get_proc("glSelectBuffer")));
  if (glow_glSelectBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSelectBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSelectBuffer\n");
#endif
  }
  glow_glSelectBuffer(size, buffer);
}
PFNGLSELECTBUFFERPROC glow_glSelectBuffer = glow_lazy_glSelectBuffer;
static void glow_lazy_glRasterPos2iv(const GLint *v) {
  glow_glRasterPos2iv = (PFNGLRASTERPOS2IVPROC)((ptrdiff_t)(glow_get_proc("glRasterPos2iv")));
  if (glow_glRasterPos2iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2iv\n");
#endif
  }
  glow_glRasterPos2iv(v);
}
PFNGLRASTERPOS2IVPROC glow_glRasterPos2iv = glow_lazy_glRasterPos2iv;
static void glow_lazy_glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
  glow_glRasterPos4s = (PFNGLRASTERPOS4SPROC)((ptrdiff_t)(glow_get_proc("glRasterPos4s")));
  if (glow_glRasterPos4s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4s\n");
#endif
  }
  glow_glRasterPos4s(x, y, z, w);
}
PFNGLRASTERPOS4SPROC glow_glRasterPos4s = glow_lazy_glRasterPos4s;
static void glow_lazy_glVertex4fv(const GLfloat *v) {
  glow_glVertex4fv = (PFNGLVERTEX4FVPROC)((ptrdiff_t)(glow_get_proc("glVertex4fv")));
  if (glow_glVertex4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4fv\n");
#endif
  }
  glow_glVertex4fv(v);
}
PFNGLVERTEX4FVPROC glow_glVertex4fv = glow_lazy_glVertex4fv;
static void glow_lazy_glVertex4iv(const GLint *v) {
  glow_glVertex4iv = (PFNGLVERTEX4IVPROC)((ptrdiff_t)(glow_get_proc("glVertex4iv")));
  if (glow_glVertex4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4iv\n");
#endif
  }
  glow_glVertex4iv(v);
}
PFNGLVERTEX4IVPROC glow_glVertex4iv = glow_lazy_glVertex4iv;
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
static void glow_lazy_glDepthRange(GLdouble near, GLdouble far) {
  glow_glDepthRange = (PFNGLDEPTHRANGEPROC)((ptrdiff_t)(glow_get_proc("glDepthRange")));
  if (glow_glDepthRange == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthRange\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthRange\n");
#endif
  }
  glow_glDepthRange(near, far);
}
PFNGLDEPTHRANGEPROC glow_glDepthRange = glow_lazy_glDepthRange;
static void glow_lazy_glIndexiv(const GLint *c) {
  glow_glIndexiv = (PFNGLINDEXIVPROC)((ptrdiff_t)(glow_get_proc("glIndexiv")));
  if (glow_glIndexiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexiv\n");
#endif
  }
  glow_glIndexiv(c);
}
PFNGLINDEXIVPROC glow_glIndexiv = glow_lazy_glIndexiv;
static void glow_lazy_glEndList() {
  glow_glEndList = (PFNGLENDLISTPROC)((ptrdiff_t)(glow_get_proc("glEndList")));
  if (glow_glEndList == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEndList\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEndList\n");
#endif
  }
  glow_glEndList();
}
PFNGLENDLISTPROC glow_glEndList = glow_lazy_glEndList;
static void glow_lazy_glRasterPos2s(GLshort x, GLshort y) {
  glow_glRasterPos2s = (PFNGLRASTERPOS2SPROC)((ptrdiff_t)(glow_get_proc("glRasterPos2s")));
  if (glow_glRasterPos2s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2s\n");
#endif
  }
  glow_glRasterPos2s(x, y);
}
PFNGLRASTERPOS2SPROC glow_glRasterPos2s = glow_lazy_glRasterPos2s;
static void glow_lazy_glTexCoord3iv(const GLint *v) {
  glow_glTexCoord3iv = (PFNGLTEXCOORD3IVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord3iv")));
  if (glow_glTexCoord3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3iv\n");
#endif
  }
  glow_glTexCoord3iv(v);
}
PFNGLTEXCOORD3IVPROC glow_glTexCoord3iv = glow_lazy_glTexCoord3iv;
static void glow_lazy_glEvalPoint2(GLint i, GLint j) {
  glow_glEvalPoint2 = (PFNGLEVALPOINT2PROC)((ptrdiff_t)(glow_get_proc("glEvalPoint2")));
  if (glow_glEvalPoint2 == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalPoint2\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalPoint2\n");
#endif
  }
  glow_glEvalPoint2(i, j);
}
PFNGLEVALPOINT2PROC glow_glEvalPoint2 = glow_lazy_glEvalPoint2;
static void glow_lazy_glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
  glow_glTexGenf = (PFNGLTEXGENFPROC)((ptrdiff_t)(glow_get_proc("glTexGenf")));
  if (glow_glTexGenf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGenf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGenf\n");
#endif
  }
  glow_glTexGenf(coord, pname, param);
}
PFNGLTEXGENFPROC glow_glTexGenf = glow_lazy_glTexGenf;
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
static void glow_lazy_glGetDoublev(GLenum pname, GLdouble *data) {
  glow_glGetDoublev = (PFNGLGETDOUBLEVPROC)((ptrdiff_t)(glow_get_proc("glGetDoublev")));
  if (glow_glGetDoublev == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetDoublev\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetDoublev\n");
#endif
  }
  glow_glGetDoublev(pname, data);
}
PFNGLGETDOUBLEVPROC glow_glGetDoublev = glow_lazy_glGetDoublev;
static void glow_lazy_glNewList(GLuint list, GLenum mode) {
  glow_glNewList = (PFNGLNEWLISTPROC)((ptrdiff_t)(glow_get_proc("glNewList")));
  if (glow_glNewList == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNewList\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNewList\n");
#endif
  }
  glow_glNewList(list, mode);
}
PFNGLNEWLISTPROC glow_glNewList = glow_lazy_glNewList;
static void glow_lazy_glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
  glow_glRects = (PFNGLRECTSPROC)((ptrdiff_t)(glow_get_proc("glRects")));
  if (glow_glRects == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRects\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRects\n");
#endif
  }
  glow_glRects(x1, y1, x2, y2);
}
PFNGLRECTSPROC glow_glRects = glow_lazy_glRects;
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
static void glow_lazy_glLightModeliv(GLenum pname, const GLint *params) {
  glow_glLightModeliv = (PFNGLLIGHTMODELIVPROC)((ptrdiff_t)(glow_get_proc("glLightModeliv")));
  if (glow_glLightModeliv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModeliv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModeliv\n");
#endif
  }
  glow_glLightModeliv(pname, params);
}
PFNGLLIGHTMODELIVPROC glow_glLightModeliv = glow_lazy_glLightModeliv;
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
static void glow_lazy_glTexCoord1iv(const GLint *v) {
  glow_glTexCoord1iv = (PFNGLTEXCOORD1IVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord1iv")));
  if (glow_glTexCoord1iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1iv\n");
#endif
  }
  glow_glTexCoord1iv(v);
}
PFNGLTEXCOORD1IVPROC glow_glTexCoord1iv = glow_lazy_glTexCoord1iv;
static void glow_lazy_glVertex3sv(const GLshort *v) {
  glow_glVertex3sv = (PFNGLVERTEX3SVPROC)((ptrdiff_t)(glow_get_proc("glVertex3sv")));
  if (glow_glVertex3sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3sv\n");
#endif
  }
  glow_glVertex3sv(v);
}
PFNGLVERTEX3SVPROC glow_glVertex3sv = glow_lazy_glVertex3sv;
static void glow_lazy_glRasterPos2d(GLdouble x, GLdouble y) {
  glow_glRasterPos2d = (PFNGLRASTERPOS2DPROC)((ptrdiff_t)(glow_get_proc("glRasterPos2d")));
  if (glow_glRasterPos2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2d\n");
#endif
  }
  glow_glRasterPos2d(x, y);
}
PFNGLRASTERPOS2DPROC glow_glRasterPos2d = glow_lazy_glRasterPos2d;
static void glow_lazy_glFogiv(GLenum pname, const GLint *params) {
  glow_glFogiv = (PFNGLFOGIVPROC)((ptrdiff_t)(glow_get_proc("glFogiv")));
  if (glow_glFogiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogiv\n");
#endif
  }
  glow_glFogiv(pname, params);
}
PFNGLFOGIVPROC glow_glFogiv = glow_lazy_glFogiv;
static void glow_lazy_glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) {
  glow_glTexGendv = (PFNGLTEXGENDVPROC)((ptrdiff_t)(glow_get_proc("glTexGendv")));
  if (glow_glTexGendv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGendv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGendv\n");
#endif
  }
  glow_glTexGendv(coord, pname, params);
}
PFNGLTEXGENDVPROC glow_glTexGendv = glow_lazy_glTexGendv;
static void glow_lazy_glColorMaterial(GLenum face, GLenum mode) {
  glow_glColorMaterial = (PFNGLCOLORMATERIALPROC)((ptrdiff_t)(glow_get_proc("glColorMaterial")));
  if (glow_glColorMaterial == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColorMaterial\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColorMaterial\n");
#endif
  }
  glow_glColorMaterial(face, mode);
}
PFNGLCOLORMATERIALPROC glow_glColorMaterial = glow_lazy_glColorMaterial;
static void glow_lazy_glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
  glow_glEvalMesh2 = (PFNGLEVALMESH2PROC)((ptrdiff_t)(glow_get_proc("glEvalMesh2")));
  if (glow_glEvalMesh2 == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalMesh2\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalMesh2\n");
#endif
  }
  glow_glEvalMesh2(mode, i1, i2, j1, j2);
}
PFNGLEVALMESH2PROC glow_glEvalMesh2 = glow_lazy_glEvalMesh2;
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
static void glow_lazy_glRectdv(const GLdouble *v1, const GLdouble *v2) {
  glow_glRectdv = (PFNGLRECTDVPROC)((ptrdiff_t)(glow_get_proc("glRectdv")));
  if (glow_glRectdv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectdv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectdv\n");
#endif
  }
  glow_glRectdv(v1, v2);
}
PFNGLRECTDVPROC glow_glRectdv = glow_lazy_glRectdv;
static void glow_lazy_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
  glow_glTexCoord3f = (PFNGLTEXCOORD3FPROC)((ptrdiff_t)(glow_get_proc("glTexCoord3f")));
  if (glow_glTexCoord3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3f\n");
#endif
  }
  glow_glTexCoord3f(s, t, r);
}
PFNGLTEXCOORD3FPROC glow_glTexCoord3f = glow_lazy_glTexCoord3f;
static void glow_lazy_glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
  glow_glVertex3d = (PFNGLVERTEX3DPROC)((ptrdiff_t)(glow_get_proc("glVertex3d")));
  if (glow_glVertex3d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3d\n");
#endif
  }
  glow_glVertex3d(x, y, z);
}
PFNGLVERTEX3DPROC glow_glVertex3d = glow_lazy_glVertex3d;
static void glow_lazy_glVertex4sv(const GLshort *v) {
  glow_glVertex4sv = (PFNGLVERTEX4SVPROC)((ptrdiff_t)(glow_get_proc("glVertex4sv")));
  if (glow_glVertex4sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4sv\n");
#endif
  }
  glow_glVertex4sv(v);
}
PFNGLVERTEX4SVPROC glow_glVertex4sv = glow_lazy_glVertex4sv;
static void glow_lazy_glScaled(GLdouble x, GLdouble y, GLdouble z) {
  glow_glScaled = (PFNGLSCALEDPROC)((ptrdiff_t)(glow_get_proc("glScaled")));
  if (glow_glScaled == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glScaled\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glScaled\n");
#endif
  }
  glow_glScaled(x, y, z);
}
PFNGLSCALEDPROC glow_glScaled = glow_lazy_glScaled;
static void glow_lazy_glIndexd(GLdouble c) {
  glow_glIndexd = (PFNGLINDEXDPROC)((ptrdiff_t)(glow_get_proc("glIndexd")));
  if (glow_glIndexd == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexd\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexd\n");
#endif
  }
  glow_glIndexd(c);
}
PFNGLINDEXDPROC glow_glIndexd = glow_lazy_glIndexd;
static void glow_lazy_glRasterPos3s(GLshort x, GLshort y, GLshort z) {
  glow_glRasterPos3s = (PFNGLRASTERPOS3SPROC)((ptrdiff_t)(glow_get_proc("glRasterPos3s")));
  if (glow_glRasterPos3s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3s\n");
#endif
  }
  glow_glRasterPos3s(x, y, z);
}
PFNGLRASTERPOS3SPROC glow_glRasterPos3s = glow_lazy_glRasterPos3s;
static void glow_lazy_glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
  glow_glRectd = (PFNGLRECTDPROC)((ptrdiff_t)(glow_get_proc("glRectd")));
  if (glow_glRectd == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectd\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectd\n");
#endif
  }
  glow_glRectd(x1, y1, x2, y2);
}
PFNGLRECTDPROC glow_glRectd = glow_lazy_glRectd;
static void glow_lazy_glTexCoord4fv(const GLfloat *v) {
  glow_glTexCoord4fv = (PFNGLTEXCOORD4FVPROC)((ptrdiff_t)(glow_get_proc("glTexCoord4fv")));
  if (glow_glTexCoord4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4fv\n");
#endif
  }
  glow_glTexCoord4fv(v);
}
PFNGLTEXCOORD4FVPROC glow_glTexCoord4fv = glow_lazy_glTexCoord4fv;


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

static void glow_debug_impl_glGetLightiv(GLenum light, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetLightiv", (void*)(ptrdiff_t)glow_glGetLightiv, light, pname, params);
  glow_glGetLightiv(light, pname, params);
  glow_post_callback_("glGetLightiv", (void*)(ptrdiff_t)glow_glGetLightiv, light, pname, params);
}
PFNGLGETLIGHTIVPROC glow_debug_glGetLightiv = glow_debug_impl_glGetLightiv;

static void glow_debug_impl_glLineWidth(GLfloat width) {

  glow_pre_callback_("glLineWidth", (void*)(ptrdiff_t)glow_glLineWidth, width);
  glow_glLineWidth(width);
  glow_post_callback_("glLineWidth", (void*)(ptrdiff_t)glow_glLineWidth, width);
}
PFNGLLINEWIDTHPROC glow_debug_glLineWidth = glow_debug_impl_glLineWidth;

static void glow_debug_impl_glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {

  glow_pre_callback_("glRasterPos3d", (void*)(ptrdiff_t)glow_glRasterPos3d, x, y, z);
  glow_glRasterPos3d(x, y, z);
  glow_post_callback_("glRasterPos3d", (void*)(ptrdiff_t)glow_glRasterPos3d, x, y, z);
}
PFNGLRASTERPOS3DPROC glow_debug_glRasterPos3d = glow_debug_impl_glRasterPos3d;

static void glow_debug_impl_glLightiv(GLenum light, GLenum pname, const GLint *params) {

  glow_pre_callback_("glLightiv", (void*)(ptrdiff_t)glow_glLightiv, light, pname, params);
  glow_glLightiv(light, pname, params);
  glow_post_callback_("glLightiv", (void*)(ptrdiff_t)glow_glLightiv, light, pname, params);
}
PFNGLLIGHTIVPROC glow_debug_glLightiv = glow_debug_impl_glLightiv;

static void glow_debug_impl_glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values) {

  glow_pre_callback_("glPixelMapfv", (void*)(ptrdiff_t)glow_glPixelMapfv, map, mapsize, values);
  glow_glPixelMapfv(map, mapsize, values);
  glow_post_callback_("glPixelMapfv", (void*)(ptrdiff_t)glow_glPixelMapfv, map, mapsize, values);
}
PFNGLPIXELMAPFVPROC glow_debug_glPixelMapfv = glow_debug_impl_glPixelMapfv;

static void glow_debug_impl_glScalef(GLfloat x, GLfloat y, GLfloat z) {

  glow_pre_callback_("glScalef", (void*)(ptrdiff_t)glow_glScalef, x, y, z);
  glow_glScalef(x, y, z);
  glow_post_callback_("glScalef", (void*)(ptrdiff_t)glow_glScalef, x, y, z);
}
PFNGLSCALEFPROC glow_debug_glScalef = glow_debug_impl_glScalef;

static void glow_debug_impl_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) {

  glow_pre_callback_("glReadPixels", (void*)(ptrdiff_t)glow_glReadPixels, x, y, width, height, format, type, pixels);
  glow_glReadPixels(x, y, width, height, format, type, pixels);
  glow_post_callback_("glReadPixels", (void*)(ptrdiff_t)glow_glReadPixels, x, y, width, height, format, type, pixels);
}
PFNGLREADPIXELSPROC glow_debug_glReadPixels = glow_debug_impl_glReadPixels;

static void glow_debug_impl_glGetIntegerv(GLenum pname, GLint *data) {

  glow_pre_callback_("glGetIntegerv", (void*)(ptrdiff_t)glow_glGetIntegerv, pname, data);
  glow_glGetIntegerv(pname, data);
  glow_post_callback_("glGetIntegerv", (void*)(ptrdiff_t)glow_glGetIntegerv, pname, data);
}
PFNGLGETINTEGERVPROC glow_debug_glGetIntegerv = glow_debug_impl_glGetIntegerv;

static void glow_debug_impl_glRasterPos3iv(const GLint *v) {

  glow_pre_callback_("glRasterPos3iv", (void*)(ptrdiff_t)glow_glRasterPos3iv, v);
  glow_glRasterPos3iv(v);
  glow_post_callback_("glRasterPos3iv", (void*)(ptrdiff_t)glow_glRasterPos3iv, v);
}
PFNGLRASTERPOS3IVPROC glow_debug_glRasterPos3iv = glow_debug_impl_glRasterPos3iv;

static void glow_debug_impl_glRasterPos4sv(const GLshort *v) {

  glow_pre_callback_("glRasterPos4sv", (void*)(ptrdiff_t)glow_glRasterPos4sv, v);
  glow_glRasterPos4sv(v);
  glow_post_callback_("glRasterPos4sv", (void*)(ptrdiff_t)glow_glRasterPos4sv, v);
}
PFNGLRASTERPOS4SVPROC glow_debug_glRasterPos4sv = glow_debug_impl_glRasterPos4sv;

static void glow_debug_impl_glTexCoord4dv(const GLdouble *v) {

  glow_pre_callback_("glTexCoord4dv", (void*)(ptrdiff_t)glow_glTexCoord4dv, v);
  glow_glTexCoord4dv(v);
  glow_post_callback_("glTexCoord4dv", (void*)(ptrdiff_t)glow_glTexCoord4dv, v);
}
PFNGLTEXCOORD4DVPROC glow_debug_glTexCoord4dv = glow_debug_impl_glTexCoord4dv;

static void glow_debug_impl_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {

  glow_pre_callback_("glTexCoord4f", (void*)(ptrdiff_t)glow_glTexCoord4f, s, t, r, q);
  glow_glTexCoord4f(s, t, r, q);
  glow_post_callback_("glTexCoord4f", (void*)(ptrdiff_t)glow_glTexCoord4f, s, t, r, q);
}
PFNGLTEXCOORD4FPROC glow_debug_glTexCoord4f = glow_debug_impl_glTexCoord4f;

static void glow_debug_impl_glVertex3s(GLshort x, GLshort y, GLshort z) {

  glow_pre_callback_("glVertex3s", (void*)(ptrdiff_t)glow_glVertex3s, x, y, z);
  glow_glVertex3s(x, y, z);
  glow_post_callback_("glVertex3s", (void*)(ptrdiff_t)glow_glVertex3s, x, y, z);
}
PFNGLVERTEX3SPROC glow_debug_glVertex3s = glow_debug_impl_glVertex3s;

static void glow_debug_impl_glGetPolygonStipple(GLubyte *mask) {

  glow_pre_callback_("glGetPolygonStipple", (void*)(ptrdiff_t)glow_glGetPolygonStipple, mask);
  glow_glGetPolygonStipple(mask);
  glow_post_callback_("glGetPolygonStipple", (void*)(ptrdiff_t)glow_glGetPolygonStipple, mask);
}
PFNGLGETPOLYGONSTIPPLEPROC glow_debug_glGetPolygonStipple = glow_debug_impl_glGetPolygonStipple;

static void glow_debug_impl_glTexParameteri(GLenum target, GLenum pname, GLint param) {

  glow_pre_callback_("glTexParameteri", (void*)(ptrdiff_t)glow_glTexParameteri, target, pname, param);
  glow_glTexParameteri(target, pname, param);
  glow_post_callback_("glTexParameteri", (void*)(ptrdiff_t)glow_glTexParameteri, target, pname, param);
}
PFNGLTEXPARAMETERIPROC glow_debug_glTexParameteri = glow_debug_impl_glTexParameteri;

static void glow_debug_impl_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glTexImage2D", (void*)(ptrdiff_t)glow_glTexImage2D, target, level, internalformat, width, height, border, format, type, pixels);
  glow_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
  glow_post_callback_("glTexImage2D", (void*)(ptrdiff_t)glow_glTexImage2D, target, level, internalformat, width, height, border, format, type, pixels);
}
PFNGLTEXIMAGE2DPROC glow_debug_glTexImage2D = glow_debug_impl_glTexImage2D;

static void glow_debug_impl_glRasterPos2dv(const GLdouble *v) {

  glow_pre_callback_("glRasterPos2dv", (void*)(ptrdiff_t)glow_glRasterPos2dv, v);
  glow_glRasterPos2dv(v);
  glow_post_callback_("glRasterPos2dv", (void*)(ptrdiff_t)glow_glRasterPos2dv, v);
}
PFNGLRASTERPOS2DVPROC glow_debug_glRasterPos2dv = glow_debug_impl_glRasterPos2dv;

static void glow_debug_impl_glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {

  glow_pre_callback_("glTexCoord3d", (void*)(ptrdiff_t)glow_glTexCoord3d, s, t, r);
  glow_glTexCoord3d(s, t, r);
  glow_post_callback_("glTexCoord3d", (void*)(ptrdiff_t)glow_glTexCoord3d, s, t, r);
}
PFNGLTEXCOORD3DPROC glow_debug_glTexCoord3d = glow_debug_impl_glTexCoord3d;

static void glow_debug_impl_glLogicOp(GLenum opcode) {

  glow_pre_callback_("glLogicOp", (void*)(ptrdiff_t)glow_glLogicOp, opcode);
  glow_glLogicOp(opcode);
  glow_post_callback_("glLogicOp", (void*)(ptrdiff_t)glow_glLogicOp, opcode);
}
PFNGLLOGICOPPROC glow_debug_glLogicOp = glow_debug_impl_glLogicOp;

static void glow_debug_impl_glReadBuffer(GLenum src) {

  glow_pre_callback_("glReadBuffer", (void*)(ptrdiff_t)glow_glReadBuffer, src);
  glow_glReadBuffer(src);
  glow_post_callback_("glReadBuffer", (void*)(ptrdiff_t)glow_glReadBuffer, src);
}
PFNGLREADBUFFERPROC glow_debug_glReadBuffer = glow_debug_impl_glReadBuffer;

static void glow_debug_impl_glRasterPos2f(GLfloat x, GLfloat y) {

  glow_pre_callback_("glRasterPos2f", (void*)(ptrdiff_t)glow_glRasterPos2f, x, y);
  glow_glRasterPos2f(x, y);
  glow_post_callback_("glRasterPos2f", (void*)(ptrdiff_t)glow_glRasterPos2f, x, y);
}
PFNGLRASTERPOS2FPROC glow_debug_glRasterPos2f = glow_debug_impl_glRasterPos2f;

static void glow_debug_impl_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glMaterialfv", (void*)(ptrdiff_t)glow_glMaterialfv, face, pname, params);
  glow_glMaterialfv(face, pname, params);
  glow_post_callback_("glMaterialfv", (void*)(ptrdiff_t)glow_glMaterialfv, face, pname, params);
}
PFNGLMATERIALFVPROC glow_debug_glMaterialfv = glow_debug_impl_glMaterialfv;

static void glow_debug_impl_glLoadMatrixd(const GLdouble *m) {

  glow_pre_callback_("glLoadMatrixd", (void*)(ptrdiff_t)glow_glLoadMatrixd, m);
  glow_glLoadMatrixd(m);
  glow_post_callback_("glLoadMatrixd", (void*)(ptrdiff_t)glow_glLoadMatrixd, m);
}
PFNGLLOADMATRIXDPROC glow_debug_glLoadMatrixd = glow_debug_impl_glLoadMatrixd;

static void glow_debug_impl_glTranslatef(GLfloat x, GLfloat y, GLfloat z) {

  glow_pre_callback_("glTranslatef", (void*)(ptrdiff_t)glow_glTranslatef, x, y, z);
  glow_glTranslatef(x, y, z);
  glow_post_callback_("glTranslatef", (void*)(ptrdiff_t)glow_glTranslatef, x, y, z);
}
PFNGLTRANSLATEFPROC glow_debug_glTranslatef = glow_debug_impl_glTranslatef;

static void glow_debug_impl_glFlush() {

  glow_pre_callback_("glFlush", (void*)(ptrdiff_t)glow_glFlush);
  glow_glFlush();
  glow_post_callback_("glFlush", (void*)(ptrdiff_t)glow_glFlush);
}
PFNGLFLUSHPROC glow_debug_glFlush = glow_debug_impl_glFlush;

static void glow_debug_impl_glColor3bv(const GLbyte *v) {

  glow_pre_callback_("glColor3bv", (void*)(ptrdiff_t)glow_glColor3bv, v);
  glow_glColor3bv(v);
  glow_post_callback_("glColor3bv", (void*)(ptrdiff_t)glow_glColor3bv, v);
}
PFNGLCOLOR3BVPROC glow_debug_glColor3bv = glow_debug_impl_glColor3bv;

static void glow_debug_impl_glColor4uiv(const GLuint *v) {

  glow_pre_callback_("glColor4uiv", (void*)(ptrdiff_t)glow_glColor4uiv, v);
  glow_glColor4uiv(v);
  glow_post_callback_("glColor4uiv", (void*)(ptrdiff_t)glow_glColor4uiv, v);
}
PFNGLCOLOR4UIVPROC glow_debug_glColor4uiv = glow_debug_impl_glColor4uiv;

static void glow_debug_impl_glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {

  glow_pre_callback_("glRasterPos4d", (void*)(ptrdiff_t)glow_glRasterPos4d, x, y, z, w);
  glow_glRasterPos4d(x, y, z, w);
  glow_post_callback_("glRasterPos4d", (void*)(ptrdiff_t)glow_glRasterPos4d, x, y, z, w);
}
PFNGLRASTERPOS4DPROC glow_debug_glRasterPos4d = glow_debug_impl_glRasterPos4d;

static void glow_debug_impl_glTexParameteriv(GLenum target, GLenum pname, const GLint *params) {

  glow_pre_callback_("glTexParameteriv", (void*)(ptrdiff_t)glow_glTexParameteriv, target, pname, params);
  glow_glTexParameteriv(target, pname, params);
  glow_post_callback_("glTexParameteriv", (void*)(ptrdiff_t)glow_glTexParameteriv, target, pname, params);
}
PFNGLTEXPARAMETERIVPROC glow_debug_glTexParameteriv = glow_debug_impl_glTexParameteriv;

static void glow_debug_impl_glColor4sv(const GLshort *v) {

  glow_pre_callback_("glColor4sv", (void*)(ptrdiff_t)glow_glColor4sv, v);
  glow_glColor4sv(v);
  glow_post_callback_("glColor4sv", (void*)(ptrdiff_t)glow_glColor4sv, v);
}
PFNGLCOLOR4SVPROC glow_debug_glColor4sv = glow_debug_impl_glColor4sv;

static void glow_debug_impl_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetTexEnvfv", (void*)(ptrdiff_t)glow_glGetTexEnvfv, target, pname, params);
  glow_glGetTexEnvfv(target, pname, params);
  glow_post_callback_("glGetTexEnvfv", (void*)(ptrdiff_t)glow_glGetTexEnvfv, target, pname, params);
}
PFNGLGETTEXENVFVPROC glow_debug_glGetTexEnvfv = glow_debug_impl_glGetTexEnvfv;

static void glow_debug_impl_glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {

  glow_pre_callback_("glRectf", (void*)(ptrdiff_t)glow_glRectf, x1, y1, x2, y2);
  glow_glRectf(x1, y1, x2, y2);
  glow_post_callback_("glRectf", (void*)(ptrdiff_t)glow_glRectf, x1, y1, x2, y2);
}
PFNGLRECTFPROC glow_debug_glRectf = glow_debug_impl_glRectf;

static void glow_debug_impl_glShadeModel(GLenum mode) {

  glow_pre_callback_("glShadeModel", (void*)(ptrdiff_t)glow_glShadeModel, mode);
  glow_glShadeModel(mode);
  glow_post_callback_("glShadeModel", (void*)(ptrdiff_t)glow_glShadeModel, mode);
}
PFNGLSHADEMODELPROC glow_debug_glShadeModel = glow_debug_impl_glShadeModel;

static void glow_debug_impl_glLoadMatrixf(const GLfloat *m) {

  glow_pre_callback_("glLoadMatrixf", (void*)(ptrdiff_t)glow_glLoadMatrixf, m);
  glow_glLoadMatrixf(m);
  glow_post_callback_("glLoadMatrixf", (void*)(ptrdiff_t)glow_glLoadMatrixf, m);
}
PFNGLLOADMATRIXFPROC glow_debug_glLoadMatrixf = glow_debug_impl_glLoadMatrixf;

static void glow_debug_impl_glListBase(GLuint base) {

  glow_pre_callback_("glListBase", (void*)(ptrdiff_t)glow_glListBase, base);
  glow_glListBase(base);
  glow_post_callback_("glListBase", (void*)(ptrdiff_t)glow_glListBase, base);
}
PFNGLLISTBASEPROC glow_debug_glListBase = glow_debug_impl_glListBase;

static void glow_debug_impl_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {

  glow_pre_callback_("glColor4ub", (void*)(ptrdiff_t)glow_glColor4ub, red, green, blue, alpha);
  glow_glColor4ub(red, green, blue, alpha);
  glow_post_callback_("glColor4ub", (void*)(ptrdiff_t)glow_glColor4ub, red, green, blue, alpha);
}
PFNGLCOLOR4UBPROC glow_debug_glColor4ub = glow_debug_impl_glColor4ub;

static void glow_debug_impl_glIndexf(GLfloat c) {

  glow_pre_callback_("glIndexf", (void*)(ptrdiff_t)glow_glIndexf, c);
  glow_glIndexf(c);
  glow_post_callback_("glIndexf", (void*)(ptrdiff_t)glow_glIndexf, c);
}
PFNGLINDEXFPROC glow_debug_glIndexf = glow_debug_impl_glIndexf;

static void glow_debug_impl_glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {

  glow_pre_callback_("glRasterPos3f", (void*)(ptrdiff_t)glow_glRasterPos3f, x, y, z);
  glow_glRasterPos3f(x, y, z);
  glow_post_callback_("glRasterPos3f", (void*)(ptrdiff_t)glow_glRasterPos3f, x, y, z);
}
PFNGLRASTERPOS3FPROC glow_debug_glRasterPos3f = glow_debug_impl_glRasterPos3f;

static void glow_debug_impl_glEvalPoint1(GLint i) {

  glow_pre_callback_("glEvalPoint1", (void*)(ptrdiff_t)glow_glEvalPoint1, i);
  glow_glEvalPoint1(i);
  glow_post_callback_("glEvalPoint1", (void*)(ptrdiff_t)glow_glEvalPoint1, i);
}
PFNGLEVALPOINT1PROC glow_debug_glEvalPoint1 = glow_debug_impl_glEvalPoint1;

static void glow_debug_impl_glGetPixelMapusv(GLenum map, GLushort *values) {

  glow_pre_callback_("glGetPixelMapusv", (void*)(ptrdiff_t)glow_glGetPixelMapusv, map, values);
  glow_glGetPixelMapusv(map, values);
  glow_post_callback_("glGetPixelMapusv", (void*)(ptrdiff_t)glow_glGetPixelMapusv, map, values);
}
PFNGLGETPIXELMAPUSVPROC glow_debug_glGetPixelMapusv = glow_debug_impl_glGetPixelMapusv;

static void glow_debug_impl_glGetTexGeniv(GLenum coord, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetTexGeniv", (void*)(ptrdiff_t)glow_glGetTexGeniv, coord, pname, params);
  glow_glGetTexGeniv(coord, pname, params);
  glow_post_callback_("glGetTexGeniv", (void*)(ptrdiff_t)glow_glGetTexGeniv, coord, pname, params);
}
PFNGLGETTEXGENIVPROC glow_debug_glGetTexGeniv = glow_debug_impl_glGetTexGeniv;

static void glow_debug_impl_glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) {

  glow_pre_callback_("glBitmap", (void*)(ptrdiff_t)glow_glBitmap, width, height, xorig, yorig, xmove, ymove, bitmap);
  glow_glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
  glow_post_callback_("glBitmap", (void*)(ptrdiff_t)glow_glBitmap, width, height, xorig, yorig, xmove, ymove, bitmap);
}
PFNGLBITMAPPROC glow_debug_glBitmap = glow_debug_impl_glBitmap;

static void glow_debug_impl_glNormal3i(GLint nx, GLint ny, GLint nz) {

  glow_pre_callback_("glNormal3i", (void*)(ptrdiff_t)glow_glNormal3i, nx, ny, nz);
  glow_glNormal3i(nx, ny, nz);
  glow_post_callback_("glNormal3i", (void*)(ptrdiff_t)glow_glNormal3i, nx, ny, nz);
}
PFNGLNORMAL3IPROC glow_debug_glNormal3i = glow_debug_impl_glNormal3i;

static void glow_debug_impl_glRasterPos3sv(const GLshort *v) {

  glow_pre_callback_("glRasterPos3sv", (void*)(ptrdiff_t)glow_glRasterPos3sv, v);
  glow_glRasterPos3sv(v);
  glow_post_callback_("glRasterPos3sv", (void*)(ptrdiff_t)glow_glRasterPos3sv, v);
}
PFNGLRASTERPOS3SVPROC glow_debug_glRasterPos3sv = glow_debug_impl_glRasterPos3sv;

static void glow_debug_impl_glMaterialiv(GLenum face, GLenum pname, const GLint *params) {

  glow_pre_callback_("glMaterialiv", (void*)(ptrdiff_t)glow_glMaterialiv, face, pname, params);
  glow_glMaterialiv(face, pname, params);
  glow_post_callback_("glMaterialiv", (void*)(ptrdiff_t)glow_glMaterialiv, face, pname, params);
}
PFNGLMATERIALIVPROC glow_debug_glMaterialiv = glow_debug_impl_glMaterialiv;

static GLubyte glow_debug_impl_glGetString(GLenum name) {

  GLubyte ret;
  glow_pre_callback_("glGetString", (void*)(ptrdiff_t)glow_glGetString, name);
  ret = glow_glGetString(name);
  glow_post_callback_("glGetString", (void*)(ptrdiff_t)glow_glGetString, name);
  return ret;
}
PFNGLGETSTRINGPROC glow_debug_glGetString = glow_debug_impl_glGetString;

static void glow_debug_impl_glLoadName(GLuint name) {

  glow_pre_callback_("glLoadName", (void*)(ptrdiff_t)glow_glLoadName, name);
  glow_glLoadName(name);
  glow_post_callback_("glLoadName", (void*)(ptrdiff_t)glow_glLoadName, name);
}
PFNGLLOADNAMEPROC glow_debug_glLoadName = glow_debug_impl_glLoadName;

static void glow_debug_impl_glClearIndex(GLfloat c) {

  glow_pre_callback_("glClearIndex", (void*)(ptrdiff_t)glow_glClearIndex, c);
  glow_glClearIndex(c);
  glow_post_callback_("glClearIndex", (void*)(ptrdiff_t)glow_glClearIndex, c);
}
PFNGLCLEARINDEXPROC glow_debug_glClearIndex = glow_debug_impl_glClearIndex;

static void glow_debug_impl_glClipPlane(GLenum plane, const GLdouble *equation) {

  glow_pre_callback_("glClipPlane", (void*)(ptrdiff_t)glow_glClipPlane, plane, equation);
  glow_glClipPlane(plane, equation);
  glow_post_callback_("glClipPlane", (void*)(ptrdiff_t)glow_glClipPlane, plane, equation);
}
PFNGLCLIPPLANEPROC glow_debug_glClipPlane = glow_debug_impl_glClipPlane;

static void glow_debug_impl_glGetMapiv(GLenum target, GLenum query, GLint *v) {

  glow_pre_callback_("glGetMapiv", (void*)(ptrdiff_t)glow_glGetMapiv, target, query, v);
  glow_glGetMapiv(target, query, v);
  glow_post_callback_("glGetMapiv", (void*)(ptrdiff_t)glow_glGetMapiv, target, query, v);
}
PFNGLGETMAPIVPROC glow_debug_glGetMapiv = glow_debug_impl_glGetMapiv;

static void glow_debug_impl_glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points) {

  glow_pre_callback_("glMap2d", (void*)(ptrdiff_t)glow_glMap2d, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
  glow_glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
  glow_post_callback_("glMap2d", (void*)(ptrdiff_t)glow_glMap2d, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
PFNGLMAP2DPROC glow_debug_glMap2d = glow_debug_impl_glMap2d;

static void glow_debug_impl_glEvalCoord2fv(const GLfloat *u) {

  glow_pre_callback_("glEvalCoord2fv", (void*)(ptrdiff_t)glow_glEvalCoord2fv, u);
  glow_glEvalCoord2fv(u);
  glow_post_callback_("glEvalCoord2fv", (void*)(ptrdiff_t)glow_glEvalCoord2fv, u);
}
PFNGLEVALCOORD2FVPROC glow_debug_glEvalCoord2fv = glow_debug_impl_glEvalCoord2fv;

static void glow_debug_impl_glGetTexEnviv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetTexEnviv", (void*)(ptrdiff_t)glow_glGetTexEnviv, target, pname, params);
  glow_glGetTexEnviv(target, pname, params);
  glow_post_callback_("glGetTexEnviv", (void*)(ptrdiff_t)glow_glGetTexEnviv, target, pname, params);
}
PFNGLGETTEXENVIVPROC glow_debug_glGetTexEnviv = glow_debug_impl_glGetTexEnviv;

static void glow_debug_impl_glDisable(GLenum cap) {

  glow_pre_callback_("glDisable", (void*)(ptrdiff_t)glow_glDisable, cap);
  glow_glDisable(cap);
  glow_post_callback_("glDisable", (void*)(ptrdiff_t)glow_glDisable, cap);
}
PFNGLDISABLEPROC glow_debug_glDisable = glow_debug_impl_glDisable;

static void glow_debug_impl_glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {

  glow_pre_callback_("glColor4i", (void*)(ptrdiff_t)glow_glColor4i, red, green, blue, alpha);
  glow_glColor4i(red, green, blue, alpha);
  glow_post_callback_("glColor4i", (void*)(ptrdiff_t)glow_glColor4i, red, green, blue, alpha);
}
PFNGLCOLOR4IPROC glow_debug_glColor4i = glow_debug_impl_glColor4i;

static void glow_debug_impl_glTexCoord3i(GLint s, GLint t, GLint r) {

  glow_pre_callback_("glTexCoord3i", (void*)(ptrdiff_t)glow_glTexCoord3i, s, t, r);
  glow_glTexCoord3i(s, t, r);
  glow_post_callback_("glTexCoord3i", (void*)(ptrdiff_t)glow_glTexCoord3i, s, t, r);
}
PFNGLTEXCOORD3IPROC glow_debug_glTexCoord3i = glow_debug_impl_glTexCoord3i;

static void glow_debug_impl_glPushMatrix() {

  glow_pre_callback_("glPushMatrix", (void*)(ptrdiff_t)glow_glPushMatrix);
  glow_glPushMatrix();
  glow_post_callback_("glPushMatrix", (void*)(ptrdiff_t)glow_glPushMatrix);
}
PFNGLPUSHMATRIXPROC glow_debug_glPushMatrix = glow_debug_impl_glPushMatrix;

static void glow_debug_impl_glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glTexImage1D", (void*)(ptrdiff_t)glow_glTexImage1D, target, level, internalformat, width, border, format, type, pixels);
  glow_glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
  glow_post_callback_("glTexImage1D", (void*)(ptrdiff_t)glow_glTexImage1D, target, level, internalformat, width, border, format, type, pixels);
}
PFNGLTEXIMAGE1DPROC glow_debug_glTexImage1D = glow_debug_impl_glTexImage1D;

static void glow_debug_impl_glTexCoord3s(GLshort s, GLshort t, GLshort r) {

  glow_pre_callback_("glTexCoord3s", (void*)(ptrdiff_t)glow_glTexCoord3s, s, t, r);
  glow_glTexCoord3s(s, t, r);
  glow_post_callback_("glTexCoord3s", (void*)(ptrdiff_t)glow_glTexCoord3s, s, t, r);
}
PFNGLTEXCOORD3SPROC glow_debug_glTexCoord3s = glow_debug_impl_glTexCoord3s;

static void glow_debug_impl_glEvalCoord1f(GLfloat u) {

  glow_pre_callback_("glEvalCoord1f", (void*)(ptrdiff_t)glow_glEvalCoord1f, u);
  glow_glEvalCoord1f(u);
  glow_post_callback_("glEvalCoord1f", (void*)(ptrdiff_t)glow_glEvalCoord1f, u);
}
PFNGLEVALCOORD1FPROC glow_debug_glEvalCoord1f = glow_debug_impl_glEvalCoord1f;

static void glow_debug_impl_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetTexLevelParameteriv", (void*)(ptrdiff_t)glow_glGetTexLevelParameteriv, target, level, pname, params);
  glow_glGetTexLevelParameteriv(target, level, pname, params);
  glow_post_callback_("glGetTexLevelParameteriv", (void*)(ptrdiff_t)glow_glGetTexLevelParameteriv, target, level, pname, params);
}
PFNGLGETTEXLEVELPARAMETERIVPROC glow_debug_glGetTexLevelParameteriv = glow_debug_impl_glGetTexLevelParameteriv;

static void glow_debug_impl_glColor4dv(const GLdouble *v) {

  glow_pre_callback_("glColor4dv", (void*)(ptrdiff_t)glow_glColor4dv, v);
  glow_glColor4dv(v);
  glow_post_callback_("glColor4dv", (void*)(ptrdiff_t)glow_glColor4dv, v);
}
PFNGLCOLOR4DVPROC glow_debug_glColor4dv = glow_debug_impl_glColor4dv;

static void glow_debug_impl_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {

  glow_pre_callback_("glColor4f", (void*)(ptrdiff_t)glow_glColor4f, red, green, blue, alpha);
  glow_glColor4f(red, green, blue, alpha);
  glow_post_callback_("glColor4f", (void*)(ptrdiff_t)glow_glColor4f, red, green, blue, alpha);
}
PFNGLCOLOR4FPROC glow_debug_glColor4f = glow_debug_impl_glColor4f;

static void glow_debug_impl_glEdgeFlagv(const GLboolean *flag) {

  glow_pre_callback_("glEdgeFlagv", (void*)(ptrdiff_t)glow_glEdgeFlagv, flag);
  glow_glEdgeFlagv(flag);
  glow_post_callback_("glEdgeFlagv", (void*)(ptrdiff_t)glow_glEdgeFlagv, flag);
}
PFNGLEDGEFLAGVPROC glow_debug_glEdgeFlagv = glow_debug_impl_glEdgeFlagv;

static void glow_debug_impl_glClearStencil(GLint s) {

  glow_pre_callback_("glClearStencil", (void*)(ptrdiff_t)glow_glClearStencil, s);
  glow_glClearStencil(s);
  glow_post_callback_("glClearStencil", (void*)(ptrdiff_t)glow_glClearStencil, s);
}
PFNGLCLEARSTENCILPROC glow_debug_glClearStencil = glow_debug_impl_glClearStencil;

static void glow_debug_impl_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glTexEnvfv", (void*)(ptrdiff_t)glow_glTexEnvfv, target, pname, params);
  glow_glTexEnvfv(target, pname, params);
  glow_post_callback_("glTexEnvfv", (void*)(ptrdiff_t)glow_glTexEnvfv, target, pname, params);
}
PFNGLTEXENVFVPROC glow_debug_glTexEnvfv = glow_debug_impl_glTexEnvfv;

static void glow_debug_impl_glColor3b(GLbyte red, GLbyte green, GLbyte blue) {

  glow_pre_callback_("glColor3b", (void*)(ptrdiff_t)glow_glColor3b, red, green, blue);
  glow_glColor3b(red, green, blue);
  glow_post_callback_("glColor3b", (void*)(ptrdiff_t)glow_glColor3b, red, green, blue);
}
PFNGLCOLOR3BPROC glow_debug_glColor3b = glow_debug_impl_glColor3b;

static void glow_debug_impl_glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {

  glow_pre_callback_("glColor4d", (void*)(ptrdiff_t)glow_glColor4d, red, green, blue, alpha);
  glow_glColor4d(red, green, blue, alpha);
  glow_post_callback_("glColor4d", (void*)(ptrdiff_t)glow_glColor4d, red, green, blue, alpha);
}
PFNGLCOLOR4DPROC glow_debug_glColor4d = glow_debug_impl_glColor4d;

static void glow_debug_impl_glTexCoord2fv(const GLfloat *v) {

  glow_pre_callback_("glTexCoord2fv", (void*)(ptrdiff_t)glow_glTexCoord2fv, v);
  glow_glTexCoord2fv(v);
  glow_post_callback_("glTexCoord2fv", (void*)(ptrdiff_t)glow_glTexCoord2fv, v);
}
PFNGLTEXCOORD2FVPROC glow_debug_glTexCoord2fv = glow_debug_impl_glTexCoord2fv;

static void glow_debug_impl_glTexEnviv(GLenum target, GLenum pname, const GLint *params) {

  glow_pre_callback_("glTexEnviv", (void*)(ptrdiff_t)glow_glTexEnviv, target, pname, params);
  glow_glTexEnviv(target, pname, params);
  glow_post_callback_("glTexEnviv", (void*)(ptrdiff_t)glow_glTexEnviv, target, pname, params);
}
PFNGLTEXENVIVPROC glow_debug_glTexEnviv = glow_debug_impl_glTexEnviv;

static void glow_debug_impl_glGetClipPlane(GLenum plane, GLdouble *equation) {

  glow_pre_callback_("glGetClipPlane", (void*)(ptrdiff_t)glow_glGetClipPlane, plane, equation);
  glow_glGetClipPlane(plane, equation);
  glow_post_callback_("glGetClipPlane", (void*)(ptrdiff_t)glow_glGetClipPlane, plane, equation);
}
PFNGLGETCLIPPLANEPROC glow_debug_glGetClipPlane = glow_debug_impl_glGetClipPlane;

static void glow_debug_impl_glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {

  glow_pre_callback_("glColor4ui", (void*)(ptrdiff_t)glow_glColor4ui, red, green, blue, alpha);
  glow_glColor4ui(red, green, blue, alpha);
  glow_post_callback_("glColor4ui", (void*)(ptrdiff_t)glow_glColor4ui, red, green, blue, alpha);
}
PFNGLCOLOR4UIPROC glow_debug_glColor4ui = glow_debug_impl_glColor4ui;

static void glow_debug_impl_glTexCoord1fv(const GLfloat *v) {

  glow_pre_callback_("glTexCoord1fv", (void*)(ptrdiff_t)glow_glTexCoord1fv, v);
  glow_glTexCoord1fv(v);
  glow_post_callback_("glTexCoord1fv", (void*)(ptrdiff_t)glow_glTexCoord1fv, v);
}
PFNGLTEXCOORD1FVPROC glow_debug_glTexCoord1fv = glow_debug_impl_glTexCoord1fv;

static void glow_debug_impl_glVertex4i(GLint x, GLint y, GLint z, GLint w) {

  glow_pre_callback_("glVertex4i", (void*)(ptrdiff_t)glow_glVertex4i, x, y, z, w);
  glow_glVertex4i(x, y, z, w);
  glow_post_callback_("glVertex4i", (void*)(ptrdiff_t)glow_glVertex4i, x, y, z, w);
}
PFNGLVERTEX4IPROC glow_debug_glVertex4i = glow_debug_impl_glVertex4i;

static void glow_debug_impl_glLighti(GLenum light, GLenum pname, GLint param) {

  glow_pre_callback_("glLighti", (void*)(ptrdiff_t)glow_glLighti, light, pname, param);
  glow_glLighti(light, pname, param);
  glow_post_callback_("glLighti", (void*)(ptrdiff_t)glow_glLighti, light, pname, param);
}
PFNGLLIGHTIPROC glow_debug_glLighti = glow_debug_impl_glLighti;

static void glow_debug_impl_glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params) {

  glow_pre_callback_("glGetTexGendv", (void*)(ptrdiff_t)glow_glGetTexGendv, coord, pname, params);
  glow_glGetTexGendv(coord, pname, params);
  glow_post_callback_("glGetTexGendv", (void*)(ptrdiff_t)glow_glGetTexGendv, coord, pname, params);
}
PFNGLGETTEXGENDVPROC glow_debug_glGetTexGendv = glow_debug_impl_glGetTexGendv;

static void glow_debug_impl_glColor3us(GLushort red, GLushort green, GLushort blue) {

  glow_pre_callback_("glColor3us", (void*)(ptrdiff_t)glow_glColor3us, red, green, blue);
  glow_glColor3us(red, green, blue);
  glow_post_callback_("glColor3us", (void*)(ptrdiff_t)glow_glColor3us, red, green, blue);
}
PFNGLCOLOR3USPROC glow_debug_glColor3us = glow_debug_impl_glColor3us;

static void glow_debug_impl_glRasterPos4dv(const GLdouble *v) {

  glow_pre_callback_("glRasterPos4dv", (void*)(ptrdiff_t)glow_glRasterPos4dv, v);
  glow_glRasterPos4dv(v);
  glow_post_callback_("glRasterPos4dv", (void*)(ptrdiff_t)glow_glRasterPos4dv, v);
}
PFNGLRASTERPOS4DVPROC glow_debug_glRasterPos4dv = glow_debug_impl_glRasterPos4dv;

static void glow_debug_impl_glRasterPos4iv(const GLint *v) {

  glow_pre_callback_("glRasterPos4iv", (void*)(ptrdiff_t)glow_glRasterPos4iv, v);
  glow_glRasterPos4iv(v);
  glow_post_callback_("glRasterPos4iv", (void*)(ptrdiff_t)glow_glRasterPos4iv, v);
}
PFNGLRASTERPOS4IVPROC glow_debug_glRasterPos4iv = glow_debug_impl_glRasterPos4iv;

static void glow_debug_impl_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {

  glow_pre_callback_("glTexEnvf", (void*)(ptrdiff_t)glow_glTexEnvf, target, pname, param);
  glow_glTexEnvf(target, pname, param);
  glow_post_callback_("glTexEnvf", (void*)(ptrdiff_t)glow_glTexEnvf, target, pname, param);
}
PFNGLTEXENVFPROC glow_debug_glTexEnvf = glow_debug_impl_glTexEnvf;

static void glow_debug_impl_glColor3i(GLint red, GLint green, GLint blue) {

  glow_pre_callback_("glColor3i", (void*)(ptrdiff_t)glow_glColor3i, red, green, blue);
  glow_glColor3i(red, green, blue);
  glow_post_callback_("glColor3i", (void*)(ptrdiff_t)glow_glColor3i, red, green, blue);
}
PFNGLCOLOR3IPROC glow_debug_glColor3i = glow_debug_impl_glColor3i;

static void glow_debug_impl_glPolygonStipple(const GLubyte *mask) {

  glow_pre_callback_("glPolygonStipple", (void*)(ptrdiff_t)glow_glPolygonStipple, mask);
  glow_glPolygonStipple(mask);
  glow_post_callback_("glPolygonStipple", (void*)(ptrdiff_t)glow_glPolygonStipple, mask);
}
PFNGLPOLYGONSTIPPLEPROC glow_debug_glPolygonStipple = glow_debug_impl_glPolygonStipple;

static void glow_debug_impl_glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values) {

  glow_pre_callback_("glPixelMapuiv", (void*)(ptrdiff_t)glow_glPixelMapuiv, map, mapsize, values);
  glow_glPixelMapuiv(map, mapsize, values);
  glow_post_callback_("glPixelMapuiv", (void*)(ptrdiff_t)glow_glPixelMapuiv, map, mapsize, values);
}
PFNGLPIXELMAPUIVPROC glow_debug_glPixelMapuiv = glow_debug_impl_glPixelMapuiv;

static void glow_debug_impl_glMultMatrixf(const GLfloat *m) {

  glow_pre_callback_("glMultMatrixf", (void*)(ptrdiff_t)glow_glMultMatrixf, m);
  glow_glMultMatrixf(m);
  glow_post_callback_("glMultMatrixf", (void*)(ptrdiff_t)glow_glMultMatrixf, m);
}
PFNGLMULTMATRIXFPROC glow_debug_glMultMatrixf = glow_debug_impl_glMultMatrixf;

static void glow_debug_impl_glIndexdv(const GLdouble *c) {

  glow_pre_callback_("glIndexdv", (void*)(ptrdiff_t)glow_glIndexdv, c);
  glow_glIndexdv(c);
  glow_post_callback_("glIndexdv", (void*)(ptrdiff_t)glow_glIndexdv, c);
}
PFNGLINDEXDVPROC glow_debug_glIndexdv = glow_debug_impl_glIndexdv;

static void glow_debug_impl_glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {

  glow_pre_callback_("glTexCoord4s", (void*)(ptrdiff_t)glow_glTexCoord4s, s, t, r, q);
  glow_glTexCoord4s(s, t, r, q);
  glow_post_callback_("glTexCoord4s", (void*)(ptrdiff_t)glow_glTexCoord4s, s, t, r, q);
}
PFNGLTEXCOORD4SPROC glow_debug_glTexCoord4s = glow_debug_impl_glTexCoord4s;

static void glow_debug_impl_glVertex3f(GLfloat x, GLfloat y, GLfloat z) {

  glow_pre_callback_("glVertex3f", (void*)(ptrdiff_t)glow_glVertex3f, x, y, z);
  glow_glVertex3f(x, y, z);
  glow_post_callback_("glVertex3f", (void*)(ptrdiff_t)glow_glVertex3f, x, y, z);
}
PFNGLVERTEX3FPROC glow_debug_glVertex3f = glow_debug_impl_glVertex3f;

static void glow_debug_impl_glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points) {

  glow_pre_callback_("glMap1f", (void*)(ptrdiff_t)glow_glMap1f, target, u1, u2, stride, order, points);
  glow_glMap1f(target, u1, u2, stride, order, points);
  glow_post_callback_("glMap1f", (void*)(ptrdiff_t)glow_glMap1f, target, u1, u2, stride, order, points);
}
PFNGLMAP1FPROC glow_debug_glMap1f = glow_debug_impl_glMap1f;

static void glow_debug_impl_glEvalMesh1(GLenum mode, GLint i1, GLint i2) {

  glow_pre_callback_("glEvalMesh1", (void*)(ptrdiff_t)glow_glEvalMesh1, mode, i1, i2);
  glow_glEvalMesh1(mode, i1, i2);
  glow_post_callback_("glEvalMesh1", (void*)(ptrdiff_t)glow_glEvalMesh1, mode, i1, i2);
}
PFNGLEVALMESH1PROC glow_debug_glEvalMesh1 = glow_debug_impl_glEvalMesh1;

static GLboolean glow_debug_impl_glIsList(GLuint list) {

  GLboolean ret;
  glow_pre_callback_("glIsList", (void*)(ptrdiff_t)glow_glIsList, list);
  ret = glow_glIsList(list);
  glow_post_callback_("glIsList", (void*)(ptrdiff_t)glow_glIsList, list);
  return ret;
}
PFNGLISLISTPROC glow_debug_glIsList = glow_debug_impl_glIsList;

static void glow_debug_impl_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetTexLevelParameterfv", (void*)(ptrdiff_t)glow_glGetTexLevelParameterfv, target, level, pname, params);
  glow_glGetTexLevelParameterfv(target, level, pname, params);
  glow_post_callback_("glGetTexLevelParameterfv", (void*)(ptrdiff_t)glow_glGetTexLevelParameterfv, target, level, pname, params);
}
PFNGLGETTEXLEVELPARAMETERFVPROC glow_debug_glGetTexLevelParameterfv = glow_debug_impl_glGetTexLevelParameterfv;

static void glow_debug_impl_glNormal3sv(const GLshort *v) {

  glow_pre_callback_("glNormal3sv", (void*)(ptrdiff_t)glow_glNormal3sv, v);
  glow_glNormal3sv(v);
  glow_post_callback_("glNormal3sv", (void*)(ptrdiff_t)glow_glNormal3sv, v);
}
PFNGLNORMAL3SVPROC glow_debug_glNormal3sv = glow_debug_impl_glNormal3sv;

static void glow_debug_impl_glTexCoord3sv(const GLshort *v) {

  glow_pre_callback_("glTexCoord3sv", (void*)(ptrdiff_t)glow_glTexCoord3sv, v);
  glow_glTexCoord3sv(v);
  glow_post_callback_("glTexCoord3sv", (void*)(ptrdiff_t)glow_glTexCoord3sv, v);
}
PFNGLTEXCOORD3SVPROC glow_debug_glTexCoord3sv = glow_debug_impl_glTexCoord3sv;

static void glow_debug_impl_glVertex3i(GLint x, GLint y, GLint z) {

  glow_pre_callback_("glVertex3i", (void*)(ptrdiff_t)glow_glVertex3i, x, y, z);
  glow_glVertex3i(x, y, z);
  glow_post_callback_("glVertex3i", (void*)(ptrdiff_t)glow_glVertex3i, x, y, z);
}
PFNGLVERTEX3IPROC glow_debug_glVertex3i = glow_debug_impl_glVertex3i;

static void glow_debug_impl_glBlendFunc(GLenum sfactor, GLenum dfactor) {

  glow_pre_callback_("glBlendFunc", (void*)(ptrdiff_t)glow_glBlendFunc, sfactor, dfactor);
  glow_glBlendFunc(sfactor, dfactor);
  glow_post_callback_("glBlendFunc", (void*)(ptrdiff_t)glow_glBlendFunc, sfactor, dfactor);
}
PFNGLBLENDFUNCPROC glow_debug_glBlendFunc = glow_debug_impl_glBlendFunc;

static void glow_debug_impl_glTexGend(GLenum coord, GLenum pname, GLdouble param) {

  glow_pre_callback_("glTexGend", (void*)(ptrdiff_t)glow_glTexGend, coord, pname, param);
  glow_glTexGend(coord, pname, param);
  glow_post_callback_("glTexGend", (void*)(ptrdiff_t)glow_glTexGend, coord, pname, param);
}
PFNGLTEXGENDPROC glow_debug_glTexGend = glow_debug_impl_glTexGend;

static void glow_debug_impl_glPixelTransferi(GLenum pname, GLint param) {

  glow_pre_callback_("glPixelTransferi", (void*)(ptrdiff_t)glow_glPixelTransferi, pname, param);
  glow_glPixelTransferi(pname, param);
  glow_post_callback_("glPixelTransferi", (void*)(ptrdiff_t)glow_glPixelTransferi, pname, param);
}
PFNGLPIXELTRANSFERIPROC glow_debug_glPixelTransferi = glow_debug_impl_glPixelTransferi;

static void glow_debug_impl_glClear(GLbitfield mask) {

  glow_pre_callback_("glClear", (void*)(ptrdiff_t)glow_glClear, mask);
  glow_glClear(mask);
  glow_post_callback_("glClear", (void*)(ptrdiff_t)glow_glClear, mask);
}
PFNGLCLEARPROC glow_debug_glClear = glow_debug_impl_glClear;

static void glow_debug_impl_glRectfv(const GLfloat *v1, const GLfloat *v2) {

  glow_pre_callback_("glRectfv", (void*)(ptrdiff_t)glow_glRectfv, v1, v2);
  glow_glRectfv(v1, v2);
  glow_post_callback_("glRectfv", (void*)(ptrdiff_t)glow_glRectfv, v1, v2);
}
PFNGLRECTFVPROC glow_debug_glRectfv = glow_debug_impl_glRectfv;

static void glow_debug_impl_glTexCoord1d(GLdouble s) {

  glow_pre_callback_("glTexCoord1d", (void*)(ptrdiff_t)glow_glTexCoord1d, s);
  glow_glTexCoord1d(s);
  glow_post_callback_("glTexCoord1d", (void*)(ptrdiff_t)glow_glTexCoord1d, s);
}
PFNGLTEXCOORD1DPROC glow_debug_glTexCoord1d = glow_debug_impl_glTexCoord1d;

static void glow_debug_impl_glTexGeniv(GLenum coord, GLenum pname, const GLint *params) {

  glow_pre_callback_("glTexGeniv", (void*)(ptrdiff_t)glow_glTexGeniv, coord, pname, params);
  glow_glTexGeniv(coord, pname, params);
  glow_post_callback_("glTexGeniv", (void*)(ptrdiff_t)glow_glTexGeniv, coord, pname, params);
}
PFNGLTEXGENIVPROC glow_debug_glTexGeniv = glow_debug_impl_glTexGeniv;

static void glow_debug_impl_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {

  glow_pre_callback_("glVertex4f", (void*)(ptrdiff_t)glow_glVertex4f, x, y, z, w);
  glow_glVertex4f(x, y, z, w);
  glow_post_callback_("glVertex4f", (void*)(ptrdiff_t)glow_glVertex4f, x, y, z, w);
}
PFNGLVERTEX4FPROC glow_debug_glVertex4f = glow_debug_impl_glVertex4f;

static void glow_debug_impl_glEvalCoord2dv(const GLdouble *u) {

  glow_pre_callback_("glEvalCoord2dv", (void*)(ptrdiff_t)glow_glEvalCoord2dv, u);
  glow_glEvalCoord2dv(u);
  glow_post_callback_("glEvalCoord2dv", (void*)(ptrdiff_t)glow_glEvalCoord2dv, u);
}
PFNGLEVALCOORD2DVPROC glow_debug_glEvalCoord2dv = glow_debug_impl_glEvalCoord2dv;

static void glow_debug_impl_glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetTexGenfv", (void*)(ptrdiff_t)glow_glGetTexGenfv, coord, pname, params);
  glow_glGetTexGenfv(coord, pname, params);
  glow_post_callback_("glGetTexGenfv", (void*)(ptrdiff_t)glow_glGetTexGenfv, coord, pname, params);
}
PFNGLGETTEXGENFVPROC glow_debug_glGetTexGenfv = glow_debug_impl_glGetTexGenfv;

static void glow_debug_impl_glColor3usv(const GLushort *v) {

  glow_pre_callback_("glColor3usv", (void*)(ptrdiff_t)glow_glColor3usv, v);
  glow_glColor3usv(v);
  glow_post_callback_("glColor3usv", (void*)(ptrdiff_t)glow_glColor3usv, v);
}
PFNGLCOLOR3USVPROC glow_debug_glColor3usv = glow_debug_impl_glColor3usv;

static void glow_debug_impl_glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {

  glow_pre_callback_("glColor4s", (void*)(ptrdiff_t)glow_glColor4s, red, green, blue, alpha);
  glow_glColor4s(red, green, blue, alpha);
  glow_post_callback_("glColor4s", (void*)(ptrdiff_t)glow_glColor4s, red, green, blue, alpha);
}
PFNGLCOLOR4SPROC glow_debug_glColor4s = glow_debug_impl_glColor4s;

static void glow_debug_impl_glIndexs(GLshort c) {

  glow_pre_callback_("glIndexs", (void*)(ptrdiff_t)glow_glIndexs, c);
  glow_glIndexs(c);
  glow_post_callback_("glIndexs", (void*)(ptrdiff_t)glow_glIndexs, c);
}
PFNGLINDEXSPROC glow_debug_glIndexs = glow_debug_impl_glIndexs;

static void glow_debug_impl_glTexCoord1s(GLshort s) {

  glow_pre_callback_("glTexCoord1s", (void*)(ptrdiff_t)glow_glTexCoord1s, s);
  glow_glTexCoord1s(s);
  glow_post_callback_("glTexCoord1s", (void*)(ptrdiff_t)glow_glTexCoord1s, s);
}
PFNGLTEXCOORD1SPROC glow_debug_glTexCoord1s = glow_debug_impl_glTexCoord1s;

static void glow_debug_impl_glRasterPos2sv(const GLshort *v) {

  glow_pre_callback_("glRasterPos2sv", (void*)(ptrdiff_t)glow_glRasterPos2sv, v);
  glow_glRasterPos2sv(v);
  glow_post_callback_("glRasterPos2sv", (void*)(ptrdiff_t)glow_glRasterPos2sv, v);
}
PFNGLRASTERPOS2SVPROC glow_debug_glRasterPos2sv = glow_debug_impl_glRasterPos2sv;

static void glow_debug_impl_glTexCoord4sv(const GLshort *v) {

  glow_pre_callback_("glTexCoord4sv", (void*)(ptrdiff_t)glow_glTexCoord4sv, v);
  glow_glTexCoord4sv(v);
  glow_post_callback_("glTexCoord4sv", (void*)(ptrdiff_t)glow_glTexCoord4sv, v);
}
PFNGLTEXCOORD4SVPROC glow_debug_glTexCoord4sv = glow_debug_impl_glTexCoord4sv;

static void glow_debug_impl_glInitNames() {

  glow_pre_callback_("glInitNames", (void*)(ptrdiff_t)glow_glInitNames);
  glow_glInitNames();
  glow_post_callback_("glInitNames", (void*)(ptrdiff_t)glow_glInitNames);
}
PFNGLINITNAMESPROC glow_debug_glInitNames = glow_debug_impl_glInitNames;

static void glow_debug_impl_glMatrixMode(GLenum mode) {

  glow_pre_callback_("glMatrixMode", (void*)(ptrdiff_t)glow_glMatrixMode, mode);
  glow_glMatrixMode(mode);
  glow_post_callback_("glMatrixMode", (void*)(ptrdiff_t)glow_glMatrixMode, mode);
}
PFNGLMATRIXMODEPROC glow_debug_glMatrixMode = glow_debug_impl_glMatrixMode;

static void glow_debug_impl_glClearDepth(GLdouble depth) {

  glow_pre_callback_("glClearDepth", (void*)(ptrdiff_t)glow_glClearDepth, depth);
  glow_glClearDepth(depth);
  glow_post_callback_("glClearDepth", (void*)(ptrdiff_t)glow_glClearDepth, depth);
}
PFNGLCLEARDEPTHPROC glow_debug_glClearDepth = glow_debug_impl_glClearDepth;

static void glow_debug_impl_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glViewport", (void*)(ptrdiff_t)glow_glViewport, x, y, width, height);
  glow_glViewport(x, y, width, height);
  glow_post_callback_("glViewport", (void*)(ptrdiff_t)glow_glViewport, x, y, width, height);
}
PFNGLVIEWPORTPROC glow_debug_glViewport = glow_debug_impl_glViewport;

static void glow_debug_impl_glColor3dv(const GLdouble *v) {

  glow_pre_callback_("glColor3dv", (void*)(ptrdiff_t)glow_glColor3dv, v);
  glow_glColor3dv(v);
  glow_post_callback_("glColor3dv", (void*)(ptrdiff_t)glow_glColor3dv, v);
}
PFNGLCOLOR3DVPROC glow_debug_glColor3dv = glow_debug_impl_glColor3dv;

static void glow_debug_impl_glColor4bv(const GLbyte *v) {

  glow_pre_callback_("glColor4bv", (void*)(ptrdiff_t)glow_glColor4bv, v);
  glow_glColor4bv(v);
  glow_post_callback_("glColor4bv", (void*)(ptrdiff_t)glow_glColor4bv, v);
}
PFNGLCOLOR4BVPROC glow_debug_glColor4bv = glow_debug_impl_glColor4bv;

static void glow_debug_impl_glVertex3fv(const GLfloat *v) {

  glow_pre_callback_("glVertex3fv", (void*)(ptrdiff_t)glow_glVertex3fv, v);
  glow_glVertex3fv(v);
  glow_post_callback_("glVertex3fv", (void*)(ptrdiff_t)glow_glVertex3fv, v);
}
PFNGLVERTEX3FVPROC glow_debug_glVertex3fv = glow_debug_impl_glVertex3fv;

static void glow_debug_impl_glPopAttrib() {

  glow_pre_callback_("glPopAttrib", (void*)(ptrdiff_t)glow_glPopAttrib);
  glow_glPopAttrib();
  glow_post_callback_("glPopAttrib", (void*)(ptrdiff_t)glow_glPopAttrib);
}
PFNGLPOPATTRIBPROC glow_debug_glPopAttrib = glow_debug_impl_glPopAttrib;

static void glow_debug_impl_glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points) {

  glow_pre_callback_("glMap1d", (void*)(ptrdiff_t)glow_glMap1d, target, u1, u2, stride, order, points);
  glow_glMap1d(target, u1, u2, stride, order, points);
  glow_post_callback_("glMap1d", (void*)(ptrdiff_t)glow_glMap1d, target, u1, u2, stride, order, points);
}
PFNGLMAP1DPROC glow_debug_glMap1d = glow_debug_impl_glMap1d;

static void glow_debug_impl_glEvalCoord2d(GLdouble u, GLdouble v) {

  glow_pre_callback_("glEvalCoord2d", (void*)(ptrdiff_t)glow_glEvalCoord2d, u, v);
  glow_glEvalCoord2d(u, v);
  glow_post_callback_("glEvalCoord2d", (void*)(ptrdiff_t)glow_glEvalCoord2d, u, v);
}
PFNGLEVALCOORD2DPROC glow_debug_glEvalCoord2d = glow_debug_impl_glEvalCoord2d;

static void glow_debug_impl_glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {

  glow_pre_callback_("glColor4b", (void*)(ptrdiff_t)glow_glColor4b, red, green, blue, alpha);
  glow_glColor4b(red, green, blue, alpha);
  glow_post_callback_("glColor4b", (void*)(ptrdiff_t)glow_glColor4b, red, green, blue, alpha);
}
PFNGLCOLOR4BPROC glow_debug_glColor4b = glow_debug_impl_glColor4b;

static void glow_debug_impl_glNormal3s(GLshort nx, GLshort ny, GLshort nz) {

  glow_pre_callback_("glNormal3s", (void*)(ptrdiff_t)glow_glNormal3s, nx, ny, nz);
  glow_glNormal3s(nx, ny, nz);
  glow_post_callback_("glNormal3s", (void*)(ptrdiff_t)glow_glNormal3s, nx, ny, nz);
}
PFNGLNORMAL3SPROC glow_debug_glNormal3s = glow_debug_impl_glNormal3s;

static void glow_debug_impl_glRasterPos2i(GLint x, GLint y) {

  glow_pre_callback_("glRasterPos2i", (void*)(ptrdiff_t)glow_glRasterPos2i, x, y);
  glow_glRasterPos2i(x, y);
  glow_post_callback_("glRasterPos2i", (void*)(ptrdiff_t)glow_glRasterPos2i, x, y);
}
PFNGLRASTERPOS2IPROC glow_debug_glRasterPos2i = glow_debug_impl_glRasterPos2i;

static void glow_debug_impl_glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {

  glow_pre_callback_("glVertex4s", (void*)(ptrdiff_t)glow_glVertex4s, x, y, z, w);
  glow_glVertex4s(x, y, z, w);
  glow_post_callback_("glVertex4s", (void*)(ptrdiff_t)glow_glVertex4s, x, y, z, w);
}
PFNGLVERTEX4SPROC glow_debug_glVertex4s = glow_debug_impl_glVertex4s;

static void glow_debug_impl_glRasterPos3dv(const GLdouble *v) {

  glow_pre_callback_("glRasterPos3dv", (void*)(ptrdiff_t)glow_glRasterPos3dv, v);
  glow_glRasterPos3dv(v);
  glow_post_callback_("glRasterPos3dv", (void*)(ptrdiff_t)glow_glRasterPos3dv, v);
}
PFNGLRASTERPOS3DVPROC glow_debug_glRasterPos3dv = glow_debug_impl_glRasterPos3dv;

static void glow_debug_impl_glTexCoord2d(GLdouble s, GLdouble t) {

  glow_pre_callback_("glTexCoord2d", (void*)(ptrdiff_t)glow_glTexCoord2d, s, t);
  glow_glTexCoord2d(s, t);
  glow_post_callback_("glTexCoord2d", (void*)(ptrdiff_t)glow_glTexCoord2d, s, t);
}
PFNGLTEXCOORD2DPROC glow_debug_glTexCoord2d = glow_debug_impl_glTexCoord2d;

static void glow_debug_impl_glLightf(GLenum light, GLenum pname, GLfloat param) {

  glow_pre_callback_("glLightf", (void*)(ptrdiff_t)glow_glLightf, light, pname, param);
  glow_glLightf(light, pname, param);
  glow_post_callback_("glLightf", (void*)(ptrdiff_t)glow_glLightf, light, pname, param);
}
PFNGLLIGHTFPROC glow_debug_glLightf = glow_debug_impl_glLightf;

static void glow_debug_impl_glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {

  glow_pre_callback_("glDrawPixels", (void*)(ptrdiff_t)glow_glDrawPixels, width, height, format, type, pixels);
  glow_glDrawPixels(width, height, format, type, pixels);
  glow_post_callback_("glDrawPixels", (void*)(ptrdiff_t)glow_glDrawPixels, width, height, format, type, pixels);
}
PFNGLDRAWPIXELSPROC glow_debug_glDrawPixels = glow_debug_impl_glDrawPixels;

static void glow_debug_impl_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {

  glow_pre_callback_("glScissor", (void*)(ptrdiff_t)glow_glScissor, x, y, width, height);
  glow_glScissor(x, y, width, height);
  glow_post_callback_("glScissor", (void*)(ptrdiff_t)glow_glScissor, x, y, width, height);
}
PFNGLSCISSORPROC glow_debug_glScissor = glow_debug_impl_glScissor;

static void glow_debug_impl_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {

  glow_pre_callback_("glColorMask", (void*)(ptrdiff_t)glow_glColorMask, red, green, blue, alpha);
  glow_glColorMask(red, green, blue, alpha);
  glow_post_callback_("glColorMask", (void*)(ptrdiff_t)glow_glColorMask, red, green, blue, alpha);
}
PFNGLCOLORMASKPROC glow_debug_glColorMask = glow_debug_impl_glColorMask;

static void glow_debug_impl_glGetBooleanv(GLenum pname, GLboolean *data) {

  glow_pre_callback_("glGetBooleanv", (void*)(ptrdiff_t)glow_glGetBooleanv, pname, data);
  glow_glGetBooleanv(pname, data);
  glow_post_callback_("glGetBooleanv", (void*)(ptrdiff_t)glow_glGetBooleanv, pname, data);
}
PFNGLGETBOOLEANVPROC glow_debug_glGetBooleanv = glow_debug_impl_glGetBooleanv;

static void glow_debug_impl_glColor4iv(const GLint *v) {

  glow_pre_callback_("glColor4iv", (void*)(ptrdiff_t)glow_glColor4iv, v);
  glow_glColor4iv(v);
  glow_post_callback_("glColor4iv", (void*)(ptrdiff_t)glow_glColor4iv, v);
}
PFNGLCOLOR4IVPROC glow_debug_glColor4iv = glow_debug_impl_glColor4iv;

static void glow_debug_impl_glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {

  glow_pre_callback_("glCopyPixels", (void*)(ptrdiff_t)glow_glCopyPixels, x, y, width, height, type);
  glow_glCopyPixels(x, y, width, height, type);
  glow_post_callback_("glCopyPixels", (void*)(ptrdiff_t)glow_glCopyPixels, x, y, width, height, type);
}
PFNGLCOPYPIXELSPROC glow_debug_glCopyPixels = glow_debug_impl_glCopyPixels;

static void glow_debug_impl_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {

  glow_pre_callback_("glRotated", (void*)(ptrdiff_t)glow_glRotated, angle, x, y, z);
  glow_glRotated(angle, x, y, z);
  glow_post_callback_("glRotated", (void*)(ptrdiff_t)glow_glRotated, angle, x, y, z);
}
PFNGLROTATEDPROC glow_debug_glRotated = glow_debug_impl_glRotated;

static void glow_debug_impl_glTranslated(GLdouble x, GLdouble y, GLdouble z) {

  glow_pre_callback_("glTranslated", (void*)(ptrdiff_t)glow_glTranslated, x, y, z);
  glow_glTranslated(x, y, z);
  glow_post_callback_("glTranslated", (void*)(ptrdiff_t)glow_glTranslated, x, y, z);
}
PFNGLTRANSLATEDPROC glow_debug_glTranslated = glow_debug_impl_glTranslated;

static GLuint glow_debug_impl_glGenLists(GLsizei range) {

  GLuint ret;
  glow_pre_callback_("glGenLists", (void*)(ptrdiff_t)glow_glGenLists, range);
  ret = glow_glGenLists(range);
  glow_post_callback_("glGenLists", (void*)(ptrdiff_t)glow_glGenLists, range);
  return ret;
}
PFNGLGENLISTSPROC glow_debug_glGenLists = glow_debug_impl_glGenLists;

static void glow_debug_impl_glTexCoord1f(GLfloat s) {

  glow_pre_callback_("glTexCoord1f", (void*)(ptrdiff_t)glow_glTexCoord1f, s);
  glow_glTexCoord1f(s);
  glow_post_callback_("glTexCoord1f", (void*)(ptrdiff_t)glow_glTexCoord1f, s);
}
PFNGLTEXCOORD1FPROC glow_debug_glTexCoord1f = glow_debug_impl_glTexCoord1f;

static void glow_debug_impl_glFogfv(GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glFogfv", (void*)(ptrdiff_t)glow_glFogfv, pname, params);
  glow_glFogfv(pname, params);
  glow_post_callback_("glFogfv", (void*)(ptrdiff_t)glow_glFogfv, pname, params);
}
PFNGLFOGFVPROC glow_debug_glFogfv = glow_debug_impl_glFogfv;

static void glow_debug_impl_glEvalCoord1dv(const GLdouble *u) {

  glow_pre_callback_("glEvalCoord1dv", (void*)(ptrdiff_t)glow_glEvalCoord1dv, u);
  glow_glEvalCoord1dv(u);
  glow_post_callback_("glEvalCoord1dv", (void*)(ptrdiff_t)glow_glEvalCoord1dv, u);
}
PFNGLEVALCOORD1DVPROC glow_debug_glEvalCoord1dv = glow_debug_impl_glEvalCoord1dv;

static void glow_debug_impl_glTexCoord2dv(const GLdouble *v) {

  glow_pre_callback_("glTexCoord2dv", (void*)(ptrdiff_t)glow_glTexCoord2dv, v);
  glow_glTexCoord2dv(v);
  glow_post_callback_("glTexCoord2dv", (void*)(ptrdiff_t)glow_glTexCoord2dv, v);
}
PFNGLTEXCOORD2DVPROC glow_debug_glTexCoord2dv = glow_debug_impl_glTexCoord2dv;

static void glow_debug_impl_glLightModelfv(GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glLightModelfv", (void*)(ptrdiff_t)glow_glLightModelfv, pname, params);
  glow_glLightModelfv(pname, params);
  glow_post_callback_("glLightModelfv", (void*)(ptrdiff_t)glow_glLightModelfv, pname, params);
}
PFNGLLIGHTMODELFVPROC glow_debug_glLightModelfv = glow_debug_impl_glLightModelfv;

static void glow_debug_impl_glPopName() {

  glow_pre_callback_("glPopName", (void*)(ptrdiff_t)glow_glPopName);
  glow_glPopName();
  glow_post_callback_("glPopName", (void*)(ptrdiff_t)glow_glPopName);
}
PFNGLPOPNAMEPROC glow_debug_glPopName = glow_debug_impl_glPopName;

static void glow_debug_impl_glPushAttrib(GLbitfield mask) {

  glow_pre_callback_("glPushAttrib", (void*)(ptrdiff_t)glow_glPushAttrib, mask);
  glow_glPushAttrib(mask);
  glow_post_callback_("glPushAttrib", (void*)(ptrdiff_t)glow_glPushAttrib, mask);
}
PFNGLPUSHATTRIBPROC glow_debug_glPushAttrib = glow_debug_impl_glPushAttrib;

static void glow_debug_impl_glColor3ubv(const GLubyte *v) {

  glow_pre_callback_("glColor3ubv", (void*)(ptrdiff_t)glow_glColor3ubv, v);
  glow_glColor3ubv(v);
  glow_post_callback_("glColor3ubv", (void*)(ptrdiff_t)glow_glColor3ubv, v);
}
PFNGLCOLOR3UBVPROC glow_debug_glColor3ubv = glow_debug_impl_glColor3ubv;

static void glow_debug_impl_glTexCoord2i(GLint s, GLint t) {

  glow_pre_callback_("glTexCoord2i", (void*)(ptrdiff_t)glow_glTexCoord2i, s, t);
  glow_glTexCoord2i(s, t);
  glow_post_callback_("glTexCoord2i", (void*)(ptrdiff_t)glow_glTexCoord2i, s, t);
}
PFNGLTEXCOORD2IPROC glow_debug_glTexCoord2i = glow_debug_impl_glTexCoord2i;

static void glow_debug_impl_glColor4ubv(const GLubyte *v) {

  glow_pre_callback_("glColor4ubv", (void*)(ptrdiff_t)glow_glColor4ubv, v);
  glow_glColor4ubv(v);
  glow_post_callback_("glColor4ubv", (void*)(ptrdiff_t)glow_glColor4ubv, v);
}
PFNGLCOLOR4UBVPROC glow_debug_glColor4ubv = glow_debug_impl_glColor4ubv;

static void glow_debug_impl_glVertex2s(GLshort x, GLshort y) {

  glow_pre_callback_("glVertex2s", (void*)(ptrdiff_t)glow_glVertex2s, x, y);
  glow_glVertex2s(x, y);
  glow_post_callback_("glVertex2s", (void*)(ptrdiff_t)glow_glVertex2s, x, y);
}
PFNGLVERTEX2SPROC glow_debug_glVertex2s = glow_debug_impl_glVertex2s;

static void glow_debug_impl_glVertex3iv(const GLint *v) {

  glow_pre_callback_("glVertex3iv", (void*)(ptrdiff_t)glow_glVertex3iv, v);
  glow_glVertex3iv(v);
  glow_post_callback_("glVertex3iv", (void*)(ptrdiff_t)glow_glVertex3iv, v);
}
PFNGLVERTEX3IVPROC glow_debug_glVertex3iv = glow_debug_impl_glVertex3iv;

static void glow_debug_impl_glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer) {

  glow_pre_callback_("glFeedbackBuffer", (void*)(ptrdiff_t)glow_glFeedbackBuffer, size, type, buffer);
  glow_glFeedbackBuffer(size, type, buffer);
  glow_post_callback_("glFeedbackBuffer", (void*)(ptrdiff_t)glow_glFeedbackBuffer, size, type, buffer);
}
PFNGLFEEDBACKBUFFERPROC glow_debug_glFeedbackBuffer = glow_debug_impl_glFeedbackBuffer;

static void glow_debug_impl_glStencilFunc(GLenum func, GLint ref, GLuint mask) {

  glow_pre_callback_("glStencilFunc", (void*)(ptrdiff_t)glow_glStencilFunc, func, ref, mask);
  glow_glStencilFunc(func, ref, mask);
  glow_post_callback_("glStencilFunc", (void*)(ptrdiff_t)glow_glStencilFunc, func, ref, mask);
}
PFNGLSTENCILFUNCPROC glow_debug_glStencilFunc = glow_debug_impl_glStencilFunc;

static void glow_debug_impl_glColor3d(GLdouble red, GLdouble green, GLdouble blue) {

  glow_pre_callback_("glColor3d", (void*)(ptrdiff_t)glow_glColor3d, red, green, blue);
  glow_glColor3d(red, green, blue);
  glow_post_callback_("glColor3d", (void*)(ptrdiff_t)glow_glColor3d, red, green, blue);
}
PFNGLCOLOR3DPROC glow_debug_glColor3d = glow_debug_impl_glColor3d;

static void glow_debug_impl_glColor3s(GLshort red, GLshort green, GLshort blue) {

  glow_pre_callback_("glColor3s", (void*)(ptrdiff_t)glow_glColor3s, red, green, blue);
  glow_glColor3s(red, green, blue);
  glow_post_callback_("glColor3s", (void*)(ptrdiff_t)glow_glColor3s, red, green, blue);
}
PFNGLCOLOR3SPROC glow_debug_glColor3s = glow_debug_impl_glColor3s;

static void glow_debug_impl_glColor3sv(const GLshort *v) {

  glow_pre_callback_("glColor3sv", (void*)(ptrdiff_t)glow_glColor3sv, v);
  glow_glColor3sv(v);
  glow_post_callback_("glColor3sv", (void*)(ptrdiff_t)glow_glColor3sv, v);
}
PFNGLCOLOR3SVPROC glow_debug_glColor3sv = glow_debug_impl_glColor3sv;

static void glow_debug_impl_glAlphaFunc(GLenum func, GLfloat ref) {

  glow_pre_callback_("glAlphaFunc", (void*)(ptrdiff_t)glow_glAlphaFunc, func, ref);
  glow_glAlphaFunc(func, ref);
  glow_post_callback_("glAlphaFunc", (void*)(ptrdiff_t)glow_glAlphaFunc, func, ref);
}
PFNGLALPHAFUNCPROC glow_debug_glAlphaFunc = glow_debug_impl_glAlphaFunc;

static void glow_debug_impl_glGetPixelMapfv(GLenum map, GLfloat *values) {

  glow_pre_callback_("glGetPixelMapfv", (void*)(ptrdiff_t)glow_glGetPixelMapfv, map, values);
  glow_glGetPixelMapfv(map, values);
  glow_post_callback_("glGetPixelMapfv", (void*)(ptrdiff_t)glow_glGetPixelMapfv, map, values);
}
PFNGLGETPIXELMAPFVPROC glow_debug_glGetPixelMapfv = glow_debug_impl_glGetPixelMapfv;

static void glow_debug_impl_glTexCoord2iv(const GLint *v) {

  glow_pre_callback_("glTexCoord2iv", (void*)(ptrdiff_t)glow_glTexCoord2iv, v);
  glow_glTexCoord2iv(v);
  glow_post_callback_("glTexCoord2iv", (void*)(ptrdiff_t)glow_glTexCoord2iv, v);
}
PFNGLTEXCOORD2IVPROC glow_debug_glTexCoord2iv = glow_debug_impl_glTexCoord2iv;

static void glow_debug_impl_glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points) {

  glow_pre_callback_("glMap2f", (void*)(ptrdiff_t)glow_glMap2f, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
  glow_glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
  glow_post_callback_("glMap2f", (void*)(ptrdiff_t)glow_glMap2f, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
PFNGLMAP2FPROC glow_debug_glMap2f = glow_debug_impl_glMap2f;

static void glow_debug_impl_glFrontFace(GLenum mode) {

  glow_pre_callback_("glFrontFace", (void*)(ptrdiff_t)glow_glFrontFace, mode);
  glow_glFrontFace(mode);
  glow_post_callback_("glFrontFace", (void*)(ptrdiff_t)glow_glFrontFace, mode);
}
PFNGLFRONTFACEPROC glow_debug_glFrontFace = glow_debug_impl_glFrontFace;

static void glow_debug_impl_glDrawBuffer(GLenum buf) {

  glow_pre_callback_("glDrawBuffer", (void*)(ptrdiff_t)glow_glDrawBuffer, buf);
  glow_glDrawBuffer(buf);
  glow_post_callback_("glDrawBuffer", (void*)(ptrdiff_t)glow_glDrawBuffer, buf);
}
PFNGLDRAWBUFFERPROC glow_debug_glDrawBuffer = glow_debug_impl_glDrawBuffer;

static void glow_debug_impl_glCallList(GLuint list) {

  glow_pre_callback_("glCallList", (void*)(ptrdiff_t)glow_glCallList, list);
  glow_glCallList(list);
  glow_post_callback_("glCallList", (void*)(ptrdiff_t)glow_glCallList, list);
}
PFNGLCALLLISTPROC glow_debug_glCallList = glow_debug_impl_glCallList;

static void glow_debug_impl_glTexCoord1sv(const GLshort *v) {

  glow_pre_callback_("glTexCoord1sv", (void*)(ptrdiff_t)glow_glTexCoord1sv, v);
  glow_glTexCoord1sv(v);
  glow_post_callback_("glTexCoord1sv", (void*)(ptrdiff_t)glow_glTexCoord1sv, v);
}
PFNGLTEXCOORD1SVPROC glow_debug_glTexCoord1sv = glow_debug_impl_glTexCoord1sv;

static void glow_debug_impl_glGetMapfv(GLenum target, GLenum query, GLfloat *v) {

  glow_pre_callback_("glGetMapfv", (void*)(ptrdiff_t)glow_glGetMapfv, target, query, v);
  glow_glGetMapfv(target, query, v);
  glow_post_callback_("glGetMapfv", (void*)(ptrdiff_t)glow_glGetMapfv, target, query, v);
}
PFNGLGETMAPFVPROC glow_debug_glGetMapfv = glow_debug_impl_glGetMapfv;

static GLenum glow_debug_impl_glGetError() {

  GLenum ret;
  glow_pre_callback_("glGetError", (void*)(ptrdiff_t)glow_glGetError);
  ret = glow_glGetError();
  glow_post_callback_("glGetError", (void*)(ptrdiff_t)glow_glGetError);
  return ret;
}
PFNGLGETERRORPROC glow_debug_glGetError = glow_debug_impl_glGetError;

static void glow_debug_impl_glTexCoord2s(GLshort s, GLshort t) {

  glow_pre_callback_("glTexCoord2s", (void*)(ptrdiff_t)glow_glTexCoord2s, s, t);
  glow_glTexCoord2s(s, t);
  glow_post_callback_("glTexCoord2s", (void*)(ptrdiff_t)glow_glTexCoord2s, s, t);
}
PFNGLTEXCOORD2SPROC glow_debug_glTexCoord2s = glow_debug_impl_glTexCoord2s;

static void glow_debug_impl_glLightfv(GLenum light, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glLightfv", (void*)(ptrdiff_t)glow_glLightfv, light, pname, params);
  glow_glLightfv(light, pname, params);
  glow_post_callback_("glLightfv", (void*)(ptrdiff_t)glow_glLightfv, light, pname, params);
}
PFNGLLIGHTFVPROC glow_debug_glLightfv = glow_debug_impl_glLightfv;

static void glow_debug_impl_glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glTexGenfv", (void*)(ptrdiff_t)glow_glTexGenfv, coord, pname, params);
  glow_glTexGenfv(coord, pname, params);
  glow_post_callback_("glTexGenfv", (void*)(ptrdiff_t)glow_glTexGenfv, coord, pname, params);
}
PFNGLTEXGENFVPROC glow_debug_glTexGenfv = glow_debug_impl_glTexGenfv;

static void glow_debug_impl_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {

  glow_pre_callback_("glTexParameterf", (void*)(ptrdiff_t)glow_glTexParameterf, target, pname, param);
  glow_glTexParameterf(target, pname, param);
  glow_post_callback_("glTexParameterf", (void*)(ptrdiff_t)glow_glTexParameterf, target, pname, param);
}
PFNGLTEXPARAMETERFPROC glow_debug_glTexParameterf = glow_debug_impl_glTexParameterf;

static void glow_debug_impl_glVertex2d(GLdouble x, GLdouble y) {

  glow_pre_callback_("glVertex2d", (void*)(ptrdiff_t)glow_glVertex2d, x, y);
  glow_glVertex2d(x, y);
  glow_post_callback_("glVertex2d", (void*)(ptrdiff_t)glow_glVertex2d, x, y);
}
PFNGLVERTEX2DPROC glow_debug_glVertex2d = glow_debug_impl_glVertex2d;

static void glow_debug_impl_glLineStipple(GLint factor, GLushort pattern) {

  glow_pre_callback_("glLineStipple", (void*)(ptrdiff_t)glow_glLineStipple, factor, pattern);
  glow_glLineStipple(factor, pattern);
  glow_post_callback_("glLineStipple", (void*)(ptrdiff_t)glow_glLineStipple, factor, pattern);
}
PFNGLLINESTIPPLEPROC glow_debug_glLineStipple = glow_debug_impl_glLineStipple;

static void glow_debug_impl_glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {

  glow_pre_callback_("glOrtho", (void*)(ptrdiff_t)glow_glOrtho, left, right, bottom, top, zNear, zFar);
  glow_glOrtho(left, right, bottom, top, zNear, zFar);
  glow_post_callback_("glOrtho", (void*)(ptrdiff_t)glow_glOrtho, left, right, bottom, top, zNear, zFar);
}
PFNGLORTHOPROC glow_debug_glOrtho = glow_debug_impl_glOrtho;

static void glow_debug_impl_glTexCoord3dv(const GLdouble *v) {

  glow_pre_callback_("glTexCoord3dv", (void*)(ptrdiff_t)glow_glTexCoord3dv, v);
  glow_glTexCoord3dv(v);
  glow_post_callback_("glTexCoord3dv", (void*)(ptrdiff_t)glow_glTexCoord3dv, v);
}
PFNGLTEXCOORD3DVPROC glow_debug_glTexCoord3dv = glow_debug_impl_glTexCoord3dv;

static GLint glow_debug_impl_glRenderMode(GLenum mode) {

  GLint ret;
  glow_pre_callback_("glRenderMode", (void*)(ptrdiff_t)glow_glRenderMode, mode);
  ret = glow_glRenderMode(mode);
  glow_post_callback_("glRenderMode", (void*)(ptrdiff_t)glow_glRenderMode, mode);
  return ret;
}
PFNGLRENDERMODEPROC glow_debug_glRenderMode = glow_debug_impl_glRenderMode;

static void glow_debug_impl_glCallLists(GLsizei n, GLenum type, const void *lists) {

  glow_pre_callback_("glCallLists", (void*)(ptrdiff_t)glow_glCallLists, n, type, lists);
  glow_glCallLists(n, type, lists);
  glow_post_callback_("glCallLists", (void*)(ptrdiff_t)glow_glCallLists, n, type, lists);
}
PFNGLCALLLISTSPROC glow_debug_glCallLists = glow_debug_impl_glCallLists;

static void glow_debug_impl_glColor3ui(GLuint red, GLuint green, GLuint blue) {

  glow_pre_callback_("glColor3ui", (void*)(ptrdiff_t)glow_glColor3ui, red, green, blue);
  glow_glColor3ui(red, green, blue);
  glow_post_callback_("glColor3ui", (void*)(ptrdiff_t)glow_glColor3ui, red, green, blue);
}
PFNGLCOLOR3UIPROC glow_debug_glColor3ui = glow_debug_impl_glColor3ui;

static void glow_debug_impl_glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {

  glow_pre_callback_("glNormal3d", (void*)(ptrdiff_t)glow_glNormal3d, nx, ny, nz);
  glow_glNormal3d(nx, ny, nz);
  glow_post_callback_("glNormal3d", (void*)(ptrdiff_t)glow_glNormal3d, nx, ny, nz);
}
PFNGLNORMAL3DPROC glow_debug_glNormal3d = glow_debug_impl_glNormal3d;

static void glow_debug_impl_glRasterPos3i(GLint x, GLint y, GLint z) {

  glow_pre_callback_("glRasterPos3i", (void*)(ptrdiff_t)glow_glRasterPos3i, x, y, z);
  glow_glRasterPos3i(x, y, z);
  glow_post_callback_("glRasterPos3i", (void*)(ptrdiff_t)glow_glRasterPos3i, x, y, z);
}
PFNGLRASTERPOS3IPROC glow_debug_glRasterPos3i = glow_debug_impl_glRasterPos3i;

static void glow_debug_impl_glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {

  glow_pre_callback_("glRasterPos4f", (void*)(ptrdiff_t)glow_glRasterPos4f, x, y, z, w);
  glow_glRasterPos4f(x, y, z, w);
  glow_post_callback_("glRasterPos4f", (void*)(ptrdiff_t)glow_glRasterPos4f, x, y, z, w);
}
PFNGLRASTERPOS4FPROC glow_debug_glRasterPos4f = glow_debug_impl_glRasterPos4f;

static void glow_debug_impl_glFogf(GLenum pname, GLfloat param) {

  glow_pre_callback_("glFogf", (void*)(ptrdiff_t)glow_glFogf, pname, param);
  glow_glFogf(pname, param);
  glow_post_callback_("glFogf", (void*)(ptrdiff_t)glow_glFogf, pname, param);
}
PFNGLFOGFPROC glow_debug_glFogf = glow_debug_impl_glFogf;

static void glow_debug_impl_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {

  glow_pre_callback_("glRotatef", (void*)(ptrdiff_t)glow_glRotatef, angle, x, y, z);
  glow_glRotatef(angle, x, y, z);
  glow_post_callback_("glRotatef", (void*)(ptrdiff_t)glow_glRotatef, angle, x, y, z);
}
PFNGLROTATEFPROC glow_debug_glRotatef = glow_debug_impl_glRotatef;

static void glow_debug_impl_glDepthFunc(GLenum func) {

  glow_pre_callback_("glDepthFunc", (void*)(ptrdiff_t)glow_glDepthFunc, func);
  glow_glDepthFunc(func);
  glow_post_callback_("glDepthFunc", (void*)(ptrdiff_t)glow_glDepthFunc, func);
}
PFNGLDEPTHFUNCPROC glow_debug_glDepthFunc = glow_debug_impl_glDepthFunc;

static void glow_debug_impl_glColor4usv(const GLushort *v) {

  glow_pre_callback_("glColor4usv", (void*)(ptrdiff_t)glow_glColor4usv, v);
  glow_glColor4usv(v);
  glow_post_callback_("glColor4usv", (void*)(ptrdiff_t)glow_glColor4usv, v);
}
PFNGLCOLOR4USVPROC glow_debug_glColor4usv = glow_debug_impl_glColor4usv;

static void glow_debug_impl_glTexCoord2f(GLfloat s, GLfloat t) {

  glow_pre_callback_("glTexCoord2f", (void*)(ptrdiff_t)glow_glTexCoord2f, s, t);
  glow_glTexCoord2f(s, t);
  glow_post_callback_("glTexCoord2f", (void*)(ptrdiff_t)glow_glTexCoord2f, s, t);
}
PFNGLTEXCOORD2FPROC glow_debug_glTexCoord2f = glow_debug_impl_glTexCoord2f;

static void glow_debug_impl_glVertex2iv(const GLint *v) {

  glow_pre_callback_("glVertex2iv", (void*)(ptrdiff_t)glow_glVertex2iv, v);
  glow_glVertex2iv(v);
  glow_post_callback_("glVertex2iv", (void*)(ptrdiff_t)glow_glVertex2iv, v);
}
PFNGLVERTEX2IVPROC glow_debug_glVertex2iv = glow_debug_impl_glVertex2iv;

static void glow_debug_impl_glTexEnvi(GLenum target, GLenum pname, GLint param) {

  glow_pre_callback_("glTexEnvi", (void*)(ptrdiff_t)glow_glTexEnvi, target, pname, param);
  glow_glTexEnvi(target, pname, param);
  glow_post_callback_("glTexEnvi", (void*)(ptrdiff_t)glow_glTexEnvi, target, pname, param);
}
PFNGLTEXENVIPROC glow_debug_glTexEnvi = glow_debug_impl_glTexEnvi;

static void glow_debug_impl_glGetPixelMapuiv(GLenum map, GLuint *values) {

  glow_pre_callback_("glGetPixelMapuiv", (void*)(ptrdiff_t)glow_glGetPixelMapuiv, map, values);
  glow_glGetPixelMapuiv(map, values);
  glow_post_callback_("glGetPixelMapuiv", (void*)(ptrdiff_t)glow_glGetPixelMapuiv, map, values);
}
PFNGLGETPIXELMAPUIVPROC glow_debug_glGetPixelMapuiv = glow_debug_impl_glGetPixelMapuiv;

static void glow_debug_impl_glIndexi(GLint c) {

  glow_pre_callback_("glIndexi", (void*)(ptrdiff_t)glow_glIndexi, c);
  glow_glIndexi(c);
  glow_post_callback_("glIndexi", (void*)(ptrdiff_t)glow_glIndexi, c);
}
PFNGLINDEXIPROC glow_debug_glIndexi = glow_debug_impl_glIndexi;

static void glow_debug_impl_glIndexsv(const GLshort *c) {

  glow_pre_callback_("glIndexsv", (void*)(ptrdiff_t)glow_glIndexsv, c);
  glow_glIndexsv(c);
  glow_post_callback_("glIndexsv", (void*)(ptrdiff_t)glow_glIndexsv, c);
}
PFNGLINDEXSVPROC glow_debug_glIndexsv = glow_debug_impl_glIndexsv;

static void glow_debug_impl_glRectiv(const GLint *v1, const GLint *v2) {

  glow_pre_callback_("glRectiv", (void*)(ptrdiff_t)glow_glRectiv, v1, v2);
  glow_glRectiv(v1, v2);
  glow_post_callback_("glRectiv", (void*)(ptrdiff_t)glow_glRectiv, v1, v2);
}
PFNGLRECTIVPROC glow_debug_glRectiv = glow_debug_impl_glRectiv;

static void glow_debug_impl_glTexCoord4iv(const GLint *v) {

  glow_pre_callback_("glTexCoord4iv", (void*)(ptrdiff_t)glow_glTexCoord4iv, v);
  glow_glTexCoord4iv(v);
  glow_post_callback_("glTexCoord4iv", (void*)(ptrdiff_t)glow_glTexCoord4iv, v);
}
PFNGLTEXCOORD4IVPROC glow_debug_glTexCoord4iv = glow_debug_impl_glTexCoord4iv;

static void glow_debug_impl_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {

  glow_pre_callback_("glMapGrid1d", (void*)(ptrdiff_t)glow_glMapGrid1d, un, u1, u2);
  glow_glMapGrid1d(un, u1, u2);
  glow_post_callback_("glMapGrid1d", (void*)(ptrdiff_t)glow_glMapGrid1d, un, u1, u2);
}
PFNGLMAPGRID1DPROC glow_debug_glMapGrid1d = glow_debug_impl_glMapGrid1d;

static void glow_debug_impl_glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values) {

  glow_pre_callback_("glPixelMapusv", (void*)(ptrdiff_t)glow_glPixelMapusv, map, mapsize, values);
  glow_glPixelMapusv(map, mapsize, values);
  glow_post_callback_("glPixelMapusv", (void*)(ptrdiff_t)glow_glPixelMapusv, map, mapsize, values);
}
PFNGLPIXELMAPUSVPROC glow_debug_glPixelMapusv = glow_debug_impl_glPixelMapusv;

static void glow_debug_impl_glNormal3iv(const GLint *v) {

  glow_pre_callback_("glNormal3iv", (void*)(ptrdiff_t)glow_glNormal3iv, v);
  glow_glNormal3iv(v);
  glow_post_callback_("glNormal3iv", (void*)(ptrdiff_t)glow_glNormal3iv, v);
}
PFNGLNORMAL3IVPROC glow_debug_glNormal3iv = glow_debug_impl_glNormal3iv;

static void glow_debug_impl_glRasterPos3fv(const GLfloat *v) {

  glow_pre_callback_("glRasterPos3fv", (void*)(ptrdiff_t)glow_glRasterPos3fv, v);
  glow_glRasterPos3fv(v);
  glow_post_callback_("glRasterPos3fv", (void*)(ptrdiff_t)glow_glRasterPos3fv, v);
}
PFNGLRASTERPOS3FVPROC glow_debug_glRasterPos3fv = glow_debug_impl_glRasterPos3fv;

static void glow_debug_impl_glTexCoord3fv(const GLfloat *v) {

  glow_pre_callback_("glTexCoord3fv", (void*)(ptrdiff_t)glow_glTexCoord3fv, v);
  glow_glTexCoord3fv(v);
  glow_post_callback_("glTexCoord3fv", (void*)(ptrdiff_t)glow_glTexCoord3fv, v);
}
PFNGLTEXCOORD3FVPROC glow_debug_glTexCoord3fv = glow_debug_impl_glTexCoord3fv;

static void glow_debug_impl_glTexGeni(GLenum coord, GLenum pname, GLint param) {

  glow_pre_callback_("glTexGeni", (void*)(ptrdiff_t)glow_glTexGeni, coord, pname, param);
  glow_glTexGeni(coord, pname, param);
  glow_post_callback_("glTexGeni", (void*)(ptrdiff_t)glow_glTexGeni, coord, pname, param);
}
PFNGLTEXGENIPROC glow_debug_glTexGeni = glow_debug_impl_glTexGeni;

static void glow_debug_impl_glColor3f(GLfloat red, GLfloat green, GLfloat blue) {

  glow_pre_callback_("glColor3f", (void*)(ptrdiff_t)glow_glColor3f, red, green, blue);
  glow_glColor3f(red, green, blue);
  glow_post_callback_("glColor3f", (void*)(ptrdiff_t)glow_glColor3f, red, green, blue);
}
PFNGLCOLOR3FPROC glow_debug_glColor3f = glow_debug_impl_glColor3f;

static void glow_debug_impl_glRasterPos2fv(const GLfloat *v) {

  glow_pre_callback_("glRasterPos2fv", (void*)(ptrdiff_t)glow_glRasterPos2fv, v);
  glow_glRasterPos2fv(v);
  glow_post_callback_("glRasterPos2fv", (void*)(ptrdiff_t)glow_glRasterPos2fv, v);
}
PFNGLRASTERPOS2FVPROC glow_debug_glRasterPos2fv = glow_debug_impl_glRasterPos2fv;

static void glow_debug_impl_glTexCoord1i(GLint s) {

  glow_pre_callback_("glTexCoord1i", (void*)(ptrdiff_t)glow_glTexCoord1i, s);
  glow_glTexCoord1i(s);
  glow_post_callback_("glTexCoord1i", (void*)(ptrdiff_t)glow_glTexCoord1i, s);
}
PFNGLTEXCOORD1IPROC glow_debug_glTexCoord1i = glow_debug_impl_glTexCoord1i;

static void glow_debug_impl_glIndexMask(GLuint mask) {

  glow_pre_callback_("glIndexMask", (void*)(ptrdiff_t)glow_glIndexMask, mask);
  glow_glIndexMask(mask);
  glow_post_callback_("glIndexMask", (void*)(ptrdiff_t)glow_glIndexMask, mask);
}
PFNGLINDEXMASKPROC glow_debug_glIndexMask = glow_debug_impl_glIndexMask;

static void glow_debug_impl_glHint(GLenum target, GLenum mode) {

  glow_pre_callback_("glHint", (void*)(ptrdiff_t)glow_glHint, target, mode);
  glow_glHint(target, mode);
  glow_post_callback_("glHint", (void*)(ptrdiff_t)glow_glHint, target, mode);
}
PFNGLHINTPROC glow_debug_glHint = glow_debug_impl_glHint;

static void glow_debug_impl_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels) {

  glow_pre_callback_("glGetTexImage", (void*)(ptrdiff_t)glow_glGetTexImage, target, level, format, type, pixels);
  glow_glGetTexImage(target, level, format, type, pixels);
  glow_post_callback_("glGetTexImage", (void*)(ptrdiff_t)glow_glGetTexImage, target, level, format, type, pixels);
}
PFNGLGETTEXIMAGEPROC glow_debug_glGetTexImage = glow_debug_impl_glGetTexImage;

static void glow_debug_impl_glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {

  glow_pre_callback_("glTexCoord4d", (void*)(ptrdiff_t)glow_glTexCoord4d, s, t, r, q);
  glow_glTexCoord4d(s, t, r, q);
  glow_post_callback_("glTexCoord4d", (void*)(ptrdiff_t)glow_glTexCoord4d, s, t, r, q);
}
PFNGLTEXCOORD4DPROC glow_debug_glTexCoord4d = glow_debug_impl_glTexCoord4d;

static void glow_debug_impl_glPopMatrix() {

  glow_pre_callback_("glPopMatrix", (void*)(ptrdiff_t)glow_glPopMatrix);
  glow_glPopMatrix();
  glow_post_callback_("glPopMatrix", (void*)(ptrdiff_t)glow_glPopMatrix);
}
PFNGLPOPMATRIXPROC glow_debug_glPopMatrix = glow_debug_impl_glPopMatrix;

static void glow_debug_impl_glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {

  glow_pre_callback_("glClearAccum", (void*)(ptrdiff_t)glow_glClearAccum, red, green, blue, alpha);
  glow_glClearAccum(red, green, blue, alpha);
  glow_post_callback_("glClearAccum", (void*)(ptrdiff_t)glow_glClearAccum, red, green, blue, alpha);
}
PFNGLCLEARACCUMPROC glow_debug_glClearAccum = glow_debug_impl_glClearAccum;

static void glow_debug_impl_glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {

  glow_pre_callback_("glMapGrid2f", (void*)(ptrdiff_t)glow_glMapGrid2f, un, u1, u2, vn, v1, v2);
  glow_glMapGrid2f(un, u1, u2, vn, v1, v2);
  glow_post_callback_("glMapGrid2f", (void*)(ptrdiff_t)glow_glMapGrid2f, un, u1, u2, vn, v1, v2);
}
PFNGLMAPGRID2FPROC glow_debug_glMapGrid2f = glow_debug_impl_glMapGrid2f;

static void glow_debug_impl_glPixelZoom(GLfloat xfactor, GLfloat yfactor) {

  glow_pre_callback_("glPixelZoom", (void*)(ptrdiff_t)glow_glPixelZoom, xfactor, yfactor);
  glow_glPixelZoom(xfactor, yfactor);
  glow_post_callback_("glPixelZoom", (void*)(ptrdiff_t)glow_glPixelZoom, xfactor, yfactor);
}
PFNGLPIXELZOOMPROC glow_debug_glPixelZoom = glow_debug_impl_glPixelZoom;

static void glow_debug_impl_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {

  glow_pre_callback_("glFrustum", (void*)(ptrdiff_t)glow_glFrustum, left, right, bottom, top, zNear, zFar);
  glow_glFrustum(left, right, bottom, top, zNear, zFar);
  glow_post_callback_("glFrustum", (void*)(ptrdiff_t)glow_glFrustum, left, right, bottom, top, zNear, zFar);
}
PFNGLFRUSTUMPROC glow_debug_glFrustum = glow_debug_impl_glFrustum;

static void glow_debug_impl_glRasterPos4fv(const GLfloat *v) {

  glow_pre_callback_("glRasterPos4fv", (void*)(ptrdiff_t)glow_glRasterPos4fv, v);
  glow_glRasterPos4fv(v);
  glow_post_callback_("glRasterPos4fv", (void*)(ptrdiff_t)glow_glRasterPos4fv, v);
}
PFNGLRASTERPOS4FVPROC glow_debug_glRasterPos4fv = glow_debug_impl_glRasterPos4fv;

static void glow_debug_impl_glVertex3dv(const GLdouble *v) {

  glow_pre_callback_("glVertex3dv", (void*)(ptrdiff_t)glow_glVertex3dv, v);
  glow_glVertex3dv(v);
  glow_post_callback_("glVertex3dv", (void*)(ptrdiff_t)glow_glVertex3dv, v);
}
PFNGLVERTEX3DVPROC glow_debug_glVertex3dv = glow_debug_impl_glVertex3dv;

static void glow_debug_impl_glFogi(GLenum pname, GLint param) {

  glow_pre_callback_("glFogi", (void*)(ptrdiff_t)glow_glFogi, pname, param);
  glow_glFogi(pname, param);
  glow_post_callback_("glFogi", (void*)(ptrdiff_t)glow_glFogi, pname, param);
}
PFNGLFOGIPROC glow_debug_glFogi = glow_debug_impl_glFogi;

static void glow_debug_impl_glLightModeli(GLenum pname, GLint param) {

  glow_pre_callback_("glLightModeli", (void*)(ptrdiff_t)glow_glLightModeli, pname, param);
  glow_glLightModeli(pname, param);
  glow_post_callback_("glLightModeli", (void*)(ptrdiff_t)glow_glLightModeli, pname, param);
}
PFNGLLIGHTMODELIPROC glow_debug_glLightModeli = glow_debug_impl_glLightModeli;

static void glow_debug_impl_glTexCoord1dv(const GLdouble *v) {

  glow_pre_callback_("glTexCoord1dv", (void*)(ptrdiff_t)glow_glTexCoord1dv, v);
  glow_glTexCoord1dv(v);
  glow_post_callback_("glTexCoord1dv", (void*)(ptrdiff_t)glow_glTexCoord1dv, v);
}
PFNGLTEXCOORD1DVPROC glow_debug_glTexCoord1dv = glow_debug_impl_glTexCoord1dv;

static void glow_debug_impl_glVertex2f(GLfloat x, GLfloat y) {

  glow_pre_callback_("glVertex2f", (void*)(ptrdiff_t)glow_glVertex2f, x, y);
  glow_glVertex2f(x, y);
  glow_post_callback_("glVertex2f", (void*)(ptrdiff_t)glow_glVertex2f, x, y);
}
PFNGLVERTEX2FPROC glow_debug_glVertex2f = glow_debug_impl_glVertex2f;

static void glow_debug_impl_glPixelTransferf(GLenum pname, GLfloat param) {

  glow_pre_callback_("glPixelTransferf", (void*)(ptrdiff_t)glow_glPixelTransferf, pname, param);
  glow_glPixelTransferf(pname, param);
  glow_post_callback_("glPixelTransferf", (void*)(ptrdiff_t)glow_glPixelTransferf, pname, param);
}
PFNGLPIXELTRANSFERFPROC glow_debug_glPixelTransferf = glow_debug_impl_glPixelTransferf;

static void glow_debug_impl_glGetMapdv(GLenum target, GLenum query, GLdouble *v) {

  glow_pre_callback_("glGetMapdv", (void*)(ptrdiff_t)glow_glGetMapdv, target, query, v);
  glow_glGetMapdv(target, query, v);
  glow_post_callback_("glGetMapdv", (void*)(ptrdiff_t)glow_glGetMapdv, target, query, v);
}
PFNGLGETMAPDVPROC glow_debug_glGetMapdv = glow_debug_impl_glGetMapdv;

static void glow_debug_impl_glPolygonMode(GLenum face, GLenum mode) {

  glow_pre_callback_("glPolygonMode", (void*)(ptrdiff_t)glow_glPolygonMode, face, mode);
  glow_glPolygonMode(face, mode);
  glow_post_callback_("glPolygonMode", (void*)(ptrdiff_t)glow_glPolygonMode, face, mode);
}
PFNGLPOLYGONMODEPROC glow_debug_glPolygonMode = glow_debug_impl_glPolygonMode;

static void glow_debug_impl_glPixelStoref(GLenum pname, GLfloat param) {

  glow_pre_callback_("glPixelStoref", (void*)(ptrdiff_t)glow_glPixelStoref, pname, param);
  glow_glPixelStoref(pname, param);
  glow_post_callback_("glPixelStoref", (void*)(ptrdiff_t)glow_glPixelStoref, pname, param);
}
PFNGLPIXELSTOREFPROC glow_debug_glPixelStoref = glow_debug_impl_glPixelStoref;

static void glow_debug_impl_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetTexParameterfv", (void*)(ptrdiff_t)glow_glGetTexParameterfv, target, pname, params);
  glow_glGetTexParameterfv(target, pname, params);
  glow_post_callback_("glGetTexParameterfv", (void*)(ptrdiff_t)glow_glGetTexParameterfv, target, pname, params);
}
PFNGLGETTEXPARAMETERFVPROC glow_debug_glGetTexParameterfv = glow_debug_impl_glGetTexParameterfv;

static void glow_debug_impl_glColor4fv(const GLfloat *v) {

  glow_pre_callback_("glColor4fv", (void*)(ptrdiff_t)glow_glColor4fv, v);
  glow_glColor4fv(v);
  glow_post_callback_("glColor4fv", (void*)(ptrdiff_t)glow_glColor4fv, v);
}
PFNGLCOLOR4FVPROC glow_debug_glColor4fv = glow_debug_impl_glColor4fv;

static void glow_debug_impl_glEvalCoord2f(GLfloat u, GLfloat v) {

  glow_pre_callback_("glEvalCoord2f", (void*)(ptrdiff_t)glow_glEvalCoord2f, u, v);
  glow_glEvalCoord2f(u, v);
  glow_post_callback_("glEvalCoord2f", (void*)(ptrdiff_t)glow_glEvalCoord2f, u, v);
}
PFNGLEVALCOORD2FPROC glow_debug_glEvalCoord2f = glow_debug_impl_glEvalCoord2f;

static void glow_debug_impl_glNormal3dv(const GLdouble *v) {

  glow_pre_callback_("glNormal3dv", (void*)(ptrdiff_t)glow_glNormal3dv, v);
  glow_glNormal3dv(v);
  glow_post_callback_("glNormal3dv", (void*)(ptrdiff_t)glow_glNormal3dv, v);
}
PFNGLNORMAL3DVPROC glow_debug_glNormal3dv = glow_debug_impl_glNormal3dv;

static void glow_debug_impl_glMateriali(GLenum face, GLenum pname, GLint param) {

  glow_pre_callback_("glMateriali", (void*)(ptrdiff_t)glow_glMateriali, face, pname, param);
  glow_glMateriali(face, pname, param);
  glow_post_callback_("glMateriali", (void*)(ptrdiff_t)glow_glMateriali, face, pname, param);
}
PFNGLMATERIALIPROC glow_debug_glMateriali = glow_debug_impl_glMateriali;

static void glow_debug_impl_glPushName(GLuint name) {

  glow_pre_callback_("glPushName", (void*)(ptrdiff_t)glow_glPushName, name);
  glow_glPushName(name);
  glow_post_callback_("glPushName", (void*)(ptrdiff_t)glow_glPushName, name);
}
PFNGLPUSHNAMEPROC glow_debug_glPushName = glow_debug_impl_glPushName;

static void glow_debug_impl_glAccum(GLenum op, GLfloat value) {

  glow_pre_callback_("glAccum", (void*)(ptrdiff_t)glow_glAccum, op, value);
  glow_glAccum(op, value);
  glow_post_callback_("glAccum", (void*)(ptrdiff_t)glow_glAccum, op, value);
}
PFNGLACCUMPROC glow_debug_glAccum = glow_debug_impl_glAccum;

static void glow_debug_impl_glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {

  glow_pre_callback_("glRecti", (void*)(ptrdiff_t)glow_glRecti, x1, y1, x2, y2);
  glow_glRecti(x1, y1, x2, y2);
  glow_post_callback_("glRecti", (void*)(ptrdiff_t)glow_glRecti, x1, y1, x2, y2);
}
PFNGLRECTIPROC glow_debug_glRecti = glow_debug_impl_glRecti;

static void glow_debug_impl_glTexCoord2sv(const GLshort *v) {

  glow_pre_callback_("glTexCoord2sv", (void*)(ptrdiff_t)glow_glTexCoord2sv, v);
  glow_glTexCoord2sv(v);
  glow_post_callback_("glTexCoord2sv", (void*)(ptrdiff_t)glow_glTexCoord2sv, v);
}
PFNGLTEXCOORD2SVPROC glow_debug_glTexCoord2sv = glow_debug_impl_glTexCoord2sv;

static void glow_debug_impl_glVertex2sv(const GLshort *v) {

  glow_pre_callback_("glVertex2sv", (void*)(ptrdiff_t)glow_glVertex2sv, v);
  glow_glVertex2sv(v);
  glow_post_callback_("glVertex2sv", (void*)(ptrdiff_t)glow_glVertex2sv, v);
}
PFNGLVERTEX2SVPROC glow_debug_glVertex2sv = glow_debug_impl_glVertex2sv;

static void glow_debug_impl_glDepthMask(GLboolean flag) {

  glow_pre_callback_("glDepthMask", (void*)(ptrdiff_t)glow_glDepthMask, flag);
  glow_glDepthMask(flag);
  glow_post_callback_("glDepthMask", (void*)(ptrdiff_t)glow_glDepthMask, flag);
}
PFNGLDEPTHMASKPROC glow_debug_glDepthMask = glow_debug_impl_glDepthMask;

static void glow_debug_impl_glPixelStorei(GLenum pname, GLint param) {

  glow_pre_callback_("glPixelStorei", (void*)(ptrdiff_t)glow_glPixelStorei, pname, param);
  glow_glPixelStorei(pname, param);
  glow_post_callback_("glPixelStorei", (void*)(ptrdiff_t)glow_glPixelStorei, pname, param);
}
PFNGLPIXELSTOREIPROC glow_debug_glPixelStorei = glow_debug_impl_glPixelStorei;

static GLboolean glow_debug_impl_glIsEnabled(GLenum cap) {

  GLboolean ret;
  glow_pre_callback_("glIsEnabled", (void*)(ptrdiff_t)glow_glIsEnabled, cap);
  ret = glow_glIsEnabled(cap);
  glow_post_callback_("glIsEnabled", (void*)(ptrdiff_t)glow_glIsEnabled, cap);
  return ret;
}
PFNGLISENABLEDPROC glow_debug_glIsEnabled = glow_debug_impl_glIsEnabled;

static void glow_debug_impl_glColor3uiv(const GLuint *v) {

  glow_pre_callback_("glColor3uiv", (void*)(ptrdiff_t)glow_glColor3uiv, v);
  glow_glColor3uiv(v);
  glow_post_callback_("glColor3uiv", (void*)(ptrdiff_t)glow_glColor3uiv, v);
}
PFNGLCOLOR3UIVPROC glow_debug_glColor3uiv = glow_debug_impl_glColor3uiv;

static void glow_debug_impl_glFinish() {

  glow_pre_callback_("glFinish", (void*)(ptrdiff_t)glow_glFinish);
  glow_glFinish();
  glow_post_callback_("glFinish", (void*)(ptrdiff_t)glow_glFinish);
}
PFNGLFINISHPROC glow_debug_glFinish = glow_debug_impl_glFinish;

static void glow_debug_impl_glVertex2fv(const GLfloat *v) {

  glow_pre_callback_("glVertex2fv", (void*)(ptrdiff_t)glow_glVertex2fv, v);
  glow_glVertex2fv(v);
  glow_post_callback_("glVertex2fv", (void*)(ptrdiff_t)glow_glVertex2fv, v);
}
PFNGLVERTEX2FVPROC glow_debug_glVertex2fv = glow_debug_impl_glVertex2fv;

static void glow_debug_impl_glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {

  glow_pre_callback_("glVertex4d", (void*)(ptrdiff_t)glow_glVertex4d, x, y, z, w);
  glow_glVertex4d(x, y, z, w);
  glow_post_callback_("glVertex4d", (void*)(ptrdiff_t)glow_glVertex4d, x, y, z, w);
}
PFNGLVERTEX4DPROC glow_debug_glVertex4d = glow_debug_impl_glVertex4d;

static void glow_debug_impl_glColor3fv(const GLfloat *v) {

  glow_pre_callback_("glColor3fv", (void*)(ptrdiff_t)glow_glColor3fv, v);
  glow_glColor3fv(v);
  glow_post_callback_("glColor3fv", (void*)(ptrdiff_t)glow_glColor3fv, v);
}
PFNGLCOLOR3FVPROC glow_debug_glColor3fv = glow_debug_impl_glColor3fv;

static void glow_debug_impl_glPassThrough(GLfloat token) {

  glow_pre_callback_("glPassThrough", (void*)(ptrdiff_t)glow_glPassThrough, token);
  glow_glPassThrough(token);
  glow_post_callback_("glPassThrough", (void*)(ptrdiff_t)glow_glPassThrough, token);
}
PFNGLPASSTHROUGHPROC glow_debug_glPassThrough = glow_debug_impl_glPassThrough;

static void glow_debug_impl_glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {

  glow_pre_callback_("glMapGrid1f", (void*)(ptrdiff_t)glow_glMapGrid1f, un, u1, u2);
  glow_glMapGrid1f(un, u1, u2);
  glow_post_callback_("glMapGrid1f", (void*)(ptrdiff_t)glow_glMapGrid1f, un, u1, u2);
}
PFNGLMAPGRID1FPROC glow_debug_glMapGrid1f = glow_debug_impl_glMapGrid1f;

static void glow_debug_impl_glEvalCoord1d(GLdouble u) {

  glow_pre_callback_("glEvalCoord1d", (void*)(ptrdiff_t)glow_glEvalCoord1d, u);
  glow_glEvalCoord1d(u);
  glow_post_callback_("glEvalCoord1d", (void*)(ptrdiff_t)glow_glEvalCoord1d, u);
}
PFNGLEVALCOORD1DPROC glow_debug_glEvalCoord1d = glow_debug_impl_glEvalCoord1d;

static void glow_debug_impl_glGetMaterialiv(GLenum face, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetMaterialiv", (void*)(ptrdiff_t)glow_glGetMaterialiv, face, pname, params);
  glow_glGetMaterialiv(face, pname, params);
  glow_post_callback_("glGetMaterialiv", (void*)(ptrdiff_t)glow_glGetMaterialiv, face, pname, params);
}
PFNGLGETMATERIALIVPROC glow_debug_glGetMaterialiv = glow_debug_impl_glGetMaterialiv;

static void glow_debug_impl_glIndexfv(const GLfloat *c) {

  glow_pre_callback_("glIndexfv", (void*)(ptrdiff_t)glow_glIndexfv, c);
  glow_glIndexfv(c);
  glow_post_callback_("glIndexfv", (void*)(ptrdiff_t)glow_glIndexfv, c);
}
PFNGLINDEXFVPROC glow_debug_glIndexfv = glow_debug_impl_glIndexfv;

static void glow_debug_impl_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {

  glow_pre_callback_("glNormal3f", (void*)(ptrdiff_t)glow_glNormal3f, nx, ny, nz);
  glow_glNormal3f(nx, ny, nz);
  glow_post_callback_("glNormal3f", (void*)(ptrdiff_t)glow_glNormal3f, nx, ny, nz);
}
PFNGLNORMAL3FPROC glow_debug_glNormal3f = glow_debug_impl_glNormal3f;

static void glow_debug_impl_glNormal3fv(const GLfloat *v) {

  glow_pre_callback_("glNormal3fv", (void*)(ptrdiff_t)glow_glNormal3fv, v);
  glow_glNormal3fv(v);
  glow_post_callback_("glNormal3fv", (void*)(ptrdiff_t)glow_glNormal3fv, v);
}
PFNGLNORMAL3FVPROC glow_debug_glNormal3fv = glow_debug_impl_glNormal3fv;

static void glow_debug_impl_glVertex4dv(const GLdouble *v) {

  glow_pre_callback_("glVertex4dv", (void*)(ptrdiff_t)glow_glVertex4dv, v);
  glow_glVertex4dv(v);
  glow_post_callback_("glVertex4dv", (void*)(ptrdiff_t)glow_glVertex4dv, v);
}
PFNGLVERTEX4DVPROC glow_debug_glVertex4dv = glow_debug_impl_glVertex4dv;

static void glow_debug_impl_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {

  glow_pre_callback_("glMapGrid2d", (void*)(ptrdiff_t)glow_glMapGrid2d, un, u1, u2, vn, v1, v2);
  glow_glMapGrid2d(un, u1, u2, vn, v1, v2);
  glow_post_callback_("glMapGrid2d", (void*)(ptrdiff_t)glow_glMapGrid2d, un, u1, u2, vn, v1, v2);
}
PFNGLMAPGRID2DPROC glow_debug_glMapGrid2d = glow_debug_impl_glMapGrid2d;

static void glow_debug_impl_glPointSize(GLfloat size) {

  glow_pre_callback_("glPointSize", (void*)(ptrdiff_t)glow_glPointSize, size);
  glow_glPointSize(size);
  glow_post_callback_("glPointSize", (void*)(ptrdiff_t)glow_glPointSize, size);
}
PFNGLPOINTSIZEPROC glow_debug_glPointSize = glow_debug_impl_glPointSize;

static void glow_debug_impl_glEdgeFlag(GLboolean flag) {

  glow_pre_callback_("glEdgeFlag", (void*)(ptrdiff_t)glow_glEdgeFlag, flag);
  glow_glEdgeFlag(flag);
  glow_post_callback_("glEdgeFlag", (void*)(ptrdiff_t)glow_glEdgeFlag, flag);
}
PFNGLEDGEFLAGPROC glow_debug_glEdgeFlag = glow_debug_impl_glEdgeFlag;

static void glow_debug_impl_glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {

  glow_pre_callback_("glTexCoord4i", (void*)(ptrdiff_t)glow_glTexCoord4i, s, t, r, q);
  glow_glTexCoord4i(s, t, r, q);
  glow_post_callback_("glTexCoord4i", (void*)(ptrdiff_t)glow_glTexCoord4i, s, t, r, q);
}
PFNGLTEXCOORD4IPROC glow_debug_glTexCoord4i = glow_debug_impl_glTexCoord4i;

static void glow_debug_impl_glMaterialf(GLenum face, GLenum pname, GLfloat param) {

  glow_pre_callback_("glMaterialf", (void*)(ptrdiff_t)glow_glMaterialf, face, pname, param);
  glow_glMaterialf(face, pname, param);
  glow_post_callback_("glMaterialf", (void*)(ptrdiff_t)glow_glMaterialf, face, pname, param);
}
PFNGLMATERIALFPROC glow_debug_glMaterialf = glow_debug_impl_glMaterialf;

static void glow_debug_impl_glGetLightfv(GLenum light, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetLightfv", (void*)(ptrdiff_t)glow_glGetLightfv, light, pname, params);
  glow_glGetLightfv(light, pname, params);
  glow_post_callback_("glGetLightfv", (void*)(ptrdiff_t)glow_glGetLightfv, light, pname, params);
}
PFNGLGETLIGHTFVPROC glow_debug_glGetLightfv = glow_debug_impl_glGetLightfv;

static void glow_debug_impl_glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {

  glow_pre_callback_("glColor3ub", (void*)(ptrdiff_t)glow_glColor3ub, red, green, blue);
  glow_glColor3ub(red, green, blue);
  glow_post_callback_("glColor3ub", (void*)(ptrdiff_t)glow_glColor3ub, red, green, blue);
}
PFNGLCOLOR3UBPROC glow_debug_glColor3ub = glow_debug_impl_glColor3ub;

static void glow_debug_impl_glEnd() {

  glow_pre_callback_("glEnd", (void*)(ptrdiff_t)glow_glEnd);
  glow_glEnd();
  glow_post_callback_("glEnd", (void*)(ptrdiff_t)glow_glEnd);
}
PFNGLENDPROC glow_debug_glEnd = glow_debug_impl_glEnd;

static void glow_debug_impl_glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {

  glow_pre_callback_("glNormal3b", (void*)(ptrdiff_t)glow_glNormal3b, nx, ny, nz);
  glow_glNormal3b(nx, ny, nz);
  glow_post_callback_("glNormal3b", (void*)(ptrdiff_t)glow_glNormal3b, nx, ny, nz);
}
PFNGLNORMAL3BPROC glow_debug_glNormal3b = glow_debug_impl_glNormal3b;

static void glow_debug_impl_glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {

  glow_pre_callback_("glRasterPos4i", (void*)(ptrdiff_t)glow_glRasterPos4i, x, y, z, w);
  glow_glRasterPos4i(x, y, z, w);
  glow_post_callback_("glRasterPos4i", (void*)(ptrdiff_t)glow_glRasterPos4i, x, y, z, w);
}
PFNGLRASTERPOS4IPROC glow_debug_glRasterPos4i = glow_debug_impl_glRasterPos4i;

static void glow_debug_impl_glVertex2dv(const GLdouble *v) {

  glow_pre_callback_("glVertex2dv", (void*)(ptrdiff_t)glow_glVertex2dv, v);
  glow_glVertex2dv(v);
  glow_post_callback_("glVertex2dv", (void*)(ptrdiff_t)glow_glVertex2dv, v);
}
PFNGLVERTEX2DVPROC glow_debug_glVertex2dv = glow_debug_impl_glVertex2dv;

static void glow_debug_impl_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {

  glow_pre_callback_("glClearColor", (void*)(ptrdiff_t)glow_glClearColor, red, green, blue, alpha);
  glow_glClearColor(red, green, blue, alpha);
  glow_post_callback_("glClearColor", (void*)(ptrdiff_t)glow_glClearColor, red, green, blue, alpha);
}
PFNGLCLEARCOLORPROC glow_debug_glClearColor = glow_debug_impl_glClearColor;

static void glow_debug_impl_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) {

  glow_pre_callback_("glGetTexParameteriv", (void*)(ptrdiff_t)glow_glGetTexParameteriv, target, pname, params);
  glow_glGetTexParameteriv(target, pname, params);
  glow_post_callback_("glGetTexParameteriv", (void*)(ptrdiff_t)glow_glGetTexParameteriv, target, pname, params);
}
PFNGLGETTEXPARAMETERIVPROC glow_debug_glGetTexParameteriv = glow_debug_impl_glGetTexParameteriv;

static void glow_debug_impl_glBegin(GLenum mode) {

  glow_pre_callback_("glBegin", (void*)(ptrdiff_t)glow_glBegin, mode);
  glow_glBegin(mode);
  glow_post_callback_("glBegin", (void*)(ptrdiff_t)glow_glBegin, mode);
}
PFNGLBEGINPROC glow_debug_glBegin = glow_debug_impl_glBegin;

static void glow_debug_impl_glRectsv(const GLshort *v1, const GLshort *v2) {

  glow_pre_callback_("glRectsv", (void*)(ptrdiff_t)glow_glRectsv, v1, v2);
  glow_glRectsv(v1, v2);
  glow_post_callback_("glRectsv", (void*)(ptrdiff_t)glow_glRectsv, v1, v2);
}
PFNGLRECTSVPROC glow_debug_glRectsv = glow_debug_impl_glRectsv;

static void glow_debug_impl_glEvalCoord1fv(const GLfloat *u) {

  glow_pre_callback_("glEvalCoord1fv", (void*)(ptrdiff_t)glow_glEvalCoord1fv, u);
  glow_glEvalCoord1fv(u);
  glow_post_callback_("glEvalCoord1fv", (void*)(ptrdiff_t)glow_glEvalCoord1fv, u);
}
PFNGLEVALCOORD1FVPROC glow_debug_glEvalCoord1fv = glow_debug_impl_glEvalCoord1fv;

static void glow_debug_impl_glMultMatrixd(const GLdouble *m) {

  glow_pre_callback_("glMultMatrixd", (void*)(ptrdiff_t)glow_glMultMatrixd, m);
  glow_glMultMatrixd(m);
  glow_post_callback_("glMultMatrixd", (void*)(ptrdiff_t)glow_glMultMatrixd, m);
}
PFNGLMULTMATRIXDPROC glow_debug_glMultMatrixd = glow_debug_impl_glMultMatrixd;

static void glow_debug_impl_glNormal3bv(const GLbyte *v) {

  glow_pre_callback_("glNormal3bv", (void*)(ptrdiff_t)glow_glNormal3bv, v);
  glow_glNormal3bv(v);
  glow_post_callback_("glNormal3bv", (void*)(ptrdiff_t)glow_glNormal3bv, v);
}
PFNGLNORMAL3BVPROC glow_debug_glNormal3bv = glow_debug_impl_glNormal3bv;

static void glow_debug_impl_glVertex2i(GLint x, GLint y) {

  glow_pre_callback_("glVertex2i", (void*)(ptrdiff_t)glow_glVertex2i, x, y);
  glow_glVertex2i(x, y);
  glow_post_callback_("glVertex2i", (void*)(ptrdiff_t)glow_glVertex2i, x, y);
}
PFNGLVERTEX2IPROC glow_debug_glVertex2i = glow_debug_impl_glVertex2i;

static void glow_debug_impl_glStencilMask(GLuint mask) {

  glow_pre_callback_("glStencilMask", (void*)(ptrdiff_t)glow_glStencilMask, mask);
  glow_glStencilMask(mask);
  glow_post_callback_("glStencilMask", (void*)(ptrdiff_t)glow_glStencilMask, mask);
}
PFNGLSTENCILMASKPROC glow_debug_glStencilMask = glow_debug_impl_glStencilMask;

static void glow_debug_impl_glDeleteLists(GLuint list, GLsizei range) {

  glow_pre_callback_("glDeleteLists", (void*)(ptrdiff_t)glow_glDeleteLists, list, range);
  glow_glDeleteLists(list, range);
  glow_post_callback_("glDeleteLists", (void*)(ptrdiff_t)glow_glDeleteLists, list, range);
}
PFNGLDELETELISTSPROC glow_debug_glDeleteLists = glow_debug_impl_glDeleteLists;

static void glow_debug_impl_glColor3iv(const GLint *v) {

  glow_pre_callback_("glColor3iv", (void*)(ptrdiff_t)glow_glColor3iv, v);
  glow_glColor3iv(v);
  glow_post_callback_("glColor3iv", (void*)(ptrdiff_t)glow_glColor3iv, v);
}
PFNGLCOLOR3IVPROC glow_debug_glColor3iv = glow_debug_impl_glColor3iv;

static void glow_debug_impl_glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {

  glow_pre_callback_("glColor4us", (void*)(ptrdiff_t)glow_glColor4us, red, green, blue, alpha);
  glow_glColor4us(red, green, blue, alpha);
  glow_post_callback_("glColor4us", (void*)(ptrdiff_t)glow_glColor4us, red, green, blue, alpha);
}
PFNGLCOLOR4USPROC glow_debug_glColor4us = glow_debug_impl_glColor4us;

static void glow_debug_impl_glSelectBuffer(GLsizei size, GLuint *buffer) {

  glow_pre_callback_("glSelectBuffer", (void*)(ptrdiff_t)glow_glSelectBuffer, size, buffer);
  glow_glSelectBuffer(size, buffer);
  glow_post_callback_("glSelectBuffer", (void*)(ptrdiff_t)glow_glSelectBuffer, size, buffer);
}
PFNGLSELECTBUFFERPROC glow_debug_glSelectBuffer = glow_debug_impl_glSelectBuffer;

static void glow_debug_impl_glRasterPos2iv(const GLint *v) {

  glow_pre_callback_("glRasterPos2iv", (void*)(ptrdiff_t)glow_glRasterPos2iv, v);
  glow_glRasterPos2iv(v);
  glow_post_callback_("glRasterPos2iv", (void*)(ptrdiff_t)glow_glRasterPos2iv, v);
}
PFNGLRASTERPOS2IVPROC glow_debug_glRasterPos2iv = glow_debug_impl_glRasterPos2iv;

static void glow_debug_impl_glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {

  glow_pre_callback_("glRasterPos4s", (void*)(ptrdiff_t)glow_glRasterPos4s, x, y, z, w);
  glow_glRasterPos4s(x, y, z, w);
  glow_post_callback_("glRasterPos4s", (void*)(ptrdiff_t)glow_glRasterPos4s, x, y, z, w);
}
PFNGLRASTERPOS4SPROC glow_debug_glRasterPos4s = glow_debug_impl_glRasterPos4s;

static void glow_debug_impl_glVertex4fv(const GLfloat *v) {

  glow_pre_callback_("glVertex4fv", (void*)(ptrdiff_t)glow_glVertex4fv, v);
  glow_glVertex4fv(v);
  glow_post_callback_("glVertex4fv", (void*)(ptrdiff_t)glow_glVertex4fv, v);
}
PFNGLVERTEX4FVPROC glow_debug_glVertex4fv = glow_debug_impl_glVertex4fv;

static void glow_debug_impl_glVertex4iv(const GLint *v) {

  glow_pre_callback_("glVertex4iv", (void*)(ptrdiff_t)glow_glVertex4iv, v);
  glow_glVertex4iv(v);
  glow_post_callback_("glVertex4iv", (void*)(ptrdiff_t)glow_glVertex4iv, v);
}
PFNGLVERTEX4IVPROC glow_debug_glVertex4iv = glow_debug_impl_glVertex4iv;

static void glow_debug_impl_glCullFace(GLenum mode) {

  glow_pre_callback_("glCullFace", (void*)(ptrdiff_t)glow_glCullFace, mode);
  glow_glCullFace(mode);
  glow_post_callback_("glCullFace", (void*)(ptrdiff_t)glow_glCullFace, mode);
}
PFNGLCULLFACEPROC glow_debug_glCullFace = glow_debug_impl_glCullFace;

static void glow_debug_impl_glGetFloatv(GLenum pname, GLfloat *data) {

  glow_pre_callback_("glGetFloatv", (void*)(ptrdiff_t)glow_glGetFloatv, pname, data);
  glow_glGetFloatv(pname, data);
  glow_post_callback_("glGetFloatv", (void*)(ptrdiff_t)glow_glGetFloatv, pname, data);
}
PFNGLGETFLOATVPROC glow_debug_glGetFloatv = glow_debug_impl_glGetFloatv;

static void glow_debug_impl_glDepthRange(GLdouble near, GLdouble far) {

  glow_pre_callback_("glDepthRange", (void*)(ptrdiff_t)glow_glDepthRange, near, far);
  glow_glDepthRange(near, far);
  glow_post_callback_("glDepthRange", (void*)(ptrdiff_t)glow_glDepthRange, near, far);
}
PFNGLDEPTHRANGEPROC glow_debug_glDepthRange = glow_debug_impl_glDepthRange;

static void glow_debug_impl_glIndexiv(const GLint *c) {

  glow_pre_callback_("glIndexiv", (void*)(ptrdiff_t)glow_glIndexiv, c);
  glow_glIndexiv(c);
  glow_post_callback_("glIndexiv", (void*)(ptrdiff_t)glow_glIndexiv, c);
}
PFNGLINDEXIVPROC glow_debug_glIndexiv = glow_debug_impl_glIndexiv;

static void glow_debug_impl_glEndList() {

  glow_pre_callback_("glEndList", (void*)(ptrdiff_t)glow_glEndList);
  glow_glEndList();
  glow_post_callback_("glEndList", (void*)(ptrdiff_t)glow_glEndList);
}
PFNGLENDLISTPROC glow_debug_glEndList = glow_debug_impl_glEndList;

static void glow_debug_impl_glRasterPos2s(GLshort x, GLshort y) {

  glow_pre_callback_("glRasterPos2s", (void*)(ptrdiff_t)glow_glRasterPos2s, x, y);
  glow_glRasterPos2s(x, y);
  glow_post_callback_("glRasterPos2s", (void*)(ptrdiff_t)glow_glRasterPos2s, x, y);
}
PFNGLRASTERPOS2SPROC glow_debug_glRasterPos2s = glow_debug_impl_glRasterPos2s;

static void glow_debug_impl_glTexCoord3iv(const GLint *v) {

  glow_pre_callback_("glTexCoord3iv", (void*)(ptrdiff_t)glow_glTexCoord3iv, v);
  glow_glTexCoord3iv(v);
  glow_post_callback_("glTexCoord3iv", (void*)(ptrdiff_t)glow_glTexCoord3iv, v);
}
PFNGLTEXCOORD3IVPROC glow_debug_glTexCoord3iv = glow_debug_impl_glTexCoord3iv;

static void glow_debug_impl_glEvalPoint2(GLint i, GLint j) {

  glow_pre_callback_("glEvalPoint2", (void*)(ptrdiff_t)glow_glEvalPoint2, i, j);
  glow_glEvalPoint2(i, j);
  glow_post_callback_("glEvalPoint2", (void*)(ptrdiff_t)glow_glEvalPoint2, i, j);
}
PFNGLEVALPOINT2PROC glow_debug_glEvalPoint2 = glow_debug_impl_glEvalPoint2;

static void glow_debug_impl_glTexGenf(GLenum coord, GLenum pname, GLfloat param) {

  glow_pre_callback_("glTexGenf", (void*)(ptrdiff_t)glow_glTexGenf, coord, pname, param);
  glow_glTexGenf(coord, pname, param);
  glow_post_callback_("glTexGenf", (void*)(ptrdiff_t)glow_glTexGenf, coord, pname, param);
}
PFNGLTEXGENFPROC glow_debug_glTexGenf = glow_debug_impl_glTexGenf;

static void glow_debug_impl_glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params) {

  glow_pre_callback_("glGetMaterialfv", (void*)(ptrdiff_t)glow_glGetMaterialfv, face, pname, params);
  glow_glGetMaterialfv(face, pname, params);
  glow_post_callback_("glGetMaterialfv", (void*)(ptrdiff_t)glow_glGetMaterialfv, face, pname, params);
}
PFNGLGETMATERIALFVPROC glow_debug_glGetMaterialfv = glow_debug_impl_glGetMaterialfv;

static void glow_debug_impl_glGetDoublev(GLenum pname, GLdouble *data) {

  glow_pre_callback_("glGetDoublev", (void*)(ptrdiff_t)glow_glGetDoublev, pname, data);
  glow_glGetDoublev(pname, data);
  glow_post_callback_("glGetDoublev", (void*)(ptrdiff_t)glow_glGetDoublev, pname, data);
}
PFNGLGETDOUBLEVPROC glow_debug_glGetDoublev = glow_debug_impl_glGetDoublev;

static void glow_debug_impl_glNewList(GLuint list, GLenum mode) {

  glow_pre_callback_("glNewList", (void*)(ptrdiff_t)glow_glNewList, list, mode);
  glow_glNewList(list, mode);
  glow_post_callback_("glNewList", (void*)(ptrdiff_t)glow_glNewList, list, mode);
}
PFNGLNEWLISTPROC glow_debug_glNewList = glow_debug_impl_glNewList;

static void glow_debug_impl_glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {

  glow_pre_callback_("glRects", (void*)(ptrdiff_t)glow_glRects, x1, y1, x2, y2);
  glow_glRects(x1, y1, x2, y2);
  glow_post_callback_("glRects", (void*)(ptrdiff_t)glow_glRects, x1, y1, x2, y2);
}
PFNGLRECTSPROC glow_debug_glRects = glow_debug_impl_glRects;

static void glow_debug_impl_glLightModelf(GLenum pname, GLfloat param) {

  glow_pre_callback_("glLightModelf", (void*)(ptrdiff_t)glow_glLightModelf, pname, param);
  glow_glLightModelf(pname, param);
  glow_post_callback_("glLightModelf", (void*)(ptrdiff_t)glow_glLightModelf, pname, param);
}
PFNGLLIGHTMODELFPROC glow_debug_glLightModelf = glow_debug_impl_glLightModelf;

static void glow_debug_impl_glLightModeliv(GLenum pname, const GLint *params) {

  glow_pre_callback_("glLightModeliv", (void*)(ptrdiff_t)glow_glLightModeliv, pname, params);
  glow_glLightModeliv(pname, params);
  glow_post_callback_("glLightModeliv", (void*)(ptrdiff_t)glow_glLightModeliv, pname, params);
}
PFNGLLIGHTMODELIVPROC glow_debug_glLightModeliv = glow_debug_impl_glLightModeliv;

static void glow_debug_impl_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) {

  glow_pre_callback_("glTexParameterfv", (void*)(ptrdiff_t)glow_glTexParameterfv, target, pname, params);
  glow_glTexParameterfv(target, pname, params);
  glow_post_callback_("glTexParameterfv", (void*)(ptrdiff_t)glow_glTexParameterfv, target, pname, params);
}
PFNGLTEXPARAMETERFVPROC glow_debug_glTexParameterfv = glow_debug_impl_glTexParameterfv;

static void glow_debug_impl_glEnable(GLenum cap) {

  glow_pre_callback_("glEnable", (void*)(ptrdiff_t)glow_glEnable, cap);
  glow_glEnable(cap);
  glow_post_callback_("glEnable", (void*)(ptrdiff_t)glow_glEnable, cap);
}
PFNGLENABLEPROC glow_debug_glEnable = glow_debug_impl_glEnable;

static void glow_debug_impl_glTexCoord1iv(const GLint *v) {

  glow_pre_callback_("glTexCoord1iv", (void*)(ptrdiff_t)glow_glTexCoord1iv, v);
  glow_glTexCoord1iv(v);
  glow_post_callback_("glTexCoord1iv", (void*)(ptrdiff_t)glow_glTexCoord1iv, v);
}
PFNGLTEXCOORD1IVPROC glow_debug_glTexCoord1iv = glow_debug_impl_glTexCoord1iv;

static void glow_debug_impl_glVertex3sv(const GLshort *v) {

  glow_pre_callback_("glVertex3sv", (void*)(ptrdiff_t)glow_glVertex3sv, v);
  glow_glVertex3sv(v);
  glow_post_callback_("glVertex3sv", (void*)(ptrdiff_t)glow_glVertex3sv, v);
}
PFNGLVERTEX3SVPROC glow_debug_glVertex3sv = glow_debug_impl_glVertex3sv;

static void glow_debug_impl_glRasterPos2d(GLdouble x, GLdouble y) {

  glow_pre_callback_("glRasterPos2d", (void*)(ptrdiff_t)glow_glRasterPos2d, x, y);
  glow_glRasterPos2d(x, y);
  glow_post_callback_("glRasterPos2d", (void*)(ptrdiff_t)glow_glRasterPos2d, x, y);
}
PFNGLRASTERPOS2DPROC glow_debug_glRasterPos2d = glow_debug_impl_glRasterPos2d;

static void glow_debug_impl_glFogiv(GLenum pname, const GLint *params) {

  glow_pre_callback_("glFogiv", (void*)(ptrdiff_t)glow_glFogiv, pname, params);
  glow_glFogiv(pname, params);
  glow_post_callback_("glFogiv", (void*)(ptrdiff_t)glow_glFogiv, pname, params);
}
PFNGLFOGIVPROC glow_debug_glFogiv = glow_debug_impl_glFogiv;

static void glow_debug_impl_glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) {

  glow_pre_callback_("glTexGendv", (void*)(ptrdiff_t)glow_glTexGendv, coord, pname, params);
  glow_glTexGendv(coord, pname, params);
  glow_post_callback_("glTexGendv", (void*)(ptrdiff_t)glow_glTexGendv, coord, pname, params);
}
PFNGLTEXGENDVPROC glow_debug_glTexGendv = glow_debug_impl_glTexGendv;

static void glow_debug_impl_glColorMaterial(GLenum face, GLenum mode) {

  glow_pre_callback_("glColorMaterial", (void*)(ptrdiff_t)glow_glColorMaterial, face, mode);
  glow_glColorMaterial(face, mode);
  glow_post_callback_("glColorMaterial", (void*)(ptrdiff_t)glow_glColorMaterial, face, mode);
}
PFNGLCOLORMATERIALPROC glow_debug_glColorMaterial = glow_debug_impl_glColorMaterial;

static void glow_debug_impl_glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {

  glow_pre_callback_("glEvalMesh2", (void*)(ptrdiff_t)glow_glEvalMesh2, mode, i1, i2, j1, j2);
  glow_glEvalMesh2(mode, i1, i2, j1, j2);
  glow_post_callback_("glEvalMesh2", (void*)(ptrdiff_t)glow_glEvalMesh2, mode, i1, i2, j1, j2);
}
PFNGLEVALMESH2PROC glow_debug_glEvalMesh2 = glow_debug_impl_glEvalMesh2;

static void glow_debug_impl_glLoadIdentity() {

  glow_pre_callback_("glLoadIdentity", (void*)(ptrdiff_t)glow_glLoadIdentity);
  glow_glLoadIdentity();
  glow_post_callback_("glLoadIdentity", (void*)(ptrdiff_t)glow_glLoadIdentity);
}
PFNGLLOADIDENTITYPROC glow_debug_glLoadIdentity = glow_debug_impl_glLoadIdentity;

static void glow_debug_impl_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {

  glow_pre_callback_("glStencilOp", (void*)(ptrdiff_t)glow_glStencilOp, fail, zfail, zpass);
  glow_glStencilOp(fail, zfail, zpass);
  glow_post_callback_("glStencilOp", (void*)(ptrdiff_t)glow_glStencilOp, fail, zfail, zpass);
}
PFNGLSTENCILOPPROC glow_debug_glStencilOp = glow_debug_impl_glStencilOp;

static void glow_debug_impl_glRectdv(const GLdouble *v1, const GLdouble *v2) {

  glow_pre_callback_("glRectdv", (void*)(ptrdiff_t)glow_glRectdv, v1, v2);
  glow_glRectdv(v1, v2);
  glow_post_callback_("glRectdv", (void*)(ptrdiff_t)glow_glRectdv, v1, v2);
}
PFNGLRECTDVPROC glow_debug_glRectdv = glow_debug_impl_glRectdv;

static void glow_debug_impl_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {

  glow_pre_callback_("glTexCoord3f", (void*)(ptrdiff_t)glow_glTexCoord3f, s, t, r);
  glow_glTexCoord3f(s, t, r);
  glow_post_callback_("glTexCoord3f", (void*)(ptrdiff_t)glow_glTexCoord3f, s, t, r);
}
PFNGLTEXCOORD3FPROC glow_debug_glTexCoord3f = glow_debug_impl_glTexCoord3f;

static void glow_debug_impl_glVertex3d(GLdouble x, GLdouble y, GLdouble z) {

  glow_pre_callback_("glVertex3d", (void*)(ptrdiff_t)glow_glVertex3d, x, y, z);
  glow_glVertex3d(x, y, z);
  glow_post_callback_("glVertex3d", (void*)(ptrdiff_t)glow_glVertex3d, x, y, z);
}
PFNGLVERTEX3DPROC glow_debug_glVertex3d = glow_debug_impl_glVertex3d;

static void glow_debug_impl_glVertex4sv(const GLshort *v) {

  glow_pre_callback_("glVertex4sv", (void*)(ptrdiff_t)glow_glVertex4sv, v);
  glow_glVertex4sv(v);
  glow_post_callback_("glVertex4sv", (void*)(ptrdiff_t)glow_glVertex4sv, v);
}
PFNGLVERTEX4SVPROC glow_debug_glVertex4sv = glow_debug_impl_glVertex4sv;

static void glow_debug_impl_glScaled(GLdouble x, GLdouble y, GLdouble z) {

  glow_pre_callback_("glScaled", (void*)(ptrdiff_t)glow_glScaled, x, y, z);
  glow_glScaled(x, y, z);
  glow_post_callback_("glScaled", (void*)(ptrdiff_t)glow_glScaled, x, y, z);
}
PFNGLSCALEDPROC glow_debug_glScaled = glow_debug_impl_glScaled;

static void glow_debug_impl_glIndexd(GLdouble c) {

  glow_pre_callback_("glIndexd", (void*)(ptrdiff_t)glow_glIndexd, c);
  glow_glIndexd(c);
  glow_post_callback_("glIndexd", (void*)(ptrdiff_t)glow_glIndexd, c);
}
PFNGLINDEXDPROC glow_debug_glIndexd = glow_debug_impl_glIndexd;

static void glow_debug_impl_glRasterPos3s(GLshort x, GLshort y, GLshort z) {

  glow_pre_callback_("glRasterPos3s", (void*)(ptrdiff_t)glow_glRasterPos3s, x, y, z);
  glow_glRasterPos3s(x, y, z);
  glow_post_callback_("glRasterPos3s", (void*)(ptrdiff_t)glow_glRasterPos3s, x, y, z);
}
PFNGLRASTERPOS3SPROC glow_debug_glRasterPos3s = glow_debug_impl_glRasterPos3s;

static void glow_debug_impl_glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {

  glow_pre_callback_("glRectd", (void*)(ptrdiff_t)glow_glRectd, x1, y1, x2, y2);
  glow_glRectd(x1, y1, x2, y2);
  glow_post_callback_("glRectd", (void*)(ptrdiff_t)glow_glRectd, x1, y1, x2, y2);
}
PFNGLRECTDPROC glow_debug_glRectd = glow_debug_impl_glRectd;

static void glow_debug_impl_glTexCoord4fv(const GLfloat *v) {

  glow_pre_callback_("glTexCoord4fv", (void*)(ptrdiff_t)glow_glTexCoord4fv, v);
  glow_glTexCoord4fv(v);
  glow_post_callback_("glTexCoord4fv", (void*)(ptrdiff_t)glow_glTexCoord4fv, v);
}
PFNGLTEXCOORD4FVPROC glow_debug_glTexCoord4fv = glow_debug_impl_glTexCoord4fv;

#endif /* GLOW_DEBUG */



int glow_init(void) {
  return glow_init_with(&glow_get_proc);
}

int glow_init_with(glow_load_proc_t get_proc) {
  int unresolved_count = 0;

  glow_glGetLightiv = (PFNGLGETLIGHTIVPROC)(ptrdiff_t)get_proc("glGetLightiv");
  if (glow_glGetLightiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetLightiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetLightiv\n");
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
  glow_glRasterPos3d = (PFNGLRASTERPOS3DPROC)(ptrdiff_t)get_proc("glRasterPos3d");
  if (glow_glRasterPos3d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLightiv = (PFNGLLIGHTIVPROC)(ptrdiff_t)get_proc("glLightiv");
  if (glow_glLightiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPixelMapfv = (PFNGLPIXELMAPFVPROC)(ptrdiff_t)get_proc("glPixelMapfv");
  if (glow_glPixelMapfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelMapfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelMapfv\n");
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
  glow_glReadPixels = (PFNGLREADPIXELSPROC)(ptrdiff_t)get_proc("glReadPixels");
  if (glow_glReadPixels == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReadPixels\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReadPixels\n");
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
  glow_glRasterPos3iv = (PFNGLRASTERPOS3IVPROC)(ptrdiff_t)get_proc("glRasterPos3iv");
  if (glow_glRasterPos3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos4sv = (PFNGLRASTERPOS4SVPROC)(ptrdiff_t)get_proc("glRasterPos4sv");
  if (glow_glRasterPos4sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4sv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord4dv = (PFNGLTEXCOORD4DVPROC)(ptrdiff_t)get_proc("glTexCoord4dv");
  if (glow_glTexCoord4dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord4f = (PFNGLTEXCOORD4FPROC)(ptrdiff_t)get_proc("glTexCoord4f");
  if (glow_glTexCoord4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex3s = (PFNGLVERTEX3SPROC)(ptrdiff_t)get_proc("glVertex3s");
  if (glow_glVertex3s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetPolygonStipple = (PFNGLGETPOLYGONSTIPPLEPROC)(ptrdiff_t)get_proc("glGetPolygonStipple");
  if (glow_glGetPolygonStipple == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetPolygonStipple\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetPolygonStipple\n");
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
  glow_glTexImage2D = (PFNGLTEXIMAGE2DPROC)(ptrdiff_t)get_proc("glTexImage2D");
  if (glow_glTexImage2D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexImage2D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexImage2D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos2dv = (PFNGLRASTERPOS2DVPROC)(ptrdiff_t)get_proc("glRasterPos2dv");
  if (glow_glRasterPos2dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord3d = (PFNGLTEXCOORD3DPROC)(ptrdiff_t)get_proc("glTexCoord3d");
  if (glow_glTexCoord3d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3d\n");
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
  glow_glReadBuffer = (PFNGLREADBUFFERPROC)(ptrdiff_t)get_proc("glReadBuffer");
  if (glow_glReadBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glReadBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glReadBuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos2f = (PFNGLRASTERPOS2FPROC)(ptrdiff_t)get_proc("glRasterPos2f");
  if (glow_glRasterPos2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2f\n");
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
  glow_glLoadMatrixd = (PFNGLLOADMATRIXDPROC)(ptrdiff_t)get_proc("glLoadMatrixd");
  if (glow_glLoadMatrixd == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadMatrixd\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadMatrixd\n");
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
  glow_glFlush = (PFNGLFLUSHPROC)(ptrdiff_t)get_proc("glFlush");
  if (glow_glFlush == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFlush\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFlush\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3bv = (PFNGLCOLOR3BVPROC)(ptrdiff_t)get_proc("glColor3bv");
  if (glow_glColor3bv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3bv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3bv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4uiv = (PFNGLCOLOR4UIVPROC)(ptrdiff_t)get_proc("glColor4uiv");
  if (glow_glColor4uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4uiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos4d = (PFNGLRASTERPOS4DPROC)(ptrdiff_t)get_proc("glRasterPos4d");
  if (glow_glRasterPos4d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4d\n");
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
  glow_glColor4sv = (PFNGLCOLOR4SVPROC)(ptrdiff_t)get_proc("glColor4sv");
  if (glow_glColor4sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4sv\n");
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
  glow_glRectf = (PFNGLRECTFPROC)(ptrdiff_t)get_proc("glRectf");
  if (glow_glRectf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectf\n");
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
  glow_glLoadMatrixf = (PFNGLLOADMATRIXFPROC)(ptrdiff_t)get_proc("glLoadMatrixf");
  if (glow_glLoadMatrixf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadMatrixf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadMatrixf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glListBase = (PFNGLLISTBASEPROC)(ptrdiff_t)get_proc("glListBase");
  if (glow_glListBase == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glListBase\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glListBase\n");
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
  glow_glIndexf = (PFNGLINDEXFPROC)(ptrdiff_t)get_proc("glIndexf");
  if (glow_glIndexf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos3f = (PFNGLRASTERPOS3FPROC)(ptrdiff_t)get_proc("glRasterPos3f");
  if (glow_glRasterPos3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalPoint1 = (PFNGLEVALPOINT1PROC)(ptrdiff_t)get_proc("glEvalPoint1");
  if (glow_glEvalPoint1 == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalPoint1\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalPoint1\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetPixelMapusv = (PFNGLGETPIXELMAPUSVPROC)(ptrdiff_t)get_proc("glGetPixelMapusv");
  if (glow_glGetPixelMapusv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetPixelMapusv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetPixelMapusv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexGeniv = (PFNGLGETTEXGENIVPROC)(ptrdiff_t)get_proc("glGetTexGeniv");
  if (glow_glGetTexGeniv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexGeniv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexGeniv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBitmap = (PFNGLBITMAPPROC)(ptrdiff_t)get_proc("glBitmap");
  if (glow_glBitmap == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBitmap\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBitmap\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNormal3i = (PFNGLNORMAL3IPROC)(ptrdiff_t)get_proc("glNormal3i");
  if (glow_glNormal3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos3sv = (PFNGLRASTERPOS3SVPROC)(ptrdiff_t)get_proc("glRasterPos3sv");
  if (glow_glRasterPos3sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3sv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMaterialiv = (PFNGLMATERIALIVPROC)(ptrdiff_t)get_proc("glMaterialiv");
  if (glow_glMaterialiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMaterialiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMaterialiv\n");
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
  glow_glLoadName = (PFNGLLOADNAMEPROC)(ptrdiff_t)get_proc("glLoadName");
  if (glow_glLoadName == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLoadName\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLoadName\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClearIndex = (PFNGLCLEARINDEXPROC)(ptrdiff_t)get_proc("glClearIndex");
  if (glow_glClearIndex == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearIndex\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearIndex\n");
#endif
    unresolved_count += 1;
  } 
  glow_glClipPlane = (PFNGLCLIPPLANEPROC)(ptrdiff_t)get_proc("glClipPlane");
  if (glow_glClipPlane == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClipPlane\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClipPlane\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetMapiv = (PFNGLGETMAPIVPROC)(ptrdiff_t)get_proc("glGetMapiv");
  if (glow_glGetMapiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMapiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMapiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMap2d = (PFNGLMAP2DPROC)(ptrdiff_t)get_proc("glMap2d");
  if (glow_glMap2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMap2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMap2d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalCoord2fv = (PFNGLEVALCOORD2FVPROC)(ptrdiff_t)get_proc("glEvalCoord2fv");
  if (glow_glEvalCoord2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord2fv\n");
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
  glow_glDisable = (PFNGLDISABLEPROC)(ptrdiff_t)get_proc("glDisable");
  if (glow_glDisable == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDisable\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDisable\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4i = (PFNGLCOLOR4IPROC)(ptrdiff_t)get_proc("glColor4i");
  if (glow_glColor4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord3i = (PFNGLTEXCOORD3IPROC)(ptrdiff_t)get_proc("glTexCoord3i");
  if (glow_glTexCoord3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3i\n");
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
  glow_glTexImage1D = (PFNGLTEXIMAGE1DPROC)(ptrdiff_t)get_proc("glTexImage1D");
  if (glow_glTexImage1D == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexImage1D\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexImage1D\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord3s = (PFNGLTEXCOORD3SPROC)(ptrdiff_t)get_proc("glTexCoord3s");
  if (glow_glTexCoord3s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalCoord1f = (PFNGLEVALCOORD1FPROC)(ptrdiff_t)get_proc("glEvalCoord1f");
  if (glow_glEvalCoord1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord1f\n");
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
  glow_glColor4dv = (PFNGLCOLOR4DVPROC)(ptrdiff_t)get_proc("glColor4dv");
  if (glow_glColor4dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4dv\n");
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
  glow_glEdgeFlagv = (PFNGLEDGEFLAGVPROC)(ptrdiff_t)get_proc("glEdgeFlagv");
  if (glow_glEdgeFlagv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEdgeFlagv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEdgeFlagv\n");
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
  glow_glTexEnvfv = (PFNGLTEXENVFVPROC)(ptrdiff_t)get_proc("glTexEnvfv");
  if (glow_glTexEnvfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexEnvfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexEnvfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3b = (PFNGLCOLOR3BPROC)(ptrdiff_t)get_proc("glColor3b");
  if (glow_glColor3b == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3b\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3b\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4d = (PFNGLCOLOR4DPROC)(ptrdiff_t)get_proc("glColor4d");
  if (glow_glColor4d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord2fv = (PFNGLTEXCOORD2FVPROC)(ptrdiff_t)get_proc("glTexCoord2fv");
  if (glow_glTexCoord2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2fv\n");
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
  glow_glGetClipPlane = (PFNGLGETCLIPPLANEPROC)(ptrdiff_t)get_proc("glGetClipPlane");
  if (glow_glGetClipPlane == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetClipPlane\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetClipPlane\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4ui = (PFNGLCOLOR4UIPROC)(ptrdiff_t)get_proc("glColor4ui");
  if (glow_glColor4ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4ui\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord1fv = (PFNGLTEXCOORD1FVPROC)(ptrdiff_t)get_proc("glTexCoord1fv");
  if (glow_glTexCoord1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex4i = (PFNGLVERTEX4IPROC)(ptrdiff_t)get_proc("glVertex4i");
  if (glow_glVertex4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLighti = (PFNGLLIGHTIPROC)(ptrdiff_t)get_proc("glLighti");
  if (glow_glLighti == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLighti\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLighti\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexGendv = (PFNGLGETTEXGENDVPROC)(ptrdiff_t)get_proc("glGetTexGendv");
  if (glow_glGetTexGendv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexGendv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexGendv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3us = (PFNGLCOLOR3USPROC)(ptrdiff_t)get_proc("glColor3us");
  if (glow_glColor3us == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3us\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3us\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos4dv = (PFNGLRASTERPOS4DVPROC)(ptrdiff_t)get_proc("glRasterPos4dv");
  if (glow_glRasterPos4dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos4iv = (PFNGLRASTERPOS4IVPROC)(ptrdiff_t)get_proc("glRasterPos4iv");
  if (glow_glRasterPos4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4iv\n");
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
  glow_glColor3i = (PFNGLCOLOR3IPROC)(ptrdiff_t)get_proc("glColor3i");
  if (glow_glColor3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPolygonStipple = (PFNGLPOLYGONSTIPPLEPROC)(ptrdiff_t)get_proc("glPolygonStipple");
  if (glow_glPolygonStipple == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPolygonStipple\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPolygonStipple\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPixelMapuiv = (PFNGLPIXELMAPUIVPROC)(ptrdiff_t)get_proc("glPixelMapuiv");
  if (glow_glPixelMapuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelMapuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelMapuiv\n");
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
  glow_glIndexdv = (PFNGLINDEXDVPROC)(ptrdiff_t)get_proc("glIndexdv");
  if (glow_glIndexdv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexdv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexdv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord4s = (PFNGLTEXCOORD4SPROC)(ptrdiff_t)get_proc("glTexCoord4s");
  if (glow_glTexCoord4s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex3f = (PFNGLVERTEX3FPROC)(ptrdiff_t)get_proc("glVertex3f");
  if (glow_glVertex3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMap1f = (PFNGLMAP1FPROC)(ptrdiff_t)get_proc("glMap1f");
  if (glow_glMap1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMap1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMap1f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalMesh1 = (PFNGLEVALMESH1PROC)(ptrdiff_t)get_proc("glEvalMesh1");
  if (glow_glEvalMesh1 == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalMesh1\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalMesh1\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIsList = (PFNGLISLISTPROC)(ptrdiff_t)get_proc("glIsList");
  if (glow_glIsList == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIsList\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIsList\n");
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
  glow_glNormal3sv = (PFNGLNORMAL3SVPROC)(ptrdiff_t)get_proc("glNormal3sv");
  if (glow_glNormal3sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3sv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord3sv = (PFNGLTEXCOORD3SVPROC)(ptrdiff_t)get_proc("glTexCoord3sv");
  if (glow_glTexCoord3sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3sv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex3i = (PFNGLVERTEX3IPROC)(ptrdiff_t)get_proc("glVertex3i");
  if (glow_glVertex3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3i\n");
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
  glow_glTexGend = (PFNGLTEXGENDPROC)(ptrdiff_t)get_proc("glTexGend");
  if (glow_glTexGend == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGend\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGend\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPixelTransferi = (PFNGLPIXELTRANSFERIPROC)(ptrdiff_t)get_proc("glPixelTransferi");
  if (glow_glPixelTransferi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelTransferi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelTransferi\n");
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
  glow_glRectfv = (PFNGLRECTFVPROC)(ptrdiff_t)get_proc("glRectfv");
  if (glow_glRectfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord1d = (PFNGLTEXCOORD1DPROC)(ptrdiff_t)get_proc("glTexCoord1d");
  if (glow_glTexCoord1d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexGeniv = (PFNGLTEXGENIVPROC)(ptrdiff_t)get_proc("glTexGeniv");
  if (glow_glTexGeniv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGeniv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGeniv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex4f = (PFNGLVERTEX4FPROC)(ptrdiff_t)get_proc("glVertex4f");
  if (glow_glVertex4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalCoord2dv = (PFNGLEVALCOORD2DVPROC)(ptrdiff_t)get_proc("glEvalCoord2dv");
  if (glow_glEvalCoord2dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord2dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord2dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetTexGenfv = (PFNGLGETTEXGENFVPROC)(ptrdiff_t)get_proc("glGetTexGenfv");
  if (glow_glGetTexGenfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexGenfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexGenfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3usv = (PFNGLCOLOR3USVPROC)(ptrdiff_t)get_proc("glColor3usv");
  if (glow_glColor3usv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3usv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3usv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4s = (PFNGLCOLOR4SPROC)(ptrdiff_t)get_proc("glColor4s");
  if (glow_glColor4s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIndexs = (PFNGLINDEXSPROC)(ptrdiff_t)get_proc("glIndexs");
  if (glow_glIndexs == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexs\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexs\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord1s = (PFNGLTEXCOORD1SPROC)(ptrdiff_t)get_proc("glTexCoord1s");
  if (glow_glTexCoord1s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos2sv = (PFNGLRASTERPOS2SVPROC)(ptrdiff_t)get_proc("glRasterPos2sv");
  if (glow_glRasterPos2sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2sv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord4sv = (PFNGLTEXCOORD4SVPROC)(ptrdiff_t)get_proc("glTexCoord4sv");
  if (glow_glTexCoord4sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4sv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glInitNames = (PFNGLINITNAMESPROC)(ptrdiff_t)get_proc("glInitNames");
  if (glow_glInitNames == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glInitNames\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glInitNames\n");
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
  glow_glClearDepth = (PFNGLCLEARDEPTHPROC)(ptrdiff_t)get_proc("glClearDepth");
  if (glow_glClearDepth == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearDepth\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearDepth\n");
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
  glow_glColor3dv = (PFNGLCOLOR3DVPROC)(ptrdiff_t)get_proc("glColor3dv");
  if (glow_glColor3dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4bv = (PFNGLCOLOR4BVPROC)(ptrdiff_t)get_proc("glColor4bv");
  if (glow_glColor4bv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4bv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4bv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex3fv = (PFNGLVERTEX3FVPROC)(ptrdiff_t)get_proc("glVertex3fv");
  if (glow_glVertex3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPopAttrib = (PFNGLPOPATTRIBPROC)(ptrdiff_t)get_proc("glPopAttrib");
  if (glow_glPopAttrib == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPopAttrib\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPopAttrib\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMap1d = (PFNGLMAP1DPROC)(ptrdiff_t)get_proc("glMap1d");
  if (glow_glMap1d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMap1d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMap1d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalCoord2d = (PFNGLEVALCOORD2DPROC)(ptrdiff_t)get_proc("glEvalCoord2d");
  if (glow_glEvalCoord2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord2d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4b = (PFNGLCOLOR4BPROC)(ptrdiff_t)get_proc("glColor4b");
  if (glow_glColor4b == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4b\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4b\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNormal3s = (PFNGLNORMAL3SPROC)(ptrdiff_t)get_proc("glNormal3s");
  if (glow_glNormal3s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos2i = (PFNGLRASTERPOS2IPROC)(ptrdiff_t)get_proc("glRasterPos2i");
  if (glow_glRasterPos2i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex4s = (PFNGLVERTEX4SPROC)(ptrdiff_t)get_proc("glVertex4s");
  if (glow_glVertex4s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos3dv = (PFNGLRASTERPOS3DVPROC)(ptrdiff_t)get_proc("glRasterPos3dv");
  if (glow_glRasterPos3dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord2d = (PFNGLTEXCOORD2DPROC)(ptrdiff_t)get_proc("glTexCoord2d");
  if (glow_glTexCoord2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2d\n");
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
  glow_glDrawPixels = (PFNGLDRAWPIXELSPROC)(ptrdiff_t)get_proc("glDrawPixels");
  if (glow_glDrawPixels == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawPixels\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawPixels\n");
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
  glow_glColorMask = (PFNGLCOLORMASKPROC)(ptrdiff_t)get_proc("glColorMask");
  if (glow_glColorMask == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColorMask\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColorMask\n");
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
  glow_glColor4iv = (PFNGLCOLOR4IVPROC)(ptrdiff_t)get_proc("glColor4iv");
  if (glow_glColor4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCopyPixels = (PFNGLCOPYPIXELSPROC)(ptrdiff_t)get_proc("glCopyPixels");
  if (glow_glCopyPixels == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCopyPixels\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCopyPixels\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRotated = (PFNGLROTATEDPROC)(ptrdiff_t)get_proc("glRotated");
  if (glow_glRotated == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRotated\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRotated\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTranslated = (PFNGLTRANSLATEDPROC)(ptrdiff_t)get_proc("glTranslated");
  if (glow_glTranslated == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTranslated\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTranslated\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGenLists = (PFNGLGENLISTSPROC)(ptrdiff_t)get_proc("glGenLists");
  if (glow_glGenLists == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGenLists\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGenLists\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord1f = (PFNGLTEXCOORD1FPROC)(ptrdiff_t)get_proc("glTexCoord1f");
  if (glow_glTexCoord1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1f\n");
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
  glow_glEvalCoord1dv = (PFNGLEVALCOORD1DVPROC)(ptrdiff_t)get_proc("glEvalCoord1dv");
  if (glow_glEvalCoord1dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord1dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord1dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord2dv = (PFNGLTEXCOORD2DVPROC)(ptrdiff_t)get_proc("glTexCoord2dv");
  if (glow_glTexCoord2dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2dv\n");
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
  glow_glPopName = (PFNGLPOPNAMEPROC)(ptrdiff_t)get_proc("glPopName");
  if (glow_glPopName == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPopName\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPopName\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPushAttrib = (PFNGLPUSHATTRIBPROC)(ptrdiff_t)get_proc("glPushAttrib");
  if (glow_glPushAttrib == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPushAttrib\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPushAttrib\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3ubv = (PFNGLCOLOR3UBVPROC)(ptrdiff_t)get_proc("glColor3ubv");
  if (glow_glColor3ubv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3ubv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3ubv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord2i = (PFNGLTEXCOORD2IPROC)(ptrdiff_t)get_proc("glTexCoord2i");
  if (glow_glTexCoord2i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4ubv = (PFNGLCOLOR4UBVPROC)(ptrdiff_t)get_proc("glColor4ubv");
  if (glow_glColor4ubv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4ubv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4ubv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex2s = (PFNGLVERTEX2SPROC)(ptrdiff_t)get_proc("glVertex2s");
  if (glow_glVertex2s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex3iv = (PFNGLVERTEX3IVPROC)(ptrdiff_t)get_proc("glVertex3iv");
  if (glow_glVertex3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFeedbackBuffer = (PFNGLFEEDBACKBUFFERPROC)(ptrdiff_t)get_proc("glFeedbackBuffer");
  if (glow_glFeedbackBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFeedbackBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFeedbackBuffer\n");
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
  glow_glColor3d = (PFNGLCOLOR3DPROC)(ptrdiff_t)get_proc("glColor3d");
  if (glow_glColor3d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3s = (PFNGLCOLOR3SPROC)(ptrdiff_t)get_proc("glColor3s");
  if (glow_glColor3s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3sv = (PFNGLCOLOR3SVPROC)(ptrdiff_t)get_proc("glColor3sv");
  if (glow_glColor3sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3sv\n");
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
  glow_glGetPixelMapfv = (PFNGLGETPIXELMAPFVPROC)(ptrdiff_t)get_proc("glGetPixelMapfv");
  if (glow_glGetPixelMapfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetPixelMapfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetPixelMapfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord2iv = (PFNGLTEXCOORD2IVPROC)(ptrdiff_t)get_proc("glTexCoord2iv");
  if (glow_glTexCoord2iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMap2f = (PFNGLMAP2FPROC)(ptrdiff_t)get_proc("glMap2f");
  if (glow_glMap2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMap2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMap2f\n");
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
  glow_glDrawBuffer = (PFNGLDRAWBUFFERPROC)(ptrdiff_t)get_proc("glDrawBuffer");
  if (glow_glDrawBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDrawBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDrawBuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCallList = (PFNGLCALLLISTPROC)(ptrdiff_t)get_proc("glCallList");
  if (glow_glCallList == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCallList\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCallList\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord1sv = (PFNGLTEXCOORD1SVPROC)(ptrdiff_t)get_proc("glTexCoord1sv");
  if (glow_glTexCoord1sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1sv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetMapfv = (PFNGLGETMAPFVPROC)(ptrdiff_t)get_proc("glGetMapfv");
  if (glow_glGetMapfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMapfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMapfv\n");
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
  glow_glTexCoord2s = (PFNGLTEXCOORD2SPROC)(ptrdiff_t)get_proc("glTexCoord2s");
  if (glow_glTexCoord2s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2s\n");
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
  glow_glTexGenfv = (PFNGLTEXGENFVPROC)(ptrdiff_t)get_proc("glTexGenfv");
  if (glow_glTexGenfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGenfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGenfv\n");
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
  glow_glVertex2d = (PFNGLVERTEX2DPROC)(ptrdiff_t)get_proc("glVertex2d");
  if (glow_glVertex2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLineStipple = (PFNGLLINESTIPPLEPROC)(ptrdiff_t)get_proc("glLineStipple");
  if (glow_glLineStipple == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLineStipple\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLineStipple\n");
#endif
    unresolved_count += 1;
  } 
  glow_glOrtho = (PFNGLORTHOPROC)(ptrdiff_t)get_proc("glOrtho");
  if (glow_glOrtho == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glOrtho\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glOrtho\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord3dv = (PFNGLTEXCOORD3DVPROC)(ptrdiff_t)get_proc("glTexCoord3dv");
  if (glow_glTexCoord3dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRenderMode = (PFNGLRENDERMODEPROC)(ptrdiff_t)get_proc("glRenderMode");
  if (glow_glRenderMode == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRenderMode\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRenderMode\n");
#endif
    unresolved_count += 1;
  } 
  glow_glCallLists = (PFNGLCALLLISTSPROC)(ptrdiff_t)get_proc("glCallLists");
  if (glow_glCallLists == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glCallLists\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glCallLists\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3ui = (PFNGLCOLOR3UIPROC)(ptrdiff_t)get_proc("glColor3ui");
  if (glow_glColor3ui == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3ui\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3ui\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNormal3d = (PFNGLNORMAL3DPROC)(ptrdiff_t)get_proc("glNormal3d");
  if (glow_glNormal3d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos3i = (PFNGLRASTERPOS3IPROC)(ptrdiff_t)get_proc("glRasterPos3i");
  if (glow_glRasterPos3i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos4f = (PFNGLRASTERPOS4FPROC)(ptrdiff_t)get_proc("glRasterPos4f");
  if (glow_glRasterPos4f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4f\n");
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
  glow_glRotatef = (PFNGLROTATEFPROC)(ptrdiff_t)get_proc("glRotatef");
  if (glow_glRotatef == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRotatef\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRotatef\n");
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
  glow_glColor4usv = (PFNGLCOLOR4USVPROC)(ptrdiff_t)get_proc("glColor4usv");
  if (glow_glColor4usv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4usv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4usv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord2f = (PFNGLTEXCOORD2FPROC)(ptrdiff_t)get_proc("glTexCoord2f");
  if (glow_glTexCoord2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex2iv = (PFNGLVERTEX2IVPROC)(ptrdiff_t)get_proc("glVertex2iv");
  if (glow_glVertex2iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2iv\n");
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
  glow_glGetPixelMapuiv = (PFNGLGETPIXELMAPUIVPROC)(ptrdiff_t)get_proc("glGetPixelMapuiv");
  if (glow_glGetPixelMapuiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetPixelMapuiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetPixelMapuiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIndexi = (PFNGLINDEXIPROC)(ptrdiff_t)get_proc("glIndexi");
  if (glow_glIndexi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexi\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIndexsv = (PFNGLINDEXSVPROC)(ptrdiff_t)get_proc("glIndexsv");
  if (glow_glIndexsv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexsv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexsv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRectiv = (PFNGLRECTIVPROC)(ptrdiff_t)get_proc("glRectiv");
  if (glow_glRectiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord4iv = (PFNGLTEXCOORD4IVPROC)(ptrdiff_t)get_proc("glTexCoord4iv");
  if (glow_glTexCoord4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMapGrid1d = (PFNGLMAPGRID1DPROC)(ptrdiff_t)get_proc("glMapGrid1d");
  if (glow_glMapGrid1d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMapGrid1d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMapGrid1d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPixelMapusv = (PFNGLPIXELMAPUSVPROC)(ptrdiff_t)get_proc("glPixelMapusv");
  if (glow_glPixelMapusv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelMapusv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelMapusv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNormal3iv = (PFNGLNORMAL3IVPROC)(ptrdiff_t)get_proc("glNormal3iv");
  if (glow_glNormal3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos3fv = (PFNGLRASTERPOS3FVPROC)(ptrdiff_t)get_proc("glRasterPos3fv");
  if (glow_glRasterPos3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord3fv = (PFNGLTEXCOORD3FVPROC)(ptrdiff_t)get_proc("glTexCoord3fv");
  if (glow_glTexCoord3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexGeni = (PFNGLTEXGENIPROC)(ptrdiff_t)get_proc("glTexGeni");
  if (glow_glTexGeni == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGeni\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGeni\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3f = (PFNGLCOLOR3FPROC)(ptrdiff_t)get_proc("glColor3f");
  if (glow_glColor3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos2fv = (PFNGLRASTERPOS2FVPROC)(ptrdiff_t)get_proc("glRasterPos2fv");
  if (glow_glRasterPos2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord1i = (PFNGLTEXCOORD1IPROC)(ptrdiff_t)get_proc("glTexCoord1i");
  if (glow_glTexCoord1i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIndexMask = (PFNGLINDEXMASKPROC)(ptrdiff_t)get_proc("glIndexMask");
  if (glow_glIndexMask == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexMask\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexMask\n");
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
  glow_glGetTexImage = (PFNGLGETTEXIMAGEPROC)(ptrdiff_t)get_proc("glGetTexImage");
  if (glow_glGetTexImage == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexImage\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexImage\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord4d = (PFNGLTEXCOORD4DPROC)(ptrdiff_t)get_proc("glTexCoord4d");
  if (glow_glTexCoord4d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4d\n");
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
  glow_glClearAccum = (PFNGLCLEARACCUMPROC)(ptrdiff_t)get_proc("glClearAccum");
  if (glow_glClearAccum == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glClearAccum\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glClearAccum\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMapGrid2f = (PFNGLMAPGRID2FPROC)(ptrdiff_t)get_proc("glMapGrid2f");
  if (glow_glMapGrid2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMapGrid2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMapGrid2f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPixelZoom = (PFNGLPIXELZOOMPROC)(ptrdiff_t)get_proc("glPixelZoom");
  if (glow_glPixelZoom == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelZoom\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelZoom\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFrustum = (PFNGLFRUSTUMPROC)(ptrdiff_t)get_proc("glFrustum");
  if (glow_glFrustum == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFrustum\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFrustum\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos4fv = (PFNGLRASTERPOS4FVPROC)(ptrdiff_t)get_proc("glRasterPos4fv");
  if (glow_glRasterPos4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex3dv = (PFNGLVERTEX3DVPROC)(ptrdiff_t)get_proc("glVertex3dv");
  if (glow_glVertex3dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFogi = (PFNGLFOGIPROC)(ptrdiff_t)get_proc("glFogi");
  if (glow_glFogi == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogi\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogi\n");
#endif
    unresolved_count += 1;
  } 
  glow_glLightModeli = (PFNGLLIGHTMODELIPROC)(ptrdiff_t)get_proc("glLightModeli");
  if (glow_glLightModeli == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModeli\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModeli\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord1dv = (PFNGLTEXCOORD1DVPROC)(ptrdiff_t)get_proc("glTexCoord1dv");
  if (glow_glTexCoord1dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex2f = (PFNGLVERTEX2FPROC)(ptrdiff_t)get_proc("glVertex2f");
  if (glow_glVertex2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPixelTransferf = (PFNGLPIXELTRANSFERFPROC)(ptrdiff_t)get_proc("glPixelTransferf");
  if (glow_glPixelTransferf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelTransferf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelTransferf\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetMapdv = (PFNGLGETMAPDVPROC)(ptrdiff_t)get_proc("glGetMapdv");
  if (glow_glGetMapdv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMapdv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMapdv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPolygonMode = (PFNGLPOLYGONMODEPROC)(ptrdiff_t)get_proc("glPolygonMode");
  if (glow_glPolygonMode == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPolygonMode\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPolygonMode\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPixelStoref = (PFNGLPIXELSTOREFPROC)(ptrdiff_t)get_proc("glPixelStoref");
  if (glow_glPixelStoref == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelStoref\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelStoref\n");
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
  glow_glColor4fv = (PFNGLCOLOR4FVPROC)(ptrdiff_t)get_proc("glColor4fv");
  if (glow_glColor4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalCoord2f = (PFNGLEVALCOORD2FPROC)(ptrdiff_t)get_proc("glEvalCoord2f");
  if (glow_glEvalCoord2f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord2f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord2f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNormal3dv = (PFNGLNORMAL3DVPROC)(ptrdiff_t)get_proc("glNormal3dv");
  if (glow_glNormal3dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMateriali = (PFNGLMATERIALIPROC)(ptrdiff_t)get_proc("glMateriali");
  if (glow_glMateriali == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMateriali\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMateriali\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPushName = (PFNGLPUSHNAMEPROC)(ptrdiff_t)get_proc("glPushName");
  if (glow_glPushName == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPushName\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPushName\n");
#endif
    unresolved_count += 1;
  } 
  glow_glAccum = (PFNGLACCUMPROC)(ptrdiff_t)get_proc("glAccum");
  if (glow_glAccum == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glAccum\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glAccum\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRecti = (PFNGLRECTIPROC)(ptrdiff_t)get_proc("glRecti");
  if (glow_glRecti == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRecti\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRecti\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord2sv = (PFNGLTEXCOORD2SVPROC)(ptrdiff_t)get_proc("glTexCoord2sv");
  if (glow_glTexCoord2sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord2sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord2sv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex2sv = (PFNGLVERTEX2SVPROC)(ptrdiff_t)get_proc("glVertex2sv");
  if (glow_glVertex2sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2sv\n");
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
  glow_glPixelStorei = (PFNGLPIXELSTOREIPROC)(ptrdiff_t)get_proc("glPixelStorei");
  if (glow_glPixelStorei == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPixelStorei\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPixelStorei\n");
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
  glow_glColor3uiv = (PFNGLCOLOR3UIVPROC)(ptrdiff_t)get_proc("glColor3uiv");
  if (glow_glColor3uiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3uiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3uiv\n");
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
  glow_glVertex2fv = (PFNGLVERTEX2FVPROC)(ptrdiff_t)get_proc("glVertex2fv");
  if (glow_glVertex2fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex4d = (PFNGLVERTEX4DPROC)(ptrdiff_t)get_proc("glVertex4d");
  if (glow_glVertex4d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3fv = (PFNGLCOLOR3FVPROC)(ptrdiff_t)get_proc("glColor3fv");
  if (glow_glColor3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glPassThrough = (PFNGLPASSTHROUGHPROC)(ptrdiff_t)get_proc("glPassThrough");
  if (glow_glPassThrough == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glPassThrough\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glPassThrough\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMapGrid1f = (PFNGLMAPGRID1FPROC)(ptrdiff_t)get_proc("glMapGrid1f");
  if (glow_glMapGrid1f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMapGrid1f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMapGrid1f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalCoord1d = (PFNGLEVALCOORD1DPROC)(ptrdiff_t)get_proc("glEvalCoord1d");
  if (glow_glEvalCoord1d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord1d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord1d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glGetMaterialiv = (PFNGLGETMATERIALIVPROC)(ptrdiff_t)get_proc("glGetMaterialiv");
  if (glow_glGetMaterialiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetMaterialiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetMaterialiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIndexfv = (PFNGLINDEXFVPROC)(ptrdiff_t)get_proc("glIndexfv");
  if (glow_glIndexfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexfv\n");
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
  glow_glNormal3fv = (PFNGLNORMAL3FVPROC)(ptrdiff_t)get_proc("glNormal3fv");
  if (glow_glNormal3fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex4dv = (PFNGLVERTEX4DVPROC)(ptrdiff_t)get_proc("glVertex4dv");
  if (glow_glVertex4dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4dv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMapGrid2d = (PFNGLMAPGRID2DPROC)(ptrdiff_t)get_proc("glMapGrid2d");
  if (glow_glMapGrid2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMapGrid2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMapGrid2d\n");
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
  glow_glEdgeFlag = (PFNGLEDGEFLAGPROC)(ptrdiff_t)get_proc("glEdgeFlag");
  if (glow_glEdgeFlag == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEdgeFlag\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEdgeFlag\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord4i = (PFNGLTEXCOORD4IPROC)(ptrdiff_t)get_proc("glTexCoord4i");
  if (glow_glTexCoord4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4i\n");
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
  glow_glGetLightfv = (PFNGLGETLIGHTFVPROC)(ptrdiff_t)get_proc("glGetLightfv");
  if (glow_glGetLightfv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetLightfv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetLightfv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3ub = (PFNGLCOLOR3UBPROC)(ptrdiff_t)get_proc("glColor3ub");
  if (glow_glColor3ub == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3ub\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3ub\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEnd = (PFNGLENDPROC)(ptrdiff_t)get_proc("glEnd");
  if (glow_glEnd == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnd\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnd\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNormal3b = (PFNGLNORMAL3BPROC)(ptrdiff_t)get_proc("glNormal3b");
  if (glow_glNormal3b == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3b\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3b\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos4i = (PFNGLRASTERPOS4IPROC)(ptrdiff_t)get_proc("glRasterPos4i");
  if (glow_glRasterPos4i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4i\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex2dv = (PFNGLVERTEX2DVPROC)(ptrdiff_t)get_proc("glVertex2dv");
  if (glow_glVertex2dv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2dv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2dv\n");
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
  glow_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)(ptrdiff_t)get_proc("glGetTexParameteriv");
  if (glow_glGetTexParameteriv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetTexParameteriv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetTexParameteriv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glBegin = (PFNGLBEGINPROC)(ptrdiff_t)get_proc("glBegin");
  if (glow_glBegin == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glBegin\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glBegin\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRectsv = (PFNGLRECTSVPROC)(ptrdiff_t)get_proc("glRectsv");
  if (glow_glRectsv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectsv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectsv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalCoord1fv = (PFNGLEVALCOORD1FVPROC)(ptrdiff_t)get_proc("glEvalCoord1fv");
  if (glow_glEvalCoord1fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalCoord1fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalCoord1fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glMultMatrixd = (PFNGLMULTMATRIXDPROC)(ptrdiff_t)get_proc("glMultMatrixd");
  if (glow_glMultMatrixd == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glMultMatrixd\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glMultMatrixd\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNormal3bv = (PFNGLNORMAL3BVPROC)(ptrdiff_t)get_proc("glNormal3bv");
  if (glow_glNormal3bv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNormal3bv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNormal3bv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex2i = (PFNGLVERTEX2IPROC)(ptrdiff_t)get_proc("glVertex2i");
  if (glow_glVertex2i == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex2i\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex2i\n");
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
  glow_glDeleteLists = (PFNGLDELETELISTSPROC)(ptrdiff_t)get_proc("glDeleteLists");
  if (glow_glDeleteLists == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDeleteLists\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDeleteLists\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor3iv = (PFNGLCOLOR3IVPROC)(ptrdiff_t)get_proc("glColor3iv");
  if (glow_glColor3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor3iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColor4us = (PFNGLCOLOR4USPROC)(ptrdiff_t)get_proc("glColor4us");
  if (glow_glColor4us == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColor4us\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColor4us\n");
#endif
    unresolved_count += 1;
  } 
  glow_glSelectBuffer = (PFNGLSELECTBUFFERPROC)(ptrdiff_t)get_proc("glSelectBuffer");
  if (glow_glSelectBuffer == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glSelectBuffer\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glSelectBuffer\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos2iv = (PFNGLRASTERPOS2IVPROC)(ptrdiff_t)get_proc("glRasterPos2iv");
  if (glow_glRasterPos2iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos4s = (PFNGLRASTERPOS4SPROC)(ptrdiff_t)get_proc("glRasterPos4s");
  if (glow_glRasterPos4s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos4s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos4s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex4fv = (PFNGLVERTEX4FVPROC)(ptrdiff_t)get_proc("glVertex4fv");
  if (glow_glVertex4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4fv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex4iv = (PFNGLVERTEX4IVPROC)(ptrdiff_t)get_proc("glVertex4iv");
  if (glow_glVertex4iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4iv\n");
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
  glow_glGetFloatv = (PFNGLGETFLOATVPROC)(ptrdiff_t)get_proc("glGetFloatv");
  if (glow_glGetFloatv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetFloatv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetFloatv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glDepthRange = (PFNGLDEPTHRANGEPROC)(ptrdiff_t)get_proc("glDepthRange");
  if (glow_glDepthRange == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glDepthRange\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glDepthRange\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIndexiv = (PFNGLINDEXIVPROC)(ptrdiff_t)get_proc("glIndexiv");
  if (glow_glIndexiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEndList = (PFNGLENDLISTPROC)(ptrdiff_t)get_proc("glEndList");
  if (glow_glEndList == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEndList\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEndList\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos2s = (PFNGLRASTERPOS2SPROC)(ptrdiff_t)get_proc("glRasterPos2s");
  if (glow_glRasterPos2s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord3iv = (PFNGLTEXCOORD3IVPROC)(ptrdiff_t)get_proc("glTexCoord3iv");
  if (glow_glTexCoord3iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalPoint2 = (PFNGLEVALPOINT2PROC)(ptrdiff_t)get_proc("glEvalPoint2");
  if (glow_glEvalPoint2 == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalPoint2\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalPoint2\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexGenf = (PFNGLTEXGENFPROC)(ptrdiff_t)get_proc("glTexGenf");
  if (glow_glTexGenf == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGenf\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGenf\n");
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
  glow_glGetDoublev = (PFNGLGETDOUBLEVPROC)(ptrdiff_t)get_proc("glGetDoublev");
  if (glow_glGetDoublev == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glGetDoublev\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glGetDoublev\n");
#endif
    unresolved_count += 1;
  } 
  glow_glNewList = (PFNGLNEWLISTPROC)(ptrdiff_t)get_proc("glNewList");
  if (glow_glNewList == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glNewList\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glNewList\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRects = (PFNGLRECTSPROC)(ptrdiff_t)get_proc("glRects");
  if (glow_glRects == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRects\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRects\n");
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
  glow_glLightModeliv = (PFNGLLIGHTMODELIVPROC)(ptrdiff_t)get_proc("glLightModeliv");
  if (glow_glLightModeliv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glLightModeliv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glLightModeliv\n");
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
  glow_glEnable = (PFNGLENABLEPROC)(ptrdiff_t)get_proc("glEnable");
  if (glow_glEnable == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEnable\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEnable\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord1iv = (PFNGLTEXCOORD1IVPROC)(ptrdiff_t)get_proc("glTexCoord1iv");
  if (glow_glTexCoord1iv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord1iv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord1iv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex3sv = (PFNGLVERTEX3SVPROC)(ptrdiff_t)get_proc("glVertex3sv");
  if (glow_glVertex3sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3sv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos2d = (PFNGLRASTERPOS2DPROC)(ptrdiff_t)get_proc("glRasterPos2d");
  if (glow_glRasterPos2d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos2d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos2d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glFogiv = (PFNGLFOGIVPROC)(ptrdiff_t)get_proc("glFogiv");
  if (glow_glFogiv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glFogiv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glFogiv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexGendv = (PFNGLTEXGENDVPROC)(ptrdiff_t)get_proc("glTexGendv");
  if (glow_glTexGendv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexGendv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexGendv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glColorMaterial = (PFNGLCOLORMATERIALPROC)(ptrdiff_t)get_proc("glColorMaterial");
  if (glow_glColorMaterial == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glColorMaterial\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glColorMaterial\n");
#endif
    unresolved_count += 1;
  } 
  glow_glEvalMesh2 = (PFNGLEVALMESH2PROC)(ptrdiff_t)get_proc("glEvalMesh2");
  if (glow_glEvalMesh2 == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glEvalMesh2\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glEvalMesh2\n");
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
  glow_glStencilOp = (PFNGLSTENCILOPPROC)(ptrdiff_t)get_proc("glStencilOp");
  if (glow_glStencilOp == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glStencilOp\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glStencilOp\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRectdv = (PFNGLRECTDVPROC)(ptrdiff_t)get_proc("glRectdv");
  if (glow_glRectdv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectdv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectdv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord3f = (PFNGLTEXCOORD3FPROC)(ptrdiff_t)get_proc("glTexCoord3f");
  if (glow_glTexCoord3f == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord3f\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord3f\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex3d = (PFNGLVERTEX3DPROC)(ptrdiff_t)get_proc("glVertex3d");
  if (glow_glVertex3d == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex3d\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex3d\n");
#endif
    unresolved_count += 1;
  } 
  glow_glVertex4sv = (PFNGLVERTEX4SVPROC)(ptrdiff_t)get_proc("glVertex4sv");
  if (glow_glVertex4sv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glVertex4sv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glVertex4sv\n");
#endif
    unresolved_count += 1;
  } 
  glow_glScaled = (PFNGLSCALEDPROC)(ptrdiff_t)get_proc("glScaled");
  if (glow_glScaled == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glScaled\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glScaled\n");
#endif
    unresolved_count += 1;
  } 
  glow_glIndexd = (PFNGLINDEXDPROC)(ptrdiff_t)get_proc("glIndexd");
  if (glow_glIndexd == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glIndexd\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glIndexd\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRasterPos3s = (PFNGLRASTERPOS3SPROC)(ptrdiff_t)get_proc("glRasterPos3s");
  if (glow_glRasterPos3s == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRasterPos3s\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRasterPos3s\n");
#endif
    unresolved_count += 1;
  } 
  glow_glRectd = (PFNGLRECTDPROC)(ptrdiff_t)get_proc("glRectd");
  if (glow_glRectd == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glRectd\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glRectd\n");
#endif
    unresolved_count += 1;
  } 
  glow_glTexCoord4fv = (PFNGLTEXCOORD4FVPROC)(ptrdiff_t)get_proc("glTexCoord4fv");
  if (glow_glTexCoord4fv == NULL) {
    GLOW_ASSERT(!0 && "glow error: failed to load glTexCoord4fv\n");
#ifndef GLOW_NO_STDIO
    printf("glow error: failed to load glTexCoord4fv\n");
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
