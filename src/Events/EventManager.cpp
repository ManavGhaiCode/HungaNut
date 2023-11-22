#include "Events/EventManager.h"
#include "log.h"

#include <string>

namespace Hunga {
    void EventManager::Brodcast(std::string EventName) {
        Event& event = m_Events[EventName];

        if ( &event == nullptr ) {
            NUT_ERROR("EventName: {} not found", EventName);
            return;
        }

        for (std::function<void(Event&)> function : event.subscribes) {
            function(event);
        }
    }

    void EventManager::Subscribe(std::string EventName, std::function<void(Hunga::Event&)> function) {
        Event& event = m_Events[EventName];

        if ( &event == nullptr ) {
            NUT_ERROR("EventName: {} not found", EventName);
            return;
        }

        event.subscribes.push_back(function);
    }

    void EventManager::addEvent(Event event) {
        m_Events[event.name] = event;
    }
}