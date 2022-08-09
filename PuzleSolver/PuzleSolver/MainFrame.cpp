#include "MainFrame.h"
#include "ImagePanel.h"
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

		IMG.infoButtonIMG.LoadFile(IMG.filePath + IMG.infoFileName, wxBITMAP_TYPE_PNG);
		IMG.infoButtonIMG.Rescale(30, 30);
	//	IMG.infoButtonIMG->SetMaskColour(255, 255, 255);

		//if (IMG.infoButtonIMG.IsOk())
		//	IMG.infoButtonIMG.SetAlpha(IMG.infoButtonIMG, true);

		wxBitmap infoButtonBitmap(IMG.infoButtonIMG);

		//wxBitmap prepBtnBmp(infoButtonBitmap.GetWidth(), infoButtonBitmap.GetHeight()); // the prepared bmp, to assign to your button
		//wxMemoryDC memDC(prepBtnBmp);
		//memDC.SetBackground(*wxTheBrushList->FindOrCreateBrush(*wxWHITE));
		//memDC.Clear();
		//memDC.DrawBitmap(infoButtonBitmap, 0, 0);
		//memDC.SelectObject(wxNullBitmap);
		/*wxColor white(255, 255, 255, 255);
		wxMask mask(infoButtonBitmap, white);
		infoButtonBitmap.SetMask(&mask);*/
		//bool is = infoButtonBitmap.HasAlpha();
		//infoButtonBitmap.ResetAlpha();
		//infoButtonBitmap.UseAlpha(false);

		//wxColor white(255, 255, 255);
		//wxMask* transparentMask = new wxMask(infoButtonBitmap, white);
		//infoButtonBitmap.SetMask(transparentMask);
		//infoButtonBitmap.GetMask();

	//	IMG.infoButtonIMG.LoadFile(IMG.filePath + IMG.startFileName, wxBITMAP_TYPE_JPEG);
	   // wxBitmap* startButtonBitmap = new wxBitmap(IMG.startButtonIMG);

		/*wxAnimation appTitleAnim;
		appTitleAnim.LoadFile(IMG.fiePathGif + IMG.appTitle, wxANIMATION_TYPE_GIF);

		wxAnimationCtrl* appTitleAnimController = new wxAnimationCtrl(imgMainPanel, NAME_TXT_ID, appTitleAnim, wxPoint(centerX, 150 + mainSett.gap));*/
	/*	appTitleAnimController->Play();*/

		//wxBitmapButton* startButton = new wxBitmapButton(imgMainPanel, START_BTN_ID, startButtonBitmap, wxPoint(centerX, 150 + mainSett.gap), wxSize(mainSett.w, mainSett.h));	

		wxBitmapButton* infoButton = new wxBitmapButton(imgMainPanel, HELP_BTN_ID, infoButtonBitmap);
		//infoButton->SetTransparent(true);

		wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	/*	mainSizer->Add(appTitleAnimController, 1, wxALIGN_CENTER | wxTOP | wxBOTTOM);*/
	//s	mainSizer->Add(startButton, 1, wxALIGN_CENTER | wxTOP | wxBOTTOM);
		mainSizer->Add(infoButton, 0, wxALIGN_TOP | wxALIGN_LEFT);
	  

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