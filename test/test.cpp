#include "HungaNut.h"

Hunga::Sprite sprite;

void Hunga::GameStart() {
    sprite = Hunga::LoadSprite("../test/fx/sprite.png");
}

void Hunga::GameUpdate() {
    Hunga::DrawSprite(sprite, 350, 250);
}