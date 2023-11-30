#include "ECS/ECS.h"
#include "log.h"

namespace Hunga {
    void ECS::AddObject(GameObject& gameObject) {
        uint32_t uuid = UUID::uuid_Gen();

        gameObject._uuid = uuid;
        m_Objects[uuid] = gameObject;
    }

    void ECS::DeleteObject(uint32_t uuid) {
        if (m_Objects.count(uuid) == 0) {
            NUT_ERROR("unable to find GameObject with uuid: {}", uuid);
        }

        m_Objects.erase(uuid);
    }

    std::map<uint32_t, GameObject>& ECS::GetObjects() {
        return m_Objects;
    }

    GameObject& ECS::GetObject_uuid(uint32_t uuid) {
        if (m_Objects.count(uuid) == 0) {
            NUT_ERROR("unable to find GameObject with uuid: {}", uuid);
            return;
        }

        return m_Objects[uuid];
    }
}