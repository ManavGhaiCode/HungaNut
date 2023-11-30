#include "ECS/GameObject.h"

namespace Hunga {
    void GameObject::AddScript(Script& script) {
        uint32_t uuid = UUID::uuid_Gen();

        script._uuid = uuid;
        m_Scripts[uuid] = &script;
    }

    void GameObject::Awake() {
        for (auto const& script : m_Scripts) {
            script.second->Awake();
        }
    }

    void GameObject::Start() {
        for (auto const& script : m_Scripts) {
            script.second->Start();
        }
    }

    void GameObject::Update() {
        for (auto const& script : m_Scripts) {
            script.second->Update();
        }
    }

    void GameObject::LateUpdate() {
        for (auto const& script : m_Scripts) {
            script.second->LateUpdate();
        }
    }

    void GameObject::FixedUpdate() {
        for (auto const& script : m_Scripts) {
            script.second->FixedUpdate();
        }
    }

    void GameObject::Serialze() {
        for (auto const& script : m_Scripts) {
            script.second->SerializeFeilds();
        }
    }

    GameObject::~GameObject() {
        for (auto const& script : m_Scripts) {
            delete script.second;
        }
    }
}