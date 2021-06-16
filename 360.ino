// Include Camera Control
#include <multiCameraIrControl.h>

// Ir LED is in pin (9) --> Change depending on the pin 
Canon myCamera(9);


//Include the Arduino Stepper Library
#include <Stepper.h>
 
// Define Constants
 
// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 
 
//  Amount of Gear Reduction
const float GEAR_RED = 64;
 
// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
 
// Define Variables

int i = 0;

// Number of Steps Required
int StepsRequired;
 
Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);
 
void setup()
{
// Nothing  (Stepper Library sets pins as outputs)
}
 
void loop()
{

  while (i < 61) 
    {
       // Rotate CCW X-amount Turns
      StepsRequired  =  - STEPS_PER_OUT_REV / 60;   
      steppermotor.setSpeed(200);  
      steppermotor.step(StepsRequired);
      delay(50);
      i++;
      
      //take picture
   
     D5.shotNow();
     // delay(10000);
    }
}
