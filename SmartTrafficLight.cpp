// Class Definitions

class GasSensor {
private:
  int pin;
  int threshold;

public:
  // Constructor to initialize gas sensor pin and threshold
  GasSensor(int pin, int threshold) : pin(pin), threshold(threshold) {
    pinMode(pin, INPUT);
  }

  // Method to read gas value
  int readGasValue() {
    return analogRead(pin);
  }

  // Method to check if gas value exceeds threshold
  bool isGasDetected() {
    return readGasValue() > threshold;
  }
};

class Buzzer {
private:
  int pin;

public:
  // Constructor to initialize buzzer pin
  Buzzer(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
  }

  // Method to turn the buzzer on with a tone
  void turnOn(int frequency = 1000) {
    tone(pin, frequency); // Activate buzzer with a specific tone
  }

  // Method to turn the buzzer off
  void turnOff() {
    noTone(pin); // Deactivate buzzer
    digitalWrite(pin, LOW);
  }
};

// Constants
const int gasSensorPin = A0;  // Gas sensor connected to Analog pin A0
const int buzzerPin = 12;     // Buzzer connected to digital pin 12
const int gasThreshold = 400; // Adjust threshold based on calibration

// Objects
GasSensor gasSensor(gasSensorPin, gasThreshold);
Buzzer buzzer(buzzerPin);

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  // Read gas value
  int gasValue = gasSensor.readGasValue();
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // Check if gas is detected
  if (gasSensor.isGasDetected()) {
    Serial.println("Gas detected! Buzzer ON");
    buzzer.turnOn(); // Activate buzzer
  } else {
    Serial.println("No gas detected. Buzzer OFF");
    buzzer.turnOff(); // Deactivate buzzer
  }

  delay(1000); // Delay for stability
}