#ifndef _RENDERPIPE_H_
#define _RENDERPIPE_H_

#include <memory>

namespace Hunga::Graphics {
    class Mesh;
    class Shader;

    class RenderCommand {
        public:
            virtual void Execute() = 0;
            virtual ~RenderCommand() {};
    };

    class RenderMesh : public RenderCommand {
        public:
            RenderMesh(std::weak_ptr<Mesh> mesh, std::weak_ptr<Shader> shader)
                : m_mesh(mesh)
                , m_shader(shader) 
            {};

            virtual void Execute();

        private:
        std::weak_ptr<Mesh> m_mesh;
        std::weak_ptr<Shader> m_shader;

    };
}

#endif