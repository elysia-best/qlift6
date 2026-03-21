#include <QPlainTextEdit>

#include "qlift-QPlainTextEdit.h"

[[maybe_unused]] void *QPlainTextEdit_new(const char *text, void *parent) {
    if (text != nullptr) {
        return static_cast<void *>(
            new QPlainTextEdit{text, static_cast<QWidget *>(parent)});
    }

    return static_cast<void *>(new QPlainTextEdit{static_cast<QWidget *>(parent)});
}

[[maybe_unused]] CQString QPlainTextEdit_toPlainText(void *plainTextEdit) {
    auto text = static_cast<QPlainTextEdit *>(plainTextEdit)->toPlainText();
    return CQString{text.utf16(), text.size()};
}

[[maybe_unused]] void QPlainTextEdit_setPlainText(void *plainTextEdit, const char *text) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setPlainText(text);
}

[[maybe_unused]] void QPlainTextEdit_appendPlainText(void *plainTextEdit, const char *text) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->appendPlainText(text);
}

[[maybe_unused]] void QPlainTextEdit_appendHtml(void *plainTextEdit, const char *html) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->appendHtml(html);
}

[[maybe_unused]] CQString QPlainTextEdit_placeholderText(void *plainTextEdit) {
    auto text = static_cast<QPlainTextEdit *>(plainTextEdit)->placeholderText();
    return CQString{text.utf16(), text.size()};
}

[[maybe_unused]] void QPlainTextEdit_setPlaceholderText(void *plainTextEdit, const char *text) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setPlaceholderText(text);
}

[[maybe_unused]] bool QPlainTextEdit_isReadOnly(void *plainTextEdit) {
    return static_cast<QPlainTextEdit *>(plainTextEdit)->isReadOnly();
}

[[maybe_unused]] void QPlainTextEdit_setReadOnly(void *plainTextEdit, bool ro) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setReadOnly(ro);
}

[[maybe_unused]] bool QPlainTextEdit_isUndoRedoEnabled(void *plainTextEdit) {
    return static_cast<QPlainTextEdit *>(plainTextEdit)->isUndoRedoEnabled();
}

[[maybe_unused]] void QPlainTextEdit_setUndoRedoEnabled(void *plainTextEdit, bool enable) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setUndoRedoEnabled(enable);
}

[[maybe_unused]] bool QPlainTextEdit_overwriteMode(void *plainTextEdit) {
    return static_cast<QPlainTextEdit *>(plainTextEdit)->overwriteMode();
}

[[maybe_unused]] void QPlainTextEdit_setOverwriteMode(void *plainTextEdit, bool overwrite) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setOverwriteMode(overwrite);
}

[[maybe_unused]] int QPlainTextEdit_lineWrapMode(void *plainTextEdit) {
    return static_cast<QPlainTextEdit *>(plainTextEdit)->lineWrapMode();
}

[[maybe_unused]] void QPlainTextEdit_setLineWrapMode(void *plainTextEdit, int mode) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setLineWrapMode(
        static_cast<QPlainTextEdit::LineWrapMode>(mode));
}

[[maybe_unused]] int QPlainTextEdit_maximumBlockCount(void *plainTextEdit) {
    return static_cast<QPlainTextEdit *>(plainTextEdit)->maximumBlockCount();
}

[[maybe_unused]] void QPlainTextEdit_setMaximumBlockCount(void *plainTextEdit, int maximum) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setMaximumBlockCount(maximum);
}

[[maybe_unused]] int QPlainTextEdit_blockCount(void *plainTextEdit) {
    return static_cast<QPlainTextEdit *>(plainTextEdit)->blockCount();
}

[[maybe_unused]] bool QPlainTextEdit_tabChangesFocus(void *plainTextEdit) {
    return static_cast<QPlainTextEdit *>(plainTextEdit)->tabChangesFocus();
}

[[maybe_unused]] void QPlainTextEdit_setTabChangesFocus(void *plainTextEdit, bool enabled) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setTabChangesFocus(enabled);
}

