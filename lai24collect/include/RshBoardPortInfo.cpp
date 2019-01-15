/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshBoardPortInfo.cpp
 * \date 25.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshBoardPortInfo class.
 *
 * \~russian
 * \brief
 * Класс RshBoardPortInfo.
 *
 */
 
#include "RshBoardPortInfo.h"

//RshBoardPortInfo
RshBoardPortInfo::RshBoardPortInfo(size_t maxPortNumber, size_t maxConfNumber):
 RshBaseType(rshBoardPortInfo, sizeof(RshBoardPortInfo)),
 ports(maxPortNumber),
 confs(maxConfNumber)
{ }
