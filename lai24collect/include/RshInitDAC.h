/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitDAC.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitDAC initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitDAC.
 *
 */
 
#ifndef RSH_INIT_DAC_H
#define RSH_INIT_DAC_H

#include "RshBaseType.h"

#include <ostream>

#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * DAC control structure.
 *
 * This structure is used to get access to device's
 * DAC (or DACs). Some of ADC boards have additional
 * DAC output channels, and using this structure
 * one can set output voltage on these DACs.
 *
 * \remarks
 * Devices which whole purpose is signal generation
 * use more complicated structures, such as RshInitGSPF.
 *
 * \see
 * RSH_CAPS_SOFT_INIT_DAC | IRshDevice::Init()
 *
 * \~russian
 * \brief
 * Структура для доступа к ЦАП.
 *
 * Данная структура используется для управления
 * ЦАПом (или ЦАПами), которые имеются у некоторых АЦП
 * устройств. Используя эту структуру, можно установить
 * нужное напряжение на одном из ЦАПов.
 *
 * \remarks
 * Устройства, основным предназначением которых
 * является генерация сигнала,
 * используют другие, более сложные структуры для
 * инициализации, например RshInitGSPF.
 *
 * \see
 * RSH_CAPS_SOFT_INIT_DAC | IRshDevice::Init()
 */
struct RshInitDAC : public RshBaseType
{
	/*!
	 *
	 * \~english
	 * \brief
	 * ID (order number) of DAC.
	 *
	 * With this field one can specify,
	 * which DAC is used for voltage output.
	 *
	 * \remarks
	 * If only one DAC installed, this parameter is ignored.\n
	 * Device ID is zero based.
	 *
	 * \~russian
	 * \brief
	 * Порядковй номер ЦАПа.
	 *
	 * Используя данное поле, можно задать номер
	 * ЦАПа, который будет использоваться для выдачи напряжения
	 *
	 * \remarks
	 * Если устройство имеет только один ЦАП,
	 * данный параметр игнорируется.\n
	 * Нумерация начинается с нуля.
	 *
	 */
	U32 id;

	/*!
	 *
	 * \~english
	 * \brief
	 * Output voltage.
	 *
	 * Use IRshDevice::Get() method with
	 * RSH_GET_DEVICE_OUTPUT_RANGE_VOLTS parameter to
	 * find out output voltage range for device.
	 *
	 * \remarks
	 * Wrong values are corrected when IRshDevice::Init() is called.
	 *
	 * \see
	 * RSH_GET_DEVICE_OUTPUT_RANGE_VOLTS | IRshDevice::Get()
	 *
	 * \~russian
	 * \brief
	 * Выходное напряжение.
	 *
	 * Используйте метод IRshDevice::Get() с
	 * параметром RSH_GET_DEVICE_OUTPUT_RANGE_VOLTS для того,
	 * чтобы определить допустимый диапазон выходного напряжения на ЦАПе.
	 *
	 * \remarks
	 * Если будет установлено неправильное (выходящее за диапазон) значение
	 * напряжения, оно будет откорректировано при вызове метода IRshDevice::Init().
	 *
	 * \see
	 * RSH_GET_DEVICE_OUTPUT_RANGE_VOLTS | IRshDevice::Get()
	 */
	double voltage;

	/*!
	 *
	 * \~english
	 * \brief
	 * Default values: id=0, voltage=0.0
	 *
	 * \~russian
	 * \brief
	 * Значения по умолчанию: id=0, voltage=0.0
	 *
	 */
	RshInitDAC(U32 ID = 0, double Voltage = 0.0);

	RshInitDAC(RshInitDAC const& obj);

	RshInitDAC& operator=(const RshInitDAC& obj);

	bool operator==(RshInitDAC& obj) const;

	bool operator!=(RshInitDAC& obj) const;

	friend std::ostream& operator<< (std::ostream &out, const RshInitDAC& obj);
};

#pragma pack(pop)
#endif //RSH_INIT_DAC_H