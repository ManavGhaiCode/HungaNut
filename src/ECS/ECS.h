#ifndef _ECS_H_
#define _ECS_H_

#include "ECS/GameObject.h"

#include <map>
#include <vector>
#include <cstdint>

namespace Hunga {
    class ECS {
        public:
            void AddObject(GameObject& gameObject);
            void DeleteObject(uint32_t uuid);

            std::map<uint32_t, GameObject>& GetObjects();
            GameObject& GetObject_uuid(uint32_t uuid);

        private:
            std::map<uint32_t, GameObject> m_Objects;
    };
}

#endif