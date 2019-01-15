/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshDeviceKey.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshDeviceKey class.
 *
 * \~russian
 * \brief
 * Класс RshDeviceKey.
 *
 */
 
#ifndef RSH_DEVICE_KEY_H
#define RSH_DEVICE_KEY_H

#include "RshBaseType.h"

#include <ostream>

#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * Identification key of a device
 *
 * This structure is used in IRshDevice::Connect() method.
 * It allows to connect to corresponding device via driver.\n
 *
 * \~russian
 * \brief
 * Идентификационный ключ устройства
 *
 * Данная структура используется в методе IRshDevice::Connect()
 * для получения доступа через драйвер к конкретному устройству.\n
 * Характеризующий устройство ключ (например, базовый адрес,
 * или заводской номер, или ip адрес с портом в виде строки)
 * заносится в структуру, которая затем передается в качестве параметра
 * в метод IRshDevice::Connect() .\n
 * Для заполнения структуры используется конструктор нужного типа.\n
 * Пример:\n
 *  \code
 * IRshDevice* device;
 * RshDeviceKey connectKey = RshDeviceKey(1);
 * device->Connect(&connectKey); //подключение по базовому адресу
 * \endcode
 *
 *
 */
struct RshDeviceKey : public RshBaseType
{
	RshDataTypes storedTypeId;
	
	U32 value_U32;
	const S8* value_S8P;
	const U16* value_U16P;  
	explicit RshDeviceKey(U32 value = 1);
	explicit RshDeviceKey(const S8* value);
	explicit RshDeviceKey(const U16* value);
	explicit RshDeviceKey(const char* value);
	explicit RshDeviceKey(const wchar_t* value);
	RshDeviceKey(const RshDeviceKey& obj);
	RshDeviceKey& operator=(const RshDeviceKey& obj);
	
	bool operator==(const RshDeviceKey& obj) const;
	bool operator!=(const RshDeviceKey& obj) const;
	
	friend std::ostream& operator<< (std::ostream &out, const RshDeviceKey& obj);
};

#pragma pack(pop)
#endif //RSH_DEVICE_KEY_H