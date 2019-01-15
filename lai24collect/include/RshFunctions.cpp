/*!
 * \copyright JSC "Rudnev-Shilyaev"
 * 
 * \file RshFunctions.cpp
 * \date 01.03.2016
 * \version 1.0 [SDK 2.1]
 * 
 * \~english
 * \brief
 * Global functions.
 * 
 * This file contains implementation of common functions used within RSH SDK code.
 * 
 * \~russian
 * \brief
 * Глобальные функции.
 * 
 * В этом файле содержится реализация часто используемых функций, применяемых в RSH SDK.
 * 
 */

#ifndef RSH_FUNCTIONS_CPP
#define RSH_FUNCTIONS_CPP

#include "RshFunctions.h"
#include "RshMacro.h"
#include <limits>
#include <sstream>
#include <iomanip>

U64 RshMix() // tries to get unique number
{
	U64 a, b, c;
	a = clock(), b = time(NULL), c = __rshgetpid();

    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
	a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

U64 RshMix(U64 seed) // tries to get unique number
{
	U64 a, b, c;
	a = seed, b = time(NULL), c = __rshgetpid();

    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

U32 RshCRC32(U8 *buf, size_t len)
{
	if(!buf)
		return 0;
	if(len<1)
		return 0;

    U32 crc_table[256];
    U32 crc; S32 i, j;
 
    for (i = 0; i < 256; i++)
    {
        crc = i;
        for (j = 0; j < 8; j++)
            crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;
 
        crc_table[i] = crc;
    };
 
    crc = 0xFFFFFFFFUL;
 
    while (len--) 
        crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);
 
    return crc ^ 0xFFFFFFFFUL;
}

double RshRoundD(double val, double pre) // round double value
{
	int sign = ( val >= 0 ) ? 1 : -1;

	val *= sign;

	pre = pow( 10.0, pre );
	val = ((U64)( val * pre + 0.5 )) / pre;

	val *= sign;

	return val;
}


double RshLsbToVoltCoef(U32 gain, double range, U8 bitSize)
{
	if(RSH_CMPDOUBLE(range, 0.0))
		return 1.0;
	else
		return (((U64)1<<bitSize)/range) * gain;
}
double RshVoltToLsbCoef(U32 gain, double range, U8 bitSize)
{
	if(gain==0)
		return 1.0;
	else
		return (range / gain) / ((U64)1<<bitSize);
}

double RshLsbToVolt(double lsb, U32 gain, double range, U8 bitSize)
{	
	return lsb * RshVoltToLsbCoef(gain,range,bitSize);
}

double RshVoltToLsb(double voltage, U32 gain, double range, U8 bitSize)
{
	return voltage * RshLsbToVoltCoef(gain,range,bitSize);
}



const wchar_t* RshConvertToUTF16(const char* pStr)
{
	#if defined(RSH_MSWINDOWS)
		static wchar_t szBuf[1024];
		MultiByteToWideChar(CP_UTF8, 0, pStr, -1, szBuf, sizeof(szBuf));
		return szBuf;

	#elif defined(RSH_LINUX)
	    std::string tmp(pStr);
		static std::wstring szBuf;
        szBuf = std::wstring(tmp.begin(),tmp.end());
        //szBuf = std::wstring((wchar_t*)pStr);             
		return szBuf.c_str();
	#endif
}

//RshCopyStringToBuffer function
template<typename T, RshDataTypes dataCode>
U32 RshCopyStringToBuffer(const char* str, RshBufferType<T, dataCode>& userBuffer)
{
	return RSH_API_PARAMETER_NOTSUPPORTED;	
}

//specializations for char buffer types
template<>
U32 RshCopyStringToBuffer(const char* str, RshBufferType<S8, rshBufferTypeS8>& userBuffer)
{
	if(str == NULL)
		return RSH_API_PARAMETER_ZEROADDRESS;

	size_t copyLength = strlen(str) + 1;

	if(copyLength>userBuffer.PSize())
		copyLength = userBuffer.PSize();

	userBuffer.Copy(reinterpret_cast<const S8*>(str), copyLength, copyLength);
	return RSH_API_SUCCESS;
}

template<>
U32 RshCopyStringToBuffer(const char* str, RshBufferType<U8, rshBufferTypeU8>& userBuffer)
{
	if(str == NULL)
		return RSH_API_PARAMETER_ZEROADDRESS;

	size_t copyLength = strlen(str) + 1;

	if(copyLength>userBuffer.PSize())
		copyLength = userBuffer.PSize();

	userBuffer.Copy(reinterpret_cast<const U8*>(str), copyLength, copyLength);
	return RSH_API_SUCCESS;
}

//RshFillBufferWithRandomNumbers function
template<typename T, RshDataTypes dataCode>
U32 RshFillBufferWithRandomNumbers(RshBufferType<T, dataCode>& userBuffer, U32 seed)
{
	return RSH_API_PARAMETER_NOTSUPPORTED;
}

//specializations for numeric buffer types
template<>
U32 RshFillBufferWithRandomNumbers<U8, rshBufferTypeU8>(RshBufferType<U8, rshBufferTypeU8>& userBuffer, U32 seed)
{
	if (seed ==0)
		std::srand((unsigned int) RshMix());
	else
		std::srand(seed);
	
	const int max = std::numeric_limits<U8>::max();
	
	for (size_t i = 0; i < userBuffer.PSize(); ++i)
		userBuffer.ptr[i] = rand() % max;

	userBuffer.SetSize(userBuffer.PSize());

	return RSH_API_SUCCESS;	
}

template<>
U32 RshFillBufferWithRandomNumbers<S8, rshBufferTypeS8>(RshBufferType<S8, rshBufferTypeS8>& userBuffer, U32 seed)
{
	if (seed ==0)
		std::srand((unsigned int) RshMix());
	else
		std::srand(seed);

	const int min = std::numeric_limits<S8>::min();
	const int max = std::numeric_limits<S8>::max();
	
	for (size_t i = 0; i < userBuffer.PSize(); ++i)
		userBuffer.ptr[i] = min + rand() % (max - min);

	userBuffer.SetSize(userBuffer.PSize());

	return RSH_API_SUCCESS;	
}

template<>
U32 RshFillBufferWithRandomNumbers<U16, rshBufferTypeU16>(RshBufferType<U16, rshBufferTypeU16>& userBuffer, U32 seed)
{
	if (seed ==0)
		std::srand((unsigned int) RshMix());
	else
		std::srand(seed);
	
	for (size_t i = 0; i < userBuffer.PSize(); ++i)
		userBuffer.ptr[i] = rand();

	userBuffer.SetSize(userBuffer.PSize());

	return RSH_API_SUCCESS;	
}

template<>
U32 RshFillBufferWithRandomNumbers<S16, rshBufferTypeS16>(RshBufferType<S16, rshBufferTypeS16>& userBuffer, U32 seed)
{
	if (seed ==0)
		std::srand((unsigned int) RshMix());
	else
		std::srand(seed);
	
	for (size_t i = 0; i < userBuffer.PSize(); ++i)
		userBuffer.ptr[i] =-RAND_MAX/2 + rand();

	userBuffer.SetSize(userBuffer.PSize());

	return RSH_API_SUCCESS;	
}

template<>
U32 RshFillBufferWithRandomNumbers<U32, rshBufferTypeU32>(RshBufferType<U32, rshBufferTypeU32>& userBuffer, U32 seed)
{
	if (seed ==0)
		std::srand((unsigned int) RshMix());
	else
		std::srand(seed);
	
	for (size_t i = 0; i < userBuffer.PSize(); ++i)
		userBuffer.ptr[i] = rand();

	userBuffer.SetSize(userBuffer.PSize());

	return RSH_API_SUCCESS;	
}

template<>
U32 RshFillBufferWithRandomNumbers<S32, rshBufferTypeS32>(RshBufferType<S32, rshBufferTypeS32>& userBuffer, U32 seed)
{
	if (seed ==0)
		std::srand((unsigned int) RshMix());
	else
		std::srand(seed);
	
	for (size_t i = 0; i < userBuffer.PSize(); ++i)
		userBuffer.ptr[i] = -RAND_MAX/2 + rand();

	userBuffer.SetSize(userBuffer.PSize());

	return RSH_API_SUCCESS;	
}

template<>
U32 RshFillBufferWithRandomNumbers<double, rshBufferTypeDouble>(RshBufferType<double, rshBufferTypeDouble>& userBuffer, U32 seed)
{
	if (seed ==0)
		std::srand((unsigned int) RshMix());
	else
		std::srand(seed);
	
	for (size_t i = 0; i < userBuffer.PSize(); ++i)
		userBuffer.ptr[i] = -RAND_MAX/2 + rand();

	userBuffer.SetSize(userBuffer.PSize());

	return RSH_API_SUCCESS;	
}

template<>
U32 RshFillBufferWithRandomNumbers<float, rshBufferTypeFloat>(RshBufferType<float, rshBufferTypeFloat>& userBuffer, U32 seed)
{
	if (seed ==0)
		std::srand((unsigned int) RshMix());
	else
		std::srand(seed);
	
	for (size_t i = 0; i < userBuffer.PSize(); ++i)
		userBuffer.ptr[i] = static_cast<float>(-RAND_MAX/2 + rand());

	userBuffer.SetSize(userBuffer.PSize());

	return RSH_API_SUCCESS;	
}

std::string RshFormatValueString(const double value, const std::string& unitString, const U32 precision, RSH_LANGUAGE language)
{
	
	double absValue = fabs(value);

	std::ostringstream stream;
	stream << std::fixed << std::setprecision( precision );

	if (RSH_CMPDOUBLE(value, 0.0))
	{
		stream << value << unitString;
		std::string str = stream.str();
		return str;
	}

	const char* siPrefixEn[] = {"n", "u", "m", "", "k", "M", "G"};
	const char* siPrefixRu[] = {"н", "мк", "м", "", "к", "М", "Г"};

	//precalculate constant
	static const double derLog = 1.0/log(1000.);

	//what power is our number
	double exp = (log(absValue) * derLog);	

	//integer part of exp (will be used to calcualte 1000.0^power)
	int power = static_cast<int>(exp);

	if (exp < 0)
		power--;

	//index in prefix table 
	int index = power + 3;
	RshCut(index, 0, 6);

	const char* prefix = "";
	if(language == RSH_LANGUAGE_ENGLISH)
		prefix = siPrefixEn[index];
	else if (language == RSH_LANGUAGE_RUSSIAN)
		prefix = siPrefixRu[index];	

	stream << value/pow(1000.0, power) << prefix << unitString;
	std::string str = stream.str();
	return str;
}

#endif //RSH_FUNCTIONS_CPP
