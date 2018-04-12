/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/deathmatch/logic/rpc/CServerRPCs.cpp
*  PURPOSE:     Server remote procedure calls
*
*  Multi Theft Auto is available from https://www.multitheftauto.com/
*
*****************************************************************************/
#include <StdInc.h>
#include "CServerRPCs.h"

void CServerRPCs::LoadFunctions()
{
    AddHandler(SET_MAX_PLAYER_COUNT, SetMaxPlayerCount, "SetMaxPlayerCount");
}

void CServerRPCs::SetMaxPlayerCount(NetBitStreamInterface& bitStream)
{
    unsigned int uiMaxPlayerCount;

    if ( bitStream.Read(uiMaxPlayerCount))
    {
        m_pClientGame->SetMaxPlayerCount(uiMaxPlayerCount);
        m_pClientGame->UpdateDiscordRichPresence();
    }
}
