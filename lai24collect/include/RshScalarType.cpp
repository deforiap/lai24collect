/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshScalarType.cpp
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
#include "RshScalarType.h"

template <typename T, RshDataTypes dataCode>
	RshScalarType<T, dataCode>::RshScalarType():
	RshBaseType(dataCode, sizeof (RshScalarType<T, dataCode>))
	{
		this->data = T();
	}

template <typename T, RshDataTypes dataCode>
	RshScalarType<T, dataCode>::RshScalarType(T value):
	RshBaseType(dataCode, sizeof (RshScalarType<T, dataCode>))
	{
		this->data = value;	
	}

template <typename T, RshDataTypes dataCode>
	RshScalarType<T, dataCode>::RshScalarType(const RshScalarType<T, dataCode>& obj):
	RshBaseType(obj._type, obj._typeSize)	
	{
		this->data = obj.data;
	}

template <typename T, RshDataTypes dataCode>
	RshScalarType<T, dataCode>& RshScalarType<T, dataCode>::operator=(const RshScalarType<T, dataCode> & obj)
	{
		if(this == &obj)
			return *this;
		data = obj.data;
		return *this;
	}

template <typename T, RshDataTypes dataCode>
	RshScalarType<T, dataCode>& RshScalarType<T, dataCode>::operator=(T value)
	{
		data = value;
		return *this;
	}
	
//Template instantiation
template struct RshScalarType< U8    , rshU8  >;
template struct RshScalarType< S8    , rshS8  >;
template struct RshScalarType< U16   , rshU16 >;
template struct RshScalarType< S16   , rshS16  >;
template struct RshScalarType< U32   , rshU32  >;
template struct RshScalarType< S32   , rshS32  >;
template struct RshScalarType< U64   , rshU64  >;
template struct RshScalarType< S64   , rshS64  >;
template struct RshScalarType< float , rshFloat   >;
template struct RshScalarType< double, rshDouble  >;
template struct RshScalarType< bool,   rshBool >;

template struct RshScalarType< void*   , rshVoidP >;
template struct RshScalarType< U8*     , rshU8P  >;
template struct RshScalarType< S8*     , rshS8P  >;
template struct RshScalarType< U16*    , rshU16P >;
template struct RshScalarType< S16*    , rshS16P  >;
template struct RshScalarType< U32*    , rshU32P  >;
template struct RshScalarType< S32*    , rshS32P  >;
template struct RshScalarType< U64*    , rshU64P  >;
template struct RshScalarType< S64*    , rshS64P  >;
template struct RshScalarType< float*  , rshFloatP  >;
template struct RshScalarType< double* , rshDoubleP >;
template struct RshScalarType< bool*   , rshBoolP >;

template struct RshScalarType< U8**     , rshU8PP  >;
template struct RshScalarType< S8**     , rshS8PP  >;
template struct RshScalarType< U16**    , rshU16PP >;
template struct RshScalarType< S16**    , rshS16PP  >;
template struct RshScalarType< U32**    , rshU32PP  >;
template struct RshScalarType< S32**    , rshS32PP  >;
template struct RshScalarType< U64**    , rshU64PP  >;
template struct RshScalarType< S64**    , rshS64PP  >;
template struct RshScalarType< float**  , rshFloatPP  >;
template struct RshScalarType< double** , rshDoublePP >;
template struct RshScalarType< bool**   , rshBoolPP >;	
