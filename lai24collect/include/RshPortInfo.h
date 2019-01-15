/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshPortInfo.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshPortInfo class and dependent types declaration.
 *
 * \~russian
 * \brief
 * Класс RshPortInfo и связанные с ним типы данных.
 *
 */
 
#ifndef RSH_PORT_INFO_H
#define RSH_PORT_INFO_H

#include "RshBaseType.h"

#include <ostream>

#pragma pack(push, 8)

/*!
* 
* \~english
* \brief
* Information about digital port
* 
* This structure contains information
* about digital port.\n
* Usually, one can obtain list of such structures
* with information about device digital ports
* using IRshDevice::Get() method with 
* ::RSH_GET_DEVICE_PORT_INFO parameter.
*
* \see
* RSH_GET_DEVICE_PORT_INFO | RSH_CAPS_SOFT_DIGITAL_PORT_IS_AVAILABLE 
* 
* \~russian
* \brief
* Информация о цифровом порте
* 
* В данной структуре содержится информация
* о цифровом порте.\n
* Как правило, данная структура используется
* для получения полной информации о цифровых
* портах устройства. Вызвав метод 
* IRshDevice::Get() с параметром ::RSH_GET_DEVICE_PORT_INFO,
* можно получить список таких структур для данного устройства.
* 
* \see
* RSH_GET_DEVICE_PORT_INFO | RSH_CAPS_SOFT_DIGITAL_PORT_IS_AVAILABLE 
* 
*/
struct RshPortInfo : public RshBaseType {

	/*!
	* 
	* \~english
	* \brief
	* Port address
	* 
	* Usually just index that can be used
	* to access port, sometimes it is actual
	* address of mapped device register.\n
	* One can use addres, obtained by  IRshDevice::Get()
	* with ::RSH_GET_DEVICE_PORT_INFO parameter call,
	* to access digital port via IRshDevice::Init() with
	* RshInitPort structure.
	* 
	* \see
	* RshInitPort
	* 
	* \~russian
	* \brief
	* Адрес порта
	* 
	* Зачастую просто индекс (идентификатор) порта,
	* который должен использоваться для обращения к нему,
	* иногда действительный адрес отображаемого в память
	* регистра устройства.\n
	* Адрес порта, полученный при вызове метода IRshDevice::Get()
	* с параметром ::RSH_GET_DEVICE_PORT_INFO, можно использовать
	* для доступа к порту через метод IRshDevice::Init()
	* со структурой инициализации RshInitPort.
	* 
	* \see
	* RshInitPort
	* 
	*/
	U32 address;

	/*!
	* 
	* \~english
	* \brief
	* Port bits number
	* 
	* Number of bits in digital port
	* 
	* \~russian
	* \brief
	* Разрядность порта
	* 
	* Количество линий (разрядность) цифрового порта
	*
	*/
	U8 bitSize;

	/*!
	* 
	* \~english
	* \brief
	* Port name
	* 
	* Port name, usually corresponds to connector name
	* as it described in device manual.
	* 
	* \~russian
	* \brief
	* Имя порта
	* 
	* Имя порта, обычно соответствует названию разъема,
	* как оно прописано в руководстве пользователся для данного
	* устройства.
	*
	*/
	const wchar_t* name; 

	RshPortInfo();

	RshPortInfo(U32 address, U8 bitsize, const wchar_t* name);

	bool operator==(RshPortInfo& obj) const;

	bool operator!=(RshPortInfo& obj) const;

	bool operator< (const RshPortInfo& obj) const;

	bool operator> (const RshPortInfo& obj) const;

	RshPortInfo& operator=(const RshPortInfo& obj);

	friend std::ostream& operator<< (std::ostream &out, const RshPortInfo& obj);
};

/*!
* 
* \~english
* \brief
* RshBufferType of RshPortInfo structures
* 
* Default size is ::RSH_MAX_CHANNEL_NUMBER
* 
* \~russian
* \brief
* Буфер RshBufferType из структур RshPortInfo
* 
* Размер по умолчанию - ::RSH_MAX_CHANNEL_NUMBER
* 
*/
typedef RshBufferType< RshPortInfo, rshBufferTypePortInfo > RSH_BUFFER_PORTINFO;

#pragma pack(pop)
#endif //RSH_PORT_INFO_H
