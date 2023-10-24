#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <core/Window.h>

namespace Hunga {
    class Engine {
        public:
            // for singletin
            static Engine& Instance();

            bool Init();
            void ShutDown();

        private:
            // void GetInfo();

            // Window
            Window m_window;

            // other vars
            static Engine* m_Instance;
    };
}

#endif