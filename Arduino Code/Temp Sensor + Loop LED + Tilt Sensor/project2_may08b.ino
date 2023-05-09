#include "arduino_secrets.h"
#include "thingProperties.h"

#define temp_sensor_pin A1

int tiltSensorPin = A0; // Define the tilt sensor input pin
int ledPin = 3; // Define the LED output pin
int tiltThreshold = 200; // Define the tilt threshold value



void setup() {
  
 pinMode(6, OUTPUT);
 pinMode(ledPin, OUTPUT); // Set the LED pin as an output

  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

 

}

void loop() {
ArduinoCloud.update();

  int tiltSensorValue = analogRead(tiltSensorPin); // Read the tilt sensor value
  Serial.println(tiltSensorValue); // Print the tilt sensor value to the serial monitor for debugging

  if (tiltSensorValue > tiltThreshold) { // If the tilt sensor value is above the threshold
    digitalWrite(ledPin, HIGH); // Turn the LED on
    motion = true;
  } else { // If the tilt sensor value is below the threshold
    digitalWrite(ledPin, LOW); // Turn the LED off
    motion = false;
  }

delay(100); // Add a short delay to avoid reading the sensor too frequently
    
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



}

/*
  Since Temperature is READ_WRITE variable, onTemperatureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTemperatureChange()  {
  // Add your code here to act upon Temperature change
}


/*
  Since Motion is READ_WRITE variable, onMotionChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMotionChange()  {
  // Add your code here to act upon Motion change
}