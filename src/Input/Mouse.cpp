#include <log.h>
#include <Input/Mouse.h>

#include <algorithm>
#include <SDL2/SDL_mouse.h>

namespace Hunga::Input {
    int Mouse::m_xpos = 0;
    int Mouse::m_ypos = 0;
    int Mouse::m_xLast = 0;
    int Mouse::m_yLast = 0;

    std::array<bool, Mouse::m_ButtonCount> Mouse::m_Buttons;
    std::array<bool, Mouse::m_ButtonCount> Mouse::m_ButtonsDown;
    std::array<bool, Mouse::m_ButtonCount> Mouse::m_ButtonsUp;

    void Mouse::init() {
        std::fill(m_Buttons.begin(), m_Buttons.end(), false);
    }

    void Mouse::Update() {
        // clear frame events
        std::fill(m_ButtonsDown.begin(), m_ButtonsDown.end(), false);
        std::fill(m_ButtonsUp.begin(), m_ButtonsUp.end(), false);

        Uint32 MouseState = SDL_GetMouseState(&m_xpos, &m_ypos);
        for (int i = 0; i < m_ButtonCount; i++) {
            bool wasDown = m_Buttons[i];

            // fancy stuff to see if the button is still down using SDL2
            m_Buttons[i] = MouseState & SDL_BUTTON(i + 1);

            bool isDown = m_Buttons[i];

            if (wasDown && !isDown) {
                m_ButtonsUp[i] = true;
            } else if (!wasDown && isDown) {
                m_ButtonsDown[i] = true;
            } else if (isDown) {
                m_Buttons[i] = true;
            } else {
                m_Buttons[i] = false;
            }
        }
    }

    bool Mouse::GetButton(int Button) {
        if (!(Button >= 0 && Button < 5)) {
            NUT_ERROR("Button Index too large:\n\tprovided: {}\n\tmax: 0 to 4", std::to_string(Button));
            return false;
        }

        return m_Buttons[Button];
    }

    bool Mouse::GetButtonUp(int Button) {
        if (!(Button >= 0 && Button < 5)) {
            NUT_ERROR("Button Index too large:\n\tprovided: {}\n\tmax: 0 to 4", std::to_string(Button));
            return false;
        }

        return m_ButtonsUp[Button];
    }

    bool Mouse::GetButtonDown(int Button) {
        if (!(Button >= 0 && Button < 5)) {
            NUT_ERROR("Button Index too large:\n\tprovided: {}\n\tmax: 0 to 4", std::to_string(Button));
            return false;
        }

        return m_ButtonsDown[Button];
    }
}