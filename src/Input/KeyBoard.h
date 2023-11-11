#ifndef _KEYBORAD_H_
#define _KEYBORAD_H_

#include <array>

namespace Hunga {
    struct KeyBoard {
        std::array<bool, 286> state;
        std::array<bool, 286> prevState;
    };
    
}

#endif