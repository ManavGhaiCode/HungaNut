#ifndef _ENGINE_H_
#define _ENGINE_H_

namespace Hunga {
    class Engine {
        public:
            // for singletin
            static Engine& Instance();

            bool Init();
            void ShutDown();

        private:
            static Engine* m_Instance;
            // void GetInfo();
    };
}

#endif