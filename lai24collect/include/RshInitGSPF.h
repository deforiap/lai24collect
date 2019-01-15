/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitGSPF.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitGSPF initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitGSPF.
 *
 */
 
#ifndef RSH_INIT_GSPF_H
#define RSH_INIT_GSPF_H

#include "RshBaseType.h"

#include <ostream>

#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * Initialization structure for signal generators
 *
 * This structure is used for GSPF series devices.\n
 * Corresponding caps codes are ::RSH_CAPS_SOFT_GENERATION_IS_AVAILABLE
 * and ::RSH_CAPS_SOFT_INIT_GSPF.
 *
 * \see
 * RshInitDAC
 *
 * \~russian
 * \brief
 * Cтруктура инициализации для генераторов
 *
 * Данная структура используется для управления
 * генераторами сигнала серии ГСПФ.\n
 * Соответствующие капс-коды: ::RSH_CAPS_SOFT_GENERATION_IS_AVAILABLE
 * и ::RSH_CAPS_SOFT_INIT_GSPF.
 *
 * \see
 * RshInitDAC
 *
 */
struct  RshInitGSPF : public RshBaseType
{
	/*!
	 *
	 * \~english
	 * \brief
	 * List of attenuator modes
	 *
	 * Elements from this list can be used
	 * as value for RshInitGSPF::attenuator field.
	 *
	 * \~russian
	 * \brief
	 * Список режимов работы аттенюатора
	 *
	 * Элементы этого перечисления могут быть
	 * использованы в качестве значений для
	 * поля RshInitGSPF::attenuator.
	 *
	 */
	enum Attenuator
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Attenuation is not used
		 *
		 * \~russian
		 * \brief
		 * Ослабление не используется
		 *
		 */
		AttenuationOff = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * 6dB attenuation
		 *
		 * \~russian
		 * \brief
		 * Ослабление 6дБ
		 *
		 */
		Attenuation6dB = 0x1,

		/*!
		 *
		 * \~english
		 * \brief
		 * 12dB attenuation
		 *
		 * \~russian
		 * \brief
		 * Ослабление 12дБ
		 *
		 */
		Attenuation12dB = 0x2,

		/*!
		 *
		 * \~english
		 * \brief
		 * 18dB attenuation
		 *
		 * \~russian
		 * \brief
		 * Ослабление 18дБ
		 *
		 */
		Attenuation18dB = 0x3,

		/*!
		 *
		 * \~english
		 * \brief
		 * 24dB attenuation
		 *
		 * \~russian
		 * \brief
		 * Ослабление 24дБ
		 *
		 */
		Attenuation24dB = 0x4,

		/*!
		 *
		 * \~english
		 * \brief
		 * 30dB attenuation
		 *
		 * \~russian
		 * \brief
		 * Ослабление 30дБ
		 *
		 */
		Attenuation30dB = 0x5,

		/*!
		 *
		 * \~english
		 * \brief
		 * 36dB attenuation
		 *
		 * \~russian
		 * \brief
		 * Ослабление 36дБ
		 *
		 */
		Attenuation36dB = 0x6,

