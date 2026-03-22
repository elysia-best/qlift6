import CQlift
import Vulkan
#if os(Linux)
import Glibc
#else
import Darwin
#endif

@inline(__always)
private func qliftVkHandle<T>(from raw: UInt64, as: T.Type = T.self) -> T {
    unsafeBitCast(raw, to: T.self)
}

public struct QVulkanPhysicalDeviceInfo {
    public let name: String
    public let vendorID: UInt32
    public let deviceID: UInt32
    public let deviceType: UInt32
    public let apiVersion: UInt32
    public let driverVersion: UInt32
}

open class QVulkanWindow: QWindow {

    public struct Flags: OptionSet {
        public var rawValue: Int32
        public init(rawValue: Int32) {
            self.rawValue = rawValue
        }

        public static let persistentResources = Flags(rawValue: 0x01)
    }

    public static let maxConcurrentFrameCount: Int32 = QVulkanWindow_MAX_CONCURRENT_FRAME_COUNT()

    public override init(parent: QWindow? = nil) {
        super.init(ptr: QVulkanWindow_new(parent?.ptr))
    }

    public override init(ptr: UnsafeMutableRawPointer) {
        super.init(ptr: ptr)
    }

    deinit {
        checkDeleteQtObj()
    }

    public var flags: Flags {
        get { Flags(rawValue: QVulkanWindow_flags(ptr)) }
        set { QVulkanWindow_setFlags(ptr, newValue.rawValue) }
    }

    public var isValid: Bool {
        QVulkanWindow_isValid(ptr)
    }

    public var colorFormat: Int32 {
        QVulkanWindow_colorFormat(ptr)
    }

    public var depthStencilFormat: Int32 {
        QVulkanWindow_depthStencilFormat(ptr)
    }

    public var sampleCountFlagBits: Int32 {
        QVulkanWindow_sampleCountFlagBits(ptr)
    }

    public var concurrentFrameCount: Int32 {
        QVulkanWindow_concurrentFrameCount(ptr)
    }

    public var currentFrame: Int32 {
        QVulkanWindow_currentFrame(ptr)
    }

    public var currentSwapChainImageIndex: Int32 {
        QVulkanWindow_currentSwapChainImageIndex(ptr)
    }

    public var swapChainImageCount: Int32 {
        QVulkanWindow_swapChainImageCount(ptr)
    }

    public var deviceHandle: UInt64 {
        QVulkanWindow_device(ptr)
    }

    public var device: VkDevice {
        qliftVkHandle(from: deviceHandle)
    }

    public var physicalDeviceHandle: UInt64 {
        QVulkanWindow_physicalDevice(ptr)
    }

    public var physicalDevice: VkPhysicalDevice {
        qliftVkHandle(from: physicalDeviceHandle)
    }

    public var graphicsQueueHandle: UInt64 {
        QVulkanWindow_graphicsQueue(ptr)
    }

    public var graphicsQueue: VkQueue {
        qliftVkHandle(from: graphicsQueueHandle)
    }

    public var graphicsCommandPoolHandle: UInt64 {
        QVulkanWindow_graphicsCommandPool(ptr)
    }

    public var graphicsCommandPool: VkCommandPool {
        qliftVkHandle(from: graphicsCommandPoolHandle)
    }

    public var currentCommandBufferHandle: UInt64 {
        QVulkanWindow_currentCommandBuffer(ptr)
    }

    public var currentCommandBuffer: VkCommandBuffer {
        qliftVkHandle(from: currentCommandBufferHandle)
    }

    public var currentFramebufferHandle: UInt64 {
        QVulkanWindow_currentFramebuffer(ptr)
    }

    public var currentFramebuffer: VkFramebuffer {
        qliftVkHandle(from: currentFramebufferHandle)
    }

    public var defaultRenderPassHandle: UInt64 {
        QVulkanWindow_defaultRenderPass(ptr)
    }

    public var defaultRenderPass: VkRenderPass {
        qliftVkHandle(from: defaultRenderPassHandle)
    }

    public var depthStencilImageHandle: UInt64 {
        QVulkanWindow_depthStencilImage(ptr)
    }

    public var depthStencilImage: VkImage {
        qliftVkHandle(from: depthStencilImageHandle)
    }

    public var depthStencilImageViewHandle: UInt64 {
        QVulkanWindow_depthStencilImageView(ptr)
    }

    public var depthStencilImageView: VkImageView {
        qliftVkHandle(from: depthStencilImageViewHandle)
    }

    public var deviceLocalMemoryIndex: UInt32 {
        QVulkanWindow_deviceLocalMemoryIndex(ptr)
    }

    public var graphicsQueueFamilyIndex: UInt32 {
        QVulkanWindow_graphicsQueueFamilyIndex(ptr)
    }

