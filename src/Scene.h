#ifndef _SCENE_H_
#define _SCENE_H_

#include "ECS/Registry.h"

namespace Hunga {
    class Scene {
        public:
            _HungaEntity CreatObject();
            inline Registry& Reg() { return m_Registry; };

        private:
            Registry m_Registry;
            
            friend class GameObject;
    };
}

#endif