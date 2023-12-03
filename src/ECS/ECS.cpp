#include "ECS/ECS.h"
#include "uuid.h"

namespace Hunga {
    void ECS::AddObject(GameObject& gameObject) {
        uint32_t uuid = UUID::uuid_Gen();
        gameObject._uuid = uuid;

        m_Objects[uuid] = gameObject;
    }

    void ECS::AddObject_withUuid(GameObject& gameObject, uint32_t uuid) {
        m_Objects[uuid] = gameObject;
    }

    void ECS::DeleteObject(uint32_t uuid) {
        m_Objects[uuid].ShutDown();
        m_Objects.erase(uuid);
    }

    void ECS::SetObjectUuid(uint32_t uuid, uint32_t new_uuid) {
        m_Objects[new_uuid] = m_Objects[uuid];
        m_Objects.erase(uuid);
    }

    void ECS::Awake() {
        for (auto gameObject : m_Objects) {
            gameObject.second.Awake();
        }
    }

    void ECS::Start() {
        for (auto gameObject : m_Objects) {
            gameObject.second.Start();
        }
    }

    void ECS::Update() {
        for (auto gameObject : m_Objects) {
            gameObject.second.Update();
        }
    }

    void ECS::LateUpdate() {
        for (auto gameObject : m_Objects) {
            gameObject.second.LateUpdate();
        }
    }

    void ECS::FixedUpdate() {
        for (auto gameObject : m_Objects) {
            gameObject.second.FixedUpdate();
        }
    }

    void ECS::Serialize() {
        for (auto gameObject : m_Objects) {
            gameObject.second.Serialize();
        }
    }
}