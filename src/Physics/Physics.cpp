#include "Physics/Physics.h"

namespace Hunga {
    void Physics::Init() {
        m_gravity = new b2Vec2 ( 0.0f, 9.8f );
        m_World = new b2World ( *m_gravity );
    }

    void Physics::Update() {
        // Physics
    }
}