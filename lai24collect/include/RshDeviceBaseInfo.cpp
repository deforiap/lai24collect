/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshDeviceBaseInfo.cpp
 * \date 28.03.2016
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshDeviceBaseInfo class and dependent types declaration.
 *
 * \~russian
 * \brief
 * Класс RshDeviceBaseInfo и связанные с ним типы данных.
 *
 */
 
#include "RshDeviceBaseInfo.h"

#include <iostream>
#include <iomanip> 

RshDeviceBaseInfo::RshDeviceBaseInfo(U16 vid, U16 pid, U16 rev, U16 chip, U16 slot, U16 base, U32 serialNumber):
	RshBaseType(rshDeviceBaseInfo, sizeof(RshDeviceBaseInfo))
	{
		this->vid = vid;
		this->pid = pid;
		this->rev = rev;
		this->chip = chip;
		this->slot = slot;
		this->base = base;
		this->serialNumber = serialNumber;
	}

RshDeviceBaseInfo::RshDeviceBaseInfo(const RshDeviceBaseInfo& pi):
	RshBaseType(pi._type, pi._typeSize)
	{
		this->vid = pi.vid;
		this->pid = pi.pid;
		this->rev = pi.rev;
		this->chip = pi.chip;
		this->slot = pi.slot;
		this->base = pi.base;
		this->serialNumber = pi.serialNumber;
	}

RshDeviceBaseInfo::RshDeviceBaseInfo(RshDataTypes type, size_t typeSize):
	RshBaseType(type, typeSize)
	{
		chip = vid = rev = pid = slot = base = 0;
		serialNumber = 0;
	}

bool RshDeviceBaseInfo::operator==(RshDeviceBaseInfo& obj) const
	{
		return
			(this->vid == obj.vid) &&
			(this->pid == obj.pid) &&
			(this->rev == obj.rev) &&
			(this->chip == obj.chip) &&
			(this->slot == obj.slot) &&
			(this->base == obj.base) &&
			(this->serialNumber == obj.serialNumber);
	}

bool RshDeviceBaseInfo::operator!=(RshDeviceBaseInfo& obj) const
	{
		return !(operator==(obj));
	}

RshDeviceBaseInfo& RshDeviceBaseInfo::operator=(const RshDeviceBaseInfo& obj)
{
	if(this == &obj)
		return *this;

	this->vid = obj.vid;
	this->pid = obj.pid;
	this->rev = obj.rev;
	this->chip = obj.chip;
	this->slot = obj.slot;
	this->base = obj.base;
	this->serialNumber = obj.serialNumber;

	return *this;
}

bool RshDeviceBaseInfo::operator<(const RshDeviceBaseInfo& obj) const {
		return this->base < obj.base;
	}

bool RshDeviceBaseInfo::operator>(const RshDeviceBaseInfo& obj) const {
		return this->base > obj.base;
	}

std::ostream& operator<< (std::ostream &out, const RshDeviceBaseInfo& obj)
{
	 // write obj to stream
	out << "[Base: " << obj.base << ", chip: " << std::hex << obj.chip << std::dec << ", slot: " << obj.slot <<
		std::hex << ", vid: 0x" << obj.vid << ", pid: 0x" << obj.pid <<
		std::dec << ", rev: " << obj.rev << ", serialNumber: " << obj.serialNumber << "]";

	return out;
}


//Template instantiation
template class RshBufferType< RshDeviceBaseInfo, rshBufferTypeDeviceBaseInfo >;
