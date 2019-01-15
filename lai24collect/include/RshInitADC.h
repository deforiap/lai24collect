/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitADC.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitADC initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitADC.
 *
 */
 
#ifndef RSH_INIT_ADC_H
#define RSH_INIT_ADC_H
 
#include "RshBaseType.h"
#include "RshChannel.h"

#include <ostream>

#pragma pack(push, 8)
/*!
 *
 * \~english
 * \brief
 * Base initialization structure for ADC devices
 *
 * This structure contains parameters,
 * common for all ADC devices.\n
 * It is never used in real device libraries,
 * just as parent for RshInitDMA and
 * RshInitMemory structures.
 *
 * \see
 * RshInitDMA | RshInitMemory
 *
 * \~russian
 * \brief
 * Базовая структура инициализации для АЦП устройств
 *
 * В этой структуре содержатся параметры инициализации,
 * общие для всех АЦП устройств, такие как размер буфера,
 * частота дискретизации и др. \n
 * Данная структура сама по себе не используется ни
 * в одной из библиотек абстракции устройств - только
 * в качестве предка для структур RshInitDMA и RshInitMemory.
 *
 * \see
 * RshInitDMA | RshInitMemory
 *
 */
struct RshInitADC : public RshBaseType
{
	/*!
	 *
	 * \~english
	 * \brief
	 * Data acquisition start mode
	 *
	 * One of RshInitADC::StartType enum
	 * constants, that determine, how
	 * ADC will be started.
	 *
	 * \~russian
	 * \brief
	 * Режим запуска сбора данных
	 *
	 * Одна из констант перечисления
	 * RshInitADC::StartType, которая определяет,
	 * как будет запускаться сбор данных.
	 *
	 */
	U32 startType;

	/*!
	 *
	 * \~english
	 * \brief
	 * Buffer size in samples
	 *
	 * Size of buffer need to acquire, in samples
	 * per channel.
	 *
	 * \remarks
	 * When using more than one channel in data
	 * acquisition, be sure to set correct size
	 * for IRshDevice::GetData() method. It will be
	 * equal to RshInitADC::bufferSize*N,
	 * where N is used channels number.
	 *
	 * \see
	 * IRshDevice::GetData()
	 *
	 * \~russian
	 * \brief
	 * Размер буфера в отсчетах
	 *
	 * Размер буфера данных, в отсчетах на канал.
	 *
	 * \remarks
	 * Размер задается на канал, т.е. при использовании
	 * нескольких каналов фактический размер собранных
	 * данных будет пропорционален числу каналов.\n
	 * Это надо учитывать при вызове метода IRshDevice::GetData().
	 * Если число используемых каналов равно N,
	 * при получении данных в метод IRshDevice::GetData()
	 * нужно передать размер, равный RshInitADC::bufferSize*N.
	 *
	 * \see
	 * IRshDevice::GetData()
	 *
	 */
	U32 bufferSize;

	/*!
	 *
	 * \~english
	 * \brief
	 * Sampling rate in Hz
	 *
	 * Sampling rate in Hz per channel.
	 * As for RshInitADC::bufferSize, this
	 * setting is always bound to channel.
	 *
	 * \remarks
	 * For devices that use multiplexor, maximum
	 * frequency depends on number of channels used.\n
	 * Always check sampling and size values after
	 * IRshDevice::Init() call to be sure which
	 * values are actually set.
	 *
	 * \see
	 * RSH_CAPS_DEVICE_SYNCHRO_CHANNELS | RSH_INIT_MODE_CHECK
	 *
	 * \~russian
	 * \brief
	 * Частота дискретизации в Гц
	 *
	 * Частота дискретизации в Гц на канал.
	 * Также как и размер RshInitADC::bufferSize,
	 * эта настройка привязывается к каналу.
	 *
	 * \remarks
	 * Для устройств с мультиплексированными каналами,
	 * максимальная частота дискретизации зависит
	 * от числа используемых каналов.\n
	 * Всегда проверяйте поле частоты дискретизации и
	 * размера буфера в стркутуре после вызова
	 * метода IRshDevice::Init() чтобы узнать,
	 * какие параметры были фактически установлены
	 * при инициализации.
	 *
	 * \see
	 * RSH_CAPS_DEVICE_SYNCHRO_CHANNELS | RSH_INIT_MODE_CHECK
	 *
	 */
	double frequency;

