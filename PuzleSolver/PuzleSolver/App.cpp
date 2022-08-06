#include "App.h"
#include "MainFrame.h"
namespace GUI
{
	wxIMPLEMENT_APP(App);

	bool App::OnInit()
	{
		const std::string filePath = "Resources/Font/"; //D:/WK/C++/PuzleSolverGit/PuzleSolver/PuzleSolver/
		const std::string fileName = "Font.ttf";
		wxFontBase::AddPrivateFont(filePath + fileName);

		MainFrame* mainFrame = new MainFrame("Puzle Solver"); // needs to be deleted somewhere!!!
		mainFrame->SetClientSize(700, 500);
		mainFrame->Center();
		mainFrame->Show();
		return true;
	}
}