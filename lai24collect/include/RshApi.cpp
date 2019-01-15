/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshApi.cpp
 * \date 15.02.2016
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * Rsh Api internal class and template implementation
 *
 * \~russian
 * \brief
 * Объединение всех cpp файлов, входящих в состав SDK
 *
 */

#ifndef RSH_API_CPP
#define RSH_API_CPP

#include "RshApi.h"

//Include all type definition files
#include "RshBaseType.cpp"
#include "RshScalarType.cpp"
#include "RshBufferType.cpp"
#include "RshRegister.cpp"
#include "RshDeviceBaseInfo.cpp"
#include "RshDeviceFullInfo.cpp"
#include "RshPortInfo.cpp"
#include "RshBoardPortInfo.cpp"
#include "RshChannel.cpp"
#include "RshSynchroChannel.cpp"
#include "RshDeviceKey.cpp"
#include "RshTime.cpp"

//Init structures
#include "RshInitADC.cpp"
#include "RshInitDMA.cpp"
#include "RshInitMemory.cpp"
#include "RshInitDAC.cpp"
#include "RshInitGSPF.cpp"
#include "RshInitPort.cpp"
#include "RshInitTimer.cpp"
#include "RshInitVoltmeter.cpp"

//Include all other cpp files
#include "RshDllInterfaceKey.cpp"
#include "RshDllClient.cpp"
#include "RshError.cpp"
#include "RshFunctions.cpp"

//Internal RSH API files
#if defined (RSH_DEVICE_BUFFER_H)
	#include <RshDeviceBuffer.cpp>
#endif

#if defined (RSH_EVENT_MANAGER_H)
	#include <RshEventObject.cpp>
	#include <RshCriticalSectionObject.cpp>
	#include <RshEventManager.cpp>
#endif

#if defined(RSH_GATHERING_PARAMETERS_H)
	#include <RshGatheringParameters.cpp>
#endif

#if defined(RSH_INIT_PACKET_H)
	#include "RshInitPacket.cpp"
#endif

#if defined(IRSH_CALIBRATOR_H)
    #include <IRshCalibrator.cpp>
#endif

#if defined(IRSH_DEBUG_H)
    #include <IRshDebug.cpp>
#endif

#if defined(CALIBRATION_PARAMETERS_H)
    #include <CalibrationParameters.cpp>
#endif


#if defined(RSHLAB_DATASTRUCTURES_H)
    #include <RshLabDataStructures.cpp>
#endif

#endif //RSH_API_CPP