	/*!
	 *
	 * \~english
	 * \brief
	 * Analog channels settings
	 *
	 * List of RshChannel structures.
	 * Number of channels is set to  ::RSH_MAX_CHANNEL_NUMBER.
	 * If device have less than that value (for most devices
	 * its true), channels past actual device number of channels
	 * are ignored.
	 *
	 * \remarks
	 * You can get device channel number using
	 * IRshDevice::Get() method with ::RSH_GET_DEVICE_NUMBER_CHANNELS
	 * parameter.
	 *
	 * \see
	 * RshChannel
	 *
	 * \~russian
	 * \brief
	 * Настройки аналоговых каналов
	 *
	 * Список структур RshChannel.
	 * Количество структур в списке равно ::RSH_MAX_CHANNEL_NUMBER.
	 * Если устройство имеет меньшее число каналов (это справедливо
	 * для большинства устройств), используется только часть
	 * списка, отвечающая фактическому количеству каналов.
	 *
	 * \remarks
	 * Узнать количество каналов устройства можно, вызвав
	 * метод IRshDevice::Get() с параметром ::RSH_GET_DEVICE_NUMBER_CHANNELS.
	 *
	 * \see
	 * RshChannel
	 *
	 */
	RSH_BUFFER_CHANNEL channels;

	/*!
	 *
	 * \~english
	 * \brief
	 * Start mode list
	 *
	 * This enum entities can be used
	 * to specify how to start ADC process.\n
	 * To do so, set one of them as value
	 * for RshInitADC::startType field.
	 *
	 * \see
	 * \link page_Synchronization Synchronization \endlink
	 *
	 * \~russian
	 * \brief
	 * Список режимов запуска
	 *
	 * Элементы этого перечисления используются
	 * для задания режима запуска АЦП.\n
	 * Чтобы выбрать режим, нужно установить
	 * одно из этих значений в поле RshInitADC::startType.
	 *
	 * \see
	 * \link page_Synchronization Синхронизация \endlink
	 *
	 */
	enum  StartType
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Program start
		 *
		 * Conversation will start as soon as
		 * command will be acquired by the device.\n
		 * That means, ADC will start as soon as
		 * IRshDevice::Start() method is called.
		 *
		 * \remarks
		 * "As soon" is not immediately, because
		 * there is always some delays for functions calls,
		 * data transfer and device responce.
		 *
		 * \~russian
		 * \brief
		 * Программный запуск
		 *
		 * Преобразование будет запущено сразу же
		 * после получения устройством команды на запуск.\n
		 * Это означает, что АЦП будет запущено сразу же после
		 * вызова метода IRshDevice::Start().
		 *
		 * \remarks
		 * "Сразу же" на самом деле происходит не мгновенно, так
		 * как всегда есть задержки - вызов функций, передача
		 * данных по шине, отклик устройства.
		 *
		 */
		Program = 0x1,

		/*!
		 *
		 * \~english
		 * \brief
		 * Timer start
		 *
		 * Start data acquisition process
		 * using internal timer.
		 *
		 * \deprecated
		 * This flag is not used in any library at the moment.
		 * In SDK1 some devices used Program mode, some Timer mode
		 * for the same thing. May be this flag will be removed in
		 * the future.
		 *
		 * \~russian
		 * \brief
		 * Запуск по таймеру
		 *
		 * Запуск преобразования по внутреннему таймеру.
		 *
		 * \deprecated
		 * На текущий момент данный режим не используется ни в одной
		 * библиотеке абстракции устройства. В SDK1 некоторые устройства
		 * использовали флаг Program, другие Timer для одного и того же
		 * режима - запуск преобразования по вызову команды IRshDevice::Start().\n
		 * Возможно, данный флаг будет удален в будущих релизах.
		 *
		 */
		Timer = 0x2,

		/*!
		 *
		 * \~english
		 * \brief
		 * Start data acquisition on external trigger
		 *
		 * Use external trigger input as source for
		 * data acquisition start command.
		 *
		 * \remarks
		 * There are two different mechanisms that can
		 * be activated by this flag: using external
		 * trigger input (see ::RSH_CAPS_DEVICE_SYNCHRO_EXTERNAL)
		 * or external start input (see ::RSH_CAPS_DEVICE_EXTERNAL_START).
		 *
		 * \~russian
		 * \brief
		 * Внешняя синхронизации (или внешний запуск)
		 *
		 * Использовать внешний источник
		 * для запуска преобразования.\n
		 * В качестве внешнего источнка может выступать либо
		 * вход внешней синхронизации, либо вход внешнего запуска.
		 *
		 * \remarks
		 * Существуют два различных механизма, которые включаются
		 * данным флагом: использование входа внешней синхронизации
		 * (как правило, данный режим есть у "Memory" устройств -
		 * см. ::RSH_CAPS_DEVICE_SYNCHRO_EXTERNAL) или использование
		 * внешнего старта (как правило, данный режим есть у "DMA"
		 * устройств - см. ::RSH_CAPS_DEVICE_EXTERNAL_START).
		 *
		 */
		External = 0x4,

