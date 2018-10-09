# brake_pedal_beam_load_cell
Simplest code to exercise an HX711 based beam load cell pedal for sim racing



[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/SFxvEBrtIVg/0.jpg)](https://www.youtube.com/watch?v=SFxvEBrtIVg)



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

About the selection of the load cell weight range:
I drive without shoes and so there is little force I apply to the brake pedal (in comparison with what you'd need on a car that has master cylinders without assist, formula cars for instance). By little I mean it is comparable to the force you'd apply on the pedal of a recent street car. 
The maximum force I apply is around 90kg. This is within the range of a 100kg load cell.
Any more force than this and it seems to me that I lose feel, it gets so hard that it gets difficult to modulate the pressure with precision. I am also very used to a potentiometer pedal. 
With 3D printed parts, I would not want to apply much more force anyway as the base mount of the load cell might start cracking. 


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
