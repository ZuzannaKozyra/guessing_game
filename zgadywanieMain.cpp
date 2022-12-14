/***************************************************************
 * Name:      zgadywanieMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Zuzanna ()
 * Created:   2022-11-09
 * Copyright: Zuzanna ()
 * License:
 **************************************************************/

#include "zgadywanieMain.h"
#include <wx/msgdlg.h>
#include <gra.h>

#undef _
#define _(s) wxString::FromUTF8(s)

//(*InternalHeaders(zgadywanieDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(zgadywanieDialog)
const long zgadywanieDialog::ID_STATICTEXT1 = wxNewId();
const long zgadywanieDialog::ID_TEXTCTRL2 = wxNewId();
const long zgadywanieDialog::ID_BUTTON1 = wxNewId();
const long zgadywanieDialog::ID_BUTTON2 = wxNewId();
const long zgadywanieDialog::ID_STATICTEXT2 = wxNewId();
const long zgadywanieDialog::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(zgadywanieDialog,wxDialog)
    //(*EventTable(zgadywanieDialog)
    //*)
END_EVENT_TABLE()

zgadywanieDialog::zgadywanieDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(zgadywanieDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;

    Create(parent, wxID_ANY, _("Zgadywanie liczby"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Zgadnij liczbę:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial Black"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(TextCtrl1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableRow(0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Restartuj grę"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(Button1, 1, wxALL|wxEXPAND, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Sprawdź"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer2->Add(Button2, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(100, false);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zgadywanieDialog::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zgadywanieDialog::OnButton2Click);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&zgadywanieDialog::OnTimer1Trigger);
    //*)
}

zgadywanieDialog::~zgadywanieDialog()
{
    //(*Destroy(zgadywanieDialog)
    //*)
}

void zgadywanieDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void zgadywanieDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void zgadywanieDialog::OnButton2Click(wxCommandEvent& event)
{
    long int x;
    TextCtrl1 -> GetValue().ToLong(&x);
    int w=moja_gra.sprawdz(x);
    if (w==1)
        wxMessageBox(_("za duża"));
     if (w==-1)
        wxMessageBox(_("za mała"));
     if (w==0)
        {
            wxString mess = _("udało się! liczba prób: "); mess << moja_gra.liczbaprob();
            wxMessageBox(mess,"Brawo!");
        }

}

void zgadywanieDialog::OnButton1Click(wxCommandEvent& event)
{
    moja_gra.reset();
    irT = 0;
}

void zgadywanieDialog::OnTimer1Trigger(wxTimerEvent& event)
{
    irT++;
    double x = irT*Timer1.GetInterval()/1000.0;
    StaticText2->SetLabel(wxString::Format("%.2f",x ));

}
