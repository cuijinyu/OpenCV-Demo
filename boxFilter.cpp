#include <opencv2/opencv.hpp>
#include <vector>
#define WINDOW_WIDTH 600
using namespace std;
using namespace cv;

int main() {
	Mat image = imread("1.jpg");
	namedWindow("�����˲�ԭͼ");
	namedWindow("�����˲�Ч��ͼ");
	imshow("�����˲�ԭͼ", image);

	Mat out;
	boxFilter(image, out, -1, Size(5, 5));

	imshow("�����˲�Ч��ͼ", out);

	waitKey(0);
}
