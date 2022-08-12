#include "Files.h"
#include "Cube.h";
#include "Images.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

namespace CVcore
{
	void Files::LoadFiles()
	{
		Puzle::Cube cube;

		for (int i = 0; i < cube.GetSideCount(); i++)
		{
			try
			{
				images[i] = cv::imread(filePath + fileNames[i] + fileType[JPG]);

				if(!images[i].data)
					printf("Cannot find: %s%s", fileNames[i], fileType[JPG]);
			}
			catch (std::exception e)
			{
				printf("Exception: [%s]\n", e.what());
			}
		}

		if (!images->empty())
		{
			Images imgInstance;

			imgInstance.ImageProcessing(images);
		}
	}
}