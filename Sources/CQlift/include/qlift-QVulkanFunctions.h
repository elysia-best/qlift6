#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

LIBRARY_API int QVulkanFunctions_vkEnumeratePhysicalDevices(void *functions,
                                                             unsigned long long instance,
                                                             unsigned int *count,
                                                             unsigned long long * _Nullable physicalDevices);
LIBRARY_API void QVulkanFunctions_vkGetPhysicalDeviceProperties(void *functions,
                                                                unsigned long long physicalDevice,
                                                                void *properties);
LIBRARY_API void QVulkanFunctions_vkGetPhysicalDeviceQueueFamilyProperties(void *functions,
                                                                           unsigned long long physicalDevice,
                                                                           unsigned int *count,
                                                                           void * _Nullable queueFamilyProperties);

#ifdef __cplusplus
}
#endif
