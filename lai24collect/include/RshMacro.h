/*!
 * \copyright JSC "Rudnev-Shilyaev"
 * 
 * \file RshMacro.h
 * \date 15.01.2016
 * \version 1.0 [SDK 2.1]
 * 
 * \~english
 * \brief
 * Macros and templates used in SDK.
 * 
 * This file contains frequently used code enclosed into macro definitions.
 * 
 * \~russian
 * \brief
 * Макросы и шаблоны, применяемые в SDK.
 * 
 * В этом файле содержатся часто используемые фрагменты кода, оформленные в виде макросов.
 * 
 */

#ifndef RSH_MACRO_H
#define RSH_MACRO_H

#include <ostream>
#include <limits>
#include <math.h>

#define RSH_DIM(a) (sizeof(a) / sizeof(a[0]))

#define RSH_CMPDOUBLE(a,b) (fabs(a - b) <  std::numeric_limits<double>::epsilon())

#define RSH_TOSTRING( x ) dynamic_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()

#define RSH_TOWSTRING( x ) dynamic_cast< std::wstringstream & >( \
            ( std::wstringstream() << std::dec << x ) ).str()

#define RSH_EXIT_ON_ERROR( res ) {if(res != RSH_API_SUCCESS ) return res;}

#define rshUTF16(str) RshConvertToUTF16(str)


#endif  //RSH_MACRO_H
