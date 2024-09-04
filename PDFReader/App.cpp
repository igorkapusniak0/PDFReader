#include "App.h"
#include "Main.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	Main* main = new Main("PDF Reader");
	main->SetClientSize(800, 600);
	main->Center();
	main->Show();
	return true;
}