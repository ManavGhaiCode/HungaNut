#include "ECS/ECS.h"
#include "log.h"

namespace Hunga {
    void ECS::ShutDown() {
        for (auto script : m_Objects) {
            script.second.ShutDown();
        }
    }

    void ECS::AddObject(GameObject& gameObject) {
        uint32_t uuid = rand();
        gameObject._uuid = uuid;

        m_Objects[uuid] = gameObject;
    }

    void ECS::AddObject_withUuid(GameObject& gameObject, uint32_t uuid) {
        m_Objects[uuid] = gameObject;
    }

    void ECS::DeleteObject(uint32_t uuid) {
        if (m_Objects.count(uuid) == 0) {
            NUT_ERROR("Unable to find gameObject with uuid {}", uuid);
            return; 
        }

        m_Objects[uuid].ShutDown();
        m_Objects.erase(uuid);
    }

    GameObject& ECS::GetObject_uuid(uint32_t uuid) {
        if (m_Objects.count(uuid) == 0) {
            NUT_ERROR("Unable to find gameObject with uuid {}", uuid);

            return emptyObject;
        }

        return m_Objects[uuid];
    }

    void ECS::SetObjectUuid(uint32_t uuid, uint32_t new_uuid) {
        if (m_Objects.count(uuid) == 0) {
            NUT_ERROR("Unable to find gameObject with uuid {}", uuid);
            return; 
        }

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

    GameObject ECS::emptyObject = GameObject ();
}