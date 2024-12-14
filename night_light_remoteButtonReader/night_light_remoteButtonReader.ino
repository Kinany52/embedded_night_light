#include <IRremote.h>

// Define the IR receiver pin
const int irPin = 7;

void setup() {
  // Initialize the IR receiver
  IrReceiver.begin(irPin, ENABLE_LED_FEEDBACK); // Start the receiver on the specified pin
  Serial.begin(9600); // Start serial communication
}

void loop() {
  // Check if a signal is received
  if (IrReceiver.decode()) {
    // Print the received value in HEX format
    Serial.print("Received code: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    // Resume the receiver to process the next signal
    IrReceiver.resume();
  }
}
