#pragma once
#include <wx/wx.h>
#include <wx/simplebook.h>

class MyFrame : public wxFrame {
private:
    wxSimplebook* book_;
    wxTextCtrl* username_field_;
    wxTextCtrl* password_field_;
    wxPanel* BuildHomePage(wxWindow* parent);
    wxPanel* BuildLoginPage(wxWindow* parent);
    wxPanel* BuildWorkPage(wxWindow* parent);
    void OnLogin(wxCommandEvent& event);
    void OnLogSubmit(wxCommandEvent& event);
    void OnLogout(wxCommandEvent& event);

public:
    MyFrame();
};
