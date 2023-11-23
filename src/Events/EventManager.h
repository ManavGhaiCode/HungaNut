#ifndef _EVENTMANAGER_H_
#define _EVENTMANAGER_H_

#include "Events/Event.h"
#include <map>

namespace Hunga {
    class EventManager {
        public:
            void Subscribe(const std::string& EventName, std::function<void(Hunga::Event&)> function);
            void Brodcast(const std::string& name);
            void addEvent(const Event& event);

        private:
            std::map<std::string, Event> m_Events;
    };
}

#endif