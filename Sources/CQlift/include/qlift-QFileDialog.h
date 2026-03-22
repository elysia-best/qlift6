#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

LIBRARY_API void *QFileDialog_new(void *parent,
                                  const char *caption,
                                  const char *directory,
                                  const char *filter);

LIBRARY_API int QFileDialog_acceptMode(void *dialog);
LIBRARY_API void QFileDialog_setAcceptMode(void *dialog, int mode);
LIBRARY_API CQString QFileDialog_defaultSuffix(void *dialog);
LIBRARY_API void QFileDialog_setDefaultSuffix(void *dialog, const char *suffix);
LIBRARY_API int QFileDialog_fileMode(void *dialog);
LIBRARY_API void QFileDialog_setFileMode(void *dialog, int mode);
LIBRARY_API int QFileDialog_options(void *dialog);
LIBRARY_API void QFileDialog_setOptions(void *dialog, int options);
LIBRARY_API void QFileDialog_setOption(void *dialog, int option, bool on);
LIBRARY_API bool QFileDialog_testOption(void *dialog, int option);
LIBRARY_API int QFileDialog_viewMode(void *dialog);
LIBRARY_API void QFileDialog_setViewMode(void *dialog, int mode);

LIBRARY_API void QFileDialog_setDirectory(void *dialog, const char *directory);
LIBRARY_API CQString QFileDialog_directory(void *dialog);
LIBRARY_API void QFileDialog_setNameFilter(void *dialog, const char *filter);
LIBRARY_API CQString QFileDialog_selectedNameFilter(void *dialog);
LIBRARY_API void QFileDialog_selectFile(void *dialog, const char *filename);
LIBRARY_API CQString QFileDialog_selectedFile(void *dialog);

LIBRARY_API CQString QFileDialog_getExistingDirectory(void *parent,
                                                      const char *caption,
                                                      const char *dir,
                                                      int options);
LIBRARY_API CQString QFileDialog_getOpenFileName(void *parent,
                                                 const char *caption,
                                                 const char *dir,
                                                 const char *filter,
                                                 int options);
LIBRARY_API CQString QFileDialog_getSaveFileName(void *parent,
                                                 const char *caption,
                                                 const char *dir,
                                                 const char *filter,
                                                 int options);

#ifdef __cplusplus
}
#endif
