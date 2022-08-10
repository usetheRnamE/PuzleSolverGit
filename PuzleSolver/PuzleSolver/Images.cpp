#include "Images.h"
#include "Files.h"

namespace CVcore
{
	void Images::Resize(cv::Mat& currentImage) { cv::resize(currentImage, currentImage, imageSize); }

	void Images::ImageProcessing()
	{
		for (int i = 0; i < 1; i++)
		{
			Resize(*images);

			cv::imshow("Resized", images[i]);
		}


		cv::waitKey(0);
	}
}