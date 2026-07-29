#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "MqttClient.hpp"
#include "PresencePublisher.hpp"

// your existing sensor + wifi includes here

extern "C" void app_main(void) {
    // 1) init NVS/Wi-Fi (your existing code)
    // 2) init ultrasonic sensor (your existing code)

    MqttClient mqtt({
        .broker_uri = "mqtt://192.168.1.10:1883",
        .client_id = "stickc_01",
        .base_topic = "presence/stickc_01",
        .username = "",
        .password = ""
    });

    mqtt.start();

    PresencePublisher presence(mqtt, {
        .trigger_cm = 80.0f,
        .clear_cm = 95.0f,
        .cooldown_ms = 10000
    });

    while (true) {
        float distance_cm = 999.0f;
        // distance_cm = read_ultrasonic_cm();  // <- your existing function

        uint32_t now_ms = static_cast<uint32_t>(esp_timer_get_time() / 1000ULL);
        presence.update(distance_cm, now_ms);

        vTaskDelay(pdMS_TO_TICKS(100)); // 10 Hz sampling
    }
}
