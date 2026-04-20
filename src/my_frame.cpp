#include "my_frame.hpp"
#include <wx/wx.h>
#include <wx/hyperlink.h>

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Runclim") {
    wxPanel* panel = new wxPanel(this);
    wxPanel* bottom_bar = new wxPanel(this);
    bottom_bar->SetBackgroundColour(wxColour(50, 50, 50));

    [[maybe_unused]]
    wxHyperlinkCtrl* link = new wxHyperlinkCtrl(
        bottom_bar, wxID_ANY,
        "Like this tool? Support development on Ko-Fi",
        "https://ko-fi.com/arvantitik",
        wxPoint(10, 5)
    );

    wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
    main_sizer->Add(panel, 1, wxEXPAND);
    main_sizer->Add(bottom_bar, 0, wxEXPAND);
    SetSizer(main_sizer);
}
