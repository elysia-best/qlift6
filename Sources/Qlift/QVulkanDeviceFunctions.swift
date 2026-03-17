import CQlift

public class QVulkanDeviceFunctions {
    public var ptr: UnsafeMutableRawPointer!

    init(ptr: UnsafeMutableRawPointer) {
        self.ptr = ptr
    }

    public func deviceWaitIdle(device: UInt64) -> Int32 {
        QVulkanDeviceFunctions_vkDeviceWaitIdle(ptr, device)
    }

    public func queueWaitIdle(queue: UInt64) -> Int32 {
        QVulkanDeviceFunctions_vkQueueWaitIdle(ptr, queue)
    }

    public func resetCommandPool(device: UInt64, commandPool: UInt64, flags: Int32 = 0) -> Int32 {
        QVulkanDeviceFunctions_vkResetCommandPool(ptr, device, commandPool, flags)
    }
}
