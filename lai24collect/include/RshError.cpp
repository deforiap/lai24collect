/*!
 * \copyright JSC "Rudnev-Shilyaev"
 * 
 * \file RshError.cpp
 * \date 24.12.2015
 * \version 1.0 [SDK 2.1]
 * 
 * \~english
 * \brief
 * Error process class and data structures connected.
 * 
 * \~russian
 * \brief
 * Класс для формирования сообщений об ошибках и связанные структуры данных.
 * 
 */

#ifndef RSHERROR_CPP
#define RSHERROR_CPP

#include "RshError.h"
#include "RshErrorDescription.h"
#include "RshMacro.h"

#include <sstream>

//set constant members
const std::map<RSH_STATUS, std::wstring> RshError::m_errorsRu = RshError::populateMap(RSH_LANGUAGE_RUSSIAN);
const std::map<RSH_STATUS, std::wstring> RshError::m_errorsEn = RshError::populateMap(RSH_LANGUAGE_ENGLISH);

U32 RshError::GetSystemErrorDescription(U32 error, std::wstring& str)
{

	str = L"";

#if defined(RSH_MSWINDOWS)
	U32 winApiCode = error & 0xffff;
	wchar_t* err = 0;		
		
	U32 len = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                           NULL,
                           winApiCode,
						   0, // default language
                           (LPTSTR) &err,
                           0,
                           NULL);
	if( len == 0 || err == NULL)
	{
		return RSH_API_FUNCTION_ERRORHAPPEND|GetLastError();
	}
	str = std::wstring(err);
	//remove special codes from string (they will break wcout stream)
	str.erase (std::remove(str.begin(), str.end(), 10), str.end());
	str.erase (std::remove(str.begin(), str.end(), 13), str.end());
#elif defined(RSH_LINUX)
	char* errormsg = strerror(error & 0xffff);
	std::string tmp = std::string(errormsg);
	str = std::wstring(tmp.begin(),tmp.end());   
#endif
	return RSH_API_SUCCESS;
}

U32 RshError::GetSystemErrorDescription(U32 error, std::string& str)
{
	std::wstring tempString;
	U32 res = GetSystemErrorDescription(error, tempString);
	if(res != RSH_API_SUCCESS)
		return res;

	res = convertWStringToStirng(tempString, str);

	return res;
}

U32 RshError::GetSystemErrorDescription(U32 error, wchar_t* str, U32 maxLength)
{
	if(!str)
		return RSH_API_PARAMETER_ZEROADDRESS;

	if(maxLength == 0)
		return RSH_API_PARAMETER_INVALID;

	std::wstring errorMessage;
	U32 res = GetSystemErrorDescription(error, errorMessage);
	if(res != RSH_API_SUCCESS)
		return res;

	//copy message to user buffer
	U32 copySize = errorMessage.length()>maxLength-1 ? maxLength-1: errorMessage.length();

	try
	{
		memcpy(str,errorMessage.c_str(), copySize*sizeof(wchar_t));
		str[copySize] = 0;
	}
	catch(...)
	{
		return RSH_API_MEMORY_COPYERROR;
	}

	return RSH_API_SUCCESS;
}

//------------------------------------------------------------------------------------------------
U32 RshError::GetSystemErrorDescription(U32 error, char* str, U32 maxLength)
{
	if(!str)
		return RSH_API_PARAMETER_ZEROADDRESS;

	if(maxLength == 0)
		return RSH_API_PARAMETER_INVALID;

	std::string errorMessage = "";
	U32 res = GetSystemErrorDescription(error, errorMessage);
	if(res != RSH_API_SUCCESS)
		return res;

	//copy message to user bufer
	U32 copySize = errorMessage.length()>maxLength-1 ? maxLength-1: errorMessage.length();
	
	try
	{
		memcpy(str,errorMessage.c_str(), copySize*sizeof(char));
		str[copySize] = 0;
	}
	catch(...)
	{
		return RSH_API_MEMORY_COPYERROR;
	}
	
	return RSH_API_SUCCESS;
}

