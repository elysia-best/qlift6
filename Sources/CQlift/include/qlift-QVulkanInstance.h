#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma clang diagnostic ignored "-Wnullability-completeness"

LIBRARY_API void *QVulkanInstance_new();
LIBRARY_API void QVulkanInstance_delete(void *instance);

LIBRARY_API int QVulkanInstance_flags(void *instance);
LIBRARY_API int QVulkanInstance_errorCode(void *instance);
LIBRARY_API bool QVulkanInstance_create(void *instance);
LIBRARY_API bool QVulkanInstance_isValid(void *instance);
LIBRARY_API int QVulkanInstance_apiVersionMajor(void *instance);
LIBRARY_API int QVulkanInstance_apiVersionMinor(void *instance);
LIBRARY_API int QVulkanInstance_apiVersionMicro(void *instance);
LIBRARY_API int QVulkanInstance_supportedApiVersionMajor(void *instance);
LIBRARY_API int QVulkanInstance_supportedApiVersionMinor(void *instance);
LIBRARY_API int QVulkanInstance_supportedApiVersionMicro(void *instance);
LIBRARY_API void *QliftQVulkanInstance_functions(void *instance);
LIBRARY_API void *QliftQVulkanInstance_deviceFunctions(void *instance, unsigned long long device);
LIBRARY_API unsigned long long QVulkanInstance_vkInstance(void *instance);
LIBRARY_API unsigned long long QVulkanInstance_getInstanceProcAddr(void *instance, const char *name);

LIBRARY_API int QVulkanInstance_supportedExtensionsSize(void *instance);
LIBRARY_API CQString QVulkanInstance_supportedExtensionNameAt(void *instance, int index);
LIBRARY_API unsigned int QVulkanInstance_supportedExtensionVersionAt(void *instance, int index);
LIBRARY_API bool QVulkanInstance_supportedExtensionsContains(void *instance, const char *name);
LIBRARY_API bool QVulkanInstance_supportedExtensionsContainsMinVersion(void *instance, const char *name, int minVersion);
LIBRARY_API int QVulkanInstance_extensionsSize(void *instance);
LIBRARY_API CQString QVulkanInstance_extensionAt(void *instance, int index);
LIBRARY_API void QVulkanInstance_setExtensions(void *instance,
											   const char * _Nullable const * _Nullable extensions,
											   int count);

LIBRARY_API int QVulkanInstance_supportedLayersSize(void *instance);
LIBRARY_API CQString QVulkanInstance_supportedLayerNameAt(void *instance, int index);
LIBRARY_API CQString QVulkanInstance_supportedLayerDescriptionAt(void *instance, int index);
LIBRARY_API unsigned int QVulkanInstance_supportedLayerVersionAt(void *instance, int index);
LIBRARY_API CQString QVulkanInstance_supportedLayerSpecVersionAt(void *instance, int index);
LIBRARY_API bool QVulkanInstance_supportedLayersContains(void *instance, const char *name);
LIBRARY_API bool QVulkanInstance_supportedLayersContainsMinVersion(void *instance, const char *name, int minVersion);
LIBRARY_API int QVulkanInstance_layersSize(void *instance);
LIBRARY_API CQString QVulkanInstance_layerAt(void *instance, int index);
LIBRARY_API void QVulkanInstance_setLayers(void *instance,
										   const char * _Nullable const * _Nullable layers,
										   int count);

LIBRARY_API void QVulkanInstance_destroy(void *instance);
LIBRARY_API void QVulkanInstance_setFlags(void *instance, int flags);
LIBRARY_API void QVulkanInstance_setApiVersion(void *instance, int major, int minor, int micro);
LIBRARY_API void QVulkanInstance_setVkInstance(void *instance, unsigned long long existingVkInstance);
LIBRARY_API void QVulkanInstance_resetDeviceFunctions(void *instance, unsigned long long device);
LIBRARY_API void QVulkanInstance_presentAboutToBeQueued(void *instance, void *window);
LIBRARY_API void QVulkanInstance_presentQueued(void *instance, void *window);
LIBRARY_API bool QVulkanInstance_supportsPresent(void *instance,
												 unsigned long long physicalDevice,
												 unsigned int queueFamilyIndex,
												 void *window);
LIBRARY_API unsigned long long QVulkanInstance_surfaceForWindow(void *window);

#ifdef __cplusplus
}
#endif
