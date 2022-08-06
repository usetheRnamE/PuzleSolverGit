#pragma once

#include <wx/wx.h>

namespace GUI
{
	class MainFrame : public wxFrame
	{
	public:
		MainFrame(const wxString& title);
	public:
		void OnStartBTNClick(wxCommandEvent& evt);
		void OnSettingsBTNClick(wxCommandEvent& evt);
		void OnExitBTNClick(wxCommandEvent& evt);

		wxDECLARE_EVENT_TABLE();
	};
}

