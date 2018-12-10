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

#include <string>
#include <chrono>
#include <iostream>
#include <thread>
#include <queue>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>

namespace gpub
{

/**
 * The class Frame is a timestamped raw image. It is produced by the camera
 * driver and consumed by the processing logic.
 */
class Frame
{
//! Timestamp type
typedef std::chrono::time_point<std::chrono::system_clock> ts_t;
private:
	//! The image
	cv::Mat& img;
	//! Timestamp of image capture
	ts_t ts;
	//! Signal if a frame is valid. Invalid frame may indicate an empty buffer
	bool isValid;

public:
	/**
	 * A frame is timestamped as now.
	 * @prarm img The image matrix
	 */
	Frame(cv::Mat& img, bool isValid=true):
		img(img), isValid(isValid) {ts = std::chrono::system_clock::now();}

	/**
	 * @param img The image matrix
	 * @param ts Frame timestamp
	 */
	Frame(cv::Mat& img, ts_t ts, bool isValid=true):
		img(img), ts(ts), isValid(isValid) {}

	/**
	 *	Usage: if(frame), check if frame is valid
	 */
	bool operator bool() {return isValid;}

	cv::Mat& getImg() const {return img;}
	ts_t getTs() const {return ts;}
	bool getIsValid() const {return isValid;}

	void setImg(const cv::Mat& img) {this->img = img;}
	void setTs(ts_t ts) {this->ts = ts;}
	void setIsValid(bool isValid) {this->isValid = isValid;}
};

/**
 * The class FrameBuffer is a virtual class of a camera driver. All driver
 * classes should inherent from this class.
 */
class FrameBuffer
{
public:
	/**
	 * Produce a new frame for the processing logic.
	 * @return The reference to next frame awaits processing
	 */
	virtual Frame& nextFrame() = 0;

	/**
	 * Called by the logic when the ball is found, the driver should prevent
	 * the buffer from overwriting.
	 * @return True if success else False
	 */
	virtual bool stop() = 0;

	/**
	 * Called by the logic when the processing is finished, the driver should
	 * flush the buffer and start recording.
	 * @return True if success else False
	 */
	virtual bool start() = 0;
};

/**
 * The FileReader reads images from files. It is used for testing.
 */
class FileReader: public FrameBuffer
{
private:
	//! Path to the image file
	std::string fileName;
public:
	/**
	 * @param fileName Path to the image file
	 */
	FileReader(std::string fileName):
		fileName(fileName) {}

	void setFileName(std::string fileName) {this->fileName = fileName;}

	/* overloads */
	Frame& nextFrame() {return Frame(cv::imread(fileName));}
	bool stop() {return true;}
	bool start() {return true;}
};
  
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