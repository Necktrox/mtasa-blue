/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/Audio/CAudioSphereSA.h
*  PURPOSE:     Header file for audio sphere class
*
*  Multi Theft Auto is available from https://www.multitheftauto.com/
*
*****************************************************************************/
#pragma once

#include <cstdint>

struct CAudioSphereSAInterface
{
    char        m_szName[8];    // + 0x00
    int16_t     m_wBank;        // + 0x08
    int16_t     m_wEnabled;     // + 0x0A
    float       m_fCenterX;     // + 0x0C
    float       m_fCenterY;     // + 0x10
    float       m_fCenterZ;     // + 0x14
    float       m_fRadius;      // + 0x18
};
static_assert(sizeof(CAudioSphereSAInterface) == 0x1C, "Invalid size for CAudioSphereSAInterface");
