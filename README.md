# POV---Persistence-of-Vision-stick-arduino-project
To show the String on the rotating stick

POV - Persistence Of Vision

Initiated by- Programmed by-
Rohan V Dvivedi
Kativarpu Parthiv

Contribution to Database of structure of characters by-
Sri Harsha Grandhi
Anurag Anand
KAtivarpu Parthiv

Contribution Mechanical Structure assembly , balancing and improvement by-
Anurag Anand
Parakh Gupta

Materials used :

8 - green clored LEDs
1 - Serial in- Parallel out shift register
1 - digital ir Sensor
1 - motor (rpm = 1000)
1 - on board 5v power supply
1 - arduino

Note -
- the LED to be glown in a frame were sent as data using SPI comm protocol
using slave select pin as the latch, and utilizing only MOSI.
- IR sensor was used to detect the position of completion of one revolution
- by canging the delay 'd' in given code the width of characters can be changed
