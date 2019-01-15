/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshChannel.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshChannel class.
 *
 * \~russian
 * \brief
 * Класс RshChannel.
 *
 */
 
#ifndef RSH_CHANNEL_H
#define RSH_CHANNEL_H
 
#include "RshBaseType.h"
#include "RshBufferType.h"

#include <ostream>
 
#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * Analog channel parameters
 *
 * Using this structure one can
 * setup parameters of analog input channel.\n
 * Usually this structure is used as an element
 * in RshBufferType list of channels (::RSH_BUFFER_CHANNEL),
 * passed to IRshDevice::Init() within initialization
 * structure.
 *
 * \~russian
 * \brief
 * Параметры аналогового канала
 *
 * Используя данную структуру, можно задать параметры
 * аналогового входного канала.\n
 * Обычно, данная структура используется как элемент
 * списка каналов RshBufferType (::RSH_BUFFER_CHANNEL),
 * передаваемый с другими данными (в структуре инициализации)
 * в метод IRshDevice::Init().
 *
 */
struct RshChannel : public RshBaseType
{
	/*!
	 *
	 * \~english
	 * \brief
	 * Gain coefficient
	 *
	 * Gain coefficient to use for this channel
	 * in data acquisition process.
	 *
	 * \remarks
	 * One can get list of availiable gain coefficients,
	 * using IRshDevice::Get() method with
	 * ::RSH_GET_DEVICE_GAIN_LIST parameter.
	 *
	 * \~russian
	 * \brief
	 * Коэффициент усиления
	 *
	 * Коэффициент усиления, который будет использован
	 * для данного канала при сборе данных
	 *
	 * \remarks
	 * Получить список доступных коэффициентов усиления
	 * можно, вызвав метод IRshDevice::Get() с параметром
	 * ::RSH_GET_DEVICE_GAIN_LIST.
	 *
	 */
	U32 gain;

	/*!
	 *
	 * \~english
	 * \brief
	 * Additional flags
	 *
	 * 'OR' Combination of RshChannel::Control
	 * enum elements. If flag set is not
	 * supported by device, it will be ignored.
	 *
	 * \remarks
	 * By default, this parameter is equal to zero,
	 * which corresponds to following flag combination:\n
	 * <b>RshChannel::NotUsed | RshChannel::NoSynchro | RshChannel::Resist1MOhm | RshChannel::DC | RshChannel::ICPPowerOff</b>
	 *
	 * \~russian
	 * \brief
	 * Дополнительные флаги
	 *
	 * Комбинация по 'ИЛИ' элементов перечисления
	 * RshChannel::Control. Если установить флаг,
	 * который не поддерживается данным устройством,
	 * он будет проигнорирован (при этом, ошибки не возникнет).
	 *
	 * \remarks
	 * По умолчанию, данный параметр равен нулю, что
	 * соответствует следующей комбинации флагов:\n
	 * <b>RshChannel::NotUsed | RshChannel::NoSynchro | RshChannel::Resist1MOhm | RshChannel::DC | RshChannel::ICPPowerOff</b>
	 *
	 */
	U32 control;

	/*!
	 *
	 * \~english
	 * \brief
	 * Input voltage adjustment
	 *
	 * Input level adjustment to use
	 * in data acquisition for this channel.
	 * This parameter is set in volts.
	 *
	 * \see
	 * RSH_CAPS_DEVICE_INPUT_LEVEL_ADJUSTMENT
	 *
	 * \~russian
	 * \brief
	 * Подстройка уровня входного напряжения
	 *
	 * Подстройка (смещение) уровня входного напряжения
	 * для данного канала. Данный параметр задается в вольтах.
	 *
	 * \see
	 * RSH_CAPS_DEVICE_INPUT_LEVEL_ADJUSTMENT
	 *
	 */
	double adjustment;


