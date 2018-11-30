/*
 *File Name    : driver.cpp
 * Author      : Ziwei Chen
 * Date        : Nov-29-2018
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

#include "driver.hpp"

/********************************** Video Capture Class *********************************/
Frame::Frame(){}

Frame::~Frame(){}

// Set functions
void Frame::setDeviceNumber(int input)
{
	DeviceNumber = input;
}

void Frame::setFrameFate(int input) 
{
	FrameRate = input;
}

void Frame::setOnScreenRec(bool input) 
{
	OnScreenRec = input;
}

// Get functions
unsigned int Frame::getDeviceNumber() 
{
	return DeviceNumber;
}

unsigned int Frame::getFrameRate() 
{
	return FrameRate;
}

bool Frame::getDeviceStatus() 
{
	return DeviceEnable;
} 

bool Frame::getOnScreenStatus() 
{
	return OnScreenRec;
}

// Record functions
void Frame::video_ini()
{ 																		// Initialization for video
	VideoStreamCap.open(DeviceNumber);									// Connect to camera
	VideoStreamCap.set(CV_CAP_PROP_XI_FRAMERATE, FrameRate);
	if(!VideoStreamCap.isOpened())
	{
		DeviceEnable = true;
	}
}


void Frame::video_start(FrameBuffer& BufferObj)
{ 																		// Record Video （Option: Offscreen or Onscreed）
    CaptureStart = true;
    while(CaptureStart == true)
    {
	    if (OnScreenRec == true)
	    {
		    VideoStreamCap >> VideoFrame; 						        // Capture Video Frame
		    BufferObj.push(VideoFrame);                                 // Store in buffer
		    imshow(VideoFrame);
	    }
	    else
	    {
		    VideoStreamCap >> VideoFrame;                               // Capture Video Frame
		    BufferObj.push(VideoFrame);                                 // Store in buffer
	    }
    }
}

void Frame::video_stop()
{
    CaptureStart = false;
}

/********************************** Frame Buffer Class **********************************/

FrameBuffer::FrameBuffer(){}

FrameBuffer::~FrameBuffer(){}

void FrameBuffer::setSize(unsigned int inputSize)                       // Set buffer size
{
    BufferSize = inputSize;
}

void FrameBuffer::push(const cv::Mat& inputFrame)                       // Push new frame into buffer
{
    if (FrameBuffer.size() < BufferSize)
    {
        FrameBuffer.push(inputFrame.clone());
    }
    else
    {
        FrameBuffer.pop();
        FrameBuffer.push(inputFrame.clone());
    }

}

cv::Mat FrameBuffer::get(){
    if (FrameBuffer.size() > 0)
    {
        cv::Mat TempFrame = FrameBuffer.front();                        // Store the first frame
        FrameBuffer.pop();                                              // Deleate the first frame

        return TempFrame;                                               // Return the first frame
    }
    else
    {
        return EmptyFrame;
    }
}

cv::Mat FrameBuffer::peek(){
    if (FrameBuffer.size() > 0)
    {
        cv::Mat TempFrame = FrameBuffer.front();                        // Store the first frame
        FrameBuffer.pop();                                              // Deleate the first frame

        return TempFrame;                                               // Return the first frame
    }
    else
    {
        return EmptyFrame;
    }
}