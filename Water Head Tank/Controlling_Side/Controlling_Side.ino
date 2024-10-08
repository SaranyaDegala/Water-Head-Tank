#include <SoftwareSerial.h>

const int MAX485_RE_NEG = 4; // RE and DE pin connected to pin 4
const int RS485Transmit = HIGH;
const int RS485Receive = LOW;

const int lowLevelLEDPin = 23; // Example pin for low level LED
const int mediumLevelLEDPin = 21; // Example pin for medium level LED
const int highLevelLEDPin = 22; // Example pin for high level LED

SoftwareSerial rs485(16, 17); // RX, TX

void setup() {
 pinMode(MAX485_RE_NEG, OUTPUT);
 digitalWrite(MAX485_RE_NEG, RS485Receive); // Set to receive mode
 Serial.begin(9600);
 rs485.begin(9600);

  // Set LED pins as outputs
 pinMode(lowLevelLEDPin, OUTPUT);
 pinMode(mediumLevelLEDPin, OUTPUT);
 pinMode(highLevelLEDPin, OUTPUT);
}

void loop() {
 if (rs485.available() >= 3) { // Check if there are enough bytes available
    // Read water level status from the field unit
 int lowLevelStatus = rs485.read() - '0'; // Convert ASCII to integer
 int mediumLevelStatus = rs485.read() - '0'; // Convert ASCII to integer
 int highLevelStatus = rs485.read() - '0'; // Convert ASCII to integer

    // Print the received water level status to the serial monitor Serial.print("Low Level: ");
 Serial.println(lowLevelStatus);
 Serial.print("Medium Level: ");
 Serial.println(mediumLevelStatus);
 Serial.print("High Level: ");
 Serial.println(highLevelStatus);

    // Process the received water level status and control the LEDs
 digitalWrite(lowLevelLEDPin, lowLevelStatus);
 digitalWrite(mediumLevelLEDPin, mediumLevelStatus);
 digitalWrite(highLevelLEDPin, highLevelStatus);
 }
}
