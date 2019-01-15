/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitDMA.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitDMA initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitDMA.
 *
 */
 
#ifndef RSH_INIT_DMA_H
#define RSH_INIT_DMA_H

#include "RshInitADC.h"

#include <ostream>

struct RshInitMemory;

#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * Initialization structure for DMA-type devices
 *
 * This structure usually is used for low-frequency
 * (10MHz or less) devices. One can use
 * ::RSH_CAPS_SOFT_INIT_DMA to find if
 * device abstraction library supports this structure
 * or not.\n
 * DMA-type device features:\n
 * low-frequency, can work in continious data acquisition moode,
 * do not have onboard memory (usually), do not have many
 * synchronization possibilities.
 *
 * \remarks
 * DMA name is used for historical reasons, some devices
 * do not have actual DMA feature (all USB devices, for examples).
 *
 * \~russian
 * \brief
 * Структура инициализации для устройств типа "DMA"
 *
 * Обычно, данная структура используется для относительно
 * низкочастотных устройств (10МГц и ниже). Узнать, поддерживается
 * ли эта структура библиотекой абстракции устройства можно,
 * используя капс ::RSH_CAPS_SOFT_INIT_DMA.\n
 * Характерные особенности устройства типа "DMA":\n
 * относительно низкая частота дискретизации, возможность
 * работать в непрерывном режиме, отсутствие собственной
 * памяти (хотя есть исключения), отсутствие (или сильно ограничены)
 * возможности синхронизации.
 *
 * \remarks
 * Название "DMA" у структуры осталось по историческим причинам (SDK1).
 * Некоторые устройства, которые можно инициализировать данной структурой,
 * на самом деле не могут передавать данные, используя ПДП (например, все
 * USB устройства).
 *
 */
