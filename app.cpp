#include <iostream>
#include <vector>
#include <QtWidgets>
#include "./inc/view.hpp"
#include "./inc/logic.hpp"
#include "./inc/driver.hpp"
#include "./inc/camera.h"
//right before commit swap carriage in Git: look up in google
// look for option for line ending
// usability and user experience. Should we prompt the user otherwise?

#define THREAD_NUM 4
#define DEBUG

/**
 * Main program entry
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Camera camera;
    camera.show();
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
    return app.exec();
}
