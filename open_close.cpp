#include <opencv2/opencv.hpp>
#include <vector>
#define WINDOW_WIDTH 600
using namespace std;
using namespace cv;

int main() {
	Mat image = imread("1.jpg");
	namedWindow("原图");
	namedWindow("开运算");
	namedWindow("闭运算");
	imshow("原图", image);

	//获取自定义核
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat out;
	Mat out_2;
	morphologyEx(image, out, CV_MOP_OPEN, element);
	morphologyEx(image, out_2, CV_MOP_CLOSE, element);
	imshow("开运算", out);
	imshow("闭运算", out_2);
	waitKey(0);
	return 0;
}
