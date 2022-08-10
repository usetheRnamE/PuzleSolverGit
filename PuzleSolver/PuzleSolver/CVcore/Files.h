#pragma once

#include <iostream>
#include <opencv2/highgui.hpp>

namespace CVcore
{
	enum CubeSide
	{
		WhiteSide, RedSide, BlueSide, OrangeSide, GreenSide, YellowSide
	};

	enum PuzleType
	{
		Pyramid = 4, Cube = 6
	};

	enum cvFileType
	{
		PNG, JPG, JPEG
	};

	class Files
	{
	private:
		const std::string filePath = "Images/";

		const std::string fileNames[Cube] = { "White", "Red", "Blue", "Orange", "Green", "Yellow" };

		const std::string fileType[3] = { ".png", ".jpg", ".jpeg" };

	protected:
		cv::Mat images[Cube];

	public:
		void LoadFiles();
	};
}
