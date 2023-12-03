#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <cstdint>
#include <map>

namespace Hunga {
    GameObject emptyObject;

    class Script {
        public:
            uint32_t _uuid;
            Script()
                : gameObject(emptyObject) 
            {};
            
            ~Script() {};

        private:
            GameObject& gameObject;

            virtual void Awake() {};
            virtual void Start() {};
            virtual void SerializeFeilds() {};
            virtual void Update() {};
            virtual void LateUpdate() {};
            virtual void FixedUpdate() {};

            virtual void OnDestroy() {};

        friend class GameObject;
    };

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