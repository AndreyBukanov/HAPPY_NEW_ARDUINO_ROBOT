/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: wheelplatform.h : FILE BEGIN */

#ifndef _WHEELPLATFORM_h
#define _WHEELPLATFORM_h

#include <Arduino.h>
#include <stdint.h>

enum WheelPlatformDirection
{
	NEUTRAL = 0x00,
	FORWARD = 0x01,
	REVERS  = 0x02,
};

enum WheelPlatformStatus
{
	STOP = 0x00,
	RUN  = 0x01,
};

enum WheelPlatformTurnSide
{
	RIGHT = 0x00,
	LEFT  = 0x01,
};

class WheelPlatform
{
private:

	/* Constants */

	const uint8_t c_wheel_speed_r = 160; // Right wheel speed
	const uint8_t c_wheel_speed_l = 160; // Left  wheel speed

	/* Members */
	
	uint16_t m_pin_1; // Control pin IN_1
	uint16_t m_pin_2; // Control pin IN_2 
	uint16_t m_pin_3; // Control pin IN_3
	uint16_t m_pin_4; // Control pin IN_4
	uint16_t m_pin_a; // Control pin EN_A
	uint16_t m_pin_b; // Control pin EN_B

	uint8_t  m_status; // Current status of platform

	uint16_t m_distance_r; // Right wheel distance counter
	uint16_t m_distance_l; // Left  wheel distance counter

	/* Methods */

	void SetStatus(uint8_t status); // Set platform status

public:

	/* Constructor */

	WheelPlatform(uint16_t in_1, uint16_t in_2, uint16_t in_3, uint16_t in_4, uint16_t en_a, uint16_t en_b);
	~WheelPlatform();

	/* Methods */

	void Init();                                                     // Initialization

	uint8_t GetStatus();                                             // Return current platform status

	void Run(uint8_t direction, uint16_t distance);                  // Moving control
	void Turn(uint8_t side, uint16_t distance);                      // Moving control
	void Stop();                                                     // Moving control

	void DistanceCounterRight();                                     // Right wheel interrupt handler
	void DistanceCounterLeft();                                      // Left wheel interrupt handler
};

#endif

/* TGT HAPPY NEW ARDUINO ROBOT PROJECT 2018: wheelplatform.h : FILE END */
