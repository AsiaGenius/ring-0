
/**

  Copyright (c) 2011, Alexéy Sudáchen, Teggo Software Ltd.

*/

#include <wx/wx.h>
#include <wx/aboutdlg.h>
#include <wx/sizer.h>
#include <wx/html/htmlwin.h>

#include <string>

std::wstring AtAppFolder(wchar_t const *fname)
  {
    wchar_t direct[MAX_PATH] = {0};
    if ( !direct[0] )
      {
        int count = ::GetModuleFileNameW(0,&direct[0],MAX_PATH);
        wchar_t *q = wcsrchr(direct,'\\');
        if ( q ) q[1] = 0;
      }
    return std::wstring(direct)+fname;
  }

struct MyMainFrame: wxDialog
  {
    MyMainFrame(const wchar_t *title) : wxDialog(0, wxID_ANY, title, wxDefaultPosition, wxDefaultSize )
      {
        wxBoxSizer *topszr = new wxBoxSizer(wxVERTICAL);
        wxPanel *pan = new wxPanel(this);
        wxHtmlWindow *html = new wxHtmlWindow(pan,wxID_ANY,wxDefaultPosition,wxSize(520,480),wxHW_SCROLLBAR_NEVER|wxSUNKEN_BORDER);
        html->LoadPage(AtAppFolder(L"testfile.htm").c_str());
        html->SetSize( html->GetInternalRepresentation()->GetWidth(),
                       html->GetInternalRepresentation()->GetHeight());
        html->SetBorders(0);
        pan->SetSize(html->GetSize());
        topszr->Add(pan, 0, wxALL, 10);
        wxSizer *buttons = CreateButtonSizer(wxOK);
        topszr->Add( buttons, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 10 );
        SetSizer(topszr);
        topszr->Fit(this);
        //SetSize(wxSize(776,480+48));
      }
  };


struct MyWxApp: wxApp
  {
    virtual bool OnInit()
      {
        return true;
      }
    virtual int OnRun()
      {
        MyMainFrame *frame = new MyMainFrame(L"MxbTest");
        frame->ShowModal();
        return 0;
      }
    virtual ~MyWxApp()
      {
      }
  };

DECLARE_APP(MyWxApp)
IMPLEMENT_APP(MyWxApp)
