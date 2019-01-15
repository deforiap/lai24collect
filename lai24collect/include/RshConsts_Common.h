/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshConsts_Common.h
 * \date 25.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * Common constants for Rsh SDK
 *
 * \~russian
 * \brief
 * Общие константы Rsh SDK
 *
 */
 
#ifndef RSH_CONSTS_COMMON_H
#define RSH_CONSTS_COMMON_H


#define RSH_MAX_LIST_SIZE                32 
#define RSH_MAX_CHANNEL_NUMBER           RSH_MAX_LIST_SIZE 
#define RSH_MAX_SETTINGS_NUMBER          RSH_MAX_SETTINGS_NUMBER 

/*!
 * 
 * \~english
 * \brief
 * Infinite timeout for operations.
 * 
 * Pass this constant to event waiting functions
 * such as IRshDevice::Get() with ::RSH_GET_WAIT_BUFFER_READY_EVENT.
 * Timeout for operation will be set to infinite.
 * 
 * \remarks
 * The only way to exit waiting state is to reset event
 * (you can call IRshDevice::Stop() to do it).
 * 
 * \see
 * IRshDevice | RSH_GET_WAIT_BUFFER_READY_EVENT
 * 
 * \~russian
 * \brief
 * Бесконечное время ожидания для операций.
 * 
 * Используется для передачи в качестве времени ожидания в 
 * функции ожидания событий (например IRshDevice::Get() с
 * параметром ::RSH_GET_WAIT_BUFFER_READY_EVENT).
 * Время ожидания будет бесконечным, т.е. метод не вернет результат
 * до тех пор, пока не произойдет ожидаемое событие или какой-либо сбой.
 * 
 * \remarks
 * Единственный способ прервать ожидание при использовании данной 
 * константы - это сброс события (вызов IRshDevice::Stop() ).
 * 
 * \see
 * IRshDevice | RSH_GET_WAIT_BUFFER_READY_EVENT
 */
#define RSH_INFINITE_WAIT_TIME	0xFFFFFFFF

#endif //RSH_CONSTS_COMMON_H