		/*!
		 *
		 * \~english
		 * \brief
		 * Internal synchronization
		 *
		 * Use analog input channels as source
		 * for trigger to start ADC.
		 *
		 * \remarks
		 * One can check if device supports this mode
		 * using ::RSH_CAPS_DEVICE_SYNCHRO_INTERNAL.\n
		 * Usually, this feature is used by "Memory" devices.
		 *
		 * \see
		 * RshChannel::Synchro | RshInitMemory::threshold
		 *
		 * \~russian
		 * \brief
		 * Внутренняя синхронизация
		 *
		 * Использование одного из аналоговых входов
		 * в качестве источника сигнала для запуска АЦП.
		 *
		 * \remarks
		 * Используйте ::RSH_CAPS_DEVICE_SYNCHRO_INTERNAL
		 * чтобы проверить, поддерживает ли устройство
		 * данный режим или нет.\n
		 * Как правило, данная возможность поддерживается
		 * устройствами типа "Memory".
		 *
		 * \see
		 * RshChannel::Synchro | RshInitMemory::threshold
		 *
		 */
		Internal = 0x8,

		/*!
		 *
		 * \~english
		 * \brief
		 * Use external frequency source for sampling
		 *
		 * External frequency will be used for
		 * sampling ADC. See ::RSH_CAPS_DEVICE_EXTERNAL_FREQUENCY
		 * for more details.
		 *
		 * \~russian
		 * \brief
		 * Использование внешней частоты дискретизации
		 *
		 * АЦП будет сэмплироваться от внешнего источника частоты
		 * дискретизации. См. ::RSH_CAPS_DEVICE_EXTERNAL_FREQUENCY
		 *
		 * \todo
		 * Напрашивается перенос данного поля в control, возможно нужно
		 * объединить контролы из RshInitMemory и RshInitDMA и перенести
		 * все флаги в RshInitADC
		 */
		FrequencyExternal = 0x10,

