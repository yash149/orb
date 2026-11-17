/*
  ORB - ST7796S DISPLAY TEST
  Target: ESP32-C3 DevKitM-1 + Mokxi 4-inch ST7796S display.

  This is a DISPLAY TEST, not the finished ORB firmware.

  TFT pin mapping:
    SCK  -> GPIO 6
    MOSI -> GPIO 7
    CS   -> GPIO 10
    DC   -> GPIO 3
    RST  -> GPIO 0
    MISO -> not connected to TFT

  Touch wiring (integrated in display assembly):
    T_CLK -> GPIO 6
    T_DIN -> GPIO 7
    T_DO  -> GPIO 1
    T_CS  -> GPIO 20
    T_IRQ -> GPIO 21

  Define the driver and pins before including TFT_eSPI.
  This sketch uses tft.width() and tft.height() dynamically.
  Current project target is landscape; change setRotation(1) only
  after checking the actual mounting orientation in Mokxi.
  Backlight LED electrical requirements must be verified separately.
*/

#define ST7796_DRIVER
#define TFT_MISO  1
#define TFT_MOSI  7
#define TFT_SCLK  6
#define TFT_CS   10
#define TFT_DC    3
#define TFT_RST   0

#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  delay(200);

  Serial.println();
  Serial.println("ORB ST7796S display test");

  tft.init();
  tft.setRotation(1);  // Landscape orientation

  const int w = tft.width();
  const int h = tft.height();

  Serial.print("Display width: ");
  Serial.println(w);
  Serial.print("Display height: ");
  Serial.println(h);

  tft.fillScreen(TFT_BLACK);
  tft.drawRect(0, 0, w, h, TFT_WHITE);

  const int headerH = max(36, h / 9);
  tft.fillRect(1, 1, w - 2, headerH, TFT_BLUE);

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_WHITE, TFT_BLUE);
  tft.drawString("ORB SMART CLOCK", w / 2, headerH / 2, 2);

  const int margin = max(8, w / 30);
  const int panelY = headerH + max(8, h / 24);
  const int footerH = max(28, h / 10);
  const int panelH = h - panelY - footerH - max(10, h / 24);

  tft.drawRoundRect(margin, panelY, w - 2 * margin, panelH,
                    8, TFT_CYAN);

  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.drawString("FULL SCREEN TEST", w / 2,
                 panelY + panelH / 2 - 12, 2);

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString(String(w) + " x " + String(h),
                 w / 2, panelY + panelH / 2 + 14, 2);

  tft.fillRect(1, h - footerH, w - 2, footerH - 1, TFT_BLUE);
  tft.setTextColor(TFT_WHITE, TFT_BLUE);
  tft.drawString("DISPLAY TEST COMPLETE",
                 w / 2, h - footerH / 2, 2);

  Serial.println("Display test complete");
}

void loop() {
}
