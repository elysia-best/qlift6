import CQlift

open class QLCDNumber: QFrame {
    var overflowCallback: (() -> Void)?

    public enum Mode: Int32 {
        case Hex = 0
        case Dec = 1
        case Oct = 2
        case Bin = 3
    }

    public enum SegmentStyle: Int32 {
        case Outline = 0
        case Filled = 1
        case Flat = 2
    }

    public init(parent: QWidget? = nil) {
        super.init(ptr: QLCDNumber_new(parent?.ptr))
    }

    public init(numDigits: UInt32, parent: QWidget? = nil) {
        super.init(ptr: QLCDNumber_new2(numDigits, parent?.ptr))
    }

    override init(ptr: UnsafeMutableRawPointer) {
        super.init(ptr: ptr)
    }

    deinit {
        checkDeleteQtObj()
    }

    override func swiftCleanup() {
        super.swiftCleanup()
        overflowCallback = nil
    }

    public var digitCount: Int32 {
        get { QLCDNumber_digitCount(ptr) }
        set { QLCDNumber_setDigitCount(ptr, newValue) }
    }

    public var intValue: Int32 {
        QLCDNumber_intValue(ptr)
    }

    public var value: Double {
        QLCDNumber_value(ptr)
    }

    public var mode: Mode {
        get { Mode(rawValue: QLCDNumber_mode(ptr)) ?? .Dec }
        set { QLCDNumber_setMode(ptr, newValue.rawValue) }
    }

    public var segmentStyle: SegmentStyle {
        get { SegmentStyle(rawValue: QLCDNumber_segmentStyle(ptr)) ?? .Filled }
        set { QLCDNumber_setSegmentStyle(ptr, newValue.rawValue) }
    }

    public var smallDecimalPoint: Bool {
        get { QLCDNumber_smallDecimalPoint(ptr) }
        set { QLCDNumber_setSmallDecimalPoint(ptr, newValue) }
    }

    public func checkOverflow(_ num: Double) -> Bool {
        QLCDNumber_checkOverflowDouble(ptr, num)
    }

    public func checkOverflow(_ num: Int32) -> Bool {
        QLCDNumber_checkOverflowInt(ptr, num)
    }

    public func display(_ text: String) {
        QLCDNumber_displayString(ptr, text)
    }

    public func display(_ num: Double) {
        QLCDNumber_displayDouble(ptr, num)
    }

    public func display(_ num: Int32) {
        QLCDNumber_displayInt(ptr, num)
    }

    public func setBinMode() {
        QLCDNumber_setBinMode(ptr)
    }

    public func setDecMode() {
        QLCDNumber_setDecMode(ptr)
    }

    public func setHexMode() {
        QLCDNumber_setHexMode(ptr)
    }

    public func setOctMode() {
        QLCDNumber_setOctMode(ptr)
    }

    open func connectOverflow<T: AnyObject, R: Any>(receiver: QObject? = nil,
                                                     target: T,
                                                     to slot: @escaping SlotVoid<T, R>) {
        self.overflowCallback = { [weak target] in
            if let target = target { _ = slot(target)() }
        }

        let rawSelf = Unmanaged.passUnretained(self).toOpaque()
        QLCDNumber_overflow_connect(self.ptr, (receiver ?? self).ptr, rawSelf) { raw in
            let _self = Unmanaged<QLCDNumber>.fromOpaque(raw).takeUnretainedValue()
            _self.overflowCallback?()
        }
    }
}
