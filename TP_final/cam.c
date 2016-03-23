#include <bcm2835.h>
#include <stdio.h>

#define PIN RPI_GPIO_P1_05

int prise = 0;

int main (int argc, char **argv) {

	if(!bcm2835_init()) {return 1;}

	bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT);
	//bcm2835_gpio_set_pud(PIN, BCM2835_GPIO_PUD_UP);

	while (1) {
		uint8_t value = bcm2835_gpio_lev(PIN);
		if (value == 0) {
			if (prise == 0) {
				printf("\n\nPassage en mode Capture\n");
				prise = 1;
				//Creation du dossier de prises
				system("./creation.sh");
			}
			// Capture
			printf("Prise de la photo...\n");
			system("./prise_photo.sh");
			printf("Photo prise.\n\n");
			// Attente
			bcm2835_delay(2000);
		} else {
			if (prise == 1) {
				printf("Arret du mode Capture\n");
				prise = 0;
			}
		}
		
		//printf("read from pin %d: %d\n", PIN, value);

		//bcm2835_delay(500);
	}

	bcm2835_close();

	return 0;
}



