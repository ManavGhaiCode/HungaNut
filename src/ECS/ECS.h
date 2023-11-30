#ifndef _ECS_H_
#define _ECS_H_

#include <entt/entt.hpp>

namespace Hunga {
    class ECS {
        public:
            void AddObject();
            void DeleteObject();

            void GetObject_uuid();
            // void SetObejct_uu

        private:
            entt::entity;
            entt::registry m_Registry;
    };
}

#endif