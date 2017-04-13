#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;//�����ռ�
int main()
{
	VideoCapture capture("v.mp4");//����VideoCapture����
	CvFont font;
	CvPoint P1, P2;
	P1.x = 130;
	P1.y = 120;
	P2.x = 490;
	P2.y = 360;
	char *strID;
	strID = "Head zone";

	double fps = capture.get(CV_CAP_PROP_FPS); //��ȡ��Ƶ֡��  
	double pauseTime = 1000 / fps; //���������м��� 

	if (!capture.isOpened())//�ж��Ƿ������ͷ����isOpened����ture
	{
		cout << "�޷�������ͷ" << endl;
		return 1;
	}
	bool stop(false);//����һ������ֹͣѭ���ı���
	Mat frame;//������Ŷ�ȡ����Ƶ���У�����ÿһ֡��ͼ�� ��Mat�������ڱ���ͼ���Լ������������ݵ����ݽṹ

	namedWindow("Camera");//����һ�����ڣ���ʾÿһ֡�Ĵ���
	while (!stop)
	{
		
		if (!capture.read(frame) || waitKey(pauseTime) == 27)//���û�ж�ȡ�����ж�
		{
			break;
		}
		cv::rectangle(frame, P1, P2, CV_RGB(0, 255, 0), 2);
		cv::putText(frame, strID, cvPoint(P1.x, P1.y - 10), CV_FONT_HERSHEY_PLAIN, 1.5, CV_RGB(255, 0, 0));//��ɫ����ע��

		imshow("Camera", frame);//������ʾ���ѻ�ȡ����Ƶ��䵽������


		char c = cvWaitKey(33);
		if (c == 32)break; //ʹ�ÿո����ֹͣASCII Ϊ32


	}
	capture.release();
	waitKey(0);//�ͷ�
	return 0;
}
