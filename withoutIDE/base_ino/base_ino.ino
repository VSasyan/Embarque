/*
	base.c
	Turns on an LED on for one second, then off for one second, repeatedly.
 */

int analogID = A0;
 
void afficherBin(unsigned n) {
	unsigned bit = 0 ;
	unsigned mask = 1 ;
	for (int i = 0 ; i < 32 ; ++i) {
		bit = (n & mask) >> i ;
		Serial.print(bit) ;
		mask <<= 1 ;
	}
	Serial.println("");
}

char* bin(unsigned long int i) {
    static char buffer [1+sizeof (unsigned long int)*8] = { 0 };
    char *p=buffer-1+sizeof (unsigned long int)*8;
    do { *--p = '0' + (i & 1); i >>= 1; } while (i);
    return p;
}

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
//	afficherBin(DDRB);
        Serial.println(bin(PORTB));
}

// the loop function runs over and over again forever
void loop() {
	DDRD = 0b10010000;
	PORTB ^= 0b01000000;
//	afficherBin(PORTB);
        Serial.println(bin(PORTB));
	delay(500);
}

