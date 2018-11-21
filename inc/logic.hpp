#ifndef _LOGIC_HPP
#define _LOGIC_HPP

#include <vector>
#include "view.hpp"
#include "driver.hpp"

namespace gpub
{

class State
{
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
