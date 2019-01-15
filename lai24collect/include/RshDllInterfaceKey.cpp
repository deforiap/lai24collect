/*!
 *
 * \file RshDllInterfaceKey.cpp
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

#include "IRshDevice.h"

RshDllInterfaceKey::RshDllInterfaceKey(const char* libraryName, void** Interface, void** Factory, void* Parameter):
 _Name(libraryName),
 _Interface(Interface),
 _Factory(Factory),
 _Parameter(Parameter)
{}

RshDllInterfaceKey::RshDllInterfaceKey(const char* deviceName, IRshDevice*& Interface):
_Name(deviceName),
_Interface( (void**)&Interface),
_Factory(0),
_Parameter(0)
{}

RshDllInterfaceKey::~RshDllInterfaceKey()
{} 
