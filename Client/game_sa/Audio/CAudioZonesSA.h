/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/Audio/CAudioZonesSA.h
*  PURPOSE:     Header file for audio zones class
*
*  Multi Theft Auto is available from https://www.multitheftauto.com/
*
*****************************************************************************/
#pragma once

#include <cstdint>

struct CAudioZoneBoxSAInterface
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
static_assert(sizeof(CAudioZoneBoxSAInterface) == 0x18, "Invalid size of CAudioZoneBoxSAInterface");

struct CAudioZoneSphereSAInterface
{
    char        m_szName[8];    // + 0x00
    int16_t     m_wBank;        // + 0x08
    int16_t     m_wEnabled;     // + 0x0A
    float       m_fCenterX;     // + 0x0C
    float       m_fCenterY;     // + 0x10
    float       m_fCenterZ;     // + 0x14
    float       m_fRadius;      // + 0x18
};
static_assert(sizeof(CAudioZoneSphereSAInterface) == 0x1C, "Invalid size of CAudioZoneSphereSAInterface");

class CAudioZonesSA
{
public:
    static void Init                ( void );
    static void RegisterAudioBox    ( const char * szZoneName, int16_t wBank, bool bEnabled, float minX, float minY, float minZ, float maxX, float maxY, float maxZ );
    static void RegisterAudioSphere ( const char * szZoneName, int16_t wBank, bool bEnabled, float centerX, float centerY, float centerZ, float radius );
    static void SwitchAudioZone     ( const char * szZoneName, bool bEnabled );
    static void Update              ( bool bForced, float fCamPositionX, float fCamPositionY, float fCamPositionZ );

public:
    static int32_t GetBoxesCount ( void );
    static int32_t GetSpheresCount ( void );
    static int32_t GetActiveBoxesCount ( void );
    static int32_t GetActiveSpheresCount ( void );

public:
    static CAudioZoneBoxSAInterface     ( * m_aBoxes ) [158]; // 152-157 unused
    static CAudioZoneSphereSAInterface  ( * m_aSpheres ) [3];
    static int32_t                      ( * m_aActiveBoxes ) [10];
    static int32_t                      ( * m_aActiveSpheres ) [10];
};
