/*!
 * \copyright JSC "Rudnev-Shilyaev"
 * 
 * \file RshCapsDescription.h
 * \date 23.12.2015
 * \version 1.0 [SDK 2.1]
 * 
 * \~english
 * \brief
 *  Simple structure to hold CAPS related data.
 * 
 * \~russian
 * \brief
 * Простая структура для хранения описаний капс-кодов
 * 
 */

#ifndef RSH_CAPS_DESCRIPTION_H
#define RSH_CAPS_DESCRIPTION_H

#include "RshMacro.h"
#include "RshFunctions.h"
#include "RshConsts_CapsCodes.h"


/*!
 * 
 * \~english
 * \brief
 * CAPS codes info.
 * 
 * Simple structure to hold CAPS related data.
 * 
 * \see
 * RSH_CAPS
 * 
 * \~russian
 * \brief
 * Описание CAPS кодов
 * 
 * Простая структура для хранения описаний капс-кодов
 * 
 * \see
 * RSH_STATUS
 * 
 */
#pragma pack(push, 8)

struct RshCapsDescription {
	/*!
	 * 
	 * \~english
	 * \brief
	 * Caps code.
	 * 
	 * One of the ::RSH_CAPS enum constants.
	 * 
	 * \~russian
	 * \brief
	 * Код ошибки.
	 *
	 * Одна из констант перечисления ::RSH_CAPS
	 * 
	 */
    U32 capsCode;

	/*!
	 * 
	 * \~english
	 * \brief
	 * Caps constant name.
	 * 
	 * \~russian
	 * \brief
	 * Название константы.
	 *
	 */
    std::wstring CapsName;
	
	/*!
	 * 
	 * \~english
	 * \brief
	 * Caps info string in russian.
	 * 
	 * \~russian
	 * \brief
	 * Строка с описанием ошибки на русском.
	 *
	 */
	std::wstring ru;

	/*!
	 * 
	 * \~english
	 * \brief
	 * Caps info string in english.
	 * 
	 * \~russian
	 * \brief
	 * Строка с описанием ошибки на английском.
	 *
	 */
	std::wstring en;
};



