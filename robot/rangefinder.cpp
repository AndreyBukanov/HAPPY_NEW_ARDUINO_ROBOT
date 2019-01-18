/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: rangefinder.cpp : FILE BEGIN */

#include "rangefinder.h"

RangeFinder::RangeFinder(uint16_t trig, uint16_t echo)
{
  m_trig_pin = trig; 
  m_echo_pin = echo; 

  m_duration = 0x00; 
  m_distance = 0x00; 

  digitalWrite(m_trig_pin, HIGH);

  pinMode(m_trig_pin, OUTPUT); 
  pinMode(m_echo_pin, INPUT);
}

RangeFinder::~RangeFinder()
{
}

void RangeFinder::Init()
{
    m_duration = 0x00; 
    m_distance = 0x00; 

    digitalWrite(m_trig_pin, HIGH);
}

uint16_t RangeFinder::Measure()
{
  digitalWrite(m_trig_pin, LOW);
  digitalWrite(m_trig_pin, HIGH); 
    
  m_duration = pulseIn(m_echo_pin, HIGH, c_pulse_timeout);
  
  m_distance = m_duration / c_dist_divider;
  
  return m_distance;
}
/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: rangefinder.cpp : FILE END */
