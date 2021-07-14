#ifndef ONFER_SCENE_H
#define ONFER_SCENE_H

#include "Window.h"
#include "WindowResizeEvent.h"
#include "WindowCloseEvent.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/OpenGL/OpenGLVertexArray.h"
#include "../Renderer/BufferLayout.h"
#include "../Renderer/Shader.h"
#include "../Renderer/Renderer2D/Camera2D.h"
#include "../Renderer/Texture.h"
#include "../Renderer/Renderer2D/Sprite.h"
#include "../Renderer/BatchRender.h"

namespace Onfer {

	class Scene {
	private:
		Window* m_Window;
		Renderer* m_Renderer;
		Camera2D* m_Camera;
		bool m_Running;
		VertexArray* va; // temporal
		VertexBuffer* vb; // temporal 
		IndexBuffer* ib; // temporal
		Shader* shader; // temporal
		Texture* texture; // temporal
		Sprite* sprite;
		Quad quad = Quad(-0.2f, -0.2f, 0.2, 0.2, 0.8f, 0.2f, 0.3, 1.0f);
		Quad quad2 = Quad(0.5f, 0.5f, 0.2, 0.2, 0.8f, 0.2f, 0.3, 1.0f);
		std::vector<Sprite> sprites;
	public:
		Scene();
		virtual ~Scene();
		// Right here goes the methods that you want to be dispatched depending on the event
		virtual void setCallbacks();
		virtual void run();

		// Default handler events
		virtual void windowResizeEvent(WindowResizeEvent e);
		virtual void windowCloseEvent(WindowCloseEvent e);
		virtual void windowMoveEvent(WindowMoveEvent e);
		virtual void keyEvents(KeyEvents e);
	};

}

#endif