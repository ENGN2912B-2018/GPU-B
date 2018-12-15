#ifndef _LOGIC_HPP
#define _LOGIC_HPP

#include <vector>
#include <opencv2/opencv.hpp>
#include "view.hpp"
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
	View view;
	std::vector<BallTracker> trackers;
	FrameBuffer frameBuffer;

public:
	void roll();

};

class HSVThreshold: public BallTracker
{
};

} // gpub

#endif // _LOGIC_HPP
