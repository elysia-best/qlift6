//
//  qlift-QImage.h
//  
//
//  Created by Dmitriy Borovikov on 09.05.2021.
//

#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

LIBRARY_API void *QImage_new();
LIBRARY_API void QImage_delete(void *image);
LIBRARY_API void *QImage_new_wh_format(int width, int height, int format);
LIBRARY_API void *QImage_new_qsize_format(void *size, int format);
LIBRARY_API void *QImage_from_file(const char *fileName, const char *format);
LIBRARY_API void *QImage_fromData(const void *data, unsigned int len, const char *format);
LIBRARY_API bool QImage_load(void *image, const char *fileName, const char *format);
LIBRARY_API bool QImage_loadFromData(void *image, const void *data, unsigned int len, const char *format);
LIBRARY_API bool QImage_save(void *image, const char *fileName, const char *format, int quality);

LIBRARY_API void *QImage_new_data(const void *data, int width, int height, int format, void *cleanupInfo);
LIBRARY_API void *QImage_new_data_bpl(const void *data, int width, int height, int bytesPerLine, int format, void *cleanupInfo);
LIBRARY_API void *QImage_convertToFormat(const void *image, int format);
LIBRARY_API void *QImage_scaled(void *image, int w, int h, int aspectMode, int mode);
LIBRARY_API void *QImage_scaledQsize(void *image, void *s, int aspectMode, int mode);
LIBRARY_API void *QImage_scaledToWidth(void *image, int w, int mode);
LIBRARY_API void *QImage_scaledToHeight(void *image, int h, int mode);
LIBRARY_API void *QImage_rgbSwapped(void *image);
LIBRARY_API void *QImage_mirrored(void *image, bool horizontal, bool vertical);
LIBRARY_API void *QImage_copy(void *image, int x, int y, int width, int height);
LIBRARY_API void QImage_invertPixels(void *image, int mode);
LIBRARY_API void QImage_fill(void *image, unsigned int pixelValue);

LIBRARY_API bool QImage_isNull(void *image);
LIBRARY_API int QImage_format(void *image);
LIBRARY_API int QImage_depth(void *image);
LIBRARY_API bool QImage_hasAlphaChannel(void *image);
LIBRARY_API int QImage_bytesPerLine(void *image);
LIBRARY_API long long QImage_sizeInBytes(void *image);
LIBRARY_API void *QImage_size(void *image);
LIBRARY_API void *QImage_rect(void *image);
LIBRARY_API int QImage_pixel(void *image, int x, int y);
LIBRARY_API void QImage_setPixel(void *image, int x, int y, unsigned int value);
LIBRARY_API void *QImage_pixelColor(void *image, int x, int y);
LIBRARY_API void QImage_setPixelColor(void *image, int x, int y, void *color);

LIBRARY_API CQString QImage_text(void *image, const char *key);
LIBRARY_API void QImage_setText(void *image, const char *key, const char *text);
LIBRARY_API int QImage_width(void *image);
LIBRARY_API int QImage_height(void *image);

#ifdef __cplusplus
}
#endif
