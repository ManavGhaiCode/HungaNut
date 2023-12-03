#ifndef _SCRIPT_H_
#define _SCRIPT_H_

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
            virtual void SerializeFeilds() {};
            virtual void Update() {};
            virtual void LateUpdate() {};
            virtual void FixedUpdate() {};

            virtual void OnDestroy() {};

        friend class GameObject;
    };
}

#endif