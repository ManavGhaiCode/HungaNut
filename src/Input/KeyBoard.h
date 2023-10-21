#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <array>

namespace Hunga::Input {
    class KeyBoard {
        public:
            void init();
            void Update();

            bool GetKey(int Key);
            bool GetKeyUp(int Key);
            bool GetKeyDown(int Key);

        private:
            static int const m_KeyCount = 286; // as of SDL_NUM_SCANCODES minus the unspcified Keys.

            std::array<bool, m_KeyCount> m_Keys;
            std::array<bool, m_KeyCount> m_KeysUp;
            std::array<bool, m_KeyCount> m_KeysDown;
    };
}

#endif