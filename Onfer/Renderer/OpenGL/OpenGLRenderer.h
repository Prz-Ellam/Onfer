#ifndef ONFER_OPENGL_RENDERER_H
#define ONFER_OPENGL_RENDERER_H

#include "../Renderer.h"
#include "../VertexArray.h"
#include "../Shader.h"

namespace Onfer {

	class OpenGLRenderer : public Renderer {
	public:
		OpenGLRenderer() = default;
		void beginScene(Camera2D& camera) override;
		void clear(float r, float g, float b, float a) override;
		void render() override;
		void endScene() override;
		void viewport(int x, int y, int width, int height) override;
		void draw(VertexArray* va, Shader* shader) override; // temporal
		//void draw(BatchRender& br, Shader* shader) override;
	private:
		mat4 m_Projection, m_View;
	};

}

#endif