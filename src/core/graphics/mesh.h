#ifndef _MESH_H_
#define _MESH_H_

#include <cstdint>

namespace Hunga::Graphics {
    class Mesh {
        public:
            Mesh(float* vertexArray, uint32_t vertexCount, uint32_t dimensions);
            Mesh(float* vertexArray, uint32_t vertexCount, uint32_t dimensions, uint32_t* elementArray, uint32_t elementCount);
            ~Mesh();

            void Bind();
            void UnBind();

            inline uint32_t GetVertexCount() const { return m_vertexCount; }
            inline uint32_t GetElementCount() const { return m_elementCount; }

        private:
            uint32_t m_elementCount;
            uint32_t m_vertexCount;
            uint32_t m_PostionVBO;
            uint32_t m_VAO;
            uint32_t m_EBO;
    };
}

#endif