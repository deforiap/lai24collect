/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitPort.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitPort initialization structures.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitPort.
 *
 */
 
#ifndef RSH_INIT_PORT_H
#define RSH_INIT_PORT_H

#include "RshBaseType.h"

#include <ostream>

#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * Digital port operations
 *
 * This structure is used to pass data to
 * and from digital port. Corresponding
 * caps codes are ::RSH_CAPS_DEVICE_HAS_DIGITAL_PORT
 * and ::RSH_CAPS_SOFT_INIT_PORT.
 *
 * \~russian
 * \brief
 * Операции с цифровым портом
 *
 * Данная структура используется для записи
 * и чтения данных из цифрового порта устройства.
 * Соответствующие капс-коды: ::RSH_CAPS_DEVICE_HAS_DIGITAL_PORT
 * и ::RSH_CAPS_SOFT_INIT_PORT.
 *
 */
struct  RshInitPort : public RshBaseType
{
    /*!
	 *
	 * \~english
	 * \brief
	 * Port operation
	 *
	 * Operation defined by code from
	 * RshInitPort::OperationType enum
	 *
	 * \~russian
	 * \brief
	 * Выполняемая операция
	 *
	 * Действие (чтение, запись и т.д.) которое
	 * необходимое выполнить. Список
	 * доступных операций - в перечислении
	 * RshInitPort::OperationType.
	 *
	 */
	U32 operationType;

	/*!
	 *
	 * \~english
	 * \brief
	 * Operation list
	 *
	 * Use codes from this enum to specify
	 * operation, that must be performed.\n
	 * Pass operation code in RshInitPort::operationType
	 * field of the initialization structure.
	 *
	 * \~russian
	 * \brief
	 * Список операций
	 *
	 * Используйте коды операций из данного списка,
	 * чтобы задать действие, которое необходимо
	 * выполнить с цифровыми портом.\n
	 * Код операции нужно записать в поле
	 * RshInitPort::operationType  структуры инициализации.
	 *
	 */
	enum OperationType
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Read data from port
		 *
		 * Read digital port state. Data
		 * acquired will be placed in
		 * RshInitPort::portValue field.
		 * If port have less than 32 lines (usually
		 * it is true), data will be placed in low
		 * part of the variable.
		 *
		 * \~russian
		 * \brief
		 * Чтение данных из цифрового порта
		 *
		 * Чтение состояния цифрового порта. Полученные
		 * данные будут помещены в поле RshInitPort::portValue.
		 * Если разрядность порта меньше 32, используется
		 * младшая часть переменной.\n
		 * Например, если порт имеет 8 линий, данные будут
		 * находиться в младшем байте поля RshInitPort::portValue
		 * после успешного выполнения операции чтения (вызов метода
		 * IRshDevice::Init() ).
		 *
		 */
		Read = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Write to digital port
		 *
		 * Value specified in RshInitPort::portValue
		 * will be written in digital port.
		 *
		 * \~russian
		 * \brief
		 * Запись в цифровой порт
		 *
		 * Значение, указанное в поле RshInitPort::portValue,
		 * будет выведено в цифровой порт.\n
		 * Если количество линий цифрового порта меньше, чем разрядность
		 * RshInitPort::portValue (32 бита), используется младшая часть.
		 *
		 */
		Write = 0x1,

		/*!
		 *
		 * \~english
		 * \brief
		 * Update port state using "AND"
		 *
		 * This operation consists of two parts:\n
		 * First, current value of digital port will
		 * be obtained. After that, obtained value will
		 * be combined using AND bit operation with value
		 * specified in RshInitPort::portValue field.
		 * Resulting value will be written to port.
		 *
		 * \~russian
		 * \brief
		 * Обновить состояние цифрового порта по "И"
		 *
		 * Данная операция состоит из двух частей:\n
		 * Сначала, будет прочитано текущее состояние цифрового порта.
		 * Далее, полученно значение будет объединено по "И"
		 * (логическая побитовая операция) со значением, переданным в поле
		 * RshInitPort::portValue структуры инициализации. Результат
		 * операции будет записан в цифровой порт.
		 *
		 */
		WriteAND = 0x2,

		/*!
		 *
		 * \~english
		 * \brief
		 * Update port state using "OR"
		 *
		 * This operation consists of two parts:\n
		 * First, current value of digital port will
		 * be obtained. After that, obtained value will
		 * be combined using OR bit operation with value
		 * specified in RshInitPort::portValue field.
		 * Resulting value will be written to port.
		 *
		 * \~russian
		 * \brief
		 * Обновить состояние цифрового порта по "ИЛИ"
		 *
		 * Данная операция состоит из двух частей:\n
		 * Сначала, будет прочитано текущее состояние цифрового порта.
		 * Далее, полученно значение будет объединено по "ИЛИ"
		 * (логическая побитовая операция) со значением, переданным в поле
		 * RshInitPort::portValue структуры инициализации. Результат
		 * операции будет записан в цифровой порт.
		 *
		 */
		WriteOR = 0x3
	};

    /*!
	 *
	 * \~english
	 * \brief
	 * Digital port adress
	 *
	 * This field specify adress of the digital port
	 * to use for operation.\n
	 * One can get device port list using
	 * IRshDevice::Get() method.
	 * See description of RshBoardPortInfo for details on
	 * how get list of availiable ports.
	 *
	 * \~russian
	 * \brief
	 * Адрес цифрового порта
	 *
	 * Данное поле определяет адрес порта,
	 * который будет использован для вывполения
	 * операции чтения/записи.\n
	 * Список доступных адресов можно получить,
	 * используя метод IRshDevice::Get().
	 * Смотрите описание структуры RshBoardPortInfo
	 * и примеры.
	 *
	 */
	U32 portAddress;

    /*!
	 *
	 * \~english
	 * \brief
	 * Port value
	 *
	 * Value to write to port or result of reading operation.
	 *
	 * \~russian
	 * \brief
	 * Состояние порта
	 *
	 * Значение, которое нужно записать в порт,
	 * либо результат операции чтения данных.\n
	 * Если разрядность цифрового порта меньше,
	 * чем размер переменной (32 бита), используeтся
	 * младшая часть.\n
	 * Для 8ми битных цифровых портов, например, данные
	 * будут находитсья в младшем байте.
	 *
	 */
	U32 portValue;

    RshInitPort();

	RshInitPort(U32 address, U32 operation = RshInitPort::Read,  U32 value = 0x0);

	RshInitPort(RshInitPort const& obj);

	RshInitPort& operator=(const RshInitPort& obj);

	bool operator==(RshInitPort& obj) const;

	bool operator!=(RshInitPort& obj) const;

	friend std::ostream& operator<< (std::ostream &out, const RshInitPort& obj);
};

#pragma pack(pop)
#endif //RSH_INIT_PORT_H
