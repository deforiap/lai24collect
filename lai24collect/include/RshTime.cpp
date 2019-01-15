/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshTime.cpp
 * \date 30.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshTime class.
 *
 * \~russian
 * \brief
 * Класс RshTime.
 *
 */

#include "RshTime.h"
#include "RshFunctions.h"
#include <iomanip>
#include <sstream>

 
RshTime::RshTime():
 h(0),
 m(0),
 s(0),
 ms(0),
 us(0),
 m_hashedTimeInMicroSeconds(0)
{ }

RshTime::RshTime(U8 hours, U8 minutes, U8 seconds, U16 milliseconds, U16 microseconds)
{
	this->setHMS(hours, minutes, seconds, milliseconds, microseconds);
}

RshTime::RshTime(double timeElapsed_s)
{
	this->setFromElapsed(timeElapsed_s);
}

RshTime::RshTime(const RshTime& obj)
{
	this->h = obj.h;
	this->m = obj.m;
	this->s = obj.s;
	this->ms = obj.ms;
	this->us = obj.us;
	this->m_hashedTimeInMicroSeconds = obj.m_hashedTimeInMicroSeconds;
}

RshTime& RshTime::operator=(const RshTime& obj)
{
	if(this == &obj)
		return *this;

	this->h = obj.h;
	this->m = obj.m;
	this->s = obj.s;
	this->ms = obj.ms;
	this->us = obj.us;
	this->m_hashedTimeInMicroSeconds = obj.m_hashedTimeInMicroSeconds;

	return *this;
}

std::ostream& operator<< (std::ostream &out, const RshTime& obj)
{
	out << obj.toString();
	return out;
}

void RshTime::setHMS(U8 hours, U8 minutes, U8 seconds, U16 milliseconds, U16 microseconds)
{
	h = RshCutV<U8>(hours, 0, 59);
	m = RshCutV<U8>(minutes, 0, 59);
	s = RshCutV<U8>(seconds, 0, 59);
	ms = RshCutV<U16>(milliseconds, 0, 999);
	us = RshCutV<U16>(microseconds, 0, 999);

	//calculate hash
	calculateTimeInMicroSeconds();
}

void RshTime::setFromElapsed(double timeElapsed_s)
{
	if (timeElapsed_s > 24 * 3600.0)
	{
		h = 23;
		m = 59;
		s = 59;
		ms = 999;
		us = 999;
	}
	else
	{
		double timeLeft = timeElapsed_s;
		h = static_cast<U8>(timeLeft / (60 * 60));
		timeLeft -= h * 60*60;

		m = static_cast<U8>(timeLeft / 60);
		timeLeft -= m * 60;

		s = static_cast<U8>(timeLeft) % 60;
		timeLeft -= s;

		ms = static_cast<U16>(timeLeft * 1000) % 1000;
		timeLeft -= ms/1000.0;

		us = static_cast<U16>(timeLeft * 1000 * 1000) % 1000;

		RshCut<U8>(h, 0, 23);
		RshCut<U8>(m, 0, 59);
		RshCut<U8>(s, 0, 59);
		RshCut<U16>(ms, 0, 999);
		RshCut<U16>(us, 0, 999);
	}

	//calculate hash
	calculateTimeInMicroSeconds();
}


RshTime RshTime::currentTime()
{
	RshTime curTime;

#if defined(RSH_MSWINDOWS)
    SYSTEMTIME stime;   //structure to store system time (in usual time format)
    FILETIME ltime;     //structure to store local time (local time in 64 bits)
    FILETIME ftTimeStamp;

    GetSystemTimeAsFileTime(&ftTimeStamp); // Gets the current system time
    FileTimeToLocalFileTime (&ftTimeStamp,&ltime);//convert in local time and store in ltime
    FileTimeToSystemTime(&ltime,&stime);//convert in system time and store in stime
	
    curTime.h = static_cast<U8>(stime.wHour);
    curTime.m = static_cast<U8>(stime.wMinute);
    curTime.s = static_cast<U8>(stime.wSecond);
    curTime.ms = stime.wMilliseconds;
	curTime.us = 0;

#elif defined (RSH_LINUX)
	struct timeval tv;
	struct timezone tz;
	struct tm *tm;
	gettimeofday(&tv,&tz);
	tm = localtime(&tv.tv_sec);

	curTime.h = tm->tm_hour;
    curTime.m = tm->tm_min;
    curTime.s = tm->tm_sec;
    curTime.ms = (U16)(tv.tv_usec / 1000);
	curTime.us = (U16)(tv.tv_usec % 1000); 
#endif

	//calculate hash
	curTime.calculateTimeInMicroSeconds();

	return curTime;
}

void RshTime::replaceAll(std::string &s, const std::string &search, const std::string &replace)
{
    for( size_t pos = 0; ; pos += replace.length() )
	{
        // Locate the substring to replace
        pos = s.find( search, pos );
        if( pos == std::string::npos )
			break;
        // Replace by erasing and inserting
        s.erase( pos, search.length() );
        s.insert( pos, replace );
    }
}

