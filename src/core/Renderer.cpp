#include <core/Renderer.h>
#include <SDL2/SDL.h>

#include <Engine.h>

#include <log.h>

namespace Hunga {
    void Renderer::Init() {
        m_renderer = SDL_CreateRenderer(&Engine::Instance().SDL_GetWindow(), -1, 0);

        if (m_renderer == nullptr) {
            NUT_ERROR("Unable to start SDL2 renderer", SDL_GetError())
        }
    }

    void Renderer::Update() {
        SDL_SetRenderDrawColor(m_renderer, 100, 149, 237, 255);
        SDL_RenderClear(m_renderer);
        SDL_RenderPresent(m_renderer);
    }
}