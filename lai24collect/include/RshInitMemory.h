/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitMemory.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitMemory initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitMemory.
 *
 */
 
#ifndef RSH_INIT_MEMORY_H
#define RSH_INIT_MEMORY_H

#include "RshInitADC.h"
#include "RshSynchroChannel.h"

#include <ostream>

struct RshInitDMA;

#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * Initialization structure for Memory-type devices
 *
 * This structure usually is used for high-frequency
 * devices. One can use
 * ::RSH_CAPS_SOFT_INIT_MEMORY to find if
 * device abstraction library supports this structure
 * or not.\n
 * Memory-type device features:\n
 * high-frequency, have onboard memory, extended
 * synchronization possibilities.
 *
 * \remarks
 * Memory name is used for historical reasons - this
 * structure is successor to SDK1
 * sturctures ADCInitParametersMemory, ADCInitParametersMemory1
 *
 * \~russian
 * \brief
 * Структура инициализации для устройств типа "Memory"
 *
 * Обычно, данная структура используется для высокочастотных
 * устройств. Узнать, поддерживается
 * ли эта структура библиотекой абстракции устройства можно,
 * используя капс ::RSH_CAPS_SOFT_INIT_MEMORY.\n
 * Характерные особенности устройств типа "Memory":\n
 * высокая частота дискретизации, наличие собственной памяти,
 * расширенные возможности синхронизации.
 *
 * \remarks
 * Название "Memory" у структуры осталось
 * по историческим причинам - данная структура выступает
 * наследником таких структур из SDK1,
 * как ADCInitParametersMemory и ADCInitParametersMemory1
 *
 */
struct RshInitMemory : public RshInitADC
{
	/*!
	 *
	 * \~english
	 * \brief
	 * External synchronization channel settings
	 *
	 * Using this field one can specify
	 * parameters for external synchronization
	 * input.
	 *
	 * \remarks
	 * Use ::RSH_CAPS_DEVICE_SYNCHRO_EXTERNAL to
	 * check if device have programmable external
	 * synchronization input.
	 *
	 * \see
	 * RshSynchroChannel
	 *
	 * \~russian
	 * \brief
	 * Параметры входа внешней синхронизации
	 *
	 * Используя данное поле, можно задать
	 * необходимые параметры (коэффициент усиления,
	 * сопротвление входа и др.) для входа внешней
	 * синхронизации.
	 *
	 * \remarks
	 * Используйте капс ::RSH_CAPS_DEVICE_SYNCHRO_EXTERNAL
	 * чтобы проверить, есть ли возможность использовать
	 * программно настраиваемый вход внешней синхронизации.
	 *
	 * \see
	 * RshSynchroChannel
	 *
	 */
	RshSynchroChannel channelSynchro;

	/*!
	 *
	 * \~english
	 * \brief
	 * Additional options
	 *
	 * Combination of flags from
	 * RshInitMemory::Control enum.
	 *
	 * \~russian
	 * \brief
	 * Дополнительные опции
	 *
	 * Комбинация флагов перечисления
	 * RshInitMemory::Control.
	 *
	 */
	U32 control;

	/*!
	 *
	 * \~english
	 * \brief
	 * Prehistory size
	 *
	 * This field specify which part of
	 * data buffer will be used to save prehistory
	 * data. Valid values range from 0 (no prehistory)
	 * to 15 (15/16 of the buffer is prehistory data).\n
	 * See \link page_SynchronizationPrehistory this page \endlink
	 * for more details.
	 *
	 * \remarks
	 * Corresponding caps code is ::RSH_CAPS_DEVICE_PREHISTORY
	 *
	 * \~russian
	 * \brief
	 * Размер предыстории
	 *
	 * Данный параметр определяет, какая часть буфера данных
	 * будет использована для записи предыстории измерений.
	 * Диапазон допустимых значений - от 0 (предыстория не записывается)
	 * до 15 (15/16 буфера будет отдано под данные предыстории).\n
	 * Дополнительные подробности можно найти
	 * в \link page_SynchronizationPrehistory статье о синхронизации \endlink.
	 *
	 * \remarks
	 * Соответствующий капс-код: ::RSH_CAPS_DEVICE_PREHISTORY
	 *
	 */
	U32 preHistory;

	/*!
	 *
	 * \~english
	 * \brief
	 * Start delay
	 *
	 * Using this field one can specify
	 * start delay value for synchronization.
	 * See \link page_SynchronizationStartDelay this page \endlink for more details.
	 *
	 * \remarks
	 * Corresponding caps code: ::RSH_CAPS_DEVICE_START_DELAY
	 *
	 * \~russian
	 * \brief
	 * Задержка старта
	 *
	 * В этом поле можно задать значение
	 * задержки старта для синхронизации.
	 * Подробности можно найти на
	 * \link page_SynchronizationStartDelay странице с описанием синхронизации \endlink.
	 *
	 * \remarks
	 * Соответствующий капс-код: ::RSH_CAPS_DEVICE_START_DELAY
	 *
	 * \todo
	 * Провести ревизию устройств, у которых есть данная возможность,
	 * выбрать, в каком виде будет задаваться параметр.
	 *
	 */
	U32	startDelay;

