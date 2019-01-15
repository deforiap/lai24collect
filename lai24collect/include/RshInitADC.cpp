/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitADC.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitADC initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitADC.
 *
 */
 
#include "RshInitADC.h"

RshInitADC::RshInitADC(const RshDataTypes type, const size_t sizeType):
	RshBaseType(type, sizeType)
	{
		startType = RshInitADC::Program;
		frequency = 0;
		bufferSize = 0;
		controlSynchro = 0;
		threshold = 0.0;
	}
RshInitADC::RshInitADC(const RshInitADC& obj):
	RshBaseType(obj._type, obj._typeSize)
	{
		this->startType  = obj.startType;
		this->bufferSize =  obj.bufferSize;
	    this->frequency =  obj.frequency;
		this->controlSynchro = obj.controlSynchro;
		this->threshold = obj.threshold;		

		this->channels.Copy(obj.channels);
	}

RshInitADC& RshInitADC::operator=(const RshInitADC& obj)
	{
		if(this == &obj)
			return *this;
		this->bufferSize = obj.bufferSize;
		this->channels = obj.channels;		
		this->frequency = obj.frequency;	
		this->startType = obj.startType;
		this->controlSynchro = obj.controlSynchro;
		this->threshold = obj.threshold;
		
		return *this;
	}

bool RshInitADC::operator==(RshInitADC& obj) const
	{
		return
			(this->bufferSize == obj.bufferSize)			&&
			(this->channels == obj.channels)				&&
			(this->controlSynchro == obj.controlSynchro)	&&		
			RSH_CMPDOUBLE(this->frequency, obj.frequency)	&&
			RSH_CMPDOUBLE(this->threshold, obj.threshold)	&&
			(this->startType == obj.startType);

	}

bool RshInitADC::operator!=(RshInitADC& obj) const
	{
		return !(operator==(obj));
	}


U32 RshInitADC::ActiveChannelsNumber() const
{
	U32 count = 0;
	for(U32 i=0; i<channels.Size(); ++i)
	{
		if(channels.ptr[i].IsUsed())
			count++;
	}
	return count;
}

std::ostream& operator<< (std::ostream &out, const RshInitADC& obj) 
{
	out << "Init Structure "<<"[0x"<<std::hex<<&obj<<std::dec<<"], type: RshInitADC" << std::endl;
	out << "startType: [";

	std::list<const char*> features;
	if(obj.startType & RshInitADC::Program)
		features.push_back("Program");
	if(obj.startType & RshInitADC::Internal)
		features.push_back("Internal");
	if(obj.startType & RshInitADC::External)
		features.push_back("External");
	if(obj.startType & RshInitADC::Master)
		features.push_back("Master");
	if(obj.startType & RshInitADC::Timer)
		features.push_back("Timer");
	if(obj.startType & RshInitADC::FrequencyExternal)
		features.push_back("FrequencyExternal");

	for(std::list<const char*>::iterator it = features.begin();
		it != features.end();++it)
	{
		out<<*it<<";";
	}

	out << "]"<< std::endl;

	out << "bufferSize: " << obj.bufferSize << std::endl;
	out << "frequency: " << obj.frequency << "Hz" << std::endl;


	out << "controlSynchro: [";
	features.clear();
	if(obj.controlSynchro & RshInitADC::SlopeDecline)
		features.push_back("SlopeDecline");
	else
		features.push_back("SlopeFront");

	if(obj.controlSynchro & RshInitADC::FrequencySwitchToMinimum)
		features.push_back("FrequencySwitchToMinimum");
	else if(obj.controlSynchro & RshInitADC::FrequencySwitchToMaximum)
		features.push_back("FrequencySwitchToMaximum");
	else 
		features.push_back("FrequencySwitchOff");

	for(std::list<const char*>::iterator it = features.begin();
		it != features.end();++it)
	{
		out<<*it<<";";
	}
	out << "]"<< std::endl;

	out << "threshold: " << obj.threshold << std::endl;

	out << "channels: ";

	if(obj.channels.Size() == 0)
		out<<"channel buffer is not initialized (size==0)" << std::endl;
	else
		out << obj.channels;

	return out;
}

void RshInitADC::SetSynchroSlopeFront()
{
	//remove RshInitADC::SlopeDecline flag
	controlSynchro &= ~(RshInitADC::SlopeDecline);
}

void RshInitADC::SetSynchroSlopeDecline()
{
	controlSynchro |= RshInitADC::SlopeDecline;
}

bool RshInitADC::IsSynchroSlopeFrontActive() const
{
	//opposite to IsSynchroSlopeDeclineActive()
	return !IsSynchroSlopeDeclineActive();
}

bool RshInitADC::IsSynchroSlopeDeclineActive() const
{
	return (controlSynchro & RshInitADC::SlopeDecline) > 0;
}

void RshInitADC::SetSynchroFreqSwitchOff()
{
	//remove both flags
	controlSynchro &= ~(RshInitADC::FrequencySwitchToMaximum);
	controlSynchro &= ~(RshInitADC::FrequencySwitchToMinimum);
}

void RshInitADC::SetSynchroFreqSwitchToMin()
{
	controlSynchro |= RshInitADC::FrequencySwitchToMinimum;
}

void RshInitADC::SetSynchroFreqSwitchToMax()
{
	controlSynchro |= RshInitADC::FrequencySwitchToMaximum;
}

bool RshInitADC::IsSynchroFreqSwitchToMinActive() const
{
	return (controlSynchro & RshInitADC::FrequencySwitchToMinimum) > 0;
}

bool RshInitADC::IsSynchroFreqSwitchToMaxActive() const
{
	return (controlSynchro & RshInitADC::FrequencySwitchToMaximum) > 0;
}
