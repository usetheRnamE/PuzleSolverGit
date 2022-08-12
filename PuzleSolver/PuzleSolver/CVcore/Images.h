#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

namespace CVcore
{
	class Images 
	{
	private:
		const cv::Size imageSize = cv::Size(100, 100);

	public:
		void ImageProcessing(cv::Mat(&images)[6]);

	private:
		void Resize(cv::Mat& currentImage);
		void ColorDetect(cv::Mat& currentImage);
		void BordersDetect(cv::Mat& currentImage);
		void Chop(cv::Mat& currentImage);
	};
}

