#include "qlift-QVulkanWindowRenderer.h"

#include <QVulkanWindow>

class QliftQVulkanWindowRenderer final : public QVulkanWindowRenderer {
public:
    QliftQVulkanWindowRenderer(void *ctx,
                               void (*preInitResourcesCb)(void *),
                               void (*initResourcesCb)(void *),
                               void (*initSwapChainResourcesCb)(void *),
                               void (*releaseSwapChainResourcesCb)(void *),
                               void (*releaseResourcesCb)(void *),
                               void (*physicalDeviceLostCb)(void *),
                               void (*logicalDeviceLostCb)(void *),
                               void (*startNextFrameCb)(void *))
        : context(ctx),
          preInitResourcesCallback(preInitResourcesCb),
          initResourcesCallback(initResourcesCb),
          initSwapChainResourcesCallback(initSwapChainResourcesCb),
          releaseSwapChainResourcesCallback(releaseSwapChainResourcesCb),
          releaseResourcesCallback(releaseResourcesCb),
          physicalDeviceLostCallback(physicalDeviceLostCb),
          logicalDeviceLostCallback(logicalDeviceLostCb),
          startNextFrameCallback(startNextFrameCb) {
    }

    void preInitResources() override {
        if (preInitResourcesCallback != nullptr) {
            preInitResourcesCallback(context);
        }
    }

    void initResources() override {
        if (initResourcesCallback != nullptr) {
            initResourcesCallback(context);
        }
    }

    void initSwapChainResources() override {
        if (initSwapChainResourcesCallback != nullptr) {
            initSwapChainResourcesCallback(context);
        }
    }

    void releaseSwapChainResources() override {
        if (releaseSwapChainResourcesCallback != nullptr) {
            releaseSwapChainResourcesCallback(context);
        }
    }

    void releaseResources() override {
        if (releaseResourcesCallback != nullptr) {
            releaseResourcesCallback(context);
        }
    }

    void physicalDeviceLost() override {
        if (physicalDeviceLostCallback != nullptr) {
            physicalDeviceLostCallback(context);
        }
    }

    void logicalDeviceLost() override {
        if (logicalDeviceLostCallback != nullptr) {
            logicalDeviceLostCallback(context);
        }
    }

    void startNextFrame() override {
        if (startNextFrameCallback != nullptr) {
            startNextFrameCallback(context);
        }
    }

private:
    void *context;
    void (*preInitResourcesCallback)(void *);
    void (*initResourcesCallback)(void *);
    void (*initSwapChainResourcesCallback)(void *);
    void (*releaseSwapChainResourcesCallback)(void *);
    void (*releaseResourcesCallback)(void *);
    void (*physicalDeviceLostCallback)(void *);
    void (*logicalDeviceLostCallback)(void *);
    void (*startNextFrameCallback)(void *);
};

[[maybe_unused]] void *QVulkanWindowRenderer_new(void *context,
                                                 void (*preInitResources)(void *),
                                                 void (*initResources)(void *),
                                                 void (*initSwapChainResources)(void *),
                                                 void (*releaseSwapChainResources)(void *),
                                                 void (*releaseResources)(void *),
                                                 void (*physicalDeviceLost)(void *),
                                                 void (*logicalDeviceLost)(void *),
                                                 void (*startNextFrame)(void *)) {
    return new QliftQVulkanWindowRenderer(context,
                                          preInitResources,
                                          initResources,
                                          initSwapChainResources,
                                          releaseSwapChainResources,
                                          releaseResources,
                                          physicalDeviceLost,
                                          logicalDeviceLost,
                                          startNextFrame);
}

[[maybe_unused]] void QVulkanWindowRenderer_delete(void *renderer) {
    delete static_cast<QVulkanWindowRenderer *>(renderer);
}
