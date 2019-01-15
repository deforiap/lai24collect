/*!
 * \copyright JSC "Rudnev-Shilyaev"
 * 
 * \file RshErrorDescription.h
 * \date 23.12.2015
 * \version 1.0 [SDK 2.1]
 * 
 * \~english
 * \brief
 *  Simple structure to hold error related data.
 * 
 * \~russian
 * \brief
 * Простая структура для хранения кода ошибки и строковых констант с ее описанием.
 * 
 */

#ifndef RSH_ERROR_DESCRIPTION_H
#define RSH_ERROR_DESCRIPTION_H

#include "RshMacro.h"
#include "RshDefChk.h"
#include "RshConsts_StatusCodes.h"



/*!
 * 
 * \~english
 * \brief
 * Error message data.
 * 
 * Simple structure to hold error related data.
 * 
 * \see
 * RSH_STATUS
 * 
 * \~russian
 * \brief
 * Данные об ошибке.
 * 
 * Простая структура для хранения кода ошибки и строковых констант
 * с ее описанием.
 * 
 * \see
 * RSH_STATUS
 * 
 */
#pragma pack(push, 8)
struct RshErrorDescription {
	/*!
	 * 
	 * \~english
	 * \brief
	 * Error code.
	 * 
	 * One of the ::RSH_STATUS enum constants.
	 * 
	 * \~russian
	 * \brief
	 * Код ошибки.
	 *
	 * Одна из констант перечисления ::RSH_STATUS.
	 * 
	 */
    RSH_STATUS ecode; 

	/*!
	 * 
	 * \~english
	 * \brief
	 * Error description string in russian.
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
	 * Error description string in english.
	 * 
	 * \~russian
	 * \brief
	 * Строка с описанием ошибки на английском.
	 *
	 */
	std::wstring en;
};



