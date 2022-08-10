#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


namespace CVcore
{
	class Images : Files
	{
	private:
		cv::Size imageSize;

	private:
		void ImageProcessing();
		void Resize(cv::Mat& currentImage)

	};
}

