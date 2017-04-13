#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;//命名空间
int WinMain()  
{
	VideoCapture capture("v.mp4");//创建VideoCapture对象
	//VideoCapture capture(0);//创建摄像头
	CvFont font;
	CvPoint P1, P2;
	P1.x = 130;
	P1.y = 120;
	P2.x = 490;
	P2.y = 360;
	char *strID;

	strID = "Head Zone";
	int flag = 1;
	double fps = capture.get(CV_CAP_PROP_FPS); //获取视频帧率  
	double pauseTime = 1000 / fps; //两 幅画面中间间隔 

	if (!capture.isOpened())//判断是否打开摄像头，打开isOpened返回ture
	{
		cout << "无法打开摄像头" << endl;
		return 1;
	}
	bool stop(false);//定义一个用来停止循环的变量
	Mat frame;//用来存放读取的视频序列，承载每一帧的图像 ，Mat类是用于保存图像以及其他矩阵数据的数据结构
	Mat temp;
	namedWindow("Camera");//创建一个窗口，显示每一帧的窗口
	while (!stop)
	{
		capture >> frame;
		if (frame.empty())//如果没有读取到就中断
		{
			break;
		}
		cv::rectangle(frame, P1, P2, CV_RGB(0, 255, 0), 2);
		cv::putText(frame, strID, cvPoint(P1.x, P1.y - 10), CV_FONT_HERSHEY_PLAIN, 1.5, CV_RGB(255, 0, 0));//红色字体注释
		if (flag == 1)
		{			
			flag = 0; 
		}
		frame.copyTo(temp);

		imshow("Camera", frame);//正常显示，把获取的视频填充到窗口中

		char c = cvWaitKey(33);      
		
		if (c == 32)break; //使用空格键来停止ASCII 为32

		       

	}
	capture.release();
	waitKey(0);//释放
	return 0;
}
