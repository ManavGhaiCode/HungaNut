namespace Hunga::Managers {
    class LogManager {
        public:
            LogManager() = default;
            ~LogManager() = default;

            void init();
            void ShutDown();
    };
}