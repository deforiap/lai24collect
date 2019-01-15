/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshScalarType.h
 * \date 28.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshScalarType template class.
 *
 * \~russian
 * \brief
 * Шаблонный Класс RshScalarType - для простых типов данных.
 *
 */
 
#ifndef RSH_TYPE_H
#define RSH_TYPE_H
 
#include "RshDefChk.h"
#include "RshBaseType.h"

#include <ostream>
 
#pragma pack(push, 8)
 
 /*!
 * 
 * \~english
 * \brief
 * Simple type template class.
 * 
 * This template is used to simlify
 * construction of simple data types (such as int,
 * float and so on) to be derived from RshBaseType.\n
 * Constucted classes (such as ::RSH_DOUBLE or ::RSH_U32)
 * contain one data field of type, specified in template.
 * 
 * \remarks
 * Usually, classes constructed with this template
 * are used as data container to pass data in
 * polymorphic methods such as IRshDevice::Get().
 *
 * \see
 * RshBaseType
 * 
 * \~russian
 * \brief
 * Шаблонный класс для простых типов данных 
 * 
 * Данный шаблон используется для создания 
 * типов данных (как правило, базовых типов вроде int
 * или double) унаследованных от RshBaseType.\n
 * Сконструированные с помощью этого шаблона классы
 * (такие как ::RSH_DOUBLE или ::RSH_U32) имеют
 * одно поле данных нужного (базового) типа, 
 * определенного в шаблоне. Идентификатор типа данных
 * тоже задается через параметр шаблона.
 * 
 * \remarks
 * Как правило, созданные с помощью этого шаблона
 * классы используются как контейнер для данных
 * при передаче параметров в полиморфные методы,
 * такие как IRshDevice::Get().
 * 
 * \see
 * RshBaseType
 * 
 */
template <typename T, RshDataTypes dataCode>
struct RshScalarType : public RshBaseType
{
	T data;

	RshScalarType();	

	RshScalarType(T value);

	RshScalarType(const RshScalarType& obj);

	RshScalarType& operator=(const RshScalarType & obj);

	RshScalarType& operator=(T value);	

	friend std::ostream& operator<< (std::ostream &out, const RshScalarType<T, dataCode>& obj)
	{
		return out << obj.data;
	}
	
	operator T() const { return data;}
};

/*!
 * 
 * \~english
 * \brief
 * Unsigned 8 bit integer.
 * 
 * \~russian
 * \brief
 * Беззнаковое целое 8 бит.
 * 
 */
typedef RshScalarType< U8, rshU8 > RSH_U8;

/*!
 * 
 * \~english
 * \brief
 * Signed 8 bit integer.
 * 
 * \~russian
 * \brief
 * Знаковое целое 8 бит.
 * 
 */
typedef RshScalarType< S8, rshS8 > RSH_S8;

/*!
 * 
 * \~english
 * \brief
 * Unsigned 16 bit integer.
 * 
 * \~russian
 * \brief
 * Беззнаковое целое 16 бит.
 * 
 */
typedef RshScalarType< U16, rshU16 > RSH_U16;

/*!
 * 
 * \~english
 * \brief
 * Signed 16 bit integer.
 * 
 * \~russian
 * \brief
 * Знаковое целое 16 бит.
 * 
 */
typedef RshScalarType< S16, rshS16 > RSH_S16;

/*!
 * 
 * \~english
 * \brief
 * Unsigned 32 bit integer.
 * 
 * \~russian
 * \brief
 * Беззнаковое целое 32 бита.
 * 
 */
typedef RshScalarType< U32, rshU32 > RSH_U32;

/*!
 * 
 * \~english
 * \brief
 * Signed 32 bit integer.
 * 
 * \~russian
 * \brief
 * Знаковое целое 32 бита.
 * 
 */
typedef RshScalarType< S32, rshS32 > RSH_S32;

