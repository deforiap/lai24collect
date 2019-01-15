/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitGSPF.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitGSPF initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitGSPF.
 *
 */
 
#include "RshInitGSPF.h"

RshInitGSPF::RshInitGSPF():
	RshBaseType(rshInitGSPF, sizeof(RshInitGSPF))
    {
		startType = RshInitGSPF::Program;
        frequency = 0.0;
		control = RshInitGSPF::SynthesizerOff|RshInitGSPF::FilterOff|
			RshInitGSPF::PlayOnce|RshInitGSPF::SynchroFront;
		attenuator = RshInitGSPF::AttenuationOff;
    }

RshInitGSPF::RshInitGSPF(const RshInitGSPF& obj):
	RshBaseType(obj._type, obj._typeSize)
	{
		this->control = obj.control;
		this->startType  = obj.startType;
		this->attenuator  = obj.attenuator;
	    this->frequency =  obj.frequency;
	}

RshInitGSPF& RshInitGSPF::operator=(const RshInitGSPF& obj)
	{
		if(this == &obj)
			return *this;
		this->control = obj.control;
		this->frequency = obj.frequency;
		this->startType = obj.startType;
		this->attenuator  = obj.attenuator;
		return *this;
	}

bool RshInitGSPF::operator==(RshInitGSPF& obj) const
	{
		return
			RSH_CMPDOUBLE(this->frequency, obj.frequency)	&&
			(this->startType == obj.startType)				&&
			(this->control == obj.control)					&&
			(this->attenuator  == obj.attenuator);
	}

bool RshInitGSPF::operator!=(RshInitGSPF& obj) const
	{
		return !(operator==(obj));
	}

std::ostream& operator<< (std::ostream &out, const RshInitGSPF& obj)
{
	out << "Init Structure "<<"[0x"<<std::hex<<&obj<<std::dec<<"], type: RshInitGSPF" << std::endl;
	out << "startType: [";

	std::list<const char*> features;
	if(obj.startType & RshInitGSPF::Program)
		features.push_back("Program");	
	if(obj.startType & RshInitGSPF::External)
		features.push_back("External");	
	if(obj.startType & RshInitGSPF::FrequencyExternal)
		features.push_back("FrequencyExternal");

	for(std::list<const char*>::iterator it = features.begin();
		it != features.end();++it)
	{
		out<<*it<<";";
	}

	out << "]"<< std::endl;

	out<<"attenuator: ";
	switch (obj.attenuator)
	{
	case RshInitGSPF::AttenuationOff:
	default:
		out <<"Off";
		break;
	case RshInitGSPF::Attenuation6dB:
		out <<"6dB";
		break;
	case RshInitGSPF::Attenuation12dB:
		out <<"12dB";
		break;
	case RshInitGSPF::Attenuation18dB:
		out <<"18dB";
		break;
	case RshInitGSPF::Attenuation24dB:
		out <<"24dB";
		break;
	case RshInitGSPF::Attenuation30dB:
		out <<"30dB";
		break;
	case RshInitGSPF::Attenuation36dB:
		out <<"36dB";
		break;
	case RshInitGSPF::Attenuation42dB:
		out <<"42dB";
		break;
	}
	out << std::endl;

	out<<"frequency: "<< obj.frequency << "Hz" << std::endl;

	out << "control: [";

	features.clear();
	if(obj.control & RshInitGSPF::FilterOn)
		features.push_back("FilterOn");	
	else
		features.push_back("FilterOff");	

	if(obj.control & RshInitGSPF::PlayLoop)
		features.push_back("PlayLoop");	
	else
		features.push_back("PlayOnce");

	if(obj.control & RshInitGSPF::SynchroDecline)
		features.push_back("SynchroDecline");	
	else
		features.push_back("SynchroFront");

	if(obj.control & RshInitGSPF::SynthesizerOn)
		features.push_back("SynthesizerOn");	
	else
		features.push_back("SynthesizerOff");

	for(std::list<const char*>::iterator it = features.begin();
		it != features.end();++it)
	{
		out<<*it<<";";
	}

	out << "]"<< std::endl;

	return out;
}


void RshInitGSPF::SetFilterOn(bool on)
{
	if(on)
		control |= RshInitGSPF::FilterOn;
	else
		control &= ~(RshInitGSPF::FilterOn);
}

void RshInitGSPF::SetSynthesizerOn(bool on)
{
	if(on)
		control |= RshInitGSPF::SynthesizerOn;
	else
		control &= ~(RshInitGSPF::SynthesizerOn);
}

void RshInitGSPF::SetSynchroSlopeFront()
{
	//remove RshInitGSPF::SynchroDecline flag
	control &= ~(RshInitGSPF::SynchroDecline);
}

void RshInitGSPF::SetSynchroSlopeDecline()
{
	control |= RshInitGSPF::SynchroDecline;
}

void RshInitGSPF::SetPlayModeOnce()
{
	//remove RshInitGSPF::PlayLoop flag
	control &= ~(RshInitGSPF::PlayLoop);	
}

void RshInitGSPF::SetPlayModeLoop()
{
	control |= RshInitGSPF::PlayLoop;	
}

bool RshInitGSPF::IsSynchroSlopeFrontActive() const
{
	//opposite to IsSynchroSlopeDeclineActive()
	return !IsSynchroSlopeDeclineActive();
}

bool RshInitGSPF::IsSynchroSlopeDeclineActive() const
{
	return (control & RshInitGSPF::SynchroDecline) > 0;
}

bool RshInitGSPF::IsFilterOn() const
{
	return (control & RshInitGSPF::FilterOn) > 0;
}

bool RshInitGSPF::IsSynthesizerOn() const
{
	return (control & RshInitGSPF::SynthesizerOn) > 0;
}

bool RshInitGSPF::IsPlayModeOnceOn() const
{
	//opposite to IsPlayModeLoopOn()
	return !IsPlayModeLoopOn();
}

bool RshInitGSPF::IsPlayModeLoopOn() const
{
	return (control & RshInitGSPF::PlayLoop) > 0;	
}

