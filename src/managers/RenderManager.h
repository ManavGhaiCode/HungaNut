#include <core/graphics/RenderPipe.h>

#include <memory>
#include <queue>

namespace Hunga::Managers {
    class RenderManager {
        public:
            RenderManager() {};
            ~RenderManager() {};

            void init();
            void ShutDown();
            
            void Clear();

            void Submit(std::unique_ptr<Graphics::RenderCommand> renderCommand);
            void SetClearColor(float r, float g, float b, float a);

            // Ececution will happen in the order of submition to the API.
            void Flush();
            
        private:

            // unique_ptr is uned to allow for useage polymorphism AKA OPP.
            std::queue<std::unique_ptr<Graphics::RenderCommand>> m_RenderQueue; 
    };
}