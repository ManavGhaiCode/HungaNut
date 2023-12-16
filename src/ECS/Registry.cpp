#include "Registry.h"
#include "log.h"

#include <type_traits>

namespace Hunga {
    _HungaEntity Registry::CreatObject() {
        NUT_ASSERT(m_Entities < MAX_ENTITIES, "Trying to make more than MAX_ENTITIES");

        m_Entities += 1;
        m_Objects[m_Entities] = std::vector<VariableScript> ();

        return m_Entities;
    }

    void Registry::DeleteObject(_HungaEntity entity) {
        m_Objects.erase(entity);
    }

    template <typename T>
    void Registry::AddScript(_HungaEntity entity) {
        m_Objects[entity].push_back({ T () });
    }

    template <typename T, typename... Args>
    void Registry::AddScript(_HungaEntity entity, Args&... args) {
        m_Objects[entity].push_back({ T ( args... ) });
    }

    template <typename T>
    void Registry::RemoveScript(_HungaEntity entity) {
        std::vector<VariableScript>& scripts = m_Objects[entity];

        for (int i = 0; i > m_Objects[entity].size(); i++) {
            if (scripts[i].TypeName == NUT_TYPEOF(T)) {
                scripts.erase(scripts.begin() + i);
            }
        }
    }

    template <typename T>
    std::vector<_HungaEntity> Registry::View() {
        std::vector<_HungaEntity> ret;

        for (auto& [key, script] : m_Objects) {
            if (script.Typename == NUT_TYPEOF(T)) {
                ret.push_back(key);
            }
        }

        return ret;
    }

    std::vector<_HungaEntity> Registry::ViewAll() {
        std::vector<_HungaEntity> ret;

        for (auto& [key, script] : m_Objects) {
            ret.push_back(key);
        }

        return ret;
    }

    template <typename T>
    std::vector<_HungaEntity> Registry::ViewWithBase() {
        std::vector<_HungaEntity> ret;

        for (auto& [key, script] : m_Objects) {
            if (dynamic_cast<T>(script.data())) {
                ret.push_back(key);
            }
        }

        return ret;
    }

    template <typename T>
    T& Registry::GetSctipt(_HungaEntity entity) {
        for (VariableScript& script : m_Objects[entity]) {
            if (script.TypeName == NUT_TYPEOF(T)) {
                return script;
            } else if (dynamic_cast<T>(script.script)) {
                return script;
            }
        }
    }

    template <typename T>
    std::vector<T&> Registry::GetSctipts(_HungaEntity entity) {
        std::vector<T&> ret;

        for (VariableScript& script : m_Objects[entity]) {
            if (script.TypeName == NUT_TYPEOF(T)) {
                ret.push_back(&script);
            } else if (dynamic_cast<T>(script.script)) {
                ret.push_back(&script);
            }
        }

        return ret;
    }

    template <typename T>
    bool Registry::HasScript(_HungaEntity entity) {
        for (VariableScript& script : m_Objects[entity]) {
            if (script.TypeName == NUT_TYPEOF(T)) {
                return true;
            } else if (dynamic_cast<T>(script.script)) {
                return true;
            }
        }

        return false;
    }
}