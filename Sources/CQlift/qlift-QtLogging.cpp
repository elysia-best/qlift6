#include <QDebug>
#include <QtLogging>

#include "qlift-QtLogging.h"

namespace {
QtLoggingMessageHandler g_messageHandler = nullptr;
void *g_messageHandlerContext = nullptr;

void qliftQtMessageHandler(QtMsgType type,
                           const QMessageLogContext &context,
                           const QString &message) {
    if (g_messageHandler == nullptr) {
        return;
    }

    g_messageHandler(g_messageHandlerContext,
                     static_cast<int>(type),
                     CQString{message.utf16(), message.size()},
                     context.category,
                     context.file,
                     context.function,
                     context.line);
}
} // namespace

[[maybe_unused]] void QtLogging_setMessagePattern(const char *pattern) {
    qSetMessagePattern(QString::fromUtf8(pattern != nullptr ? pattern : ""));
}

[[maybe_unused]] CQString QtLogging_formatLogMessage(int type,
                                                     const char *message,
                                                     const char *category,
                                                     const char *file,
                                                     const char *function,
                                                     int line) {
    thread_local QString formattedMessage;

    const QMessageLogContext context{file,
                                     line,
                                     function,
                                     category != nullptr ? category : "default"};

    formattedMessage = qFormatLogMessage(static_cast<QtMsgType>(type),
                                         context,
                                         QString::fromUtf8(message != nullptr ? message : ""));

    return CQString{formattedMessage.utf16(), formattedMessage.size()};
}

[[maybe_unused]] void QtLogging_installMessageHandler(void *context,
                                                      QtLoggingMessageHandler handler) {
    g_messageHandlerContext = context;
    g_messageHandler = handler;

    if (handler == nullptr) {
        qInstallMessageHandler(nullptr);
        return;
    }

    qInstallMessageHandler(qliftQtMessageHandler);
}

[[maybe_unused]] void QtLogging_debug(const char *message) {
    qDebug().noquote() << QString::fromUtf8(message != nullptr ? message : "");
}

[[maybe_unused]] void QtLogging_info(const char *message) {
    qInfo().noquote() << QString::fromUtf8(message != nullptr ? message : "");
}

[[maybe_unused]] void QtLogging_warning(const char *message) {
    qWarning().noquote() << QString::fromUtf8(message != nullptr ? message : "");
}

[[maybe_unused]] void QtLogging_critical(const char *message) {
    qCritical().noquote() << QString::fromUtf8(message != nullptr ? message : "");
}

[[maybe_unused]] void QtLogging_fatal(const char *message) {
    const auto utf8 = QString::fromUtf8(message != nullptr ? message : "").toUtf8();
    qFatal("%s", utf8.constData());
}