#include "Physics/Physics.h"

#include <SDL2/SDL.h>

namespace Hunga {
    void Physics::Init() {
        m_gravity = new b2Vec2 ( 0.0f, 9.8f );
        m_World = new b2World ( *m_gravity );

        b2BodyDef bodyDef;
        bodyDef.angle = 0;
        bodyDef.position.Set(0, 20);
        bodyDef.type = b2_staticBody;

        b2PolygonShape boxShape;
        boxShape.SetAsBox(1, 1);

        b2FixtureDef fixtureDef;
        fixtureDef.density = 0;
        fixtureDef.shape = &boxShape;

        m_body = m_World->CreateBody(&bodyDef);
        m_body->CreateFixture(&fixtureDef);
    }
}