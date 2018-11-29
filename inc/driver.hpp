/*
 *File Name    : driver.hpp
 * Author      : Ziwei Chen
 * Date        : Nov-27-2018
 * Modified    : N/A
 * Modify Date : N/A
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
#include <vector>
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
		/************************************ Con/Destructors ************************************/
			Frame(){} 							// Constructor
			~Frame(){} 							// Destructor
		/************************************ Data Member Set ************************************/
			void setDeviceNumber(int input)
			{
				DeviceNumber = input;
			}

			void setFrameFate(int input) 
			{
				FrameRate = input;
			}

			void setRecDuration(int input) 
			{
				RecDuration = input;
			}

			void setOnScreenRec(bool input) 
			{
				OnScreenRec = input;
			}

		/************************************ Data Member Get ************************************/

			int getDeviceNumber() 
			{
				return DeviceNumber;
			}

			int getFrameRate() 
			{
				return FrameRate;
			}

			int getRecDuration( 
			{
				return RecDuration;
			}

			int getTotalFrame() 
			{
				return FrameCount;
			}

			bool getDeviceStatus() 
			{
				return DeviceEnable;
			} 

			bool getBufferStatus() 
			{
				return BufferFilled;
			}

			bool getOnScreenStatus() 
			{
				return OnScreenRec;
			}

		/************************************ Buffer Get *****************************************/
			cv::Mat get() 														// Take Current Frame and Move Pointer to Next
			{
				if (FrameBufferVec.size() > 0){
					cv::Mat ThisFrame = FrameBufferVec.front(thisFrame);
					FrameBufferVec.pop();
					return ThisFrame;											// Return this frame
				}
				else 
				{
					return emptyMat;											// Return emptyMat when out of range
				}
			
			}

			cv::Mat peek() 														// Take Current Frame and Move Pointer to Previous
			{
				if (FrameBufferVec.size() > 0)
				{
					return FrameBufferVec.front(thisFrame);
				}
				else 
				{
					return emptyMat;											// Return emptyMat when out of range
				}

			}

		/************************************ Video Record ***************************************/
			void video_ini()
			{ 																		// Initialization for video
				VideoStreamCap.open(DeviceNumber);									// Connect to camera
				VideoStreamCap.set(CV_CAP_PROP_XI_FRAMERATE, FrameRate);
				if(!VideoStreamCap.isOpened())
				{
					DeviceEnable = true;
				}
			}

			void video_capture()
			{ 																		// Record Video （Option: Offscreen or Onscreed）
				RecFrameCount = 0; 													// Reset Total Recorded Frame
				if (OnScreenRec == true)
				{
					while RecFrameCount < FrameCount)
					{
						VideoStreamCap >> VideoFrame; 								// Capture Video Frame
							if (FrameBufferVec.size() <= BufferSize)
							{
								FrameBufferVec.push(VideoFrame.clone()); 			// Store in buffer
								imshow(VideoFrame);

							}
							else													// Keep buffer in size
							{
								FrameBufferVec.pop();
								FrameBufferVec.push(VideoFrame.clone());
								imshow(VideoFrame);
							}
					}
				}
				else
				{
					while RecFrameCount < FrameCount)								// Capture Video Frame
					{
						VideoStreamCap >> VideoFrame; 					
						imshow("Video Capture", VideoFrame);
						if(!(VideoFrame.empty()))
						{	
							if (FrameBufferVec.size() <= BufferSize)
							{
								FrameBufferVec.push(VideoFrame.clone()); 			// Store in buffer
							}
							else													// Keep buffer in size
							{
								FrameBufferVec.pop();
								FrameBufferVec.push(VideoFrame.clone());
							}
						} 
					}
				}
				BufferFilled = true;
			}

			void video_playback()
			{ 																		// Playback Recorded Video in Buffer
				while (FrameBufferVec.size() > 0)
				{
					imshow("Video Capture", FrameBufferVec.front());   				// Read Recorded buffer and playback
					FrameBufferVec.pop();
				}
			}

			

		private:
			bool DeviceEnable = false;
			bool BufferFilled = false;

			bool OnScreenRec = false;							// Show video while recording. Suggest set to false to save computing pwr

			unsigned int DeviceNumber = 0;						// Device Number. Select when there are mutilpe cameras in system
			unsigned int RecDuration = 5; 						// Video Clip duration in seconds
			unsigned int FrameRate = 30; 						// Frame Rate in Frame/Second
			unsigned int FrameCount = RecDuration * FrameRate; 	// Total Frame Number, 0 base

			unsigned int RecFrameCount = 0;						// Total Frame Recorded, index, 0 base

			unsigned int BufferSize = 150;                      // Defaule buffer size 5 seconds

			cv::Mat VideoFrame;									// For storing single frame
			cv::Mat emptyMat;                             		// Empty matrix, for returning purpose
            std::queue <cv::Mat> FrameBufferVec;				// For frame buffer

			cv::VideoCapture VideoStreamCap;					// Camera Stream object

	};

	class FrameBuffer{
		public:
			virtual Frame nextFrame();
	};

} // gpub


#endif // _DRIVER_HPP
