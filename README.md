# ESP32-Ultrasonic
Firmware to connect HC-SR04 ultrasonic sensors with various ESP32 boards.

Setup Instructions for Arduino IDE

    Install Board Package
        File → Preferences → Additional Board Manager URLs:

        https://espressif.github.io/arduino-esp32/package_esp32_index.json

        Tools → Board → Boards Manager → Search "esp32" → Install

    Install Required Libraries
        Sketch → Include Library → Manage Libraries...
        Search and install:
            M5Unified
            M5GFX

    Select Board & Port
        Tools → Board → M5Stack → M5Atom S3
        Tools → Port → [Your Device Port]

