#include "App.h"
#include "MainFrame.h"

namespace GUI
{
	wxIMPLEMENT_APP(App);

	bool App::OnInit()
	{
		wxInitAllImageHandlers();

		MainFrame* mainFrame = new MainFrame("Puzle Solver");

		mainFrame->SetClientSize(700, 500);
		mainFrame->Center();
		mainFrame->Show();
		SetTopWindow(mainFrame);
		return true;
	}
}