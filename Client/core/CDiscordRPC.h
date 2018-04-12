/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        core/CDiscordRPC.h
 *  PURPOSE:     Header file for Discord RPC class
 *
 *  Multi Theft Auto is available from https://www.multitheftauto.com/
 *
 *****************************************************************************/
#pragma once

#include <ctime>
#include <discord_rpc.h>
#include <core/CDiscordRPCInterface.h>
// #include "Serverbrowser/CServerList.h"

class CDiscordRPC : public CDiscordRPCInterface
{
    enum class EPresenceState
    {
        NONE,
        MAIN_MENU,
        ON_SERVER,
    };

    enum class EDiscordState
    {
        OFFLINE,
        READY,
    };

public:
    ~CDiscordRPC();

    CDiscordRPC(const CDiscordRPC&) = delete;
    CDiscordRPC& operator=(const CDiscordRPC&) = delete;
    CDiscordRPC(const CDiscordRPC&&) = delete;
    CDiscordRPC& operator=(const CDiscordRPC&&) = delete;

    static CDiscordRPC& GetSingleton();

    void DoPulse() const;

private:
    CDiscordRPC();
    void Shutdown();
    void SetDiscordState(EDiscordState eState);

public:
    // Interface
    void Enable() override;
    void Disable() override;
    void UpdatePresence() override;
    void SetServerPresence(const std::string& strServerName, size_t uiPlayerCount, size_t uiMaxPlayerCount) override;
    void SetPresenceServerName(const std::string& strServerName) override;
    void SetPresencePlayerCount(size_t uiPlayerCount) override;
    void SetPresenceMaxPlayerCount(size_t uiMaxPlayerCount) override;
    void SetMainMenuPresence() override;

    static void Initialize();

private:
    // Static internal event handlers
    static void onReady();
    static void onDisconnect(int errorCode, const char* message);
    static void onError(int errorCode, const char* message);
    static void onJoinGameRequest(const char* joinSecret);
    static void onSpectateGameRequest(const char* spectateSecret);
    static void onJoinRequest(const DiscordJoinRequest* request);

    static DiscordEventHandlers ms_EventHandlers;

private:
    bool            m_bInitialized;
    bool            m_bEnabled;
    EDiscordState   m_DiscordState;
    EPresenceState  m_PresenceState;
    std::string     m_strServerName;
    size_t          m_uiPlayerCount;
    size_t          m_uiMaxPlayerCount;
    time_t          m_ServerPresenceStartTime;
    // CServerListItem m_ServerListItem;
    // bool            m_bQueryingServerInfo;
};