[[maybe_unused]] double QPlainTextEdit_tabStopDistance(void *plainTextEdit) {
    return static_cast<QPlainTextEdit *>(plainTextEdit)->tabStopDistance();
}

[[maybe_unused]] void QPlainTextEdit_setTabStopDistance(void *plainTextEdit, double distance) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setTabStopDistance(distance);
}

[[maybe_unused]] bool QPlainTextEdit_centerOnScroll(void *plainTextEdit) {
    return static_cast<QPlainTextEdit *>(plainTextEdit)->centerOnScroll();
}

[[maybe_unused]] void QPlainTextEdit_setCenterOnScroll(void *plainTextEdit, bool enabled) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setCenterOnScroll(enabled);
}

[[maybe_unused]] bool QPlainTextEdit_backgroundVisible(void *plainTextEdit) {
    return static_cast<QPlainTextEdit *>(plainTextEdit)->backgroundVisible();
}

[[maybe_unused]] void QPlainTextEdit_setBackgroundVisible(void *plainTextEdit, bool visible) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->setBackgroundVisible(visible);
}

[[maybe_unused]] void QPlainTextEdit_clear(void *plainTextEdit) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->clear();
}

[[maybe_unused]] void QPlainTextEdit_copy(void *plainTextEdit) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->copy();
}

[[maybe_unused]] void QPlainTextEdit_cut(void *plainTextEdit) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->cut();
}

[[maybe_unused]] void QPlainTextEdit_paste(void *plainTextEdit) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->paste();
}

[[maybe_unused]] void QPlainTextEdit_selectAll(void *plainTextEdit) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->selectAll();
}

[[maybe_unused]] void QPlainTextEdit_undo(void *plainTextEdit) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->undo();
}

[[maybe_unused]] void QPlainTextEdit_redo(void *plainTextEdit) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->redo();
}

[[maybe_unused]] void QPlainTextEdit_zoomIn(void *plainTextEdit, int range) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->zoomIn(range);
}

[[maybe_unused]] void QPlainTextEdit_zoomOut(void *plainTextEdit, int range) {
    static_cast<QPlainTextEdit *>(plainTextEdit)->zoomOut(range);
}

[[maybe_unused]] void QPlainTextEdit_textChanged_connect(void *plainTextEdit,
                                                         void *receiver,
                                                         void *context,
                                                         void (*slot_ptr)(void *)) {
    QObject::connect(
        static_cast<QPlainTextEdit *>(plainTextEdit),
        &QPlainTextEdit::textChanged,
        static_cast<QObject *>(receiver),
        [context, slot_ptr]() { (*slot_ptr)(context); });
}

[[maybe_unused]] void QPlainTextEdit_blockCountChanged_connect(void *plainTextEdit,
                                                               void *receiver,
                                                               void *context,
                                                               void (*slot_ptr)(void *, int)) {
    QObject::connect(
        static_cast<QPlainTextEdit *>(plainTextEdit),
        &QPlainTextEdit::blockCountChanged,
        static_cast<QObject *>(receiver),
        [context, slot_ptr](int newBlockCount) { (*slot_ptr)(context, newBlockCount); });
}

[[maybe_unused]] void QPlainTextEdit_copyAvailable_connect(void *plainTextEdit,
                                                           void *receiver,
                                                           void *context,
                                                           void (*slot_ptr)(void *, bool)) {
    QObject::connect(
        static_cast<QPlainTextEdit *>(plainTextEdit),
        &QPlainTextEdit::copyAvailable,
        static_cast<QObject *>(receiver),
        [context, slot_ptr](bool yes) { (*slot_ptr)(context, yes); });
}

[[maybe_unused]] void QPlainTextEdit_cursorPositionChanged_connect(void *plainTextEdit,
                                                                   void *receiver,
                                                                   void *context,
                                                                   void (*slot_ptr)(void *)) {
    QObject::connect(
        static_cast<QPlainTextEdit *>(plainTextEdit),
        &QPlainTextEdit::cursorPositionChanged,
        static_cast<QObject *>(receiver),
        [context, slot_ptr]() { (*slot_ptr)(context); });
}
