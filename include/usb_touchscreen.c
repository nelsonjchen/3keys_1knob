// ===================================================================================
// USB HID TouchScreen Functions for CH551, CH552 and CH554
// ===================================================================================

#include "usb_conkbd.h"
#include "usb_hid.h"
#include "usb_handler.h"
#include "vscode.h"

#define TS_sendReport()  HID_sendReport(TS_report, sizeof(TS_report))

// ===================================================================================
// TouchScreen HID report
// ===================================================================================
__xdata uint8_t  TS_report[9] = {1,0,0,0,0,0,0,0,0};

void TOC_press(uint8_t event, uint8_t x, uint8_t y) {

}

void TOC_release(uint8_t event, uint8_t x, uint8_t y) {

}


// ===================================================================================
// Tap touch screen
// ===================================================================================
void TOC_tap(uint8_t x, uint8_t y) {
  TOC_press(1, x, y);
  TOC_release(1, x, y);
}
