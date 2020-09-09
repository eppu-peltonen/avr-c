#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// Slows the CPU clock to usable range
#define PRESCALER 10
#define CLOCK_RATE 15998976
// Number of timer ticks in a second
#define COUNTER_VALUE (CLOCK_RATE >> PRESCALER)

// TIMER1 compare interrupt service routine
// fires when counter value matches OCR1A
ISR(TIMER1_COMPA_vect) {
    PORTB ^= _BV(PORTB5);
}



int main ()
{
    // B5 bit to output mode
    // Maps to Arduino internal led on pin 13
    DDRB |= _BV(PORTB5);

    // Timer configuration
    OCR1A = COUNTER_VALUE;

    TCCR1A = 0x00;
    TCCR1B |= (1 << WGM12); //Clear timer on compare (CTC). Compare to OCR1A
    TCCR1B |= (1 << CS10) | (1 << CS12); // Set prescaler to 1024

    // Interrupt
    TIMSK1 |= (1 << OCIE1A);

    // Enable interrupts
    sei();
    
    // Main loop for something useful
    while (true) {
        
    }
}