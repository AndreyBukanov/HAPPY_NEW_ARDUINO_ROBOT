/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: turningplatform.h : FILE BEGIN */

#ifndef _TURNINGPLATFORM_h
#define _TURNINGPLATFORM_h

#include <Arduino.h>
#include <Servo.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

class TurningPlatform
{
  private:

    /* Constants */

    const uint16_t c_angle_max = 180;
    const uint16_t c_angle_min = 0;
    const uint16_t c_angle_def = 90;
    const uint16_t c_degree_ms = 2;
    
    /* Members */
    
    Servo     m_servo;   // Servo module
    uint16_t  m_pwm_pin; // PWM pin number
    uint16_t  m_angle;   // Current angle value
    
  public:

    /* Constructor */

    TurningPlatform(uint16_t pwm_pin);
    ~TurningPlatform();
      
    /* Methods */

    void     Init();                   // Initialization
    void     SetAngle(uint16_t angle); // Set Angle Value
    uint16_t GetAngle();               // Get Current Angle Value
};

#endif

/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: turningplatform.h : FILE END */
