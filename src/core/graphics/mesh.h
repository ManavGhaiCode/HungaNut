#ifndef _MESH_H_
#define _MESH_H_

#include <cstdint>

namespace Hunga::Graphics {
    class Mesh {
        public:
            Mesh(float* vertexArray, uint32_t vertexCount, uint32_t dimensions);
            ~Mesh();

            void Bind();

            void UnBind();

        private:
            uint32_t m_vertexCount;
            uint32_t m_PostionVBO;
            uint32_t m_VAO;
    };
}

#endif