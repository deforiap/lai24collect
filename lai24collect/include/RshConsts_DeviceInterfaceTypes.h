/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshConsts_DeviceInterfaceTypes.h
 * \date 30.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * Device interface types constants enum for Rsh SDK
 *
 * \~russian
 * \brief
 * Константы типов интерфейсов устройств Rsh SDK
 *
 */
 
#ifndef RSH_CONSTS_DEVICE_INTERFACE_TYPES_H
#define RSH_CONSTS_DEVICE_INTERFACE_TYPES_H
 
/*!
 * 
 * \~english
 * \brief
 * Device physical interfaces.
 *
 * \~russian
 * \brief
 * Типы интерфейсов устройств
 * 
 */
typedef enum
{
	/*!
	 * 
	 * \~english
	 * \brief
	 * Default (undefined value)
	 *
	 * \~russian
	 * \brief
	 * Значение по умолчанию (тип интерфейса не определен)
	 * 
	 */
	RSH_ITYPE_UNDEFINED = 0,

	/*!
	 * 
	 * \~english
	 * \brief
	 * PCI device
	 *
	 * \~russian
	 * \brief
	 * Устройство с интерфейсом PCI
	 * 
	 */
	RSH_ITYPE_PCI = (1 << 0),

	/*!
	 * 
	 * \~english
	 * \brief
	 * PCI Express device
	 *
	 * \~russian
	 * \brief
	 * Устройство с интерфейсом PCI Express
	 * 
	 */
	RSH_ITYPE_PCIe = (1 << 1),

	/*!
	 * 
	 * \~english
	 * \brief
	 * USB 1.1 device
	 *
	 * \~russian
	 * \brief
	 * Устройство с интерфейсом USB 1.1
	 * 
	 */
	RSH_ITYPE_USB_11 = (1 << 2),

	/*!
	 * 
	 * \~english
	 * \brief
	 * USB 2.0 device
	 *
	 * \~russian
	 * \brief
	 * Устройство с интерфейсом USB 2.0
	 * 
	 */
	RSH_ITYPE_USB_20 = (1 << 3),

	/*!
	 * 
	 * \~english
	 * \brief
	 * USB 3.0 device
	 *
	 * \~russian
	 * \brief
	 * Устройство с интерфейсом USB 3.0
	 * 
	 */
	RSH_ITYPE_USB_30 = (1 << 4),

	/*!
	*
	* \~english
	* \brief
	* Ethernet device
	*
	* \~russian
	* \brief
	* Устройство с интерфейсом Ethernet
	*
	*/
	RSH_ITYPE_ETH = (1 << 5),

	/*!
	 * 
	 * \~english
	 * \brief
	 * Emulation device
	 *
	 * Device is emulated programmatically
	 * and have no real physical interface.
	 *
	 * \~russian
	 * \brief
	 * Эмуляция
	 * 
	 * Устройство эмулируется программно,
	 * и не имеет физического интерфейса.
	 * 
	 */
	RSH_ITYPE_EMULATION = (1 << 6),

	/*!
	 * 
	 * \~english
	 * \brief
	 * Combination of all flags
	 *
	 * \~russian
	 * \brief
	 * Комбинация всех доступных флагов
	 * 
	 */
	RSH_ITYPE_ANY = 0xFFFFFFFF

} RSH_BOARD_ITYPE;

#endif //RSH_CONSTS_DEVICE_INTERFACE_TYPES_H