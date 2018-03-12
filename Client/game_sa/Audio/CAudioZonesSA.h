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
#include "CAudioBoxSA.h"
#include "CAudioSphereSA.h"

class CAudioZonesSA
{
public:
    static void Init                ( );
    static void RegisterAudioBox    ( const char * szZoneName, int16_t wBank, bool bEnabled, float fMinX, float fMinY, float fMinZ, float fMaxX, float fMaxY, float fMaxZ );
    static void RegisterAudioSphere ( const char * szZoneName, int16_t wBank, bool bEnabled, float fCenterX, float fCenterY, float fCenterZ, float fRadius );
    static void SwitchAudioZone     ( const char * szZoneName, bool bEnabled );
    static void Update              ( bool bForced, float fCamPositionX, float fCamPositionY, float fCamPositionZ );

public:
    static int32_t GetBoxesCount            ( );
    static int32_t GetSpheresCount          ( );
    static int32_t GetActiveBoxesCount      ( );
    static int32_t GetActiveSpheresCount    ( );

public:
    static CAudioBoxSAInterface     ( * m_aBoxes ) [158]; // 152-157 unused
    static CAudioSphereSAInterface  ( * m_aSpheres ) [3];
    static int32_t                  ( * m_aActiveBoxes ) [10];
    static int32_t                  ( * m_aActiveSpheres ) [10];
};
