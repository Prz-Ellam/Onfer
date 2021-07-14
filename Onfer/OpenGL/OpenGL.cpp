#include "OpenGL.h"
#include "../utils/Log.h"

namespace Onfer {

	PFNGLGENBUFFERSPROC gl::GenBuffers = nullptr;
	PFNGLBINDBUFFERPROC gl::BindBuffer = nullptr;
	PFNGLBUFFERDATAPROC gl::BufferData = nullptr;
	PFNGLENABLEVERTEXATTRIBARRAYPROC gl::EnableVertexAttribArray = nullptr;
	PFNGLVERTEXATTRIBPOINTERPROC gl::VertexAttribPointer = nullptr;
	PFNGLGENVERTEXARRAYSPROC gl::GenVertexArrays = nullptr;
	PFNGLBINDVERTEXARRAYPROC gl::BindVertexArray = nullptr;
	PFNGLDELETEBUFFERSPROC gl::DeleteBuffers = nullptr;
	PFNGLDELETEVERTEXARRAYSPROC gl::DeleteVertexArrays = nullptr;
	PFNGLCREATESHADERPROC gl::CreateShader = nullptr;
	PFNGLSHADERSOURCEPROC gl::ShaderSource = nullptr;
	PFNGLCOMPILESHADERPROC gl::CompileShader = nullptr;
	PFNGLUSEPROGRAMPROC	gl::UseProgram = nullptr;
	PFNGLCREATEPROGRAMPROC gl::CreateProgram = nullptr;
	PFNGLATTACHSHADERPROC gl::AttachShader = nullptr;
	PFNGLLINKPROGRAMPROC gl::LinkProgram = nullptr;
	PFNGLVALIDATEPROGRAMPROC gl::ValidateProgram = nullptr;
	PFNGLDELETESHADERPROC gl::DeleteShader = nullptr;
	PFNGLDELETEPROGRAMPROC gl::DeleteProgram = nullptr;
	PFNGLGETSHADERIVPROC gl::GetShaderiv = nullptr;
	PFNGLGETSHADERINFOLOGPROC gl::GetShaderInfoLog = nullptr;
	PFNGLGETUNIFORMLOCATIONPROC gl::GetUniformLocation = nullptr;
	PFNGLUNIFORMMATRIX4FVPROC gl::UniformMatrix4fv = nullptr;
	PFNGLGENERATEMIPMAPPROC gl::GenerateMipmap = nullptr;
	PFNGLACTIVETEXTUREPROC gl::ActiveTexture = nullptr;
	PFNGLUNIFORM1IPROC gl::Uniform1i = nullptr;
	PFNGLBUFFERSUBDATAPROC gl::BufferSubData = nullptr;

	bool gl::init() {

		GenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
		if (!GenBuffers) {
			Log::error("Error al obtener gl::GenBuffers");
			return false;
		}

		BindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
		if (!BindBuffer) {
			Log::error("Error al obtener gl::BindBuffers");
			return false;
		}

		BufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
		if (!BufferData) {
			Log::error("Error al obtener gl::BufferData");
			return false;
		}

		EnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
		if (!EnableVertexAttribArray) {
			Log::error("Error al obtener gl::EnableVertexAttribArray");
			return false;
		}

		VertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
		if (!VertexAttribPointer) {
			Log::error("Error al obtener gl::VertexAttribPointer");
			return false;
		}

		GenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
		if (!GenVertexArrays) {
			Log::error("Error al obtener gl::GenVertexArrays");
			return false;
		}

		BindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
		if (!BindVertexArray) {
			Log::error("Error al obtener gl::GenVertexArrays");
			return false;
		}

		DeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
		if (!DeleteBuffers) {
			Log::error("Error al obtener gl::DeleteBuffers");
			return false;
		}

		DeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
		if (!DeleteVertexArrays) {
			Log::error("Error al obtener gl::DeleteVertexArrays");
			return false;
		}

		CreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
		if (!CreateShader) {
			Log::error("Error al obtener gl::CreateShader");
			return false;
		}

		ShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
		if (!ShaderSource) {
			Log::error("Error al obtener gl::ShaderSource");
			return false;
		}

		CompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
		if (!CompileShader) {
			Log::error("Error al obtener gl::CompileShader");
			return false;
		}

		UseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
		if (!UseProgram) {
			Log::error("Error al obtener gl::UseProgram");
			return false;
		}

		CreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
		if (!CreateProgram) {
			Log::error("Error al obtener gl::CreateProgram");
			return false;
		}

		AttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
		if (!AttachShader) {
			Log::error("Error al obtener gl::AttachShader");
			return false;
		}

		LinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
		if (!LinkProgram) {
			Log::error("Error al obtener gl::LinkProgram");
			return false;
		}

		ValidateProgram = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
		if (!ValidateProgram) {
			Log::error("Error al obtener gl::ValidateProgram");
			return false;
		}

		DeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
		if (!DeleteShader) {
			Log::error("Error al obtener gl::DeleteShader");
			return false;
		}

		DeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
		if (!DeleteProgram) {
			Log::error("Error al obtener gl::DeleteProgram");
			return false;
		}

		GetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
		if (!GetShaderiv) {
			Log::error("Error al obtener gl::GetShaderiv");
			return false;
		}

		GetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
		if (!GetShaderInfoLog) {
			Log::error("Error al obtener gl::GetShaderInfoLog");
			return false;
		}

		GetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");;
		if (!GetUniformLocation) {
			Log::error("Error al obtener gl::GetUniformLocation");
			return false;
		}

		UniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");;
		if (!UniformMatrix4fv) {
			Log::error("Error al obtener gl::UniformMatrix4fv");
			return false;
		}

		GenerateMipmap = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");;
		if (!GenerateMipmap) {
			Log::error("Error al obtener gl::GenerateMipmap");
			return false;
		}

		ActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");;
		if (!ActiveTexture) {
			Log::error("Error al obtener gl::ActiveTexture");
			return false;
		}

		Uniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");;
		if (!Uniform1i) {
			Log::error("Error al obtener gl::Uniform1i");
			return false;
		}

		BufferSubData = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");;
		if (!BufferSubData) {
			Log::error("Error al obtener gl::BufferSubData");
			return false;
		}

	}

	void gl::shutDown() {

		Log::info("Shutdown OpenGL");

	}


}