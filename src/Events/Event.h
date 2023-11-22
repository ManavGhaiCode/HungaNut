#ifndef _Event_H_
#define _Event_H_

#include <string>
#include <vector>
#include <functional>

namespace Hunga {
    struct Event {
        std::string name;
        std::vector<std::function<void( Hunga::Event& )>> subscribes;
    };
}

#endif