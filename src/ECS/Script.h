#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include "uuid.h"
#include "ECS/GameObject.h"

#include <cstdint>

namespace Hunga {
    class Script {
        public:
            uint32_t _uuid;
            Script() {};
            ~Script() {};

        private:
            virtual void Awake() {};
            virtual void Start() {};
            virtual void Update() {};
            virtual void LateUpdate() {};
            virtual void FixedUpdate() {};

            virtual void SerializeFeilds() {};

        friend class GameObject;
    };
}

#endif