	/*!
	 *
	 * \~english
	 * \brief
	 * Channel flag list
	 *
	 * Additional channel parameters that
	 * can be passed in RshChannel::control field.
	 *
	 * \~russian
	 * \brief
	 * Список опций для канала
	 *
	 * Дополнительные параметры канала, которые могут быть
	 * заданы в поле RshChannel::control.
	 *
	 */
	enum Control
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Channel will NOT be used in data acquisition
		 *
		 * Mutually exclusive with RshChannel::Used
		 *
		 * \~russian
		 * \brief
		 * Канал НЕ будет использоваться при сборе данных
		 *
		 * Взаимоисключающий с RshChannel::Used
		 *
		 */
		NotUsed = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Channel will NOT be used as trigger source
		 *
		 * Mutually exclusive with RshChannel::Synchro
		 *
		 * \~russian
		 * \brief
		 * Канал НЕ будет использоваться в качестве источника синхронизации
		 *
		 * Взаимоисключающий с RshChannel::Synchro
		 *
		 */
		NoSynchro = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Set 1MOhm resist for channel
		 *
		 * Mutually exclusive with RshChannel::Resist50Ohm
		 *
		 * \~russian
		 * \brief
		 * Установить входное сопротивление канала 1МОм
		 *
		 * Взаимоисключающий с RshChannel::Resist50Ohm
		 *
		 */
		Resist1MOhm	= 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Set input to DC mode
		 *
		 * Mutually exclusive with RshChannel::AC
		 *
		 * \~russian
		 * \brief
		 * Установить состояние входа "открытый"
		 *
		 * Взаимоисключающий с RshChannel::AC
		 *
		 */
		DC = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Turn OFF ICP power supply for channel
		 *
		 * Mutually exclusive with RshChannel::ICPPowerOn
		 *
		 * \~russian
		 * \brief
		 * Отключение ICP питания канала
		 *
		 * Взаимоисключающий с RshChannel::ICPPowerOn
		 *
		 */
		ICPPowerOff	= 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Channel will be used in data acquisition
		 *
		 * Mutually exclusive with RshChannel::NotUsed
		 *
		 * \~russian
		 * \brief
		 * Канал будет использоваться при сборе данных
		 *
		 * Взаимоисключающий с RshChannel::NotUsed
		 *
		 */
		Used = 0x1,

		/*!
		 *
		 * \~english
		 * \brief
		 * Channel will be used as trigger source
		 *
		 * Mutually exclusive with RshChannel::NoSynchro
		 *
		 * \~russian
		 * \brief
		 * Канал будет использоваться в качестве источника синхронизации
		 *
		 * Взаимоисключающий с RshChannel::NoSynchro
		 *
		 */
		Synchro = 0x2,

		/*!
		 *
		 * \~english
		 * \brief
		 * Set input to AC mode
		 *
		 * Mutually exclusive with RshChannel::DC
		 *
		 * \~russian
		 * \brief
		 * Установить состояние входа "закрытый"
		 *
		 * Взаимоисключающий с RshChannel::DC
		 *
		 */
		AC = 0x4,

		/*!
		 *
		 * \~english
		 * \brief
		 * Set 50Ohm resist for channel
		 *
		 * Mutually exclusive with RshChannel::Resist1MOhm
		 *
		 * \~russian
		 * \brief
		 * Установить входное сопротивление канала 50Ом
		 *
		 * Взаимоисключающий с RshChannel::Resist1MOhm
		 *
		 */
		Resist50Ohm	= 0x8,

		/*!
		 *
		 * \~english
		 * \brief
		 * Turn On ICP power supply for channel
		 *
		 * Mutually exclusive with RshChannel::ICPPowerOff
		 *
		 * \~russian
		 * \brief
		 * Включение ICP питания канала
		 *
		 * Взаимоисключающий с RshChannel::ICPPowerOff
		 *
		 */
		ICPPowerOn = 0x10,

