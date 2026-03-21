import CQlift

open class QPlainTextEdit: QWidget {
    public enum LineWrapMode: Int32 {
        case NoWrap
        case WidgetWidth
    }

    var textChangedCallback: (() -> Void)?
    var blockCountChangedCallback: ((Int32) -> Void)?
    var copyAvailableCallback: ((Bool) -> Void)?
    var cursorPositionChangedCallback: (() -> Void)?

    public init(text: String = "", parent: QWidget? = nil) {
        super.init(ptr: QPlainTextEdit_new(text, parent?.ptr))
    }

    override init(ptr: UnsafeMutableRawPointer) {
        super.init(ptr: ptr)
    }

    deinit {
        checkDeleteQtObj()
    }

    override func swiftCleanup() {
        super.swiftCleanup()
        textChangedCallback = nil
        blockCountChangedCallback = nil
        copyAvailableCallback = nil
        cursorPositionChangedCallback = nil
    }

    public var plainText: String {
        get {
            let s = QPlainTextEdit_toPlainText(ptr)
            return String(utf16CodeUnits: s.utf16, count: Int(s.size))
        }
        set { QPlainTextEdit_setPlainText(ptr, newValue) }
    }

    public var placeholderText: String {
        get {
            let s = QPlainTextEdit_placeholderText(ptr)
            return String(utf16CodeUnits: s.utf16, count: Int(s.size))
        }
        set { QPlainTextEdit_setPlaceholderText(ptr, newValue) }
    }

    public var readOnly: Bool {
        get { QPlainTextEdit_isReadOnly(ptr) }
        set { QPlainTextEdit_setReadOnly(ptr, newValue) }
    }

    public var undoRedoEnabled: Bool {
        get { QPlainTextEdit_isUndoRedoEnabled(ptr) }
        set { QPlainTextEdit_setUndoRedoEnabled(ptr, newValue) }
    }

    public var overwriteMode: Bool {
        get { QPlainTextEdit_overwriteMode(ptr) }
        set { QPlainTextEdit_setOverwriteMode(ptr, newValue) }
    }

    public var lineWrapMode: LineWrapMode {
        get { LineWrapMode(rawValue: QPlainTextEdit_lineWrapMode(ptr)) ?? .WidgetWidth }
        set { QPlainTextEdit_setLineWrapMode(ptr, newValue.rawValue) }
    }

    public var maximumBlockCount: Int32 {
        get { QPlainTextEdit_maximumBlockCount(ptr) }
        set { QPlainTextEdit_setMaximumBlockCount(ptr, newValue) }
    }

    public var blockCount: Int32 {
        get { QPlainTextEdit_blockCount(ptr) }
    }

    public var tabChangesFocus: Bool {
        get { QPlainTextEdit_tabChangesFocus(ptr) }
        set { QPlainTextEdit_setTabChangesFocus(ptr, newValue) }
    }

    public var tabStopDistance: Double {
        get { QPlainTextEdit_tabStopDistance(ptr) }
        set { QPlainTextEdit_setTabStopDistance(ptr, newValue) }
    }

    public var centerOnScroll: Bool {
        get { QPlainTextEdit_centerOnScroll(ptr) }
        set { QPlainTextEdit_setCenterOnScroll(ptr, newValue) }
    }

    public var backgroundVisible: Bool {
        get { QPlainTextEdit_backgroundVisible(ptr) }
        set { QPlainTextEdit_setBackgroundVisible(ptr, newValue) }
    }

    public func appendPlainText(_ text: String) {
        QPlainTextEdit_appendPlainText(ptr, text)
    }

    public func appendHtml(_ html: String) {
        QPlainTextEdit_appendHtml(ptr, html)
    }

    public func clear() {
        QPlainTextEdit_clear(ptr)
    }

    public func copy() {
        QPlainTextEdit_copy(ptr)
    }

    public func cut() {
        QPlainTextEdit_cut(ptr)
    }

    public func paste() {
        QPlainTextEdit_paste(ptr)
    }

    public func selectAll() {
        QPlainTextEdit_selectAll(ptr)
    }

    public func undo() {
        QPlainTextEdit_undo(ptr)
    }

    public func redo() {
        QPlainTextEdit_redo(ptr)
    }

    public func zoomIn(_ range: Int32 = 1) {
        QPlainTextEdit_zoomIn(ptr, range)
    }

    public func zoomOut(_ range: Int32 = 1) {
        QPlainTextEdit_zoomOut(ptr, range)
    }

    open func connectTextChanged<T: AnyObject, R: Any>(receiver: QObject? = nil,
                                                        target: T,
                                                        to slot: @escaping SlotVoid<T, R>) {
        self.textChangedCallback = { [weak target] in
            if let target = target { _ = slot(target)() }
        }

        let rawSelf = Unmanaged.passUnretained(self).toOpaque()
        QPlainTextEdit_textChanged_connect(self.ptr, (receiver ?? self).ptr, rawSelf) { raw in
            let _self = Unmanaged<QPlainTextEdit>.fromOpaque(raw).takeUnretainedValue()
            _self.textChangedCallback?()
        }
    }

    open func connectBlockCountChanged<T: AnyObject, R: Any>(receiver: QObject? = nil,
                                                              target: T,
                                                              to slot: @escaping Slot<T, Int32, R>) {
        self.blockCountChangedCallback = { [weak target] in
            if let target = target { _ = slot(target)($0) }
        }

        let rawSelf = Unmanaged.passUnretained(self).toOpaque()
        QPlainTextEdit_blockCountChanged_connect(self.ptr, (receiver ?? self).ptr, rawSelf) { raw, count in
            let _self = Unmanaged<QPlainTextEdit>.fromOpaque(raw).takeUnretainedValue()
            _self.blockCountChangedCallback?(count)
        }
    }

    open func connectCopyAvailable<T: AnyObject, R: Any>(receiver: QObject? = nil,
                                                          target: T,
                                                          to slot: @escaping Slot<T, Bool, R>) {
        self.copyAvailableCallback = { [weak target] in
            if let target = target { _ = slot(target)($0) }
        }

        let rawSelf = Unmanaged.passUnretained(self).toOpaque()
        QPlainTextEdit_copyAvailable_connect(self.ptr, (receiver ?? self).ptr, rawSelf) { raw, available in
            let _self = Unmanaged<QPlainTextEdit>.fromOpaque(raw).takeUnretainedValue()
            _self.copyAvailableCallback?(available)
        }
    }

    open func connectCursorPositionChanged<T: AnyObject, R: Any>(receiver: QObject? = nil,
                                                                  target: T,
                                                                  to slot: @escaping SlotVoid<T, R>) {
        self.cursorPositionChangedCallback = { [weak target] in
            if let target = target { _ = slot(target)() }
        }

        let rawSelf = Unmanaged.passUnretained(self).toOpaque()
        QPlainTextEdit_cursorPositionChanged_connect(self.ptr, (receiver ?? self).ptr, rawSelf) { raw in
            let _self = Unmanaged<QPlainTextEdit>.fromOpaque(raw).takeUnretainedValue()
            _self.cursorPositionChangedCallback?()
        }
    }
}
