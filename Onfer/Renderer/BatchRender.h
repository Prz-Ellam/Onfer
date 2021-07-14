//#ifndef ONFER_BATCH_RENDER_H
//#define ONFER_BATCH_RENDER_H
//
//#include "IndexBuffer.h"
//#include "VertexBuffer.h"
//#include "VertexArray.h"
//#include "Renderer2D/Sprite.h"
//
//namespace Onfer {
//
//	class BatchRender {
//	public:
//		BatchRender();
//
//		void batchSprite(Sprite& sprite);
//
//		void activeVAO();
//
//		void loadDataToVAO();
//
//		uint32_t indexCount();
//
//	private:
//		VertexArray* m_VAO;
//		VertexBuffer* m_VBO;
//		IndexBuffer* m_IBO;
//		std::vector<BufferLayout> layouts;
//		uint32_t m_VBOffset;
//		uint32_t m_IBOffset;
//	};
//
//}
//
//#endif