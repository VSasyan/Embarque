/*
  Amina et Valentin
 */
 const int ledPin = 3;
 int sensorValue = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  sensorValue = analogRead(A0);
  analogWrite(ledPin, sensorValue/4);
}
