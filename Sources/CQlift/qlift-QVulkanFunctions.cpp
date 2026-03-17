#include "qlift-QVulkanFunctions.h"

#include <QVulkanFunctions>

#include <cstdint>
#include <type_traits>
#include <vector>

namespace {

template <typename T>
unsigned long long vkHandleToULL(T handle) {
    if constexpr (std::is_pointer_v<T>) {
        return static_cast<unsigned long long>(reinterpret_cast<std::uintptr_t>(handle));
    } else {
        return static_cast<unsigned long long>(handle);
    }
}

template <typename T>
T ullToVkHandle(unsigned long long value) {
    if constexpr (std::is_pointer_v<T>) {
        return reinterpret_cast<T>(static_cast<std::uintptr_t>(value));
    } else {
        return static_cast<T>(value);
    }
}

}

[[maybe_unused]] int QVulkanFunctions_vkEnumeratePhysicalDevices(void *functions,
                                                                  unsigned long long instance,
                                                                  unsigned int *count,
                                                                  unsigned long long * _Nullable physicalDevices) {
    auto f = static_cast<QVulkanFunctions *>(functions);
    if (physicalDevices == nullptr) {
        return f->vkEnumeratePhysicalDevices(ullToVkHandle<VkInstance>(instance), count, nullptr);
    }

    std::vector<VkPhysicalDevice> devices(*count);
    const auto result = f->vkEnumeratePhysicalDevices(ullToVkHandle<VkInstance>(instance), count, devices.data());
    for (unsigned int i = 0; i < *count; ++i) {
        physicalDevices[i] = vkHandleToULL(devices[i]);
    }
    return result;
}

[[maybe_unused]] void QVulkanFunctions_vkGetPhysicalDeviceProperties(void *functions,
                                                                     unsigned long long physicalDevice,
                                                                     void *properties) {
    static_cast<QVulkanFunctions *>(functions)->vkGetPhysicalDeviceProperties(
        ullToVkHandle<VkPhysicalDevice>(physicalDevice),
        static_cast<VkPhysicalDeviceProperties *>(properties));
}

[[maybe_unused]] void QVulkanFunctions_vkGetPhysicalDeviceQueueFamilyProperties(void *functions,
                                                                                 unsigned long long physicalDevice,
                                                                                 unsigned int *count,
                                                                                 void * _Nullable queueFamilyProperties) {
    static_cast<QVulkanFunctions *>(functions)->vkGetPhysicalDeviceQueueFamilyProperties(
        ullToVkHandle<VkPhysicalDevice>(physicalDevice),
        count,
        static_cast<VkQueueFamilyProperties *>(queueFamilyProperties));
}
