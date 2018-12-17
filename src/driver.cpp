/*
 *File Name    : driver.cpp
 * Author      : Ziwei Chen
 * Date        : Nov-29-2018
 * Modified    : Ziwei Chen
 * Modify Date : Dec-15-2018
 *
 * Description : This class was to buffer the video stream from external device.
 *  Compile: g++ -Wall -O3 driver.cpp ../inc/driver.hpp -I/usr/local/Cellar/opencv/3.4.3/include/opencv -I/usr/local/Cellar/opencv/3.4.3/include -L/usr/local/Cellar/opencv/3.4.3/lib -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dpm -lopencv_face -lopencv_photo -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_dnn -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_flann -lopencv_xobjdetect -lopencv_imgcodecs -lopencv_objdetect -lopencv_xphoto -lopencv_imgproc -lopen
 * ******************************************************************************************
*/
#include "../inc/driver.hpp"

/*
 *  ********************************************* CameraDriver: FrameBuffer Class Methods *********************************************
*/
gpub::CameraDriver::CameraDriver(){}

gpub::CameraDriver::~CameraDriver(){}

// Set functions
void gpub::CameraDriver::setDeviceNumber(int input) {
	DeviceNumber = input;
}

void gpub::CameraDriver::setFrameFate(int input) {
	FrameRate = input;
}

void gpub::CameraDriver::setOnScreenRec(bool input) {
	OnScreenRec = input;
}

void gpub::CameraDriver::setBufferSize(unsigned int inputSize) {        // Set buffer size
    BufferSize = inputSize;
}

// Get functions
unsigned int gpub::CameraDriver::getDeviceNumber() {
	return DeviceNumber;
}

unsigned int gpub::CameraDriver::getFrameRate() {
	return FrameRate;
}

bool gpub::CameraDriver::getDeviceStatus() {
	return DeviceEnable;
}

bool gpub::CameraDriver::getOnScreenStatus() {
	return OnScreenRec;
}

// Record functions
bool gpub::CameraDriver::iniCap() {                                     // Initialization for video
        VideoStreamCap.open(DeviceNumber);				// Connect to camera
	VideoStreamCap.set(CV_CAP_PROP_XI_FRAMERATE, FrameRate);
	if(!VideoStreamCap.isOpened()){
		DeviceEnable = true;
	}
    return 0;
}

bool gpub::CameraDriver::startCap() {                                   // Record Video （Option: Offscreen or Onscreed）
    CaptureStart = true;                                                // Set Capture to start
    while((CaptureStart == true)){
        VideoStreamCap >> VideoFrame; 					// Capture Video Frame
        if (bufferWrite == true){                                       // When buffer was enabled
	        if (OnScreenRec == true) {
                MatObj = Frame(VideoFrame.clone());                     // Construct Video Frame here
		        if (FIFOBuffer.size() < BufferSize) {
                    FIFOBuffer.push(MatObj);                            // Store in buffer
                } else {
                    FIFOBuffer.pop();
                    FIFOBuffer.push(MatObj);
                }
		        //imshow(VideoFrame);
	        } else {
                MatObj = Frame(VideoFrame.clone());                     // Construct Video Frame here
		        if (FIFOBuffer.size() < BufferSize) {
                    FIFOBuffer.push(MatObj);                            // Store in buffer
                } else {
                    FIFOBuffer.pop();
                    FIFOBuffer.push(MatObj);
                }
	        }
        }
    }
    return 0;
}

bool gpub::CameraDriver::stopCap() {
    CaptureStart = false;
    return 0;
}

/*
 *  Overloads
*/
gpub::Frame &gpub::CameraDriver::nextFrame() {                          // Method for get frame
    if (FIFOBuffer.size() > 0) {
        OutputFrameObj = FIFOBuffer.front();
        FIFOBuffer.pop();
    } else {
        OutputFrameObj = Frame(EmptyFrame,false);                       // Create and output dummy frame
    }
    return OutputFrameObj;
}

bool gpub::CameraDriver::stop() {
    bufferWrite = false;
    return true;
}

bool gpub::CameraDriver::start() {
    bufferWrite = true;
    return true;
}
