/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/packets/CPlayerPuresyncPacket.h
 *  PURPOSE:     Player pure synchronization packet class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#ifndef __CPLAYERPURESYNCPACKET_H
#define __CPLAYERPURESYNCPACKET_H

#include "CPacket.h"
#include "CPlayer.h"

class CPlayerPuresyncPacket : public CPacket
{
public:
    CPlayerPuresyncPacket(void){};
    explicit CPlayerPuresyncPacket(CPlayer* pPlayer) { m_pSourceElement = pPlayer; };

    bool          HasSimHandler(void) const { return true; }
    ePacketID     GetPacketID(void) const { return PACKET_ID_PLAYER_PURESYNC; };
    unsigned long GetFlags(void) const { return PACKET_MEDIUM_PRIORITY | PACKET_SEQUENCED; };

    bool Read(NetBitStreamInterface& BitStream);
    bool Write(NetBitStreamInterface& BitStream) const;
};

#endif
