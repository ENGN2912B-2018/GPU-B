/*
 *File Name    : logic.cpp
 * Author      : Haoze Zhang
 * Date        : Dec-01-2018
 * Modified    : Haoze Zhang
 * Modify Date : Dec-16-2018
 *
 * Description : This file is the methods for tracking logic
 * ******************************************************************************************
*/
#include <vector>
#include <exception>
#include <opencv2/opencv.hpp>
#include "../inc/logic.hpp"

gpub::State gpub::HSVThreshold::analyse(gpub::Frame frame)
{
	auto ts = frame.getTs();
	cv::Mat bgr = frame.getImg();
 	cv::Mat hsv;
	cv::Mat mask;

	if (bgr.empty())
	{
		throw std::exception();
	}

	// create hsv ball mask
	cv::cvtColor(bgr, hsv, cv::COLOR_BGR2HSV);
	cv::inRange(hsv, lower, upper, mask);
	cv::Mat element = cv::getStructuringElement(
		cv::MORPH_RECT, cv::Size(2*erosionSize + 1, 2*erosionSize+1),
		cv::Point(erosionSize, erosionSize));
	cv::erode(mask, mask, element);
	cv::dilate(mask, mask, element);

	// extract contours
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::findContours(
		mask, contours, hierarchy,
		cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE
	);

	// select the largest contour
	int largestIdx = 0;
	double largestArea = 0.0;
	for(int i = 0; i< contours.size(); i++)
	{
		double a = contourArea(contours[i], false);
		if (a > largestArea)
		{
			largestArea = a;
			largestIdx = i;
		}
	}

	// return the center of the largest contour
	if (largestArea > areaThreshold)
	{
		cv::Moments m = cv::moments(contours[largestIdx], false);
		return State(m.m10/m.m00, m.m01/m.m00);
	}
	else
	{
		return State(false);
	}
}
