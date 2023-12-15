#ifndef _REGISTORY_H_
#define _REGISTORY_H_

#include "Defines.h"
#include "ECS/Script.h"

#include <map>
#include <vector>

namespace Hunga {
    typedef std::map<_HungaEntity, std::vector<VariableScript>> _HungaRegistry;

    class Registry {
        public:
            Registry() = default;

            _HungaEntity CreatObject();
            void DeleteObject(_HungaEntity entity);

            template <typename T>
            void AddScript(_HungaEntity entity);

            template <typename T, typename... Args>
            void AddScript(_HungaEntity entity, Args&... args);

            template <typename T>
            void RemoveScript(_HungaEntity entity);

            template <typename T>
            T* GetSctipt(_HungaEntity entity);

            template <typename T>
            std::vector<_HungaEntity> View();
            std::vector<_HungaEntity> ViewAll();

            template <typename T>
            std::vector<_HungaEntity> ViewWithBase();

        private:

            uint16_t m_Entities = 0;
            _HungaRegistry m_Objects;
    };
}

#endif