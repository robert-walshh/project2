#include "arduino_secrets.h"
#include "thingProperties.h"

#define temp_sensor_pin A1



void setup() {

  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

 pinMode(6, OUTPUT);

}

void loop() {
ArduinoCloud.update();


digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)


delay(500);

  // Read temperature sensor data
  int sensor_data = analogRead(temp_sensor_pin);
  temperature =  ( 4.4 * sensor_data * 26) / 1024.0;
  temperature = floor(temperature * 10) / 10.0;

  Serial.print("Current Temperature: ");
  Serial.println(temperature);

  

  digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW


  delay(1000);



  // Print temperature to serial monitor and LCD

  Serial.print("Current Temperature:");
  Serial.println(temperature);


  delay(1000);

}

/*
  Since Temperature is READ_WRITE variable, onTemperatureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTemperatureChange()  {
  // Add your code here to act upon Temperature change
}
