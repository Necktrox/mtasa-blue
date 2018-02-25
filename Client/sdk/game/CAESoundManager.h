/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        sdk/game/CAESoundManager.h
*  PURPOSE:     Game audio engine manager interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/
#pragma once

class CAESound;
class CAEAudioEntity;
class CEntitySAInterface;

class CAESoundManager
{
public:
    virtual void Initialise                                             ( ) = 0;
    virtual void Terminate                                              ( ) = 0;
    virtual void Reset                                                  ( ) = 0;
    virtual void Service                                                ( ) = 0;
    virtual void PauseManually                                          ( bool bPaused ) = 0;
    virtual void RequestNewSound                                        ( CAESound * pAESound ) = 0;
    virtual int  AreSoundsPlayingInBankSlot                             ( uint16_t usBank ) = 0;
    virtual int  AreSoundsOfThisEventPlayingForThisEntity               ( uint16_t usEvent, CAEAudioEntity * pAudioEntity ) = 0;
    virtual int  AreSoundsOfThisEventPlayingForThisEntityAndPhysical    ( uint16_t usEvent, CAEAudioEntity * pAudioEntity, CEntitySAInterface * pGameEntity ) = 0;
    virtual void CancelSoundsOfThisEventPlayingForThisEntity            ( uint16_t usEvent, CAEAudioEntity * pAudioEntity ) = 0;
    virtual void CancelSoundsOfThisEventPlayingForThisEntityAndPhysical ( uint16_t usEvent, CAEAudioEntity * pAudioEntity, CEntitySAInterface * pGameEntity ) = 0;
    virtual void CancelSoundsInBankSlot                                 ( uint16_t usBank, uint8_t bUnknown ) = 0;
    virtual void CancelSoundsOwnedByAudioEntity                         ( CEntitySAInterface * pGameEntity, uint8_t bUnknown ) = 0;
};
