#ifndef _EVENTMANAGER_H_
#define _EVENTMANAGER_H_

#include "Events/Event.h"
#include <map>

namespace Hunga {
    class EventManager {
        public:
            void Subscribe(std::string EventName, std::function<void(Hunga::Event&)> function);
            void Brodcast(std::string name);
            void addEvent(Event event);

        private:
            std::map<std::string, Event> m_Events;
    };
}

#endif