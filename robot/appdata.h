/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: appdata.h : FILE BEGIN */

#include "Arduino.h"

#define PIN_TRIG  (8)   // Range Finder TRIG pin number
#define PIN_ECHO  (9)   // Range Finder ECHO pin number

#define PIN_PWM   (4)   // Turning Platform Servo PWM pin number

#define PIN_IN_1  (11)  // Rigth Wheel IN_1 pin
#define PIN_IN_2  (10)  // Rigth Wheel IN_2 pin
#define PIN_EN_A  (5)   // Rigth Wheel EN_A pin

#define PIN_IN_3  (12)  // Left Wheel IN_1 pin
#define PIN_IN_4  (13)  // Left Wheel IN_2 pin
#define PIN_EN_B  (6)   // Left Wheel EN_A pin

#define PIN_ODO_R (2)   // Right Odometer Interrupt pin number
#define PIN_ODO_L (3)   // Left  Odometer Interrupt pin number


void SetInterrupt(uint8_t pin, void(*callback)(void));


/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: appdata.h : FILE END */
