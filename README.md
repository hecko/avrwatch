plne funkcna a otestovana na ATMega8L - PDIP verzia

  xtal (32kHz) musi byt zapojeny s externymi kondenzatormi (pozri errata v datasheete atmega8l) - pouzite 22pF (oznacenie 22) (na kazdej nozicke prepojene s GND)
  vsetky GND prepojene
  vsetky VCC prepojene
  AREF prepojeny cez 100n (oznacenie 104) kondenzator na GND
  7 segment display SA36-11GWA cez cca 100 Ohm odpory (spolocna anoda)
  tlacitla su medi INT pinmi a GND s 10K resistormi na pinoch do VCC
  napajane cez CR2032, alebo 2xAA 

![wiring](https://raw.github.com/hecko/avrwatch/master/doc/wiring.jpg)

programovanie je testovane na programatore usbtiny
