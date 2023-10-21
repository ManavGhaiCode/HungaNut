#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include <Input/InputKeys.h>
#include <Input/KeyBoard.h>
#include <Input/Mouse.h>

namespace Hunga {
    class Engine;
}

namespace Hunga::Managers {
    class InputManager {
        public:
            void Update();

            bool GetButtonDown(MouseKeys Button);
            bool GetButtonUp(MouseKeys Button);
            bool GetButton(MouseKeys Button);

            bool GetKey(Keys Key);
            bool GetKeyUp(Keys Key);
            bool GetKeyDown(Keys Key);

        private:
            void init();

            Input::Mouse m_mouse;
            Input::KeyBoard m_keyBoard;

        friend class Hunga::Engine;
    };
}

#endif