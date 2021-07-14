#ifndef ONFER_RENDERER_H
#define ONFER_RENDERER_H

#include <Windows.h>
#include <gl/GL.h>
#include "Shader.h"
#include "VertexArray.h"
#include "../Renderer/Renderer2D/Camera2D.h"
#include "../Renderer/Renderer2D/Sprite.h"
#include "../Renderer/BatchRender.h"

namespace Onfer {

	class Renderer {
	public:
		virtual void beginScene(Camera2D& camera) = 0;
		virtual void clear(float r, float g, float b, float a) = 0;
		virtual void render() = 0;
		virtual void endScene() = 0;
		virtual void viewport(int x, int y, int width, int height) = 0;
		virtual void draw(VertexArray* va, Shader* shader) = 0;
		//virtual void draw(BatchRender& br, Shader* shader) = 0;
	protected:
		Renderer() = default;
	};

}

#endif