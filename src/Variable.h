#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <string>

namespace Hunga {
    struct Variable {
        std::string name;
        void* data;

        template <typename T>
        Variable(std::string Name, T Data) {
            name = Name;
            ( (T*) data ) = Data;
        }
    };
}

#endif