const int pumpPin1 = 4; // First pump is controlled by digital pin 11
const int pumpPin2 = 2; // Second pump is controlled by digital pin 12
const int pumpPin3 = 6;
void setup() {
  // Initialize the serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // Set the pump control pins as outputs:
  pinMode(pumpPin1, OUTPUT);
  pinMode(pumpPin2, OUTPUT);
  pinMode(pumpPin3, OUTPUT);

  // Ensure the pumps are off at startup:
  digitalWrite(pumpPin1, LOW);
  digitalWrite(pumpPin2, LOW);
  digitalWrite(pumpPin3, LOW);
}


String incomingByte ;    

void loop() {

  if (Serial.available() > 0) {

  incomingByte = Serial.readStringUntil('\n');
  Serial.println(incomingByte);

    if (incomingByte == "pump1") {

      digitalWrite(pumpPin1, HIGH); // Turn the first pump on
      digitalWrite(pumpPin2, LOW);// Ensure the second pump is off
      digitalWrite(pumpPin3, LOW);
    
      Serial.write("pump on");

    }

    else if (incomingByte == "pump2") {

      digitalWrite(pumpPin1, LOW); // Ensure the first pump is off
      digitalWrite(pumpPin2, HIGH); // Turn the second pump on
      digitalWrite(pumpPin3, LOW);
      // Serial.write("Led off");
      Serial.write("pump on");

    }
    else if (incomingByte == "pump3") {

      digitalWrite(pumpPin1, LOW); // Ensure the first pump is off
      digitalWrite(pumpPin2, LOW); // Turn the second pump on
      digitalWrite(pumpPin3, HIGH);
      // Serial.write("Led off");
      Serial.write("pump on");

    }

    else if (incomingByte == "pumpsoff"){
      digitalWrite(pumpPin1, LOW);
      digitalWrite(pumpPin2, LOW);
      digitalWrite(pumpPin3, LOW );
      Serial.write("PUMPS OFF");

    }

  }

}
