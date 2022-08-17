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

	cv::Mat Preprocess(cv::Mat& img)
	{
		cv::Mat imgGS, imgBlur, imgCanny, imgDil;

		cv::cvtColor(img, imgGS, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(imgGS, imgBlur, cv::Size(3, 3), 3, 0);
		cv::Canny(imgBlur, imgCanny, 25, 75);

		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

		cv::dilate(imgCanny, imgDil, kernel);
	
	  /*  cv::imshow("uncolored", imgGS);
		cv::imshow("CAnny", imgCanny);
		cv::imshow("Dil", imgDil);

		cv::waitKey(0);*/
		

		return imgDil;
	}

    /*static double Angle(cv::Point point1, cv::Point point2, cv::Point pointZero)
    {
        double dx1 = point1.x - pointZero.x;
        double dy1 = point1.y - pointZero.y;
        double dx2 = point2.x - pointZero.x;
        double dy2 = point2.y - pointZero.y;
        return (dx1 * dx2 + dy1 * dy2) / sqrt((dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2) + 1e-10);
    }*/

    static void FindSquares(const cv::Mat& image, std::vector<std::vector<cv::Point> >& squares)
    {
        squares.clear();
        cv::Mat pyr, timg, gray0(image.size(), CV_8U), gray;

        // down-scale and upscale the image to filter out the noise
        pyrDown(image, pyr, cv::Size(image.cols / 2, image.rows / 2));
        pyrUp(pyr, timg, image.size());

        std::vector<std::vector<cv::Point> > contours;

        int thresh = 50, N = 11;

        for (int c = 0; c < 3; c++)
        {
            int chanel[] = { c, 0 };
            mixChannels(&timg, 1, &gray0, 1, chanel, 1);

            for (int l = 0; l < N; l++)
                if (l == 0)
                {
                    Canny(gray0, gray, 0, thresh, 5);

                    dilate(gray, gray, cv::Mat(), cv::Point(-1, -1));
                }
                else
                    gray = gray0 >= (l + 1) * 255 / N;

            findContours(gray, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
            std::vector<cv::Point> approx;

            for (size_t i = 0; i < contours.size(); i++)
            {
                approxPolyDP(contours[i], approx, arcLength(contours[i], true) * 0.02, true);

                if (approx.size() == 4 &&
                    fabs(contourArea(approx)) > 0 &&
                    isContourConvex(approx))
                {
                    //double maxCosine = 0;
                    //for (int j = 2; j < 5; j++)
                    //{
                    //    // find the maximum cosine of the angle between joint edges
                    //    double cosine = fabs(Angle(approx[j % 4], approx[j - 2], approx[j - 1]));
                    //    maxCosine = MAX(maxCosine, cosine);
                    //}
                    //// if cosines of all angles are small
                    //// (all angles are ~90 degree) then write quandrange
                    //// vertices to resultant sequence
                    //if (maxCosine < 0.3)
                        squares.push_back(approx);
                }
            }
        }
        cv::imshow("pyr", pyr);
        cv::imshow("timg", timg);
        cv::imshow("gray0", gray0);
        cv::imshow("gray", gray);

        cv::waitKey(0);
    }

	void Images::BordersDetect(cv::Mat& currentImage)
	{
		cv::Mat testImg = Preprocess(currentImage);

		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> hierarchy;

		cv::findContours(testImg, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

		std::vector<std::vector<cv::Point>> conPoly(contours.size());
		std::vector<cv::Rect> boundRect(contours.size());

		for (int i = 0; i < contours.size(); i++)
			if (cv::contourArea(contours[i]) > 1000)
			{
				cv::approxPolyDP(contours[i], conPoly[i], .02 * cv::arcLength(contours[i], true), true);

				cv::drawContours(currentImage, conPoly, i, cv::Scalar(255, 0, 255), 1);

				boundRect[i] = cv::boundingRect(conPoly[i]);

				cv::rectangle(currentImage, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 255, 0), 5);
			}
	}

	void Images::Chop(cv::Mat& currentImage)
	{

	}

	void Images::ImageProcessing(cv::Mat (&images)[6])
	{
        std::vector<std::vector<cv::Point> > squares;

		for(cv::Mat image : images)
		{
			Resize(image);

			//BordersDetect(image);

            FindSquares(image, squares);
            polylines(image, squares, true, cv::Scalar(0, 255, 0), 3, cv::LINE_AA);

			cv::imshow("Contoured", image);

            int c = cv::waitKey();
            if (c == 27)
                break;
		}

		cv::waitKey(0);

	}
}