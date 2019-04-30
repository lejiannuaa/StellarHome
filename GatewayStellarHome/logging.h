#ifndef LOGGING
#define LOGGING

#define LOGGING_INFO_ON
#define LOGGING_DEBUG_ON
#define LOGGING_LOG_ON
#define LOGGING_WARN_ON
#define LOGGING_ERROR_ON

#define STREAM      stdout

#if defined(LOGGING_INFO_ON)
#define INFO(...)    \
    {\
    fprintf(STREAM, "DEBUG:   %s %s L#%d\n", __PRETTY_FUNCTION__, __FILE__, __LINE__);  \
    fprintf(STREAM, ##__VA_ARGS__); \
    fflush(STREAM); \
    }
#endif

#if defined(LOGGING_DEBUG_ON)
#define DEBUG(...)    \
    {\
    fprintf(STREAM, "DEBUG:   %s %s L#%d\n", __PRETTY_FUNCTION__, __FILE__, __LINE__);  \
    fprintf(STREAM, ##__VA_ARGS__); \
    fflush(STREAM); \
    }
#endif

#if defined(LOGGING_LOG_ON)
#define LOG(...)    \
    {\
    fprintf(STREAM, "LOG:   %s L#%d ", __PRETTY_FUNCTION__, __LINE__);  \
    fprintf(STREAM, ##__VA_ARGS__); \
    fflush(STREAM); \
    }
#endif

#if defined(LOGGING_WARN_ON)
#define WARN(...)   \
    { \
    fprintf(STREAM, "WARN:  %s L#%d ", __PRETTY_FUNCTION__, __LINE__);  \
    fprintf(STREAM, ##__VA_ARGS__); \
    fflush(STREAM); \
    }
#endif

#if defined(LOGGING_ERROR_ON)
#define ERROR(...)  \
    { \
    fprintf(STREAM, "ERROR: %s L#%d ", __PRETTY_FUNCTION__, __LINE__); \
    fprintf(STREAM, ##__VA_ARGS__); \
    fflush(STREAM); \
    exit(1); \
    }
#endif

#endif // LOGGING

