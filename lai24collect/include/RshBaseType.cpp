/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshBaseType.cpp
 * \date 04.03.2016
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshBaseType class and dependent types declaration.
 *
 * \~russian
 * \brief
 * Класс  RshBaseType и связанные с ним типы данных.
 *
 */
 
#include "RshBaseType.h"
 
//RshBaseType
RshBaseType::RshBaseType(const RshDataTypes type, const size_t typeSize):
	_type(type),
	_typeSize(typeSize)
{}

//Disabled. See RshBaseType.h for explanation.
//RshBaseType::~RshBaseType(){}

const char* RshBaseType::GetTypeName(const RshDataTypes typeCode)
	{
		switch(typeCode)
		{
		//<BeginTypeStrings>
		default: return "UnknownType";
		case rshU8: return "RshU8";
		case rshS8: return "RshS8";
		case rshU16: return "RshU16";
		case rshS16: return "RshS16";
		case rshU32: return "RshU32";
		case rshS32: return "RshS32";
		case rshU64: return "RshU64";
		case rshS64: return "RshS64";
		case rshFloat: return "RshFloat";
		case rshDouble: return "RshDouble";
		case rshBool: return "RshBool";
		case rshVoidP: return "RshVoidP";
		case rshU8P: return "RshU8P";
		case rshS8P: return "RshS8P";
		case rshU16P: return "RshU16P";
		case rshS16P: return "RshS16P";
		case rshU32P: return "RshU32P";
		case rshS32P: return "RshS32P";
		case rshU64P: return "RshU64P";
		case rshS64P: return "RshS64P";
		case rshFloatP: return "RshFloatP";
		case rshDoubleP: return "RshDoubleP";
		case rshBoolP: return "RshBoolP";
		case rshU8PP: return "RshU8PP";
		case rshS8PP: return "RshS8PP";
		case rshU16PP: return "RshU16PP";
		case rshS16PP: return "RshS16PP";
		case rshU32PP: return "RshU32PP";
		case rshS32PP: return "RshS32PP";
		case rshU64PP: return "RshU64PP";
		case rshS64PP: return "RshS64PP";
		case rshFloatPP: return "RshFloatPP";
		case rshDoublePP: return "RshDoublePP";
		case rshBoolPP: return "RshBoolPP";
		case rshBufferTypeU8: return "RshBufferTypeU8";
		case rshBufferTypeS8: return "RshBufferTypeS8";
		case rshBufferTypeU16: return "RshBufferTypeU16";
		case rshBufferTypeS16: return "RshBufferTypeS16";
		case rshBufferTypeU32: return "RshBufferTypeU32";
		case rshBufferTypeS32: return "RshBufferTypeS32";
		case rshBufferTypeU64: return "RshBufferTypeU64";
		case rshBufferTypeS64: return "RshBufferTypeS64";
		case rshBufferTypeFloat: return "RshBufferTypeFloat";
		case rshBufferTypeDouble: return "RshBufferTypeDouble";
		case rshBufferTypeBool: return "RshBufferTypeBool";
		case rshBufferTypeChannel: return "RshBufferTypeChannel";
		case rshBufferTypePortInfo: return "RshBufferTypePortInfo";
		case rshBufferTypeSetting: return "RshBufferTypeSetting";
		case rshBufferTypeSettingChannel: return "RshBufferTypeSettingChannel";
		case rshDBufferTypeU8: return "RshDBufferTypeU8";
		case rshDBufferTypeS8: return "RshDBufferTypeS8";
		case rshDBufferTypeU16: return "RshDBufferTypeU16";
		case rshDBufferTypeS16: return "RshDBufferTypeS16";
		case rshDBufferTypeU32: return "RshDBufferTypeU32";
		case rshDBufferTypeS32: return "RshDBufferTypeS32";
		case rshDBufferTypeU64: return "RshDBufferTypeU64";
		case rshDBufferTypeS64: return "RshDBufferTypeS64";
		case rshDBufferTypeFloat: return "RshDBufferTypeFloat";
		case rshDBufferTypeDouble: return "RshDBufferTypeDouble";
		case rshDBufferTypeBool: return "RshDBufferTypeBool";
		case rshBufferTypeU8P: return "RshBufferTypeU8P";
		case rshBufferTypeDeviceBaseInfo: return "RshBufferTypeDeviceBaseInfo";
		case rshBufferTypeDeviceFullInfo: return "RshBufferTypeDeviceFullInfo";
		case rshBufferTypeChannelVoltage: return "RshBufferTypeChannelVoltage";
		case rshBufferTypeCalibrationItem: return "RshBufferTypeCalibrationItem";
		case rshBufferTypeCalibrationGroup: return "RshBufferTypeCalibrationGroup";
		case rshBufferTypeBaseP: return "RshBufferTypeBaseP";
		case rshBufferTypeCalibrationCategory: return "RshBufferTypeCalibrationCategory";
		case rshBufferTypeCalibrationVerification: return "RshBufferTypeCalibrationVerification";
		case rshInitADC: return "RshInitADC";
		case rshInitGSPF: return "RshInitGSPF";
		case rshInitDMA: return "RshInitDMA";
		case rshInitMemory: return "RshInitMemory";
		case rshInitVoltmeter: return "RshInitVoltmeter";
		case rshInitPort: return "RshInitPort";
		case rshInitPacket: return "RshInitPacket";
		case rshInitDAC: return "RshInitDAC";
		case rshInitTimer: return "RshInitTimer";
		case rshRegister: return "RshRegister";
		case rshPort: return "RshPort";
		case rshGatheringParameters: return "RshGatheringParameters";
		case rshDeviceActiveList: return "RshDeviceActiveList";
		case rshOnboardBaseInfo: return "RshOnboardBaseInfo";
		case rshDeviceBaseInfo: return "RshDeviceBaseInfo";
		case rshDeviceFullInfo: return "RshDeviceFullInfo";
		case rshDeviceBuffer: return "RshDeviceBuffer";
		case rshPortInfo: return "RshPortInfo";
		case rshBoardPortInfo: return "RshBoardPortInfo";
		case rshIFactory: return "RshIFactory";
		case rshIRSHDevice: return "RshIRSHDevice";
		case rshChannel: return "RshChannel";
		case rshSynchroChannel: return "RshSynchroChannel";
		case rshCalibrationParameters: return "RshCalibrationParameters";
		case rshCalibrationControl: return "RshCalibrationControl";
		case rshDebugContainer: return "RshDebugContainer";
		case rshChannelVoltage: return "RshChannelVoltage";
		case rshDeviceKey: return "RshDeviceKey";
		case rshCalibrationChannelParameter: return "RshCalibrationChannelParameter";
		case rshCalibrationItemBase: return "RshCalibrationItemBase";
		case rshCalibrationItemCheckBox: return "RshCalibrationItemCheckBox";
		case rshCalibrationItemRegister: return "RshCalibrationItemRegister";
		case rshCalibrationItemButton: return "RshCalibrationItemButton";
		case rshCalibrationItemFilePath: return "RshCalibrationItemFilePath";
		case rshCalibrationItemRegOffset: return "RshCalibrationItemRegOffset";
		case rshCalibrationItemToggleButton: return "RshCalibrationItemToggleButton";
		case rshCalibrationParameterVerification: return "RshCalibrationParameterVerification";
		case rshBoardInfoDMA: return "RshBoardInfoDMA";
		case rshBoardInfoMemory: return "RshBoardInfoMemory";
		case rshBoardInfoGSPF: return "RshBoardInfoGSPF";
		case rshBoardInfoDigital: return "RshBoardInfoDigital";
		case rshFRDACTune: return "RshFRDACTune";
		case rshTunerDataWrapper: return "RshTunerDataWrapper";
		case rshTunerDataWrapperP: return "RshTunerDataWrapperP";
		case rshDPADataFFTComplex: return "RshDPADataFFTComplex";
		case rshDPADataWindowFunction: return "RshDPADataWindowFunction";
		case rshDPADataFindGap: return "RshDPADataFindGap";
		case rshDPADataFindFront: return "RshDPADataFindFront";
		case rshDPADataGeneratorSignalBase: return "RshDPADataGeneratorSignalBase";
		case rshDPADataFFTPowerSpectrum: return "RshDPADataFFTPowerSpectrum";
		case rshDPAStatisticsBase: return "RshDPAStatisticsBase";
		case rshDPADataStroboscope: return "RshDPADataStroboscope";
		case rshDPADataSaveHDF5: return "RshDPADataSaveHDF5";
		case rshDPADataThermoCouple: return "RshDPADataThermoCouple";
		case rshLabDataBuffer: return "RshLabDataBuffer";
		case rshLabDataStatistics: return "RshLabDataStatistics";
		case rshLabDataFeatures: return "RshLabDataFeatures";
		case rshLabXYData: return "RshLabXYData";
		case rshLabDataSave: return "RshLabDataSave";
		//</BeginTypeStrings>
		}
	}

const char* RshBaseType::GetTypeName() const
{
	return GetTypeName(_type);
} 