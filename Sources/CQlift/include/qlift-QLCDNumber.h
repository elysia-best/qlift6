#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

LIBRARY_API void *QLCDNumber_new(void *parent);
LIBRARY_API void *QLCDNumber_new2(unsigned int numDigits, void *parent);

LIBRARY_API bool QLCDNumber_checkOverflowDouble(void *lcdNumber, double num);
LIBRARY_API bool QLCDNumber_checkOverflowInt(void *lcdNumber, int num);

LIBRARY_API int QLCDNumber_digitCount(void *lcdNumber);
LIBRARY_API void QLCDNumber_setDigitCount(void *lcdNumber, int numDigits);

LIBRARY_API int QLCDNumber_intValue(void *lcdNumber);
LIBRARY_API double QLCDNumber_value(void *lcdNumber);

LIBRARY_API int QLCDNumber_mode(void *lcdNumber);
LIBRARY_API void QLCDNumber_setMode(void *lcdNumber, int mode);

LIBRARY_API int QLCDNumber_segmentStyle(void *lcdNumber);
LIBRARY_API void QLCDNumber_setSegmentStyle(void *lcdNumber, int style);

LIBRARY_API bool QLCDNumber_smallDecimalPoint(void *lcdNumber);
LIBRARY_API void QLCDNumber_setSmallDecimalPoint(void *lcdNumber, bool small);

LIBRARY_API void QLCDNumber_displayString(void *lcdNumber, const char *text);
LIBRARY_API void QLCDNumber_displayDouble(void *lcdNumber, double num);
LIBRARY_API void QLCDNumber_displayInt(void *lcdNumber, int num);

LIBRARY_API void QLCDNumber_setBinMode(void *lcdNumber);
LIBRARY_API void QLCDNumber_setDecMode(void *lcdNumber);
LIBRARY_API void QLCDNumber_setHexMode(void *lcdNumber);
LIBRARY_API void QLCDNumber_setOctMode(void *lcdNumber);

#pragma clang diagnostic ignored "-Wnullability-completeness"
#pragma clang assume_nonnull begin
LIBRARY_API void QLCDNumber_overflow_connect(void *lcdNumber,
											 void *receiver,
											 void *context,
											 void (*slot_ptr)(void *));
#pragma clang assume_nonnull end

#ifdef __cplusplus
}
#endif
