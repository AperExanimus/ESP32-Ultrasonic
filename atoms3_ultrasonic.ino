#include <M5Unified.h>
#include <M5GFX.h>

// Pin assignments for M5Atom S3 bottom header
#define TRIG_PIN  7   // G7
#define ECHO_PIN  8   // G8

void setup() {
  // Initialize M5Unified with default settings (auto-detects device)
  M5.begin(); 

  // Optional: Configure display explicitly if auto-detect fails
  // For Atom S3, the screen usually initializes automatically with M5.begin()
  
  // Setup Display
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  M5.Lcd.setTextSize(2);
  
  Serial.begin(115200);
  Serial.println("M5Atom S3 Ultrasonic Test");
}

void loop() {
  long distance = readDistanceCM(TRIG_PIN, ECHO_PIN);
  
  // Clear area and show distance
  M5.Lcd.fillRect(0, 20, 128, 40, TFT_BLACK);
  M5.Lcd.setCursor(40, 20);
  M5.Lcd.setTextSize(3);
  
  if (distance < 0) {
    M5.Lcd.println("--");
    Serial.println("No object detected");
  } else {
    M5.Lcd.printf("%ld", distance);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  // Small text at bottom
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(0x808080, TFT_BLACK); // Gray color
  M5.Lcd.setCursor(35, 65);
  M5.Lcd.printf("cm (%d-%d)", TRIG_PIN, ECHO_PIN);
  
  delay(80);
}

long readDistanceCM(int trigPin, int echoPin) {
  long duration;
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 30000L);
  
  if (duration == 0) return -1;
  
  float distance = duration * 0.034 / 2;
  
  if (distance > 400 || distance < 2) return -1;
  
  return (long)distance;
}