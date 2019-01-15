/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshTime.h
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

#ifndef RSH_TIME_H
#define RSH_TIME_H

#include "RshDefChk.h"

#include <ostream>
#include <string>

#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * Time store structure.
 *
 * Maximum value that can be stored
 * in structure is
 * 23h 59m 59s 999ms 999us
 *
 * \~russian
 * \brief
 * Структура с данными о времени.
 *
 * Максимальное значение, которое может храниться в структуре:
 * 23ч 59м 59с 999мс 999мкс
 *
 */
class RshTime
{

	friend std::ostream& operator<< (std::ostream &out, const RshTime& obj);

public:

	RshTime();

	RshTime(U8 hours, U8 minutes, U8 seconds = 0, U16 milliseconds = 0, U16 microseconds = 0);

	RshTime(const RshTime& obj);

	RshTime& operator=(const RshTime& obj);

	bool operator==(const RshTime& obj) const;
	bool operator<(const RshTime& obj) const;

	bool operator!=(const RshTime& obj) const;

	bool operator>(const RshTime& obj) const;
	bool operator<=(const RshTime& obj) const;
	bool operator>=(const RshTime& obj) const;

	/*!
	* \~english
	* \brief
	* Convert elapsed time
	*
	* Convert elapsed time in seconds (floating point) to
	* hours, minutes, seconds, milliseconds and microseconds elapsed.
	*
	* \param [in] timeElapsed_s Time in seconds
	*
	* \remarks
	* If timeElapsed_s is bigger or equal to 86400.0, time will be set
	* to 23h 59m 59s 999ms 999us
	*
	* \~russian
	* \brief
	* Преобразование интервала времени
	*
	* Преобразование времени (в секундах, число с плавающей точкой) в
	* полное представление - часы, минуты, секунды, миллисекунды и микросекунды.
	*
	* \param [in] timeElapsed_s Время в секундах
	*
	* \remarks
	* Если время timeElapsed_s больше либо равно 86400.0 (сутки), будет установлено
	* значение 23ч 59м 59с 999мс 999мкс.
	*
	*/
	RshTime(double timeElapsed_s);

	/*!
	 *
	 * \~english
	 * \brief
	 * Fill structure with current time information
	 *
	 * This method fills the RshTime structure
	 * with current time values.
	 *
	 * \returns
	 * Filled RshTime structure.
	 *
	 * \~russian
	 * \brief
	 * Текущее время
	 *
	 * Данный метод заполняет структуру
	 * RshTime - поля структуры получают значения,
	 * соответствующие системному времени.
	 *
	 * \returns
	 * Заполненная структура RshTime.
	 *
	 */
	static RshTime currentTime();

	/*!
	 *
	 * \~english
	 * \brief
	 * Convert to string
	 *
	 * Convert to std::string, using format constant\n
	 * <b>hh</b> - hours value\n
	 * <b>mm</b> - minutes value\n
	 * <b>ss</b> - seconds value\n
	 * <b>zzz</b> - milliseconds value\n
	 * <b>uuu</b> - microseconds value\n
	 * For example, using "hh.mm" format string one can get something like "13.09"
	 *
	 * \param [in] format
	 * Default value is "hh:mm:ss:zzz.uuu"
	 *
	 *
	 * \~russian
	 * \brief
	 * Преобразование в строку
	 *
	 * Формат задается в виде строки, можно использовать следующие ключевые слова:\n
	 * <b>hh</b> - часы\n
	 * <b>mm</b> - минуты\n
	 * <b>ss</b> - секунды\n
	 * <b>zzz</b> - миллисекунды\n
	 * <b>uuu</b> - микросекунды\n
	 * Например, для формата "hh.mm" будет сформированаа строка вида "13.09"
	 *
	 * \param [in] format
	 * По умолчанию используется формат "hh:mm:ss:zzz.uuu"
	 *
	 */
	std::string toString(const std::string& format=std::string("hh:mm:ss:zzz.uuu")) const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Convert to string
	 *
	 * Convert to std::wstring, using format constant\n
	 * <b>hh</b> - hours value\n
	 * <b>mm</b> - minutes value\n
	 * <b>ss</b> - seconds value\n
	 * <b>zzz</b> - milliseconds value\n
	 * <b>uuu</b> - microseconds value\n
	 * For example, using "hh.mm" format string one can get something like "13.09"
	 *
	 * \param [in] format
	 * Default value is "hh:mm:ss:zzz.uuu"
	 *
	 *
	 * \~russian
	 * \brief
	 * Преобразование в строку
	 *
	 * Формат задается в виде строки, можно использовать следующие ключевые слова:\n
	 * <b>hh</b> - часы\n
	 * <b>mm</b> - минуты\n
	 * <b>ss</b> - секунды\n
	 * <b>zzz</b> - миллисекунды\n
	 * <b>uuu</b> - микросекунды\n
	 * Например, для формата "hh.mm" будет сформированаа строка вида "13.09"
	 *
	 * \param [in] format
	 * По умолчанию используется формат "hh:mm:ss:zzz.uuu"
	 *
	 */
	std::wstring toWString(const std::wstring& format=std::wstring(L"hh:mm:ss:zzz.uuu")) const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Convert to microseconds
	 *
	 * \returns
	 * Current structure time in microseconds
	 *
	 * \~russian
	 * \brief
	 * Преобразование в микросекунды
	 *
	 * \returns
	 * Текущее хранящееся в структуре время в микросекундах
	 * Пересчет производится суммированием всех полей структуры.
	 *
	 */
	U64 toMicroSeconds() const;

