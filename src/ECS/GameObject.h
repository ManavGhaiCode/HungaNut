#ifndef _COPONENT_H_
#define _COPONENT_H_

#include "ECS/ECS.h"

#include "ECS/Script.h"
#include "uuid.h"

#include <cstdint>
#include <map>

namespace Hunga {
    class GameObject {
        public:
            uint32_t _uuid;
            GameObject() {};
            ~GameObject();

            void AddScript(Script& Script);
            
        private:
            std::map<uint32_t, Script*> m_Scripts;

            void Awake();
            void Start();
            void Update();
            void LateUpdate();
            void FixedUpdate();

            void Serialze();

        friend class ECS;
    };
}

#endif