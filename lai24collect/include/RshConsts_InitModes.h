/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshConsts_InitModes.h
 * \date 25.12.2015
 * \version 1.0 [SDK 2.1]
 *
* \~english
 * \brief
 * Device init modes constants for Rsh SDK
 *
 * \~russian
 * \brief
 * Константы вариантов инициализации устройства Rsh SDK
 *
 */
 
#ifndef RSH_CONSTS_INIT_MODES_H
#define RSH_CONSTS_INIT_MODES_H

/*!
 * 
 * \~english
 * \brief
 * Initialization modes.
 *
 * \see
 * IRshDevice::Init().
 * 
 * \~russian
 * \brief
 * Варианты инициализации.
 * 
 * \see
 * IRshDevice::Init().
 */
typedef enum
{
	/*!
	 * \~english
	 * \brief
	 * Check initialization structure and return.
	 *
	 * If IRshDevice::Init() is used with this code,
	 * method will only check (and correct) parameters in
	 * initialization structure.
	 *
	 *
	 * \~russian
	 * \brief
	 * Только проверка параметров инициализации в структуре.
	 *
	 * Если метод IRshDevice::Init() вызывается с использованием
	 * этого параметра, то результатом его работы будет только
	 * проверка и корректировка параметров в структуре инициализации,
	 * без физического обращения к устройству.
	 */
	RSH_INIT_MODE_CHECK  = 0,

	/*!
	 * \~english
	 * \brief
	 * Correct structure parameters and do hardware initialization.
	 *
	 * If IRshDevice::Init() is used with this code,
	 * method will check (and correct) parameters in
	 * initialization structure and then send those parameters
	 * to device.
	 *
	 *
	 * \~russian
	 * \brief
	 * Проверка параметров в структуре и фактическая инициализация.
	 *
	 * Если метод IRshDevice::Init() вызывается с использованием
	 * этого параметра, то параметры инициализации в структуре
	 * будут откорректированы, и после этого отправлены в устройство.
	 *
	 */
	RSH_INIT_MODE_INIT  = 1,

	/*!
	 * \~english
	 * \brief
	 * Forced reinitialization
	 *
	 * If IRshDevice::Init() is used with this code,
	 * parameters passed in initialization structure will be  resend
	 * to device even if all parameters are equal to parameters from
	 * previous IRshDevice::Init() call.\n
	 *
	 * \remarks
	 * Not all libraries support this feature.
	 *
	 *
	 * \~russian
	 * \brief
	 * Принудительная переинициализация
	 *
	 * При вызове метода IRshDevice::Init() параметры инициализации
	 * запоминаются. Это относится только к тем вызовам, где идет фактическая 
	 * инициализация, т.е. к вызовам с параметром RSH_INIT_MODE_INIT или RSH_INIT_MODE_REINIT,
	 * причем вызов должен завершиться успешно, чтобы параметры были запомнены.\n
	 * 
	 * Последующие вызовы IRshDevice::Init() с теми же самыми параметрами не имеют эффекта,
	 * так как внутри метода IRshDevice::Init() производится сравнение параметров с предыдущим
	 * вызовом, и если они идентичны, метод сразу возвращает ::RSH_API_SUCCESS.\n
	 *
	 * Использование данного флага заставляет метод IRshDevice::Init() провести 
	 * фактическую инициализацию (с записью параметров в регистры устройства), даже в том случае,
	 * если структура инициализации полностью совпадает с сохраненной.
	 *
	 * \remarks
	 * Данная опция поддерживается не во всех библиотеках абстракции.
	 *
	 */
	RSH_INIT_MODE_REINIT = 2

} RSH_INIT_MODES;

#endif //RSH_CONSTS_INIT_MODES_H
