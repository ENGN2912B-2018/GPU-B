#ifndef _DRIVER_HPP
#define _DRIVER_HPP

#include <string>
#include <chrono>

#include <opencv2/opencv.hpp>

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

};

} // gpub


#endif // _DRIVER_HPP
