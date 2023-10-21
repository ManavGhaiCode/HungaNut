#include <iostream>

#include <log.h>
#include <Input/KeyBoard.h>

#include <algorithm>

#include <SDL2/SDL_keyboard.h>

namespace Hunga::Input {
    void KeyBoard::init() {
        std::fill(m_Keys.begin(), m_Keys.end(), false);
        std::fill(m_KeysDown.begin(), m_KeysDown.end(), false);
        std::fill(m_KeysUp.begin(), m_KeysUp.end(), false);
    }

    void KeyBoard::Update() {
        const Uint8* KeyBoardState = SDL_GetKeyboardState(nullptr);

        for (int i = 0; i < m_KeyCount; i++) {
            bool wasDown = m_Keys[i];

            m_Keys[i] = KeyBoardState[i];

            bool isDown = m_Keys[i];

            if (wasDown && !isDown) {
                m_KeysUp[i] = true;
            } else if (!wasDown && isDown) {
                m_KeysDown[i] = true;
            } else if (isDown) {
                m_Keys[i] = true;
            } else {
                m_Keys[i] = false;
            }
        }
    }

    bool KeyBoard::GetKey(int Key) {
        if (!(Key >= 0 && Key < m_KeyCount)) {
            NUT_ERROR("Key Index too large:\n\tprovided: {}\n\tmax: 0 to {}", std::to_string(Key), m_KeyCount);
            return false;
        }

        return m_Keys[Key];
    }

    bool KeyBoard::GetKeyUp(int Key) {
        if (!(Key >= 0 && Key < m_KeyCount)) {
            NUT_ERROR("Key Index too large:\n\tprovided: {}\n\tmax: 0 to {}", std::to_string(Key), m_KeyCount);
            return false;
        }

        return m_KeysUp[Key];
    }

    bool KeyBoard::GetKeyDown(int Key) {
        if (!(Key >= 0 && Key < m_KeyCount)) {
            NUT_ERROR("Key Index too large:\n\tprovided: {}\n\tmax: 0 to {}", std::to_string(Key), m_KeyCount);
            return false;
        }

        return m_KeysDown[Key];
    }
}