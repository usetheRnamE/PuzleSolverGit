#include "MainFrame.h"
#include <iostream>

struct ButtonSettings
{
	const float w = 200, h = 50;
	const float gap = 50;
} mainSett;

namespace GUI
{
	MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
	{
		wxPanel* mainPanel = new wxPanel(this);

		wxButton* startButton = new wxButton(mainPanel, wxID_ANY, "Begin the cubing session", wxPoint(250, 50 + mainSett.gap), wxSize(mainSett.w, mainSett.h));
		wxButton* settingButton = new wxButton(mainPanel, wxID_ANY, "Settings", wxPoint(250, 150 + mainSett.gap), wxSize(mainSett.w, mainSett.h));
		wxButton* exitButton = new wxButton(mainPanel, wxID_ANY, "Exit", wxPoint(250, 250 + mainSett.gap), wxSize(mainSett.w, mainSett.h));
	}
}