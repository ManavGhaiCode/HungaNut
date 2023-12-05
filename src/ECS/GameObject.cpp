#include "ECS/GameObject.h"
#include "log.h"

#include <stdlib.h>

namespace Hunga {
    void GameObject::ShutDown() {
        for (auto script : m_Scripts) {
            script.second->OnDestroy();

            delete m_Scripts[script.second->_uuid];
            m_Scripts.erase(script.second->_uuid);
        }
    }

    void GameObject::AddScript(Script& script) {
        uint32_t uuid = rand();
        script._uuid = uuid;

        script.gameObject = this;

        m_Scripts[uuid] = &script;
    }

    void GameObject::DeleteScript(uint32_t uuid) {
        if (m_Scripts.count(uuid) == 0) {
            return;
            NUT_ERROR("Unable to find script with uuid: {}", uuid);
        }

        delete m_Scripts[uuid];
        m_Scripts.erase(uuid);
    }

    void GameObject::Awake() {
        for (auto script : m_Scripts) {
            script.second->Awake();
        }
    }

    void GameObject::Start() {
        for (auto script : m_Scripts) {
            script.second->Start();
        }
    }

    void GameObject::Serialize() {
        for (auto script : m_Scripts) {
            script.second->SerializeFeilds();
        }
    }

    void GameObject::Update() {
        for (auto script : m_Scripts) {
            script.second->Update();
        }
    }

    void GameObject::LateUpdate() {
        for (auto script : m_Scripts) {
            script.second->LateUpdate();
        }
    }

    void GameObject::FixedUpdate() {
        for (auto script : m_Scripts) {
            script.second->FixedUpdate();
        }
    }
}