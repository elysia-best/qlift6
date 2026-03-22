import CQlift

open class QFileDialog: QDialog {
    public enum AcceptMode: Int32 {
        case AcceptOpen = 0
        case AcceptSave = 1
    }

    public enum FileMode: Int32 {
        case AnyFile = 0
        case ExistingFile = 1
        case Directory = 2
        case ExistingFiles = 3
    }

    public struct Option: OptionSet {
        public let rawValue: Int32

        public init(rawValue: Int32) {
            self.rawValue = rawValue
        }

        public static let ShowDirsOnly = Option(rawValue: 0x00000001)
        public static let DontResolveSymlinks = Option(rawValue: 0x00000002)
        public static let DontConfirmOverwrite = Option(rawValue: 0x00000004)
        public static let DontUseNativeDialog = Option(rawValue: 0x00000008)
        public static let ReadOnly = Option(rawValue: 0x00000010)
        public static let HideNameFilterDetails = Option(rawValue: 0x00000020)
        public static let DontUseCustomDirectoryIcons = Option(rawValue: 0x00000040)
    }

    public enum ViewMode: Int32 {
        case Detail = 0
        case List = 1
    }

    public init(parent: QWidget? = nil,
                caption: String = "",
                directory: String = "",
                filter: String = "") {
        super.init(ptr: QFileDialog_new(parent?.ptr, caption, directory, filter))
    }

    override init(ptr: UnsafeMutableRawPointer) {
        super.init(ptr: ptr)
    }

    deinit {
        checkDeleteQtObj()
    }

    public var acceptMode: AcceptMode {
        get { AcceptMode(rawValue: QFileDialog_acceptMode(ptr)) ?? .AcceptOpen }
        set { QFileDialog_setAcceptMode(ptr, newValue.rawValue) }
    }

    public var defaultSuffix: String {
        get {
            let s = QFileDialog_defaultSuffix(ptr)
            return String(utf16CodeUnits: s.utf16, count: Int(s.size))
        }
        set { QFileDialog_setDefaultSuffix(ptr, newValue) }
    }

    public var fileMode: FileMode {
        get { FileMode(rawValue: QFileDialog_fileMode(ptr)) ?? .AnyFile }
        set { QFileDialog_setFileMode(ptr, newValue.rawValue) }
    }

    public var options: Option {
        get { Option(rawValue: QFileDialog_options(ptr)) }
        set { QFileDialog_setOptions(ptr, newValue.rawValue) }
    }

    public var viewMode: ViewMode {
        get { ViewMode(rawValue: QFileDialog_viewMode(ptr)) ?? .Detail }
        set { QFileDialog_setViewMode(ptr, newValue.rawValue) }
    }

    public var directory: String {
        get {
            let s = QFileDialog_directory(ptr)
            return String(utf16CodeUnits: s.utf16, count: Int(s.size))
        }
        set { QFileDialog_setDirectory(ptr, newValue) }
    }

    public var selectedNameFilter: String {
        let s = QFileDialog_selectedNameFilter(ptr)
        return String(utf16CodeUnits: s.utf16, count: Int(s.size))
    }

    public var selectedFile: String {
        let s = QFileDialog_selectedFile(ptr)
        return String(utf16CodeUnits: s.utf16, count: Int(s.size))
    }

    public func setOption(_ option: Option, on: Bool = true) {
        QFileDialog_setOption(ptr, option.rawValue, on)
    }

    public func testOption(_ option: Option) -> Bool {
        QFileDialog_testOption(ptr, option.rawValue)
    }

    public func setNameFilter(_ filter: String) {
        QFileDialog_setNameFilter(ptr, filter)
    }

    public func selectFile(_ filename: String) {
        QFileDialog_selectFile(ptr, filename)
    }

    public static func getExistingDirectory(parent: QWidget? = nil,
                                            caption: String = "",
                                            dir: String = "",
                                            options: Option = .ShowDirsOnly) -> String {
        let s = QFileDialog_getExistingDirectory(parent?.ptr, caption, dir, options.rawValue)
        return String(utf16CodeUnits: s.utf16, count: Int(s.size))
    }

    public static func getOpenFileName(parent: QWidget? = nil,
                                       caption: String = "",
                                       dir: String = "",
                                       filter: String = "",
                                       options: Option = []) -> String {
        let s = QFileDialog_getOpenFileName(parent?.ptr, caption, dir, filter, options.rawValue)
        return String(utf16CodeUnits: s.utf16, count: Int(s.size))
    }

    public static func getSaveFileName(parent: QWidget? = nil,
                                       caption: String = "",
                                       dir: String = "",
                                       filter: String = "",
                                       options: Option = []) -> String {
        let s = QFileDialog_getSaveFileName(parent?.ptr, caption, dir, filter, options.rawValue)
        return String(utf16CodeUnits: s.utf16, count: Int(s.size))
    }
}