		/*!
		 *
		 * \~english
		 * \brief
		 * Set channel as first channel to analog-digital conversation
		 *
		 * Not supported by most devices.
		 *
		 * \~russian
		 * \brief
		 * Выбрать канал в качестве первого канала для оцифровки
		 *
		 * Большинство устройств не поддерживает данную опцию.
		 *
		 */
		FirstChannel = 0x10000,
	};

	RshChannel(U32 Gain = 1, U32 Control = 0, double Adjustment = 0.0);

	RshChannel(const RshChannel& obj);

	RshChannel& operator=(const RshChannel& obj);

	bool operator==(RshChannel& obj) const;

	bool operator!=(RshChannel& obj) const;

	bool operator< (const RshChannel& obj) const;

	bool operator> (const RshChannel& obj) const;

	friend std::ostream& operator<< (std::ostream &out, const RshChannel& obj);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set channel parameters to default values
	 *
	 * gain = 1; adjustment = 0.0; control = 0;
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
	 * Set channel to be used (or not) in data acquisition
	 *
	 * \param[in] on
	 * If true, flag RshChannel::Used will be set,
	 * if false flag will be removed.
 	 *
	 * \~russian
	 * \brief
	 * Установка использования канала при сборе данных
	 *
	 * \param[in] on
	 * Если передано значение true, флаг RshChannel::Used будет включен,
	 * если false, то флаг будет снят.
	 *
	 */	
	void SetUsed(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshChannel::FirstChannel flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshChannel::FirstChannel
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 *
	 */	
	void SetFirstChannel(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshChannel::Synchro flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshChannel::Synchro
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 *
	 */	
	void SetSynchro(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshChannel::ICPPowerOn flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshChannel::ICPPowerOn
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 *
	 */	
	void SetICPPower(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshChannel::AC flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
	 * Setting RshChannel::AC flag automaticaly
	 * remove RshChannel::DC flag and vise versa.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshChannel::AC
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 * Установка флага RshChannel::AC приводит к снятию 
	 * флага RshChannel::DC; снятие флага RshChannel::AC
	 * приводит к установке флага RshChannel::DC.
	 *
	 */
	void SetInputAC(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshChannel::DC flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
	 * Setting RshChannel::DC flag automaticaly
	 * remove RshChannel::AC flag and vise versa.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshChannel::AC
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 * Установка флага RshChannel::DC приводит к снятию 
	 * флага RshChannel::AC; снятие флага RshChannel::DC
	 * приводит к установке флага RshChannel::AC.
	 *
	 */
	void SetInputDC(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshChannel::Resist50Ohm flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
	 * Setting RshChannel::Resist50Ohm flag automaticaly
	 * remove RshChannel::Resist1MOhm flag and vise versa.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshChannel::AC
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 * Установка флага RshChannel::Resist50Ohm приводит к снятию 
	 * флага RshChannel::Resist1MOhm; снятие флага RshChannel::Resist50Ohm
	 * приводит к установке флага RshChannel::Resist1MOhm.
	 *
	 */
	void SetResist50Ohm(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshChannel::Resist1MOhm flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
	 * Setting RshChannel::Resist1MOhm flag automaticaly
	 * remove RshChannel::Resist50Ohm flag and vise versa.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshChannel::AC
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 * Установка флага RshChannel::Resist1MOhm приводит к снятию 
	 * флага RshChannel::Resist50Ohm; снятие флага RshChannel::Resist1MOhm
	 * приводит к установке флага RshChannel::Resist50Ohm.
	 *
	 */
	void SetResist1MOhm(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshChannel::Used flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshChannel::Used
	 *
	 */	
	bool IsUsed() const;
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshChannel::FirstChannel flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshChannel::FirstChannel
	 *
	 */	
	bool IsFirstChannel() const;
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshChannel::Synchro flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshChannel::Synchro
	 *
	 */	
	bool IsSynchroSource() const;
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshChannel::ICPPowerOn flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshChannel::ICPPowerOn
	 *
	 */	
	bool IsICPPowerOn() const;
	
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

/*!
 *
 * \~english
 * \brief
 * RshBufferType of RshChannel structures
 *
 * Default size is equal to ::RSH_MAX_CHANNEL_NUMBER
 *
 * \~russian
 * \brief
 * Буфер RshBufferType из структур RshChannel
 *
 * Размер списка по умолчанию равен ::RSH_MAX_CHANNEL_NUMBER
 *
 */
typedef RshBufferType< RshChannel, rshBufferTypeChannel > RSH_BUFFER_CHANNEL;

#pragma pack(pop)
#endif// RSH_CHANNEL_H
