#pragma once

#include <wx/wx.h>

namespace GUI
{
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

