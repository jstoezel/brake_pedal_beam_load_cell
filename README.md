# brake_pedal_beam_load_cell
Simplest code to exercise an HX711 based beam load cell pedal for sim racing

:warning: Depending on the HX711 breakout board you get, you may need to cut a trace at the back of the board to enable fast sampling of the load cell (often identified as "RATE" on the silkscreen). The intent is to get pin 15 (RATE) to be tied to VCC. This will enable 80Hz data sampling.

------

SOFTWARE

This project is dependent on the following library

https://github.com/aguegu/ardulibs/tree/master/hx711

------

HARDWARE

This project requires:
- A Teensy LC https://www.pjrc.com/teensy/teensyLC.html
- An HX711 breakout board such as these ones on eBay: https://www.ebay.com/sch/i.html?_from=R40&_trksid=p2380057.m570.l1313.TR11.TRC2.A0.H0.Xhx711.TRS0&_nkw=hx711&_sacat=0
- Look up on eBay, at the time I am writting I can see "Parallel Beam Load Cell Sensor 100kg/217lb Scale Weighing Sensor 0.02 Precision" available for $14

------

Connections Between the Teensy and the HX711 breakout board:

| TEENSY  | HX711 |
| ------------- | ------------- |
| 0  | CLK  |
| 1  | DAT  |
| 3.3V  | VCC  |
| GND  | GND  |

------

Connections Between the X711 breakout and load beam cell are load beam cell dependent but should follow a colour coding.

------
