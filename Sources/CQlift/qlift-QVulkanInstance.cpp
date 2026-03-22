#include "qlift-QVulkanInstance.h"
#include <QVulkanInstance>

#include <QString>

namespace {

static CQString toCQString(const QByteArray &text) {
    thread_local QString str;
    str = QString::fromLatin1(text);
    return CQString { str.utf16(), str.size() };
}

static CQString toCQString(const QString &text) {
    return CQString { text.utf16(), text.size() };
}

}

[[maybe_unused]] void *QVulkanInstance_new() {
    return new QVulkanInstance();
}

[[maybe_unused]] void QVulkanInstance_delete(void *instance) {
    delete static_cast<QVulkanInstance *>(instance);
}

[[maybe_unused]] int QVulkanInstance_flags(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->flags();
}

[[maybe_unused]] int QVulkanInstance_errorCode(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->errorCode();
}

[[maybe_unused]] bool QVulkanInstance_create(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->create();
}

[[maybe_unused]] bool QVulkanInstance_isValid(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->isValid();
}

[[maybe_unused]] int QVulkanInstance_apiVersionMajor(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->apiVersion().majorVersion();
}

[[maybe_unused]] int QVulkanInstance_apiVersionMinor(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->apiVersion().minorVersion();
}

[[maybe_unused]] int QVulkanInstance_apiVersionMicro(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->apiVersion().microVersion();
}

[[maybe_unused]] int QVulkanInstance_supportedApiVersionMajor(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->supportedApiVersion().majorVersion();
}

[[maybe_unused]] int QVulkanInstance_supportedApiVersionMinor(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->supportedApiVersion().minorVersion();
}

[[maybe_unused]] int QVulkanInstance_supportedApiVersionMicro(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->supportedApiVersion().microVersion();
}

[[maybe_unused]] void *QliftQVulkanInstance_functions(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->functions();
}

[[maybe_unused]] void *QliftQVulkanInstance_deviceFunctions(void *instance, unsigned long long device) {
    return static_cast<QVulkanInstance *>(instance)->deviceFunctions(reinterpret_cast<VkDevice>(device));
}

[[maybe_unused]] unsigned long long QVulkanInstance_vkInstance(void *instance) {
    return reinterpret_cast<unsigned long long>(static_cast<QVulkanInstance *>(instance)->vkInstance());
}

[[maybe_unused]] unsigned long long QVulkanInstance_getInstanceProcAddr(void *instance, const char *name) {
    return reinterpret_cast<unsigned long long>(
        static_cast<QVulkanInstance *>(instance)->getInstanceProcAddr(name));
}

[[maybe_unused]] int QVulkanInstance_supportedExtensionsSize(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->supportedExtensions().size();
}

[[maybe_unused]] CQString QVulkanInstance_supportedExtensionNameAt(void *instance, int index) {
    const auto list = static_cast<QVulkanInstance *>(instance)->supportedExtensions();
    if (index < 0 || index >= list.size()) {
        return CQString { nullptr, 0 };
    }
    return toCQString(list[index].name);
}

[[maybe_unused]] unsigned int QVulkanInstance_supportedExtensionVersionAt(void *instance, int index) {
    const auto list = static_cast<QVulkanInstance *>(instance)->supportedExtensions();
    if (index < 0 || index >= list.size()) {
        return 0;
    }
    return list[index].version;
}

[[maybe_unused]] bool QVulkanInstance_supportedExtensionsContains(void *instance, const char *name) {
    return static_cast<QVulkanInstance *>(instance)->supportedExtensions().contains(QByteArray(name));
}

[[maybe_unused]] bool QVulkanInstance_supportedExtensionsContainsMinVersion(void *instance, const char *name, int minVersion) {
    return static_cast<QVulkanInstance *>(instance)->supportedExtensions().contains(QByteArray(name), minVersion);
}

[[maybe_unused]] int QVulkanInstance_extensionsSize(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->extensions().size();
}

[[maybe_unused]] CQString QVulkanInstance_extensionAt(void *instance, int index) {
    const auto list = static_cast<QVulkanInstance *>(instance)->extensions();
    if (index < 0 || index >= list.size()) {
        return CQString { nullptr, 0 };
    }
    return toCQString(list[index]);
}

[[maybe_unused]] void QVulkanInstance_setExtensions(void *instance,
                                                    const char *const *extensions,
                                                    int count) {
    QByteArrayList list;
    list.reserve(count > 0 ? count : 0);
    for (int i = 0; i < count; ++i) {
        if (extensions != nullptr && extensions[i] != nullptr) {
            list.append(QByteArray(extensions[i]));
        }
    }
    static_cast<QVulkanInstance *>(instance)->setExtensions(list);
}

[[maybe_unused]] int QVulkanInstance_supportedLayersSize(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->supportedLayers().size();
}

