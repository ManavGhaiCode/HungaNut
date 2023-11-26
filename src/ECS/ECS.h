#ifndef _ECS_H_
#define _ECS_H_

#include "ECS/GameObject.h"

#include <map>
#include <cstdint>

namespace Hunga {
    class ECS {
        private:
            std::map<uint32_t, GameObject> m_Objects;
    };
}

#endif