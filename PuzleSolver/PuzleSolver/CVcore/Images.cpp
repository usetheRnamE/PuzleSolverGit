#include "Images.h"
#include "Files.h"

namespace CVcore
{
	void Images::Resize(cv::Mat& currentImage) 
	{
		cv::resize(currentImage, currentImage, imageSize);
	}

	void Images::ColorDetect(cv::Mat& currentImage)
	{
	}

	void Images::BordersDetect(cv::Mat& currentImage)
	{
	}

	void Images::Chop(cv::Mat& currentImage)
	{

	}

	void Images::ImageProcessing(cv::Mat (&images)[6])
	{
		for(cv::Mat image : images)
		{
			Resize(image);


			cv::imshow("Resized", image);
			cv::waitKey(0);
		}
	}
}