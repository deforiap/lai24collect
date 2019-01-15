/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshDeviceFullInfo.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshDeviceFullInfo class and dependent types declaration.
 *
 * \~russian
 * \brief
 * Класс RshDeviceFullInfo и связанные с ним типы данных.
 *
 */
 
#ifndef RSH_DEVICE_FULL_INFO_H
#define RSH_DEVICE_FULL_INFO_H

#include "RshDeviceBaseInfo.h"
#include "RshConsts_DeviceInterfaceTypes.h"

#include <ostream>

#pragma pack(push, 8)

/*!
* 
* \~english
* \brief
* Extended information about device
* 
* This structure is derived from RshDeviceBaseInfo structure,
* and extends it to contain additional information,
* such as library registry key name, full device name 
* and physical device interface type.

* Use IRshDevice::Get() method with
* RSH_GET_DEVICE_ACTIVE_LIST  parameter to
* obtain list of currently connected devices.
* 
* \see
* RSH_GET_DEVICE_ACTIVE_LIST
* 
* \~russian
* \brief
* Структура с информацией об устройстве
* 
* Расширенная информация об устройстве.
* Данная структура унаследована от RshDeviceBaseInfo,
* и содержит дополнительную информацию - 
* имя ключа в реестре, полное имя устройства, 
* имя программного интерфейса 
* и тип физического интерфейса устройства.
*
* \see
* RSH_GET_DEVICE_ACTIVE_LIST
* 
*/
struct RshDeviceFullInfo : public RshDeviceBaseInfo 
{
	/*!
	* 
	* \~english
	* \brief
	* Physical interface type
	* 
	* One of the values from ::RSH_BOARD_ITYPE enum.
	* 
	* \~russian
	* \brief
	* Тип физического интерфейса устройства
	* 
	* Одно из значений перечисления ::RSH_BOARD_ITYPE
	* 
	*/
	U32 itype; 
	
	/*!
	* 
	* \~english
	* \brief
	* Registry key name
	* 
	* The name of registry key that hold the path and other info
	* about actual dynamic library.
	* This keyname is dll specific and create registry branch when dll
	* is registered using RegSvr32\n
	* This key name should be specified in RshDllInterfaceKey  structure
	* to load dll using RshDllClient class.
	* 
	* \~russian
	* \brief
	* Имя ключа в реестре
	* 
	* Ключ с этим именем содержит информацию о пути
	* к динамической библиотеке устройства, версию и имя
	* программного интерфейса. Это имя записано в dll,
	* ветка в реестре создается при регистрации dll
	* с помощью RegSvr32\n
	* Именно это имя должно указываться в качестве имени устройства
	* при загрузке с помощью класса RshDllClient, как одна из переменных 
	* в конструкторе RshDllInterfaceKey.
	*/
	const S8* libraryName;
	
	/*!
	* 
	* \~english
	* \brief
	* Library interface name
	* 
	* Usually it is "IRshDevice" for devices
	* 
	* \~russian
	* \brief
	* Имя интерфейса библиотеки
	* 
	* Обычно для устройств это значение - "IRshDevice"
	* 
	*/
	const S8* libraryInterfaceName;
	
	/*!
	* 
	* \~english
	* \brief
	* Pointer to UTF16 string with  device name in russian
	* 
	* Every unique device (that is, device that have unique vid/pid)
	* combination have its own name.
	* 
	* \~russian
	* \brief
	* Указатель на строку UTF16 с именем устройства на русском 
	* 
	* Каждое устройство имеет свой уникальный идентификатор -
	* vid/pid, которому соответствует определенное имя.
	* 
	*/
	const U16* deviceOriginalName_RU;
	
	/*!
	* 
	* \~english
	* \brief
	* Pointer to UTF16 string with  device name in english
	* 
	* Every unique device (that is, device that have unique vid/pid)
	* combination have its own name.
	* 
	* \~russian
	* \brief
	* Указатель на строку UTF16 с именем устройства на английском 
	* 
	* Каждое устройство имеет свой уникальный идентификатор -
	* vid/pid, которому соответствует определенное имя.
	* 
	*/
	const U16* deviceOriginalName_EN;

	RshDeviceFullInfo();

	RshDeviceFullInfo(const RshDeviceFullInfo& obj);


	RshDeviceFullInfo& operator=(const RshDeviceFullInfo& obj);

	RshDeviceFullInfo& operator=(const RshDeviceBaseInfo& obj);

	bool operator==(RshDeviceFullInfo& obj) const;

	bool operator!=(RshDeviceFullInfo& obj) const;

	bool operator<(const RshDeviceFullInfo& obj) const;

	bool operator>(const RshDeviceFullInfo& obj) const;

	friend std::ostream& operator<< (std::ostream &out, const RshDeviceFullInfo& obj);
};

/*!
* 
* \~english
* \brief
* RshBufferType of RshDeviceFullInfo structures
* 
* Default size is ::RSH_MAX_LIST_SIZE
* 
* \~russian
* \brief
* Буфер RshBufferType из структур RshDeviceFullInfo
* 
* Размер по умолчанию - ::RSH_MAX_LIST_SIZE
* 
*/
typedef RshBufferType< RshDeviceFullInfo, rshBufferTypeDeviceFullInfo> RSH_BUFFER_DEVICE_FULL_INFO;


#pragma pack(pop)
#endif //RSH_DEVICE_FULL_INFO_H