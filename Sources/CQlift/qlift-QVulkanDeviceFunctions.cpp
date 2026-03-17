#include "qlift-QVulkanDeviceFunctions.h"

#include <QVulkanDeviceFunctions>

#include <cstdint>
#include <type_traits>

namespace {

template <typename T>
T ullToVkHandle(unsigned long long value) {
    if constexpr (std::is_pointer_v<T>) {
        return reinterpret_cast<T>(static_cast<std::uintptr_t>(value));
    } else {
        return static_cast<T>(value);
    }
}

}

[[maybe_unused]] int QVulkanDeviceFunctions_vkDeviceWaitIdle(void *functions, unsigned long long device) {
    return static_cast<QVulkanDeviceFunctions *>(functions)->vkDeviceWaitIdle(ullToVkHandle<VkDevice>(device));
}

[[maybe_unused]] int QVulkanDeviceFunctions_vkQueueWaitIdle(void *functions, unsigned long long queue) {
    return static_cast<QVulkanDeviceFunctions *>(functions)->vkQueueWaitIdle(ullToVkHandle<VkQueue>(queue));
}

[[maybe_unused]] int QVulkanDeviceFunctions_vkResetCommandPool(void *functions,
                                                               unsigned long long device,
                                                               unsigned long long commandPool,
                                                               int flags) {
    return static_cast<QVulkanDeviceFunctions *>(functions)->vkResetCommandPool(
        ullToVkHandle<VkDevice>(device),
        ullToVkHandle<VkCommandPool>(commandPool),
        static_cast<VkCommandPoolResetFlags>(flags));
}
