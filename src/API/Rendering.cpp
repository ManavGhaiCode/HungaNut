#include "Engine.h"
#include "API/Rendering.h"
#include "Renderer/Sprite.h"
#include "Defines.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

namespace Hunga {
    Renderer& renderer = Engine::Instance().GetRenderer();

    Sprite LoadSprite(std::string SpritePath) {
        // SDL_Surface* SpriteSurface = IMG_Load(SpritePath.c_str());
        // SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer.GetRenderer(), SpriteSurface);

        Sprite sprite;
        // sprite.texture = spriteTexture;
        // sprite.h = SpriteSurface->h;
        // sprite.w = SpriteSurface->w;
        // sprite.x = 100;
        // sprite.y = 100;

        // SDL_FreeSurface(SpriteSurface);

        return sprite;
    }

    void DrawSprite(Sprite sprite, int x, int y) {
        sprite.x = x;
        sprite.y = y;
        renderer.PushSprite(sprite);
    }
}