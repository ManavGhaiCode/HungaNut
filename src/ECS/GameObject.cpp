#include "ECS/GameObject.h"
#include "log.h"

#include <string>

namespace Hunga {
    template <typename T>
    bool GameObject::HasScript() {
        return m_scene->m_Registry.HasScript<T>(m_Handle);
    };

    template <typename T>
    void GameObject::AddScript() {
        m_scene->m_Registry.AddScript<T>(m_Handle);
    }

    template <typename T, typename... Args>
    void GameObject::AddScript(Args&... args) {
        m_scene->m_Registry.AddScript<T>(m_Handle, std::forward<Args>(args)...);
    }

    template <typename T>
    void GameObject::DeleteScript() {
        bool ScriptPresent = HasScript<T>();

        NUT_ASSERT(ScriptPresent, "Script Type not present in GameObject");
        m_scene->m_Registry.RemoveScript<T>(m_Handle);
    }

    template <typename T>
    std::vector<T&> GameObject::GetScript() {
        return m_scene->m_Registry.GetSctipt<T>(m_Handle);
    }
}