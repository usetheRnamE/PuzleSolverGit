#pragma once

#include <wx/wx.h>

namespace GUI
{
	enum ID // forbiden ID: 0, 1, [4999, 5999]
	{
		START_BTN_ID = 2, HELP_BTN_ID,
		NAME_TXT_ID,
		BACKGROUND_ID
	};

	class MainFrame : public wxFrame
	{
	public:
		MainFrame(const wxString& mainFrameTitle);
	public:
		void OnStartBTNClick(wxCommandEvent& evt);
		void OnHelpBTNClick(wxCommandEvent& evt);

		wxDECLARE_EVENT_TABLE();
	};
}

