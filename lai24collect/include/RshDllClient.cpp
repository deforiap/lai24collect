/*!
 * \copyright 2013 JSC "Rudnev-Shilyaev"
 *
 * \file RshDllClient.cpp
 * \date 26.02.2016
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
#ifndef RSHDLLCLIENT_CPP
#define RSHDLLCLIENT_CPP

#include "RshDllClient.h"

#if defined(RSH_MSWINDOWS)

void* RshDllClient::LoadByPath(const TCHAR* szPath, const char* szExportName)
{
	if(szPath == 0 || szExportName == 0)
		return 0;

	HMODULE m_hLib;

	m_hLib = HMODULE(::LoadLibrary(szPath));

	if(m_hLib == 0)
		return 0;
	return (void*)::GetProcAddress(m_hLib, szExportName);
}

U32 RshDllClient::LoadRegistered(const std::string& szRegistryBranchPath, const std::string& szModuleName, const std::string& szExportName)
	{

        WCHAR szPath[512];

		std::string registryPath("SOFTWARE");
		registryPath += "\\" + szRegistryBranchPath;	
		registryPath += "\\" + szModuleName;


		std::wstring wRegistryPath(registryPath.begin(),registryPath.end());

		HKEY hKeyModule;
		LONG r = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, wRegistryPath.c_str(), 0, KEY_READ, &hKeyModule);
		if(r != ERROR_SUCCESS)
			return RSH_API_REGISTRY_KEYCANTOPEN | r;

		unsigned long dwType, dwSize = sizeof(szPath)/sizeof(TCHAR);
        r = ::RegQueryValueEx(hKeyModule, L"path", 0, &dwType,
			(unsigned char*)szPath, &dwSize);

		if(r != ERROR_SUCCESS || dwType != REG_SZ)
		{
			::RegCloseKey(hKeyModule);
			return RSH_API_REGISTRY_PATHRECNOTFOUND | r;
		}


		::RegCloseKey(hKeyModule);

		HMODULE m_hLib;

		m_hLib = HMODULE(::LoadLibrary(szPath));

		if(m_hLib == 0)
			return RSH_API_DLL_WASNOTLOADED | GetLastError();

		// create a new inctance of IFDIC
		IFDIC* fdic = new IFDIC;
		fdic->factory = (IRshFactory*)::GetProcAddress(m_hLib, szExportName.c_str()); // get StaticFactory

		if( fdic->factory == 0 )
		{
			::FreeLibrary(m_hLib);
			return RSH_API_DLL_NOFACTORY | GetLastError();
		}

		fdic->hLib = m_hLib;
		fdic->libraryName = szModuleName;

		m_libraries.push_back(fdic);

		return RSH_API_SUCCESS;
	}


RshDllClient::RshDllClient()
{

}

RshDllClient::~RshDllClient()
{
    Free();
}

U32 RshDllClient::GetRegisteredList(std::vector<std::string>& list, RshDllClient::LibraryType libType)
{

		list.clear();

		//format key path
		std::string registryPath("SOFTWARE\\");
		
		switch(libType)
		{
			case libraryDriver:
			default:
				registryPath += std::string(RSH_KEY_PATH_DRV);				
				break;
			case libraryBase:
				registryPath += std::string(RSH_KEY_PATH_LIBRARY);	
				break;
			case libraryDPA:
				registryPath += std::string(RSH_KEY_PATH_DPA);
				break;
		}

		
		std::wstring wRegistryPath(registryPath.begin(),registryPath.end());

		//open regKey
		HKEY hKeyModule;
		LONG r = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, wRegistryPath.c_str(), 0, KEY_READ, &hKeyModule);
		if(r != ERROR_SUCCESS)
			return RSH_API_REGISTRY_KEYCANTOPEN | r;

		//enumerate all subkeys
		r = ERROR_SUCCESS;
		U32 index = 0;
		WCHAR subKeyName[1024];
		DWORD subKeyNameLength = 1024;
		while (r == ERROR_SUCCESS)
		{
			subKeyNameLength = 1024;
			r = ::RegEnumKeyEx(hKeyModule, index, subKeyName, &subKeyNameLength, 0, 0, 0, 0);
			if(r != ERROR_SUCCESS)
				break;
			std::wstring wskName(subKeyName);
			list.push_back(std::string(wskName.begin(), wskName.end()));
			index++;
		}
		::RegCloseKey(hKeyModule);
		return RSH_API_SUCCESS;
}


U32 RshDllClient::Free()
{
	std::vector<IFDIC*>::iterator itf = m_libraries.begin();

	for (; itf != m_libraries.end(); ++itf)
		::FreeLibrary(((IFDIC*) * itf)->hLib);

	m_libraries.clear();

	return RSH_API_SUCCESS;
}

U32 RshDllClient::GetInterface(RshDllInterfaceKey& key, const std::string& registryBranch, const std::string& interfaceName)
{
	bool recordFound = false;

	std::vector<IFDIC*>::iterator it = m_libraries.begin();
	for (; it != m_libraries.end(); ++it)
	{
		if (((IFDIC*)* it)->libraryName == key._Name)
		{
			recordFound = true;
			break;
		}
	}

	if (recordFound)
	{
		if (key._Factory)
			*key._Factory = ((IFDIC*)* it)->factory;

		//only need to get factory, return success without creating class instance
		if(key._Factory != NULL && key._Interface == NULL)
			return RSH_API_SUCCESS;

		// create class instance and return it
		return ((IFDIC*)* it)->factory->CreateInstance(interfaceName.c_str(), key._Interface, key._Parameter);
	}
	else
	{
		// if we haven't found the entry in m_libraries then try to load library and get an interface from it
		U32 st = LoadRegistered(registryBranch, key._Name);
		if (st != RSH_API_SUCCESS)
			return st;

		// so, LoadRegistered finished successfully => we can find all what we need in m_libraries, let's make GetInterface call again
		return GetInterface(key, registryBranch, interfaceName);
	}
}

U32 RshDllClient::GetLibraryInterface(IN OUT RshDllInterfaceKey& key, IN const std::string& interfaceName)
{
	return GetInterface(key, std::string(RSH_KEY_PATH_LIBRARY),
				interfaceName == "" ? "I" + std::string(key._Name) : interfaceName);
}


U32 RshDllClient::GetDPALibraryInterface(IN OUT RshDllInterfaceKey& key)
{	
	return GetInterface(key, std::string(RSH_KEY_PATH_DPA), std::string("IDPA") );
}


U32 RshDllClient::GetDeviceInterface(IN OUT RshDllInterfaceKey& key)
{
	return GetInterface(key, std::string(RSH_KEY_PATH_DRV), std::string("IRshDevice"));
}

#elif defined(RSH_LINUX)
#include <dirent.h>

U32 RshDllClient::LoadDriver(std::string libraryName, std::string fullLibraryPath, IFDIC** f) // loads SO object
{
		void* library = NULL;
		void* (*CreateFactory)(const char*, const char*);


		library = dlopen(fullLibraryPath.c_str(), RTLD_NOW | RTLD_LOCAL);

		if (!library) {
			perror(dlerror());
			return RSH_API_DLL_WASNOTLOADED;
		}

		CreateFactory = (void* (*)(const char*, const char*))dlsym(library, "CreateFactory"); // load CreateFactory function

		if (!CreateFactory) {
			return RSH_API_DLL_NOFACTORY;
		}


		IFDIC* fdic = new IFDIC;
                fdic->hLib = library;
		fdic->libraryName = libraryName;
        fdic->factory = (IRshFactory*) (*CreateFactory)(path_RSHBoardLibs.c_str(), path_RSHBaseLibs.c_str());

		*f = fdic;

		m_libraries.push_back(fdic);

		return RSH_API_SUCCESS;
	}

U32 RshDllClient::GetInterface(std::string libraryName, std::string libraryInterfaceName, std::string libraryPath,
		void** interface, void** factory, void* parameter) {
			U32 st;
			bool deviceRecordFound = false;

			std::vector<IFDIC*>::iterator it = m_libraries.begin();
			for (; it != m_libraries.end(); ++it) {
				if (((IFDIC*) * it)->libraryName == libraryName) {
					deviceRecordFound = true;
					break;
				}
			}
                        std::string lin = libraryInterfaceName;
			if (deviceRecordFound) {

                        	if (factory)
                                    *factory = ((IFDIC*) * it)->factory;


                                return ((IFDIC*) * it)->factory->CreateInstance(lin.c_str(), interface, parameter );// create device class instance
		        } else { // if we haven't found the entry in m_libraries then try to load library ang get an interface from it

			        std::string fullPath;
                                fullPath = libraryPath;
                                fullPath += "lib";
                                fullPath += libraryName;
                                fullPath += ".so";

                                IFDIC* f;
				st = LoadDriver(libraryName, fullPath, &f);
                                if( st != RSH_API_SUCCESS ) return st;

                                if (factory)
                                    *factory = f->factory;

                                return f->factory->CreateInstance(lin.c_str(), interface, parameter );// create device class instance
		        }


			}
RshDllClient::RshDllClient(const char* path_Boards, const char* path_Libs)
{
		if (path_Boards)
            path_RSHBoardLibs = std::string(path_Boards);
		else 
			path_RSHBoardLibs = std::string(RSH_DLL_BOARDS_DIRECTORY);

		if (path_Libs)
            path_RSHBaseLibs = std::string(path_Libs);	
		else
			path_RSHBaseLibs = std::string(RSH_DLL_LIBRARIES_DIRECTORY); 

		path_RSHDPALibs = std::string(RSH_DLL_DPA_DIRECTORY); 
}

RshDllClient::RshDllClient()
{
	path_RSHBoardLibs = std::string(RSH_DLL_BOARDS_DIRECTORY);
	path_RSHBaseLibs = std::string(RSH_DLL_LIBRARIES_DIRECTORY); 
	path_RSHDPALibs = std::string(RSH_DLL_DPA_DIRECTORY); 
}


RshDllClient::~RshDllClient()
{}

U32 RshDllClient::GetLibraryInterface(IN OUT RshDllInterfaceKey& key,IN const std::string& interfaceName)
{
	std::string libraryInterfaceName = "I";
	libraryInterfaceName += key._Name;

    return GetInterface( key._Name, libraryInterfaceName, path_RSHBaseLibs,
				key._Interface, key._Factory, key._Parameter);
}

	// получить интерфейс для работы с платой (все платы поддерживают интерфейс IADCDevice)

U32 RshDllClient::GetDeviceInterface(IN OUT RshDllInterfaceKey& key)
{
    return GetInterface(key._Name, "IRshDevice", path_RSHBoardLibs,
			key._Interface, key._Factory, key._Parameter);
}

U32 RshDllClient::Free() // free allocated memory for drivers and objects
{
		std::vector<IFDIC*>::iterator itf = m_libraries.begin();

		for (; itf != m_libraries.end(); ++itf)
		{
                    ((IFDIC*) * itf)->factory->Free();
                    dlclose(((IFDIC*) * itf)->hLib);
                }

		m_libraries.clear();

		return RSH_API_SUCCESS;
}

U32 RshDllClient::GetRegisteredList(std::vector<std::string>& list, RshDllClient::LibraryType libType)
{

        list.clear();

        //format key path
        std::string libraryPath;

        switch(libType)
        {
            case libraryDriver:
                default:
                libraryPath = RSH_DLL_BOARDS_DIRECTORY;
                break;
            case libraryBase:
                libraryPath = RSH_DLL_LIBRARIES_DIRECTORY;
                break;
            case libraryDPA:
                libraryPath = RSH_DLL_DPA_DIRECTORY;
                break;
        }


        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (libraryPath.c_str())) != NULL) {
          /* print all the files and directories within directory */
          while ((ent = readdir (dir)) != NULL) {
            bool existPrefix = false;
            bool existEnding = false;

            std::string libName = std::string(ent->d_name);
            if( libName.find("lib") != std::string::npos ) existPrefix = true;
            if( libName.find(".so") != std::string::npos ) existEnding = true;

            if( existPrefix & existEnding )
                list.push_back(libName.substr(3, libName.size() - 6));
          }
          closedir (dir);
        } else {
          /* could not open directory */
          perror ("");
          return RSH_API_FILE_CANTREAD;
        }

        return RSH_API_SUCCESS;
}

U32 RshDllClient::GetDPALibraryInterface(IN OUT RshDllInterfaceKey& key)
{
        return GetInterface( key._Name, "IDPA", path_RSHDPALibs,
                        key._Interface, key._Factory, key._Parameter);
}
#endif // LINUX

#endif //RSHDLLCLIENT_CPP
