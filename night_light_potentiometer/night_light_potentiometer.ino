// Define LED pins
int ledPins[] = {3, 5, 6, 9, 10, 11};
const int numLEDs = 6;

// Potentiometer pin
int potPin = A0;

void setup() {
  // Set LED pins as outputs
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Read potentiometer value (0-1023)
  int potValue = analogRead(potPin);

  // Map potentiometer value to PWM range (0-255)
  int brightness = map(potValue, 0, 1023, 0, 255);

  // Set brightness for each LED
  for (int i = 0; i < numLEDs; i++) {
    analogWrite(ledPins[i], brightness);
  }
}