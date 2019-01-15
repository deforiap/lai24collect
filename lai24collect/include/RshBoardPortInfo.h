/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshBoardPortInfo.h
 * \date 25.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshBoardPortInfo class.
 *
 * \~russian
 * \brief
 * Класс RshBoardPortInfo.
 *
 */
 
#ifndef RSH_BOARD_PORT_INFO_H
#define RSH_BOARD_PORT_INFO_H

#include "RshConsts_Common.h"
#include "RshBaseType.h"
#include "RshPortInfo.h"

#pragma pack(push, 8)

/*!
* 
* \~english
* \brief
* Information about device digital ports
* 
* This structure is used as container
* for obtaining port information.\n
* One need pass this structure to 
* IRshDevice::Get() method  with
* parameter ::RSH_GET_DEVICE_PORT_INFO.
* 
* \~russian
* \brief
* Информация о цифровых портах устройства
* 
* Данная структура используется как контейнер
* для получения информации о цифровых портах.\n
* После вызова метода IRshDevice::Get() с параметром
* ::RSH_GET_DEVICE_PORT_INFO, переданная структура
* будет содержать информацию о цифровых портах
* данного устройтсва.
* 
*/
struct RshBoardPortInfo : public RshBaseType
{
	/*!
	* 
	* \~english
	* \brief
	* Constructor
	* 
	* One can specify maximum number of
	* digital ports and configuration ports.\n
	* In most cases there is no need of it.
	* 
	* 
	* \~russian
	* \brief
	* Конструктор
	* Можно задать максимальное количество конфигурационных
	* и цифровых портов, которые может вместить структура.\n
	* В большинстве случаев в этом нет необходимости.	
	*
	*/
	RshBoardPortInfo(size_t maxPortNumber = RSH_MAX_LIST_SIZE, size_t maxConfNumber = RSH_MAX_LIST_SIZE);

	/*!
	* 
	* \~english
	* \brief
	* Configuration ports
	* 
	* List of device configuration ports.
	* Use RshBufferType::Size() field to determine,
	* how many configuration ports device have.
	* 
	* \remarks
	* Most devices do not have configuration ports,
	* only data ports.
	* 
	* \~russian
	* \brief
	* Конфигурационные порты
	* 
	* Список конфигурационных портов устройства.
	* Используйте поле RshBufferType::Size() для того, 
	* чтобы определить количество конфигурационных портов
	* после заполнения структуры.
	* 
	* \remarks
	* Большинство устройств не имеет конфигурационных портов,
	* только порты данных.
	* 
	*/
	RSH_BUFFER_PORTINFO confs;

	/*!
	* 
	* \~english
	* \brief
	* Data ports
	* 
	* Actual digital ports, that can be used
	* to input and output data.
	* Use RshBufferType::Size() field to determine,
	* how many data ports device have.
	* 
	* \~russian
	* \brief
	* Порты данных
	* 
	* Цифровые порты устройства, которые могут быть 
	* использованы для ввода и вывода цифровых данных.
	* Используйте поле RshBufferType::Size() для того, 
	* чтобы определить количество портов данных
	* после заполнения структуры.
	* 
	*/
	RSH_BUFFER_PORTINFO ports;
};

#pragma pack(pop)
#endif //RSH_BOARD_PORT_INFO_H