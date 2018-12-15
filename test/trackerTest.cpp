#include <iostream>
#include "logic.hpp"
#include "driver.hpp"
// compile:
// g++ $(pkg-config --cflags --libs opencv) -std=c++11 -I ../inc ../src/logic.cpp  trackerTest.cpp -o trackerTest

int main()
{
	gpub::HSVThreshold tracker;
	gpub::FrameBuffer fb = gpub::FileReader("ball.jpg");
	gpub::State s = tracker.analyse(fb.nextFrame());
	std::cout << s.getX() << " " << s.getY() << std::endl;
}
