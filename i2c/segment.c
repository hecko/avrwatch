// segment.c
// Unix-watch Hodinky ukazujuce okrem datumu a casu
// aj unix epochu
// verzia ATMEGA8/48/88/168/328
// RTC - Interny
// Display - 7+1 segmentovy led display
// Autor: Marek Blasko, Marcel Hecko 
// Licencia: GPL
//  -    A    -> PB0
// | |  F B   -> PB1 PB2
//  -    G    -> PB3
// | |  E C   -> PB4 PB5
//  - .  D DP -> PD6 PD7

#include <stdlib.h>
#include <inttypes.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

void segments_off(void) {
    //vsetko zhasnut (0xFF)
  PORTB &= ~PORTB; //clear na nuly
  PORTB = ~PORTB; // nastavit jednicky na zhasnutie
  PORTD &= ~PORTD; //clear na nuly
  PORTD = ~PORTD; // nastavit jednicky na zhasnutie
}

void segments(uint8_t a) {
  //segments_off();
  switch(a) {
    case 0:
      PORTB &= ~(1<<0);
      PORTB &= ~(1<<1);
      PORTB &= ~(1<<2);
      PORTB &= ~(1<<4);
      PORTB &= ~(1<<5);
      PORTD &= ~(1<<6);
    break;
    case 1:
      //teraz sa nieco zapne 
      PORTB &= ~(1<<2);
      PORTB &= ~(1<<4);
    break;
    case 2:
      PORTB &= ~(1<<0);
      PORTB &= ~(1<<1);
      PORTB &= ~(1<<3);
      PORTB &= ~(1<<4);
      PORTB &= ~(1<<5);
    break;
    case 3:
      PORTB &= ~(1<<0);
      PORTB &= ~(1<<1);
      PORTB &= ~(1<<3);
      PORTD &= ~(1<<6);
      PORTB &= ~(1<<5);
    break;
    case 4:
      PORTB &= ~(1<<1);
      PORTB &= ~(1<<2);
      PORTB &= ~(1<<3);
      PORTD &= ~(1<<6);
    break;
    case 5:
      PORTB &= ~(1<<0);
      PORTB &= ~(1<<2);
      PORTB &= ~(1<<3);
      PORTD &= ~(1<<6);
      PORTB &= ~(1<<5);
    break;
    case 6:
      PORTB &= ~(1<<0);
      PORTB &= ~(1<<2);
      PORTB &= ~(1<<3);
      PORTB &= ~(1<<4);
      PORTD &= ~(1<<6);
      PORTB &= ~(1<<5);
    break;
    case 7:
      PORTB &= ~(1<<0);
      PORTB &= ~(1<<1);
      PORTD &= ~(1<<6);
    break;
    case 8:
      PORTB &= ~(1<<0);
      PORTB &= ~(1<<1);
      PORTB &= ~(1<<2);
      PORTB &= ~(1<<3);
      PORTB &= ~(1<<4);
      PORTD &= ~(1<<6);
      PORTB &= ~(1<<5);
    break;
    case 9:
      PORTB &= ~(1<<0);
      PORTB &= ~(1<<1);
      PORTB &= ~(1<<2);
      PORTB &= ~(1<<3);
      PORTD &= ~(1<<6);
      PORTB &= ~(1<<5);
    break;
    case 10: //a
      PORTB &= ~(1<<0);
      PORTB &= ~(1<<1);
      PORTB &= ~(1<<2);
      PORTB &= ~(1<<3);
      PORTB &= ~(1<<4);
      PORTD &= ~(1<<6);
    break;
    case 11:
      PORTB &= ~(1<<1);
      PORTB &= ~(1<<2);
      PORTB &= ~(1<<4);
      PORTD &= ~(1<<6);
    break;
    case 12: //c
      PORTB &= ~(1<<0);
      PORTB &= ~(1<<2);
      PORTB &= ~(1<<4);
      PORTB &= ~(1<<5);
    break;
    default:
      PORTB &= ~(1<<3);
    break;
  }
  _delay_ms(250);
  //segments_off();
}

