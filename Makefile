PORT=ttyACM1

CROSS=arm-none-eabi-
BOSSAC=bossac

CFLAGS=-g -nostartfiles -O0 -DF_CPU=48000000UL -mcpu=cortex-m0plus -mthumb
LFLAGS=-Wl,-T,trinketm0.ld

build:
	${CROSS}gcc ${CFLAGS} ${LFLAGS} *.c -o kernel.elf
	${CROSS}objcopy kernel.elf -O binary kernel.bin

disasm:
	${CROSS}objdump -D kernel.elf > kernel.elf.asm
	${CROSS}nm kernel.elf > kernel.elf.nm
	hexdump kernel.bin > kernel.bin.hexdump

clean:
	rm *.bin *.elf *.nm *.asm *.hexdump 2> /dev/null

flash:
	${BOSSAC} -i -d --port=${PORT} -i -e -w -v kernel.bin -R --offset 0x2000