[[maybe_unused]] CQString QVulkanInstance_supportedLayerNameAt(void *instance, int index) {
    const auto list = static_cast<QVulkanInstance *>(instance)->supportedLayers();
    if (index < 0 || index >= list.size()) {
        return CQString { nullptr, 0 };
    }
    return toCQString(list[index].name);
}

[[maybe_unused]] CQString QVulkanInstance_supportedLayerDescriptionAt(void *instance, int index) {
    const auto list = static_cast<QVulkanInstance *>(instance)->supportedLayers();
    if (index < 0 || index >= list.size()) {
        return CQString { nullptr, 0 };
    }
    return toCQString(list[index].description);
}

[[maybe_unused]] unsigned int QVulkanInstance_supportedLayerVersionAt(void *instance, int index) {
    const auto list = static_cast<QVulkanInstance *>(instance)->supportedLayers();
    if (index < 0 || index >= list.size()) {
        return 0;
    }
    return list[index].version;
}

[[maybe_unused]] CQString QVulkanInstance_supportedLayerSpecVersionAt(void *instance, int index) {
    const auto list = static_cast<QVulkanInstance *>(instance)->supportedLayers();
    if (index < 0 || index >= list.size()) {
        return CQString { nullptr, 0 };
    }
    return toCQString(list[index].specVersion.toString());
}

[[maybe_unused]] bool QVulkanInstance_supportedLayersContains(void *instance, const char *name) {
    return static_cast<QVulkanInstance *>(instance)->supportedLayers().contains(QByteArray(name));
}

[[maybe_unused]] bool QVulkanInstance_supportedLayersContainsMinVersion(void *instance, const char *name, int minVersion) {
    return static_cast<QVulkanInstance *>(instance)->supportedLayers().contains(QByteArray(name), minVersion);
}

[[maybe_unused]] int QVulkanInstance_layersSize(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->layers().size();
}

[[maybe_unused]] CQString QVulkanInstance_layerAt(void *instance, int index) {
    const auto list = static_cast<QVulkanInstance *>(instance)->layers();
    if (index < 0 || index >= list.size()) {
        return CQString { nullptr, 0 };
    }
    return toCQString(list[index]);
}

[[maybe_unused]] void QVulkanInstance_setLayers(void *instance,
                                                const char *const *layers,
                                                int count) {
    QByteArrayList list;
    list.reserve(count > 0 ? count : 0);
    for (int i = 0; i < count; ++i) {
        if (layers != nullptr && layers[i] != nullptr) {
            list.append(QByteArray(layers[i]));
        }
    }
    static_cast<QVulkanInstance *>(instance)->setLayers(list);
}

[[maybe_unused]] void QVulkanInstance_destroy(void *instance) {
    static_cast<QVulkanInstance *>(instance)->destroy();
}

[[maybe_unused]] void QVulkanInstance_setFlags(void *instance, int flags) {
    static_cast<QVulkanInstance *>(instance)->setFlags(static_cast<QVulkanInstance::Flags>(flags));
}

[[maybe_unused]] void QVulkanInstance_setApiVersion(void *instance, int major, int minor, int micro) {
    static_cast<QVulkanInstance *>(instance)->setApiVersion(QVersionNumber(major, minor, micro));
}

[[maybe_unused]] void QVulkanInstance_setVkInstance(void *instance, unsigned long long existingVkInstance) {
    static_cast<QVulkanInstance *>(instance)->setVkInstance(reinterpret_cast<VkInstance>(existingVkInstance));
}

[[maybe_unused]] void QVulkanInstance_resetDeviceFunctions(void *instance, unsigned long long device) {
    static_cast<QVulkanInstance *>(instance)->resetDeviceFunctions(reinterpret_cast<VkDevice>(device));
}

[[maybe_unused]] void QVulkanInstance_presentAboutToBeQueued(void *instance, void *window) {
    static_cast<QVulkanInstance *>(instance)->presentAboutToBeQueued(static_cast<QWindow *>(window));
}

[[maybe_unused]] void QVulkanInstance_presentQueued(void *instance, void *window) {
    static_cast<QVulkanInstance *>(instance)->presentQueued(static_cast<QWindow *>(window));
}

[[maybe_unused]] bool QVulkanInstance_supportsPresent(void *instance,
                                                      unsigned long long physicalDevice,
                                                      unsigned int queueFamilyIndex,
                                                      void *window) {
    return static_cast<QVulkanInstance *>(instance)->supportsPresent(
        reinterpret_cast<VkPhysicalDevice>(physicalDevice),
        queueFamilyIndex,
        static_cast<QWindow *>(window));
}

[[maybe_unused]] unsigned long long QVulkanInstance_surfaceForWindow(void *window) {
    return reinterpret_cast<unsigned long long>(QVulkanInstance::surfaceForWindow(static_cast<QWindow *>(window)));
}
