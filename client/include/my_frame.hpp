#pragma once
#include <wx/wx.h>
#include <wx/simplebook.h>
#include <wx/spinctrl.h>
#include <wx/filepicker.h>

class MyFrame : public wxFrame {
private:
    wxSimplebook* book_;
    wxTextCtrl* username_field_;
    wxTextCtrl* password_field_;
    wxSimplebook* analysis_book_;
    wxTimer* poll_timer_;
    wxSpinCtrlDouble *atm_n2_spin_, *atm_o2_spin_, *atm_co2_spin_, *flux_spin_, *star_temp_spin_;
    wxFilePickerCtrl* topo_file_picker_;

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
