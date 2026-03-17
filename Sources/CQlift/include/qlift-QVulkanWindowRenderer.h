#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

LIBRARY_API void *QVulkanWindowRenderer_new(void *context,
                                            void (*preInitResources)(void *),
                                            void (*initResources)(void *),
                                            void (*initSwapChainResources)(void *),
                                            void (*releaseSwapChainResources)(void *),
                                            void (*releaseResources)(void *),
                                            void (*physicalDeviceLost)(void *),
                                            void (*logicalDeviceLost)(void *),
                                            void (*startNextFrame)(void *));
LIBRARY_API void QVulkanWindowRenderer_delete(void *renderer);

#ifdef __cplusplus
}
#endif
