/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshRegister.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshRegister class.
 *
 * \~russian
 * \brief
 * Класс RshRegister.
 *
 */
 
#include "RshRegister.h"
 
RshRegister::RshRegister(U32 Offset, U8 ByteSize, U32 Value):
 RshBaseType(rshRegister, sizeof (RshRegister)),
 size(ByteSize),
 offset(Offset),
 value(Value)
{ }

RshRegister::RshRegister(const RshRegister& obj):
RshBaseType(rshRegister, sizeof (RshRegister))
{
	this->size = obj.size;
	this->offset = obj.offset;
	this->value = obj.value;
}

RshRegister& RshRegister::operator=(const RshRegister& obj)
{
	if(this == &obj)
		return *this;

	this->size = obj.size;
	this->offset = obj.offset;
	this->value = obj.value;
	return *this;
}

RshRegister& RshRegister::operator=(const U32 Value)
{
	this->value = Value;
	return *this;
}

bool RshRegister::operator==(const RshRegister& obj) const
{
	if(this->size != obj.size)
		return false;
	if(this->offset != obj.offset)
		return false;
	if(this->value != obj.value)
		return false;

	return true;
}

bool RshRegister::operator!=(const RshRegister& obj) const
{
	return !( operator==(obj) );
}
bool RshRegister::operator<(const RshRegister& obj) const
{
	return (this->value < obj.value);
}

RshRegister::operator U32() const
{
	return value;
}

std::ostream& operator<< (std::ostream &out, const RshRegister& obj)
{
	return out << "[offset=" << obj.offset <<"; value=" << obj.value << "; size=" << +obj.size << "]";
}