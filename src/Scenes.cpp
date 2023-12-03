#include "Scenes.h"

namespace Hunga {
    void Scene::ShutDown() {
        m_ECS.ShutDown();
    }
}