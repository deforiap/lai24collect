/*!
 * \copyright JSC "Rudnev-Shilyaev"
 * 
 * \file RshError.h
 * \date 22.12.2015
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

#ifndef RSH_ERROR_H
#define RSH_ERROR_H

#include "RshDefChk.h"
#include "RshConsts_Language.h"
#include "RshConsts_StatusCodes.h"

#include <map>

/*!
 * 
 * \~english
 * \brief
 * Convinient methods to get error messages.
 * 
 * Using this class one can form error message 
 * on Rsh Api error codes (::RSH_STATUS) and also
 * system error codes. 
 * 
 * \~russian
 * \brief
 * Набор методов для формирования сообщений об ошибках.
 * 
 * Используя данный класс можно получить
 * сообщения об ошибках на основе кодов Rsh Api (::RSH_STATUS),
 * а также системных кодах ошибок.
 * 
 */
class RshError {

public:

	/*!
	 * 
	 * \~english
	 * \brief
	 * Get system error message in UTF-16 format.
	 * 
	 * \param [in] error
	 * System error code.\n
	 * You can pass \b errno (for Linux) or GetLastError() (for Windows).
	 *
	 * \param [in,out] str
	 * Pointer to buffer where error description will be placed
	 *
	 * \param [in] maxLength
	 * Maximum length of error message (be sure that you allocated enough
	 * memory in \b str buffer).
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS or error code
	 * 
	 * Windows (or Linux) system call performed to get detailed
	 * error description. Result of this call is placed in UTF-16 format.
	 * 
	 * \remarks
	 * \b error parameter is masked with 0xFFFF, so you can pass codes returned by 
	 * different Rsh Api functions.	
	 *
	 * \see
	 * \link RshError_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Получение описания по системному коду ошибки в формате UTF-16.
	 * 
	 * \param [in] error
	 * Системный код ошибки.\n
	 * Можно передать  \b errno (для Linux) или GetLastError() (для Windows)
	 *
	 * \param [in,out] str
	 * Указатель на буфер (строку), в который будет помещено описание ошибки
	 *
	 * \param [in] maxLength
	 * Максимальная длина сообщения об ошибке (фактически, размер выделенной
	 * памяти для буфера \b str).
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки
	 * 
	 * Для формирования сообщения по коду ошибки используется вызов
	 * системной функции (зависит от операционной системы). Результат
	 * этого вызова возвращается в формате UTF-16.
	 * 
	 * \remarks
	 * Параметр \b error маскируется с 0xFFFF, поэтому можно передавать
	 * в этот метод коды ошибок, возвращаемые различными функциями Rsh Api.
	 *
	 * \see
	 * \link RshError_RU.cpp Пример использования \endlink
	 * 
	 */
    static U32 GetSystemErrorDescription(U32 error, wchar_t* str, U32 maxLength);


	/*!
	 * 
	 * \~english
	 * \brief
	 * Get system error message.
	 * 
	 * \param [in] error
	 * System error code.\n
	 * You can pass \b errno (for Linux) or GetLastError() (for Windows).
	 *
	 * \param [in,out] str
	 * Pointer to buffer where error description will be placed
	 *
	 * \param [in] maxLength
	 * Maximum length of error message (be sure that you allocated enough
	 * memory in \b str buffer).
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS or error code
	 * 
	 * Windows (or Linux) system call performed to get detailed
	 * error description. Result of this call is placed in ANSI format.
	 * 
	 * \remarks
	 * \b error parameter is masked with 0xFFFF, so you can pass codes returned by 
	 * different Rsh Api functions.	
	 *
	 * \see
	 * \link RshError_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Получение описания по системному коду ошибки.
	 * 
	 * \param [in] error
	 * Системный код ошибки.\n
	 * Можно передать  \b errno (для Linux) или GetLastError() (для Windows)
	 *
	 * \param [in,out] str
	 * Указатель на буфер (строку), в который будет помещено описание ошибки
	 *
	 * \param [in] maxLength
	 * Максимальная длина сообщения об ошибке (фактически, размер выделенной
	 * памяти для буфера \b str).
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки
	 * 
	 * Для формирования сообщения по коду ошибки используется вызов
	 * системной функции (зависит от операционной системы). Результат
	 * этого вызова возвращается в формате ANSI.
	 * 
	 * \remarks
	 * Параметр \b error маскируется с 0xFFFF, поэтому можно передавать
	 * в этот метод коды ошибок, возвращаемые различными функциями Rsh Api.
	 *
	 * \see
	 * \link RshError_RU.cpp Пример использования \endlink
	 *
	 * \todo Linux версия данного метода, возможно, имеет проблемы с кодировкой (проверить)
	 * 
	 */
    static U32 GetSystemErrorDescription(U32 error, char* str, U32 maxLength);

