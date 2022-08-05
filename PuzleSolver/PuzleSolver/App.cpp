#include "App.h"
#include "MainFrame.h"
namespace GUI
{
	wxIMPLEMENT_APP(App);

	bool App::OnInit()
	{
		MainFrame* mainFrame = new MainFrame("Puzle Solver"); // needs to be deleted somewhere!!!
		mainFrame->SetClientSize(700, 500);
		mainFrame->Center();
		mainFrame->Show();
		return true;
	}
}