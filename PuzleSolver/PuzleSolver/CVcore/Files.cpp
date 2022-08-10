#include "Files.h"
#include "Cube.h";

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

namespace CVcore
{
	Puzle::Cube cube;

	void ImageProcessing();

	void Files::LoadFiles()
	{
		for (int i = 0; i < cube.GetSideCount(); i++)
			images[i] = cv::imread(filePath + fileNames[i] + fileType[JPG]);

		ImageProcessing();
		//cv::waitKey(0);
	}
}