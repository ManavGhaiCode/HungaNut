#include "ECS/ECS.h"

namespace Hunga {
    void ECS::AddObject(GameObject& gameObject) {
        uint32_t uuid = UUID::uuid_Gen();

        gameObject._uuid = uuid;
        m_Objects[uuid] = gameObject;
    }

    void ECS::DeleteObject(uint32_t uuid) {
        m_Objects.erase(uuid);
    }

    std::map<uint32_t, GameObject>& ECS::GetObjects() {
        return m_Objects;
    }

    GameObject& ECS::GetObject_uuid(uint32_t uuid) {
        return m_Objects[uuid];
    }
}