/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshSynchroChannel.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshSynchroChannel class.
 *
 * \~russian
 * \brief
 * Класс RshSynchroChannel.
 *
 */

#ifndef RSH_SYNCHRO_CHANNEL_H
#define RSH_SYNCHRO_CHANNEL_H
 
#include "RshBaseType.h"

#include <ostream>

#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * External trigger channel parameters
 *
 * This structure is similar to RshChannel,
 * but used to setup external trigger channel.
 *
 * \~russian
 * \brief
 * Параметры канала внешней синхронизации
 *
 * Данная структура похожа на структуру RshChannel,
 * но используется для настройки параметров
 * канала внешней синхронизации.
 *
 */
struct RshSynchroChannel : public RshBaseType
{
	/*!
	 *
	 * \~english
	 * \brief
	 * Gain coefficient
	 *
	 * Gain coefficient to use for
	 * external trigger channel.
	 *
	 * \remarks
	 * One can get list of availiable gain coefficients,
	 * using IRshDevice::Get() method with
	 * ::RSH_GET_DEVICE_EXT_SYNC_GAINLIST  parameter.
	 *
	 * \~russian
	 * \brief
	 * Коэффициент усиления
	 *
	 * Коэффициент усиления, который будет использован
	 * для канала внешней синхронизации
	 *
	 * \remarks
	 * Получить список доступных коэффициентов усиления
	 * можно, вызвав метод IRshDevice::Get() с параметром
	 * ::RSH_GET_DEVICE_EXT_SYNC_GAINLIST.
	 *
	 */
	U32 gain;

	/*!
	 *
	 * \~english
	 * \brief
	 * Additional flags
	 *
	 * 'OR' Combination of RshSynchroChannel::Control
	 * enum elements. If flag set is not
	 * supported by device, it will be ignored.
	 *
	 * \remarks
	 * By default, this parameter is equal to zero,
	 * which corresponds to following flag combination:\n
	 * <b>RshSynchroChannel::FilterOff | RshSynchroChannel::Resist1MOhm | RshSynchroChannel::DC</b>
	 *
	 * \~russian
	 * \brief
	 * Дополнительные флаги
	 *
	 * Комбинация по 'ИЛИ' элементов перечисления
	 * RshSynchroChannel::Control. Если установить флаг,
	 * который не поддерживается данным устройством,
	 * он будет проигнорирован (при этом, ошибки не возникнет).
	 *
	 * \remarks
	 * По умолчанию, данный параметр равен нулю, что
	 * соответствует следующей комбинации флагов:\n
	 * <b>RshSynchroChannel::FilterOff | RshSynchroChannel::Resist1MOhm | RshSynchroChannel::DC</b>
	 *
	 */
	U32 control;

	/*!
	 *
	 * \~english
	 * \brief
	 * Channel flag list
	 *
	 * Additional channel parameters that
	 * can be passed in RshSynchroChannel::control field.
	 *
	 * \~russian
	 * \brief
	 * Список опций для канала
	 *
	 * Дополнительные параметры канала внешней синхронизации, которые могут быть
	 * заданы в поле RshSynchroChannel::control.
	 *
	 */
	enum Control
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Turn OFF filters for external trigger channel
		 *
		 * Mutually exclusive with RshSynchroChannel::FilterLow and RshSynchroChannel::FilterHigh
		 *
		 * \~russian
		 * \brief
		 * Выключить фильтр для канала внешней синхронизации
		 *
		 * Взаимоисключающий с RshSynchroChannel::FilterLow и RshSynchroChannel::FilterHigh
		 *
		 */
		FilterOff	= 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Set 1MOhm resist for external trigger channel
		 *
		 * Mutually exclusive with RshSynchroChannel::Resist50Ohm
		 *
		 * \~russian
		 * \brief
		 * Установить входное сопротивление канала внешней синхронизации 1МОм
		 *
		 * Взаимоисключающий с RshSynchroChannel::Resist50Ohm
		 *
		 */
		Resist1MOhm	= 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Set input to DC mode
		 *
		 * Mutually exclusive with RshSynchroChannel::AC
		 *
		 * \~russian
		 * \brief
		 * Установить состояние входа "открытый"
		 *
		 * Взаимоисключающий с RshSynchroChannel::AC
		 *
		 */
		DC = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Turn on low pass filter for external trigger channel
		 *
		 * Mutually exclusive with RshSynchroChannel::FilterOff and RshSynchroChannel::FilterHigh
		 *
		 * \see
		 * RSH_CAPS_DEVICE_EXT_SYNC_FILTER_LOW
		 *
		 * \~russian
		 * \brief
		 * Включить фильтр низких частот для канала внешней синхронизации.
		 *
		 * Взаимоисключающий с RshSynchroChannel::FilterOff и RshSynchroChannel::FilterHigh
		 *
		 * \see
		 * RSH_CAPS_DEVICE_EXT_SYNC_FILTER_LOW
		 *
		 */
		FilterLow = 0x1,

