PROJECT=segment_test
SOURCES=main.c rtc.c twimaster.c
HEADERS=rtc.h i2cmaster.h 
CC=avr-gcc
OBJCOPY=avr-objcopy
#MMCU=atmega168
MMCU=atmega8
AVR_FREQ=1000000L

CFLAGS=-mmcu=$(MMCU) -Wall -Os

$(PROJECT).hex: $(PROJECT).out
	$(OBJCOPY) -j .text -O ihex $(PROJECT).out $(PROJECT).hex

$(PROJECT).out: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -I./ -o $(PROJECT).out -DF_CPU=$(AVR_FREQ) $(SOURCES) 

program: $(PROJECT).hex
	avrdude -p $(MMCU) -c usbtiny -b 4800  -e -U flash:w:$(PROJECT).hex

clean:
	rm -f $(PROJECT).out
	rm -f $(PROJECT).hex
