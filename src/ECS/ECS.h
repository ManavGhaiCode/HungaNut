#ifndef _ECS_H_
#define _ECS_H_

#include "ECS/GameObject.h"

#include <cstdint>
#include <map>

namespace Hunga {
    class ECS {
        public:
            void ShutDown();

            void AddObject(GameObject& gameObject);
            void AddObject_withUuid(GameObject& gameObject, uint32_t uuid);
            void DeleteObject(uint32_t uuid);

            GameObject& GetObject_uuid(uint32_t uuid);
            void SetObjectUuid(uint32_t uuid, uint32_t new_uuid);

            GameObject static emptyObject;

        private:
            void Awake();
            void Start();
            void Update();
            void LateUpdate();
            void FixedUpdate();

            void Serialize();

            std::map<uint32_t, GameObject> m_Objects;
    };

    GameObject ECS::emptyObject = GameObject ();
}


#endif