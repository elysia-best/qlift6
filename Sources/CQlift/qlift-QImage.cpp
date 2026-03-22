//
//  qlift-QImage.cpp
//  
//
//  Created by Dmitriy Borovikov on 09.05.2021.
//

#include <QImage>
#include <QColor>

#include "qlift-QImage.h"

[[maybe_unused]] void *QImage_new() {
    return static_cast<void *>( new QImage() );
}

[[maybe_unused]] void *QImage_new_wh_format(int width, int height, int format) {
    return static_cast<void *>(new QImage(width, height, static_cast<QImage::Format>(format)));
}

[[maybe_unused]] void *QImage_new_qsize_format(void *size, int format) {
    return static_cast<void *>(new QImage(*static_cast<QSize *>(size), static_cast<QImage::Format>(format)));
}

[[maybe_unused]] void *QImage_from_file(const char *fileName, const char *format) {
    return static_cast<void *>(new QImage(fileName, format));
}

[[maybe_unused]] void *QImage_fromData(const void *data, unsigned int len, const char *format) {
    return static_cast<void *>(new QImage(QImage::fromData(static_cast<const uchar *>(data), static_cast<int>(len), format)));
}

[[maybe_unused]] bool QImage_load(void *image, const char *fileName, const char *format) {
    return static_cast<QImage *>(image)->load(fileName, format);
}

[[maybe_unused]] bool QImage_loadFromData(void *image, const void *data, unsigned int len, const char *format) {
    return static_cast<QImage *>(image)->loadFromData(static_cast<const uchar *>(data), static_cast<int>(len), format);
}

[[maybe_unused]] bool QImage_save(void *image, const char *fileName, const char *format, int quality) {
    return static_cast<QImage *>(image)->save(fileName, format, quality);
}

[[maybe_unused]] void QImage_delete(void *image) {
    delete static_cast<QImage *>(image);
}

[[maybe_unused]] void *QImage_new_data(const void *data, int width, int height, int format, void *cleanupInfo) {
    return static_cast<void *>( new QImage { static_cast<const uchar *>(data), width, height, static_cast<QImage::Format>(format)} );
}

[[maybe_unused]] void *QImage_new_data_bpl(const void *data, int width, int height, int bytesPerLine, int format, void *cleanupInfo) {
    return static_cast<void *>( new QImage { static_cast<const uchar *>(data), width, height, bytesPerLine, static_cast<QImage::Format>(format)} );
}

[[maybe_unused]] void *QImage_convertToFormat(const void *image, int format) {
    QImage *new_image = new QImage();
    *new_image = static_cast<const QImage *>(image)->convertToFormat(static_cast<QImage::Format>(format), Qt::AutoColor);
    return new_image;
}

[[maybe_unused]] void *QImage_scaled(void *image, int w, int h, int aspectMode, int mode) {
    return static_cast<void *>(new QImage(static_cast<QImage *>(image)->
                                          scaled(w, h,
                                                 static_cast<Qt::AspectRatioMode>(aspectMode),
                                                 static_cast<Qt::TransformationMode>(mode)) ));
}

[[maybe_unused]] void *QImage_scaledQsize(void *image, void *s, int aspectMode, int mode) {
    return static_cast<void *>(new QImage(static_cast<QImage *>(image)->
                                          scaled(*static_cast<const QSize *>(s),
                                                 static_cast<Qt::AspectRatioMode>(aspectMode),
                                                 static_cast<Qt::TransformationMode>(mode)) ));
}

[[maybe_unused]] void *QImage_scaledToWidth(void *image, int w, int mode) {
    return static_cast<void *>(new QImage(static_cast<QImage *>(image)->
                                          scaledToWidth(w, static_cast<Qt::TransformationMode>(mode)) ));
}

[[maybe_unused]] void *QImage_scaledToHeight(void *image, int h, int mode) {
    return static_cast<void *>(new QImage(static_cast<QImage *>(image)->
                                          scaledToHeight(h, static_cast<Qt::TransformationMode>(mode)) ));
}

[[maybe_unused]] void *QImage_rgbSwapped(void *image) {
    return static_cast<void *>(new QImage(static_cast<QImage *>(image)->rgbSwapped()));
}

[[maybe_unused]] void *QImage_mirrored(void *image, bool horizontal, bool vertical) {
    Qt::Orientations orient = Qt::Orientations();
    if (horizontal) {
        orient |= Qt::Horizontal;
    }
    if (vertical) {
        orient |= Qt::Vertical;
    }
    return static_cast<void *>(new QImage(static_cast<QImage *>(image)->flipped(orient)));
}

[[maybe_unused]] void *QImage_copy(void *image, int x, int y, int width, int height) {
    return static_cast<void *>(new QImage(static_cast<QImage *>(image)->copy(x, y, width, height)));
}

[[maybe_unused]] void QImage_invertPixels(void *image, int mode) {
    static_cast<QImage *>(image)->invertPixels(static_cast<QImage::InvertMode>(mode));
}

[[maybe_unused]] void QImage_fill(void *image, unsigned int pixelValue) {
    static_cast<QImage *>(image)->fill(pixelValue);
}

[[maybe_unused]] bool QImage_isNull(void *image) {
    return static_cast<QImage *>(image)->isNull();
}

[[maybe_unused]] int QImage_format(void *image) {
    return static_cast<QImage *>(image)->format();
}

[[maybe_unused]] int QImage_depth(void *image) {
    return static_cast<QImage *>(image)->depth();
}

[[maybe_unused]] bool QImage_hasAlphaChannel(void *image) {
    return static_cast<QImage *>(image)->hasAlphaChannel();
}

[[maybe_unused]] int QImage_bytesPerLine(void *image) {
    return static_cast<int>(static_cast<QImage *>(image)->bytesPerLine());
}

[[maybe_unused]] long long QImage_sizeInBytes(void *image) {
    return static_cast<long long>(static_cast<QImage *>(image)->sizeInBytes());
}

[[maybe_unused]] void *QImage_size(void *image) {
    return static_cast<void *>(new QSize(static_cast<QImage *>(image)->size()));
}

[[maybe_unused]] void *QImage_rect(void *image) {
    return static_cast<void *>(new QRect(static_cast<QImage *>(image)->rect()));
}

[[maybe_unused]] int QImage_pixel(void *image, int x, int y) {
    return static_cast<int>(static_cast<QImage *>(image)->pixel(x, y));
}

[[maybe_unused]] void QImage_setPixel(void *image, int x, int y, unsigned int value) {
    static_cast<QImage *>(image)->setPixel(x, y, value);
}

[[maybe_unused]] void *QImage_pixelColor(void *image, int x, int y) {
    return static_cast<void *>(new QColor(static_cast<QImage *>(image)->pixelColor(x, y)));
}

[[maybe_unused]] void QImage_setPixelColor(void *image, int x, int y, void *color) {
    static_cast<QImage *>(image)->setPixelColor(x, y, *static_cast<QColor *>(color));
}

[[maybe_unused]] CQString QImage_text(void *image, const char *key) {
    auto text = static_cast<QImage *>(image)->text(key);
    return CQString { text.utf16(), text.size() };
}

[[maybe_unused]] void QImage_setText(void *image, const char *key, const char *text) {
    static_cast<QImage *>(image)->setText(key, text);
}

[[maybe_unused]] int QImage_width(void *image) {
    return static_cast<QImage *>(image)->width();
}

[[maybe_unused]] int QImage_height(void *image) {
    return static_cast<QImage *>(image)->height();
}