	/*!
	 *
	 * \~english
	 * \brief
	 * Hysteresis
	 *
	 * This field is used to specify
	 * hysteresis value. Hysteresis must be
	 * in range from 0 to 20.
	 * See \link page_SynchronizationHysteresis this page \endlink for more details.
	 *
	 * \remarks
	 * Corresponding caps code: ::RSH_CAPS_DEVICE_HYSTERESIS
	 *
	 * \~russian
	 * \brief
	 * Гистерезис
	 *
	 * В данном поле можно задать уровень гистерезиса.
	 * Диапазон допустимых значений - от 0 до 20.
	 * Подробности можно найти на
	 * \link page_SynchronizationHysteresis странице с описанием синхронизации \endlink.
	 *
	 * \remarks
	 * Соответствующий капс-код: ::RSH_CAPS_DEVICE_HYSTERESIS
	 *
	 */
	U32	hysteresis;

	/*!
	 *
	 * \~english
	 * \brief
	 * Packet number
	 *
	 * This field is actual only for devices
	 * that support packet data acquisition mode
	 * (See ::RSH_CAPS_DEVICE_PACKET_MODE).\n
	 * Using this field, one can specify, how
	 * many packets of RshInitMemory::bufferSize
	 * will be acquired in one cycle.
	 *
	 * \remarks
	 * If device do not support packet acquisition,
	 * this field is ignored.
	 *
	 * \~russian
	 * \brief
	 * Количество пакетов
	 *
	 * Данная опция актуальна только для устройств,
	 * которые поддерживают пакетный режим сбора данных
	 * (см. ::RSH_CAPS_DEVICE_PACKET_MODE).\n
	 * Используя данное поле, можно задать, сколько
	 * пакетов данных размера RshInitMemory::bufferSize
	 * нужно собрать за один цикл сбора данных.
	 *
	 * \remarks
	 * Если устройство не может работать в пакетном режиме,
	 * данный параметр игнорируется.
	 *
	 */
	U32 packetNumber;	

	/*!
	 *
	 * \~english
	 * \brief
	 * List of additional flags
	 *
	 * Use this flags
	 * to specify additional options in
	 * RshInitMemory::control field.
	 *
	 * \~russian
	 * \brief
	 * Список дополнительных опций сбора данных
	 *
	 * Флаги из этого списка можно использовать
	 * в поле RshInitMemory::control, чтобы
	 * задействовать дополнительные опции сбора данных.
	 *
	 */
	enum Control
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Normal mode
		 *
		 * Double and quadro frequency modes are not used.
		 * This flag is default and can be used for all
		 * devices.\n
		 * Mutually exclusive with RshInitMemory::FreqDouble
		 * and RshInitMemory::FreqQuadro
		 *
		 * \see
		 * RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE | RSH_CAPS_DEVICE_QUADRO_FREQUENCY_MODE
		 *
		 * \~russian
		 * \brief
		 * Обычный режим
		 *
		 * Удвоение и учетверение частоты не используется.
		 * Данный режим используется по умолчанию и подходит
		 * для всех устройств.\n
		 * Взаимоисключающий с флагами RshInitMemory::FreqDouble и RshInitMemory::FreqQuadro
		 *
		 * \see
		 * RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE | RSH_CAPS_DEVICE_QUADRO_FREQUENCY_MODE
		 *
		 */
		FreqSingle = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Auto start off
		 *
		 * Automatic start is turned off. This is default value.
		 * This flag is actual only for devices which
		 * support ::RSH_CAPS_DEVICE_AUTO_START_MODE mode.
		 *
		 *
		 * \see
		 * RSH_CAPS_DEVICE_AUTO_START_MODE | RSH_GET_DEVICE_AUTO_START_INTERVAL_SET
		 *
		 * \~russian
		 * \brief
		 * Автозапуск выключен
		 *
		 * Автоматический запуск сбора данных выключен. Данный
		 * флаг актуален только для устройств с поддержкой
		 * режима ::RSH_CAPS_DEVICE_AUTO_START_MODE.
		 *
		 * \see
		 * RSH_CAPS_DEVICE_AUTO_START_MODE | RSH_GET_DEVICE_AUTO_START_INTERVAL_SET
		 *
		 */
		AutoStartOff = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Double sampling rate
		 *
		 * When this flag is active, device will work in double
		 * frequency mode.
		 * This flag can be set only for devices that support
		 * this feature (::RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE).
		 * Mutually exclusive with RshInitMemory::FreqSingle
		 * and RshInitMemory::FreqQuadro
		 *
		 * \see
		 * RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE
		 *
		 * \~russian
		 * \brief
		 * Удвоение частоты
		 *
		 * Если данный флаг активен, устройство будет работать
		 * в режиме удвоения частоты дискретизации.
		 * Этот флаг можно включить только для устройств, которые
		 * поддерживают данный режим работы (::RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE).
		 * Взаимоисключающий с флагами RshInitMemory::FreqSingle и RshInitMemory::FreqQuadro
		 *
		 * \see
		 * RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE
		 *
		 */
		FreqDouble	= 0x1,

