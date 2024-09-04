#include <wx/wx.h>
#include "Main.h"
#include <wx/notebook.h>
#include <wx/wx.h>
#include <vector>
#include <string>

Main::Main(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	controls();
}

// H and H (renault), Ford Sheridan

void Main::controls() {
	panel = new wxPanel(this);
http://192.168.178.116:5005/
	notebook = new wxNotebook(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize);

	wxPanel* tab1 = new wxPanel(notebook, wxID_ANY);
	wxPanel* tab2 = new wxPanel(notebook, wxID_ANY);
	wxPanel* tab3 = new wxPanel(notebook, wxID_ANY);

	wxButton* button1 = new wxButton(tab1, wxID_ANY, "left");
	wxButton* button2 = new wxButton(tab1, wxID_ANY, "middle");
	wxButton* button3 = new wxButton(tab1, wxID_ANY, "right");

	/*wxTextCtrl* textCtrl1 = new wxTextCtrl(notebook, wxID_ANY, L"Tab 1 Contents");
	notebook->AddPage(textCtrl1, L"Tab 1");
	wxTextCtrl* textCtrl2 = new wxTextCtrl(notebook, wxID_ANY, L"Tab 2 Contents");
	notebook->AddPage(textCtrl2, L"Tab 2");*/

	wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* middleSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);

	leftSizer->Add(button1, 1, wxEXPAND | wxALL, 5);
	middleSizer->Add(button2, 1, wxEXPAND | wxALL, 5);
	rightSizer->Add(button3, 1, wxEXPAND | wxALL, 5);


	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
	mainSizer->Add(leftSizer, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(rightSizer, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(middleSizer, 1, wxEXPAND | wxALL, 5);

	tab1->SetSizer(mainSizer);

	
	notebook->AddPage(tab1, L"Tab1");
	notebook->AddPage(tab2, L"Tab2");
	notebook->AddPage(tab3, L"Tab3");


	//leftSizer->Add(button1);
	//middleSizer->Add(button2);
	//rightSizer->Add(button3);


	wxBoxSizer* tabsSizer = new wxBoxSizer(wxHORIZONTAL);
	//mainSizer->Add(leftSizer, 0, wxALIGN_LEFT | wxALL, 10);
	//mainSizer->AddStretchSpacer(1);
	tabsSizer->Add(notebook, 1, wxEXPAND | wxALL, 5);
	//mainSizer->AddStretchSpacer(1);
	//mainSizer->Add(rightSizer, 0, wxALIGN_RIGHT | wxALL, 10);
	

	panel->SetSizer(tabsSizer);


	tabsSizer->SetSizeHints(this);
	this->Fit();

}

void Main::OnWindowsClose(wxCloseEvent& evt){
	
}

void Main::OnResize(wxSizeEvent& evt){

}

void Main::NewTab() {
	wxPanel tab = new wxPanel(notebook, wxID_ANY);
	

}
