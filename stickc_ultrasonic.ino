#include <M5StickC.h>

const int trigPin = 26;
const int echoPin = 36; // Input-only pin

long duration;
int distance;

void setup() {
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send 10us pulse to Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read Echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate Distance (Speed of sound = 0.034 cm/us)
  distance = duration * 0.034 / 2;

  // Update Display
  M5.Lcd.fillRect(10, 40, 100, 20, BLACK);
  M5.Lcd.setCursor(10, 40);
  if (distance > 0 && distance < 400) {
    M5.Lcd.print(distance);
    M5.Lcd.print(" cm");
  } else {
    M5.Lcd.print("Far");
  }
  
  delay(50);
}