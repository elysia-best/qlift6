import CQlift
#if os(Linux)
import Glibc
#else
import Darwin
#endif

public struct QVulkanExtensionInfo {
    public let name: String
    public let version: UInt32
}

public struct QVulkanLayerInfo {
    public let name: String
    public let description: String
    public let version: UInt32
    public let specVersion: String
}

public struct QVulkanVersion {
    public let major: Int32
    public let minor: Int32
    public let micro: Int32
}

public class QVulkanInstance {

    public struct Flags: OptionSet {
        public var rawValue: Int32
        public init(rawValue: Int32) {
            self.rawValue = rawValue
        }

        public static let noDebugOutputRedirect = Flags(rawValue: 0x01)
        public static let noPortabilityDrivers = Flags(rawValue: 0x02)
    }

    public enum ErrorCode: Int32 {
        case success = 0
    }

    public var ptr: UnsafeMutableRawPointer!

    public init() {
        ptr = QVulkanInstance_new()
    }

    init(ptr: UnsafeMutableRawPointer) {
        self.ptr = ptr
    }

    deinit {
        guard ptr != nil else {
            return
        }
        QVulkanInstance_delete(ptr)
        ptr = nil
    }

    public var flags: Flags {
        get { Flags(rawValue: QVulkanInstance_flags(ptr)) }
        set { QVulkanInstance_setFlags(ptr, newValue.rawValue) }
    }

    public var isValid: Bool {
        QVulkanInstance_isValid(ptr)
    }

    public var apiVersion: QVulkanVersion {
        QVulkanVersion(major: QVulkanInstance_apiVersionMajor(ptr),
                       minor: QVulkanInstance_apiVersionMinor(ptr),
                       micro: QVulkanInstance_apiVersionMicro(ptr))
    }

    public var supportedApiVersion: QVulkanVersion {
        QVulkanVersion(major: QVulkanInstance_supportedApiVersionMajor(ptr),
                       minor: QVulkanInstance_supportedApiVersionMinor(ptr),
                       micro: QVulkanInstance_supportedApiVersionMicro(ptr))
    }

    public var errorCodeRawValue: Int32 {
        QVulkanInstance_errorCode(ptr)
    }

    public var errorCode: ErrorCode? {
        ErrorCode(rawValue: errorCodeRawValue)
    }

    public func functions() -> QVulkanFunctions? {
        guard let p = QliftQVulkanInstance_functions(ptr) else {
            return nil
        }
        return QVulkanFunctions(ptr: p)
    }

    public func deviceFunctions(device: UInt64) -> QVulkanDeviceFunctions? {
        guard let p = QliftQVulkanInstance_deviceFunctions(ptr, device) else {
            return nil
        }
        return QVulkanDeviceFunctions(ptr: p)
    }

    public var vkInstanceHandle: UInt64 {
        QVulkanInstance_vkInstance(ptr)
    }

    public func getInstanceProcAddr(_ name: String) -> UInt64 {
        QVulkanInstance_getInstanceProcAddr(ptr, name)
    }

    public var extensions: [String] {
        let count = QVulkanInstance_extensionsSize(ptr)
        guard count > 0 else {
            return []
        }

        return (0..<count).map { idx in
            let item = QVulkanInstance_extensionAt(ptr, idx)
            return String(utf16CodeUnits: item.utf16, count: Int(item.size))
        }
    }

    public var layers: [String] {
        let count = QVulkanInstance_layersSize(ptr)
        guard count > 0 else {
            return []
        }

        return (0..<count).map { idx in
            let item = QVulkanInstance_layerAt(ptr, idx)
            return String(utf16CodeUnits: item.utf16, count: Int(item.size))
        }
    }

    public func supportedExtensionsContains(_ name: String) -> Bool {
        QVulkanInstance_supportedExtensionsContains(ptr, name)
    }

    public func supportedExtensionsContains(_ name: String, minVersion: Int32) -> Bool {
        QVulkanInstance_supportedExtensionsContainsMinVersion(ptr, name, minVersion)
    }

