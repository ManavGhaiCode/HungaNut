#ifndef _RENDERING_API_H_
#define _RENDERING_API_H_

#include <string>

struct SDL_Texture;
namespace Hunga {
    SDL_Texture* LoadSprite(std::string SpritePath);
    void DrawSprite(Sprite* sprite);
}

#endif