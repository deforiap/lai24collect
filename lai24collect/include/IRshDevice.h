/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file IRshDevice.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * IRshDevice interface.
 *
 * \~russian
 * \brief
 * Интерфейс IRshDevice.
 *
 */

#ifndef IRSH_DEVICE_H
#define IRSH_DEVICE_H

#include "RshDefChk.h"
#include "RshBaseType.h"
#include "RshDeviceKey.h"
#include "RshConsts_ConnectModes.h"
#include "RshConsts_InitModes.h"
#include "RshConsts_GetDataModes.h"


#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * Interface is used to control almost all RSH ADC/DAC devices.
 *
 * Main interface to handle ADC and DAC devices produced by CJSC "Rudnev-Shilyaev"
 * and some third-party devices by other companies. \n
 * Typical scenario is when user gets object with IRshDevice interface from
 * device abstraction library, which can be loaded
 * using RshDllClient class.
 * Then user can get access to all features of the device without knowing
 * low level architecture of device and device drivers.
 *
 * \remarks
 * Some RSh devices do not use this interface, for example, charge
 * amplifiers that are connected to PC using seral port and accessed
 * via RS-232 interface.
 *
 * \see
 * RshDllClient
 *
 * \~russian
 * \brief
 * Интерфейс используется для управления практически всеми
 * АЦП/ЦАП устройствами ЗАО "Руднев-Шиляев".
 *
 * Основной интерфейс для управления устройствами, выпускаемыми фирмой ЗАО "Руднев-Шиляев",
 * а также некоторыми устройствами других фирм.\n
 * Обычный сценарий работы - получение объекта, реализующего интерфейс IRshDevice,
 * из библиотеки абстракции, которая может быть загружена используя класс RshDllClient.
 * После этого пользователь получает доступ ко всем возможностям устройства, при этом
 * ему не нужно знать низкоуровневых деталей реализации аппаратной структуры устройства и драйвера.
 *
 * \remarks
 * Некоторые устройства ЗАО "Руднев-Шиляев" не используют этот интерфейс, например,
 * усилители заряда подключаются к компьютеру через последовательный порт и
 * управляются по протоколу RS-232.
 *
 * \see
 * RshDllClient.
 */
struct  IRshDevice
{
	/*!
	 *
	 * \~english
	 * \brief
	 * Connect to certain device.
	 *
	 * \param[in] key
	 * Identification key for a device. It might be an index of the device, a serial number of the device or a connection string to the device.
	 *
	 * \param[in] mode
	 * Connection mode using a device index, a serial number or a connection string.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * This method must be executed first before any other
	 * device access methods.\n
	 * After successfull call of this method
	 * device is ready to use and can be configured
	 * for data acquisition.\n
	 * Most other methods of interface (such as Init(), Start() etc.)
	 * will return error if device was not connected using Connect().\n
	 * One can, however, get some static library and device information
	 * using Get() method.
	 *
	 *
	 * \remarks
	 * If you use connection mode ::RSH_CONNECT_MODE_BASE devices are enumerated from 1.
	 * Order of devices is determined by operating system and
	 * depends on used slot and plug order.
	 *
	 * \see
	 * Get() | RSH_CONNECT_MODES |  RshDeviceKey
	 *
	 * \~russian
	 * \brief
	 * Подключение к заданному устройству.
	 *
	 * \param[in] key
	 * Идентификационный ключ устройства.
	 * В зависимости от выбранного режима подключения может быть индексом устройства, его серийным номером или строкой подключения.\n
	 * В качестве ключа используется структура RshDeviceKey (тип параметра RshBaseType оставлен для большей универсальности).
	 *
	 * \param[in] mode
	 * Режим подключения к устройству с использованием серийного номера устройства, его индекса или строки подключения.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * Данный метод нужно вызывать первым, до вызова любых других
	 * методов доступа к устройству.\n
	 * После успешного вызова этого метода устройство полностью готово
	 * к использованию и может быть настроено для сбора данных.
	 * Большинство других методов интерфейса (такие как Init(), Start())
	 * вернут ошибку, если вызвать их до вызова Connect().\n
	 * Можно, однако, получить некоторые статические параметры библиотеки абстракции
	 * и устройства, используя метод Get().
	 *
	 * \remarks
	 * Если вы используете режим подключения ::RSH_CONNECT_MODE_BASE, нумерация устройств начинается с 1.
	 * Порядок устройств определяется операционной системой, и зависит
	 * от используемого разъема (слота), а так же очередности подключения устройств к компьютеру.
	 *
	 * \see
	 * Get() | RSH_CONNECT_MODES | RshDeviceKey
	 */
	virtual U32    __RSHCALLCONV  Connect( IN RshBaseType* key, IN U32 mode = RSH_CONNECT_MODE_BASE ) = 0;

