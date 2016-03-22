/*
	DJ.c
	Turns on an according to the volume.
 */

int analogID = A0;
int sensorValue = 0;

float maxi = 280;
float led_5 = maxi / 6 * 5;
float led_4 = maxi / 6 * 4;
float led_3 = maxi / 6 * 3;
float led_2 = maxi / 6 * 2;
float led_1 = maxi / 6 * 1;

char* bin(unsigned long int i) {
	static char buffer [1+sizeof (unsigned long int)*8] = { 0 };
	char *p=buffer-1+sizeof (unsigned long int)*8;
	do { *--p = '0' + (i & 1); i >>= 1; } while (i);
	return p;
}

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(analogID, INPUT); // on lit ici
	DDRB = 0b00011111; // sorties LED
	PORTB = 0b00000000; // Tout éteint
}

// the loop function runs over and over again forever
void loop() {
	sensorValue = analogRead(A0);

	Serial.println(sensorValue);

	if (sensorValue > led_5) {
		PORTB = 0b00011111;
	} else if (sensorValue > led_4) {
		PORTB = 0b00001111;
	} else if (sensorValue > led_3) {
		PORTB = 0b00000111;
	} else if (sensorValue > led_2) {
		PORTB = 0b00000011;
	} else if (sensorValue > led_1) {
		PORTB = 0b00000001;
	} else {
		PORTB = 0b00000000;
	}
}
