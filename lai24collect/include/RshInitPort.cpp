/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitPort.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitPort initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitPort.
 *
 */
 
#include "RshInitPort.h"

RshInitPort::RshInitPort():
	RshBaseType(rshInitPort, sizeof(RshInitPort)),
	operationType(Read),
	portAddress(0),
	portValue(0)
{ }

RshInitPort::RshInitPort(U32 address, U32 operation, U32 value):
	RshBaseType(rshInitPort, sizeof(RshInitPort)),
	operationType(operation),
	portAddress(address),
	portValue(value)
{ }

RshInitPort::RshInitPort(const RshInitPort& obj):
	RshBaseType(obj._type, obj._typeSize)
	{
		this->operationType = obj.operationType;
	    this->portAddress =  obj.portAddress;
		this->portValue =  obj.portValue;
	}

RshInitPort& RshInitPort::operator=(const RshInitPort& obj)
	{
		if(this == &obj)
			return *this;
		this->operationType = obj.operationType;
	    this->portAddress =  obj.portAddress;
		this->portValue =  obj.portValue;
		return *this;
	}

bool RshInitPort::operator==(RshInitPort& obj) const
	{
		return
			(this->operationType == obj.operationType)	&&
			(this->portAddress == obj.portAddress)		&&
			(this->portValue == obj.portValue);
	}

bool RshInitPort::operator!=(RshInitPort& obj) const
	{
		return !(operator==(obj));
	}

std::ostream& operator<< (std::ostream &out, const RshInitPort& obj)
{
	out << "Init Structure "<<"[0x"<<std::hex<<&obj<<std::dec<<"], type: RshInitPort" << std::endl;
	
	out<<"operationType: ";

	if(obj.operationType == RshInitPort::Read)
		out<<"Read";
	else if(obj.operationType == RshInitPort::Write)
		out<<"Write";
	else if(obj.operationType == RshInitPort::WriteAND)
		out<<"WriteAND";
	else if(obj.operationType == RshInitPort::WriteOR)
		out<<"WriteOR";
	else
		out<<"Unknown op="<<obj.operationType;

	out << std::endl;

	out<<"portAddress: "<< obj.portAddress << std::endl;
	out<<"portValue: "<< obj.portValue << std::endl;

	return out;
}

