# Compiler options

CC=avr-gcc
# Optimize for size 
# MCU clock speed
# Define processor
CFLAGS= -Os -DF_CPU=16000000UL -mmcu=atmega328p
BINS=blink

# USB port where board is connected
USBPORT:=/dev/ttyACM0

# Compiling
all: $(BINS)

# Compile .c files to .out files
%.out: %.c
	$(CC) $(CFLAGS) $< -o $@

%.hex: %.out
	avr-objcopy -O ihex -R .eeprom $< $@

# Upload to board
install.%: %.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P ${USBPORT} -b 115200 -U flash:w:$<

clean:
	rm -f *.hex *.out