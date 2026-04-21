#include "my_frame.hpp"
#include <wx/wx.h>
#include <wx/hyperlink.h>

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Runclim") {
    wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);

    book_ = new wxSimplebook(this);
    book_->AddPage(BuildHomePage(book_), "");
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

    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Work page coming soon");
    wxButton* logout_btn = new wxButton(panel, wxID_ANY, "Logout");

    Bind(wxEVT_BUTTON, &MyFrame::OnLogout, this, logout_btn->GetId());

    sizer->AddStretchSpacer();
    sizer->Add(label, 0, wxALIGN_CENTER);
    sizer->Add(logout_btn, 0, wxALIGN_CENTER | wxTOP, 10);
    sizer->AddStretchSpacer();

    panel->SetSizer(sizer);
    return panel;
}

void MyFrame::OnLogin(wxCommandEvent& event) {
    // TODO: Add login logic
    book_->SetSelection(1);
}

void MyFrame::OnLogout(wxCommandEvent& event) {
    book_->SetSelection(0);
}
