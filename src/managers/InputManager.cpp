#include <managers/InputManager.h>

namespace Hunga::Managers {
    void InputManager::Update() {
        m_keyBoard.Update();
        m_mouse.Update();
    }

    bool InputManager::GetButtonDown(MouseKeys Button) {
        return m_mouse.GetButton(Button);
    };

    bool InputManager::GetButtonUp(MouseKeys Button) {
        return m_mouse.GetButtonUp(Button);
    };

    bool InputManager::GetButton(MouseKeys Button) {
        return m_mouse.GetButtonDown(Button);
    };

    bool InputManager::GetKey(Keys Key) {
        return m_keyBoard.GetKey(Key);
    };

    bool InputManager::GetKeyUp(Keys Key) {
        return m_keyBoard.GetKeyUp(Key);
    };

    bool InputManager::GetKeyDown(Keys Key) {
        return m_keyBoard.GetKeyDown(Key);
    };

    void InputManager::init() {
        m_mouse.init();
        m_keyBoard.init();
    }
}