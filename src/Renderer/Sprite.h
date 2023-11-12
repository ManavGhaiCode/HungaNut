#ifndef _SPRITE_H_
#define _SPRITE_H_

struct SDL_Texture;
namespace Hunga {
    struct Sprite {
        SDL_Texture* texture;

        int x;
        int y;
        int w;
        int h;
    };
}

#endif