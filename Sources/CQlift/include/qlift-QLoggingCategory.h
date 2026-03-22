#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

LIBRARY_API void *QLoggingCategory_new(const char *category, int enableForLevel);
LIBRARY_API void QLoggingCategory_delete(void *loggingCategory);

LIBRARY_API CQString QLoggingCategory_categoryName(void *loggingCategory);
LIBRARY_API bool QLoggingCategory_isCriticalEnabled(void *loggingCategory);
LIBRARY_API bool QLoggingCategory_isDebugEnabled(void *loggingCategory);
LIBRARY_API bool QLoggingCategory_isEnabled(void *loggingCategory, int msgType);
LIBRARY_API bool QLoggingCategory_isInfoEnabled(void *loggingCategory);
LIBRARY_API bool QLoggingCategory_isWarningEnabled(void *loggingCategory);
LIBRARY_API void QLoggingCategory_setEnabled(void *loggingCategory, int msgType, bool enable);

LIBRARY_API void *QLoggingCategory_defaultCategory(void);
LIBRARY_API void QLoggingCategory_setFilterRules(const char *rules);

LIBRARY_API void QLoggingCategory_cDebug(void *loggingCategory, const char *message);
LIBRARY_API void QLoggingCategory_cInfo(void *loggingCategory, const char *message);
LIBRARY_API void QLoggingCategory_cWarning(void *loggingCategory, const char *message);
LIBRARY_API void QLoggingCategory_cCritical(void *loggingCategory, const char *message);

#ifdef __cplusplus
}
#endif