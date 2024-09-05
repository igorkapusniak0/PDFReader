#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>

class Main : public wxFrame {
public:
	Main(const wxString& title);

private:
	void controls();

	void OnWindowsClose(wxCloseEvent& evt);
	void OnResize(wxSizeEvent& evt);
	void NewTab(wxCommandEvent& evt);
	void BindEventHandlers();

	wxPanel* panel;
	wxWindow* window;	
	wxNotebook* notebook;
	wxButton* addTabButton;
};