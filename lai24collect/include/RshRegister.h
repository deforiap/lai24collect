/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshRegister.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshRegister class.
 *
 * \~russian
 * \brief
 * Класс RshRegister.
 *
 */
 
#ifndef RSH_REGISTER_H
#define RSH_REGISTER_H

#include "RshBaseType.h"

#include <ostream>


#pragma pack(push, 8)

/*!
 * 
 * \~english
 * \brief
 * Register data structure.
 * 
 * This structure is used to pass 
 * parameters to or from device registers.
 * 
 * \see
 * RSH_GET_DEVICE_REGISTER_BOARD | RSH_GET_DEVICE_REGISTER_BOARD_SET  
 * 
 * \~russian
 * \brief
 * Структура с данными регистра
 * 
 * Данная структура используется для передачи
 * параметров в регистры устройтсва.
 *
 * \see
 * RSH_GET_DEVICE_REGISTER_BOARD | RSH_GET_DEVICE_REGISTER_BOARD_SET  
 * 
 */
struct RshRegister : public RshBaseType {
	/*!
	* 
	* \~english
	* \brief
	* Size of register in bytes
	*
	* Possible values are 1, 2 and 4.
	* Register size depends on device type,
	* see device documentation for more info.
	* 
	* \~russian
	* \brief
	* Размер регистра в байтах
	*
	* Допустимые значения: 1, 2 и 4 байта.
	* Размер регистра зависит от устройства,
	* смотрите документацию к устройтсву для
	* получения дополнительной информации.
	* 
	*/
	U8 size;
	/*!
	* 
	* \~english
	* \brief
	* Register address
	*
	* Register address (offset) for memory
	* mapped registers or actual register number.
	* See device documentation for more info.
	* 
	* \~russian
	* \brief
	* Адрес регистра
	*
	* Адрес регистра (смещение) для регистров,
	* отображенных в память, либо фактический
	* номер регистра.
	* Смотрите документацию к устройству для 
	* получения дополнительной информации.
	* 
	*/
	U32 offset; 
	/*!
	* 
	* \~english
	* \brief
	* Value passed to (or from) register
	* 
	* \~russian
	* \brief
	* Значение, которое нужно записать (или прочитанное из регистра)
	*
	*/
	U32 value; 

	RshRegister(U32 Offset = 0, U8 ByteSize = 1, U32 Value = 0);
	RshRegister(const RshRegister& obj);
	RshRegister& operator=(const RshRegister& obj);
	RshRegister& operator=(const U32 Value);
	bool operator==(const RshRegister& obj) const;
	bool operator!=(const RshRegister& obj) const;
	bool operator<(const RshRegister& obj) const;
	
	operator U32() const;

	friend std::ostream& operator<< (std::ostream &out,  const RshRegister& obj);

};
 
#pragma pack(pop)
 
#endif //RSH_REGISTER_H