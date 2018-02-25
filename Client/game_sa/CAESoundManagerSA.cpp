/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/CAESoundManagerSA.cpp
*  PURPOSE:     Audio engine sound manager
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/
#include "StdInc.h"

#define FUNC_CAESoundManager__Initialise                                                0x4EFD30
#define FUNC_CAESoundManager__Terminate                                                 0x4EFAA0
#define FUNC_CAESoundManager__Reset                                                     0x4EF4D0
#define FUNC_CAESoundManager__Service                                                   0x4F0000
#define FUNC_CAESoundManager__PauseManually                                             0x4EF510
#define FUNC_CAESoundManager__RequestNewSound                                           0x4EFB10
#define FUNC_CAESoundManager__AreSoundsPlayingInBankSlot                                0x4EF520
#define FUNC_CAESoundManager__AreSoundsOfThisEventPlayingForThisEntity                  0x4EF570
#define FUNC_CAESoundManager__AreSoundsOfThisEventPlayingForThisEntityAndPhysical       0x4EF5D0
#define FUNC_CAESoundManager__CancelSoundsOfThisEventPlayingForThisEntity               0x4EFB90
#define FUNC_CAESoundManager__CancelSoundsOfThisEventPlayingForThisEntityAndPhysical    0x4EFBF0
#define FUNC_CAESoundManager__CancelSoundsInBankSlot                                    0x4EFC60
#define FUNC_CAESoundManager__CancelSoundsOwnedByAudioEntity                            0x4EFCD0

CAESoundManagerSA* g_pAESoundManagerSA = nullptr;

template < typename ReturnType, uintptr_t address, typename Class, typename... Arguments >
static inline ReturnType CallMethod ( Class * self, Arguments... arguments )
{
    return reinterpret_cast < ReturnType ( __thiscall * ) ( Class *, Arguments... ) > ( address ) ( self, arguments... );
}

CAESoundManagerSA::CAESoundManagerSA ( CAESoundManagerSAInterface * pInterface )
    : m_pInterface { pInterface }
{
    g_pAESoundManagerSA = this;
}

void CAESoundManagerSA::Initialise ( )
{
    return CallMethod < void, FUNC_CAESoundManager__Initialise, CAESoundManagerSAInterface > ( m_pInterface );
}

void CAESoundManagerSA::Terminate ( )
{
    return CallMethod < void, FUNC_CAESoundManager__Terminate, CAESoundManagerSAInterface > ( m_pInterface );
}

void CAESoundManagerSA::Reset ( )
{
    return CallMethod < void, FUNC_CAESoundManager__Reset, CAESoundManagerSAInterface > ( m_pInterface );
}

void CAESoundManagerSA::Service ( )
{
    return CallMethod < void, FUNC_CAESoundManager__Service, CAESoundManagerSAInterface > ( m_pInterface );
}

void CAESoundManagerSA::PauseManually ( bool bPaused )
{
    return CallMethod < void, FUNC_CAESoundManager__PauseManually, CAESoundManagerSAInterface, char > ( m_pInterface, bPaused ? 1 : 0 );
}

void CAESoundManagerSA::RequestNewSound ( CAESound * pAESound )
{
    if ( !pAESound )
        return;

    return CallMethod < void, FUNC_CAESoundManager__RequestNewSound, CAESoundManagerSAInterface, CAESound * > ( m_pInterface, pAESound );
}

int CAESoundManagerSA::AreSoundsPlayingInBankSlot ( uint16_t usBank )
{
    return CallMethod < int, FUNC_CAESoundManager__AreSoundsPlayingInBankSlot, CAESoundManagerSAInterface, uint16_t > ( m_pInterface, usBank );
}

int CAESoundManagerSA::AreSoundsOfThisEventPlayingForThisEntity ( uint16_t usEvent, CAEAudioEntity * pAudioEntity )
{
    if ( !pAudioEntity )
        return 0;

    return CallMethod < int, FUNC_CAESoundManager__AreSoundsOfThisEventPlayingForThisEntity, CAESoundManagerSAInterface, CAEAudioEntity * > ( m_pInterface, pAudioEntity );
}

int CAESoundManagerSA::AreSoundsOfThisEventPlayingForThisEntityAndPhysical ( uint16_t usEvent, CAEAudioEntity * pAudioEntity, CEntitySAInterface * pGameEntity )
{
    if ( !pAudioEntity || !pGameEntity )
        return 0;

    return CallMethod < int, FUNC_CAESoundManager__AreSoundsOfThisEventPlayingForThisEntityAndPhysical, CAESoundManagerSAInterface, uint16_t, CAEAudioEntity *, CEntitySAInterface * > ( m_pInterface, usEvent, pAudioEntity, pGameEntity );
}

void CAESoundManagerSA::CancelSoundsOfThisEventPlayingForThisEntity ( uint16_t usEvent, CAEAudioEntity * pAudioEntity )
{
    if ( !pAudioEntity )
        return;

    return CallMethod < void, FUNC_CAESoundManager__CancelSoundsOfThisEventPlayingForThisEntity, CAESoundManagerSAInterface, uint16_t, CAEAudioEntity * > ( m_pInterface, usEvent, pAudioEntity );
}

void CAESoundManagerSA::CancelSoundsOfThisEventPlayingForThisEntityAndPhysical ( uint16_t usEvent, CAEAudioEntity * pAudioEntity, CEntitySAInterface * pGameEntity )
{
    if ( !pAudioEntity || !pGameEntity )
        return;

    return CallMethod < void, FUNC_CAESoundManager__CancelSoundsOfThisEventPlayingForThisEntityAndPhysical, CAESoundManagerSAInterface, uint16_t, CAEAudioEntity *, CEntitySAInterface * > ( m_pInterface, usEvent, pAudioEntity, pGameEntity );
}

void CAESoundManagerSA::CancelSoundsInBankSlot ( uint16_t usBank, uint8_t bUnknown )
{
    return CallMethod < void, FUNC_CAESoundManager__CancelSoundsInBankSlot, CAESoundManagerSAInterface, uint16_t, uint8_t > ( m_pInterface, usBank, bUnknown ? 1 : 0 );
}

void CAESoundManagerSA::CancelSoundsOwnedByAudioEntity ( CEntitySAInterface * pGameEntity, uint8_t bUnknown )
{
    if ( !pGameEntity )
        return;

    return CallMethod < void, FUNC_CAESoundManager__CancelSoundsOwnedByAudioEntity, CAESoundManagerSAInterface, CEntitySAInterface *, uint8_t > ( m_pInterface, pGameEntity, bUnknown ? 1 : 0 );
}
