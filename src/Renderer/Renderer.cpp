#include <SDL2/SDL.h>
#include "Renderer/Renderer.h"
#include "Renderer/Color.h"
#include "Engine.h"

namespace Hunga {
    void Renderer::Init() {
        m_BGColor = NUT_CBULE;
        m_Renderer = SDL_CreateRenderer ( &Engine::Instance().GetWidnow(), -1, SDL_RENDERER_ACCELERATED );

        SDL_SetRenderDrawColor(
            m_Renderer,
            m_BGColor.r,
            m_BGColor.g,
            m_BGColor.b,
            m_BGColor.a
        );
    }

    void Renderer::Update() {
        SDL_Rect rect;
        rect.x = 100;
        rect.y = 100;
        rect.w = 100;
        rect.h = 100;

        SDL_RenderClear(m_Renderer);

        for (Sprite* s : m_Sprites) {
            SDL_RenderCopy(m_Renderer, s, nullptr, &rect);
        }

        SDL_RenderPresent(m_Renderer);
    }

    void Renderer::PushSprite(Sprite* sprite) {
        m_Sprites.push_back(sprite);
    }
}