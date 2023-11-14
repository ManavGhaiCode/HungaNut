#ifndef _INPUT_H_
#define _INPUT_H_

#include "Engine.h"

namespace Hunga {
    bool GetKey(int Key) {
        return Engine::Instance().GetInputManager().GetKey(Key);
    }

    bool GetKeyUp(int Key) {
        return Engine::Instance().GetInputManager().GetKeyUp(Key);
    }

    bool GetKeyDown(int Key) {
        return Engine::Instance().GetInputManager().GetKeyDown(Key);
    }

    bool GetButtonDown(int Button) {
        return Engine::Instance().GetInputManager().GetButton(Button);
    }

    bool GetButtonUp(int Button) {
        return Engine::Instance().GetInputManager().GetButtonUp(Button);
    }

    bool GetButton(int Button) {
        return Engine::Instance().GetInputManager().GetButtonDown(Button);
    }
}

#endif