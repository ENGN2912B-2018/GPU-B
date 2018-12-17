/*
 *File Name    : logic.cpp
 * Author      : Haoze Zhang
 * Date        : Dec-01-2018
 * Modified    : Ziwei Chen
 * Modify Date : Dec-16-2018
 *
 * Description : This file is the main function for this project
 * ******************************************************************************************
*/
#include <iostream>
#include <vector>
#include <thread>
#include <QtWidgets>
#include "./inc/logic.hpp"
#include "./inc/driver.hpp"
#include "./inc/camera.h"

#define THREAD_NUM 4
// #define DEBUG

/**
 * The tracking algorithms loop
 */
void track(Camera view, gpub::HSVThreshold& tracker,
           gpub::FrameBuffer& fb, bool& killSwitch)
{
    while (killSwitch)
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
                    cv::Mat img = fv[i].getImg();
                    cv::circle(img, cv::Point(sv[i].getX(),sv[i].getY()),3,
                           cv::Scalar(255,255,255),cv::FILLED);
                    view.updateBallState(sv[i], img);
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
}

/**
 * Main program entry
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Camera view;
    view.show();
    std::cout << "This is the ball tracker" << std::endl;

    gpub::HSVThreshold tracker;
    gpub::FrameBuffer fb = gpub::CameraDriver();

	bool killSwitch = true;
    std::thread ballTracker(track, view, tracker, fb, killSwitch);

    int ret = 0;
    ret = app.exec();
    killSwitch = false;
    ballTracker.join();
    return ret;
}
