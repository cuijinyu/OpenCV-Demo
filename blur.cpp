#include <opencv2/opencv.hpp>
#include <vector>
#define WINDOW_WIDTH 600
using namespace std;
using namespace cv;
int main() {
	Mat srcImage = imread("1.jpg");
	imshow("ԭʼͼ", srcImage);

	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));

	imshow("Ч��ͼ", dstImage);

	waitKey(0);
}
