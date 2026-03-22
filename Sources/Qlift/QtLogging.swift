import CQlift


public enum QtMsgType: Int32 {
    case QtDebugMsg = 0
    case QtInfoMsg = 4
    case QtWarningMsg = 1
    case QtCriticalMsg = 2
    case QtFatalMsg = 3
}

public struct QMessageLogContext {
    public let category: String
    public let file: String
    public let function: String
    public let line: Int32
}

public typealias QtMessageHandler = (QtMsgType, QMessageLogContext, String) -> ()

private final class QtLoggingMessageHandlerBox {
    let handler: QtMessageHandler

    init(handler: @escaping QtMessageHandler) {
        self.handler = handler
    }
}

private var qtLoggingMessageHandlerBox: QtLoggingMessageHandlerBox?

private let qtLoggingMessageHandlerThunk: @convention(c) (UnsafeMutableRawPointer?, Int32, CQString, UnsafePointer<CChar>?, UnsafePointer<CChar>?, UnsafePointer<CChar>?, Int32) -> Void = {
    rawContext,
    rawType,
    rawMessage,
    rawCategory,
    rawFile,
    rawFunction,
    rawLine in
    guard let rawContext else {
        return
    }

    let box = Unmanaged<QtLoggingMessageHandlerBox>.fromOpaque(rawContext).takeUnretainedValue()

    let type = QtMsgType(rawValue: rawType) ?? .QtDebugMsg
    let message = String(utf16CodeUnits: rawMessage.utf16, count: Int(rawMessage.size))
    let context = QMessageLogContext(
        category: rawCategory.map { String(cString: $0) } ?? "default",
        file: rawFile.map { String(cString: $0) } ?? "",
        function: rawFunction.map { String(cString: $0) } ?? "",
        line: rawLine
    )

    box.handler(type, context, message)
}

public enum QtLogging {
    public static func setMessagePattern(_ pattern: String) {
        QtLogging_setMessagePattern(pattern)
    }

    public static func formatLogMessage(type: QtMsgType,
                                        message: String,
                                        category: String = "default",
                                        file: String = "",
                                        function: String = "",
                                        line: Int32 = 0) -> String {
        let text = QtLogging_formatLogMessage(type.rawValue,
                                              message,
                                              category,
                                              file,
                                              function,
                                              line)
        return String(utf16CodeUnits: text.utf16, count: Int(text.size))
    }

    public static func installMessageHandler(_ handler: QtMessageHandler?) {
        guard let handler else {
            qtLoggingMessageHandlerBox = nil
            QtLogging_installMessageHandler(nil, nil)
            return
        }

        let box = QtLoggingMessageHandlerBox(handler: handler)
        qtLoggingMessageHandlerBox = box
        let rawContext = Unmanaged.passUnretained(box).toOpaque()

        return QtLogging_installMessageHandler(rawContext, qtLoggingMessageHandlerThunk)
    }

    public static func debug(_ message: String) {
        QtLogging_debug(message)
    }

    public static func info(_ message: String) {
        QtLogging_info(message)
    }

    public static func warning(_ message: String) {
        QtLogging_warning(message)
    }

    public static func critical(_ message: String) {
        QtLogging_critical(message)
    }

    public static func fatal(_ message: String) {
        QtLogging_fatal(message)
    }
}