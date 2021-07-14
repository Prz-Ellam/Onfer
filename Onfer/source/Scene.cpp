#include "Scene.h"
#include <chrono>
#include <gl/GL.h>
#include "../Renderer/OpenGL/OpenGLRenderer.h"
#include "../OpenGL/OpenGL.h"
#include "../Renderer/OpenGL/OpenGLIndexBuffer.h"
#include "../Renderer/OpenGL/OpenGLShader.h"
#include "../Renderer/OpenGL/OpenGLTexture.h"
#include "../utils/Timer.h"
#include "../Renderer/VertexBufferFactory.h"
#include "../Renderer/IndexBufferFactory.h"
#include "../Renderer/Renderer2D/Quad.h"

#define EVENT_FN(name) std::bind(&Scene::##name, this, std::placeholders::_1)

namespace Onfer {

	Scene::Scene() : m_Running(true) {

		Timer time(__FUNCTION__);

		m_Window = new Window();
		m_Renderer = new OpenGLRenderer();
		gl::init();
		setCallbacks();
		m_Window->show(ShowWindowMode::ShowDefault);
		float width = (float)m_Window->getWidth() / 1000;
		float height = (float)m_Window->getHeight() / 1000;
		m_Camera = new Camera2D(-width, width, -height, height, -1.0f, 1.0f);

#pragma region PENDIENTE			
		//Vertex vertices[] = {	Vertex({-0.5f, -0.5f,  0.0f}, {1.0f,  1.0f,  1.0f,  1.0f}, {0.0f,  0.0f}),
		//						Vertex({ 0.5f, -0.5f,  0.0f}, {1.0f,  1.0f,  1.0f,  1.0f}, {0.0f,  0.0f}),
		//						Vertex({ 0.0f,  0.5f,  0.0f}, {1.0f,  1.0f,  1.0f,  1.0f}, {0.0f,  0.0f})
		//};

		//OpenGLVertexArray va;
		//OpenGLVertexBuffer vb = OpenGLVertexBuffer(vertices, sizeof(vertices));
		//
		//std::vector<BufferLayout> layouts;
		//layouts.push_back(BufferLayout(0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, texCoords)));

		//va.attachVB(&vb, layouts);

		////float vertices[] = { -0.5f, -0.5f,
		////					  0.5f, -0.5f,
		////					  0.0f,  0.5f };

		//gl::GenBuffers(1, &vertexBuffer);
		//gl::BindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		//gl::BufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		//gl::GenVertexArrays(1, &vertexArray);
		//gl::BindVertexArray(vertexArray);

		//gl::EnableVertexAttribArray(0);
		//gl::VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
#pragma endregion
		     
		va = new OpenGLVertexArray();

		//batchRender = new BatchRender();

		// No hay que especificar el tamanio del Quad en el constructor, de eso que se encargue la clase sprite, cambiarlo

		sprite = new Sprite(vec3(0.0f, 0.0f, 0.0f), vec3(1.0f, 1.0f, 1.0f), 45.0f, "Assets//prueba.jpg", vec4(0.8, 0.2, 0.3, 1.0f));

		//sprites.push_back(sprite);

		// Sprite sprite = Sprite(vec3(0.0f, 0.0f, 0.0f), vec3(1.0f, 1.0f, 1.0f), 0.0f, "Assets//prueba.jpg", vec4(0.8, 0.2, 0.3, 1.0f));


		

		/*Vertex2D vertices[] = {	Vertex2D(vec3(-0.5f, -0.5f,  0.0f), vec4(0.8f, 0.2f, 0.3f, 1.0f), vec2(0.0f, 0.0f)), 
								Vertex2D(vec3( 0.5f, -0.5f,  0.0f), vec4(0.8f, 0.2f, 0.3f, 1.0f), vec2(1.0f, 0.0f)),
								Vertex2D(vec3( 0.5f,  0.5f,  0.0f), vec4(0.8f, 0.2f, 0.3f, 1.0f), vec2(1.0f, 1.0f)),
								Vertex2D(vec3(-0.5f,  0.5f,  0.0f), vec4(0.8f, 0.2f, 0.3f, 1.0f), vec2(0.0f, 1.0f)),
		};*/

		std::vector<BufferLayout> layouts;
		layouts.push_back(BufferLayout(0, DataType::Float3));
		layouts.push_back(BufferLayout(1, DataType::Float4));
		layouts.push_back(BufferLayout(2, DataType::Float2));

		uint32_t index[] = { 0, 1, 2, 2, 3, 0 };

		vb = VertexBufferFactory::createVertexBuffer(VERTEX_QUAD_SIZE * 1000);
		ib = IndexBufferFactory::createIndexBuffer(INDEX_QUAD_SIZE * 1000);

		va->attachVertexBuffer(vb, layouts);
		va->attachIndexBuffer(ib);

		shader = new OpenGLShader("Assets//VertexShader.glsl", "Assets//FragmentShader.glsl");
		texture = new OpenGLTexture("Assets//prueba.jpg");

	}

