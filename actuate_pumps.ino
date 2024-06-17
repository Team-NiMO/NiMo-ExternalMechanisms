
const int pumpPin1 = 4;
const int pumpPin2 = 3;
const int pumpPin3 = 2;
void setup() {
  // Initialize the serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // Set the pump control pins as outputs:
  pinMode(pumpPin1, OUTPUT);
  pinMode(pumpPin2, OUTPUT);
  pinMode(pumpPin3, OUTPUT);

  // Ensure the pumps are off at startup:
  digitalWrite(pumpPin1, HIGH);
  digitalWrite(pumpPin2, HIGH);
  digitalWrite(pumpPin3, HIGH);
}


String incomingByte ;    

void loop() {

  if (Serial.available() > 0) {

  incomingByte = Serial.readStringUntil('\n');
  Serial.println(incomingByte);

    if (incomingByte == "pump1") {

      digitalWrite(pumpPin1, LOW); // Turn the first pump on
      digitalWrite(pumpPin2, HIGH);// Ensure the second pump is off
      digitalWrite(pumpPin3, HIGH);
    
      Serial.write("pump on");

    }

    else if (incomingByte == "pump2") {

      digitalWrite(pumpPin1, HIGH); // Ensure the first pump is off
      digitalWrite(pumpPin2, LOW); // Turn the second pump on
      digitalWrite(pumpPin3, HIGH);
      // Serial.write("Led off");
      Serial.write("pump on");

    }
    else if (incomingByte == "pump3") {

      digitalWrite(pumpPin1, HIGH); // Ensure the first pump is off
      digitalWrite(pumpPin2, HIGH); // Turn the second pump on
      digitalWrite(pumpPin3, LOW);
      // Serial.write("Led off");
      Serial.write("pump on");

    }

    else if (incomingByte == "pumpsoff"){
      digitalWrite(pumpPin1, HIGH);
      digitalWrite(pumpPin2, HIGH);
      digitalWrite(pumpPin3, HIGH);
      Serial.write("PUMPS OFF");

    }

  }

}