RshCapsDescription RshCapsInfoList[] = {
//<BeginCapsDescription>
{RSH_CAPS_DEVICE_PCI,
rshUTF16("RSH_CAPS_DEVICE_PCI"),
rshUTF16("Устройство с интерфейсом PCI."),
rshUTF16("Device has PCI interface.")},

{RSH_CAPS_DEVICE_PCI_EXPRESS,
rshUTF16("RSH_CAPS_DEVICE_PCI_EXPRESS"),
rshUTF16("Устройство с интерфейсом PCI Express."),
rshUTF16("Device has PCI Express interface.")},

{RSH_CAPS_DEVICE_USB1_1,
rshUTF16("RSH_CAPS_DEVICE_USB1_1"),
rshUTF16("Устройство с интерфейсом USB 1.1."),
rshUTF16("Device has USB 1.1 interface.")},

{RSH_CAPS_DEVICE_USB2_0,
rshUTF16("RSH_CAPS_DEVICE_USB2_0"),
rshUTF16("Устройство с интерфейсом USB 2.0."),
rshUTF16("Device has USB 2.0 interface.")},

{RSH_CAPS_DEVICE_USB3_0,
rshUTF16("RSH_CAPS_DEVICE_USB3_0"),
rshUTF16("Устройство с интерфейсом USB 3.0."),
rshUTF16("Device has USB 3.0 interface.")},

{RSH_CAPS_DEVICE_ETHERNET,
rshUTF16("RSH_CAPS_DEVICE_ETHERNET"),
rshUTF16("Устройство с интерфейсом Ethernet."),
rshUTF16("Device has Ethernet interface.")},

{RSH_CAPS_DEVICE_FREQUENCY_SYNTHESIZER,
rshUTF16("RSH_CAPS_DEVICE_FREQUENCY_SYNTHESIZER"),
rshUTF16("Устройство имеет синтезатор частоты."),
rshUTF16("Device has frequency synthesizer installed.")},

{RSH_CAPS_DEVICE_TIMER_8254,
rshUTF16("RSH_CAPS_DEVICE_TIMER_8254"),
rshUTF16("В устройстве установлен программируемый счетчик-таймер Intel 8254."),
rshUTF16("Device has 3 channel Intel 8254 PIT chip installed.")},

{RSH_CAPS_DEVICE_MEMORY_PER_CHANNEL,
rshUTF16("RSH_CAPS_DEVICE_MEMORY_PER_CHANNEL"),
rshUTF16("Устройство поддерживает возможность задать произвольный размер блока для каждого измерительного канала."),
rshUTF16("Device supports selection of individual block size for each analog channel.")},

{RSH_CAPS_DEVICE_FREQUENCY_LIST,
rshUTF16("RSH_CAPS_DEVICE_FREQUENCY_LIST"),
rshUTF16("Устройство имеет таблицу фиксированных частот квантования."),
rshUTF16("Device has predefined sampling rates list.")},

{RSH_CAPS_DEVICE_SIZE_LIST,
rshUTF16("RSH_CAPS_DEVICE_SIZE_LIST"),
rshUTF16("Устройство имеет таблицу фиксированных размеров."),
rshUTF16("Device has predefined buffer size list.")},

{RSH_CAPS_DEVICE_HAS_DIGITAL_PORT,
rshUTF16("RSH_CAPS_DEVICE_HAS_DIGITAL_PORT"),
rshUTF16("Устройство имеет цифровые линии для ввода (вывода) данных"),
rshUTF16("Device has TTL lines for input (output).")},

{RSH_CAPS_DEVICE_GAIN_LIST,
rshUTF16("RSH_CAPS_DEVICE_GAIN_LIST"),
rshUTF16("Устройство имеет таблицу коэффициентов усиления."),
rshUTF16("Device has predefined list of gain coefficients.")},

{RSH_CAPS_DEVICE_GAINS_PER_CHANNEL,
rshUTF16("RSH_CAPS_DEVICE_GAINS_PER_CHANNEL"),
rshUTF16("Поддерживается установка коэффициента усиления индивидуально для каждого канала."),
rshUTF16("Gain coefficients can be set separately for each analog channel.")},

{RSH_CAPS_DEVICE_PREHISTORY,
rshUTF16("RSH_CAPS_DEVICE_PREHISTORY"),
rshUTF16("Доступна возможность записи предыстории измерения."),
rshUTF16("Prehistory data writing is availible.")},

{RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE,
rshUTF16("RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE"),
rshUTF16("Устройство поддерживает режим сбора данных с удвоенной частотой дискретизации."),
rshUTF16("Device supports double frequency data acquisition mode.")},

{RSH_CAPS_DEVICE_QUADRO_FREQUENCY_MODE,
rshUTF16("RSH_CAPS_DEVICE_QUADRO_FREQUENCY_MODE"),
rshUTF16("Устройство поддерживает режим режим сбора данных с учетверенной частотой дискретизации."),
rshUTF16("Device supports quadro frequency data acquisition mode.")},

{RSH_CAPS_DEVICE_AUTO_CALIBRATION,
rshUTF16("RSH_CAPS_DEVICE_AUTO_CALIBRATION"),
rshUTF16("Устройство поддерживает режим автокалибровки."),
rshUTF16("Device supports autocalibration.")},

{RSH_CAPS_DEVICE_SYNCHRO_INTERNAL,
rshUTF16("RSH_CAPS_DEVICE_SYNCHRO_INTERNAL"),
rshUTF16("Аналоговые каналы устройства могут быть использованы в качестве источника синхронизации."),
rshUTF16("Analog input of the device can be used as trigger source.")},

{RSH_CAPS_DEVICE_SYNCHRO_EXTERNAL,
rshUTF16("RSH_CAPS_DEVICE_SYNCHRO_EXTERNAL"),
rshUTF16("Устройство имеет дополнительный вход, который может быть использован в качестве источника синхронизации."),
rshUTF16("Device has additional input that can be used as trigger source.")},

{RSH_CAPS_DEVICE_EXTERNAL_START,
rshUTF16("RSH_CAPS_DEVICE_EXTERNAL_START"),
rshUTF16("Устройство поддерживает возможность внешнего запуска преобразования."),
rshUTF16("Device has digital trigger.")},

{RSH_CAPS_DEVICE_HYSTERESIS,
rshUTF16("RSH_CAPS_DEVICE_HYSTERESIS"),
rshUTF16("Устройство имеет возможность задания уровня гистерезиса для синхронизации."),
rshUTF16("Device has programmable hysteresis for synchronization.")},

{RSH_CAPS_DEVICE_EXT_SYNC_GAIN_LIST,
rshUTF16("RSH_CAPS_DEVICE_EXT_SYNC_GAIN_LIST"),
rshUTF16("Устройство имеет отдельный список коэффициентов усиления для входа внешней синхронизации."),
rshUTF16("Device have separate gain coefficients list for externl input.")},

{RSH_CAPS_DEVICE_EXT_SYNC_FILTER_LOW,
rshUTF16("RSH_CAPS_DEVICE_EXT_SYNC_FILTER_LOW"),
rshUTF16("Фильтр низких частот может быть включен для входа внешней синхронизации."),
rshUTF16("High pass filter can be set on external syncrhonization input.")},

{RSH_CAPS_DEVICE_EXT_SYNC_FILTER_HIGH,
rshUTF16("RSH_CAPS_DEVICE_EXT_SYNC_FILTER_HIGH"),
rshUTF16("Фильтр высоких частот может быть включен для входа внешней синхронизации."),
rshUTF16("Low pass filter can be set on external syncrhonization input.")},

{RSH_CAPS_DEVICE_EXT_SYNC_INPUT_RESIST_50_OHM,
rshUTF16("RSH_CAPS_DEVICE_EXT_SYNC_INPUT_RESIST_50_OHM"),
rshUTF16("Доступен режим входного сопротивления 50Ом для входа внешней синхронизации."),
rshUTF16("External synchronization input of the device has 50 Ohm resist mode.")},

{RSH_CAPS_DEVICE_EXT_SYNC_INPUT_RESIST_1_MOHM,
rshUTF16("RSH_CAPS_DEVICE_EXT_SYNC_INPUT_RESIST_1_MOHM"),
rshUTF16("Доступен режим входного сопротивления 1МОм для входа внешней синхронизации."),
rshUTF16("External synchronization input of the device has 1 MOhm resist mode.")},

{RSH_CAPS_DEVICE_EXT_SYNC_COUPLING_AC_DC,
rshUTF16("RSH_CAPS_DEVICE_EXT_SYNC_COUPLING_AC_DC"),
rshUTF16("Доступна возможность переключения состояния входа внешней синхронизации \"Открытый\"/\"Закрытый\"."),
rshUTF16("AC/DC coupling of the external synchronization input can be changed.")},

{RSH_CAPS_DEVICE_HAS_DAC_INSTALLED,
rshUTF16("RSH_CAPS_DEVICE_HAS_DAC_INSTALLED"),
rshUTF16("Устройство имеет один или несколько ЦАПов."),
rshUTF16("Device have one or more DAC modules installed.")},

{RSH_CAPS_DEVICE_INPUT_LEVEL_ADJUSTMENT,
rshUTF16("RSH_CAPS_DEVICE_INPUT_LEVEL_ADJUSTMENT"),
rshUTF16("Устройство имеет возможность подстройки уровня входного напряжения аналоговых каналов."),
rshUTF16("Device's analog channels have programmable hardware input level adjustment.")},

{RSH_CAPS_DEVICE_INPUT_COUPLING_AC_DC,
rshUTF16("RSH_CAPS_DEVICE_INPUT_COUPLING_AC_DC"),
rshUTF16("Доступна возможность переключения состояния аналоговых входов \"открытый/закрытый\"."),
rshUTF16("AC/DC coupling of the analog inputs can be changed.")},

{RSH_CAPS_DEVICE_INPUT_RESIST_50_OHM,
rshUTF16("RSH_CAPS_DEVICE_INPUT_RESIST_50_OHM"),
rshUTF16("Доступен режим входного сопротивления 50Ом для аналоговых каналов."),
rshUTF16("Analog input channels of the device has 50 Ohm resist mode.")},

{RSH_CAPS_DEVICE_INPUT_RESIST_1_MOHM,
rshUTF16("RSH_CAPS_DEVICE_INPUT_RESIST_1_MOHM"),
rshUTF16("Доступен режим входного сопротивления 1МОм для аналоговых каналов."),
rshUTF16("Analog input channels of the device has 1 MOhm resist mode.")},

{RSH_CAPS_DEVICE_FRAME_FREQUENCY_MODE,
rshUTF16("RSH_CAPS_DEVICE_FRAME_FREQUENCY_MODE"),
rshUTF16("Устройство поддерживает режим кадрового сбора."),
rshUTF16("Device supports frame frequency mode.")},

{RSH_CAPS_DEVICE_PACKET_MODE,
rshUTF16("RSH_CAPS_DEVICE_PACKET_MODE"),
rshUTF16("Устройство поддерживает пакетный режим сбора данных."),
rshUTF16("Device supports packet mode of data acquisition.")},

{RSH_CAPS_DEVICE_START_DELAY,
rshUTF16("RSH_CAPS_DEVICE_START_DELAY"),
rshUTF16("Сбор данных может быть начат с задержкой (относительно события синхронизации)"),
rshUTF16("Data acquisition process can be delayed (from trigger event).")},

{RSH_CAPS_DEVICE_SLAVE_MASTER_SWITCH,
rshUTF16("RSH_CAPS_DEVICE_SLAVE_MASTER_SWITCH"),
rshUTF16("Сбор данных может быть запущен от ведущего устройства."),
rshUTF16("Data acquisition can be started from master device.")},

{RSH_CAPS_DEVICE_SYNCHRO_CHANNELS,
rshUTF16("RSH_CAPS_DEVICE_SYNCHRO_CHANNELS"),
rshUTF16("Аналоговые каналы устройства - синхронные."),
rshUTF16("Device's channels are synchronous.")},

{RSH_CAPS_DEVICE_EXTERNAL_FREQUENCY,
rshUTF16("RSH_CAPS_DEVICE_EXTERNAL_FREQUENCY"),
rshUTF16("АЦП может тактироваться из внешнего источника."),
rshUTF16("ADC can be sampled by external signal source.")},

{RSH_CAPS_DEVICE_FREQUENCY_SWITCH_PREHISTORY,
rshUTF16("RSH_CAPS_DEVICE_FREQUENCY_SWITCH_PREHISTORY"),
rshUTF16("Доступна возможность переключения частоты дискретизации после получения события синхронизации."),
rshUTF16("Sampling rate can be changed after trigger event.")},

{RSH_CAPS_DEVICE_FREE_CHANNEL_SELECT_IN_EXT_MODE,
rshUTF16("RSH_CAPS_DEVICE_FREE_CHANNEL_SELECT_IN_EXT_MODE"),
rshUTF16("Можно выбрать канал (каналы), который будут использоваться в режиме удвоения (учетверения) частоты."),
rshUTF16("One can select what channel (channels) will be used in double (quadro) frequency mode.")},

{RSH_CAPS_DEVICE_DIFFERENTIAL_INPUT_MODE,
rshUTF16("RSH_CAPS_DEVICE_DIFFERENTIAL_INPUT_MODE"),
rshUTF16("Доступна возможность программно переключаться между однополюсным/дифференциальным режимом."),
rshUTF16("Device can be programmably configure to acquire data in unipolar/ bipolar mode.")},

{RSH_CAPS_DEVICE_FLASH_INFO_ONBOARD,
rshUTF16("RSH_CAPS_DEVICE_FLASH_INFO_ONBOARD"),
rshUTF16("Устройство имеет энергонезависимую память (флэш), которая содержит дополнительную информацию."),
rshUTF16("There is a flash memory unit onboard for device information.")},

{RSH_CAPS_DEVICE_GPS_MODULE_INSTALLED,
rshUTF16("RSH_CAPS_DEVICE_GPS_MODULE_INSTALLED"),
rshUTF16("Устройство имеет GPS-модуль"),
rshUTF16("Device have GPS module")},

{RSH_CAPS_DEVICE_AUTO_START_MODE,
rshUTF16("RSH_CAPS_DEVICE_AUTO_START_MODE"),
rshUTF16("Устройство поддерживает режим автоматического запуска"),
rshUTF16("Device supports automatic restart")},

{RSH_CAPS_DEVICE_DIGITAL_PORT_DATA_WITH_ANALOG_DATA,
rshUTF16("RSH_CAPS_DEVICE_DIGITAL_PORT_DATA_WITH_ANALOG_DATA"),
rshUTF16("Цифровые данные могут передаваться вместе с аналоговыми."),
rshUTF16("Digital line data can be contained within analog data.")},

{RSH_CAPS_SOFT_CALIBRATION_IS_AVAILABLE,
rshUTF16("RSH_CAPS_SOFT_CALIBRATION_IS_AVAILABLE"),
rshUTF16("Библиотека абстракции содержит методы для проведения автоматической настройки и калибровки устройства."),
rshUTF16("Abstraction library contains methods that allow automatic calibration perform.")},

{RSH_CAPS_SOFT_GATHERING_IS_AVAILABLE,
rshUTF16("RSH_CAPS_SOFT_GATHERING_IS_AVAILABLE"),
rshUTF16("Библиотека абстракции содержит методы для осуществления сбора данных в режиме \"старт-стоп\"."),
rshUTF16("Abstraction library contains methods that allow data acquisition in \"start-stop\" mode.")},

{RSH_CAPS_SOFT_PGATHERING_IS_AVAILABLE,
rshUTF16("RSH_CAPS_SOFT_PGATHERING_IS_AVAILABLE"),
rshUTF16("Библиотека абстракции содержит методы для осуществления сбора данных в непрерывном режиме"),
rshUTF16("Abstraction library contains methods that allow continious data acquisition.")},

{RSH_CAPS_SOFT_DIGITAL_PORT_IS_AVAILABLE,
rshUTF16("RSH_CAPS_SOFT_DIGITAL_PORT_IS_AVAILABLE"),
rshUTF16("Библиотека абстракции содержит методы для управления цифровым портом."),
rshUTF16("Abstraction library contains methods that allow control of digital port.")},

{RSH_CAPS_SOFT_GENERATION_IS_AVAILABLE,
rshUTF16("RSH_CAPS_SOFT_GENERATION_IS_AVAILABLE"),
rshUTF16("Библиотека абстракции содержит методы для генерации сигнала."),
rshUTF16("Abstraction library contains methods that allow signal generation.")},

{RSH_CAPS_SOFT_INIT_MEMORY,
rshUTF16("RSH_CAPS_SOFT_INIT_MEMORY"),
rshUTF16("Структура инициализации RshInitMemory поддерживается библиотекой абстракции."),
rshUTF16("RshInitMemory initialization structure is supported by abstraction library.")},

{RSH_CAPS_SOFT_INIT_DMA,
rshUTF16("RSH_CAPS_SOFT_INIT_DMA"),
rshUTF16("Структура инициализации RshInitDMA поддерживается библиотекой абстракции."),
rshUTF16("RshInitDMA initialization structure is supported by abstraction library.")},

{RSH_CAPS_SOFT_INIT_GSPF,
rshUTF16("RSH_CAPS_SOFT_INIT_GSPF"),
rshUTF16("Структура инициализации RshInitGSPF поддерживается библиотекой абстракции."),
rshUTF16("RshInitGSPF initialization structure is supported by abstraction library.")},

{RSH_CAPS_SOFT_INIT_VOLTMETER,
rshUTF16("RSH_CAPS_SOFT_INIT_VOLTMETER"),
rshUTF16("Структура инициализации RshInitVoltmeter поддерживается библиотекой абстракции."),
rshUTF16("RshInitVoltmeter initialization structure is supported by abstraction library.")},

{RSH_CAPS_SOFT_INIT_TIMER,
rshUTF16("RSH_CAPS_SOFT_INIT_TIMER"),
rshUTF16("Структура инициализации RshInitTimer поддерживается библиотекой абстракции."),
rshUTF16("RshInitTimer initialization structure is supported by abstraction library.")},

{RSH_CAPS_SOFT_STROBOSCOPE,
rshUTF16("RSH_CAPS_SOFT_STROBOSCOPE"),
rshUTF16("Библиотека абстракции содержит методы для реализация программного стробоскопа."),
rshUTF16("Abstraction library contains methods that allow use of software stoboscope.")},

{RSH_CAPS_SOFT_INIT_DAC,
rshUTF16("RSH_CAPS_SOFT_INIT_DAC"),
rshUTF16("Структура инициализации RshInitDAC поддерживается библиотекой абстракции."),
rshUTF16("RshInitDAC initialization structure is supported by abstraction library.")},

{RSH_CAPS_SOFT_INIT_PORT,
rshUTF16("RSH_CAPS_SOFT_INIT_PORT"),
rshUTF16("Структура инициализации RshInitPort поддерживается библиотекой абстракции."),
rshUTF16("RshInitPort initialization structure is supported by abstraction library.")},

{RSH_CAPS_SOFT_TUNER_MODE_IS_AVAILABLE,
rshUTF16("RSH_CAPS_SOFT_TUNER_MODE_IS_AVAILABLE"),
rshUTF16("Внутренние настройки устройства могут быть изменены с использованием данной библиотеки абстракции."),
rshUTF16("Internal device parameters can be tuned using this abstraction library.")},

{RSH_CAPS_MAX,
rshUTF16("RSH_CAPS_MAX"),
rshUTF16("Максимальное количество значений в перечислении RSH_CAPS."),
rshUTF16("Maximum number of values in RSH_CAPS enum.")},


  //</BeginCapsDescription>
};
#pragma pack(pop)



#endif //RSH_CAPS_DESCRIPTION_H
