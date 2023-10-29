#ifndef _LOG_H_
#define _LOG_H_

#include <Defines.h>
#include <NutLogger/NutLogger.h>

#ifdef DEBUG
    #define NUT_TRACE(...) NutLogger::LogTrace(__VA_ARGS__);
    #define NUT_DEBUG(...) NutLogger::LogDebug(__VA_ARGS__);
    #define NUT_INFO(...)  NutLogger::LogInfo(__VA_ARGS__);
    #define NUT_WARN(...)  NutLogger::LogWarn(__VA_ARGS__);
    #define NUT_ERROR(...) NutLogger::LogError(__VA_ARGS__);
    #define NUT_FATAL(...) NutLogger::LogFatal(__VA_ARGS__);
#elif
    #define NUT_TRACE(...) (void*)0
    #define NUT_DEBUG(...) (void*)0
    #define NUT_INFO(...)  (void*)0
    #define NUT_WARN(...)  (void*)0
    #define NUT_ERROR(...) (void*)0
    #define NUT_FATAL(...) (void*)0
#endif

#endif