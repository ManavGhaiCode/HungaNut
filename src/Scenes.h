#ifndef _SCENES_H_
#define _SCENES_H_

#include "ECS/ECS.h"

namespace Hunga {
    class Scene {
        public:
            void Init() {};
            void ShutDown();

            inline ECS& GetECS() { return m_ECS; };
        private:
            ECS m_ECS;
    };
}

#endif