	/*!
	 *
	 * \~english
	 * \brief
	 * Setup data acquisition parameters.
	 *
	 * \param[in,out] structure
	 * Initialization structure derived from RshBaseType.\n
	 * Each device can support one or more of initialization
	 * structures, such as RshInitDMA or RshInitMemory.
	 *
	 * \param[in] mode
	 * Initialization mode:\n
	 * ::RSH_INIT_MODE_CHECK - check and change wrong
	 * parameters in structure without any hardware access.\n
	 * ::RSH_INIT_MODE_INIT - real initialization, check and change
	 * wrong parameters and send them to hardware.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * This method is used to setup device and set data acquisition parameters.
	 * Special parameter structures are used:\n
	 * RshInitDMA: for low frequency (less than 10MHz) devices with no integrated flash memory.\n
	 * RshInitMemory: for high frequency devices with on board memory.\n
	 * RshInitGSPF: for digital generator devices.\n
	 * RshInitVoltmeter: for B7/78 voltmeter.\n
	 * RshInitPort: access to digital port.\n
	 * RshInitDAC: access to DACs.\n
	 * Using these structures one can set various settings such as
	 * buffer size, frequency, number of channels and so on. See structure
	 * description for more details.
	 * Example:
	 * \include IRshDevice_Init_RshInitDMA_EN.cpp
	 *
	 * \remarks
	 * You can find what init structure is supported by your device using
	 * Get() method with parameter ::RSH_GET_DEVICE_IS_CAPABLE and check
	 * capabilities ::RSH_CAPS_SOFT_INIT_MEMORY, ::RSH_CAPS_SOFT_INIT_DMA etc.
	 *
	 * \see
	 * RshInitDMA | RshInitMemory | RshInitDAC | RshInitVoltmeter | RshInitPort | RshInitGSPF
	 *
	 * \~russian
	 * \brief
	 * Установка параметров сбора и настройка устройства.
	 *
	 * \param[in,out] structure
	 * Структура инициализации, унаследованная от RshBaseType.\n
	 * Каждое устройство поддерживает как минимум одну структуру
	 * инициализации, такую как RshInitDMA или RshInitMemory.
	 *
	 * \param[in] mode
	 * ::RSH_INIT_MODE_CHECK - проверка полей в переданной структуре инициализаци,
	 * неподходящие значения будут исправлены на допустимые. После исправления
	 * параметров метод завершает работу, обращений к устройству не производится.\n
	 * ::RSH_INIT_MODE_INIT - действительня реализация, после исправления значений
	 * в структуре производится передача выбранных параметров к устройству, запись
	 * в регистры и тому подобное.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * Данный метод используется для задания параметров сбора (генерации).
	 * Для передачи параметров используется одна из специальных структур инициализации:\n
	 * RshInitDMA: как правило, данная структура используется для низкочастотных (до 10Мгц) устройств
	 * без установленной флэш памяти для данных.\n
	 * RshInitMemory: для высокочастотных устройств с собственной памятью.\n
	 * RshInitGSPF: для цифровых генераторов сигнала.\n
	 * RshInitVoltmeter: для вольтметра В7/78\n
	 * RshInitPort: для доступа к цифровым портам.\n
	 * RshInitDAC: для доступа к ЦАПам.\n
	 * Используя данные структуры, можно задать различные параметры сбора,
	 * такие как частоту дискретизации, число каналов, размер буфера и др.
	 * Более подробно - в описании структур инициализации.\n
	 *
	 * Пример использования метода:
	 * \include IRshDevice_Init_RshInitDMA_RU.cpp
	 *
	 * \remarks
	 * Чтобы узнать, поддерживает или нет конкретное устройство ту или иную структуру
	 * инициализации, используйте метод Get() с параметром ::RSH_GET_DEVICE_IS_CAPABLE
	 * с соответствующими кодами для структур (::RSH_CAPS_SOFT_INIT_MEMORY, ::RSH_CAPS_SOFT_INIT_DMA и т.д.)
	 *
	 * \see
	 * RshInitDMA | RshInitMemory | RshInitDAC | RshInitVoltmeter | RshInitPort | RshInitGSPF
	 *
	 */
	virtual U32    __RSHCALLCONV  Init( IN OUT RshBaseType* structure, IN U32 mode = RSH_INIT_MODE_INIT ) = 0;

