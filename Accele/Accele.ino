/*
	Accele (i2c communication)
	Some tools.
 */
#include <Wire.h>

char* bin(unsigned long int i) {
	static char buffer [1+sizeof (unsigned long int)*8] = { 0 };
	char *p=buffer-1+sizeof (unsigned long int)*8;
	do { *--p = '0' + (i & 1); i >>= 1; } while (i);
	return p;
}

void setup() {
	Serial.begin(9600);
	Wire.begin();
	
}

// the loop function runs over and over again forever
void loop() {
  Wire.beginTransmission(0x68);
  
  // Transmission de la position registre 0x11 = 3B
  Wire.write(0x3B);
  
  //Transmission fini (envoie des donnees)
  Wire.endTransmission(false);
  
  //Requete de 14 caracteres a l'adresse du device slave 0x68
  Wire.requestFrom(0x68, 14, true);
  
  //Récupération des accelerations
  int a_x = Wire.read() << 8 | Wire.read();
  int a_y = Wire.read() << 8 | Wire.read();
  int a_z = Wire.read() << 8 | Wire.read();
  
  //Recuperation de la temperature
  int t = Wire.read() << 8 | Wire.read();
  
  //Recuperation des vitesses
  int v_x = Wire.read() << 8 | Wire.read();
  int v_y = Wire.read() << 8 | Wire.read();
  int v_z = Wire.read() << 8 | Wire.read();
  
  //Affichage
  Serial.println("\n\n");
  
  Serial.println("Acceleration :");
    Serial.print("   - x : "); Serial.print(a_x); Serial.println();
    Serial.print("   - y : "); Serial.print(a_y); Serial.println();
    Serial.print("   - z : "); Serial.print(a_z); Serial.println();
    
  Serial.print("Temperature : "); Serial.print(t); Serial.println();
  
  Serial.println("Vitesses :");
  
    Serial.print("   - x : "); Serial.print(v_x); Serial.println();
    Serial.print("   - y : "); Serial.print(v_y); Serial.println();
    Serial.print("   - z : "); Serial.print(v_z); Serial.println();
   
  
  delay(1000);
}
