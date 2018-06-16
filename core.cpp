#include <opencv2/opencv.hpp>
#include <vector>
#define WINDOW_WIDTH 600
using namespace std;
using namespace cv;

/*
	�Զ���Ļ��ƺ�����ʵ���˻��Ʋ�ͬ�Ƕȣ��ߴ���ͬ����Բ
*/
void DrawEllipse (Mat img, double angle) {
	int thickness = 2;
	int lineType = 8;

	ellipse(img,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),
		angle,
		0,
		360,
		Scalar(255, 129, 0),
		thickness,
		lineType
	);
}

/*
	�Զ���Ļ��ƺ�����ʵ����ʵ��Բ�Ļ���
*/
void DrawFilledCircle (Mat img, Point center) {
	int thickness = -1;
	int lineType = 8;

	circle(img,
		center,
		WINDOW_WIDTH / 32,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}

/*
	�Զ���Ļ��ƺ�����ʵ���˰�����εĻ���
*/
void DrawPolygon(Mat img) {
	int lineType = 8;

	Point rookPointers[1][5];	//	����һЩ��
	rookPointers[0][0] = Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
	rookPointers[0][1] = Point(WINDOW_WIDTH / 40, 6 * WINDOW_WIDTH / 8);
	rookPointers[0][2] = Point(WINDOW_WIDTH / 41, 5 * WINDOW_WIDTH / 8);
	rookPointers[0][3] = Point(WINDOW_WIDTH / 3, 4 * WINDOW_WIDTH / 8);
	rookPointers[0][5] = Point(WINDOW_WIDTH / 30, 3 * WINDOW_WIDTH / 8);

	const Point * ppt[1] = { rookPointers[0] };
	int npt[] = { 20 };
	fillPoly(img,
		ppt,
		npt,
		1,
		Scalar(255, 255, 255),
		lineType);
}

/*
	�Զ���Ļ��ƺ�����ʵ�����ߵĻ���
*/
void DrawLine (Mat img, Point start, Point end) {
	int thickness = 2;
	int lineType = 8;
	line(img,
		start,
		end,
		Scalar(0, 0, 0),
		thickness,
		lineType);
}

int main(void) {
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

	DrawEllipse(atomImage, 90.0);
	DrawEllipse(atomImage, 0.0);
	DrawEllipse(atomImage, 45.0);
	DrawEllipse(atomImage, -45.0);
	DrawFilledCircle(atomImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));

	DrawPolygon(rookImage);
	rectangle(rookImage,
		Point(0, 7 * WINDOW_WIDTH / 8),
		Point(WINDOW_WIDTH, WINDOW_WIDTH),
		Scalar(0, 255, 255)
	);
	DrawLine(rookImage, Point(0, 15 * WINDOW_WIDTH / 16), Point(WINDOW_WIDTH, 15 * WINDOW_WIDTH));

	imshow("����ͼ1", atomImage);
	moveWindow("����ͼ1", 0, 200);
	imshow("����ͼ2", rookImage);
	moveWindow("����ͼ2", WINDOW_WIDTH, 200);
	waitKey(0);
	return 0;
}

