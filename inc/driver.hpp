#ifndef _DRIVER_HPP
#define _DRIVER_HPP
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>

using namespace cv;
using namespace std;

namespace gpub
{

	class Frame{
		/*
		 * This class was designed to use OpenCL for video capture
		 * openCV can be installed by $ brew install opencv
		*/
		public:
			Frame(){}

			~Frame(){}

			VideoCapture(){
				// Initialize Video Stream Using OpenCV
    			VideoCapture VideoStreamCap;
				VideoStreamCap.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));// Video Stream Capture Settings
    			VideoStreamCap.set(CV_CAP_PROP_FPS, 30);
    			VideoStreamCap.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
    			VideoStreamCap.set(CV_CAP_PROP_FRAME_HEIGHT, 720);

				// Initialize Video Capture GUI
				VideoStreamCap.open(0);
				namedWindow("Video Stream Capture");

    			if( !VideoStreamCap.isOpened() ){
        			std::cerr << "***Could not initialize capturing...***\n";
        			return -1;
    			}

				//

			}
		

		private:
			cv::Mat VideoFrameMat; // Matrix for Video Frame Storeage
			

	};

	class FrameBuffer{
		public:
			virtual Frame nextFrame();
	};

} // gpub


#endif // _DRIVER_HPP