/*!
 * 
 * \~english
 * \brief
 * Unsigned 64 bit integer.
 * 
 * \~russian
 * \brief
 * Беззнаковое целое 64 бита.
 * 
 */
typedef RshScalarType< U64, rshU64 > RSH_U64;

/*!
 * 
 * \~english
 * \brief
 * Signed 64 bit integer.
 * 
 * \~russian
 * \brief
 * Знаковое целое 64 бита.
 * 
 */
typedef RshScalarType< S64, rshS64 > RSH_S64;

/*!
 * 
 * \~english
 * \brief
 * Floating point number (4 bytes).
 * 
 * \~russian
 * \brief
 * Число с плавающей точкой (4 байта).
 * 
 */
typedef RshScalarType< float, rshFloat >  RSH_FLOAT;

/*!
 * 
 * \~english
 * \brief
 * Floating point number (8 bytes).
 * 
 * \~russian
 * \brief
 * Число с плавающей точкой (8 байт).
 * 
 */
typedef RshScalarType< double, rshDouble >  RSH_DOUBLE;

/*!
 * 
 * \~english
 * \brief
 * Boolean.
 * 
 * \~russian
 * \brief
 * Логический тип.
 * 
 */
typedef RshScalarType< bool,   rshBool >     RSH_BOOL;

/*!
 * 
 * \~english
 * \brief
 * Void pointer.
 * 
 * \~russian
 * \brief
 * Указатель на void.
 * 
 */
typedef RshScalarType< void*   , rshVoidP >    RSH_VOIDP;

/*!
 * 
 * \~english
 * \brief
 * U8 (unsigned 8 bit integer) pointer.
 * 
 * \~russian
 * \brief
 * Указатель на U8 (беззнаковое целое 8 бит).
 * 
 */
typedef RshScalarType< U8*     , rshU8P  >     RSH_U8P;

/*!
 * 
 * \~english
 * \brief
 * S8 (signed 8 bit integer) pointer.
 * 
 * \~russian
 * \brief
 * Указатель на S8 (знаковое целое 8 бит).
 * 
 */
typedef RshScalarType< S8*     , rshS8P  >     RSH_S8P;

/*!
 * 
 * \~english
 * \brief
 * U16 (unsigned 16 bit integer) pointer.
 * 
 * \~russian
 * \brief
 * Указатель на U16 (беззнаковое целое 16 бит).
 * 
 */
typedef RshScalarType< U16*    , rshU16P >     RSH_U16P;

/*!
 * 
 * \~english
 * \brief
 * S16 (signed 16 bit integer) pointer.
 * 
 * \~russian
 * \brief
 * Указатель на S16 (знаковое целое 16 бит).
 * 
 */
typedef RshScalarType< S16*    , rshS16P  >    RSH_S16P;

/*!
 * 
 * \~english
 * \brief
 * U32 (unsigned 32 bit integer) pointer.
 * 
 * \~russian
 * \brief
 * Указатель на U32 (беззнаковое целое 32 бит).
 * 
 */
typedef RshScalarType< U32*    , rshU32P  >    RSH_U32P;

/*!
 * 
 * \~english
 * \brief
 * S32 (signed 32 bit integer) pointer.
 * 
 * \~russian
 * \brief
 * Указатель на S32 (знаковое целое 32 бит).
 * 
 */
typedef RshScalarType< S32*    , rshS32P  >    RSH_S32P;

/*!
 * 
 * \~english
 * \brief
 * U64 (unsigned 64 bit integer) pointer.
 * 
 * \~russian
 * \brief
 * Указатель на U64 (беззнаковое целое 64 бит).
 * 
 */
typedef RshScalarType< U64*    , rshU64P  >    RSH_U64P;

/*!
 * 
 * \~english
 * \brief
 * S64 (signed 64 bit integer) pointer.
 * 
 * \~russian
 * \brief
 * Указатель на S64 (знаковое целое 64 бит).
 * 
 */
