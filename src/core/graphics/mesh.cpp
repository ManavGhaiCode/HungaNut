#include <glad/glad.h>
#include <core/graphics/mesh.h>

namespace Hunga::Graphics {
    Mesh::Mesh(float* vertexArray, uint32_t vertexCount, uint32_t dimensions) 
        : m_vertexCount(vertexCount) 
    {
        glGenVertexArrays(1, &m_VAO);
        glBindVertexArray(m_VAO);

        glGenBuffers(1, &m_PostionVBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_PostionVBO);
        glBufferData(GL_ARRAY_BUFFER, vertexCount * dimensions * (uint32_t)sizeof(float), vertexArray, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, dimensions, GL_FLOAT, GL_FALSE, 0, 0);
        glDisableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }

    Mesh::~Mesh() {
        glDeleteBuffers(1, &m_VAO);
        glDeleteVertexArrays(1, &m_VAO);
    }

    void Mesh::Bind() {
        glBindVertexArray(m_VAO);
        glEnableVertexAttribArray(0);
    }

    void Mesh::UnBind() {
        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
    }
}