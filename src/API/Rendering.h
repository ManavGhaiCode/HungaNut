#ifndef _RENDERING_API_H_
#define _RENDERING_API_H_

#include "Renderer/Sprite.h"
#include <string>

struct SDL_Texture;

namespace Hunga {
    Sprite LoadSprite(std::string SpritePath);
    void DrawSprite(Sprite sprite, int x, int y);
}

#endif