#include <opencv2/opencv.hpp>
#include <vector>
#define WINDOW_WIDTH 600
using namespace std;
using namespace cv;

int main() {
	Mat image = imread("1.jpg");
	namedWindow("方框滤波原图");
	namedWindow("方框滤波效果图");
	imshow("方框滤波原图", image);

	Mat out;
	boxFilter(image, out, -1, Size(5, 5));

	imshow("方框滤波效果图", out);

	waitKey(0);
}
