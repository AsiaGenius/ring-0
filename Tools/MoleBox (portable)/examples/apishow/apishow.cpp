
#include <wx/wx.h>
#include <wx/aboutdlg.h>
#include <wx/sizer.h>
#include <wx/html/htmlwin.h>

#include "wx/splitter.h"
#include "wx/treectrl.h"
#include "wx/listctrl.h"
#include "wx/toolbar.h"
#include "wx/filedlg.h"
#include "wx/imagpng.h"
#include "wx/bmpbuttn.h"
#include "wx/dirdlg.h"
#include "wx/help.h"

#include "../moleapi.h"

struct MyMainFrame: wxDialog  
{
    wxPanel *BuildPanel(wxWindow *parent)
      {
        wxString build_no = wxString::Format(L"%d",Molebox_BuildNo());
        wxString pcid = wxString::Format(L"%x",Molebox_PcId());
       
        wxPanel *pan = new wxPanel(parent);
        wxBoxSizer *topszr = new wxStaticBoxSizer(new wxStaticBox(pan,wxID_ANY,L"MOLEBOX: API"),wxVERTICAL);
        wxBoxSizer *r0;
        r0 = new wxBoxSizer(wxHORIZONTAL);
        r0->Add(new wxStaticText(pan,wxID_ANY,L"BuildNo",wxDefaultPosition,wxSize(80,-1)), 0, wxRIGHT|wxALIGN_CENTER_VERTICAL, 3);
        r0->Add(new wxStaticText(pan,wxID_ANY,build_no,wxDefaultPosition,wxSize(80,-1)), 0, wxRIGHT|wxALIGN_CENTER_VERTICAL, 3);
        topszr->Add(r0, 0, wxLEFT|wxRIGHT|wxGROW|wxALIGN_LEFT, 5 );
        r0 = new wxBoxSizer(wxHORIZONTAL);
        r0->Add(new wxStaticText(pan,wxID_ANY,L"PcId",wxDefaultPosition,wxSize(80,-1)), 0, wxRIGHT|wxALIGN_CENTER_VERTICAL, 3);
        r0->Add(new wxStaticText(pan,wxID_ANY,pcid,wxDefaultPosition,wxSize(80,-1)), 0, wxRIGHT|wxALIGN_CENTER_VERTICAL, 3);
        topszr->Add(r0, 0, wxLEFT|wxRIGHT|wxGROW|wxALIGN_LEFT, 5 );
        pan->SetSizer(topszr);
        return pan;
      }

    MyMainFrame(const wchar_t *title) : 
	wxDialog(0, wxID_ANY, +title, wxDefaultPosition, wxDefaultSize )
      {        
        wxBoxSizer *topszr = new wxBoxSizer(wxVERTICAL);
        wxPanel *pan = BuildPanel(this);
        topszr->Add(pan, 0, wxALL, 10);
        wxSizer *buttons = CreateButtonSizer(wxOK);
        topszr->Add( buttons, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 10 );
        SetSizer(topszr);
        topszr->Fit(this);
        //SetSize(wxSize(776,480+48));
      }

    void OnQuit(wxCommandEvent& WXUNUSED(event))
      {
        Destroy();
      }
  
DECLARE_EVENT_TABLE();

  };

struct MyWxApp: wxApp
  {
    MyWxApp() : wxApp()
      {
         //DebugBreak();
      }

    virtual bool OnInit()
      {
        //DebugBreak();
        return true;
      }
    virtual int OnRun()
      {
        wxApp *app = wxTheApp;
	wxLayoutDirection d = wxTheApp->GetLayoutDirection();
        MyMainFrame *frame = new MyMainFrame(L"Show API");
        frame->ShowModal();             
        return 0;
      }
    virtual ~MyWxApp()
      {
      }
      
    virtual wxLayoutDirection GetLayoutDirection() const
      {
        return wxApp::GetLayoutDirection();
      }
  };

BEGIN_EVENT_TABLE(MyMainFrame, wxDialog)
    //EVT_MENU(wxID_ABOUT, MyMainFrame::OnAbout)
    EVT_MENU(wxID_EXIT,  MyMainFrame::OnQuit)
END_EVENT_TABLE()

DECLARE_APP(MyWxApp)
IMPLEMENT_APP(MyWxApp)

