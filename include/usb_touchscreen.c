#include "usb_hid.h"
#include "usb_handler.h"
#include "vscode.h"

#define TS_sendReport()  HID_sendReport(TS_report, sizeof(TS_report))

__xdata uint8_t TS_report[9];

void TOC_press(uint16_t x, uint16_t y) {
  TS_report[0] = 1;                        // Contact Count: 1
  TS_report[1] = 0;                        // Contact Identifier: 0
  TS_report[2] = 0b00000001;               // Tip Switch: 1 (touching), In Range: 0, Padding: 000000
  TS_report[3] = 0x7F;                     // Pressure: 127 (maximum pressure)
  TS_report[4] = x & 0xFF;                 // X Coordinate: lower 8 bits
  TS_report[5] = (x >> 8) & 0xFF;          // X Coordinate: upper 8 bits
  TS_report[6] = y & 0xFF;                 // Y Coordinate: lower 8 bits
  TS_report[7] = (y >> 8) & 0xFF;          // Y Coordinate: upper 8 bits
  TS_report[8] = 1;                        // Contact Count Maximum: 1

  TS_sendReport();                         // send report
}

void TOC_release(uint16_t x, uint16_t y) {
  TS_report[0] = 1;                        // Contact Count: 1
  TS_report[1] = 0;                        // Contact Identifier: 0
  TS_report[2] = 0b00000000;               // Tip Switch: 0 (not touching), In Range: 0, Padding: 000000
  TS_report[3] = 0x7F;                     // Pressure: 127 (maximum pressure, but not touching)
  TS_report[4] = x & 0xFF;                 // X Coordinate: lower 8 bits
  TS_report[5] = (x >> 8) & 0xFF;          // X Coordinate: upper 8 bits
  TS_report[6] = y & 0xFF;                 // Y Coordinate: lower 8 bits
  TS_report[7] = (y >> 8) & 0xFF;          // Y Coordinate: upper 8 bits
  TS_report[8] = 1;                        // Contact Count Maximum: 1

  TS_sendReport();                         // send report
}

void TOC_tap(uint16_t x, uint16_t y) {
  TOC_press(x, y);
  TOC_release(x, y);
}
