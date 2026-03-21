#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma clang diagnostic ignored "-Wnullability-completeness"

LIBRARY_API void *QPlainTextEdit_new(const char *text, void *parent);

LIBRARY_API CQString QPlainTextEdit_toPlainText(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setPlainText(void *plainTextEdit, const char *text);
LIBRARY_API void QPlainTextEdit_appendPlainText(void *plainTextEdit, const char *text);
LIBRARY_API void QPlainTextEdit_appendHtml(void *plainTextEdit, const char *html);

LIBRARY_API CQString QPlainTextEdit_placeholderText(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setPlaceholderText(void *plainTextEdit, const char *text);

LIBRARY_API bool QPlainTextEdit_isReadOnly(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setReadOnly(void *plainTextEdit, bool ro);
LIBRARY_API bool QPlainTextEdit_isUndoRedoEnabled(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setUndoRedoEnabled(void *plainTextEdit, bool enable);
LIBRARY_API bool QPlainTextEdit_overwriteMode(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setOverwriteMode(void *plainTextEdit, bool overwrite);
LIBRARY_API int QPlainTextEdit_lineWrapMode(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setLineWrapMode(void *plainTextEdit, int mode);
LIBRARY_API int QPlainTextEdit_maximumBlockCount(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setMaximumBlockCount(void *plainTextEdit, int maximum);
LIBRARY_API int QPlainTextEdit_blockCount(void *plainTextEdit);
LIBRARY_API bool QPlainTextEdit_tabChangesFocus(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setTabChangesFocus(void *plainTextEdit, bool enabled);
LIBRARY_API double QPlainTextEdit_tabStopDistance(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setTabStopDistance(void *plainTextEdit, double distance);
LIBRARY_API bool QPlainTextEdit_centerOnScroll(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setCenterOnScroll(void *plainTextEdit, bool enabled);
LIBRARY_API bool QPlainTextEdit_backgroundVisible(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_setBackgroundVisible(void *plainTextEdit, bool visible);

LIBRARY_API void QPlainTextEdit_clear(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_copy(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_cut(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_paste(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_selectAll(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_undo(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_redo(void *plainTextEdit);
LIBRARY_API void QPlainTextEdit_zoomIn(void *plainTextEdit, int range);
LIBRARY_API void QPlainTextEdit_zoomOut(void *plainTextEdit, int range);

#pragma clang assume_nonnull begin
LIBRARY_API void QPlainTextEdit_textChanged_connect(void *plainTextEdit,
                                                    void *receiver,
                                                    void *context,
                                                    void (*slot_ptr)(void *));
LIBRARY_API void QPlainTextEdit_blockCountChanged_connect(void *plainTextEdit,
                                                          void *receiver,
                                                          void *context,
                                                          void (*slot_ptr)(void *, int));
LIBRARY_API void QPlainTextEdit_copyAvailable_connect(void *plainTextEdit,
                                                      void *receiver,
                                                      void *context,
                                                      void (*slot_ptr)(void *, bool));
LIBRARY_API void QPlainTextEdit_cursorPositionChanged_connect(void *plainTextEdit,
                                                              void *receiver,
                                                              void *context,
                                                              void (*slot_ptr)(void *));
#pragma clang assume_nonnull end

#ifdef __cplusplus
}
#endif
