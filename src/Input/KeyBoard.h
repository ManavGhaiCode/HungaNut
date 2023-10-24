#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <array>

namespace Hunga::Input {
    struct KeyBoard {
        std::array<bool, 156> State;
        std::array<bool, 156> LastState;
    };
}

#endif