#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "Scene.h"
#include "Defines.h"

#include <vector>

namespace Hunga {
    class GameObject {
        public:
            GameObject(_HungaEntity handle)
                : m_Handle(handle)
            {};

            template <typename T>
            void AddScript();

            template <typename T, typename... Args>
            void AddScript(Args&... args);

            template <typename T>
            bool HasScript();

            template <typename T>
            void DeleteScript();

            template <typename T>
            std::vector<T&> GetScript();

        private: 
            _HungaEntity m_Handle;
            Scene* m_scene;
    };
}

#endif