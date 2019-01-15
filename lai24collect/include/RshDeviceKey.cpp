/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshDeviceKey.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshDeviceKey class.
 *
 * \~russian
 * \brief
 * Класс RshDeviceKey.
 *
 */
 
#include "RshDeviceKey.h"

RshDeviceKey::RshDeviceKey(U32 value):
	RshBaseType(rshDeviceKey, sizeof(RshDeviceKey))
	{
		this->storedTypeId = rshU32;

		this->value_U32 = value;
		this->value_S8P  = 0;
		this->value_U16P = 0;
	}

RshDeviceKey::RshDeviceKey(const S8* value):
	RshBaseType(rshDeviceKey, sizeof(RshDeviceKey))
	{
		this->storedTypeId = rshS8P;

		this->value_U32 = 0;
		this->value_S8P  = value;
		this->value_U16P = 0;
	}

RshDeviceKey::RshDeviceKey(const char* value):
	RshBaseType(rshDeviceKey, sizeof(RshDeviceKey))
	{
		this->storedTypeId = rshS8P;

		this->value_U32 = 0;
		this->value_S8P  = reinterpret_cast<const S8*>(value);
		this->value_U16P = 0;
	}


RshDeviceKey::RshDeviceKey(const U16* value):
	RshBaseType(rshDeviceKey, sizeof(RshDeviceKey))
	{
		this->storedTypeId = rshU16P;

		this->value_U32 = 0;
		this->value_S8P  = 0;
		this->value_U16P = value;
	}

RshDeviceKey::RshDeviceKey(const wchar_t* value):
	RshBaseType(rshDeviceKey, sizeof(RshDeviceKey))
	{
		this->storedTypeId = rshU16P;

		this->value_U32 = 0;
		this->value_S8P  = 0;
		this->value_U16P = reinterpret_cast<const U16*>(value);
	}

RshDeviceKey::RshDeviceKey(const RshDeviceKey& obj):
	RshBaseType(rshDeviceKey, sizeof(RshDeviceKey))
{
	this->storedTypeId = obj.storedTypeId;

	this->value_U32 = obj.value_U32;
	this->value_S8P  = obj.value_S8P;
	this->value_U16P = obj.value_U16P;
}
	
RshDeviceKey& RshDeviceKey::operator=(const RshDeviceKey& obj)
{
	if(this == &obj)
		return *this;

	this->storedTypeId = obj.storedTypeId;
	this->value_U32 = obj.value_U32;
	this->value_S8P  = obj.value_S8P;
	this->value_U16P = obj.value_U16P;

	return *this;
}
	
bool RshDeviceKey::operator==(const RshDeviceKey& obj) const
{
	if(this->storedTypeId != obj.storedTypeId)
		return false;

	if(this->value_U32 != obj.value_U32)
		return false;
	if(this->value_S8P  != obj.value_S8P)
		return false;
	if(this->value_U16P != obj.value_U16P)
		return false;
	
	return true;
}

bool RshDeviceKey::operator!=(const RshDeviceKey& obj) const
{
 return !( operator==(obj) );
}

std::ostream& operator<< (std::ostream &out, const RshDeviceKey& obj)
{
	out << "Structure "<<"[0x"<<std::hex<<&obj<<std::dec<<"], type: " << obj.GetTypeName() << std::endl;

	out<<"storedTypeId: " << RshBaseType::GetTypeName(obj.storedTypeId) << std::endl;
	switch(obj.storedTypeId)
	{
		case rshU32:
			out << "base: " << obj.value_U32 << std::endl;
			break;

		case rshS8P:
			out << "connectionString: " << obj.value_S8P << std::endl;
		break;

		case rshU16P:
			{
				std::wstring wstr = std::wstring((wchar_t*)obj.value_U16P);
				std::string converted(wstr.begin(), wstr.end());
				out << "connectionString: " << converted.c_str() << std::endl;
				break;
			}
	default:
		out << "wrong storedTypeId!" << std::endl;
	}
	return out;
}
