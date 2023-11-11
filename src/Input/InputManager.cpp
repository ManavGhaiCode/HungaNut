#include "Input/InputManager.h"

#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_mouse.h>

namespace Hunga {
    void InputManager::Update() {
        Uint32 MouseState = SDL_GetMouseState(&m_Mouse.x, &m_Mouse.y);
        m_Mouse.prevState = m_Mouse.state;

        for (int i = 0; i < m_Mouse.state.size(); i++) {
            m_Mouse.state[i] = MouseState & SDL_BUTTON(i);
        }

        const Uint8* KeyBoardState = SDL_GetKeyboardState(nullptr);
        m_KeyBoard.prevState = m_KeyBoard.state;

        for (int i = 0; i < m_KeyBoard.state.size(); i++) {
            m_KeyBoard.state[i] = KeyBoardState[i];
        }
    }

    bool InputManager::GetKey(int key) {
        return m_KeyBoard.state[key];
    }

    bool InputManager::GetKeyUp(int key) {
        if (!m_KeyBoard.state[key] && m_KeyBoard.prevState[key]) {
            return true;
        }

        return false;
    }

    bool InputManager::GetKeyDown(int key) {
        if (m_KeyBoard.state[key] && !m_KeyBoard.prevState[key]) {
            return true;
        }

        return false;
    }

    bool InputManager::GetButton(int button) {
        return m_Mouse.state[button];
    }

    bool InputManager::GetButtonUp(int button) {
        if (!m_Mouse.state[button] && m_Mouse.prevState[button]) {
            return true;
        }

        return false;
    }

    bool InputManager::GetButtonDown(int button) {
        if (m_Mouse.state[button] && !m_Mouse.prevState[button]) {
            return true;
        }

        return false;
    }
}