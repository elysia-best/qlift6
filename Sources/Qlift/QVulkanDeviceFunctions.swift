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

    public func deviceWaitIdle(device: UInt64) -> Int32 {
        QVulkanDeviceFunctions_vkDeviceWaitIdle(ptr, device)
    }

    public func deviceWaitIdle(device: VkDevice) -> Int32 {
        deviceWaitIdle(device: qliftRawVkHandle(device))
    }

    public func queueWaitIdle(queue: UInt64) -> Int32 {
        QVulkanDeviceFunctions_vkQueueWaitIdle(ptr, queue)
    }

    public func queueWaitIdle(queue: VkQueue) -> Int32 {
        queueWaitIdle(queue: qliftRawVkHandle(queue))
    }

    public func resetCommandPool(device: UInt64, commandPool: UInt64, flags: Int32 = 0) -> Int32 {
        QVulkanDeviceFunctions_vkResetCommandPool(ptr, device, commandPool, flags)
    }

    public func resetCommandPool(device: VkDevice,
                                 commandPool: VkCommandPool,
                                 flags: Int32 = 0) -> Int32 {
        resetCommandPool(device: qliftRawVkHandle(device),
                         commandPool: qliftRawVkHandle(commandPool),
                         flags: flags)
    }
}
