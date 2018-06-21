#include <opencv2/opencv.hpp>
#include <vector>
#define WINDOW_WIDTH 600
using namespace std;
using namespace cv;
int main() {
	Mat srcImage = imread("1.jpg");
	imshow("原始图", srcImage);

	Mat dstImage;
	GaussianBlur(srcImage, dstImage, Size(7, 7), 0, 0);

	imshow("效果图", dstImage);

	waitKey(0);
}
