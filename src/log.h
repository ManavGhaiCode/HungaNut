#ifndef _LOG_H_
#define _LOG_H_

#include <spdlog/spdlog.h>
#include <Defines.h>

#ifdef DEBUG
    #define NUT_TRACE(...) if (spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(HUNGANUT_DEFAULT_LOGGER_NAME)->trace(__VA_ARGS__); }
#else
    #define NUT_TRACE(...) void(0)
#endif

#endif