struct RshInitDMA : public RshInitADC
{
	/*!
	 *
	 * \~english
	 * \brief
	 * Data acquisition modes list
	 *
	 * Values from this list are
	 * mutually exclusive (that is, use
	 * only one mode). Set it to the
	 * RshInitDMA::dmaMode field.
	 *
	 * \~russian
	 * \brief
	 * Список режимов сбора данных
	 *
	 * Значения из этого списка - взаимоисключающие
	 * (можно единовременно задать только один из
	 * режимов работы). Режим задается в поле RshInitDMA::dmaMode
	 * структуры инициализации.
	 *
	 */
	enum  DmaMode
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * Single buffer mode
		 *
		 * So called "Start-Stop" mode.\n
		 * Only one buffer of specified size is
		 * acquired, and then data transfer process is
		 * terminated.
		 *
		 * \see
		 * RSH_CAPS_SOFT_GATHERING_IS_AVAILABLE
		 *
		 * \~russian
		 * \brief
		 * Одиночный запуск
		 *
		 * Так называемый режим "Старт-Стоп".\n
		 * В этом режиме собирается один буфер заданного
		 * размера, после чего процесс сбора данных останавливается
		 * (прекращается переда по ПДП, если она была активна).
		 *
		 * \see
		 * RSH_CAPS_SOFT_GATHERING_IS_AVAILABLE
		 *
		 */
		Single= 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Continuous mode
		 *
		 * In this mode data acquisition and transfer
		 * will continue forever, until IRshDevice::Stop()
		 * method is called.
		 *
		 * \see
		 * RSH_CAPS_SOFT_PGATHERING_IS_AVAILABLE
		 *
		 * \~russian
		 * \brief
		 * Непрерывный режим
		 *
		 * В этом режиме процесс сбора и передачи данных
		 * будет продолжаться бесконечно (в теории), до вызова
		 * метода IRshDevice::Stop().
		 *
		 * \see
		 * RSH_CAPS_SOFT_PGATHERING_IS_AVAILABLE
		 *
		 */
		Persistent = 0x1,
	};

	/*!
	 *
	 * \~english
	 * \brief
	 * Data acquisition mode.
	 *
	 * One of the elements of RshInitDMA::DmaMode
	 * enum. There are only two modes actually:
	 * "Start-stop" mode and continuous mode.\n
	 * One can use ::RSH_CAPS_SOFT_GATHERING_IS_AVAILABLE
	 * and ::RSH_CAPS_SOFT_PGATHERING_IS_AVAILABLE caps
	 * to check if device supports work in this two modes.
	 *
	 * \~russian
	 * \brief
	 * Режим сбора данных
	 *
	 * Один из элементов перечисления RshInitDMA::DmaMode.
	 * Существует два возможных сценария работы: работа в режиме
	 * "Старт-Стоп" или работа в непрерывном режиме.\n
	 * Используейте соответствующие капсы (::RSH_CAPS_SOFT_GATHERING_IS_AVAILABLE
	 * и ::RSH_CAPS_SOFT_PGATHERING_IS_AVAILABLE) чтобы проверить,
	 * поддерживает ли устройство работу в каждом из режимов.
	 *
	 */
	U32 dmaMode;

	/*!
	 *
	 * \~english
	 * \brief
	 * Additional options
	 *
	 * Combination of flags from
	 * RshInitDMA::Control enum.
	 * By default, RshInitDMA::StandardMode
	 * flag is used.
	 *
	 * \~russian
	 * \brief
	 * Дополнительные опции
	 *
	 * Комбинация флагов перечисления
	 * RshInitDMA::Control. По умолчанию,
	 * используется флаг RshInitDMA::StandardMode.
	 *
	 */
	U32 control;

	/*!
	 *
	 * \~english
	 * \brief
	 * Sampling rate inside frame
	 *
	 * Actual for \link page_FrameFreqMode Frame Frequency work mode \endlink.
	 *
	 * \remarks
	 * Use ::RSH_CAPS_DEVICE_FRAME_FREQUENCY_MODE caps
	 * to find if devie supports this mode or not.
	 *
	 * \~russian
	 * \brief
	 * Частота дискретизации внутри кадра
	 *
	 * Данный параметр используется при включенном
	 * \link page_FrameFreqMode режиме кадрового сбора \endlink.
	 *
	 * \remarks
	 * Используйте ::RSH_CAPS_DEVICE_FRAME_FREQUENCY_MODE для того,
	 * чтобы определить, поддерживает ли устройство данный
	 * режим работы или нет.
	 *
	 */
	double frequencyFrame;

	/*!
	 *
	 * \~english
	 * \brief
	 * List of additional flags
	 *
	 * Use flags combined by 'OR' statement
	 * to specify additional options in
	 * RshInitDMA::control field.
	 *
	 * \~russian
	 * \brief
	 * Список дополнительных опций сбора данных
	 *
	 * Флаги из этого списка можно объединять
	 * по 'ИЛИ'. Установив нужную комбинацию
	 * флагов в поле RshInitDMA::control, можно
	 * задействовать дополнительные опции.
	 *
	 */
	enum  Control
	{
		/*!
		 *
		 * \~english
		 * \brief
		 * No special options used
		 *
		 * This flag can be omited and used only for
		 * more readable code.\n
		 * This flag meaning is: no differential mode, no frame
		 * frequency mode.
		 *
		 * \~russian
		 * \brief
		 * Дополнительные опции не используются
		 *
		 * Нет необходимости специально указывать
		 * данный флаг (т.к. это значение по умолчанию).
		 * Используется для повышения читаемости кода.\n
		 * Данный флаг означает: однополюсный вход,
		 * кадровый режим не используется.
		 *
		 */
		StandardMode = 0x0,

		/*!
		 *
		 * \~english
		 * \brief
		 * Turn on differential mode
		 *
		 * One can check if device supports this mode
		 * or not by using ::RSH_CAPS_DEVICE_DIFFERENTIAL_INPUT_MODE.\n
		 * See device user manual for details about analog input pin connect
		 * in two work modes.
		 *
		 * \~russian
		 * \brief
		 * Включение дифференциального режима работы
		 *
		 * Проверить, поддерживает ли устройство данный режим
		 * работы или нет, можно с помощью ::RSH_CAPS_DEVICE_DIFFERENTIAL_INPUT_MODE.\n
		 *
		 * \remarks
		 * Схема подключения для однополюсного и дифференциального режимов
		 * обычно приводится в руководстве пользователя для данного устройства.
		 *
		 */
		DiffMode = 0x1,

		/*!
		 *
		 * \~english
		 * \brief
		 * Turn on frame sampling mode
		 *
		 * When this flag is active, RshInitDMA::frequencyFrame
		 * field value is used as sampling rate inside frame.
		 *
		 * \~russian
		 * \brief
		 * Включение кадрового режима сбора
		 *
		 * Когда данный флаг включен, значение поля
		 * RshInitDMA::frequencyFrame используется для
		 * установки частоты дискретизации внутри кадра.
		 *
		 */
		FrameMode = 0x2,

		/*!
		 *
		 * \~english
		 * \brief
		 * Switch multiplexor on start
		 *
		 * \deprecated
		 * Not used at this moment, can be
		 * excluded from future releases.
		 *
		 * \~russian
		 * \brief
		 * Переключение мультиплексора по старту
		 *
		 * \deprecated
		 * В текущий момент не используется, возможно будет удалено
		 * в следующих релизах.
		 *
		 */
		MulSwitchStart = 0x4,
	};



	RshInitDMA();

    RshInitDMA(RshInitADC const& obj);

    RshInitDMA(RshInitDMA const& obj);

	RshInitDMA& operator=(const RshInitDMA& obj);
	RshInitDMA& operator=(const RshInitMemory& obj);

	bool operator==(RshInitDMA& obj) const;

	bool operator!=(RshInitDMA& obj) const;

	friend std::ostream& operator<< (std::ostream &out, const RshInitDMA& obj);

	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshInitDMA::DiffMode flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие RshInitDMA::DiffMode
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 *
	 */
	void SetDiffMode(bool on = true);

	/*!
	 *
	 * \~english
	 * \brief
	 * Set or remove RshInitDMA::FrameMode flag
	 *
	 * \param[in] on
	 * If true, flag will be set,
	 * if false flag will be removed.
 	 *
	 * \~russian
	 * \brief
	 * Установка или снятие RshInitDMA::FrameMode
	 *
	 * \param[in] on
	 * Если передано значение true, флаг будет установлен,
	 * если false, то флаг будет снят.
	 *
	 */
	void SetFrameMode(bool on = true);

	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitDMA::DiffMode flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitDMA::DiffMode
	 *
	 */	
	bool IsDiffModeActive() const;

	/*!
	 *
	 * \~english
	 * \brief
	 * Check RshInitDMA::FrameMode flag
	 *
	 * \~russian
	 * \brief
	 * Проверка наличия флага RshInitDMA::FrameMode
	 *
	 */	
	bool IsFrameModeActive() const;
};
 
 
#pragma pack(pop)
 
#endif //RSH_INIT_DMA_H