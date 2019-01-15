/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitTimer.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitTimer initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitTimer.
 *
 */

#include <iomanip>

#include "RshInitTimer.h"

RshInitTimer::RshInitTimer():
	RshBaseType(rshInitTimer, sizeof(RshInitTimer))
	{
		timer0Mode = RshInitTimer::InterruptOnTerminalCount;
		timer1Mode = RshInitTimer::InterruptOnTerminalCount;
		timer2Mode = RshInitTimer::InterruptOnTerminalCount;
		timer0Count = 0;
		timer1Count = 0;
		timer2Count = 0;
	}

RshInitTimer::RshInitTimer(const RshInitTimer& obj):
	RshBaseType(obj._type, obj._typeSize)
	{

		this->timer0Mode = obj.timer0Mode;
		this->timer1Mode = obj.timer1Mode;
		this->timer2Mode = obj.timer2Mode;
		this->timer0Count = obj.timer0Count;
		this->timer1Count = obj.timer1Count;
		this->timer2Count = obj.timer2Count;
	}

RshInitTimer& RshInitTimer::operator=(const RshInitTimer& obj)
{
	if(this == &obj)
		return *this;
	this->timer0Mode = obj.timer0Mode;
	this->timer1Mode = obj.timer1Mode;
	this->timer2Mode = obj.timer2Mode;
	this->timer0Count = obj.timer0Count;
	this->timer1Count = obj.timer1Count;
	this->timer2Count = obj.timer2Count;
	return *this;
}

bool RshInitTimer::operator==(RshInitTimer& obj) const
{
	return
		(this->timer0Mode == obj.timer0Mode) &&
		(this->timer1Mode == obj.timer1Mode) &&
		(this->timer2Mode == obj.timer2Mode) &&
		(this->timer0Count == obj.timer0Count) &&
		(this->timer1Count == obj.timer1Count) &&
		(this->timer2Count == obj.timer2Count);
}

bool RshInitTimer::operator!=(RshInitTimer& obj) const
{
	return !(operator==(obj));
}

const char* TimerModeString(U32 timerMode)
{
	switch(timerMode)
	{
	case RshInitTimer::InterruptOnTerminalCount:
		 return "InterruptOnTerminalCount";
	
	case RshInitTimer::ProgrammableOneShot:
		return "ProgrammableOneShot";

	case RshInitTimer::RateGenerator:
		return "RateGenerator";

	case RshInitTimer::SquareWaveGenerator:
		return "SquareWaveGenerator";

	case RshInitTimer::SoftwareTriggeredStrobe:
		return "SoftwareTriggeredStrobe";

	case RshInitTimer::HardwareTriggeredStrobe:
		return "HardwareTriggeredStrobe";

	default:
		return "Unknown";
	}
}

std::ostream& operator<< (std::ostream &out, const RshInitTimer& obj)
{
	out << "Init Structure "<<"[0x"<<std::hex<<&obj<<std::dec<<"], type: RshInitTimer" << std::endl;

	out << "Timer0: [mode=" << TimerModeString(obj.timer0Mode) << ", count = " <<std::setw(8) <<obj.timer0Count<< "]" << std::endl;
	out << "Timer1: [mode=" << TimerModeString(obj.timer1Mode) << ", count = " <<std::setw(8) <<obj.timer1Count<< "]" << std::endl;
	out << "Timer2: [mode=" << TimerModeString(obj.timer2Mode) << ", count = " <<std::setw(8) <<obj.timer2Count<< "]" << std::endl;
	return out;
}
