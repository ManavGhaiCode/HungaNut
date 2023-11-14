#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include <box2d/box2d.h>

namespace Hunga {
    class Physics {
        public:
            void Init();
            void Update();

        private:
            b2Vec2* m_gravity = nullptr;
            b2World* m_World = nullptr;
    };
}

#endif