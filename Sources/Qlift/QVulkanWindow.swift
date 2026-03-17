import CQlift

open class QVulkanWindow: QWindow {

    public struct Flags: OptionSet {
        public var rawValue: Int32
        public init(rawValue: Int32) {
            self.rawValue = rawValue
        }

        public static let persistentResources = Flags(rawValue: 0x01)
    }

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

    public var physicalDeviceHandle: UInt64 {
        QVulkanWindow_physicalDevice(ptr)
    }

    public var graphicsQueueHandle: UInt64 {
        QVulkanWindow_graphicsQueue(ptr)
    }

    public var currentCommandBufferHandle: UInt64 {
        QVulkanWindow_currentCommandBuffer(ptr)
    }

    public var currentFramebufferHandle: UInt64 {
        QVulkanWindow_currentFramebuffer(ptr)
    }

    public var defaultRenderPassHandle: UInt64 {
        QVulkanWindow_defaultRenderPass(ptr)
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
