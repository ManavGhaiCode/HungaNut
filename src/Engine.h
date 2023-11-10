#ifndef _ENGINE_H_
#define _ENGINE_H_

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance();

            void Run();
            void Quit();

        private:
            bool Init();
            void ShutDown() { m_Instance = nullptr; };

            // vars
            bool m_running = false;


            // singletin stuff
            static Engine* m_Instance;
            Engine() {};
    };
};

#endif