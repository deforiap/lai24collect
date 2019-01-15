/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshConsts_GetCodes.h
 * \date 26.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * Get codes constants enum for Rsh SDK
 *
 * \~russian
 * \brief
 * Константы метода Get()для Rsh SDK
 *
 */
 
#ifndef RSH_CONSTS_GET_CODES_H
#define RSH_CONSTS_GET_CODES_H

#define _RSH_GROUP_GET_DELIMITER(value)    (  value << 16 )
#define	_RSH_GROUP_GET_BUFFER(value)       ( _RSH_GROUP_GET_DELIMITER(0x1) | ( value & 0xffff ) )
#define	_RSH_GROUP_GET_WAIT(value)         ( _RSH_GROUP_GET_DELIMITER(0x2) | ( value & 0xffff ) )
#define	_RSH_GROUP_GET_DEVICE(value)       ( _RSH_GROUP_GET_DELIMITER(0x3) | ( value & 0xffff ) )
#define	_RSH_GROUP_GET_SDK(value)          ( _RSH_GROUP_GET_DELIMITER(0x4) | ( value & 0xffff ) )
#define	_RSH_GROUP_GET_LIBRARY(value)      ( _RSH_GROUP_GET_DELIMITER(0x5) | ( value & 0xffff ) )
#define	_RSH_GROUP_GET_CORELIB(value)      ( _RSH_GROUP_GET_DELIMITER(0x6) | ( value & 0xffff ) )


/*!
 * 
 * \~english
 * \brief
 * Operation codes for IRshDevice::Get() method of IRshDevice (and some other) interface.
 * 
 * \remarks
 * Most of these codes are used to obtain data from device library,
 * but some of them are used to set device parameters. These codes
 * have _SET postfix.
 * 
 * \see
 * IRshDevice::Get().
 * 
 * \~russian
 * \brief
 * Коды операций для метода IRshDevice::Get() интерфейса IRshDevice (и некоторых других).
 * 
 * \remarks
 * Большинство этих кодов используются для получения различной информации
 * из библиотеки устройства, но некоторые из них служат для передачи информации
 * в библиотеку или для управления устройством. Такие коды имеют суффикс _SET.
 * 
 * \see
 * IRshDevice::Get().
 */
