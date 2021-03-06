/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        game_sa/C3DMarkerSA.cpp
 *  PURPOSE:     3D Marker entity
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#include "StdInc.h"

void C3DMarkerSA::GetMatrix(CMatrix* pMatrix)
{
    CMatrix_Padded* mat = &GetInterface()->m_mat;
    MemCpyFast(&pMatrix->vPos, &mat->vPos, sizeof(CVector));
    MemCpyFast(&pMatrix->vFront, &mat->vFront, sizeof(CVector));
    MemCpyFast(&pMatrix->vRight, &mat->vRight, sizeof(CVector));
    MemCpyFast(&pMatrix->vUp, &mat->vUp, sizeof(CVector));
}

void C3DMarkerSA::SetMatrix(CMatrix* pMatrix)
{
    CMatrix_Padded* mat = &GetInterface()->m_mat;
    MemCpyFast(&mat->vPos, &pMatrix->vPos, sizeof(CVector));
    MemCpyFast(&mat->vFront, &pMatrix->vFront, sizeof(CVector));
    MemCpyFast(&mat->vRight, &pMatrix->vRight, sizeof(CVector));
    MemCpyFast(&mat->vUp, &pMatrix->vUp, sizeof(CVector));
}

VOID C3DMarkerSA::SetPosition(CVector* vecPosition)
{
    DEBUG_TRACE("VOID C3DMarkerSA::SetPosition(CVector * vecPosition)");
    this->GetInterface()->m_mat.vPos = *vecPosition;
}

CVector* C3DMarkerSA::GetPosition()
{
    DEBUG_TRACE("CVector * C3DMarkerSA::GetPosition()");
    return &this->GetInterface()->m_mat.vPos;
}

DWORD C3DMarkerSA::GetType()
{
    DEBUG_TRACE("DWORD C3DMarkerSA::GetType()");
    return this->GetInterface()->m_nType;
}

VOID C3DMarkerSA::SetType(DWORD dwType)
{
    DEBUG_TRACE("VOID C3DMarkerSA::SetType(DWORD dwType)");
    this->GetInterface()->m_nType = (unsigned short)(dwType);
}

BOOL C3DMarkerSA::IsActive()
{
    DEBUG_TRACE("BOOL C3DMarkerSA::IsActive()");
    return (BOOL)this->GetInterface()->m_bIsUsed;
}

DWORD C3DMarkerSA::GetIdentifier()
{
    DEBUG_TRACE("DWORD C3DMarkerSA::GetIdentifier()");
    return this->GetInterface()->m_nIdentifier;
}

SColor C3DMarkerSA::GetColor()
{
    DEBUG_TRACE("RGBA C3DMarkerSA::GetColor()");
    // From ABGR
    unsigned long ulABGR = this->GetInterface()->rwColour;
    SColor        color;
    color.A = (ulABGR >> 24) & 0xff;
    color.B = (ulABGR >> 16) & 0xff;
    color.G = (ulABGR >> 8) & 0xff;
    color.R = ulABGR & 0xff;
    return color;
}

VOID C3DMarkerSA::SetColor(const SColor color)
{
    // To ABGR
    this->GetInterface()->rwColour = (color.A << 24) | (color.B << 16) | (color.G << 8) | color.R;
}

VOID C3DMarkerSA::SetPulsePeriod(WORD wPulsePeriod)
{
    DEBUG_TRACE("VOID C3DMarkerSA::SetPulsePeriod(WORD wPulsePeriod)");
    this->GetInterface()->m_nPulsePeriod = wPulsePeriod;
}

VOID C3DMarkerSA::SetRotateRate(short RotateRate)
{
    DEBUG_TRACE("VOID C3DMarkerSA::SetRotateRate(short RotateRate)");
    this->GetInterface()->m_nRotateRate = RotateRate;
}

FLOAT C3DMarkerSA::GetSize()
{
    DEBUG_TRACE("FLOAT C3DMarkerSA::GetSize()");
    return this->GetInterface()->m_fSize;
}

VOID C3DMarkerSA::SetSize(FLOAT fSize)
{
    DEBUG_TRACE("VOID C3DMarkerSA::SetSize(FLOAT fSize)");
    this->GetInterface()->m_fSize = fSize;
}

FLOAT C3DMarkerSA::GetBrightness()
{
    DEBUG_TRACE("FLOAT C3DMarkerSA::GetBrightness()");
    return this->GetInterface()->m_fBrightness;
}

VOID C3DMarkerSA::SetBrightness(FLOAT fBrightness)
{
    DEBUG_TRACE("VOID C3DMarkerSA::SetBrightness(FLOAT fBrightness)");
    this->GetInterface()->m_fBrightness = fBrightness;
}

VOID C3DMarkerSA::SetCameraRange(FLOAT fCameraRange)
{
    DEBUG_TRACE("VOID C3DMarkerSA::SetCameraRange(FLOAT fCameraRange)");
    this->GetInterface()->m_fCameraRange = fCameraRange;
}

VOID C3DMarkerSA::SetPulseFraction(FLOAT fPulseFraction)
{
    DEBUG_TRACE("VOID C3DMarkerSA::SetPulseFraction(FLOAT fPulseFraction)");
    this->GetInterface()->m_fPulseFraction = fPulseFraction;
}

FLOAT C3DMarkerSA::GetPulseFraction()
{
    DEBUG_TRACE("FLOAT C3DMarkerSA::GetPulseFraction()");
    return this->GetInterface()->m_fPulseFraction;
}

VOID C3DMarkerSA::Disable()
{
    DEBUG_TRACE("VOID C3DMarkerSA::Disable ()");
    this->GetInterface()->m_nIdentifier = 0;
}

VOID C3DMarkerSA::DeleteMarkerObject()
{
    if (this->GetInterface()->m_pRwObject)
    {
        DWORD dwFunc = FUNC_DeleteMarkerObject;
        DWORD dwThis = (DWORD)this->GetInterface();
        _asm
        {
            mov     ecx, dwThis
            call    dwFunc
        }

        // OutputDebugString ( "Object destroyed!" );
    }
    else
    {
        // OutputDebugString ( "No object to destroy!" );
    }
}

VOID C3DMarkerSA::Reset()
{
    this->internalInterface->m_lastPosition = this->internalInterface->m_mat.vPos;
}
