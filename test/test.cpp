#include "HungaNut.h"

Hunga::Sprite sprite;

void Hunga::GameStart() {
    sprite = Hunga::LoadSprite("../test/fx/sprite.png");
}

void Hunga::GameUpdate() {
    Hunga::DrawSprite(sprite, 350, 250);

    if (GetKey(Keys::X)) {
        NUT_TRACE("Pressed Key X.");
    }
}

void Hunga::GameStop() {
    NUT_TRACE("Game End.");
}

void Hunga::MakeScene(Hunga::Scene& scene) {}