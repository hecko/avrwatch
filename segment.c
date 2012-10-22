// segment.c
// Unix-watch Hodinky ukazujuce okrem datumu a casu
// aj unix epochu
// verzia ATMEGA8/48/88/168/328
// RTC - Interny
// Display - 7+1 segmentovy led display
// Autor: Marek Blasko, Marcel Hecko 

#include <stdlib.h>
#include <inttypes.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

void segments_off(void) {
  PORTB |= 0x3F; // nastavit jednicky na zhasnutie
  PORTD |= 0xC0; // nastavit jednicky na zhasnutie
}

void segments(uint8_t a) {

  static const unsigned char seg[] PROGMEM = {
  0b11110000, // 0 - ktore segmenty (A,B,C...) zasvietit, aby sme ukazali nulu
  0b10000001, // 1
  0b11011100, // 2
  0b11010101, // 3
  0b10110001, // 4
  0b01110101, // 5
  0b01111101, // 6
  0b11000001, // 7
  0b11111101, // 8
  0b11110101, // 9
  0b11110100, // (10 otocene o 90 stupnov)
  0b10101001, // 11
  0b00011100, // C (12)
  0b00000010, // DP (bodka) (13)
  0b00000100, // _ (podtrznik) (14)
  };  

  segments_off();

  unsigned char d;
  unsigned int i;

  d=pgm_read_byte(seg+a);

  for(i=0;i<=20;i++) { 
    PORTB &= ~(d&0x3F);
    PORTD &= ~(d&0xC0);
    _delay_ms(10);
    segments_off();
    _delay_ms(10);
  }
}

