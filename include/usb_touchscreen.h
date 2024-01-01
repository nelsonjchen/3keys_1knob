// ===================================================================================
// USB HID Touchscreen for CH551, CH552 and CH554
// ===================================================================================

#pragma once
#include <stdint.h>
#include "usb_hid.h"

// Functions
#define TS_INIT() HID_init()         // init touch screen
void TOC_press(uint8_t event, uint8_t x, uint8_t y);
void TOC_release(uint8_t event, uint8_t x, uint8_t y);
void TOC_tap(uint8_t x, uint8_t y);