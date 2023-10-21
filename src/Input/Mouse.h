#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <array>

namespace Hunga::Input {
    class Mouse {
        public:
            void init();
            void Update();

            inline int GetX() { return m_xpos; };
            inline int GetY() { return m_ypos; };

            bool GetButton(int Button);
            bool GetButtonUp(int Button);
            bool GetButtonDown(int Button);

        private:
            static int const m_ButtonCount = 5; // as SDL supports 5 mouse buttons.

            int m_xpos;
            int m_ypos;
            int m_xLast;
            int m_yLast;

            std::array<bool, m_ButtonCount> m_Buttons;
            std::array<bool, m_ButtonCount> m_ButtonsUp;
            std::array<bool, m_ButtonCount> m_ButtonsDown;
    };
}

#endif