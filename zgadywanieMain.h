/***************************************************************
 * Name:      zgadywanieMain.h
 * Purpose:   Defines Application Frame
 * Author:    Zuzanna ()
 * Created:   2022-11-09
 * Copyright: Zuzanna ()
 * License:
 **************************************************************/
#include "gra.h"
#ifndef ZGADYWANIEMAIN_H
#define ZGADYWANIEMAIN_H

//(*Headers(zgadywanieDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)

class zgadywanieDialog: public wxDialog
{
    public:

        zgadywanieDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~zgadywanieDialog();

    private:

        //(*Handlers(zgadywanieDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        //*)

        //(*Identifiers(zgadywanieDialog)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT2;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(zgadywanieDialog)
        wxBoxSizer* BoxSizer1;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxTextCtrl* TextCtrl1;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()

        gra moja_gra;
        int irT=0;
};

#endif // ZGADYWANIEMAIN_H