	static U32 GetSystemErrorDescription(U32 error, std::string& str);
	static U32 GetSystemErrorDescription(U32 error, std::wstring& str);

	/*!
	 * 
	 * \~english
	 * \brief
	 * Get Rsh Api error message in UTF-16 format.
	 * 
	 * \param [in] error
	 * Rsh Api error code.
	 *
	 * \param [in,out] str
	 * Pointer to buffer where error description will be placed
	 *
	 * \param [in] maxLength
	 * Maximum length of error message (be sure that you allocated enough
	 * memory in \b str buffer).
	 * 
	 * \param [in] language
	 * One of the ::RSH_LANGUAGE constants.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS or error code
	 * 
	 * Using this method one can get detailed error description.	
	 * 
	 * \remarks
	 * \b error parameter is masked with 0xFFFF0000, so you can pass codes returned by 
	 * different Rsh Api functions.
	 * 
	 * \see
	 * RSH_STATUS | \link RshError_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Получение сообщения об ошибке по коду из Rsh Api в формате UTF-16.
	 * 
	 * \param [in] error
	 * Код ошибки.
	 *
	 * \param [in,out] str
	 * Указатель на буфер (строку), в который будет помещено описание ошибки
	 *
	 * \param [in] maxLength
	 * Максимальная длина сообщения об ошибке (фактически, размер выделенной
	 * памяти для буфера \b str).
	 * 
	 * \param [in] language
	 * Одна из констант списка ::RSH_LANGUAGE.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки
	 * 
	 * Используя данный метод можно получить детальное описание ошибки по ее коду.	
	 * 
	 * \remarks
	 * Параметр \b error маскируется с 0xFFFF0000, поэтому можно передавать
	 * в этот метод коды ошибок, возвращаемые различными функциями Rsh Api.
	 * 
	 * \see
	 * RSH_STATUS | \link RshError_RU.cpp Пример использования \endlink
	 * 
	 */
    static U32 GetErrorDescription(U32 error, wchar_t* str, U32 maxLength, RSH_LANGUAGE language = RSH_LANGUAGE_ENGLISH);

	/*!
	 * 
	 * \~english
	 * \brief
	 * Get Rsh Api error message.
	 * 
	 * \param [in] error
	 * Rsh Api error code.
	 *
	 * \param [in,out] str
	 * Pointer to buffer where error description will be placed
	 *
	 * \param [in] maxLength
	 * Maximum length of error message (be sure that you allocated enough
	 * memory in \b str buffer).
	 * 
	 * \param [in] language
	 * One of the ::RSH_LANGUAGE constants.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS or error code
	 * 
	 * Using this method one can get detailed error description.	
	 * 
	 * \remarks
	 * \b error parameter is masked with 0xFFFF0000, so you can pass codes returned by 
	 * different Rsh Api functions.
	 * 
	 * \see
	 * RSH_STATUS | \link RshError_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Получение сообщения об ошибке по коду из Rsh Api.
	 * 
	 * \param [in] error
	 * Код ошибки.
	 *
	 * \param [in,out] str
	 * Указатель на буфер (строку), в который будет помещено описание ошибки
	 *
	 * \param [in] maxLength
	 * Максимальная длина сообщения об ошибке (фактически, размер выделенной
	 * памяти для буфера \b str).
	 * 
	 * \param [in] language
	 * Одна из констант списка ::RSH_LANGUAGE.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки
	 * 
	 * Используя данный метод можно получить детальное описание ошибки по ее коду.	
	 * 
	 * \remarks
	 * Параметр \b error маскируется с 0xFFFF0000, поэтому можно передавать
	 * в этот метод коды ошибок, возвращаемые различными функциями Rsh Api.
	 * 
	 * \see
	 * RSH_STATUS | \link RshError_RU.cpp Пример использования \endlink
	 *
	 * \todo Linux версия данного метода, возможно, имеет проблемы с кодировкой (проверить)
	 * 
	 */
    static U32 GetErrorDescription(U32 error, char* str, U32 maxLength, RSH_LANGUAGE language = RSH_LANGUAGE_ENGLISH);

	static U32 GetErrorDescription(U32 error, std::wstring& str, RSH_LANGUAGE language = RSH_LANGUAGE_ENGLISH);

