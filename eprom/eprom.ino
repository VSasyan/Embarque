/*
  EPROM - Amina, Valentin
 */
 
  int w_0 = 2;
  int w_1 = 3;
  int w_2 = 4;
  int w_3 = 5;
  int w_4 = 6;
  int w_5 = 7;
  int w_6 = 8;
  int w_7 = 9;
  
  int r_0 = 12;
  int r_1 = 11;
  int r_2 = A0;
  int r_3 = A1;
  int r_4 = A2;
  int r_5 = A3;
  int r_6 = A4;
  int r_7 = A5;
  char out[3];
 
void setup() {
  Serial.begin(9600);
  Serial.println("Hello");

  pinMode(w_0, OUTPUT);
  pinMode(w_1, OUTPUT);
  pinMode(w_2, OUTPUT);
  pinMode(w_3, OUTPUT);
  pinMode(w_4, OUTPUT);
  pinMode(w_5, OUTPUT);
  pinMode(w_6, OUTPUT);
  pinMode(w_7, OUTPUT);
  
  pinMode(r_0, INPUT);
  pinMode(r_1, INPUT);
  pinMode(r_2, INPUT);
  pinMode(r_3, INPUT);
  pinMode(r_4, INPUT);
  pinMode(r_5, INPUT);
  pinMode(r_6, INPUT);
  pinMode(r_7, INPUT);
}

void loop() {
  
  if (Serial.available()) {
    if (Serial.read() == 'd') {
      Serial.println("Debut...");
      
      int v_0, v_1, v_2, v_3, v_4, v_5, v_6, v_7;
      
      for (v_7 = 0; v_7 < 2; v_7++) {
      for (v_6 = 0; v_6 < 2; v_6++) {
      for (v_5 = 0; v_5 < 2; v_5++) {
      for (v_4 = 0; v_4 < 2; v_4++) {
      for (v_3 = 0; v_3 < 2; v_3++) {
      for (v_2 = 0; v_2 < 2; v_2++) {
      for (v_1 = 0; v_1 < 2; v_1++) {
      for (v_0 = 0; v_0 < 2; v_0++) {
        // Adresse :
        digitalWrite(w_0, v_0);
        digitalWrite(w_1, v_1);
        digitalWrite(w_2, v_2);
        digitalWrite(w_3, v_3);
        digitalWrite(w_4, v_4);
        digitalWrite(w_5, v_5);
        digitalWrite(w_6, v_6);
        digitalWrite(w_7, v_7);  
        
        // Lecture :
        int result =
          digitalRead(r_0) + 
          digitalRead(r_1) * 2 +
          digitalRead(r_2) * 4 +
          digitalRead(r_3) * 8 +
          digitalRead(r_4) * 16 +
          digitalRead(r_5) * 32 +
          digitalRead(r_6) * 64 +
          digitalRead(r_7) * 128;
  
        // Affichage :
        sprintf(out, "%02X", result);
        out[2]=0;
        Serial.print(v_7);
        Serial.print(v_6);
        Serial.print(v_5);
        Serial.print(v_4);
        Serial.print(v_3);
        Serial.print(v_2);
        Serial.print(v_1);
        Serial.print(v_0);
        Serial.print(" : ");
        Serial.print(out);
        Serial.println();
      }
      }
      }
      }
      }
      }
      }
      }
    }
  }
}

