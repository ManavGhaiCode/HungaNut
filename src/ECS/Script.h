#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include <cstdint>
#include <string>

namespace Hunga {
    class Script {
        public:
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
    };

    struct VariableScript {
        void* script = nullptr;
        std::string TypeName = "";

        VariableScript() = default;

        template <typename T>
        VariableScript(const T& other)
            : TypeName(NUT_TYPEOF(T))
        {
            *( (T*)script ) = &other;
        }
    };
}

#endif