		/*!
		 *
		 * \~english
		 * \brief
		 * Use master device as start trigger source
		 *
		 * This flag may be used in systems where
		 * two or more devieces are started synchronously
		 * from one source. One device usually is master
		 * device, and all other are slave devices.
		 *
		 * \see
		 * RSH_CAPS_DEVICE_SLAVE_MASTER_SWITCH
		 *
		 * \~russian
		 * \brief
		 * Запуск от ведущего устройства
		 *
		 * Актуально для систем, где несколько устройств
		 * запускаются синхронно. Одно из устройств
		 * выступает в качестве ведущего, все остальные -
		 * в качестве ведомых.
		 *
		 * \see
		 * RSH_CAPS_DEVICE_SLAVE_MASTER_SWITCH
		 *
		 */
		Master = 0x20
	};

	/*!
	 *
	 * \~english
	 * \brief
	 * Synchronization threshold
	 *
	 * Trigger threshold in volts.
	 * This parameter is actual, when device
	 * working in synchronization mode
	 * (RshInitDMA::startType is set to
	 * RshInitDMA::Internal or RshInitDMA::External).\n
	 * When sygnal will bypass threshold, synchronization event
	 * will be triggered, and device start acquire and transfer data.
	 *
	 * \remarks
	 * When synchronization is turned off, this
	 * field is ignored.
	 *
	 * \see
	 * \link page_Synchronization Synchronization \endlink
	 *
	 * \~russian
	 * \brief
	 * Уровень синхронизации
	 *
	 * Уровень синхронизации в вольтах.
	 * Данный параметр актуален, когда устройство
	 * работает в режиме синхронизации (т.е. тип запуска
	 * RshInitDMA::startType установлен либо RshInitDMA::Internal,
	 * либо RshInitMemory::External).\n
	 * Когда сигнал на выбранном для синхронизации входе достигает
	 * заданного порога (сверху или снизу, в зависимости от состояния
	 * поля RshInitDMA::controlSynchro), происходит событие
	 * синхронизации, и начинается процесс сбора и передача данных.
	 *
	 * \remarks
	 * Если синхронизация выключана, данное поле не используется
	 *
	 * \see
	 * \link page_Synchronization Синхронизация \endlink
	 *
	 */
	double threshold;

	/*!
	 *
	 * \~english
	 * \brief
	 * Additional synchonization options
	 *
	 * Combination of flags from
	 * RshInitDMA::ControlSynchro enum.\n
	 * By default this parameter is equal to zero,
	 * which corresponds to following flag combination:
	 * RshInitDMA::FrequencySwitchOff | RshInitDMA::SlopeFront
	 *
	 * \~russian
	 * \brief
	 * Дополнительные параметры синхронизации
	 *
	 * Комбинация флагов из перечисления
	 * RshInitDMA::ControlSynchro.\n
	 * По умолчанию, данный параметр равен нулю,
	 * что соответствует сочетанию флагов:
	 * RshInitDMA::FrequencySwitchOff | RshInitDMA::SlopeFront
	 *
	 */
    U32 controlSynchro;

	/*!
	 *
	 * \~english
	 * \brief
	 * List of additional synchronization flags
	 *
	 * Use flags combined by 'OR' statement
	 * to specify additional options in
	 * RshInitDMA::controlSynchro field.
	 *
	 * \~russian
	 * \brief
	 * Список дополнительных опций сбора данных
	 *
	 * Флаги из этого списка можно объединять
	 * по 'ИЛИ'. Установив нужную комбинацию
	 * флагов в поле RshInitDMA::controlSynchro,
	 * можно задействовать дополнительные опции.
	 *
	 */
	enum ControlSynchro
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Sampling rates for history and prehistory are equal
		 *
		 * Default option, work for all devices.
		 * SDK1 analog is ADC_CONTROL_ESW constant.
		 *
		 * \see
		 * RSH_CAPS_DEVICE_FREQUENCY_SWITCH_PREHISTORY
		 *
		 * \~russian
		 * \brief
		 * Предыстория и история собираются с одной частотой дискретизации
		 *
		 * Данный флаг ставится по умолчанию, и работает
		 * для всех устройств.\n
		 * Аналог в SDK1 - константа ADC_CONTROL_ESW.
		 *
		 * \see
		 * RSH_CAPS_DEVICE_FREQUENCY_SWITCH_PREHISTORY
		 *
		 */
		FrequencySwitchOff = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Use signal front for synchronization
		 *
		 * This field is only actual when
		 * synchonization mode is active
		 * (see RshInitDMA::startType).\n
		 * Mutually exclusive with RshInitDMA::SlopeDecline.
		 *
		 * \~russian
		 * \brief
		 * Синхронизация по фронту
		 *
		 * Данный флаг актуален только при работе
		 * в режиме синхронизации (см.  RshInitDMA::startType).\n
		 * Взаимоисключающий с флагом RshInitDMA::SlopeDecline.
		 *
		 */
		SlopeFront = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Use signal decline for synchronization
		 *
		 * This field is only actual when
		 * synchonization mode is active
		 * (see RshInitDMA::startType).\n
		 * Mutually exclusive with RshInitDMA::SlopeFront.
		 *
		 * \~russian
		 * \brief
		 * Синхронизация по спаду
		 *
		 * Данный флаг актуален только при работе
		 * в режиме синхронизации (см.  RshInitDMA::startType).\n
		 * Взаимоисключающий с флагом RshInitDMA::SlopeFront.
		 *
		 */
		SlopeDecline = 0x2,

		/*!
		 *
		 * \~english
		 * \brief
		 * Sampling rates for history and prehistory are different (switch to low frequency).
		 *
		 * This flag can be used only for devices that
		 * support this feature ( ::RSH_CAPS_DEVICE_FREQUENCY_SWITCH_PREHISTORY).
		 * When flag is active, sampling rate is changed to low frequency
		 * (F = Fmax/8) when synchronization event occures. As a result, prehistory and
		 * main data will have different sampling rate.\n
		 * 
		 * SDK1 analog is ADC_CONTROL_FSW constant.
		 *
		 * \~russian
		 * \brief
		 * Предыстория и история собираются с разными частотами (переключение на низкую частоту)
		 *
		 * Данный флаг может использоваться только для устройств,
		 * которые поддерживают данную возможность
		 * ( ::RSH_CAPS_DEVICE_FREQUENCY_SWITCH_PREHISTORY).
		 * Если флаг активен, частота дискретизации будет изменена
		 * (на низкую частоту, F = Fmax/8, см. документацию к устройству).
		 * в момент срабатывания синхронизации, и предыстория будет
		 * оцифрована с одной частотой, а основной сигнал - с другой.\n
		 * Аналог в SDK1 - константа ADC_CONTROL_FSW.
		 *
		 */
		FrequencySwitchToMinimum = 0x4,

		/*!
		 *
		 * \~english
		 * \brief
		 * Sampling rates for history and prehistory are different (switch to high frequency).
		 *
		 * This flag can be used only for devices that
		 * support this feature ( ::RSH_CAPS_DEVICE_FREQUENCY_SWITCH_PREHISTORY).
		 * When flag is active, sampling rate is changed to high frequency when
		 * synchronization event occures. As a result, prehistory and
		 * main data will have different sampling rate.\n
		 *
		 * \~russian
		 * \brief
		 * Предыстория и история собираются с разными частотами (переключение на высокую частоту)
		 *
		 * Данный флаг может использоваться только для устройств,
		 * которые поддерживают данную возможность
		 * ( ::RSH_CAPS_DEVICE_FREQUENCY_SWITCH_PREHISTORY).
		 * Если флаг активен, частота дискретизации будет изменена
		 * (на высокую частоту, см. документацию к устройству).
		 * в момент срабатывания синхронизации, и предыстория будет
		 * оцифрована с одной частотой, а основной сигнал - с другой.\n		 
		 *
		 */
		FrequencySwitchToMaximum = 0x8
	};

	RshInitADC(const RshDataTypes type = rshInitADC, const size_t sizeType = sizeof(RshInitADC));
	
	RshInitADC(RshInitADC const& obj);

	RshInitADC& operator=(const RshInitADC& obj);


	bool operator==(RshInitADC& obj) const;

	bool operator!=(RshInitADC& obj) const ;

	friend std::ostream& operator<< (std::ostream &out, const RshInitADC& obj) ;
	
	/*!
	 * 
	 * \~english
	 * \brief
	 * Number of selected channels.
	 * 
	 * \returns
	 * Number of channels that have RshChannel::Used flag active
	 * 
	 * This method is useful to determine how many channels are 
	 * selected in initialization structure.
	 * 
	 * \~russian
	 * \brief
	 * Число активных каналов в массиве каналов.
	 * 
	 * \returns
	 * Количество активных каналов.
	 * 
	 * Данный метод позволяет получить число каналов с
	 * установленным флагом RshChannel::Used.
	 * 
	 * 
	 */
	U32 ActiveChannelsNumber() const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitADC::SlopeFront flag
	 *
	 * Set synchronization mode using signal front
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitADC::SlopeFront
	 *
	 * Синхронизация по фронту
	 *
	 */
	void SetSynchroSlopeFront();

	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitADC::SlopeDecline flag
	 *
	 * Set synchronization mode using signal decline
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitADC::SlopeDecline
	 *
	 * Синхронизация по спаду
	 *
	 */
	void SetSynchroSlopeDecline();


	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitADC::SlopeFront flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitADC::SlopeFront
	 *
	 */	
	bool IsSynchroSlopeFrontActive() const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitADC::SlopeDecline flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitADC::SlopeDecline
	 *
	 */	
	bool IsSynchroSlopeDeclineActive() const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitADC::FrequencySwitchOff flag
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitADC::FrequencySwitchOff
	 *
	 */
	void SetSynchroFreqSwitchOff();

	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitADC::FrequencySwitchToMinimum flag
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitADC::FrequencySwitchToMinimum
	 *
	 */
	void SetSynchroFreqSwitchToMin();

	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitADC::FrequencySwitchToMaximum flag
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitADC::FrequencySwitchToMaximum
	 *
	 */
	void SetSynchroFreqSwitchToMax();


	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitADC::FrequencySwitchToMinimum flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitADC::FrequencySwitchToMinimum
	 *
	 */	
	bool IsSynchroFreqSwitchToMinActive() const;


	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitADC::FrequencySwitchToMaximum flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitADC::FrequencySwitchToMaximum
	 *
	 */	
	bool IsSynchroFreqSwitchToMaxActive() const;
};

#pragma pack(pop)
#endif //RSH_INIT_ADC_H