#include "OpenGLRenderer.h"
#include "../../OpenGL/OpenGL.h"

namespace Onfer {

	void OpenGLRenderer::beginScene(Camera2D& camera) {

		m_Projection = camera.getProjection();
		m_View = camera.getView();
	
	}

	void OpenGLRenderer::clear(float r, float g, float b, float a) {
	
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);

	}

	void OpenGLRenderer::viewport(int x, int y, int width, int height) {
	
		glViewport(x, y, width, height);

	}

	void OpenGLRenderer::render() {
	
	}

	void OpenGLRenderer::endScene() {
	
	}

	void OpenGLRenderer::draw(VertexArray* va, Shader* shader) {

		shader->bind();
		shader->setMat4("u_Projection", m_Projection);
		shader->setMat4("u_View", m_View);
		va->bind();
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);

	}

	//void OpenGLRenderer::draw(BatchRender& br, Shader* shader) {

	//	br.loadDataToVAO();
	//	br.activeVAO();
	//	shader->bind();
	//	shader->setMat4("u_Projection", m_Projection);
	//	shader->setMat4("u_View", m_View);
	//	glDrawElements(GL_TRIANGLES, br.indexCount(), GL_UNSIGNED_INT, nullptr);

	//}

}