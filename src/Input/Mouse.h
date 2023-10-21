#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <array>

namespace Hunga::Input {
    class Mouse {
        public:
            static void init();

            static void Update();
            inline static int GetX() { return m_xpos; };

            static bool GetButton(int Button);
            static bool GetButtonUp(int Button);
            static bool GetButtonDown(int Button);

        private:
            const static int m_ButtonCount = 5; // as SDL supports 5 mouse buttons.

            static int m_xpos;
            static int m_ypos;
            static int m_xLast;
            static int m_yLast;

            static std::array<bool, m_ButtonCount> m_Buttons;
            static std::array<bool, m_ButtonCount> m_ButtonsUp;
            static std::array<bool, m_ButtonCount> m_ButtonsDown;
    };
}

#endif