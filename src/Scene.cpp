#include "Scene.h"
#include "ECS/GameObject.h"

namespace Hunga {
    GameObject Scene::CreatObject() {
        GameObject gameObject = m_Registry.CreatObject();
        return gameObject;
    }
}