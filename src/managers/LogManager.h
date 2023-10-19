#ifndef _LOGMANAGER_H_
#define _LOGMANAGER_H_

namespace Hunga::Managers {
    class LogManager {
        public:
            LogManager() = default;
            ~LogManager() = default;

            void init();
            void ShutDown();
    };
}

#endif