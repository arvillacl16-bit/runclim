#include "my_frame.hpp"
#include <wx/wx.h>
#include <wx/hyperlink.h>
#include <wx/splitter.h>

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Runclim") {
    wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);

    poll_timer_ = new wxTimer(this);
    Bind(wxEVT_TIMER, &MyFrame::OnPollTimer, this);

    book_ = new wxSimplebook(this);
    book_->AddPage(BuildHomePage(book_), "");
    book_->AddPage(BuildLoginPage(book_), "");
    book_->AddPage(BuildWorkPage(book_), "");
    book_->SetSelection(0);

    wxPanel* bottom_bar = new wxPanel(this);
    bottom_bar->SetBackgroundColour(wxColour(50, 50, 50));

    [[maybe_unused]]
    wxHyperlinkCtrl* link = new wxHyperlinkCtrl(
        bottom_bar, wxID_ANY,
        "Like this tool? Support development on Ko-Fi",
        "https://ko-fi.com/arvantitik",
        wxPoint(10, 5)
    );
    main_sizer->Add(book_, 1, wxEXPAND);
    main_sizer->Add(bottom_bar, 0, wxEXPAND);
    SetSizer(main_sizer);
}

wxPanel* MyFrame::BuildHomePage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* title = new wxStaticText(panel, wxID_ANY, "Welcome to Runclim");
    wxStaticText* desc = new wxStaticText(panel, wxID_ANY, "Run ExoPlaSim in the cloud and analyze results");
    wxButton* login_btn = new wxButton(panel, wxID_ANY, "Login / Register");

    Bind(wxEVT_BUTTON, &MyFrame::OnLogin, this, login_btn->GetId());

    sizer->AddStretchSpacer();
    sizer->Add(title, 0, wxALIGN_CENTER | wxBOTTOM, 10);
    sizer->Add(desc, 0, wxALIGN_CENTER | wxBOTTOM, 20);
    sizer->Add(login_btn, 0, wxALIGN_CENTER);
    sizer->AddStretchSpacer();

    panel->SetSizer(sizer);
    return panel;
}

wxPanel* MyFrame::BuildWorkPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    wxSplitterWindow* splitter = new wxSplitterWindow(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);

    wxPanel* runs_panel = new wxPanel(splitter);
    wxPanel* analysis_panel = new wxPanel(splitter);

    analysis_book_ = new wxSimplebook(analysis_panel);
    analysis_book_->AddPage(BuildDefaultAnalysisPage(analysis_book_), "");
    analysis_book_->AddPage(BuildNewRunPage(analysis_book_), "");
    analysis_book_->AddPage(BuildWaitPage(analysis_book_), "");
    analysis_book_->AddPage(BuildExistingRunPage(analysis_book_), "");
    analysis_book_->SetSelection(0);

    wxBoxSizer* analysis_sizer = new wxBoxSizer(wxVERTICAL);
    analysis_sizer->Add(analysis_book_, 1, wxEXPAND);
    analysis_panel->SetSizer(analysis_sizer);

    wxButton* new_run_btn = new wxButton(runs_panel, wxID_ANY, "New run");
    Bind(wxEVT_BUTTON, &MyFrame::ShowNewRun, this, new_run_btn->GetId());

    splitter->SplitVertically(runs_panel, analysis_panel);
    splitter->SetSashGravity(0.3);
    splitter->SetBackgroundColour(wxColour(150, 150, 150));

    wxButton* logout_btn = new wxButton(panel, wxID_ANY, "Logout");
    Bind(wxEVT_BUTTON, &MyFrame::OnLogout, this, logout_btn->GetId());

    sizer->Add(splitter, 1, wxEXPAND);
    sizer->Add(logout_btn, 0, wxALIGN_RIGHT | wxALL, 5);
    panel->SetSizer(sizer); 
    return panel;
}

wxPanel* MyFrame::BuildLoginPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    username_field_ = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(250, -1));
    password_field_ = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(250, -1), wxTE_PASSWORD);

    wxButton* login_btn = new wxButton(panel, wxID_ANY, "Login");
    wxButton* register_btn = new wxButton(panel, wxID_ANY, "Register");
    
    Bind(wxEVT_BUTTON, &MyFrame::OnLogSubmit, this, login_btn->GetId());
    Bind(wxEVT_BUTTON, &MyFrame::OnLogSubmit, this, register_btn->GetId());

    sizer->AddStretchSpacer();
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Username"), 0, wxALIGN_CENTER | wxBOTTOM, 5);
    sizer->Add(username_field_, 0, wxALIGN_CENTER | wxBOTTOM, 10);
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Password"), 0, wxALIGN_CENTER | wxBOTTOM, 5);
    sizer->Add(password_field_, 0, wxALIGN_CENTER | wxBOTTOM, 20);
    sizer->Add(login_btn, 0, wxALIGN_CENTER | wxBOTTOM, 5);
    sizer->Add(register_btn, 0, wxALIGN_CENTER | wxBOTTOM, 5);
    sizer->AddStretchSpacer();

    panel->SetSizer(sizer);
    return panel;
}

void MyFrame::OnLogin(wxCommandEvent& event) {
    book_->SetSelection(1);
}

void MyFrame::OnLogSubmit(wxCommandEvent& event) {
    // TODO: Validate
    book_->SetSelection(2);
}

void MyFrame::OnLogout(wxCommandEvent& event) {
    book_->SetSelection(0);
}

void MyFrame::ShowDefaultAnalysis(wxCommandEvent& event) {
    analysis_book_->SetSelection(0);
}

void MyFrame::ShowNewRun(wxCommandEvent& event) {
    analysis_book_->SetSelection(1);
}

void MyFrame::ShowExistingRun(const wxString& run_id) {
    // TODO: IMPLEMENT
    analysis_book_->SetSelection(3);
}

void MyFrame::OnRunSubmitted(wxCommandEvent& event) {
    // TODO: Send to cloud
    ShowExistingRun("run_id");
}

void MyFrame::ShowWaitPage(wxCommandEvent& event) {
    analysis_book_->SetSelection(2);
    poll_timer_->Start(3000);
}

void MyFrame::OnPollTimer(wxTimerEvent& event) {
    poll_timer_->Stop();
    ShowExistingRun("run_id");
}

wxPanel* MyFrame::BuildDefaultAnalysisPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    new wxStaticText(panel, wxID_ANY, "Default Analysis");
    return panel;
}

wxPanel* MyFrame::BuildNewRunPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "New Run");
    wxButton* btn = new wxButton(panel, wxID_ANY, "Send");
    Bind(wxEVT_BUTTON, &MyFrame::ShowWaitPage, this, btn->GetId());

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->AddStretchSpacer();
    sizer->Add(text);
    sizer->Add(btn);
    sizer->AddStretchSpacer();

    panel->SetSizer(sizer);
    return panel;
}

wxPanel* MyFrame::BuildWaitPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Waiting");
    return panel;
}

wxPanel* MyFrame::BuildExistingRunPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Existing Run");
    wxButton* btn = new wxButton(panel, wxID_ANY, "Back to analysis");
    Bind(wxEVT_BUTTON, &MyFrame::ShowDefaultAnalysis, this, btn->GetId());

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->AddStretchSpacer();
    sizer->Add(text);
    sizer->Add(btn);
    sizer->AddStretchSpacer();

    panel->SetSizer(sizer);
    return panel;
}
