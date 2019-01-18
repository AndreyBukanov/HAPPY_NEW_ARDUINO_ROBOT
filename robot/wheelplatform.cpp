/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: wheelplatform.cpp : FILE BEGIN */

#include "wheelplatform.h"

WheelPlatform::WheelPlatform(uint16_t in_1, uint16_t in_2, uint16_t in_3, uint16_t in_4, uint16_t en_a, uint16_t en_b)
{
	m_pin_1 = in_1;
	m_pin_2 = in_2;
	m_pin_3 = in_3;
	m_pin_4 = in_4;

	m_pin_a = en_a;
	m_pin_b = en_b;

	digitalWrite(m_pin_1, LOW);
	digitalWrite(m_pin_2, LOW);
	digitalWrite(m_pin_3, LOW);
	digitalWrite(m_pin_4, LOW);

	digitalWrite(m_pin_a, LOW);
	digitalWrite(m_pin_b, LOW);

	pinMode(m_pin_1, OUTPUT);
	pinMode(m_pin_2, OUTPUT);
	pinMode(m_pin_3, OUTPUT);
	pinMode(m_pin_4, OUTPUT);

	pinMode(m_pin_a, OUTPUT);
	pinMode(m_pin_b, OUTPUT);

	m_status = STOP;

	m_distance_r = 0;
	m_distance_l = 0;
}

WheelPlatform::~WheelPlatform()
{
}

void WheelPlatform::SetStatus(uint8_t status)
{
	m_status = status;
}

void WheelPlatform::Init()
{
	digitalWrite(m_pin_1, LOW);
	digitalWrite(m_pin_2, LOW);
	digitalWrite(m_pin_3, LOW);
	digitalWrite(m_pin_4, LOW);

	digitalWrite(m_pin_a, LOW);
	digitalWrite(m_pin_b, LOW);

	SetStatus(STOP);
}

uint8_t WheelPlatform::GetStatus()
{
	return m_status;
}

void WheelPlatform::Run(uint8_t direction, uint16_t distance)
{
	if (direction == FORWARD)
	{
		digitalWrite(m_pin_1, LOW);
		digitalWrite(m_pin_2, HIGH);

		digitalWrite(m_pin_3, LOW);
		digitalWrite(m_pin_4, HIGH);
	}
	else if (direction == REVERS)
	{
		digitalWrite(m_pin_1, HIGH);
		digitalWrite(m_pin_2, LOW);

		digitalWrite(m_pin_3, HIGH);
		digitalWrite(m_pin_4, LOW);
	}
	else
	{
		digitalWrite(m_pin_1, LOW);
		digitalWrite(m_pin_2, LOW);

		digitalWrite(m_pin_3, LOW);
		digitalWrite(m_pin_4, LOW);
	}

	m_distance_r = distance;
	m_distance_l = distance;

	analogWrite(m_pin_a, c_wheel_speed_r);
	analogWrite(m_pin_b, c_wheel_speed_l);

	SetStatus(RUN);
}

void WheelPlatform::Turn(uint8_t side, uint16_t distance)
{
	if (side == LEFT)
	{
		digitalWrite(m_pin_1, LOW);
		digitalWrite(m_pin_2, HIGH);

		digitalWrite(m_pin_3, HIGH);
		digitalWrite(m_pin_4, LOW);
	}
	else if (side == RIGHT)
	{
		digitalWrite(m_pin_1, HIGH);
		digitalWrite(m_pin_2, LOW);

		digitalWrite(m_pin_3, LOW);
		digitalWrite(m_pin_4, HIGH);
	}
	else
	{
		digitalWrite(m_pin_1, LOW);
		digitalWrite(m_pin_2, LOW);

		digitalWrite(m_pin_3, LOW);
		digitalWrite(m_pin_4, LOW);
	}

	m_distance_r = distance;
	m_distance_l = distance;

	analogWrite(m_pin_a, c_wheel_speed_r);
	analogWrite(m_pin_b, c_wheel_speed_l);

	SetStatus(RUN);
}

void WheelPlatform::Stop()
{
	analogWrite(m_pin_a, 0);
	analogWrite(m_pin_b, 0);

	m_distance_r = 0;
	m_distance_l = 0;

	digitalWrite(m_pin_1, LOW);
	digitalWrite(m_pin_2, LOW);

	digitalWrite(m_pin_3, LOW);
	digitalWrite(m_pin_4, LOW);

	SetStatus(STOP);
}

void WheelPlatform::DistanceCounterRight()
{
	if (m_distance_r > 0)
	{
		m_distance_r--;
	}
	else
	{
		Stop();
	}
}

void WheelPlatform::DistanceCounterLeft()
{
	if (m_distance_l > 0)
	{
		m_distance_l--;
	}
	else
	{
		Stop();
	}
}

/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: wheelplatform.cpp : FILE END */