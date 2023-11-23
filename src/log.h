#ifndef _LOG_H_
#define _LOG_H_

#include "Logging/NutLogger.h"
#include "Defines.h"

#ifdef DEBUG
    #define NUT_TRACE(...) Nut::LogTrace(__VA_ARGS__)
    #define NUT_DEBUG(...) Nut::LogDebug(__VA_ARGS__)
    #define NUT_INFO(...) Nut::LogInfo(__VA_ARGS__)
    #define NUT_WARN(...) Nut::LogWarn(__VA_ARGS__)
    #define NUT_ERROR(...) Nut::LogError(__VA_ARGS__)
    #define NUT_FATAL(...) Nut::LogFatal(__VA_ARGS__)
    #define NUT_ASSERT(x, msg) if ((x)) {} else { NUT_FATAL("ASSERT - {}\n\t{}\n\tin file: {}\n\ton line: {}", #x, msg, __FILE__, __LINE__); NUT_BREAK }
#elif
    #define NUT_TRACE(...) void(0)
    #define NUT_DEBUG(...) void(0)
    #define NUT_INFO(...) void(0)
    #define NUT_WARN(...) void(0)
    #define NUT_ERROR(...) void(0)
    #define NUT_FATAL(...) void(0)
    #define NUT_ASSERT(x, msg) void(0)
#endif

#endif