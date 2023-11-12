#include <SDL2/SDL.h>
#include "Renderer/Renderer.h"
#include "Engine.h"

namespace Hunga {
    void Renderer::Init() {
        m_Renderer = SDL_CreateRenderer ( Engine::Instance().GetWidnow(), -1, SDL_RENDERER_ACCELERATED );
        SDL_SetRenderDrawColor(m_Renderer, 175, 100, 175, 255);
    }

    void Renderer::Update() {
        SDL_RenderClear(m_Renderer);

        SDL_Rect rect;
        rect.x = 350;
        rect.y = 250;
        rect.h = 100;
        rect.w = 100;

        SDL_SetRenderDrawColor(m_Renderer, 0, 100, 175, 255);
        SDL_RenderDrawRect(m_Renderer, &rect);
        SDL_RenderPresent(m_Renderer);

        SDL_SetRenderDrawColor(m_Renderer, 175, 100, 175, 255);
    }
}