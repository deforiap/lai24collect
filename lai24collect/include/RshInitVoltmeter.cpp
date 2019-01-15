/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitVoltmeter.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitVoltmeter initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitVoltmeter.
 *
 */
 
#include "RshInitVoltmeter.h"

RshInitVoltmeter::RshInitVoltmeter():
	RshBaseType(rshInitVoltmeter, sizeof(RshInitVoltmeter))
    {
		startType = Program;
		bufferSize = 1;
		filter = 200;
		control = VoltageDC;
    }

RshInitVoltmeter::RshInitVoltmeter(const RshInitVoltmeter& obj):
	RshBaseType(obj._type, obj._typeSize)
	{
		this->control = obj.control;
		this->bufferSize = obj.bufferSize;
		this->filter = obj.filter;
		this->startType = obj.startType;
	}

RshInitVoltmeter& RshInitVoltmeter::operator=(const RshInitVoltmeter& obj)
{
	if(this == &obj)
		return *this;
	this->control = obj.control;
	this->bufferSize = obj.bufferSize;
	this->filter = obj.filter;
	this->startType = obj.startType;
	return *this;
}

bool RshInitVoltmeter::operator==(RshInitVoltmeter& obj) const
	{
		return
			(this->startType == obj.startType)		&&
			(this->bufferSize == obj.bufferSize)	&&
			(this->filter == obj.filter)			&&
			(this->control == obj.control);
	}

bool RshInitVoltmeter::operator!=(RshInitVoltmeter& obj) const
	{
		return !(operator==(obj));
	}

std::ostream& operator<< (std::ostream &out, const RshInitVoltmeter& obj)
{
	out << "Init Structure "<<"[0x"<<std::hex<<&obj<<std::dec<<"], type: RshInitVoltmeter" << std::endl;

	//FIX_ME the only value that can be used is Program for now
	out<<"startType: Program"<<  std::endl;

	out<<"bufferSize: "<< obj.bufferSize <<  std::endl;

	out<<"control: ";

	if(obj.control == RshInitVoltmeter::VoltageAC)
		out<<"VoltageAC";
	else if(obj.control == RshInitVoltmeter::VoltageDC)
		out<<"VoltageDC";
	else if(obj.control == RshInitVoltmeter::CurrentAC)
		out<<"CurrentAC";
	else if(obj.control == RshInitVoltmeter::CurrentDC)
		out<<"CurrentDC";
	else 
		out<<"Unknown value="<<obj.control;

	out<<std::endl;

	out<<"filter: "<< obj.filter <<  std::endl;

	return out;
}
