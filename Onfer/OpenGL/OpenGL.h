#ifndef ONFER_OPENGL_H
#define ONFER_OPENGL_H

#include <Windows.h>
#include <gl/GL.h>

namespace Onfer {

	typedef void (APIENTRY* PFNGLGENBUFFERSPROC) (GLsizei n, GLuint* buffers);
	typedef void (APIENTRY* PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
	typedef void (APIENTRY* PFNGLBUFFERDATAPROC) (GLenum target, ptrdiff_t size, const GLvoid* data, GLenum usage);

	typedef void (APIENTRY* PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint* arrays);
	typedef void (APIENTRY* PFNGLBINDVERTEXARRAYPROC) (GLuint array);

	typedef void (APIENTRY* PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
	typedef void (APIENTRY* PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

	typedef void (APIENTRY* PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint* buffers);
	typedef void (APIENTRY* PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint* arrays);

	typedef GLuint(APIENTRY* PFNGLCREATESHADERPROC) (GLenum type);
	typedef void (APIENTRY* PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const char** string, const GLint* length);
	typedef void (APIENTRY* PFNGLCOMPILESHADERPROC) (GLuint shader);
	typedef void (APIENTRY* PFNGLUSEPROGRAMPROC) (GLuint program);
	typedef GLuint(APIENTRY* PFNGLCREATEPROGRAMPROC) (void);
	typedef void (APIENTRY* PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
	typedef void (APIENTRY* PFNGLLINKPROGRAMPROC) (GLuint program);
	typedef void (APIENTRY* PFNGLVALIDATEPROGRAMPROC) (GLuint program);
	typedef void (APIENTRY* PFNGLDELETESHADERPROC) (GLuint shader);
	typedef void (APIENTRY* PFNGLDELETEPROGRAMPROC) (GLuint program);
	typedef void (APIENTRY* PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint* params);
	typedef void (APIENTRY* PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei* length, char* infoLog);

	typedef GLint(APIENTRY* PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const char* name);
	typedef void (APIENTRY* PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

	typedef void (APIENTRY* PFNGLGENERATEMIPMAPPROC) (GLenum target);
	typedef void (APIENTRY* PFNGLACTIVETEXTUREPROC) (GLenum texture);
	typedef void (APIENTRY* PFNGLUNIFORM1IPROC) (GLint location, GLint v0);

	typedef void (APIENTRY* PFNGLBUFFERSUBDATAPROC) (GLenum target, ptrdiff_t offset, ptrdiff_t size, const void* data);

#define GL_ARRAY_BUFFER                   0x8892
#define GL_STATIC_DRAW                    0x88E4
#define GL_DYNAMIC_DRAW				      35048 
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_TEXTURE0                       0x84C0
#define GL_BGRA                           0x80E1
#define GL_ELEMENT_ARRAY_BUFFER           0x8893


	class gl {
	public:
		static bool init();
		static void shutDown();
		static PFNGLGENBUFFERSPROC GenBuffers;
		static PFNGLBINDBUFFERPROC BindBuffer;
		static PFNGLBUFFERDATAPROC BufferData;
		static PFNGLENABLEVERTEXATTRIBARRAYPROC EnableVertexAttribArray;
		static PFNGLVERTEXATTRIBPOINTERPROC VertexAttribPointer;
		static PFNGLGENVERTEXARRAYSPROC GenVertexArrays;
		static PFNGLBINDVERTEXARRAYPROC BindVertexArray;
		static PFNGLDELETEBUFFERSPROC DeleteBuffers;
		static PFNGLDELETEVERTEXARRAYSPROC DeleteVertexArrays;
		static PFNGLCREATESHADERPROC CreateShader;
		static PFNGLSHADERSOURCEPROC ShaderSource;
		static PFNGLCOMPILESHADERPROC CompileShader;
		static PFNGLUSEPROGRAMPROC UseProgram;
		static PFNGLCREATEPROGRAMPROC CreateProgram;
		static PFNGLATTACHSHADERPROC AttachShader;
		static PFNGLLINKPROGRAMPROC LinkProgram;
		static PFNGLVALIDATEPROGRAMPROC ValidateProgram;
		static PFNGLDELETESHADERPROC DeleteShader;
		static PFNGLDELETEPROGRAMPROC DeleteProgram;
		static PFNGLGETSHADERIVPROC GetShaderiv;
		static PFNGLGETSHADERINFOLOGPROC GetShaderInfoLog;
		static PFNGLGETUNIFORMLOCATIONPROC GetUniformLocation;
		static PFNGLUNIFORMMATRIX4FVPROC UniformMatrix4fv;
		static PFNGLUNIFORM1IPROC Uniform1i;
		static PFNGLGENERATEMIPMAPPROC GenerateMipmap;
		static PFNGLACTIVETEXTUREPROC ActiveTexture;
		static PFNGLBUFFERSUBDATAPROC BufferSubData;

		enum {
			ArrayBuffer = GL_ARRAY_BUFFER,
			StaticDraw = GL_STATIC_DRAW,
			ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
			VertexShader = GL_VERTEX_SHADER,
			FragmentShader = GL_FRAGMENT_SHADER,
			DynamicDraw = GL_DYNAMIC_DRAW
		};

	};

}

#endif