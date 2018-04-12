/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/deathmatch/logic/rpc/CServerRPCs.h
*  PURPOSE:     Header for server RPC calls
*
*  Multi Theft Auto is available from https://www.multitheftauto.com/
*
*****************************************************************************/
#pragma once

#include "CRPCFunctions.h"

class CServerRPCs : public CRPCFunctions
{
public:
    static void LoadFunctions();

    DECLARE_RPC(SetMaxPlayerCount);
};
