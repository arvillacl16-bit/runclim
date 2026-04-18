#include <wx/wx.h>

class MyApp : public wxApp {
public:
    bool OnInit() override;
};

class MyFrame : public wxFrame {
private:
    void OnButtonClick(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);

public:
    MyFrame();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Hello wxWidgets") {
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Click me", wxPoint(100, 100));

    Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this, button->GetId());
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    CreateStatusBar();
    SetStatusText("ready");
}

void MyFrame::OnButtonClick(wxCommandEvent& event) {
    wxMessageBox("Hello world", "Test", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

