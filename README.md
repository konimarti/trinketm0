# Adafruit Trinket M0 Bare Metal C Programming

This is a very simple example to blink the on-board LED on the Adafruit Trinket M0 with a pure C program. 
The Trinket M0 uses an ARM Cortex M0+ processor (ATSAMD21E18A).

# Relevant Datasheets
* [SAMD21E18A]( https://cdn.sparkfun.com/datasheets/Dev/Arduino/Boards/Atmel-42181-SAM-D21_Datasheet.pdf)
* [Adafruit Trinket M0](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-trinket-m0-circuitpython-arduino.pdf)

# Dependencies
* Install the cross-compiling toolchain for ARM processors (```arm-none-eabi-gcc``` and ```arm-none-eabi-binutils```)
* Install the flashing utiliy bossa for your platform (for Arch Linux: [Bossa AUR](https://aur.archlinux.org/packages/bossa/))

# Building and Flashing
* Plug in your Trinket and check the port (e.g. /dev/ttyACM0 or /dev/ttyACM1) 
* Adjust the port in the Makefile accordingly
* Then do the building and flashing:

	```
	make build
	make flash
	```

# Credits
* This example has been put together by looking at the following very helpful resources:
	- [Tutorial on Bare Metal Programming on the Raspberry]( https://github.com/BrianSidebotham/arm-tutorial-rpi)
	- [Run C program on ARM Cortex M3](https://jacobmossberg.se/posts/2018/08/11/run-c-program-bare-metal-on-arm-cortex-m3.html#c-program
)
