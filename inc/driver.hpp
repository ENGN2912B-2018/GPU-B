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
		/************************************ Con/Destructors ************************************/
			Frame(){} 							// Constructor

			~Frame(){} 							// Destructor
		/************************************ Data Member Set ************************************/
			void setDeviceNumber(int input) {DeviceNumber = input;}

			void setFrameFate(int input) {FrameRate = input;}

			void setRecDuration(int input) {RecDuration = input;}

			void setOnScreenRec(bool input) { OnScreenRec = input;}
		
		    void resetBuffer() {
				FrameBufferVec.clear();
				ptBufferFrame = 0;
				BufferFilled = false;
			}

			void resetBufferPointer(){
				ptBufferFrame = 0;
			}

		/************************************ Data Member Get ************************************/

			int getDeviceNumber() {return DeviceNumber;}

			int getFrameRate() {return FrameRate;}

			int getRecDuration() {return RecDuration;}

			int getTotalFrame() {return FrameCount;}

			bool getDeviceStatus() {return DeviceEnable;} 

			bool getBufferStatus() {return BufferFilled;}

			bool getOnScreenStatus() {return OnScreenRec;}

		/************************************ Buffer Get *****************************************/
			Mat frameGetFrame(){ 										// Take Current Frame and Move Pointer to Next

				unsigned long long int thisFrame = ptBufferFrame;
				if (thisFrame < RecFrameCount){
					ptBufferFrame ++;
					return FrameBufferVec.at(thisFrame);				// Return this frame
				} else {
					return emptyMat;									// Return emptyMat when out of range
				}
			
			}

			Mat frameGetPrev(){ 										// Take Current Frame and Move Pointer to Previous
				unsigned long long int thisFrame = ptBufferFrame;
				if (thisFrame < RecFrameCount){ 						// Datatype for thisFrame: unsigned long long int, max 18,446,744,073,709,551,615
					ptBufferFrame --;
					return FrameBufferVec.at(thisFrame);
				} else {
					return emptyMat;									// Return emptyMat when out of range
				}

			}

			Mat frameGetAny(unsigned long long int targetFrame){ 		// Get any frame
				if (targetFrame < RecFrameCount){
					return FrameBufferVec.at(targetFrame);				// Return this frame
				} else {
					return emptyMat;									// Return emptyMat when out of range
				}
			}

			Mat framePeekNext(){ 										// Take Next Frame and keep pointer as it is
				unsigned long long int thisFrame = ptBufferFrame + 1;
				if (thisFrame < RecFrameCount){
					return FrameBufferVec.at(thisFrame);				// Return this frame
				} else {
					return emptyMat;									// Return emptyMat when out of range
				}
			}

			Mat framePeekPrev(){ 										// Take Previous Frame and keep pointer as it is
				unsigned long long int thisFrame = ptBufferFrame - 1;
				if (thisFrame < RecFrameCount){
					return FrameBufferVec.at(thisFrame);				// Return this frame
				} else {
					return emptyMat;									// Return emptyMat when out of range
				}
			}

			Mat framePeekThis(){ 										// Take Current Frame and keep pointer as it is
				if (ptBufferFrame < RecFrameCount){
					return FrameBufferVec.at(thisFrame);				// Return this frame
				} else {
					return emptyMat;									// Return emptyMat when out of range
				}
			}
		/************************************ Video Record ***************************************/
			void Video_Ini(){ 																	// Initialization for video
				VideoStreamCap.open(DeviceNumber);												// Connect to camera
				VideoStreamCap.set(CV_CAP_PROP_XI_FRAMERATE, FrameRate);
				if(!VideoStreamCap.isOpened()){
					DeviceEnable = true;
				}
			}

			void Video_Capture(){ 																// Record Video （Option: Offscreen or Onscreed）
				RecFrameCount = 0; 																// Reset Total Recorded Frame
				if (OnScreenRec == true){
					while RecFrameCount < FrameCount){
						VideoStreamCap >> VideoFrame; 												// Capture Video Frame
						if(!(VideoFrame.empty())) { FrameBufferVec.push_back(VideoFrame.clone()); } // Store in buffer
					}
				} else {
					while RecFrameCount < FrameCount){
						VideoStreamCap >> VideoFrame; 												// Capture Video Frame
						imshow("Video Capture", VideoFrame);
						if(!(VideoFrame.empty())) { FrameBufferVec.push_back(VideoFrame.clone()); } // Store in buffer
					}
				}
				BufferFilled = true;
			}

			void Video_Playback(){ 																// Playback Recorded Video in Buffer
				for (int index = 0; index < FrameCount; index++){
					imshow("Video Capture", FrameBufferVec.at(index));   						// Read Recorded buffer and playback
				}
			}

			

		private:
			bool DeviceEnable = false;
			bool BufferFilled = false;

			bool OnScreenRec = false;						// Show video while recording. Suggest set to false to save computing pwr

			int DeviceNumber = 0;							// Device Number. Select when there are mutilpe cameras in system
			int RecDuration = 5; 							// Video Clip duration in seconds
			int FrameRate = 30; 							// Frame Rate in Frame/Second
			int FrameCount = RecDuration * FrameRate; 		// Total Frame Number, 0 base

			int RecFrameCount = 0;							// Total Frame Recorded, index, 0 base

			unsigned long long int ptBufferFrame = 0;       // Pointer for access buffer frames

			Mat VideoFrame;									// For storing single frame
			Mat emptyMat;                                 	// Empty matrix, for returning purpose
			vector<Mat> FrameBufferVec;						// For frame buffer

			VideoCapture VideoStreamCap;					// Camera Stream object

	};

	class FrameBuffer{
		public:
			virtual Frame nextFrame();
	};

} // gpub


#endif // _DRIVER_HPP
