#ifndef _LOG_H_
#define _LOG_H_

#include <Defines.h>

#include <NutLogger/NutLogger.h>

#ifdef DEBUG
    #define NUT_TRACE (msg) NutLogger::LogTrace (msg)
    #define NUT_DEBUG (msg) NutLogger::LogDebug (msg)
    #define NUT_INFO  (msg) NutLogger::LogInfo  (msg)
    #define NUT_WARN  (msg) NutLogger::LogWarn  (msg)
    #define NUT_ERROR (msg) NutLogger::LogError (msg)
    #define NUT_FATAL (msg) NutLogger::LogFatal (msg)
#elif
    #define NUT_TRACE (msg) (void*)0
    #define NUT_DEBUG (msg) (void*)0
    #define NUT_INFO  (msg) (void*)0
    #define NUT_WARN  (msg) (void*)0
    #define NUT_ERROR (msg) (void*)0
    #define NUT_FATAL (msg) (void*)0
#endif

#endif