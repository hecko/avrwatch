// standadne kniznice
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "rtc.h"	// rtc utility
#include "segment.c"	//7-segment library

#include "i2cmaster.h"
#define ds1307 0xD0

#define TRUE 1
#define FALSE 0

// globalne premenne
volatile unsigned char now[5]; // sekundy, desiatky sekund, minuty, desiatky minut, hodiny 
volatile unsigned char chng;
volatile unsigned char show;

// rutina na zachytaanie RTC preruseni
/*ISR(TIMER2_OVF_vect)
{
   now[0]++;   //inkrementjeme unix epochu sekundy
   if (now[0]>9)
      {
      now[0]=0;
      now[1]++;
      if (now[1]>5) {
        now[1]=0;
        now[2]++;
        if (now[2]>9) {
          now[2]=0;
          now[3]++; //desiatky minut
          if(now[3]>5) {
            now[3]=0;
            now[4]++; //hodiny
            if(now[4]>11) {
              now[4]=0;
            }
          }
        }
      }
    }
  chng=0;
}
*/

ISR_ALIAS(INT1_vect, INT0_vect);

ISR(INT0_vect) {
  _delay_ms(20);
  show=0;
}

uint8_t ret;

uint8_t ds1307_write(uint8_t address,uint8_t data) {
  i2c_start_wait(ds1307+I2C_WRITE);
  i2c_write(address);
  i2c_write(data); 
  i2c_stop();
  return TRUE;
}


uint8_t ds1307_read(uint8_t address,uint8_t *data) {
  i2c_start_wait(ds1307+I2C_WRITE);
  i2c_write(address); 
  i2c_start_wait(ds1307+I2C_READ);
  *data = i2c_readNak();
  i2c_stop();
  return TRUE;
}

void ds1307_init() {
  uint8_t temp; 

  ds1307_read(0x00,&temp);
  temp&=(~(1<<7));  	//Clear CH Bit - spusti casovac
  ds1307_write(0x00,temp);
}

int main(void) {

  uint8_t cas;

  i2c_init();
  ds1307_init();

  _delay_ms(2000);
  //zapneme pocitanie casu
  rtc_init();

  //katodova LED - low je zapnuty
  //nastavenie pinov ako output
  DDRB = 0xff;
  DDRD = 0xff;

  //nastavenie D3 a D4 pinov ako input (buttons)
  DDRD |= 0b00011000;
  GICR |= (1<<INT0);
  GICR |= (1<<INT1);

  //zacina zapnute (kontrola)
  PORTB = 0x00;
  PORTD &= ~0b11000000;
  _delay_ms(2000);
  segments_off();

  i2c_init();
  ds1307_init();

  //sei();

  while(1){
//    if (show==0) {
      ds1307_read(0x00,&cas);
      //PORTB = cas;
      segments(cas);
      //_delay_ms(350);
      PORTB &= ~PORTB; //clear na nuly
      PORTB = ~PORTB; // nastavit jednicky na zhasnutie
      _delay_ms(150);
//      show=1;
/*
      for(int i=4;i>=0;i--) {
        segments(now[i]);
        segments_off();
        _delay_ms(50);
        show=1;
      }
*/
//    }
  }
}

