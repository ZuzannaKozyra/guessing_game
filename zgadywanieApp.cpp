/***************************************************************
 * Name:      zgadywanieApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Zuzanna ()
 * Created:   2022-11-09
 * Copyright: Zuzanna ()
 * License:
 **************************************************************/

#include "zgadywanieApp.h"

//(*AppHeaders
#include "zgadywanieMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(zgadywanieApp);

bool zgadywanieApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	zgadywanieDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
