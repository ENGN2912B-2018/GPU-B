/*
 *File Name    : logic.hpp
 * Author      : Haoze Zhang
 * Date        : Dec-01-2018
 * Modified    : Haoze Zhang
 * Modify Date : Dec-16-2018
 *
 * Description : This file is the class for tracking logic
 * ******************************************************************************************
*/
#ifndef _LOGIC_HPP
#define _LOGIC_HPP

#include <vector>
#include <opencv2/opencv.hpp>
#include "driver.hpp"

namespace gpub
{

class State
{
private:
	bool hasBall = true;
	double speed = -1.0;
	int x = -1;
	int y = -1;

public:
	State();
	State(bool hasBall): hasBall(hasBall) {}
	State(int x, int y): x(x), y(y) {}
	State(double speed, int x, int y): speed(speed), x(x), y(y) {}

	operator bool() {return hasBall;}

	int getSpeed() const {return speed;}
	int getX() const {return x;}
	int getY() const {return y;}

	void setSpeed(double speed) {(*this).speed = speed;}
};

class BallTracker
{
public:
	virtual State analyse(Frame) = 0;
};

class Fusor
{
private:
	std::vector<BallTracker> trackers;
	FrameBuffer frameBuffer;

public:
	State roll();

};

class HSVThreshold: public BallTracker
{
private:
	cv::Scalar upper = cv::Scalar(29.0, 86.0, 6.0);
	cv::Scalar lower = cv::Scalar(64.0, 255.0, 255.0);
	int erosionSize = 2;
	double areaThreshold = 50.0;

public:
	State analyse(Frame);

	void setUpper(double h, double s, double v)
	{
		upper = cv::Scalar(h, s, v);
	}
	void setLower(double h, double s, double v)
	{
		lower = cv::Scalar(h, s, v);
	}
};

} // gpub

#endif // _LOGIC_HPP