U32 RshError::GetErrorDescription(U32 error, std::wstring& str, RSH_LANGUAGE language)
{
	RSH_STATUS errorCodeRsh = static_cast<RSH_STATUS>(error & 0xffff0000);

	switch (language)
	{
		case RSH_LANGUAGE_RUSSIAN:
		{
			std::map<RSH_STATUS, std::wstring>::const_iterator it = m_errorsRu.find(errorCodeRsh);
			if (it != m_errorsRu.end())			
				str = it->second;		
			else
			{
				std::wstringstream streamVal;
				streamVal << std::hex << (error & ~0xffff);
				str = std::wstring(rshUTF16("Error not found. Error code:  0x")) + streamVal.str();
			}
			break;
		}
		case RSH_LANGUAGE_ENGLISH:
		default:
		{
			std::map<RSH_STATUS, std::wstring>::const_iterator it = m_errorsEn.find(errorCodeRsh);
			if (it != m_errorsEn.end())
				str = it->second;
			else
			{
				std::wstringstream streamVal;
				streamVal << std::hex << (error & ~0xffff);
				str = std::wstring(rshUTF16("Неизвестная ошибка. Код ошибки:  0x")) + streamVal.str();
			}
			break;
		}
	}	

	return RSH_API_SUCCESS;
}

U32 RshError::GetErrorDescription(U32 error, std::string& str,  RSH_LANGUAGE language)
{
	std::wstring tempString;

	U32 res = GetErrorDescription(error, tempString, language);
	if(res != RSH_API_SUCCESS)
		return res;

	res = convertWStringToStirng(tempString, str);

	return res;
}

//------------------------------------------------------------------------------------------------
U32 RshError::GetErrorDescription(U32 error, wchar_t* str, U32 maxLength, RSH_LANGUAGE language)
{
	if(!str)
		return RSH_API_PARAMETER_ZEROADDRESS;

	if(maxLength == 0)
		return RSH_API_PARAMETER_INVALID;	
	
	
	std::wstring errorMessage;

	U32 res = GetErrorDescription(error, errorMessage, language);
	if(res != RSH_API_SUCCESS)
		return res;

	//copy data to user buffer
	U32 copySize = errorMessage.length()>maxLength-1 ? maxLength-1: errorMessage.length();

	try
	{
		memcpy(str,errorMessage.c_str(), copySize*sizeof(wchar_t));
		str[copySize] = 0;
	}
	catch(...)
	{
		return RSH_API_MEMORY_COPYERROR;
	}

	return RSH_API_SUCCESS;
}	

//------------------------------------------------------------------------------------------------
U32 RshError::GetErrorDescription(U32 error, char* str, U32 maxLength, RSH_LANGUAGE language)
{
	if(!str)
		return RSH_API_PARAMETER_ZEROADDRESS;

	if(maxLength == 0)
		return RSH_API_PARAMETER_INVALID;

	std::string errorMessage = "";
	U32 res = GetErrorDescription(error, errorMessage, language);
	if(res != RSH_API_SUCCESS)
		return res;

	//copy message to user buffer
	U32 copySize = errorMessage.length()>maxLength-1 ? maxLength-1: errorMessage.length();
	
	try
	{
		memcpy(str,errorMessage.c_str(), copySize*sizeof(char));
		str[copySize] = 0;
	}
	catch(...)
	{
		return RSH_API_MEMORY_COPYERROR;
	}
	
	return RSH_API_SUCCESS;
}
//------------------------------------------------------------------------------------------------
void RshError::PrintError(U32 error, RSH_LANGUAGE language, bool includeSystemErrorInfo)
{
		#if defined(RSH_MSWINDOWS)
		  _wsetlocale( LC_ALL, L"Russian" );
		  setlocale( LC_ALL, "Russian" );
		#elif defined(RSH_LINUX)
          setlocale( LC_ALL, "ru_RU.utf8" );
		#endif

		if(error != RSH_API_SUCCESS)
		{
			if(language == RSH_LANGUAGE_RUSSIAN)
				std::wcout<< rshUTF16("--ОШИБКА[0x");
			else 
				std::wcout << std::endl << rshUTF16("--ERROR[0x");

		
			std::wstring errorString;
			
            U32 res = RshError::GetErrorDescription(error & ~0xffff, errorString, language);
			if(res == RSH_API_SUCCESS)
			{
				std::wcout << std::hex
					<< (error & 0xffff0000) << rshUTF16("]-- ")
					<< errorString << std::endl ;
			}
			else
			{
				std::wcout <<rshUTF16("Couldn't format error message - GetErrorDescriptionUTF16 failed with code 0x")<<std::hex<<res;
			}
			
			if(includeSystemErrorInfo && (error & 0xffff) )
			{
                U32 res = RshError::GetSystemErrorDescription( error & 0xffff, errorString);
				if(res == RSH_API_SUCCESS)
				{

					if(language == RSH_LANGUAGE_RUSSIAN)
						std::wcout<<std::endl<<rshUTF16("Системная ошибка [");
					else
						std::wcout<<std::endl<<rshUTF16("System error [");

					std::wcout << std::dec << (error & 0xffff) << rshUTF16("]: ");                          
									std::wcout << errorString << std::endl;
				}
				else
				{
					std::wcout << rshUTF16("Couldn't format error message - GetSystemErrorDescriptionUTF16 failed with code 0x") << std::hex << res;
				}
			}
			
		}
		else
		{
			if(language == RSH_LANGUAGE_RUSSIAN)
				std::wcout<<std::endl<< rshUTF16("--УСПЕХ--")<<std::endl;
			else 
				std::wcout<<std::endl<< rshUTF16("--SUCCESS--")<<std::endl;		
		}
}

