#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma clang diagnostic ignored "-Wnullability-completeness"

LIBRARY_API void *QVulkanWindow_new(void * _Nullable parent);
LIBRARY_API int QVulkanWindow_MAX_CONCURRENT_FRAME_COUNT();
LIBRARY_API int QVulkanWindow_flags(void *window);
LIBRARY_API int QVulkanWindow_availablePhysicalDevicesSize(void *window);
LIBRARY_API CQString QVulkanWindow_availablePhysicalDeviceNameAt(void *window, int index);
LIBRARY_API unsigned int QVulkanWindow_availablePhysicalDeviceVendorIDAt(void *window, int index);
LIBRARY_API unsigned int QVulkanWindow_availablePhysicalDeviceDeviceIDAt(void *window, int index);
LIBRARY_API unsigned int QVulkanWindow_availablePhysicalDeviceDeviceTypeAt(void *window, int index);
LIBRARY_API unsigned int QVulkanWindow_availablePhysicalDeviceApiVersionAt(void *window, int index);
LIBRARY_API unsigned int QVulkanWindow_availablePhysicalDeviceDriverVersionAt(void *window, int index);
LIBRARY_API bool QVulkanWindow_hasPhysicalDeviceProperties(void *window);
LIBRARY_API bool QVulkanWindow_physicalDeviceProperties(void *window, void *outProperties);
LIBRARY_API CQString QVulkanWindow_physicalDevicePropertiesName(void *window);
LIBRARY_API unsigned int QVulkanWindow_physicalDevicePropertiesVendorID(void *window);
LIBRARY_API unsigned int QVulkanWindow_physicalDevicePropertiesDeviceID(void *window);
LIBRARY_API unsigned int QVulkanWindow_physicalDevicePropertiesDeviceType(void *window);
LIBRARY_API unsigned int QVulkanWindow_physicalDevicePropertiesApiVersion(void *window);
LIBRARY_API unsigned int QVulkanWindow_physicalDevicePropertiesDriverVersion(void *window);
LIBRARY_API int QVulkanWindow_supportedDeviceExtensionsSize(void *window);
LIBRARY_API CQString QVulkanWindow_supportedDeviceExtensionNameAt(void *window, int index);
LIBRARY_API unsigned int QVulkanWindow_supportedDeviceExtensionVersionAt(void *window, int index);
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
LIBRARY_API unsigned long long QVulkanWindow_graphicsCommandPool(void *window);
LIBRARY_API unsigned long long QVulkanWindow_currentCommandBuffer(void *window);
LIBRARY_API unsigned long long QVulkanWindow_currentFramebuffer(void *window);
LIBRARY_API unsigned long long QVulkanWindow_defaultRenderPass(void *window);
LIBRARY_API unsigned long long QVulkanWindow_depthStencilImage(void *window);
LIBRARY_API unsigned long long QVulkanWindow_depthStencilImageView(void *window);
LIBRARY_API unsigned long long QVulkanWindow_msaaColorImage(void *window, int idx);
LIBRARY_API unsigned long long QVulkanWindow_msaaColorImageView(void *window, int idx);
LIBRARY_API unsigned long long QVulkanWindow_swapChainImage(void *window, int idx);
LIBRARY_API unsigned long long QVulkanWindow_swapChainImageView(void *window, int idx);
LIBRARY_API unsigned int QVulkanWindow_deviceLocalMemoryIndex(void *window);
LIBRARY_API unsigned int QVulkanWindow_graphicsQueueFamilyIndex(void *window);
LIBRARY_API unsigned int QVulkanWindow_hostVisibleMemoryIndex(void *window);
LIBRARY_API bool QVulkanWindow_isValid(void *window);
LIBRARY_API bool QVulkanWindow_supportsGrab(void *window);
LIBRARY_API void *QVulkanWindow_grab(void *window);
LIBRARY_API void *QVulkanWindow_swapChainImageSize(void *window);

LIBRARY_API void QVulkanWindow_setRenderer(void *window, void *renderer);
LIBRARY_API void QVulkanWindow_setFlags(void *window, int flags);
LIBRARY_API void QVulkanWindow_setPhysicalDeviceIndex(void *window, int idx);
LIBRARY_API void QVulkanWindow_setSampleCount(void *window, int sampleCount);
LIBRARY_API void QVulkanWindow_setDeviceExtensions(void *window,
											const char * _Nullable const * _Nullable extensions,
											int count);
LIBRARY_API void QVulkanWindow_setPreferredColorFormats(void *window, const int * _Nullable formats, int count);
LIBRARY_API void QVulkanWindow_frameReady(void *window);

#ifdef __cplusplus
}
#endif