    public func supportedLayersContains(_ name: String) -> Bool {
        QVulkanInstance_supportedLayersContains(ptr, name)
    }

    public func supportedLayersContains(_ name: String, minVersion: Int32) -> Bool {
        QVulkanInstance_supportedLayersContainsMinVersion(ptr, name, minVersion)
    }

    public func supportedExtensions() -> [QVulkanExtensionInfo] {
        let count = QVulkanInstance_supportedExtensionsSize(ptr)
        guard count > 0 else {
            return []
        }

        return (0..<count).map { idx in
            let nameC = QVulkanInstance_supportedExtensionNameAt(ptr, idx)
            let name = String(utf16CodeUnits: nameC.utf16, count: Int(nameC.size))
            return QVulkanExtensionInfo(
                name: name,
                version: QVulkanInstance_supportedExtensionVersionAt(ptr, idx)
            )
        }
    }

    public func supportedLayers() -> [QVulkanLayerInfo] {
        let count = QVulkanInstance_supportedLayersSize(ptr)
        guard count > 0 else {
            return []
        }

        return (0..<count).map { idx in
            let nameC = QVulkanInstance_supportedLayerNameAt(ptr, idx)
            let descriptionC = QVulkanInstance_supportedLayerDescriptionAt(ptr, idx)
            let specVersionC = QVulkanInstance_supportedLayerSpecVersionAt(ptr, idx)

            return QVulkanLayerInfo(
                name: String(utf16CodeUnits: nameC.utf16, count: Int(nameC.size)),
                description: String(utf16CodeUnits: descriptionC.utf16, count: Int(descriptionC.size)),
                version: QVulkanInstance_supportedLayerVersionAt(ptr, idx),
                specVersion: String(utf16CodeUnits: specVersionC.utf16, count: Int(specVersionC.size))
            )
        }
    }

    public func setApiVersion(major: Int32, minor: Int32, micro: Int32 = 0) {
        QVulkanInstance_setApiVersion(ptr, major, minor, micro)
    }

    public func setVkInstance(handle: UInt64) {
        QVulkanInstance_setVkInstance(ptr, handle)
    }

    public func setExtensions(_ extensions: [String]) {
        let cStrings = extensions.map { strdup($0) }
        defer {
            cStrings.forEach { free($0) }
        }

        var pointers = cStrings.map { $0.map { UnsafePointer<CChar>($0) } }
        pointers.withUnsafeMutableBufferPointer { buffer in
            QVulkanInstance_setExtensions(ptr, buffer.baseAddress, Int32(buffer.count))
        }
    }

    public func setLayers(_ layers: [String]) {
        let cStrings = layers.map { strdup($0) }
        defer {
            cStrings.forEach { free($0) }
        }

        var pointers = cStrings.map { $0.map { UnsafePointer<CChar>($0) } }
        pointers.withUnsafeMutableBufferPointer { buffer in
            QVulkanInstance_setLayers(ptr, buffer.baseAddress, Int32(buffer.count))
        }
    }

    public func resetDeviceFunctions(device: UInt64) {
        QVulkanInstance_resetDeviceFunctions(ptr, device)
    }

    public func presentAboutToBeQueued(window: QWindow) {
        QVulkanInstance_presentAboutToBeQueued(ptr, window.ptr)
    }

    public func presentQueued(window: QWindow) {
        QVulkanInstance_presentQueued(ptr, window.ptr)
    }

    public func supportsPresent(physicalDevice: UInt64,
                                queueFamilyIndex: UInt32,
                                window: QWindow) -> Bool {
        QVulkanInstance_supportsPresent(ptr, physicalDevice, queueFamilyIndex, window.ptr)
    }

    public static func surfaceForWindow(_ window: QWindow) -> UInt64 {
        QVulkanInstance_surfaceForWindow(window.ptr)
    }

    @discardableResult
    public func create() -> Bool {
        QVulkanInstance_create(ptr)
    }

    public func destroy() {
        QVulkanInstance_destroy(ptr)
    }
}
