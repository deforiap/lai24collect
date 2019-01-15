/*!
 * \copyright JSC "Rudnev-Shilyaev"
 * 
 * \file RshConsts_StatusCodes.h
 * \date 25.12.2015
 * \version 1.0 [SDK 2.1]
 * 
 * \~english
 * \brief
 * This file defines all the status codes for RSH SDK. 
 * 
 * \~russian
 * \brief
 * В этом файле содержится описание возвращаемых кодов для RSH SDK.
 * 
 */

#ifndef RSH_STATUS_CODES_H
#define RSH_STATUS_CODES_H

#define _RSH_GROUP_DELIMITER(value)	( value << 24 ) 

#define	_RSH_GROUP_COMMON(value)    ( (value << 16) | _RSH_GROUP_DELIMITER(0x0) )
#define	_RSH_GROUP_DEVICE(value)    ( (value << 16) | _RSH_GROUP_DELIMITER(0x1) )
#define	_RSH_GROUP_THREADS(value)   ( (value << 16) | _RSH_GROUP_DELIMITER(0x2) )
#define	_RSH_GROUP_FILES(value)     ( (value << 16) | _RSH_GROUP_DELIMITER(0x3) )
#define	_RSH_GROUP_DLL(value)       ( (value << 16) | _RSH_GROUP_DELIMITER(0x4) )
#define	_RSH_GROUP_CS(value)        ( (value << 16) | _RSH_GROUP_DELIMITER(0x5) )
#define	_RSH_GROUP_EVENTS(value)    ( (value << 16) | _RSH_GROUP_DELIMITER(0x6) )
#define	_RSH_GROUP_PARAMETER(value) ( (value << 16) | _RSH_GROUP_DELIMITER(0x7) )
#define	_RSH_GROUP_COREDLL(value)   ( (value << 16) | _RSH_GROUP_DELIMITER(0x8) )
#define	_RSH_GROUP_FUNCTION(value)  ( (value << 16) | _RSH_GROUP_DELIMITER(0x9) )
#define	_RSH_GROUP_BUFFER(value)    ( (value << 16) | _RSH_GROUP_DELIMITER(0xA) )
#define	_RSH_GROUP_OBJECT(value)    ( (value << 16) | _RSH_GROUP_DELIMITER(0xB) )
#define	_RSH_GROUP_REGISTRY(value)  ( (value << 16) | _RSH_GROUP_DELIMITER(0xC) )
#define	_RSH_GROUP_INTERFACE(value) ( (value << 16) | _RSH_GROUP_DELIMITER(0xD) )
#define	_RSH_GROUP_MEMORY(value)    ( (value << 16) | _RSH_GROUP_DELIMITER(0xE) )
#define	_RSH_GROUP_PLXAPI(value)    ( (value << 16) | _RSH_GROUP_DELIMITER(0xF) )
#define	_RSH_GROUP_SCRIPT(value)    ( (value << 16) | _RSH_GROUP_DELIMITER(0x10) )
#define	_RSH_GROUP_DATABASE(value)  ( (value << 16) | _RSH_GROUP_DELIMITER(0x11) )
#define	_RSH_GROUP_NETWORK(value)	( (value << 16) | _RSH_GROUP_DELIMITER(0x12) )
#define	_RSH_GROUP_CALIBRATION(value)	( (value << 16) | _RSH_GROUP_DELIMITER(0x13) )


#define	_RSH_GROUP_HDF5(value)      ( (value << 16) | _RSH_GROUP_DELIMITER(0xFA) )
#define	_RSH_GROUP_RSHLAB(value)    ( (value << 16) | _RSH_GROUP_DELIMITER(0xFB) )
#define	_RSH_GROUP_UNIDRIVER(value) ( (value << 16) | _RSH_GROUP_DELIMITER(0xFC) )
#define	_RSH_GROUP_DM(value)        ( (value << 16) | _RSH_GROUP_DELIMITER(0xFD) )
#define	_RSH_GROUP_DPA(value)       ( (value << 16) | _RSH_GROUP_DELIMITER(0xFE) )
#define	_RSH_GROUP_VISA(value)      ( (value << 16) | _RSH_GROUP_DELIMITER(0xFF) )

/*!
 * 
 * \~english
 * \brief
 * Status codes returned by methods of Rsh API.
 * 
 * You can find  numeric values for all codes on the \link page_ErrorCodes Error description page\endlink.	
 * 
 * \~russian
 * \brief
 * Коды ошибок, возвращаемые различными методами Rsh API.
 * 
 * Численные значения всех кодов можно найти на \link page_ErrorCodes странице с описанием ошибок\endlink.	
 * 
 */
