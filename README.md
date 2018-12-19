# Ball Tracker - Group GPU-B
<div style="text-align:center; font-weight:bold">
     <p>Scientific Programming in C++<br>ENGN-2912B Section 01</p>
     <img src="doc/images/Brown_Logo_3.png" width="150" title="Brown Logo">
     <p>Brown University <br> School of Engineering</p>
     <p>December 2018</p>
</div>

## Team Members
[Ziwei Chen](mailto:ziwei_chen1@brown.edu): Product owner, SCRUM master<br />
[Jocelyn Cheng](mailto:jocelyn_cheng@brown.edu): Senior director of UX and screen design<br />
[Haoze Zhang](mailto:haoze_zhang@brown.edu): Senior director of software engineering<br />


## Introduction
### Overview
The conventional object tracking in sports are expensive, and requires highly sophisticated technique for operation. This repository presents a solution for single camera based ball tracking at low cost and with smooth learning curve. 
The softerware consists a Graphical User Interface (GUI) implemented by using Qt for easy operation, a buffer that developen by using C++ standard templet library (STL) as well as OpenCV to ensures the realtime performance, 
and an algorithm that utilizes OpenCL, OpenCV, and OpenMP for accurate tracking.

### Goals and Objectives
The goal for this project was to develop a platform that preformes ball tracking in realtime at low hardware cost. Utilizing the computational power for GPU was set at one of the object for this project, and it ensures the templet matching 
can be performed in a high efficient manner. In addition, this software platform also requires to be run in realtime in order to give the user instantaneous feedback for ball speed and trajectory. Aside from the performance part, this software
should also be designed to be easy to use, which means instead of a design by engineer and use by engineer software, it has to be user friendly and the general public shoul be able to use the platform without any technical training. 

## Software Architecture Design
### Required External Libraries
This software requires the suport of external libraries and specific enviroment for compiling and running. Although the use case may very, the recommended requirement list is shown as follow:

Windows 10 Pro  64bit<br />
Qt Creator 4.8.0<br />
Qt 5.12.0<br />
MinGW 7.3.0 64bit for C++<br />
OpenCV 3.4.4<br />
OpenCL 2.2<br />
OpenMP 4.5<br />

### Functional Bolck Diagrams
```under construction```
### Data Flow Diagrams
```under construction```
### UML Diagrams
The UML Diagram for this program is shown as follow: <br />
<img src="https://github.com/ENGN2912B-2018/GPU-B/blob/master/doc/images/Classes.png" width="650" title="UML"><br /><br />

## Interface Descriptions
### Graphical Interface
```under construction```
<img src="https://github.com/ENGN2912B-2018/GPU-B/blob/master/doc/images/Capture.png" width="650" title="UML"><br /><br />
<img src="https://github.com/ENGN2912B-2018/GPU-B/blob/master/doc/images/Capture2.png" width="650" title="UML"><br /><br />
<img src="https://github.com/ENGN2912B-2018/GPU-B/blob/master/doc/images/Capture3.png" width="650" title="UML"><br /><br />
<img src="https://github.com/ENGN2912B-2018/GPU-B/blob/master/doc/images/Capture4.png" width="650" title="UML"><br /><br />

### Data Visualization
```Do we have this?```
### Communications Protocols
```We don't have this```
### Threading and Concurrenty
``` Something Here?```
### Exception Handling
```We have it, but what should be written here?```

## Testing and Evaluation
### Test Enviroment (OS, Compioler, Library)
The testing enviroment was set to using the recommended enviroment and libraries, which means using Windows 10 64bit, and Qt 4.8.0 as IDE. The actual Qt version needs to be installed was 5.12.0, and MinGW 7.3.0 64bit for C++ as compiler.
All the libraries including OpenCV 4.3.3, OpenCL 2.1, and OpenMP 4.5 need to be configured in Windows system variables first, and then properly linked to project in Qt IDE.

### Description of Function Testing to Date
```under construction```

