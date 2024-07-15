#include <Arduino.h>

/*
Pico USB stuff
V205
aaaa

*/



// Define the baud rate for both UART interfaces
const int baudRate = 115200; // Baud rate for the Pi console probe

void setup() {
  // Start both serial interfaces

  Serial.begin(baudRate);
  Serial2.begin(baudRate);

  // Optional: print a message to the console
  Serial.println("Serial Forwarding between Serial2 and Serial has started.");
}

void loop() {
  // Check if data is available on Serial2 and forward it to Serial

  if (Serial2.available()) {
    int byteFromSerial2 = Serial2.read();
    Serial.write(byteFromSerial2);
  }

  // Check if data is available on Serial and forward it to Serial2
  if (Serial.available()) {
    int byteFromSerial = Serial.read();
    Serial2.write(byteFromSerial);
  }
}