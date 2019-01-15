/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshChannel.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshChannel class.
 *
 * \~russian
 * \brief
 * Класс RshChannel.
 *
 */
 
#include "RshChannel.h"
#include "RshMacro.h"

RshChannel::RshChannel(U32 Gain, U32 Control, double Adjustment):
 RshBaseType(rshChannel, sizeof(RshChannel)),
 control(Control),
 gain(Gain),
 adjustment(Adjustment)
{ }

RshChannel::RshChannel(const RshChannel& obj):
 RshBaseType(rshChannel, sizeof(RshChannel)),
 control(obj.control),
 gain(obj.gain),
 adjustment(obj.adjustment)
{ }

bool RshChannel::operator==(RshChannel& obj) const
{
	return
		RSH_CMPDOUBLE(this->adjustment,obj.adjustment)	&&
		(this->control == obj.control)			&&
		(this->gain == obj.gain);
}

bool RshChannel::operator!=(RshChannel& obj) const
{
	return !(operator==(obj));			
}

bool RshChannel::operator< (const RshChannel& obj) const
{
	return this->gain < obj.gain;
}

bool RshChannel::operator> (const RshChannel& obj) const
{
	return this->gain > obj.gain;
}

std::ostream& operator<< (std::ostream &out, const RshChannel& obj)
{
    // write obj to stream
	out << "[gain: "<<obj.gain<<", adjustment: "<<obj.adjustment<<", control: "<<obj.control<<"]";
	return out;
}

RshChannel& RshChannel::operator=(const RshChannel& obj)
{
	if(this == &obj)
		return *this;
	this->adjustment = obj.adjustment;
	this->control = obj.control;
	this->gain = obj.gain;
	return *this;
}

void RshChannel::SetDefaultPatameters()
{
	gain = 1;
	control = 0;
	adjustment = 0.0;
}

void RshChannel::SetUsed(bool on)
{
	if(on)
		control |= RshChannel::Used;
	else
		control &= ~(RshChannel::Used);
}

void RshChannel::SetFirstChannel(bool on)
{
	if(on)
		control |= RshChannel::FirstChannel;
	else
		control &= ~(RshChannel::FirstChannel);
}

void RshChannel::SetSynchro(bool on)
{
	if(on)
		control |= RshChannel::Synchro;
	else
		control &= ~(RshChannel::Synchro);
}

void RshChannel::SetICPPower(bool on)
{
	if(on)
		control |= RshChannel::ICPPowerOn;
	else
		control &= ~(RshChannel::ICPPowerOn);
}

void RshChannel::SetInputAC(bool on)
{
	if(on)
		control |= RshChannel::AC;
	else
		control &= ~(RshChannel::AC);
}

void RshChannel::SetInputDC(bool on)
{
	//opposite to SetInputAC 
	SetInputAC(!on);
}

void RshChannel::SetResist50Ohm(bool on)
{
	if(on)
		control |= RshChannel::Resist50Ohm;
	else
		control &= ~(RshChannel::Resist50Ohm);
}

void RshChannel::SetResist1MOhm(bool on)
{
	//opposite to SetResist50Ohm 
	SetResist50Ohm(!on);
}
bool RshChannel::IsUsed() const
{
	return (control & RshChannel::Used)>0; 
}

bool RshChannel::IsFirstChannel() const
{
	return (control & RshChannel::FirstChannel)>0; 
}

bool RshChannel::IsSynchroSource() const
{
	return (control & RshChannel::Synchro)>0; 
}

bool RshChannel::IsICPPowerOn() const
{
	return (control & RshChannel::ICPPowerOn)>0; 
}

bool RshChannel::IsInputACActive() const
{
	return (control & RshChannel::AC)>0;
}

bool RshChannel::IsInputDCActive() const
{
	//opposite to IsInputACActive()
	return !IsInputACActive();
}
	

bool RshChannel::IsResist50OhmActive() const
{
	return (control & RshChannel::Resist50Ohm)>0; 
}
	
	
bool RshChannel::IsResist1MOhmActive() const
{
	//opposite to IsResist50OhmActive()
	return !IsResist50OhmActive();
}

//Template instantiation	
template class RshBufferType< RshChannel, rshBufferTypeChannel >;
