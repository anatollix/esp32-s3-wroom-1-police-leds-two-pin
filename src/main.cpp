#include <Arduino.h>

// Red LED on GPIO4
#define LED_RED_PIN 4

// Blue LED on GPIO5
#define LED_BLUE_PIN 5

// Blink timing (milliseconds)
#define BLINK_ON_MS  250
#define BLINK_OFF_MS 100

void flashLed(uint8_t pin) {
  digitalWrite(pin, HIGH);
  delay(BLINK_ON_MS);
  digitalWrite(pin, LOW);
  delay(BLINK_OFF_MS);
}

void setup() {
  Serial.begin(115200);
  delay(3000);

  Serial.println("\n========================================");
  Serial.println("   ESP32-S3 Police LEDs (Two-Pin)");
  Serial.println("========================================");
  Serial.printf("Board: ESP32-S3-WROOM-1\n");
  Serial.printf("CPU Freq: %d MHz\n", ESP.getCpuFreqMHz());
  Serial.printf("Free Heap: %d bytes\n", ESP.getFreeHeap());
  Serial.printf("Red  LED -> GPIO%d\n", LED_RED_PIN);
  Serial.printf("Blue LED -> GPIO%d\n", LED_BLUE_PIN);
  Serial.println("========================================\n");

  pinMode(LED_RED_PIN,  OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);

  digitalWrite(LED_RED_PIN,  LOW);
  digitalWrite(LED_BLUE_PIN, LOW);
}

void loop() {
  flashLed(LED_RED_PIN);
  flashLed(LED_BLUE_PIN);
}
