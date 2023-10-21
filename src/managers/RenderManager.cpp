#include <log.h>
#include <managers/RenderManager.h>

#include <glad/glad.h>
#include <SDL2/SDL.h>

namespace Hunga::Managers {
    void RenderManager::init() {
        NUT_INFO ( 
            "OpenGL Info:\n \tVendor: {}\n \tRenderer: {}\n \tVersion: {}", 
            (const char*)glGetString(GL_VENDOR), 
            (const char*)glGetString(GL_RENDERER), 
            (const char*)glGetString(GL_VERSION)
        );

        // Init OpenGL

        gladLoadGLLoader(SDL_GL_GetProcAddress);

        glEnable(GL_DEPTH_TEST); // for allowing the use of depth
        glDepthFunc(GL_LEQUAL); // set func for depth

        glEnable(GL_BLEND); // for allowing the use of transparency
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // set func for transparency

        glClearColor(
            static_cast<float>(0x64) / static_cast<float>(0xFF),
            static_cast<float>(0x75) / static_cast<float>(0xFF),
            static_cast<float>(0xED) / static_cast<float>(0xFF),
            1
        ); // set default COLOR to cornflower blue.
    }

    void RenderManager::ShutDown() {
        while (m_RenderQueue.size() > 0) {
            m_RenderQueue.pop();
        }
    }

    void RenderManager::Submit(std::unique_ptr<Graphics::RenderCommand> renderCommand) {
        m_RenderQueue.push(std::move(renderCommand));
    }

    void RenderManager::Flush() {
        while (m_RenderQueue.size() > 0) {
            auto renderCommand = std::move(m_RenderQueue.front());
            renderCommand->Execute();
            
            m_RenderQueue.pop();
        }
    }

    void RenderManager::SetClearColor(float r, float g, float b, float a) {
        glClearColor(r, g, b, a); // set BG color the rgba value
    }

    void RenderManager::Clear() {
        NUT_ASSERT(m_RenderQueue.size() == 0, "Render queue not flushed");
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void RenderManager::SetWireFrameMode(bool mode) {
        if (mode) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
    }
}