RshErrorDescription RshErrorList[] = {
//<BeginErrorDescription>

  {RSH_API_SUCCESS,
  rshUTF16("Ошибок нет."),
  rshUTF16("No errors.")},

  {RSH_API_UNDEFINED,
  rshUTF16("Неизвестная ошибка."),
  rshUTF16("Undefined error.")},

  {RSH_API_DEVICE_NOTFOUND,
  rshUTF16("Устройство не найдено в системе."),
  rshUTF16("The device was not found in the system.")},

  {RSH_API_DEVICE_NOTINITIALIZED,
  rshUTF16("Устройство не было инициализировано."),
  rshUTF16("The device was not initialized.")},

  {RSH_API_DEVICE_DLLWASNOTLOADED,
  rshUTF16("Не удалось загрузить библиотеку абстракции."),
  rshUTF16("The abstract device dll was not loaded.")},

  {RSH_API_DEVICE_WRONGPCIINDEX,
  rshUTF16("Неверный индекс слота для устройства."),
  rshUTF16("Wrong pci slot index.")},

  {RSH_API_DEVICE_WRONGUSBINDEX,
  rshUTF16("Неверный индекс USB входа для устройства."),
  rshUTF16("Wrong usb socket index.")},

  {RSH_API_DEVICE_NOBOARDONPCIBUS,
  rshUTF16("На шине PCI не обнаружено ни одной поддерживаемой платы."),
  rshUTF16("There is no supported PCI(e) device in the system.")},

  {RSH_API_DEVICE_NOBOARDONUSBBUS,
  rshUTF16("На шине USB не обнаружено ни одного поддерживаемого устройства."),
  rshUTF16("There is no supported USB device in the system.")},

  {RSH_API_DEVICE_PLXREGISTERSARENOTMAPPED,
  rshUTF16("Неверно заданы входные параметры функции."),
  rshUTF16("PLX registers are not mapped into physical memory.")},

  {RSH_API_DEVICE_CANTGETDATA,
  rshUTF16("Не удается получить данные с устройства."),
  rshUTF16("Couldn't get data from the device.")},

  {RSH_API_DEVICE_CANTSETDATA,
  rshUTF16("Не удается записать данные в устройство."),
  rshUTF16("Couldn't set data to the device.")},

  {RSH_API_DEVICE_CANTINITIALIZE,
  rshUTF16("Не удается провести инициализацию устройства."),
  rshUTF16("Couldn't initialize the device.")},

  {RSH_API_DEVICE_CANTSTART,
  rshUTF16("Не удается запустить устройство."),
  rshUTF16("Couldn't start the device.")},

  {RSH_API_DEVICE_CANTSTOP,
  rshUTF16("Не удается остановить устройство."),
  rshUTF16("Couldn't stop the device.")},

  {RSH_API_DEVICE_CANTCREATEINSTANCE,
  rshUTF16("Не удается создать экземпляр устройства."),
  rshUTF16("Couldn't create a device instance.")},

  {RSH_API_DEVICE_NOINSTANCE,
  rshUTF16("Нет экземпляра устройства."),
  rshUTF16("There is no device instance.")},

  {RSH_API_DEVICE_LOADXILINX,
  rshUTF16("Не загружен XILINX."),
  rshUTF16("Data was not loaded into the device XILINX chip.")},

  {RSH_API_DEVICE_FUNCTION_NOTSUPPORTED,
  rshUTF16("Функция не поддерживается устройством."),
  rshUTF16("Function is not supported by this device.")},

  {RSH_API_DEVICE_INTBUFFERNOTINITIALIZED,
  rshUTF16("Внутренний буфер не инициализирован."),
  rshUTF16("Internal buffer not initialized.")},

  {RSH_API_DEVICE_REVISIONNOTFOUND,
  rshUTF16("Ревизия устройства не обнаружена."),
  rshUTF16("Device revision was not found.")},

  {RSH_API_DEVICE_WRONGTIMERNUMBER,
  rshUTF16("Неверный номер таймера устройства."),
  rshUTF16("Wrong timer number.")},

  {RSH_API_DEVICE_WASNOTSTARTED,
  rshUTF16("Устройство не было запущено."),
  rshUTF16("The device was not started.")},

  {RSH_API_DEVICE_STOPPEDWITHTRIGGER,
  rshUTF16("АЦП устройства остановлено по программному триггеру."),
  rshUTF16("The device ADC unit was stopped with program trigger.")},

  {RSH_API_DEVICE_IOCTLFAILED,
  rshUTF16("Не удалось выполнить команду IOCTL при работе с драйвером устройства."),
  rshUTF16("Couldn't implement device IOCTL code while communicating with the driver.")},

  {RSH_API_DEVICE_NOPOWER,
  rshUTF16("К устройству не подключено питание."),
  rshUTF16("There is no power supply for the device.")},

  {RSH_API_DEVICE_WRONGVIDORPID,
  rshUTF16("Несоответствие vid или pid."),
  rshUTF16("Discrepancy of pid or vid.")},

  {RSH_API_DEVICE_ALREADYCAPTURED,
  rshUTF16("Устройство было ранее захвачено."),
  rshUTF16("Device has been already captured.")},

  {RSH_API_DEVICE_BADFLASH,
  rshUTF16("Нарушена флеш память устройства."),
  rshUTF16("Device flash memory is inconsistent.")},

  {RSH_API_THREAD_CANTTERMINATE,
  rshUTF16("Не удаётся завершить поток."),
  rshUTF16("Couldn't terminate the thread.")},

  {RSH_API_THREAD_CANTCREATE,
  rshUTF16("Не удаётся создать поток."),
  rshUTF16("Couldn't create the thread.")},

  {RSH_API_THREAD_GATHERING_INPROCESS,
  rshUTF16("Сбор данных в потоке активен."),
  rshUTF16("Data gathering is in process.")},

  {RSH_API_THREAD_GATHERING_STOPPED,
  rshUTF16("Сбор данных в потоке остановлен."),
  rshUTF16("Data gathering was stopped.")},

  {RSH_API_FILE_CANTOPEN,
  rshUTF16("Не удалось открыть файл."),
  rshUTF16("Couldn't open the file.")},

  {RSH_API_FILE_CANTCREATE,
  rshUTF16("Не удалось создать файл."),
  rshUTF16("Couldn't create the file.")},

  {RSH_API_FILE_NAMENOTDEFINED,
  rshUTF16("Имя файла не задано."),
  rshUTF16("The file name is not defined.")},

  {RSH_API_FILE_ALREADYEXISTS,
  rshUTF16("Файл с указанным именем уже существует."),
  rshUTF16("The file already exists.")},

  {RSH_API_FILE_CANTWRITE,
  rshUTF16("Не удалось записать данные в файл."),
  rshUTF16("Couldn't write data to the file.")},

  {RSH_API_FILE_CANTREAD,
  rshUTF16("Не удалось прочитать данные из файла."),
  rshUTF16("Couldn't read data from the file.")},

  {RSH_API_FILE_CANTCLOSE,
  rshUTF16("Не удалось закрыть файл."),
  rshUTF16("Couldn't close the file.")},

  {RSH_API_FILE_WASNOTOPENED,
  rshUTF16("Файл не был открыт."),
  rshUTF16("File was not opened.")},

  {RSH_API_DLL_WASNOTLOADED,
  rshUTF16("Не удалось загрузить динамическую библиотеку."),
  rshUTF16("Dll was not loaded.")},

  {RSH_API_DLL_VERSIONNOTSUPPORTED,
  rshUTF16("Версия dll не поддерживается."),
  rshUTF16("Loaded dll has unsupported version.")},

  {RSH_API_DLL_NOFACTORY,
  rshUTF16("В загруженной dll не был обнаружен класс StaticFactory."),
  rshUTF16("There is no StaticFactory class inside the dll.")},

  {RSH_API_CRITSECTION_ALREADY_OWNED,
  rshUTF16("Критическая секция уже занята другим потоком."),
  rshUTF16("Critical section is already owned by other thread.")},

  {RSH_API_CRITSECTION_NOTINITIALIZED,
  rshUTF16("Критическая секция не инициализирована."),
  rshUTF16("Critical section is not initialized.")},

  {RSH_API_EVENT_WAITTIMEOUT,
  rshUTF16("Время ожидания наступления события истекло."),
  rshUTF16("Wait event time is out.")},

  {RSH_API_EVENT_WAITFAILED,
  rshUTF16("Не удалось активировать функцию ожидания события."),
  rshUTF16("Wait event failed.")},

  {RSH_API_EVENT_NOTINITIALIZED,
  rshUTF16("Событие не инициализировано."),
  rshUTF16("The event was not initialized.")},

  {RSH_API_EVENT_CANTRESET,
  rshUTF16("Не удалось деактивировать событие."),
  rshUTF16("Couldn't reset the event.")},

  {RSH_API_EVENT_CANTSET,
  rshUTF16("Не удалось активировать событие."),
  rshUTF16("Couldn't set the event")},

  {RSH_API_EVENT_CANTCREATE,
  rshUTF16("Не удалось инициализировать событие."),
  rshUTF16("Couldn't create the event.")},

  {RSH_API_PARAMETER_ZEROADDRESS,
  rshUTF16("Адрес входного параметра равен 0."),
  rshUTF16("Input parameter has zero address.")},

  {RSH_API_PARAMETER_NOTINITIALIZED,
  rshUTF16("Параметр не инициализирован."),
  rshUTF16("The parameter was not initialized.")},

  {RSH_API_PARAMETER_NOTSUPPORTED,
  rshUTF16("Параметр не поддерживается."),
  rshUTF16("The parameter is not supported")},

  {RSH_API_PARAMETER_INVALID,
  rshUTF16("Неверный входной параметр."),
  rshUTF16("The parameter is invalid.")},

  {RSH_API_PARAMETER_DATATYPENOTSUPPORTED,
  rshUTF16("Параметр данного типа данных не поддерживается."),
  rshUTF16("The parameter of this data type is not supported.")},

  {RSH_API_PARAMETER_STARTTYPEINVALID,
  rshUTF16("Тип запуска устройства не поддерживается."),
  rshUTF16("Device start mode is not supported.")},

  {RSH_API_PARAMETER_CHANNELWASNOTSELECTED,
  rshUTF16("Не выбраны активные каналы."),
  rshUTF16("There is no selected channel.")},

  {RSH_API_PARAMETER_TOOMANYCHANNELS,
  rshUTF16("Каналов больше, чем поддерживается."),
  rshUTF16("Too many channels in structure.")},

  {RSH_API_PARAMETER_NOTENOUGHCHANNELS,
  rshUTF16("В структуре инициализации присутствуют не все каналы."),
  rshUTF16("Not enough channels in RshChannel structure.")},

  {RSH_API_PARAMETER_WRONGTIMERNUMBER,
  rshUTF16("Неверный номер таймера"),
  rshUTF16("Wrong timer number")},

  {RSH_API_PARAMETER_WRONGDEVICEHANDLE,
  rshUTF16("Неверный идентификатор устройства во входном параметре."),
  rshUTF16("Wrong device handle in input parameter.")},

  {RSH_API_PARAMETER_WRONGCHANNELCOMBINATION,
  rshUTF16("Неверная комбинация активных каналов."),
  rshUTF16("Wrong combination of active channels.")},

  {RSH_API_PARAMETER_WRONGCHANNELNUMBER,
  rshUTF16("Неверное количество каналов."),
  rshUTF16("Wrong channel number.")},

  {RSH_API_PARAMETER_STARTMODENOTSUPPORTED,
  rshUTF16("Режим старта не поддерживается."),
  rshUTF16("Device start mode is not supported.")},

  {RSH_API_PARAMETER_DATAMODENOTSUPPORTED,
  rshUTF16("Режим конвертации данных не поддерживается."),
  rshUTF16("Device data mode is not supported.")},

  {RSH_API_PARAMETER_CONNECTMODENOTSUPPORTED,
  rshUTF16("Режим подключения не поддерживается."),
  rshUTF16("Device connect mode is not supported.")},

  {RSH_API_PARAMETER_CONTROLINVALID,
  rshUTF16("Режим работы устройства не поддерживается."),
  rshUTF16("Device control mode is invalid.")},

  {RSH_API_PARAMETER_WRONGPREDICATE,
  rshUTF16("входной предикат не поддерживается"),
  rshUTF16("input parameter predicate not supported")},

  {RSH_API_PARAMETER_OUTOFRANGE,
  rshUTF16("Значение параметра находится вне области допустимых значений."),
  rshUTF16("The parameter is out of range.")},

  {RSH_API_PARAMETER_INVALIDDEVICEBASEINDEX,
  rshUTF16("Порядковый номер устройства задан неверно."),
  rshUTF16("Wrong device index.")},

  {RSH_API_PARAMETER_SAMEVALUE,
  rshUTF16("Значение параметра совпадает с внутренним значением соответсвующего параметра."),
  rshUTF16("The same parameter value.")},

  {RSH_API_COREDLL_NOTEXISTS,
  rshUTF16("Core Library указанного типа не существует."),
  rshUTF16("Core Library of this type does not exist.")},

  {RSH_API_COREDLL_WASNOTLOADED,
  rshUTF16("Core Library не была загружена."),
  rshUTF16("Core Library was not loaded.")},

  {RSH_API_COREDLL_DLLNOFACTORY,
  rshUTF16("В Core Library не найден StaticFactory."),
  rshUTF16("There is no StaticFactory in Core Library.")},

  {RSH_API_COREDLL_INTERFACEDOESNOTMATCH,
  rshUTF16("Core Library интерфейс не соответствует."),
  rshUTF16("Core Library interface does not match.")},

  {RSH_API_COREDLL_REGISTRYKEYCANTOPEN,
  rshUTF16("Не удается открыть ветку реестра для Core Library."),
  rshUTF16("Couldn't open registry key for Core Library.")},

  {RSH_API_COREDLL_REGISTRYPATHRECNOTFOUND,
  rshUTF16("Не удается найти запись в реестре с полным путем к Core Library."),
  rshUTF16("Couldn't find path record in registry for Core Library.")},

  {RSH_API_COREDLL_UNSUPPORTEDVERSION,
  rshUTF16("Версия Core Library не поддерживается библиотекой абстракции."),
  rshUTF16("Core Library version doesn't correspond with abstraction library version.")},

  {RSH_API_COREDLL_GATHERINGINPROCESS,
  rshUTF16("Внутренний поток сбора данных не остановлен."),
  rshUTF16("Data gathering thread was not stopped.")},

  {RSH_API_COREDLL_GATHERINGDIDNOTSTART,
  rshUTF16("Сбор данных не был запущен."),
  rshUTF16("Gathering did not start.")},

  {RSH_API_COREDLL_PERSISTENTGTHREADISACTIVE,
  rshUTF16("Поток непрерывного сбора активен"),
  rshUTF16("Persistent collection thread is in active state.")},

  {RSH_API_COREDLL_COLLECTINGBUFFERZEROSIZE,
  rshUTF16("Данные не получены, буфер не заполнен"),
  rshUTF16("Data was not acquired, buffer is empty.")},

  {RSH_API_COREDLL_DEVICEREVISIONNOTFOUND,
  rshUTF16("Не найдена ревизия устройства"),
  rshUTF16("Device revision was not found.")},

  {RSH_API_COREDLL_DEVICEREVISIONNOTSUPPORTED,
  rshUTF16("Ревизия устройства не поддерживается."),
  rshUTF16("Device revision is not supported.")},

  {RSH_API_COREDLL_WRONGPORTNUMBER,
  rshUTF16("RSH_API_COREDLL_WRONGPORTNUMBER"),
  rshUTF16("Wrong port number.")},

  {RSH_API_COREDLL_WRONGTIMERNUMBER,
  rshUTF16("RSH_API_COREDLL_WRONGTIMERNUMBER"),
  rshUTF16("Wrong timer number.")},

  {RSH_API_COREDLL_REGSPACEDOESNOTEXIST,
  rshUTF16("RSH_API_COREDLL_REGSPACEDOESNOTEXIST."),
  rshUTF16("RSH_API_COREDLL_REGSPACEDOESNOTEXIST.")},

  {RSH_API_COREDLL_USERBUFFEREVENTNOTDEFINED,
  rshUTF16("Не задано пользовательское событие."),
  rshUTF16("User buffer event is not defined.")},

  {RSH_API_COREDLL_USERBUFFERWAITTIMEOUT,
  rshUTF16("Время ожидания готовности буфера истекло."),
  rshUTF16("Wait buffer time is out.")},

  {RSH_API_COREDLL_CANTCREATEPLX9054CLASS,
  rshUTF16("Не удалось создать экземпляр класса PLX9054."),
  rshUTF16("Couldn't create an instance of plx9054 class.")},

  {RSH_API_COREDLL_CANTCREATEPLX9050CLASS,
  rshUTF16("Не удалось создать экземпляр класса PLX9050."),
  rshUTF16("Couldn't create an instance of plx9050 class.")},

  {RSH_API_COREDLL_CANTCREATEPLX8311CLASS,
  rshUTF16("Не удалось создать экземпляр класса PLX8311."),
  rshUTF16("Couldn't create an instance of plx8311 class.")},

  {RSH_API_COREDLL_CANTCREATERSHUSBCLASS,
  rshUTF16("Не удалось создать экземпляр класса RSHUSB."),
  rshUTF16("Couldn't create an instance of RSHUSB class.")},

  {RSH_API_COREDLL_CANTCREATERSHVISACLASS,
  rshUTF16("Не удалось создать экземпляр класса RSHVISA."),
  rshUTF16("Couldn't create an instance of RSHVISA class.")},

  {RSH_API_FUNCTION_NOTDEFINED,
  rshUTF16("Функция не определена."),
  rshUTF16("The function is not defined.")},

  {RSH_API_FUNCTION_ERRORHAPPEND,
  rshUTF16("Произошла ошибка внутри функции."),
  rshUTF16("Function has failed with error.")},

  {RSH_API_FUNCTION_NOTSUPPORTED,
  rshUTF16("Функция не поддерживается."),
  rshUTF16("The function is not supported.")},

  {RSH_API_FUNCTION_GETCODENOTDEFINED,
  rshUTF16("Get-код не определен внутри метода IRshDevice::Get()."),
  rshUTF16("Get-code is not defined inside IRshDevice::Get() method.")},

  {RSH_API_BUFFER_NOTINITIALIZED,
  rshUTF16("Буфер не инициализирован."),
  rshUTF16("The buffer is not initialized.")},

  {RSH_API_BUFFER_ZEROSIZE,
  rshUTF16("Физический размер буфера равен нулю. Вероятно буфер не был инициализирован."),
  rshUTF16("Buffer size is zero. Probably the buffer is not initialized.")},

  {RSH_API_BUFFER_INANDOUTMISMATCH,
  rshUTF16("Формат входного и выходного буфера не совпадает."),
  rshUTF16("Input and output buffer format are not the same.")},

  {RSH_API_BUFFER_WRONGDATATYPE,
  rshUTF16("Буфер с таким типом данных не поддерживается."),
  rshUTF16("The buffer has unsupported data type.")},

  {RSH_API_BUFFER_PROCESSING_ERROR,
  rshUTF16("Ошибка при проведении вычислений."),
  rshUTF16("There is a runtime calculation error.")},

  {RSH_API_BUFFER_SIZEISEXCEEDED,
  rshUTF16("Объем данных в буфере превышает допустимый размер."),
  rshUTF16("Data Buffer size is exceeded.")},

  {RSH_API_BUFFER_ISEMPTY,
  rshUTF16("Буфер пуст."),
  rshUTF16("The buffer is empty.")},

  {RSH_API_BUFFER_SIZEMISMATCH,
  rshUTF16("Размер копируемого буфера не соответствует размеру буфера, в который производится копирование."),
  rshUTF16("Size mismatch when copy operation takes place.")},

  {RSH_API_BUFFER_NOTCOMPLETED,
  rshUTF16("Буфер не заполнен до конца."),
  rshUTF16("The buffer is not completed.")},

  {RSH_API_BUFFER_ALLOCATIONZEROSIZE,
  rshUTF16("Попытка выделения памяти размером 0 байт."),
  rshUTF16("There was an attempt to allocate a buffer of zero size.")},

  {RSH_API_BUFFER_INSUFFICIENTSIZE,
  rshUTF16("Размер буфера недостаточен для того, чтобы вместить все данные."),
  rshUTF16("Buffer size is too small for contain all data.")},

  {RSH_API_BUFFER_WRONGSIZE,
  rshUTF16("Размер буфера задан неверно."),
  rshUTF16("Buffer size is not correct.")},

  {RSH_API_OBJECT_NOTFOUND,
  rshUTF16("Объект не найден."),
  rshUTF16("The object was not found.")},

  {RSH_API_OBJECT_REFERENCENOTFOUND,
  rshUTF16("Ссылка на объект не найдена."),
  rshUTF16("The object reference was not found.")},

  {RSH_API_OBJECT_HASCHANGED,
  rshUTF16("Объект изменился."),
  rshUTF16("The object has changed.")},

  {RSH_API_OBJECT_ALREADYEXISTS,
  rshUTF16("Объект уже существует."),
  rshUTF16("The object already exists.")},

  {RSH_API_OBJECT_UNSUPPORTEDTYPE,
  rshUTF16("Неподдерживаемый тип объекта."),
  rshUTF16("Unsupported object type.")},

  {RSH_API_REGISTRY_KEYCANTOPEN,
  rshUTF16("Не найдена запись в реестре."),
  rshUTF16("Registry key value was not found.")},

  {RSH_API_REGISTRY_PATHRECNOTFOUND,
  rshUTF16("Не найдена запись path в реестре."),
  rshUTF16("Dll Path record value was not found.")},

  {RSH_API_REGISTRY_UINAMERECNOTFOUND,
  rshUTF16("Не найдена запись UIName в реестре."),
  rshUTF16("Dll UIName record value was not found.")},

  {RSH_API_INTERFACE_DOESNOTMATCH,
  rshUTF16("Интерфейс объекта в Dll не соответсвует запрашиваемому."),
  rshUTF16("Interface of object in Dll does not match requested interface type.")},

  {RSH_API_INTERFACE_CANTCREATEINSTANCE,
  rshUTF16("Не удается создать экземпляр объекта в фабрике."),
  rshUTF16("Couldn't create an instance of an object in Factory.")},

  {RSH_API_INTERFACE_WASNOTINITIALIZED,
  rshUTF16("Интерфейс не был инициализирован."),
  rshUTF16("Interface was not initialized.")},

  {RSH_API_INTERFACE_CANTCREATEINSTANCE_PARAMETER_ZEROADDRESS,
  rshUTF16("RshStaticFactory::CreateInstance не задан адрес объекта получателя интерфейса."),
  rshUTF16("RshStaticFactory::CreateInstance zero parameter address for interface object.")},

  {RSH_API_MEMORY_ERROR,
  rshUTF16("Ошибка работы с памятью."),
  rshUTF16("Memory error.")},

  {RSH_API_MEMORY_ALLOCATIONERROR,
  rshUTF16("Не удалось выделить память."),
  rshUTF16("Couldn't allocate memory.")},

  {RSH_API_MEMORY_COPYERROR,
  rshUTF16("Сбой при копировании из одной области памяти в другую."),
  rshUTF16("Copy memory failure.")},

  {RSH_API_PLXAPI_FAILED,
  rshUTF16("Cбой в работе PLX API."),
  rshUTF16("PLX API failed.")},

  {RSH_API_PLXAPI_NULLPARAM,
  rshUTF16("PLX API - неверный параметр, указатель на null."),
  rshUTF16("PLX API - null parameter.")},

  {RSH_API_PLXAPI_UNSUPPORTEDFUNCTION,
  rshUTF16("Функция PLX API не поддерживается."),
  rshUTF16("PLX API - function is not supported.")},

  {RSH_API_PLXAPI_NOACTIVEDRIVER,
  rshUTF16("В системе нет активного драйвера устройства."),
  rshUTF16("There is no active PLX driver in the system.")},

  {RSH_API_PLXAPI_CONFIGACCESSFAILED,
  rshUTF16("PLX API - Ошибка доступа к конфигурации"),
  rshUTF16("PLX API - config access failed.")},

  {RSH_API_PLXAPI_INVALIDDEVICEINFO,
  rshUTF16("PLX API - неверная информация об устройстве"),
  rshUTF16("PLX API - invalid device info.")},

  {RSH_API_PLXAPI_INVALIDDRIVERVERSION,
  rshUTF16("Версия PLX-драйвера не соответсвует версии используемой PLX-API."),
  rshUTF16("PLX API invalid driver version.")},

  {RSH_API_PLXAPI_INVALIDOFFSET,
  rshUTF16("PLX API - неверное значение смещения."),
  rshUTF16("PLX API - invalid zero offset.")},

  {RSH_API_PLXAPI_INVALIDDATA,
  rshUTF16("PLX API - неверные данные."),
  rshUTF16("PLX API - invalid data.")},

  {RSH_API_PLXAPI_INVALIDSIZE,
  rshUTF16("PLX API - неверный размер."),
  rshUTF16("PLX API - invalid size.")},

  {RSH_API_PLXAPI_INVALIDADDRESS,
  rshUTF16("PLX API - неверный адрес."),
  rshUTF16("PLX API - invalid address.")},

  {RSH_API_PLXAPI_INVALIDACCESSTYPE,
  rshUTF16("PLX API - неверный тип доступа."),
  rshUTF16("PLX API - invalid access type.")},

  {RSH_API_PLXAPI_INVALIDINDEX,
  rshUTF16("PLX API - неверный индекс."),
  rshUTF16("PLX API - invalid index.")},

  {RSH_API_PLXAPI_INVALIDPOWERSTATE,
  rshUTF16("PLX API - неверное значение состояния питания."),
  rshUTF16("PLX API - invalid power state.")},

  {RSH_API_PLXAPI_INVALIDIOPSPACE,
  rshUTF16("PLX API - неверное пространство ввода-вывода."),
  rshUTF16("PLX API - invalid IO space.")},

  {RSH_API_PLXAPI_INVALIDHANDLE,
  rshUTF16("PLX API - неверный дескриптор."),
  rshUTF16("PLX API invalid handle.")},

  {RSH_API_PLXAPI_INVALIDPCISPACE,
  rshUTF16("PLX API - неверное простаноство pci."),
  rshUTF16("PLX API - invalid pci space.")},

  {RSH_API_PLXAPI_INVALIDBUSINDEX,
  rshUTF16("PLX API - неверный индекс шины данных."),
  rshUTF16("PLX API - invalid BUS index.")},

  {RSH_API_PLXAPI_INSUFFICIENTRESOURCES,
  rshUTF16("PLX API - недостаточно ресурсов."),
  rshUTF16("PLX API - insufficient resources.")},

  {RSH_API_PLXAPI_WAITTIMEOUT,
  rshUTF16("PLX API - время ожидания готовности функции истекло."),
  rshUTF16("PLX API - wait time out.")},

  {RSH_API_PLXAPI_WAITCANCELED,
  rshUTF16("PLX API - ожидание было отменено. "),
  rshUTF16("PLX API - wait canceled.")},

  {RSH_API_PLXAPI_DMACHANNELUNAVAILABLE,
  rshUTF16("PLX API - ПДП каналы недоступны."),
  rshUTF16("PLX API - DMA channel unavailable.")},

  {RSH_API_PLXAPI_DMACHANNELINVALID,
  rshUTF16("PLX API - неверный канал ПДП."),
  rshUTF16("PLX API - DMA channel invalid.")},

  {RSH_API_PLXAPI_DMADONE,
  rshUTF16("PLX API - передача данных ПДП завершена."),
  rshUTF16("PLX API DMA done.")},

  {RSH_API_PLXAPI_DMAPAUSED,
  rshUTF16("PLX API - ПДП приостановлен."),
  rshUTF16("PLX API - DMA paused.")},

  {RSH_API_PLXAPI_DMAINPROGRESS,
  rshUTF16("PLX API - Канал ПДП занят."),
  rshUTF16("PLX API - DMA in progress.")},

  {RSH_API_PLXAPI_DMACOMMANDINVALID,
  rshUTF16("PLX API - Неверная команда ПДП."),
  rshUTF16("PLX API - DMA command invalid.")},

  {RSH_API_PLXAPI_DMAINVALIDCHANNELPRIORITY,
  rshUTF16("PLX API - неверный приоритет каналов ПДП."),
  rshUTF16("PLX API - DMA invalid channel priority.")},

  {RSH_API_PLXAPI_DMASGLPAGESGETERROR,
  rshUTF16("PLX API - ошибка поулчения страниц ПДП SGL"),
  rshUTF16("PLX API - DMA SGL pages get error.")},

  {RSH_API_PLXAPI_DMASGLPAGESLOCKERROR,
  rshUTF16("PLX API - ошибка захвата страниц ПДП SGL."),
  rshUTF16("PLX API - DMA SGL pages lock error.")},

  {RSH_API_PLXAPI_MUFIFOEMPTY,
  rshUTF16("PLX API - MU FIFO пусто."),
  rshUTF16("PLX API - MU FIFO empty.")},

  {RSH_API_PLXAPI_MUFIFOFULL,
  rshUTF16("PLX API - MU FIFO заполнено."),
  rshUTF16("PLX API - MU FIFO full.")},

  {RSH_API_PLXAPI_POWERDOWN,
  rshUTF16("PLX API - отсутствует питание."),
  rshUTF16("PLX API - power down.")},

  {RSH_API_PLXAPI_HSNOTSUPPORTED,
  rshUTF16("PLX API - HS не поддерживается."),
  rshUTF16("PLX API - HS not supported.")},

  {RSH_API_PLXAPI_VPDNOTSUPPORTED,
  rshUTF16("PLX API - VPD не поддерживается."),
  rshUTF16("PLX API - VPD not supported.")},

  {RSH_API_PLXAPI_DEVICEINUSE,
  rshUTF16("Устройство PLX захвачено другим потоком или процессом"),
  rshUTF16("PLX device is owned by another calling thread or process.")},

  {RSH_API_PLXAPI_DEVICEDISABLED,
  rshUTF16("PLX API - устройство отключено."),
  rshUTF16("PLX API - device disabled.")},

  {RSH_API_PLXAPI_LASTERROR,
  rshUTF16("Последняя ошибка PLX API"),
  rshUTF16("PLX API last error.")},

  {RSH_API_PLXAPI_DEVICENOTINITIALIZED,
  rshUTF16("PLX API - устройство не инициализировано"),
  rshUTF16("PLX API - device is not initialized.")},

  {RSH_API_PLXAPI_CANTCREATEDEVICEOBJECT,
  rshUTF16("PLX API - не удалось создать объект устройства."),
  rshUTF16("PLX API - can't create device object.")},

  {RSH_API_PLXAPI_EEPROMNOSERIAL,
  rshUTF16("Серийный номер платы не прописан в EEPROM."),
  rshUTF16("There is no serial number within EEPROM.")},

  {RSH_API_SCRIPT_SYNTAXERROR,
  rshUTF16("Ошибка синтаксиса в скрипте"),
  rshUTF16("Script syntax error")},

  {RSH_API_SCRIPT_CANTEVALUATE,
  rshUTF16("Не удалось определить значение"),
  rshUTF16("Couldn't evaluate value")},

  {RSH_API_SCRIPT_STARTFUNCTIONDOESNOTEXIST,
  rshUTF16("Не найдена функция запуска"),
  rshUTF16("Start function not found")},

  {RSH_API_SCRIPT_FUNCTIONDOESNOTEXIST,
  rshUTF16("Заданная функция не существует."),
  rshUTF16("Function specified does not exists.")},

  {RSH_API_DATABASE_CANTOPEN,
  rshUTF16("Не удалось открыть базу данных."),
  rshUTF16("Couldn't open database.")},

  {RSH_API_DATABASE_WASNOTOPENED,
  rshUTF16("База данных не откыта."),
  rshUTF16("Database was not opened.")},

  {RSH_API_DATABASE_CANTCREATETABLE,
  rshUTF16("Не удалось создать таблицу в базе данных."),
  rshUTF16("Couldn't create table in database.")},

  {RSH_API_DATABASE_CANTSELECTFROMTABLE,
  rshUTF16("Не удалось выполнить команду select."),
  rshUTF16("Couldn't do select from table.")},

  {RSH_API_DATABASE_TABLEISEMPTY,
  rshUTF16("Таблица пуста."),
  rshUTF16("Database table is empty.")},

  {RSH_API_DATABASE_CANTWRITERECORD,
  rshUTF16("не удалось осуществить запись в базу данных."),
  rshUTF16("Couldn't write record in databse.")},

  {RSH_API_DATABASE_CANTDELETEFROMTABLE,
  rshUTF16("Не удалось удалить запись из таблицы."),
  rshUTF16("Couldn't delete from databse table.")},

  {RSH_API_DATABASE_RECORDALREADYEXISTS,
  rshUTF16("Запись уже существует в базе данных."),
  rshUTF16("Database record already exists.")},

  {RSH_API_DATABASE_WRONGPREDICATE,
  rshUTF16("неверный предикат."),
  rshUTF16("Wrong predicate.")},

  {RSH_API_DATABASE_RECORDNOTFOUND,
  rshUTF16("Запись не найдена в базе данных."),
  rshUTF16("Database record was not found.")},

  {RSH_API_HDF5_GROUPDOESNTEXIST,
  rshUTF16("Группа с указанным именем не существует в HDF5 файле."),
  rshUTF16("Selected group doesn't exists within HDF5 file.")},

  {RSH_API_HDF5_GROUPCANTCREATE,
  rshUTF16("Не удаётся создать группу в HDF5 файле."),
  rshUTF16("Can't create the specified group in HDF5 file.")},

  {RSH_API_HDF5_GROUPOBJECTINDEXDOESNTEXIST,
  rshUTF16("Не удаётся найти объект с указанным индексом в группе."),
  rshUTF16("There is no object with selected index in the selected group.")},

  {RSH_API_HDF5_OBJECTISAGROUP,
  rshUTF16("Указанный объект является группой."),
  rshUTF16("Selected object is a group.")},

  {RSH_API_HDF5_DATASETDOESNTEXIST,
  rshUTF16("Набор данных с указанным именем не существует в HDF5 файле."),
  rshUTF16("DataSet doesn't exists within HDF5 file.")},

  {RSH_API_HDF5_DATASETWRONGOFFSET,
  rshUTF16("Неверное смещение в DataSet."),
  rshUTF16("Wrong offset in DataSet.")},

  {RSH_API_HDF5_EXCEPTION_DATASETOPERATIONFAIL,
  rshUTF16("При работе с DataSet произошла ошибка."),
  rshUTF16("Failure caused by the DataSet operations.")},

  {RSH_API_HDF5_EXCEPTION_DATASPACEOPERATIONFAIL,
  rshUTF16("При работе с DataSpace произошла ошибка."),
  rshUTF16("Failure caused by the DataSpace operations.")},

  {RSH_API_HDF5_EXCEPTION_FILEOPERATIONFAIL,
  rshUTF16("При работе с HDF5-файлом произошла ошибка."),
  rshUTF16("Failure caused by the hdf5 file operations.")},

  {RSH_API_HDF5_EXCEPTION_FILECANTCREATE,
  rshUTF16("Не удаётся создать HDF5-файл."),
  rshUTF16("Can't create HDF5 file.")},

  {RSH_API_HDF5_EXCEPTION_FILECANTOPEN,
  rshUTF16("Не удаётся открыть HDF5-файл."),
  rshUTF16("Can't open HDF5 file.")},

  {RSH_API_HDF5_EXCEPTION_FILECANTREAD,
  rshUTF16("Ошибка чтения HDF5-файла."),
  rshUTF16("Can't read HDF5 file.")},

  {RSH_API_HDF5_EXCEPTION_FILECANTWRITE,
  rshUTF16("Ошибка записи HDF5-файла."),
  rshUTF16("Can't write HDF5 file.")},

  {RSH_API_HDF5_EXCEPTION_DATATYPEOPERATIONFAIL,
  rshUTF16("При работе с DataType произошла ошибка."),
  rshUTF16("Failure caused by the DataType operations.")},

  {RSH_API_HDF5_EXCEPTION_ATTRIBUTEOPERATIONFAIL,
  rshUTF16("При работе с Attribute произошла ошибка."),
  rshUTF16("Failure caused by the Attribute operations.")},

  {RSH_API_HDF5_WRONGDATAPATH,
  rshUTF16("Неверный путь к данным."),
  rshUTF16("Wrong data path.")},

  {RSH_API_HDF5_TYPEMISMATCH,
  rshUTF16("Тип данных объекта в HDF файле не соотвествует с запрашиваемому типу объекта."),
  rshUTF16("Demanded data type doesn't match to HDF object data type.")},

  {RSH_API_RSHLAB_VOLTMETERNOTFOUND,
  rshUTF16("Не найдено устройство типа вольтметр."),
  rshUTF16("Voltmeter was not found.")},

  {RSH_API_RSHLAB_GENERATORNOTFOUND,
  rshUTF16("Не найдено устройство типа генератор."),
  rshUTF16("Generator was not found.")},

  {RSH_API_RSHLAB_TARGETDEVICENOTFOUND,
  rshUTF16("Не найдено целевое устройство."),
  rshUTF16("Target device was not found.")},

  {RSH_API_UNIDRIVER_DLLWASNOTLOADED,
  rshUTF16("Не удалось загрузить библиотеку RshUniDriver.dll"),
  rshUTF16("RshUniDriver.dll was not loaded")},

  {RSH_API_DM_DLLWASNOTLOADED,
  rshUTF16("Библиотека DM.dll не загружена."),
  rshUTF16("Library DM.dll was not loaded.")},

  {RSH_API_DPA_DLLWASNOTLOADED,
  rshUTF16("Не удалось загрузить алгоритмическую библиотеку DPA.dll"),
  rshUTF16("DPA.dll was not loaded")},

  {RSH_API_DPA_FINDTRIGGER_NOTFOUND,
  rshUTF16("В сигнале не найден момент синхронизации удовлетворяющий заданным параметрам."),
  rshUTF16("synchro trigger not found.")},

  {RSH_API_DPA_FUNCTION_CLASS_MISMATCH,
  rshUTF16("Тип структуры не соответсвует выполняемому алгоритму."),
  rshUTF16("Input parameter structure is not correspond to algorithmic class type.")},

  {RSH_API_DPA_FUNCTION_CLASS_NOTDEFINED,
  rshUTF16("Алгоритмический класс выбранного типа не определен в библиотеке DPA."),
  rshUTF16("Algorithmic  class of selected type is not defined inside DPA library.")},

  {RSH_API_VISA_CANTCONNECTTODRIVER,
  rshUTF16("Не удалось подключиться к драйверу VISA."),
  rshUTF16("Couldn't connect to VISA driver.")},

  {RSH_API_NET_GENERALFAILURE,
  rshUTF16("Неизвестная ошибка при работе с сетью."),
  rshUTF16("General (unknown) network failure.")},

  {RSH_API_NET_COULDNTCREATESOCKET,
  rshUTF16("Не удалось создать сокет."),
  rshUTF16("Couldn't create socket.")},

  {RSH_API_NET_COULDNTCREATEEVENT,
  rshUTF16("Не удалось создать event."),
  rshUTF16("Couldn't create event.")},

  {RSH_API_NET_EVENTSELECTFAILED,
  rshUTF16("Не удалось выполнить функцию select."),
  rshUTF16("Event select function failed.")},

  {RSH_API_NET_UDPSOCKETBINDFAILED,
  rshUTF16("Не удалось открыть UDP сокет."),
  rshUTF16("UDP socket bind failed.")},

  {RSH_API_NET_TCPSOCKETCONNECTFAILED,
  rshUTF16("Не удалось выполнить подключение через TCP сокет."),
  rshUTF16("TCP socket connect failed.")},

  {RSH_API_NET_SOCKETRECEIVEDATAFAILED,
  rshUTF16("Не удалось выполнить операцию получения данных из сокета."),
  rshUTF16("Socket receive data operation failed.")},

  {RSH_API_NET_SOCKETSENDDATAFAILED,
  rshUTF16("Не удалось выполнить операцию отправки данных."),
  rshUTF16("Socket send data operation failed.")},

  {RSH_API_NET_CLOSESOCKETFAILED,
  rshUTF16("Не удалось выполнить операцию закрытия сокета."),
  rshUTF16("Close socket operation failed.")},

  {RSH_API_CALIBRATION_ITEMNOTFOUND,
  rshUTF16("Поле RshCalibrationItemBase::id не соответсвует ни одному RshCalibrationItem определённому внутри dll."),
  rshUTF16("There is no RshCalibrationItem inside dll with id equal to requested RshCalibrationItemBase::id.")},

  //</BeginErrorDescription>
  };
  

#pragma pack(pop)



#endif //RSH_ERROR_DESCRIPTION_H
