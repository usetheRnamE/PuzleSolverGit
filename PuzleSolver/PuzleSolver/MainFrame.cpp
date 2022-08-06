#include "MainFrame.h"
#include "Colors.h"

#include <iostream>
#include <string>

namespace GUI
{
	struct ButtonSettings
	{
		const float w = 200, h = 50;
		const float gap = 50;
	} mainSett;

	enum ID // forbiden ID: 0, 1, [4999, 5999]
	{
		START_BTN_ID = 2, HELP_BTN_ID,
		NAME_TXT_ID
	};

	template <typename T>
	void GUI_ElementAdjust(T& GUIelement, float scale, wxColor backgroundColor)
	{
		GUIelement.SetBackgroundColour(backgroundColor);
		GUIelement.SetForegroundColour(COLOR.Yellow);
		GUIelement.SetFont(GUIelement.GetFont().Scale(scale));
	}

	wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
		EVT_BUTTON(START_BTN_ID, MainFrame::OnStartBTNClick)
		EVT_BUTTON(HELP_BTN_ID, MainFrame::OnHelpBTNClick)
	wxEND_EVENT_TABLE()


	MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
	{
		wxPanel* mainPanel = new wxPanel(this);
		mainPanel->SetBackgroundColour(COLOR.Black);

		float centerX = 250;

		wxStaticText* nameOfApp = new wxStaticText(mainPanel, NAME_TXT_ID, "Puzle Solver", wxPoint(0, 75), wxSize(700, 50), wxBU_RIGHT | wxBU_EXACTFIT);
		GUI_ElementAdjust(*nameOfApp, 3, COLOR.Black);
		wxFont fnt = nameOfApp->GetFont();

		wxButton* startButton = new wxButton(mainPanel, START_BTN_ID, "Start", wxPoint(centerX, 150 + mainSett.gap), wxSize(mainSett.w, mainSett.h));
		GUI_ElementAdjust(*startButton, 1.5, COLOR.Silver);

		wxButton* exitButton = new wxButton(mainPanel, HELP_BTN_ID, "Help", wxPoint(centerX, 250 + mainSett.gap), wxSize(mainSett.w, mainSett.h));
		GUI_ElementAdjust(*exitButton, 1.5, COLOR.Silver);

	}

	void MainFrame::OnStartBTNClick(wxCommandEvent& evt)
	{
		wxLogStatus("Started");
	}

	void MainFrame::OnHelpBTNClick(wxCommandEvent& evt)
	{
		wxLogStatus("Info");
	}
}