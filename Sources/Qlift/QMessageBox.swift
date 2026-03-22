import CQlift


open class QMessageBox: QDialog {

    public var icon: QMessageBox.Icon {
        get { QMessageBox.Icon(rawValue: QMessageBox_icon(ptr)) }
        set { QMessageBox_setIcon(self.ptr, newValue.rawValue) }
    }

    public var text: String {
        get {
            let s = QMessageBox_text(ptr)
            return String(utf16CodeUnits: s.utf16, count: Int(s.size))
        }
        set { QMessageBox_setText(self.ptr, newValue) }
    }

    public var informativeText: String {
        get {
            let s = QMessageBox_informativeText(ptr)
            return String(utf16CodeUnits: s.utf16, count: Int(s.size))
        }
        set { QMessageBox_setInformativeText(self.ptr, newValue) }
    }

    public var detailedText: String {
        get {
            let s = QMessageBox_detailedText(ptr)
            return String(utf16CodeUnits: s.utf16, count: Int(s.size))
        }
        set { QMessageBox_setDetailedText(self.ptr, newValue) }
    }

    public override var windowTitle: String {
        get {
            let s = QMessageBox_windowTitle(ptr)
            return String(utf16CodeUnits: s.utf16, count: Int(s.size))
        }
        set { QMessageBox_setWindowTitle(ptr, newValue) }
    }

    public var standardButtons: QMessageBox.StandardButton {
        get { .init(rawValue: QMessageBox_standardButtons(ptr)) }
        set { QMessageBox_setStandardButtons(self.ptr, newValue.rawValue) }
    }

    public init(parent: QWidget? = nil) {
        super.init(ptr: QMessageBox_new(parent?.ptr))
    }

    override init(ptr: UnsafeMutableRawPointer) {
        super.init(ptr: ptr)
    }

    deinit {
        checkDeleteQtObj()
    }

    public func setDefaultStandardButton(_ button: QMessageBox.StandardButton) {
        QMessageBox_setDefaultButtonStandardButton(self.ptr, button.rawValue)
    }

    open func exec() -> QMessageBox.StandardButton {
        return QMessageBox.StandardButton(rawValue: QMessageBox_exec(self.ptr))
    }

    public static func about(parent: QWidget? = nil, title: String, text: String) {
        QMessageBox_about(parent?.ptr, title, text)
    }

    public static func aboutQt(parent: QWidget? = nil, title: String = "") {
        QMessageBox_aboutQt(parent?.ptr, title)
    }

    public static func critical(parent: QWidget? = nil,
                                title: String,
                                text: String,
                                buttons: QMessageBox.StandardButton = .Ok,
                                defaultButton: QMessageBox.StandardButton = .NoButton) -> QMessageBox.StandardButton {
        QMessageBox.StandardButton(rawValue: QMessageBox_critical(parent?.ptr,
                                                                  title,
                                                                  text,
                                                                  buttons.rawValue,
                                                                  defaultButton.rawValue))
    }

    public static func information(parent: QWidget? = nil,
                                   title: String,
                                   text: String,
                                   buttons: QMessageBox.StandardButton = .Ok,
                                   defaultButton: QMessageBox.StandardButton = .NoButton) -> QMessageBox.StandardButton {
        QMessageBox.StandardButton(rawValue: QMessageBox_information(parent?.ptr,
                                                                     title,
                                                                     text,
                                                                     buttons.rawValue,
                                                                     defaultButton.rawValue))
    }

    public static func question(parent: QWidget? = nil,
                                title: String,
                                text: String,
                                buttons: QMessageBox.StandardButton = [.Yes, .No],
                                defaultButton: QMessageBox.StandardButton = .NoButton) -> QMessageBox.StandardButton {
        QMessageBox.StandardButton(rawValue: QMessageBox_question(parent?.ptr,
                                                                  title,
                                                                  text,
                                                                  buttons.rawValue,
                                                                  defaultButton.rawValue))
    }

    public static func warning(parent: QWidget? = nil,
                               title: String,
                               text: String,
                               buttons: QMessageBox.StandardButton = .Ok,
                               defaultButton: QMessageBox.StandardButton = .NoButton) -> QMessageBox.StandardButton {
        QMessageBox.StandardButton(rawValue: QMessageBox_warning(parent?.ptr,
                                                                 title,
                                                                 text,
                                                                 buttons.rawValue,
                                                                 defaultButton.rawValue))
    }
}

extension QMessageBox {
    public struct Icon: OptionSet {
        public let rawValue: Int32

        public init(rawValue: Int32) {
            self.rawValue = rawValue
        }

        public static let NoIcon: Icon = []
        public static let Information = Icon(rawValue: 1)
        public static let Warning = Icon(rawValue: 2)
        public static let Critical = Icon(rawValue: 3)
        public static let Question = Icon(rawValue: 4)
    }

    public struct StandardButton: OptionSet {
        public let rawValue: Int32

        public init(rawValue: Int32) {
            self.rawValue = rawValue
        }

        public static let NoButton: StandardButton = []
        public static let Ok = StandardButton(rawValue: 0x00000400)
        public static let Open = StandardButton(rawValue: 0x00002000)
        public static let Save = StandardButton(rawValue: 0x00000800)
        public static let Cancel = StandardButton(rawValue: 0x00400000)
        public static let Close = StandardButton(rawValue: 0x00200000)
        public static let Discard = StandardButton(rawValue: 0x00800000)
        public static let Apply = StandardButton(rawValue: 0x02000000)
        public static let Reset = StandardButton(rawValue: 0x04000000)
        public static let RestoreDefaults = StandardButton(rawValue: 0x08000000)
        public static let Help = StandardButton(rawValue: 0x01000000)
        public static let SaveAll = StandardButton(rawValue: 0x00001000)
        public static let Yes = StandardButton(rawValue: 16384)
        public static let YesToAll = StandardButton(rawValue: 0x00008000)
        public static let No = StandardButton(rawValue: 65536)
        public static let NoToAll = StandardButton(rawValue: 0x00020000)
        public static let Abort = StandardButton(rawValue: 0x00040000)
        public static let Retry = StandardButton(rawValue: 0x00080000)
        public static let Ignore = StandardButton(rawValue: 0x00100000)
    }
}
