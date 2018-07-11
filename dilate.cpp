#include <opencv2/opencv.hpp>
#include <vector>
#define WINDOW_WIDTH 600
using namespace std;
using namespace cv;

int main() {
	Mat image = imread("1.jpg");
	namedWindow("原图");
	namedWindow("膨胀操作");
	imshow("原图", image);

	//获取自定义核
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat out;

	dilate(image, out, element);
	imshow("膨胀操作", out);
	waitKey(0);
	return 0;
}
