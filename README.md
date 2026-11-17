# ORB — Smart Alarm Clock

ORB is a touchscreen smart alarm clock prototype built around an ESP32-C3, a 4-inch ST7796S TFT display with integrated resistive touch, a DS3231 real-time clock, and a BME280 environmental sensor.

> **Status: prototype / in development.** The ST7796S display test has been run successfully in Mokxi. The complete clock firmware, touch calibration, RTC, sensor integration, and final physical build still need validation. This repository does not claim the project is finished or shipped.

## Hardware target

- ESP32-C3 DevKitM-1
- 4-inch ST7796S SPI TFT display
- Integrated XPT2046-compatible resistive touchscreen
- DS3231 RTC module
- BME280 temperature, humidity, and pressure sensor
- Breadboard and jumper wires for the prototype

See [wiring documentation](docs/WIRING.md) and [BOM](hardware/BOM.csv).

## Intended features

- Full-screen clock and date UI
- Touch navigation
- Five configurable alarms with weekday repeats
- Snooze and stop controls
- DS3231-backed timekeeping
- Indoor temperature, humidity, and pressure display
- Persistent alarm settings

These are project goals, not claims that every feature is already working.

## Repository layout

- `firmware/` — Arduino sketches
- `hardware/` — bill of materials and module details
- `docs/` — wiring, testing, project requirements, and session journal template
- `cad/step/` — exported STEP models, when created
- `pcb/` — PCB design files, if a custom PCB is designed
- `media/` — genuine project screenshots and demo media

## Firmware setup

1. Open the sketch in Arduino IDE or the supported Mokxi editor.
2. Select the ESP32-C3 DevKitM-1 target.
3. Configure TFT_eSPI for the ST7796S component and pin assignments documented in [WIRING.md](docs/WIRING.md).
4. Install the libraries listed in [TESTING.md](docs/TESTING.md).
5. Run the display-only test before integrating touch, RTC, and BME280.
6. Record actual build output and simulator/hardware results in the test log.

The current display sketch is a display test, not the final ORB application firmware.

## Current verification status

| Area | Status |
|---|---|
| ST7796S display test | Demonstrated in Mokxi |
| Full-screen ORB UI | In progress |
| Touch input | Serial touch readings observed; coordinate calibration and control hits not fully verified |
| DS3231 | Not yet end-to-end verified |
| BME280 | Not yet end-to-end verified |
| Alarm scheduling and persistence | Not yet end-to-end verified |
| Buzzer/audio | No confirmed buzzer connection or driver yet |
| Physical enclosure/build | Not yet documented |

## Fallen project documentation checklist

The supplied Fallen Docs screenshots ask for:
- A README explaining what the project is and how to use it, and why/how it was made.
- A journal for each work session describing work, changes, reasoning, learning, time spent, and genuine screenshots.
- A shipped/working project for a build submission.
- Organized, publicly available source files.
- Relevant full assembly/3D files, PCB/schematic sources, STEP files for modeled parts, firmware, and a BOM CSV with links.
- Final product photos and a demo video for a build submission.

See [docs/PROJECT_REQUIREMENTS.md](docs/PROJECT_REQUIREMENTS.md). ORB is not yet being represented as a shipped build.

## Journaling

Copy [docs/SESSION_LOG_TEMPLATE.md](docs/SESSION_LOG_TEMPLATE.md) once per work session and save each entry in `docs/journal/` with a dated filename. Do not invent progress or screenshots.

## License

No license has been selected yet. Until one is chosen, the repository has no explicit open-source reuse license.
