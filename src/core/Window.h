#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <GLFW/glfw3.h>

namespace Hunga {
    class Window {
        public:
            Window() {};

            void Init();
            void ShutDown();

        private:
            GLFWwindow* m_window;
            
    };
}

#endif