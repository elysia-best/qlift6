#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma clang diagnostic ignored "-Wnullability-completeness"

LIBRARY_API void *QVulkanWindow_new(void * _Nullable parent);
LIBRARY_API int QVulkanWindow_flags(void *window);
LIBRARY_API int QVulkanWindow_colorFormat(void *window);
LIBRARY_API int QVulkanWindow_depthStencilFormat(void *window);
LIBRARY_API int QVulkanWindow_sampleCountFlagBits(void *window);
LIBRARY_API int QVulkanWindow_concurrentFrameCount(void *window);
LIBRARY_API int QVulkanWindow_currentFrame(void *window);
LIBRARY_API int QVulkanWindow_currentSwapChainImageIndex(void *window);
LIBRARY_API int QVulkanWindow_swapChainImageCount(void *window);
LIBRARY_API int QVulkanWindow_supportedSampleCountsSize(void *window);
LIBRARY_API int QVulkanWindow_supportedSampleCountAt(void *window, int index);
LIBRARY_API unsigned long long QVulkanWindow_device(void *window);
LIBRARY_API unsigned long long QVulkanWindow_physicalDevice(void *window);
LIBRARY_API unsigned long long QVulkanWindow_graphicsQueue(void *window);
LIBRARY_API unsigned long long QVulkanWindow_currentCommandBuffer(void *window);
LIBRARY_API unsigned long long QVulkanWindow_currentFramebuffer(void *window);
LIBRARY_API unsigned long long QVulkanWindow_defaultRenderPass(void *window);
LIBRARY_API bool QVulkanWindow_isValid(void *window);
LIBRARY_API bool QVulkanWindow_supportsGrab(void *window);
LIBRARY_API void *QVulkanWindow_grab(void *window);
LIBRARY_API void *QVulkanWindow_swapChainImageSize(void *window);

LIBRARY_API void QVulkanWindow_setRenderer(void *window, void *renderer);
LIBRARY_API void QVulkanWindow_setFlags(void *window, int flags);
LIBRARY_API void QVulkanWindow_setPhysicalDeviceIndex(void *window, int idx);
LIBRARY_API void QVulkanWindow_setSampleCount(void *window, int sampleCount);
LIBRARY_API void QVulkanWindow_setPreferredColorFormats(void *window, const int * _Nullable formats, int count);
LIBRARY_API void QVulkanWindow_frameReady(void *window);

#ifdef __cplusplus
}
#endif
