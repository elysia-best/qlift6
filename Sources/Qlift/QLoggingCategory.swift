import CQlift


public final class QLoggingCategory {
    public var ptr: UnsafeMutableRawPointer!
    private let ownsHandle: Bool

    public init(category: String, enableForLevel: QtMsgType = .QtDebugMsg) {
        self.ptr = QLoggingCategory_new(category, enableForLevel.rawValue)
        self.ownsHandle = true
    }

    internal init(ptr: UnsafeMutableRawPointer, ownsHandle: Bool) {
        self.ptr = ptr
        self.ownsHandle = ownsHandle
    }

    deinit {
        guard ptr != nil else {
            return
        }

        if ownsHandle {
            QLoggingCategory_delete(ptr)
        }
        ptr = nil
    }

    public var categoryName: String {
        let s = QLoggingCategory_categoryName(ptr)
        return String(utf16CodeUnits: s.utf16, count: Int(s.size))
    }

    public var isCriticalEnabled: Bool {
        QLoggingCategory_isCriticalEnabled(ptr)
    }

    public var isDebugEnabled: Bool {
        QLoggingCategory_isDebugEnabled(ptr)
    }

    public var isInfoEnabled: Bool {
        QLoggingCategory_isInfoEnabled(ptr)
    }

    public var isWarningEnabled: Bool {
        QLoggingCategory_isWarningEnabled(ptr)
    }

    public func isEnabled(_ type: QtMsgType) -> Bool {
        QLoggingCategory_isEnabled(ptr, type.rawValue)
    }

    public func setEnabled(_ type: QtMsgType, _ enable: Bool) {
        QLoggingCategory_setEnabled(ptr, type.rawValue, enable)
    }

    public static var defaultCategory: QLoggingCategory {
        QLoggingCategory(ptr: QLoggingCategory_defaultCategory(), ownsHandle: false)
    }

    public static func setFilterRules(_ rules: String) {
        QLoggingCategory_setFilterRules(rules)
    }

    public func cDebug(_ message: String) {
        QLoggingCategory_cDebug(ptr, message)
    }

    public func cInfo(_ message: String) {
        QLoggingCategory_cInfo(ptr, message)
    }

    public func cWarning(_ message: String) {
        QLoggingCategory_cWarning(ptr, message)
    }

    public func cCritical(_ message: String) {
        QLoggingCategory_cCritical(ptr, message)
    }
}