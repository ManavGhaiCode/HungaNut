#ifndef _UUID_H_
#define _UUID_H_

#include <cstdint>
#include <cstdlib>

namespace UUID {
    uint32_t last_UUID = 0;

    uint32_t uuid_Gen() {
        std::srand(last_UUID);
        last_UUID = std::rand();

        return last_UUID;
    }
}

#endif