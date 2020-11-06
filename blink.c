
/*
 *
 * Physical address from SAMD21E18A datasheet
 *
 * */

#define GPIO_BASE 0x41004400
#define PORTDIRSET 0x41004408
#define PORTOUT 0x41004410
#define PORTCLR 0x41004414
#define LED_GPIO_BIT 10

/** GPIO Register set */
volatile unsigned int* gpio;

/** Simple loop variable */
volatile unsigned int tim;

/** Main function - we'll never return from here */
void kernel_main() {
	/* Set output direction for LED pin*/
	gpio = (unsigned int*)PORTDIRSET;
	*gpio |= (1 << LED_GPIO_BIT);

	/* Never exit */
	while (1) {
		for (tim = 0; tim < 5000; tim++)
			;

		/* Clear LED output pin*/
		gpio = (unsigned int*)PORTCLR;
		*gpio = (1 << LED_GPIO_BIT);

		for (tim = 0; tim < 5000; tim++)
			;

		/* Set LED output pin*/
		gpio = (unsigned int*)PORTOUT;
		*gpio = (1 << LED_GPIO_BIT);
	}
}
