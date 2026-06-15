# M5Atom S3 Ultrasonic Distance Sensor

A simple ultrasonic distance measurement script for the **M5Atom S3** using the HC-SR04 sensor. Built with Arduino IDE, this project uses no external dependencies beyond the core M5 libraries.

https://docs.m5stack.com/en/core/AtomS3

## 📋 Requirements

### Software Prerequisites
Before uploading code, configure your Arduino IDE:

1.  **Add ESP32 Board Support**
    *   Open `File → Preferences`.
    *   Paste this into **Additional Board Manager URLs**:
        ```text
        https://espressif.github.io/arduino-esp32/package_esp32_index.json
        ```
    *   Go to `Tools → Board → Boards Manager`, search **"esp32"**, and install the latest version by **Espressif Systems**.

2.  **Install M5 Libraries**
    *   Go to `Sketch → Include Library → Manage Libraries...`
    *   Search and install these two libraries:
        *   **M5Unified** (by M5Stack)
        *   **M5GFX** (by M5Stack)

3.  **Select Board & Port**
    *   `Tools → Board → M5Stack → **M5Atom S3**`
    *   `Tools → Port → [Your Device Port]` (e.g., `/dev/ttyUSB0` or `COM3`)

📜 License

This project is licensed under the MIT License. See the LICENSE file for details.