typedef enum
{
  //! \ru: Ошибок нет.
  //! \en: No errors.
  RSH_API_SUCCESS = _RSH_GROUP_COMMON(0x0), //0x0000

  //! \ru: Неизвестная ошибка.
  //! \en: Undefined error.
  RSH_API_UNDEFINED = _RSH_GROUP_COMMON(0x1), //0x0000

  //! \ru: Устройство не найдено в системе.
  //! \en: The device was not found in the system.
  RSH_API_DEVICE_NOTFOUND = _RSH_GROUP_DEVICE(0x1), //0x0100 

  //! \ru: Устройство не было инициализировано.
  //! \en: The device was not initialized.
  RSH_API_DEVICE_NOTINITIALIZED = _RSH_GROUP_DEVICE(0x2), //0x0100 

  //! \ru: Не удалось загрузить библиотеку абстракции.
  //! \en: The abstract device dll was not loaded.
  RSH_API_DEVICE_DLLWASNOTLOADED = _RSH_GROUP_DEVICE(0x3), //0x0100 

  //! \ru: Неверный индекс слота для устройства.
  //! \en: Wrong pci slot index.
  RSH_API_DEVICE_WRONGPCIINDEX = _RSH_GROUP_DEVICE(0x4), //0x0100 

  //! \ru: Неверный индекс USB входа для устройства.
  //! \en: Wrong usb socket index.
  RSH_API_DEVICE_WRONGUSBINDEX = _RSH_GROUP_DEVICE(0x5), //0x0100 

  //! \ru: На шине PCI не обнаружено ни одной поддерживаемой платы.
  //! \en: There is no supported PCI(e) device in the system.
  RSH_API_DEVICE_NOBOARDONPCIBUS = _RSH_GROUP_DEVICE(0x6), //0x0100 

  //! \ru: На шине USB не обнаружено ни одного поддерживаемого устройства.
  //! \en: There is no supported USB device in the system.
  RSH_API_DEVICE_NOBOARDONUSBBUS = _RSH_GROUP_DEVICE(0x7), //0x0100 

  //! \ru: Неверно заданы входные параметры функции.
  //! \en: PLX registers are not mapped into physical memory.
  RSH_API_DEVICE_PLXREGISTERSARENOTMAPPED = _RSH_GROUP_DEVICE(0x8), //0x0100 

  //! \ru: Не удается получить данные с устройства.
  //! \en: Couldn't get data from the device.
  RSH_API_DEVICE_CANTGETDATA = _RSH_GROUP_DEVICE(0x9), //0x0100 

  //! \ru: Не удается записать данные в устройство.
  //! \en: Couldn't set data to the device.
  RSH_API_DEVICE_CANTSETDATA = _RSH_GROUP_DEVICE(0xA), //0x0100 

  //! \ru: Не удается провести инициализацию устройства.
  //! \en: Couldn't initialize the device.
  RSH_API_DEVICE_CANTINITIALIZE = _RSH_GROUP_DEVICE(0xB), //0x0100 

  //! \ru: Не удается запустить устройство.
  //! \en: Couldn't start the device.
  RSH_API_DEVICE_CANTSTART = _RSH_GROUP_DEVICE(0xC), //0x0100 

  //! \ru: Не удается остановить устройство.
  //! \en: Couldn't stop the device.
  RSH_API_DEVICE_CANTSTOP = _RSH_GROUP_DEVICE(0xD), //0x0100 

  //! \ru: Не удается создать экземпляр устройства.
  //! \en: Couldn't create a device instance.
  RSH_API_DEVICE_CANTCREATEINSTANCE = _RSH_GROUP_DEVICE(0xE), //0x0100 

  //! \ru: Нет экземпляра устройства.
  //! \en: There is no device instance.
  RSH_API_DEVICE_NOINSTANCE = _RSH_GROUP_DEVICE(0xF), //0x0100 

  //! \ru: Не загружен XILINX.
  //! \en: Data was not loaded into the device XILINX chip.
  RSH_API_DEVICE_LOADXILINX = _RSH_GROUP_DEVICE(0x10), //0x0100 

  //! \ru: Функция не поддерживается устройством.
  //! \en: Function is not supported by this device.
  RSH_API_DEVICE_FUNCTION_NOTSUPPORTED = _RSH_GROUP_DEVICE(0x11), //0x0100 

  //! \ru: Внутренний буфер не инициализирован.
  //! \en: Internal buffer not initialized.
  RSH_API_DEVICE_INTBUFFERNOTINITIALIZED = _RSH_GROUP_DEVICE(0x12), //0x0100 

  //! \ru: Ревизия устройства не обнаружена.
  //! \en: Device revision was not found.
  RSH_API_DEVICE_REVISIONNOTFOUND = _RSH_GROUP_DEVICE(0x13), //0x0100 

  //! \ru: Неверный номер таймера устройства.
  //! \en: Wrong timer number.
  RSH_API_DEVICE_WRONGTIMERNUMBER = _RSH_GROUP_DEVICE(0x14), //0x0100 

  //! \ru: Устройство не было запущено.
  //! \en: The device was not started.
  RSH_API_DEVICE_WASNOTSTARTED = _RSH_GROUP_DEVICE(0x15), //0x0100 

  //! \ru: АЦП устройства остановлено по программному триггеру.
  //! \en: The device ADC unit was stopped with program trigger.
  RSH_API_DEVICE_STOPPEDWITHTRIGGER = _RSH_GROUP_DEVICE(0x16), //0x0100 

  //! \ru: Не удалось выполнить команду IOCTL при работе с драйвером устройства.
  //! \en: Couldn't implement device IOCTL code while communicating with the driver.
  RSH_API_DEVICE_IOCTLFAILED = _RSH_GROUP_DEVICE(0x17), //0x0100 

  //! \ru: К устройству не подключено питание.
  //! \en: There is no power supply for the device.
  RSH_API_DEVICE_NOPOWER = _RSH_GROUP_DEVICE(0x18), //0x0100 

  //! \ru: Несоответствие vid или pid.
  //! \en: Discrepancy of pid or vid.
  RSH_API_DEVICE_WRONGVIDORPID =  _RSH_GROUP_DEVICE(0x19), //0x0100  

  //! \ru: Устройство было ранее захвачено.
  //! \en: Device has been already captured.
  RSH_API_DEVICE_ALREADYCAPTURED =  _RSH_GROUP_DEVICE(0x1A), //0x0100

  //! \ru: Нарушена флеш память устройства.
  //! \en: Device flash memory is inconsistent.
  RSH_API_DEVICE_BADFLASH =  _RSH_GROUP_DEVICE(0x1B), //0x0100


  //! \ru: Не удаётся завершить поток.
  //! \en: Couldn't terminate the thread.
  RSH_API_THREAD_CANTTERMINATE = _RSH_GROUP_THREADS(0x1), //0x0200 

  //! \ru: Не удаётся создать поток.
  //! \en: Couldn't create the thread.
  RSH_API_THREAD_CANTCREATE = _RSH_GROUP_THREADS(0x2), //0x0200 

  //! \ru: Сбор данных в потоке активен.
  //! \en: Data gathering is in process.
  RSH_API_THREAD_GATHERING_INPROCESS = _RSH_GROUP_THREADS(0x3), //0x0200 

  //! \ru: Сбор данных в потоке остановлен.
  //! \en: Data gathering was stopped.
  RSH_API_THREAD_GATHERING_STOPPED = _RSH_GROUP_THREADS(0x4), //0x0200 

  //! \ru: Не удалось открыть файл.
  //! \en: Couldn't open the file.
  RSH_API_FILE_CANTOPEN = _RSH_GROUP_FILES(0x1), //0x0300 

  //! \ru: Не удалось создать файл.
  //! \en: Couldn't create the file.
  RSH_API_FILE_CANTCREATE = _RSH_GROUP_FILES(0x2), //0x0300 

  //! \ru: Имя файла не задано.
  //! \en: The file name is not defined.
  RSH_API_FILE_NAMENOTDEFINED = _RSH_GROUP_FILES(0x3), //0x0300 

  //! \ru: Файл с указанным именем уже существует.
  //! \en: The file already exists.
  RSH_API_FILE_ALREADYEXISTS = _RSH_GROUP_FILES(0x4), //0x0300 

  //! \ru: Не удалось записать данные в файл.
  //! \en: Couldn't write data to the file.
  RSH_API_FILE_CANTWRITE = _RSH_GROUP_FILES(0x5), //0x0300 

  //! \ru: Не удалось прочитать данные из файла.
  //! \en: Couldn't read data from the file.
  RSH_API_FILE_CANTREAD = _RSH_GROUP_FILES(0x6), //0x0300 

  //! \ru: Не удалось закрыть файл.
  //! \en: Couldn't close the file.
  RSH_API_FILE_CANTCLOSE = _RSH_GROUP_FILES(0x7), //0x0300 

  //! \ru: Файл не был открыт.
  //! \en: File was not opened.
  RSH_API_FILE_WASNOTOPENED = _RSH_GROUP_FILES(0x8), //0x0300 

  //! \ru: Не удалось загрузить динамическую библиотеку.
  //! \en: Dll was not loaded.
  RSH_API_DLL_WASNOTLOADED = _RSH_GROUP_DLL(0x1), //0x0400 

  //! \ru: Версия dll не поддерживается.
  //! \en: Loaded dll has unsupported version.
  RSH_API_DLL_VERSIONNOTSUPPORTED = _RSH_GROUP_DLL(0x2), //0x0400

  //! \ru: В загруженной dll не был обнаружен класс StaticFactory.
  //! \en: There is no StaticFactory class inside the dll.
  RSH_API_DLL_NOFACTORY = _RSH_GROUP_DLL(0x3), //0x0400

  //! \ru: Критическая секция уже занята другим потоком.
  //! \en: Critical section is already owned by other thread.
  RSH_API_CRITSECTION_ALREADY_OWNED = _RSH_GROUP_CS(0x1), //0x0500

  //! \ru: Критическая секция не инициализирована.
  //! \en: Critical section is not initialized.
  RSH_API_CRITSECTION_NOTINITIALIZED = _RSH_GROUP_CS(0x2), //0x0500

  //! \ru: Время ожидания наступления события истекло.
  //! \en: Wait event time is out.
  RSH_API_EVENT_WAITTIMEOUT = _RSH_GROUP_EVENTS(0x1), //0x0600

  //! \ru: Не удалось активировать функцию ожидания события.
  //! \en: Wait event failed.
  RSH_API_EVENT_WAITFAILED = _RSH_GROUP_EVENTS(0x2), //0x0600

  //! \ru: Событие не инициализировано.
  //! \en: The event was not initialized.
  RSH_API_EVENT_NOTINITIALIZED = _RSH_GROUP_EVENTS(0x3), //0x0600

  //! \ru: Не удалось деактивировать событие.
  //! \en: Couldn't reset the event.
  RSH_API_EVENT_CANTRESET = _RSH_GROUP_EVENTS(0x4), //0x0600

  //! \ru: Не удалось активировать событие.
  //! \en: Couldn't set the event
  RSH_API_EVENT_CANTSET = _RSH_GROUP_EVENTS(0x5), //0x0600

  //! \ru: Не удалось инициализировать событие.
  //! \en: Couldn't create the event.
  RSH_API_EVENT_CANTCREATE = _RSH_GROUP_EVENTS(0x6), //0x0600

  //! \ru: Адрес входного параметра равен 0.
  //! \en: Input parameter has zero address.
  RSH_API_PARAMETER_ZEROADDRESS = _RSH_GROUP_PARAMETER(0x1), //0x0700

  //! \ru: Параметр не инициализирован.
  //! \en: The parameter was not initialized.
  RSH_API_PARAMETER_NOTINITIALIZED = _RSH_GROUP_PARAMETER(0x2), //0x0700

  //! \ru: Параметр не поддерживается.
  //! \en: The parameter is not supported
  RSH_API_PARAMETER_NOTSUPPORTED = _RSH_GROUP_PARAMETER(0x3), //0x0700

  //! \ru: Неверный входной параметр.
  //! \en: The parameter is invalid.
  RSH_API_PARAMETER_INVALID = _RSH_GROUP_PARAMETER(0x4), //0x0700

  //! \ru: Параметр данного типа данных не поддерживается.
  //! \en: The parameter of this data type is not supported.
  RSH_API_PARAMETER_DATATYPENOTSUPPORTED = _RSH_GROUP_PARAMETER(0x5), //0x0700

  //! \ru: Тип запуска устройства не поддерживается.
  //! \en: Device start mode is not supported.
  RSH_API_PARAMETER_STARTTYPEINVALID = _RSH_GROUP_PARAMETER(0x6), //0x0700

  //! \ru: Не выбраны активные каналы.
  //! \en: There is no selected channel.
  RSH_API_PARAMETER_CHANNELWASNOTSELECTED = _RSH_GROUP_PARAMETER(0x7), //0x0700

  //! \ru: Каналов больше, чем поддерживается.
  //! \en: Too many channels in structure.
  RSH_API_PARAMETER_TOOMANYCHANNELS = _RSH_GROUP_PARAMETER(0x8), //0x0700

  //! \ru: В структуре инициализации присутствуют не все каналы.
  //! \en: Not enough channels in RshChannel structure.
  RSH_API_PARAMETER_NOTENOUGHCHANNELS = _RSH_GROUP_PARAMETER(0x9), //0x0700

  //! \ru: Неверный номер таймера
  //! \en: Wrong timer number
  RSH_API_PARAMETER_WRONGTIMERNUMBER = _RSH_GROUP_PARAMETER(0xA), //0x0700

  //! \ru: Неверный идентификатор устройства во входном параметре.
  //! \en: Wrong device handle in input parameter.
  RSH_API_PARAMETER_WRONGDEVICEHANDLE = _RSH_GROUP_PARAMETER(0xB), //0x0700

  //! \ru: Неверная комбинация активных каналов.
  //! \en: Wrong combination of active channels.
  RSH_API_PARAMETER_WRONGCHANNELCOMBINATION = _RSH_GROUP_PARAMETER(0xC), //0x0700

  //! \ru: Неверное количество каналов.
  //! \en: Wrong channel number.
  RSH_API_PARAMETER_WRONGCHANNELNUMBER = _RSH_GROUP_PARAMETER(0xD), //0x0700

  //! \ru: Режим старта не поддерживается.
  //! \en: Device start mode is not supported.
  RSH_API_PARAMETER_STARTMODENOTSUPPORTED = _RSH_GROUP_PARAMETER(0xE), //0x0700

  //! \ru: Режим конвертации данных не поддерживается.
  //! \en: Device data mode is not supported.
  RSH_API_PARAMETER_DATAMODENOTSUPPORTED = _RSH_GROUP_PARAMETER(0xF), //0x0700

  //! \ru: Режим подключения не поддерживается.
  //! \en: Device connect mode is not supported.
  RSH_API_PARAMETER_CONNECTMODENOTSUPPORTED = _RSH_GROUP_PARAMETER(0x10), //0x0700

  //! \ru: Режим работы устройства не поддерживается.
  //! \en: Device control mode is invalid.
  RSH_API_PARAMETER_CONTROLINVALID = _RSH_GROUP_PARAMETER(0x11), //0x0700

  //! \ru: входной предикат не поддерживается
  //! \en: input parameter predicate not supported
  RSH_API_PARAMETER_WRONGPREDICATE = _RSH_GROUP_PARAMETER(0xA5), //0x0700

  //! \ru: Значение параметра находится вне области допустимых значений.
  //! \en: The parameter is out of range.
  RSH_API_PARAMETER_OUTOFRANGE = _RSH_GROUP_PARAMETER(0xA9), //0x0700

  //! \ru: Порядковый номер устройства задан неверно.
  //! \en: Wrong device index.
  RSH_API_PARAMETER_INVALIDDEVICEBASEINDEX = _RSH_GROUP_PARAMETER(0xAA), //0x0700

  //! \ru: Значение параметра совпадает с внутренним значением соответсвующего параметра.
  //! \en: The same parameter value.
  RSH_API_PARAMETER_SAMEVALUE = _RSH_GROUP_PARAMETER(0xAB), //0x0700

  //! \ru: Core Library указанного типа не существует.
  //! \en: Core Library of this type does not exist.
  RSH_API_COREDLL_NOTEXISTS = _RSH_GROUP_COREDLL(0x1), //0x0800

  //! \ru: Core Library не была загружена.
  //! \en: Core Library was not loaded.
  RSH_API_COREDLL_WASNOTLOADED = _RSH_GROUP_COREDLL(0x2), //0x0800

  //! \ru: В Core Library не найден StaticFactory.
  //! \en: There is no StaticFactory in Core Library.
  RSH_API_COREDLL_DLLNOFACTORY = _RSH_GROUP_COREDLL(0x3), //0x0800

  //! \ru: Core Library интерфейс не соответствует.
  //! \en: Core Library interface does not match.
  RSH_API_COREDLL_INTERFACEDOESNOTMATCH = _RSH_GROUP_COREDLL(0x4), //0x0800

  //! \ru: Не удается открыть ветку реестра для Core Library.
  //! \en: Couldn't open registry key for Core Library.
  RSH_API_COREDLL_REGISTRYKEYCANTOPEN = _RSH_GROUP_COREDLL(0x5), //0x0800

  //! \ru: Не удается найти запись в реестре с полным путем к Core Library.
  //! \en: Couldn't find path record in registry for Core Library.
  RSH_API_COREDLL_REGISTRYPATHRECNOTFOUND = _RSH_GROUP_COREDLL(0x6), //0x0800

  //! \ru: Версия Core Library не поддерживается библиотекой абстракции.
  //! \en: Core Library version doesn't correspond with abstraction library version.
  RSH_API_COREDLL_UNSUPPORTEDVERSION = _RSH_GROUP_COREDLL(0x7), //0x0800

  //! \ru: Внутренний поток сбора данных не остановлен.
  //! \en: Data gathering thread was not stopped.
  RSH_API_COREDLL_GATHERINGINPROCESS = _RSH_GROUP_COREDLL(0x11), //0x0800

  //! \ru: Сбор данных не был запущен.
  //! \en: Gathering did not start.
  RSH_API_COREDLL_GATHERINGDIDNOTSTART = _RSH_GROUP_COREDLL(0x12), //0x0800

  //! \ru: Поток непрерывного сбора активен
  //! \en: Persistent collection thread is in active state.
  RSH_API_COREDLL_PERSISTENTGTHREADISACTIVE = _RSH_GROUP_COREDLL(0x13), //0x0800

  //! \ru: Данные не получены, буфер не заполнен
  //! \en: Data was not acquired, buffer is empty.
  RSH_API_COREDLL_COLLECTINGBUFFERZEROSIZE = _RSH_GROUP_COREDLL(0x14), //0x0800

  //! \ru: Не найдена ревизия устройства
  //! \en: Device revision was not found.
  RSH_API_COREDLL_DEVICEREVISIONNOTFOUND = _RSH_GROUP_COREDLL(0x15), //0x0800

  //! \ru: Ревизия устройства не поддерживается.
  //! \en: Device revision is not supported.
  RSH_API_COREDLL_DEVICEREVISIONNOTSUPPORTED = _RSH_GROUP_COREDLL(0x16), //0x0800

  //! \ru: RSH_API_COREDLL_WRONGPORTNUMBER
  //! \en: Wrong port number.
  RSH_API_COREDLL_WRONGPORTNUMBER = _RSH_GROUP_COREDLL(0x17), //0x0800

  //! \ru: RSH_API_COREDLL_WRONGTIMERNUMBER
  //! \en: Wrong timer number.
  RSH_API_COREDLL_WRONGTIMERNUMBER = _RSH_GROUP_COREDLL(0x18), //0x0800

  //! \ru: RSH_API_COREDLL_REGSPACEDOESNOTEXIST.
  //! \en: RSH_API_COREDLL_REGSPACEDOESNOTEXIST.
  RSH_API_COREDLL_REGSPACEDOESNOTEXIST = _RSH_GROUP_COREDLL(0x19), //0x0800

  //! \ru: Не задано пользовательское событие.
  //! \en: User buffer event is not defined.
  RSH_API_COREDLL_USERBUFFEREVENTNOTDEFINED = _RSH_GROUP_COREDLL(0x1A), //0x0800

  //! \ru: Время ожидания готовности буфера истекло.
  //! \en: Wait buffer time is out.
  RSH_API_COREDLL_USERBUFFERWAITTIMEOUT = _RSH_GROUP_COREDLL(0x1B), //0x0800

  //! \ru: Не удалось создать экземпляр класса PLX9054.
  //! \en: Couldn't create an instance of plx9054 class.
  RSH_API_COREDLL_CANTCREATEPLX9054CLASS = _RSH_GROUP_COREDLL(0x31), //0x0800

  //! \ru: Не удалось создать экземпляр класса PLX9050.
  //! \en: Couldn't create an instance of plx9050 class.
  RSH_API_COREDLL_CANTCREATEPLX9050CLASS = _RSH_GROUP_COREDLL(0x32), //0x0800

  //! \ru: Не удалось создать экземпляр класса PLX8311.
  //! \en: Couldn't create an instance of plx8311 class.
  RSH_API_COREDLL_CANTCREATEPLX8311CLASS = _RSH_GROUP_COREDLL(0x33), //0x0800

  //! \ru: Не удалось создать экземпляр класса RSHUSB.
  //! \en: Couldn't create an instance of RSHUSB class.
  RSH_API_COREDLL_CANTCREATERSHUSBCLASS = _RSH_GROUP_COREDLL(0x34), //0x0800

  //! \ru: Не удалось создать экземпляр класса RSHVISA.
  //! \en: Couldn't create an instance of RSHVISA class.
  RSH_API_COREDLL_CANTCREATERSHVISACLASS = _RSH_GROUP_COREDLL(0x35), //0x0800

  //! \ru: Функция не определена.
  //! \en: The function is not defined.
  RSH_API_FUNCTION_NOTDEFINED = _RSH_GROUP_FUNCTION(0x1), //0x0900

  //! \ru: Произошла ошибка внутри функции.
  //! \en: Function has failed with error.
  RSH_API_FUNCTION_ERRORHAPPEND = _RSH_GROUP_FUNCTION(0x2), //0x0900

  //! \ru: Функция не поддерживается.
  //! \en: The function is not supported.
  RSH_API_FUNCTION_NOTSUPPORTED = _RSH_GROUP_FUNCTION(0x3), //0x0900

  //! \ru: Get-код не определен внутри метода IRshDevice::Get().
  //! \en: Get-code is not defined inside IRshDevice::Get() method.
  RSH_API_FUNCTION_GETCODENOTDEFINED = _RSH_GROUP_FUNCTION(0x4), //0x0900

  //! \ru: Буфер не инициализирован.
  //! \en: The buffer is not initialized.
  RSH_API_BUFFER_NOTINITIALIZED = _RSH_GROUP_BUFFER(0x1), //0x0A00

  //! \ru: Физический размер буфера равен нулю. Вероятно буфер не был инициализирован.
  //! \en: Buffer size is zero. Probably the buffer is not initialized.
  RSH_API_BUFFER_ZEROSIZE = _RSH_GROUP_BUFFER(0x2), //0x0A00

  //! \ru: Формат входного и выходного буфера не совпадает.
  //! \en: Input and output buffer format are not the same.
  RSH_API_BUFFER_INANDOUTMISMATCH = _RSH_GROUP_BUFFER(0x3), //0x0A00

  //! \ru: Буфер с таким типом данных не поддерживается.
  //! \en: The buffer has unsupported data type.
  RSH_API_BUFFER_WRONGDATATYPE = _RSH_GROUP_BUFFER(0x4), //0x0A00

  //! \ru: Ошибка при проведении вычислений.
  //! \en: There is a runtime calculation error.
  RSH_API_BUFFER_PROCESSING_ERROR = _RSH_GROUP_BUFFER(0x5), //0x0A00

  //! \ru: Объем данных в буфере превышает допустимый размер.
  //! \en: Data Buffer size is exceeded.
  RSH_API_BUFFER_SIZEISEXCEEDED = _RSH_GROUP_BUFFER(0x6), //0x0A00

  //! \ru: Буфер пуст.
  //! \en: The buffer is empty.
  RSH_API_BUFFER_ISEMPTY = _RSH_GROUP_BUFFER(0x7), //0x0A00

  //! \ru: Размер копируемого буфера не соответствует размеру буфера, в который производится копирование.
  //! \en: Size mismatch when copy operation takes place.
  RSH_API_BUFFER_SIZEMISMATCH = _RSH_GROUP_BUFFER(0x8), //0x0A00

  //! \ru: Буфер не заполнен до конца.
  //! \en: The buffer is not completed.
  RSH_API_BUFFER_NOTCOMPLETED = _RSH_GROUP_BUFFER(0x9), //0x0A00

  //! \ru: Попытка выделения памяти размером 0 байт.
  //! \en: There was an attempt to allocate a buffer of zero size.
  RSH_API_BUFFER_ALLOCATIONZEROSIZE = _RSH_GROUP_BUFFER(0xA), //0x0A00

  //! \ru: Размер буфера недостаточен для того, чтобы вместить все данные.
  //! \en: Buffer size is too small for contain all data.
  RSH_API_BUFFER_INSUFFICIENTSIZE = _RSH_GROUP_BUFFER(0xB), //0x0A00

  //! \ru: Размер буфера задан неверно.
  //! \en: Buffer size is not correct.
  RSH_API_BUFFER_WRONGSIZE = _RSH_GROUP_BUFFER(0xC), //0x0A00

  //! \ru: Объект не найден.
  //! \en: The object was not found.
  RSH_API_OBJECT_NOTFOUND = _RSH_GROUP_OBJECT(0x1), //0x0B00

  //! \ru: Ссылка на объект не найдена.
  //! \en: The object reference was not found.
  RSH_API_OBJECT_REFERENCENOTFOUND = _RSH_GROUP_OBJECT(0x2), //0x0B00

  //! \ru: Объект изменился.
  //! \en: The object has changed.
  RSH_API_OBJECT_HASCHANGED = _RSH_GROUP_OBJECT(0x3), //0x0B00
    
  //! \ru: Объект уже существует.
  //! \en: The object already exists.
  RSH_API_OBJECT_ALREADYEXISTS = _RSH_GROUP_OBJECT(0x4), //0x0B00

  //! \ru: Неподдерживаемый тип объекта.
  //! \en: Unsupported object type.
  RSH_API_OBJECT_UNSUPPORTEDTYPE = _RSH_GROUP_OBJECT(0x5), //0x0B00

  //! \ru: Не найдена запись в реестре.
  //! \en: Registry key value was not found.
  RSH_API_REGISTRY_KEYCANTOPEN = _RSH_GROUP_REGISTRY(0x1), //0x0C00

  //! \ru: Не найдена запись path в реестре.
  //! \en: Dll Path record value was not found.
  RSH_API_REGISTRY_PATHRECNOTFOUND = _RSH_GROUP_REGISTRY(0x2), //0x0C00

  //! \ru: Не найдена запись UIName в реестре.
  //! \en: Dll UIName record value was not found.
  RSH_API_REGISTRY_UINAMERECNOTFOUND = _RSH_GROUP_REGISTRY(0x3), //0x0C00

  //! \ru: Интерфейс объекта в Dll не соответсвует запрашиваемому.
  //! \en: Interface of object in Dll does not match requested interface type.
  RSH_API_INTERFACE_DOESNOTMATCH = _RSH_GROUP_INTERFACE(0x1), //0x0D00

  //! \ru: Не удается создать экземпляр объекта в фабрике.
  //! \en: Couldn't create an instance of an object in Factory.
  RSH_API_INTERFACE_CANTCREATEINSTANCE = _RSH_GROUP_INTERFACE(0x2), //0x0D00

  //! \ru: Интерфейс не был инициализирован.
  //! \en: Interface was not initialized.
  RSH_API_INTERFACE_WASNOTINITIALIZED = _RSH_GROUP_INTERFACE(0x3), //0x0D00

  //! \ru: RshStaticFactory::CreateInstance не задан адрес объекта получателя интерфейса.
  //! \en: RshStaticFactory::CreateInstance zero parameter address for interface object.
  RSH_API_INTERFACE_CANTCREATEINSTANCE_PARAMETER_ZEROADDRESS = _RSH_GROUP_INTERFACE(0x4),  //0x0D00

  //! \ru: Ошибка работы с памятью.
  //! \en: Memory error.
  RSH_API_MEMORY_ERROR = _RSH_GROUP_MEMORY(0x1), //0x0E00

  //! \ru: Не удалось выделить память.
  //! \en: Couldn't allocate memory.
  RSH_API_MEMORY_ALLOCATIONERROR = _RSH_GROUP_MEMORY(0x2), //0x0E00

  //! \ru: Сбой при копировании из одной области памяти в другую.
  //! \en: Copy memory failure.
  RSH_API_MEMORY_COPYERROR = _RSH_GROUP_MEMORY(0x3), //0x0E00

  //! \ru: Cбой в работе PLX API.
  //! \en: PLX API failed.
  RSH_API_PLXAPI_FAILED = _RSH_GROUP_PLXAPI(0x1), //0x0F00

  //! \ru: PLX API - неверный параметр, указатель на null.
  //! \en: PLX API - null parameter.
  RSH_API_PLXAPI_NULLPARAM = _RSH_GROUP_PLXAPI(0x2), //0x0F00

  //! \ru: Функция PLX API не поддерживается.
  //! \en: PLX API - function is not supported.
  RSH_API_PLXAPI_UNSUPPORTEDFUNCTION = _RSH_GROUP_PLXAPI(0x3), //0x0F00

  //! \ru: В системе нет активного драйвера устройства.
  //! \en: There is no active PLX driver in the system.
  RSH_API_PLXAPI_NOACTIVEDRIVER = _RSH_GROUP_PLXAPI(0x4), //0x0F00

  //! \ru: PLX API - Ошибка доступа к конфигурации
  //! \en: PLX API - config access failed.
  RSH_API_PLXAPI_CONFIGACCESSFAILED = _RSH_GROUP_PLXAPI(0x5), //0x0F00

  //! \ru: PLX API - неверная информация об устройстве
  //! \en: PLX API - invalid device info.
  RSH_API_PLXAPI_INVALIDDEVICEINFO = _RSH_GROUP_PLXAPI(0x6), //0x0F00

  //! \ru: Версия PLX-драйвера не соответсвует версии используемой PLX-API.
  //! \en: PLX API invalid driver version.
  RSH_API_PLXAPI_INVALIDDRIVERVERSION = _RSH_GROUP_PLXAPI(0x7), //0x0F00

  //! \ru: PLX API - неверное значение смещения.
  //! \en: PLX API - invalid zero offset.
  RSH_API_PLXAPI_INVALIDOFFSET = _RSH_GROUP_PLXAPI(0x8), //0x0F00

  //! \ru: PLX API - неверные данные.
  //! \en: PLX API - invalid data.
  RSH_API_PLXAPI_INVALIDDATA = _RSH_GROUP_PLXAPI(0x9), //0x0F00

  //! \ru: PLX API - неверный размер.
  //! \en: PLX API - invalid size.
  RSH_API_PLXAPI_INVALIDSIZE = _RSH_GROUP_PLXAPI(0xA), //0x0F00

  //! \ru: PLX API - неверный адрес.
  //! \en: PLX API - invalid address.
  RSH_API_PLXAPI_INVALIDADDRESS = _RSH_GROUP_PLXAPI(0xB), //0x0F00

  //! \ru: PLX API - неверный тип доступа.
  //! \en: PLX API - invalid access type.
  RSH_API_PLXAPI_INVALIDACCESSTYPE = _RSH_GROUP_PLXAPI(0xC), //0x0F00

  //! \ru: PLX API - неверный индекс.
  //! \en: PLX API - invalid index.
  RSH_API_PLXAPI_INVALIDINDEX = _RSH_GROUP_PLXAPI(0xD), //0x0F00

  //! \ru: PLX API - неверное значение состояния питания.
  //! \en: PLX API - invalid power state.
  RSH_API_PLXAPI_INVALIDPOWERSTATE = _RSH_GROUP_PLXAPI(0xE), //0x0F00

  //! \ru: PLX API - неверное пространство ввода-вывода.
  //! \en: PLX API - invalid IO space.
  RSH_API_PLXAPI_INVALIDIOPSPACE = _RSH_GROUP_PLXAPI(0xF), //0x0F00

  //! \ru: PLX API - неверный дескриптор.
  //! \en: PLX API invalid handle.
  RSH_API_PLXAPI_INVALIDHANDLE = _RSH_GROUP_PLXAPI(0x10), //0x0F00

  //! \ru: PLX API - неверное простаноство pci.
  //! \en: PLX API - invalid pci space.
  RSH_API_PLXAPI_INVALIDPCISPACE = _RSH_GROUP_PLXAPI(0x11), //0x0F00

  //! \ru: PLX API - неверный индекс шины данных.
  //! \en: PLX API - invalid BUS index.
  RSH_API_PLXAPI_INVALIDBUSINDEX = _RSH_GROUP_PLXAPI(0x12), //0x0F00

  //! \ru: PLX API - недостаточно ресурсов.
  //! \en: PLX API - insufficient resources.
  RSH_API_PLXAPI_INSUFFICIENTRESOURCES = _RSH_GROUP_PLXAPI(0x13), //0x0F00

  //! \ru: PLX API - время ожидания готовности функции истекло.
  //! \en: PLX API - wait time out.
  RSH_API_PLXAPI_WAITTIMEOUT = _RSH_GROUP_PLXAPI(0x14), //0x0F00

  //! \ru: PLX API - ожидание было отменено. 
  //! \en: PLX API - wait canceled.
  RSH_API_PLXAPI_WAITCANCELED = _RSH_GROUP_PLXAPI(0x15), //0x0F00

  //! \ru: PLX API - ПДП каналы недоступны.
  //! \en: PLX API - DMA channel unavailable.
  RSH_API_PLXAPI_DMACHANNELUNAVAILABLE = _RSH_GROUP_PLXAPI(0x16), //0x0F00

  //! \ru: PLX API - неверный канал ПДП.
  //! \en: PLX API - DMA channel invalid.
  RSH_API_PLXAPI_DMACHANNELINVALID = _RSH_GROUP_PLXAPI(0x17), //0x0F00

  //! \ru: PLX API - передача данных ПДП завершена.
  //! \en: PLX API DMA done.
  RSH_API_PLXAPI_DMADONE = _RSH_GROUP_PLXAPI(0x18), //0x0F00

  //! \ru: PLX API - ПДП приостановлен.
  //! \en: PLX API - DMA paused.
  RSH_API_PLXAPI_DMAPAUSED = _RSH_GROUP_PLXAPI(0x19), //0x0F00

  //! \ru: PLX API - Канал ПДП занят.
  //! \en: PLX API - DMA in progress.
  RSH_API_PLXAPI_DMAINPROGRESS = _RSH_GROUP_PLXAPI(0x1A), //0x0F00

  //! \ru: PLX API - Неверная команда ПДП.
  //! \en: PLX API - DMA command invalid.
  RSH_API_PLXAPI_DMACOMMANDINVALID = _RSH_GROUP_PLXAPI(0x1B), //0x0F00

  //! \ru: PLX API - неверный приоритет каналов ПДП.
  //! \en: PLX API - DMA invalid channel priority.
  RSH_API_PLXAPI_DMAINVALIDCHANNELPRIORITY = _RSH_GROUP_PLXAPI(0x1C), //0x0F00

  //! \ru: PLX API - ошибка поулчения страниц ПДП SGL
  //! \en: PLX API - DMA SGL pages get error.
  RSH_API_PLXAPI_DMASGLPAGESGETERROR = _RSH_GROUP_PLXAPI(0x1D), //0x0F00

  //! \ru: PLX API - ошибка захвата страниц ПДП SGL.
  //! \en: PLX API - DMA SGL pages lock error.
  RSH_API_PLXAPI_DMASGLPAGESLOCKERROR = _RSH_GROUP_PLXAPI(0x1E), //0x0F00

  //! \ru: PLX API - MU FIFO пусто.
  //! \en: PLX API - MU FIFO empty.
  RSH_API_PLXAPI_MUFIFOEMPTY = _RSH_GROUP_PLXAPI(0x1F), //0x0F00

  //! \ru: PLX API - MU FIFO заполнено.
  //! \en: PLX API - MU FIFO full.
  RSH_API_PLXAPI_MUFIFOFULL = _RSH_GROUP_PLXAPI(0x20), //0x0F00

  //! \ru: PLX API - отсутствует питание.
  //! \en: PLX API - power down.
  RSH_API_PLXAPI_POWERDOWN = _RSH_GROUP_PLXAPI(0x21), //0x0F00

  //! \ru: PLX API - HS не поддерживается.
  //! \en: PLX API - HS not supported.
  RSH_API_PLXAPI_HSNOTSUPPORTED = _RSH_GROUP_PLXAPI(0x22), //0x0F00

  //! \ru: PLX API - VPD не поддерживается.
  //! \en: PLX API - VPD not supported.
  RSH_API_PLXAPI_VPDNOTSUPPORTED = _RSH_GROUP_PLXAPI(0x23), //0x0F00

  //! \ru: Устройство PLX захвачено другим потоком или процессом
  //! \en: PLX device is owned by another calling thread or process.
  RSH_API_PLXAPI_DEVICEINUSE = _RSH_GROUP_PLXAPI(0x24), //0x0F00

  //! \ru: PLX API - устройство отключено.
  //! \en: PLX API - device disabled.
  RSH_API_PLXAPI_DEVICEDISABLED = _RSH_GROUP_PLXAPI(0x25), //0x0F00

  //! \ru: Последняя ошибка PLX API
  //! \en: PLX API last error.
  RSH_API_PLXAPI_LASTERROR = _RSH_GROUP_PLXAPI(0x26), //0x0F00

  //! \ru: PLX API - устройство не инициализировано
  //! \en: PLX API - device is not initialized.
  RSH_API_PLXAPI_DEVICENOTINITIALIZED = _RSH_GROUP_PLXAPI(0x27), //0x0F00

  //! \ru: PLX API - не удалось создать объект устройства.
  //! \en: PLX API - can't create device object.
  RSH_API_PLXAPI_CANTCREATEDEVICEOBJECT = _RSH_GROUP_PLXAPI(0x28), //0x0F00

  //! \ru: Серийный номер платы не прописан в EEPROM.
  //! \en: There is no serial number within EEPROM.
  RSH_API_PLXAPI_EEPROMNOSERIAL = _RSH_GROUP_PLXAPI(0x29), //0x0F00

  //! \ru: Ошибка синтаксиса в скрипте
  //! \en: Script syntax error
  RSH_API_SCRIPT_SYNTAXERROR = _RSH_GROUP_SCRIPT(0x1), //0x1000

  //! \ru: Не удалось определить значение
  //! \en: Couldn't evaluate value
  RSH_API_SCRIPT_CANTEVALUATE = _RSH_GROUP_SCRIPT(0x2), //0x1000

  //! \ru: Не найдена функция запуска
  //! \en: Start function not found
  RSH_API_SCRIPT_STARTFUNCTIONDOESNOTEXIST = _RSH_GROUP_SCRIPT(0x3), //0x1000

  //! \ru: Заданная функция не существует.
  //! \en: Function specified does not exists.
  RSH_API_SCRIPT_FUNCTIONDOESNOTEXIST = _RSH_GROUP_SCRIPT(0x4), //0x1000

  //! \ru: Не удалось открыть базу данных.
  //! \en: Couldn't open database.
  RSH_API_DATABASE_CANTOPEN = _RSH_GROUP_DATABASE(0x1), //0x1100

  //! \ru: База данных не откыта.
  //! \en: Database was not opened.
  RSH_API_DATABASE_WASNOTOPENED = _RSH_GROUP_DATABASE(0x2), //0x1100

  //! \ru: Не удалось создать таблицу в базе данных.
  //! \en: Couldn't create table in database.
  RSH_API_DATABASE_CANTCREATETABLE = _RSH_GROUP_DATABASE(0x3), //0x1100

  //! \ru: Не удалось выполнить команду select.
  //! \en: Couldn't do select from table.
  RSH_API_DATABASE_CANTSELECTFROMTABLE = _RSH_GROUP_DATABASE(0x4), //0x1100

  //! \ru: Таблица пуста.
  //! \en: Database table is empty.
  RSH_API_DATABASE_TABLEISEMPTY = _RSH_GROUP_DATABASE(0x5), //0x1100

  //! \ru: не удалось осуществить запись в базу данных.
  //! \en: Couldn't write record in databse.
  RSH_API_DATABASE_CANTWRITERECORD = _RSH_GROUP_DATABASE(0x6), //0x1100

  //! \ru: Не удалось удалить запись из таблицы.
  //! \en: Couldn't delete from databse table.
  RSH_API_DATABASE_CANTDELETEFROMTABLE = _RSH_GROUP_DATABASE(0x7), //0x1100

  //! \ru: Запись уже существует в базе данных.
  //! \en: Database record already exists.
  RSH_API_DATABASE_RECORDALREADYEXISTS = _RSH_GROUP_DATABASE(0x8), //0x1100

  //! \ru: неверный предикат.
  //! \en: Wrong predicate.
  RSH_API_DATABASE_WRONGPREDICATE = _RSH_GROUP_DATABASE(0x9), //0x1100

  //! \ru: Запись не найдена в базе данных.
  //! \en: Database record was not found.
  RSH_API_DATABASE_RECORDNOTFOUND = _RSH_GROUP_DATABASE(0xA), //0x1100


  
  //! \ru: Группа с указанным именем не существует в HDF5 файле.
  //! \en: Selected group doesn't exists within HDF5 file.
  RSH_API_HDF5_GROUPDOESNTEXIST = _RSH_GROUP_HDF5(0x1), //0xFA00

  //! \ru: Не удаётся создать группу в HDF5 файле.
  //! \en: Can't create the specified group in HDF5 file.
  RSH_API_HDF5_GROUPCANTCREATE = _RSH_GROUP_HDF5(0x2), //0xFA00

  //! \ru: Не удаётся найти объект с указанным индексом в группе.
  //! \en: There is no object with selected index in the selected group.
  RSH_API_HDF5_GROUPOBJECTINDEXDOESNTEXIST = _RSH_GROUP_HDF5(0x3), //0xFA00

  //! \ru: Указанный объект является группой.
  //! \en: Selected object is a group.
  RSH_API_HDF5_OBJECTISAGROUP = _RSH_GROUP_HDF5(0x4), //0xFA00

  //! \ru: Набор данных с указанным именем не существует в HDF5 файле.
  //! \en: DataSet doesn't exists within HDF5 file.
  RSH_API_HDF5_DATASETDOESNTEXIST = _RSH_GROUP_HDF5(0x10), //0xFA00

  //! \ru: Неверное смещение в DataSet.
  //! \en: Wrong offset in DataSet.
  RSH_API_HDF5_DATASETWRONGOFFSET = _RSH_GROUP_HDF5(0x11), //0xFA00

   //! \ru: При работе с DataSet произошла ошибка.
  //! \en: Failure caused by the DataSet operations.
  RSH_API_HDF5_EXCEPTION_DATASETOPERATIONFAIL = _RSH_GROUP_HDF5(0x20), //0xFA00

  //! \ru: При работе с DataSpace произошла ошибка.
  //! \en: Failure caused by the DataSpace operations.
  RSH_API_HDF5_EXCEPTION_DATASPACEOPERATIONFAIL = _RSH_GROUP_HDF5(0x21), //0xFA00

  //! \ru: При работе с HDF5-файлом произошла ошибка.
  //! \en: Failure caused by the hdf5 file operations.
  RSH_API_HDF5_EXCEPTION_FILEOPERATIONFAIL = _RSH_GROUP_HDF5(0x22), //0xFA00

  //! \ru: Не удаётся создать HDF5-файл.
  //! \en: Can't create HDF5 file.
  RSH_API_HDF5_EXCEPTION_FILECANTCREATE = _RSH_GROUP_HDF5(0x23), //0xFA00

  //! \ru: Не удаётся открыть HDF5-файл.
  //! \en: Can't open HDF5 file.
  RSH_API_HDF5_EXCEPTION_FILECANTOPEN = _RSH_GROUP_HDF5(0x24), //0xFA00

  //! \ru: Ошибка чтения HDF5-файла.
  //! \en: Can't read HDF5 file.
  RSH_API_HDF5_EXCEPTION_FILECANTREAD = _RSH_GROUP_HDF5(0x25), //0xFA00

  //! \ru: Ошибка записи HDF5-файла.
  //! \en: Can't write HDF5 file.
  RSH_API_HDF5_EXCEPTION_FILECANTWRITE = _RSH_GROUP_HDF5(0x26), //0xFA00

  //! \ru: При работе с DataType произошла ошибка.
  //! \en: Failure caused by the DataType operations.
  RSH_API_HDF5_EXCEPTION_DATATYPEOPERATIONFAIL = _RSH_GROUP_HDF5(0x27), //0xFA00

  //! \ru: При работе с Attribute произошла ошибка.
  //! \en: Failure caused by the Attribute operations.
  RSH_API_HDF5_EXCEPTION_ATTRIBUTEOPERATIONFAIL = _RSH_GROUP_HDF5(0x28), //0xFA00

  //! \ru: Неверный путь к данным.
  //! \en: Wrong data path.
  RSH_API_HDF5_WRONGDATAPATH = _RSH_GROUP_HDF5(0x30), //0xFA00

  //! \ru: Тип данных объекта в HDF файле не соотвествует с запрашиваемому типу объекта.
  //! \en: Demanded data type doesn't match to HDF object data type.
  RSH_API_HDF5_TYPEMISMATCH = _RSH_GROUP_HDF5(0x40), //0xFA00

  

  //! \ru: Не найдено устройство типа вольтметр.
  //! \en: Voltmeter was not found.
  RSH_API_RSHLAB_VOLTMETERNOTFOUND = _RSH_GROUP_RSHLAB(0x1), //0xFB00

  //! \ru: Не найдено устройство типа генератор.
  //! \en: Generator was not found.
  RSH_API_RSHLAB_GENERATORNOTFOUND = _RSH_GROUP_RSHLAB(0x2), //0xFB00

  //! \ru: Не найдено целевое устройство.
  //! \en: Target device was not found.
  RSH_API_RSHLAB_TARGETDEVICENOTFOUND = _RSH_GROUP_RSHLAB(0x3), //0xFB00


  //! \ru: Не удалось загрузить библиотеку RshUniDriver.dll
  //! \en: RshUniDriver.dll was not loaded
  RSH_API_UNIDRIVER_DLLWASNOTLOADED = _RSH_GROUP_UNIDRIVER(0x1), //0xFC00

  //! \ru: Библиотека DM.dll не загружена.
  //! \en: Library DM.dll was not loaded.
  RSH_API_DM_DLLWASNOTLOADED = _RSH_GROUP_DM(0x1), //0xFD00

  //! \ru: Не удалось загрузить алгоритмическую библиотеку DPA.dll
  //! \en: DPA.dll was not loaded
  RSH_API_DPA_DLLWASNOTLOADED = _RSH_GROUP_DPA(0x1), //0xFE00

  //! \ru: В сигнале не найден момент синхронизации удовлетворяющий заданным параметрам.
  //! \en: synchro trigger not found.
  RSH_API_DPA_FINDTRIGGER_NOTFOUND = _RSH_GROUP_DPA(0x2), //0xFE00

  //! \ru: Тип структуры не соответсвует выполняемому алгоритму.
  //! \en: Input parameter structure is not correspond to algorithmic class type.
  RSH_API_DPA_FUNCTION_CLASS_MISMATCH = _RSH_GROUP_DPA(0x3), //0xFE00

  //! \ru: Алгоритмический класс выбранного типа не определен в библиотеке DPA.
  //! \en: Algorithmic  class of selected type is not defined inside DPA library.
  RSH_API_DPA_FUNCTION_CLASS_NOTDEFINED = _RSH_GROUP_DPA(0x4), //0xFE00

  //! \ru: Не удалось подключиться к драйверу VISA.
  //! \en: Couldn't connect to VISA driver.
  RSH_API_VISA_CANTCONNECTTODRIVER = _RSH_GROUP_VISA(0x1), //0xFF00


  //! \ru: Неизвестная ошибка при работе с сетью.
  //! \en: General (unknown) network failure.
  RSH_API_NET_GENERALFAILURE  = _RSH_GROUP_NETWORK(0x1),

  //! \ru: Не удалось создать сокет.
  //! \en: Couldn't create socket.
  RSH_API_NET_COULDNTCREATESOCKET = _RSH_GROUP_NETWORK(0x2),

  //! \ru: Не удалось создать event.
  //! \en: Couldn't create event.
  RSH_API_NET_COULDNTCREATEEVENT = _RSH_GROUP_NETWORK(0x3),

  //! \ru: Не удалось выполнить функцию select.
  //! \en: Event select function failed.
  RSH_API_NET_EVENTSELECTFAILED = _RSH_GROUP_NETWORK(0x4),

  //! \ru: Не удалось открыть UDP сокет.
  //! \en: UDP socket bind failed.
  RSH_API_NET_UDPSOCKETBINDFAILED = _RSH_GROUP_NETWORK(0x5),

  //! \ru: Не удалось выполнить подключение через TCP сокет.
  //! \en: TCP socket connect failed.
  RSH_API_NET_TCPSOCKETCONNECTFAILED = _RSH_GROUP_NETWORK(0x6),

  //! \ru: Не удалось выполнить операцию получения данных из сокета.
  //! \en: Socket receive data operation failed.
  RSH_API_NET_SOCKETRECEIVEDATAFAILED = _RSH_GROUP_NETWORK(0x7),

  //! \ru: Не удалось выполнить операцию отправки данных.
  //! \en: Socket send data operation failed.
  RSH_API_NET_SOCKETSENDDATAFAILED = _RSH_GROUP_NETWORK(0x8),

  //! \ru: Не удалось выполнить операцию закрытия сокета.
  //! \en: Close socket operation failed.
  RSH_API_NET_CLOSESOCKETFAILED = _RSH_GROUP_NETWORK(0x9),

  
  //! \ru: Поле RshCalibrationItemBase::id не соответсвует ни одному RshCalibrationItem определённому внутри dll.
  //! \en: There is no RshCalibrationItem inside dll with id equal to requested RshCalibrationItemBase::id.
  RSH_API_CALIBRATION_ITEMNOTFOUND =  _RSH_GROUP_CALIBRATION(0x1),

} RSH_STATUS;


#endif //RSH_STATUS_CODES_H
