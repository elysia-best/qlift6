#include <QLCDNumber>
#include <QString>

#include "qlift-QLCDNumber.h"

[[maybe_unused]] void *QLCDNumber_new(void *parent) {
    return static_cast<void *>(new QLCDNumber{static_cast<QWidget *>(parent)});
}

[[maybe_unused]] void *QLCDNumber_new2(unsigned int numDigits, void *parent) {
    return static_cast<void *>(new QLCDNumber{numDigits, static_cast<QWidget *>(parent)});
}

[[maybe_unused]] bool QLCDNumber_checkOverflowDouble(void *lcdNumber, double num) {
    return static_cast<QLCDNumber *>(lcdNumber)->checkOverflow(num);
}

[[maybe_unused]] bool QLCDNumber_checkOverflowInt(void *lcdNumber, int num) {
    return static_cast<QLCDNumber *>(lcdNumber)->checkOverflow(num);
}

[[maybe_unused]] int QLCDNumber_digitCount(void *lcdNumber) {
    return static_cast<QLCDNumber *>(lcdNumber)->digitCount();
}

[[maybe_unused]] void QLCDNumber_setDigitCount(void *lcdNumber, int numDigits) {
    static_cast<QLCDNumber *>(lcdNumber)->setDigitCount(numDigits);
}

[[maybe_unused]] int QLCDNumber_intValue(void *lcdNumber) {
    return static_cast<QLCDNumber *>(lcdNumber)->intValue();
}

[[maybe_unused]] double QLCDNumber_value(void *lcdNumber) {
    return static_cast<QLCDNumber *>(lcdNumber)->value();
}

[[maybe_unused]] int QLCDNumber_mode(void *lcdNumber) {
    return static_cast<QLCDNumber *>(lcdNumber)->mode();
}

[[maybe_unused]] void QLCDNumber_setMode(void *lcdNumber, int mode) {
    static_cast<QLCDNumber *>(lcdNumber)->setMode(static_cast<QLCDNumber::Mode>(mode));
}

[[maybe_unused]] int QLCDNumber_segmentStyle(void *lcdNumber) {
    return static_cast<QLCDNumber *>(lcdNumber)->segmentStyle();
}

[[maybe_unused]] void QLCDNumber_setSegmentStyle(void *lcdNumber, int style) {
    static_cast<QLCDNumber *>(lcdNumber)->setSegmentStyle(static_cast<QLCDNumber::SegmentStyle>(style));
}

[[maybe_unused]] bool QLCDNumber_smallDecimalPoint(void *lcdNumber) {
    return static_cast<QLCDNumber *>(lcdNumber)->smallDecimalPoint();
}

[[maybe_unused]] void QLCDNumber_setSmallDecimalPoint(void *lcdNumber, bool small) {
    static_cast<QLCDNumber *>(lcdNumber)->setSmallDecimalPoint(small);
}

[[maybe_unused]] void QLCDNumber_displayString(void *lcdNumber, const char *text) {
    static_cast<QLCDNumber *>(lcdNumber)->display(QString::fromUtf8(text));
}

[[maybe_unused]] void QLCDNumber_displayDouble(void *lcdNumber, double num) {
    static_cast<QLCDNumber *>(lcdNumber)->display(num);
}

[[maybe_unused]] void QLCDNumber_displayInt(void *lcdNumber, int num) {
    static_cast<QLCDNumber *>(lcdNumber)->display(num);
}

[[maybe_unused]] void QLCDNumber_setBinMode(void *lcdNumber) {
    static_cast<QLCDNumber *>(lcdNumber)->setBinMode();
}

[[maybe_unused]] void QLCDNumber_setDecMode(void *lcdNumber) {
    static_cast<QLCDNumber *>(lcdNumber)->setDecMode();
}

[[maybe_unused]] void QLCDNumber_setHexMode(void *lcdNumber) {
    static_cast<QLCDNumber *>(lcdNumber)->setHexMode();
}

[[maybe_unused]] void QLCDNumber_setOctMode(void *lcdNumber) {
    static_cast<QLCDNumber *>(lcdNumber)->setOctMode();
}

[[maybe_unused]] void QLCDNumber_overflow_connect(void *lcdNumber,
                                                  void *receiver,
                                                  void *context,
                                                  void (*slot_ptr)(void *)) {
    QObject::connect(static_cast<QLCDNumber *>(lcdNumber),
                     &QLCDNumber::overflow,
                     static_cast<QObject *>(receiver),
                     [context, slot_ptr]() { (*slot_ptr)(context); });
}
