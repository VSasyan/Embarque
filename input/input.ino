/*
  Amina et Valentin
 */
 
 const int buttonPin = 2;
 const int ledPin = 3;
 int buttonState = LOW;
 int speed = 8;
 int oldButtonState = LOW;


// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(13, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  oldButtonState = buttonState;
  buttonState = digitalRead(buttonPin);
  
  if ((oldButtonState == LOW) && (buttonState == HIGH)) {
    speed /= 2; 
    if (speed < 2) speed = 8;
    Serial.print("Speed : ");
    Serial.print(speed);
    Serial.print("\n");
  }
  int i = 0;
  for (i = 0; i < 256; i++) {
    analogWrite(ledPin, i);
    delay(speed);
  }
  for (i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(speed);
  }
}
