#include <iostream>
#include <vector>
#include "view.hpp"
#include "logic.hpp"
#include "driver.hpp"

#define THREAD_NUM 4
#define DEBUG

/**
 * Main program entry
 */
int main(int argc, char const *argv[])
{
	std::cout << "This is the ball tracker" << std::endl;

	gpub::HSVThreshold tracker;
	gpub::FrameBuffer fb = gpub::CameraDriver();
	gpub::View view;

	while (1)
	{
		std::vector<gpub::Frame> fv(THREAD_NUM);
		std::vector<gpub::State> sv(THREAD_NUM);
		for (int i=0; i<THREAD_NUM; i++)
		{
			fv[i] = fb.nextFrame();
		}
		#pragma omp parallel for num_threads(THREAD_NUM)
		for (int i=0; i<THREAD_NUM; i++)
		{
			if (fv[i]) // if frame valid
			{
				try
				{
					sv[i] = tracker.analyse(fv[i]);
				}
				catch(const std::exception& e)
				{
					std::cerr << "Failed to analyse frame" << std::endl;
				}
			}
			else
			{
				fb.start();
			}
		}
		for (int i=0; i<THREAD_NUM; i++)
		{
			if (sv[i]) // if ball present
			{
				fb.stop();
				try
				{
					view.updateBallState(sv[i], fv[i].getImg());
					#ifdef DEBUG
					std::cout << sv[i].getX() << " " << sv[i].getY() << std::endl;
					#endif
				}
				catch(const std::exception& e)
				{
					std::cerr << "Failed to update GUI" << std::endl;
				}
			}
		}
	}
	return 0;
}