	/*!
	*
	* \~english
	* \brief
	* Set structure time values
	*
	* \~russian
	* \brief
	* Установить время в структуре
	*
	*/
	void setHMS(U8 hours, U8 minutes, U8 seconds = 0, U16 milliseconds = 0, U16 microseconds = 0);

	/*!
	*
	* \~english
	* \brief
	* Set structure time values
	*
	* \param [in] timeElapsed_s Time in seconds
	*
	* \remarks
	* If timeElapsed_s is bigger or equal to 86400.0, time will be set
	* to 23h 59m 59s 999ms 999us
	*
	* \~russian
	* \brief
	* Установить время в структуре
	*
	* \param [in] timeElapsed_s Время в секундах
	*
	* \remarks
	* Если время timeElapsed_s больше либо равно 86400.0 (сутки), будет установлено
	* значение 23ч 59м 59с 999мс 999мкс.
	*
	*/
	void setFromElapsed(double timeElapsed_s);

	/*!
	*
	* \~english
	* \brief
	* Hours
	*
	* \~russian
	* \brief
	* Часы
	*
	*/
	U8 hours() { return h; }

	/*!
	*
	* \~english
	* \brief
	* Minuts.
	*
	* \~russian
	* \brief
	* Минуты.
	*
	*/
	U8 minutes() { return m; }

	/*!
	*
	* \~english
	* \brief
	* Seconds.
	*
	* \~russian
	* \brief
	* Секунды.
	*
	*/
	U8 seconds() { return s; }

	/*!
	*
	* \~english
	* \brief
	* MilliSeconds.
	*
	* \~russian
	* \brief
	* Миллисекунды.
	*
	*/
	U16 milliSeconds() { return ms; }

	/*!
	*
	* \~english
	* \brief
	* Microseconds.
	*
	* \~russian
	* \brief
	* Микросекунды.
	*
	*/
	U16 microSeconds() { return us; }

private:
	/*!
	*
	* \~english
	* \brief
	* Hours.
	*
	* \~russian
	* \brief
	* Часы.
	*
	*/
	U8 h;

	/*!
	*
	* \~english
	* \brief
	* Minuts.
	*
	* \~russian
	* \brief
	* Минуты.
	*
	*/
	U8 m;

   /*!
	*
	* \~english
	* \brief
	* Seconds.
	*
	* \~russian
	* \brief
	* Секунды.
	*
	*/
	U8 s;

	/*!
	*
	* \~english
	* \brief
	* MilliSeconds.
	*
	* \~russian
	* \brief
	* Миллисекунды.
	*
	*/
	U16 ms;

	/*!
	*
	* \~english
	* \brief
	* Microseconds.
	*
	* \~russian
	* \brief
	* Микросекунды.
	*
	*/
	U16 us;

	//helper method to replace all substrings in string
	static void replaceAll(std::string &s, const std::string &search, const std::string &replace);
	static void replaceAll(std::wstring &s, const std::wstring &search, const std::wstring &replace);

	//helper method to calculate time in microseconds
	void calculateTimeInMicroSeconds() const;

	mutable U64 m_hashedTimeInMicroSeconds;
};

#pragma pack(pop)
#endif //RSH_TIME_H
