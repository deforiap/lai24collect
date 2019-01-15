/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitDAC.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitDAC initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitDAC.
 *
 */
 
#include "RshInitDAC.h"
 
RshInitDAC::RshInitDAC(U32 ID, double Voltage):
	RshBaseType(rshInitDAC, sizeof(RshInitDAC)),
	id(ID),
	voltage(Voltage)
    { }

RshInitDAC::RshInitDAC(const RshInitDAC& obj):
	RshBaseType(obj._type, obj._typeSize)
	{
		this->id = obj.id;
	    this->voltage =  obj.voltage;
	}

RshInitDAC& RshInitDAC::operator=(const RshInitDAC& obj)
	{
		if(this == &obj)
			return *this;
		this->id = obj.id;
		this->voltage = obj.voltage;
		return *this;
	}

bool RshInitDAC::operator==(RshInitDAC& obj) const
	{
		return
			RSH_CMPDOUBLE(this->voltage, obj.voltage)	&&
			(this->id == obj.id);
	}

bool RshInitDAC::operator!=(RshInitDAC& obj) const
	{
		return !(operator==(obj));
	}

std::ostream& operator<< (std::ostream &out, const RshInitDAC& obj)
{
	out << "Init Structure "<<"[0x"<<std::hex<<&obj<<std::dec<<"], type: RshInitDAC" << std::endl;

	out<<"id: "<< obj.id << std::endl;
	out<<"voltage: "<< obj.voltage << std::endl;

	return out;
} 
