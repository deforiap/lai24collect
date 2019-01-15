/*!
* \copyright JSC "Rudnev-Shilyaev"
*
* \file RshTypes.h
* \date 24.12.2015
* \version 1.0 [SDK 2.00]
*
* \~english
* \brief
* This file includes RSH SDK types and definitions.
*
* \~russian
* \brief
* В этом файле содержатся определения типов данных, используемых в RSH SDK.
*
*/

#ifndef RSH_TYPES_H
#define RSH_TYPES_H


#include "RshDefChk.h"

//include all type definition files
#include "RshBaseType.h"
#include "RshScalarType.h"
#include "RshBufferType.h"
#include "RshRegister.h"
#include "RshDeviceBaseInfo.h"
#include "RshDeviceFullInfo.h"
#include "RshPortInfo.h"
#include "RshBoardPortInfo.h"
#include "RshTime.h"

//Init structures
#include "RshChannel.h"
#include "RshSynchroChannel.h"
#include "RshInitADC.h"
#include "RshInitDMA.h"
#include "RshInitMemory.h"
#include "RshInitDAC.h"
#include "RshInitGSPF.h"
#include "RshInitPort.h"
#include "RshInitTimer.h"
#include "RshInitVoltmeter.h"

//keys
#include "RshDeviceKey.h"
#include "RshDllInterfaceKey.h"

#endif //RSH_TYPES_H
