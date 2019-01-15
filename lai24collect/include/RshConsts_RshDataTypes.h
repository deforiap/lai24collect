/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshConsts_RshDataTypes.h
 * \date 04.03.2016
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * Type ID constants enum for Rsh SDK
 *
 * \~russian
 * \brief
 * Константы типов данных Rsh SDK
 *
 */
 
#ifndef RSH_DATA_TYPES_ENUM
#define RSH_DATA_TYPES_ENUM

#define _RSH_GROUP_TYPE_DELIMITER(value)   ( 0xadc00000 | ( value << 12 ) )
#define	_RSH_GROUP_TYPE_BASE(value)        ( _RSH_GROUP_TYPE_DELIMITER(0x1) | ( value & 0xfff ) )
#define	_RSH_GROUP_TYPE_POINTER(value)     ( _RSH_GROUP_TYPE_DELIMITER(0x2) | ( value & 0xfff ) )
#define	_RSH_GROUP_TYPE_BUFFER(value)      ( _RSH_GROUP_TYPE_DELIMITER(0x3) | ( value & 0xfff ) )
#define	_RSH_GROUP_TYPE_INIT(value)        ( _RSH_GROUP_TYPE_DELIMITER(0x4) | ( value & 0xfff ) )
#define	_RSH_GROUP_TYPE_STUFF(value)       ( _RSH_GROUP_TYPE_DELIMITER(0x5) | ( value & 0xfff ) )
#define	_RSH_GROUP_TYPE_INTERNAL(value)    ( _RSH_GROUP_TYPE_DELIMITER(0x6) | ( value & 0xfff ) )
#define	_RSH_GROUP_TYPE_DPA(value)         ( _RSH_GROUP_TYPE_DELIMITER(0x7) | ( value & 0xfff ) )
#define	_RSH_GROUP_TYPE_LAB(value)         ( _RSH_GROUP_TYPE_DELIMITER(0x8) | ( value & 0xfff ) )


/*!
 * 
 * \~english
 * \brief
 * Data types identifiers.
 * 
 * Every derived from RshBaseType class has its own unique ID,
 * which is used to identify it.
 * 
 * \~russian
 * \brief
 * Идентификаторы типов данных.
 * 
 * Каждый класс, унаследованный от RshBaseType, имеет
 * свой уникальный идентификатор, который позволяет
 * определить тип данных, когда это необходимо.
 *
 */
