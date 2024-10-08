#include <SoftwareSerial.h>
const int MAX485_RE_NEG = 4; // RE and DE pin connected to pin 4
const int RS485Transmit = HIGH;
const int RS485Receive = LOW;

uint8_t lowLevelPin = 14; // Example pin for low water level sensor
uint8_t mediumLevelPin = 27; // Example pin for medium water level sensor
uint8_t highLevelPin = 26; // Example pin for high water level sensor

SoftwareSerial rs485(16, 17); // RX, TX

void setup() {
 pinMode(MAX485_RE_NEG, OUTPUT);
 digitalWrite(MAX485_RE_NEG, RS485Transmit); // Set to transmit mode
 Serial.begin(9600);
 rs485.begin(9600);
 pinMode(lowLevelPin, INPUT_PULLDOWN);
 pinMode(mediumLevelPin, INPUT_PULLDOWN);
 pinMode(highLevelPin, INPUT_PULLDOWN);
}

void loop() {
  // Read the status of water level sensors
 int lowLevelStatus = digitalRead(lowLevelPin);
 int mediumLevelStatus = digitalRead(mediumLevelPin);
 int highLevelStatus = digitalRead(highLevelPin);

  // Print the sensor values to the serial monitor
 Serial.print("Low Level: ");
 Serial.println(lowLevelStatus);
 Serial.print("Medium Level: ");
 Serial.println(mediumLevelStatus);
 Serial.print("High Level: ");
 Serial.println(highLevelStatus);

  // Send water level status to the control unit
 rs485.print(lowLevelStatus);
 rs485.print(mediumLevelStatus);
 rs485.println(highLevelStatus);

 delay(1000); // Adjust delay as necessary
}