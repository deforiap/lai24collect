/*!
 *
 * \file RshDllClient.h
 * \date 25.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * Dll client class
 *
 * This class is used to load dlls and create interface instances.
 *
 * \~russian
 * \brief
 * Класс для работы с dll
 *
 * Содержит методы для загрузки библиотек и инстанцирования классов из этих библиотек.
 *
 */

#ifndef RSH_DLL_CLIENT_H
#define RSH_DLL_CLIENT_H

#include "RshDefChk.h"
#include "IRshFactory.h"
#include "RshDllInterfaceKey.h"

#include <vector>
#include <string>

#if defined(RSH_MSWINDOWS)
	#include "REGKEY\RSH_RegistryPaths.ri"
	#include <tchar.h>	
#endif

/*!
 *
 * \~english
 * \brief
 * Get objects from dynamic libraries
 *
 * This class used to simlify access to device
 * and other library interfaces.\n
 * With only one method call one can
 * get device abstraction library object
 * instance ready to work with.
 *
 * \remarks
 * You can get access to any device without this class,
 * just export StaticFactory object from dll and
 * call it IRshFactory::CreateInstance() method.
 *
 * \see
 * IRshFactory | IRshDevice
 *
 * \~russian
 * \brief
 * Класс для работы с dll
 *
 * Данный класс упрощает работу с динамическими библиотеками.
 * Используя данный класс, можно вызвав всего один метод получить
 * готовый к работе объект с интерфейсом IRshDevice
 * из библиотеки абстракции устройства.
 *
 * \remarks
 * Можно обойтись и без использования данного класса - нужно
 * экспортировать объект StaticFactory из dll, и вызвать
 * метод IRshFactory::CreateInstance().
 *
 * \see
 * IRshFactory | IRshDevice
 */
class RshDllClient
{
	
public:

