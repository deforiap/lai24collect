/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshDeviceFullInfo.cpp
 * \date 27.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshDeviceFullInfo class and dependent types declaration.
 *
 * \~russian
 * \brief
 * Класс RshDeviceFullInfo и связанные с ним типы данных.
 *
 */
 
#include "RshDeviceFullInfo.h"
#include "RshBufferType.h"

RshDeviceFullInfo::RshDeviceFullInfo():
 RshDeviceBaseInfo(rshDeviceFullInfo, sizeof(RshDeviceFullInfo))
{
	itype = RSH_ITYPE_UNDEFINED;
	libraryName = (S8*)"Unknown";
	libraryInterfaceName = (S8*)"Unknown";
	deviceOriginalName_EN = (U16*)L"Unknown";
	deviceOriginalName_RU = (U16*)L"Unknown";
}

RshDeviceFullInfo::RshDeviceFullInfo(const RshDeviceFullInfo& obj):
 RshDeviceBaseInfo(obj._type, obj._typeSize)
{
	this->itype = obj.itype;
	this->libraryName = obj.libraryName;
	this->libraryInterfaceName = obj.libraryInterfaceName;
	this->deviceOriginalName_RU = obj.deviceOriginalName_RU;
	this->deviceOriginalName_EN = obj.deviceOriginalName_EN;

	this->vid = obj.vid;
	this->pid = obj.pid;
	this->rev = obj.rev;
	this->chip = obj.chip;
	this->slot = obj.slot;
	this->base = obj.base;
	this->serialNumber = obj.serialNumber;
}

bool RshDeviceFullInfo::operator==(RshDeviceFullInfo& obj) const
{
	if(this->vid != obj.vid)
		return false;

	if (this->pid != obj.pid)
		return false;
	if(this->rev != obj.rev)
		return false;
	if(this->chip != obj.chip)
		return false;
	if(this->slot != obj.slot)
		return false;
	if(this->base != obj.base)
		return false;

	if (this->itype != obj.itype)
		return false;
	if (this->libraryName != obj.libraryName)
		return false;
	if (this->libraryInterfaceName != obj.libraryInterfaceName)
		return false;
	if (this->deviceOriginalName_RU != obj.deviceOriginalName_RU)
		return false;
	if (this->deviceOriginalName_EN != obj.deviceOriginalName_EN)
		return false;

	return true;
}

bool RshDeviceFullInfo::operator!=(RshDeviceFullInfo& obj) const
{
	return !(operator==(obj));
}

RshDeviceFullInfo& RshDeviceFullInfo::operator=(const RshDeviceFullInfo& obj)
{
	if (this == &obj)
		return *this;

	this->itype = obj.itype;
	this->libraryName = obj.libraryName;
	this->libraryInterfaceName = obj.libraryInterfaceName;
	this->deviceOriginalName_RU = obj.deviceOriginalName_RU;
	this->deviceOriginalName_EN = obj.deviceOriginalName_EN;

	this->vid = obj.vid;
	this->pid = obj.pid;
	this->rev = obj.rev;
	this->chip = obj.chip;
	this->slot = obj.slot;
	this->base = obj.base;
	this->serialNumber = obj.serialNumber;

	return *this;
}

RshDeviceFullInfo& RshDeviceFullInfo::operator=(const RshDeviceBaseInfo& obj)
{
	if (this == &obj)
		return *this;

	this->itype = RSH_ITYPE_UNDEFINED;
	this->libraryName = (S8*)"Unknown";
	this->libraryInterfaceName = (S8*)"Unknown";
	this->deviceOriginalName_EN = (U16*)L"Unknown";
	this->deviceOriginalName_RU = (U16*)L"Unknown";

	this->vid = obj.vid;
	this->pid = obj.pid;
	this->rev = obj.rev;
	this->chip = obj.chip;
	this->slot = obj.slot;
	this->base = obj.base;
	this->serialNumber = obj.serialNumber;

	return *this;
}


bool RshDeviceFullInfo::operator<(const RshDeviceFullInfo& obj) const
{
	return this->base < obj.base;
}

bool RshDeviceFullInfo::operator>(const RshDeviceFullInfo& obj) const
{
	return this->base > obj.base;
}

std::ostream& operator<< (std::ostream &out, const RshDeviceFullInfo& obj)
{
	// write obj to stream
	out << "[Interface: ";
	switch (obj.itype)
	{
		case RSH_ITYPE_UNDEFINED:
		default:
			out << "Undefined";
			break;
		case RSH_ITYPE_PCI:
			out << "PCI";
			break;
		case RSH_ITYPE_PCIe:
			out << "PCIe";
			break;	
		case RSH_ITYPE_USB_11:
			out << "USB 1.1";
			break;
		case RSH_ITYPE_USB_20:
			out << "USB 2.0";
			break;
		case RSH_ITYPE_USB_30:
			out << "USB 3.0";
			break;
		case RSH_ITYPE_ETH:
			out << "Ethernet";
			break;
		case RSH_ITYPE_EMULATION:
			out << "Emulation";
			break;
	}
	out << ", library name: " << obj.libraryName << ", ";
	out << "library interface: " << obj.libraryInterfaceName << ", ";
	std::wstring tmp((wchar_t*)obj.deviceOriginalName_EN);
	std::string originalName(tmp.begin(), tmp.end());
	out << "original name: " << originalName << ", ";

	//from here its the same as RshDeviceBaseInfo
	out << "base: " << obj.base << ", chip: " << std::hex << obj.chip << std::dec << ", slot: " << obj.slot <<
		std::hex << ", vid: 0x" << obj.vid << ", pid: 0x" << obj.pid <<
		std::dec << ", rev: " << obj.rev << ", serialNumber: " << obj.serialNumber << "]";

	return out;
}

template class RshBufferType< RshDeviceFullInfo, rshBufferTypeDeviceFullInfo >;
