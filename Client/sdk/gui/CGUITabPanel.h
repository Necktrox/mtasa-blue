/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        sdk/gui/CGUITabPanel.h
 *  PURPOSE:     Tab panel widget interface
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#ifndef __CGUITABPANEL_H
#define __CGUITABPANEL_H

#include "CGUIElement.h"
#include "CGUITab.h"

class CGUITabPanel : public CGUIElement
{
public:
    virtual ~CGUITabPanel(void){};

    virtual CGUITab* CreateTab(const char* szCaption) = 0;
    virtual void     DeleteTab(CGUITab* pTab) = 0;

    virtual CGUITab* GetSelectedTab(void) = 0;
    virtual void     SetSelectedTab(CGUITab* pTab) = 0;

    virtual void         SetSelectedIndex(unsigned int uiIndex) = 0;
    virtual unsigned int GetSelectedIndex(void) = 0;

    virtual unsigned int GetTabCount(void) = 0;

    virtual void SetSelectionHandler(GUI_CALLBACK Callback) = 0;

    virtual bool IsTabSelected(CGUITab* pTab) = 0;
};

#endif
