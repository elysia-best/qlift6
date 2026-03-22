//
//  QImage.swift
//  
//
//  Created by Dmitriy Borovikov on 09.05.2021.
//

import CQlift
import Foundation

open class QImage {
    public enum Format: Int32 {
        case Format_Invalid = 0
        case Format_Mono
        case Format_MonoLSB
        case Format_Indexed8
        case Format_RGB32
        case Format_ARGB32
        case Format_ARGB32_Premultiplied
        case Format_RGB16
        case Format_ARGB8565_Premultiplied
        case Format_RGB666
        case Format_ARGB6666_Premultiplied
        case Format_RGB555
        case Format_ARGB8555_Premultiplied
        case Format_RGB888
        case Format_RGB444
        case Format_ARGB4444_Premultiplied
        case Format_RGBX8888
        case Format_RGBA8888
        case Format_RGBA8888_Premultiplied
        case Format_BGR30
        case Format_A2BGR30_Premultiplied
        case Format_RGB30
        case Format_A2RGB30_Premultiplied
        case Format_Alpha8
        case Format_Grayscale8
        case Format_RGBX64
        case Format_RGBA64
        case Format_RGBA64_Premultiplied
        case Format_Grayscale16
        case Format_BGR888
        case Format_RGBX16FPx4
        case Format_RGBA16FPx4
        case Format_RGBA16FPx4_Premultiplied
        case Format_RGBX32FPx4
        case Format_RGBA32FPx4
        case Format_RGBA32FPx4_Premultiplied
        case Format_CMYK8888
    }

    public enum InvertMode: Int32 {
        case InvertRgb = 0, InvertRgba }

    public var ptr: UnsafeMutableRawPointer!

    public init() {
        self.ptr = QImage_new()
    }

    public init(width: Int32, height: Int32, format: Format) {
        self.ptr = QImage_new_wh_format(width, height, format.rawValue)
    }

    public init(size: QSize, format: Format) {
        self.ptr = QImage_new_qsize_format(size.ptr, format.rawValue)
    }

    public init(fileName: String, format: String? = nil) {
        self.ptr = QImage_from_file(fileName, format)
    }

    public init(ptr: UnsafeMutableRawPointer) {
        self.ptr = ptr
    }

    public init(data: Data, width: Int, height: Int, format: Format) {
        self.ptr = data.withUnsafeBytes { ptr in
            QImage_new_data(ptr.baseAddress!, Int32(width), Int32(height), format.rawValue, nil)
        }
    }

    public init(data: UnsafeRawPointer, width: Int, height: Int, format: Format) {
        self.ptr = QImage_new_data(data, Int32(width), Int32(height), format.rawValue, nil)
    }

    public init(data: Data, width: Int, height: Int, format: Format, bytesPerLine: Int) {
        self.ptr = data.withUnsafeBytes { ptr in
            QImage_new_data_bpl(ptr.baseAddress!, Int32(width), Int32(height), Int32(bytesPerLine), format.rawValue, nil)
        }
    }

    public init(data: UnsafeRawPointer, width: Int, height: Int, format: Format, bytesPerLine: Int) {
        self.ptr = QImage_new_data_bpl(data, Int32(width), Int32(height), Int32(bytesPerLine), format.rawValue, nil)
    }

    public static func fromData(_ data: Data, format: String? = nil) -> QImage {
        data.withUnsafeBytes { buf in
            QImage(ptr: QImage_fromData(buf.baseAddress!, UInt32(buf.count), format))
        }
    }

    deinit {
        guard self.ptr != nil else {
            return
        }
        QImage_delete(self.ptr)
        self.ptr = nil
    }

    public func convertToFormat(format: Format) -> QImage {
        QImage(ptr: QImage_convertToFormat(ptr, format.rawValue))
    }

    public func load(fileName: String, format: String? = nil) -> Bool {
        QImage_load(ptr, fileName, format)
    }

