#include <QLoggingCategory>

#include "qlift-QLoggingCategory.h"

[[maybe_unused]] void *QLoggingCategory_new(const char *category, int enableForLevel) {
    return new QLoggingCategory(category,
                                static_cast<QtMsgType>(enableForLevel));
}

[[maybe_unused]] void QLoggingCategory_delete(void *loggingCategory) {
    delete static_cast<QLoggingCategory *>(loggingCategory);
}

[[maybe_unused]] CQString QLoggingCategory_categoryName(void *loggingCategory) {
    thread_local QString name;
    const auto *category = static_cast<QLoggingCategory *>(loggingCategory);
    name = QString::fromUtf8(category->categoryName());
    return CQString{name.utf16(), name.size()};
}

[[maybe_unused]] bool QLoggingCategory_isCriticalEnabled(void *loggingCategory) {
    return static_cast<QLoggingCategory *>(loggingCategory)->isCriticalEnabled();
}

[[maybe_unused]] bool QLoggingCategory_isDebugEnabled(void *loggingCategory) {
    return static_cast<QLoggingCategory *>(loggingCategory)->isDebugEnabled();
}

[[maybe_unused]] bool QLoggingCategory_isEnabled(void *loggingCategory, int msgType) {
    return static_cast<QLoggingCategory *>(loggingCategory)
        ->isEnabled(static_cast<QtMsgType>(msgType));
}

[[maybe_unused]] bool QLoggingCategory_isInfoEnabled(void *loggingCategory) {
    return static_cast<QLoggingCategory *>(loggingCategory)->isInfoEnabled();
}

[[maybe_unused]] bool QLoggingCategory_isWarningEnabled(void *loggingCategory) {
    return static_cast<QLoggingCategory *>(loggingCategory)->isWarningEnabled();
}

[[maybe_unused]] void QLoggingCategory_setEnabled(void *loggingCategory,
                                                  int msgType,
                                                  bool enable) {
    static_cast<QLoggingCategory *>(loggingCategory)
        ->setEnabled(static_cast<QtMsgType>(msgType), enable);
}

[[maybe_unused]] void *QLoggingCategory_defaultCategory(void) {
    return QLoggingCategory::defaultCategory();
}

[[maybe_unused]] void QLoggingCategory_setFilterRules(const char *rules) {
    QLoggingCategory::setFilterRules(QString::fromUtf8(rules != nullptr ? rules : ""));
}

[[maybe_unused]] void QLoggingCategory_cDebug(void *loggingCategory,
                                              const char *message) {
    const auto *category = static_cast<QLoggingCategory *>(loggingCategory);
    qCDebug(*category).noquote() << QString::fromUtf8(message != nullptr ? message : "");
}

[[maybe_unused]] void QLoggingCategory_cInfo(void *loggingCategory,
                                             const char *message) {
    const auto *category = static_cast<QLoggingCategory *>(loggingCategory);
    qCInfo(*category).noquote() << QString::fromUtf8(message != nullptr ? message : "");
}

[[maybe_unused]] void QLoggingCategory_cWarning(void *loggingCategory,
                                                const char *message) {
    const auto *category = static_cast<QLoggingCategory *>(loggingCategory);
    qCWarning(*category).noquote() << QString::fromUtf8(message != nullptr ? message : "");
}

[[maybe_unused]] void QLoggingCategory_cCritical(void *loggingCategory,
                                                 const char *message) {
    const auto *category = static_cast<QLoggingCategory *>(loggingCategory);
    qCCritical(*category).noquote() << QString::fromUtf8(message != nullptr ? message : "");
}