	/*!
	 *
	 * \~english
	 * \brief
	 * Start data acquisition or signal generation process.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * ADC devices start data acquisition
	 * and transfer when this method is called.
	 * After data transfer complete, data ready event
	 * will be signalled and data can be collected using
	 * GetData() method.\n
	 * Signal generators (GSPF family for instance) start
	 * buffer translation on this command. So, for them command order
	 * is reverced: one need first to transfer data buffer using
	 * GetData() method and only after that start generation with Start().
	 *
	 * \remarks
	 * Process of starting device is not immidiate,
	 * some time required for transfer command and process it.\n
	 * Moreover, if synchronization of some kind used,
	 * device only start actual data acquisition process
	 * when synchronization event will be triggered.
	 *
	 * \see
	 * RSH_GET_WAIT_BUFFER_READY_EVENT |  \link page_Synchronization Synchronization \endlink
	 *
	 * \~russian
	 * \brief
	 * Запуск процесса сбора данных или генерации сигнала.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * Устройства сбора данных начинают процесс сбора
	 * и передачи данных, когда вызывается этот метод.
	 * После завершения передачи ставится флаг готовности данных,
	 * и данные можно получить с помощью метода GetData() \n
	 * Генераторы сигнала (серия ГСПФ) начинают проигрование
	 * буфера по этой команде. Таким образом, для генераторов
	 * порядок команд будет обратным: сначала нужно передать подготовленный
	 * буфер с данными с помощью метода GetData() и только затем
	 * запустить генарацию, вызвав Start().
	 *
	 * \remarks
	 * Процесс запуска происходит не мгновенно,
	 * требуется некоторое время на передачу команды
	 * и подготовку устройства.\n
	 * Более того, если используется синхронизация в каком-либо виде,
	 * непосредственно процесс сбора данных начнется только
	 * после получения события синхронизации.
	 *
	 * \see
	 * RSH_GET_WAIT_BUFFER_READY_EVENT |  \link page_Synchronization Синхронизация\endlink
	 *
	 */
	virtual U32    __RSHCALLCONV  Start() = 0;

