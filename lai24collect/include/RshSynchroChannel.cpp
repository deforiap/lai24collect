/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshSynchroChannel.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshSynchroChannel class.
 *
 * \~russian
 * \brief
 * Класс RshSynchroChannel.
 *
 */
 
#include "RshSynchroChannel.h"
 
RshSynchroChannel::RshSynchroChannel():
 RshBaseType(rshSynchroChannel, sizeof(RshSynchroChannel)),
 gain(1),
 control(0)
{ }

bool RshSynchroChannel::operator==(RshSynchroChannel& obj) const
{
	return
		(this->control == obj.control)		&&
		(this->gain == obj.gain);
}

bool RshSynchroChannel::operator!=(RshSynchroChannel& obj) const
{
	return !(operator==(obj));
}

RshSynchroChannel& RshSynchroChannel::operator=(const RshSynchroChannel& obj)
{
	if(this == &obj)
		return *this;
	this->control = obj.control;
	this->gain = obj.gain;
	return *this;
}

std::ostream& operator<< (std::ostream &out, const RshSynchroChannel& obj)
{
    // write obj to stream
	out << "[gain: "<<obj.gain<<", control: "<<obj.control<<"]";
	return out;
}
	
void RshSynchroChannel::SetDefaultPatameters()
{
	gain = 1;
	control = 0;
}

void RshSynchroChannel::SetFilterLow(bool on)
{
	if(on)
	{
		//set RshSynchroChannel::FilterLow flag
		control |= RshSynchroChannel::FilterLow;
		//remove RshSynchroChannel::FilterHigh flag
		control &= ~(RshSynchroChannel::FilterHigh);
	}
	else
	{
		//remove both flags
		control &= ~(RshSynchroChannel::FilterLow);
		control &= ~(RshSynchroChannel::FilterHigh);
	}
}

void RshSynchroChannel::SetFilterHigh(bool on)
{
	if(on)
	{
		//set RshSynchroChannel::FilterHigh flag
		control |= RshSynchroChannel::FilterHigh;
		//remove RshSynchroChannel::FilterLow flag
		control &= ~(RshSynchroChannel::FilterLow);
	}
	else
	{
		//remove both flags
		control &= ~(RshSynchroChannel::FilterLow);
		control &= ~(RshSynchroChannel::FilterHigh);
	}
}
	
void RshSynchroChannel::SetInputAC(bool on)
{
	if(on)
		control |= RshSynchroChannel::AC;
	else
		control &= ~(RshSynchroChannel::AC);
}

void RshSynchroChannel::SetInputDC(bool on)
{
	//opposite to SetInputAC 
	SetInputAC(!on);
}

void RshSynchroChannel::SetResist50Ohm(bool on)
{
	if(on)
		control |= RshSynchroChannel::Resist50Ohm;
	else
		control &= ~(RshSynchroChannel::Resist50Ohm);
}

void RshSynchroChannel::SetResist1MOhm(bool on)
{
	//opposite to SetResist50Ohm 
	SetResist50Ohm(!on);
}


bool RshSynchroChannel::IsFilterHighActive() const
{
	return (control & RshSynchroChannel::FilterHigh)>0;
}

bool RshSynchroChannel::IsFilterLowActive() const
{
	return (control & RshSynchroChannel::FilterLow)>0;
}

bool RshSynchroChannel::IsInputACActive() const
{
	return (control & RshSynchroChannel::AC)>0;
}

bool RshSynchroChannel::IsInputDCActive() const
{
	//opposite to IsInputACActive()
	return !IsInputACActive();
}
	

bool RshSynchroChannel::IsResist50OhmActive() const
{
	return (control & RshSynchroChannel::Resist50Ohm)>0; 
}
	
	
bool RshSynchroChannel::IsResist1MOhmActive() const
{
	//opposite to IsResist50OhmActive()
	return !IsResist50OhmActive();
}
