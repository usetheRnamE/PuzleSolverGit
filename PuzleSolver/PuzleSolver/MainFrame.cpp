#include "MainFrame.h"
#include "Color.h"

#include <iostream>
#include <string>

struct ButtonSettings
{
	const float w = 200, h = 50;
	const float gap = 50;
} mainSett;

namespace GUI
{
	enum ID // forbiden ID: 0, 1, [4999, 5999]
	{
		START_BTN_ID = 2, SETTINGS_BTN_ID, EXIT_BTN_ID,
		NAME_TXT_ID
	};

	void ButtonSet(wxButton& btn, float scale)
	{
		btn.SetBackgroundColour(COLOR.Platinum);
		btn.SetForegroundColour(COLOR.Green);
		btn.SetFont(btn.GetFont().Scale(scale));
	}

	wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
		EVT_BUTTON(START_BTN_ID, MainFrame::OnStartBTNClick)
		EVT_BUTTON(SETTINGS_BTN_ID, MainFrame::OnSettingsBTNClick)
		EVT_BUTTON(EXIT_BTN_ID, MainFrame::OnExitBTNClick)
	wxEND_EVENT_TABLE()


	MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
	{
		wxPanel* mainPanel = new wxPanel(this);
		mainPanel->SetBackgroundColour(COLOR.Black);

		float centerX = 250;

		wxStaticText* nameOfApp = new wxStaticText(mainPanel, NAME_TXT_ID, "Puzle Solver", wxPoint(centerX, 50), wxSize(200, 50), wxBU_RIGHT | wxBU_EXACTFIT);
		nameOfApp->SetBackgroundColour(COLOR.Black);
		nameOfApp->SetForegroundColour(COLOR.Yellow);
		nameOfApp->SetFont(nameOfApp->GetFont().Scale(3));

		wxButton* startButton = new wxButton(mainPanel, START_BTN_ID, "Start", wxPoint(centerX, 100 + mainSett.gap), wxSize(mainSett.w, mainSett.h));
		ButtonSet(*startButton, 1.5);

		wxButton* settingButton = new wxButton(mainPanel, SETTINGS_BTN_ID, "Settings", wxPoint(centerX, 200 + mainSett.gap), wxSize(mainSett.w, mainSett.h));
		ButtonSet(*settingButton, 1.5);

		wxButton* exitButton = new wxButton(mainPanel, EXIT_BTN_ID, "Exit", wxPoint(centerX, 300 + mainSett.gap), wxSize(mainSett.w, mainSett.h));
		ButtonSet(*exitButton, 1.5);

		CreateStatusBar();
	}

	void MainFrame::OnStartBTNClick(wxCommandEvent& evt)
	{
		wxLogStatus("Started");
	}

	void MainFrame::OnSettingsBTNClick(wxCommandEvent& evt)
	{
		wxLogStatus("Settings");
	}

	void MainFrame::OnExitBTNClick(wxCommandEvent& evt)
	{
		wxLogStatus("Exit");
	}
}