	/*!
	 *
	 * \~english
	 * \brief
	 * Stop data acquisition or signal generation process.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * When this method is called, all data connected
	 * activity is terminated: continious data transfer
	 * is cancelled, ADC (or DAC) is stopped, USB pipes
	 * and DMA channels are reseted to default state and ready
	 * to next Start() call.
	 *
	 * \remarks
	 * If this method is called before any actual data transfer
	 * commited, Get() method with RSH_GET_WAIT_BUFFER_READY_EVENT
	 * parameter will return error code as result.
	 *
	 * \see
	 * RSH_GET_WAIT_BUFFER_READY_EVENT
	 *
	 * \~russian
	 * \brief
	 * Остановка процесса сбора данных или генерации сигнала.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * При вызове этого метода вся активность, связанная со сбором
	 * или генерацией прекращается: останавливается АЦП (ЦАП), сбрасывается
	 * процесс передачи по USB, ПДП каналы возвращаются в исходное состояние.
	 * Устройство готово к следующему вызову метода Start().
	 *
	 * \remarks
	 * Если данный метод вызывается до того, как была успешно завершена
	 * передача блока данных (размер блока определяется настройками сбора
	 * в структуре инициализации), метод Get() с параметром RSH_GET_WAIT_BUFFER_READY_EVENT
	 * вернет код ошибки в качестве результата работы.
	 *
	 * \see
	 * RSH_GET_WAIT_BUFFER_READY_EVENT
	 *
	 */
	virtual U32    __RSHCALLCONV  Stop() = 0;

	/*!
	 *
	 * \~english
	 * \brief
	 * Get (or send) data buffer to device.
	 *
	 * \param [in,out] buffer
	 * Buffer for (with) data.
	 * One of the RshBufferType simple type classes.\n
	 * ::RSH_BUFFER_S8, ::RSH_BUFFER_S16, ::RSH_BUFFER_S32 are used
	 * in most cases for transfer converted by ADC data.
	 * Data is always shifted so MSB will be first (left) bit.\n
	 * ::RSH_BUFFER_DOUBLE can be used too, for transfer
	 * data converted to volts.\n
	 * User must allocate memory for data he wants to transfer before
	 * GetData() Call! One can do so with RshBufferType::Allocate method.
	 *
	 * \param [in] flags
	 * Additional flags for data conversation.
	 * Can be used, for example, to get acces to digital lines
	 * at the same time with data acquisition and write this
	 * information with data. Flag list: ::RSH_DATA_MODES.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * This method is used to transfer data from (or to)
	 * device abstraction library. After receiving ::RSH_GET_WAIT_BUFFER_READY_EVENT
	 * data is ready for transfer. One must allocate buffer. If allocated buffer size
	 * is less than total data available, buffer will be filled with data that fit
	 * into it, no error will be thrown. If the opposite true, its no problem also.
	 * One can check actual data transfered to buffer looking to RshBufferType::size value.
	 *
	 * \remarks
	 * When selecting buffer size in initialization structure its always per channel value.
	 * So, for example, one set buffer size in initialization structure to 2048 and number
	 * of channels to 2, one must expect total data available in GetData() method
	 * to be equal to 2*2048 = 4096 samples.
	 *
	 * \see
	 * RshBufferType | RSH_DATA_MODES
	 *
	 * \~russian
	 * \brief
	 * Получение (или отправка) буфера с данными.
	 *
	 * \param [in, out] buffer
	 * Буфер для данных (или буфер с данными при генерации сигнала).
	 * Одна из реализаций шаблона RshBufferType для простых типов данных.\n
	 * Чаще всего для передачи данных используются типы буфера
	 * ::RSH_BUFFER_S8, ::RSH_BUFFER_S16, ::RSH_BUFFER_S32.
	 * Данные всегда приводятся к старшему биту (исключение - специальные
	 * дополнительные флаги преобразования данных, см. \b flags).\n
	 * Кроме того, иногда удобно использовать ::RSH_BUFFER_DOUBLE,
	 * в котором данные будут сразу в вольтах, а не в МЗР.\n
	 * Пользователь должен сам выделить память под данные перед
	 * вызовом GetData(). Это можно сделать с помощью метода RshBufferType::Allocate.
	 *
	 * \param [in] flags
	 * Дополнительные флаги преобразования данных. Могут использоваться, например,
	 * для того, чтобы получить сигналы с цифровых линий одновременно с данными
	 * аналоговых каналов. Полный список флагов: ::RSH_DATA_MODES.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * Этот метод используется для передачи данных из (или к) библиотеке абстракции устройства.
	 * После получения события ::RSH_GET_WAIT_BUFFER_READY_EVENT данные готовы (уже находятся в компьютере,
	 * в памяти библиотеки абстракции). Можно забрать их в свою программу, предварительно выделив память
	 * в объекте RshBufferType. Если размер выделенного буфера окажется меньше, чем размер доступных данных,
	 * ничего страшного не произойдет - буфер будет заполнен полностью. В обратной ситуации (когда размер
	 * выделенного буфера больше чем размер доступных данных) в буфер будет переложено столько данных,
	 * сколько есть в наличии. В поле RshBufferType::size после вызова GetData() содержится фактический
	 * размер переданных данных.\n
	 * Все размеры всегда в словах (отсчетах АЦП).
	 *
	 * \remarks
	 * В структурах инициализации размер буфера всегда привязан к каналу.
	 * Если, к примеру, при инициализации был задан размер 2048 отсчетов, и выбрано 2 канала,
	 * следует ожидать 2048*2 = 4096 отсчетов при вызове метода GetData().
	 *
	 * \see
	 * RshBufferType | RSH_DATA_MODES
	 *
	 */
	virtual U32    __RSHCALLCONV  GetData( IN OUT RshBaseType* buffer, IN U32 flags=RSH_DATA_MODE_NO_FLAGS) = 0;

