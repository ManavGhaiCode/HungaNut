#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include "Input/KeyBoard.h"
#include "Input/Mouse.h"

namespace Hunga {
    class InputManager {
        public:
            void Update();

            bool GetKey(int key);
            bool GetKeyUp(int key);
            bool GetKeyDown(int key);
            bool GetButtonDown(int button);
            bool GetButtonUp(int button);
            bool GetButton(int button);

        private:
            KeyBoard m_KeyBoard;
            Mouse m_Mouse;
    };
}

#endif