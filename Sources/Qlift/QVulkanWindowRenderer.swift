import CQlift

open class QVulkanWindowRenderer {

    public var ptr: UnsafeMutableRawPointer!

    public init() {
        let rawSelf = Unmanaged.passUnretained(self).toOpaque()
        ptr = QVulkanWindowRenderer_new(rawSelf,
                                        QVulkanWindowRenderer.preInitResourcesThunk,
                                        QVulkanWindowRenderer.initResourcesThunk,
                                        QVulkanWindowRenderer.initSwapChainResourcesThunk,
                                        QVulkanWindowRenderer.releaseSwapChainResourcesThunk,
                                        QVulkanWindowRenderer.releaseResourcesThunk,
                                        QVulkanWindowRenderer.physicalDeviceLostThunk,
                                        QVulkanWindowRenderer.logicalDeviceLostThunk,
                                        QVulkanWindowRenderer.startNextFrameThunk)
    }

    deinit {
        guard ptr != nil else {
            return
        }
        QVulkanWindowRenderer_delete(ptr)
        ptr = nil
    }

    open func preInitResources() {
    }

    open func initResources() {
    }

    open func initSwapChainResources() {
    }

    open func releaseSwapChainResources() {
    }

    open func releaseResources() {
    }

    open func physicalDeviceLost() {
    }

    open func logicalDeviceLost() {
    }

    open func startNextFrame() {
    }

    private static let preInitResourcesThunk: @convention(c) (UnsafeMutableRawPointer?) -> Void = { raw in
        guard let raw else { return }
        let renderer = Unmanaged<QVulkanWindowRenderer>.fromOpaque(raw).takeUnretainedValue()
        renderer.preInitResources()
    }

    private static let initResourcesThunk: @convention(c) (UnsafeMutableRawPointer?) -> Void = { raw in
        guard let raw else { return }
        let renderer = Unmanaged<QVulkanWindowRenderer>.fromOpaque(raw).takeUnretainedValue()
        renderer.initResources()
    }

    private static let initSwapChainResourcesThunk: @convention(c) (UnsafeMutableRawPointer?) -> Void = { raw in
        guard let raw else { return }
        let renderer = Unmanaged<QVulkanWindowRenderer>.fromOpaque(raw).takeUnretainedValue()
        renderer.initSwapChainResources()
    }

    private static let releaseSwapChainResourcesThunk: @convention(c) (UnsafeMutableRawPointer?) -> Void = { raw in
        guard let raw else { return }
        let renderer = Unmanaged<QVulkanWindowRenderer>.fromOpaque(raw).takeUnretainedValue()
        renderer.releaseSwapChainResources()
    }

    private static let releaseResourcesThunk: @convention(c) (UnsafeMutableRawPointer?) -> Void = { raw in
        guard let raw else { return }
        let renderer = Unmanaged<QVulkanWindowRenderer>.fromOpaque(raw).takeUnretainedValue()
        renderer.releaseResources()
    }

    private static let physicalDeviceLostThunk: @convention(c) (UnsafeMutableRawPointer?) -> Void = { raw in
        guard let raw else { return }
        let renderer = Unmanaged<QVulkanWindowRenderer>.fromOpaque(raw).takeUnretainedValue()
        renderer.physicalDeviceLost()
    }

    private static let logicalDeviceLostThunk: @convention(c) (UnsafeMutableRawPointer?) -> Void = { raw in
        guard let raw else { return }
        let renderer = Unmanaged<QVulkanWindowRenderer>.fromOpaque(raw).takeUnretainedValue()
        renderer.logicalDeviceLost()
    }

    private static let startNextFrameThunk: @convention(c) (UnsafeMutableRawPointer?) -> Void = { raw in
        guard let raw else { return }
        let renderer = Unmanaged<QVulkanWindowRenderer>.fromOpaque(raw).takeUnretainedValue()
        renderer.startNextFrame()
    }
}
