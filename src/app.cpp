#include "app.hpp"
#include "my_frame.hpp"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    frame->Maximize();
    return true;
}
