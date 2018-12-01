/*
 *File Name    : driver.cpp
 * Author      : Ziwei Chen
 * Date        : Nov-29-2018
 * Modified    : Ziwei Chen
 * Modify Date : Nov-30-2018
 * 
 * Description : This class was to buffer the video stream from external device.
 * 
 * ******************************************************************************************
*/
#include "driver.hpp"

CameraDriver::CameraDriver(){}

CameraDriver::~CameraDriver(){}

// Set functions
void CameraDriver::setDeviceNumber(int input) {
	DeviceNumber = input;
}

void CameraDriver::setFrameFate(int input) {
	FrameRate = input;
}

void CameraDriver::setOnScreenRec(bool input) {
	OnScreenRec = input;
}

void CameraDriver::setBufferSize(unsigned int inputSize) {              // Set buffer size
    BufferSize = inputSize;
}


// Get functions
unsigned int CameraDriver::getDeviceNumber() {
	return DeviceNumber;
}

unsigned int CameraDriver::getFrameRate() {
	return FrameRate;
}

bool CameraDriver::getDeviceStatus() {
	return DeviceEnable;
} 

bool CameraDriver::getOnScreenStatus() {
	return OnScreenRec;
}

// Record functions
void CameraDriver::ini() { 												// Initialization for video
	VideoStreamCap.open(DeviceNumber);									// Connect to camera
	VideoStreamCap.set(CV_CAP_PROP_XI_FRAMERATE, FrameRate);
	if(!VideoStreamCap.isOpened()){
		DeviceEnable = true;
	}
}

virtual bool CameraDriver::start() { 		                    		// Record Video （Option: Offscreen or Onscreed）
    CaptureStart = true;                                                // Set Capture to start
    while(CaptureStart == true){
        VideoStreamCap >> VideoFrame; 						            // Capture Video Frame
	    if (OnScreenRec == true) {
            MatObj = Frame(VideoFrame.clone()):                         // Construct Video Frame here
		    if (FIFOBuffer.size() < BufferSize) {
                FIFOBuffer.push(MatObj);                                // Store in buffer
            } else {
                FIFOBuffer.pop();
                FIFOBuffer.push(MatObj);
            }
		    imshow(VideoFrame);
	    } else {
            MatObj = Frame(VideoFrame.clone()):                         // Construct Video Frame here
		    if (FIFOBuffer.size() < BufferSize) {
                FIFOBuffer.push(MatObj);                                // Store in buffer
            } else {
                FIFOBuffer.pop();
                FIFOBuffer.push(MatObj);
            }
	    }
    }
    return 0;
}

virtual bool CameraDriver::stop() {
    CaptureStart = false;
    return 0;
}

virtual Frame nextFrame() {                                              // Method for get frame
    if (FIFOBuffer.size() > 0) {
        OutputFrameObj = FrameBuffer.front();
        FrameBuffer.pop();
    } else {
        OutputFrameObj = Frame(EmptyFrame,false);                       // Create and output dummy frame
    }
    return OutputFrameObj;
}