		/*!
		 *
		 * \~english
		 * \brief
		 * 42dB attenuation
		 *
		 * \~russian
		 * \brief
		 * Ослабление 42дБ
		 *
		 */
		Attenuation42dB = 0x7

	};

	/*!
	 *
	 * \~english
	 * \brief
	 * Data generation start mode
	 *
	 * One of RshInitGSPF::StartType enum
	 * constants, that determine, how
	 * DAC will be started.
	 *
	 * \~russian
	 * \brief
	 * Режим запуска генерации сигнала
	 *
	 * Одна из констант перечисления
	 * RshInitGSPF::StartType, которая определяет,
	 * как будет запускаться генерация сигнала.
	 *
	 */
    U32 startType;

    /*!
	 *
	 * \~english
	 * \brief
	 * Generator sampling rate
	 *
	 * Sampling rate of the generator in Hz.\n
	 * Depending on RshInitGSPF::control value
	 * may be one of the predefined frequencies from
	 * frequency list (see ::RSH_GET_DEVICE_FREQUENCY_LIST),
	 * or frequency synthesizer created frequency.
	 *
	 * \~russian
	 * \brief
	 * Частота дискретизации
	 *
	 * Частота дискретизации, которая будет
	 * использована при генерации сигнала, в Гц.\n
	 * В зависимости от состояния поля RshInitGSPF::control будет
	 * использована частота из списка частот
	 * (см. ::RSH_GET_DEVICE_FREQUENCY_LIST), либо близкая к
	 *  заданной частота, созданная синтезатором частоты.
	 *
	 */
	double frequency;

    /*!
	 *
	 * \~english
	 * \brief
	 * Attenuator value
	 *
	 * One of the RshInitGSPF::Attenuator enum
	 * values. Predifined set of attenuation level
	 * constants can be used.\n
	 * By default, signal is not attenuated.
	 *
	 * \remarks
	 * Attenuation is applied to signal just
	 * before output, that means, that using attenuator
	 * one can improve DAC dynamic range for small amplitude
	 * signals generated.
	 *
	 * \~russian
	 * \brief
	 * Аттенюатор
	 *
	 * Один из элементов перечисления RshInitGSPF::Attenuator.\n
	 * С помощью этого поля можно задать дополнительное
	 * ослабление сигнала.\n
	 * По умолчанию, ослабление не используется.
	 *
	 * \remarks
	 * При использовании аттенюатора, ослабление сигнала происходит
	 * уже после его формирования ЦАПом, непосредственно перед
	 * выдачей сигнала на выход генератора. Таким образом, используя
	 * аттенюатор, можно более полно использовать динамический
	 * диапазон ЦАП при генерации слабых сигналов.
	 *
	 */
	U32 attenuator;

	/*!
	 *
	 * \~english
	 * \brief
	 * Additional flags
	 *
	 * 'OR' Combination of RshInitGSPF::Control
	 * enum elements. This field is used to specify
	 * additional signal generation options, such as
	 * using of frequency synthesizer, filter and so on.
	 *
	 * \remarks
	 * By default, this parameter is equal to zero,
	 * which corresponds to following flag combination:\n
	 * <b>RshInitGSPF::SynthesizerOff | RshInitGSPF::FilterOff | RshInitGSPF::PlayOnce | RshInitGSPF::SynchroFront</b>
	 *
	 * \~russian
	 * \brief
	 * Дополнительные флаги
	 *
	 * Комбинация по 'ИЛИ' элементов перечисления
	 * RshInitGSPF::Control. Данное поле используется
	 * для управления дополнительными параметрами генерации
	 * сигнала, такими как использование синтезатора частоты,
	 * фильтра и др.
	 *
	 * \remarks
	 * По умолчанию, данный параметр равен нулю, что
	 * соответствует следующей комбинации флагов:\n
	 * <b>RshInitGSPF::SynthesizerOff | RshInitGSPF::FilterOff | RshInitGSPF::PlayOnce | RshInitGSPF::SynchroFront</b>
	 *
	 */
	U32 control;

	/*!
	 *
	 * \~english
	 * \brief
	 * Start mode list
	 *
	 * This enum entities can be used
	 * to specify how to start generation process.\n
	 * To do so, set one of them as value
	 * for RshInitGSPF::startType field.
	 *
	 * \~russian
	 * \brief
	 * Список режимов запуска
	 *
	 * Элементы этого перечисления используются
	 * для задания режима запуска процесса генерации.\n
	 * Чтобы выбрать режим, нужно установить
	 * одно из этих значений в поле RshInitGSPF::startType.
	 *
	 */
	enum  StartType
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Program start
		 *
		 * Generation will start as soon as
		 * command will be acquired by the device.\n
		 * That means, DAC will start as soon as
		 * IRshDevice::Start() method is called.
		 *
		 * \remarks
		 * "As soon" is not immediately, because
		 * there is always some delays for functions calls,
		 * data transfer and device responce.
		 *
		 * \~russian
		 * \brief
		 * Программный запуск
		 *
		 * Генерация будет запущена сразу же
		 * после получения устройством команды на запуск.\n
		 * Это означает, что ЦАП будет запущен сразу же после
		 * вызова метода IRshDevice::Start().
		 *
		 * \remarks
		 * "Сразу же" на самом деле происходит не мгновенно, так
		 * как всегда есть задержки - вызов функций, передача
		 * данных по шине, отклик устройства.
		 *
		 */
		Program = 0x1,

		/*!
		 *
		 * \~english
		 * \brief
		 * Start signal generation on external trigger
		 *
		 * Use external trigger input as source for
		 * signal generation start command.
		 *
		 * \~russian
		 * \brief
		 * Внешний запуск
		 *
		 * Использовать внешний источник
		 * для запуска процесса генерации сигнала.\n
		 * Генерация будет запущена по приходу соответствующего
		 * строба запуска на вход внешнего запуска.\n
		 * Дополнительную информацию о необходимых параметрах
		 * запускающего сигнала можно найти в руководстве пользователя.
		 *
		 */
		External = 0x4,

		/*!
		 *
		 * \~english
		 * \brief
		 * Use external frequency source for sampling
		 *
		 * External frequency will be used for
		 * sampling DAC.\n
		 * External input is used as sampling source for
		 * DAC. See user manual for details about sampling
		 * signal parameters.
		 *
		 * \~russian
		 * \brief
		 * Использование внешней частоты дискретизации
		 *
		 * ЦАП будет тактироваться от внешнего источника частоты
		 * дискретизации.\n
		 * Дополнительную информацию о необходимых параметрах
		 * тактирующего сигнала можно найти
		 * в руководстве пользователя.
		 *
		 */
		FrequencyExternal = 0x10
	};

	/*!
	 *
	 * \~english
	 * \brief
	 * List of additional flags
	 *
	 * Use this flags
	 * to specify additional options in
	 * RshInitGSPF::control field.
	 *
	 * \~russian
	 * \brief
	 * Список дополнительных параметров генерации
	 *
	 * Флаги из этого списка можно использовать
	 * в поле RshInitGSPF::control, чтобы
	 * задействовать дополнительные режимы генерации сигнала.
	 *
	 */
	enum Control
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Turn OFF filter
		 *
		 * Mutually exclusive with RshInitGSPF::FilterOn
		 *
		 * \~russian
		 * \brief
		 * Выключить фильтр НЧ
		 *
		 * Выключение ФНЧ.
		 * Взаимоисключающий с RshInitGSPF::FilterOn
		 *
		 */
		FilterOff = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Play buffer only once
		 *
		 * Signal in buffer will be played once, and then DAC will
		 * be stopped.\n
		 * Mutually exclusive with RshInitGSPF::PlayLoop.
		 *
		 * \~russian
		 * \brief
		 * Одиночное проигрование
		 *
		 * Записанный в буфер сигнал будет выведен на ЦАП,
		 * после чего проигрование остановится.\n
		 * Взаимоисключающий с RshInitGSPF::PlayLoop.
		 *
		 */
		PlayOnce = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Start generation on trigger front
		 *
		 * Only valid when RshInitGSPF::External is used as
		 * RshInitGSPF::startType value.\n
		 * Generation will be started on trigger front.
		 * Mutually exclusive with RshInitGSPF::SynchroDecline.
		 *
		 * \~russian
		 * \brief
		 * Запуск по фронту
		 *
		 * Актуально только при использовании запуска
		 * с флагом RshInitGSPF::External.\n
		 * Генерация сигнала начнется по фронту запускающего импульса.
		 * Взаимоисключающий с RshInitGSPF::SynchroDecline.
		 *
		 */
		SynchroFront = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Frequency synthesizer is not used
		 *
		 * DAC will be sampled using Quartz frequency and devider.\n
		 * Mutually exclusive with RshInitGSPF::SynthesizerOn.
		 *
		 * \~russian
		 * \brief
		 * Синтезатор частоты не исползуется
		 *
		 * ЦАП будет тактироваться от кварцевого генератора (с делителем)\n
		 * Взаимоисключающий с RshInitGSPF::SynthesizerOn.
		 *
		 */
		SynthesizerOff = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Frequency synthesizer is used
		 *
		 * DAC will be sampled by frequency synthesizer.\n
		 * Mutually exclusive with RshInitGSPF::SynthesizerOff.
		 *
		 * \~russian
		 * \brief
		 * Использовать синтезатор частоты
		 *
		 * Синтезатор частоты будет использоваться в качестве
		 * источника тактовых импульсов для ЦАП.\n
		 * Взаимоисключающий с RshInitGSPF::SynthesizerOff.
		 *
		 */
		SynthesizerOn = 0x1,

		/*!
		 *
		 * \~english
		 * \brief
		 * Turn ON filter
		 *
		 * Turn on low pass filter with cut edge at 10.7MHz
		 * Mutually exclusive with RshInitGSPF::FilterOff
		 *
		 * \~russian
		 * \brief
		 * Включить фильтр НЧ
		 *
		 * Включение ФНЧ с частотой среза 10.7МГц.
		 * Взаимоисключающий с RshInitGSPF::FilterOff
		 *
		 */
		FilterOn = 0x2,

		/*!
		 *
		 * \~english
		 * \brief
		 * Play buffer continuously
		 *
		 * Signal in buffer will be played continuously.\n
		 * Mutually exclusive with RshInitGSPF::PlayOnce.
		 *
		 * \remarks
		 * When using this flag, signal will be played even
		 * when your program is no more running. Call
		 * IRshDevice::Stop() to stop playing.
		 *
		 * \~russian
		 * \brief
		 * Циклическое проигрование
		 *
		 * Записанный в буфер сигнал будет проигрываться
		 * циклически.\n
		 * Взаимоисключающий с RshInitGSPF::PlayOnce.
		 *
		 * \remarks
		 * При использовании данного флага, сигнал будет
		 * проигрываться даже после завершения работы
		 * программы. Чтобы остановать проигрование, нужно вызвать
		 * метод IRshDevice::Stop().
		 *
		 */
		PlayLoop = 0x4,

		/*!
		 *
		 * \~english
		 * \brief
		 * Start generation on trigger decline
		 *
		 * Only valid when RshInitGSPF::External is used as
		 * RshInitGSPF::startType value.\n
		 * Generation will be started on trigger decline.
		 * Mutually exclusive with RshInitGSPF::SynchroFront.
		 *
		 * \~russian
		 * \brief
		 * Запуск по спаду
		 *
		 * Актуально только при использовании запуска
		 * с флагом RshInitGSPF::External.\n
		 * Генерация сигнала начнется по спаду запускающего импульса.
		 * Взаимоисключающий с RshInitGSPF::SynchroFront.
		 *
		 */
		SynchroDecline = 0x8
	};

    RshInitGSPF();

	RshInitGSPF(RshInitGSPF const& obj);

	RshInitGSPF& operator=(const RshInitGSPF& obj);

	bool operator==(RshInitGSPF& obj) const;

	bool operator!=(RshInitGSPF& obj) const;

	friend std::ostream& operator<< (std::ostream &out, const RshInitGSPF& obj);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshInitGSPF::FilterOn flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshInitGSPF::FilterOn
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 *
	 */
	void SetFilterOn(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshInitGSPF::SynthesizerOn flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие флага RshInitGSPF::SynthesizerOn
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 *
	 */
	void SetSynthesizerOn(bool on = true);
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitGSPF::SynchroFront flag
	 *
	 * Set synchronization mode using signal front
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitGSPF::SynchroFront
	 *
	 * Синхронизация по фронту
	 *
	 */
	void SetSynchroSlopeFront();

	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitGSPF::SynchroDecline flag
	 *
	 * Set synchronization mode using signal decline
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitGSPF::SynchroDecline
	 *
	 * Синхронизация по спаду
	 *
	 */
	void SetSynchroSlopeDecline();
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitGSPF::PlayOnce flag
	 *
	 * Set  signal play mode to "play once"
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitGSPF::PlayOnce
	 *
	 * Сигнал  (буфер) будет проигран только один раз
	 *
	 */
	void SetPlayModeOnce();

	/*!
	 *
	 * \~english
	 * \brief
	 * Set RshInitGSPF::PlayLoop flag
	 *
	 * Set  signal play mode to "play loop"
 	 *
	 * \~russian
	 * \brief
	 * Установка флага RshInitGSPF::PlayLoop
	 *
	 * Циклическое проигрывание сигнала (буфера).
	 * Сигнал будет проигрываться до вызова метода Stop().
	 *
	 */
	void SetPlayModeLoop();
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitGSPF::SynchroFront flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitGSPF::SynchroFront
	 *
	 */	
	bool IsSynchroSlopeFrontActive() const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitGSPF::SynchroDecline flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitGSPF::SynchroDecline
	 *
	 */	
	bool IsSynchroSlopeDeclineActive() const;
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitGSPF::FilterOn flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitGSPF::FilterOn
	 *
	 */	
	bool IsFilterOn() const;
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitGSPF::SynthesizerOn flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitGSPF::SynthesizerOn
	 *
	 */	
	bool IsSynthesizerOn() const;
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitGSPF::PlayOnce flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitGSPF::PlayOnce
	 *
	 */	
	bool IsPlayModeOnceOn() const;
	
	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitGSPF::PlayLoop flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitGSPF::PlayLoop
	 *
	 */	
	bool IsPlayModeLoopOn() const;
};

#pragma pack(pop)
#endif //RSH_INIT_GSPF_H 
