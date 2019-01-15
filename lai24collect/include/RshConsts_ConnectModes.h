/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshConsts_ConnectModes.h
 * \date 15.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * Device connect modes constants for Rsh SDK
 *
 * \~russian
 * \brief
 * Константы вариантов подключения к устройству  Rsh SDK
 *
 */
 
#ifndef RSH_CONSTS_CONNECT_MODES_H
#define RSH_CONSTS_CONNECT_MODES_H

/*!
 * 
 * \~english
 * \brief
 * Connect modes.
 *
 * \see
 * IRshDevice::Connect().
 * 
 * \~russian
 * \brief
 * Варианты подключения к устройству.
 * 
 * \see
 * IRshDevice::Connect().
 */
typedef enum
{
	/*!
	 * \~english
	 * \brief
	 * Connect to device by device index.
	 *
	 * If IRshDevice::Connect() is used with this code,
	 * method will use device index which was assigned to selected device
	 * by the driver.
	 *
	 * \~russian
	 * \brief
	 * Подключение к устройству по его индексу.
	 *
	 * Если метод IRshDevice::Connect() вызывается с использованием
	 * этого параметра, то подключение к устройству происходит в соответствии с построенной 
	 * драйвером таблицей устройств. Нумерация устройств ведется последовательно начиная с 1.
	 */
	RSH_CONNECT_MODE_BASE  = 0,

	/*!
	 * \~english
	 * \brief
	 * Connect to device by device serial number.
	 *
	 * If IRshDevice::Connect() is used with this code,
	 * method will use specified device serial number to connect to device.
	 *
	 * \~russian
	 * \brief
	 * Подключение к устройству по его заводскому номеру.
	 *
	 * Если метод IRshDevice::Connect() вызывается с использованием
	 * этого параметра, то подключение производится к устройству с указанным 
	 * заводским номером.
	 *
	 */
	RSH_CONNECT_MODE_SERIAL_NUMBER  = 1,

	/*!
	 * \~english
	 * \brief
	 * Connect via IP
	 *
	 * This mode is used by some ethernet devices. 
	 * One can specify ip adress and port in 
	 * string, for example "192.168.0.5:2034".
	 *
	 * \~russian
	 * \brief
	 * Подключение к устройству по IP адресу
	 *
	 * Подключение к устройству по IP-адресу.
	 * Данный режим используется некоторыми устройствами
	 * с сетевым интерфейсом.\n
	 * IP-адрес и порт  можно задать в виде строки - например
	 * "192.168.0.5:2034" .
	 *
	 */
	RSH_CONNECT_MODE_IP_ADDRESS = 2,

	/*!
	 * \~english
	 * \brief
	 * Connect to PLX device
	 *
	 * This mode is used to connect to specific PLX device\n
	 * Connection string format: №device;PlxChipType (RshDeviceKey::S8*)\n
	 * example:  RshDeviceKey( "0;9054" ) - connects to the first device in the system with a Plx 9054 chip. 
	 *
	 * \~russian
	 * \brief
	 * Подключение к PLX устройству по типу чипа
	 *
	 * Данный режим используется для подключения к любым чипам PLX напрямую.\n
	 * Формат строки подключения: №устройства;типчипа (RshDeviceKey::S8*)
	 * пример:  RshDeviceKey( "0;9054" ) - подключается к первому найденному устройству в системе с чипом Plx 9054.
	 *
	 */
	RSH_CONNECT_MODE_PLXCHIP_TYPE = 16
	
} RSH_CONNECT_MODES;

#endif //RSH_CONSTS_CONNECT_MODES_H
