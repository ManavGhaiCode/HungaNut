// #include <SDL2/SDL.h>
#include "Renderer/Renderer.h"
#include "Renderer/Sprite.h"
#include "Renderer/Color.h"
#include "Renderer/vkInit.h"
#include "Engine.h"

namespace Hunga {
    void Renderer::Init() {
        m_Instance = vkInit::Init("Window!");

        // m_BGColor = NUT_CBULE;
        // m_Renderer = SDL_CreateRenderer ( &Engine::Instance().GetWidnow(), -1, SDL_RENDERER_ACCELERATED );

        // SDL_SetRenderDrawColor(
        //     m_Renderer,
        //     m_BGColor.r,
        //     m_BGColor.g,
        //     m_BGColor.b,
        //     m_BGColor.a
        // );
    }

    void Renderer::Update() {
    //     SDL_RenderClear(m_Renderer);

    //     for (Sprite s : m_Sprites) {
    //         SDL_Rect rect;
    //         rect.x = s.x;
    //         rect.y = s.y;
    //         rect.h = s.h;
    //         rect.w = s.w;

    //         SDL_RenderCopy(m_Renderer, s.texture, nullptr, &rect);
    //     }

    //     SDL_RenderPresent(m_Renderer);
    //     m_Sprites.clear();
    }

    void Renderer::ShutDown() {
        m_Instance.destroy();
        // m_Sprites.clear();
    }

    void Renderer::PushSprite(Sprite sprite) {
        // m_Sprites.push_back(sprite);
    }
}