/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        sdk/core/CDiscordRPC.h
 *  PURPOSE:     Discord RPC interface class
 *
 *  Multi Theft Auto is available from https://www.multitheftauto.com/
 *
 *****************************************************************************/
#pragma once

#include <string>

class CDiscordRPCInterface
{
public:
    virtual void Enable() = 0;
    virtual void Disable() = 0;
    virtual void UpdatePresence() = 0;
    virtual void SetServerPresence(const std::string& strServerName, size_t uiPlayerCount, size_t uiMaxPlayerCount) = 0;
    virtual void SetPresenceServerName(const std::string& strServerName) = 0;
    virtual void SetPresencePlayerCount(size_t uiPlayerCount) = 0;
    virtual void SetPresenceMaxPlayerCount(size_t uiMaxPlayerCount) = 0;
    virtual void SetMainMenuPresence() = 0;
};