	/*!
	 *
	 * \~english
	 * \brief
	 * Library types.
	 *
	 * Types from this list are used
	 * in GetRegisteredList() method
	 * and determine register branch to search in.
	 *
	 * \~russian
	 * \brief
	 * Список типов библиотек.
	 *
	 * Типы из этого списка используются в методе
	 * GetRegisteredList() и определяют
	 * ветку реестра, в которй будет производиться
	 * поиск зарегистрированных библиотек.
	 *
	 */
	enum LibraryType
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Device drivers (abstraction libraries)
		 *
		 * \~russian
		 * \brief
		 * Драйверы (библиотеки абстракции) устройств
		 *
		 */
		libraryDriver = 0,
		/*!
		 *
		 * \~english
		 * \brief
		 * Base libraries
		 *
		 * \~russian
		 * \brief
		 * Базовые библиотеки
		 *
		 */
		libraryBase = 1,
		/*!
		 *
		 * \~english
		 * \brief
		 * DPA algorithms libraries
		 *
		 * \~russian
		 * \brief
		 * Библиотеки алгоритмов DPA
		 *
		 */
		libraryDPA = 2
	};


	RshDllClient();
	
	#if defined(RSH_LINUX)   
	RshDllClient(const char* path_Boards, const char* path_Libs);
	#endif

	~RshDllClient();

	/*!
	 *
	 * \~english
	 * \brief
	 * Get list of registered libraries.
	 *
	 * \param[in,out] list
	 * List (std::vector<std::string>) to be filled. It will be cleared on
	 * method call and filled with names of registered libraries
	 * of specified type.
	 *
	 * \param[in] libType
	 * Library type to enlist.
	 * One of the RshDllClient::LibraryType enum values.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * This static method is used to obtain list of registered libraries
	 * from Windows registry. Names from this list can be used to obtain
	 * device (or library) interface by using GetDeviceInterface() method.
	 *
	 *
	 * \see
	 * RshDllInterfaceKey | \link RshDllClient_GetRegisteredList_EN.cpp Usage example \endlink
	 *
	 * \~russian
	 * \brief
	 * Получение списка зарегистрированных библиотек.
	 *
	 * \param[in,out] list
	 * Список (std::vector<std::string>) который будет заполнен.
	 * Переданный в метод список будет очищен перед заполнением.
	 * После успешного завершения работы метода в нем будет содержаться
	 * список всех зарегистрированных в системе библиотек заданного типа.
	 *
	 * \param[in] libType
	 * Тип библиотеки.
	 * Одна из констант перечисления RshDllClient::LibraryType.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * Данный метод используется для получения списка зарегистрированных
	 * библиотек из реестра Windows. Полученные имена библиотек могут быть
	 * использованы для инстанцирования объектов с помощью метода GetDeviceInterface()
	 * и других подобных.
	 *
	 * \see
	 * RshDllInterfaceKey | \link RshDllClient_GetRegisteredList_RU.cpp Пример использования \endlink
	 *
	 */
	static U32 GetRegisteredList(std::vector<std::string>& list, RshDllClient::LibraryType libType = libraryDriver);

	/*!
	 *
	 * \~english
	 * \brief
	 * Unload all libraries.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * Using this method one can unload all
	 * libraries, that was loaded using RshDllClient class.
	 *
	 * \remarks
	 * Call this method when you dont need device library
	 * (or libraries) loaded anymore - in main class destructor,
	 * or on exit from application.\n
	 * After this call one can be sure, that all loaded
	 * libraries unloaded properly.
	 *
	 * \~russian
	 * \brief
	 * Выгрузка всех библиотек.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * Используя данный метод, можно выгрузить все
	 * библиотеки, которые были загружены с помощью
	 * класса RshDllClient.
	 *
	 * \remarks
	 * Вызов данного метода целесообразно производить в тот
	 * момент, когда библиотека для работы с устройством (или
	 * несколько библиотек) уже не нужны - например, в деструкторе
	 * основного класса, или при выходе из приложения.\n
	 * Вызов данного метода гарантирует, что все библиотеки (в том
	 * числе базовые, загружаемые скрытно от пользователя) будут корректо
	 * выгружены из памяти.
	 *
	 */
	U32 Free();

	/*!
	 *
	 * \~english
	 * \brief
	 * Load library interface object.
	 *
	 * \param[in,out] key
	 * RshDllInterfaceKey object which contains
	 * library name and pointer to interface class.
	 * See RshDllInterfaceKey for more details.
	 *
	 * \param[in] interfaceName
	 * Name of the library interface. For most cases,
	 * this parameter can be omited, because usually
	 * libraries have names and interface names corresponded each
	 * other: PLX9054 and IPLX9054 for example.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * This method is used to instantinate library classes from
	 * dlls registered in windows registry in <i>Base library</i> branch.
	 *
	 * \see
	 * RshDllInterfaceKey
	 *
	 * \~russian
	 * \brief
	 * Получение интерфейса библиотеки.
	 *
	 * \param[in,out] key
	 * Объект класса RshDllInterfaceKey, который содержит имя
	 * нужной библиотеки и указатель на объект класса библиотеки.
	 * После успешного вызова метода, переданный указатель будет
	 * ссылаться на инстанцированный объект.
	 *
	 * \param[in] interfaceName
	 * Имя интерфейса библиотеки. В большинстве случаев, этот
	 * параметр можно не указывать, т.к. обычно загружаемые
	 * библиотеки имеют имя интерфейса, соответствующее имени
	 * самой библиотеки: например, PLX9054 (имя в реестре)  и IPLX9054
	 * (название интерфейса).
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * Данный метод используется для инстанцирования классов
	 * из динамических библиотек, зарегистрированных в
	 * ветке <i>Base library</i> реестра Windows.
	 *
	 * \see
	 * RshDllInterfaceKey
	 *
	 */
	U32 GetLibraryInterface(IN OUT RshDllInterfaceKey& key, IN const std::string& interfaceName = std::string(""));

	/*!
	 *
	 * \~english
	 * \brief
	 * Load DPA library interface object.
	 *
	 * \param[in,out] key
	 * RshDllInterfaceKey object which contains
	 * library name and pointer to interface class.
	 * See RshDllInterfaceKey for more details.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * This method is used to instantinate DPA (Data processing algorithms)
	 * library classes from dlls,
	 * registered in windows registry in <i>Base library\\DPA</i>  branch.\n
	 * This method is analog of GetLibraryInterface(), the only exception is
	 * registry branch were search for registered libraries is performed
	 * and objec interface is hardcoded.
	 *
	 * \see
	 * RshDllInterfaceKey | IDPA
	 *
	 * \~russian
	 * \brief
	 * Получение интерфейса библиотеки DPA.
	 *
	 * \param[in,out] key
	 * Объект класса RshDllInterfaceKey, который содержит имя
	 * нужной библиотеки и указатель на объект класса библиотеки.
	 * После успешного вызова метода, переданный указатель будет
	 * ссылаться на инстанцированный объект.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * Данный метод используется для инстанцирования классов
	 * с интерфейсом IDPA (Data processing algorithms)
	 * из динамических библиотек, зарегистрированных в
	 * ветке <i>Base library\\DPA</i> реестра Windows.\n
	 * Данный метод является аналогом метода GetLibraryInterface(),
	 * отличие - ветка в реестре, в которой выполняется
	 * поиск, а также то, что интерфейс жестко задан (IDPA).
	 *
	 * \see
	 * RshDllInterfaceKey | IDPA
	 *
	 */
	U32 GetDPALibraryInterface(IN OUT RshDllInterfaceKey& key);

	/*!
	 *
	 * \~english
	 * \brief
	 * Load device interface (IRshDevice).
	 *
	 * \param[in, out] key
	 * RshDllInterfaceKey object which contains
	 * device library name and pointer to IRshDevice interface.
	 * See RshDllInterfaceKey for more details.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 *
	 * This method is used to inctantinate device
	 * interface (IRshDevice) classes from libraries,
	 * registered in <i>Drivers</i> branch of Windows registry.
	 *
	 * \remarks
	 * You can instantinate IRshDevice object from any dynamic
	 * library manually, exporting static IRshFactory object with
	 * <i>StaticFactory</i> name and calling it IRshFactory::CreateInstance() method.
	 *
	 * \see
	 * RshDllInterfaceKey | IRshFactory
	 *
	 * \~russian
	 * \brief
	 * Получение интерфейса устройства (IRshDevice).
	 *
	 * \param[in, out] key
	 * Объект класса RshDllInterfaceKey, который содержит имя
	 * нужной библиотеки и указатель на объект IRshDevice.
	 * После успешного вызова метода, переданный указатель будет
	 * ссылаться на инстанцированный объект, который можно
	 * использовать для управления устройством.
	 *
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 *
	 * Данный метод используется для инстанцирования объектов
	 * с интерфейсом устройства (IRshDevice) из динамических библиотек,
	 * зарегистрированных в реестре Windows в ветке  <i>Drivers</i>.
	 *
	 * \remarks
	 * Инстанцировать объект IRshDevice можно без использвания данного
	 * метода - для этого нужно эскпортировать статический объект фабрики
	 * (IRshFactory) с именем <i>StaticFactory</i> из dll, а затем вызвать
	 * у экспортированной фабрики метод IRshFactory::CreateInstance().
	 *
	 * \see
	 * RshDllInterfaceKey | IRshFactory
	 *
	 */
	U32 GetDeviceInterface(IN OUT RshDllInterfaceKey& key);
	
