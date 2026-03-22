#pragma once

#include "compiler.h"

#ifdef __cplusplus
#include <QtLogging>
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*QtLoggingMessageHandler)(void *context,
                                        int type,
                                        CQString message,
                                        const char *category,
                                        const char *file,
                                        const char *function,
                                        int line);

LIBRARY_API void QtLogging_setMessagePattern(const char *pattern);

LIBRARY_API CQString QtLogging_formatLogMessage(int type,
                                                const char *message,
                                                const char *category,
                                                const char *file,
                                                const char *function,
                                                int line);

#ifdef __cplusplus
LIBRARY_API QtMessageHandler QtLogging_installMessageHandler(void *context,
                                                             QtLoggingMessageHandler handler);
#else
LIBRARY_API void *QtLogging_installMessageHandler(void *context,
                                                  QtLoggingMessageHandler handler);
#endif

LIBRARY_API void QtLogging_debug(const char *message);
LIBRARY_API void QtLogging_info(const char *message);
LIBRARY_API void QtLogging_warning(const char *message);
LIBRARY_API void QtLogging_critical(const char *message);
LIBRARY_API void QtLogging_fatal(const char *message);

#ifdef __cplusplus
}
#endif