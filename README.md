# Timer and interrupts test

C blink example using timer and interrupts on ATmega328P (Arduino Uno).

### Installation

This example uses AVRDUDE, AVR Libc and avr-gcc:

https://www.nongnu.org/avrdude/
https://www.nongnu.org/avr-libc/
https://gcc.gnu.org/wiki/avr-gcc

Another way is to install Arduino IDE and specify the include path to Arduino include files in your project settings.

### Configurations

Specify the USB port where your board is connected:

```
# USB port where board is connected
USBPORT:=/dev/ttyACM0
```

### Running

```
make
```
```
make install.blink
```