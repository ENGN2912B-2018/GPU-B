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
	class CameraDriver: public FrameBuffer{
        /* This class was to get frames from actual camera,
         * and construce the fram object using class Frame.
         * The constructed frame should be stored into a queue
        */
        public:
            CameraDriver();                         // Constructor
            ~CameraDriver();                        // Destructor

			void setDeviceNumber(int input);		// Set functions
			void setFrameFate(int input); 
			void setOnScreenRec(bool input); 

            void setBufferSize(unsigned int inputSize)

			unsigned int getDeviceNumber(); 		// Get functions
			unsigned int getFrameRate(); 
			bool getDeviceStatus(); 
			bool getOnScreenStatus(); 

            void ini();                             // Initialize Video Stream

            virtual Frame nextFrame();	            // I/O: Get the next frame from buffer
            virtual bool stop();                    // I/O: Stop Video Capturing (Stop fillin buffer)
            virtual bool start();                   // I/O: Start Video Capturing (Start fillin buffer)

        private:
            unsigned int BufferSize = 150;

            Frame MatObj;                           // Constructed Frame Object
            Frame OutputFrameObj;                   // Constructed Void Frame Object
            cv::VideoCapture VideoStreamCap;		// Camera Stream object
            cv::Mat EmptyFrame;                     // Empty Frame
            cv::Mat VideoFrame;                     // Frame from camera
            std::quene<Frame> FIFOBuffer;           // Quene of frame object

			bool DeviceEnable = false;
			bool OnScreenRec = false;				// Show video while recording. Suggest set to false to save computing pwr
			bool CaptureStart = false;

			unsigned int DeviceNumber = 0;			// Device Number. Select when there are mutilpe cameras in system
			unsigned int FrameRate = 30; 			// Frame Rate in Frame/Second

	};
} // gpub

#endif // _DRIVER_HPP
