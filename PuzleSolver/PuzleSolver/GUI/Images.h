#pragma once
#include <iostream>

namespace GUI
{

	struct Images
	{
		std::string filePath = "Resources/Images/";
		std::string fiePathGif = "Resources/Gifs/";

		std::string backgroundFileName = "Background.jpg";	


		std::string infoFileName = "InfoButton.png";
		std::string startFileName = "StartButton.png";

		std::string appTitle = "PuzleSolverTitle.gif";

		wxImage infoButtonIMG, startButtonIMG;
	} IMG;
}