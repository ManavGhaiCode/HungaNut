#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <cstdint>
#include <vector>

#include "Defines.h"
#include "Renderer/Color.h"
#include "Renderer/Sprite.h"
#include <vulkan/vulkan.hpp>

struct SDL_Renderer;
namespace Hunga {
    class Renderer {
        public:
            void Init();
            void ShutDown();
            void Update();

            // SDL_Renderer* GetRenderer() { return m_Renderer; }

            void PushSprite(Sprite sprite);

        private:
            vk::Instance m_Instance;
            Color m_BGColor { 0 ,0 ,0 ,0 };
    };
}

#endif