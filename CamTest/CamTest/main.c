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
    
    //↓↓↓ face detection
    const char *cascade_name = "/opt/local/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml";
    CvHaarClassifierCascade *cascade = 0;
    CvMemStorage *storage = 0;
    IplImage *frame_gray = 0;
    CvSeq *faces = 0;
    int i;
    static CvScalar colors[] = {
        {{0, 0, 255}}, {{0, 128, 255}},
        {{0, 255, 255}}, {{0, 255, 0}},
        {{255, 128, 0}}, {{255, 255, 0}},
        {{255, 0, 0}}, {{255, 0, 255}}
    };
    // ブーストされた分類器のカスケードを読み込む
    cascade = (CvHaarClassifierCascade *)cvLoad(cascade_name, 0, 0, 0);
    //↑↑↑ face detection

    // カメラに対するキャプチャ構造体を作成
    src = cvCreateCameraCapture(0);
    
    // set capture size
    cvSetCaptureProperty(src, CV_CAP_PROP_FRAME_WIDTH, w);
    cvSetCaptureProperty(src, CV_CAP_PROP_FRAME_HEIGHT, h);

    // Windowを生成
    cvNamedWindow(WIN_NAME, CV_WINDOW_AUTOSIZE);
    
    while (1) {
        // キャプチャ
        frame = cvQueryFrame(src);
        
        //↓↓↓ face detection
        // グレースケールイメージ？
        frame_gray = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
        // メモリー確保
        storage = cvCreateMemStorage(0);
        cvClearMemStorage(storage);
        // 読み込んだ画像のグレースケール化
        cvCvtColor(frame, frame_gray, CV_BGR2GRAY);
        // ヒストグラムの均一化
        cvEqualizeHist(frame_gray, frame_gray);//, <#CvArr *dst#>)
        //↑↑↑ face detection
        
        //↓↓↓ facd dectection
        // 顔検出
        faces = cvHaarDetectObjects(frame_gray, cascade, storage, 1.11, 4, 0, cvSize(40, 40), cvSize(0, 0));

        // 検出されたすべての顔位置に円を描画する
        for (i = 0; i < (faces ? faces->total : 0); i++) {
            CvRect *r = (CvRect *) cvGetSeqElem (faces, i);
            CvPoint center;
            int radius;
            center.x = cvRound (r->x + r->width * 0.5);
            center.y = cvRound (r->y + r->height * 0.5);
            radius = cvRound ((r->width + r->height) * 0.25);
            cvCircle (frame, center, radius, colors[i % 8], 3, 8, 0);
        }
        //↑↑↑ face detection
        
        // 表示
        cvShowImage(WIN_NAME, frame);

        // キー入力待ち
        key = cvWaitKey(33);
        
        // ESC入力されたら終了
        if (ESC_KEY == key) {
            break;
        }
    }
    
    cvDestroyWindow(WIN_NAME);
    cvReleaseCapture(&src);

    return 0;
}
