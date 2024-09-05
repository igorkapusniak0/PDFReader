#include <wx/wx.h>
#include "Main.h"
#include <wx/notebook.h>
#include <wx/wx.h>
#include <vector>
#include <string>

Main::Main(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	controls();
	BindEventHandlers();
}


void Main::controls() {
	panel = new wxPanel(this);

	//addTabButton = new wxButton(panel, wxID_ANY, "Add Tab", wxPoint(10, 10));

	notebook = new wxNotebook(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize);

	menuBar = new wxMenuBar;
	
	menuFile = new wxMenu;
	menuTools = new wxMenu();
	menuHelp = new wxMenu();

	menuFile->Append(wxID_OPEN, wxT("&Open File"));
	menuFile->Append(wxID_CLOSE, wxT("&Close File"));
	
	menuBar->Append(menuFile, wxT("&File"));
	menuBar->Append(menuHelp, wxT("&Help"));
	menuBar->Append(menuTools, wxT("&File"));

	statusBar = this->CreateStatusBar();
	

	SetMenuBar(menuBar);

	wxBoxSizer* tabsSizer = new wxBoxSizer(wxHORIZONTAL);

	tabsSizer->Add(notebook, 1, wxEXPAND | wxALL, 5);

	panel->SetSizer(tabsSizer);


	tabsSizer->SetSizeHints(this);
	this->Fit();

}

void Main::OnWindowsClose(wxCloseEvent& evt){
	
}

void Main::OnResize(wxSizeEvent& evt){

}

void Main::BindEventHandlers() {

	//addTabButton->Bind(wxEVT_BUTTON, &Main::NewTab, this);
	menuFile->Bind(wxEVT_MENU, &Main::NewTab, this, wxID_OPEN);
	menuFile->Bind(wxEVT_MENU, &Main::CloseTab, this, wxID_CLOSE);
}

void Main::CloseTab(wxCommandEvent& evt) {
	statusBar->SetStatusText("closedtab");
	int openPage = notebook->GetSelection();
	if (openPage == wxNOT_FOUND){
		return;
	}
	notebook->DeletePage(openPage);
	
}



void Main::NewTab(wxCommandEvent& evt) {

	wxPanel* tab = new wxPanel(notebook, wxID_ANY);

	wxButton* button1 = new wxButton(tab, wxID_ANY, "left");
	wxButton* button2 = new wxButton(tab, wxID_ANY, "middle");
	wxButton* button3 = new wxButton(tab, wxID_ANY, "right");

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

	tab->SetSizer(mainSizer);

	notebook->AddPage(tab, L"Tab");
	statusBar->SetStatusText("newtab");
}


