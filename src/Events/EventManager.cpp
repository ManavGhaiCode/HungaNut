#include "Events/EventManager.h"
#include <string>

namespace Hunga {
    void EventManager::Brodcast(std::string EventName) {
        for (Event event : m_Events) {
            if (event.name == EventName) {
                for (std::function<void(Hunga::Event&)> function : event.subscribes) {
                    function(event);
                }
            }
        }
    }

    void EventManager::Subscribe(std::string EventName, std::function<void(Hunga::Event&)> function) {
        for (Event event : m_Events) {
            if (event.name == EventName) {
                event.subscribes.push_back(function);
            }
        }
    }

    void EventManager::addEvent(Event event) {
        m_Events.push_back(event);
    }
}