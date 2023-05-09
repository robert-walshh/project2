#include "arduino_secrets.h"
#include "thingProperties.h"
#include <LiquidCrystal.h>
int Contrast = 50;

const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int seconds = 0;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  analogWrite(A3, Contrast);
  lcd.begin(16, 2);
}

void loop() {
  ArduinoCloud.update();
  lcd.setCursor(0, 0);
  lcd.print("Text");
  lcd.setCursor(0, 1);
  lcd.print(seconds);
  seconds += 1;
  delay(1000);
}
