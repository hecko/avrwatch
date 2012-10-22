// segment.c
// Unix-watch Hodinky ukazujuce okrem datumu a casu
// aj unix epochu
// verzia ATMEGA8/48/88/168/328
// RTC - Interny
// Display - 7+1 segmentovy led display
// Autor: Marek Blasko, Marcel Hecko 

// standadne kniznice
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "rtc.h"	// rtc utility
#include "segment.h"	//7-segment library

// globalne premenne
volatile unsigned char sec1 = 0;
volatile unsigned char sec10 = 0;
volatile unsigned char min1 = 0;
volatile unsigned char min10 = 0;
volatile unsigned char hod = 0;
volatile unsigned char show = 1;
volatile unsigned char setup = 1;
volatile unsigned char show_setup = 1;
volatile unsigned char setup_hod = 1;
volatile unsigned char setup_min = 1;

void increment_time(void) {
  sec1++;
  if(sec1>9){
    sec1=0;
    sec10++;
  } 
  if(sec10>5){
    sec10=0;
    min1++; 
  }
  if(min1>9){
    min1=0;
    min10++; 
  }
  if(min10>5){
    min10=0;
    hod++; 
  }
  if(hod>11){
    hod=0;
  }
}

// rutina na zachytavanie RTC preruseni
ISR(TIMER2_OVF_vect) {
  increment_time();
}

//pin D2
ISR(INT0_vect) {
  segments(13);
  //ked podrzime gombicek dlhsie prejdeme, alebo odideme z/do setup modu
  volatile unsigned char val;
  volatile unsigned int i = 0;
  val = PIND & 0x04; //nacitanie hodnoty tlacitka na D2
  while (val==0x00) {
    val = PIND & 0x04; 
    i++; //pocitaj ako dlho mame stlacene tlacitko D2
    _delay_ms(10);
    if (i>=100) {
      segments(14);
    }
  }

  if (i>=100) { //ak bolo tlacitko stlacene dlho
    if (setup==1) { //ak nie sme v setupe tak startujeme setup mode
      setup=0;
      setup_hod=0;
    } else { //ak sme uz v setupe, tak sa z neho exitneme
      setup=1;
      setup_hod=1;
      setup_min=1;
    }
    segments_off();
  } else {
    if (setup==0 && setup_hod==0) { // ak sme drzali tlacitko kratko tak sa prepneme na nastavovanie daneho parametru 
      setup_hod=1;
      setup_min=0;
    } else {  //ak nie sme v setupe po kratkom stlaceni tlacitka zobraz nic 

    }
  }

}

//pin D3
ISR(INT1_vect) {
  if (setup==0 && setup_min==0) {
    _delay_ms(200);
    min1++;  //zvys cas o jednu minutu
    increment_time();
    sec1 = 0;
    sec10 = 0;
  } else if (setup==0 && setup_hod==0) {
    _delay_ms(200);
    hod++;  //zvys cas o jednu minutu
    increment_time();
  } else {
    show=0;
  }
}

int main(void) {
  //zapneme pocitanie casu
  rtc_init();

  //katodova LED - low je zapnuty
  //nastavenie pinov LED portov ako output (1)
  DDRB |= 0x3F;
  DDRD |= 0xC0;

  //nastavenie D3 a D4 pinov ako input (buttons) (0)
  DDRD &= ~0x18;
  GICR |= (1<<INT0);
  GICR |= (1<<INT1);

  //zacina zapnute (kontrola)
  _delay_ms(2000);
  segments_off();

  sei();

  while(1){
    // ked nie sme v setup rezime a mame nastavene show
    if (show==0) {
      //ukazujem aktualny cas
      segments(hod);
      _delay_ms(250);
      segments_off();
      _delay_ms(100);
      segments(min10);
      _delay_ms(150);
      segments_off();
      _delay_ms(50);
      segments(min1);
      _delay_ms(150);
      segments_off();
      show=1;
    }
    if (setup==0 && setup_hod==0) {
      //we are in setup mode for hours
      segments(hod);
      _delay_ms(150);
      segments_off();
      _delay_ms(250);
    } else if (setup==0 && setup_min==0) {
      //show minutes (tens)
      segments(min10);
      _delay_ms(100);
      segments_off();
      _delay_ms(30);
      //show minutes (ones)
      segments(min1);
      _delay_ms(100);
      segments_off();
      _delay_ms(300);
    }
  } 
}

