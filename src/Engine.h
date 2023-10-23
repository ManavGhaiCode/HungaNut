#ifndef _ENGINE_H_
#define _ENGINE_H_

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance(); // for singletin stuff
            void Run(); // for running the game

            void ShutDown(); // for turning off the game
        private:

            void Init(); // Init function

            // void GetInfo(); // for Debug

            // for singletin stuff
            Engine() {};
            static Engine* m_Instance;
    };
}

#endif