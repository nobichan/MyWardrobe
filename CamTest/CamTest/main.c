//
//  main.c
//  CamTest
//
//  Created by USER on 2013/07/21.
//  Copyright (c) 2013年 USER. All rights reserved.
//

#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <ctype.h>

#define WIN_NAME "CamTest"
#define WIN_HEIGHT 480
#define WIN_WIDTH 640
#define ESC_KEY 27

int main ()
{
    int key;
    CvCapture *src;
    IplImage *frame;
    double w = WIN_WIDTH, h = WIN_HEIGHT;
    
    src = cvCreateCameraCapture(0);
    
    // set capture size
    cvSetCaptureProperty(src, CV_CAP_PROP_FRAME_WIDTH, w);
    cvSetCaptureProperty(src, CV_CAP_PROP_FRAME_HEIGHT, h);
    
    cvNamedWindow(WIN_NAME, CV_WINDOW_AUTOSIZE);
    
    while (1) {
        frame = cvQueryFrame(src);
        cvShowImage(WIN_NAME, frame);
        key = cvWaitKey(33);
        if (ESC_KEY == key) {
            break;
        }
    }
    
    cvDestroyWindow(WIN_NAME);
    cvReleaseCapture(&src);

    return 0;
}
