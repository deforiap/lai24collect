/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshConsts_CapsCodes.h
 * \date 10.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * CAPS codes constants enum for Rsh SDK
 *
 * \~russian
 * \brief
 * Константы возможностей CAPS для Rsh SDK
 *
 */
 
#ifndef RSH_CONSTS_CAPS_CODES_H
#define RSH_CONSTS_CAPS_CODES_H

  /*!
  * 
  * \~english
  * \brief
  * List of device and software capabilities (features).
  * 
  * You can check what device is capable of using 
  * IRshDevice::Get() method with parameter ::RSH_GET_DEVICE_IS_CAPABLE.\n
  * 
  * \see
  * IRshDevice::Get() | \link IRshDevice_Get_RSH_GET_DEVICE_IS_CAPABLE_EN.cpp Usage example \endlink
  * 
  * \~russian
  * \brief
  * Список возможностей устройства и программного обеспечения
  * 
  * Позволяет узнать, какие возможности поддерживаются устройством
  * и библиотекой абстракции, используя метод IRshDevice::Get()
  * с параметром ::RSH_GET_DEVICE_IS_CAPABLE.\n
  *
  * \see
  * IRshDevice::Get() | \link IRshDevice_Get_RSH_GET_DEVICE_IS_CAPABLE_RU.cpp Пример использования \endlink
  *
  */
 typedef enum
 {	 
	 /*!
	  * \~english
	  * \brief
	  * Device has PCI interface.
	  * \~russian
	  * \brief
	  * Устройство с интерфейсом PCI.
	  */
	 RSH_CAPS_DEVICE_PCI = 0,

	 /*!
	  * \~english
	  * \brief
	  * Device has PCI Express interface.
	  * \~russian
	  * \brief
	  * Устройство с интерфейсом PCI Express.
	  */
	 RSH_CAPS_DEVICE_PCI_EXPRESS = 1,

	 /*!
	  * \~english
	  * \brief
	  * Device has USB 1.1 interface.
	  * \~russian
	  * \brief
	  * Устройство с интерфейсом USB 1.1.
	  */
	 RSH_CAPS_DEVICE_USB1_1 = 2,

	 /*!
	  * \~english
	  * \brief
	  * Device has USB 2.0 interface.
	  * \~russian
	  * \brief
	  * Устройство с интерфейсом USB 2.0.
	  */
	 RSH_CAPS_DEVICE_USB2_0 = 3,

	 /*!
	  * \~english
	  * \brief
	  * Device has USB 3.0 interface.
	  * \~russian
	  * \brief
	  * Устройство с интерфейсом USB 3.0.
	  */
	 RSH_CAPS_DEVICE_USB3_0 = 4,

	 /*!
	  * \~english
	  * \brief
	  * Device has Ethernet interface.
	  * \~russian
	  * \brief
	  * Устройство с интерфейсом Ethernet.
	  */
	 RSH_CAPS_DEVICE_ETHERNET = 5,

	
	 /*!
	  * \~english
	  * \brief
	  * Device has frequency synthesizer installed.
	  *
	  * Frequency synthesizer allows to vary sampling rate smoothly,
	  * opposite to standart devices with frequency divider,
	  * where you have maximum frequency Fmax and dirived frequencies
	  * such as Fmax/2, Fmax/4 etc.
	  *
	  * \remarks
	  * Some devices with frequency synthesizer DO NOT SUPPORT free frequency select
	  * and have a list of the predefined frequencies anyway.
	  * Check it using ::RSH_CAPS_DEVICE_FREQUENCY_LIST.
	  *
	  * \see RSH_CAPS_DEVICE_FREQUENCY_LIST | RSH_GET_DEVICE_FREQUENCY_LIST
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет синтезатор частоты.
	  *
	  * Синтезатор частоты позволяет плавно изменять
	  * частоту дискретизации, в отличие от устройств с делителем
	  * частоты, у которых есть некая максимальная частота дискретизации Fmax
	  * и кратные ей частоты Fmax/2, Fmax/4 и т.д.
	  *
	  * \remarks 
	  * Некоторые устройства с установленным синтезатором частоты НЕ ПОДДЕРЖИВАЮТ
	  * возможность произвольного выбора частоты дискретизации.
	  * Проверить наличие предопределенного списка поддерживаемых частот можно с 
	  * помощью ::RSH_CAPS_DEVICE_FREQUENCY_LIST.
	  *
	  * \see RSH_CAPS_DEVICE_FREQUENCY_LIST | RSH_GET_DEVICE_FREQUENCY_LIST
	  *
	  */
	 RSH_CAPS_DEVICE_FREQUENCY_SYNTHESIZER = 15,

	 /*!
	  * \~english
	  * \brief
	  * Device has 3 channel Intel 8254 PIT chip installed.
	  *
	  * Using RshInitTimer sturcture one can set some tricky
	  * data acquisition mode for device.	 
	  *
	  * \see  RshInitTimer
	  *
	  * \~russian
	  * \brief
	  * В устройстве установлен программируемый счетчик-таймер Intel 8254.
	  *
	  * Используя структуру инициализации RshInitTimer 
	  * можно задать нестандартный режим сбора данных.	
	  *
	  * \see  RshInitTimer
	  */
	 RSH_CAPS_DEVICE_TIMER_8254 = 16,	

	 /*!
	  * \~english
	  * \brief
	  * Device supports selection of individual block size for each analog channel.
	  * \~russian
	  * \brief
	  * Устройство поддерживает возможность задать произвольный размер блока для каждого измерительного канала.
	  */
	 RSH_CAPS_DEVICE_MEMORY_PER_CHANNEL = 17,

	 /*!
	  * \~english
	  * \brief
	  * Device has predefined sampling rates list.
	  *
	  * Frequency list can be obtained using IRshDevice::Get() method
	  * with parameter ::RSH_GET_DEVICE_FREQUENCY_LIST.\n
	  *
	  * \remarks
	  * If device don't have frequency list,
	  * one can obtaind minimum and maximum sampling rates for device
	  * using IRshDevice::Get() method with parameters ::RSH_GET_DEVICE_MIN_FREQUENCY
	  * and ::RSH_GET_DEVICE_MAX_FREQUENCY accordingly.
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет таблицу фиксированных частот квантования.
	  *
	  * Список частот дискретизации может быть получен с помощью метода IRshDevice::Get()
	  * с параметром ::RSH_GET_DEVICE_FREQUENCY_LIST.\n
	  *
	  * \remarks
	  * Если у устройства нет таблицы частот,
	  * можно получить минимальную и максимальную возможные частоты квантования,
	  * используя метод IRshDevice::Get() с параметрами ::RSH_GET_DEVICE_MIN_FREQUENCY
	  * и ::RSH_GET_DEVICE_MAX_FREQUENCY соответственно.
	  *
	  */
	 RSH_CAPS_DEVICE_FREQUENCY_LIST = 18,

	  /*!
	  * \~english
	  * \brief
	  * Device has predefined buffer size list.
	  *
	  * Buffer size list can be obtained using IRshDevice::Get() method
	  * with parameter ::RSH_GET_DEVICE_SIZE_LIST.\n
	  *
	  * \remarks 
	  * All sizes in list are related to single channel, so
	  * if you use 2 channels (for example), you must pass 2 times larger buffer
	  * in IRshDevice::GetData() than size you set in RshInitADC::bufferSize initialization parameter.
	  *
	  * If device don't have size list,
	  * one can obtaind minimum and maximum sample size for device
	  * using IRshDevice::Get() method with parameters ::RSH_GET_DEVICE_MIN_SAMPLES_PER_CHANNEL
	  * and ::RSH_GET_DEVICE_MAX_SAMPLES_PER_CHANNEL accordingly.
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет таблицу фиксированных размеров.
	  *
	  * Список частот дискретизации может быть получен с помощью метода IRshDevice::Get()
	  * с параметром ::RSH_GET_DEVICE_SIZE_LIST.\n
	  *
	  * \remarks
	  * Все размеры в таблице размеров приведены на канал, т.е. если используется
	  * 2 канала (например), в метод IRshDevice::GetData() нужно передать буфер
	  * в два раза большего размера, чем заданное значение параметра инициализации RshInitADC::bufferSize.
	  *
	  * Если у устройства нет таблицы размеров,
	  * можно получить минимальный и максимальный допустимый размер в отсчетах на канал,
	  * используя метод IRshDevice::Get() с параметрами ::RSH_GET_DEVICE_MIN_SAMPLES_PER_CHANNEL
	  * и ::RSH_GET_DEVICE_MAX_SAMPLES_PER_CHANNEL соответственно.
	  *
	  */
	 RSH_CAPS_DEVICE_SIZE_LIST = 19,

	 /*!
	  * \~english
	  * \brief
	  * Device has TTL lines for input (output).
	  *
	  * One can obtain additinal information about digital ports installed
	  * using IRshDevice::Get() with ::RSH_GET_DEVICE_PORT_INFO parameter.
	  * Obtained RshBoardPortInfo structure contains all information
	  * you need to control digital input/output.
	  *
	  * \see
	  * RshBoardPortInfo | RshInitPort
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет цифровые линии для ввода (вывода) данных
	  *
	  * Дополнительную информацию о цифровых портах устройства можно получить,
	  * используя метод IRshDevice::Get() с параметром ::RSH_GET_DEVICE_PORT_INFO.
	  * Полученная  структура RshBoardPortInfo содержит все необходимые данные
	  * для организации управления цифровыми вводом/выводом.
	  *
	  * \see
	  * RshBoardPortInfo | RshInitPort
	  *
	  */
	 RSH_CAPS_DEVICE_HAS_DIGITAL_PORT = 20,

	 /*!
	  * \~english
	  * \brief
	  * Device has predefined list of gain coefficients.
	  *	
	  * One can get this list using IRshDevice::Get() method
	  * with ::RSH_GET_DEVICE_GAIN_LIST parameter.\n Input (or output)
	  * range of the device is divided by coefficients from list.
	  * For example, if device has input range 10V and we set gain equal 2,
	  * device will have input range 5V for the same bit range, so dynamic range
	  * will improve.
	  *
	  * \see
	  * RSH_GET_DEVICE_GAIN_LIST | RSH_GET_DEVICE_INPUT_RANGE_VOLTS | RshLsbToVoltCoef
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет таблицу коэффициентов усиления.
	  *
	  *	Получить список коэффициентов усиления можно с помощью метода
	  * IRshDevice::Get() с параметром ::RSH_GET_DEVICE_GAIN_LIST. \n
	  * При использовании коэффициента усиления отличного от 1.0,
	  * входной (или выходной) диапазон устройства делится на этот коэффициент
	  * усиления, позволяя более полно задействовать динамический диапазон АЦП
	  * при работе со слабыми сигналами.\n Например, если устройство имеет входной диапазон
	  * 10В и 12 бит, вся шкала от 0 до 4096МЗР соотвествует напряжению от -10 до +10В.
	  * Использование коэффициента усиления равного 2 ставит в соответствие тому же диапазону
	  * (от 0 до 4096МЗР) напряжение от -5 до +5В, таким образом цена одного МЗР становится в два
	  * раза меньше. Правильно выбрав коэффициент усиления, можно более точно измерить слабый сигнал.
	  *
	  * \see
	  * RSH_GET_DEVICE_GAIN_LIST | RSH_GET_DEVICE_INPUT_RANGE_VOLTS | RshLsbToVoltCoef
	  *
	  */
	 RSH_CAPS_DEVICE_GAIN_LIST = 21,

	 /*!
	  * \~english
	  * \brief
	  * Gain coefficients can be set separately for each analog channel.
	  *
	  * Gain coefficients can be obtained using IRshDevice::Get() method
	  * with ::RSH_GET_DEVICE_GAIN_LIST parameter. \n
	  * Gain coefficients can be set using RshInitADC::channels list.
	  *
	  * \remarks
	  * Most of the rsh devices have this feature.
	  *
	  * \see 
	  * RshChannel | RshInitADC | RSH_GET_DEVICE_GAIN_LIST
	  *
	  * \~russian
	  * \brief
	  * Поддерживается установка коэффициента усиления индивидуально для каждого канала.
	  *
	  * Список коэффициентов усиления может быть получен с помощью метода IRshDevice::Get()
	  * с параметром ::RSH_GET_DEVICE_GAIN_LIST. \n
	  * Устанавливаются коэффиценты усиления в списке RshInitADC::channels структуры инициализации.
	  *
	  * \remarks
	  * Большинство устройств поддерживают эту возможность.
	  *
	  * \see 
	  * RshChannel | RshInitADC | RSH_GET_DEVICE_GAIN_LIST
	  *
	  */
	 RSH_CAPS_DEVICE_GAINS_PER_CHANNEL = 22,

	 /*!
	  * \~english
	  * \brief
	  * Prehistory data writing is availible.
	  *
	  * Using RshInitMemory::preHistory field one can choose, what part
	  * of databuffer will be used for saving "prehistory" data
	  * (before synchronization event occurred) and "history" data
	  * (after synchronization event occurred).
	  *
	  * \remarks
	  * Prehistory parameter is only used when working with synchronization.
	  *
	  * \see
	  * RshInitMemory | RSH_GET_DEVICE_PREHISTORY_SIZE | \link page_Synchronization Synchronization\endlink
	  * 
	  * \~russian
	  * \brief
	  * Доступна возможность записи предыстории измерения.
	  *
	  * Используя поле RshInitMemory::preHistory структуры инициализации,
	  * можно задать, какая часть буфера данных будет использована для 
	  * записи данных "предыстории" (до события синхронизации) и 
	  * "истории" (после события синхронизации).	
	  *
	  * \remarks
	  * Параметр "предыстория" актуален только при работе в режиме синхронизации.
	  *
	  * \see
	  * RshInitMemory | RSH_GET_DEVICE_PREHISTORY_SIZE | \link page_Synchronization Синхронизация\endlink
	  */
	 RSH_CAPS_DEVICE_PREHISTORY = 23,

	 /*!
	  * \~english
	  * \brief
	  * Device supports double frequency data acquisition mode.
	  * 
	  * Some of high sampling rate devices with on board memory installed
	  * can operate in so called <b>double frequency</b> mode.
	  * For such devices, each analog channel usualy has its own ADC chip
	  * and when device is operated in normal mode, all ADC work in parralles,
	  * converting data from analog inputs.\n
	  * When double frequency mode is activated, 2 ADC start work with only one analog input
	  * (for most devices it is first channel, but for some you can chose what channel use
	  * for double frequency - see ::RSH_CAPS_DEVICE_FREE_CHANNEL_SELECT_IN_EXT_MODE).\n
	  * The result of this is that sampling rate (and buffer size) is doubled for selected channel,
	  * so if device has maximum sampling frequency 1GHz for example, in double frequency mode 
	  * it will have ONLY one channel active, but with 2GHz sampling rate.\n
	  * Example: \include IRshDevice_DoubleFreqMode_EN.cpp
	  *
	  * \remarks
	  * For block devices like oscillosopes, when 2 or more ADC board are combined in one 
	  * multychannel device, total number of channels in double frequency mode is half
	  * its channels in normal mode.
	  *
	  * \see
	  * RshInitMemory | RSH_CAPS_DEVICE_FREE_CHANNEL_SELECT_IN_EXT_MODE
	  *
	  * \~russian
	  * \brief
	  * Устройство поддерживает режим сбора данных с удвоенной частотой дискретизации.
	  *
	  * Некоторые из высокочастотных устройств с собственной памятью
	  * могут работать в так называемом режиме <b>удвоения частоты</b>.
	  * Как правило, на таких устройствах установлено отдельное АЦП для оцифровки каждого
	  * канала. Когда устройство работает в обычном режиме, все АЦП работают параллельно,
	  * каждое цифрует данные со своего аналогового канала.\n
	  * В режиме удвоения частоты, 2 АЦП работают с данными \a одного аналогового канала
	  * (для большинства устройств это первый канал, для некоторых устройств можно задать 
	  * канал, который будет использоваться для удвоения - см. ::RSH_CAPS_DEVICE_FREE_CHANNEL_SELECT_IN_EXT_MODE).\n
	  * В результате этого, частота дискретизации (и размер буфера) для этого канала удваивается,
	  * и если, к примеру, максимальная частота дискретизации для устройства 1ГГц, в режиме удвоения
	  * будет активен ТОЛЬКО один из двух каналов, но с частотой дискретизации 2ГГц. \n
	  * Пример: \include IRshDevice_DoubleFreqMode_RU.cpp
	  *
	  *
	  * \remarks
	  * Для составных устройств (многоканальных осциллографов), в которых используются 2 или
	  * более устройства в качестве базовых модулей, число каналов в режиме удвоения будет
	  * в два раза меньше, чеи общее число каналов осциллографа.
	  *
	  * \see
	  * RshInitMemory | RSH_CAPS_DEVICE_FREE_CHANNEL_SELECT_IN_EXT_MODE
	  *
	  */
	 RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE = 24,

	 /*!
	  * \~english
	  * \brief
	  * Device supports quadro frequency data acquisition mode.
	  *
	  * This mode is similar to double frequency mode (::RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE)
	  * only exception is that frequency is multiplied by 4 and not 2. Channel number
	  * is divided by 4, accordingly.
	  *
	  * \see 
	  * RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE
	  *
	  * \~russian
	  * \brief
	  * Устройство поддерживает режим режим сбора данных с учетверенной частотой дискретизации.
	  *
	  * Данный режим аналогичен удвоению частоты (::RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE),
	  * единственное отличие - частота умножается на 4, а не на 2. Число каналов, соответственно,
	  * тоже делится на 4.
	  *
	  * \see 
	  * RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE
	  *
	  */
	 RSH_CAPS_DEVICE_QUADRO_FREQUENCY_MODE = 25,

	 /*!
	  * \~english
	  * \brief
	  * Device supports autocalibration.
	  *
	  * Automatic internal calibration. Calibration procedure
	  * is device specific. For example, Leonardo II board
	  * adjust zero level for analog channels when one call
	  * IRshDevice::Get() with RSH_GET_DEVICE_AUTO_CALIBRATION_SET parameter.
	  *
	  * \remarks
	  * ::RSH_CAPS_SOFT_CALIBRATION_IS_AVAILABLE is not connected to this one!
	  * ::RSH_CAPS_SOFT_CALIBRATION_IS_AVAILABLE is active for device libraries
	  * that have imbeded calibration algorithms, used during device setup
	  * with external signal generation and measurement devices.
	  *
	  * \see
	  * RSH_GET_DEVICE_AUTO_CALIBRATION_SET
	  *
	  * \~russian
	  * \brief
	  * Устройство поддерживает режим автокалибровки.
	  *
	  * Автоматическая внутренняя калибровка. Процедура
	  * калибровки индивидуальна для каждого устройства.
	  * Например, плата Леонардо II настраивает уровни смещения нуля
	  * при вызове метода IRshDevice::Get() с параметром
	  * RSH_GET_DEVICE_AUTO_CALIBRATION_SET. 
	  *
	  * \remarks
	  * Флаг ::RSH_CAPS_SOFT_CALIBRATION_IS_AVAILABLE не связан с этим флагом!
	  * Наличие ::RSH_CAPS_SOFT_CALIBRATION_IS_AVAILABLE говорит о том, что
	  * в библиотеке устройства присуствуют алгоритмы калибровки, нужные
	  * при настройке (предпродажной или ремонтной) устройства. 
	  *
	  * \see
	  * RSH_GET_DEVICE_AUTO_CALIBRATION_SET
	  *
	  */
	 RSH_CAPS_DEVICE_AUTO_CALIBRATION = 26,

	 /*!
	  * \~english
	  * \brief
	  * Analog input of the device can be used as trigger source.
	  *
	  * Using RshInitMemory initialization structure one can
	  * set treshold and select one of the input analog channels as
	  * trigger source. Synchronization slope and some other parameters
	  * are also programmable. After starting data acquisition using 
	  * IRshDevice::Start() method, synchronization event will be 
	  * raised when signal on selected input will correspond to selected trigger settings.
	  *
	  * \see
	  * RshInitMemory | RshChannel
	  *
	  * \~russian
	  * \brief
	  * Аналоговые каналы устройства могут быть использованы в качестве источника синхронизации.
	  *
	  * Используя структуру инициализации RshInitMemory можно задать порог срабатывания,
	  * условие перехода (фронт или спад), а также некоторые другие параметры и выбрать один
	  * из аналоговых входных каналов устройства в качестве источника синхронизации.
	  * После запуска процесса сбора данных с помощью метода IRshDevice::Start(), устройство
	  * будет ожидать прихода события синхронизации в соотвествии с заданными параметрами.
	  *
	  * \see
	  * RshInitMemory | RshChannel 
	  *
	  */
	 RSH_CAPS_DEVICE_SYNCHRO_INTERNAL = 27,

	 /*!
	  * \~english
	  * \brief
	  * Device has additional input that can be used as trigger source.
	  *
	  * Syncrhonization parameters (such as threshold, slope, filter use etc.)
	  * can be selected using RshInitMemory structure.  After starting data acquisition using 
	  * IRshDevice::Start() method, synchronization event will be 
	  * raised when signal on external sync input will correspond to selected trigger settings.
	  *
	  * \remarks
	  * Usually external input differs from analog inputs - it can have its own
	  * input range, gain coefficients list, input resist switch, programmable filters, etc.
	  * All this parameters can be obtained using IRshDevice::Get() method. All external
	  * synchronization specific parameters have <b>RSH_GET_DEVICE_EXT_SYNC</b> prefix,
	  * for example ::RSH_GET_DEVICE_EXT_SYNC_GAINLIST.
	  *
	  * \see
	  * RshInitMemory | RshSynchroChannel
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет дополнительный вход, который может быть использован в качестве источника синхронизации.
	  *
	  * Параметры синхронизации (порог, условие перехода, использование фильтра и др.)
	  * могут быть заданы в структуре RshInitMemory. После запуска сбора данных с помощью
	  * метода IRshDevice::Start(), устройство будет ожидать прихода события синхронизаци
	  * в соотвествии с заданными параметрами.
	  *
	  * \remarks
	  * Вход внешней синхронизации обычно отличается от аналоговых входов по своим параметрам.
	  * Он может иметь собственный входной диапазон, список коэффициентов усиления, переключение
	  * сопротивления входа, программируемые фильтры и т.д. 
	  * Все эти параметры могут быть получены с помощью метода IRshDevice::Get(). Параметры,
	  * относящиеся к внешней синхронизации, имеют префикс <b>RSH_GET_DEVICE_EXT_SYNC</b>,
	  * например ::RSH_GET_DEVICE_EXT_SYNC_GAINLIST.
	  *
	  * \see
	  * RshInitMemory | RshSynchroChannel
	  */
	 RSH_CAPS_DEVICE_SYNCHRO_EXTERNAL = 28,
	 	
	 /*!
	  * \~english
	  * \brief
	  * Device has digital trigger.
	  *
	  * Data acquisition process can be triggered using TTL signal.
	  * Information about signal connection, levels and condition to trigger
	  * can be found in device documentation or user manual.
	  *
	  * \remarks
	  * External start and external synchronization are not the same thing!
	  *
	  * \~russian	  
	  * \brief
	  * Устройство поддерживает возможность внешнего запуска преобразования.
	  *
	  * Процесс сбора данных может быть запущен подачей TTL сигнала на определенный
	  * цифровой вход устройства.
	  * Информация о подключении, уровне сигнала и условиях срабатывания содержится
	  * в руководстве пользователя для конкретного устройства.
	  *
	  * \remarks
	  * Внешний запуск преобразования и внешняя синхронизация - не одно и то же!
	  *
	  */
	 RSH_CAPS_DEVICE_EXTERNAL_START = 29,

	 /*!
	  * \~english
	  * \brief
	  * Device has programmable hysteresis for synchronization.
	  *
	  * Some devices with hardware digital synchronization have
	  * programmable hysteresis level feature.\n
	  * For more details about this option see RshInitMemory::hysteresis.
	  *
	  * \see
	  * RshInitMemory::hysteresis | IRshDevice::Init() | \link page_Synchronization Synchronization\endlink
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет возможность задания уровня гистерезиса для синхронизации.
	  *
	  * Некоторые устройства с аппаратной цифровой синхронизацией имеют
	  * возможность программно задавать уровень гистерезиса. \n
	  * Более подробно об этой фозможности смотрите тут: RshInitMemory::hysteresis.
	  *
	  * \see
	  * RshInitMemory::hysteresis | IRshDevice::Init() | \link page_Synchronization Синхронизация\endlink
	  *
	  */
	 RSH_CAPS_DEVICE_HYSTERESIS = 30,

	 /*!
	  * \~english
	  * \brief
	  * Device have separate gain coefficients list for externl input.
	  *
	  * External syncrhonization input often have its own gain list.
	  * You can get that list using IRshDevice::Get() method with
	  * ::RSH_GET_DEVICE_EXT_SYNC_GAINLIST parameter.
	  *
	  * \remarks
	  * If external synchronization input supports resist switch,
	  * you can get different lists for 50Ohm and 1MOhm modes
	  * using ::RSH_GET_DEVICE_EXT_SYNC_GAIN_LIST_50_OHM and
	  * ::RSH_GET_DEVICE_EXT_SYNC_GAIN_LIST_1_MOHM constans accordingly.
	  *
	  * \see
	  * IRshDevice::Get() | RSH_GET_DEVICE_EXT_SYNC_GAINLIST
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет отдельный список коэффициентов усиления для входа внешней синхронизации.
	  *
	  * Вход внешней синхронизации часто отличается от обычных аналоговых входов,
	  * и может иметь свой собственный список коэффициентов усиления.
	  * Получить этот список можно используя метод IRshDevice::Get()
	  * с параметром ::RSH_GET_DEVICE_EXT_SYNC_GAINLIST.
	  *
	  * \remarks
	  * Если вход внешней синхронизации поддерживает переключение
	  * входного сопротивления, можно получить два различных списка
	  * коэффициентов усиления для 50Ом и 1МОм режима, используя
	  * метод IRshDevice::Get() с константами ::RSH_GET_DEVICE_EXT_SYNC_GAIN_LIST_50_OHM
	  * и ::RSH_GET_DEVICE_EXT_SYNC_GAIN_LIST_1_MOHM соответственно.
	  *
	  * \see
	  * IRshDevice::Get() | RSH_GET_DEVICE_EXT_SYNC_GAINLIST
	  *
	  */
	 RSH_CAPS_DEVICE_EXT_SYNC_GAIN_LIST = 31,

	 /*!
	  * \~english
	  * \brief
	  * High pass filter can be set on external syncrhonization input.
	  *
	  * Filter pass band and other details are device specific, see
	  * user manual for more information.\n
	  * RshInitMemory::channelSynchro field  of RshInitMemory is used for external
	  * synchronization channel control.
	  * RshSynchroChannel::FilterLow bit must be set in RshSynchroChannel::control field
	  * to turn filter on.
	  *
	  * \see RshInitMemory | RshSynchroChannel | \link RshInitMemroySynchroChannel_EN.cpp Example of external synchronization input setup\endlink
	  *
	  * \~russian
	  * \brief
	  * Фильтр низких частот может быть включен для входа внешней синхронизации.
	  *
	  * Полоса пропускания, подавление и другие характеристики фильтра зависят от
	  * типа устройства, более подробная информация содержится в руководстве пользователя.\n
	  * Для управления каналом внешней синхронизации используется поле
	  * RshInitMemory::channelSynchro структуры RshInitMemory.
	  * Для того, чтобы задействовать ФНЧ, нужно выставить бит 
	  * RshSynchroChannel::FilterLow в поле RshSynchroChannel::control.
	  *
	  * \see RshInitMemory | RshSynchroChannel | \link RshInitMemroySynchroChannel_RU.cpp Пример настройки параметров входа внешней синхронизации\endlink
	  */
	 RSH_CAPS_DEVICE_EXT_SYNC_FILTER_LOW = 32,

	  /*!
	  * \~english
	  * \brief
	  * Low pass filter can be set on external syncrhonization input.
	  *
	  * Filter pass band and other details are device specific, see
	  * user manual for more information.\n
	  * RshInitMemory::channelSynchro field  of RshInitMemory is used for external
	  * synchronization channel control.
	  * RshSynchroChannel::FilterHigh bit must be set in RshSynchroChannel::control field
	  * to turn filter on.
	  *
	  * \see RshInitMemory | RshSynchroChannel | \link RshInitMemroySynchroChannel_EN.cpp Example of external synchronization input setup\endlink
	  *
	  * \~russian
	  * \brief
	  * Фильтр высоких частот может быть включен для входа внешней синхронизации.
	  *
	  * Полоса пропускания, подавление и другие характеристики фильтра зависят от
	  * типа устройства, более подробная информация содержится в руководстве пользователя.\n
	  * Для управления каналом внешней синхронизации используется поле
	  * RshInitMemory::channelSynchro структуры RshInitMemory.
	  * Для того, чтобы задействовать ФВЧ, нужно выставить бит 
	  * RshSynchroChannel::FilterHigh в поле RshSynchroChannel::control.
	  *
	  * \see RshInitMemory | RshSynchroChannel | \link RshInitMemroySynchroChannel_RU.cpp Пример настройки параметров входа внешней синхронизации\endlink
	  */
	 RSH_CAPS_DEVICE_EXT_SYNC_FILTER_HIGH = 33,

	 /*!
	  * \~english
	  * \brief
	  * External synchronization input of the device has 50 Ohm resist mode.
	  *
	  * If RSH_CAPS_DEVICE_EXT_SYNC_INPUT_RESIST_1_MOHM is also available,
	  * one can switch between resist modes using RshInitMemory::channelSynchro
	  * field of RshInitMemory structure. \n 
	  * If 50Ohm is the only option, or neither of resist CAPS available,
	  * using this setting will take no effect.
	  *
	  * \remarks
	  * When switching resist mode dont forget that modes have different gain lists
	  * and some features (as coupling) are available only for 1MOhm input mode.
	  *
	  * \see RSH_CAPS_DEVICE_EXT_SYNC_COUPLING_AC_DC | RshSynchroChannel | \link RshInitMemroySynchroChannel_EN.cpp Example of external synchronization input setup\endlink
	  *
	  * \~russian
	  * \brief
	  * Доступен режим входного сопротивления 50Ом для входа внешней синхронизации.
	  *
	  * Если, кроме того, активен режим RSH_CAPS_DEVICE_EXT_SYNC_INPUT_RESIST_1_MOHM,
	  * можно программно переключать входное сопротивление входа, используя поле
	  * RshInitMemory::channelSynchro структуры RshInitMemory.\n	  
	  * Если 50Ом единственная доступная опция, или вообще ни одна из опций неактивна,
	  * использование данной настройки не будет иметь эффекта, и вход внешней синхронизации
	  * всегда будет в единственном доступном состоянии.
	  *
	  * \remarks
	  * При переключении сопротивления входа нужно помнить, что списки коэффициентов
	  * усиления различаются для разных входных сопротивлений. Кроме того, некоторые
	  * опции (например, возможность использования открытого/закрытого входа) доступны
	  * только в режиме 1МОм входа.
	  *
	  * \see RSH_CAPS_DEVICE_EXT_SYNC_COUPLING_AC_DC | RshSynchroChannel | \link RshInitMemroySynchroChannel_RU.cpp Пример настройки параметров входа внешней синхронизации\endlink 
	  *
	  */
	 RSH_CAPS_DEVICE_EXT_SYNC_INPUT_RESIST_50_OHM = 34,

	  /*!
	  * \~english
	  * \brief
	  * External synchronization input of the device has 1 MOhm resist mode.
	  *
	  * If RSH_CAPS_DEVICE_EXT_SYNC_INPUT_RESIST_50_OHM is also available,
	  * one can switch between resist modes using RshInitMemory::channelSynchro
	  * field of RshInitMemory structure. \n 
	  * If 1MOhm is the only option, or neither of resist CAPS available,
	  * using this setting will take no effect.
	  *
	  * \remarks
	  * When switching resist mode dont forget that modes have different gain lists
	  * and some features (as coupling) are available only for 1MOhm input mode.
	  *
	  * \see RSH_CAPS_DEVICE_EXT_SYNC_COUPLING_AC_DC | RshSynchroChannel | \link RshInitMemroySynchroChannel_EN.cpp Example of external synchronization input setup\endlink
	  *
	  * \~russian
	  * \brief
	  * Доступен режим входного сопротивления 1МОм для входа внешней синхронизации.
	  *
	  * Если, кроме того, активен режим RSH_CAPS_DEVICE_EXT_SYNC_INPUT_RESIST_50_OHM,
	  * можно программно переключать входное сопротивление входа, используя поле
	  * RshInitMemory::channelSynchro структуры RshInitMemory.\n	  
	  * Если 1МОм единственная доступная опция, или вообще ни одна из опций неактивна,
	  * использование данной настройки не будет иметь эффекта, и вход внешней синхронизации
	  * всегда будет в единственном доступном состоянии.
	  *
	  * \remarks
	  * При переключении сопротивления входа нужно помнить, что списки коэффициентов
	  * усиления различаются для разных входных сопротивлений. Кроме того, некоторые
	  * опции (например, возможность использования открытого/закрытого входа) доступны
	  * только в режиме 1МОм входа.
	  *
	  * \see RSH_CAPS_DEVICE_EXT_SYNC_COUPLING_AC_DC | RshSynchroChannel | \link RshInitMemroySynchroChannel_RU.cpp Пример настройки параметров входа внешней синхронизации\endlink 
	  *
	  */
	 RSH_CAPS_DEVICE_EXT_SYNC_INPUT_RESIST_1_MOHM = 35,

	 /*!
	  * \~english
	  * \brief
	  * AC/DC coupling of the external synchronization input can be changed.
	  *
	  * In 1MOhm input mode one can switch between AC and DC mode of external
	  * synchronization channel using RshInitMemory::channelSynchro
	  * field of RshInitMemory structure. \n  
	  *
	  * \see  RshSynchroChannel | \link RshInitMemroySynchroChannel_EN.cpp Example of external synchronization input setup\endlink 
	  * 
	  * \~russian
	  * \brief
	  * Доступна возможность переключения состояния входа внешней синхронизации "Открытый"/"Закрытый".
	  *
	  * Если синхровход работает в режиме входного сопротивления 1МОм, есть возможность
	  * задать состояние входа: открытый (постоянная составляющая сигнала учитывается) или
	  * закрытый (постоянная составляющая сигнала отбрасывается). Для установки параметра
	  * используется  поле RshInitMemory::channelSynchro структуры RshInitMemory.
	  *
	  * \see  RshSynchroChannel | \link RshInitMemroySynchroChannel_RU.cpp Пример настройки параметров входа внешней синхронизации\endlink 
	  * 
	  */
	 RSH_CAPS_DEVICE_EXT_SYNC_COUPLING_AC_DC = 36,

	 /*!
	  * \~english
	  * \brief
	  * Device have one or more DAC modules installed.
	  *
	  * One can get access to DACs using IRshDevice::Init() method
	  * with RshInitDAC initialization structure.
	  *
	  * \remarks
	  * Do not confuse this feature with RSH_CAPS_SOFT_GENERATION_IS_AVAILABLE.
	  * Second one is for devices which main feature is signal generation,
	  * such as GSPF. GSPF have internal buffer for data, attenuator and can play
	  * signals from buffer with different sampling frequencies.\n
	  * DAC installed on ADC board is quite simple, and can only
	  * set some voltage level on output node.
	  * 
	  * \see RSH_CAPS_SOFT_INIT_DAC | RshInitDAC | \link RshInitDAC_EN.cpp DAC control example\endlink
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет один или несколько ЦАПов.
	  *
	  * Управлять ЦАПами можно с помощью метода IRshDevice::Init(),
	  * используя структуру инициализации RshInitDAC.
	  *
	  * \remarks
	  * Не путайте данную возможность с RSH_CAPS_SOFT_GENERATION_IS_AVAILABLE.
	  * Для устройств, которые поддерживают RSH_CAPS_SOFT_GENERATION_IS_AVAILABLE,
	  * генерация сигнала является основным предназначением.\n
	  * Например, устройства серии GSPF имеют внутренний буфер для данных, аттенюатор,
	  * возможность выдачи сигнала из внутреннего буфера с различной частотой дискретизации
	  * и в разных режимах - одиночный, с повторением, по внешнему триггеру.\n
	  * Флаг RSH_CAPS_SOFT_INIT_DAC говорит о том, что устройство может, помимо основной
	  * своей задачи (сбор и оцифровка данных), выдать сигнал на ЦАП, причем
	  * никаких других действий кроме установки заданного уровня сигнала на выходе
	  * произвести нельзя.
	  * 
	  * \see RSH_CAPS_SOFT_INIT_DAC | RshInitDAC | \link RshInitDAC_RU.cpp пример управления ЦАПом\endlink
	  *
	  */
	 RSH_CAPS_DEVICE_HAS_DAC_INSTALLED = 37,

	 /*!
	  * \~english
	  * \brief
	  * Device's analog channels have programmable hardware input level adjustment.
	  *
	  * Usually, voltage range of this adjustment is equal to input voltage range.
	  * One can get access to this feature, using RshInitADC::channels list,
	  * via RshChannel::adjustment field.\n
	  * For example, device have input range ±25V, and we have sinus signal
	  * with mean value 20V and amplitude 10V. Without signal adjustment, we 
	  * cant't see full signal (it will be cut off becouse maximum value will be
	  * 20+10 = 30 V). Setting RshChannel::adjustment parameter for this channel
	  * to -15V we will have signal on ADC input in range from 35-15=20V to 10-15=-5V,
	  * which is in range of our ADC and can be converted without losing anything.
	  *
	  * \remarks You can acheive similar result using RshChannel::AC mode
	  * if ::RSH_CAPS_DEVICE_INPUT_COUPLING_AC_DC flag is available.
	  *
	  * \see RshChannel | RshInitADC
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет возможность подстройки уровня входного напряжения аналоговых каналов.
	  *
	  * Обычно, диапазон подстройки уровня входного напряжения совпадает со входным
	  * диапазоном канала.
	  * Управлять этим параметром можно отдельно для каждого канала в списке RshInitADC::channels,
	  * используя поле RshChannel::adjustment.\n
	  * Допустим, канал имеет входной диапазон ±25В, а на входе синусоидальный сигнал
	  * со средним значениме 20В и амплитудой 10В. Без коррекции входного напряжения
	  * на входе АЦП будет сигнал от 35В до 10В, и оцифровать его без потерь
	  * не получится. Установив же параметр RshChannel::adjustment равным, к примеру,
	  * -15В, мы получим на входе АЦП сигнал в диапазоне от 35-15=20В до 10-15=-5В,
	  * который может быть оцифрован без потерь.
	  *
	  * \remarks Добиться похожего результата можно, используя режим RshChannel::AC,
	  * если флаг ::RSH_CAPS_DEVICE_INPUT_COUPLING_AC_DC доступен для устройства.
	  *
	  * \see RshChannel | RshInitADC
	  */
	 RSH_CAPS_DEVICE_INPUT_LEVEL_ADJUSTMENT = 38,

	 /*!
	  * \~english
	  * \brief
	  * AC/DC coupling of the analog inputs can be changed.
	  *
	  * In 1MOhm input mode one can switch between AC and DC mode of analog
	  * input channels setting one of the flags (RshChannel::AC or RshChannel::DC)
	  * in RshChannel::control field for selected channel in RshInitMemory::channels list
	  * in RshInitMemory structure.
	  *
	  * \see  RshChannel | RshInitMemory | \link RshChannelSetup_EN.cpp Channels setup example\endlink
	  *
	  * \~russian
	  * \brief
	  * Доступна возможность переключения состояния аналоговых входов "открытый/закрытый".
	  *
	  * Если аналоговый канал поддерживает входное сопротивление 1МОм,
	  * в этом режиме можно переключать состояние канала между "открытый вход"
	  * и "закрытый вход", устанавливая один из флагов (RshChannel::AC или RshChannel::DC)
	  * в поле RshChannel::control для выбранного канала в списке RshInitMemory::channels
	  * в структуре инициализации RshInitMemory.
	  *
	  * \see  RshChannel | RshInitMemory | \link RshChannelSetup_RU.cpp Пример настройки каналов\endlink
	  *
	  */
	 RSH_CAPS_DEVICE_INPUT_COUPLING_AC_DC = 39,

	 /*!
	  * \~english
	  * \brief
	  * Analog input channels of the device has 50 Ohm resist mode.
	  *
	  * If RSH_CAPS_DEVICE_INPUT_RESIST_1_MOHM is also available,
	  * one can switch between resist modes using RshChannel::control field
	  * for selected channel in RshInitMemory::channels list of RshInitMemory structure.\n 
	  * If 50Ohm is the only option, or neither of resist CAPS available,
	  * using this setting will take no effect.
	  *
	  * \remarks
	  * When switching resist mode dont forget that modes have different gain lists
	  * and some features (as coupling) are available only for 1MOhm input mode.
	  *
	  * \see RSH_CAPS_DEVICE_INPUT_COUPLING_AC_DC | RshChannel | \link RshChannelSetup_EN.cpp Channels setup example\endlink
	  *
	  * \~russian
	  * \brief
	  * Доступен режим входного сопротивления 50Ом для аналоговых каналов.
	  *
	  * Если, кроме того, активен режим RSH_CAPS_DEVICE_INPUT_RESIST_1_MOHM,
	  * можно программно переключать входное сопротивление входа, используя поле
	  * RshChannel::control для выбранного канала в списке RshInitMemory::channels структуры RshInitMemory.\n	  
	  * Если 50Ом единственная доступная опция, или вообще ни одна из опций неактивна,
	  * использование данной настройки не будет иметь эффекта, и вход
	  * всегда будет в единственном доступном состоянии.
	  *
	  * \remarks
	  * При переключении сопротивления входа нужно помнить, что списки коэффициентов
	  * усиления различаются для разных входных сопротивлений. Кроме того, некоторые
	  * опции (например, возможность использования открытого/закрытого входа) доступны
	  * только в режиме 1МОм входа.
	  *
	  * \see RSH_CAPS_DEVICE_INPUT_COUPLING_AC_DC | RshChannel | \link RshChannelSetup_RU.cpp Пример настройки каналов\endlink
	  *
	  */
	 RSH_CAPS_DEVICE_INPUT_RESIST_50_OHM = 40,

	 /*!
	  * \~english
	  * \brief
	  * Analog input channels of the device has 1 MOhm resist mode.
	  *
	  * If RSH_CAPS_DEVICE_INPUT_RESIST_50_OHM is also available,
	  * one can switch between resist modes using RshChannel::control field
	  * for selected channel in RshInitMemory::channels list of RshInitMemory structure.\n 
	  * If 1MOhm is the only option, or neither of resist CAPS available,
	  * using this setting will take no effect.
	  *
	  * \remarks
	  * When switching resist mode dont forget that modes have different gain lists
	  * and some features (as coupling) are available only for 1MOhm input mode.
	  *
	  * \see RSH_CAPS_DEVICE_INPUT_COUPLING_AC_DC | RshChannel | \link RshChannelSetup_EN.cpp Channels setup example\endlink
	  *
	  * \~russian
	  * \brief
	  * Доступен режим входного сопротивления 1МОм для аналоговых каналов.
	  *
	  * Если, кроме того, активен режим RSH_CAPS_DEVICE_INPUT_RESIST_50_OHM,
	  * можно программно переключать входное сопротивление входа, используя поле
	  * RshChannel::control для выбранного канала в списке RshInitMemory::channels структуры RshInitMemory.\n	  
	  * Если 1МОм единственная доступная опция, или вообще ни одна из опций неактивна,
	  * использование данной настройки не будет иметь эффекта, и вход
	  * всегда будет в единственном доступном состоянии.
	  *
	  * \remarks
	  * При переключении сопротивления входа нужно помнить, что списки коэффициентов
	  * усиления различаются для разных входных сопротивлений. Кроме того, некоторые
	  * опции (например, возможность использования открытого/закрытого входа) доступны
	  * только в режиме 1МОм входа.
	  *
	  * \see RSH_CAPS_DEVICE_INPUT_COUPLING_AC_DC | RshChannel | \link RshChannelSetup_RU.cpp Пример настройки каналов\endlink
	  *
	  */
	 RSH_CAPS_DEVICE_INPUT_RESIST_1_MOHM = 41,
	 
	 /* dont sure we need this, commented	  
	 RSH_CAPS_DEVICE_ADC_MODE_SWITCH = 42,
	 */

	 /*!
	  * \~english
	  * \brief
	  * Device supports frame frequency mode.
	  *
	  * In this mode one defines two frequencies:\n
	  * one used inside frame (determing time between channels) and the other outside
	  * (determing time between frames).\n
	  * This mode is useful when one need to acqure data with low sampling rate from
	  * several channels and use ADC with non-synchronious (multyplexed) channels.
	  * Without this mode, gaps between channels will be very large because of low
	  * frequency. But with frame frequency used, interval between channel can be small,
	  * when interval between frames can be large.
	  *
	  * \see RshInitDMA | \link page_FrameFreqMode Frame frequency data acquisition mode\endlink
	  * 
	  * \~russian
	  * \brief
	  * Устройство поддерживает режим кадрового сбора.
	  * 
	  * В этом режиме задаются две частоты:\n
	  * одна определяет частоту внутри кадра (интервал между данными с разных каналов),
	  * а другая - частоту кадров (интервал между блоками данных, в каждом блоке - по
	  * одному отсчету с каждого выбранного для измерения канала).\n
	  * Этот режим полезен при использовании устройства АЦП, каналы
	  * которого мультиплексируются (не являются синхронными), с низкой частотой дискретизации.
	  * Без включения кадрового режима при использовании низкой частоты дискретизации интервал
	  * между каналами будет очень большим. Но если включить данный режим, можно одновнременно
	  * получить низкую частоту дискретизации и маленький интервал между измерениями с разных
	  * каналов.
	  *
	  * \see RshInitDMA | \link page_FrameFreqMode Кадровый режим сбора данных\endlink
	  */
	 RSH_CAPS_DEVICE_FRAME_FREQUENCY_MODE = 43,

	 /*!
	  * \~english
	  * \brief
	  * Device supports packet mode of data acquisition.
	  *
	  * This mode is used for devices with internal memory installed.
	  * Such devices first acquire data to internal buffer (that can be
	  * several Mb long), and then transfer data using USB/PCI interface
	  * to PC. Second process is quite long, so if required data size is small,
	  * it will be waste of time on data transfer. \n
	  * Thus, packet mode is quite useful: one setup data block size using RshInitMemory::bufferSize and
	  * number of blocks using  RshInitMemory::packetNumber
	  * (obviously, \b bufferSize*packetNumber must be less then \b MaximumMemory, which one can obtain
	  * using IRshDevice::Get() method with parameter ::RSH_GET_DEVICE_MEMORY_SIZE). \n
	  * When data acquistion process will be started with IRshDevice::Start() method,
	  * device will start acquistion (using all parameters such
	  * as trigger source etc.) multiple times until it got all RshInitMemory::packetNumber
	  * blocks and only after that will start transfer data to PC.
	  *
	  * \see RshInitMemory
	  *
	  * \~russian
	  * \brief
	  * Устройство поддерживает пакетный режим сбора данных.
	  *
	  * Этот режим используется для устройств сбора данных с установленной собственной памятью.
	  * Такие устройства собирают данные во внутренний буфер (размер которого может
	  * составлять несколько мегабайт), а затем передают эти данные в компьютер по относительном
	  * медленным интерфейсам (USB, PCI). Если задан небольшой размер буфера для сбора,
	  * основное время уходит не на сбор данных, а на инициализацию сбора и передачу их
	  * в компьютер.\n
	  *
	  * Пакетный режим, таким образом, может быть очень полезен: в этом режиме можно задать
	  * размер блока данных( поле RshInitMemory::bufferSize) и количество этих блоков
	  * (поле RshInitMemory::packetNumber). Очевидно, что итоговый размер, равный
	  * \b bufferSize*packetNumber, должен быть меньше, чем максимальный объем доступной
	  * внутренней памяти \b MaximumMemory (его можно узнать с помощью метода IRshDevice::Get()
	  * с параметром ::RSH_GET_DEVICE_MEMORY_SIZE).\n
	  * Когда будет запущен процесс сбора данных с помощью метода IRshDevice::Start(),
	  * устройство будет собирать данные (используя все заданные параметры сбора, настройки синхронизации
	  * и т.д.) до тех пор, пока не соберет RshInitMemory::packetNumber блоков данных. Только после
	  * этого начнется передача данных в компьютер. \n
	  * Таким образом, можно, например, записать без пропусков несколько быстрых процессов,
	  * идущих с небольшим интервалом, что было бы невозможно в обычном режиме.
	  *
	  * \see RshInitMemory
	  *
	  */
	 RSH_CAPS_DEVICE_PACKET_MODE = 44,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Data acquisition process can be delayed (from trigger event).
	  * 
	  * When device work in syncrhonization mode, one can set
	  * time interval (RshInitMemory::startDelay field), and
	  * when synchronization event will be triggered, data writing
	  * will start not immediately, but after \b startDelay time elapsed.\n
	  * This setting is opposite to using RshInitMemory::preHistory.
	  * 
	  * \see
	  * RshInitMemory | \link page_Synchronization Synchronization\endlink
	  * 
	  * \~russian
	  * \brief
	  * Сбор данных может быть начат с задержкой (относительно события синхронизации)
	  * 
	  * Если устройство работает в режиме ожидания события синхронизации, можно задать
	  * интервал времени (поле RshInitMemory::startDelay), определяющий задержку старта.
	  * Когда будет получено событие синхронизации, запись данных в буфер начнется не
	  * мгновенно, а через заданное в поле \b startDelay время. \n
	  * Эта опция, по сути, "предыстория наоборот"
	  * (предыстория задается в поле RshInitMemory::preHistory).	
	  * 
	  * \see
	  * RshInitMemory | \link page_Synchronization Синхронизация\endlink
	  */
	 RSH_CAPS_DEVICE_START_DELAY = 45,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Data acquisition can be started from master device.
	  * 
	  * Using RshInitADC::Master as RshInitADC::startType,
	  * one can run device as slave. After call to IRshDevice::Start()
	  * method device will be in waitng state (like synchronization),
	  * but wait for signal from master device.
	  * 
	  * \remarks
	  * This feature is mostly used in systems where several identical
	  * devices are used for syncrhonious data acquisition. Special link
	  * between devices is required for this feature to work.
	  * 
	  * \~russian
	  * \brief
	  * Сбор данных может быть запущен от ведущего устройства.
	  * 
	  * Задав RshInitADC::Master в качестве источника запуска в поле RshInitADC::startType,
	  * можно сделать устройство "ведомым" (slave). После вызова метода IRshDevice::Start(),
	  * устройство будет находиться в режиме ожидания (как при использовании синхронизации),
	  * и сбор данных начнется только при получении специального сигнала от ведущего (Master)
	  * устройства
	  * 
	  * \remarks
	  * Даная возможность чаще всего применяется в составных системах, где несколько 
	  * одинаковых устройств используются для синхронного сбора данных. Необходимо
	  * соединять ведущее и ведомое (или ведомые) устройства специальным кабелем,
	  * чтобы система заработала в таком режиме.
	  *
	  */
	 RSH_CAPS_DEVICE_SLAVE_MASTER_SWITCH = 46,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Device's channels are synchronous.
	  * 
	  * If this flag is active, the device have separate ADC for each
	  * of analog channels, all ADCs are started by common clock signal
	  * and data from all channels acquired simultaniously.\n
	  * If opposite is true, device only have one ADC and channels are multyplexed.
	  * All samples have intervals equal to 1/F between them, where F is sampling
	  * frequency.
	  * 
	  * \remarks
	  * If device dont support this feature, its maximum frequency is always divided
	  * by number of channels used. For example, if device have maximum sampling rate equal
	  * to 500kHz, when using 2 channels one can only set RshInitADC::frequency field
	  * to 250kHz.
	  * 
	  * \see
	  * RshInitADC
	  * 
	  * \~russian
	  * \brief
	  * Аналоговые каналы устройства - синхронные.
	  * 
	  * Если данный флаг активен, устройство имеет свой собственный АЦП 
	  * на каждом из аналоговых каналов, все эти АЦП тактируются из одного
	  * источника, и данные со всех каналов собираются синхронно.\n
	  * Если же верно обратное, устройство имеет только один АЦП и аналоговые
	  * каналы оцифровываются по очереди (мультиплексируются). При этом
	  * все отсчеты отделены друг от друга по времени на величину 1/F,
	  * где F - частота дискретизации.
	  * 
	  * \remarks
	  * Если устройство не поддерживает данную опцию (каналы не синхронны),
	  * максимальная частота дискретизации всегда делится на количество активных
	  * (участвующих в сборе данных) каналов. Например, если максимальная частота
	  * дискретизации устройства составляет 500кГц, при использовании двух каналов
	  * максимально возможное значение частоты в поле RshInitADC::frequency 
	  * будет равно 250кГц.
	  * 
	  * \see
	  * RshInitADC
	  */
	 RSH_CAPS_DEVICE_SYNCHRO_CHANNELS = 47,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * ADC can be sampled by external signal source.
	  * 
	  * To turn on this feature use RshInitADC::FrequencyExternal bit
	  * in RshInitADC::startType field of initialization structure.
	  * One can combine this flag
	  * (using OR state) with some other startType flags, like 
	  * RshInitADC::Timer or RshInitADC::Internal.\n
	  * Parameters of signal to use as sampling source can be find
	  * in device's user manual.
	  * 
	  * \remarks
	  * When using this feature, RshInitADC::frequency field is still
	  * used (in most devices) to determine what frequency divider will
	  * be used.\n
	  * For example, if maximum sampling rate for device is 500kHz,
	  * and 150кHz external sampling source is used, when RshInitADC::frequency is
	  * set to 250kHz, then divider = 500/250 = 2 will be applyed to external frequency 
	  * signal, producing 150/2 = 75kHz sample rate.
	  * 
	  * \~russian
	  * \brief
	  * АЦП может тактироваться из внешнего источника.
	  * 
	  * Чтобы включить эту возможность, нужно установить бит RshInitADC::FrequencyExternal
	  * в поле RshInitADC::startType структуры инициализации. Можно комбинировать
	  * этот режим (используя логическое ИЛИ) с другими флагами, например RshInitADC::Timer,
	  * RshInitADC::Internal.\n
	  * Требования к сигналу (амплитуда, скважность, полярность и пр.) описаны
	  * в руководстве пользователя для каждого конкретного устройства.
	  * 
	  * \remarks
	  * При использовании данной возможности, поле RshInitADC::frequency структуры 
	  * инициализации все еще актуально (по крайней мере, для большинства устройств),
	  * т.к. заданная в нем частота используется для вычисления значения делителя частоты.\n
	  * Например, если максимальная частота дискретизации устройства составляет 500кГц,
	  * в качестве внешней тактовой частоты используется сигнал с частотой 150кГц, 
	  * а в поле RshInitADC::frequency задана частота 250кГц, при оцифровке будет использовано
	  * значение делителя частоты равное 500/250 = 2. Таким образом, получим, что реальная частота
	  * дискретизации будет равна 150/2 = 75кГц.
	  * 
	  */
	 RSH_CAPS_DEVICE_EXTERNAL_FREQUENCY = 48,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Sampling rate can be changed after trigger event.
	  * 
	  * If this feature is available, one can use two
	  * different sampling rates for "prehistory" and "data"
	  * parts of the buffer. History sampling rate has two fixed values F1 = Fmax
	 * and F2 = Fmax/8. See device documentation for more details.	  
	  * One can turn this feature on using RshInitMemory::FrequencySwitchToMaximum 
	  * or RshInitMemory::FrequencySwitchToMinimum flag
	  * in RshInitMemory::controlSynchro field of initialization structure. 
	  * 
	  * \see
	  * RSH_CAPS_DEVICE_PREHISTORY | \link page_Synchronization Synchronization\endlink
	  * 
	  * \~russian
	  * \brief
	  * Доступна возможность переключения частоты дискретизации после получения события синхронизации.
	  * 
	  * Если доступна данная возможность, можно использовать две разные частоты
	  * для "предыстории" и "истории" данных в буфере. Частота предыстории задается как обычно 
	  * (поле <b>frequency</b> структуры инициализации), а частота истории может быть переключена либо
	  * на максимальную для данного устройства частоту (Fmax), либо на частоту Fmax/8.\n
	  * Включить этот режим работы можно, используя флаги RshInitMemory::FrequencySwitchToMinimum
	  * и RshInitMemory::FrequencySwitchToMaximum в поле RshInitMemory::controlSynchro
	  * структуры инициализации RshInitMemory.
	  * 	
	  * \see
	  *  RSH_CAPS_DEVICE_PREHISTORY | \link page_Synchronization Синхронизация\endlink
	  */
	 RSH_CAPS_DEVICE_FREQUENCY_SWITCH_PREHISTORY = 49,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * One can select what channel (channels) will be used in double (quadro) frequency mode.
	  * 
	  * If this feature is available, one can specify which channel (or channels) will be used
	  * when double frequency mode is activated. If not, zero channel (or even channels if there
	  * are more than two of them) will always selected for double frequency mode.
	  * Channel selection is performed using standart RshChannel::Used flag in
	  * RshInitMemory::channels list.
	  * 
	  * \remarks
	  * This feature is relevant for quadro frequency too, one (obvious) except is that
	  * one can select only one channel from every four.
	  * 
	  * \see
	  * RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE | \link IRshDevice_DoubleFreqMode_EN.cpp Init parameters example\endlink
	  * 
	  * \~russian
	  * \brief
	  * Можно выбрать канал (каналы), который будут использоваться в режиме удвоения (учетверения) частоты.
	  * 
	  * Если доступна данная возможность, можно указать, какой канал (или каналы) будет использоваться
	  * в режиме удвоения частоты. По умолчанию, всегда используется нулевой канал (или четные каналы,
	  * если их количество больше двух). Выбор каналов осуществляется с помощью стандартного флага
	  * RshChannel::Used в списке RshInitMemory::channels структуры инициализации.
	  * 
	  * \remarks
	  * Данная возможность также актуальна и для режима учетверения, за исключением того, что можно
	  * выбрать один канал из каждых четырех, а не два, как в режиме удвоения.
	  * 
	  * \see
	  * RSH_CAPS_DEVICE_DOUBLE_FREQUENCY_MODE | \link IRshDevice_DoubleFreqMode_RU.cpp Пример задания параметров\endlink
	  */
	 RSH_CAPS_DEVICE_FREE_CHANNEL_SELECT_IN_EXT_MODE = 50,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Device can be programmably configure to acquire data in unipolar/ bipolar mode.
	  * 
	  * Devices work in unipolar mode by default.
	  * One need set RshInitDMA::DiffMode flag of RshInitDMA::control field to set
	  * device in bipolar mode.
	  * 
	  * \remarks
	  * Channels number will be divided by 2, and input lines for analog channels
	  * must be connected according user manual.
	  * 
	  * \see
	  * RshInitDMA
	  * 
	  * \~russian
	  * \brief
	  * Доступна возможность программно переключаться между однополюсным/дифференциальным режимом.
	  * 
	  * По умолчанию, устроства работают в однополюсном режиме. Чтобы задействовать 
	  * дифференциальный режим работы, нужно установить флаг RshInitDMA::DiffMode
	  * в поле RshInitDMA::control структуры инициализации.
	  * 
	  * \remarks
	  * При включении дифференциального режима количество каналов становится меньше в два раза,
	  * так как оцифровывается разностное напряжение двух входов.
	  * Кроме того, требуется выполнить подключение сигналов в соответствии со схемой
	  * подключения дифференциальных входов согласно руководству пользователя.
	  * 
	  * \see
	  * RshInitDMA
	  */
	 RSH_CAPS_DEVICE_DIFFERENTIAL_INPUT_MODE = 51,	


	 /*! 	  
	  * 
	  * \~english
	  * \brief
	  * There is a flash memory unit onboard for device information.
	  * 
	  * This flag indicates that device has onboard flash memory which is used 
	  * for additional information such as serial number. 
	  *
	  * \~russian
	  * \brief
	  * Устройство имеет энергонезависимую память (флэш), которая содержит дополнительную информацию.
	  * 
	  * Наличие данного флага означает, что устройство располагает дополнительной памятью, в которую
	  * может быть записан заводской номер платы, различные настроечные коэффициенты и другая 
	  * информация. Как правило, информация записывается на этапе настройки и в процессе эксплуатации
	  * доступна только для чтения.
	  *
	  */
 	 RSH_CAPS_DEVICE_FLASH_INFO_ONBOARD = 52,


	 /*!
	  * 
	  * \~english
	  * \brief
	  * Device have GPS module
	  * 
	  * One can obtain GPS data using IRshDevice::Get() method
	  * with ::RSH_GET_DEVICE_GPS_DATA or ::RSH_GET_DEVICE_GPS_DATA_UTF16 constants.
	  * 
	  * \remarks
	  * Format of GPS sentance string is device (and module) dependend,
	  * see device manual for details.
	  * 
	  * \~russian
	  * \brief
	  * Устройство имеет GPS-модуль
	  * 
	  * Получить данные GPS можно, вызвав метод IRshDevice::Get()
	  * с параметром ::RSH_GET_DEVICE_GPS_DATA или ::RSH_GET_DEVICE_GPS_DATA_UTF16.
	  * 
	  * \remarks
	  * Формат строки с данными зависит от устройства и используемого 
	  * модуля, все подробности приведены в описании устройства.
	  * 
	  */
	 RSH_CAPS_DEVICE_GPS_MODULE_INSTALLED = 53,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Device supports automatic restart
	  * 
	  * Device can be proggrammed in such a way that it
	  * will automatically restart data acquisition using
	  * internal timing interval. This interval can 
	  * be set using IRshDevice::Get() method with
	  * ::RSH_GET_DEVICE_AUTO_START_INTERVAL_SET parameter.\n
	  * 
	  * \remarks
	  * This mode is not continuous mode. Data buffers obtained
	  * are not continuous. The only difference from "Start-Stop"
	  * mode is that one do not have to start data acquisition for
	  * each buffer - device hardware will do it.\n
	  * From programming point of view, however, work process look 
	  * much like work in continuous mode - one have to init device,
	  * start it, and then wait to interrupt events (one for each bufer)
	  * infinitely, until IRshDevice::Stop() method is called.
	  * 
	  * \~russian
	  * \brief
	  * Устройство поддерживает режим автоматического запуска
	  * 
	  * Устройство может быть запрограммировано таким образом, что
	  * сбор данных будет запускаться автоматически, с заданным интервалом.
	  * Интервал запуска можно задать, используя метод IRshDevice::Get()
	  * с параметром ::RSH_GET_DEVICE_AUTO_START_INTERVAL_SET.
	  * 
	  * \remarks
	  * Данный режим работы - это \b НЕ непрерывный режим. Каждый блок данных, 
	  * получаемый от устройства, независим и не связан с предыдущим.
	  * Единственное отличие от стандартного режима "Старт-Стоп" в том, что
	  * не нужно запускать сбор каждый раз - устройство будет делать это 
	  * автоматически.\n
	  * С программной точки зрения, однако, процесс работы с устройством
	  * выглядит очень похожим на работу в непрерывном режиме - нужно
	  * задать параметры сбора данных (в том числе и интервал опроса), запустить
	  * сбор и затем получать данные длительное время, ожидая событие готовности
	  * для каждого собранного буфера. Процесс сбора данных может быть остановлен
	  * вызовом метода IRshDevice::Stop().
	  *
	  * 
	  */
	 RSH_CAPS_DEVICE_AUTO_START_MODE = 54,


	 /*!
	  * 
	  * \~english
	  * \brief
	  * Digital line data can be contained within analog data.
	  * 
	  * Device digital lines data (input digital port for ADC devices) can
	  * be placed in last significant bits of analog data.
	  * 
	  * \remarks
	  * Use special IRshDevice::GetData() flag ( ::RSH_DATA_MODE_CONTAIN_DIGITAL_INPUT)
	  * to transfer digital port data with analog data (for ADC devices) or to output
	  * digital lines (for GSPF devices). See ::RSH_DATA_MODE_CONTAIN_DIGITAL_INPUT for details.
	  * 
	  * \see
	  * RSH_DATA_MODE_CONTAIN_DIGITAL_INPUT
	  * 
	  * \~russian
	  * \brief
	  * Цифровые данные могут передаваться вместе с аналоговыми.
	  * 
	  * Устройство имеет возможность получать данные со своего цифрового порта или
	  * входных цифровых линий вместе с аналоговыми данными. Цифровые данные помещаются
	  * в несколько младших битов каждого слова данных.
	  * 
	  * \remarks
	  * Используется специальный флаг  ( ::RSH_DATA_MODE_CONTAIN_DIGITAL_INPUT) при вызове
	  * метода IRshDevice::GetData() для того, чтобы цифровые данные не были отмаскированы.
	  * См. ::RSH_DATA_MODE_CONTAIN_DIGITAL_INPUT для более подробного описания.
	  * 
	  * \see
	  * RSH_DATA_MODE_CONTAIN_DIGITAL_INPUT
	  * 
	  */
	 RSH_CAPS_DEVICE_DIGITAL_PORT_DATA_WITH_ANALOG_DATA = 55,

	 /*! 	  
	  * 
	  * \~english
	  * \brief
	  * Abstraction library contains methods that allow automatic calibration perform.
	  * 
	  * This flag indicates that device can be calibrated programmably,
	  * with use of external signal generation and measurement devices.\n
	  * Do not confuse with ::RSH_CAPS_DEVICE_AUTO_CALIBRATION (automatic
	  * calibration of device during runtime). This flag is for preproduction
	  * process only.
	  * 
	  * \~russian
	  * \brief
	  * Библиотека абстракции содержит методы для проведения автоматической настройки и калибровки устройства.
	  * 
	  * Наличие данного флага означает, что устройство может быть откалибровано (настройка внутренних
	  * коэффициентов) программно, с использованием внешнего источника сигнала
	  * и эталонного измерительного прибора.\n
	  * Данная возможность не связана с наличием флага ::RSH_CAPS_DEVICE_AUTO_CALIBRATION
	  * (автоматическая подстройка нуля в процессе работы). Режим автоматической 
	  * калибровки используется только при производстве и ремонте устройств.
	  * 
	  */
	 RSH_CAPS_SOFT_CALIBRATION_IS_AVAILABLE = 512,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Abstraction library contains methods that allow data acquisition in "start-stop" mode.
	  * 
	  * Device can be programmed to acquire data in "Start-Stop"
	  * mode. In this mode only one data block of predefined size
	  * will be acquired and transfered to user. This is most 
	  * common scenario of work.
	  * 
	  * \see
	  * RshInitDMA | RshInitMemory
	  * 
	  * \~russian
	  * \brief
	  * Библиотека абстракции содержит методы для осуществления сбора данных в режиме "старт-стоп".
	  * 
	  * Устройство может быть запрограммировано для сбора данных
	  * в режиме "Старт-Стоп". В этом режиме происходит одиночный
	  * запуск устройства, сбор одного блока данных с заданными 
	  * параметрами (частота дискретизации, размер и т.д.) и остановка
	  * устройства. Этот сценарий работы является наибоелее распространенным.
	  * 
	  * \see
	  * RshInitDMA | RshInitMemory
	  *
	  */
	 RSH_CAPS_SOFT_GATHERING_IS_AVAILABLE = 513,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Abstraction library contains methods that allow continious data acquisition.
	  * 
	  * In this mode device's ADC is started once, and then acquire
	  * data continiously, generating interrupt each time
	  * data block is ready. This process can be active long
	  * time, and stops only when IRshDevice::Stop() method is called.
	  * 
	  * \remarks
	  * Due to brandwidth limitation for computer interfaces,
	  * this mode only available for low frequency (10MHz maximum) devices
	  * 
	  * \see
	  * RshInitDMA
	  * 
	  * \~russian
	  * \brief
	  * Библиотека абстракции содержит методы для осуществления сбора данных в непрерывном режиме
	  * 
	  * В этом режиме АЦП запускается один раз, и затем оцифровывает
	  * входные сигналы непрерывно, генерируя прерывание каждый раз, 
	  * когда готова очередная порция данных. Этот процесс может продолжаться
	  * долгое время (теоретически, бесконечно) и будет остановлен только
	  * при вызове метода IRshDevice::Stop().
	  * 
	  * \remarks
	  * Из-за аппаратных ограничений по пропускной способности различных
	  * интерфейсов, этот режим доступен только для относительно
	  * низкочастотных устройств (до 10МГц).
	  * 
	  * \see
	  * RshInitDMA
	  *
	  */
	 RSH_CAPS_SOFT_PGATHERING_IS_AVAILABLE = 514,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Abstraction library contains methods that allow control of digital port.
	  * 
	  * Using IRshDevice::Init() method and RshInitPort structure
	  * one can write and read data from digital port.
	  * Information about digital port can be obtained using
	  * IRshDevice::Get() method with ::RSH_GET_DEVICE_PORT_INFO parameter.	
	  * 
	  * \see
	  * RshInitPort | RshInitPort | RshPortInfo
	  * 
	  * \~russian
	  * \brief
	  * Библиотека абстракции содержит методы для управления цифровым портом.
	  * 
	  * Используя метод IRshDevice::Init() и структуру инициализации
	  * RshInitPort можно читать и записывать данные в цифровой порт устройства.
	  * Получить информацию о цифровом порте можно, используя метод IRshDevice::Get()
	  * с параметром ::RSH_GET_DEVICE_PORT_INFO.
	  * 
	  * \see
	  * RshInitPort | RshInitPort | RshPortInfo
	  *
	  */
	 RSH_CAPS_SOFT_DIGITAL_PORT_IS_AVAILABLE = 515,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Abstraction library contains methods that allow signal generation.
	  * 
	  * Using RshInitGSPF stucture one can set generation parameters,
	  * and then send data buffer to device using IRshDevice::GetData() method.
	  * 
	  * \see
	  * RshInitGSPF
	  * 
	  * \~russian
	  * \brief
	  * Библиотека абстракции содержит методы для генерации сигнала.
	  * 
	  * Используя структуру инициализации RshInitGSPF можно задать параметры
	  * генерации сигнала, и затем отправить сформированный буфер данных
	  * с сигналом в устройство, используя метод IRshDevice::GetData().
	  * 
	  * \see
	  * RshInitGSPF
	  *
	  */
	 RSH_CAPS_SOFT_GENERATION_IS_AVAILABLE = 516,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * RshInitMemory initialization structure is supported by abstraction library.
	  * 
	  * One can use this structure as parameter for IRshDevice::Init() method.	 
	  * 
	  * \remarks
	  * This structure is usually used for high frequency devices with internal memory installed.
	  *
	  * \see
	  * RshInitMemory | IRshDevice::Init()
	  * 
	  * \~russian
	  * \brief
	  * Структура инициализации RshInitMemory поддерживается библиотекой абстракции.
	  * 
	  * Использовать эту структуру для передачи параметров можно
	  * в методе IRshDevice::Init().
	  *
	  * \remarks
	  * Данная структура обычно используется для высокочастотных устройств сбора
	  * данных с установленной собственной памятью.
	  *
	  * \see
	  * RshInitMemory | IRshDevice::Init()
	  */
	 RSH_CAPS_SOFT_INIT_MEMORY = 517,

	  /*!
	  * 
	  * \~english
	  * \brief
	  * RshInitDMA initialization structure is supported by abstraction library.
	  * 
	  * One can use this structure as parameter for IRshDevice::Init() method.	 
	  * 
	  * \remarks
	  * This structure is usually used for low frequency devices.
	  *
	  * \see
	  * RshInitDMA | IRshDevice::Init()
	  * 
	  * \~russian
	  * \brief
	  * Структура инициализации RshInitDMA поддерживается библиотекой абстракции.
	  * 
	  * Использовать эту структуру для передачи параметров можно
	  * в методе IRshDevice::Init().
	  * 
	  * \remarks
	  * Данная структура обычно используется для низкочастотных устройств сбора
	  * данных. Используя эту структуру, можно организовать сбор данных в непрерывном режиме.
	  * 
	  * \see
	  * RshInitDMA | IRshDevice::Init()
	  */
	 RSH_CAPS_SOFT_INIT_DMA = 518,

	  /*!
	  * 
	  * \~english
	  * \brief
	  * RshInitGSPF initialization structure is supported by abstraction library.
	  * 
	  * One can use this structure as parameter for IRshDevice::Init() method.	 
	  * 
	  * \remarks
	  * This structure is used for programming GSPF family devices.
	  *
	  * \see
	  * RshInitGSPF | IRshDevice::Init()
	  * 
	  * \~russian
	  * \brief
	  * Структура инициализации RshInitGSPF поддерживается библиотекой абстракции.
	  * 
	  * Использовать эту структуру для передачи параметров можно
	  * в методе IRshDevice::Init().
	  *
	  * \remarks
	  * Данная структура используется для программирования устройств
	  * серии ГСПФ.
	  *
	  * \see
	  * RshInitGSPF | IRshDevice::Init()
	  */
	 RSH_CAPS_SOFT_INIT_GSPF = 519,
	 
	  /*!
	  * 
	  * \~english
	  * \brief
	  * RshInitVoltmeter initialization structure is supported by abstraction library.
	  * 
	  * One can use this structure as parameter for IRshDevice::Init() method.	 
	  * 
	  * \remarks
	  * This structure is used for programming VISA-based digital voltmeters.
	  *
	  * \see
	  * RshInitVoltmeter | IRshDevice::Init()
	  * 
	  * \~russian
	  * \brief
	  * Структура инициализации RshInitVoltmeter поддерживается библиотекой абстракции.
	  * 
	  * Использовать эту структуру для передачи параметров можно
	  * в методе IRshDevice::Init().
	  *
	  * \remarks
	  * Данная структура используется для программирования цифровых
	  * вольтметров с интерфейсом VISA.
	  *
	  * \see
	  * RshInitVoltmeter | IRshDevice::Init()
	  */
	 RSH_CAPS_SOFT_INIT_VOLTMETER = 520,

	  /*!
	  * 
	  * \~english
	  * \brief
	  * RshInitTimer initialization structure is supported by abstraction library.
	  * 
	  * One can use this structure as parameter for IRshDevice::Init() method.	 
	  * 
	  * \remarks
	  * This structure is used for direct control of counter timer.
	  *
	  * \see
	  * RshInitTimer | IRshDevice::Init() | RSH_CAPS_DEVICE_TIMER_8254
	  * 
	  * \~russian
	  * \brief
	  * Структура инициализации RshInitTimer поддерживается библиотекой абстракции.
	  * 
	  * Использовать эту структуру для передачи параметров можно
	  * в методе IRshDevice::Init().
	  *
	  * \remarks
	  * Данная структура используется для прямого управления
	  * программируемым счетчиком-таймером устройства.
	  *
	  * \see
	  * RshInitTimer | IRshDevice::Init() | RSH_CAPS_DEVICE_TIMER_8254
	  */
	 RSH_CAPS_SOFT_INIT_TIMER = 521,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Abstraction library contains methods that allow use of software stoboscope.
	  * 
	  * Stroboscope only work with synchronization and periodic signals.
	  * Obtaining information about precise time of synchronization event
	  * and interpolate several signal realisation to one output signal
	  * with better resolution in time domain.	 
	  * 
	  * \~russian
	  * \brief
	  * Библиотека абстракции содержит методы для реализация программного стробоскопа.
	  * 
	  * Стробоскопирование работает только для периодических сигналов, 
	  * и при включенной синхронизации. Получая информацию о точном моменте срабатывания
	  * синхронизации, можно из нескольких реализации периодического сигнала
	  * построить одну, но с более высоким временным разрешением.
	  *	 
	  */
	 RSH_CAPS_SOFT_STROBOSCOPE = 522,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * RshInitDAC initialization structure is supported by abstraction library.
	  * 
	  * One can use this structure as parameter for IRshDevice::Init() method.	 
	  * 
	  * \remarks
	  * This structure is used for DAC control
	  *
	  * \see
	  * RshInitDAC | IRshDevice::Init()
	  * 
	  * \~russian
	  * \brief
	  * Структура инициализации RshInitDAC поддерживается библиотекой абстракции.
	  * 
	  * Использовать эту структуру для передачи параметров можно
	  * в методе IRshDevice::Init().
	  *
	  * \remarks
	  * Данная структура используется для управления ЦАПами.
	  *
	  * \see
	  * RshInitDAC | IRshDevice::Init()
	  */
	 RSH_CAPS_SOFT_INIT_DAC = 523,

	  /*!
	  * 
	  * \~english
	  * \brief
	  * RshInitPort initialization structure is supported by abstraction library.
	  * 
	  * One can use this structure as parameter for IRshDevice::Init() method.	 
	  * 
	  * \remarks
	  * This structure is used for digital port access
	  *
	  * \see
	  * RshInitPort | IRshDevice::Init()
	  * 
	  * \~russian
	  * \brief
	  * Структура инициализации RshInitPort поддерживается библиотекой абстракции.
	  * 
	  * Использовать эту структуру для передачи параметров можно
	  * в методе IRshDevice::Init().
	  *
	  * \remarks
	  * Данная структура используется для управления цифровым портом.
	  *
	  * \see
	  * RshInitPort | IRshDevice::Init()
	  */
	 RSH_CAPS_SOFT_INIT_PORT = 524,

	 /*!
	  * 
	  * \~english
	  * \brief
	  * Internal device parameters can be tuned using this abstraction library.
	  * 
	  * Special private set of methods and structures is used to change internal device
	  * parameters.
	  * Tuner is used only for initial device configuration and pre-sale preparation.
	  * 
	  * 
	  * \~russian
	  * \brief
	  * Внутренние настройки устройства могут быть изменены с использованием данной библиотеки абстракции.
	  * 
	  * Для изменения значений внутренних настроечных коэффициентов устройства используется
	  * специальный набор методов и структур, которые являются закрытыми.
	  * Тюнер используется только при первоначальной настройке и предпродажной подготовке устройства.
	  *
	  */
	 RSH_CAPS_SOFT_TUNER_MODE_IS_AVAILABLE = 525,


	 /*!
	  * \~english
	  * \brief
	  * Maximum number of values in RSH_CAPS enum.
	  * \~russian
	  * \brief
	  * Максимальное количество значений в перечислении RSH_CAPS.
	  */
	 RSH_CAPS_MAX = 1024
 } RSH_CAPS;
 
#endif //RSH_CONSTS_CAPS_CODES_H
  