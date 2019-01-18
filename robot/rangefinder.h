/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: rangefinder.h : FILE BEGIN */

#ifndef _RANGEFINDER_h
#define _RANGEFINDER_h

#include <Arduino.h>
#include <stdbool.h>
#include <stdint.h>

class RangeFinder
{
  private:

    /* Constants */
    
    const uint16_t c_trig_init_us  = 2;
    const uint16_t c_trig_pulse_us = 10;
    const uint16_t c_dist_divider  = 58;
    const uint16_t c_pulse_timeout = 40000;
  
    /* Members */
  
    uint16_t m_duration; // Measured Pulse Duration
    uint16_t m_distance; // Calculated Distance
    uint16_t m_trig_pin; // Trig Pin Number
    uint16_t m_echo_pin; // Echo Pin Number
 
  public:

    /* Constructor */
      
     RangeFinder(uint16_t trig, uint16_t echo);
    ~RangeFinder();
  
    /* Methods */
  
    void      Init();        // Initialization
    uint16_t  Measure();     // Make one measure  
};

#endif

/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: rangefinder.h : FILE END */