		/*!
		 *
		 * \~english
		 * \brief
		 * Turn on high pass filter for external trigger channel
		 *
		 * Mutually exclusive with RshSynchroChannel::FilterOff and RshSynchroChannel::FilterLow
		 *
		 * \see
		 * RSH_CAPS_DEVICE_EXT_SYNC_FILTER_HIGH
		 *
		 * \~russian
		 * \brief
		 * Включить фильтр высоких частот для канала внешней синхронизации
		 *
		 * Взаимоисключающий с RshSynchroChannel::FilterOff и RshSynchroChannel::FilterLow
		 *
		 * \see
		 * RSH_CAPS_DEVICE_EXT_SYNC_FILTER_HIGH
		 *
		 */
		FilterHigh = 0x2,

		/*!
		 *
		 * \~english
		 * \brief
		 * Set input to AC mode
		 *
		 * Mutually exclusive with RshSynchroChannel::DC
		 *
		 * \~russian
		 * \brief
		 * Установить состояние входа "закрытый"
		 *
		 * Взаимоисключающий с RshSynchroChannel::DC
		 *
		 */
		AC = 0x4,

		/*!
		 *
		 * \~english
		 * \brief
		 * Set 50Ohm resist for channel
		 *
		 * Mutually exclusive with RshSynchroChannel::Resist1MOhm
		 *
		 * \~russian
		 * \brief
		 * Установить входное сопротивление канала 50Ом
		 *
		 * Взаимоисключающий с RshSynchroChannel::Resist1MOhm
		 *
		 */
		Resist50Ohm	= 0x8
	};

	RshSynchroChannel();

	RshSynchroChannel& operator=(const RshSynchroChannel& obj);

	bool operator==(RshSynchroChannel& obj) const;

	bool operator!=(RshSynchroChannel& obj) const;
	
	friend std::ostream& operator<< (std::ostream &out, const RshSynchroChannel& obj);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set channel parameters to default values
	 *
	 * gain = 1; control = 0;
	 *
	 * \~russian
	 * \brief
	 * Установить параметры канала по умолчанию
	 *
	 * gain = 1; adjustment = 0.0; control = 0;
	 *
	 */
	void SetDefaultPatameters();
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshSynchroChannel::FilterLow flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
	 * Setting RshSynchroChannel::FilterLow flag will automaticaly
	 * remove RshSynchroChannel::FilterHigh flag.
	 * Removing RshSynchroChannel::FilterLow flag will automaticaly
	 * remove BOTH RshSynchroChannel::FilterLow and RshSynchroChannel::FilterHigh flags,
	 * that is equal to setting RshSynchroChannel::FilterOff flag.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshSynchroChannel::FilterLow
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 * Установка флага RshSynchroChannel::FilterLow приводит к снятию 
	 * флага RshSynchroChannel::FilterHigh; снятие флага RshSynchroChannel::FilterLow
	 * приводит к снятию СРАЗУ ДВУХ ФЛАГОВ - RshSynchroChannel::FilterLow и RshSynchroChannel::FilterHigh,
	 * что эквивалентно установке флага RshSynchroChannel::FilterOff.
	 *
	 */
	void SetFilterLow(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshSynchroChannel::FilterHigh flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
	 * Setting RshSynchroChannel::FilterHigh flag will automaticaly
	 * remove RshSynchroChannel::FilterLow flag.
	 * Removing RshSynchroChannel::FilterHigh flag will automaticaly
	 * remove BOTH RshSynchroChannel::FilterHigh and RshSynchroChannel::FilterLow,
	 * that is equal to setting RshSynchroChannel::FilterOff flag.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshSynchroChannel::FilterHigh
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 * Установка флага RshSynchroChannel::FilterHigh приводит к снятию 
	 * флага RshSynchroChannel::FilterLow; снятие флага RshSynchroChannel::FilterHigh
	 * приводит к снятию <b>СРАЗУ ДВУХ ФЛАГОВ</b>
	 * - RshSynchroChannel::FilterHigh и RshSynchroChannel::FilterLow,
	 * что эквивалентно установке флага RshSynchroChannel::FilterOff.
	 *
	 */
	void SetFilterHigh(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshSynchroChannel::AC flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
	 * Setting RshSynchroChannel::AC flag automaticaly
	 * remove RshSynchroChannel::DC flag and vise versa.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshSynchroChannel::AC
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 * Установка флага RshSynchroChannel::AC приводит к снятию 
	 * флага RshSynchroChannel::DC; снятие флага RshSynchroChannel::AC
	 * приводит к установке флага RshSynchroChannel::DC.
	 *
	 */
	void SetInputAC(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshSynchroChannel::DC flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
	 * Setting RshSynchroChannel::DC flag automaticaly
	 * remove RshSynchroChannel::AC flag and vise versa.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshSynchroChannel::AC
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 * Установка флага RshSynchroChannel::DC приводит к снятию 
	 * флага RshSynchroChannel::AC; снятие флага RshSynchroChannel::DC
	 * приводит к установке флага RshSynchroChannel::AC.
	 *
	 */
	void SetInputDC(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshSynchroChannel::Resist50Ohm flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
	 * Setting RshSynchroChannel::Resist50Ohm flag automaticaly
	 * remove RshSynchroChannel::Resist1MOhm flag and vise versa.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshSynchroChannel::AC
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 * Установка флага RshSynchroChannel::Resist50Ohm приводит к снятию 
	 * флага RshSynchroChannel::Resist1MOhm; снятие флага RshSynchroChannel::Resist50Ohm
	 * приводит к установке флага RshSynchroChannel::Resist1MOhm.
	 *
	 */
	void SetResist50Ohm(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshSynchroChannel::Resist1MOhm flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
	 * Setting RshSynchroChannel::Resist1MOhm flag automaticaly
	 * remove RshSynchroChannel::Resist50Ohm flag and vise versa.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshSynchroChannel::AC
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 * Установка флага RshSynchroChannel::Resist1MOhm приводит к снятию 
	 * флага RshSynchroChannel::Resist50Ohm; снятие флага RshSynchroChannel::Resist1MOhm
	 * приводит к установке флага RshSynchroChannel::Resist50Ohm.
	 *
	 */
	void SetResist1MOhm(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshChannel::FilterHigh flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshChannel::FilterHigh
	 *
	 */
	bool IsFilterHighActive() const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshChannel::FilterLow flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshChannel::FilterLow
	 *
	 */
	bool IsFilterLowActive() const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshChannel::AC flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshChannel::AC
	 *
	 */	
	bool IsInputACActive() const;
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshChannel::DC flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshChannel::DC
	 *
	 */	
	bool IsInputDCActive() const;
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshChannel::Resist50Ohm flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshChannel::Resist50Ohm
	 *
	 */	
	bool IsResist50OhmActive() const;
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshChannel::Resist1MOhm flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshChannel::Resist1MOhm
	 *
	 */	
	bool IsResist1MOhmActive() const;
};

#pragma pack(pop)
#endif //RSH_SYNCHRO_CHANNEL_H