### Instructions for Compiling and Running
<b>Step 1:</b> Since this project was built and compiled in [Qt Creator IDE](https://www.qt.io), the required components is shown as follow:<br />
<img src="https://github.com/ENGN2912B-2018/GPU-B/blob/master/doc/images/QtInatall.png" width="450" title="Install Component"><br /><br />

<b>Step 2:</b> Install all required libraries and packages, the download links are given as follow:<br />
[OpenCV 4.3.3](https://opencv.org)<br />
[OpenCL 2.2](https://www.khronos.org/opencl/)<br />
[OpenMP 4.5](https://www.openmp.org)<br />

<b>Step 3:</b> Configure all installed libraries and packages in Windows system variables.

<b>Step 4:</b> Configure Qt Creator IDE for using MinGW 7.3.0 64 bit for C++ as the C++ compiler, and link the libraries required to project

<b>Step 5:</b> Compile and run the software. Make sure a camera was attached via. Universal Serial Bus (USB) connection.

## Conclusions
### Major Accoumplishments
For this project, the Graphical User Interface was successfully designed by using Qt. A high speed FIFO buffer was designed by using standard templet library, and video capture and playback function was developed by using OpenCV. 
In addition, A tracking algorithm was developed, and the program was designed for utilizing multithreading for maximize performance. Aside from functional accoumplishments, the program also consists error handling, which gives it the
best stability possible.

### Results of Development Effort
```under construction```

### Were you successful in meeting all goals and objectives?  What didn't work?  What would take more time?
Most of the development objectives were achieved. The program is utilizing the computational power of GPU for algorithm acceleration, and the graphical user interface is useable. The actual tracking performance, nevertheless, is limited.
The tracking object needs to be traveled at minimal speed for the program to follow. This was resulted by the low frame rate and low sensitivity of the camera, and cannot be resolved by software. The time consuming for the implementation
of individual functions were well with in expectation. The system integration, however, tooks most time of this project. Since the development enviroment was not unified, switching between different operation systems caused software incompatibility
issues, and a considerable amount of time was devoted into solve them. 

## Future Work
### Potential future software expansions and software features
Although this platform satisfies most development goals, improvements and feature expansions are still possible for future work. Firstly, although the operation for this platform was easy, it still utilizes external dynamically linked libraries, 
which would be linked in runtime. This limits the usage and downgrade the software compatibility, and may be a potential improvement. In addition, the tracking only works under bright ligntning condition, or slow ball movement. This 
problem was due to the low sensibility and low frame rate for the hardware camera module. This problem can be improved by switching to a high speed camera that outputs at least 120 frames per second.  

## Author Contributions
### Ziwei Chen
Ziwei Chen was responsable for hardware camera setup, and video stream buffering. He implemented the hardware driver for this softwre, and beffer the captured video stream for ensuring realtime processing can be achieved. He also
implemented the interfac between driver and algorithm, which allows the algorithm to control the buffer status. He was also responsable for holding regular team meetings, and setup meeting agendas to push the development forward. 
### Jocelyn Cheng
Jocelyn Cheng was responsable for graphical user interface development and design. The UI/UX design was the essencial for easy user interaction,  and it was implemented by using Qt IDE. In addition, she also implemented the interface
between algorithm and GUI, which made it possible for user to visualize the realtime performance on screen.
### Haoze Zhang
He was responsable for tracking algorithm, system interfacing, and software architecture. He implemented the actual tracking algorithm by using templet matching. He also finished the main program, and interface all components to make the 
software as one piece.












```
# Original Content

Practicing pitching baseballs can be hard because getting immediate feedback is hard. Our ball tracker is here to help!

Commercially available alternatives are extremely expensive, hard to set up, and require several cameras. Our ball tracker produces accurate estimates of the pitch velocity and strike zone using only a single camera and a laptop.

This program was designed With sports lovers and recreational players in mind, but even professionals can use it. With just a laptop and a decent camera, our ball tracker can give you a quality training session anytime, anywhere.

## Technical Highlights
**It's accurate!** The ball tracker adopts multiple state-of-the-art tracking algorithms and fuses the measurements with a [Baysian probabilistic model](https://en.wikipedia.org/wiki/Bayesian_probability). It can deliver incredible tracking accuracy even with a low-cost camera.

**It's fast!** The ball tracker is programmed with [OpenCL](https://www.khronos.org/opencl/) which harnesses the ultimate parallel processing power of the GPU. It outruns any balls, guaranteed.

**It's fun!** The graphics is implemented with [Qt](https://en.wikipedia.org/wiki/Qt_(software)) which delivers a native, clean, and professional look and feel. Together with sophisticated error handling, the software is more accessible, more robust, and more fun to use than ever - it just does not crash its beautiful interface on any rubbish input and keeps the practice going all day.

## Installation
```under construction```

## Usage
```under construction```

```