private:
	#if defined(RSH_MSWINDOWS)
    struct IFDIC
	{
        HMODULE		    hLib; // Handle to opened dll
        IRshFactory*    factory; // Factory class
        std::string     libraryName; // Loaded interface name
    };
	
    void* LoadByPath(const TCHAR* szPath, const char* szExportName);

    U32 LoadRegistered(const std::string& szRegistryBranchPath, const std::string& szModuleName,
                        const std::string& szExportName = std::string("StaticFactory"));

	U32 GetInterface(RshDllInterfaceKey& key, const std::string& registryBranch, const std::string& interfaceName);

	#elif defined(RSH_LINUX)
    struct IFDIC
	{
		void* hLib; // Handle to opened dll
		IRshFactory* factory; // Factory class
		std::string libraryName; // Loaded interface name
    };

    //! loads SO object
    U32 LoadDriver(std::string libraryName, std::string fullLibraryPath, IFDIC** f);

    U32 GetInterface(std::string libraryName, std::string libraryInterfaceName, std::string libraryPath,
    void** interface, void** factory = NULL, void* parameter = NULL);

	std::string path_RSHBoardLibs;
	std::string path_RSHBaseLibs;
	std::string path_RSHDPALibs;
	
    #endif

    std::vector<IFDIC*> m_libraries;	
};



#endif //RSH_DLL_CLIENT_H
