/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        core/CDiscordRPC.cpp
 *  PURPOSE:     Source file for Discord RPC class
 *
 *  Multi Theft Auto is available from https://www.multitheftauto.com/
 *
 *****************************************************************************/
#include "StdInc.h"
#include "CDiscordRPC.h"

constexpr const char* DISCORD_APPLICATION_ID = "389006734896922624";

DiscordEventHandlers CDiscordRPC::ms_EventHandlers = {0};

CDiscordRPC::CDiscordRPC()
    : m_bInitialized{false},
      m_bEnabled{false},
      m_DiscordState{EDiscordState::OFFLINE},
      m_PresenceState{EPresenceState::NONE},
      m_strServerName{""},
      m_uiPlayerCount{0},
      m_uiMaxPlayerCount{0},
      m_ServerPresenceStartTime{0}
      // m_bQueryingServerInfo{false}
{
}

CDiscordRPC::~CDiscordRPC()
{
    Shutdown();
}

CDiscordRPC& CDiscordRPC::GetSingleton()
{
    static CDiscordRPC instance;
    return instance;
}

void CDiscordRPC::DoPulse() const
{
    if (!m_bInitialized || !m_bEnabled)
        return;

    /*if (m_bQueryingServerInfo)
    {
        if (m_PresenceState != EPresenceState::ON_SERVER)
        {
            m_bQueryingServerInfo = false;
        }
        else
        {
            m_ServerListItem.Pulse(true);

            if (m_ServerListItem.bScanned)
            {
                m_bQueryingServerInfo = false;
                m_strServerName = m_ServerListItem.strName;
                m_uiMaxPlayerCount = m_ServerListItem.nMaxPlayers;
                UpdatePresence();
            }
            else if (m_ServerListItem.bSkipped)
            {
                m_bQueryingServerInfo = false;
            }
        }
    }*/

    Discord_UpdateConnection();
    Discord_RunCallbacks();
}

void CDiscordRPC::Shutdown()
{
    if (!m_bInitialized)
        return;

    Discord_Shutdown();
    m_bInitialized = false;
}

void CDiscordRPC::SetDiscordState(EDiscordState eState)
{
    m_DiscordState = eState;
}

void CDiscordRPC::UpdatePresence()
{
    if (!m_bInitialized || !m_bEnabled || m_DiscordState == EDiscordState::OFFLINE || m_PresenceState == EPresenceState::NONE)
        return;

    DiscordRichPresence presence = {0};
    presence.largeImageKey = "default";

    switch (m_PresenceState)
    {
        case EPresenceState::MAIN_MENU:
            presence.state = "In Main Menu";
            break;
        case EPresenceState::ON_SERVER:
            presence.details = m_strServerName.c_str();
            presence.startTimestamp = m_ServerPresenceStartTime;
            presence.partySize = m_uiPlayerCount;
            presence.partyMax = m_uiMaxPlayerCount;
            presence.state = "In Game";
            // TODO(Necktrox): Handle join request: presence.joinSecret = g_pCore->GetNetwork()->GetConnectedServer(true);
            break;
        default:
            break;
    }

    Discord_UpdatePresence(&presence);
}

void CDiscordRPC::Enable()
{
    if (m_bEnabled)
        return;

    m_bEnabled = true;

    if (!m_bInitialized)
    {
        Discord_Initialize(DISCORD_APPLICATION_ID, &ms_EventHandlers, 1, nullptr);
        m_bInitialized = true;
    }

    UpdatePresence();
}

void CDiscordRPC::Disable()
{
    if (!m_bEnabled)
        return;

    m_bEnabled = false;
    Discord_ClearPresence();
}

void CDiscordRPC::SetServerPresence(const std::string& strServerName, size_t uiPlayerCount, size_t uiMaxPlayerCount)
{
    // m_bQueryingServerInfo = false;

    /*{
        // Try to read server information from server browser cache
        CConnectManager* pConnectManager = g_pCore->GetConnectManager();
        
        const std::string strHost = pConnectManager->m_strLastHost;
        const unsigned short usPort = pConnectManager->m_usLastPort;

        CServerListItem* pServerListItem = g_pCore->GetLocalGUI()->GetMainMenu()->GetServerBrowser()->FindServer(strHost, usPort);

        if (pServerListItem)
        {
            m_strServerName = pServerListItem->strName;
            m_uiMaxPlayerCount = pServerListItem->nMaxPlayers;
        }
        else
        {
            // Query the server for information
            m_strServerName = "Playing on a server";
            m_uiMaxPlayerCount = 0;

            // in_addr Address{};
            // CServerListItem::Parse(strHost.c_str(), Address);

            // m_ServerListItem.Init();
            // m_ServerListItem.ChangeAddress(Address, usPort);
            // m_ServerListItem.Query();

            // m_bQueryingServerInfo = true;
        }
    }*/

    m_strServerName = strServerName;
    m_uiPlayerCount = uiPlayerCount;
    m_uiMaxPlayerCount = uiMaxPlayerCount;
    m_ServerPresenceStartTime = time(nullptr);
    m_PresenceState = EPresenceState::ON_SERVER;

    UpdatePresence();
}

void CDiscordRPC::SetPresenceServerName(const std::string& strServerName)
{
    m_strServerName = strServerName;
}

void CDiscordRPC::SetPresencePlayerCount(size_t uiPlayerCount)
{
    m_uiPlayerCount = uiPlayerCount;
}

void CDiscordRPC::SetPresenceMaxPlayerCount(size_t uiMaxPlayerCount)
{
    m_uiMaxPlayerCount = uiMaxPlayerCount;
}

void CDiscordRPC::SetMainMenuPresence()
{
    m_PresenceState = EPresenceState::MAIN_MENU;
    // m_bQueryingServerInfo = false;

    UpdatePresence();
}

void CDiscordRPC::Initialize()
{
    ms_EventHandlers.ready = onReady;
    ms_EventHandlers.disconnected = onDisconnect;
#ifdef MTA_DEBUG
    ms_EventHandlers.errored = onError;
    ms_EventHandlers.joinGame = onJoinGameRequest;
    ms_EventHandlers.spectateGame = onSpectateGameRequest;
    ms_EventHandlers.joinRequest = onJoinRequest;
#endif
}

void CDiscordRPC::onReady()
{
    auto& DiscordRPC = GetSingleton();
    DiscordRPC.SetDiscordState(EDiscordState::READY);
    DiscordRPC.UpdatePresence();
}

void CDiscordRPC::onDisconnect(int errorCode, const char* message)
{
    auto& DiscordRPC = GetSingleton();
    DiscordRPC.SetDiscordState(EDiscordState::OFFLINE);
}

void CDiscordRPC::onError(int errorCode, const char* message)
{
    OutputDebugLine(SString{"[Discord] Error [%d]: %s", errorCode, message});
}

void CDiscordRPC::onJoinGameRequest(const char* joinSecret)
{
    OutputDebugLine(SString{"[Discord] onJoinGameRequest: %s", joinSecret});
}

void CDiscordRPC::onSpectateGameRequest(const char* spectateSecret)
{
    OutputDebugLine(SString{"[Discord] onSpectateGameRequest: %s", spectateSecret});
}

void CDiscordRPC::onJoinRequest(const DiscordJoinRequest* request)
{
    OutputDebugLine(SString{"[Discord] onJoinRequest: %s#%s [id]", request->username, request->discriminator, request->userId});
}
