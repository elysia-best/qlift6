#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

LIBRARY_API void *QMessageBox_new(void *parent);
LIBRARY_API void QMessageBox_setWindowTitle(void *messageBox, const char *title);
LIBRARY_API CQString QMessageBox_windowTitle(void *messageBox);
LIBRARY_API void QMessageBox_setIcon(void *messageBox, int icon);
LIBRARY_API int QMessageBox_icon(void *messageBox);
LIBRARY_API CQString QMessageBox_text(void *messageBox);
LIBRARY_API void QMessageBox_setText(void *messageBox, const char *text);
LIBRARY_API CQString QMessageBox_informativeText(void *messageBox);
LIBRARY_API void QMessageBox_setInformativeText(void *messageBox, const char *text);
LIBRARY_API CQString QMessageBox_detailedText(void *messageBox);
LIBRARY_API void QMessageBox_setDetailedText(void *messageBox, const char *text);
LIBRARY_API void QMessageBox_setStandardButtons(void *messageBox, int buttons);
LIBRARY_API int QMessageBox_standardButtons(void *messageBox);
LIBRARY_API void QMessageBox_setDefaultButtonStandardButton(void *messageBox,
                                                            int button);
LIBRARY_API int QMessageBox_exec(void *messageBox);

LIBRARY_API void QMessageBox_about(void *parent, const char *title, const char *text);
LIBRARY_API void QMessageBox_aboutQt(void *parent, const char *title);
LIBRARY_API int QMessageBox_critical(void *parent,
                                     const char *title,
                                     const char *text,
                                     int buttons,
                                     int defaultButton);
LIBRARY_API int QMessageBox_information(void *parent,
                                        const char *title,
                                        const char *text,
                                        int buttons,
                                        int defaultButton);
LIBRARY_API int QMessageBox_question(void *parent,
                                     const char *title,
                                     const char *text,
                                     int buttons,
                                     int defaultButton);
LIBRARY_API int QMessageBox_warning(void *parent,
                                    const char *title,
                                    const char *text,
                                    int buttons,
                                    int defaultButton);

#ifdef __cplusplus
}
#endif
