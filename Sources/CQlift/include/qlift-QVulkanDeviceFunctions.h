#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

LIBRARY_API int QVulkanDeviceFunctions_vkDeviceWaitIdle(void *functions, unsigned long long device);
LIBRARY_API int QVulkanDeviceFunctions_vkQueueWaitIdle(void *functions, unsigned long long queue);
LIBRARY_API int QVulkanDeviceFunctions_vkResetCommandPool(void *functions,
                                                          unsigned long long device,
                                                          unsigned long long commandPool,
                                                          int flags);

#ifdef __cplusplus
}
#endif
