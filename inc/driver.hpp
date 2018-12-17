/*
 *File Name    : driver.hpp
 * Author      : Ziwei Chen
 * Date        : Nov-27-2018
 * Modified    : Ziwei Chen
 * Modify Date : Dec-15-2018
 *
 * Description : This class was to buffer the video stream from external device.
 *
 * OpenCV Installation:
 * https://medium.com/@jaskaranvirdi/setting-up-opencv-and-c-development-environment-in-xcode-b6027728003
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
	cv::Mat img;
	//! Timestamp of image capture
	ts_t ts;
	//! Signal if a frame is valid. Invalid frame may indicate an empty buffer
	bool isValid;

public:
	Frame() {}
	Frame(const Frame& f) {Frame(f.img);}
	/**
	 * A frame is timestamped as now.
	 * @prarm img The image matrix
	 */
	Frame(const cv::Mat& img, bool isValid=true):
		img(img), isValid(isValid) {ts = std::chrono::system_clock::now();}

	/**
	 * @param img The image matrix
	 * @param ts Frame timestamp
	 */
	Frame(const cv::Mat& img, ts_t ts, bool isValid=true):
		img(img), ts(ts), isValid(isValid) {}

	/**
	 *	Usage: if(frame), check if frame is valid
	 */
	operator bool() {return isValid;}


	cv::Mat getImg() const {return img;}
	ts_t getTs() const {return ts;}
	bool getIsValid() const {return isValid;}

	void setImg(const cv::Mat& img) {this->img = img;}
	void setTs(ts_t ts) {this->ts = ts;}
	void setIsValid(bool isValid) {this->isValid = isValid;}
};
/*
 *  ******************************************************************************************
*/

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
	virtual Frame& nextFrame() {}

	/**
	 * Called by the logic when the ball is found, the driver should prevent
	 * the buffer from overwriting.
	 * @return True if success else False
	 */
	virtual bool stop() {}

	/**
	 * Called by the logic when the processing is finished, the driver should
	 * flush the buffer and start recording.
	 * @return True if success else False
	 */
	virtual bool start() {}
};

/*
 *  ******************************************************************************************
*/

/**
 * The FileReader reads images from files. It is used for testing.
 */
class FileReader: public FrameBuffer
{
private:
	//! Path to the image file
	std::string fileName;
	Frame frame;
public:
	/**
	 * @param fileName Path to the image file
	 */
	FileReader(std::string fileName):
		fileName(fileName) {frame = Frame(cv::imread(fileName));}

	void setFileName(std::string fileName) {this->fileName = fileName;}

	/* overloads */
	Frame& nextFrame() {
		frame = Frame(cv::imread(fileName));
		return frame;
	}
	bool stop() {return true;}
	bool start() {return true;}
};

/*
 *  ******************************************************************************************
*/

/*
 * This class was to get frames from actual camera, and construce the fram object using class Frame.
 * The constructed frame should be stored into a queue
*/

class CameraDriver: public FrameBuffer{

     public:
	 	/**
		 * Constructor and destructor
	 	*/
    	CameraDriver();
    	~CameraDriver();
	 	/**
		 * Camera set functions.
	 	*/
                void setDeviceNumber(int input);	// Default to 0. Change this value when other cameras exist in system
                void setFrameFate(int input); 		// Default to 30fps. May has no effect depending on camera module
                void setOnScreenRec(bool input); 	// Default to false.
    	void setBufferSize(unsigned int inputSize);	// Default to 150 frames. CameraDriver stops writting to buffer when size exceed
	 	/**
		 * Camera get functions.
	 	*/
                unsigned int getDeviceNumber(); 	// Get hardware device number
                unsigned int getFrameRate(); 		// Get target frame rate in setting
                bool getDeviceStatus(); 		// Get target camera status, if it is initialized
                bool getOnScreenStatus(); 		// Get if on screen recording was enabled
	 	/**
		 * Camera operation functions.
	 	*/
        bool iniCap();					// Initialize Video Stream and camera, ready to record
                bool startCap();			// Start recording and feed into buffer
                bool stopCap();				// Stop recording
	 	/**
		 * Overload
	 	*/
		Frame& nextFrame();
		bool stop();
		bool start();
    private:
		/**
		 * Camera setting parameters
	 	*/
                unsigned int DeviceNumber = 0;		// Device Number. Select when there are mutilpe cameras in system
                unsigned int FrameRate = 30; 		// Frame Rate in Frame/Second
		unsigned int BufferSize = 150;
                cv::VideoCapture VideoStreamCap;	// Camera Stream object
                cv::Mat VideoFrame;                     // Simple single video frame matrix from camera
    	Frame MatObj;                           	// Constructed Frame Object directly from camera and generated by class Frame
		/**
		 * Camera status indicators
	 	*/
		bool DeviceEnable = false;
		bool OnScreenRec = false;
                bool CaptureStart = false;		// Indicator for if the camera is currently working
		/**
		 * Buffer status indicators
	 	*/
                bool bufferWrite = true;		// Set buffer write premission, should not write buffer when false
                Frame OutputFrameObj;                   // Constructed Frame Object that ready for output/store in buffer
                cv::Mat EmptyFrame;                     // Empty Frame
                std::queue<Frame> FIFOBuffer;           // Quene of frame object
	};	
}; // gpub


#endif // _DRIVER_HPP