typedef RshScalarType< S64*    , rshS64P  >    RSH_S64P;

/*!
 * 
 * \~english
 * \brief
 * float (4 byte floating point) pointer.
 * 
 * \~russian
 * \brief
 * Указатель на float (число с плавающей точкой 4 байта).
 * 
 */
typedef RshScalarType< float*  , rshFloatP  >  RSH_FLOATP;

/*!
 * 
 * \~english
 * \brief
 * double (8 byte floating point) pointer.
 * 
 * \~russian
 * \brief
 * Указатель на double (число с плавающей точкой 8 байт).
 * 
 */
typedef RshScalarType< double* , rshDoubleP >  RSH_DOUBLEP;

/*!
 * 
 * \~english
 * \brief
 * bool pointer.
 * 
 * \~russian
 * \brief
 * Указатель на bool (логический тип).
 * 
 */
typedef RshScalarType< bool*   , rshBoolP >    RSH_BOOLP;

/*!
 * 
 * \~english
 * \brief
 * U8 (unsigned 8 bit integer) pointer to pointer.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на U8(беззнаковое целое 8 бит).
 * 
 */
typedef RshScalarType< U8**     , rshU8PP  >     RSH_U8PP;

/*!
 * 
 * \~english
 * \brief
 * S8 (signed 8 bit integer) pointer to pointer.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на S8(знаковое целое 8 бит).
 * 
 */
typedef RshScalarType< S8**     , rshS8PP  >     RSH_S8PP;

/*!
 * 
 * \~english
 * \brief
 * U16 (unsigned 16 bit integer) pointer to pointer.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на U16(беззнаковое целое 16 бит).
 * 
 */
typedef RshScalarType< U16**    , rshU16PP >     RSH_U16PP;

/*!
 * 
 * \~english
 * \brief
 * S16 (signed 16 bit integer) pointer to pointer.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на S16(знаковое целое 16 бит).
 * 
 */
typedef RshScalarType< S16**    , rshS16PP  >    RSH_S16PP;

/*!
 * 
 * \~english
 * \brief
 * U32 (unsigned 32 bit integer) pointer to pointer.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на U32(беззнаковое целое 32 бит).
 * 
 */
typedef RshScalarType< U32**    , rshU32PP  >    RSH_U32PP;

/*!
 * 
 * \~english
 * \brief
 * S32 (signed 32 bit integer) pointer to pointer.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на S32(знаковое целое 32 бит).
 * 
 */
typedef RshScalarType< S32**    , rshS32PP  >    RSH_S32PP;

/*!
 * 
 * \~english
 * \brief
 * U64 (unsigned 64 bit integer) pointer to pointer.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на U64(беззнаковое целое 64 бит).
 * 
 */
typedef RshScalarType< U64**    , rshU64PP  >    RSH_U64PP;

/*!
 * 
 * \~english
 * \brief
 * S64 (signed 64 bit integer) pointer to pointer.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на S64(знаковое целое 64 бит).
 * 
 */
typedef RshScalarType< S64**    , rshS64PP  >    RSH_S64PP;

/*!
 * 
 * \~english
 * \brief
 * float (4 byte floating point) pointer to pointer.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на float (число с плавающей точкой 4 байта).
 * 
 */
typedef RshScalarType< float**  , rshFloatPP  >  RSH_FLOATPP;

/*!
 * 
 * \~english
 * \brief
 * double (8 byte floating point) pointer to pointer.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на double (число с плавающей точкой 8 байт).
 * 
 */
typedef RshScalarType< double** , rshDoublePP >  RSH_DOUBLEPP;

/*!
 * 
 * \~english
 * \brief
 * Pointer to pointer to bool.
 * 
 * \~russian
 * \brief
 * Указатель на указатель на bool (логический тип).
 * 
 */
typedef RshScalarType< bool**   , rshBoolPP >    RSH_BOOLPP;


#pragma pack(pop)

#endif //RSH_TYPE_H
