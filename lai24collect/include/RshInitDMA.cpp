/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitDMA.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitDMA initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitDMA.
 *
 */
 
#include "RshInitDMA.h"
#include "RshInitMemory.h"

RshInitDMA::RshInitDMA():
	RshInitADC(rshInitDMA, sizeof(RshInitDMA))
	{
		dmaMode = RshInitDMA::Single;
		control = RshInitDMA::StandardMode;
		controlSynchro = 0;
		threshold = 0;
		frequencyFrame = 0.0;
	}

RshInitDMA::RshInitDMA(const RshInitADC& obj):
	RshInitADC(rshInitDMA, sizeof(RshInitDMA))
    {
		this->dmaMode = RshInitDMA::Single;
        this->control = 0;
        this->frequencyFrame = 0;
        this->startType  = obj.startType;
        this->bufferSize =  obj.bufferSize;
        this->frequency =  obj.frequency;
		this->threshold = obj.threshold;
		this->controlSynchro = obj.controlSynchro;

        this->channels.Copy(obj.channels);
    }

RshInitDMA::RshInitDMA(const RshInitDMA& obj):
	RshInitADC(obj._type, obj._typeSize)
	{
		this->dmaMode = obj.dmaMode;
		this->control = obj.control;
		this->frequencyFrame = obj.frequencyFrame;
		this->startType  = obj.startType;
		this->bufferSize =  obj.bufferSize;
	    this->frequency =  obj.frequency;
		this->threshold = obj.threshold;
		this->controlSynchro = obj.controlSynchro;

		this->channels.Copy(obj.channels);
	}

RshInitDMA& RshInitDMA::operator=(const RshInitDMA& obj)
	{
		if(this == &obj)
			return *this;
		this->bufferSize = obj.bufferSize;
		this->channels = obj.channels;
		this->control = obj.control;
		this->dmaMode = obj.dmaMode;
		this->frequency = obj.frequency;
		this->frequencyFrame = obj.frequencyFrame;
		this->startType = obj.startType;
		this->threshold = obj.threshold;
		this->controlSynchro = obj.controlSynchro;

		return *this;
	}

RshInitDMA& RshInitDMA::operator=(const RshInitMemory& obj)
	{
		this->dmaMode = RshInitDMA::Single;
		this->frequencyFrame = 0;
		this->bufferSize = obj.bufferSize;
		this->channels = obj.channels;
		this->control = obj.control;
		this->frequency = obj.frequency;
		this->startType = obj.startType;
		this->threshold = obj.threshold;
		this->controlSynchro = obj.controlSynchro;
		
		return *this;
	}

bool RshInitDMA::operator==(RshInitDMA& obj) const
	{
		return
			(this->bufferSize == obj.bufferSize)			&&
			(this->channels == obj.channels)				&&
			(this->control == obj.control)					&&
			(this->dmaMode == obj.dmaMode)					&&
			(this->controlSynchro == obj.controlSynchro)	&&
			RSH_CMPDOUBLE(this->frequency, obj.frequency)	&&
			RSH_CMPDOUBLE(this->frequencyFrame, obj.frequencyFrame)	&&
			RSH_CMPDOUBLE(this->threshold, obj.threshold)	&&
			(this->startType == obj.startType);

	}

bool RshInitDMA::operator!=(RshInitDMA& obj) const
	{
		return !(operator==(obj));
	}

std::ostream& operator<< (std::ostream &out, const RshInitDMA& obj)
{
	out << "Init Structure "<<"[0x"<<std::hex<<&obj<<std::dec<<"], type: RshInitDMA"<< std::endl;

	out << "Parent structure: ";
	const RshInitADC* parent = dynamic_cast<const RshInitADC*>(&obj);
	if(parent)
		out << *parent;
	else 
		out << "cast failed" << std::endl;		

	out<<"frequencyFrame: " << obj.frequencyFrame << "Hz" << std::endl;

	out<<"dmaMode: ";
	if(obj.dmaMode & RshInitDMA::Persistent)
		out<<"Persistent";
	else
		out<<"Single";
	out<<std::endl;

	out<<"control: [";

	std::list<const char*> features;
	if(obj.dmaMode & RshInitDMA::DiffMode)
		features.push_back("DiffMode");
	else
		features.push_back("DiffModeOff");

	if(obj.dmaMode & RshInitDMA::FrameMode)
		features.push_back("FrameMode");
	else
		features.push_back("FrameModeOff");

	if(obj.dmaMode & RshInitDMA::MulSwitchStart)
		features.push_back("MulSwitchStart");
	else
		features.push_back("MulSwitchStartOff");

	for(std::list<const char*>::iterator it = features.begin();
		it != features.end();++it)
	{
		out<<*it<<";";
	}
	out << "]"<< std::endl;

	return out;
}

void RshInitDMA::SetDiffMode(bool on)
{
	if(on)
		control |= RshInitDMA::DiffMode;
	else
		control &= ~(RshInitDMA::DiffMode);
}

void RshInitDMA::SetFrameMode(bool on)
{
	if(on)
		control |= RshInitDMA::FrameMode;
	else
		control &= ~(RshInitDMA::FrameMode);
}

bool RshInitDMA::IsDiffModeActive() const
{
	return (control & RshInitDMA::DiffMode) > 0;
}

bool RshInitDMA::IsFrameModeActive() const
{
	return (control & RshInitDMA::FrameMode) > 0;
}
