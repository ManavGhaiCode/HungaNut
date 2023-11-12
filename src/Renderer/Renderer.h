#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <cstdint>
#include <vector>

#include "Defines.h"
#include "Renderer/Color.h"
#include "Renderer/Sprite.h"

struct SDL_Renderer;
namespace Hunga {
    class Renderer {
        public:
            void Init();
            void ShutDown();
            void Update();

            SDL_Renderer* GetRenderer() { return m_Renderer; }

            void PushSprite(Sprite sprite);

        private:
            SDL_Renderer *m_Renderer;
            Color m_BGColor { 0 ,0 ,0 ,0 };

            std::vector<Sprite> m_Sprites;
    };
}

#endif