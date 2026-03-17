import CQlift

public class QVulkanFunctions {
    public var ptr: UnsafeMutableRawPointer!

    init(ptr: UnsafeMutableRawPointer) {
        self.ptr = ptr
    }

    public func enumeratePhysicalDevices(instanceHandle: UInt64) -> (result: Int32, devices: [UInt64]) {
        var count: UInt32 = 0
        let firstResult = QVulkanFunctions_vkEnumeratePhysicalDevices(ptr, instanceHandle, &count, nil)
        guard firstResult == 0, count > 0 else {
            return (firstResult, [])
        }

        var devices = Array<UInt64>(repeating: 0, count: Int(count))
        let secondResult = devices.withUnsafeMutableBufferPointer { buffer in
            QVulkanFunctions_vkEnumeratePhysicalDevices(ptr, instanceHandle, &count, buffer.baseAddress)
        }
        if secondResult != 0 {
            return (secondResult, [])
        }
        return (secondResult, Array(devices.prefix(Int(count))))
    }
}
