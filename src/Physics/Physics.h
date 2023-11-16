#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include <chipmunk.h>

namespace Hunga {
    class Physics {
        public:
            void Init();
            void ShutDown();

            void Update();

        private:
            cpSpace* m_World;
            cpVect* m_gravity;
    };
}

#endif