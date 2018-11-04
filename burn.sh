# $1 == dev
avrdude -F -V -c arduino -p ATMEGA328P -P $1 -b 57600 -U flash:w:led.hex
