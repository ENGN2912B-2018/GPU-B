#ifndef _DRIVER_HPP
#define _DRIVER_HPP

namespace gpub
{

class Frame
{
};

class FrameBuffer
{
public:
	virtual Frame nextFrame();
};

} // gpub


#endif // _DRIVER_HPP
