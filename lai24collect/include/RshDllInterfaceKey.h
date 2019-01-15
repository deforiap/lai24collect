/*!
 *
 * \file RshDllInterfaceKey.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * Helper class used with RshDllClient
 *
 * \~russian
 * \brief
 * Вспомогательный класс, используемый совместно с RshDllClient
 *
 */

#ifndef RSH_DLL_INTERFACE_KEY_H
#define RSH_DLL_INTERFACE_KEY_H

#include "RshDefChk.h"
struct IRshDevice;

#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * This structure is used to pass parameters
 * to RshDllClient class methods.
 *
 * Using RshDllClient::GetDeviceInterface(),
 * one can load device interface
 * (IRshDevice) from dynamic link library.\n
 * Additionally, factory class (IRshFactory) can be obtained too,
 * and pass additional instancination parameters to this factory.
 *
 * \see
 * RshDllClient
 *
 * \~russian
 * \brief
 * Данная структура используется для передачи параметров
 * в методы класса RshDllClient.
 *
 * Используя метод RshDllClient::GetDeviceInterface() и
 * другие, можно загрузить интерфейс устройства (IRshDevice)
 * из динамической библиотеки.\n
 * Дополнительно, можно получить интерфейс фабрики (IRshFactory),
 * а также передать дополнительные параметры инстанцирования в нее.
 *
 * \see
 * RshDllClient
 *
 */
struct RshDllInterfaceKey
{
	/*!
	 *
	 * \~english
	 * \brief
	 * Device name.
	 *
	 * Name of the device (or library) as it appears in windows registry
	 * (LA20USB, LA1_5PCI etc.)
	 *
	 * \remarks
	 * One can get list of all registred devices (or libraries) using
	 * RshDllClient::GetRegisteredList() method.\n
	 *
	 * \see
	 * RshDllClient
	 *
	 * \~russian
	 * \brief
	 * Имя устройства.
	 *
	 * Имя устройства (или библиотеки), соответствующее записи в реестре
	 * (LA20USB, LA1_5PCI и т.д.)
	 *
	 * \remarks
	 * Получить полный список всех зарегистрированных устройств (или библиотек)
	 * можно с помощью метода RshDllClient::GetRegisteredList().\n
	 *
	 * \see
	 * RshDllClient
	 *
	 */
	 const char* _Name;

	/*!
	 *
	 * \~english
	 * \brief
	 * Pointer to loaded library interface
	 *
	 * Library interface object will be set in this field after
	 * RshDllClient::GetLibraryInterface() call.\n
	 * For device interface instantination RshDllClient::GetDeviceInterface()
	 * method is used.
	 *
	 * \see
	 * RshDllClient
	 *
	 *
	 * \~russian
	 * \brief
	 * Указатель на загружаемый интерфейс.
	 *
	 * В данном поле будет возвращен объект с интерфейсом
	 * нужной библиотеки (или устройства) после вызова метода
	 * RshDllClient::GetLibraryInterface()
	 * ( RshDllClient::GetDeviceInterface() для устройства).
	 *
	 * \see
	 * RshDllClient
	 *
	 */
	void** _Interface;
	void** _Factory;
	void* _Parameter;
	RshDllInterfaceKey(const char* libraryName, void** Interface, void** Factory = NULL, void* Parameter = NULL);
	
	//passing reference to pointer in this constructor. We need real pointer inside, not copy of it!
	explicit RshDllInterfaceKey(const char* deviceName, IRshDevice*& Interface);
	~RshDllInterfaceKey();
};
#pragma pack(pop)
#endif //RSH_DLL_INTERFACE_KEY_H
 