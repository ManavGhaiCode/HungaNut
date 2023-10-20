#ifndef _LOG_H_
#define _LOG_H_

#include <spdlog/spdlog.h>
#include <Defines.h>

// defines for DEGUB Build of the Game
#ifdef DEBUG
    #define NUT_TRACE(...) if (spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME)->trace(__VA_ARGS__); }
    #define NUT_DEBUG(...) if (spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME)->debug(__VA_ARGS__); }
    #define NUT_INFO(...)  if (spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME)->info(__VA_ARGS__); }
    #define NUT_WARN(...)  if (spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME)->warn(__VA_ARGS__); }
    #define NUT_ERROR(...) if (spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME)->error(__VA_ARGS__); }
    #define NUT_FATAL(...) if (spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME)->critical(__VA_ARGS__); }
    #define NUT_ASSERT(x, msg) if ((x)) {} else { NUT_FATAL("ASSERT - {}\n\t{}\n\tin file: {}\n\ton line: {}", #x, msg, __FILE__, __LINE__); NUT_BREAK }
#else
// defines for RELEASE Build of the Game
    #define NUT_TRACE(...) (void)0
    #define NUT_DEBUG(...) (void)0
    #define NUT_INFO(...)  (void)0
    #define NUT_WARN(...)  (void)0
    #define NUT_ERROR(...) (void)0
    #define NUT_FATAL(...) (void)0
    #define NUT_ASSERT(x, msg) (void)0
#endif

#endif