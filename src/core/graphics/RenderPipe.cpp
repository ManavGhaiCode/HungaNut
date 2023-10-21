#include <log.h> // logging file

// Graphics stuff
#include <glad/glad.h>
#include <core/graphics/mesh.h>
#include <core/graphics/shader.h>
#include <core/graphics/RenderPipe.h>

namespace Hunga::Graphics {
    void RenderMesh::Execute() {
        std::shared_ptr<Mesh> mesh = m_mesh.lock();
        std::shared_ptr<Shader> shader = m_shader.lock();

        if (mesh && shader) {
            mesh->Bind();
            shader->Bind();

            if (mesh->GetElementCount() > 0) {
                glDrawElements(GL_TRIANGLES, mesh->GetElementCount(), GL_UNSIGNED_INT, 0);
            } else {
                glDrawArrays(GL_TRIANGLE_STRIP, 0, mesh->GetVertexCount());
            }

            shader->UnBind();
            mesh->UnBind();
        } else {
            NUT_WARN("Attempting to use RenderMesh without shader or mesh...");
        }
    }
}