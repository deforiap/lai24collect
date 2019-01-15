/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitMemory.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitMemory initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitMemory.
 *
 */
 
#include "RshInitMemory.h"
#include "RshInitDMA.h"

RshInitMemory::RshInitMemory():
	RshInitADC(rshInitMemory, sizeof(RshInitMemory))
	{
		control = 0;
		preHistory = 0;
		startDelay = 0;
		hysteresis = 0;
		packetNumber = 1;
		threshold = 0.0;
		controlSynchro = 0;
	}

RshInitMemory::RshInitMemory(const RshInitADC& obj):
	RshInitADC(rshInitMemory, sizeof(RshInitMemory))
    {
        this->preHistory = 0;
        this->control = 0;
        this->startDelay = 0;
        this->startType  = obj.startType;
        this->hysteresis  = 0;
        this->packetNumber  = 0;
        this->threshold  = 0;
        this->controlSynchro  = 0;
        this->bufferSize =  obj.bufferSize;
        this->frequency =  obj.frequency;

        this->channels.Copy(obj.channels);
    }

RshInitMemory::RshInitMemory(const RshInitMemory& obj):
	RshInitADC(obj._type, obj._typeSize)
	{
		this->preHistory = obj.preHistory;
		this->control = obj.control;
		this->startDelay = obj.startDelay;
		this->startType  = obj.startType;
		this->hysteresis  = obj.hysteresis;
		this->packetNumber  = obj.packetNumber;
		this->threshold  = obj.threshold;
		this->controlSynchro  = obj.controlSynchro;
		this->bufferSize =  obj.bufferSize;
	    this->frequency =  obj.frequency;

		this->channels.Copy(obj.channels);
	}

RshInitMemory& RshInitMemory::operator=(const RshInitMemory& obj)
	{
		if(this == &obj)
			return *this;
		this->preHistory = obj.preHistory;
		this->control = obj.control;
		this->bufferSize = obj.bufferSize;
		this->channels = obj.channels;
		this->channelSynchro = obj.channelSynchro;
		this->controlSynchro = obj.controlSynchro;
		this->frequency = obj.frequency;
		this->hysteresis = obj.hysteresis;
		this->packetNumber = obj.packetNumber;
		this->startDelay = obj.startDelay;
		this->startType = obj.startType;
		this->threshold = obj.threshold;
		return *this;
	}

RshInitMemory& RshInitMemory::operator=(const RshInitDMA& obj)
	{
		this->preHistory = 0;
		this->controlSynchro = 0;
		this->hysteresis = 0;
		this->packetNumber = 0;
		this->startDelay = 0;
        RshSynchroChannel chn_temp;
		this->channelSynchro = chn_temp;
		
		this->control = obj.control;
		this->bufferSize = obj.bufferSize;
		this->channels = obj.channels;
		this->frequency = obj.frequency;
		this->startType = obj.startType;
		this->threshold = obj.threshold;
		return *this;
	}

bool RshInitMemory::operator==(RshInitMemory& obj) const
	{
		return
			(this->preHistory == obj.preHistory)		&&
			(this->bufferSize == obj.bufferSize)			&&
			(this->channels == obj.channels)				&&
			(this->channelSynchro == obj.channelSynchro)	&&
			(this->controlSynchro == obj.controlSynchro)	&&
			RSH_CMPDOUBLE(this->frequency, obj.frequency)	&&
			(this->hysteresis == obj.hysteresis)			&&
			(this->packetNumber == obj.packetNumber)		&&
			(this->startDelay == obj.startDelay)			&&
			(this->startType == obj.startType)				&&
			RSH_CMPDOUBLE(this->threshold, obj.threshold);
	}

bool RshInitMemory::operator!=(RshInitMemory& obj) const
	{
		return !(operator==(obj));
	}

std::ostream& operator<< (std::ostream &out, const RshInitMemory& obj)
{
	out << "Init Structure "<<"[0x"<<std::hex<<&obj<<std::dec<<"], type: RshInitMemory"<< std::endl;

	out << "Parent structure: ";
	const RshInitADC* parent = dynamic_cast<const RshInitADC*>(&obj);
	if(parent)
		out << *parent;
	else 
		out << "cast failed" << std::endl;
	
	out<<"channelSynchro: " << obj.channelSynchro << std::endl;
	
	out<<"control: [";
	
	if(obj.control & RshInitMemory::AutoStartOn)
		out << "AutoStartOn;";
	else 
		out  << "AutoStartOff;";

	if(obj.control & RshInitMemory::FreqDouble)
		out << "FreqDouble";
	else if(obj.control & RshInitMemory::FreqQuadro)
		out << "FreqQuadro";
	else
		out << "FreqSingle";
	out << "]"<< std::endl;

	out<<"packetNumber: " << obj.packetNumber << std::endl;
	out<<"preHistory: " << obj.preHistory << std::endl;
	out<<"startDelay: " << obj.startDelay << std::endl;
	out<<"hysteresis: " << obj.hysteresis << std::endl;
	
	return out;
}

void RshInitMemory::SetAutoStartOn(bool on)
{
	if(on)
		control |= RshInitMemory::AutoStartOn;
	else
		control &= ~(RshInitMemory::AutoStartOn);
}

bool RshInitMemory::IsAutoStartOn() const
{
	return (control & RshInitMemory::AutoStartOn) > 0;
}

void RshInitMemory::SetFreqModeSingle()
{
	//remove double and quadro flags
	control &= ~(RshInitMemory::FreqDouble);
	control &= ~(RshInitMemory::FreqQuadro);
}

void RshInitMemory::SetFreqModeDouble()
{
	control |= RshInitMemory::FreqDouble;
}


void RshInitMemory::SetFreqModeQuadro()
{
	control |= RshInitMemory::FreqQuadro;
}

bool RshInitMemory::IsSingleFreqModeActive() const
{
	return ( !IsDoubleFreqModeActive() &&
		!IsQuadroFreqModeActive() );
}

	
bool RshInitMemory::IsDoubleFreqModeActive() const
{
	return (control & RshInitMemory::FreqDouble) > 0;
}

bool RshInitMemory::IsQuadroFreqModeActive() const
{
	return (control & RshInitMemory::FreqQuadro) > 0;
}
