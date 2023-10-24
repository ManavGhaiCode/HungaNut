#ifndef _MOSUE_H_
#define _MOSUE_H_

#include <array>

namespace Hunga::Input {
    struct Mouse {
        std::array<bool, 156> State;
        std::array<bool, 156> LastState;

        int x;
        int y;
    };
}

#endif