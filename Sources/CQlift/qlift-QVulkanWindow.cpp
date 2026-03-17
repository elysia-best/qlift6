#include "qlift-QVulkanWindow.h"

#include <QImage>
#include <QVulkanWindow>

#include <cstdint>
#include <type_traits>

namespace {

template <typename T>
unsigned long long vkHandleToULL(T handle) {
    if constexpr (std::is_pointer_v<T>) {
        return static_cast<unsigned long long>(reinterpret_cast<std::uintptr_t>(handle));
    } else {
        return static_cast<unsigned long long>(handle);
    }
}

class QliftQVulkanWindow final : public QVulkanWindow {
public:
    explicit QliftQVulkanWindow(QWindow *parent = nullptr)
        : QVulkanWindow(parent) {
    }

    ~QliftQVulkanWindow() override {
        if (renderer != nullptr) {
            delete renderer;
            renderer = nullptr;
        }
    }

    void setRenderer(QVulkanWindowRenderer *newRenderer) {
        if (renderer != nullptr) {
            delete renderer;
        }
        renderer = newRenderer;
    }

    QVulkanWindowRenderer *createRenderer() override {
        auto out = renderer;
        renderer = nullptr;
        return out;
    }

private:
    QVulkanWindowRenderer *renderer = nullptr;
};

}

[[maybe_unused]] void *QVulkanWindow_new(void * _Nullable parent) {
    return new QliftQVulkanWindow(static_cast<QWindow *>(parent));
}

[[maybe_unused]] int QVulkanWindow_flags(void *window) {
    return static_cast<QVulkanWindow *>(window)->flags();
}

[[maybe_unused]] int QVulkanWindow_colorFormat(void *window) {
    return static_cast<QVulkanWindow *>(window)->colorFormat();
}

[[maybe_unused]] int QVulkanWindow_depthStencilFormat(void *window) {
    return static_cast<QVulkanWindow *>(window)->depthStencilFormat();
}

[[maybe_unused]] int QVulkanWindow_sampleCountFlagBits(void *window) {
    return static_cast<QVulkanWindow *>(window)->sampleCountFlagBits();
}

[[maybe_unused]] int QVulkanWindow_concurrentFrameCount(void *window) {
    return static_cast<QVulkanWindow *>(window)->concurrentFrameCount();
}

[[maybe_unused]] int QVulkanWindow_currentFrame(void *window) {
    return static_cast<QVulkanWindow *>(window)->currentFrame();
}

[[maybe_unused]] int QVulkanWindow_currentSwapChainImageIndex(void *window) {
    return static_cast<QVulkanWindow *>(window)->currentSwapChainImageIndex();
}

[[maybe_unused]] int QVulkanWindow_swapChainImageCount(void *window) {
    return static_cast<QVulkanWindow *>(window)->swapChainImageCount();
}

[[maybe_unused]] int QVulkanWindow_supportedSampleCountsSize(void *window) {
    return static_cast<QVulkanWindow *>(window)->supportedSampleCounts().size();
}

[[maybe_unused]] int QVulkanWindow_supportedSampleCountAt(void *window, int index) {
    const auto counts = static_cast<QVulkanWindow *>(window)->supportedSampleCounts();
    if (index < 0 || index >= counts.size()) {
        return 0;
    }
    return counts[index];
}

[[maybe_unused]] unsigned long long QVulkanWindow_device(void *window) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->device());
}

[[maybe_unused]] unsigned long long QVulkanWindow_physicalDevice(void *window) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->physicalDevice());
}

[[maybe_unused]] unsigned long long QVulkanWindow_graphicsQueue(void *window) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->graphicsQueue());
}

[[maybe_unused]] unsigned long long QVulkanWindow_currentCommandBuffer(void *window) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->currentCommandBuffer());
}

[[maybe_unused]] unsigned long long QVulkanWindow_currentFramebuffer(void *window) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->currentFramebuffer());
}

[[maybe_unused]] unsigned long long QVulkanWindow_defaultRenderPass(void *window) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->defaultRenderPass());
}

[[maybe_unused]] bool QVulkanWindow_isValid(void *window) {
    return static_cast<QVulkanWindow *>(window)->isValid();
}

[[maybe_unused]] bool QVulkanWindow_supportsGrab(void *window) {
    return static_cast<QVulkanWindow *>(window)->supportsGrab();
}

[[maybe_unused]] void *QVulkanWindow_grab(void *window) {
    auto image = static_cast<QVulkanWindow *>(window)->grab();
    return new QImage(image);
}

[[maybe_unused]] void *QVulkanWindow_swapChainImageSize(void *window) {
    auto size = static_cast<QVulkanWindow *>(window)->swapChainImageSize();
    return new QSize(size);
}

[[maybe_unused]] void QVulkanWindow_setRenderer(void *window, void *renderer) {
    auto qvWindow = static_cast<QVulkanWindow *>(window);
    auto swiftWindow = dynamic_cast<QliftQVulkanWindow *>(qvWindow);
    if (swiftWindow != nullptr) {
        swiftWindow->setRenderer(static_cast<QVulkanWindowRenderer *>(renderer));
    }
}

[[maybe_unused]] void QVulkanWindow_setFlags(void *window, int flags) {
    static_cast<QVulkanWindow *>(window)->setFlags(static_cast<QVulkanWindow::Flags>(flags));
}

[[maybe_unused]] void QVulkanWindow_setPhysicalDeviceIndex(void *window, int idx) {
    static_cast<QVulkanWindow *>(window)->setPhysicalDeviceIndex(idx);
}

[[maybe_unused]] void QVulkanWindow_setSampleCount(void *window, int sampleCount) {
    static_cast<QVulkanWindow *>(window)->setSampleCount(sampleCount);
}

[[maybe_unused]] void QVulkanWindow_setPreferredColorFormats(void *window, const int * _Nullable formats, int count) {
    QList<VkFormat> preferredFormats;
    preferredFormats.reserve(count);
    for (int i = 0; i < count; ++i) {
        preferredFormats.append(static_cast<VkFormat>(formats[i]));
    }
    static_cast<QVulkanWindow *>(window)->setPreferredColorFormats(preferredFormats);
}

[[maybe_unused]] void QVulkanWindow_frameReady(void *window) {
    static_cast<QVulkanWindow *>(window)->frameReady();
}
