#include <QMessageBox>

#include "qlift-QMessageBox.h"

[[maybe_unused]] void *QMessageBox_new(void *parent) {
    return static_cast<void *>(
        new QMessageBox{static_cast<QWidget *>(parent)});
}

[[maybe_unused]] void QMessageBox_setWindowTitle(void *messageBox, const char *title) {
    static_cast<QMessageBox *>(messageBox)->setWindowTitle(title);
}

[[maybe_unused]] CQString QMessageBox_windowTitle(void *messageBox) {
    auto text = static_cast<QMessageBox *>(messageBox)->windowTitle();
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] int QMessageBox_icon(void *messageBox) {
    return static_cast<QMessageBox *>(messageBox)->icon();
}

[[maybe_unused]] int QMessageBox_standardButtons(void *messageBox) {
    return static_cast<QMessageBox *>(messageBox)->standardButtons();
}

[[maybe_unused]] void QMessageBox_setIcon(void *messageBox, int icon) {
    static_cast<QMessageBox *>(messageBox)
        ->setIcon(static_cast<QMessageBox::Icon>(icon));
}

[[maybe_unused]] CQString QMessageBox_text(void *messageBox) {
    auto text = static_cast<QMessageBox *>(messageBox)->text();
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] void QMessageBox_setText(void *messageBox, const char *text) {
    static_cast<QMessageBox *>(messageBox)->setText(text);
}

[[maybe_unused]] CQString QMessageBox_informativeText(void *messageBox) {
    auto text = static_cast<QMessageBox *>(messageBox)->informativeText();
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] void QMessageBox_setInformativeText(void *messageBox, const char *text) {
    static_cast<QMessageBox *>(messageBox)->setInformativeText(text);
}

[[maybe_unused]] CQString QMessageBox_detailedText(void *messageBox) {
    auto text = static_cast<QMessageBox *>(messageBox)->detailedText();
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] void QMessageBox_setDetailedText(void *messageBox, const char *text) {
    static_cast<QMessageBox *>(messageBox)->setDetailedText(text);
}

[[maybe_unused]] void QMessageBox_setStandardButtons(void *messageBox,
                                                     int buttons) {
    static_cast<QMessageBox *>(messageBox)
        ->setStandardButtons(
            static_cast<QFlags<QMessageBox::StandardButton>>(buttons));
}

[[maybe_unused]] void
QMessageBox_setDefaultButtonStandardButton(void *messageBox, int button) {
    static_cast<QMessageBox *>(messageBox)
        ->setDefaultButton(static_cast<QMessageBox::StandardButton>(button));
}

[[maybe_unused]] int QMessageBox_exec(void *messageBox) {
    return static_cast<QMessageBox *>(messageBox)->exec();
}

[[maybe_unused]] void QMessageBox_about(void *parent, const char *title, const char *text) {
    QMessageBox::about(static_cast<QWidget *>(parent), title, text);
}

[[maybe_unused]] void QMessageBox_aboutQt(void *parent, const char *title) {
    QMessageBox::aboutQt(static_cast<QWidget *>(parent), title);
}

[[maybe_unused]] int QMessageBox_critical(void *parent,
                                          const char *title,
                                          const char *text,
                                          int buttons,
                                          int defaultButton) {
    return QMessageBox::critical(
        static_cast<QWidget *>(parent),
        title,
        text,
        static_cast<QFlags<QMessageBox::StandardButton>>(buttons),
        static_cast<QMessageBox::StandardButton>(defaultButton));
}

[[maybe_unused]] int QMessageBox_information(void *parent,
                                             const char *title,
                                             const char *text,
                                             int buttons,
                                             int defaultButton) {
    return QMessageBox::information(
        static_cast<QWidget *>(parent),
        title,
        text,
        static_cast<QFlags<QMessageBox::StandardButton>>(buttons),
        static_cast<QMessageBox::StandardButton>(defaultButton));
}

[[maybe_unused]] int QMessageBox_question(void *parent,
                                          const char *title,
                                          const char *text,
                                          int buttons,
                                          int defaultButton) {
    return QMessageBox::question(
        static_cast<QWidget *>(parent),
        title,
        text,
        static_cast<QFlags<QMessageBox::StandardButton>>(buttons),
        static_cast<QMessageBox::StandardButton>(defaultButton));
}

[[maybe_unused]] int QMessageBox_warning(void *parent,
                                         const char *title,
                                         const char *text,
                                         int buttons,
                                         int defaultButton) {
    return QMessageBox::warning(
        static_cast<QWidget *>(parent),
        title,
        text,
        static_cast<QFlags<QMessageBox::StandardButton>>(buttons),
        static_cast<QMessageBox::StandardButton>(defaultButton));
}
