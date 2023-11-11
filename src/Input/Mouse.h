#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <array>

namespace Hunga {
    struct Mouse {
        int x;
        int y;

        std::array<bool, 5> state;
        std::array<bool, 5> prevState;
    };
}

#endif