    public func loadFromData(_ data: Data, format: String? = nil) -> Bool {
        data.withUnsafeBytes { buf in
            QImage_loadFromData(ptr, buf.baseAddress!, UInt32(buf.count), format)
        }
    }

    public func save(fileName: String, format: String? = nil, quality: Int = -1) -> Bool {
        QImage_save(ptr, fileName, format, Int32(quality))
    }

    public func rgbSwapped() -> QImage {
        QImage(ptr: QImage_rgbSwapped(ptr))
    }

    public func mirrored(horizontal: Bool = false, vertical: Bool = true) -> QImage {
        QImage(ptr: QImage_mirrored(ptr, horizontal, vertical))
    }

    public func copy(x: Int32, y: Int32, width: Int32, height: Int32) -> QImage {
        QImage(ptr: QImage_copy(ptr, x, y, width, height))
    }

    public func invertPixels(mode: InvertMode = .InvertRgb) {
        QImage_invertPixels(ptr, mode.rawValue)
    }

    public func fill(pixelValue: UInt32) {
        QImage_fill(ptr, pixelValue)
    }

    public func pixel(x: Int32, y: Int32) -> UInt32 {
        UInt32(bitPattern: QImage_pixel(ptr, x, y))
    }

    public func setPixel(x: Int32, y: Int32, value: UInt32) {
        QImage_setPixel(ptr, x, y, value)
    }

    public func pixelColor(x: Int32, y: Int32) -> QColor {
        QColor(ptr: QImage_pixelColor(ptr, x, y))
    }

    public func setPixelColor(x: Int32, y: Int32, color: QColor) {
        QImage_setPixelColor(ptr, x, y, color.ptr)
    }

    public func text(_ key: String = "") -> String {
        let s = QImage_text(ptr, key)
        return String(utf16CodeUnits: s.utf16, count: Int(s.size))
    }

    public func setText(_ key: String, _ value: String) {
        QImage_setText(ptr, key, value)
    }

    public var isNull: Bool {
        QImage_isNull(ptr)
    }

    public var format: Format {
        Format(rawValue: QImage_format(ptr)) ?? .Format_Invalid
    }

    public var depth: Int32 {
        QImage_depth(ptr)
    }

    public var hasAlphaChannel: Bool {
        QImage_hasAlphaChannel(ptr)
    }

    public var bytesPerLine: Int32 {
        QImage_bytesPerLine(ptr)
    }

    public var sizeInBytes: Int64 {
        QImage_sizeInBytes(ptr)
    }

    public var size: QSize {
        QSize(ptr: QImage_size(ptr))
    }

    public var rect: QRect {
        QRect(ptr: QImage_rect(ptr))
    }

    public func scaled(w: Int32, h: Int32,
                       aspectMode: Qt.AspectRatioMode = .IgnoreAspectRatio,
                       mode: Qt.TransformationMode = .FastTransformation ) -> QImage {
        QImage(ptr: QImage_scaled(ptr, w, h, aspectMode.rawValue, mode.rawValue))
    }

    public func scaled(s: QSize,
                       aspectMode: Qt.AspectRatioMode = .IgnoreAspectRatio,
                       mode: Qt.TransformationMode = .FastTransformation ) -> QImage {
        QImage(ptr: QImage_scaledQsize(ptr, s.ptr, aspectMode.rawValue, mode.rawValue))
    }

    public func scaledToWidth(_ w: Int32,
                              mode: Qt.TransformationMode = .FastTransformation ) -> QImage {
        QImage(ptr: QImage_scaledToWidth(ptr, w, mode.rawValue))
    }

    public func scaledToHeight(_ h: Int32,
                               mode: Qt.TransformationMode = .FastTransformation ) -> QImage {
        QImage(ptr: QImage_scaledToHeight(ptr, h, mode.rawValue))
    }

    public var height: Int32 {
        QImage_height(ptr)
    }

    public var width: Int32 {
        QImage_width(ptr)
    }
}
