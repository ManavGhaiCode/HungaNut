#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <cstdint>
#include "Renderer/Color.h"

struct SDL_Renderer;
namespace Hunga {
    class Renderer {
        public:
            void Init();
            void Update();

        private:
            SDL_Renderer *m_Renderer;
            Color m_BGColor { 0 ,0 ,0 ,0 };

            void Flush();
    };
}

#endif