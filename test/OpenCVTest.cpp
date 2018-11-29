/*
 *File Name   : OpenCVTest.cpp
 * Author      : Ziwei Chen
 * Date        : Nov-23-2018
 * Modified    : Ziwei Chen
 * Modify Date : Nov-29-2018
 * 
 * Description : This program was designed to test the video capture
 *               using OpenCV and buffer. Hardware camera is required
 *               for running this program. OpenCV needs to be installed.
 * 
 * 
 * OpenCV Installation: 
 * https://medium.com/@jaskaranvirdi/setting-up-opencv-and-c-development-environment-in-xcode-b6027728003
 * Compile Using:
 * $ g++ $(pkg-config --cflags --libs opencv) -std=c++11  OpenCVTest.cpp -o VideoCapTest
 * 
 * ******************************************************************************************
*/

#include <iostream>
#include <vector>
#include <queue>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>

using namespace cv;
using namespace std;

int main()
{
    //****************************** Record Settings ******************************//
    int DeviceNumber = 0;
    int RecDuration = 5;
    int FrameRate = 30;
    int FrameSamples = FrameRate * RecDuration;
    //***************************** Hardware Settings *****************************//
    VideoCapture VideoStreamCap;
    VideoStreamCap.open(DeviceNumber);
    VideoStreamCap.set(CV_CAP_PROP_XI_FRAMERATE, FrameRate);
    if( !VideoStreamCap.isOpened() )
    {
        std::cerr << "***Could not Initialize Camera...***\n";
        return -1;
    }
    //****************************** Initializations ******************************//
    Mat VideoFrame;                                         // Each Video Frame
    queue <Mat> FrameBufferVec;                             // Buffer Storage
    cout << endl;
    cout << endl;
    cout << "************************** VIDEO CAPTURE ***************************" << endl;
    cout << " Device Connected: Camera " << DeviceNumber << endl;
    cout << " Record Duration : " << RecDuration << " Seconds" << endl;
    cout << " Frame Rate      : " << FrameRate << " Frames/Second" << endl;
    cout << " Total Frame     : " << FrameSamples << endl;
    cout << " Record Mode     : OFF SCREEN" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;
    cout << "CAMERA READY" << endl;
    cout << "Press ENTER to Start Recording or Press CTRL+C to exit" << endl;
    getchar();
    waitKey(1000);
    cout << "Start in: " << endl;
    cout << " 5" << endl;
    waitKey(1000);
    cout << " 4" << endl;
    waitKey(1000);
    cout << " 3" << endl;
    waitKey(1000);
    cout << " 2" << endl;
    waitKey(1000);
    cout << " 1" << endl;
    waitKey(1000);
    cout << " 0" << endl;

    //****************************** Video Recording ******************************//
    int RecFrameCount = 0;
    while(1){
        VideoStreamCap >> VideoFrame;                                                   // Capture Video Frame

        if(!(VideoFrame.empty())){ FrameBufferVec.push(VideoFrame.clone()); }      // Store in buffer
        waitKey(1);
        if (RecFrameCount == FrameSamples - 1){
            break;
        } else {
            RecFrameCount ++;
            cout << "Frame " << RecFrameCount << " Stored in buffer" << endl;
        }
    }
    cout << endl;
    cout << "COMPLETE!!" << endl;
    cout << "Buffer Size: " << FrameBufferVec.size() << " Frames" << endl;
    cout << "Press Enter to Start Playback" << endl;
    getchar();
    //****************************** Video Playback ******************************//
    for (int index = 0; index < FrameSamples; index++){

        VideoFrame = FrameBufferVec.front();    // Return the very first element
        FrameBufferVec.pop();                   // Delete the very first element
        if(!(VideoFrame.empty())){
            cout << "Reading From Buffer, Current Frame: " << index << endl;
            imshow("Video Capture", VideoFrame);                          // Read buffer and display
        } 
        waitKey(33);
    }
    cout << endl;
    cout << "Playback Finished" << endl;
    cout << "Press ENTER to Exit Program" << endl;
    getchar();
    return 1;
}
