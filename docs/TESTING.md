# Test log and validation checklist

## ST7796S display test — Mokxi

- Component in project: ST7796/ST7796S 4-inch SPI TFT.
- Driver macro used: `ST7796_DRIVER`.
- Board: ESP32-C3 DevKitM-1.
- Display test produced visible colors and text.
- Portrait rotation (`setRotation(0)`) showed content on the display.
- Landscape and portrait tests have both been attempted. The user wants a wide clock-style layout; final mounting orientation and exact logical dimensions must be confirmed.
- One observed Serial Monitor/display text readout showed approximately 403 × 320. Do not hard-code 480 × 320 until the current runtime values are verified.
- Touch input has produced click/touch coordinates in Serial Monitor; coordinate calibration and hit-target mapping are not yet fully verified.
- DS3231 and BME280 end-to-end integration is not yet confirmed.

## Test checklist

- [x] Display test: visible color fills and text observed in Mokxi
- [ ] Record exact current `tft.width()` and `tft.height()` values for chosen rotation
- [ ] Confirm full-screen border reaches all four logical edges
- [ ] Verify backlight/LED behavior
- [ ] Confirm touch press and release behavior
- [ ] Calibrate raw touch coordinates at all four corners
- [ ] Verify every touch UI control maps to the intended location
- [ ] Confirm DS3231 is detected and retains time over reset
- [ ] Confirm BME280 is detected and readings are plausible
- [ ] Verify alarm save/load across reset
- [ ] Verify weekday repeat behavior
- [ ] Verify alarm trigger, snooze, stop, and auto-stop
- [ ] Test the complete ORB UI at the actual logical screen dimensions

## How to record a test

For each test, record:
- Date and exact sketch/version
- Mokxi component configuration
- Serial Monitor output
- What appeared on screen
- Pass/fail and limitations
- Screenshot filename (use genuine screenshots)
