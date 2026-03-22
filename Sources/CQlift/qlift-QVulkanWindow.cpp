#include "qlift-QVulkanWindow.h"

#include <QImage>
#include <QString>
#include <QVulkanWindow>

#include <cstdint>
#include <type_traits>

namespace {

static CQString toCQString(const QByteArray &text) {
    thread_local QString str;
    str = QString::fromLatin1(text);
    return CQString { str.utf16(), str.size() };
}

static CQString toCQString(const QString &text) {
    return CQString { text.utf16(), text.size() };
}

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

[[maybe_unused]] int QVulkanWindow_MAX_CONCURRENT_FRAME_COUNT() {
    return QVulkanWindow::MAX_CONCURRENT_FRAME_COUNT;
}

[[maybe_unused]] int QVulkanWindow_flags(void *window) {
    return static_cast<QVulkanWindow *>(window)->flags();
}

[[maybe_unused]] int QVulkanWindow_availablePhysicalDevicesSize(void *window) {
    return static_cast<QVulkanWindow *>(window)->availablePhysicalDevices().size();
}

[[maybe_unused]] CQString QVulkanWindow_availablePhysicalDeviceNameAt(void *window, int index) {
    const auto list = static_cast<QVulkanWindow *>(window)->availablePhysicalDevices();
    if (index < 0 || index >= list.size()) {
        return CQString { nullptr, 0 };
    }
    return toCQString(QString::fromUtf8(list[index].deviceName));
}

[[maybe_unused]] unsigned int QVulkanWindow_availablePhysicalDeviceVendorIDAt(void *window, int index) {
    const auto list = static_cast<QVulkanWindow *>(window)->availablePhysicalDevices();
    if (index < 0 || index >= list.size()) {
        return 0;
    }
    return list[index].vendorID;
}

[[maybe_unused]] unsigned int QVulkanWindow_availablePhysicalDeviceDeviceIDAt(void *window, int index) {
    const auto list = static_cast<QVulkanWindow *>(window)->availablePhysicalDevices();
    if (index < 0 || index >= list.size()) {
        return 0;
    }
    return list[index].deviceID;
}

[[maybe_unused]] unsigned int QVulkanWindow_availablePhysicalDeviceDeviceTypeAt(void *window, int index) {
    const auto list = static_cast<QVulkanWindow *>(window)->availablePhysicalDevices();
    if (index < 0 || index >= list.size()) {
        return 0;
    }
    return list[index].deviceType;
}

[[maybe_unused]] unsigned int QVulkanWindow_availablePhysicalDeviceApiVersionAt(void *window, int index) {
    const auto list = static_cast<QVulkanWindow *>(window)->availablePhysicalDevices();
    if (index < 0 || index >= list.size()) {
        return 0;
    }
    return list[index].apiVersion;
}

[[maybe_unused]] unsigned int QVulkanWindow_availablePhysicalDeviceDriverVersionAt(void *window, int index) {
    const auto list = static_cast<QVulkanWindow *>(window)->availablePhysicalDevices();
    if (index < 0 || index >= list.size()) {
        return 0;
    }
    return list[index].driverVersion;
}

[[maybe_unused]] int QVulkanWindow_supportedDeviceExtensionsSize(void *window) {
    return static_cast<QVulkanWindow *>(window)->supportedDeviceExtensions().size();
}

[[maybe_unused]] CQString QVulkanWindow_supportedDeviceExtensionNameAt(void *window, int index) {
    const auto list = static_cast<QVulkanWindow *>(window)->supportedDeviceExtensions();
    if (index < 0 || index >= list.size()) {
        return CQString { nullptr, 0 };
    }
    return toCQString(list[index].name);
}

[[maybe_unused]] unsigned int QVulkanWindow_supportedDeviceExtensionVersionAt(void *window, int index) {
    const auto list = static_cast<QVulkanWindow *>(window)->supportedDeviceExtensions();
    if (index < 0 || index >= list.size()) {
        return 0;
    }
    return list[index].version;
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

[[maybe_unused]] unsigned long long QVulkanWindow_graphicsCommandPool(void *window) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->graphicsCommandPool());
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

[[maybe_unused]] unsigned long long QVulkanWindow_depthStencilImage(void *window) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->depthStencilImage());
}

[[maybe_unused]] unsigned long long QVulkanWindow_depthStencilImageView(void *window) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->depthStencilImageView());
}

[[maybe_unused]] unsigned long long QVulkanWindow_msaaColorImage(void *window, int idx) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->msaaColorImage(idx));
}

[[maybe_unused]] unsigned long long QVulkanWindow_msaaColorImageView(void *window, int idx) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->msaaColorImageView(idx));
}

[[maybe_unused]] unsigned long long QVulkanWindow_swapChainImage(void *window, int idx) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->swapChainImage(idx));
}

[[maybe_unused]] unsigned long long QVulkanWindow_swapChainImageView(void *window, int idx) {
    return vkHandleToULL(static_cast<QVulkanWindow *>(window)->swapChainImageView(idx));
}

[[maybe_unused]] unsigned int QVulkanWindow_deviceLocalMemoryIndex(void *window) {
    return static_cast<QVulkanWindow *>(window)->deviceLocalMemoryIndex();
}

[[maybe_unused]] unsigned int QVulkanWindow_graphicsQueueFamilyIndex(void *window) {
    return static_cast<QVulkanWindow *>(window)->graphicsQueueFamilyIndex();
}

[[maybe_unused]] unsigned int QVulkanWindow_hostVisibleMemoryIndex(void *window) {
    return static_cast<QVulkanWindow *>(window)->hostVisibleMemoryIndex();
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

[[maybe_unused]] void QVulkanWindow_setDeviceExtensions(void *window,
                                                        const char *const *extensions,
                                                        int count) {
    QByteArrayList list;
    list.reserve(count > 0 ? count : 0);
    for (int i = 0; i < count; ++i) {
        if (extensions != nullptr && extensions[i] != nullptr) {
            list.append(QByteArray(extensions[i]));
        }
    }
    static_cast<QVulkanWindow *>(window)->setDeviceExtensions(list);
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
