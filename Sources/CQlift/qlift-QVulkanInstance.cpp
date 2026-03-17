#include "qlift-QVulkanInstance.h"
#include <QVulkanInstance>

#include <QString>

namespace {

static CQString toCQString(const QByteArray &text) {
    auto str = QString::fromLatin1(text);
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

[[maybe_unused]] void *QliftQVulkanInstance_functions(void *instance) {
    return static_cast<QVulkanInstance *>(instance)->functions();
}

[[maybe_unused]] void *QliftQVulkanInstance_deviceFunctions(void *instance, unsigned long long device) {
    return static_cast<QVulkanInstance *>(instance)->deviceFunctions(reinterpret_cast<VkDevice>(device));
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

[[maybe_unused]] void QVulkanInstance_destroy(void *instance) {
    static_cast<QVulkanInstance *>(instance)->destroy();
}

[[maybe_unused]] void QVulkanInstance_setFlags(void *instance, int flags) {
    static_cast<QVulkanInstance *>(instance)->setFlags(static_cast<QVulkanInstance::Flags>(flags));
}