	/*!
	 *
	 * \~english
	 * \brief
	 * Access to different information about device and abstraction library.
	 *
	 * \param [in] mode
	 * One of ::RSH_GET constants. Depending on constant,
	 * behavior of method can vary, see corresponding
	 * constant description.
	 *
	 * \param [in, out] adr
	 * Address of one RshBaseType dirived data object.
	 * Depends on \b mode parameter used. Can be NULL
	 * in some cases.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * This method used to perform wide range of
	 * activities due to its flexibility. With it one
	 * can get various static and non-static information
	 * about device and abstraction library, and also control
	 * some device activities.
	 *
	 * \remarks
	 * Always check method return value to be sure that
	 * you actually got infromation you need.\n
	 * In most cases, passed data object will be
	 * changed and filled with data you required,
	 * but sometimes data is passed to device (or library).
	 * In these cases, ::RSH_GET constant have \b _SET suffix,
	 * and data must be prepared \a before method call.
	 *
	 * \see
	 * RSH_GET
	 *
	 * \~russian
	 * \brief
	 * Получение различной информации об устройстве и библиотеке абстракции.
	 *
	 * \param [in] mode
	 * Одна из констант списка ::RSH_GET. В зависимости от используемой
	 * константы, действие метода будет меняться. Все необходимые сведения
	 * приведены в описании конкретной константы.
	 *
	 * \param [in, out] adr
	 * Адрес объекта, унаследованного от класса RshBaseType.
	 * Какой конкретно тип будет использоваться, зависит от
	 * используемого режима (параметр \b mode ). В некоторых
	 * случаях можно передавать NULL.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * Данный метод используется для выполнения широкого спектра
	 * действий ввиду его гибкости. С помощью этого метода
	 * можно получать информацию (как статическую, так и динамическую)
	 * об устройстве и библиотеке абстракции, а также управлять некоторыми
	 * функциями библиотеки и устройства.
	 *
	 * \remarks
	 * Всегда проверяйте возвращаемое методом значение, чтобы быть
	 * уверенными в том, что полученная информация актуальна.\n
	 * В большинстве случаев, передаваемый в метод объект будет модифицирован,
	 * и после вызова метода будет содержать запрошенные данные.
	 * Но в некоторых случаях данные отправляются в устройство (или библиотеку
	 * абстракции). В этих случаях, константы из списка ::RSH_GET имеют
	 * суффикс \b _SET, и данные должны быть подготовлены \a до вызова метода.
	 *
	 *
	 * \see
	 * RSH_GET
	 *
	 */
	virtual U32    __RSHCALLCONV  Get( IN U32 mode, IN OUT RshBaseType* adr=NULL) = 0;
};

#pragma pack(pop)
#endif //IRSH_DEVICE_H
