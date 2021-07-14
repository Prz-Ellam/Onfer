//#include "BatchRender.h"
//#include "OpenGL/OpenGLVertexArray.h"
//#include "OpenGL/OpenGLVertexBuffer.h"
//#include "OpenGL/OpenGLIndexBuffer.h"
//#include "VertexBufferFactory.h"
//#include "IndexBufferFactory.h"
//
//namespace Onfer {
//
//	BatchRender::BatchRender() : m_VBOffset(0), m_IBOffset(0) {
//
//		m_VAO = new OpenGLVertexArray();
//		m_VBO = VertexBufferFactory::createVertexBuffer(VERTEX_QUAD_SIZE * 1000);
//		m_IBO = IndexBufferFactory::createIndexBuffer(INDEX_QUAD_COUNT * 1000);
//
//		layouts.push_back(BufferLayout(0, DataType::Float3));
//		layouts.push_back(BufferLayout(1, DataType::Float4));
//		layouts.push_back(BufferLayout(2, DataType::Float2));
//
//	}
//
//	void BatchRender::batchSprite(Sprite& sprite) {
//
//		m_VBO->sendData(sprite.getQuad()->getVertexData(), VERTEX_QUAD_SIZE, m_VBOffset);
//		m_VBOffset += VERTEX_QUAD_SIZE;
//
//		m_IBO->sendData(sprite.getQuad()->getIndexData(), INDEX_QUAD_COUNT, m_IBOffset);
//		m_IBOffset += INDEX_QUAD_SIZE;
//
//	}
//
//	void BatchRender::loadDataToVAO() {
//
//		m_VAO->attachVertexBuffer(m_VBO, layouts);
//		m_VAO->attachIndexBuffer(m_IBO);
//
//	}
//
//	void BatchRender::activeVAO() {
//
//		m_VAO->bind();
//
//	}
//
//	uint32_t BatchRender::indexCount() {
//
//		return m_IBOffset / sizeof(uint32_t);
//
//	}


//}