//------------------------------------------------------------------------------------------------
void RshError::PrintErrorDebug(U32 error, const wchar_t* message, bool includeSystemErrorInfo)
{
		#if defined(RSH_MSWINDOWS)
		_wsetlocale( LC_ALL, L"Russian" );	
		#elif defined(RSH_LINUX)
          setlocale( LC_ALL, "ru_RU.utf8" );
		#endif
		RSH_LANGUAGE language = RSH_LANGUAGE_ENGLISH;

		if(error != RSH_API_SUCCESS)
		{	
			std::wcout << std::endl << rshUTF16("--ERROR[0x");
		
			std::wstring errorString;

            U32 res = RshError::GetErrorDescription(error & ~0xffff, errorString, language);
			if(res == RSH_API_SUCCESS)
			{
				std::wcout << std::hex
				<< (error & 0xffff0000) << rshUTF16("]-- ");
				if(message)
					std::wcout<<message;
				else
					std::wcout<<rshUTF16("~~!wchar_t* message points to NULL!~~");
				std::wcout << rshUTF16(": ") << errorString <<std::endl ;
			}
			else
			{
				std::wcout << rshUTF16("Couldn't format error message - GetErrorDescriptionUTF16 failed with code 0x")<<std::hex<<res;
			}		
			
			if(includeSystemErrorInfo && (error & 0xffff) )
			{
                U32 res = RshError::GetSystemErrorDescription( error & 0xffff, errorString);
				if(res == RSH_API_SUCCESS)
				{
					std::wcout << std::endl << rshUTF16("System error [");
					std::wcout << std::dec << (error & 0xffff) << rshUTF16("]: ");                          
                                std::wcout << errorString << std::endl;
				}
				else
				{
					std::wcout << rshUTF16("Couldn't format error message - GetSystemErrorDescriptionUTF16 failed with code 0x")<<std::hex<<res;
				}
			}
			
		}
		else
		{
			std::wcout<<std::endl<< rshUTF16("--SUCCESS-- ")<<message<<std::endl;		
		}
}

void RshError::PrintErrorDebug(U32 error, const char* message, bool includeSystemErrorInfo )
{
	std::string sTmp = std::string(message);
	std::wstring wTmp = std::wstring(sTmp.begin(), sTmp.end());
	PrintErrorDebug(error, wTmp.c_str(), includeSystemErrorInfo);
}

const std::map<RSH_STATUS, std::wstring> RshError::populateMap(RSH_LANGUAGE language)
{
	std::map<RSH_STATUS, std::wstring> errorMap;
	if (language == RSH_LANGUAGE_ENGLISH)
	{
		for (size_t i = 0; i < RSH_DIM(RshErrorList); ++i)
		{
			errorMap[RshErrorList[i].ecode] = RshErrorList[i].en;			
		}
	}
	else if (language == RSH_LANGUAGE_RUSSIAN)
	{
		for (size_t i = 0; i < RSH_DIM(RshErrorList); ++i)
		{
			errorMap[RshErrorList[i].ecode] = RshErrorList[i].ru;
		}
	}

	return errorMap;
}

U32 RshError::convertWStringToStirng(const std::wstring& src, std::string& dst)
{
	dst = "";	

#if defined(RSH_MSWINDOWS)
	U32 maxLength = src.length() + 1; //+1 for ending '0' character
	char* buf = new char [maxLength];
    int err = WideCharToMultiByte(CP_ACP, 0, src.c_str(), -1, buf, maxLength, NULL, NULL);
		
	if(err == 0)
	{
		delete[] buf;
		return RSH_API_FUNCTION_ERRORHAPPEND |GetLastError();
	}	
	dst = std::string(buf);
	delete[] buf;

#elif defined(RSH_LINUX)	
	dst = std::string(src.begin(),src.end());  
#endif

	return RSH_API_SUCCESS;
}

#endif //RSHERROR_CPP
