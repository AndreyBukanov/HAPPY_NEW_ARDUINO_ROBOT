/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: turningplatform.cpp : FILE BEGIN */

#include "turningplatform.h"

TurningPlatform::TurningPlatform(uint16_t pwm_pin)
{
  m_pwm_pin = pwm_pin;
  m_angle = c_angle_def;

  m_servo.attach(m_pwm_pin);

  Init();
}

TurningPlatform::~TurningPlatform()
{
  bool r = m_servo.attached();

  if (r)
    m_servo.detach();
}

void TurningPlatform::Init()
{
  m_servo.write(c_angle_def);

  delay(c_degree_ms * c_angle_def);
}

void TurningPlatform::SetAngle(uint16_t angle)
{
  m_servo.write(angle);

  uint16_t d_angle = 0;

  if(angle > m_angle)
    d_angle = angle - m_angle;
  else
    d_angle = m_angle - angle;

  delay(c_degree_ms * d_angle);

  m_angle = angle;
}

uint16_t TurningPlatform::GetAngle()
{
  m_angle = m_servo.read();

  return m_angle;
}

/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: turningplatform.cpp : FILE END */
