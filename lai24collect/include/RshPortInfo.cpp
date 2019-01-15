/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshPortInfo.cpp
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshPortInfo class and dependent types declaration.
 *
 * \~russian
 * \brief
 * Класс RshPortInfo и связанные с ним типы данных.
 *
 */
 
#include "RshPortInfo.h"

RshPortInfo::RshPortInfo():
	RshBaseType(rshPortInfo, sizeof(RshPortInfo))
	{
		address = 0;
		bitSize = 0;
		name = (wchar_t*)L"";
	}

RshPortInfo::RshPortInfo(U32 address, U8 bitsize, const wchar_t* name):
	RshBaseType(rshPortInfo, sizeof(RshPortInfo))
	{
		this->address = address;
		this->bitSize = bitsize;
		this->name = name;
	}

bool RshPortInfo::operator==(RshPortInfo& obj) const
	{
		return
			(this->address == obj.address) &&
			(this->bitSize == obj.bitSize) &&
			(this->name == obj.name);
	}

bool RshPortInfo::operator!=(RshPortInfo& obj) const
	{
		return !(operator==(obj));
	}

bool RshPortInfo::operator< (const RshPortInfo& obj) const
	{
		return this->address < obj.address;
	}

bool RshPortInfo::operator> (const RshPortInfo& obj) const
	{
		return this->address > obj.address;
	}

RshPortInfo& RshPortInfo::operator=(const RshPortInfo& obj)
	{
		if(this == &obj)
			return *this;

		this->address = obj.address;
		this->bitSize = obj.bitSize;
		this->name = obj.name;

		return *this;
	}

std::ostream& operator<< (std::ostream &out, const RshPortInfo& obj)
{
	// write obj to stream (convert wchar string to char string)
	//+obj.bitSize used to out it as number and not as a char
	std::wstring wstring(obj.name);
	std::string nameString(wstring.begin(),wstring.end());
	out<<"[name: "<<nameString.c_str()<< ", address: "<<obj.address<<", bitSize: "<<+obj.bitSize<<"]";
	
	return out;
}

//Template instantiation
template class RshBufferType< RshPortInfo, rshBufferTypePortInfo >;