    public var hostVisibleMemoryIndex: UInt32 {
        QVulkanWindow_hostVisibleMemoryIndex(ptr)
    }

    public var swapChainImageSize: QSize {
        QSize(ptr: QVulkanWindow_swapChainImageSize(ptr))
    }

    public func setPhysicalDeviceIndex(_ idx: Int32) {
        QVulkanWindow_setPhysicalDeviceIndex(ptr, idx)
    }

    public func setRenderer(_ renderer: QVulkanWindowRenderer) {
        QVulkanWindow_setRenderer(ptr, renderer.ptr)
    }

    public func setSampleCount(_ sampleCount: Int32) {
        QVulkanWindow_setSampleCount(ptr, sampleCount)
    }

    public func setDeviceExtensions(_ extensions: [String]) {
        let cStrings = extensions.map { strdup($0) }
        defer {
            cStrings.forEach { free($0) }
        }

        var pointers = cStrings.map { $0.map { UnsafePointer<CChar>($0) } }
        pointers.withUnsafeMutableBufferPointer { buffer in
            QVulkanWindow_setDeviceExtensions(ptr, buffer.baseAddress, Int32(buffer.count))
        }
    }

    public func setPreferredColorFormats(_ formats: [Int32]) {
        formats.withUnsafeBufferPointer { buffer in
            QVulkanWindow_setPreferredColorFormats(ptr, buffer.baseAddress, Int32(buffer.count))
        }
    }

    public func supportedSampleCounts() -> [Int32] {
        let count = QVulkanWindow_supportedSampleCountsSize(ptr)
        guard count > 0 else {
            return []
        }

        return (0..<count).map { index in
            QVulkanWindow_supportedSampleCountAt(ptr, index)
        }
    }

    public func supportedDeviceExtensions() -> [QVulkanExtensionInfo] {
        let count = QVulkanWindow_supportedDeviceExtensionsSize(ptr)
        guard count > 0 else {
            return []
        }

        return (0..<count).map { idx in
            let nameC = QVulkanWindow_supportedDeviceExtensionNameAt(ptr, idx)
            return QVulkanExtensionInfo(
                name: String(utf16CodeUnits: nameC.utf16, count: Int(nameC.size)),
                version: QVulkanWindow_supportedDeviceExtensionVersionAt(ptr, idx)
            )
        }
    }

    public func availablePhysicalDevices() -> [QVulkanPhysicalDeviceInfo] {
        let count = QVulkanWindow_availablePhysicalDevicesSize(ptr)
        guard count > 0 else {
            return []
        }

        return (0..<count).map { idx in
            let nameC = QVulkanWindow_availablePhysicalDeviceNameAt(ptr, idx)
            return QVulkanPhysicalDeviceInfo(
                name: String(utf16CodeUnits: nameC.utf16, count: Int(nameC.size)),
                vendorID: QVulkanWindow_availablePhysicalDeviceVendorIDAt(ptr, idx),
                deviceID: QVulkanWindow_availablePhysicalDeviceDeviceIDAt(ptr, idx),
                deviceType: QVulkanWindow_availablePhysicalDeviceDeviceTypeAt(ptr, idx),
                apiVersion: QVulkanWindow_availablePhysicalDeviceApiVersionAt(ptr, idx),
                driverVersion: QVulkanWindow_availablePhysicalDeviceDriverVersionAt(ptr, idx)
            )
        }
    }

    public func msaaColorImageHandle(at index: Int32) -> UInt64 {
        QVulkanWindow_msaaColorImage(ptr, index)
    }

    public func msaaColorImage(at index: Int32) -> VkImage {
        qliftVkHandle(from: msaaColorImageHandle(at: index))
    }

    public func msaaColorImageViewHandle(at index: Int32) -> UInt64 {
        QVulkanWindow_msaaColorImageView(ptr, index)
    }

    public func msaaColorImageView(at index: Int32) -> VkImageView {
        qliftVkHandle(from: msaaColorImageViewHandle(at: index))
    }

    public func swapChainImageHandle(at index: Int32) -> UInt64 {
        QVulkanWindow_swapChainImage(ptr, index)
    }

    public func swapChainImage(at index: Int32) -> VkImage {
        qliftVkHandle(from: swapChainImageHandle(at: index))
    }

    public func swapChainImageViewHandle(at index: Int32) -> UInt64 {
        QVulkanWindow_swapChainImageView(ptr, index)
    }

    public func swapChainImageView(at index: Int32) -> VkImageView {
        qliftVkHandle(from: swapChainImageViewHandle(at: index))
    }

    public func supportsGrab() -> Bool {
        QVulkanWindow_supportsGrab(ptr)
    }

    public func grab() -> QImage {
        QImage(ptr: QVulkanWindow_grab(ptr))
    }

    public func frameReady() {
        QVulkanWindow_frameReady(ptr)
    }
}
