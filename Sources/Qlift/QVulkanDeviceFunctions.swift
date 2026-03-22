import CQlift
import Vulkan

@inline(__always)
private func qliftRawVkHandle<T>(_ vkHandle: T) -> UInt64 {
    unsafeBitCast(vkHandle, to: UInt64.self)
}

public class QVulkanDeviceFunctions {
    public var ptr: UnsafeMutableRawPointer!

    init(ptr: UnsafeMutableRawPointer) {
        self.ptr = ptr
    }

    public func deviceWaitIdle(device: VkDevice) -> Int32 {
        QVulkanDeviceFunctions_vkDeviceWaitIdle(ptr, qliftRawVkHandle(device))
    }

    public func queueWaitIdle(queue: VkQueue) -> Int32 {
        QVulkanDeviceFunctions_vkQueueWaitIdle(ptr, qliftRawVkHandle(queue))
    }

    public func resetCommandPool(device: VkDevice,
                                 commandPool: VkCommandPool,
                                 flags: Int32 = 0) -> Int32 {
        QVulkanDeviceFunctions_vkResetCommandPool(ptr,
                                                  qliftRawVkHandle(device),
                                                  qliftRawVkHandle(commandPool),
                                                  flags)
    }
}
