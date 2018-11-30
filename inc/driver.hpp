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
	cv::Mat img;
	//! Timestamp of image capture
	ts_t ts;

public:
	/**
	 * A frame is timestamped as now.
	 * @prarm img The image matrix
	 */
	Frame(cv::Mat img):
		img(img) {ts = std::chrono::system_clock::now();}

	/**
	 * @param img The image matrix
	 * @param ts Frame timestamp
	 */
	Frame(cv::Mat img, ts_t ts):
		img(img), ts(ts) {}
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
	 * @return The next frame awaits processing
	 */
	virtual Frame nextFrame() = 0;

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
