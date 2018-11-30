/*
 *File Name    : driver.hpp
 * Author      : Ziwei Chen
 * Date        : Nov-27-2018
 * Modified    : Ziwei Chen
 * Modify Date : Nov-29-2017
 * 
 * Description : This class was to buffer the video stream from external device.
 * 
 * OpenCV Installation: 
 * https://medium.com/@jaskaranvirdi/setting-up-opencv-and-c-development-environment-in-xcode-b6027728003
 * Compile Using (g++):
 * $ g++ $(pkg-config --cflags --libs opencv) -std=c++11  OpenCVTest.cpp -o VideoCapTest
 * 
 * ******************************************************************************************
*/
#ifndef _DRIVER_HPP
#define _DRIVER_HPP
#include <iostream>
#include <thread>
#include <queue>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>

namespace gpub
{
	class Frame{
		/*
		 * This class was designed to use OpenCL for video capture
		 * openCV can be installed by $ brew install opencv
		*/
		public:
			Frame(); 											// Constructor
			~Frame(); 											// Destructor

			void setDeviceNumber(int input);					// Set functions
			void setFrameFate(int input); 
			void setOnScreenRec(bool input); 

			unsigned int getDeviceNumber(); 					// Get functions
			unsigned int getFrameRate(); 
			bool getDeviceStatus(); 
			bool getOnScreenStatus(); 


			void video_ini();									// Record functions
			void video_start(FrameBuffer& BufferObj)
			void video_stop();

		private:
			bool DeviceEnable = false;
			bool OnScreenRec = false;							// Show video while recording. Suggest set to false to save computing pwr
			bool CaptureStart = false;

			unsigned int DeviceNumber = 0;						// Device Number. Select when there are mutilpe cameras in system
			unsigned int FrameRate = 30; 						// Frame Rate in Frame/Second

			cv::Mat VideoFrame;									// For storing single frame
			cv::VideoCapture VideoStreamCap;					// Camera Stream object
	};

	class FrameBuffer{
		public:
			FrameBuffer(); 										// Constructor
			~FrameBuffer();  									// Destructor

			void setSize(unsigned int inputSize); 
			void push(const cv::Mat& inputFrame); 				// Store Function, pass by reference
			
			cv::Mat get();										// Get Frame Function
			cv::Mat peek();

		private:
			unsigned int BufferSize = 150;
			cd::Mat EmptyFrame;
			std::queue <cd::Mat> FrameBuffer;

	};

} // gpub


#endif // _DRIVER_HPP