typedef enum
{
	/*!
	 * \~english
	 * \brief
	 * Check buffer ready event state.
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 * Obtained data: 1 - buffer ready event is signaled (data ready),
	 * 0 - buffer ready event is not signaled.
	 * If data acquisition process was started before IRshDevice::Get() call,
	 * one can check if data is ready or not using this code.	 
	 * 
	 * \remarks
	 * This code check only current state of buffer ready event,
	 * if you need create data wait routine better use
	 * ::RSH_GET_WAIT_BUFFER_READY_EVENT code instead.
	 *
	 * \see \link IRshDevice_Get_RSH_GET_BUFFER_READY_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Проверка готовности данных в случае одиночного преобразования.
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Полученные данные: 1 - было получено прерывание по готовности данных,
	 * 0 - прерывание не было получено.
	 * Если перед вызовом метода IRshDevice::Get() с данным кодом был запущен сбор данных,
	 * можно узнать, готова ли уже очередная порция данных.	
	 * 
	 * \remarks
	 * Данный код проверяет текущее (на момент вызова метода IRshDevice::Get()) состояние события,
	 * если нужно организовать цикл ожидания готовности данных, лучше воспользоваться
	 * кодом ::RSH_GET_WAIT_BUFFER_READY_EVENT.
	 *
	 * \see \link IRshDevice_Get_RSH_GET_BUFFER_READY_RU.cpp Пример использования \endlink
	 *
	 */
	RSH_GET_BUFFER_READY = _RSH_GROUP_GET_BUFFER(0x1), // 0x10000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Wait while data acquisition and transfer process will be finished.
	 * 
	 * <b>Data type</b>: [in] ::RSH_U32\n
	 * After starting data acquisition process, one can call IRshDevice::Get()
	 * with this parameter to start waiting data receive event. Second parameter
	 * of IRshDevice::Get() is timeout in ms. One can use ::RSH_INFINITE_WAIT_TIME
	 * for infinite waitng.
	 * 
	 * \remarks
	 * This method is analog of WinAPI WaitForSingleObject call, but
	 * realisation is crossplatform.
	 * 
	 * \warning Calling this method will lock caller thread until event signalled
	 * or timeout! If ::RSH_INFINITE_WAIT_TIME is used, the only way to unlock thread
	 * is call to IRshDevice::Stop() method from other thread.
	 *
	 * \see
	 * \link IRshDevice_Get_RSH_GET_WAIT_BUFFER_READY_EVENT_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Ожидание завершения процесса сбора и передачи данных.
	 * 
	 * <b>Тип данных</b>: [in] ::RSH_U32\n
	 * После запуска процесса сбора данных, можно вызвать метод IRshDevice::Get()
	 * с этим параметром и ожидать события готовности данных. Второй параметр в методе
	 * IRshDevice::Get() задает максимальное время ожидания (таймаут) в мс.
	 * Можно использовать константу ::RSH_INFINITE_WAIT_TIME для бесконечного ожидания.
	 * 
	 * \remarks
	 * По сути, данный метод аналогичен вызову функции WaitForSingleObject
	 * из WinAPI, но его реализация кроссплатформенная.
	 *
	 * \warning Вызов данного метода блокирует вызывающий поток до тех пор,
	 * пока не будет получено событие готовности данных, или таймаут! Если
	 * используется константа ::RSH_INFINITE_WAIT_TIME, единственный способ 
	 * отменить ожидание и разблокировать поток - это вызов метода IRshDevice::Stop().
	 * 
	 * \see
	 * \link IRshDevice_Get_RSH_GET_WAIT_BUFFER_READY_EVENT_RU.cpp Пример использования \endlink
	 * 
	 */
	RSH_GET_WAIT_BUFFER_READY_EVENT = _RSH_GROUP_GET_WAIT(0x1), // 0x20000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Wait for continious data acquisition process to finish.
	 * 
	 * <b>Data type</b>: [in] ::RSH_U32\n
	 * After calling IRshDevice::Stop() method continious data
	 * acquisition won't stop immidiately. Last data block can be transfered
	 * before process termination. Using this constant one can get sure
	 * that data acquisition process completely stopped before do anything else.\n
	 * Second parameter of IRshDevice::Get() is timeout in ms.
	 * One can use ::RSH_INFINITE_WAIT_TIME for infinite waitng.
	 * 
	 * \remarks
	 * In most cases you can avoid calling this method, but
	 * it can be extremely useful for thread synchronization
	 * in complex applications.
	 * 
	 * \see
	 * \link IRshDevice_Get_RSH_GET_WAIT_GATHERING_COMPLETE_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Ожидание завершения процесса непрервыного сбора данных.
	 * 
	 * <b>Тип данных</b>: [in] ::RSH_U32\n
	 * После вызова метода IRshDevice::Stop() при работе в непрерывном режиме
	 * может пройти какое-то время до того момента, когда сбор будет
	 * фактически остановлен. Используя данную константу можно быть уверенным
	 * в том, что процесс сбора данных полностью остановлен, прежде чем
	 * выполнять какие-либо другие действия.\n
	 * Второй параметр в методе IRshDevice::Get() задает максимальное время
	 * ожидания (таймаут) в мс.Можно использовать константу ::RSH_INFINITE_WAIT_TIME
	 * для бесконечного ожидания.
	 * 
	 * \remarks
	 * В большинстве случаев можно обойтись без вызова данного метода, но
	 * он может быть очень полезен для синхронизации потоков в сложных приложениях.
	 * 
	 * \see
	 * \link IRshDevice_Get_RSH_GET_WAIT_GATHERING_COMPLETE_RU.cpp Пример использования \endlink
	 * 
	 */
	RSH_GET_WAIT_GATHERING_COMPLETE = _RSH_GROUP_GET_WAIT(0x2), // 0x20000
	
	/*!
	 * 
	 * \~english
	 * \brief
	 * Nanosecond delay
	 * 
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 * Nanosecond delay, usually implemented by using PLX chip high precision timers.
	 * Not implemented for all devices and libraries!
	 *
	 * \~russian
	 * \brief
	 * Наносекундная задержка	
	 * 
	 * <b>Тип данных</b>: [in] ::RSH_U32\n
	 * Наносекундная задержка, реализованная средствами высокоточного таймера чипа PLX.
	 * Доступно не для всех устройств и библиотек!
	 * 
	 */
	RSH_GET_WAIT_NANO_DELAY = _RSH_GROUP_GET_WAIT(0x3), // 0x20000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Wait for INT_0 interrupt
	 * 
	 * <b>Data type</b>: [in] NULL\n
	 * \deprecated Can be moved to private SDK
	 *
	 * \~russian
	 * \brief
	 * Ожидание срабатывания прерывания INT_0
	 *
	 *  <b>Data type</b>: [in] NULL\n
	 * \deprecated Возможен перенос в закрытую часть SDK
	 * 
	 */
	RSH_GET_WAIT_INTERRUPT0 = _RSH_GROUP_GET_WAIT(0x4), // 0x20000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Wait for INT_1 interrupt
	 * 
	 * <b>Data type</b>: [in] NULL\n
	 * \deprecated Can be moved to private SDK
	 *
	 * \~russian
	 * \brief
	 * Ожидание срабатывания прерывания INT_1
	 *
	 *  <b>Data type</b>: [in] NULL\n
	 * \deprecated Возможен перенос в закрытую часть SDK
	 * 
	 */
	RSH_GET_WAIT_INTERRUPT1 = _RSH_GROUP_GET_WAIT(0x5), // 0x20000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Get product ID of the device.
	 * 
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 * Each peace of hardware connected to PC has
	 * its unique (for device class) vendor ID and 
	 * device ID numbers. Using this numbers operation
	 * system can chose driver to use to work with
	 * this device.\n
	 * Using IRshDevice::Get() method with this constant
	 * one can obtain product id of the device.
	 *
	 * \see
	 * \link IRshDevice_Get_RSH_GET_DEVICE_INFORMATION_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Получение идентификационного кода устройства.
	 * 
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Каждое устройство расширения, подключаемое к компьютеру,
	 * имеет уникальный (для данной модели устройства) код устройства (product ID или PID)
	 * и код производителя (vendor ID или VID). Операционная система
	 * использует данные коды для идентифиакции устройства и выбора драйвера
	 * для него.\n
	 * Используя метод IRshDevice::Get() с данной константой, можно
	 * получить код оборудования для устройства.	
	 * 
	 * \see
	 * \link IRshDevice_Get_RSH_GET_DEVICE_INFORMATION_RU.cpp Пример использования \endlink
	 * 
	 */
	RSH_GET_DEVICE_PID = _RSH_GROUP_GET_DEVICE(0x1), // 0x30000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Get vendor ID of the device.
	 * 
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 * Each peace of hardware connected to PC has
	 * its unique (for device class) vendor ID and 
	 * device ID numbers. Using this numbers operation
	 * system can chose driver to use to work with
	 * this device.\n
	 * Using IRshDevice::Get() method with this constant
	 * one can obtain vendor id of the device.
	 *
	 * \see
	 * \link IRshDevice_Get_RSH_GET_DEVICE_INFORMATION_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Получение идентификационного кода производителя устройства.
	 * 
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Каждое устройство расширения, подключаемое к компьютеру,
	 * имеет уникальный (для данной модели устройства) код устройства (product ID или PID)
	 * и код производителя (vendor ID или VID). Операционная система
	 * использует данные коды для идентифиакции устройства и выбора драйвера
	 * для него.\n
	 * Используя метод IRshDevice::Get() с данной константой, можно
	 * получить код производителя устройства.	
	 * 
	 * \see
	 * \link IRshDevice_Get_RSH_GET_DEVICE_INFORMATION_RU.cpp Пример использования \endlink
	 * 
	 */
	RSH_GET_DEVICE_VID = _RSH_GROUP_GET_DEVICE(0x2), // 0x30000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Get long name of the abatraction library.
	 * 
	 * <b>Data type</b>: [out] ::RSH_S8P\n
	 * Obtain string constant with library name.
	 * Pointer to internal string constant will be returned,
	 * no need to allocate memory in user application.	
	 * 
	 * \see
	 * \link IRshDevice_Get_RSH_GET_DEVICE_INFORMATION_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Получение полного имени библиотеки абстракции.
	 * 
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Получение указателя на строковую константу с именем
	 * библиотеки абстракции. Так как возвращается указатель,
	 * выделять память под строку дополнительно не нужно.
	 * 
	 * \see
	 * \link IRshDevice_Get_RSH_GET_DEVICE_INFORMATION_RU.cpp Пример использования \endlink
	 * 
	 */
	RSH_GET_DEVICE_NAME_VERBOSE = _RSH_GROUP_GET_DEVICE(0x3), // 0x30000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Unicode version of ::RSH_GET_DEVICE_NAME_VERBOSE.
	 * 
	 * <b>Data type</b>: [out] ::RSH_U16P\n
	 * Obtain string constant with library name in UTF-16 format.
	 *
	 * \~russian
	 * \brief
	 * Аналог ::RSH_GET_DEVICE_NAME_VERBOSE в формате юникод.
	 * 
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Получение строки с названием библиотеки в формате UTF-16.
	 * 
	 */
	RSH_GET_DEVICE_NAME_VERBOSE_UTF16 = _RSH_GROUP_GET_DEVICE(0x4), // 0x30000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Check for device and software feature support.
	 * 
	 * <b>Data type</b>: [in] ::RSH_U32\n
	 * Using this constant one can check if the device
	 * and abstraction library support various hardware
	 * and software features. Feature code must be passed
	 * as second parameter of IRshDevice::Get() method.
	 * 
	 * \remarks
	 * Full list of features one can check with detailed description
	 * can be found \link RSH_CAPS here \endlink.
	 * 
	 * \see
	 * \link IRshDevice_Get_RSH_GET_DEVICE_IS_CAPABLE_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Определение возможностей устройства и библиотеки.
	 * 
	 * <b>Тип данных</b>: [in] ::RSH_U32\n
	 * Используя данную константу, можно проверить, поддерживает
	 * ли устройство и библиотека различные аппаратные и программные
	 * режимы работы и возможности. Код свойства, поддержку которого 
	 * нужно проверить, должен передаваться в качестве второго параметра
	 * метода IRshDevice::Get().
	 * 
	 * \remarks
	 * Полный список свойств можно посмотреть \link RSH_CAPS здесь\endlink.
	 * 
	 * \see
	 * \link IRshDevice_Get_RSH_GET_DEVICE_IS_CAPABLE_RU.cpp Пример использования \endlink
	 * 
	 */
	RSH_GET_DEVICE_IS_CAPABLE = _RSH_GROUP_GET_DEVICE(0x5), // 0x30000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Get base address list.
	 * 
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 * When there are several devices of one type
	 * connected to PC (or boards installed), these
	 * devices are enumerated, and each device have
	 * its unique index (1 based).\n
	 * Using this constant, one can get such a list. 
	 * 
	 * \remarks
	 * Indexes obtained through this IRshDevice::Get()
	 * call can be used in IRshDevice::Connect() method.
	 * 
	 * \see
	 * IRshDevice::Connect() | \link IRshDevice_Get_RSH_GET_DEVICE_BASE_LIST_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Получение списка допустимых базовых адресов.
	 * 
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Если в системе установлено несколько устройств 
	 * одного типа, для выбора конкретного устройства
	 * используется базовый адрес. Базовые адреса выдаются
	 * операционной системой, и зависят от слота (порта)
	 * подключения, а также порядка включения устройств.\n
	 * Используя данную константу, можно получить этот список
	 * в виде массива целых чисел.
	 * 
	 * \remarks
	 * Полученные базовые адреса можно использовать
	 * в методе IRshDevice::Connect().
	 * 
	 * \see
	 * IRshDevice::Connect() | \link IRshDevice_Get_RSH_GET_DEVICE_BASE_LIST_RU.cpp Пример использования \endlink
	 * 
	 */
	RSH_GET_DEVICE_BASE_LIST = _RSH_GROUP_GET_DEVICE(0x6), // 0x30000

	/*!
	 * 
	 * \~english
	 * \brief
	 * Get device list with additional information.
	 * 
	 * <b>Data type</b>: [out] ::RSH_BUFFER_DEVICE_BASE_INFO\n
	 * This constant is used for the same purpose as
	 * ::RSH_GET_DEVICE_BASE_LIST. But returned list
	 * is not simple base address array - it is list of RshDeviceBaseInfo
	 * structures. RshDeviceBaseInfo contains extended information about device,
	 * such as PCI slot used, VID and PID, serial number.	
	 * 
	 * \see
	 * RshDeviceBaseInfo | \link IRshDevice_Get_RSH_GET_DEVICE_BASE_LIST_EXT_EN.cpp Usage example \endlink
	 * 
	 * \~russian
	 * \brief
	 * Получение списка устройств с дополнительной информацией.
	 * 
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_DEVICE_BASE_INFO\n
	 * Данная константа используется для тех же целей, что и 
	 * ::RSH_GET_DEVICE_BASE_LIST. Но, в отличие от нее, возвращается
	 * не просто список допустимых базовых адресов, а массив структур
	 * RshDeviceBaseInfo. Структура RshDeviceBaseInfo содержит, помимо
	 * базового адреса, дополнительную информацию о подключенном устройстве -
	 * используемый PCI слот, коды оборудования и производителя, ревизию,
	 * заводской номер.	 
	 * 
	 * \see
	 * RshDeviceBaseInfo | \link IRshDevice_Get_RSH_GET_DEVICE_BASE_LIST_EXT_RU.cpp Пример использования \endlink
	 * 
	 */
	RSH_GET_DEVICE_BASE_LIST_EXT = _RSH_GROUP_GET_DEVICE(0x7), // 0x30000

	/*!
	 * \~english
	 * \brief
	 * Minimum value of device sample rate
	 *
	 * <b>Data type</b>: [out] ::RSH_DOUBLE\n
	 *
	 * \~russian
	 * \brief
	 * Минимально возможная частота дискретизации
	 *
	 * <b>Тип данных</b>: [out] ::RSH_DOUBLE\n
	 * Минимально возможная частота дискретизации для устройства.
	 */
	RSH_GET_DEVICE_MIN_FREQUENCY = _RSH_GROUP_GET_DEVICE(0x8), // 0x30000 

	/*!
	 * \~english
	 * \brief
	 * Maximum value of device sample rate
	 *
	 * <b>Data type</b>: [out] ::RSH_DOUBLE\n
	 *
	 * \~russian
	 * \brief
	 * Максимально возможная частота дискретизации
	 *
	 * <b>Тип данных</b>: [out] ::RSH_DOUBLE\n
	 * Максимально возможная частота дискретизации для устройства.
	 */

	RSH_GET_DEVICE_MAX_FREQUENCY = _RSH_GROUP_GET_DEVICE(0x9), // 0x30000

	/*!
	 * \~english
	 * \brief
	 * Minimum amplitude value in LSB
	 *
	 * <b>Data type</b>: [out] ::RSH_S32\n
	 *
	 * \~russian
	 * \brief
	 * Минимальное значение амплитуды (МЗР)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S32\n
	 * Минимальное значение амплитуды (МЗР)
	 */
	RSH_GET_DEVICE_MIN_AMP_LSB = _RSH_GROUP_GET_DEVICE(0xA), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * Maximum amplitude value in LSB
	 *
	 * <b>Data type</b>: [out] ::RSH_S32\n
	 *
	 * \~russian
	 * \brief
	 * Максимальное значение амплитуды (МЗР)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S32\n
	 * Максимальное значение амплитуды (МЗР) 
	 */
	RSH_GET_DEVICE_MAX_AMP_LSB = _RSH_GROUP_GET_DEVICE(0xB), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * Device frequency list
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_DOUBLE\n
	 *
	 * \see
	 * ::RSH_CAPS_DEVICE_FREQUENCY_LIST
	 *
	 * \~russian
	 * \brief
	 * Таблица допустимых частот дискретизации
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_DOUBLE\n
	 * Таблица допустимых частот дискретизации
	 *
	 * \see
	 * ::RSH_CAPS_DEVICE_FREQUENCY_LIST
	 *
	 */
	RSH_GET_DEVICE_FREQUENCY_LIST = _RSH_GROUP_GET_DEVICE(0xC), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * How many bytes one need to store one sample of data
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 * This value depends on ADC/DAC number of bits.
	 *
	 * \~russian
	 * \brief
	 * Размер в байтах, необходимый для записи одного значения
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Размер в байтах, необходимый для записи одного значения 
	 */
	RSH_GET_DEVICE_DATA_SIZE_BYTES = _RSH_GROUP_GET_DEVICE(0xD), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * ADC or DAC resolution
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 *
	 * \~russian
	 * \brief
	 * Разрядность АЦП (или ЦАП) 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Разрядность АЦП (или ЦАП) 
	 */
	RSH_GET_DEVICE_DATA_BITS = _RSH_GROUP_GET_DEVICE(0xE), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * How many analog channels have the device
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 *
	 * \~russian
	 * \brief
	 * Количество аналоговых каналов 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Количество аналоговых каналов 
	 */
	RSH_GET_DEVICE_NUMBER_CHANNELS = _RSH_GROUP_GET_DEVICE(0xF), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * How many analog channels have the base device
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 * This value is actual for system and combined devices,
	 * such as multichannel digital oscilloscopes, that
	 * are build from several simple ADC devices.
	 *
	 * \~russian
	 * \brief
	 * Количество каналов в базовом устройстве 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Количество каналов в базовом устройстве.\n
	 * Актуально для систем и составных устройств (например, многоканальные осциллографы).
	 */
	RSH_GET_DEVICE_NUMBER_CHANNELS_BASE = _RSH_GROUP_GET_DEVICE(0x10), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * List of gain values that can be used for analog channels
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 *
	 * \~russian
	 * \brief
	 * Список допустимых коэффициентов усиления
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Список допустимых коэффициентов усиления для 
	 * аналоговых каналов.
	 */
	RSH_GET_DEVICE_GAIN_LIST = _RSH_GROUP_GET_DEVICE(0x11), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * List of gain values that can be used for analog channels with 50Ohm resistance
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 *
	 * \~russian
	 * \brief
	 * Получение  массива с коэффициентами усиления для входа 50Ом 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Получение  массива с коэффициентами усиления для входа 50Ом 
	 */
	RSH_GET_DEVICE_GAIN_LIST_50_OHM = _RSH_GROUP_GET_DEVICE(0x12), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * List of gain values that can be used for analog channels with 1MOhm resistance
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 *
	 * \~russian
	 * \brief
	 * Получение  массива с коэффициентами усиления для входа 1МОм 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Получение  массива с коэффициентами усиления для входа 1МОм 
	 */
	RSH_GET_DEVICE_GAIN_LIST_1_MOHM = _RSH_GROUP_GET_DEVICE(0x13), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * Size of onboard device memory
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 *
	 * \~russian
	 * \brief
	 * Размер памяти, установленной на плате (или доступной для сбора)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Размер памяти, установленной на плате (или доступной для сбора) 
	 */
	RSH_GET_DEVICE_MEMORY_SIZE = _RSH_GROUP_GET_DEVICE(0x14), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * List of allowable buffer sizes
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 *
	 * \see
	 * ::RSH_CAPS_DEVICE_SIZE_LIST
	 *
	 * \~russian
	 * \brief
	 * Список допустимых размеров блоков собираемых данных 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Список допустимых размеров блоков собираемых данных 
	 *
	 * \see
	 * ::RSH_CAPS_DEVICE_SIZE_LIST
	 *
	 */
	RSH_GET_DEVICE_SIZE_LIST = _RSH_GROUP_GET_DEVICE(0x15), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * List of allowable buffer sizes in "normal" mode
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 * Normal mode is when no double/quadro frequency is used.
	 * This Get is equivalent of ::RSH_GET_DEVICE_SIZE_LIST.
	 *
	 * \~russian
	 * \brief
	 * Список допустимых размеров буфера
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Список допустимых размеров буфера в простом режиме работы
	 * (без использования удвоения/учетверения частоты).
	 * Данный код - аналог ::RSH_GET_DEVICE_SIZE_LIST.
	 *
	 */
	RSH_GET_DEVICE_SIZE_LIST_SINGLE = _RSH_GROUP_GET_DEVICE(0x16), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * List of allowable buffer sizes in double frequency mode
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 * If this get fails, just use single size list and multiply
	 * every value by 2.
	 *
	 * \~russian
	 * \brief
	 * Список допустимых размеров буфера в режиме удвоения  
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Список допустимых размеров буфера в режиме удвоения  
	 * Если этот код не работает, просто используейте 
	 * стандартный список размеров, умножая каждое значение на 2.
	 *
	 */
	RSH_GET_DEVICE_SIZE_LIST_DOUBLE = _RSH_GROUP_GET_DEVICE(0x17), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * List of allowable buffer sizes in quadro frequency mode
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 * If this get fails, just use single size list and multiply
	 * every value by 4.
	 *
	 * \~russian
	 * \brief
	 * Список допустимых размеров буфера в режиме учетверения  
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Список допустимых размеров буфера в режиме учетверения  
	 * Если этот код не работает, просто используейте 
	 * стандартный список размеров, умножая каждое значение на 4.
	 */
	RSH_GET_DEVICE_SIZE_LIST_QUADRO = _RSH_GROUP_GET_DEVICE(0x18), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * List of allowable packet sizes
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 *
	 * \see
	 * ::RSH_CAPS_DEVICE_PACKET_MODE
	 *
	 * \~russian
	 * \brief
	 * Список допустимых размеров пакетов   
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Список допустимых размеров пакетов   
	 *
	 * \see
	 * ::RSH_CAPS_DEVICE_PACKET_MODE
	 *
	 */
	RSH_GET_DEVICE_PACKET_LIST = _RSH_GROUP_GET_DEVICE(0x19), // 0x30000	
		
	/*!
	 * \~english
	 * \brief
	 * Device analog channels input range for gain == 1
	 *
	 * <b>Data type</b>: [out] ::RSH_DOUBLE\n
	 * This value is maximum positive input value for
	 * device analog channels. When gain is used,
	 * input range is changed accordingly.
	 * For example, for the gain == 2, input range is 2 times less.
	 *
	 * \see
	 * RshLsbToVolt | RshVoltToLsb
	 *
	 * \~russian
	 * \brief
	 * Входной диапазон в вольтах при коэффициенте усиления 1 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_DOUBLE\n
	 * Входной диапазон в вольтах при коэффициенте усиления 1 
	 * Т.е. максимальный входной диапазон аналоговых каналов устройства.
	 * При использовании коэффициентов усиления, диапазон меняется соответственно.
	 * Например, для к.у. == 2, он будет в 2 раза меньше, чем максимальный.
	 *
	 * \see
	 * RshLsbToVolt | RshVoltToLsb
	 *
	 */
	RSH_GET_DEVICE_INPUT_RANGE_VOLTS = _RSH_GROUP_GET_DEVICE(0x1A), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Device analog channels output range for gain == 1
	 *
	 * <b>Data type</b>: [out] ::RSH_DOUBLE\n
	 * This value is maximum positive input value for
	 * device analog channels. When gain is used,
	 * output range is changed accordingly.
	 * For example, for the gain == 2, input range is 2 times less.
	 *
	 * \see
	 * RshLsbToVolt | RshVoltToLsb
	 *
	 * \~russian
	 * \brief
	 * Выходной диапазон в вольтах при коэффициенте усиления 1 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_DOUBLE\n
	 * Выходной диапазон в вольтах при коэффициенте усиления 1
	 * (без использования аттенюатора)
	 * Т.е. максимальный выходной диапазон аналоговых каналов устройства.
	 * При использовании коэффициентов усиления, диапазон меняется соответственно.
	 * Например, для к.у. == 2, он будет в 2 раза меньше, чем максимальный.
	 *
	 * \see
	 * RshLsbToVolt | RshVoltToLsb
	 *
	 */
	RSH_GET_DEVICE_OUTPUT_RANGE_VOLTS = _RSH_GROUP_GET_DEVICE(0x1B), // 0x30000	
		
	/*!
	 * \~english
	 * \brief
	 * List of external synchro input allowable gains
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 *
	 * \~russian
	 * \brief
	 * Список допустимых коэффициентов усиления для входа внешней синхронизации 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Список допустимых коэффициентов усиления для входа внешней синхронизации   
	 */
	RSH_GET_DEVICE_EXT_SYNC_GAINLIST = _RSH_GROUP_GET_DEVICE(0x1C), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * List of external synchro input allowable gains for 50Ohm input
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 *
	 * \~russian
	 * \brief
	 * Получение  массива с коэффициентами усиления внешней синхронизации для входа 50Ом  
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Получение  массива с коэффициентами усиления внешней синхронизации для входа 50Ом 
	 */
	RSH_GET_DEVICE_EXT_SYNC_GAIN_LIST_50_OHM = _RSH_GROUP_GET_DEVICE(0x1D), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * List of external synchro input allowable gains for 1MOhm input
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_U32\n
	 *
	 * \~russian
	 * \brief
	 * Получение  массива с коэффициентами усиления внешней синхронизации для входа 1МОм 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_U32\n
	 * Получение  массива с коэффициентами усиления внешней синхронизации для входа 1МОм  
	 */
	RSH_GET_DEVICE_EXT_SYNC_GAIN_LIST_1_MOHM = _RSH_GROUP_GET_DEVICE(0x1E), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Device external synchro input range for gain == 1
	 *
	 * <b>Data type</b>: [out] ::RSH_DOUBLE\n
	 * This value is maximum positive input value for
	 * device external synchro channel. When gain is used,
	 * input range is changed accordingly.
	 * For example, for the gain == 2, input range is 2 times less.
	 *
	 * \~russian
	 * \brief
	 * Диапазон входа внешней синхронизации в вольтах при коэффициенте усиления 1
	 *
	 * <b>Тип данных</b>: [out] ::RSH_DOUBLE\n
	 * Диапазон входа внешней синхронизации в вольтах при коэффициенте усиления 1
	 * Т.е. максимальный входной диапазон для канала внешней синхронизации.
	 * При использовании коэффициентов усиления, диапазон меняется соответственно.
	 * Например, для к.у. == 2, он будет в 2 раза меньше, чем максимальный.
	 */
	RSH_GET_DEVICE_EXT_SYNC_INPUT_RANGE_VOLTS = _RSH_GROUP_GET_DEVICE(0x1F), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Get data structure with information about device digital ports
	 *
	 * <b>Data type</b>: [out] ::RshBoardPortInfo\n
	 *
	 * \see
	 * RshBoardPortInfo
	 *
	 * \~russian
	 * \brief
	 * Получeние структуры из со служебной информацией о портах
	 *
	 * <b>Тип данных</b>: [out] RshBoardPortInfo\n
	 * Получeние структуры из со служебной информацией о портах
	 *
	 * \see
	 * RshBoardPortInfo
	 *
	 */
	RSH_GET_DEVICE_PORT_INFO = _RSH_GROUP_GET_DEVICE(0x20), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Get device serial number
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 *
	 * \~russian
	 * \brief
	 * Получение заводского номера устройства
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Получение заводского номера устройства  
	 */
	RSH_GET_DEVICE_SERIAL_NUMBER = _RSH_GROUP_GET_DEVICE(0x21), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Get current prehistory size in counts
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 *
	 * \see \link page_Synchronization Synchronization \endlink
	 *
	 * \~russian
	 * \brief
	 * Размер предыстории в отсчетах
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Размер предыстории в отсчетах	 
	 *
	 * \see \link page_Synchronization Synchronization \endlink
	 *
	 */
	RSH_GET_DEVICE_PREHISTORY_SIZE = _RSH_GROUP_GET_DEVICE(0x22), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Get number of currently active channels
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n
	 * Usually it's usefull to check this value after
	 * IRshDevice::Init() call.
	 *
	 * \~russian
	 * \brief
	 * Количество каналов, выбраных для работы
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Количество каналов, выбраных для работы
	 * (доступно после вызова метода IRshDevice::Init() )  
	 */
	RSH_GET_DEVICE_ACTIVE_CHANNELS_NUMBER = _RSH_GROUP_GET_DEVICE(0x23), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Check plug status for USB device
	 *
	 * <b>Data type</b>: [in] ::NULL\n
	 * Second parameter is ignored.
	 *
	 * \~russian
	 * \brief
	 * Проверка статуса подключения для USB устройств
	 *
	 * <b>Тип данных</b>: [in] NULL\n
	 * Проверка статуса подключения для USB устройств. Второй параметр игнорируется.     
	 */
	RSH_GET_DEVICE_PLUG_STATUS = _RSH_GROUP_GET_DEVICE(0x24), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Get list of currently available devices
	 *
	 * <b>Data type</b>: [out] ::RSH_BUFFER_DEVICE_FULL_INFO\n
	 * Obtain list of all Rudshel devices, connected/plugged to PC.
	 * 
	 * \~russian
	 * \brief
	 *
	 * Получение списка активных устройств
	 *
	 * <b>Тип данных</b>: [out] ::RSH_BUFFER_DEVICE_FULL_INFO\n
	 * Получение списка устройств ЗАО "Руднев-Шиляев",
	 * подключенных (установленных) в данный момент.\n
	 * Список заполняется на основании данных, получаемых от операционной
	 * системы.
	 *
	 */
	RSH_GET_DEVICE_ACTIVE_LIST = _RSH_GROUP_GET_DEVICE(0x25), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Start automatic calibration process
	 *
	 * <b>Data type</b>: [in] ::NULL\n
	 * Not available for all devices.
	 * \see ::RSH_CAPS_DEVICE_AUTO_CALIBRATION
	 * 
	 * \~russian
	 * \brief
	 * Запуск процесса автоматической калибровки
	 *
	 * <b>Тип данных</b>: [in] NULL\n
	 * Производит автоматическую калибровку для тех устройств, которые поддерживают данную возможность	
	 * \see ::RSH_CAPS_DEVICE_AUTO_CALIBRATION
	 */
	RSH_GET_DEVICE_AUTO_CALIBRATION_SET = _RSH_GROUP_GET_DEVICE(0x26), // 0x30000 
		
	/*!
	 * \~english
	 * \brief
	 * Control of analog channels ICP power
	 *
	 * <b>Data type</b>: [in] ::RSH_U32\n
	 * Not available for all devices.
	 * Every bit in U32 value is for one of channels.
	 * Bit state 0 is power off, bit state 1 is power on.
	 * \deprecated Use control word of initialization structure
	 * 
	 * \~russian
	 * \brief
	 * Управление ICP-питанием аналоговых каналов
	 *
	 * <b>Тип данных</b>: [in] ::RSH_U32\n
	 * Управление ICP-питанием. Соответствующий каналу бит = 0 - нет питания, = 1 - есть питание  
	 * \deprecated Используйте контрольное слово структуры инициализации
     *
	 */
	RSH_GET_DEVICE_ICP_POWER_SET = _RSH_GROUP_GET_DEVICE(0x27), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Turn on hardware averaging of data
	 *
	 * <b>Data type</b>: [in] ::NULL\n	
	 * \deprecated Only LA-50USB device have this feature,
	 * and its not supported in current SDK release.
	 *
	 * \~russian
	 * \brief
	 * Включение аппаратного усреднения данных
	 *	
	 * <b>Тип данных</b>: [in] ::NULL\n
	 * \deprecated Только ЛА-50USB имеет такую возможность,
	 * но в текущей версии SDK данная опция не реализована.
	 *
	 */
	RSH_GET_DEVICE_AVR_MODE_SET = _RSH_GROUP_GET_DEVICE(0x28), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Read data from device register
	 *
	 * <b>Data type</b>: [out] ::RshRegister\n	
	 *
	 * \~russian
	 * \brief
	 * Чтение из регистра устройства 
	 *
	 * <b>Тип данных</b>: [out] RshRegister\n
	 * Чтение из регистра устройства  
	 */
	RSH_GET_DEVICE_REGISTER_BOARD = _RSH_GROUP_GET_DEVICE(0x29), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Write data to device register
	 *
	 * <b>Data type</b>: [in] ::RshRegister\n	
	 *
	 * \~russian
	 * \brief
	 * Запись в регистр устройства
	 *
	 * <b>Тип данных</b>: [in] RshRegister\n
	 * Запись в регистр устройства   
	 */
	RSH_GET_DEVICE_REGISTER_BOARD_SET = _RSH_GROUP_GET_DEVICE(0x2A), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Read data from plx9050 register (memory range 1)
	 *
	 * <b>Data type</b>: [out] ::RshRegister\n	
	 *
	 * \~russian
	 * \brief
	 * Чтение из регистра устройства plx9050 (диапазон памяти 1)
	 *
	 * <b>Тип данных</b>: [out] RshRegister\n
	 * Чтение из регистра устройства plx9050 (диапазон памяти 1)
	 */
	RSH_GET_DEVICE_REGISTER_BOARD_SPACE1 = _RSH_GROUP_GET_DEVICE(0x2B), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Write data to plx9050 register (memory range 1)
	 *
	 * <b>Data type</b>: [in] ::RshRegister\n	
	 *
	 * \~russian
	 * \brief
	 * Запись в регистр устройства plx9050 (диапазон памяти 1)
	 *
	 * <b>Тип данных</b>: [in] RshRegister\n
	 * Запись в регистр устройства plx9050 (диапазон памяти 1)
	 */
	RSH_GET_DEVICE_REGISTER_BOARD_SPACE1_SET = _RSH_GROUP_GET_DEVICE(0x2C), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Read data from plx9050 register (memory range 2)
	 *
	 * <b>Data type</b>: [out] ::RshRegister\n	
	 *
	 * \~russian
	 * \brief
	 * Чтение из регистра устройства plx9050 (диапазон памяти 2)
	 *
	 * <b>Тип данных</b>: [out] RshRegister\n
	 * Чтение из регистра устройства plx9050 (диапазон памяти 2)
	 */
	RSH_GET_DEVICE_REGISTER_BOARD_SPACE2 = _RSH_GROUP_GET_DEVICE(0x2D), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Write data to plx9050 register (memory range 2)
	 *
	 * <b>Data type</b>: [in] ::RshRegister\n	
	 *
	 * \~russian
	 * \brief
	 * Запись в регистр устройства plx9050 (диапазон памяти 2)
	 *
	 * <b>Тип данных</b>: [in] RshRegister\n
	 * Запись в регистр устройства plx9050 (диапазон памяти 2)
	 */
	RSH_GET_DEVICE_REGISTER_BOARD_SPACE2_SET = _RSH_GROUP_GET_DEVICE(0x2E), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Minimum number of counts (buffer size) per channel.
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 * For devices that don't have size lists.
	 *
	 * \~russian
	 * \brief
	 * Минимальное количество отсчетов (размер буфера) на канал
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Минимальное количество отсчетов (размер буфера) на канал  
	 * Актуально для устройств, которые не имеют фиксированного списка размеров.
	 *
	 */
	RSH_GET_DEVICE_MIN_SAMPLES_PER_CHANNEL = _RSH_GROUP_GET_DEVICE(0x2F), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Maximum number of counts (buffer size) per channel.
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 * For devices that don't have size lists.
	 *
	 * \~russian
	 * \brief
	 * Максимальное количество отсчетов (размер буфера) на канал
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Максимальное количество отсчетов (размер буфера) на канал
	 * Актуально для устройств, которые не имеют фиксированного списка размеров.
	 *
	 */
	RSH_GET_DEVICE_MAX_SAMPLES_PER_CHANNEL = _RSH_GROUP_GET_DEVICE(0x30), // 0x30000
		
	/*!
	 * \~english
	 * \brief
	 * Reset device and free locked resources.
	 *
	 * <b>Data type</b>: [in] ::NULL\n	
	 * Performs "deep" device reset, actual for PLX based devices
	 *
	 * \~russian
	 * \brief
	 * Сброс устройства, освобождение захваченных устройством ресурсов
	 *
	 * <b>Тип данных</b>: [in] NULL\n
	 * Сброс устройства, освобождение захваченных устройством ресурсов
	 * В основном актуально для устройств на базе чипов PLX.
	 * Позволяет провести сброс устройства без выгрузки и загрузки библиотек.
	 *
	 */
	RSH_GET_DEVICE_RESET = _RSH_GROUP_GET_DEVICE(0x31), // 0x30000
	
	/*!
	 * \~english
	 * \brief
	 * Check device power state
	 *
	 * <b>Data type</b>: [in] ::NULL\n	
	 * For devices with power supply control.
	 * Second parameter is ignored.
	 *
	 * \~russian
	 * \brief
	 * Состояние питания устройства
	 *
	 * <b>Тип данных</b>: [in] NULL\n
	 * Проверка статуса питания (для устройств с внешним питанием). Второй параметр игнорируется.     
	 */
	RSH_GET_DEVICE_POWER_STATUS  = _RSH_GROUP_GET_DEVICE(0x32),// 0x30000

	/*
	 * \~english
	 * \brief
	 * Get list of active devices (with more information)
	 *
	 * NOT SUPPORTED for current SDK release.
	 *
	 * \~russian
	 * \brief
	 * Получение списка активных устройств (расширенная информация)
	 *
	 * Получение списка активных устройств (расширенная информация)
	 * \warning В текущей версии не реализовано!
	 * \todo Возможно, следует удалить данный код
	 * 	
	do_not_parse_deprecated_GET_DEVICE_ACTIVE_LIST_EXT = _RSH_GROUP_GET_DEVICE(0x33), // 0x30000
	*/

	/*!
	 * \~english
	 * \brief
	 * Get GPS data
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 * Get GPS data as string. String format depends on device type.
	 * Usually its something like this:
	 * \code
	 * GGA,123519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42
	 * \endcode
	 * (for NMEA-0183). See device user manual for more details.
	 *
	 * \~russian
	 * \brief
	 * Получение данных GPS
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Формат строки зависит от устройства (чипа GPS).
	 * Как правило, данные представляют собой строку вида:\n
	 * \code 
	 * GGA,123519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42
	  * \endcode 
	 * (пример для NMEA-0183). Подробное описание формата можно найти
	 * в руководстве пользователя для устройства.
	 *
	 */
	RSH_GET_DEVICE_GPS_DATA = _RSH_GROUP_GET_DEVICE(0x34), // 0x30000

	
	/*!
	 * \~english
	 * \brief
	 * Get GPS data as unicode string 
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 * Get GPS data as string. String format depends on device type.
	 * Usually its something like this:
	 * \code
	 * GGA,123519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42
	 * \endcode
	 * (for NMEA-0183). See device user manual for more details.
	 *
	 * \~russian
	 * \brief
	 * Получение данных GPS (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Аналог ::RSH_GET_DEVICE_GPS_DATA но в формате UTF-16.
	 */
	RSH_GET_DEVICE_GPS_DATA_UTF16 = _RSH_GROUP_GET_DEVICE(0x35), // 0x30000

	/*!
	 * \~english
	 * \brief
	 * Set autostart interval
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 * Set autostart interval in ms for devices, that
	 * support this feature.
	 *
	 * \see
	 * RSH_CAPS_DEVICE_AUTO_START_MODE
	 *
	 * \~russian
	 * \brief
	 * Установка интервала автозапуска
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Используется для задания интервала автоматического запуска сбора
	 * данных в мс, для тех устройств, которые поддерживают данную возможность.
	 *
	 * \see
	 * RSH_CAPS_DEVICE_AUTO_START_MODE
	 */
	RSH_GET_DEVICE_AUTO_START_INTERVAL_SET = _RSH_GROUP_GET_DEVICE(0x36), // 0x30000

	/*!
	 * \~english
	 * \brief
	 * Get current value of supply voltage
	 *
	 * <b>Data type</b>: [out] ::RSH_DOUBLE\n	
	 * Get current value of supply voltage,
	 * usually is used for devices with battery supply.
	 *
	 * \~russian
	 * \brief
	 * Получение текущего значения напряжения питания
	 *
	 * <b>Тип данных</b>: [out] ::RSH_DOUBLE\n
	 * Получение текущего значения напряжения питания в вольтах.\n 
	 * Как правило, применияется для устройств с автономным питанием.
	 */
	RSH_GET_DEVICE_POWER_SOURCE_VOLTAGE = _RSH_GROUP_GET_DEVICE(0x37), // 0x30000

		
	/*!
	 * \~english
	 * \brief
	 * SDK version major
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Версия SDK major  
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Версия SDK major  
	 */
	RSH_GET_SDK_VERSION_MAJOR = _RSH_GROUP_GET_SDK(0x1), // 0x40000
		
	/*!
	 * \~english
	 * \brief
	 * SDK version minor
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Версия SDK minor  
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Версия SDK minor 
	 */
	RSH_GET_SDK_VERSION_MINOR =  _RSH_GROUP_GET_SDK(0x2), // 0x40000
		
	/*!
	 * \~english
	 * \brief
	 * SDK version string literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа с версией SDK
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа с версией SDK
	 */
	RSH_GET_SDK_VERSION_STRING =  _RSH_GROUP_GET_SDK(0x3), // 0x40000
		
	/*!
	 * \~english
	 * \brief
	 * Organisation name string literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - название организации
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - название организации
	 */
	RSH_GET_SDK_COPYRIGHT_STRING =  _RSH_GROUP_GET_SDK(0x4), // 0x40000
		
	/*!
	 * \~english
	 * \brief
	 * SDK version string literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа с версией SDK (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа с версией SDK (Unicode)
	 */
	RSH_GET_SDK_COPYRIGHT_STRING_UTF16 =  _RSH_GROUP_GET_SDK(0x5), // 0x40000
		
	/*!
	 * \~english
	 * \brief
	 * Organisation name string literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - название организации (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - название организации (Unicode)
	 */
	RSH_GET_SDK_VERSION_STRING_UTF16 =  _RSH_GROUP_GET_SDK(0x6), // 0x40000
		
	/*!
	 * \~english
	 * \brief
	 * Library version - major
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Получение версии библиотеки - major.
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Получение версии библиотеки - major.  
	 */
	RSH_GET_LIBRARY_VERSION_MAJOR =  _RSH_GROUP_GET_LIBRARY(0x1), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library version - minor
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Получение версии библиотеки - minor.
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Получение версии библиотеки - minor.  
	 */
	RSH_GET_LIBRARY_VERSION_MINOR =  _RSH_GROUP_GET_LIBRARY(0x2), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library version - build
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Получение версии библиотеки - build.
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Получение версии библиотеки - build.
	 */
	RSH_GET_LIBRARY_VERSION_BUILD =  _RSH_GROUP_GET_LIBRARY(0x3), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library version - date
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Получение версии библиотеки - date.
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Получение версии библиотеки - date.
	 */
	RSH_GET_LIBRARY_VERSION_DATE =  _RSH_GROUP_GET_LIBRARY(0x4), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library interface type literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя интерфейса
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - имя интерфейса 
	 */
	RSH_GET_LIBRARY_INTERFACE_NAME =  _RSH_GROUP_GET_LIBRARY(0x5), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library interface type literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя интерфейса (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - имя интерфейса (Unicode)  
	 */
	RSH_GET_LIBRARY_INTERFACE_NAME_UTF16 =  _RSH_GROUP_GET_LIBRARY(0x6), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Module name literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя модуля 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - имя модуля 
	 */
	RSH_GET_LIBRARY_MODULE_NAME =  _RSH_GROUP_GET_LIBRARY(0x7), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Module name literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя модуля (Unicode) 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - имя модуля (Unicode)  
	 */
	RSH_GET_LIBRARY_MODULE_NAME_UTF16 =  _RSH_GROUP_GET_LIBRARY(0x8), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library path literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - путь размещения файла библиотеки 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - путь размещения файла библиотеки 
	 */
	RSH_GET_LIBRARY_PATH =  _RSH_GROUP_GET_LIBRARY(0x9), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library path literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - путь размещения файла библиотеки (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - путь размещения файла библиотеки (Unicode)   
	 */
	RSH_GET_LIBRARY_PATH_UTF16 =  _RSH_GROUP_GET_LIBRARY(0xA), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library file name literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя файла библиотеки абстракции
	 *
     * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - имя файла библиотеки абстракции
	 */
	RSH_GET_LIBRARY_FILENAME =  _RSH_GROUP_GET_LIBRARY(0xB), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library file name in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя файла библиотеки абстракции (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - имя файла библиотеки абстракции (Unicode) 
	 */
	RSH_GET_LIBRARY_FILENAME_UTF16 =  _RSH_GROUP_GET_LIBRARY(0xC), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library version as string literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - версия библиотеки абстракции 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - версия библиотеки абстракции  
	 */
	RSH_GET_LIBRARY_VERSION_STR =  _RSH_GROUP_GET_LIBRARY(0xD), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library version as string in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - версия библиотеки абстракции (Unicode) 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - версия библиотеки абстракции (Unicode)  
	 */
	RSH_GET_LIBRARY_VERSION_STR_UTF16 =  _RSH_GROUP_GET_LIBRARY(0xE), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library description literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - описание библиотеки (как в свойствах файла)  
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - описание библиотеки (как в свойствах файла)  
	 */
	RSH_GET_LIBRARY_DESCRIPTION =  _RSH_GROUP_GET_LIBRARY(0xF), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library description in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - описание библиотеки (Unicode)  
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - описание библиотеки (Unicode)  
	 */
	RSH_GET_LIBRARY_DESCRIPTION_UTF16 =  _RSH_GROUP_GET_LIBRARY(0x10), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library internal name literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - внутреннее имя библиотеки (как в свойствах файла) 
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - внутреннее имя библиотеки (как в свойствах файла)  
	 */
	RSH_GET_LIBRARY_PRODUCT_NAME =  _RSH_GROUP_GET_LIBRARY(0x11), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Library internal name literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - внутреннее имя библиотеки (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - внутреннее имя библиотеки (Unicode)  
	 */
	RSH_GET_LIBRARY_PRODUCT_NAME_UTF16 =  _RSH_GROUP_GET_LIBRARY(0x12), // 0x50000
		
	/*!
	 * \~english
	 * \brief
	 * Core Library version - major
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Получение версии базовой библиотеки - major
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Получение версии базовой библиотеки - major  
	 */
	RSH_GET_CORELIB_VERSION_MAJOR = _RSH_GROUP_GET_CORELIB(0x1), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core Library version - minor
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Получение версии базововй библиотеки - minor
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Получение версии базововй библиотеки - minor
	 */
	RSH_GET_CORELIB_VERSION_MINOR = _RSH_GROUP_GET_CORELIB(0x2), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core Library version - build
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Получение версии базововй библиотеки - build
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Получение версии базововй библиотеки - build  
	 */
	RSH_GET_CORELIB_VERSION_BUILD = _RSH_GROUP_GET_CORELIB(0x3), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core Library version - date
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Получение версии базововй библиотеки - date
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Получение версии базововй библиотеки - date  
	 */
	RSH_GET_CORELIB_VERSION_DATE = _RSH_GROUP_GET_CORELIB(0x4), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library interface name literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя интерфейса базовой библиотеки
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - имя интерфейса базовой библиотеки  
	 */
	RSH_GET_CORELIB_INTERFACE_NAME = _RSH_GROUP_GET_CORELIB(0x5), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library interface name literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя интерфейса базовой библиотеки (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - имя интерфейса базовой библиотеки (Unicode) 
	 */
	RSH_GET_CORELIB_INTERFACE_NAME_UTF16 = _RSH_GROUP_GET_CORELIB(0x6), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library module name literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя модуля базовой библиотеки
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - имя модуля базовой библиотеки  
	 */
	RSH_GET_CORELIB_MODULE_NAME = _RSH_GROUP_GET_CORELIB(0x7), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library module name literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя модуля базовой библиотеки (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - имя модуля базовой библиотеки (Unicode) 
	 */
	RSH_GET_CORELIB_MODULE_NAME_UTF16 = _RSH_GROUP_GET_CORELIB(0x8), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library file path literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - путь размещения файла базовой библиотеки
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - путь размещения файла базовой библиотеки
	 */
	RSH_GET_CORELIB_PATH = _RSH_GROUP_GET_CORELIB(0x9), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library file path literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - путь размещения файла базовой библиотеки (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - путь размещения файла базовой библиотеки (Unicode)   
	 */
	RSH_GET_CORELIB_PATH_UTF16 = _RSH_GROUP_GET_CORELIB(0xA), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library file name literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя файла базовой библиотеки
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - имя файла базовой библиотеки 
	 */
	RSH_GET_CORELIB_FILENAME = _RSH_GROUP_GET_CORELIB(0xB), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library file name literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - имя файла базовой библиотеки (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - имя файла базовой библиотеки (Unicode)  
	 */
	RSH_GET_CORELIB_FILENAME_UTF16 = _RSH_GROUP_GET_CORELIB(0xC), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library version as string literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - версия базовой библиотеки
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - версия базовой библиотеки   
	 */
	RSH_GET_CORELIB_VERSION_STR = _RSH_GROUP_GET_CORELIB(0xD), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library version as string literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - версия базовой библиотеки Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - версия базовой библиотеки Unicode)  
	 */
	RSH_GET_CORELIB_VERSION_STR_UTF16 = _RSH_GROUP_GET_CORELIB(0xE), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library description literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - описание базовой библиотеки (как в свойствах файла)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - описание базовой библиотеки (как в свойствах файла)  
	 */
	RSH_GET_CORELIB_DESCRIPTION = _RSH_GROUP_GET_CORELIB(0xF), // 0x60000
		
	/*!
     * \~english
	 * \brief
	 * Core library description literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - описание базовой библиотеки (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - описание базовой библиотеки (Unicode)  
	 */
	RSH_GET_CORELIB_DESCRIPTION_UTF16 =  _RSH_GROUP_GET_CORELIB(0x10), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library internal name literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - внутреннее имя  базовой библиотеки (как в свойствах файла)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Строковая константа - внутреннее имя  базовой библиотеки (как в свойствах файла)
	 */
	RSH_GET_CORELIB_PRODUCT_NAME = _RSH_GROUP_GET_CORELIB(0x11), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Core library internal name literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_U16P\n	
	 *
	 * \~russian
	 * \brief
	 * Строковая константа - внутреннее имя базовой библиотеки (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Строковая константа - внутреннее имя базовой библиотеки (Unicode)
	 */
	RSH_GET_CORELIB_PRODUCT_NAME_UTF16= _RSH_GROUP_GET_CORELIB(0x12), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Driver API version (for PLX devices)
	 *
	 * <b>Data type</b>: [out] ::RSH_U32\n	
	 *
	 * \~russian
	 * \brief
	 * Версия API драйвера (актуально для PLX устройств)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U32\n
	 * Версия API драйвера (актуально для PLX устройств)
	 */
	RSH_GET_CORELIB_VERSION_INTERNAL_API = _RSH_GROUP_GET_CORELIB(0x13), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Driver API version (for PLX devices) as string literal
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Версия  API драйвера в виде строки
	 *
	 * <b>Тип данных</b>: [out] ::RSH_S8P\n
	 * Версия  API драйвера в виде строки
	 */
	RSH_GET_CORELIB_VERSION_INTERNAL_API_STR = _RSH_GROUP_GET_CORELIB(0x14), // 0x60000
		
	/*!
	 * \~english
	 * \brief
	 * Driver API version (for PLX devices) as string literal in UTF16
	 *
	 * <b>Data type</b>: [out] ::RSH_S8P\n	
	 *
	 * \~russian
	 * \brief
	 * Версия  API драйвера в виде строки (Unicode)
	 *
	 * <b>Тип данных</b>: [out] ::RSH_U16P\n
	 * Версия  API драйвера в виде строки (Unicode)
	 */
	RSH_GET_CORELIB_VERSION_INTERNAL_API_STR_UTF16 = _RSH_GROUP_GET_CORELIB(0x15) // 0x60000
	

}RSH_GET;
 
#endif //RSH_CONSTS_GET_CODES_H 
 