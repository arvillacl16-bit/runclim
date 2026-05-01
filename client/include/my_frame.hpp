#pragma once
#include <wx/wx.h>
#include <wx/simplebook.h>

class MyFrame : public wxFrame {
private:
    wxSimplebook* book_;
    wxTextCtrl* username_field_;
    wxTextCtrl* password_field_;
    wxSimplebook* analysis_book_;
    wxTimer* poll_timer_;

    wxPanel* BuildHomePage(wxWindow* parent);
    wxPanel* BuildLoginPage(wxWindow* parent);
    wxPanel* BuildWorkPage(wxWindow* parent);
    wxPanel* BuildDefaultAnalysisPage(wxWindow* parent);
    wxPanel* BuildNewRunPage(wxWindow* parent);
    wxPanel* BuildWaitPage(wxWindow* parent);
    wxPanel* BuildExistingRunPage(wxWindow* parent);
    void OnLogin(wxCommandEvent& event);
    void OnLogSubmit(wxCommandEvent& event);
    void OnLogout(wxCommandEvent& event);
    void ShowDefaultAnalysis(wxCommandEvent& event);
    void ShowNewRun(wxCommandEvent& event);
    void ShowWaitPage(wxCommandEvent& event);
    void ShowExistingRun(const wxString& run_id);
    void OnRunSubmitted(wxCommandEvent& event);
    void OnPollTimer(wxTimerEvent& event);

public:
    MyFrame();
};