		/*!
		 *
		 * \~english
		 * \brief
		 * Quadro sampling rate
		 *
		 * When this flag is active, device will work in quadro
		 * frequency mode.
		 * This flag can be set only for devices that support
		 * this feature (::RSH_CAPS_DEVICE_QUADRO_FREQUENCY_MODE).
		 * Mutually exclusive with RshInitMemory::FreqSingle
		 * and RshInitMemory::FreqDouble
		 *
		 * \see
		 * RSH_CAPS_DEVICE_QUADRO_FREQUENCY_MODE
		 *
		 * \~russian
		 * \brief
		 * Учетверение частоты
		 *
		 * Если данный флаг активен, устройство будет работать
		 * в режиме учетверения частоты дискретизации.
		 * Этот флаг можно включить только для устройств, которые
		 * поддерживают данный режим работы (::RSH_CAPS_DEVICE_QUADRO_FREQUENCY_MODE).
		 * Взаимоисключающий с флагами RshInitMemory::FreqSingle и RshInitMemory::FreqDouble
		 *
		 * \see
		 * RSH_CAPS_DEVICE_QUADRO_FREQUENCY_MODE
		 *
		 */
		FreqQuadro	= 0x2,

		/*!
		 *
		 * \~english
		 * \brief
		 * Auto start on
		 *
		 * Automatic start is turned on.
		 * This flag is actual only for devices which
		 * support ::RSH_CAPS_DEVICE_AUTO_START_MODE mode.\n
		 * When this mode is active, device hardware will start
		 * data acquisition process automatically, using current
		 * settings. One can call IRshDevice::Start() method
		 * only once, and the just obtain data until end (need
		 * to call IRshDevice::Stop() to terminate process).
		 *
		 *
		 * \see
		 * RSH_CAPS_DEVICE_AUTO_START_MODE | RSH_GET_DEVICE_AUTO_START_INTERVAL_SET
		 *
		 * \~russian
		 * \brief
		 * Автозапуск включен
		 *
		 * Автоматический запуск сбора данных выключен. Данный
		 * флаг актуален только для устройств с поддержкой
		 * режима ::RSH_CAPS_DEVICE_AUTO_START_MODE.\n
		 * Когда данный режим включен, устройство будет циклически
		 * запускать процесс сбора и передачи данных с заданным интервалом,
		 * используя текущие настройки сбора. Нужно вызвать метод
		 * IRshDevice::Start() только один раз для запуска процесса, и затем
		 * просто получать данные до тех пор, пока это необходимо
		 * (вызов метода IRshDevice::Stop() останавливает процесс).
		 *
		 * \see
		 * RSH_CAPS_DEVICE_AUTO_START_MODE | RSH_GET_DEVICE_AUTO_START_INTERVAL_SET
		 *
		 */
		AutoStartOn = 0x4,
	};

	RshInitMemory();

    RshInitMemory(RshInitADC const& obj);

	RshInitMemory(RshInitMemory const& obj);

	RshInitMemory& operator=(const RshInitMemory& obj);
	RshInitMemory& operator=(const RshInitDMA& obj);

	bool operator==(RshInitMemory& obj) const;

	bool operator!=(RshInitMemory& obj) const;

	friend std::ostream& operator<< (std::ostream &out, const RshInitMemory& obj);

	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshInitMemory::AutoStartOn flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие RshInitMemory::AutoStartOn
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 *
	 */
	void SetAutoStartOn(bool on = true);

	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitMemory::AutoStartOn flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitMemory::AutoStartOn
	 *
	 */	
	bool IsAutoStartOn() const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitMemory::FreqSingle flag
	 *
	 * Set "normal" frequency mode (not using double/quadro frequency)
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitMemory::FreqSingle
	 *
	 * Задает режим работы "обычный", без удвоения/учетверения частоты
	 *
	 */
	void SetFreqModeSingle();

	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitMemory::FreqDouble flag
	 *
	 * Set double frequency mode active
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitMemory::FreqDouble
	 *
	 * Задает режим работы с удвоением частоты дискретизации
	 *
	 */
	void SetFreqModeDouble();

	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitMemory::FreqQuadro flag
	 *
	 * Set double frequency mode active
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitMemory::FreqQuadro
	 *
	 * Задает режим работы с учетверением частоты дискретизации
	 *
	 */
	void SetFreqModeQuadro();


	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitMemory::FreqSingle flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitMemory::FreqSingle
	 *
	 */	
	bool IsSingleFreqModeActive() const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitMemory::FreqDouble flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitMemory::FreqDouble
	 *
	 */	
	bool IsDoubleFreqModeActive() const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitMemory::FreqQuadro flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitMemory::FreqQuadro
	 *
	 */	
	bool IsQuadroFreqModeActive() const;

};

#pragma pack(pop)
#endif //RSH_INIT_MEMORY_H
