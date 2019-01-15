/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshInitTimer.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshInitTimer initialization structure.
 *
 * \~russian
 * \brief
 * Структура инициализации RshInitTimer.
 *
 */
 
#ifndef RSH_INIT_TIMER_H
#define RSH_INIT_TIMER_H

#include "RshBaseType.h"

#include <ostream>

#pragma pack(push, 8)

/*!
 *
 * \~english
 * \brief
 * Direct timers control structure
 *
 * This structure can be used for
 * devices with 3 channel timer installed.\n
 * Using this structure one can setup each
 * timer work mode and value, programming
 * device to do data acquisition in some
 * sophisticated manner.
 *
 * \see
 * ::RSH_CAPS_DEVICE_TIMER_8254
 *
 * \deprecated 
 * This structure is supposed to use with LA1.5PCI (and possibly LA2USB) device,
 * but all functionality is not supported in current SDK release
 *
 * \~russian
 * \brief
 * Прямое управление таймерами
 *
 * Данная структура инициализации может быть
 * использована для устройств, в которых
 * установлен трехканальный счетчик-таймер.\n
 * С помощью данной структуры можно задать значение
 * для каждого таймера, а также режим его работы.
 * Таким образом, можно установить некий специфический
 * режим работы устройства, который невозможно реализовать
 * через стандартные структуры инициализации.
 *
 * \see
 * ::RSH_CAPS_DEVICE_TIMER_8254
 *
 * \deprecated 
 * Предполагалось, что данная структура будет использоваться для
 * устройства ЛА1.5PCI (и, возможно, ЛА2USB), но полная поддержка
 * данной структуры не реализована в текущей версии SDK.
 *
 */
struct  RshInitTimer : public RshBaseType
{
	/*!
	 *
	 * \~english
	 * \brief
	 * Work mode for timer 0.
	 *
	 * One value from RshInitTimer::TimerMode enum.
	 *
	 * \~russian
	 * \brief
	 * Режима работы счетчика-таймера 0.
	 *
	 * Одно из значений перечисления RshInitTimer::TimerMode.
	 *
	 */
    U32 timer0Mode;

	/*!
	 *
	 * \~english
	 * \brief
	 * Work mode for timer 1.
	 *
	 * One value from RshInitTimer::TimerMode enum.
	 *
	 * \~russian
	 * \brief
	 * Режима работы счетчика-таймера 1.
	 *
	 * Одно из значений перечисления RshInitTimer::TimerMode.
	 *
	 */
	U32 timer1Mode;

	/*!
	 *
	 * \~english
	 * \brief
	 * Work mode for timer 2.
	 *
	 * One value from RshInitTimer::TimerMode enum.
	 *
	 * \~russian
	 * \brief
	 * Режима работы счетчика-таймера 2.
	 *
	 * Одно из значений перечисления RshInitTimer::TimerMode.
	 *
	 */
	U32 timer2Mode;

	/*!
	 *
	 * \~english
	 * \brief
	 * Counter value for timer 0.
	 *
	 * \~russian
	 * \brief
	 * Значение счетчика для таймера 0.
	 *
	 */
	U32 timer0Count;

	/*!
	 *
	 * \~english
	 * \brief
	 * Counter value for timer 1.
	 *
	 * \~russian
	 * \brief
	 * Значение счетчика для таймера 1.
	 *
	 */
	U32 timer1Count;

	/*!
	 *
	 * \~english
	 * \brief
	 * Counter value for timer 2.
	 *
	 * \~russian
	 * \brief
	 * Значение счетчика для таймера 2.
	 *
	 */
	U32 timer2Count;

	/*!
	 *
	 * \~english
	 * \brief
	 * Timer work mode selection
	 *
	 * \~russian
	 * \brief
	 * Выбор режима работы счетчика-таймера.
	 *
	 */
	enum TimerMode
	{
		/*!
		 * \~english
		 * \brief
		 * Interrupt on terminal count.
		 * \~russian
		 * \brief
		 * Прерывание терминального счета.
		 */
		InterruptOnTerminalCount = 0,

		/*!
		 * \~english
		 * \brief
		 * Programmable one shot.
		 * \~russian
		 * \brief
		 * Ждущий мультивибратор.
		 */
		ProgrammableOneShot = 1,

		/*!
		 * \~english
		 * \brief
		 * Rate generator.
		 * \~russian
		 * \brief
		 * Генератор частоты.
		 */
		RateGenerator = 2,

		/*!
		 * \~english
		 * \brief
		 * Square wave generator.
		 * \~russian
		 * \brief
		 * Генератор меандра.
		 */
		SquareWaveGenerator = 3,

		/*!
		 * \~english
		 * \brief
		 * Software triggered strobe.
		 * \~russian
		 * \brief
		 * Счетчик событий.
		 */
		SoftwareTriggeredStrobe = 4,

		/*!
		 * \~english
		 * \brief
		 * Hardware tiggered strobe.
		 * \~russian
		 * \brief
		 * Счетчик событий с автозагрузкой.
		 */
		HardwareTriggeredStrobe = 5
	};

	RshInitTimer();

	RshInitTimer(RshInitTimer const& obj);

	RshInitTimer& operator=(const RshInitTimer& obj);

	bool operator==(RshInitTimer& obj) const;

	bool operator!=(RshInitTimer& obj) const;

	static const char* TimerModeString(U32 timerMode);

	friend std::ostream& operator<< (std::ostream &out, const RshInitTimer& obj);
};

#pragma pack(pop)
#endif //RSH_INIT_TIMER_H