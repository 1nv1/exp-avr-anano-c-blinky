#include <avr/io.h>
#include <avr/interrupt.h>

#define Clear(x) (x = x ^ x)

#define OCR1A_1S ((F_CPU / 256) - 1)

ISR(TIMER1_COMPA_vect) {
  PORTB ^= _BV(PORTB5);
}

int main(void) {
  // Init port
  DDRB |= _BV(DDB5);
  // Disable global interrupts
  cli();
  Clear(TCCR1A);
  Clear(TCCR1B);
  // Count for 1 second
  OCR1A = OCR1A_1S;
  // Configure timer1 for CTC mode
  TCCR1B |= (1 << WGM12);
  // Configure prescaler to 256
  TCCR1B |= (1 << CS12);
  // Set interrupt on compare match
  TIMSK1 |= (1 << OCIE1A);
  // Enable global interrupts
  sei();
  // Super-loop
  while(1);
}

