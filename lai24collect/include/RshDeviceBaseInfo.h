/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshDeviceBaseInfo.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshDeviceBaseInfo class and dependent types declaration.
 *
 * \~russian
 * \brief
 * Класс RshDeviceBaseInfo и связанные с ним типы данных.
 *
 */
 
#ifndef RSH_DEVICEBASEINFO_H
#define RSH_DEVICEBASEINFO_H

#include "RshBaseType.h"
#include "RshBufferType.h"

#include <ostream>

#pragma pack(push, 8)

/*!
* 
* \~english
* \brief
* Device information structure
* 
* Extended information about device. 
* Contains device base address, serial number,
* slot number and so on.\n
* One can get list of such structures using
* IRshDevice::Get() method with
* RSH_GET_DEVICE_BASE_LIST_EXT parameter.
* 
* \see
* RSH_GET_DEVICE_BASE_LIST_EXT
* 
* \~russian
* \brief
* Структура с информацией об устройстве
* 
* Расширенная информация об устройстве.
* Содержит базовый адрес устройства, его
* заводской номер, код чипа PLX и т.д.\n
* Получить заполненный список таких структур
* можно с помощью метода IRshDevice::Get() 
* с параметром RSH_GET_DEVICE_BASE_LIST_EXT.
*
* \see
* RSH_GET_DEVICE_BASE_LIST_EXT
* 
*/
struct RshDeviceBaseInfo  : public RshBaseType  {

	/*!
	* 
	* \~english
	* \brief
	* Chip ID
	* 
	* Chip ID (PLX 9050, 9054, 8311, USB-specific code)
	* 
	* \~russian
	* \brief
	* Идентификатор чипа
	* 
	* Идентификатор чипа (модули PLX  9050, 9054, 8311, или коды USB)
	* 
	*/
	U16 chip;

	/*!
	* 
	* \~english
	* \brief
	* Vendor ID (VID) of the device
	*
	* Each peace of hardware connected to PC has
	* its unique (for device class) vendor ID and 
	* device ID numbers. Using this numbers operation
	* system can chose driver to use to work with
	* this device.
	* 
	* \~russian
	* \brief
	* Идентификатор производителя (VID) устройства
	*
	* Каждое устройство расширения, подключаемое к компьютеру,
	* имеет уникальный (для данной модели устройства) код устройства (product ID или PID)
	* и код производителя (vendor ID или VID). Операционная система
	* использует данные коды для идентифиакции устройства и выбора драйвера
	* для него.
	* 
	*/
	U16 vid; 
	/*!
	* 
	* \~english
	* \brief
	* Product ID (PID) of the device
	*
	* Each peace of hardware connected to PC has
	* its unique (for device class) vendor ID and 
	* device ID numbers. Using this numbers operation
	* system can chose driver to use to work with
	* this device.
	* 
	* \~russian
	* \brief
	* Идентификатор продукта (PID)
	*
	* Каждое устройство расширения, подключаемое к компьютеру,
	* имеет уникальный (для данной модели устройства) код устройства (product ID или PID)
	* и код производителя (vendor ID или VID). Операционная система
	* использует данные коды для идентифиакции устройства и выбора драйвера
	* для него.
	* 
	*/
	U16 pid;

	/*!
	* 
	* \~english
	* \brief
	* Device revision
	* 
	* Device revision.\n
	* Some revisions only different in firmware used,
	* some have diffierent hardware features, such
	* as memory size.
	* 
	* \~russian
	* \brief
	* Ревизия устройства
	* 
	* Номер ревизии устройства.\n
	* Некоторые ревизии отличаются только версией прошивки,
	* другие имеют более существенные отличия, такие
	* как размер установленной в устройстве памяти
	* или разрядность АЦП.
	* 
	*/
	U16 rev; 

	/*!
	* 
	* \~english
	* \brief
	* PCI slot number
	* 
	* Number of PCI slot where board is located.
	* Not actual for USB devices.
	* 
	* \~russian
	* \brief
	* Номер слота PCI
	* 
	* Номер слота PCI, в который установлена данная плата.
	* Не актуально для USB устройств.
	* 
	* \todo Добавить реализацию для USB устройств тоже, например по номеру хаба.
	*/
	U16 slot;

	/*!
	* 
	* \~english
	* \brief
	* Device base address
	* 
	* Device base address (index).
	* If there are two or more devices
	* of the same type, they will be enumerated
	* by the operation system.\n
	* Enumeration starts from 1.
	*
	* \see
	* IRshDevice::Connect()
	* 
	* \~russian
	* \brief
	* Базовый адрес устройства
	* 
	* Базовый адрес (индекс) устройства.
	* Если в системе одновременно установлено несколько
	* устройство одного типа, они будут пронумерованы 
	* операционной системой.\n
	* Нумерация начинается с 1.
	* 
	* \see
	* IRshDevice::Connect()
	*
	*/
	U16 base;

	/*!
	* 
	* \~english
	* \brief
	* Serial number of the device	
	* 
	* \~russian
	* \brief
	* Заводской номер устройства
	* 
	*/
	U32 serialNumber;

	RshDeviceBaseInfo(RshDataTypes type = rshDeviceBaseInfo, size_t typeSize = sizeof(RshDeviceBaseInfo));

	RshDeviceBaseInfo(U16 vid, U16 pid, U16 rev, U16 chip, U16 slot, U16 base, U32 serialNumber = 0);

	RshDeviceBaseInfo(const RshDeviceBaseInfo& pi);

	RshDeviceBaseInfo& operator=(const RshDeviceBaseInfo& obj);	

	bool operator==(RshDeviceBaseInfo& obj) const;

	bool operator!=(RshDeviceBaseInfo& obj) const;	

	bool operator<(const RshDeviceBaseInfo& obj) const;

	bool operator>(const RshDeviceBaseInfo& obj) const;

	friend std::ostream& operator<< (std::ostream &out, const  RshDeviceBaseInfo& obj);
};

/*!
* 
* \~english
* \brief
* RshBufferType of RshDeviceBaseInfo structures
* 
* Default size is ::RSH_MAX_LIST_SIZE
* 
* \~russian
* \brief
* Буфер RshBufferType из структур RshDeviceBaseInfo
* 
* Размер по умолчанию - ::RSH_MAX_LIST_SIZE
* 
*/
typedef RshBufferType< RshDeviceBaseInfo, rshBufferTypeDeviceBaseInfo> RSH_BUFFER_DEVICE_BASE_INFO;


#pragma pack(pop)
#endif //RSH_DEVICEBASEINFO_H