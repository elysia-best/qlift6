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
LIBRARY_API void *QliftQVulkanInstance_functions(void *instance);
LIBRARY_API void *QliftQVulkanInstance_deviceFunctions(void *instance, unsigned long long device);

LIBRARY_API int QVulkanInstance_supportedExtensionsSize(void *instance);
LIBRARY_API CQString QVulkanInstance_supportedExtensionNameAt(void *instance, int index);
LIBRARY_API unsigned int QVulkanInstance_supportedExtensionVersionAt(void *instance, int index);
LIBRARY_API bool QVulkanInstance_supportedExtensionsContains(void *instance, const char *name);
LIBRARY_API bool QVulkanInstance_supportedExtensionsContainsMinVersion(void *instance, const char *name, int minVersion);

LIBRARY_API int QVulkanInstance_supportedLayersSize(void *instance);
LIBRARY_API CQString QVulkanInstance_supportedLayerNameAt(void *instance, int index);
LIBRARY_API CQString QVulkanInstance_supportedLayerDescriptionAt(void *instance, int index);
LIBRARY_API unsigned int QVulkanInstance_supportedLayerVersionAt(void *instance, int index);
LIBRARY_API CQString QVulkanInstance_supportedLayerSpecVersionAt(void *instance, int index);
LIBRARY_API bool QVulkanInstance_supportedLayersContains(void *instance, const char *name);
LIBRARY_API bool QVulkanInstance_supportedLayersContainsMinVersion(void *instance, const char *name, int minVersion);

LIBRARY_API void QVulkanInstance_destroy(void *instance);
LIBRARY_API void QVulkanInstance_setFlags(void *instance, int flags);

#ifdef __cplusplus
}
#endif
