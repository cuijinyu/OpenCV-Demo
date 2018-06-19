#include <opencv2/opencv.hpp>
#include <vector>
#define WINDOW_WIDTH 600
using namespace std;
using namespace cv;

/*
	全局函数声明
*/
static void on_ContrastAndBright (int, void *);
static void showHelpText();


/*
	全局变量声明
*/
int g_nContrastValue;	//	对比度值
int g_nBrightValue;		//	亮度值
Mat g_srcImage, g_dstImage;

/*控制台应用程序的入口函数，程序从这里开始*/

int main() {
	//读取输入图像
	g_srcImage = imread("1.jpg");
	
	if (!g_srcImage.data) {
		printf("读取图片错误，请确定目录下是否有imread函数指定图片存在");
		return false;
	}

	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());

	g_nContrastValue = 80;	//	设置对比度和亮度的初值
	g_nBrightValue = 80;

	namedWindow("【效果图窗口】", 1);

	//创建轨迹条
	createTrackbar("对比度：", "【效果图窗口】", &g_nContrastValue, 300, on_ContrastAndBright);
	createTrackbar("亮度：", "【效果图窗口】", &g_nBrightValue, 200, on_ContrastAndBright);

	//进行回调函数初始化
	on_ContrastAndBright(g_nBrightValue, 0);
	on_ContrastAndBright(g_nContrastValue, 0);

	while (char(waitKey(1)) != 'q') {

	}
	return 0;
}

static void on_ContrastAndBright(int, void *) {
	namedWindow("【原始图窗口】", 1);
	for (int y = 0; y < g_srcImage.rows; y++) {
		for (int x = 0; x < g_srcImage.cols; x++) {
			for (int c = 0; c < 3; c++) {
				g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);
			}
		}
	}
	imshow("【原始图窗口】", g_srcImage);
	imshow("【效果图窗口】", g_dstImage);
}

