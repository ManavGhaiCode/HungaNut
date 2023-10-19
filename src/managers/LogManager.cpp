#include <log.h>
#include <managers/LogManager.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>

namespace Hunga::Managers {
    void LogManager::init() {
        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

        // sets the format to [Year-month-day hour:minute:secound.millesecound] Message
        consoleSink->set_pattern("%^[%Y-%m-%d] %H:%M:%S.%E] %v%$");

        std::vector<spdlog::sink_ptr> sinks { consoleSink };
        auto logger = std::make_shared<spdlog::logger> (HUNGANUT_DEFAULT_LOGGER_NAME,
        sinks.begin(), sinks.end() );

        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::trace);

        spdlog::register_logger(logger);
    }

    void LogManager::ShutDown() {
        spdlog::shutdown();
    }
}