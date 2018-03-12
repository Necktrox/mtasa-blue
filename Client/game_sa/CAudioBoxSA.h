/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/Audio/CAudioBoxSA.h
*  PURPOSE:     Header file for audio box class
*
*  Multi Theft Auto is available from https://www.multitheftauto.com/
*
*****************************************************************************/
#pragma once

#include <cstdint>

struct CAudioBoxSAInterface
{
    char        m_szName[8];    // + 0x00
    int16_t     m_wBank;        // + 0x08
    int16_t     m_wEnabled;     // + 0x0A
    int16_t     m_wMinX;        // + 0x0C
    int16_t     m_wMinY;        // + 0x0E
    int16_t     m_wMinZ;        // + 0x10
    int16_t     m_wMaxX;        // + 0x12
    int16_t     m_wMaxY;        // + 0x14
    int16_t     m_wMaxZ;        // + 0x16
};
static_assert(sizeof(CAudioBoxSAInterface) == 0x18, "Invalid size for CAudioBoxSAInterface");
