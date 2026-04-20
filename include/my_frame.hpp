#pragma once
#include <wx/wx.h>
#include <wx/simplebook.h>

class MyFrame : public wxFrame {
private:
    wxSimplebook* book_;
    wxPanel* BuildHomePage(wxWindow* parent);
    wxPanel* BuildWorkPage(wxWindow* parent);
    void OnLogin(wxCommandEvent& event);

public:
    MyFrame();
};
