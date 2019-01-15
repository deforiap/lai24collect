/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshConsts_GetDataModes.h
 * \date 25.12.2015
 * \version 1.0 [SDK 2.1]
 *
* \~english
 * \brief
 * GetData flags constants for Rsh SDK
 *
 * \~russian
 * \brief
 * Дополнительные флаги метода GetData() для Rsh SDK
 *
 */
 
#ifndef RSH_CONSTS_GETDATA_MODES_H
#define RSH_CONSTS_GETDATA_MODES_H

/*!
 * 
 * \~english
 * \brief
 * Additional data transfer flags for IRshDevice::GetData() method.
 * 
 * Flags from this enum can be combined using OR statement,
 * and are used to control data conversation process.
 * 
 * 
 * \see
 * IRshDevice::GetData()
 * 
 * \~russian
 * \brief
 * Дополнительные флаги преобразования данных для метода IRshDevice::GetData().
 * 
 * Флаги из этого списка можно комбинировать по ИЛИ.
 * Для некоторых устройств, данные флаги позволяются получить
 * (или отправить) дополнительню информацию вместе с данными,
 * или изменить параметры процесса преобразования данных.
 * 
 * \see
 * IRshDevice::GetData()
 * 
 */
typedef enum
{
	/*!
	 * 
	 * \~english
	 * \brief
	 * No additional flags are used.
	 * 
	 * You can omit this flag, because its default value of 
	 * IRshDevice::GetData() \b flags parameter.
	 * 
	 * \~russian
	 * \brief
	 * Дополнительные флаги не используются.
	 * 
	 * Можно не прописывать данный флаг, поскольку он ставится
	 * по умолчанию в качестве параметра \b flags метода IRshDevice::GetData().
	 * 
	 */
	RSH_DATA_MODE_NO_FLAGS = 0x0,

	/*!
	 * 
	 * \~english
	 * \brief
	 * State of digital input lines is transfered within data.
	 * 
	 * Some devices have possibility to write ditial port bits
	 * in data word with analog data input.\n
	 * For example, if we have device with 12 bit ADC, which use
	 * 16 bit bus for data transfer, 4 last sagnificant bits can be
	 * used for 4 digital lines data.\n
	 * 
	 * \remarks
	 * When using floating point buffer (::RSH_BUFFER_DOUBLE) in
	 * IRshDevice::GetData() method, this flag will be ignored,
	 * becuase analog input is converted to volts.
	 *
	 * \see RSH_CAPS_DEVICE_DIGITAL_PORT_DATA_WITH_ANALOG_DATA | \link IRshDevice_GetData_DigitalInput_EN.cpp Use example\endlink
	 * 
	 * \~russian
	 * \brief
	 * Передача состояния входных линий цифрового порта вместе с данными.
	 * 
	 * У некоторых устройств есть возможность записи данных цифровых портов
	 * в слово данных аналоговых каналов. \n
	 * Например, если устройство имеет разрядность 12 бит и использует внутреннюю
	 * шину 16 бит для передачи данных, 4 младших бита могут быть использованы
	 * для записи состояния четырех входных линий цифрового порта.\n	
	 * 
	 * \remarks
	 * При использовании в методе IRshDevice::GetData()  буфера из чисел с плавающей точкой
	 * (::RSH_BUFFER_DOUBLE), данный флаг будет проигнорирован, т.к.
	 * аналоговые данные преобразуются в вольты.	
	 *
	 * \see RSH_CAPS_DEVICE_DIGITAL_PORT_DATA_WITH_ANALOG_DATA | \link IRshDevice_GetData_DigitalInput_RU.cpp Пример использования \endlink 
	 * 
	 */
	RSH_DATA_MODE_CONTAIN_DIGITAL_INPUT = 0x00001,

	/*!
	 * 
	 * \~english
	 * \brief
	 * Output TTL signal on digital lines simulteniously with analog output.
	 * 
	 * Two last sagnificant bits of each data sample sended
	 * to GSPF device using IRshDevice::GetData() method
	 * will be used as state of two ditial TTL lines.\n
	 * Signal on that lines will be changed at the same time
	 * as next sample is converted by DAC. So, time parameters
	 * of generated TTL-signal will depend on used sampling rate
	 * and buffer size.
	 * 
	 * \~russian
	 * \brief
	 * Вывод TTL-совместимого сигнала на цифровые выходы одновременно с выводом аналоговых данных.
	 * 
	 * Два младших бита каждого отсчета (слова) данных, отправленных
	 * на устройство ГСПФ с помощью метода IRshDevice::GetData()
	 * будут использоваться для вывода на две TTL-совместимых цифровых линии.\n
	 * Состояние линий будет обновляться одновременно с выдачей очередного
	 * значения из буфера на ЦАП, т.е. временные характеристики выдаваемого
	 * TTL сигнала будут определяться установленной частотой дискретизации
	 * и размером буфера.
	 *
	 */
	RSH_DATA_MODE_GSPF_TTL = 0x10000

} RSH_DATA_MODES;

#endif //RSH_CONSTS_GETDATA_MODES_H
