/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitVoltmeter.h
 * \date 30.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitVoltmeter initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitVoltmeter.
 *
 */
 
#ifndef RSH_INIT_VOLTMETER_H
#define RSH_INIT_VOLTMETER_H

#include "RshBaseType.h"

#include <ostream>

#pragma pack(push, 8)


/*!
 *
 * \~english
 * \brief
 * Initialization structure for voltmeter V7-78
 *
 * This structure is designed to use with
 * V7-78 USB connection via VISA driver.
 * 
 * \todo Refactoring
 *
 * \~russian
 * \brief
 * Cтруктура инициализации для вольтметров типа B7-78.
 *
 * Вольтметр управляется через USB порт, используется
 * стандартный VISA драйвер для него.
 *
 * \todo Рефакторинг
 *
 */
struct  RshInitVoltmeter : public RshBaseType
{
	/*!
	 *
	 * \~english
	 * \brief
	 * Start type
	 *
	 * Currently there is only one start type available - 
	 * program start.
	 *
	 * \~russian
	 * \brief
	 * Тип запуска
	 * 
	 * В настоящий момент, доступно только одно значение - 
	 * программный запуск.
	 *
	 */
    U32 startType;

	/*!
	 *
	 * \~english
	 * \brief
	 * Buffer size
	 *
	 * Buffer size in counts to fill
	 *
	 * \~russian
	 * \brief
	 * Размер буфера
	 * 
	 * Размер буфера в отсчетах.
	 *
	 */
	U32 bufferSize;

	/*!
	 *
	 * \~english
	 * \brief
	 * Filter
	 *
	 * Filter value
	 *
	 * Uses internal "<b>DET:BAND</b>" command.
	 * possible values are 3, 20, 200(default);
	 *
	 * \~russian
	 * \brief
	 * Фильтр
	 * 
	 * Внутренняя команда:  "<b>DET:BAND</b>"
	 * Допустимые значения: 3, 20, 200 (значение по умолчанию)
	 *
	 */
	U32 filter;	

	/*!
	 *
	 * \~english
	 * \brief
	 * Device work mode
	 *
	 * Set device work mode
	 *
	 * Uses internal "<b>FUNC</b>" command.
	 * Possible work modes are in Control enum;
	 *
	 * \~russian
	 * \brief
	 * Режим работы вольтметра
	 * 
	 * Внутренняя команда:  "<bFUNC</b>"
	 * Допустимые значения собраны в перечислении Control
	 *
	 */
	U32 control;

	/*!
	 *
	 * \~english
	 * \brief
	 * Possible start types
	 *
	 * Only one value for now
	 *
	 * \~russian
	 * \brief
	 * Способы запуска
	 * 
	 * На текущий момент одно допустимое значение, программный запуск.
	 *
	 */
	enum StartType 
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Program start
		 *
		 * \~russian
		 * \brief
		 * Программный запуск
		 *
		 */
		Program	= 0x0, 
	};

	/*!
	 *
	 * \~english
	 * \brief
	 * Work modes
	 *
	 * \~russian
	 * \brief
	 * Режимы работы
	 *
	 */
	enum Control
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Measure DC voltage
		 *
		 * \~russian
		 * \brief
		 * Измерение постоянного напряжения
		 *
		 */
		VoltageDC = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Measure AC voltage
		 *
		 * \~russian
		 * \brief
		 * Измерение переменного напряжения
		 *
		 */
		VoltageAC = 0x1,

		/*!
		 *
		 * \~english
		 * \brief
		 * Measure DC current
		 *
		 * \~russian
		 * \brief
		 * Измерение постоянного тока
		 *
		 */
		CurrentDC = 0x2,

		/*!
		 *
		 * \~english
		 * \brief
		 * Measure AC current
		 *
		 * \~russian
		 * \brief
		 * Измерение переменного тока
		 *
		 */
		CurrentAC = 0x4
	};
    RshInitVoltmeter();

	RshInitVoltmeter(RshInitVoltmeter const& obj);

	RshInitVoltmeter& operator=(const RshInitVoltmeter& obj);

	bool operator==(RshInitVoltmeter& obj) const;

	bool operator!=(RshInitVoltmeter& obj) const;

	friend std::ostream& operator<< (std::ostream &out, const RshInitVoltmeter& obj);
};

#pragma pack(pop)
#endif //RSH_INIT_VOLTMETER_H
