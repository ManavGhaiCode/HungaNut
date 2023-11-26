#include "ECS/ECS.h"

namespace Hunga {
    void ECS::AddObject(GameObject& gameObject) {
        uint32_t uuid = UUID::uuid_Gen();

        gameObject._uuid = uuid;
        m_Objects[uuid] = gameObject;
    }
}