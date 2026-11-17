# ORB wiring reference

Board: ESP32-C3 DevKitM-1  
Display: 4-inch ST7796S SPI TFT with integrated XPT2046-compatible resistive touch  
RTC: DS3231  
Sensor: BME280

## TFT display

| Display pin | ESP32-C3 connection | Notes |
|---|---:|---|
| VCC | 3V3, if supported by the exact component | Verify component power specification |
| GND | GND | Common ground |
| CS | GPIO 10 | TFT chip select |
| RST | GPIO 0 | TFT reset |
| DC | GPIO 3 | Data/command |
| MOSI | GPIO 7 | SPI data from ESP32 |
| SCK | GPIO 6 | SPI clock |
| LED | Not yet confirmed | Check backlight specification and Mokxi behavior |
| MISO | Not connected | TFT readback is not used in this wiring |

## Integrated touchscreen

The display assembly exposes touch pins. These are not a separate touch module.

| Touch pin | ESP32-C3 connection |
|---|---:|
| T_CLK | GPIO 6 |
| T_DIN | GPIO 7 |
| T_DO | GPIO 1 |
| T_CS | GPIO 20 |
| T_IRQ | GPIO 21 |
| VCC | 3V3, if supported by component |
| GND | GND |

Touch shares SPI clock (GPIO 6) and MOSI/data-in (GPIO 7) with the display. Touch T_DO is the controller's data-out line and uses GPIO 1.

## I2C: DS3231 + BME280

| ESP32-C3 pin | DS3231 | BME280 |
|---|---|---|
| GPIO 4 | SDA | SDA |
| GPIO 5 | SCL | SCL |
| 3V3 | VCC | VIN, if supported by breakout |
| GND | GND | GND |

Both I2C modules share SDA and SCL. Verify breakout voltage requirements before powering physical modules.

## Not yet specified

- Display LED/backlight supply and final connection.
- Buzzer (no confirmed buzzer connection).
- External buttons (touchscreen is intended as input).
- Physical enclosure wiring.

## Verification notes

The supplied Mokxi close-ups show the display and touch wires routed to the GPIOs above. The display LED pin appeared unwired in one screenshot. The exact LED pin behavior and voltage are not confirmed here. Do not connect it to a supply until the component specification is checked.
