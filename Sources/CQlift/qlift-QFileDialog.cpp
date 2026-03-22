#include <QFileDialog>

#include "qlift-QFileDialog.h"

[[maybe_unused]] void *QFileDialog_new(void *parent,
                                       const char *caption,
                                       const char *directory,
                                       const char *filter) {
    return static_cast<void *>(
        new QFileDialog(static_cast<QWidget *>(parent), caption, directory, filter));
}

[[maybe_unused]] int QFileDialog_acceptMode(void *dialog) {
    return static_cast<QFileDialog *>(dialog)->acceptMode();
}

[[maybe_unused]] void QFileDialog_setAcceptMode(void *dialog, int mode) {
    static_cast<QFileDialog *>(dialog)->setAcceptMode(static_cast<QFileDialog::AcceptMode>(mode));
}

[[maybe_unused]] CQString QFileDialog_defaultSuffix(void *dialog) {
    auto text = static_cast<QFileDialog *>(dialog)->defaultSuffix();
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] void QFileDialog_setDefaultSuffix(void *dialog, const char *suffix) {
    static_cast<QFileDialog *>(dialog)->setDefaultSuffix(suffix);
}

[[maybe_unused]] int QFileDialog_fileMode(void *dialog) {
    return static_cast<QFileDialog *>(dialog)->fileMode();
}

[[maybe_unused]] void QFileDialog_setFileMode(void *dialog, int mode) {
    static_cast<QFileDialog *>(dialog)->setFileMode(static_cast<QFileDialog::FileMode>(mode));
}

[[maybe_unused]] int QFileDialog_options(void *dialog) {
    return static_cast<QFileDialog *>(dialog)->options();
}

[[maybe_unused]] void QFileDialog_setOptions(void *dialog, int options) {
    static_cast<QFileDialog *>(dialog)->setOptions(static_cast<QFlags<QFileDialog::Option>>(options));
}

[[maybe_unused]] void QFileDialog_setOption(void *dialog, int option, bool on) {
    static_cast<QFileDialog *>(dialog)->setOption(static_cast<QFileDialog::Option>(option), on);
}

[[maybe_unused]] bool QFileDialog_testOption(void *dialog, int option) {
    return static_cast<QFileDialog *>(dialog)->testOption(static_cast<QFileDialog::Option>(option));
}

[[maybe_unused]] int QFileDialog_viewMode(void *dialog) {
    return static_cast<QFileDialog *>(dialog)->viewMode();
}

[[maybe_unused]] void QFileDialog_setViewMode(void *dialog, int mode) {
    static_cast<QFileDialog *>(dialog)->setViewMode(static_cast<QFileDialog::ViewMode>(mode));
}

[[maybe_unused]] void QFileDialog_setDirectory(void *dialog, const char *directory) {
    static_cast<QFileDialog *>(dialog)->setDirectory(directory);
}

[[maybe_unused]] CQString QFileDialog_directory(void *dialog) {
    auto text = static_cast<QFileDialog *>(dialog)->directory().path();
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] void QFileDialog_setNameFilter(void *dialog, const char *filter) {
    static_cast<QFileDialog *>(dialog)->setNameFilter(filter);
}

[[maybe_unused]] CQString QFileDialog_selectedNameFilter(void *dialog) {
    auto text = static_cast<QFileDialog *>(dialog)->selectedNameFilter();
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] void QFileDialog_selectFile(void *dialog, const char *filename) {
    static_cast<QFileDialog *>(dialog)->selectFile(filename);
}

[[maybe_unused]] CQString QFileDialog_selectedFile(void *dialog) {
    auto files = static_cast<QFileDialog *>(dialog)->selectedFiles();
    if (files.isEmpty()) {
        static const QString empty;
        return CQString { empty.utf16(), empty.size() };
    }
    auto text = files.first();
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] CQString QFileDialog_getExistingDirectory(void *parent,
                                                           const char *caption,
                                                           const char *dir,
                                                           int options) {
    auto text = QFileDialog::getExistingDirectory(
        static_cast<QWidget *>(parent),
        caption,
        dir,
        static_cast<QFlags<QFileDialog::Option>>(options));
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] CQString QFileDialog_getOpenFileName(void *parent,
                                                      const char *caption,
                                                      const char *dir,
                                                      const char *filter,
                                                      int options) {
    auto text = QFileDialog::getOpenFileName(
        static_cast<QWidget *>(parent),
        caption,
        dir,
        filter,
        nullptr,
        static_cast<QFlags<QFileDialog::Option>>(options));
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] CQString QFileDialog_getSaveFileName(void *parent,
                                                      const char *caption,
                                                      const char *dir,
                                                      const char *filter,
                                                      int options) {
    auto text = QFileDialog::getSaveFileName(
        static_cast<QWidget *>(parent),
        caption,
        dir,
        filter,
        nullptr,
        static_cast<QFlags<QFileDialog::Option>>(options));
    return CQString { text.utf16(), text.size() };
}
