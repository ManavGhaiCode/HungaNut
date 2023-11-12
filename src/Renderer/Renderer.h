#ifndef _RENDERER_H_
#define _RENDERER_H_

struct SDL_Renderer;
namespace Hunga {
    class Renderer {
        public:
            void Init();
            void Update();
        private:
            SDL_Renderer *m_Renderer;
    };
}

#endif