#ifndef _VIEW_HPP
#define _VIEW_HPP

#include <opencv2/opencv.hpp>
#include "logic.hpp"

namespace gpub
{

class View
{
public:
        void updateBallState(State state, cv::Mat img);
};

} // gpub

#endif // _VIEW_HPP
