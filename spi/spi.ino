/*
	SPI communication
	Some tools.
  http://arduino.stackexchange.com/questions/16348/how-do-you-use-spi-on-an-arduino
 */
#include <SPI.h>

// pinMOSI => 11
// pinMISO => 12
// pinSCK => 13
// pinSS => 10

char* bin(unsigned long int i) {
	static char buffer [1+sizeof (unsigned long int)*8] = { 0 };
	char *p=buffer-1+sizeof (unsigned long int)*8;
	do { *--p = '0' + (i & 1); i >>= 1; } while (i);
	return p;
}

void setup() {
  Serial.begin(9600);   // debugging
  Serial.println("Master bonjour");
  digitalWrite(SS, HIGH);
  SPI.begin();
  //SPI.setClockDivider(SPI_CLOCK_DIV2);
}

void loop() {
  char TSIc[5] = "TSIc";
  SPI.beginTransaction(SPISettings(512000, MSBFIRST, SPI_MODE0));
  digitalWrite (SS, LOW);        // assert Slave Select
  SPI.transfer(TSIc, 5);
  digitalWrite (SS, HIGH);       // de-assert Slave Select
  SPI.endTransaction();
  Serial.println("Master envoye");
  delay(1000);
}

