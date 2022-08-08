#include "MainFrame.h"
#include "Colors.h"
#include "ImagePanel.h"
#include "GUISettings.h"
#include "Images.h"

#include <iostream>
#include <string>
#include <wx/animate.h>
namespace GUI
{
	enum ID // forbiden ID: 0, 1, [4999, 5999]
	{
		START_BTN_ID = 2, HELP_BTN_ID,
		NAME_TXT_ID,
		BACKGROUND_ID
	};

	wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
		EVT_BUTTON(START_BTN_ID, MainFrame::OnStartBTNClick)
		EVT_BUTTON(HELP_BTN_ID, MainFrame::OnHelpBTNClick)
	wxEND_EVENT_TABLE()

	MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
	{
		ImagePanel* imgMainPanel = new ImagePanel(this, IMG.filePath + IMG.backgroundFileName, wxBITMAP_TYPE_JPEG);
		imgMainPanel->SetMinClientSize(wxSize(640, 480));

		float centerX = 250;

		IMG.infoButtonIMG.LoadFile(IMG.filePath + IMG.infoFileName, wxBITMAP_TYPE_JPEG);
		IMG.infoButtonIMG.Rescale(50, 50);
		wxBitmap infoButtonBitmap(IMG.infoButtonIMG);

	//	IMG.infoButtonIMG.LoadFile(IMG.filePath + IMG.startFileName, wxBITMAP_TYPE_JPEG);
	   // wxBitmap* startButtonBitmap = new wxBitmap(IMG.startButtonIMG);

		wxAnimation appTitleAnim;
		appTitleAnim.LoadFile(IMG.fiePathGif + IMG.appTitle, wxANIMATION_TYPE_GIF);

		wxAnimationCtrl* appTitleAnimController = new wxAnimationCtrl(imgMainPanel, NAME_TXT_ID, appTitleAnim, wxPoint(centerX, 150 + mainSett.gap));
		appTitleAnimController->Play();

		//wxBitmapButton* startButton = new wxBitmapButton(imgMainPanel, START_BTN_ID, startButtonBitmap, wxPoint(centerX, 150 + mainSett.gap), wxSize(mainSett.w, mainSett.h));	

		wxBitmapButton* infoButton = new wxBitmapButton(imgMainPanel, HELP_BTN_ID, infoButtonBitmap);

		wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
		mainSizer->Add(appTitleAnimController, 1, wxALIGN_CENTER | wxTOP | wxBOTTOM);
	//s	mainSizer->Add(startButton, 1, wxALIGN_CENTER | wxTOP | wxBOTTOM);
		mainSizer->Add(infoButton, 1, wxALIGN_TOP | wxALIGN_LEFT | wxTOP | wxLEFT);
	  



		imgMainPanel->SetSizer(mainSizer);

		mainSizer->Layout();
	}

	void MainFrame::OnStartBTNClick(wxCommandEvent& evt)
	{
		wxLogStatus("Started");
		//evt.Skip();
	}

	void MainFrame::OnHelpBTNClick(wxCommandEvent& evt)
	{
		wxLogStatus("Info");
	}
}