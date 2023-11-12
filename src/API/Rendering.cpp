#include "Engine.h"
#include "API/Rendering.h"
#include "Defines.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

namespace Hunga {
    Renderer& renderer = Engine::Instance().GetRenderer();

    Sprite* LoadSprite(std::string SpritePath) {
        SDL_Surface* SpriteSurface = IMG_Load(SpritePath.c_str());
        SDL_Texture* sprite = SDL_CreateTextureFromSurface(renderer.GetRenderer(), SpriteSurface);

        SDL_FreeSurface(SpriteSurface);

        return sprite;
    }

    void DrawSprite(Sprite* sprite) {
        renderer.PushSprite(sprite);
    }
}