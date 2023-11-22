#ifndef _EVENT_H_
#define _EVENT_H_

#include "Engine.h"
#include "Events/EventManager.h"

namespace Hunga {
    EventManager& eventManager = Engine::Instance().GetEventManager();

    void SubcribeEvent(std::string EventName, std::function<void( Event& )> function) {
        eventManager.Subscribe(EventName, function);
    }

    void EventBoadcast(std::string EventName) {
        eventManager.Brodcast(EventName);
    }

    void AddEvent(std::string EventName) {
        Event event;
        event.name = EventName;

        eventManager.addEvent(event);
    }
}

#endif