// ===================================================================================
// USB HID Touchscreen for CH551, CH552 and CH554
// ===================================================================================

#pragma once
#include <stdint.h>
#include "usb_hid.h"

// Functions
#define TS_INIT() HID_init()         // init touch screen
void TOC_press(uint16_t x, uint16_t y);
void TOC_release(uint16_t x, uint16_t y);
void TOC_tap(uint16_t x, uint16_t y);