	Scene::~Scene() {

		delete m_Renderer;
		delete m_Window;
		delete m_Camera;
		delete shader;
		delete sprite;

	}

	void Scene::setCallbacks() {
	
		m_Window->setWindowResizeEventCallback(EVENT_FN(windowResizeEvent));
		m_Window->setWindowMoveEventCallback(EVENT_FN(windowMoveEvent));
		m_Window->setWindowCloseEventCallback(EVENT_FN(windowCloseEvent));
		m_Window->setKeyEventsCallback(EVENT_FN(keyEvents));

	}

	void Scene::run() {

		while (m_Running) {

			m_Window->update();

			m_Renderer->beginScene(*m_Camera);

			m_Renderer->clear(0.1f, 0.1f, 0.1f, 1.0f);


			vb->sendData(sprite->getTransformQuad(), VERTEX_QUAD_SIZE, 0);
			ib->sendData(quad.getIndexData(), INDEX_QUAD_COUNT, 0);

			vb->sendData(quad2.getVertexData(), VERTEX_QUAD_SIZE, VERTEX_QUAD_SIZE);
			ib->sendData(quad2.getIndexData(), INDEX_QUAD_COUNT, INDEX_QUAD_SIZE);

			m_Camera->move();

			// m_Renderer->draw(sprites);
			// for (auto& sprite : sprites) 
			//    batch rendering
			// endScene -> draw call to OpenGL
			

			texture->bind(1);
			shader->bind();
			shader->setInt1("u_Texture", 1);
			m_Renderer->draw(va, shader);
#pragma region PENDIENTE
			//gl::BindVertexArray(vertexArray);
			//shader->bind();
			//shader->setMat4("u_Projection", m_Camera->getProjection());
			//shader->setMat4("u_View", m_Camera->getView());
			//va->bind();
			//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
			//glDrawArrays(GL_TRIANGLES, 0, 3);
#pragma endregion

			m_Renderer->endScene();
			
		}

	}

	void Scene::windowResizeEvent(WindowResizeEvent e) {

		Log::info(e.toString().c_str());
		m_Renderer->viewport(0, 0, e.getWidth(), e.getHeight());

	}

	void Scene::windowCloseEvent(WindowCloseEvent e) {

		Log::info("Window closed!");
		m_Running = false;

	}

	void Scene::windowMoveEvent(WindowMoveEvent e) {
	
		Log::info(e.toString());
	
	}

	void Scene::keyEvents(KeyEvents e) {

		//m_Events = e;
		//m_Camera->move(e);

		/*if (e.isKeyPressed(KeyCode::KeyW)) {
			Log::info("Key W is pressed");
		}
		if (e.isKeyPressed(KeyCode::KeyA)) {
			Log::info("Key A is pressed");
		}*/
		//if (e.getLastKey() == KeyCode::KeyF) {
			//printf("F is the last key pressed\n");
		//}

	}

}