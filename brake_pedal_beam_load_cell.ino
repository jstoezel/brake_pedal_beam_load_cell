///////////////////////////////////////////////////////////////////////
// SIMPLEST LOAD CELL BRAKE PEDAL FOR RACING SIMULATION
// by JS Stoezel
// js.stoezel@gmail.com
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// INCLUDES
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Get this library from this Git repository
// https://github.com/aguegu/ardulibs/tree/master/hx711
#include "HX711.h"
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// MACROS
///////////////////////////////////////////////////////////////////////
// How many samples to take at initialization of the library to zero
// out the offset of the load cell.
#define BRAKE_PEDAL_LOAD_BEAM_CELL_TARE_REPS  10

// Sanity check for the load cell readings. This will typically be to
// prevent from loading negative values if/when the load cell is pulled
// in the wrong direction
#define BRAKE_PEDAL_LOAD_BEAM_CELL_MAX_VAL  2000000

// This setting links the maximum effort applied to the pedal to the
// maximum value sent to the joystick interface.
// The joystick interface expects a value ranging from 0 t0 1023. Adjust
// this number to your liking, so the joystick will read 1023 at the maximum
// force you feel comfortable applying to the brake pedal (without braking it).
// The hardware I am using is 3D printed and I do not recommend this value
// Be set any lower than 1100. Any lower value will require more force to
// be applied to the pedal, and may damage the 3D printed parts.
#define BRAKE_PEDAL_LOAD_BEAM_CELL_SCALING  1100


///////////////////////////////////////////////////////////////////////
// LOCAL VARIABLES
///////////////////////////////////////////////////////////////////////
HX711 brake_pedal(1 /* DAT */, 0 /* CLK */, 128 /* GAIN */);
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// FUNCTIONS
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
void setup()
///////////////////////////////////////////////////////////////////////
{
  // Zero the pedal offset. This is is to compensate for the own weight
  // of the pedal. It is important not to apply any force to the pedal
  // While this is happening
  brake_pedal.tare(BRAKE_PEDAL_LOAD_BEAM_CELL_TARE_REPS);
  
  Joystick.useManualSend(true);
} // setup

///////////////////////////////////////////////////////////////////////
void loop()
///////////////////////////////////////////////////////////////////////
{
  int32_t brake_value ;
  
  brake_value = brake_pedal.get_value(1);

  if((brake_value > BRAKE_PEDAL_LOAD_BEAM_CELL_MAX_VAL) || 
     (brake_value < 0))
  {
    brake_value = 0;
  }
  
  brake_value /= BRAKE_PEDAL_LOAD_BEAM_CELL_SCALING;
  
  Joystick.X(brake_value);
  Joystick.send_now();
} // loop
