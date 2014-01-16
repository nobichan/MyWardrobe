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

#define WIN_NAME    "CamTest"
#define WIN_NAME2   "CamTest2"
#define WIN_HEIGHT  480
#define WIN_WIDTH   640
#define ESC_KEY     27

#define _INNER_CAMERA 0
#define _OPTION1_CAMERA 1
#define _OPTION2_CAMERA 2

/* グローバル変数 */
CvFont font;
//IplImage *img = 0;

/* プロトタイプ宣言 */
void on_mouse (int event, int x, int y, int flags, void *param);

int main ()
{
    int         key;
    CvCapture   *src_l, *src_r;
    IplImage    *frame_l, *frame_r;
    double      w = WIN_WIDTH, h = WIN_HEIGHT;

    //↓↓↓ face detection
    const char  *cascade_name = "/opt/local/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml";
    CvHaarClassifierCascade *cascade = 0;
    CvMemStorage *storage = 0;
    IplImage    *frame_gray = 0;
    CvSeq       *faces = 0;
    int i;

    static CvScalar colors[] = {
        {{  0,   0, 255}}, {{  0, 128, 255}},
        {{  0, 255, 255}}, {{  0, 255,   0}},
        {{255, 128,   0}}, {{255, 255,   0}},
        {{255,   0,   0}}, {{255,   0, 255}}
    };
    // ブーストされた分類器のカスケードを読み込む
    cascade = (CvHaarClassifierCascade *)cvLoad(cascade_name, 0, 0, 0);
    //↑↑↑ face detection

    // カメラに対するキャプチャ構造体を作成
  //  src_l = cvCreateCameraCapture(_INNER_CAMERA);   // left
    src_r = cvCreateCameraCapture(_OPTION1_CAMERA);   // right

  //  frame_l = (IplImage*)malloc(sizeof(IplImage));	// left frame
    frame_r = (IplImage*)malloc(sizeof(IplImage));	// right frame

    // set capture size
  //  cvSetCaptureProperty(src_l, CV_CAP_PROP_FRAME_WIDTH,  w);   // left
  //  cvSetCaptureProperty(src_l, CV_CAP_PROP_FRAME_HEIGHT, h);
    cvSetCaptureProperty(src_r, CV_CAP_PROP_FRAME_WIDTH,  w);   // right
    cvSetCaptureProperty(src_r, CV_CAP_PROP_FRAME_HEIGHT, h);

    // Windowを生成
    cvNamedWindow(WIN_NAME, CV_WINDOW_AUTOSIZE);
    cvNamedWindow(WIN_NAME2, CV_WINDOW_AUTOSIZE);

	// メモリー確保
	storage = cvCreateMemStorage(0);
	cvClearMemStorage(storage);

    while (1) {
        // キャプチャ
  //      frame_l = cvQueryFrame(src_l);
        frame_r = cvQueryFrame(src_r);

        //↓↓↓ face detection ↓↓↓ -----------------------
        // グレースケールイメージ？
//        frame_gray = cvCreateImage(cvGetSize(frame_l), IPL_DEPTH_8U, 1);
        frame_gray = cvCreateImage(cvGetSize(frame_r), IPL_DEPTH_8U, 1);

        // メモリー確保
     //   storage = cvCreateMemStorage(0);
     //   cvClearMemStorage(storage);

        // 読み込んだ画像のグレースケール化
 //       cvCvtColor(frame_l, frame_gray, CV_BGR2GRAY);
        cvCvtColor(frame_r, frame_gray, CV_BGR2GRAY);

        // ヒストグラムの均一化
        cvEqualizeHist(frame_gray, frame_gray);
        frame_r = frame_gray;
        //↑↑↑ face detection ↑↑↑ -----------------------

        //↓↓↓ facd dectection ↓↓↓ -----------------------
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
   //         cvCircle (frame_l, center, radius, colors[i % 8], 3, 8, 0);
            cvCircle (frame_r, center, radius, colors[i % 8], 3, 8, 0);
        }
        //↑↑↑ face detection ↑↑↑ -----------------------

        // 表示
 //       cvShowImage(WIN_NAME, frame_l);
        cvShowImage(WIN_NAME2, frame_r);

        // キー入力待ち
        key = cvWaitKey(33);

        // ESC入力されたら終了
        if (ESC_KEY == key) {
            break;
        }
    }

    cvDestroyWindow(WIN_NAME);
    cvDestroyWindow(WIN_NAME2);
    cvReleaseCapture(&src_l);
    cvReleaseCapture(&src_r);

    return 0;
}

