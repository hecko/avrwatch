// rtc.c
// Utility pre RTC
// verzia ATMEGA8/48/88/168/328
// RTC - Interny
// Autor: Marek Blasko
// Licencia: GPL
// POZOR! piny pe externy kristal async oscilatora su
// zdielane s klasickym oscilatorom CPU musi bezat na interny
// RC oscilator.
#include <avr/io.h>
#include <avr/interrupt.h>

void rtc_init(void)
{
	//RTC robi timer2
	//Zapnutie asynchronneho modu a externeho oscilatora
	//plati pre ATMega128 aj ATMega8
	ASSR |= 1<<AS2;
	// nastavenie preddelicky na 128. 32.....Khz / 128 = 1/256s
	// Timmer pretescie za 1s. Typ prace citacky normal
	//TCCR2A = 0x00;
	TCCR2 = 0x00;
        //rovnake pre ATMega128 
	//TCCR2B = 1<<CS22 | 1<<CS20;
	TCCR2 = 1<<CS22 | 1<<CS20;
	// zapneme generovanie prerusenia pri preteceni
	TIMSK |= 1<<TOIE2;
}