void RshTime::replaceAll(std::wstring &s, const std::wstring &search, const std::wstring &replace)
{
    for( size_t pos = 0; ; pos += replace.length() )
	{
        // Locate the substring to replace
        pos = s.find( search, pos );
        if( pos == std::string::npos )
			break;
        // Replace by erasing and inserting
        s.erase( pos, search.length() );
        s.insert( pos, replace );
    }
}

void RshTime::calculateTimeInMicroSeconds() const
{
	//convert all to microseconds
	m_hashedTimeInMicroSeconds = static_cast<U64>(this->us) + static_cast<U64>(this->ms)*1000L +
		(static_cast<U64>(this->s)  + (static_cast<U64>(this->m)  + static_cast<U64>(this->h) * 60) * 60  ) * 1000000L;
}

std::string RshTime::toString(const std::string& format) const 
{
	std::string resultString = std::string(format);
	
	std::ostringstream timeStream; 

	//convert hours to string
	timeStream << std::setw(2) << std::setfill('0') << +h;
	std::string stringHours = timeStream.str();
	timeStream.str("");
	timeStream.clear();

	//convert minutes to string
	timeStream << std::setw(2) << std::setfill('0') << +m;
	std::string stringMinutes = timeStream.str();
	timeStream.str("");
	timeStream.clear();

	//convert seconds to string
	timeStream << std::setw(2) << std::setfill('0') << +s;
	std::string stringSeconds = timeStream.str();
	timeStream.str("");
	timeStream.clear();
	
	//convert milliseconds to string
	timeStream << std::setw(3) << std::setfill('0') << +ms;
	std::string stringMilliSeconds = timeStream.str();
	timeStream.str("");
	timeStream.clear();

	//convert microseconds to string
	timeStream << std::setw(3) << std::setfill('0') << +us;
	std::string stringMicroSeconds = timeStream.str();
		
	//replace all units with real values in result string
	replaceAll(resultString, "hh", stringHours);
	replaceAll(resultString, "mm", stringMinutes);
	replaceAll(resultString, "ss", stringSeconds);
	replaceAll(resultString, "zzz", stringMilliSeconds);
	replaceAll(resultString, "uuu", stringMicroSeconds);

	return resultString;	
}

std::wstring RshTime::toWString(const std::wstring& format) const
{
	std::wstring resultString = std::wstring(format);
	
	std::wostringstream timeStream; 

	//convert hours to string
	timeStream << std::setw(2) << std::setfill(L'0') << +h;
	std::wstring stringHours = timeStream.str();
	timeStream.str(L"");
	timeStream.clear();

	//convert minutes to string
	timeStream << std::setw(2) << std::setfill(L'0') << +m;
	std::wstring stringMinutes = timeStream.str();
	timeStream.str(L"");
	timeStream.clear();

	//convert seconds to string
	timeStream << std::setw(2) << std::setfill(L'0') << +s;
	std::wstring stringSeconds = timeStream.str();
	timeStream.str(L"");
	timeStream.clear();
	
	//convert milliseconds to string
	timeStream << std::setw(3) << std::setfill(L'0') << +ms;
	std::wstring stringMilliSeconds = timeStream.str();
	timeStream.str(L"");
	timeStream.clear();

	//convert microseconds to string
	timeStream << std::setw(3) << std::setfill(L'0') << +us;
	std::wstring stringMicroSeconds = timeStream.str();
		
	//replace all units with real values in result string
	replaceAll(resultString, L"hh", stringHours);
	replaceAll(resultString, L"mm", stringMinutes);
	replaceAll(resultString, L"ss", stringSeconds);
	replaceAll(resultString, L"zzz", stringMilliSeconds);
	replaceAll(resultString, L"uuu", stringMicroSeconds);

	return resultString;	
}

bool RshTime::operator==(const RshTime& obj) const
{
	return this->m_hashedTimeInMicroSeconds == obj.m_hashedTimeInMicroSeconds;
}

bool RshTime::operator<(const RshTime& obj) const
{
	return this->m_hashedTimeInMicroSeconds < obj.m_hashedTimeInMicroSeconds;
}

bool RshTime::operator!=(const RshTime& obj) const 
{
	return this->m_hashedTimeInMicroSeconds != obj.m_hashedTimeInMicroSeconds;
}

bool RshTime::operator>(const RshTime& obj) const
{
	return this->m_hashedTimeInMicroSeconds > obj.m_hashedTimeInMicroSeconds;
}

bool RshTime::operator<=(const RshTime& obj) const
{
	return this->m_hashedTimeInMicroSeconds <= obj.m_hashedTimeInMicroSeconds;
}

bool RshTime::operator>=(const RshTime& obj) const
{
	return this->m_hashedTimeInMicroSeconds >= obj.m_hashedTimeInMicroSeconds;
}

U64 RshTime::toMicroSeconds() const
{
	return m_hashedTimeInMicroSeconds;
}
