/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/Audio/CAudioZonesSA.cpp
*  PURPOSE:     Source file for audio zones class
*
*  Multi Theft Auto is available from https://www.multitheftauto.com/
*
*****************************************************************************/
#include "StdInc.h"
#include "CAudioZonesSA.h"

// 0x5081A0 CAudioZones::Init(void)
#define FUNC_CAudioZones__Init 0x5081A0

// 0x5081C0 CAudioZones::RegisterAudioSphere(char *,int,bool,float,float,float,float)
#define FUNC_CAudioZones__RegisterAudioSphere 0x5081C0

// 0x508240 CAudioZones::RegisterAudioBox(char *,int,bool,float,float,float,float,float,float)
#define FUNC_CAudioZones__RegisterAudioBox 0x508240

// 0x508320 CAudioZones::SwitchAudioZone(char *,bool)
#define FUNC_CAudioZones__SwitchAudioZone 0x508320

// 0x5083C0 CAudioZones::Update(bool,CVector)
#define FUNC_CAudioZones__Update 0x5083C0

#define VAR_CAudioZones__m_aBoxes               0xB6DCD0
#define VAR_CAudioZones__m_aSpheres             0xB6EBA8
#define VAR_CAudioZones__m_aActiveBoxes         0xB6DC6C
#define VAR_CAudioZones__m_aActiveSpheres       0xB6DC94
#define VAR_CAudioZones__m_NumActiveBoxes       0xB6DCBC
#define VAR_CAudioZones__m_NumActiveSpheres     0xB6DCC0
#define VAR_CAudioZones__m_NumBoxes             0xB6DCC4
#define VAR_CAudioZones__m_NumSpheres           0xB6DCC8
#define VAR_CAudioZones__m_fLastCameraPosX      0xB6EBFC // | Only used in CAudioZones::Update(...)
#define VAR_CAudioZones__m_fLastCameraPosY      0xB6EC00 // | to determine if an update is required
#define VAR_CAudioZones__m_fLastCameraPosZ      0xB6EC04 // | and that check can be circumvented by forcing the update
#define VAR_CAudioZones__m_bRenderAudioZones    0xB6DC68

GAMESA_INIT_ARRAY_PTR ( CAudioZonesSA::m_aBoxes,           VAR_CAudioZones__m_aBoxes );
GAMESA_INIT_ARRAY_PTR ( CAudioZonesSA::m_aSpheres,         VAR_CAudioZones__m_aSpheres );
GAMESA_INIT_ARRAY_PTR ( CAudioZonesSA::m_aActiveBoxes,     VAR_CAudioZones__m_aActiveBoxes );
GAMESA_INIT_ARRAY_PTR ( CAudioZonesSA::m_aActiveSpheres,   VAR_CAudioZones__m_aActiveSpheres );

void CAudioZonesSA::Init ( )
{
    return gamesa::Call < void, FUNC_CAudioZones__Init > ();
}

void CAudioZonesSA::RegisterAudioBox ( const char * szZoneName, int16_t wBank, bool bEnabled, float fMinX, float fMinY, float fMinZ, float fMaxX, float fMaxY, float fMaxZ )
{
    return gamesa::Call < void, FUNC_CAudioZones__RegisterAudioBox, const char *, int16_t, int16_t, float, float, float, float, float, float > ( szZoneName, wBank, bEnabled, fMinX, fMinY, fMinZ, fMaxX, fMaxY, fMaxZ );
}

void CAudioZonesSA::RegisterAudioSphere ( const char * szZoneName, int16_t wBank, bool bEnabled, float fCenterX, float fCenterY, float fCenterZ, float fRadius )
{
    return gamesa::Call < void, FUNC_CAudioZones__RegisterAudioSphere, const char *, int16_t, int16_t, float, float, float, float > ( szZoneName, wBank, bEnabled, fCenterX, fCenterY, fCenterZ, fRadius );
}

void CAudioZonesSA::SwitchAudioZone ( const char * szZoneName, bool bEnabled )
{
    return gamesa::Call < void, FUNC_CAudioZones__SwitchAudioZone, const char *, bool > ( szZoneName, bEnabled );
}

void CAudioZonesSA::Update ( bool bForced, float fCamPositionX, float fCamPositionY, float fCamPositionZ )
{
    return gamesa::Call < void, FUNC_CAudioZones__Update, bool, float, float, float > ( bForced, fCamPositionX, fCamPositionY, fCamPositionZ );
}

int32_t CAudioZonesSA::GetBoxesCount ( )
{
    return gamesa::GetVariable < int32_t, VAR_CAudioZones__m_NumBoxes > ( );
}

int32_t CAudioZonesSA::GetSpheresCount ( )
{
    return gamesa::GetVariable < int32_t, VAR_CAudioZones__m_NumSpheres > ( );
}

int32_t CAudioZonesSA::GetActiveBoxesCount ( )
{
    return gamesa::GetVariable < int32_t, VAR_CAudioZones__m_NumActiveBoxes > ( );
}

int32_t CAudioZonesSA::GetActiveSpheresCount ( )
{
    return gamesa::GetVariable < int32_t, VAR_CAudioZones__m_NumActiveSpheres > ( );
}