typedef enum
{
	rshTypeUndefined = 0x0,
	rshU8 = _RSH_GROUP_TYPE_BASE(0x1), //0xadc01000
	rshS8 = _RSH_GROUP_TYPE_BASE(0x2),
	rshU16 = _RSH_GROUP_TYPE_BASE(0x3),
	rshS16 = _RSH_GROUP_TYPE_BASE(0x4),
	rshU32 = _RSH_GROUP_TYPE_BASE(0x5),
	rshS32 = _RSH_GROUP_TYPE_BASE(0x6),
	rshU64 = _RSH_GROUP_TYPE_BASE(0x7),
	rshS64 = _RSH_GROUP_TYPE_BASE(0x8),
	rshFloat = _RSH_GROUP_TYPE_BASE(0x9),
	rshDouble = _RSH_GROUP_TYPE_BASE(0xA),
	rshBool  = _RSH_GROUP_TYPE_BASE(0xB),

	rshVoidP = _RSH_GROUP_TYPE_POINTER(0x1), //0xadc02000
	rshU8P = _RSH_GROUP_TYPE_POINTER(0x2),
	rshS8P  = _RSH_GROUP_TYPE_POINTER(0x3),
	rshU16P = _RSH_GROUP_TYPE_POINTER(0x4),
	rshS16P = _RSH_GROUP_TYPE_POINTER(0x5),
	rshU32P = _RSH_GROUP_TYPE_POINTER(0x6),
	rshS32P = _RSH_GROUP_TYPE_POINTER(0x7),
	rshU64P = _RSH_GROUP_TYPE_POINTER(0x8),
	rshS64P = _RSH_GROUP_TYPE_POINTER(0x9),
	rshFloatP = _RSH_GROUP_TYPE_POINTER(0xA),
	rshDoubleP = _RSH_GROUP_TYPE_POINTER(0xB),
	rshBoolP = _RSH_GROUP_TYPE_POINTER(0xC),
	rshU8PP = _RSH_GROUP_TYPE_POINTER(0xD),
	rshS8PP = _RSH_GROUP_TYPE_POINTER(0xE),
	rshU16PP = _RSH_GROUP_TYPE_POINTER(0xF),
	rshS16PP = _RSH_GROUP_TYPE_POINTER(0x10),
	rshU32PP = _RSH_GROUP_TYPE_POINTER(0x11),
	rshS32PP = _RSH_GROUP_TYPE_POINTER(0x12),
	rshU64PP = _RSH_GROUP_TYPE_POINTER(0x13),
	rshS64PP = _RSH_GROUP_TYPE_POINTER(0x14),
	rshFloatPP = _RSH_GROUP_TYPE_POINTER(0x15),
	rshDoublePP = _RSH_GROUP_TYPE_POINTER(0x16),
	rshBoolPP = _RSH_GROUP_TYPE_POINTER(0x17),

	rshBufferTypeU8 = _RSH_GROUP_TYPE_BUFFER(0x1), //0xadc03000
	rshBufferTypeS8 = _RSH_GROUP_TYPE_BUFFER(0x2),
	rshBufferTypeU16 = _RSH_GROUP_TYPE_BUFFER(0x3),
	rshBufferTypeS16 = _RSH_GROUP_TYPE_BUFFER(0x4),
	rshBufferTypeU32 = _RSH_GROUP_TYPE_BUFFER(0x5),
	rshBufferTypeS32 = _RSH_GROUP_TYPE_BUFFER(0x6),
	rshBufferTypeU64 = _RSH_GROUP_TYPE_BUFFER(0x7),
	rshBufferTypeS64 = _RSH_GROUP_TYPE_BUFFER(0x8),
	rshBufferTypeFloat = _RSH_GROUP_TYPE_BUFFER(0x9),
	rshBufferTypeDouble = _RSH_GROUP_TYPE_BUFFER(0xA),
	rshBufferTypeBool = _RSH_GROUP_TYPE_BUFFER(0xB),
	rshBufferTypeChannel = _RSH_GROUP_TYPE_BUFFER(0xC),
	rshBufferTypePortInfo = _RSH_GROUP_TYPE_BUFFER(0xD),
	rshBufferTypeSetting = _RSH_GROUP_TYPE_BUFFER(0xE),
	rshBufferTypeSettingChannel = _RSH_GROUP_TYPE_BUFFER(0xF),
	rshDBufferTypeU8 = _RSH_GROUP_TYPE_BUFFER(0x10),
	rshDBufferTypeS8 = _RSH_GROUP_TYPE_BUFFER(0x11),
	rshDBufferTypeU16 = _RSH_GROUP_TYPE_BUFFER(0x12),
	rshDBufferTypeS16 = _RSH_GROUP_TYPE_BUFFER(0x13),
	rshDBufferTypeU32 = _RSH_GROUP_TYPE_BUFFER(0x14),
	rshDBufferTypeS32 = _RSH_GROUP_TYPE_BUFFER(0x15),
	rshDBufferTypeU64 = _RSH_GROUP_TYPE_BUFFER(0x16),
	rshDBufferTypeS64 = _RSH_GROUP_TYPE_BUFFER(0x17),
	rshDBufferTypeFloat = _RSH_GROUP_TYPE_BUFFER(0x18),
	rshDBufferTypeDouble = _RSH_GROUP_TYPE_BUFFER(0x19),
	rshDBufferTypeBool = _RSH_GROUP_TYPE_BUFFER(0x1A),
	rshBufferTypeU8P = _RSH_GROUP_TYPE_BUFFER(0x1B),
	rshBufferTypeDeviceBaseInfo = _RSH_GROUP_TYPE_BUFFER(0x1C),
	rshBufferTypeDeviceFullInfo = _RSH_GROUP_TYPE_BUFFER(0x1D),
	rshBufferTypeChannelVoltage = _RSH_GROUP_TYPE_BUFFER(0x1E),
	rshBufferTypeCalibrationItem = _RSH_GROUP_TYPE_BUFFER(0x1F), 
	rshBufferTypeCalibrationGroup = _RSH_GROUP_TYPE_BUFFER(0x20), 
	rshBufferTypeBaseP = _RSH_GROUP_TYPE_BUFFER(0x21), 
	rshBufferTypeCalibrationCategory = _RSH_GROUP_TYPE_BUFFER(0x22),
	rshBufferTypeCalibrationVerification = _RSH_GROUP_TYPE_BUFFER(0x23),

	rshInitADC = _RSH_GROUP_TYPE_INIT(0x1), //0xadc04000
	rshInitGSPF = _RSH_GROUP_TYPE_INIT(0x2),
	rshInitDMA = _RSH_GROUP_TYPE_INIT(0x3),
	rshInitMemory = _RSH_GROUP_TYPE_INIT(0x4),
	rshInitVoltmeter = _RSH_GROUP_TYPE_INIT(0x5),
	rshInitPort = _RSH_GROUP_TYPE_INIT(0x6),
	rshInitPacket = _RSH_GROUP_TYPE_INIT(0x7),
	rshInitDAC = _RSH_GROUP_TYPE_INIT(0x8),
	rshInitTimer = _RSH_GROUP_TYPE_INIT(0x9),

	rshRegister = _RSH_GROUP_TYPE_STUFF(0x1), //0xadc05000
	rshPort = _RSH_GROUP_TYPE_STUFF(0x2),
	rshGatheringParameters = _RSH_GROUP_TYPE_STUFF(0x3),
	rshDeviceActiveList = _RSH_GROUP_TYPE_STUFF(0x4),
	rshOnboardBaseInfo = _RSH_GROUP_TYPE_STUFF(0x5),
	rshDeviceBaseInfo = _RSH_GROUP_TYPE_STUFF(0x6),
	rshDeviceFullInfo = _RSH_GROUP_TYPE_STUFF(0x7),
	rshDeviceBuffer = _RSH_GROUP_TYPE_STUFF(0x8),
	rshPortInfo = _RSH_GROUP_TYPE_STUFF(0x9),
	rshBoardPortInfo = _RSH_GROUP_TYPE_STUFF(0xA),
	rshIFactory = _RSH_GROUP_TYPE_STUFF(0xB),
	rshIRSHDevice = _RSH_GROUP_TYPE_STUFF(0xC),
	rshChannel = _RSH_GROUP_TYPE_STUFF(0xD),
	rshSynchroChannel = _RSH_GROUP_TYPE_STUFF(0xE),
	rshCalibrationParameters = _RSH_GROUP_TYPE_STUFF(0xF),
	rshCalibrationControl = _RSH_GROUP_TYPE_STUFF(0x10),
	rshDebugContainer = _RSH_GROUP_TYPE_STUFF(0x11),
	rshChannelVoltage = _RSH_GROUP_TYPE_STUFF(0x12),
	rshDeviceKey = _RSH_GROUP_TYPE_STUFF(0x13),
	rshCalibrationChannelParameter = _RSH_GROUP_TYPE_STUFF(0x14),
	rshCalibrationItemBase = _RSH_GROUP_TYPE_STUFF(0x15),
	rshCalibrationItemCheckBox = _RSH_GROUP_TYPE_STUFF(0x16),
	rshCalibrationItemRegister = _RSH_GROUP_TYPE_STUFF(0x17),	
	rshCalibrationItemButton = _RSH_GROUP_TYPE_STUFF(0x18),
	rshCalibrationItemFilePath = _RSH_GROUP_TYPE_STUFF(0x19),
	rshCalibrationItemRegOffset = _RSH_GROUP_TYPE_STUFF(0x1A),
	rshCalibrationItemToggleButton = _RSH_GROUP_TYPE_STUFF(0x1B),

	rshCalibrationParameterVerification = _RSH_GROUP_TYPE_STUFF(0x1C),

	rshBoardInfoDMA = _RSH_GROUP_TYPE_INTERNAL(0x1), //0xadc06000
	rshBoardInfoMemory = _RSH_GROUP_TYPE_INTERNAL(0x2),
	rshBoardInfoGSPF = _RSH_GROUP_TYPE_INTERNAL(0x3),
	rshBoardInfoDigital = _RSH_GROUP_TYPE_INTERNAL(0x4),
	rshFRDACTune  = _RSH_GROUP_TYPE_INTERNAL(0x5),
	rshTunerDataWrapper = _RSH_GROUP_TYPE_INTERNAL(0x6),
	rshTunerDataWrapperP = _RSH_GROUP_TYPE_INTERNAL(0x7),

	rshDPADataFFTComplex  = _RSH_GROUP_TYPE_DPA(0x1), //0xadc07000
	rshDPADataWindowFunction  = _RSH_GROUP_TYPE_DPA(0x2),
	rshDPADataFindGap = _RSH_GROUP_TYPE_DPA(0x3),
	rshDPADataFindFront  = _RSH_GROUP_TYPE_DPA(0x4),
	rshDPADataGeneratorSignalBase = _RSH_GROUP_TYPE_DPA(0x5),
	rshDPADataFFTPowerSpectrum = _RSH_GROUP_TYPE_DPA(0x6),
	rshDPAStatisticsBase = _RSH_GROUP_TYPE_DPA(0x7),
	rshDPADataStroboscope = _RSH_GROUP_TYPE_DPA(0x8),
	rshDPADataSaveHDF5 = _RSH_GROUP_TYPE_DPA(0x9),
	rshDPADataThermoCouple = _RSH_GROUP_TYPE_DPA(0xA),

	rshLabDataBuffer = _RSH_GROUP_TYPE_LAB(0x1), //0xadc08000
	rshLabDataStatistics = _RSH_GROUP_TYPE_LAB(0x2), 
	rshLabDataFeatures = _RSH_GROUP_TYPE_LAB(0x3),
	rshLabXYData = _RSH_GROUP_TYPE_LAB(0x4), 
	rshLabDataSave = _RSH_GROUP_TYPE_LAB(0x5),

} RshDataTypes;

#endif //RSH_DATA_TYPES_ENUM