/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/Common.h
*  PURPOSE:     Common game layer include file
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/
#pragma once

#include <game/Common.h>
#include <type_traits>

#undef DEBUG_LOG
#ifdef DEBUG_LOG
    #include <stdio.h>
    #include <time.h>

    static FILE* fDebugFile;

    static void OutputDebugText ( char * szDebugText )
    {
        #ifdef MTA_DEBUG
        char szDebug[500];
        sprintf ( szDebug, "%s\n", szDebugText );
        OutputDebugString ( szDebug );
        #endif
    }

    #ifdef MTA_DEBUG
        #define DEBUG_TRACE(szText) \
            OutputDebugString(szText);
    #endif
#else
    #define DEBUG_TRACE(szText) // we do nothing with release versions
#endif

namespace gamesa
{
    namespace detail
    {
        template < typename T, size_t N >
        constexpr size_t member_size ( T ( *& ) [ N ] )
        {
            return N;
        }
    }

    template < typename ValueType, uintptr_t address >
    ValueType GetVariable ( )
    {
        return * reinterpret_cast < ValueType * > ( address );
    }

    template < typename ReturnType, uintptr_t address, typename... Arguments >
    ReturnType Call ( Arguments... arguments )
    {
        return reinterpret_cast < ReturnType ( __cdecl * ) ( Arguments... ) > ( address ) ( arguments... );
    }

    template < typename ReturnType, uintptr_t address, typename Class, typename... Arguments >
    ReturnType CallMethod ( Class * self, Arguments... arguments )
    {
        return reinterpret_cast < ReturnType ( __thiscall * ) ( Class *, Arguments... ) > ( address ) ( self, arguments... );
    }
}

#define GAMESA_INIT_ARRAY_PTR(classMember,address)                      \
    typename std::remove_extent <                                       \
                std::remove_pointer < decltype ( classMember ) >::type  \
                                >::type                                 \
    ( * classMember ) [ gamesa::detail::member_size ( classMember ) ] = reinterpret_cast < decltype ( classMember ) > ( address )
