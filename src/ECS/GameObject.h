#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "ECS/Script.h"

#include <cstdint>
#include <map>

namespace Hunga {
    class GameObject {
        public:
            uint32_t _uuid;

            void AddScript(Script& script);
            void DeleteScript(uint32_t uuid);

            void ShutDown();

        private:
            void Awake();
            void Start();
            void Update();
            void LateUpdate();
            void FixedUpdate();
            
            void Serialize();

            std::map<uint32_t, Script*> m_Scripts;

        friend class ECS;
    };
}

#endif