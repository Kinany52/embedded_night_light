#include <IRremote.h>

// Define LED pins
int ledPins[] = {3, 5, 6, 9, 10, 11};
const int numLEDs = 6;

// IR Receiver pin
const int irPin = A1;

// Variables
int brightness;            // Default brightness (0-255)
bool isOn = false;             // Toggle state for LEDs (ON/OFF)

// Debounce variables
unsigned long lastCode = 0;    // Stores the last processed code
unsigned long lastTime = 0;    // Stores the time of the last processed code
const unsigned long debounceDelay = 200; // Debounce delay in milliseconds

void setup() {
  // Initialize LED pins as outputs
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Start IR receiver
  IrReceiver.begin(irPin, ENABLE_LED_FEEDBACK);
  Serial.begin(9600); // Enable Serial for debugging
}

void loop() {
  // Check for incoming IR signals
  if (IrReceiver.decode()) {
    // Handle NEC protocol only
    if (IrReceiver.decodedIRData.protocol == NEC) {
      unsigned long code = IrReceiver.decodedIRData.decodedRawData;

      // Filter out repeat codes (NEC repeat signal is 0xFFFFFFFF)
      if (code != 0xFFFFFFFF) {
        // Debounce: process code only if it's different or enough time has passed
        if (millis() - lastTime > debounceDelay || code != lastCode) {
          lastCode = code;
          lastTime = millis();

          // Handle specific codes
          if (code == 0xBA45FF00) { // Power button
            isOn = !isOn; // Toggle ON/OFF state
            brightness = isOn ? 255 : 0; // Full brightness when ON, 0 when OFF
            updateLEDs();
            Serial.println("Power toggled.");
          } 
          else if (code == 0xB946FF00 || code == 0xF609FF00) { // Volume Up or Arrow Up
            //brightness = 0;
            brightness += 25.5; // Increase brightness
            brightness = constrain(brightness, 0, 255); // Ensure brightness stays within range
            updateLEDs();
            Serial.println("Brightness increased.");
          } 
          else if (code == 0xEA15FF00 || code == 0xF807FF00) { // Volume Down or Arrow Down
            //brightness = 255;
            brightness -= 25.5; // Decrease brightness
            brightness = constrain(brightness, 0, 255); // Ensure brightness stays within range
            updateLEDs();
            Serial.println("Brightness decreased.");
          }
        }
      }
    }

    // Resume IR receiver
    delay(10); // Small delay to stabilize receiver
    IrReceiver.resume();
  } else {
    // Safety mechanism to reset receiver if no valid signal is processed
    if (millis() - lastTime > 1000) { // If no valid signal for 1 second
      IrReceiver.enableIRIn(); // Reinitialize receiver
      lastTime = millis(); // Reset debounce timer
    }
  }
}

// Function to update LED brightness
void updateLEDs() {
  for (int i = 0; i < numLEDs; i++) {
    analogWrite(ledPins[i], brightness);
  }
}