	static U32 GetErrorDescription(U32 error, std::string& str,  RSH_LANGUAGE language = RSH_LANGUAGE_ENGLISH);

	/*!
	 * 
	 * \~english
	 * \brief
	 * Print error description.
	 * 
	 * \param [in] error
	 * Error code obtained via Rsh Api calls.
	 * 
	 * \param [in] language
	 * One of the ::RSH_LANGUAGE constants.
	 * 
	 * \param [in] includeSystemErrorInfo
	 * If true, system error code information will
	 * be printed too.\n
	 * For this flag to work \b error parameter must
	 * contain system error code in low word
	 * (error & 0xFFFF != 0).
	 * 
	 * This method is used to print detailed error messge
	 * to the standart output.	
	 * 
	 * \remarks
	 * System error messages sometimes can't be translated
	 * and be printed in system default language ignoring
	 * \b language parameter.
	 * 
	 * 
	 * \see
	 * \link RshError_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Печать описания ошибки.
	 * 
	 * \param [in] error
	 * Код ошибки, полученный в результате вызова функций из Rsh Api.
	 * 
	 * \param [in] language
	 * Одна из констант списка ::RSH_LANGUAGE.
	 * 
	 * \param [in] includeSystemErrorInfo
	 * Если данный флаг установлен (true), дополнительно будет
	 * напечатана информация о системном коде ошибки.\n
	 * Чтобы данный флаг сработал, в младшем слове
	 * параметра \b error должен содержаться системный код ошибки
	 *(error & 0xFFFF != 0).
	 * 
	 * Данный метод используется для вывода детального сообщения об
	 * ошибке в стандартный поток вывода.
	 * 
	 * \remarks
	 * Системные сообщения об ошибках иногда не могут быть переведены
	 * на язык, отличный от дефолтного в системе. В этом случае 
	 * параметр \b language будет проигнорирован.
	 * 
	 * \see
	 * \link RshError_RU.cpp Пример использования \endlink
	 * 
	 */
    static void PrintError(U32 error, RSH_LANGUAGE language = RSH_LANGUAGE_ENGLISH, bool includeSystemErrorInfo = false);

	/*!
	 * 
	 * \~english
	 * \brief
	 * Print debug message.
	 * 
	 * \param [in] error
	 * Error code obtained via Rsh Api calls.
	 * 
	 * \param [in] message
	 * Additional message to print with error description.
	 * 
	 * \param [in] includeSystemErrorInfo
	 * If true, system error code information will
	 * be printed too.\n
	 * For this flag to work \b error parameter must
	 * contain system error code in low word
	 * (error & 0xFFFF != 0).
	 * 
	 * This method is analog of PrintError(), except two thing:
	 * \li Default language (English) is always used
	 * \li One can pass additional string to print with error description.
	 * 
	 * \see
	 * \link RshError_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Печать отладочного сообщения.
	 * 
	 * \param [in] error
	 * Код ошибки, полученный в результате вызова функций из Rsh Api.
	 * 
	 * \param [in] message
	 * Описание параметра message.
	 * 
	 * \param [in] includeSystemErrorInfo
	 * Если данный флаг установлен (true), дополнительно будет
	 * напечатана информация о системном коде ошибки.\n
	 * Чтобы данный флаг сработал, в младшем слове
	 * параметра \b error должен содержаться системный код ошибки
	 *(error & 0xFFFF != 0).
	 * 
	 * Данный метод является аналогом метода PrintError(), со следующими
	 * отличиями:
	 * \li При выводе сообщений всегда используется английский язык.
	 * \li Можно передать дополнительную строку, которая будет напечатана
	 * вместе с описанием ошибки.	 
	 * 
	 * \see
	 * \link RshError_RU.cpp Пример использования \endlink
	 * 
	 */
    static void PrintErrorDebug(U32 error, const wchar_t* message, bool includeSystemErrorInfo = false);
	static void PrintErrorDebug(U32 error, const char* message, bool includeSystemErrorInfo = false);
	
private:
	//russian error messages
	static const std::map<RSH_STATUS, std::wstring> m_errorsRu;
	//english error messages
	static const std::map<RSH_STATUS, std::wstring> m_errorsEn;

	//helper method to populate const maps
	static const std::map<RSH_STATUS, std::wstring> populateMap(RSH_LANGUAGE language);

	//helper method to convert std::wstring in std::string (platform specific to support cyrillic)
	static U32 convertWStringToStirng(const std::wstring& src, std::string& dst);
};



#endif //RSH_ERROR_H
