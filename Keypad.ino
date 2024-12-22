#include <Keypad.h>

// Constants for row and column sizes
const byte ROWS = 4;
const byte COLS = 4;

// Array to represent keys on the keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connections to Arduino (update pin numbers)
byte rowPins[ROWS] = {6, 7, 8, 9};   // Rows connected to pins 6, 7, 8, 9
byte colPins[COLS] = {10, 11, 12, 13}; // Columns connected to pins 10, 11, 12, 13

// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Setup serial monitor
  Serial.begin(19200);
}

void loop() {
  // Get key value if pressed
  char customKey = customKeypad.getKey();

  if (customKey) {
    // Print key value to serial monitor
    Serial.println(customKey);
  }
}
