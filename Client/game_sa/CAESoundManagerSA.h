/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/CAESoundManagerSA.h
*  PURPOSE:     Header file for audio engine sound manager class
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/
#pragma once

#include <game/CAESoundManager.h>

#define CLASS_CAESoundManager                           0xB62CB0

#define SOUNDMANAGER_CAESOUND_POOL_SIZE     74

#pragma pack(push, 1)
class CAESoundManagerSAInterface
{
    uint16_t    m_usUnknown1;                               // + 0x0
    uint16_t    m_usUnknown2;                               // + 0x2
    CAESound    m_Pool[SOUNDMANAGER_CAESOUND_POOL_SIZE];    // + 0x4

    BYTE        m_Padding2[0x4C0];  // + 0x87F0
    BYTE        m_bUnknown;         // + 0x8CB4
    BYTE        m_bPaused;          // + 0x8CB5
    BYTE        m_Padding3[0x5];
};
#pragma pack(pop)
static_assert(sizeof(CAESoundManagerSAInterface) == 0x8CBB, "Invalid size for CAESoundManagerSAInterface");

class CAESoundManagerSA : public CAESoundManager
{
public:
    CAESoundManagerSA ( CAESoundManagerSAInterface * pInterface );

public:
    virtual void Initialise                                             ( ) override;
    virtual void Terminate                                              ( ) override;
    virtual void Reset                                                  ( ) override;
    virtual void Service                                                ( ) override;
    virtual void PauseManually                                          ( bool bPaused ) override;
    virtual void RequestNewSound                                        ( CAESound * pAESound ) override;
    virtual int  AreSoundsPlayingInBankSlot                             ( uint16_t usBank ) override;
    virtual int  AreSoundsOfThisEventPlayingForThisEntity               ( uint16_t usEvent, CAEAudioEntity * pAudioEntity ) override;
    virtual int  AreSoundsOfThisEventPlayingForThisEntityAndPhysical    ( uint16_t usEvent, CAEAudioEntity * pAudioEntity, CEntitySAInterface * pGameEntity ) override;
    virtual void CancelSoundsOfThisEventPlayingForThisEntity            ( uint16_t usEvent, CAEAudioEntity * pAudioEntity ) override;
    virtual void CancelSoundsOfThisEventPlayingForThisEntityAndPhysical ( uint16_t usEvent, CAEAudioEntity * pAudioEntity, CEntitySAInterface * pGameEntity ) override;
    virtual void CancelSoundsInBankSlot                                 ( uint16_t usBank, uint8_t bUnknown ) override;
    virtual void CancelSoundsOwnedByAudioEntity                         ( CEntitySAInterface * pGameEntity, uint8_t bUnknown ) override;

private:
    CAESoundManagerSAInterface * m_pInterface;
};
