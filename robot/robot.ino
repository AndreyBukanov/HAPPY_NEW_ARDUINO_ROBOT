/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: MAIN FILE : FILE BEGIN */

/*
	Go to loop() func. It contains something interesting...
*/

#include "appdata.h"
#include "rangefinder.h"
#include "turningplatform.h"
#include "wheelplatform.h"

RangeFinder     *g_rfinder;    // Rangefinder Module   
TurningPlatform *g_tplate;     // Turning Platform Module
WheelPlatform   *g_wplate;     // Wheel Platform

void right_wheel_interrupt()
{
	/* Update counter of right wheel */
	g_wplate->DistanceCounterRight();
}

void left_wheel_interrupt()
{
	/* Update counter of left wheel */
	g_wplate->DistanceCounterLeft();
}

void setup()
{	
	/* Debug output */
	Serial.begin(115200);

	/* Make a new rangefinder */
	g_rfinder = new RangeFinder(PIN_TRIG, PIN_ECHO);

	/* Make a new turning platform */
	g_tplate = new TurningPlatform(PIN_PWM);

	/* Make a new wheel platform */
	g_wplate = new WheelPlatform(PIN_IN_1, PIN_IN_2, PIN_IN_3, PIN_IN_4, PIN_EN_A, PIN_EN_B);

	/* Interrupt Connecting */
	SetInterrupt(PIN_ODO_R, right_wheel_interrupt);
	SetInterrupt(PIN_ODO_L, left_wheel_interrupt);
}

// 33 - 90 deg

#define WALL_THRESHOLD 15
#define LEFT_TURN_POINTS 9
#define RIGHT_TURN_POINTS 9
#define FORWARD_ITSELF_POINTS 25

void turnLeft()
{
  g_wplate->Turn(LEFT, LEFT_TURN_POINTS); // Now, turn around! 40 points turn...
  delay(100);
}

void turnRight()
{
  g_wplate->Turn(RIGHT, RIGHT_TURN_POINTS); // Now, turn around! 40 points turn...
  delay(100);  
}

void goForward(uint16_t distanceRight)
{
  if (distanceRight > 13)
  {
    g_wplate->Turn(RIGHT, 1);
    delay(100);
  }
  else
  {
    g_wplate->Turn(LEFT, 1);
    delay(100);
  }
  
  g_wplate->Run(FORWARD, FORWARD_ITSELF_POINTS); // Run, boy, run! 100 points run...
  
  while (g_wplate->GetStatus() == RUN) 
  {
    delay(100); // Just waiting
  }
}

struct WallFound
{
  bool bForward = 0;
  bool bRight = 0;
  uint16_t distanceRight = 0;
};

uint16_t readForward()
{
  g_tplate->SetAngle(90);  // .... to the middle...
  delay(300);
  return g_rfinder->Measure(); // distance measured in "cm"  
}

uint16_t readRight()
{
  g_tplate->SetAngle(1);  // .... to the middle...
  delay(300);
  return g_rfinder->Measure(); // distance measured in "cm"
}

struct WallFound readLongSensor()
{
  struct WallFound wf;

  uint16_t right_distance = (readRight() + readRight() + readRight()) / 3; // distance measured in "cm"
  if (right_distance <= 15)
  {
    Serial.println("R");
    wf.distanceRight = right_distance;
    wf.bRight = true;
  }

  uint16_t forward_distance = (readForward() + readForward() + readForward()) / 3; // distance measured in "cm"
  if (forward_distance <= 15)
  {
    Serial.println("F");
    wf.bForward = true;
  }

   return wf;
}

void loop()
{
  
  struct WallFound wf = readLongSensor();
  if (wf.bRight == false)
  {
    //Serial.println("Right - wall found");
    turnRight();
  }
  else if (wf.bForward == false)
  {
    //Serial.println("Forward - wall found");
    goForward(wf.distanceRight);
  }
  else
  {
    turnLeft();
  }

  delay(100);
}

/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: MAIN FILE : FILE END */























/*
                                   ``````````                                   
                      ``````.........................``````                     
                ```...........................................```               
            ``.....................................................```          
        ``.............................................................``       
      ``...........                                        ...............`     
    ``..........                                             ..............``   
    `.........            NEVER MIND, IT'S JUST A CAT          ..............`  
   `..........                                                    ...........`  
   `........                 TRY TO MAKE IT WORKING                 .........`  
   `..........                                                     ..........`  
    `...........            GO   TO  CODE, LAZY A*S              ...........`   
      `...........                                  /           ...........`     
        ``..........                                         ..........```      
          ```.......................................................```         
           `  ````.............................................````             
          .s/:`     ``````.............................``````                   
          +o+/o-             ```````````````````````                            
          oh:o:h-.-:::--..`          ``                                         
          smoshyo+++oo//++o+/:.   `-sso:                                        
        `:ys:..`          ``-/oo.-shsss:                                        
       `++.                   `-smh/:os`                                        
       +/ -ss:            ```   `+d+d+`                                         
     ./o``hNMh          `+hdy.    od+`                                          
     `d+-`-++.   --`    :dNMN:    :o                                            
    .:d/:`   ````hs`  `  -++-`    :o                                            
   `.:h+-`   `+//h-../+      .+/. +o                                            
   `.-/h.     ```-/++:`     `:-` `d-                                            
       -s:``              ./..::.o+                                             
        `:+o/.`            .+/`-/o:                                             
           `doo+:`          `-//` +/                                            
            y.`.:.          `.`   `o/                                           
            h-                     `y:                                          
            d/`+                 `` `d-                                         
           `do.y`               :+:  -d.                                        
           `dsoh:.              +o+   :h`                                       
           `dy.o++              :-o.   +h`                                      
            dd`.`                +-.    sy`                                     
            yo`                  .      `o:                                     

*/
